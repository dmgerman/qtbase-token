begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"imageitem.h"
end_include
begin_include
include|#
directive|include
file|"gestures.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_constructor
DECL|function|ImageItem
name|ImageItem
operator|::
name|ImageItem
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|setImage
argument_list|(
name|image
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|setImage
name|void
name|ImageItem
operator|::
name|setImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|image_
operator|=
name|image
expr_stmt|;
name|pixmap_
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
operator|.
name|scaled
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|image
name|QImage
name|ImageItem
operator|::
name|image
parameter_list|()
specifier|const
block|{
return|return
name|image_
return|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|QRectF
name|ImageItem
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
specifier|const
name|QSize
name|size
init|=
name|pixmap_
operator|.
name|size
argument_list|()
decl_stmt|;
return|return
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|ImageItem
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
name|painter
operator|->
name|drawPixmap
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pixmap_
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|GestureImageItem
name|GestureImageItem
operator|::
name|GestureImageItem
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
member_init_list|:
name|ImageItem
argument_list|(
name|image
argument_list|)
block|{
name|grabGesture
argument_list|(
name|Qt
operator|::
name|PanGesture
argument_list|)
expr_stmt|;
name|grabGesture
argument_list|(
name|ThreeFingerSlideGesture
operator|::
name|Type
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|event
name|bool
name|GestureImageItem
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Gesture
condition|)
block|{
name|qDebug
argument_list|(
literal|"gestureimageitem: gesture triggered"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
name|ImageItem
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"moc_imageitem.cpp"
end_include
end_unit
