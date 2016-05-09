#include "../inc/include.h"







static const u16 _palette [ 16 ] =
{
	0x0000,	0x0FFF,	0x0444,	0x0000,
	0x0000,	0x0000,	0x0000,	0x0000,
	0x0000,	0x0000,	0x0000,	0x0000,
	0x0000,	0x0000,	0x0000,	0x0000
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void font_init ()
{
	const u32 _tile[8] = {};

	//VDP_loadFont ( cb_font_8x8, 1 );
	VDP_loadFontData ( cb_font_8x8, FONT_LEN, 0 );

	// carga los caract�res especiales
	VDP_loadTileData ( (u32*)cb_font_8x8_spa, TILE_FONTINDEX-15, 15, 0);

	// hack for VDP_loadFont, inserts " " in 0 position
	VDP_loadTileData ( _tile, TILE_FONTINDEX-15, 1, 0 );
	VDP_loadTileData ( _tile, TILE_FONTINDEX-00, 1, 0 );
}


void font_setPalette()
{
	VDP_setTextPalette  ( PAL0 );
	VDP_setPaletteColor ( PAL0+0, _palette[0] );
	VDP_setPaletteColor ( PAL0+1, _palette[1] );
	VDP_setPaletteColor ( PAL0+2, _palette[2] );
}


u16 *font_getPalette ( )
{
	return ( u16*) _palette;
}