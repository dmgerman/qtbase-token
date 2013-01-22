begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPICTURE_P_H
end_ifndef
begin_define
DECL|macro|QPICTURE_P_H
define|#
directive|define
name|QPICTURE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qatomic.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbuffer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qobjectdefs.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpicture.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpen.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qbrush.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qrect.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPaintEngine
name|class
name|QPaintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|qt_mfhdr_tag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPicturePrivate
block|{
name|friend
name|class
name|QPicturePaintEngine
decl_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QPicture
operator|&
name|r
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|s
operator|,
name|QPicture
operator|&
name|r
operator|)
expr_stmt|;
name|public
label|:
enum|enum
name|PaintCommand
block|{
name|PdcNOP
init|=
literal|0
block|,
comment|//<void>
name|PdcDrawPoint
init|=
literal|1
block|,
comment|// point
name|PdcDrawFirst
init|=
name|PdcDrawPoint
block|,
name|PdcMoveTo
init|=
literal|2
block|,
comment|// point
name|PdcLineTo
init|=
literal|3
block|,
comment|// point
name|PdcDrawLine
init|=
literal|4
block|,
comment|// point,point
name|PdcDrawRect
init|=
literal|5
block|,
comment|// rect
name|PdcDrawRoundRect
init|=
literal|6
block|,
comment|// rect,ival,ival
name|PdcDrawEllipse
init|=
literal|7
block|,
comment|// rect
name|PdcDrawArc
init|=
literal|8
block|,
comment|// rect,ival,ival
name|PdcDrawPie
init|=
literal|9
block|,
comment|// rect,ival,ival
name|PdcDrawChord
init|=
literal|10
block|,
comment|// rect,ival,ival
name|PdcDrawLineSegments
init|=
literal|11
block|,
comment|// ptarr
name|PdcDrawPolyline
init|=
literal|12
block|,
comment|// ptarr
name|PdcDrawPolygon
init|=
literal|13
block|,
comment|// ptarr,ival
name|PdcDrawCubicBezier
init|=
literal|14
block|,
comment|// ptarr
name|PdcDrawText
init|=
literal|15
block|,
comment|// point,str
name|PdcDrawTextFormatted
init|=
literal|16
block|,
comment|// rect,ival,str
name|PdcDrawPixmap
init|=
literal|17
block|,
comment|// rect,pixmap
name|PdcDrawImage
init|=
literal|18
block|,
comment|// rect,image
name|PdcDrawText2
init|=
literal|19
block|,
comment|// point,str
name|PdcDrawText2Formatted
init|=
literal|20
block|,
comment|// rect,ival,str
name|PdcDrawTextItem
init|=
literal|21
block|,
comment|// pos,text,font,flags
name|PdcDrawLast
init|=
name|PdcDrawTextItem
block|,
name|PdcDrawPoints
init|=
literal|22
block|,
comment|// ptarr,ival,ival
name|PdcDrawWinFocusRect
init|=
literal|23
block|,
comment|// rect,color
name|PdcDrawTiledPixmap
init|=
literal|24
block|,
comment|// rect,pixmap,point
name|PdcDrawPath
init|=
literal|25
block|,
comment|// path
comment|// no painting commands below PdcDrawLast.
name|PdcBegin
init|=
literal|30
block|,
comment|//<void>
name|PdcEnd
init|=
literal|31
block|,
comment|//<void>
name|PdcSave
init|=
literal|32
block|,
comment|//<void>
name|PdcRestore
init|=
literal|33
block|,
comment|//<void>
name|PdcSetdev
init|=
literal|34
block|,
comment|// device - PRIVATE
name|PdcSetBkColor
init|=
literal|40
block|,
comment|// color
name|PdcSetBkMode
init|=
literal|41
block|,
comment|// ival
name|PdcSetROP
init|=
literal|42
block|,
comment|// ival
name|PdcSetBrushOrigin
init|=
literal|43
block|,
comment|// point
name|PdcSetFont
init|=
literal|45
block|,
comment|// font
name|PdcSetPen
init|=
literal|46
block|,
comment|// pen
name|PdcSetBrush
init|=
literal|47
block|,
comment|// brush
name|PdcSetTabStops
init|=
literal|48
block|,
comment|// ival
name|PdcSetTabArray
init|=
literal|49
block|,
comment|// ival,ivec
name|PdcSetUnit
init|=
literal|50
block|,
comment|// ival
name|PdcSetVXform
init|=
literal|51
block|,
comment|// ival
name|PdcSetWindow
init|=
literal|52
block|,
comment|// rect
name|PdcSetViewport
init|=
literal|53
block|,
comment|// rect
name|PdcSetWXform
init|=
literal|54
block|,
comment|// ival
name|PdcSetWMatrix
init|=
literal|55
block|,
comment|// matrix,ival
name|PdcSaveWMatrix
init|=
literal|56
block|,
name|PdcRestoreWMatrix
init|=
literal|57
block|,
name|PdcSetClip
init|=
literal|60
block|,
comment|// ival
name|PdcSetClipRegion
init|=
literal|61
block|,
comment|// rgn
name|PdcSetClipPath
init|=
literal|62
block|,
comment|// path
name|PdcSetRenderHint
init|=
literal|63
block|,
comment|// ival
name|PdcSetCompositionMode
init|=
literal|64
block|,
comment|// ival
name|PdcSetClipEnabled
init|=
literal|65
block|,
comment|// bool
name|PdcSetOpacity
init|=
literal|66
block|,
comment|// qreal
name|PdcReservedStart
init|=
literal|0
block|,
comment|// codes 0-199 are reserved
name|PdcReservedStop
init|=
literal|199
comment|//   for Qt
block|}
enum|;
name|QPicturePrivate
argument_list|()
expr_stmt|;
name|QPicturePrivate
argument_list|(
specifier|const
name|QPicturePrivate
operator|&
name|other
argument_list|)
expr_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|bool
name|checkFormat
parameter_list|()
function_decl|;
name|void
name|resetFormat
parameter_list|()
function_decl|;
name|QBuffer
name|pictb
decl_stmt|;
name|int
name|trecs
decl_stmt|;
name|bool
name|formatOk
decl_stmt|;
name|int
name|formatMajor
decl_stmt|;
name|int
name|formatMinor
decl_stmt|;
name|QRect
name|brect
decl_stmt|;
name|QRect
name|override_rect
decl_stmt|;
name|QScopedPointer
operator|<
name|QPaintEngine
operator|>
name|paintEngine
expr_stmt|;
name|bool
name|in_memory_only
decl_stmt|;
name|QList
operator|<
name|QImage
operator|>
name|image_list
expr_stmt|;
name|QList
operator|<
name|QPixmap
operator|>
name|pixmap_list
expr_stmt|;
name|QList
operator|<
name|QBrush
operator|>
name|brush_list
expr_stmt|;
name|QList
operator|<
name|QPen
operator|>
name|pen_list
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPICTURE_P_H
end_comment
end_unit
