#include "../../inc/include.h"
//#include "../../res/all/screens.h"

#define IMAGES  1


void screen_publisher ( )
{
    if ( DEV > 1 ) return;

	displayOff(0);

	VDP_setScreenWidth320();
	VDP_setPlanSize ( 64, 32 );

//	palette_init();
	vram_init ( VRAM_DEFAULT );

	resetScroll();
	resetScreen();


	const u16 x = 12;
	const u16 y = 8;


	u16 i, vram_pos [ IMAGES ];


	Image *images [ IMAGES ] =
	{
		(Image*) &screen_publisher_00
	};

	for ( i=0; i<IMAGES; i++ )
	{
		u16 size = images[i]->tileset->numTile;
		vram_pos [ i ] = vram_new ( size );
		SYS_disableInts();
		VDP_loadTileData ( images[i]->tileset->tiles, vram_pos[i], size, 0 );
		SYS_enableInts();
	}


	waitHz(20);

	for ( i=0; i<IMAGES; i++ )
	{
		waitHz(3);

		SYS_disableInts();
		preparePal ( PAL1, images[i]->palette->data );
		VDP_setMap ( PLAN_A, images[i]->map,TILE_ATTR_FULL ( PAL1, 0, 0, 0, vram_pos[i] ), x, y );
		SYS_enableInts();
	}

	vram_destroy();
	displayOn(10);

	waitJoySc(6);

	displayOff(10);
	//musicStop ( );
}
