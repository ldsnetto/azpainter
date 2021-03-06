/*$
 Copyright (C) 2013-2018 Azel.

 This file is part of AzPainter.

 AzPainter is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 AzPainter is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
$*/

/***************************************
 * フィルタダイアログデータ
 ***************************************/


#define FDDAT_F_PREV_NONE         0
#define FDDAT_F_PREV_IN_DIALOG    1
#define FDDAT_F_PREV_CANVAS_COLOR 2
#define FDDAT_F_PREV_CANVAS_COMIC 3

#define FDDAT_F_RESET_BUTTON   (1<<3)
#define FDDAT_F_GET_CANVAS_POS (1<<4)
#define FDDAT_F_SAVE_DATA      (1<<5)

#define WG_BAR   0
#define WG_CHECK 1
#define WG_COMBO 2
#define WG_LABEL 3
#define WG_DEF_CLIPPING  128
#define WG_DEF_LEVEL     129
#define WG_DEF_REPLACE_COL 130
#define WG_END   255

#define VAL16(n)  (n >> 8) & 0xff,n & 0xff
#define BARWIDTH_DEF  0x01,0x18		//280
#define PREVSIZE_DEF  0,220, 0,220

enum
{
	TRID_BRIGHTNESS = 10,	//明度
	TRID_CONTRAST,		//コントラスト
	TRID_GAMMA,			//ガンマ値
	TRID_HUE,			//色相
	TRID_SATURATION,	//彩度
	TRID_THRESHOLD_VAL,	//しきい値
	TRID_TYPE,			//タイプ
	TRID_GRADATION,		//階調
	TRID_RADIUS,		//半径
	TRID_FREQUENCY,		//サイクル数
	TRID_SHARPNESS,		//鮮明さ
	TRID_COLOR,
	TRID_AMITONE_LINE,	//線数
	TRID_DENSITY,		//密度
	TRID_ANGLE,
	TRID_DPI,
	TRID_ANTIALIAS,
	TRID_SIZE,
	TRID_USE_ADVCOLOR,
	TRID_ANGLE_R,
	TRID_ANGLE_G,
	TRID_ANGLE_B,
	TRID_SAME_ANGLE_R,
	TRID_GRAYSCALE,
	TRID_THICKNESS,
	TRID_THICKNESS_MIN,
	TRID_THICKNESS_MAX,
	TRID_INTERVAL_MIN,
	TRID_INTERVAL_MAX,
	TRID_HORZ_LINE,
	TRID_VERT_LINE,
	TRID_COLUMN_WIDTH,
	TRID_ROW_WIDTH,
	TRID_SAME_COLUMN_WIDTH,
	TRID_STRENGTH,
	TRID_AMOUNT,
	TRID_OPACITY,
	TRID_RAND_RADIUS_MIN,
	TRID_RAND_OPACITY_MIN,
	TRID_DRAWPOINT_TYPE,
	TRID_DISTANCE,
	TRID_REVERSE,
	TRID_LENGTH,
	TRID_WIDTH,
	TRID_END_TO_LOOP,
	TRID_HELP_CANVASPOS,
	TRID_BACKGROUND,
	TRID_ZOOM,
	TRID_SMOOTH,
	TRID_DENT,
	TRID_COUNT,
	TRID_CHECKEDLAYER_TO_SRC,
	TRID_CUT_SRCIMG,
	TRID_HILIGHT,
	TRID_COLOR_NUM,
	TRID_ASPECT_RATIO,	//縦横比
	TRID_INTERVAL_RAND,	//間隔ランダム
	TRID_THICKNESS_RAND,	//太さランダム
	TRID_LENGTH_RAND,		//長さランダム
	TRID_WAVE_LENGTH,		//波の長さ
	TRID_TAIL_THICKNESS,	//抜きの太さ
	TRID_SIMPLE_PREVIEW,	//簡易プレビュー
	TRID_PREVIEW_RED,		//赤色でプレビュー

	/* アルファベット */
	TRID_R = 240,
	TRID_G,
	TRID_B,
	TRID_X,
	TRID_Y,
	TRID_H,
	TRID_L,
	TRID_S,

	/* コンボボックの先頭ID */
	TRID_CB_THRESHOLD_DITHER = 1000,
	TRID_CB_DRAWCLOUD_COLOR = 1010,
	TRID_CB_DRAWCOLOR = 1020,
	TRID_CB_DRAWPOINT_TYPE = 1030,
	TRID_CB_DRAWPOINT_COLOR = 1040,
	TRID_CB_DRAWPOINT_EDGETYPE = 1050,
	TRID_CB_DIRECTION_TYPE = 1060,	//斜め、横方向、縦方向
	TRID_CB_MEDIAN_TYPE = 1070,
	TRID_CB_WAVE_TYPE = 1080,
	TRID_CB_POLAR_TYPE = 1090,
	TRID_CB_BACKGROUND_TYPE = 1100,
	TRID_CB_COMIC_DRAWTYPE = 1110
};

/* [1byte] フラグ (下位3bit:プレビュータイプ、上位5bit:フラグ)
 * <ダイアログ内プレビュー時> [2byte x 2] プレビュー幅、高さ

 * [1byte] ウィジェットタイプ (255 で終了)
 * [1byte] ラベル文字列ID (0 でなし)
 * [1byte] データサイズ
 * [*] データ
 * ...
 */

//--------- カラー

//明度・コントラスト調整
static const uint8_t g_col_brightconst[] = {
	FDDAT_F_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_BRIGHTNESS, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, TRID_CONTRAST, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_END
};

//ガンマ補正
static const uint8_t g_col_gamma[] = {
	FDDAT_F_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_GAMMA, 11, BARWIDTH_DEF, VAL16(10), VAL16(400), VAL16(100), VAL16(100), 2,
	WG_END
};

//レベル補正
static const uint8_t g_col_level[] = {
	FDDAT_F_PREV_CANVAS_COLOR, WG_DEF_LEVEL, WG_END
};

//RGB補正
static const uint8_t g_col_rgb[] = {
	FDDAT_F_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_R, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, TRID_G, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, TRID_B, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_END
};

//HSV調整
static const uint8_t g_col_hsv[] = {
	FDDAT_F_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_HUE, 6, BARWIDTH_DEF, VAL16(-180), VAL16(180),
	WG_BAR, TRID_SATURATION, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, TRID_BRIGHTNESS, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_END
};

//HLS調整
static const uint8_t g_col_hls[] = {
	FDDAT_F_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_H, 6, BARWIDTH_DEF, VAL16(-180), VAL16(180),
	WG_BAR, TRID_L, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_BAR, TRID_S, 6, BARWIDTH_DEF, VAL16(-100), VAL16(100),
	WG_END
};

//2値化
static const uint8_t g_col_threshold[] = {
	FDDAT_F_PREV_CANVAS_COLOR | FDDAT_F_RESET_BUTTON,
	WG_BAR, TRID_THRESHOLD_VAL, 11, BARWIDTH_DEF, VAL16(1), VAL16(1000), VAL16(500), VAL16(500), 1,
	WG_END
};

//2値化(ディザ)
static const uint8_t g_col_threshold_dither[] = {
	FDDAT_F_PREV_CANVAS_COLOR,
	WG_COMBO, TRID_TYPE, 3, 5, VAL16(TRID_CB_THRESHOLD_DITHER),
	WG_END
};

//ポスタリゼーション
static const uint8_t g_col_posterize[] = {
	FDDAT_F_PREV_CANVAS_COLOR,
	WG_BAR, TRID_GRADATION, 8, VAL16(200), VAL16(2), VAL16(64), VAL16(4),
	WG_END
};

//減色
static const uint8_t g_col_reducecol[] = {
	FDDAT_F_PREV_NONE,
	WG_BAR, TRID_COLOR_NUM, 8, VAL16(160), VAL16(2), VAL16(256), VAL16(256),
	WG_END
};

//描画色置換
static const uint8_t g_col_replace_drawcol[] = {
	FDDAT_F_PREV_CANVAS_COLOR,
	WG_DEF_REPLACE_COL, WG_END,
};


//------- ぼかし

//ぼかし
static const uint8_t g_blur_blur[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 6, VAL16(100), VAL16(1), VAL16(30),
	WG_DEF_CLIPPING,
	WG_END
};

//ガウスぼかし
static const uint8_t g_blur_gauss[] = {
	FDDAT_F_PREV_IN_DIALOG, VAL16(200), VAL16(200),
	WG_BAR, TRID_RADIUS, 6, VAL16(100), VAL16(1), VAL16(20),
	WG_DEF_CLIPPING,
	WG_END
};

//モーションブラー
static const uint8_t g_blur_motion[] = {
	FDDAT_F_PREV_IN_DIALOG, VAL16(200), VAL16(200),
	WG_BAR, TRID_RADIUS, 6, VAL16(100), VAL16(1), VAL16(20),
	WG_BAR, TRID_ANGLE, 6, VAL16(180), VAL16(-180), VAL16(180),
	WG_DEF_CLIPPING,
	WG_END
};

//放射状ぼかし
static const uint8_t g_blur_radial[] = {
	FDDAT_F_PREV_IN_DIALOG|FDDAT_F_GET_CANVAS_POS, VAL16(200), VAL16(200),
	WG_BAR, TRID_STRENGTH, 8, VAL16(120), VAL16(1), VAL16(50), VAL16(3),
	WG_DEF_CLIPPING,
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//レンズぼかし
static const uint8_t g_blur_lens[] = {
	FDDAT_F_PREV_IN_DIALOG, VAL16(200), VAL16(200),
	WG_BAR, TRID_RADIUS, 8, VAL16(120), VAL16(1), VAL16(30), VAL16(3),
	WG_BAR, TRID_HILIGHT, 8, VAL16(120), VAL16(0), VAL16(150), VAL16(20),
	WG_DEF_CLIPPING,
	WG_END
};

//------- 描画

//雲模様
static const uint8_t g_draw_cloud[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_FREQUENCY, 8, VAL16(180), VAL16(2), VAL16(200), VAL16(7),
	WG_BAR, TRID_SHARPNESS, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(55),
	WG_BAR, TRID_CONTRAST, 8, VAL16(180), VAL16(0), VAL16(100), VAL16(25),
	WG_COMBO, TRID_COLOR, 3, 3, VAL16(TRID_CB_DRAWCLOUD_COLOR),
	WG_END
};

//アミトーン(1)
static const uint8_t g_draw_amitone1[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMITONE_LINE, 11, VAL16(180), VAL16(10), VAL16(4000), VAL16(600), VAL16(0), 1,
	WG_BAR, TRID_DENSITY, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(10),
	WG_BAR, TRID_ANGLE, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(45),
	WG_BAR, TRID_DPI, 12, VAL16(180), VAL16(1), VAL16(2400), VAL16(0), VAL16(0), 0, 1,
	WG_CHECK, TRID_ANTIALIAS, 1, 1,
	WG_COMBO, TRID_COLOR, 4, 4, VAL16(TRID_CB_DRAWCOLOR), 2,
	WG_END
};

//アミトーン(2)
static const uint8_t g_draw_amitone2[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_SIZE, 11, VAL16(180), VAL16(10), VAL16(4000), VAL16(50), VAL16(0), 1,
	WG_BAR, TRID_DENSITY, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(10),
	WG_BAR, TRID_ANGLE, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(45),
	WG_CHECK, TRID_ANTIALIAS, 1, 1,
	WG_COMBO, TRID_COLOR, 4, 4, VAL16(TRID_CB_DRAWCOLOR), 2,
	WG_END
};

//ランダム点描画
static const uint8_t g_draw_rndpoint[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(512), VAL16(5),
	WG_BAR, TRID_RADIUS, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(2),
	WG_BAR, TRID_OPACITY, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(100),
	WG_BAR, TRID_RAND_RADIUS_MIN, 8, VAL16(180), VAL16(0), VAL16(100), VAL16(100),
	WG_BAR, TRID_RAND_OPACITY_MIN, 8, VAL16(180), VAL16(0), VAL16(100), VAL16(100),
	WG_COMBO, TRID_DRAWPOINT_TYPE, 3, 3, VAL16(TRID_CB_DRAWPOINT_TYPE),
	WG_COMBO, TRID_COLOR, 3, 4, VAL16(TRID_CB_DRAWPOINT_COLOR),
	WG_END
};

//縁に沿って点描画
static const uint8_t g_draw_edgepoint[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_COMBO, TRID_TYPE, 3, 2, VAL16(TRID_CB_DRAWPOINT_EDGETYPE),
	WG_BAR, TRID_RADIUS, 6, VAL16(160), VAL16(1), VAL16(100),
	WG_BAR, TRID_OPACITY, 8, VAL16(160), VAL16(1), VAL16(100), VAL16(100),
	WG_COMBO, TRID_DRAWPOINT_TYPE, 3, 3, VAL16(TRID_CB_DRAWPOINT_TYPE),
	WG_COMBO, TRID_COLOR, 3, 4, VAL16(TRID_CB_DRAWPOINT_COLOR),
	WG_END
};

//枠線
static const uint8_t g_draw_frame[] = {
	FDDAT_F_PREV_NONE,
	WG_BAR, TRID_THICKNESS, 6, VAL16(130), VAL16(1), VAL16(100),
	WG_COMBO, TRID_COLOR, 3, 4, VAL16(TRID_CB_DRAWCOLOR),
	WG_END
};

//水平線&垂直線
static const uint8_t g_draw_horzvert_line[] = {
	FDDAT_F_PREV_IN_DIALOG, VAL16(230), VAL16(230),
	WG_BAR, TRID_THICKNESS_MIN, 6, VAL16(180), VAL16(1), VAL16(100),
	WG_BAR, TRID_THICKNESS_MAX, 6, VAL16(180), VAL16(1), VAL16(100),
	WG_BAR, TRID_INTERVAL_MIN, 8, VAL16(180), VAL16(1), VAL16(400), VAL16(2),
	WG_BAR, TRID_INTERVAL_MAX, 8, VAL16(180), VAL16(1), VAL16(400), VAL16(2),
	WG_CHECK, TRID_HORZ_LINE, 1, 1,
	WG_CHECK, TRID_VERT_LINE, 0,
	WG_COMBO, TRID_COLOR, 3, 4, VAL16(TRID_CB_DRAWCOLOR),
	WG_END
};

//チェック柄
static const uint8_t g_draw_plaid[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_COLUMN_WIDTH, 8, VAL16(180), VAL16(2), VAL16(400), VAL16(5),
	WG_BAR, TRID_ROW_WIDTH, 8, VAL16(180), VAL16(2), VAL16(400), VAL16(5),
	WG_CHECK, TRID_SAME_COLUMN_WIDTH, 1, 1,
	WG_COMBO, TRID_COLOR, 3, 4, VAL16(TRID_CB_DRAWCOLOR),
	WG_END
};

//------- 描画 (漫画用)

static const uint8_t g_comic_concline[] = {
	FDDAT_F_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
	WG_BAR, TRID_RADIUS, 13, VAL16(200), VAL16(10), VAL16(5000), VAL16(200), VAL16(0), 0, 0, 'a',  //半径
	WG_BAR, TRID_ASPECT_RATIO, 13, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 0, 'b',  //縦横比
	WG_BAR, TRID_DENSITY, 13, VAL16(200), VAL16(2), VAL16(300), VAL16(15), VAL16(0), 0, 0, 'c',    //密度
	WG_BAR, TRID_INTERVAL_RAND, 13, VAL16(200), VAL16(0), VAL16(99), VAL16(0), VAL16(0), 0, 0, 'd',  //間隔
	WG_BAR, TRID_THICKNESS, 13, VAL16(200), VAL16(2), VAL16(1000), VAL16(25), VAL16(0), 1, 0, 'e',   //太さ
	WG_BAR, TRID_THICKNESS_RAND, 13, VAL16(200), VAL16(0), VAL16(1000), VAL16(0), VAL16(0), 1, 0, 'f',  //太さランダム
	WG_BAR, TRID_LENGTH, 13, VAL16(200), VAL16(1), VAL16(1000), VAL16(500), VAL16(0), 1, 0, 'g', //長さ
	WG_BAR, TRID_LENGTH_RAND, 13, VAL16(200), VAL16(0), VAL16(1000), VAL16(200), VAL16(0), 1, 0, 'h',  //長さランダム
	WG_COMBO, TRID_TYPE, 5, 3, VAL16(TRID_CB_COMIC_DRAWTYPE), 0, 'i',  //描画タイプ
	WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'j',
	WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'k',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

static const uint8_t g_comic_flash[] = {
	FDDAT_F_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
    WG_BAR, TRID_RADIUS, 13, VAL16(200), VAL16(10), VAL16(5000), VAL16(200), VAL16(0), 0, 0, 'a',
    WG_BAR, TRID_ASPECT_RATIO, 13, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 0, 'b',
    WG_BAR, TRID_DENSITY, 13, VAL16(200), VAL16(2), VAL16(300), VAL16(100), VAL16(0), 0, 0, 'c',
    WG_BAR, TRID_INTERVAL_RAND, 13, VAL16(200), VAL16(0), VAL16(99), VAL16(20), VAL16(0), 0, 0, 'd',
    WG_BAR, TRID_THICKNESS, 13, VAL16(200), VAL16(2), VAL16(1000), VAL16(40), VAL16(0), 1, 0, 'e',
    WG_BAR, TRID_THICKNESS_RAND, 13, VAL16(200), VAL16(0), VAL16(1000), VAL16(30), VAL16(0), 1, 0, 'f',
    WG_BAR, TRID_LENGTH, 13, VAL16(200), VAL16(1), VAL16(1000), VAL16(350), VAL16(0), 1, 0, 'g',
    WG_BAR, TRID_LENGTH_RAND, 13, VAL16(200), VAL16(0), VAL16(1000), VAL16(200), VAL16(0), 1, 0, 'h',
    WG_COMBO, TRID_TYPE, 5, 3, VAL16(TRID_CB_COMIC_DRAWTYPE), 0, 'i',
    WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'j',
    WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'k',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
    WG_END
};

static const uint8_t g_comic_popupflash[] = {
	FDDAT_F_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
    WG_BAR, TRID_RADIUS, 13, VAL16(200), VAL16(10), VAL16(5000), VAL16(130), VAL16(0), 0, 0, 'a',
    WG_BAR, TRID_ASPECT_RATIO, 13, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 0, 'b',
    WG_BAR, TRID_DENSITY, 13, VAL16(200), VAL16(2), VAL16(300), VAL16(80), VAL16(0), 0, 0, 'c',
    WG_BAR, TRID_INTERVAL_RAND, 13, VAL16(200), VAL16(0), VAL16(99), VAL16(20), VAL16(0), 0, 0, 'd',
    WG_BAR, TRID_THICKNESS, 13, VAL16(200), VAL16(2), VAL16(1000), VAL16(30), VAL16(0), 1, 0, 'e',
    WG_BAR, TRID_THICKNESS_RAND, 13, VAL16(200), VAL16(0), VAL16(1000), VAL16(20), VAL16(0), 1, 0, 'f',
    WG_BAR, TRID_LENGTH, 13, VAL16(200), VAL16(1), VAL16(1000), VAL16(250), VAL16(0), 1, 0, 'g',
    WG_BAR, TRID_LENGTH_RAND, 13, VAL16(200), VAL16(0), VAL16(1000), VAL16(300), VAL16(0), 1, 0, 'h',
    WG_COMBO, TRID_TYPE, 5, 3, VAL16(TRID_CB_COMIC_DRAWTYPE), 0, 'i',
    WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'j',
    WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'k',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
    WG_END
};

static const uint8_t g_comic_uniflash[] = {
	FDDAT_F_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
    WG_BAR, TRID_RADIUS, 13, VAL16(200), VAL16(10), VAL16(5000), VAL16(160), VAL16(0), 0, 0, 'a',
    WG_BAR, TRID_ASPECT_RATIO, 13, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 0, 'b',
    WG_BAR, TRID_DENSITY, 13, VAL16(200), VAL16(2), VAL16(300), VAL16(110), VAL16(0), 0, 0, 'c',
    WG_BAR, TRID_INTERVAL_RAND, 13, VAL16(200), VAL16(0), VAL16(99), VAL16(0), VAL16(0), 0, 0, 'd',
    WG_BAR, TRID_THICKNESS, 13, VAL16(200), VAL16(2), VAL16(1000), VAL16(30), VAL16(0), 1, 0, 'e',
    WG_BAR, TRID_THICKNESS_RAND, 13, VAL16(200), VAL16(0), VAL16(1000), VAL16(0), VAL16(0), 1, 0, 'f',
    WG_BAR, TRID_LENGTH, 13, VAL16(200), VAL16(1), VAL16(1000), VAL16(300), VAL16(0), 1, 0, 'g',
    WG_BAR, TRID_LENGTH_RAND, 13, VAL16(200), VAL16(0), VAL16(1000), VAL16(0), VAL16(0), 1, 0, 'h',
    WG_COMBO, TRID_TYPE, 5, 3, VAL16(TRID_CB_COMIC_DRAWTYPE), 0, 'i',
    WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'j',
    WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'k',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
    WG_END
};

static const uint8_t g_comic_uniflash_wave[] = {
	FDDAT_F_PREV_CANVAS_COMIC | FDDAT_F_GET_CANVAS_POS | FDDAT_F_RESET_BUTTON | FDDAT_F_SAVE_DATA,
    WG_BAR, TRID_RADIUS, 13, VAL16(200), VAL16(10), VAL16(5000), VAL16(160), VAL16(0), 0, 0, 'a',
    WG_BAR, TRID_ASPECT_RATIO, 13, VAL16(200), VAL16(-1000), VAL16(1000), VAL16(0), VAL16(0), 3, 0, 'b',
    WG_BAR, TRID_DENSITY, 13, VAL16(200), VAL16(2), VAL16(300), VAL16(30), VAL16(0), 0, 0, 'c',
    WG_BAR, TRID_WAVE_LENGTH, 13, VAL16(200), VAL16(1), VAL16(1000), VAL16(200), VAL16(0), 1, 0, 'd', //波の長さ
    WG_BAR, TRID_THICKNESS, 13, VAL16(200), VAL16(2), VAL16(1000), VAL16(15), VAL16(0), 1, 0, 'e',
    WG_BAR, TRID_LENGTH, 13, VAL16(200), VAL16(1), VAL16(1000), VAL16(300), VAL16(0), 1, 0, 'f',
    WG_BAR, TRID_TAIL_THICKNESS, 13, VAL16(200), VAL16(0), VAL16(100), VAL16(0), VAL16(0), 0, 0, 'g', //抜きの太さ
    WG_COMBO, TRID_TYPE, 5, 3, VAL16(TRID_CB_COMIC_DRAWTYPE), 0, 'h',
    WG_CHECK, TRID_SIMPLE_PREVIEW, 2, 1, 'i',
    WG_CHECK, TRID_PREVIEW_RED, 2, 1, 'j',
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
    WG_END
};

//------- ピクセレート

//モザイク
static const uint8_t g_pix_mozaic[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_SIZE, 6, VAL16(120), VAL16(2), VAL16(100),
	WG_DEF_CLIPPING,
	WG_END
};

//水晶
static const uint8_t g_pix_crystal[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_SIZE, 6, VAL16(150), VAL16(5), VAL16(200),
	WG_CHECK, TRID_USE_ADVCOLOR, 0,
	WG_DEF_CLIPPING,
	WG_END
};

//ハーフトーン
static const uint8_t g_pix_halftone[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_SIZE, 11, VAL16(180), VAL16(10), VAL16(2000), VAL16(50), VAL16(0), 1,
	WG_BAR, TRID_ANGLE_R, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(15),
	WG_BAR, TRID_ANGLE_G, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(75),
	WG_BAR, TRID_ANGLE_B, 6, VAL16(180), VAL16(-180), VAL16(180),
	WG_CHECK, TRID_SAME_ANGLE_R, 0,
	WG_CHECK, TRID_ANTIALIAS, 1, 1,
	WG_CHECK, TRID_GRAYSCALE, 0,
	WG_END
};

//------ 輪郭

//シャープ
static const uint8_t g_edge_sharp[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_STRENGTH, 8, VAL16(120), VAL16(1), VAL16(50), VAL16(3),
	WG_END
};

//アンシャープマスク
static const uint8_t g_edge_unsharpmask[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 8, VAL16(180), VAL16(1), VAL16(20), VAL16(1),
	WG_BAR, TRID_STRENGTH, 8, VAL16(180), VAL16(1), VAL16(300), VAL16(50),
	WG_DEF_CLIPPING,
	WG_END
};

//ハイパス
static const uint8_t g_edge_highpass[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 6, VAL16(100), VAL16(1), VAL16(20),
	WG_DEF_CLIPPING,
	WG_END
};

//------ 効果

//グロ―
static const uint8_t g_eff_glow[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_BRIGHTNESS, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(23),
	WG_BAR, TRID_RADIUS, 8, VAL16(180), VAL16(1), VAL16(20), VAL16(3),
	WG_BAR, TRID_STRENGTH, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(90),
	WG_DEF_CLIPPING,
	WG_END
};

//RGBずらし
static const uint8_t g_eff_rgbshift[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_COMBO, TRID_TYPE, 3, 3, VAL16(TRID_CB_DIRECTION_TYPE),
	WG_BAR, TRID_DISTANCE, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(3),
	WG_DEF_CLIPPING,
	WG_END
};

//油絵風
static const uint8_t g_eff_oilpaint[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 8, VAL16(100), VAL16(1), VAL16(8), VAL16(2),
	WG_DEF_CLIPPING,
	WG_END
};

//エンボス
static const uint8_t g_eff_emboss[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_STRENGTH, 6, VAL16(100), VAL16(1), VAL16(16),
	WG_COMBO, TRID_TYPE, 3, 3, VAL16(TRID_CB_DIRECTION_TYPE),
	WG_CHECK, TRID_REVERSE, 0,
	WG_CHECK, TRID_GRAYSCALE, 1, 1,
	WG_DEF_CLIPPING,
	WG_END
};

//ノイズ
static const uint8_t g_eff_noise[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMOUNT, 8, VAL16(160), VAL16(1), VAL16(100), VAL16(6),
	WG_CHECK, TRID_GRAYSCALE, 1, 1,
	WG_END
};

//拡散
static const uint8_t g_eff_diffusion[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_DISTANCE, 6, VAL16(160), VAL16(1), VAL16(50),
	WG_DEF_CLIPPING,
	WG_END
};

//ひっかき
static const uint8_t g_eff_scratch[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_LENGTH, 8, VAL16(180), VAL16(2), VAL16(50), VAL16(10),
	WG_BAR, TRID_ANGLE, 8, VAL16(180), VAL16(-180), VAL16(180), VAL16(45),
	WG_DEF_CLIPPING,
	WG_END
};

//メディアン
static const uint8_t g_eff_median[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_RADIUS, 6, VAL16(50), VAL16(1), VAL16(3),
	WG_COMBO, TRID_TYPE, 4, 3, VAL16(TRID_CB_MEDIAN_TYPE), 1,
	WG_DEF_CLIPPING,
	WG_END
};

//ぶれ
static const uint8_t g_eff_blurring[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_DISTANCE, 8, VAL16(120), VAL16(1), VAL16(60), VAL16(4),
	WG_DEF_CLIPPING,
	WG_END
};

//----------- 変形

//波形
static const uint8_t g_trans_wave[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(50), VAL16(10),
	WG_BAR, TRID_WIDTH, 11, VAL16(180), VAL16(1), VAL16(500), VAL16(40), VAL16(0), 1,
	WG_COMBO, TRID_TYPE, 4, 3, VAL16(TRID_CB_WAVE_TYPE), 2,
	WG_DEF_CLIPPING,
	WG_CHECK, TRID_END_TO_LOOP, 0,
	WG_END
};

//波紋
static const uint8_t g_trans_ripple[] = {
	FDDAT_F_PREV_IN_DIALOG|FDDAT_F_GET_CANVAS_POS, PREVSIZE_DEF,
	WG_BAR, TRID_FREQUENCY, 8, VAL16(180), VAL16(1), VAL16(100), VAL16(17),
	WG_BAR, TRID_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(200), VAL16(50),
	WG_DEF_CLIPPING,
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//極座標
static const uint8_t g_trans_polar[] = {
	FDDAT_F_PREV_NONE,
	WG_COMBO, TRID_TYPE, 3, 2, VAL16(TRID_CB_POLAR_TYPE),
	WG_COMBO, TRID_BACKGROUND, 3, 3, VAL16(TRID_CB_BACKGROUND_TYPE),
	WG_END
};

//放射状ずらし
static const uint8_t g_trans_radial_shift[] = {
	FDDAT_F_PREV_IN_DIALOG|FDDAT_F_GET_CANVAS_POS, PREVSIZE_DEF,
	WG_BAR, TRID_LENGTH, 8, VAL16(180), VAL16(1), VAL16(150), VAL16(10),
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//渦巻き
static const uint8_t g_trans_swirl[] = {
	FDDAT_F_PREV_IN_DIALOG|FDDAT_F_GET_CANVAS_POS, PREVSIZE_DEF,
	WG_BAR, TRID_AMOUNT, 8, VAL16(180), VAL16(1), VAL16(200), VAL16(20),
	WG_BAR, TRID_ZOOM, 11, VAL16(180), VAL16(1), VAL16(300), VAL16(100), VAL16(100), 2,
	WG_COMBO, TRID_BACKGROUND, 4, 3, VAL16(TRID_CB_BACKGROUND_TYPE), 1,
	WG_LABEL, TRID_HELP_CANVASPOS, 0,
	WG_END
};

//------ ほか

//アンチエイリアシング
static const uint8_t g_other_antialiasing[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_STRENGTH, 8, VAL16(120), VAL16(1), VAL16(100), VAL16(80),
	WG_END
};

//縁取り
static const uint8_t g_other_hemming[] = {
	FDDAT_F_PREV_IN_DIALOG, PREVSIZE_DEF,
	WG_BAR, TRID_COUNT, 6, VAL16(120), VAL16(1), VAL16(20),
	WG_COMBO, TRID_COLOR, 3, 4, VAL16(TRID_CB_DRAWCOLOR),
	WG_CHECK, TRID_CHECKEDLAYER_TO_SRC, 0,
	WG_CHECK, TRID_CUT_SRCIMG, 0,
	WG_END
};

//立体枠
static const uint8_t g_other_3Dframe[] = {
	FDDAT_F_PREV_NONE,
	WG_BAR, TRID_WIDTH, 8, VAL16(100), VAL16(1), VAL16(100), VAL16(6),
	WG_CHECK, TRID_SMOOTH, 0,
	WG_CHECK, TRID_DENT, 0,
	WG_END
};

//シフト
static const uint8_t g_other_shift[] = {
	FDDAT_F_PREV_NONE,
	WG_BAR, TRID_X, 6, VAL16(280), VAL16(-1000), VAL16(1000),
	WG_BAR, TRID_Y, 6, VAL16(280), VAL16(-1000), VAL16(1000),
	WG_END
};
