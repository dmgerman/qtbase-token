begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxlibcursor.h"
end_include
begin_include
include|#
directive|include
file|"qxlibintegration.h"
end_include
begin_include
include|#
directive|include
file|"qxlibscreen.h"
end_include
begin_include
include|#
directive|include
file|"qxlibwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxlibdisplay.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QBitmap>
end_include
begin_include
include|#
directive|include
file|<X11/cursorfont.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QXlibCursor
name|QXlibCursor
operator|::
name|QXlibCursor
parameter_list|(
name|QXlibScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|QPlatformCursor
argument_list|(
name|screen
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|changeCursor
name|void
name|QXlibCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QXlibWindow
modifier|*
name|w
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|window
condition|)
block|{
name|w
operator|=
cast|static_cast
argument_list|<
name|QXlibWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// No X11 cursor control when there is no widget under the cursor
return|return;
block|}
if|if
condition|(
operator|!
name|w
condition|)
return|return;
name|int
name|id
init|=
name|cursor
operator|->
name|handle
argument_list|()
decl_stmt|;
name|Cursor
name|c
decl_stmt|;
if|if
condition|(
operator|!
name|cursorMap
operator|.
name|contains
argument_list|(
name|id
argument_list|)
condition|)
block|{
if|if
condition|(
name|cursor
operator|->
name|shape
argument_list|()
operator|==
name|Qt
operator|::
name|BitmapCursor
condition|)
name|c
operator|=
name|createCursorBitmap
argument_list|(
name|cursor
argument_list|)
expr_stmt|;
else|else
name|c
operator|=
name|createCursorShape
argument_list|(
name|cursor
operator|->
name|shape
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|c
condition|)
block|{
return|return;
block|}
name|cursorMap
operator|.
name|insert
argument_list|(
name|id
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|c
operator|=
name|cursorMap
operator|.
name|value
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
name|w
operator|->
name|setCursor
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createCursorBitmap
name|Cursor
name|QXlibCursor
operator|::
name|createCursorBitmap
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|)
block|{
name|XColor
name|bg
decl_stmt|,
name|fg
decl_stmt|;
name|bg
operator|.
name|red
operator|=
literal|255
operator|<<
literal|8
expr_stmt|;
name|bg
operator|.
name|green
operator|=
literal|255
operator|<<
literal|8
expr_stmt|;
name|bg
operator|.
name|blue
operator|=
literal|255
operator|<<
literal|8
expr_stmt|;
name|fg
operator|.
name|red
operator|=
literal|0
expr_stmt|;
name|fg
operator|.
name|green
operator|=
literal|0
expr_stmt|;
name|fg
operator|.
name|blue
operator|=
literal|0
expr_stmt|;
name|QPoint
name|spot
init|=
name|cursor
operator|->
name|hotSpot
argument_list|()
decl_stmt|;
name|Window
name|rootwin
init|=
name|testLiteScreen
argument_list|()
operator|->
name|rootWindow
argument_list|()
decl_stmt|;
name|QImage
name|mapImage
init|=
name|cursor
operator|->
name|bitmap
argument_list|()
operator|->
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
decl_stmt|;
name|QImage
name|maskImage
init|=
name|cursor
operator|->
name|mask
argument_list|()
operator|->
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
decl_stmt|;
name|int
name|width
init|=
name|cursor
operator|->
name|bitmap
argument_list|()
operator|->
name|width
argument_list|()
decl_stmt|;
name|int
name|height
init|=
name|cursor
operator|->
name|bitmap
argument_list|()
operator|->
name|height
argument_list|()
decl_stmt|;
name|int
name|bytesPerLine
init|=
name|mapImage
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
name|int
name|destLineSize
init|=
name|width
operator|/
literal|8
decl_stmt|;
if|if
condition|(
name|width
operator|%
literal|8
condition|)
name|destLineSize
operator|++
expr_stmt|;
specifier|const
name|uchar
modifier|*
name|map
init|=
name|mapImage
operator|.
name|bits
argument_list|()
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|mask
init|=
name|maskImage
operator|.
name|bits
argument_list|()
decl_stmt|;
name|char
modifier|*
name|mapBits
init|=
operator|new
name|char
index|[
name|height
operator|*
name|destLineSize
index|]
decl_stmt|;
name|char
modifier|*
name|maskBits
init|=
operator|new
name|char
index|[
name|height
operator|*
name|destLineSize
index|]
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
name|height
condition|;
name|i
operator|++
control|)
block|{
name|memcpy
argument_list|(
name|mapBits
operator|+
operator|(
name|destLineSize
operator|*
name|i
operator|)
argument_list|,
name|map
operator|+
operator|(
name|bytesPerLine
operator|*
name|i
operator|)
argument_list|,
name|destLineSize
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|maskBits
operator|+
operator|(
name|destLineSize
operator|*
name|i
operator|)
argument_list|,
name|mask
operator|+
operator|(
name|bytesPerLine
operator|*
name|i
operator|)
argument_list|,
name|destLineSize
argument_list|)
expr_stmt|;
block|}
name|Pixmap
name|cp
init|=
name|XCreateBitmapFromData
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|rootwin
argument_list|,
name|mapBits
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|Pixmap
name|mp
init|=
name|XCreateBitmapFromData
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|rootwin
argument_list|,
name|maskBits
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|Cursor
name|c
init|=
name|XCreatePixmapCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|cp
argument_list|,
name|mp
argument_list|,
operator|&
name|fg
argument_list|,
operator|&
name|bg
argument_list|,
name|spot
operator|.
name|x
argument_list|()
argument_list|,
name|spot
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|XFreePixmap
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|XFreePixmap
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|mp
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|mapBits
expr_stmt|;
operator|delete
index|[]
name|maskBits
expr_stmt|;
return|return
name|c
return|;
block|}
end_function
begin_function
DECL|function|createCursorShape
name|Cursor
name|QXlibCursor
operator|::
name|createCursorShape
parameter_list|(
name|int
name|cshape
parameter_list|)
block|{
name|Cursor
name|cursor
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|cshape
argument_list|<
literal|0
operator|||
name|cshape
argument_list|>
name|Qt
operator|::
name|LastCursor
condition|)
return|return
literal|0
return|;
switch|switch
condition|(
name|cshape
condition|)
block|{
case|case
name|Qt
operator|::
name|ArrowCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_left_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UpArrowCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_center_ptr
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|CrossCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_crosshair
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|WaitCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_watch
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|IBeamCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_xterm
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeAllCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_fleur
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|PointingHandCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_hand2
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeBDiagCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_top_right_corner
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeFDiagCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_bottom_right_corner
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeVerCursor
case|:
case|case
name|Qt
operator|::
name|SplitVCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_sb_v_double_arrow
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeHorCursor
case|:
case|case
name|Qt
operator|::
name|SplitHCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_sb_h_double_arrow
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|WhatsThisCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_question_arrow
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|ForbiddenCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_circle
argument_list|)
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|BusyCursor
case|:
name|cursor
operator|=
name|XCreateFontCursor
argument_list|(
name|testLiteScreen
argument_list|()
operator|->
name|display
argument_list|()
operator|->
name|nativeDisplay
argument_list|()
argument_list|,
name|XC_watch
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|//default cursor for all the rest
break|break;
block|}
return|return
name|cursor
return|;
block|}
end_function
begin_function
DECL|function|testLiteScreen
name|QXlibScreen
modifier|*
name|QXlibCursor
operator|::
name|testLiteScreen
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QXlibScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
