/*
 *  Source machine generated by GadToolsBox V2.0b
 *  which is (c) Copyright 1991-1993 Jaba Development
 *
 *  GUI Designed by : Christian Bauer
 */

#include <exec/types.h>
#include <intuition/intuition.h>
#include <intuition/classes.h>
#include <intuition/classusr.h>
#include <intuition/imageclass.h>
#include <intuition/gadgetclass.h>
#include <libraries/gadtools.h>
#include <graphics/displayinfo.h>
#include <graphics/gfxbase.h>
#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/gadtools_protos.h>
#include <clib/graphics_protos.h>
#include <clib/utility_protos.h>
#include <string.h>
#include "AmigaGUI.h"

struct Screen         *Scr = NULL;
UBYTE                 *PubScreenName = NULL;
APTR                   VisualInfo = NULL;
struct Window         *PrefsWnd = NULL;
struct Gadget         *PrefsGList = NULL;
struct Menu           *PrefsMenus = NULL;
struct IntuiMessage    PrefsMsg;
UWORD                  PrefsZoom[4];
struct Gadget         *PrefsGadgets[31];
UWORD                  PrefsLeft = 0;
UWORD                  PrefsTop = 16;
UWORD                  PrefsWidth = 561;
UWORD                  PrefsHeight = 238;
UBYTE                 *PrefsWdt = (UBYTE *)"Frodo Preferences";
struct TextAttr       *Font, Attr;
UWORD                  FontX, FontY;
UWORD                  OffX, OffY;

UBYTE *SIDType0Labels[] = {
	(UBYTE *)"None",
	(UBYTE *)"Digital (AHI)",
	(UBYTE *)"SID Card",
	NULL };

UBYTE *REUSize0Labels[] = {
	(UBYTE *)"None",
	(UBYTE *)"128K",
	(UBYTE *)"256K",
	(UBYTE *)"512K",
	NULL };

UBYTE *DriveType80Labels[] = {
	(UBYTE *)"DIR",
	(UBYTE *)"D64",
	(UBYTE *)"T64",
	NULL };

UBYTE *DriveType90Labels[] = {
	(UBYTE *)"DIR",
	(UBYTE *)"D64",
	(UBYTE *)"T64",
	NULL };

UBYTE *DriveType100Labels[] = {
	(UBYTE *)"DIR",
	(UBYTE *)"D64",
	(UBYTE *)"T64",
	NULL };

UBYTE *DriveType110Labels[] = {
	(UBYTE *)"DIR",
	(UBYTE *)"D64",
	(UBYTE *)"T64",
	NULL };

struct IntuiText PrefsIText[] = {
	2, 0, JAM1,34, 115, NULL, (UBYTE *)"Drive", NULL };

#define Prefs_TNUM 1

struct NewMenu PrefsNewMenu[] = {
	NM_TITLE, (STRPTR)"Preferences", NULL, 0, NULL, NULL,
	NM_ITEM, (STRPTR)"Open...", (STRPTR)"O", 0, 0L, (APTR)PrefsOpen,
	NM_ITEM, (STRPTR)"Save", (STRPTR)"S", 0, 0L, (APTR)PrefsSave,
	NM_ITEM, (STRPTR)"Save As...", (STRPTR)"A", 0, 0L, (APTR)PrefsSaveAs,
	NM_ITEM, (STRPTR)"Revert", (STRPTR)"R", 0, 0L, (APTR)PrefsRevert,
	NM_ITEM, (STRPTR)NM_BARLABEL, NULL, 0, 0L, NULL,
	NM_ITEM, (STRPTR)"OK", NULL, 0, 0L, (APTR)PrefsOK,
	NM_ITEM, (STRPTR)"Cancel", NULL, 0, 0L, (APTR)PrefsCancel,
	NM_END, NULL, NULL, 0, 0L, NULL };

UWORD PrefsGTypes[] = {
	CHECKBOX_KIND,
	CHECKBOX_KIND,
	CHECKBOX_KIND,
	CHECKBOX_KIND,
	CHECKBOX_KIND,
	CHECKBOX_KIND,
	CHECKBOX_KIND,
	CHECKBOX_KIND,
	INTEGER_KIND,
	INTEGER_KIND,
	INTEGER_KIND,
	INTEGER_KIND,
	INTEGER_KIND,
	CYCLE_KIND,
	CYCLE_KIND,
	STRING_KIND,
	CYCLE_KIND,
	STRING_KIND,
	CYCLE_KIND,
	STRING_KIND,
	CYCLE_KIND,
	STRING_KIND,
	CYCLE_KIND,
	CHECKBOX_KIND,
	CHECKBOX_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND
};

struct NewGadget PrefsNGad[] = {
	8, 4, 26, 11, (UBYTE *)"Sprite display", NULL, GD_SpritesOn, PLACETEXT_RIGHT, NULL, (APTR)SpritesOnClicked,
	8, 16, 26, 11, (UBYTE *)"Sprite collisions", NULL, GD_SpriteCollisions, PLACETEXT_RIGHT, NULL, (APTR)SpriteCollisionsClicked,
	8, 28, 26, 11, (UBYTE *)"Joystick connected", NULL, GD_Joystick2On, PLACETEXT_RIGHT, NULL, (APTR)Joystick2OnClicked,
	8, 40, 26, 11, (UBYTE *)"Map joystick to port 1", NULL, GD_JoystickSwap, PLACETEXT_RIGHT, NULL, (APTR)JoystickSwapClicked,
	8, 52, 26, 11, (UBYTE *)"Limit speed", NULL, GD_LimitSpeed, PLACETEXT_RIGHT, NULL, (APTR)LimitSpeedClicked,
	8, 64, 26, 11, (UBYTE *)"Fast reset", NULL, GD_FastReset, PLACETEXT_RIGHT, NULL, (APTR)FastResetClicked,
	8, 76, 26, 11, (UBYTE *)"Clear CIA ICR on write", NULL, GD_CIAIRQHack, PLACETEXT_RIGHT, NULL, (APTR)CIAIRQHackClicked,
	8, 88, 26, 11, (UBYTE *)"SID filters", NULL, GD_SIDFilters, PLACETEXT_RIGHT, NULL, (APTR)SIDFiltersClicked,
	490, 4, 65, 14, (UBYTE *)"Cycles per line (CPU)", NULL, GD_NormalCycles, PLACETEXT_LEFT, NULL, (APTR)NormalCyclesClicked,
	490, 19, 65, 14, (UBYTE *)"Cycles per Bad Line (CPU)", NULL, GD_BadLineCycles, PLACETEXT_LEFT, NULL, (APTR)BadLineCyclesClicked,
	490, 34, 65, 14, (UBYTE *)"Cycles per line (CIA)", NULL, GD_CIACycles, PLACETEXT_LEFT, NULL, (APTR)CIACyclesClicked,
	490, 49, 65, 14, (UBYTE *)"Cycles per line (1541)", NULL, GD_FloppyCycles, PLACETEXT_LEFT, NULL, (APTR)FloppyCyclesClicked,
	490, 64, 65, 14, (UBYTE *)"Draw every n-th frame", NULL, GD_SkipFrames, PLACETEXT_LEFT, NULL, (APTR)SkipFramesClicked,
	426, 79, 129, 14, (UBYTE *)"SID emulation type", NULL, GD_SIDType, PLACETEXT_LEFT, NULL, (APTR)SIDTypeClicked,
	426, 94, 129, 14, (UBYTE *)"REU size", NULL, GD_REUSize, PLACETEXT_LEFT, NULL, (APTR)REUSizeClicked,
	47, 123, 401, 14, (UBYTE *)"8", NULL, GD_DrivePath8, PLACETEXT_LEFT, NULL, (APTR)DrivePath8Clicked,
	470, 123, 65, 14, NULL, NULL, GD_DriveType8, 0, NULL, (APTR)DriveType8Clicked,
	47, 138, 401, 14, (UBYTE *)"9", NULL, GD_DrivePath9, PLACETEXT_LEFT, NULL, (APTR)DrivePath9Clicked,
	470, 138, 65, 14, NULL, NULL, GD_DriveType9, 0, NULL, (APTR)DriveType9Clicked,
	47, 153, 401, 14, (UBYTE *)"10", NULL, GD_DrivePath10, PLACETEXT_LEFT, NULL, (APTR)DrivePath10Clicked,
	470, 153, 65, 14, NULL, NULL, GD_DriveType10, 0, NULL, (APTR)DriveType10Clicked,
	47, 168, 401, 14, (UBYTE *)"11", NULL, GD_DrivePath11, PLACETEXT_LEFT, NULL, (APTR)DrivePath11Clicked,
	470, 168, 65, 14, NULL, NULL, GD_DriveType11, 0, NULL, (APTR)DriveType11Clicked,
	20, 186, 26, 11, (UBYTE *)"Map '/'<->'\' in filenames", NULL, GD_MapSlash, PLACETEXT_RIGHT, NULL, (APTR)MapSlashClicked,
	20, 198, 26, 11, (UBYTE *)"Enable 1541 processor emulation", NULL, GD_Emul1541Proc, PLACETEXT_RIGHT, NULL, (APTR)Emul1541ProcClicked,
	61, 218, 81, 16, (UBYTE *)"_OK", NULL, GD_OK, PLACETEXT_IN, NULL, (APTR)OKClicked,
	416, 218, 81, 16, (UBYTE *)"_Cancel", NULL, GD_Cancel, PLACETEXT_IN, NULL, (APTR)CancelClicked,
	448, 123, 20, 14, (UBYTE *)"�", NULL, GD_GetDrive8, PLACETEXT_IN, NULL, (APTR)GetDrive8Clicked,
	448, 138, 20, 14, (UBYTE *)"�", NULL, GD_GetDrive9, PLACETEXT_IN, NULL, (APTR)GetDrive9Clicked,
	448, 153, 20, 14, (UBYTE *)"�", NULL, GD_GetDrive10, PLACETEXT_IN, NULL, (APTR)GetDrive10Clicked,
	448, 168, 20, 14, (UBYTE *)"�", NULL, GD_GetDrive11, PLACETEXT_IN, NULL, (APTR)GetDrive11Clicked
};

ULONG PrefsGTags[] = {
	(TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(GTIN_Number), 0, (GTIN_MaxChars), 10, (STRINGA_Justification), (GACT_STRINGRIGHT), (TAG_DONE),
	(GTIN_Number), 0, (GTIN_MaxChars), 10, (STRINGA_Justification), (GACT_STRINGRIGHT), (TAG_DONE),
	(GTIN_Number), 0, (GTIN_MaxChars), 10, (STRINGA_Justification), (GACT_STRINGRIGHT), (TAG_DONE),
	(GTIN_Number), 0, (GTIN_MaxChars), 10, (STRINGA_Justification), (GACT_STRINGRIGHT), (TAG_DONE),
	(GTIN_Number), 0, (GTIN_MaxChars), 10, (STRINGA_Justification), (GACT_STRINGRIGHT), (TAG_DONE),
	(GTCY_Labels), (ULONG)&SIDType0Labels[ 0 ], (TAG_DONE),
	(GTCY_Labels), (ULONG)&REUSize0Labels[ 0 ], (TAG_DONE),
	(GTST_MaxChars), 256, (TAG_DONE),
	(GTCY_Labels), (ULONG)&DriveType80Labels[ 0 ], (TAG_DONE),
	(GTST_MaxChars), 256, (TAG_DONE),
	(GTCY_Labels), (ULONG)&DriveType90Labels[ 0 ], (TAG_DONE),
	(GTST_MaxChars), 256, (TAG_DONE),
	(GTCY_Labels), (ULONG)&DriveType100Labels[ 0 ], (TAG_DONE),
	(GTST_MaxChars), 256, (TAG_DONE),
	(GTCY_Labels), (ULONG)&DriveType110Labels[ 0 ], (TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(GT_Underscore), '_', (TAG_DONE),
	(GT_Underscore), '_', (TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(TAG_DONE),
	(TAG_DONE)
};

static UWORD ComputeX( UWORD value )
{
	return(( UWORD )((( FontX * value ) + 4 ) / 8 ));
}

static UWORD ComputeY( UWORD value )
{
	return(( UWORD )((( FontY * value ) + 4 ) / 8 ));
}

static void ComputeFont( UWORD width, UWORD height )
{
	Font = &Attr;
	Font->ta_Name = (STRPTR)Scr->RastPort.Font->tf_Message.mn_Node.ln_Name;
	Font->ta_YSize = FontY = Scr->RastPort.Font->tf_YSize;
	FontX = Scr->RastPort.Font->tf_XSize;

	OffX = Scr->WBorLeft;
	OffY = Scr->RastPort.TxHeight + Scr->WBorTop + 1;

	if ( width && height ) {
		if (( ComputeX( width ) + OffX + Scr->WBorRight ) > Scr->Width )
			goto UseTopaz;
		if (( ComputeY( height ) + OffY + Scr->WBorBottom ) > Scr->Height )
			goto UseTopaz;
	}
	return;

UseTopaz:
	Font->ta_Name = (STRPTR)"topaz.font";
	FontX = FontY = Font->ta_YSize = 8;
}

int SetupScreen( void )
{
	if ( ! ( Scr = LockPubScreen( PubScreenName )))
		return( 1L );

	ComputeFont( 0, 0 );

	if ( ! ( VisualInfo = GetVisualInfo( Scr, TAG_DONE )))
		return( 2L );

	return( 0L );
}

void CloseDownScreen( void )
{
	if ( VisualInfo ) {
		FreeVisualInfo( VisualInfo );
		VisualInfo = NULL;
	}

	if ( Scr        ) {
		UnlockPubScreen( NULL, Scr );
		Scr = NULL;
	}
}

void PrefsRender( void )
{
	struct IntuiText	it;
	UWORD			cnt;

	ComputeFont( PrefsWidth, PrefsHeight );


	for ( cnt = 0; cnt < Prefs_TNUM; cnt++ ) {
		CopyMem(( char * )&PrefsIText[ cnt ], ( char * )&it, (long)sizeof( struct IntuiText ));
		it.ITextFont = Font;
		it.LeftEdge  = OffX + ComputeX( it.LeftEdge ) - ( IntuiTextLength( &it ) >> 1 );
		it.TopEdge   = OffY + ComputeY( it.TopEdge ) - ( Font->ta_YSize >> 1 );
		PrintIText( PrefsWnd->RPort, &it, 0, 0 );
	}
}

int HandlePrefsIDCMP( void )
{
	struct IntuiMessage	*m;
	struct MenuItem		*n;
	int			(*func)();
	BOOL			running = TRUE;

	while( m = GT_GetIMsg( PrefsWnd->UserPort )) {

		CopyMem(( char * )m, ( char * )&PrefsMsg, (long)sizeof( struct IntuiMessage ));

		GT_ReplyIMsg( m );

		switch ( PrefsMsg.Class ) {

			case	IDCMP_REFRESHWINDOW:
				GT_BeginRefresh( PrefsWnd );
				PrefsRender();
				GT_EndRefresh( PrefsWnd, TRUE );
				break;

			case	IDCMP_VANILLAKEY:
				running = PrefsVanillaKey();
				break;

			case	IDCMP_GADGETUP:
				func = ( void * )(( struct Gadget * )PrefsMsg.IAddress )->UserData;
				running = func();
				break;

			case	IDCMP_MENUPICK:
				while( PrefsMsg.Code != MENUNULL ) {
					n = ItemAddress( PrefsMenus, PrefsMsg.Code );
					func = (void *)(GTMENUITEM_USERDATA( n ));
					running = func();
					PrefsMsg.Code = n->NextSelect;
				}
				break;
		}
	}
	return( running );
}

int OpenPrefsWindow( void )
{
	struct NewGadget	ng;
	struct Gadget	*g;
	UWORD		lc, tc;
	UWORD		wleft = PrefsLeft, wtop = PrefsTop, ww, wh;

	ComputeFont( PrefsWidth, PrefsHeight );

	ww = ComputeX( PrefsWidth );
	wh = ComputeY( PrefsHeight );

	if (( wleft + ww + OffX + Scr->WBorRight ) > Scr->Width ) wleft = Scr->Width - ww;
	if (( wtop + wh + OffY + Scr->WBorBottom ) > Scr->Height ) wtop = Scr->Height - wh;

	if ( ! ( g = CreateContext( &PrefsGList )))
		return( 1L );

	for( lc = 0, tc = 0; lc < Prefs_CNT; lc++ ) {

		CopyMem((char * )&PrefsNGad[ lc ], (char * )&ng, (long)sizeof( struct NewGadget ));

		ng.ng_VisualInfo = VisualInfo;
		ng.ng_TextAttr   = Font;
		ng.ng_LeftEdge   = OffX + ComputeX( ng.ng_LeftEdge );
		ng.ng_TopEdge    = OffY + ComputeY( ng.ng_TopEdge );
		ng.ng_Width      = ComputeX( ng.ng_Width );
		ng.ng_Height     = ComputeY( ng.ng_Height);

		PrefsGadgets[ lc ] = g = CreateGadgetA((ULONG)PrefsGTypes[ lc ], g, &ng, ( struct TagItem * )&PrefsGTags[ tc ] );

		while( PrefsGTags[ tc ] ) tc += 2;
		tc++;

		if ( NOT g )
			return( 2L );
	}

	if ( ! ( PrefsMenus = CreateMenus( PrefsNewMenu, GTMN_FrontPen, 0L, TAG_DONE )))
		return( 3L );

	LayoutMenus( PrefsMenus, VisualInfo, TAG_DONE );

		PrefsZoom[0] = PrefsZoom[1] = 0;
	if ( PrefsWdt )
		PrefsZoom[2] = TextLength( &Scr->RastPort, (UBYTE *)PrefsWdt, strlen((char *)PrefsWdt )) + 80;
	else
		PrefsZoom[2]  = 80L;
		PrefsZoom[3] = Scr->WBorTop + Scr->RastPort.TxHeight + 1;

	if ( ! ( PrefsWnd = OpenWindowTags( NULL,
				WA_Left,	wleft,
				WA_Top,		wtop,
				WA_Width,	ww + OffX + Scr->WBorRight,
				WA_Height,	wh + OffY + Scr->WBorBottom,
				WA_IDCMP,	CHECKBOXIDCMP|INTEGERIDCMP|CYCLEIDCMP|STRINGIDCMP|BUTTONIDCMP|IDCMP_MENUPICK|IDCMP_VANILLAKEY|IDCMP_REFRESHWINDOW,
				WA_Flags,	WFLG_DRAGBAR|WFLG_DEPTHGADGET|WFLG_SMART_REFRESH|WFLG_SIMPLE_REFRESH|WFLG_ACTIVATE,
				WA_Gadgets,	PrefsGList,
				WA_Title,	PrefsWdt,
				WA_ScreenTitle,	"Frodo C64 Emulator",
				WA_PubScreen,	Scr,
				WA_Zoom,	PrefsZoom,
				TAG_DONE )))
	return( 4L );

	SetMenuStrip( PrefsWnd, PrefsMenus );
	GT_RefreshWindow( PrefsWnd, NULL );

	PrefsRender();

	return( 0L );
}

void ClosePrefsWindow( void )
{
	if ( PrefsMenus      ) {
		ClearMenuStrip( PrefsWnd );
		FreeMenus( PrefsMenus );
		PrefsMenus = NULL;	}

	if ( PrefsWnd        ) {
		CloseWindow( PrefsWnd );
		PrefsWnd = NULL;
	}

	if ( PrefsGList      ) {
		FreeGadgets( PrefsGList );
		PrefsGList = NULL;
	}
}

