begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PAINTCOMMANDS_H
end_ifndef
begin_define
DECL|macro|PAINTCOMMANDS_H
define|#
directive|define
name|PAINTCOMMANDS_H
end_define
begin_include
include|#
directive|include
file|<qcolor.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qpainterpath.h>
end_include
begin_include
include|#
directive|include
file|<qregion.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<qbrush.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QPainter
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QRegExp
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QOpenGLFramebufferObject
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QOpenGLPaintDevice
argument_list|)
end_macro
begin_expr_stmt
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|QOpenGLContext
argument_list|)
endif|#
directive|endif
expr|enum
name|DeviceType
block|{
name|WidgetType
block|,
name|BitmapType
block|,
name|PixmapType
block|,
name|ImageType
block|,
name|ImageMonoType
block|,
name|OpenGLType
block|,
name|OpenGLBufferType
block|,
name|PictureType
block|,
name|PrinterType
block|,
name|PdfType
block|,
name|PsType
block|,
name|GrabType
block|,
name|CustomDeviceType
block|,
name|CustomWidgetType
block|,
name|ImageWidgetType
block|}
expr_stmt|;
end_expr_stmt
begin_comment
comment|/************************************************************************/
end_comment
begin_decl_stmt
name|class
name|PaintCommands
block|{
name|public
label|:
comment|// construction / initialization
name|PaintCommands
argument_list|(
argument|const QStringList&cmds
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|:
name|m_painter
argument_list|(
literal|0
argument_list|)
operator|,
name|m_surface_painter
argument_list|(
literal|0
argument_list|)
operator|,
name|m_commands
argument_list|(
name|cmds
argument_list|)
operator|,
name|m_gradientSpread
argument_list|(
name|QGradient
operator|::
name|PadSpread
argument_list|)
operator|,
name|m_gradientCoordinate
argument_list|(
name|QGradient
operator|::
name|LogicalMode
argument_list|)
operator|,
name|m_width
argument_list|(
name|w
argument_list|)
operator|,
name|m_height
argument_list|(
name|h
argument_list|)
operator|,
name|m_verboseMode
argument_list|(
name|false
argument_list|)
operator|,
name|m_type
argument_list|(
name|WidgetType
argument_list|)
operator|,
name|m_checkers_background
argument_list|(
name|true
argument_list|)
operator|,
name|m_shouldDrawText
argument_list|(
name|true
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
operator|,
name|m_default_glcontext
argument_list|(
literal|0
argument_list|)
operator|,
name|m_surface_glcontext
argument_list|(
literal|0
argument_list|)
operator|,
name|m_surface_glbuffer
argument_list|(
literal|0
argument_list|)
operator|,
name|m_surface_glpaintdevice
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{
name|staticInit
argument_list|()
block|; }
name|public
operator|:
name|void
name|setCheckersBackground
argument_list|(
argument|bool b
argument_list|)
block|{
name|staticInit
argument_list|()
block|;
name|m_checkers_background
operator|=
name|b
block|; }
name|void
name|setContents
argument_list|(
argument|const QStringList&cmds
argument_list|)
block|{
name|staticInit
argument_list|()
block|;
name|m_blockMap
operator|.
name|clear
argument_list|()
block|;
name|m_pathMap
operator|.
name|clear
argument_list|()
block|;
name|m_pixmapMap
operator|.
name|clear
argument_list|()
block|;
name|m_imageMap
operator|.
name|clear
argument_list|()
block|;
name|m_regionMap
operator|.
name|clear
argument_list|()
block|;
name|m_gradientStops
operator|.
name|clear
argument_list|()
block|;
name|m_controlPoints
operator|.
name|clear
argument_list|()
block|;
name|m_gradientSpread
operator|=
name|QGradient
operator|::
name|PadSpread
block|;
name|m_gradientCoordinate
operator|=
name|QGradient
operator|::
name|LogicalMode
block|;
name|m_commands
operator|=
name|cmds
block|;       }
name|void
name|setPainter
argument_list|(
argument|QPainter *pt
argument_list|)
block|{
name|staticInit
argument_list|()
block|;
name|m_painter
operator|=
name|pt
block|; }
name|void
name|setType
argument_list|(
argument|DeviceType t
argument_list|)
block|{
name|staticInit
argument_list|()
block|;
name|m_type
operator|=
name|t
block|; }
name|void
name|setFilePath
argument_list|(
argument|const QString&path
argument_list|)
block|{
name|staticInit
argument_list|()
block|;
name|m_filepath
operator|=
name|path
block|; }
name|void
name|setControlPoints
argument_list|(
argument|const QVector<QPointF>&points
argument_list|)
block|{
name|staticInit
argument_list|()
block|;
name|m_controlPoints
operator|=
name|points
block|; }
name|void
name|setVerboseMode
argument_list|(
argument|bool v
argument_list|)
block|{
name|staticInit
argument_list|()
block|;
name|m_verboseMode
operator|=
name|v
block|; }
name|void
name|insertAt
argument_list|(
argument|int commandIndex
argument_list|,
argument|const QStringList&newCommands
argument_list|)
expr_stmt|;
name|void
name|setShouldDrawText
parameter_list|(
name|bool
name|drawText
parameter_list|)
block|{
name|m_shouldDrawText
operator|=
name|drawText
expr_stmt|;
block|}
comment|// run
name|void
name|runCommands
parameter_list|()
function_decl|;
name|private
label|:
comment|// run
name|void
name|runCommand
parameter_list|(
specifier|const
name|QString
modifier|&
name|scriptLine
parameter_list|)
function_decl|;
comment|// conversion methods
name|int
name|convertToInt
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
name|double
name|convertToDouble
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
name|float
name|convertToFloat
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
name|QColor
name|convertToColor
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
comment|// commands: comments
name|void
name|command_comment
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: importer
name|void
name|command_import
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: blocks
name|void
name|command_begin_block
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_end_block
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_repeat_block
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: misc
name|void
name|command_textlayout_draw
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_abort
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: noops
name|void
name|command_noop
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: setters
name|void
name|command_setBgMode
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setBackground
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setOpacity
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_setFillRule
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setBrush
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setBrushOrigin
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_brushTranslate
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_brushRotate
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_brushScale
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_brushShear
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setClipPath
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setClipRect
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setClipRectangle
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setClipRegion
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setClipping
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setCompositionMode
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setFont
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setPen
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setPen2
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_pen_setDashOffset
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_pen_setDashPattern
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_pen_setCosmetic
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setRenderHint
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_clearRenderHint
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_appendStop
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_clearStops
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_setConical
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_setLinear
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_setRadial
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_setRadialExtended
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_setLinearPen
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_setSpread
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_gradient_setCoordinateMode
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: drawing ops
name|void
name|command_drawArc
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawChord
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawConvexPolygon
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawEllipse
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawImage
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawLine
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawPath
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawPie
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawPixmap
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawPoint
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawPolygon
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawPolyline
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawRect
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawRoundedRect
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawRoundRect
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawText
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawStaticText
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_drawTiledPixmap
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_addEllipse
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_addPolygon
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_addRect
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_addText
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_arcTo
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_closeSubpath
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_createOutline
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_cubicTo
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_debugPrint
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_lineTo
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_moveTo
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_region_addEllipse
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_region_addRect
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// getters
name|void
name|command_region_getClipRegion
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_path_getClipPath
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: surface begin/end
name|void
name|command_surface_begin
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_surface_end
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: save/restore painter state
name|void
name|command_restore
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_save
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: pixmap/image
name|void
name|command_pixmap_load
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_pixmap_setMask
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_bitmap_load
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_image_convertToFormat
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_image_load
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_image_setColor
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_image_setColorCount
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// commands: transformation
name|void
name|command_resetMatrix
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_translate
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_rotate
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_rotate_x
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_rotate_y
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_scale
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_mapQuadToQuad
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
name|void
name|command_setMatrix
parameter_list|(
name|QRegExp
name|re
parameter_list|)
function_decl|;
comment|// attributes
name|QPainter
modifier|*
name|m_painter
decl_stmt|;
name|QPainter
modifier|*
name|m_surface_painter
decl_stmt|;
name|QImage
name|m_surface_image
decl_stmt|;
name|QPixmap
name|m_surface_pixmap
decl_stmt|;
name|QRectF
name|m_surface_rect
decl_stmt|;
name|QStringList
name|m_commands
decl_stmt|;
name|QString
name|m_currentCommand
decl_stmt|;
name|int
name|m_currentCommandIndex
decl_stmt|;
name|QString
name|m_filepath
decl_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|m_blockMap
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QPainterPath
operator|>
name|m_pathMap
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QPixmap
operator|>
name|m_pixmapMap
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QImage
operator|>
name|m_imageMap
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QRegion
operator|>
name|m_regionMap
expr_stmt|;
name|QGradientStops
name|m_gradientStops
decl_stmt|;
name|QGradient
operator|::
name|Spread
name|m_gradientSpread
expr_stmt|;
name|QGradient
operator|::
name|CoordinateMode
name|m_gradientCoordinate
expr_stmt|;
name|bool
name|m_abort
decl_stmt|;
name|int
name|m_width
decl_stmt|;
name|int
name|m_height
decl_stmt|;
name|bool
name|m_verboseMode
decl_stmt|;
name|DeviceType
name|m_type
decl_stmt|;
name|bool
name|m_checkers_background
decl_stmt|;
name|bool
name|m_shouldDrawText
decl_stmt|;
name|QVector
operator|<
name|QPointF
operator|>
name|m_controlPoints
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|QOpenGLContext
modifier|*
name|m_default_glcontext
decl_stmt|;
name|QOpenGLContext
modifier|*
name|m_surface_glcontext
decl_stmt|;
name|QOpenGLFramebufferObject
modifier|*
name|m_surface_glbuffer
decl_stmt|;
name|QOpenGLPaintDevice
modifier|*
name|m_surface_glpaintdevice
decl_stmt|;
endif|#
directive|endif
comment|// painter functionalities string tables
specifier|static
specifier|const
name|char
modifier|*
name|brushStyleTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|penStyleTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|fontWeightTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|fontHintingTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|clipOperationTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|spreadMethodTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|coordinateMethodTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|compositionModeTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|imageFormatTable
index|[]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|sizeModeTable
index|[]
decl_stmt|;
specifier|static
name|int
name|translateEnum
parameter_list|(
specifier|const
name|char
modifier|*
name|table
index|[]
parameter_list|,
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|,
name|int
name|limit
parameter_list|)
function_decl|;
comment|// utility
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|image_load
argument_list|(
specifier|const
name|QString
operator|&
name|filepath
argument_list|)
expr_stmt|;
comment|// commands dictionary management
specifier|static
name|void
name|staticInit
parameter_list|()
function_decl|;
name|public
label|:
struct|struct
name|PaintCommandInfos
block|{
name|PaintCommandInfos
argument_list|(
argument|QString id
argument_list|,
argument|void (PaintCommands::*p)(QRegExp)
argument_list|,
argument|QRegExp r
argument_list|,
argument|QString sy
argument_list|,
argument|QString sa
argument_list|)
block|:
name|identifier
argument_list|(
name|id
argument_list|)
operator|,
name|regExp
argument_list|(
name|r
argument_list|)
operator|,
name|syntax
argument_list|(
name|sy
argument_list|)
operator|,
name|sample
argument_list|(
name|sa
argument_list|)
operator|,
name|paintMethod
argument_list|(
argument|p
argument_list|)
block|{}
name|PaintCommandInfos
argument_list|(
argument|QString title
argument_list|)
operator|:
name|identifier
argument_list|(
name|title
argument_list|)
operator|,
name|paintMethod
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|isSectionHeader
argument_list|()
specifier|const
block|{
return|return
name|paintMethod
operator|==
literal|0
return|;
block|}
name|QString
name|identifier
decl_stmt|;
name|QRegExp
name|regExp
decl_stmt|;
name|QString
name|syntax
decl_stmt|;
name|QString
name|sample
decl_stmt|;
name|void
argument_list|(
name|PaintCommands
operator|::
operator|*
name|paintMethod
argument_list|)
argument_list|(
name|QRegExp
argument_list|)
expr_stmt|;
block|}
struct|;
specifier|static
name|PaintCommandInfos
modifier|*
name|findCommandById
parameter_list|(
specifier|const
name|QString
modifier|&
name|identifier
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|s_commandInfoTable
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|s_commandInfoTable
index|[
name|i
index|]
operator|.
name|identifier
operator|==
name|identifier
condition|)
return|return
operator|&
name|s_commandInfoTable
index|[
name|i
index|]
return|;
return|return
literal|0
return|;
block|}
specifier|static
name|QList
operator|<
name|PaintCommandInfos
operator|>
name|s_commandInfoTable
expr_stmt|;
specifier|static
name|QList
operator|<
name|QPair
operator|<
name|QString
operator|,
name|QStringList
operator|>
expr|>
name|s_enumsTable
expr_stmt|;
specifier|static
name|QMultiHash
operator|<
name|QString
operator|,
name|int
operator|>
name|s_commandHash
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PAINTCOMMANDS_H
end_comment
end_unit
