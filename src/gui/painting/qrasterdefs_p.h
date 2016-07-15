begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftimage.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType glyph image formats and default raster interface            */
end_comment
begin_comment
comment|/*    (specification).                                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004 by                               */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Note: A `raster' is simply a scan-line converter, used to render      */
end_comment
begin_comment
comment|/*       QT_FT_Outlines into QT_FT_Bitmaps.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__QT_FTIMAGE_H__
end_ifndef
begin_define
DECL|macro|__QT_FTIMAGE_H__
define|#
directive|define
name|__QT_FTIMAGE_H__
end_define
begin_comment
comment|/* //  W A R N I N G //  ------------- // // This file is not part of the Qt API.  It exists purely as an // implementation detail.  This header file may change from version to // version without notice, or even be removed. // // We mean it. */
end_comment
begin_macro
name|QT_FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    basic_types                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    QT_FT_Pos                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The type QT_FT_Pos is a 32-bit integer used to store vectorial        */
end_comment
begin_comment
comment|/*    coordinates.  Depending on the context, these can represent        */
end_comment
begin_comment
comment|/*    distances in integer font units, or 16,16, or 26.6 fixed float     */
end_comment
begin_comment
comment|/*    pixel coordinates.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|QT_FT_Pos
typedef|typedef
name|signed
name|int
name|QT_FT_Pos
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_Vector                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple structure used to store a 2D vector; coordinates are of   */
end_comment
begin_comment
comment|/*    the QT_FT_Pos type.                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    x :: The horizontal coordinate.                                    */
end_comment
begin_comment
comment|/*    y :: The vertical coordinate.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|QT_FT_Vector_
typedef|typedef
struct|struct
name|QT_FT_Vector_
block|{
DECL|member|x
name|QT_FT_Pos
name|x
decl_stmt|;
DECL|member|y
name|QT_FT_Pos
name|y
decl_stmt|;
block|}
DECL|typedef|QT_FT_Vector
name|QT_FT_Vector
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_BBox                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to hold an outline's bounding box, i.e., the      */
end_comment
begin_comment
comment|/*    coordinates of its extrema in the horizontal and vertical          */
end_comment
begin_comment
comment|/*    directions.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    xMin :: The horizontal minimum (left-most).                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    yMin :: The vertical minimum (bottom-most).                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    xMax :: The horizontal maximum (right-most).                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    yMax :: The vertical maximum (top-most).                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|QT_FT_BBox_
typedef|typedef
struct|struct
name|QT_FT_BBox_
block|{
DECL|member|xMin
DECL|member|yMin
name|QT_FT_Pos
name|xMin
decl_stmt|,
name|yMin
decl_stmt|;
DECL|member|xMax
DECL|member|yMax
name|QT_FT_Pos
name|xMax
decl_stmt|,
name|yMax
decl_stmt|;
block|}
DECL|typedef|QT_FT_BBox
name|QT_FT_BBox
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    QT_FT_Pixel_Mode                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration type used to describe the format of pixels in a     */
end_comment
begin_comment
comment|/*    given bitmap.  Note that additional formats may be added in the    */
end_comment
begin_comment
comment|/*    future.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_PIXEL_MODE_NONE ::                                              */
end_comment
begin_comment
comment|/*      Value 0 is reserved.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_PIXEL_MODE_MONO ::                                              */
end_comment
begin_comment
comment|/*      A monochrome bitmap, using 1 bit per pixel.  Note that pixels    */
end_comment
begin_comment
comment|/*      are stored in most-significant order (MSB), which means that     */
end_comment
begin_comment
comment|/*      the left-most pixel in a byte has value 128.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_PIXEL_MODE_GRAY ::                                              */
end_comment
begin_comment
comment|/*      An 8-bit bitmap, generally used to represent anti-aliased glyph  */
end_comment
begin_comment
comment|/*      images.  Each pixel is stored in one byte.  Note that the number */
end_comment
begin_comment
comment|/*      of value "gray" levels is stored in the `num_bytes' field of     */
end_comment
begin_comment
comment|/*      the @QT_FT_Bitmap structure (it generally is 256).                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_PIXEL_MODE_GRAY2 ::                                             */
end_comment
begin_comment
comment|/*      A 2-bit/pixel bitmap, used to represent embedded anti-aliased    */
end_comment
begin_comment
comment|/*      bitmaps in font files according to the OpenType specification.   */
end_comment
begin_comment
comment|/*      We haven't found a single font using this format, however.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_PIXEL_MODE_GRAY4 ::                                             */
end_comment
begin_comment
comment|/*      A 4-bit/pixel bitmap, used to represent embedded anti-aliased    */
end_comment
begin_comment
comment|/*      bitmaps in font files according to the OpenType specification.   */
end_comment
begin_comment
comment|/*      We haven't found a single font using this format, however.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_PIXEL_MODE_LCD ::                                               */
end_comment
begin_comment
comment|/*      An 8-bit bitmap, used to represent RGB or BGR decimated glyph    */
end_comment
begin_comment
comment|/*      images used for display on LCD displays; the bitmap's width is   */
end_comment
begin_comment
comment|/*      three times wider than the original glyph image.  See also       */
end_comment
begin_comment
comment|/*      @QT_FT_RENDER_MODE_LCD.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_PIXEL_MODE_LCD_V ::                                             */
end_comment
begin_comment
comment|/*      An 8-bit bitmap, used to represent RGB or BGR decimated glyph    */
end_comment
begin_comment
comment|/*      images used for display on rotated LCD displays; the bitmap's    */
end_comment
begin_comment
comment|/*      height is three times taller than the original glyph image.      */
end_comment
begin_comment
comment|/*      See also @QT_FT_RENDER_MODE_LCD_V.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|QT_FT_Pixel_Mode_
typedef|typedef
enum|enum
name|QT_FT_Pixel_Mode_
block|{
DECL|enumerator|QT_FT_PIXEL_MODE_NONE
name|QT_FT_PIXEL_MODE_NONE
init|=
literal|0
block|,
DECL|enumerator|QT_FT_PIXEL_MODE_MONO
name|QT_FT_PIXEL_MODE_MONO
block|,
DECL|enumerator|QT_FT_PIXEL_MODE_GRAY
name|QT_FT_PIXEL_MODE_GRAY
block|,
DECL|enumerator|QT_FT_PIXEL_MODE_GRAY2
name|QT_FT_PIXEL_MODE_GRAY2
block|,
DECL|enumerator|QT_FT_PIXEL_MODE_GRAY4
name|QT_FT_PIXEL_MODE_GRAY4
block|,
DECL|enumerator|QT_FT_PIXEL_MODE_LCD
name|QT_FT_PIXEL_MODE_LCD
block|,
DECL|enumerator|QT_FT_PIXEL_MODE_LCD_V
name|QT_FT_PIXEL_MODE_LCD_V
block|,
DECL|enumerator|QT_FT_PIXEL_MODE_MAX
name|QT_FT_PIXEL_MODE_MAX
comment|/* do not remove */
block|}
DECL|typedef|QT_FT_Pixel_Mode
name|QT_FT_Pixel_Mode
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    qt_ft_pixel_mode_xxx                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A list of deprecated constants.  Use the corresponding             */
end_comment
begin_comment
comment|/*    @QT_FT_Pixel_Mode values instead.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    qt_ft_pixel_mode_none  :: see @QT_FT_PIXEL_MODE_NONE                     */
end_comment
begin_comment
comment|/*    qt_ft_pixel_mode_mono  :: see @QT_FT_PIXEL_MODE_MONO                     */
end_comment
begin_comment
comment|/*    qt_ft_pixel_mode_grays :: see @QT_FT_PIXEL_MODE_GRAY                     */
end_comment
begin_comment
comment|/*    qt_ft_pixel_mode_pal2  :: see @QT_FT_PIXEL_MODE_GRAY2                    */
end_comment
begin_comment
comment|/*    qt_ft_pixel_mode_pal4  :: see @QT_FT_PIXEL_MODE_GRAY4                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|qt_ft_pixel_mode_none
define|#
directive|define
name|qt_ft_pixel_mode_none
value|QT_FT_PIXEL_MODE_NONE
end_define
begin_define
DECL|macro|qt_ft_pixel_mode_mono
define|#
directive|define
name|qt_ft_pixel_mode_mono
value|QT_FT_PIXEL_MODE_MONO
end_define
begin_define
DECL|macro|qt_ft_pixel_mode_grays
define|#
directive|define
name|qt_ft_pixel_mode_grays
value|QT_FT_PIXEL_MODE_GRAY
end_define
begin_define
DECL|macro|qt_ft_pixel_mode_pal2
define|#
directive|define
name|qt_ft_pixel_mode_pal2
value|QT_FT_PIXEL_MODE_GRAY2
end_define
begin_define
DECL|macro|qt_ft_pixel_mode_pal4
define|#
directive|define
name|qt_ft_pixel_mode_pal4
value|QT_FT_PIXEL_MODE_GRAY4
end_define
begin_comment
comment|/* */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    QT_FT_Palette_Mode                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    THIS TYPE IS DEPRECATED.  DO NOT USE IT!                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    An enumeration type used to describe the format of a bitmap        */
end_comment
begin_comment
comment|/*    palette, used with qt_ft_pixel_mode_pal4 and qt_ft_pixel_mode_pal8.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    qt_ft_palette_mode_rgb  :: The palette is an array of 3-bytes RGB     */
end_comment
begin_comment
comment|/*                            records.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    qt_ft_palette_mode_rgba :: The palette is an array of 4-bytes RGBA    */
end_comment
begin_comment
comment|/*                            records.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    As qt_ft_pixel_mode_pal2, pal4 and pal8 are currently unused by       */
end_comment
begin_comment
comment|/*    FreeType, these types are not handled by the library itself.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
unit|typedef enum  QT_FT_Palette_Mode_   {     qt_ft_palette_mode_rgb = 0,     qt_ft_palette_mode_rgba,      qt_ft_palettte_mode_max
comment|/* do not remove */
end_comment
begin_comment
unit|} QT_FT_Palette_Mode;
comment|/* */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_Bitmap                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to describe a bitmap or pixmap to the raster.     */
end_comment
begin_comment
comment|/*    Note that we now manage pixmaps of various depths through the      */
end_comment
begin_comment
comment|/*    `pixel_mode' field.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    rows         :: The number of bitmap rows.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    width        :: The number of pixels in bitmap row.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pitch        :: The pitch's absolute value is the number of bytes  */
end_comment
begin_comment
comment|/*                    taken by one bitmap row, including padding.        */
end_comment
begin_comment
comment|/*                    However, the pitch is positive when the bitmap has */
end_comment
begin_comment
comment|/*                    a `down' flow, and negative when it has an `up'    */
end_comment
begin_comment
comment|/*                    flow.  In all cases, the pitch is an offset to add */
end_comment
begin_comment
comment|/*                    to a bitmap pointer in order to go down one row.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    buffer       :: A typeless pointer to the bitmap buffer.  This     */
end_comment
begin_comment
comment|/*                    value should be aligned on 32-bit boundaries in    */
end_comment
begin_comment
comment|/*                    most cases.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_grays    :: This field is only used with                       */
end_comment
begin_comment
comment|/*                    `QT_FT_PIXEL_MODE_GRAY'; it gives the number of gray  */
end_comment
begin_comment
comment|/*                    levels used in the bitmap.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pixel_mode   :: The pixel mode, i.e., how pixel bits are stored.   */
end_comment
begin_comment
comment|/*                    See @QT_FT_Pixel_Mode for possible values.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    palette_mode :: This field is only used with paletted pixel modes; */
end_comment
begin_comment
comment|/*                    it indicates how the palette is stored.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    palette      :: A typeless pointer to the bitmap palette; only     */
end_comment
begin_comment
comment|/*                    used for paletted pixel modes.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*   For now, the only pixel mode supported by FreeType are mono and     */
end_comment
begin_comment
comment|/*   grays.  However, drivers might be added in the future to support    */
end_comment
begin_comment
comment|/*   more `colorful' options.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   When using pixel modes pal2, pal4 and pal8 with a void `palette'    */
end_comment
begin_comment
comment|/*   field, a gray pixmap with respectively 4, 16, and 256 levels of     */
end_comment
begin_comment
comment|/*   gray is assumed.  This, in order to be compatible with some         */
end_comment
begin_comment
comment|/*   embedded bitmap formats defined in the TrueType specification.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   Note that no font was found presenting such embedded bitmaps, so    */
end_comment
begin_comment
comment|/*   this is currently completely unhandled by the library.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|QT_FT_Bitmap_
typedef|typedef
struct|struct
name|QT_FT_Bitmap_
block|{
DECL|member|rows
name|int
name|rows
decl_stmt|;
DECL|member|width
name|int
name|width
decl_stmt|;
DECL|member|pitch
name|int
name|pitch
decl_stmt|;
DECL|member|buffer
name|unsigned
name|char
modifier|*
name|buffer
decl_stmt|;
DECL|member|num_grays
name|short
name|num_grays
decl_stmt|;
DECL|member|pixel_mode
name|char
name|pixel_mode
decl_stmt|;
DECL|member|palette_mode
name|char
name|palette_mode
decl_stmt|;
DECL|member|palette
name|void
modifier|*
name|palette
decl_stmt|;
block|}
DECL|typedef|QT_FT_Bitmap
name|QT_FT_Bitmap
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    outline_processing                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_Outline                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This structure is used to describe an outline to the scan-line     */
end_comment
begin_comment
comment|/*    converter.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    n_contours :: The number of contours in the outline.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    n_points   :: The number of points in the outline.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    points     :: A pointer to an array of `n_points' QT_FT_Vector        */
end_comment
begin_comment
comment|/*                  elements, giving the outline's point coordinates.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    tags       :: A pointer to an array of `n_points' chars, giving    */
end_comment
begin_comment
comment|/*                  each outline point's type.  If bit 0 is unset, the   */
end_comment
begin_comment
comment|/*                  point is `off' the curve, i.e. a Bezier control      */
end_comment
begin_comment
comment|/*                  point, while it is `on' when set.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                  Bit 1 is meaningful for `off' points only.  If set,  */
end_comment
begin_comment
comment|/*                  it indicates a third-order Bezier arc control point; */
end_comment
begin_comment
comment|/*                  and a second-order control point if unset.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    contours   :: An array of `n_contours' shorts, giving the end      */
end_comment
begin_comment
comment|/*                  point of each contour within the outline.  For       */
end_comment
begin_comment
comment|/*                  example, the first contour is defined by the points  */
end_comment
begin_comment
comment|/*                  `0' to `contours[0]', the second one is defined by   */
end_comment
begin_comment
comment|/*                  the points `contours[0]+1' to `contours[1]', etc.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    flags      :: A set of bit flags used to characterize the outline  */
end_comment
begin_comment
comment|/*                  and give hints to the scan-converter and hinter on   */
end_comment
begin_comment
comment|/*                  how to convert/grid-fit it.  See QT_FT_Outline_Flags.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|QT_FT_Outline_
typedef|typedef
struct|struct
name|QT_FT_Outline_
block|{
DECL|member|n_contours
name|int
name|n_contours
decl_stmt|;
comment|/* number of contours in glyph        */
DECL|member|n_points
name|int
name|n_points
decl_stmt|;
comment|/* number of points in the glyph      */
DECL|member|points
name|QT_FT_Vector
modifier|*
name|points
decl_stmt|;
comment|/* the outline's points               */
DECL|member|tags
name|char
modifier|*
name|tags
decl_stmt|;
comment|/* the points flags                   */
DECL|member|contours
name|int
modifier|*
name|contours
decl_stmt|;
comment|/* the contour end points             */
DECL|member|flags
name|int
name|flags
decl_stmt|;
comment|/* outline masks                      */
block|}
DECL|typedef|QT_FT_Outline
name|QT_FT_Outline
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*   QT_FT_OUTLINE_FLAGS                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A list of bit-field constants use for the flags in an outline's    */
end_comment
begin_comment
comment|/*    `flags' field.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_OUTLINE_NONE           :: Value 0 is reserved.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_OUTLINE_OWNER          :: If set, this flag indicates that the  */
end_comment
begin_comment
comment|/*                                 outline's field arrays (i.e.          */
end_comment
begin_comment
comment|/*                                 `points', `flags'& `contours') are   */
end_comment
begin_comment
comment|/*                                 `owned' by the outline object, and    */
end_comment
begin_comment
comment|/*                                 should thus be freed when it is       */
end_comment
begin_comment
comment|/*                                 destroyed.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   QT_FT_OUTLINE_EVEN_ODD_FILL   :: By default, outlines are filled using */
end_comment
begin_comment
comment|/*                                 the non-zero winding rule.  If set to */
end_comment
begin_comment
comment|/*                                 1, the outline will be filled using   */
end_comment
begin_comment
comment|/*                                 the even-odd fill rule (only works    */
end_comment
begin_comment
comment|/*                                 with the smooth raster).              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   QT_FT_OUTLINE_REVERSE_FILL    :: By default, outside contours of an    */
end_comment
begin_comment
comment|/*                                 outline are oriented in clock-wise    */
end_comment
begin_comment
comment|/*                                 direction, as defined in the TrueType */
end_comment
begin_comment
comment|/*                                 specification.  This flag is set if   */
end_comment
begin_comment
comment|/*                                 the outline uses the opposite         */
end_comment
begin_comment
comment|/*                                 direction (typically for Type 1       */
end_comment
begin_comment
comment|/*                                 fonts).  This flag is ignored by the  */
end_comment
begin_comment
comment|/*                                 scan-converter.  However, it is very  */
end_comment
begin_comment
comment|/*                                 important for the auto-hinter.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   QT_FT_OUTLINE_IGNORE_DROPOUTS :: By default, the scan converter will   */
end_comment
begin_comment
comment|/*                                 try to detect drop-outs in an outline */
end_comment
begin_comment
comment|/*                                 and correct the glyph bitmap to       */
end_comment
begin_comment
comment|/*                                 ensure consistent shape continuity.   */
end_comment
begin_comment
comment|/*                                 If set, this flag hints the scan-line */
end_comment
begin_comment
comment|/*                                 converter to ignore such cases.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   QT_FT_OUTLINE_HIGH_PRECISION  :: This flag indicates that the          */
end_comment
begin_comment
comment|/*                                 scan-line converter should try to     */
end_comment
begin_comment
comment|/*                                 convert this outline to bitmaps with  */
end_comment
begin_comment
comment|/*                                 the highest possible quality.  It is  */
end_comment
begin_comment
comment|/*                                 typically set for small character     */
end_comment
begin_comment
comment|/*                                 sizes.  Note that this is only a      */
end_comment
begin_comment
comment|/*                                 hint, that might be completely        */
end_comment
begin_comment
comment|/*                                 ignored by a given scan-converter.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   QT_FT_OUTLINE_SINGLE_PASS     :: This flag is set to force a given     */
end_comment
begin_comment
comment|/*                                 scan-converter to only use a single   */
end_comment
begin_comment
comment|/*                                 pass over the outline to render a     */
end_comment
begin_comment
comment|/*                                 bitmap glyph image.  Normally, it is  */
end_comment
begin_comment
comment|/*                                 set for very large character sizes.   */
end_comment
begin_comment
comment|/*                                 It is only a hint, that might be      */
end_comment
begin_comment
comment|/*                                 completely ignored by a given         */
end_comment
begin_comment
comment|/*                                 scan-converter.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|QT_FT_OUTLINE_NONE
define|#
directive|define
name|QT_FT_OUTLINE_NONE
value|0x0
end_define
begin_define
DECL|macro|QT_FT_OUTLINE_OWNER
define|#
directive|define
name|QT_FT_OUTLINE_OWNER
value|0x1
end_define
begin_define
DECL|macro|QT_FT_OUTLINE_EVEN_ODD_FILL
define|#
directive|define
name|QT_FT_OUTLINE_EVEN_ODD_FILL
value|0x2
end_define
begin_define
DECL|macro|QT_FT_OUTLINE_REVERSE_FILL
define|#
directive|define
name|QT_FT_OUTLINE_REVERSE_FILL
value|0x4
end_define
begin_define
DECL|macro|QT_FT_OUTLINE_IGNORE_DROPOUTS
define|#
directive|define
name|QT_FT_OUTLINE_IGNORE_DROPOUTS
value|0x8
end_define
begin_define
DECL|macro|QT_FT_OUTLINE_HIGH_PRECISION
define|#
directive|define
name|QT_FT_OUTLINE_HIGH_PRECISION
value|0x100
end_define
begin_define
DECL|macro|QT_FT_OUTLINE_SINGLE_PASS
define|#
directive|define
name|QT_FT_OUTLINE_SINGLE_PASS
value|0x200
end_define
begin_comment
comment|/*************************************************************************   *   * @enum:   *   qt_ft_outline_flags   *   * @description:   *   These constants are deprecated.  Please use the corresponding   *   @QT_FT_OUTLINE_FLAGS values.   *   * @values:   *   qt_ft_outline_none            :: See @QT_FT_OUTLINE_NONE.   *   qt_ft_outline_owner           :: See @QT_FT_OUTLINE_OWNER.   *   qt_ft_outline_even_odd_fill   :: See @QT_FT_OUTLINE_EVEN_ODD_FILL.   *   qt_ft_outline_reverse_fill    :: See @QT_FT_OUTLINE_REVERSE_FILL.   *   qt_ft_outline_ignore_dropouts :: See @QT_FT_OUTLINE_IGNORE_DROPOUTS.   *   qt_ft_outline_high_precision  :: See @QT_FT_OUTLINE_HIGH_PRECISION.   *   qt_ft_outline_single_pass     :: See @QT_FT_OUTLINE_SINGLE_PASS.   */
end_comment
begin_define
DECL|macro|qt_ft_outline_none
define|#
directive|define
name|qt_ft_outline_none
value|QT_FT_OUTLINE_NONE
end_define
begin_define
DECL|macro|qt_ft_outline_owner
define|#
directive|define
name|qt_ft_outline_owner
value|QT_FT_OUTLINE_OWNER
end_define
begin_define
DECL|macro|qt_ft_outline_even_odd_fill
define|#
directive|define
name|qt_ft_outline_even_odd_fill
value|QT_FT_OUTLINE_EVEN_ODD_FILL
end_define
begin_define
DECL|macro|qt_ft_outline_reverse_fill
define|#
directive|define
name|qt_ft_outline_reverse_fill
value|QT_FT_OUTLINE_REVERSE_FILL
end_define
begin_define
DECL|macro|qt_ft_outline_ignore_dropouts
define|#
directive|define
name|qt_ft_outline_ignore_dropouts
value|QT_FT_OUTLINE_IGNORE_DROPOUTS
end_define
begin_define
DECL|macro|qt_ft_outline_high_precision
define|#
directive|define
name|qt_ft_outline_high_precision
value|QT_FT_OUTLINE_HIGH_PRECISION
end_define
begin_define
DECL|macro|qt_ft_outline_single_pass
define|#
directive|define
name|qt_ft_outline_single_pass
value|QT_FT_OUTLINE_SINGLE_PASS
end_define
begin_comment
comment|/* */
end_comment
begin_define
DECL|macro|QT_FT_CURVE_TAG
define|#
directive|define
name|QT_FT_CURVE_TAG
parameter_list|(
name|flag
parameter_list|)
value|( flag& 3 )
end_define
begin_define
DECL|macro|QT_FT_CURVE_TAG_ON
define|#
directive|define
name|QT_FT_CURVE_TAG_ON
value|1
end_define
begin_define
DECL|macro|QT_FT_CURVE_TAG_CONIC
define|#
directive|define
name|QT_FT_CURVE_TAG_CONIC
value|0
end_define
begin_define
DECL|macro|QT_FT_CURVE_TAG_CUBIC
define|#
directive|define
name|QT_FT_CURVE_TAG_CUBIC
value|2
end_define
begin_define
DECL|macro|QT_FT_CURVE_TAG_TOUCH_X
define|#
directive|define
name|QT_FT_CURVE_TAG_TOUCH_X
value|8
end_define
begin_comment
DECL|macro|QT_FT_CURVE_TAG_TOUCH_X
comment|/* reserved for the TrueType hinter */
end_comment
begin_define
DECL|macro|QT_FT_CURVE_TAG_TOUCH_Y
define|#
directive|define
name|QT_FT_CURVE_TAG_TOUCH_Y
value|16
end_define
begin_comment
DECL|macro|QT_FT_CURVE_TAG_TOUCH_Y
comment|/* reserved for the TrueType hinter */
end_comment
begin_define
DECL|macro|QT_FT_CURVE_TAG_TOUCH_BOTH
define|#
directive|define
name|QT_FT_CURVE_TAG_TOUCH_BOTH
value|( QT_FT_CURVE_TAG_TOUCH_X | \                                    QT_FT_CURVE_TAG_TOUCH_Y )
end_define
begin_define
DECL|macro|QT_FT_Curve_Tag_On
define|#
directive|define
name|QT_FT_Curve_Tag_On
value|QT_FT_CURVE_TAG_ON
end_define
begin_define
DECL|macro|QT_FT_Curve_Tag_Conic
define|#
directive|define
name|QT_FT_Curve_Tag_Conic
value|QT_FT_CURVE_TAG_CONIC
end_define
begin_define
DECL|macro|QT_FT_Curve_Tag_Cubic
define|#
directive|define
name|QT_FT_Curve_Tag_Cubic
value|QT_FT_CURVE_TAG_CUBIC
end_define
begin_define
DECL|macro|QT_FT_Curve_Tag_Touch_X
define|#
directive|define
name|QT_FT_Curve_Tag_Touch_X
value|QT_FT_CURVE_TAG_TOUCH_X
end_define
begin_define
DECL|macro|QT_FT_Curve_Tag_Touch_Y
define|#
directive|define
name|QT_FT_Curve_Tag_Touch_Y
value|QT_FT_CURVE_TAG_TOUCH_Y
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Outline_MoveToFunc                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function pointer type used to describe the signature of a `move  */
end_comment
begin_comment
comment|/*    to' function during outline walking/decomposition.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    A `move to' is emitted to start a new contour in an outline.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    to   :: A pointer to the target point of the `move to'.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user :: A typeless pointer which is passed from the caller of the  */
end_comment
begin_comment
comment|/*            decomposition function.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Error code.  0 means success.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|QT_FT_Outline_MoveToFunc
modifier|*
name|QT_FT_Outline_MoveToFunc
function_decl|)
parameter_list|(
name|QT_FT_Vector
modifier|*
name|to
parameter_list|,
name|void
modifier|*
name|user
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Outline_MoveTo_Func
define|#
directive|define
name|QT_FT_Outline_MoveTo_Func
value|QT_FT_Outline_MoveToFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Outline_LineToFunc                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function pointer type used to describe the signature of a `line  */
end_comment
begin_comment
comment|/*    to' function during outline walking/decomposition.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    A `line to' is emitted to indicate a segment in the outline.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    to   :: A pointer to the target point of the `line to'.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user :: A typeless pointer which is passed from the caller of the  */
end_comment
begin_comment
comment|/*            decomposition function.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Error code.  0 means success.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|QT_FT_Outline_LineToFunc
modifier|*
name|QT_FT_Outline_LineToFunc
function_decl|)
parameter_list|(
name|QT_FT_Vector
modifier|*
name|to
parameter_list|,
name|void
modifier|*
name|user
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Outline_LineTo_Func
define|#
directive|define
name|QT_FT_Outline_LineTo_Func
value|QT_FT_Outline_LineToFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Outline_ConicToFunc                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function pointer type use to describe the signature of a `conic  */
end_comment
begin_comment
comment|/*    to' function during outline walking/decomposition.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    A `conic to' is emitted to indicate a second-order Bezier arc in   */
end_comment
begin_comment
comment|/*    the outline.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    control :: An intermediate control point between the last position */
end_comment
begin_comment
comment|/*               and the new target in `to'.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    to      :: A pointer to the target end point of the conic arc.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user    :: A typeless pointer which is passed from the caller of   */
end_comment
begin_comment
comment|/*               the decomposition function.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Error code.  0 means success.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|QT_FT_Outline_ConicToFunc
modifier|*
name|QT_FT_Outline_ConicToFunc
function_decl|)
parameter_list|(
name|QT_FT_Vector
modifier|*
name|control
parameter_list|,
name|QT_FT_Vector
modifier|*
name|to
parameter_list|,
name|void
modifier|*
name|user
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Outline_ConicTo_Func
define|#
directive|define
name|QT_FT_Outline_ConicTo_Func
value|QT_FT_Outline_ConicToFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Outline_CubicToFunc                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function pointer type used to describe the signature of a `cubic */
end_comment
begin_comment
comment|/*    to' function during outline walking/decomposition.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    A `cubic to' is emitted to indicate a third-order Bezier arc.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    control1 :: A pointer to the first Bezier control point.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    control2 :: A pointer to the second Bezier control point.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    to       :: A pointer to the target end point.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user     :: A typeless pointer which is passed from the caller of  */
end_comment
begin_comment
comment|/*                the decomposition function.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Error code.  0 means success.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|QT_FT_Outline_CubicToFunc
modifier|*
name|QT_FT_Outline_CubicToFunc
function_decl|)
parameter_list|(
name|QT_FT_Vector
modifier|*
name|control1
parameter_list|,
name|QT_FT_Vector
modifier|*
name|control2
parameter_list|,
name|QT_FT_Vector
modifier|*
name|to
parameter_list|,
name|void
modifier|*
name|user
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Outline_CubicTo_Func
define|#
directive|define
name|QT_FT_Outline_CubicTo_Func
value|QT_FT_Outline_CubicToFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_Outline_Funcs                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure to hold various function pointers used during outline  */
end_comment
begin_comment
comment|/*    decomposition in order to emit segments, conic, and cubic Beziers, */
end_comment
begin_comment
comment|/*    as well as `move to' and `close to' operations.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    move_to  :: The `move to' emitter.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    line_to  :: The segment emitter.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    conic_to :: The second-order Bezier arc emitter.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cubic_to :: The third-order Bezier arc emitter.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    shift    :: The shift that is applied to coordinates before they   */
end_comment
begin_comment
comment|/*                are sent to the emitter.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    delta    :: The delta that is applied to coordinates before they   */
end_comment
begin_comment
comment|/*                are sent to the emitter, but after the shift.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The point coordinates sent to the emitters are the transformed     */
end_comment
begin_comment
comment|/*    version of the original coordinates (this is important for high    */
end_comment
begin_comment
comment|/*    accuracy during scan-conversion).  The transformation is simple:   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      x' = (x<< shift) - delta                                        */
end_comment
begin_comment
comment|/*      y' = (x<< shift) - delta                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Set the value of `shift' and `delta' to 0 to get the original      */
end_comment
begin_comment
comment|/*    point coordinates.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|QT_FT_Outline_Funcs_
typedef|typedef
struct|struct
name|QT_FT_Outline_Funcs_
block|{
DECL|member|move_to
name|QT_FT_Outline_MoveToFunc
name|move_to
decl_stmt|;
DECL|member|line_to
name|QT_FT_Outline_LineToFunc
name|line_to
decl_stmt|;
DECL|member|conic_to
name|QT_FT_Outline_ConicToFunc
name|conic_to
decl_stmt|;
DECL|member|cubic_to
name|QT_FT_Outline_CubicToFunc
name|cubic_to
decl_stmt|;
DECL|member|shift
name|int
name|shift
decl_stmt|;
DECL|member|delta
name|QT_FT_Pos
name|delta
decl_stmt|;
block|}
DECL|typedef|QT_FT_Outline_Funcs
name|QT_FT_Outline_Funcs
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    basic_types                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    QT_FT_IMAGE_TAG                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This macro converts four letter tags into an unsigned long.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Since many 16bit compilers don't like 32bit enumerations, you      */
end_comment
begin_comment
comment|/*    should redefine this macro in case of problems to something like   */
end_comment
begin_comment
comment|/*    this:                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      #define QT_FT_IMAGE_TAG( value, _x1, _x2, _x3, _x4 )  value         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    to get a simple enumeration without assigning special numbers.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_FT_IMAGE_TAG
end_ifndef
begin_define
DECL|macro|QT_FT_IMAGE_TAG
define|#
directive|define
name|QT_FT_IMAGE_TAG
parameter_list|(
name|value
parameter_list|,
name|_x1
parameter_list|,
name|_x2
parameter_list|,
name|_x3
parameter_list|,
name|_x4
parameter_list|)
define|\
value|value = ( ( (unsigned long)_x1<< 24 ) | \                     ( (unsigned long)_x2<< 16 ) | \                     ( (unsigned long)_x3<< 8  ) | \                       (unsigned long)_x4         )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* QT_FT_IMAGE_TAG */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    QT_FT_Glyph_Format                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration type used to describe the format of a given glyph   */
end_comment
begin_comment
comment|/*    image.  Note that this version of FreeType only supports two image */
end_comment
begin_comment
comment|/*    formats, even though future font drivers will be able to register  */
end_comment
begin_comment
comment|/*    their own format.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_GLYPH_FORMAT_NONE ::                                            */
end_comment
begin_comment
comment|/*      The value 0 is reserved and does describe a glyph format.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_GLYPH_FORMAT_COMPOSITE ::                                       */
end_comment
begin_comment
comment|/*      The glyph image is a composite of several other images.  This    */
end_comment
begin_comment
comment|/*      format is _only_ used with @QT_FT_LOAD_NO_RECURSE, and is used to   */
end_comment
begin_comment
comment|/*      report compound glyphs (like accented characters).               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_GLYPH_FORMAT_BITMAP ::                                          */
end_comment
begin_comment
comment|/*      The glyph image is a bitmap, and can be described as an          */
end_comment
begin_comment
comment|/*      @QT_FT_Bitmap.  You generally need to access the `bitmap' field of  */
end_comment
begin_comment
comment|/*      the @QT_FT_GlyphSlotRec structure to read it.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_GLYPH_FORMAT_OUTLINE ::                                         */
end_comment
begin_comment
comment|/*      The glyph image is a vertorial outline made of line segments     */
end_comment
begin_comment
comment|/*      and Bezier arcs; it can be described as an @QT_FT_Outline; you      */
end_comment
begin_comment
comment|/*      generally want to access the `outline' field of the              */
end_comment
begin_comment
comment|/*      @QT_FT_GlyphSlotRec structure to read it.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_GLYPH_FORMAT_PLOTTER ::                                         */
end_comment
begin_comment
comment|/*      The glyph image is a vectorial path with no inside/outside       */
end_comment
begin_comment
comment|/*      contours.  Some Type 1 fonts, like those in the Hershey family,  */
end_comment
begin_comment
comment|/*      contain glyphs in this format.  These are described as           */
end_comment
begin_comment
comment|/*      @QT_FT_Outline, but FreeType isn't currently capable of rendering   */
end_comment
begin_comment
comment|/*      them correctly.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|QT_FT_Glyph_Format_
typedef|typedef
enum|enum
name|QT_FT_Glyph_Format_
block|{
DECL|enumerator|QT_FT_IMAGE_TAG
name|QT_FT_IMAGE_TAG
argument_list|(
name|QT_FT_GLYPH_FORMAT_NONE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|QT_FT_IMAGE_TAG
name|QT_FT_IMAGE_TAG
argument_list|(
name|QT_FT_GLYPH_FORMAT_COMPOSITE
argument_list|,
literal|'c'
argument_list|,
literal|'o'
argument_list|,
literal|'m'
argument_list|,
literal|'p'
argument_list|)
block|,
DECL|enumerator|QT_FT_IMAGE_TAG
name|QT_FT_IMAGE_TAG
argument_list|(
name|QT_FT_GLYPH_FORMAT_BITMAP
argument_list|,
literal|'b'
argument_list|,
literal|'i'
argument_list|,
literal|'t'
argument_list|,
literal|'s'
argument_list|)
block|,
DECL|enumerator|QT_FT_IMAGE_TAG
name|QT_FT_IMAGE_TAG
argument_list|(
name|QT_FT_GLYPH_FORMAT_OUTLINE
argument_list|,
literal|'o'
argument_list|,
literal|'u'
argument_list|,
literal|'t'
argument_list|,
literal|'l'
argument_list|)
block|,
DECL|enumerator|QT_FT_IMAGE_TAG
name|QT_FT_IMAGE_TAG
argument_list|(
argument|QT_FT_GLYPH_FORMAT_PLOTTER
argument_list|,
literal|'p'
argument_list|,
literal|'l'
argument_list|,
literal|'o'
argument_list|,
literal|'t'
argument_list|)
block|}
DECL|typedef|QT_FT_Glyph_Format
name|QT_FT_Glyph_Format
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    qt_ft_glyph_format_xxx                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A list of decprecated constants.  Use the corresponding            */
end_comment
begin_comment
comment|/*    @QT_FT_Glyph_Format values instead.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    qt_ft_glyph_format_none      :: see @QT_FT_GLYPH_FORMAT_NONE             */
end_comment
begin_comment
comment|/*    qt_ft_glyph_format_composite :: see @QT_FT_GLYPH_FORMAT_COMPOSITE        */
end_comment
begin_comment
comment|/*    qt_ft_glyph_format_bitmap    :: see @QT_FT_GLYPH_FORMAT_BITMAP           */
end_comment
begin_comment
comment|/*    qt_ft_glyph_format_outline   :: see @QT_FT_GLYPH_FORMAT_OUTLINE          */
end_comment
begin_comment
comment|/*    qt_ft_glyph_format_plotter   :: see @QT_FT_GLYPH_FORMAT_PLOTTER          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|qt_ft_glyph_format_none
define|#
directive|define
name|qt_ft_glyph_format_none
value|QT_FT_GLYPH_FORMAT_NONE
end_define
begin_define
DECL|macro|qt_ft_glyph_format_composite
define|#
directive|define
name|qt_ft_glyph_format_composite
value|QT_FT_GLYPH_FORMAT_COMPOSITE
end_define
begin_define
DECL|macro|qt_ft_glyph_format_bitmap
define|#
directive|define
name|qt_ft_glyph_format_bitmap
value|QT_FT_GLYPH_FORMAT_BITMAP
end_define
begin_define
DECL|macro|qt_ft_glyph_format_outline
define|#
directive|define
name|qt_ft_glyph_format_outline
value|QT_FT_GLYPH_FORMAT_OUTLINE
end_define
begin_define
DECL|macro|qt_ft_glyph_format_plotter
define|#
directive|define
name|qt_ft_glyph_format_plotter
value|QT_FT_GLYPH_FORMAT_PLOTTER
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****            R A S T E R   D E F I N I T I O N S                *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* A raster is a scan converter, in charge of rendering an outline into  */
end_comment
begin_comment
comment|/* a a bitmap.  This section contains the public API for rasters.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Note that in FreeType 2, all rasters are now encapsulated within      */
end_comment
begin_comment
comment|/* specific modules called `renderers'.  See `freetype/ftrender.h' for   */
end_comment
begin_comment
comment|/* more details on renderers.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    raster                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Scanline converter                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    How vectorial outlines are converted into bitmaps and pixmaps.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section contains technical definitions.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    QT_FT_Raster                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle (pointer) to a raster object.  Each object can be used    */
end_comment
begin_comment
comment|/*    independently to convert an outline into a bitmap or pixmap.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|QT_FT_Raster
typedef|typedef
name|struct
name|TRaster_
modifier|*
name|QT_FT_Raster
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_Span                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a single span of gray (or black) pixels  */
end_comment
begin_comment
comment|/*    when rendering a monochrome or anti-aliased bitmap.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    x        :: The span's horizontal start position.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    len      :: The span's length in pixels.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    coverage :: The span color/coverage, ranging from 0 (background)   */
end_comment
begin_comment
comment|/*                to 255 (foreground).  Only used for anti-aliased       */
end_comment
begin_comment
comment|/*                rendering.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This structure is used by the span drawing callback type named     */
end_comment
begin_comment
comment|/*    QT_FT_SpanFunc which takes the y-coordinate of the span as a          */
end_comment
begin_comment
comment|/*    a parameter.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The coverage value is always between 0 and 255, even if the number */
end_comment
begin_comment
comment|/*    of gray levels have been set through QT_FT_Set_Gray_Levels().         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|QT_FT_Span_
typedef|typedef
struct|struct
name|QT_FT_Span_
block|{
DECL|member|x
name|short
name|x
decl_stmt|;
DECL|member|len
name|unsigned
name|short
name|len
decl_stmt|;
DECL|member|y
name|short
name|y
decl_stmt|;
DECL|member|coverage
name|unsigned
name|char
name|coverage
decl_stmt|;
block|}
DECL|typedef|QT_FT_Span
name|QT_FT_Span
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_SpanFunc                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used as a call-back by the anti-aliased renderer in     */
end_comment
begin_comment
comment|/*    order to let client applications draw themselves the gray pixel    */
end_comment
begin_comment
comment|/*    spans on each scan line.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    y     :: The scanline's y-coordinate.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    count :: The number of spans to draw on this scanline.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    spans :: A table of `count' spans to draw on the scanline.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user  :: User-supplied data that is passed to the callback.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This callback allows client applications to directly render the    */
end_comment
begin_comment
comment|/*    gray spans of the anti-aliased bitmap to any kind of surfaces.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This can be used to write anti-aliased outlines directly to a      */
end_comment
begin_comment
comment|/*    given background bitmap, and even perform translucency.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that the `count' field cannot be greater than a fixed value   */
end_comment
begin_comment
comment|/*    defined by the QT_FT_MAX_GRAY_SPANS configuration macro in            */
end_comment
begin_comment
comment|/*    ftoption.h.  By default, this value is set to 32, which means that */
end_comment
begin_comment
comment|/*    if there are more than 32 spans on a given scanline, the callback  */
end_comment
begin_comment
comment|/*    will be called several times with the same `y' parameter in order  */
end_comment
begin_comment
comment|/*    to draw all callbacks.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Otherwise, the callback is only called once per scan-line, and     */
end_comment
begin_comment
comment|/*    only for those scanlines that do have `gray' pixels on them.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|QT_FT_SpanFunc
modifier|*
name|QT_FT_SpanFunc
function_decl|)
parameter_list|(
name|int
name|count
parameter_list|,
specifier|const
name|QT_FT_Span
modifier|*
name|spans
parameter_list|,
name|void
modifier|*
name|worker
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Raster_Span_Func
define|#
directive|define
name|QT_FT_Raster_Span_Func
value|QT_FT_SpanFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Raster_BitTest_Func                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    THIS TYPE IS DEPRECATED.  DO NOT USE IT.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    A function used as a call-back by the monochrome scan-converter    */
end_comment
begin_comment
comment|/*    to test whether a given target pixel is already set to the drawing */
end_comment
begin_comment
comment|/*    `color'.  These tests are crucial to implement drop-out control    */
end_comment
begin_comment
comment|/*    per-se the TrueType spec.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    y     :: The pixel's y-coordinate.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    x     :: The pixel's x-coordinate.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user  :: User-supplied data that is passed to the callback.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*   1 if the pixel is `set', 0 otherwise.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|QT_FT_Raster_BitTest_Func
modifier|*
name|QT_FT_Raster_BitTest_Func
function_decl|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|void
modifier|*
name|user
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Raster_BitSet_Func                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    THIS TYPE IS DEPRECATED.  DO NOT USE IT.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    A function used as a call-back by the monochrome scan-converter    */
end_comment
begin_comment
comment|/*    to set an individual target pixel.  This is crucial to implement   */
end_comment
begin_comment
comment|/*    drop-out control according to the TrueType specification.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    y     :: The pixel's y-coordinate.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    x     :: The pixel's x-coordinate.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user  :: User-supplied data that is passed to the callback.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    1 if the pixel is `set', 0 otherwise.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|QT_FT_Raster_BitSet_Func
modifier|*
name|QT_FT_Raster_BitSet_Func
function_decl|)
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|void
modifier|*
name|user
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    QT_FT_RASTER_FLAG_XXX                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A list of bit flag constants as used in the `flags' field of a     */
end_comment
begin_comment
comment|/*    @QT_FT_Raster_Params structure.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_RASTER_FLAG_DEFAULT :: This value is 0.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_RASTER_FLAG_AA      :: This flag is set to indicate that an     */
end_comment
begin_comment
comment|/*                              anti-aliased glyph image should be       */
end_comment
begin_comment
comment|/*                              generated.  Otherwise, it will be        */
end_comment
begin_comment
comment|/*                              monochrome (1-bit).                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_RASTER_FLAG_DIRECT  :: This flag is set to indicate direct      */
end_comment
begin_comment
comment|/*                              rendering.  In this mode, client         */
end_comment
begin_comment
comment|/*                              applications must provide their own span */
end_comment
begin_comment
comment|/*                              callback.  This lets them directly       */
end_comment
begin_comment
comment|/*                              draw or compose over an existing bitmap. */
end_comment
begin_comment
comment|/*                              If this bit is not set, the target       */
end_comment
begin_comment
comment|/*                              pixmap's buffer _must_ be zeroed before  */
end_comment
begin_comment
comment|/*                              rendering.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                              Note that for now, direct rendering is   */
end_comment
begin_comment
comment|/*                              only possible with anti-aliased glyphs.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    QT_FT_RASTER_FLAG_CLIP    :: This flag is only used in direct         */
end_comment
begin_comment
comment|/*                              rendering mode.  If set, the output will */
end_comment
begin_comment
comment|/*                              be clipped to a box specified in the     */
end_comment
begin_comment
comment|/*                              "clip_box" field of the QT_FT_Raster_Params */
end_comment
begin_comment
comment|/*                              structure.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                              Note that by default, the glyph bitmap   */
end_comment
begin_comment
comment|/*                              is clipped to the target pixmap, except  */
end_comment
begin_comment
comment|/*                              in direct rendering mode where all spans */
end_comment
begin_comment
comment|/*                              are generated if no clipping box is set. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|QT_FT_RASTER_FLAG_DEFAULT
define|#
directive|define
name|QT_FT_RASTER_FLAG_DEFAULT
value|0x0
end_define
begin_define
DECL|macro|QT_FT_RASTER_FLAG_AA
define|#
directive|define
name|QT_FT_RASTER_FLAG_AA
value|0x1
end_define
begin_define
DECL|macro|QT_FT_RASTER_FLAG_DIRECT
define|#
directive|define
name|QT_FT_RASTER_FLAG_DIRECT
value|0x2
end_define
begin_define
DECL|macro|QT_FT_RASTER_FLAG_CLIP
define|#
directive|define
name|QT_FT_RASTER_FLAG_CLIP
value|0x4
end_define
begin_comment
comment|/* deprecated */
end_comment
begin_define
DECL|macro|qt_ft_raster_flag_default
define|#
directive|define
name|qt_ft_raster_flag_default
value|QT_FT_RASTER_FLAG_DEFAULT
end_define
begin_define
DECL|macro|qt_ft_raster_flag_aa
define|#
directive|define
name|qt_ft_raster_flag_aa
value|QT_FT_RASTER_FLAG_AA
end_define
begin_define
DECL|macro|qt_ft_raster_flag_direct
define|#
directive|define
name|qt_ft_raster_flag_direct
value|QT_FT_RASTER_FLAG_DIRECT
end_define
begin_define
DECL|macro|qt_ft_raster_flag_clip
define|#
directive|define
name|qt_ft_raster_flag_clip
value|QT_FT_RASTER_FLAG_CLIP
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_Raster_Params                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure to hold the arguments used by a raster's render        */
end_comment
begin_comment
comment|/*    function.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    target      :: The target bitmap.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    source      :: A pointer to the source glyph image (e.g. an        */
end_comment
begin_comment
comment|/*                   QT_FT_Outline).                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    flags       :: The rendering flags.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gray_spans  :: The gray span drawing callback.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    black_spans :: The black span drawing callback.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bit_test    :: The bit test callback.  UNIMPLEMENTED!              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bit_set     :: The bit set callback.  UNIMPLEMENTED!               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    user        :: User-supplied data that is passed to each drawing   */
end_comment
begin_comment
comment|/*                   callback.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    clip_box    :: An optional clipping box.  It is only used in       */
end_comment
begin_comment
comment|/*                   direct rendering mode.  Note that coordinates here  */
end_comment
begin_comment
comment|/*                   should be expressed in _integer_ pixels (and not in */
end_comment
begin_comment
comment|/*                   26.6 fixed-point units).                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    An anti-aliased glyph bitmap is drawn if the QT_FT_RASTER_FLAG_AA bit */
end_comment
begin_comment
comment|/*    flag is set in the `flags' field, otherwise a monochrome bitmap    */
end_comment
begin_comment
comment|/*    will be generated.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If the QT_FT_RASTER_FLAG_DIRECT bit flag is set in `flags', the       */
end_comment
begin_comment
comment|/*    raster will call the `gray_spans' callback to draw gray pixel      */
end_comment
begin_comment
comment|/*    spans, in the case of an aa glyph bitmap, it will call             */
end_comment
begin_comment
comment|/*    `black_spans', and `bit_test' and `bit_set' in the case of a       */
end_comment
begin_comment
comment|/*    monochrome bitmap.  This allows direct composition over a          */
end_comment
begin_comment
comment|/*    pre-existing bitmap through user-provided callbacks to perform the */
end_comment
begin_comment
comment|/*    span drawing/composition.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that the `bit_test' and `bit_set' callbacks are required when */
end_comment
begin_comment
comment|/*    rendering a monochrome bitmap, as they are crucial to implement    */
end_comment
begin_comment
comment|/*    correct drop-out control as defined in the TrueType specification. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|QT_FT_Raster_Params_
typedef|typedef
struct|struct
name|QT_FT_Raster_Params_
block|{
DECL|member|target
name|QT_FT_Bitmap
modifier|*
name|target
decl_stmt|;
DECL|member|source
name|void
modifier|*
name|source
decl_stmt|;
DECL|member|flags
name|int
name|flags
decl_stmt|;
DECL|member|gray_spans
name|QT_FT_SpanFunc
name|gray_spans
decl_stmt|;
DECL|member|black_spans
name|QT_FT_SpanFunc
name|black_spans
decl_stmt|;
DECL|member|bit_test
name|QT_FT_Raster_BitTest_Func
name|bit_test
decl_stmt|;
comment|/* doesn't work! */
DECL|member|bit_set
name|QT_FT_Raster_BitSet_Func
name|bit_set
decl_stmt|;
comment|/* doesn't work! */
DECL|member|user
name|void
modifier|*
name|user
decl_stmt|;
DECL|member|clip_box
name|QT_FT_BBox
name|clip_box
decl_stmt|;
DECL|member|skip_spans
name|int
name|skip_spans
decl_stmt|;
block|}
DECL|typedef|QT_FT_Raster_Params
name|QT_FT_Raster_Params
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Raster_NewFunc                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to create a new raster object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    memory :: A handle to the memory allocator.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    raster :: A handle to the new raster object.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Error code.  0 means success.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The `memory' parameter is a typeless pointer in order to avoid     */
end_comment
begin_comment
comment|/*    un-wanted dependencies on the rest of the FreeType code.  In       */
end_comment
begin_comment
comment|/*    practice, it is a QT_FT_Memory, i.e., a handle to the standard        */
end_comment
begin_comment
comment|/*    FreeType memory allocator.  However, this field can be completely  */
end_comment
begin_comment
comment|/*    ignored by a given raster implementation.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|QT_FT_Raster_NewFunc
modifier|*
name|QT_FT_Raster_NewFunc
function_decl|)
parameter_list|(
name|QT_FT_Raster
modifier|*
name|raster
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Raster_New_Func
define|#
directive|define
name|QT_FT_Raster_New_Func
value|QT_FT_Raster_NewFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Raster_DoneFunc                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to destroy a given raster object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    raster :: A handle to the raster object.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|QT_FT_Raster_DoneFunc
modifier|*
name|QT_FT_Raster_DoneFunc
function_decl|)
parameter_list|(
name|QT_FT_Raster
name|raster
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Raster_Done_Func
define|#
directive|define
name|QT_FT_Raster_Done_Func
value|QT_FT_Raster_DoneFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Raster_ResetFunc                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    FreeType provides an area of memory called the `render pool',      */
end_comment
begin_comment
comment|/*    available to all registered rasters.  This pool can be freely used */
end_comment
begin_comment
comment|/*    during a given scan-conversion but is shared by all rasters.  Its  */
end_comment
begin_comment
comment|/*    content is thus transient.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function is called each time the render pool changes, or just */
end_comment
begin_comment
comment|/*    after a new raster object is created.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    raster    :: A handle to the new raster object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pool_base :: The address in memory of the render pool.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pool_size :: The size in bytes of the render pool.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Rasters can ignore the render pool and rely on dynamic memory      */
end_comment
begin_comment
comment|/*    allocation if they want to (a handle to the memory allocator is    */
end_comment
begin_comment
comment|/*    passed to the raster constructor).  However, this is not           */
end_comment
begin_comment
comment|/*    recommended for efficiency purposes.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|QT_FT_Raster_ResetFunc
modifier|*
name|QT_FT_Raster_ResetFunc
function_decl|)
parameter_list|(
name|QT_FT_Raster
name|raster
parameter_list|,
name|unsigned
name|char
modifier|*
name|pool_base
parameter_list|,
name|unsigned
name|long
name|pool_size
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Raster_Reset_Func
define|#
directive|define
name|QT_FT_Raster_Reset_Func
value|QT_FT_Raster_ResetFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Raster_SetModeFunc                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is a generic facility to change modes or attributes  */
end_comment
begin_comment
comment|/*    in a given raster.  This can be used for debugging purposes, or    */
end_comment
begin_comment
comment|/*    simply to allow implementation-specific `features' in a given      */
end_comment
begin_comment
comment|/*    raster module.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    raster :: A handle to the new raster object.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    mode   :: A 4-byte tag used to name the mode or property.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    args   :: A pointer to the new mode/property to use.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|QT_FT_Raster_SetModeFunc
modifier|*
name|QT_FT_Raster_SetModeFunc
function_decl|)
parameter_list|(
name|QT_FT_Raster
name|raster
parameter_list|,
name|unsigned
name|long
name|mode
parameter_list|,
name|void
modifier|*
name|args
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Raster_Set_Mode_Func
define|#
directive|define
name|QT_FT_Raster_Set_Mode_Func
value|QT_FT_Raster_SetModeFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    QT_FT_Raster_RenderFunc                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*   Invokes a given raster to scan-convert a given glyph image into a   */
end_comment
begin_comment
comment|/*   target bitmap.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    raster :: A handle to the raster object.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    params :: A pointer to a QT_FT_Raster_Params structure used to store  */
end_comment
begin_comment
comment|/*              the rendering parameters.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    Error code.  0 means success.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The exact format of the source image depends on the raster's glyph */
end_comment
begin_comment
comment|/*    format defined in its QT_FT_Raster_Funcs structure.  It can be an     */
end_comment
begin_comment
comment|/*    QT_FT_Outline or anything else in order to support a large array of   */
end_comment
begin_comment
comment|/*    glyph formats.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note also that the render function can fail and return a           */
end_comment
begin_comment
comment|/*    QT_FT_Err_Unimplemented_Feature error code if the raster used does    */
end_comment
begin_comment
comment|/*    not support direct composition.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    XXX: For now, the standard raster doesn't support direct           */
end_comment
begin_comment
comment|/*         composition but this should change for the final release (see */
end_comment
begin_comment
comment|/*         the files demos/src/ftgrays.c and demos/src/ftgrays2.c for    */
end_comment
begin_comment
comment|/*         examples of distinct implementations which support direct     */
end_comment
begin_comment
comment|/*         composition).                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|QT_FT_Raster_RenderFunc
modifier|*
name|QT_FT_Raster_RenderFunc
function_decl|)
parameter_list|(
name|QT_FT_Raster
name|raster
parameter_list|,
name|QT_FT_Raster_Params
modifier|*
name|params
parameter_list|)
function_decl|;
end_typedef
begin_define
DECL|macro|QT_FT_Raster_Render_Func
define|#
directive|define
name|QT_FT_Raster_Render_Func
value|QT_FT_Raster_RenderFunc
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    QT_FT_Raster_Funcs                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*   A structure used to describe a given raster class to the library.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    glyph_format  :: The supported glyph format for this raster.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    raster_new    :: The raster constructor.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    raster_reset  :: Used to reset the render pool within the raster.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    raster_render :: A function to render a glyph into a given bitmap. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    raster_done   :: The raster destructor.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|QT_FT_Raster_Funcs_
typedef|typedef
struct|struct
name|QT_FT_Raster_Funcs_
block|{
DECL|member|glyph_format
name|QT_FT_Glyph_Format
name|glyph_format
decl_stmt|;
DECL|member|raster_new
name|QT_FT_Raster_NewFunc
name|raster_new
decl_stmt|;
DECL|member|raster_reset
name|QT_FT_Raster_ResetFunc
name|raster_reset
decl_stmt|;
DECL|member|raster_set_mode
name|QT_FT_Raster_SetModeFunc
name|raster_set_mode
decl_stmt|;
DECL|member|raster_render
name|QT_FT_Raster_RenderFunc
name|raster_render
decl_stmt|;
DECL|member|raster_done
name|QT_FT_Raster_DoneFunc
name|raster_done
decl_stmt|;
block|}
DECL|typedef|QT_FT_Raster_Funcs
name|QT_FT_Raster_Funcs
typedef|;
end_typedef
begin_comment
comment|/* */
end_comment
begin_macro
name|QT_FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTIMAGE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
