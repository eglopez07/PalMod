#pragma once

// Note that we only look up Onslaught from this section, and we don't have a sprite(?)
#define MVC_A_IMGSTART (0x3B + 0x11 + 0x11 + 0x01) //MVC2, then SSF2T, then SFA3, then XMVSF

// To add characters or palette lists:
// * Update the SupportedPaletteListIndex with the new index name.
// * Add an array below along the line sof MVC_A_RYU_PALETTES. 
// * Update every array using MVC_A_NUMUNIT below
// * Update the three index lookups in Game_MVC_A_.cpp that are marked - look for usage of indexRyu to find them
// That should be it.  Good luck.

enum SupportedPaletteListIndex
{
    indexWarMachine = 0,
    indexCaptainAmerica,
    indexHulk,
    indexWolverine,
    indexVenom,
    indexSpiderman,
    indexRoll,
    indexRyu,
    indexCapCom,
    indexChun,
    indexJin,
    indexGief,
    indexStrider,
    indexMegaman,
    indexMorrigan,
    indexOnslaught,
    indexHyperVenom,
    indexOrangeHulk,
    indexGWM,
    indexShadowLady,
    indexLilith,
    indexGambit,
    indexAssists,
    indexLast
};

constexpr auto MVC_A_NUMUNIT = indexLast;

#define MVC_A_EXTRALOC MVC_A_NUMUNIT

// These are the base offsets for a character.
const UINT32 MVC_A_UNITLOC[MVC_A_NUMUNIT] =
{
    0x481C4, // War Machine
    0x48284, // Cap
    0x48344, // Hulk
    0x48404, // Wolvie
    0x48584, // Venom
    0x48644, // Spidey
    0x48704, // Roll
    0x487C4, // Ryu
    0x48884, // CapCom
    0x48944, // Chun
    0x48A04, // Jin
    0x48AC4, // Gief
    0x48E04, // Strider
    0x48F84, // Megaman
    0x48ec4, // Morrigan
    0x49044, // Onslaught
    0x490A4, // Hyper Venom
    0x49164, // Orange Hulk
    0x49224, // GWM
    0x492E4, // Shadow Lady
    0x493A4, // Lilith
    0x484c4, // Gambit
    0x0, // Assists: Special
};

struct sMVC_PaletteDataset
{
    LPCSTR szPaletteName;
    int nPaletteOffset;
    UINT16 indexImgToUse = INVALID_UNIT_VALUE; // the major character/collection index
    UINT16 indexOffsetToUse = 0x0; // subsprites within that collection
};

const sMVC_PaletteDataset MVC_A_RYU_PALETTES[] =
{
    { "Ryu P1", 0x487C4, 0x00 },
    { "Ryu P1 Hadouken", 0x487E4, 0x00, 1 },
    { "Ryu P1 Shoryuken", 0x48804, 0x27, 2 },
    { "Ryu P2", 0x48824, 0x00 },
    { "Ryu P2 Hadouken", 0x48844, 0x00, 1 },
    { "Ryu P2 Shoryuken", 0x48864, 0x27, 2 },

    { "Ken P1", 0x4EC44, 0x00 },
    { "Ken P1 Hakouken", 0x4EC64, 0x00, 1 },
    { "Ken P1 Shoryuken", 0x4EC84, 0x27, 2 },
    { "Ken P2", 0x4ECA4, 0x00 },
    { "Ken P2 Hadouken", 0x4ECC4, 0x00, 1 },
    { "Ken P2 Shoryuken", 0x4ECE4, 0x27, 2 },

    { "Akuma P1", 0x4ED04, 0x00 },
    { "Akuma P1 Hadouken", 0x4ED24, 0x1E, 1 },
    { "Akuma P1 Shoryuken", 0x4ED44, 0x27, 2 },
    { "Akuma P2", 0x4ED64, 0x00 },
    { "Akuma P2 Hadouken", 0x4ED84, 0x1E, 1 },
    { "Akuma P2 Shoryuken", 0x4EDA4, 0x27, 2 },
};

const sMVC_PaletteDataset MVC_A_GIEF_PALETTES[] =
{
    { "Zangief P1", 0x48AC4, 0x01 },
    { "P1 Banishing Fist",  0x48AE4, 0x01, 1 },
    { "Palette 3",  0x48B04, 0xFF },
    { "Zangief P2", 0x48B24, 0x01 },
    { "P2 Banishing Fist",  0x48B44, 0x01, 1 },
    { "Palette 6",  0x48B64, 0xFF },

    { "Mecha Zangief P1", 0x48C84, 0x01 },
    { "P1 Yoga Flame",      0x48CA4, 0x01, 0x3 },
    { "Palette 15",          0x48CC4, 0xFF },
    { "Mecha Zangief P2", 0x48CE4, 0x01 },
    { "P2 Yoga Flame",    0x48D04, 0x01, 0x3 },
    { "Palette 18",          0x48D24, 0xFF  },
};

const sMVC_PaletteDataset MVC_A_SHADOWLADY_PALETTES[] =
{
    { "P1 Color", 0x492E4, 0x1b },
    { "P1 Glimmer 1", 0x4FF64, 0x1b },
    { "P1 Glimmer 2", 0x4FF84, 0x1b },
    { "P1 Glimmer 3", 0x4FFA4, 0x1b },
    { "P1 Extra 1", 0x49304 },
    { "P1 Extra 2", 0x49324 },

    { "P2 Color", 0x49344, 0x1b },
    { "P2 Glimmer 1", 0x4FFC4, 0x1b },
    { "P2 Glimmer 2", 0x4FFE4, 0x1b },
    { "P2 Glimmer 3", 0x50004, 0x1b },
    { "P2 Extra 1", 0x49364 },
    { "P2 Extra 2", 0x49384 },
};

const sMVC_PaletteDataset MVC_A_CHUNLI_PALETTES[] =
{
    { "P1 Color", 0x48944, 0x1b },
    { "P1 leg flash", 0x48964, 0x1b, 1 },
    { "P1 Kikosho", 0x48984, 0x1b, 2 },
    { "P2 Color", 0x489A4, 0x1b },
    { "P2 leg flash", 0x489C4, 0x1b, 1 },
    { "P2 Kikosho", 0x489E4, 0x1b, 2 },
};

const sMVC_PaletteDataset MVC_A_JIN_PALETTES[] =
{
    { "P1 Color",        0x48A04, 0x37 },
    { "P1 Blodia FX",    0x48A24, 0x37, 1 },
    { "P1 Blodia Punch", 0x48A44, 0x37, 2 },
    { "P2 Color",        0x48A64, 0x37 },
    { "P2 Blodia FX",    0x48A84, 0x37, 1 },
    { "P2 Blodia Punch", 0x48AA4, 0x37, 2 },
};

// Note that since this is eleventy palettes, the code is substituting the default Megaman sprite when 0xff is supplied.  
// To unwind that we would want to specify the correct sprites to use everywhere.  MM is 0x1C .
const sMVC_PaletteDataset MVC_A_MEGAMAN_PALETTES[] =
{
    { "Megaman P1", 0x48F84 },
    { "P1 Rush/Eddie", 0x48FA4 },
    { "P1 Beat",  0x48FC4 },
    { "Megaman P2", 0x48FE4 },
    { "P2 Rush/Eddie", 0x49004 },
    { "P2 Beat",  0x49024 },

    { "P1 Intro", 0x4C064 },
    { "P1 Extra 1", 0x4C084 },
    { "P1 Extra 2", 0x4C0A4 },
    { "P1 Extra 3", 0x4C0C4 },
    { "P1 Extra 4", 0x4C0E4 },
    { "P1 Extra 5", 0x4C104 },
    { "P1 Extra 6", 0x4C124 },
    { "P1 Extra 7", 0x4C144 },
    { "P1 Extra 8", 0x4C164 },
    { "P1 Extra 9", 0x4C184 },

    { "P1 Rush/Eddie Extras 1", 0x4C1A4 },
    { "P1 Rush/Eddie Extras 2", 0x4C1C4 },
    { "P1 Rush/Eddie Extras 3", 0x4C1E4 },
    { "P1 Rush/Eddie Extras 4", 0x4C204 },
    { "P1 Rush/Eddie Extras 5", 0x4C224 },
    { "P1 Rush/Eddie Extras 6", 0x4C244 },
    { "P1 Rush/Eddie Extras 7", 0x4C264 },
    { "P1 Rush/Eddie Extras 8", 0x4C284 },
    { "P1 Rush/Eddie Extras 9", 0x4C2A4 },

    { "P1 Beat Extras 1", 0x4C2C4 },
    { "P1 Beat Extras 2", 0x4C2E4 },
    { "P1 Beat Extras 3", 0x4C304 },
    { "P1 Beat Extras 4", 0x4C324 },
    { "P1 Beat Extras 5", 0x4C344 },
    { "P1 Beat Extras 6", 0x4C364 },
    { "P1 Beat Extras 7", 0x4C384 },
    { "P1 Beat Extras 8", 0x4C3A4 },
    { "P1 Beat Extras 9", 0x4C3C4 },

    { "P1 Beat Plane Extras 1", 0x4C3E4  },
    { "P1 Beat Plane Extras 2", 0x4C404 },
    { "P1 Beat Plane Extras 3", 0x4C424 },
    { "P1 Beat Plane Extras 4", 0x4C444 },
    { "P1 Beat Plane Extras 5", 0x4C464 },
    { "P1 Beat Plane Extras 6", 0x4C484 },
    { "P1 Beat Plane Extras 7", 0x4C4A4 },
    { "P1 Beat Plane Extras 8", 0x4C4C4 },
    { "P1 Beat Plane Extras 9", 0x4C4E4 },

    { "P1 Charged HP 1", 0x4C504 },
    { "P1 Charged HP 2", 0x4C524 },
    { "P1 Charged HP 3", 0x4C544 },
    { "P1 Charged HP 4", 0x4C564 },
    { "P1 Charged HP 5", 0x4C584 },
    { "P1 Charged HP 6", 0x4C5A4 },
    { "P1 Charged HP 7", 0x4C5C4 },
    { "P1 Charged HP 8", 0x4C5E4 },
    { "P1 Charged HP 9", 0x4C604 },

    { "P1 Rush Extras 1", 0x4C624 },
    { "P1 Rush Extras 2", 0x4C644 },
    { "P1 Rush Extras 3", 0x4C664 },
    { "P1 Rush Extras 4", 0x4C684 },
    { "P1 Rush Extras 5", 0x4C6A4 },
    { "P1 Rush Extras 6", 0x4C6C4 },
    { "P1 Rush Extras 7", 0x4C6E4 },
    { "P1 Rush Extras 8", 0x4C704 },
    { "P1 Rush Extras 9", 0x4C724 },

    { "P1 Intro", 0x4C744 },

    { "P1 Rush Extra 1", 0x4C784 },
    { "P1 Rush Extra 2", 0x4C7A4 },
    { "P1 Rush Extra 3", 0x4C7C4 },
    { "P1 Rush Extra 4", 0x4C7E4 },
    { "P1 Rush Extra 5", 0x4C804 },
    { "P1 Rush Extra 6", 0x4C824 },
    { "P1 Rush Extra 7", 0x4C844 },
    { "P1 Rush Extra 8", 0x4C864 },
    { "P1 Rush Extra 9", 0x4C884 },

    { "P1 Hyper Megaman 1", 0x4C8A4 },
    { "P1 Hyper Megaman 2", 0x4C8C4 },
    { "P1 Hyper Megaman 3", 0x4C8E4 },
    { "P1 Hyper Megaman 4", 0x4C904 },
    { "P1 Hyper Megaman 5", 0x4C924 },
    { "P1 Hyper Megaman 6", 0x4C944 },
    { "P1 Hyper Megaman 7", 0x4C964 },
    { "P1 Hyper Megaman 8", 0x4C984 },
    { "P1 Hyper Megaman 9", 0x4C9A4 },

    { "P1 Beat Extras", 0x4C9C4 },

    { "P1 Roll Win Pose", 0x4CAE4, 0x1d },
    { "P1 Magnetic Megaman", 0x4CB04 },
    { "P1 Extras 1", 0x4DE64 },
    { "P1 Extras 2", 0x4DE84 },
    { "P1 Extras 3", 0x4DEA4 },
    { "P1 Extras 4", 0x4DEC4 },
    { "P1 Extras 5", 0x4DEE4 },
    { "P1 Extras 6", 0x4DF04 },
    { "P1 Extras 7", 0x4DF24 },
    { "P1 Extras 8", 0x4DF44 },
    { "P1 Extras 9", 0x4DF64 },

    { "P1 Beat Extra", 0x4DF84 },
    { "P1 Megaman Extra", 0x4E0A4 },
    { "P1 Magnetic Megaman", 0x4E0C4 },

    { "P2 Intro", 0x4CB44 },
    { "P2 Extra 1", 0x4CB64 },
    { "P2 Extra 2", 0x4CB84 },
    { "P2 Extra 3", 0x4CBA4 },
    { "P2 Extra 4", 0x4CBC4 },
    { "P2 Extra 5", 0x4CBE4 },
    { "P2 Extra 6", 0x4CC04 },
    { "P2 Extra 7", 0x4CC24 },
    { "P2 Extra 8", 0x4CC44 },
    { "P2 Extra 9", 0x4CC64 },

    { "P2 Rush/Eddie Extras 1", 0x4CC84 },
    { "P2 Rush/Eddie Extras 2", 0x4CCA4 },
    { "P2 Rush/Eddie Extras 3", 0x4CCC4 },
    { "P2 Rush/Eddie Extras 4", 0x4CCE4 },
    { "P2 Rush/Eddie Extras 5", 0x4CD04 },
    { "P2 Rush/Eddie Extras 6", 0x4CD24 },
    { "P2 Rush/Eddie Extras 7", 0x4CD44 },
    { "P2 Rush/Eddie Extras 8", 0x4CD64 },
    { "P2 Rush/Eddie Extras 9", 0x4CD84 },

    { "P2 Beat Extras 1", 0x4CDA4 },
    { "P2 Beat Extras 2", 0x4CDC4 },
    { "P2 Beat Extras 3", 0x4CDE4 },
    { "P2 Beat Extras 4", 0x4CE04 },
    { "P2 Beat Extras 5", 0x4CE24 },
    { "P2 Beat Extras 6", 0x4CE44 },
    { "P2 Beat Extras 7", 0x4CE64 },
    { "P2 Beat Extras 8", 0x4CE84 },
    { "P2 Beat Extras 9", 0x4CEA4 },

    { "P2 Beat Plane Extras 1", 0x4CEC4 },
    { "P2 Beat Plane Extras 2", 0x4CEE4 },
    { "P2 Beat Plane Extras 3", 0x4CF04 },
    { "P2 Beat Plane Extras 4", 0x4CF24 },
    { "P2 Beat Plane Extras 5", 0x4CF44 },
    { "P2 Beat Plane Extras 6", 0x4CF64 },
    { "P2 Beat Plane Extras 7", 0x4CF84 },
    { "P2 Beat Plane Extras 8", 0x4CFA4 },
    { "P2 Beat Plane Extras 9", 0x4CFC4 },

    { "P2 Charged HP 1", 0x4CFE4 },
    { "P2 Charged HP 2", 0x4D004 },
    { "P2 Charged HP 3", 0x4D024 },
    { "P2 Charged HP 4", 0x4D044 },
    { "P2 Charged HP 5", 0x4D064 },
    { "P2 Charged HP 6", 0x4D084 },
    { "P2 Charged HP 7", 0x4D0A4 },
    { "P2 Charged HP 8", 0x4D0C4 },
    { "P2 Charged HP 9", 0x4D0E4 },

    { "P2 Rush Extras 1", 0x4D104 },
    { "P2 Rush Extras 2", 0x4D124 },
    { "P2 Rush Extras 3", 0x4D144 },
    { "P2 Rush Extras 4", 0x4D164 },
    { "P2 Rush Extras 5", 0x4D184 },
    { "P2 Rush Extras 6", 0x4D1A4 },
    { "P2 Rush Extras 7", 0x4D1C4 },
    { "P2 Rush Extras 8", 0x4D1E4 },
    { "P2 Rush Extras 9", 0x4D204 },

    { "P2 Intro", 0x4D224 },

    { "P2 Rush Extra 1", 0x4D264 },
    { "P2 Rush Extra 2", 0x4D284 },
    { "P2 Rush Extra 3", 0x4D2A4 },
    { "P2 Rush Extra 4", 0x4D2C4 },
    { "P2 Rush Extra 5", 0x4D2E4 },
    { "P2 Rush Extra 6", 0x4D304 },
    { "P2 Rush Extra 7", 0x4D324 },
    { "P2 Rush Extra 8", 0x4D344 },
    { "P2 Rush Extra 9", 0x4D364 },

    { "P2 Hyper Megaman 1", 0x4D384 },
    { "P2 Hyper Megaman 2", 0x4D3A4 },
    { "P2 Hyper Megaman 3", 0x4D3C4 },
    { "P2 Hyper Megaman 4", 0x4D3E4 },
    { "P2 Hyper Megaman 5", 0x4D404 },
    { "P2 Hyper Megaman 6", 0x4D424 },
    { "P2 Hyper Megaman 7", 0x4D444 },
    { "P2 Hyper Megaman 8", 0x4D464 },
    { "P2 Hyper Megaman 9", 0x4D484 },

    { "P2 Beat Extras", 0x4D4A4 },

    { "P2 Roll Win Pose", 0x4D5C4, 0x1d },
    { "P2 Magnetic Megaman", 0x4D5E4 },
    { "P2 Megaman Extra", 0x4EB84 },
    { "P2 Magnetic Megaman", 0x4EBA4 },
};

const sMVC_PaletteDataset MVC_A_ROLL_PALETTES[] =
{
    { "P1 Color",       0x48704, 0x1d },
    { "P1 Rush/Eddie",  0x48724 },
    { "P1 Beat",        0x48744 },
    { "P2 Color",       0x48764, 0x1d },
    { "P2 Rush/Eddie",  0x48784 },
    { "P2 Beat",        0x487A4 },

    { "P1 Hair", 0x4D604 }, // 09 : these numbers align to the mvc2 extra ids as identified in the Palette Variant Full spreadsheet
    { "P1 Intro / Death Animation", 0x4D624 },

    { "P1 Intro 1", 0x4D644, 0x1d },
    { "P1 Intro 2", 0x4D664, 0x1d },
    { "P1 Intro 3", 0x4D684, 0x1d },
    { "P1 Intro 4", 0x4D6A4, 0x1d },
    { "P1 Intro 5", 0x4D6C4, 0x1d },
    { "P1 Intro 6", 0x4D6E4, 0x1d },
    { "P1 Intro 7", 0x4D704, 0x1d },
    { "P1 Intro 8", 0x4D724, 0x1d },
    { "P1 Intro 9", 0x4D744, 0x1d }, // 13 

    { "P1 Rush/Eddie 1", 0x4D764 },
    { "P1 Rush/Eddie 2", 0x4D784 },
    { "P1 Rush/Eddie 3", 0x4D7A4 },
    { "P1 Rush/Eddie 4", 0x4D7C4 },
    { "P1 Rush/Eddie 5", 0x4D7E4 },
    { "P1 Rush/Eddie 6", 0x4D804 },
    { "P1 Rush/Eddie 7", 0x4D824 },
    { "P1 Rush/Eddie 8", 0x4D844 },
    { "P1 Rush/Eddie 9", 0x4D864 }, // 1c

    { "P1 Beat 1", 0x4D884 },
    { "P1 Beat 2", 0x4D8A4 },
    { "P1 Beat 3", 0x4D8C4 },
    { "P1 Beat 4", 0x4D8E4 },
    { "P1 Beat 5", 0x4D904 },
    { "P1 Beat 6", 0x4D924 },
    { "P1 Beat 7", 0x4D944 },
    { "P1 Beat 8", 0x4D964 },
    { "P1 Beat 9", 0x4D984 }, // 25

    { "P1 Beat Plane 1", 0x4D9A4 },
    { "P1 Beat Plane 2", 0x4D9C4 },
    { "P1 Beat Plane 3", 0x4D9E4 },
    { "P1 Beat Plane 4", 0x4DA04 },
    { "P1 Beat Plane 5", 0x4DA24 },
    { "P1 Beat Plane 6", 0x4DA44 },
    { "P1 Beat Plane 7", 0x4DA64 },
    { "P1 Beat Plane 8", 0x4DA84 },
    { "P1 Beat Plane 9", 0x4DAA4 }, // 2e

    { "P1 Charging Roll 1", 0x4DAC4, 0x1d },
    { "P1 Charging Roll 2", 0x4DAE4, 0x1d },
    { "P1 Charging Roll 3", 0x4DB04, 0x1d },
    { "P1 Charging Roll 4", 0x4DB24, 0x1d },
    { "P1 Charging Roll 5", 0x4DB44, 0x1d },
    { "P1 Charging Roll 6", 0x4DB64, 0x1d },
    { "P1 Charging Roll 7", 0x4DB84, 0x1d },
    { "P1 Charging Roll 8", 0x4DBA4, 0x1d },
    { "P1 Charging Roll 9", 0x4DBC4, 0x1d }, // 37

    { "P1 Rush Drill 1", 0x4DBE4 },
    { "P1 Rush Drill 2", 0x4DC04 },
    { "P1 Rush Drill 3", 0x4DC24 },
    { "P1 Rush Drill 4", 0x4DC44 },
    { "P1 Rush Drill 5", 0x4DC64 },
    { "P1 Rush Drill 6", 0x4DC84 },
    { "P1 Rush Drill 7", 0x4DCA4 },
    { "P1 Rush Drill 8", 0x4DCC4 },
    { "P1 Rush Drill 9", 0x4DCE4 }, // 40

    { "P1 Teleport Intro", 0x4DD04 },
    { "P1 Dr Light", 0x4DD24 },

    { "P1 Hyper Roll Armor 1", 0x4DD44 },
    { "P1 Hyper Roll Armor 2", 0x4DD64 },
    { "P1 Hyper Roll Armor 3", 0x4DD84 },
    { "P1 Hyper Roll Armor 4", 0x4DDA4 },
    { "P1 Hyper Roll Armor 5", 0x4DDC4 },
    { "P1 Hyper Roll Armor 6", 0x4DDE4 },
    { "P1 Hyper Roll Armor 7", 0x4DE04 },
    { "P1 Hyper Roll Armor 8", 0x4DE24 },
    { "P1 Hyper Roll Armor 9", 0x4DE44 }, // 4b

    { "P1 Megaman Intro 1", 0x4DE64, 0x1c },
    { "P1 Megaman Intro 2", 0x4DE84, 0x1c },
    { "P1 Megaman Intro 3", 0x4DEA4, 0x1c },
    { "P1 Megaman Intro 4", 0x4DEC4, 0x1c },
    { "P1 Megaman Intro 5", 0x4DEE4, 0x1c },
    { "P1 Megaman Intro 6", 0x4DF04, 0x1c },
    { "P1 Megaman Intro 7", 0x4DF24, 0x1c },
    { "P1 Megaman Intro 8", 0x4DF44, 0x1c },
    { "P1 Megaman Intro 9", 0x4DF64, 0x1c }, // 54ish

    { "P1 Hyper Roll Missiles", 0x4DF84 }, // 55

    { "P1 Revert Hyper Roll 1", 0x4DFA4 },
    { "P1 Revert Hyper Roll 2", 0x4DFC4 },
    { "P1 Revert Hyper Roll 3", 0x4DFE4 },
    { "P1 Revert Hyper Roll 4", 0x4E004 },
    { "P1 Revert Hyper Roll 5", 0x4E024 },
    { "P1 Revert Hyper Roll 6", 0x4E044 },
    { "P1 Revert Hyper Roll 7", 0x4E064 },
    { "P1 Revert Hyper Roll 8", 0x4E084 }, // 5d

    { "P1 Megaman", 0x4E0a4, 0x1c }, // 5e
    { "P1 Magnetic Shockwave Megaman", 0x4E0c4, 0x1c }, // 5f

    { "P2 Hair ", 0x4E0e4 },
    { "P2 Intro / Death Animation", 0x4E104 },

    { "P2 Intro 1", 0x4E124, 0x1d },
    { "P2 Intro 2", 0x4E144, 0x1d },
    { "P2 Intro 3", 0x4E164, 0x1d },
    { "P2 Intro 4", 0x4E184, 0x1d },
    { "P2 Intro 5", 0x4E1A4, 0x1d },
    { "P2 Intro 6", 0x4E1C4, 0x1d },
    { "P2 Intro 7", 0x4E1E4, 0x1d },
    { "P2 Intro 8", 0x4E204, 0x1d },
    { "P2 Intro 9", 0x4E224, 0x1d },

    { "P2 Rush/Eddie 1", 0x4E244 },
    { "P2 Rush/Eddie 2", 0x4E264 },
    { "P2 Rush/Eddie 3", 0x4E284 },
    { "P2 Rush/Eddie 4", 0x4E2A4 },
    { "P2 Rush/Eddie 5", 0x4E2C4 },
    { "P2 Rush/Eddie 6", 0x4E2E4 },
    { "P2 Rush/Eddie 7", 0x4E304 },
    { "P2 Rush/Eddie 8", 0x4E324 },
    { "P2 Rush/Eddie 9", 0x4E344 },

    { "P2 Beat 1", 0x4E364 },
    { "P2 Beat 2", 0x4E384 },
    { "P2 Beat 3", 0x4E3A4 },
    { "P2 Beat 4", 0x4E3C4 },
    { "P2 Beat 5", 0x4E3E4 },
    { "P2 Beat 6", 0x4E404 },
    { "P2 Beat 7", 0x4E424 },
    { "P2 Beat 8", 0x4E444 },
    { "P2 Beat 9", 0x4E464 },

    { "P2 Beat Plane 1", 0x4E484 },
    { "P2 Beat Plane 2", 0x4E4A4 },
    { "P2 Beat Plane 3", 0x4E4C4 },
    { "P2 Beat Plane 4", 0x4E4E4 },
    { "P2 Beat Plane 5", 0x4E504 },
    { "P2 Beat Plane 6", 0x4E524 },
    { "P2 Beat Plane 7", 0x4E544 },
    { "P2 Beat Plane 8", 0x4E564 },
    { "P2 Beat Plane 9", 0x4E584 },

    { "P2 Charging Roll 1", 0x4E5A4, 0x1d },
    { "P2 Charging Roll 2", 0x4E5C4, 0x1d },
    { "P2 Charging Roll 3", 0x4E5E4, 0x1d },
    { "P2 Charging Roll 4", 0x4E604, 0x1d },
    { "P2 Charging Roll 5", 0x4E624, 0x1d },
    { "P2 Charging Roll 6", 0x4E644, 0x1d },
    { "P2 Charging Roll 7", 0x4E664, 0x1d },
    { "P2 Charging Roll 8", 0x4E684, 0x1d },
    { "P2 Charging Roll 9", 0x4E6A4, 0x1d },

    { "P2 Rush Drill 1", 0x4E6C4 },
    { "P2 Rush Drill 2", 0x4E6E4 },
    { "P2 Rush Drill 3", 0x4E704 },
    { "P2 Rush Drill 4", 0x4E724 },
    { "P2 Rush Drill 5", 0x4E744 },
    { "P2 Rush Drill 6", 0x4E764 },
    { "P2 Rush Drill 7", 0x4E784 },
    { "P2 Rush Drill 8", 0x4E7A4 },
    { "P2 Rush Drill 9", 0x4E7C4 },

    { "P2 Teleport Intro", 0x4E7E4 },
    { "P2 Dr Light", 0x4E804 },

    { "P2 Hyper Roll Armor 1", 0x4E824 },
    { "P2 Hyper Roll Armor 2", 0x4E844 },
    { "P2 Hyper Roll Armor 3", 0x4E864 },
    { "P2 Hyper Roll Armor 4", 0x4E884 },
    { "P2 Hyper Roll Armor 5", 0x4E8A4 },
    { "P2 Hyper Roll Armor 6", 0x4E8C4 },
    { "P2 Hyper Roll Armor 7", 0x4E8E4 },
    { "P2 Hyper Roll Armor 8", 0x4E904 },
    { "P2 Hyper Roll Armor 9", 0x4E924 },

    { "P2 Megaman Intro 1", 0x4E944, 0x1c },
    { "P2 Megaman Intro 2", 0x4E964, 0x1c },
    { "P2 Megaman Intro 3", 0x4E984, 0x1c },
    { "P2 Megaman Intro 4", 0x4E9A4, 0x1c },
    { "P2 Megaman Intro 5", 0x4E9C4, 0x1c },
    { "P2 Megaman Intro 6", 0x4E9E4, 0x1c },
    { "P2 Megaman Intro 7", 0x4EA04, 0x1c },
    { "P2 Megaman Intro 8", 0x4EA24, 0x1c },
    { "P2 Megaman Intro 9", 0x4EA44, 0x1c }, // 54ish

    { "P2 Hyper Roll Missiles", 0x4EA64 }, // 55

    { "P2 Revert Hyper Roll 1", 0x4EA84 },
    { "P2 Revert Hyper Roll 2", 0x4EAA4 },
    { "P2 Revert Hyper Roll 3", 0x4EAC4 },
    { "P2 Revert Hyper Roll 4", 0x4EAE4 },
    { "P2 Revert Hyper Roll 5", 0x4EB04 },
    { "P2 Revert Hyper Roll 6", 0x4EB24 },
    { "P2 Revert Hyper Roll 7", 0x4EB44 },
    { "P2 Revert Hyper Roll 8", 0x4EB64 }, // 5d

    { "P2 Megaman", 0x4EB84, 0x1c }, // 5e
    { "P2 Magnetic Shockwave Megaman", 0x4EBA4, 0x1c }, // 5f
};

const sMVC_PaletteDataset MVC_A_ONSLAUGHT_PALETTES[] =
{
    { "Palette 1",    0x49044 },
    { "Palette 2",    0x49064 },
    { "Palette 3",    0x49084 },
};

const sMVC_PaletteDataset MVC_A_WARMACHINE_PALETTES[] =
{
    { "P1 Color",         0x481C4, 0x33 },
    { "P1 Proton Cannon", 0x481E4, 0x33, 1 }, // same sprites as iron man
    { "P1 Proton Laser",  0x48204, 0x33, 2 },
    { "P2 Color",         0x48224, 0x33 },
    { "P2 Proton Cannon", 0x48244, 0x33, 1 },
    { "P2 Proton Laser",  0x48264, 0x33, 2 },
};

const sMVC_PaletteDataset MVC_A_GOLDWARMACHINE_PALETTES[] =
{
    { "P1 Color",         0x49224, 0x33 },
    { "P1 Proton Cannon", 0x49244, 0x33, 1 }, // same sprites as iron man
    { "P1 Proton Laser",  0x49264, 0x33, 2 },
    { "P2 Color",         0x49284, 0x33 },
    { "P2 Proton Cannon", 0x492a4, 0x33, 1 },
    { "P2 Proton Laser",  0x492c4, 0x33, 2 },
};

const sMVC_PaletteDataset MVC_A_CAPAM_PALETTES[] =
{
    { "P1 Color",         0x48284, 0xb },
    { "P1 Shield",        0x482A4, 0xb, 1 },
    { "P1 Charging Star", 0x482C4, 0xb, 2 },
    { "P2 Color",         0x482E4, 0xb },
    { "P2 Shield",        0x48304, 0xb, 1 },
    { "P2 Charging Star", 0x48324, 0xb, 2 },
};

const sMVC_PaletteDataset MVC_A_HULK_PALETTES[] =
{
    { "P1 Color",       0x48344, 0xD },
    { "P1 Charge",      0x48364, 0xD, 1 },
    { "P1 Gamma Quake", 0x48384, 0xD, 2 },
    { "P2 Color",       0x483A4, 0xD },
    { "P2 Charge",      0x483C4, 0xD, 1 },
    { "P2 Gamma Quake", 0x483E4, 0xD, 2 },
};

const sMVC_PaletteDataset MVC_A_ORANGEHULK_PALETTES[] =
{
    { "P1 Color",       0x49164, 0xD },
    { "P1 Charge",      0x49184, 0xD, 1 },
    { "P1 Gamma Quake", 0x491A4, 0xD, 2 },
    { "P2 Color",       0x491C4, 0xD },
    { "P2 Charge",      0x491E4, 0xD, 1 },
    { "P2 Gamma Quake", 0x49204, 0xD, 2 },
};

const sMVC_PaletteDataset MVC_A_WOLVERINE_PALETTES[] =
{
    { "P1 Color",        0x48404, 0x7 },
    { "P1 Claws",        0x48424, 0x7, 1 },
    { "P1 Berserker FX", 0x48444, 0x7, 2 },
    { "P2 Color",        0x48464, 0x7 },
    { "P2 Claws",        0x48484, 0x7, 1 },
    { "P2 Berserker FX", 0x484A4, 0x7, 2 },
};

const sMVC_PaletteDataset MVC_A_VENOM_PALETTES[] =
{
    { "P1 Color",    0x48584, 0xe },
    { "P1 Taunt",    0x485A4, 0xe, 1 },
    { "P1 Web",      0x485C4, 0xe, 2 },
    { "P2 Color",    0x485E4, 0xe },
    { "P2 Taunt",    0x48604, 0xe, 1 },
    { "P2 Web",      0x48624, 0xe, 2 },
};

const sMVC_PaletteDataset MVC_A_HYPERVENOM_PALETTES[] =
{
    { "P1 Color",    0x490A4, 0xe },
    { "P1 Taunt",    0x490C4, 0xe, 1 },
    { "P1 Web",      0x490E4, 0xe, 2 },
    { "P2 Color",    0x49104, 0xe },
    { "P2 Taunt",    0x49124, 0xe, 1 },
    { "P2 Web",      0x49144, 0xe, 2 },
};

const sMVC_PaletteDataset MVC_A_SPIDEY_PALETTES[] =
{
    { "P1 Color",    0x48644, 0xc },
    { "P1 Extra 1",  0x48664 },
    { "P1 Web",      0x48684, 0xc, 2 },
    { "P2 Color",    0x486A4, 0xc },
    { "P2 Extra 1",  0x486C4},
    { "P2 Web",      0x486E4, 0xc, 2 },
};

const sMVC_PaletteDataset MVC_A_CAPCOM_PALETTES[] =
{
    { "P1 Color",  0x48884, 0x38 },
    { "P1 Ninjas", 0x488A4, 0x38, 1 },
    { "P1 Hoover", 0x488C4, 0x38, 2 },
    { "P2 Color",  0x488E4, 0x38 },
    { "P2 Ninjas", 0x48904, 0x38, 1 },
    { "P2 Hoover", 0x48924, 0x38, 2 },
};

const sMVC_PaletteDataset MVC_A_MORRIGAN_PALETTES[] =
{
    { "P1 Color",  0x48ec4, 0x3 },
    { "P1 Lilith", 0x48eE4, 0x3, 1 },
    { "P1 Extra 2", 0x48f04, 0x3, 2 },
    { "P2 Color",  0x48f24, 0x3 },
    { "P2 Lilith", 0x48f44, 0x3, 1 },
    { "P2 Extra 2", 0x48f64, 0x3, 2 },
};

const sMVC_PaletteDataset MVC_A_LILITH_PALETTES[] =
{
    { "P1 Color",  0x493A4, 0x3 },
    { "P1 Extra 1", 0x493C4, 0x3, 1 },
    { "P1 Extra 2", 0x493E4, 0x3, 2 },
    { "P2 Color",  0x49404, 0x3 },
    { "P2 Extra 1", 0x49424, 0x3, 1 },
    { "P2 Extra 2", 0x49444, 0x3, 2 },
};

const sMVC_PaletteDataset MVC_A_STRIDER_PALETTES[] =
{
    { "P1 Color", 0x48E04, 0x05 },
    { "P1 FX",    0x48E24, 0x05, 1 },
    { "P1 Mech",  0x48E44, 0x05, 2 },
    { "P2 Color", 0x48E64, 0x05 },
    { "P2 FX",    0x48E84, 0x05, 1 },
    { "P2 Mech",  0x48EA4, 0x05, 2 },
};

const sMVC_PaletteDataset MVC_A_GAMBIT_PALETTES[] =
{
    { "P1 Color",   0x484c4, 0x28 },
    { "P1 Extra 1", 0x484E4, 0x28, 1 },
    { "P1 Extra 2", 0x48504, 0x28, 2 },
    { "P2 Color",   0x48524, 0x28 },
    { "P2 Extra 1", 0x48544, 0x28, 1 },
    { "P2 Extra 2", 0x48564, 0x28, 2 },
};

const sMVC_PaletteDataset MVC_A_ASSIST_PALETTES[] =
{
    { "Anita P1", 0x50FA4 },
    { "Anita P1 Extra 1", 0x50FC4 },
    { "Anita P1 Extra 2", 0x50FE4 },
    { "Anita P2", 0x51004 },
    { "Anita P2 Extra 1", 0x51024 },
    { "Anita P2 Extra 2", 0x51044 },

    { "Arthur P1", 0x50804 },
    { "Arthur P1 Extra 1", 0x50824 },
    { "Arthur P1 Extra 2", 0x50844 },
    { "Arthur P2", 0x50864 },
    { "Arthur P2 Extra 1", 0x50884 },
    { "Arthur P2 Extra 2", 0x508A4 },

    { "Colossus P1", 0x505C4, 0x32 },
    { "Colossus P2", 0x50624, 0x32 },

    { "Cyclops P1", 0x50504, 0x6 },
    { "Cyclops P2", 0x50564, 0x6 },
    { "Cyclops Optic Blast 1", 0x508C4 },
    { "Cyclops Optic Blast 2", 0x508E4 },
    { "Cyclops Optic Blast 3", 0x50904 },
    { "Cyclops Optic Blast 4", 0x50924 },
    { "Cyclops Optic Blast 5", 0x50944 },

    { "Devilot P1", 0x510C4 },
    { "Devilot P1 Extra 1", 0x510E4 },
    { "Devilot P1 Extra 2", 0x51104 },
    { "Devilot P1 Extra 3", 0x51184 },
    { "Devilot P1 Extra 4", 0x511A4 },
    { "Devilot P2", 0x51124 },
    { "Devilot P2 Extra 1", 0x51144 },
    { "Devilot P2 Extra 2", 0x51164 },
    { "Devilot P2 Extra 3", 0x511C4 },
    { "Devilot P2 Extra 4", 0x511E4 },

    { "Iceman P1", 0x50D64, 0x9 },
    { "Iceman P1 Extra 1", 0x50D84, 0x9 },
    { "Iceman P1 Extra 2", 0x50DA4, 0x9 },
    { "Iceman P2", 0x50DC4, 0x9 },
    { "Iceman P2 Extra 1", 0x50DE4, 0x9 },
    { "Iceman P2 Extra 2", 0x50E04, 0x9 },

    { "Jubilee P1", 0x51204 },
    { "Jubilee P2", 0x51264 },

    { "Juggernaut P1", 0x502C4, 0x29 },
    { "Juggernaut P1 Extra 1", 0x50304, 0x29, 2 },
    { "Juggernaut P2", 0x50324, 0x29 },
    { "Juggernaut P2 Extra 1", 0x50364, 0x29, 2 },

    { "Lou P1", 0x50204 },
    { "Lou P1 Extra", 0x50224 },
    { "Lou P2", 0x50264 },
    { "Lou P2 Extra", 0x50284 },

    { "Magneto P1", 0x50384, 0x2c },
    { "Magneto P1 Extra", 0x503A4, 0x2c, 1 },
    { "Magneto P2", 0x503E4, 0x2c },
    { "Magneto P2 Extra", 0x50404, 0x2c, 1 },

    { "Michelle Heart P1", 0x50A24 },
    { "Michelle Heart P1 Extra", 0x50A44 },
    { "Michelle Heart P2", 0x50A84 },
    { "Michelle Heart P2 Extra", 0x50AA4 },

    { "Psylocke P1", 0x50444, 0x8 },
    { "Psylocke P1 Extra", 0x50464, 0x8, 2 },
    { "Psylocke P2", 0x504A4, 0x8 },
    { "Psylocke P2 Extra", 0x504C4, 0x8, 2 },

    { "Pure & Fur P1", 0x50E24 },
    { "Pure & Fur P1 Extra 1", 0x50E44 },
    { "Pure & Fur P1 Extra 2", 0x50E64 },
    { "Pure & Fur P2", 0x50E84 },
    { "Pure & Fur P2 Extra 1", 0x50EA4 },
    { "Pure & Fur P2 Extra 2", 0x50EC4 },

    { "Rogue P1", 0x50CA4, 0xa },
    { "Rogue P2", 0x50D04, 0xa },

    { "Saki P1", 0x50964 },
    { "Saki P1 Extra", 0x50984 },
    { "Saki P2", 0x509C4 },
    { "Saki P2 Extra", 0x509E4 },

    { "Sentinel P1", 0x51344, 0x34 },
    { "Sentinel P2", 0x513A4, 0x34 },

    { "Shadow Nash P1", 0x51284, 0x21 },
    { "Shadow Nash P1 Extra", 0x512C4, 0x21, 2 },
    { "Shadow Nash P2", 0x512E4, 0x21 },
    { "Shadow Nash P2 Extra", 0x51324, 0x21, 2 },

    { "Storm P1", 0x50BA4, 0x2a },
    { "Storm P1 Extra", 0x50C64, 0x2a, 0xc },
    { "Storm P2", 0x50C04, 0x2a },
    { "Storm P2 Extra", 0x50C84, 0x2a, 0xc },

    { "Ton-Pooh P1", 0x50744 },
    { "Ton-Pooh P1 Extra 1", 0x50764 },
    { "Ton-Pooh P1 Extra 2", 0x50784 },
    { "Ton-Pooh P2", 0x507A4 },
    { "Ton-Pooh P2 Extra 1", 0x507C4 },
    { "Ton-Pooh P2 Extra 2", 0x507E4 },

    { "Thor P1", 0x50AE4 },
    { "Thor P1 Extra", 0x50B04 },
    { "Thor P2", 0x50B44 },
    { "Thor P2 Extra", 0x50B64 },

    { "Unknown Soldier P1", 0x50684 },
    { "Unknown Soldier P1 Extra", 0x506A4 },
    { "Unknown Soldier P2", 0x506E4 },
    { "Unknown Soldier P2 Extra", 0x50704 },

    { "US Agent P1", 0x50EE4, 0xb },
    { "US Agent P1 Shield", 0x50F04, 0xb, 1 },
    { "US Agent P1 Charging Star", 0x50F24, 0xb, 2 },
    { "US Agent P2", 0x50F44, 0xb },
    { "US Agent P2 Shield", 0x50F64, 0xb, 1 },
    { "US Agent P2 Charging Star", 0x50F84, 0xb, 2 },
};

const UINT8 MVC_A_UNITSORT[MVC_A_NUMUNIT + 1] = //Plus 1 for the extra palettes
{
    indexCaptainAmerica,
    indexCapCom,
    indexChun,
    indexGambit,
    indexHulk,
    indexJin,
    indexLilith,
    indexMegaman,
    indexMorrigan,
    indexOnslaught,
    indexOrangeHulk,
    indexRoll,
    indexRyu,
    indexShadowLady,
    indexSpiderman,
    indexStrider,
    indexVenom,
    indexHyperVenom,
    indexWarMachine,
    indexGWM,
    indexWolverine,
    indexGief,
    indexAssists,

    MVC_A_EXTRALOC //Extra palettes
};

const char MVC_A_IMGDESC[6][MAX_DESCRIPTION_LENGTH] =
{
    "P1 Color",
    "Palette 2",
    "Palette 3",
    "P2 Color",
    "Palette 5",
    "Palette 6"
};

const char MVC_A_UNITDESC[MVC_A_NUMUNIT][MAX_DESCRIPTION_LENGTH] =
{
    "War Machine",
    "Captain America",
    "Hulk",
    "Wolverine",
    "Venom",
    "Spider-Man",
    "Roll",
    "Ryu",
    "Captain Commando",
    "Chun-Li",
    "Jin",
    "Zangief",
    "Strider",
    "Megaman",
    "Morrigan",
    "Onslaught",
    "Red Venom",
    "Orange Hulk",
    "Gold War Machine",
    "Shadow Lady",
    "Lilith",
    "Gambit",
    "Assists",
};

const UINT16 MVC_A_PALAMT[MVC_A_NUMUNIT] = {

    ARRAYSIZE(MVC_A_WARMACHINE_PALETTES), // WM
    ARRAYSIZE(MVC_A_CAPAM_PALETTES), // CapAm
    ARRAYSIZE(MVC_A_HULK_PALETTES), // Hulk
    ARRAYSIZE(MVC_A_WOLVERINE_PALETTES), // Wolvie
    ARRAYSIZE(MVC_A_VENOM_PALETTES), // Venom
    ARRAYSIZE(MVC_A_SPIDEY_PALETTES), // Spidey
    ARRAYSIZE(MVC_A_ROLL_PALETTES), // Roll
    ARRAYSIZE(MVC_A_RYU_PALETTES), // Ryu
    ARRAYSIZE(MVC_A_CAPCOM_PALETTES), // Capcom
    ARRAYSIZE(MVC_A_CHUNLI_PALETTES), // Chun
    ARRAYSIZE(MVC_A_JIN_PALETTES), // Jin
    ARRAYSIZE(MVC_A_GIEF_PALETTES), // Gief & MechaGief
    ARRAYSIZE(MVC_A_STRIDER_PALETTES), // Strider    
    ARRAYSIZE(MVC_A_MEGAMAN_PALETTES), // Megaman
    ARRAYSIZE(MVC_A_MORRIGAN_PALETTES), // Morrigan
    ARRAYSIZE(MVC_A_ONSLAUGHT_PALETTES), // Onslaught
    ARRAYSIZE(MVC_A_HYPERVENOM_PALETTES), // Red Venom
    ARRAYSIZE(MVC_A_ORANGEHULK_PALETTES), // Orange Hulk
    ARRAYSIZE(MVC_A_GOLDWARMACHINE_PALETTES), // Gold War Machine
    ARRAYSIZE(MVC_A_SHADOWLADY_PALETTES), // Shadow Lady
    ARRAYSIZE(MVC_A_LILITH_PALETTES), // Lilith
    ARRAYSIZE(MVC_A_GAMBIT_PALETTES), // Gambit
    ARRAYSIZE(MVC_A_ASSIST_PALETTES), // Assists
};

const UINT16 MVC_A_IMGREDIR[MVC_A_NUMUNIT] = {

    0x33, // WM
    0x0B, // CapAm
    0x0D, // Hulk
    0x07, // Wolvie
    0x0E, // Venom
    0x0C, // Spidey
    0x1D, // Roll
    0x00, // Ryu
    0x38, // Capcom
    0x1B, // Chun
    0x37, // Jin
    0x01, // gieeeeef
    0x05, // strider
    0x1C, // megaman
    0x03, // morrigan
    MVC_A_IMGSTART, // onslaughter
    0x0E, // red venom
    0x0D, // orange hulk
    0x33, // gwm
    0x1B, // shadow lady
    0x03, // lilith
    0x28, // gambit
    0xFF, // :( Assists ... we don't have anything. 
};

// We extend this array with data groveled from the mvce.txt extensible extras file, if any.
const stExtraDef MVC_A_EXTRA[] =
{
    //Start

    { UNIT_START_VALUE },

    { INVALID_UNIT_VALUE }
};
