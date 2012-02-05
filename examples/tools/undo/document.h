begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DOCUMENT_H
end_ifndef
begin_define
DECL|macro|DOCUMENT_H
define|#
directive|define
name|DOCUMENT_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QUndoStack
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTextStream
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Shape
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|Rectangle
block|,
name|Circle
block|,
name|Triangle
block|}
enum|;
name|Shape
argument_list|(
argument|Type type = Rectangle
argument_list|,
argument|const QColor&color = Qt::red
argument_list|,
argument|const QRect&rect = QRect()
argument_list|)
empty_stmt|;
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|rect
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|resizeHandle
argument_list|()
specifier|const
expr_stmt|;
name|QColor
name|color
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QString
name|typeToString
parameter_list|(
name|Type
name|type
parameter_list|)
function_decl|;
specifier|static
name|Type
name|stringToType
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
name|bool
modifier|*
name|ok
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|QSize
name|minSize
decl_stmt|;
name|private
label|:
name|Type
name|m_type
decl_stmt|;
name|QRect
name|m_rect
decl_stmt|;
name|QColor
name|m_color
decl_stmt|;
name|QString
name|m_name
decl_stmt|;
name|friend
name|class
name|Document
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Document
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|Document
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QString
name|addShape
argument_list|(
specifier|const
name|Shape
operator|&
name|shape
argument_list|)
block|;
name|void
name|deleteShape
argument_list|(
specifier|const
name|QString
operator|&
name|shapeName
argument_list|)
block|;
name|Shape
name|shape
argument_list|(
argument|const QString&shapeName
argument_list|)
specifier|const
block|;
name|QString
name|currentShapeName
argument_list|()
specifier|const
block|;
name|void
name|setShapeRect
argument_list|(
specifier|const
name|QString
operator|&
name|shapeName
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setShapeColor
argument_list|(
specifier|const
name|QString
operator|&
name|shapeName
argument_list|,
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|bool
name|load
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|)
block|;
name|void
name|save
argument_list|(
name|QTextStream
operator|&
name|stream
argument_list|)
block|;
name|QString
name|fileName
argument_list|()
specifier|const
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|QUndoStack
operator|*
name|undoStack
argument_list|()
specifier|const
block|;
name|signals
operator|:
name|void
name|currentShapeChanged
argument_list|(
specifier|const
name|QString
operator|&
name|shapeName
argument_list|)
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|void
name|setCurrentShape
argument_list|(
argument|int index
argument_list|)
block|;
name|int
name|indexOf
argument_list|(
argument|const QString&shapeName
argument_list|)
specifier|const
block|;
name|int
name|indexAt
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
block|;
name|QString
name|uniqueName
argument_list|(
argument|const QString&name
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|Shape
operator|>
name|m_shapeList
block|;
name|int
name|m_currentIndex
block|;
name|int
name|m_mousePressIndex
block|;
name|QPoint
name|m_mousePressOffset
block|;
name|bool
name|m_resizeHandlePressed
block|;
name|QString
name|m_fileName
block|;
name|QUndoStack
operator|*
name|m_undoStack
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DOCUMENT_H
end_comment
end_unit
