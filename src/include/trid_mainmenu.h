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
 * 文字列ID : メインメニュー
 ***************************************/

#ifndef TRID_MAINMENU_H
#define TRID_MAINMENU_H

enum
{
/* トップ */

TRMENU_TOP_FILE = 1,
TRMENU_TOP_EDIT,
TRMENU_TOP_LAYER,
TRMENU_TOP_SELECT,
TRMENU_TOP_FILTER,
TRMENU_TOP_VIEW,
TRMENU_TOP_OPTION,

/* ファイル */

TRMENU_FILE_NEW = 1000,
TRMENU_FILE_OPEN,
TRMENU_FILE_SAVE,
TRMENU_FILE_SAVE_AS,
TRMENU_FILE_SAVE_DUP,
TRMENU_FILE_RECENTFILE,
TRMENU_FILE_EXIT,
TRMENU_FILE_RECENTFILE_CLEAR,
TRMENU_FILE_MINIMIZE,

/* 編集 */

TRMENU_EDIT_UNDO = 2000,
TRMENU_EDIT_REDO,
TRMENU_EDIT_CHECK_MASKS,
TRMENU_EDIT_FILL,
TRMENU_EDIT_ERASE,
TRMENU_EDIT_RESIZE_CANVAS,
TRMENU_EDIT_SCALE_CANVAS,
TRMENU_EDIT_CHANGE_DPI,

/* 選択範囲 */

TRMENU_SEL_RELEASE = 3000,
TRMENU_SEL_INVERSE,
TRMENU_SEL_ALL,
TRMENU_SEL_COPY,
TRMENU_SEL_CUT,
TRMENU_SEL_PASTE_NEWLAYER,
TRMENU_SEL_EXPAND,
TRMENU_SEL_OUTPUT_PNG,

/* レイヤ */

TRMENU_LAYER_TOP = 4000,
TRMENU_LAYER_BOTTOM = 4999,

TRMENU_LAYER_NEW = 4000,
TRMENU_LAYER_NEW_FOLDER,
TRMENU_LAYER_NEW_FROM_FILE,
TRMENU_LAYER_COPY,
TRMENU_LAYER_DELETE,
TRMENU_LAYER_ERASE,
TRMENU_LAYER_OPTION,
TRMENU_LAYER_SETCOLOR,
TRMENU_LAYER_SETTYPE,
TRMENU_LAYER_DROP,
TRMENU_LAYER_COMBINE,
TRMENU_LAYER_COMBINE_MULTI,
TRMENU_LAYER_BLEND_ALL,
TRMENU_LAYER_EDIT,
TRMENU_LAYER_VIEW,
TRMENU_LAYER_FLAG,
TRMENU_LAYER_OUTPUT,
TRMENU_LAYER_CLOSE_ALL_FOLDERS,

TRMENU_LAYER_EDIT_REV_HORZ = 4100,
TRMENU_LAYER_EDIT_REV_VERT,
TRMENU_LAYER_EDIT_ROTATE_LEFT,
TRMENU_LAYER_EDIT_ROTATE_RIGHT,

TRMENU_LAYER_VIEW_ALL_SHOW = 4200,
TRMENU_LAYER_VIEW_ALL_HIDE,
TRMENU_LAYER_VIEW_ONLY_CURRENT,
TRMENU_LAYER_VIEW_REV_CHECKED,
TRMENU_LAYER_VIEW_REV_IMAGE,

TRMENU_LAYER_FLAG_OFF_LOCK = 4300,
TRMENU_LAYER_FLAG_OFF_FILL_REF,
TRMENU_LAYER_FLAG_OFF_CHECKED,

TRMENU_LAYER_TB_MOVE_UP = 4900,
TRMENU_LAYER_TB_MOVE_DOWN,

/* フィルタ */

TRMENU_FILTER_TOP = 5100,
TRMENU_FILTER_BOTTOM = 5999,

TRMENU_FILTER_COLOR = 5000,
TRMENU_FILTER_COLREP,
TRMENU_FILTER_ALPHA1,
TRMENU_FILTER_ALPHA2,
TRMENU_FILTER_BLUR,
TRMENU_FILTER_DRAW,
TRMENU_FILTER_DRAW_COMIC,
TRMENU_FILTER_PIXELATE,
TRMENU_FILTER_EDGE,
TRMENU_FILTER_EFFECT,
TRMENU_FILTER_TRANSFORM,
TRMENU_FILTER_OTHER,

TRMENU_FILTER_COLOR_BRIGHT_CONST = 5100,
TRMENU_FILTER_COLOR_GAMMA,
TRMENU_FILTER_COLOR_LEVEL,
TRMENU_FILTER_COLOR_RGB,
TRMENU_FILTER_COLOR_HSV,
TRMENU_FILTER_COLOR_NEGA,
TRMENU_FILTER_COLOR_GRAYSCALE,
TRMENU_FILTER_COLOR_SEPIA,
TRMENU_FILTER_COLOR_GRADMAP,
TRMENU_FILTER_COLOR_THRESHOLD,
TRMENU_FILTER_COLOR_THRESHOLD_DITHER,
TRMENU_FILTER_COLOR_POSTERIZE,
TRMENU_FILTER_COLOR_REDUCE_COLOR,

TRMENU_FILTER_COLREP_DRAWCOL,
TRMENU_FILTER_COLREP_DRAWCOL_TO_TP,
TRMENU_FILTER_COLREP_EXDRAWCOL_TO_TP,
TRMENU_FILTER_COLREP_DRAWCOL_TO_BKGND,
TRMENU_FILTER_COLREP_TP_TO_DRAWCOL,

TRMENU_FILTER_ALPHA1_TP_TO_TP,
TRMENU_FILTER_ALPHA1_NOTTP_TO_TP,
TRMENU_FILTER_ALPHA1_COPY,
TRMENU_FILTER_ALPHA1_ADD,
TRMENU_FILTER_ALPHA1_SUB,
TRMENU_FILTER_ALPHA1_MUL,
TRMENU_FILTER_ALPHA1_LUM_REV,
TRMENU_FILTER_ALPHA1_LUM,

TRMENU_FILTER_ALPHA2_LUM_REV,
TRMENU_FILTER_ALPHA2_LUM,
TRMENU_FILTER_ALPHA2_TEXTURE,
TRMENU_FILTER_ALPHA2_CREATE_GRAYSCALE,

TRMENU_FILTER_BLUR_BLUR,
TRMENU_FILTER_BLUR_GAUSS,
TRMENU_FILTER_BLUR_MOTION,
TRMENU_FILTER_BLUR_RADIAL,
TRMENU_FILTER_BLUR_LENS,

TRMENU_FILTER_DRAW_CLOUD,
TRMENU_FILTER_DRAW_AMITONE1,
TRMENU_FILTER_DRAW_AMITONE2,
TRMENU_FILTER_DRAW_RANDOM_POINT,
TRMENU_FILTER_DRAW_EDGE_POINT,
TRMENU_FILTER_DRAW_FRAME,
TRMENU_FILTER_DRAW_HORZVERT_LINE,
TRMENU_FILTER_DRAW_PLAID,

TRMENU_FILTER_COMIC_CONCLINE,
TRMENU_FILTER_COMIC_FLASH,
TRMENU_FILTER_COMIC_POPUP_FLASH,
TRMENU_FILTER_COMIC_UNIFLASH,
TRMENU_FILTER_COMIC_UNIFLASH_WAVE,

TRMENU_FILTER_PIXELATE_MOZAIC,
TRMENU_FILTER_PIXELATE_CRYSTAL,
TRMENU_FILTER_PIXELATE_HALFTONE,

TRMENU_FILTER_EDGE_SHARP,
TRMENU_FILTER_EDGE_UNSHARPMASK,
TRMENU_FILTER_EDGE_SOBEL,
TRMENU_FILTER_EDGE_LAPLACIAN,
TRMENU_FILTER_EDGE_HIGHPASS,

TRMENU_FILTER_EFFECT_GLOW,
TRMENU_FILTER_EFFECT_RGBSHIFT,
TRMENU_FILTER_EFFECT_OILPAINT,
TRMENU_FILTER_EFFECT_EMBOSS,
TRMENU_FILTER_EFFECT_NOISE,
TRMENU_FILTER_EFFECT_DIFFUSION,
TRMENU_FILTER_EFFECT_SCRATCH,
TRMENU_FILTER_EFFECT_MEDIAN,
TRMENU_FILTER_EFFECT_BLURRING,

TRMENU_FILTER_TRANS_WAVE,
TRMENU_FILTER_TRANS_RIPPLE,
TRMENU_FILTER_TRANS_POLAR,
TRMENU_FILTER_TRANS_RADIAL_SHIFT,
TRMENU_FILTER_TRANS_SWIRL,

TRMENU_FILTER_OTHER_LUM_TO_ALPHA,
TRMENU_FILTER_OTHER_1PXDOT_THINNING,
TRMENU_FILTER_OTHER_ANTIALIASING,
TRMENU_FILTER_OTHER_HEMMING,
TRMENU_FILTER_OTHER_3DFRAME,
TRMENU_FILTER_OTHER_SHIFT,

//追加フィルタ
TRMENU_FILTER_ALPHA2_OPAQUE_TO_MAX,
TRMENU_FILTER_COLOR_HLS,

/* 表示 */

TRMENU_VIEW_PALETTE = 6000,
TRMENU_VIEW_CANVAS_MIRROR,
TRMENU_VIEW_BKGND_PLAID,
TRMENU_VIEW_GRID,
TRMENU_VIEW_GRID_SPLIT,
TRMENU_VIEW_TOOLBAR,
TRMENU_VIEW_STATUSBAR,
TRMENU_VIEW_CANVAS_ZOOM,
TRMENU_VIEW_CANVAS_ROTATE,

TRMENU_VIEW_PALETTE_VISIBLE = 6100,
TRMENU_VIEW_PALETTE_ALL_WINDOW,
TRMENU_VIEW_PALETTE_ALL_DOCK,
TRMENU_VIEW_PALETTE_TOOL,
TRMENU_VIEW_PALETTE_OPTION,
TRMENU_VIEW_PALETTE_LAYER,
TRMENU_VIEW_PALETTE_BRUSH,
TRMENU_VIEW_PALETTE_COLOR,
TRMENU_VIEW_PALETTE_COLOR_PALETTE,
TRMENU_VIEW_PALETTE_CANVAS_CTRL,
TRMENU_VIEW_PALETTE_CANVAS_VIEW,
TRMENU_VIEW_PALETTE_IMAGE_VIEWER,
TRMENU_VIEW_PALETTE_FILTER_LIST,
TRMENU_VIEW_PALETTE_COLOR_WHEEL,

TRMENU_VIEW_CANVASZOOM_UP = 6200,
TRMENU_VIEW_CANVASZOOM_DOWN,
TRMENU_VIEW_CANVASZOOM_FIT,

TRMENU_VIEW_CANVASROTATE_LEFT = 6300,
TRMENU_VIEW_CANVASROTATE_RIGHT,
TRMENU_VIEW_CANVASROTATE_0,
TRMENU_VIEW_CANVASROTATE_90,
TRMENU_VIEW_CANVASROTATE_180,
TRMENU_VIEW_CANVASROTATE_270,

/* 設定ほか */

TRMENU_OPT_ENV = 7000,
TRMENU_OPT_GRID,
TRMENU_OPT_SHORTCUTKEY,
TRMENU_OPT_CANVASKEY,
TRMENU_OPT_DOCK_ARRANGE,
TRMENU_OPT_VERSION

};

#endif
