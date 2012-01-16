begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QUndoStack>
end_include
begin_include
include|#
directive|include
file|"document.h"
end_include
begin_include
include|#
directive|include
file|"commands.h"
end_include
begin_decl_stmt
DECL|variable|resizeHandleWidth
specifier|static
specifier|const
name|int
name|resizeHandleWidth
init|=
literal|6
decl_stmt|;
end_decl_stmt
begin_comment
comment|/****************************************************************************** ** Shape */
end_comment
begin_decl_stmt
specifier|const
name|QSize
name|Shape
operator|::
name|minSize
argument_list|(
literal|80
argument_list|,
literal|50
argument_list|)
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|Shape
name|Shape
operator|::
name|Shape
parameter_list|(
name|Type
name|type
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
member_init_list|:
name|m_type
argument_list|(
name|type
argument_list|)
member_init_list|,
name|m_rect
argument_list|(
name|rect
argument_list|)
member_init_list|,
name|m_color
argument_list|(
name|color
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|type
name|Shape
operator|::
name|Type
name|Shape
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
end_function
begin_function
DECL|function|rect
name|QRect
name|Shape
operator|::
name|rect
parameter_list|()
specifier|const
block|{
return|return
name|m_rect
return|;
block|}
end_function
begin_function
DECL|function|color
name|QColor
name|Shape
operator|::
name|color
parameter_list|()
specifier|const
block|{
return|return
name|m_color
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|Shape
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
end_function
begin_function
DECL|function|resizeHandle
name|QRect
name|Shape
operator|::
name|resizeHandle
parameter_list|()
specifier|const
block|{
name|QPoint
name|br
init|=
name|m_rect
operator|.
name|bottomRight
argument_list|()
decl_stmt|;
return|return
name|QRect
argument_list|(
name|br
operator|-
name|QPoint
argument_list|(
name|resizeHandleWidth
argument_list|,
name|resizeHandleWidth
argument_list|)
argument_list|,
name|br
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|typeToString
name|QString
name|Shape
operator|::
name|typeToString
parameter_list|(
name|Type
name|type
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|Rectangle
case|:
name|result
operator|=
name|QLatin1String
argument_list|(
literal|"Rectangle"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Circle
case|:
name|result
operator|=
name|QLatin1String
argument_list|(
literal|"Circle"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Triangle
case|:
name|result
operator|=
name|QLatin1String
argument_list|(
literal|"Triangle"
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|stringToType
name|Shape
operator|::
name|Type
name|Shape
operator|::
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
parameter_list|)
block|{
if|if
condition|(
name|ok
operator|!=
literal|0
condition|)
operator|*
name|ok
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|QLatin1String
argument_list|(
literal|"Rectangle"
argument_list|)
condition|)
return|return
name|Rectangle
return|;
if|if
condition|(
name|s
operator|==
name|QLatin1String
argument_list|(
literal|"Circle"
argument_list|)
condition|)
return|return
name|Circle
return|;
if|if
condition|(
name|s
operator|==
name|QLatin1String
argument_list|(
literal|"Triangle"
argument_list|)
condition|)
return|return
name|Triangle
return|;
if|if
condition|(
name|ok
operator|!=
literal|0
condition|)
operator|*
name|ok
operator|=
literal|false
expr_stmt|;
return|return
name|Rectangle
return|;
block|}
end_function
begin_comment
comment|/****************************************************************************** ** Document */
end_comment
begin_constructor
DECL|function|Document
name|Document
operator|::
name|Document
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_currentIndex
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_mousePressIndex
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_resizeHandlePressed
argument_list|(
literal|false
argument_list|)
block|{
name|m_undoStack
operator|=
operator|new
name|QUndoStack
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
name|QPalette
name|pal
init|=
name|palette
argument_list|()
decl_stmt|;
name|pal
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|,
name|QPixmap
argument_list|(
literal|":/icons/background.png"
argument_list|)
argument_list|)
expr_stmt|;
name|pal
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|HighlightedText
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|setPalette
argument_list|(
name|pal
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|addShape
name|QString
name|Document
operator|::
name|addShape
parameter_list|(
specifier|const
name|Shape
modifier|&
name|shape
parameter_list|)
block|{
name|QString
name|name
init|=
name|Shape
operator|::
name|typeToString
argument_list|(
name|shape
operator|.
name|type
argument_list|()
argument_list|)
decl_stmt|;
name|name
operator|=
name|uniqueName
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|m_shapeList
operator|.
name|append
argument_list|(
name|shape
argument_list|)
expr_stmt|;
name|m_shapeList
index|[
name|m_shapeList
operator|.
name|count
argument_list|()
operator|-
literal|1
index|]
operator|.
name|m_name
operator|=
name|name
expr_stmt|;
name|setCurrentShape
argument_list|(
name|m_shapeList
operator|.
name|count
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|name
return|;
block|}
end_function
begin_function
DECL|function|deleteShape
name|void
name|Document
operator|::
name|deleteShape
parameter_list|(
specifier|const
name|QString
modifier|&
name|shapeName
parameter_list|)
block|{
name|int
name|index
init|=
name|indexOf
argument_list|(
name|shapeName
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
return|return;
name|update
argument_list|(
name|m_shapeList
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|m_shapeList
operator|.
name|removeAt
argument_list|(
name|index
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|<=
name|m_currentIndex
condition|)
block|{
name|m_currentIndex
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|index
operator|==
name|m_shapeList
operator|.
name|count
argument_list|()
condition|)
operator|--
name|index
expr_stmt|;
name|setCurrentShape
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|shape
name|Shape
name|Document
operator|::
name|shape
parameter_list|(
specifier|const
name|QString
modifier|&
name|shapeName
parameter_list|)
specifier|const
block|{
name|int
name|index
init|=
name|indexOf
argument_list|(
name|shapeName
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
return|return
name|Shape
argument_list|()
return|;
return|return
name|m_shapeList
operator|.
name|at
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setShapeRect
name|void
name|Document
operator|::
name|setShapeRect
parameter_list|(
specifier|const
name|QString
modifier|&
name|shapeName
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|int
name|index
init|=
name|indexOf
argument_list|(
name|shapeName
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
return|return;
name|Shape
modifier|&
name|shape
init|=
name|m_shapeList
index|[
name|index
index|]
decl_stmt|;
name|update
argument_list|(
name|shape
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|update
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|shape
operator|.
name|m_rect
operator|=
name|rect
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setShapeColor
name|void
name|Document
operator|::
name|setShapeColor
parameter_list|(
specifier|const
name|QString
modifier|&
name|shapeName
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|int
name|index
init|=
name|indexOf
argument_list|(
name|shapeName
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
return|return;
name|Shape
modifier|&
name|shape
init|=
name|m_shapeList
index|[
name|index
index|]
decl_stmt|;
name|shape
operator|.
name|m_color
operator|=
name|color
expr_stmt|;
name|update
argument_list|(
name|shape
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|undoStack
name|QUndoStack
modifier|*
name|Document
operator|::
name|undoStack
parameter_list|()
specifier|const
block|{
return|return
name|m_undoStack
return|;
block|}
end_function
begin_function
DECL|function|load
name|bool
name|Document
operator|::
name|load
parameter_list|(
name|QTextStream
modifier|&
name|stream
parameter_list|)
block|{
name|m_shapeList
operator|.
name|clear
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|stream
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|shapeType
decl_stmt|,
name|shapeName
decl_stmt|,
name|colorName
decl_stmt|;
name|int
name|left
decl_stmt|,
name|top
decl_stmt|,
name|width
decl_stmt|,
name|height
decl_stmt|;
name|stream
operator|>>
name|shapeType
operator|>>
name|shapeName
operator|>>
name|colorName
operator|>>
name|left
operator|>>
name|top
operator|>>
name|width
operator|>>
name|height
expr_stmt|;
if|if
condition|(
name|stream
operator|.
name|status
argument_list|()
operator|!=
name|QTextStream
operator|::
name|Ok
condition|)
return|return
literal|false
return|;
name|bool
name|ok
decl_stmt|;
name|Shape
operator|::
name|Type
name|type
init|=
name|Shape
operator|::
name|stringToType
argument_list|(
name|shapeType
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return
literal|false
return|;
name|QColor
name|color
argument_list|(
name|colorName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|color
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|false
return|;
name|Shape
name|shape
argument_list|(
name|type
argument_list|)
decl_stmt|;
name|shape
operator|.
name|m_name
operator|=
name|shapeName
expr_stmt|;
name|shape
operator|.
name|m_color
operator|=
name|color
expr_stmt|;
name|shape
operator|.
name|m_rect
operator|=
name|QRect
argument_list|(
name|left
argument_list|,
name|top
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|m_shapeList
operator|.
name|append
argument_list|(
name|shape
argument_list|)
expr_stmt|;
block|}
name|m_currentIndex
operator|=
name|m_shapeList
operator|.
name|isEmpty
argument_list|()
condition|?
operator|-
literal|1
else|:
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|save
name|void
name|Document
operator|::
name|save
parameter_list|(
name|QTextStream
modifier|&
name|stream
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
name|m_shapeList
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|Shape
modifier|&
name|shape
init|=
name|m_shapeList
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QRect
name|r
init|=
name|shape
operator|.
name|rect
argument_list|()
decl_stmt|;
name|stream
operator|<<
name|Shape
operator|::
name|typeToString
argument_list|(
name|shape
operator|.
name|type
argument_list|()
argument_list|)
operator|<<
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|<<
name|shape
operator|.
name|name
argument_list|()
operator|<<
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|<<
name|shape
operator|.
name|color
argument_list|()
operator|.
name|name
argument_list|()
operator|<<
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|<<
name|r
operator|.
name|left
argument_list|()
operator|<<
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|<<
name|r
operator|.
name|top
argument_list|()
operator|<<
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|<<
name|r
operator|.
name|width
argument_list|()
operator|<<
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
operator|<<
name|r
operator|.
name|height
argument_list|()
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|m_shapeList
operator|.
name|count
argument_list|()
operator|-
literal|1
condition|)
name|stream
operator|<<
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
name|m_undoStack
operator|->
name|setClean
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fileName
name|QString
name|Document
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
return|return
name|m_fileName
return|;
block|}
end_function
begin_function
DECL|function|setFileName
name|void
name|Document
operator|::
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|m_fileName
operator|=
name|fileName
expr_stmt|;
block|}
end_function
begin_function
DECL|function|indexAt
name|int
name|Document
operator|::
name|indexAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
specifier|const
block|{
for|for
control|(
name|int
name|i
init|=
name|m_shapeList
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|m_shapeList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|rect
argument_list|()
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|Document
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|int
name|index
init|=
name|indexAt
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
decl_stmt|;
empty_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
block|{
name|setCurrentShape
argument_list|(
name|index
argument_list|)
expr_stmt|;
specifier|const
name|Shape
modifier|&
name|shape
init|=
name|m_shapeList
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|m_resizeHandlePressed
operator|=
name|shape
operator|.
name|resizeHandle
argument_list|()
operator|.
name|contains
argument_list|(
name|event
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_resizeHandlePressed
condition|)
name|m_mousePressOffset
operator|=
name|shape
operator|.
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
operator|-
name|event
operator|->
name|pos
argument_list|()
expr_stmt|;
else|else
name|m_mousePressOffset
operator|=
name|event
operator|->
name|pos
argument_list|()
operator|-
name|shape
operator|.
name|rect
argument_list|()
operator|.
name|topLeft
argument_list|()
expr_stmt|;
block|}
name|m_mousePressIndex
operator|=
name|index
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseReleaseEvent
name|void
name|Document
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
name|m_mousePressIndex
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|Document
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_mousePressIndex
operator|==
operator|-
literal|1
condition|)
return|return;
specifier|const
name|Shape
modifier|&
name|shape
init|=
name|m_shapeList
operator|.
name|at
argument_list|(
name|m_mousePressIndex
argument_list|)
decl_stmt|;
name|QRect
name|rect
decl_stmt|;
if|if
condition|(
name|m_resizeHandlePressed
condition|)
block|{
name|rect
operator|=
name|QRect
argument_list|(
name|shape
operator|.
name|rect
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|,
name|event
operator|->
name|pos
argument_list|()
operator|+
name|m_mousePressOffset
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|rect
operator|=
name|shape
operator|.
name|rect
argument_list|()
expr_stmt|;
name|rect
operator|.
name|moveTopLeft
argument_list|(
name|event
operator|->
name|pos
argument_list|()
operator|-
name|m_mousePressOffset
argument_list|)
expr_stmt|;
block|}
name|QSize
name|size
init|=
name|rect
operator|.
name|size
argument_list|()
operator|.
name|expandedTo
argument_list|(
name|Shape
operator|::
name|minSize
argument_list|)
decl_stmt|;
name|rect
operator|.
name|setSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|m_undoStack
operator|->
name|push
argument_list|(
operator|new
name|SetShapeRectCommand
argument_list|(
name|this
argument_list|,
name|shape
operator|.
name|name
argument_list|()
argument_list|,
name|rect
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|gradient
specifier|static
name|QGradient
name|gradient
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QColor
name|c
init|=
name|color
decl_stmt|;
name|c
operator|.
name|setAlpha
argument_list|(
literal|160
argument_list|)
expr_stmt|;
name|QLinearGradient
name|result
argument_list|(
name|rect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|rect
operator|.
name|bottomRight
argument_list|()
argument_list|)
decl_stmt|;
name|result
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|c
operator|.
name|dark
argument_list|(
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColorAt
argument_list|(
literal|0.5
argument_list|,
name|c
operator|.
name|light
argument_list|(
literal|200
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|c
operator|.
name|dark
argument_list|(
literal|150
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|triangle
specifier|static
name|QPolygon
name|triangle
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QPolygon
name|result
argument_list|(
literal|3
argument_list|)
decl_stmt|;
name|result
operator|.
name|setPoint
argument_list|(
literal|0
argument_list|,
name|rect
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|top
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|.
name|setPoint
argument_list|(
literal|1
argument_list|,
name|rect
operator|.
name|right
argument_list|()
argument_list|,
name|rect
operator|.
name|bottom
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|.
name|setPoint
argument_list|(
literal|2
argument_list|,
name|rect
operator|.
name|left
argument_list|()
argument_list|,
name|rect
operator|.
name|bottom
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|Document
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QRegion
name|paintRegion
init|=
name|event
operator|->
name|region
argument_list|()
decl_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QPalette
name|pal
init|=
name|palette
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_shapeList
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|Shape
modifier|&
name|shape
init|=
name|m_shapeList
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|paintRegion
operator|.
name|contains
argument_list|(
name|shape
operator|.
name|rect
argument_list|()
argument_list|)
condition|)
continue|continue;
name|QPen
name|pen
init|=
name|pal
operator|.
name|text
argument_list|()
operator|.
name|color
argument_list|()
decl_stmt|;
name|pen
operator|.
name|setWidth
argument_list|(
name|i
operator|==
name|m_currentIndex
condition|?
literal|2
else|:
literal|1
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|pen
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|gradient
argument_list|(
name|shape
operator|.
name|color
argument_list|()
argument_list|,
name|shape
operator|.
name|rect
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QRect
name|rect
init|=
name|shape
operator|.
name|rect
argument_list|()
decl_stmt|;
name|rect
operator|.
name|adjust
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
operator|-
name|resizeHandleWidth
operator|/
literal|2
argument_list|,
operator|-
name|resizeHandleWidth
operator|/
literal|2
argument_list|)
expr_stmt|;
comment|// paint the shape
switch|switch
condition|(
name|shape
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|Shape
operator|::
name|Rectangle
case|:
name|painter
operator|.
name|drawRect
argument_list|(
name|rect
argument_list|)
expr_stmt|;
break|break;
case|case
name|Shape
operator|::
name|Circle
case|:
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawEllipse
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|false
argument_list|)
expr_stmt|;
break|break;
case|case
name|Shape
operator|::
name|Triangle
case|:
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPolygon
argument_list|(
name|triangle
argument_list|(
name|rect
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setRenderHint
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|,
literal|false
argument_list|)
expr_stmt|;
break|break;
block|}
comment|// paint the resize handle
name|painter
operator|.
name|setPen
argument_list|(
name|pal
operator|.
name|text
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRect
argument_list|(
name|shape
operator|.
name|resizeHandle
argument_list|()
operator|.
name|adjusted
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
comment|// paint the shape name
name|painter
operator|.
name|setBrush
argument_list|(
name|pal
operator|.
name|text
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|shape
operator|.
name|type
argument_list|()
operator|==
name|Shape
operator|::
name|Triangle
condition|)
name|rect
operator|.
name|adjust
argument_list|(
literal|0
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|shape
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setCurrentShape
name|void
name|Document
operator|::
name|setCurrentShape
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|QString
name|currentName
decl_stmt|;
if|if
condition|(
name|m_currentIndex
operator|!=
operator|-
literal|1
condition|)
name|update
argument_list|(
name|m_shapeList
operator|.
name|at
argument_list|(
name|m_currentIndex
argument_list|)
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|m_currentIndex
operator|=
name|index
expr_stmt|;
if|if
condition|(
name|m_currentIndex
operator|!=
operator|-
literal|1
condition|)
block|{
specifier|const
name|Shape
modifier|&
name|current
init|=
name|m_shapeList
operator|.
name|at
argument_list|(
name|m_currentIndex
argument_list|)
decl_stmt|;
name|update
argument_list|(
name|current
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
name|currentName
operator|=
name|current
operator|.
name|name
argument_list|()
expr_stmt|;
block|}
emit|emit
name|currentShapeChanged
argument_list|(
name|currentName
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|indexOf
name|int
name|Document
operator|::
name|indexOf
parameter_list|(
specifier|const
name|QString
modifier|&
name|shapeName
parameter_list|)
specifier|const
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
name|m_shapeList
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|m_shapeList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|name
argument_list|()
operator|==
name|shapeName
condition|)
return|return
name|i
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|uniqueName
name|QString
name|Document
operator|::
name|uniqueName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
name|QString
name|unique
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
condition|;
operator|++
name|i
control|)
block|{
name|unique
operator|=
name|name
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
condition|)
name|unique
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|indexOf
argument_list|(
name|unique
argument_list|)
operator|==
operator|-
literal|1
condition|)
break|break;
block|}
return|return
name|unique
return|;
block|}
end_function
begin_function
DECL|function|currentShapeName
name|QString
name|Document
operator|::
name|currentShapeName
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_currentIndex
operator|==
operator|-
literal|1
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|m_shapeList
operator|.
name|at
argument_list|(
name|m_currentIndex
argument_list|)
operator|.
name|name
argument_list|()
return|;
block|}
end_function
end_unit
