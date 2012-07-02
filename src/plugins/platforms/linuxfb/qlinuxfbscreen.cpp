begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlinuxfbscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbcursor_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QLinuxFbScreen
name|QLinuxFbScreen
operator|::
name|QLinuxFbScreen
parameter_list|(
name|uchar
modifier|*
name|d
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|lstep
parameter_list|,
name|QImage
operator|::
name|Format
name|screenFormat
parameter_list|)
member_init_list|:
name|compositePainter
argument_list|(
literal|0
argument_list|)
block|{
name|data
operator|=
name|d
expr_stmt|;
name|mGeometry
operator|=
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|bytesPerLine
operator|=
name|lstep
expr_stmt|;
name|mFormat
operator|=
name|screenFormat
expr_stmt|;
name|mDepth
operator|=
literal|16
expr_stmt|;
name|mScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|mGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|mGeometry
operator|.
name|height
argument_list|()
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
name|mFbScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|data
argument_list|,
name|mGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|mGeometry
operator|.
name|height
argument_list|()
argument_list|,
name|bytesPerLine
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
name|cursor
operator|=
operator|new
name|QFbCursor
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setGeometry
name|void
name|QLinuxFbScreen
operator|::
name|setGeometry
parameter_list|(
name|QRect
name|rect
parameter_list|)
block|{
name|mGeometry
operator|=
name|rect
expr_stmt|;
operator|delete
name|mFbScreenImage
expr_stmt|;
name|mFbScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|data
argument_list|,
name|mGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|mGeometry
operator|.
name|height
argument_list|()
argument_list|,
name|bytesPerLine
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
operator|delete
name|compositePainter
expr_stmt|;
name|compositePainter
operator|=
literal|0
expr_stmt|;
operator|delete
name|mScreenImage
expr_stmt|;
name|mScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|mGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|mGeometry
operator|.
name|height
argument_list|()
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFormat
name|void
name|QLinuxFbScreen
operator|::
name|setFormat
parameter_list|(
name|QImage
operator|::
name|Format
name|format
parameter_list|)
block|{
name|mFormat
operator|=
name|format
expr_stmt|;
operator|delete
name|mFbScreenImage
expr_stmt|;
name|mFbScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|data
argument_list|,
name|mGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|mGeometry
operator|.
name|height
argument_list|()
argument_list|,
name|bytesPerLine
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
operator|delete
name|compositePainter
expr_stmt|;
name|compositePainter
operator|=
literal|0
expr_stmt|;
operator|delete
name|mScreenImage
expr_stmt|;
name|mScreenImage
operator|=
operator|new
name|QImage
argument_list|(
name|mGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|mGeometry
operator|.
name|height
argument_list|()
argument_list|,
name|mFormat
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doRedraw
name|QRegion
name|QLinuxFbScreen
operator|::
name|doRedraw
parameter_list|()
block|{
name|QRegion
name|touched
decl_stmt|;
name|touched
operator|=
name|QFbScreen
operator|::
name|doRedraw
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|compositePainter
condition|)
block|{
name|compositePainter
operator|=
operator|new
name|QPainter
argument_list|(
name|mFbScreenImage
argument_list|)
expr_stmt|;
block|}
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|touched
operator|.
name|rects
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
name|rects
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
name|compositePainter
operator|->
name|drawImage
argument_list|(
name|rects
index|[
name|i
index|]
argument_list|,
operator|*
name|mScreenImage
argument_list|,
name|rects
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|touched
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
