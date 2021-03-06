// ImgDumpBmp.cpp : implementation file
//

#include "stdafx.h"
#include "ImgDumpBmp.h"

#include "windows.h"

// CImgDumpBmp

IMPLEMENT_DYNAMIC(CImgDumpBmp, CWnd)
CImgDumpBmp::CImgDumpBmp()
		:CanSizeScroll(FALSE)
		,LButtonDown(FALSE)
		,VScroll_Enabled(FALSE)
		,HScroll_Enabled(FALSE)
		,nPalIndex(0)
{
	RegisterWndClass();

	FirstRun = TRUE;
	PaintDC = NULL;

	//Fix later
	crBGCol = RGB(0, 0, 0);
}

CImgDumpBmp::~CImgDumpBmp()
{
	CleanUp();
}

BEGIN_MESSAGE_MAP(CImgDumpBmp, CWnd)
		ON_WM_SIZE()
		ON_WM_PAINT()
		ON_WM_HSCROLL()
		ON_WM_VSCROLL()
		ON_WM_ERASEBKGND()
		ON_WM_LBUTTONDOWN()
		ON_WM_LBUTTONUP()
		ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

BOOL CImgDumpBmp::RegisterWndClass()
{
    WNDCLASS windowclass;
    HINSTANCE hInst = AfxGetInstanceHandle();

    //Check weather the class is registerd already

    if (!(::GetClassInfo(hInst, IMGDUMPBMP, &windowclass)))
    {
        //If not then we have to register the new class

        windowclass.style = CS_DBLCLKS;// | CS_HREDRAW | CS_VREDRAW;

        windowclass.lpfnWndProc = ::DefWindowProc;
        windowclass.cbClsExtra = windowclass.cbWndExtra = 0;
        windowclass.hInstance = hInst;
        windowclass.hIcon = NULL;
        windowclass.hCursor = AfxGetApp()->LoadStandardCursor(IDC_SIZEALL);
        windowclass.hbrBackground = ::GetSysColorBrush(COLOR_WINDOW);
        windowclass.lpszMenuName = NULL;
        windowclass.lpszClassName = IMGDUMPBMP;

        if (!AfxRegisterClass(&windowclass))
        {
            AfxThrowResourceException();
            return FALSE;
        }
    }

    return TRUE;
}

void CImgDumpBmp::InitImgData()
{

	rgSrcImg = pMainImgCtrl->GetImgBuffer();
	img_amt = pMainImgCtrl->GetImgAmt();
	//rImgRct = pMainImgCtrl->GetImgRct();

	//Init blit data here

	rImgRct.SetRect(0, 0, 0, 0);

	for(int nImgCtr = 0; nImgCtr < img_amt; nImgCtr++)
	{
		int nXOffs = rgSrcImg[nImgCtr]->nXOffs;
		int nYOffs = rgSrcImg[nImgCtr]->nYOffs;

		nXOffs = nImgCtr ? nXOffs + (rgSrcImg[0]->uImgW / 2) - (rgSrcImg[nImgCtr]->uImgW / 2) : 0;
		nYOffs = nImgCtr ? nYOffs + (rgSrcImg[0]->uImgH / 2) - (rgSrcImg[nImgCtr]->uImgH / 2) : 0;

		if(nXOffs < rImgRct.left)
		{
			rImgRct.left = nXOffs;
		}

		if(nYOffs < rImgRct.top)
		{
			rImgRct.top = nYOffs;
		}

		if(nXOffs + rgSrcImg[nImgCtr]->uImgW > rImgRct.right)
		{
			rImgRct.right = nXOffs + rgSrcImg[nImgCtr]->uImgW;
		}

		if(abs(nYOffs) + rgSrcImg[nImgCtr]->uImgH > rImgRct.bottom)
		{
			rImgRct.bottom = nYOffs + rgSrcImg[nImgCtr]->uImgH;
		}

		ptOffs[nImgCtr].x = nXOffs;
		ptOffs[nImgCtr].y = nYOffs;
	}

	blt_w = rImgRct.Width();
	blt_h = rImgRct.Height();

	GetOutputW();
	GetOutputH();

	ResizeMainBmp();
	

	
}



void CImgDumpBmp::OnSize(UINT nType,int cx,int cy )
{
	CWnd::OnSize(nType, cx, cy);

	if(!FirstRun)
	{
		SetClientSize();
		SizeScroll(TRUE);
		UpdateClip();
		
		UpdateBltRect();
		ClearCtrlBG();
	}

	//UpdateCtrl();
}

int CImgDumpBmp::ScrollBounds(int in_val, BOOL horiz)
{
	int min = 0;
	int max;

	switch(horiz)
	{
	case FALSE:
			max = clip_bottom;
		break;
	case TRUE:
			max = clip_right;
		break;
	}

	if (in_val < min)
		return min;

	if(in_val > max)
		return max;

	return in_val;
}

void CImgDumpBmp::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{	
	int curr_pos = m_VScroll.GetScrollPos();
	int old_pos = curr_pos;

	switch(nSBCode)
	{
	case SB_BOTTOM:
		curr_pos = nMainH;
		break;
	case SB_ENDSCROLL:
		break;
	case SB_LINEDOWN:
		curr_pos += 1;
		break;
	case SB_LINEUP:
		curr_pos -= 1;
		break;
	case SB_PAGEDOWN:
		curr_pos += SCROLL_PAGE_AMT;
		break;
	case SB_PAGEUP:
		curr_pos -= SCROLL_PAGE_AMT;
		break;
	case SB_THUMBPOSITION:
		m_VScroll.SetScrollPos(nPos);
		break;
	case SB_THUMBTRACK:
		m_VScroll.SetScrollPos(nPos);
		break;
	case SB_TOP:
		curr_pos = 0;
		break;
	}

	curr_pos = ScrollBounds(curr_pos, FALSE);

	if(curr_pos != old_pos)
		m_VScroll.SetScrollPos(curr_pos);


	UpdateBltRect();
	UpdateCtrl();

	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CImgDumpBmp::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{	
	int curr_pos = m_HScroll.GetScrollPos();
	int old_pos = curr_pos;

	switch(nSBCode)
	{
	case SB_LEFT:
		curr_pos = 0;
		break;
	case SB_ENDSCROLL:
		break;
	case SB_LINELEFT:
		curr_pos -= 1;
		break;
	case SB_LINERIGHT:
		curr_pos += 1;
		break;
	case SB_PAGELEFT:
		curr_pos -= SCROLL_PAGE_AMT;
		break;
	case SB_PAGERIGHT:
		curr_pos += SCROLL_PAGE_AMT;
		break;
	case SB_RIGHT:
		curr_pos = nMainW;
		break;
	case SB_THUMBPOSITION:
		m_HScroll.SetScrollPos(nPos);
		break;
	case SB_THUMBTRACK:
		m_HScroll.SetScrollPos(nPos);
		break;
	}

	curr_pos = ScrollBounds(curr_pos, TRUE);

	if(curr_pos != old_pos)
		m_HScroll.SetScrollPos(curr_pos);

	UpdateBltRect();
	UpdateCtrl();

	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CImgDumpBmp::UpdateBltRect(BOOL reset_flag)
{
	int scroll_h = m_VScroll.GetScrollPos();
	int scroll_w = m_HScroll.GetScrollPos();

	main_blt.top = 0 + (scroll_h * reset_flag);
	//main_blt.bottom = cl_height + scroll_h;

	main_blt.left = 0 + (scroll_w * reset_flag);


	if(!reset_flag)
	{
		m_VScroll.SetScrollPos(0, 0);
		m_HScroll.SetScrollPos(0, 0);
	}
	//main_blt.right = cl_width + scroll_w;
}

void CImgDumpBmp::SetClientSize()
{
	GetClientRect(&ctrl_rect);

	cl_width = ctrl_rect.right - SCROLL_W;
	cl_height = ctrl_rect.bottom - SCROLL_W;
}

void CImgDumpBmp::UpdateClip()
{
	clip_right = nMainW - cl_width;
	clip_bottom = nMainH - cl_height;

	m_HScroll.SetScrollRange(0, clip_right);
	m_VScroll.SetScrollRange(0, clip_bottom);

	HScroll_Enabled = cl_width < nMainW;
	VScroll_Enabled = cl_height < nMainH;

	m_HScroll.EnableWindow(HScroll_Enabled);
	m_VScroll.EnableWindow(VScroll_Enabled);
	
}

void CImgDumpBmp::OnMouseMove(UINT nFlags, CPoint point)
{
	CWnd::OnMouseMove(nFlags, point);

	

	if(LButtonDown)
	{
		POINT diff;

		

		diff.x = point.x - old_pt.x;
		diff.y = point.y - old_pt.y;

		

		if(diff.x || diff.y)
		{
			int hscroll_pos = m_HScroll.GetScrollPos();
			int vscroll_pos = m_VScroll.GetScrollPos();

			hscroll_pos -= diff.x;
			vscroll_pos -= diff.y;

			if(HScroll_Enabled)
				m_HScroll.SetScrollPos(hscroll_pos);
			
			if(VScroll_Enabled)
				m_VScroll.SetScrollPos(vscroll_pos);

			UpdateBltRect();

			old_pt = point;

			Draw();
			//UpdateCtrl();
		}

	}
}

void CImgDumpBmp::OnLButtonDown(UINT nFlags, CPoint point)
{
	LButtonDown = TRUE;

	SetCapture();

	old_pt.x = point.x;
	old_pt.y = point.y;

	CWnd::OnLButtonDown(nFlags, point);
}

void CImgDumpBmp::OnLButtonUp(UINT nFlags, CPoint point)
{
	LButtonDown = FALSE;

	ReleaseCapture();

	CWnd::OnLButtonUp(nFlags, point);
}

void CImgDumpBmp::OnPaint()
{
	if(FirstRun)
	{
		PaintDC = new CPaintDC(this);

		MainDC.CreateCompatibleDC(PaintDC);
		MainDC.SelectObject(MainHBmp);

		//Get the control size
		SetClientSize();


		SetBG(crBGCol);

		//Create the scroll bars. Why are they here???????????????????

		SizeScroll();

		m_HScroll.Create(SBS_HORZ | SBS_TOPALIGN | WS_CHILD, h_rect, this, 100);
		m_HScroll.ShowScrollBar();

		m_VScroll.Create(SBS_VERT | SBS_TOPALIGN | WS_CHILD, v_rect, this, 100);
		m_VScroll.ShowScrollBar();

		CanSizeScroll = TRUE;

		UpdateBltRect();

		FirstRun = FALSE;
		
		//Update
		UpdateCtrl();
	}

	SizeScroll(TRUE);
	
	Draw();

	
	CWnd::OnPaint();
	
	
}

BOOL CImgDumpBmp::OnEraseBkgnd(CDC* pDC)
{

	return TRUE;//CWnd::OnEraseBkgnd(pDC);
}


void CImgDumpBmp::SizeScroll(BOOL resize)
{

	v_rect.top = ctrl_rect.top; v_rect.bottom = cl_height;
	v_rect.left = cl_width; v_rect.right = ctrl_rect.right;

	h_rect.top = cl_height; h_rect.bottom = ctrl_rect.bottom;
	h_rect.left = ctrl_rect.left; h_rect.right = cl_width;

	if(resize && CanSizeScroll)
	{
		m_HScroll.MoveWindow(&h_rect);
		m_VScroll.MoveWindow(&v_rect);
	}

}

/*
void CImgDumpBmp::DrawSource()
{
	POINT out_pt;


	SrcDC.Rectangle(0, 0, blt_w * nPalAmt, blt_h);

	int add_amt;
	int img_index;

	int nCurrW;
	int nCurrH;
	UINT32 * pImgData;
	int nCurrPalSz;

	switch(DispType)
	{
	case DISP_ALT:
		add_amt = nPalAmt == 2 ? 1 : 2;
		break;
	case DISP_DEF:	
		add_amt = 1;
		break;
		
	}

	for(int img_ctr = 0; img_ctr < img_amt; img_ctr++)
	{
		img_index = 0;
		
		pImgData = pImgBmpData[img_ctr];
		nCurrPalSz = rgSrcImg[img_ctr]->uPalSz;
		nCurrW = rgSrcImg[img_ctr]->uImgW;
		nCurrH = rgSrcImg[img_ctr]->uImgH;

		for(int amt_ctr = 0; amt_ctr < (nPalAmt) ; amt_ctr+=add_amt)
		{
			
			

			for(int index = 0; index < nCurrPalSz; index++)
			{
				COLORREF crCol = pppPalettes[img_ctr][amt_ctr][index];

				for(int i = 0; i < px_ctr[img_ctr][index]; i++)
				{
					
					out_pt.x = px[img_ctr][index][i].x + (blt_w * img_index);
					out_pt.y = px[img_ctr][index][i].y;

					pImgData[nCurrW * out_pt.y + out_pt.x] = crCol & 0x00FFFFFF;
				}
			}


			if(DispType == DISP_ALT)
			{
				if(add_amt == 2)
				{
					if(amt_ctr == 4)
						amt_ctr = -1;

					if(amt_ctr == 5)
						add_amt = 1;
				}
			}

			

			img_index++;

		}
	}
}

*/
void CImgDumpBmp::SetBG(COLORREF new_crBGCol)
{
	crBGCol = new_crBGCol;
}

void CImgDumpBmp::ClearCtrlBG()
{
	COLORREF crCol = GetSysColor(COLOR_3DFACE);
	if(cl_width > nMainW)
	{
		PaintDC->FillSolidRect(CRect(nMainW, 0, cl_width, cl_height), crCol);
	}

	if(cl_height > nMainH)
	{
		PaintDC->FillSolidRect(CRect(0, nMainH, cl_width, cl_height), crCol);
	}

	PaintDC->FillSolidRect(CRect(ctrl_rect.right - SCROLL_W, ctrl_rect.bottom - SCROLL_W, ctrl_rect.right, ctrl_rect.bottom), crCol);
}

void CImgDumpBmp::UpdateCtrl(BOOL bDraw, UINT8 * pDstData)
{

	ClearCtrlBG();

	MainDC.FillSolidRect(CRect(0, 0, nMainW, nMainH), crBGCol);


	int row_ctr = 0;
	int nPal;

	int nXOffs;
	int nYOffs;

	int nTargetX, nTargetY;
	
	UINT8 * pMainData;

	if(pDstData)
	{
		pMainData = (UINT8 *)pMainBmpData;
		pMainBmpData = (UINT32 *)pDstData;
	}

	for(int i = 0; i < amt; i++)
	{
		nPal = amt > 1 ? i : nPalIndex;

		if(DispType == DISP_DEF)
		{
			if( i >= 3)
			{
				row_ctr = 1;
			}

			nTargetX = (i - (row_ctr * 3)) ;
		}
		if(DispType == DISP_ALT)
		{
			if(i % 2)
			{
				row_ctr = 1;
			}
			else
			{
				row_ctr = 0;
			}

			nTargetX = (i / 2);
		}

		//pMainBmpData[0] = 0x00FFFFFF;

		for(int nImgCtr = 0; nImgCtr < img_amt; nImgCtr++)
		{
			nXOffs = rgSrcImg[nImgCtr]->nXOffs;
			nYOffs = rgSrcImg[nImgCtr]->nYOffs;

			CustomBlt(nImgCtr, nPal,

				//Left
				( nTargetX  * (blt_w * zoom))
				+ border_sz + (border_sz * nTargetX) + abs(rImgRct.left * zoom) + (ptOffs[nImgCtr].x * zoom),

				//Top
				( row_ctr * (blt_h * zoom))
				+ border_sz + (border_sz * row_ctr) + abs(rImgRct.top * zoom) + (ptOffs[nImgCtr].y * zoom),
				
				zoom, (BOOL)pDstData
				);
		}
	}

	if(pDstData)
	{
		pMainBmpData = (UINT32 *)pMainData;
	}
	bDraw ? Draw(): NULL;
	UpdateClip();
}

BOOL CImgDumpBmp::CustomBlt(int nSrcIndex, int nPalIndex, int nDstX, int nDstY, double fpZoom, BOOL bTransBG)
{
	int nWidth = rgSrcImg[nSrcIndex]->uImgW;
	int nHeight = rgSrcImg[nSrcIndex]->uImgH;
	int nBltW, nBltH;
	int nSrcX = 0, nSrcY = 0;

	UINT8 uIndex;

	int nStartRow;
	int nSrcStartRow;
	int nSrcPos;
	int nDstPos;

	double fpXDiff = (double)nWidth / ((double)nWidth * fpZoom);
	double fpYDiff = (double)nHeight / ((double)nHeight * fpZoom);

	int nXCtr = 0;
	int nYCtr = 0;

	UINT8 * pDstBmpData = (UINT8 *)pMainBmpData;
	UINT8 * pImgData = (UINT8 *)rgSrcImg[nSrcIndex]->pImgData;
	UINT8 * pCurrPal = (UINT8 *)pppPalettes[nSrcIndex][nPalIndex];

	CRect rBltRct(nDstX, nDstY, nDstX + (nWidth * fpZoom), nDstY + (nHeight * fpZoom));

	if(nDstX < 0)
	{
		rBltRct.left = 0;
		nSrcX = abs(nDstX);
	}

	if(nDstY < 0)
	{
		rBltRct.top = 0;
		nSrcY = abs(nDstY);
	}

	if(rBltRct.right > nMainW)
	{
		rBltRct.right = nMainW;
	}

	if(rBltRct.bottom > nMainH)
	{
		rBltRct.bottom = nMainH;
	}

	nBltW = rBltRct.right - rBltRct.left;
	nBltH = rBltRct.bottom - rBltRct.top;



	int nRightBlt = rBltRct.right * 4;


	if(bTransBG)
	{
		double fpAdd = 0.0f;

		for(int y = 0; y < (nBltH); y++)
		{
			nYCtr = (int)((double)y * fpYDiff);
		
			nStartRow = (0 - ((nBltH - 1) - y + rBltRct.top)) * (nMainW*4) + (rBltRct.left*4);
			nSrcStartRow = ((nYCtr + nSrcY) * nWidth) + nSrcX;

			for(int x = 0; x < nBltW*4; x+=4)
			{
				
				nXCtr = (int)((double)x * fpXDiff);

				uIndex = pImgData[nSrcStartRow + (nXCtr / 4)];

				if(uIndex)
				{
					fpAdd = ((double) pCurrPal[(uIndex * 4) + 3] / 255.0f);

					nDstPos = nStartRow + x;

					pDstBmpData[nDstPos + 3] += pCurrPal[(uIndex * 4) + 3];

					pDstBmpData[nDstPos + 2] = pDstBmpData[nDstPos + 2] ?  pDstBmpData[nDstPos + 2] + ((double)pCurrPal[(uIndex * 4)] * fpAdd) : pDstBmpData[nDstPos + 2] + pCurrPal[(uIndex * 4)];
					pDstBmpData[nDstPos + 1] = pDstBmpData[nDstPos + 1] ? pDstBmpData[nDstPos + 1] + ((double)pCurrPal[(uIndex * 4) + 1] * fpAdd) : pDstBmpData[nDstPos + 1] + pCurrPal[(uIndex * 4) + 1];
					pDstBmpData[nDstPos] = pDstBmpData[nDstPos] ? pDstBmpData[nDstPos] + ((double)pCurrPal[(uIndex * 4) + 2] * fpAdd) : pDstBmpData[nDstPos] + pCurrPal[(uIndex * 4) + 2];
				}
			}
			

		}
	}
	else
	{
		double fpDstA1 = 1.0, fpDstA2 = 1.0;
		UINT8 * uDstR, * uDstG, * uDstB;
		
		for(int y = 0; y < nBltH; y++)
		{
			nYCtr = (int)((double)y * fpYDiff);
		
			nStartRow = (rBltRct.top + (((nBltH - 1) - y))) * (nMainW*4) + (rBltRct.left*4);
			nSrcStartRow = ((nYCtr + nSrcY) * nWidth) + nSrcX;

			for(int x = 0; x < nBltW*4; x+=4)
			{
				
				nXCtr = (int)((double)x * fpXDiff);

				uIndex = pImgData[nSrcStartRow + (nXCtr / 4)];

				if(uIndex)
				{
					nDstPos = nStartRow + x;

					fpDstA2 = (1.0f - (pCurrPal[(uIndex * 4) + 3]) / 255.0f);
					fpDstA1 = 1.0f - fpDstA2;

					uDstR = &pDstBmpData[nDstPos + 2];
					uDstG = &pDstBmpData[nDstPos + 1];
					uDstB = &pDstBmpData[nDstPos];

					
					*uDstR = (UINT8)aadd((fpDstA1 * (double)pCurrPal[(uIndex * 4)]), (fpDstA2 * (double)*uDstR));
					*uDstG = (UINT8)aadd((fpDstA1 * (double)pCurrPal[(uIndex * 4) + 1]),  (fpDstA2 * (double)*uDstG));
					*uDstB = (UINT8)aadd((fpDstA1 * (double)pCurrPal[(uIndex * 4) + 2]), (fpDstA2 * (double)*uDstB));
				}
			}
			

		}
	}

	return TRUE;


}

void CImgDumpBmp::Draw()
{
	PaintDC->BitBlt(0, 0, cl_width, cl_height, &MainDC, main_blt.left, main_blt.top, SRCCOPY);
}

void CImgDumpBmp::CleanUp()
{
	//Delete the extra palettes

	if(pppPalettes)
	{
		for(int i = 0; i < img_amt; i++)
		{
			if(pppPalettes[i])
			{
				for(int amt_ctr = 0; amt_ctr < (nPalAmt); amt_ctr++)
				{
					if(pppPalettes[i][amt_ctr])
						delete [] pppPalettes[i][amt_ctr];
				}

				delete [] pppPalettes[i];
			}
		}

		delete [] pppPalettes;
	}

	DeleteObject(MainHBmp);
	//Clean main image data
	
}

int CImgDumpBmp::GetOutputW()
{
	int w_mul;

	switch(amt)
	{
	case 1:
		w_mul = 1;
		break;
	case 6:
		w_mul = 3;
		break;
	case 7:
		w_mul = 4;
		break;
	}


	nMainW = ( ( w_mul  * border_sz)  + border_sz) + ((blt_w * zoom) * w_mul);
		
	return nMainW;
}

int CImgDumpBmp::GetOutputH()
{
	int h_mul = (amt == 1 ? 1 : 2); 

	nMainH = ( ( h_mul  * border_sz)  + border_sz) + ((blt_h * zoom) * h_mul);

	return nMainH;
}

void CImgDumpBmp::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	//CPoint mouse_pos;

	CWnd::OnTimer(nIDEvent);
}


void CImgDumpBmp::ResizeMainBmp()
{
	static int nPrevW = 0;
	static int nPrevH = 0;

	if(nMainW != nPrevW || nMainH != nPrevH)
	{
		DeleteObject(MainHBmp);

		MainBmpi.bmiHeader.biWidth = nMainW;
		MainBmpi.bmiHeader.biHeight = -nMainH;
		MainBmpi.bmiHeader.biPlanes = 1;
		MainBmpi.bmiHeader.biBitCount = 32;
		MainBmpi.bmiHeader.biCompression = BI_RGB;
		MainBmpi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);

		
		MainHBmp = CreateDIBSection(MainDC.GetSafeHdc(), &MainBmpi, DIB_RGB_COLORS, (void **)&pMainBmpData, NULL, 0);

		if(!FirstRun)
		{
			MainDC.SelectObject(MainHBmp);
		}
	}
}