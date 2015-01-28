begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfbbackingstore_p.h"
end_include
begin_include
include|#
directive|include
file|"qfbwindow_p.h"
end_include
begin_include
include|#
directive|include
file|"qfbscreen_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qscreen.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QFbBackingStore
name|QFbBackingStore
operator|::
name|QFbBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
block|{
if|if
condition|(
name|window
operator|->
name|handle
argument_list|()
condition|)
operator|(
cast|static_cast
argument_list|<
name|QFbWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|)
operator|->
name|setBackingStore
argument_list|(
name|this
argument_list|)
expr_stmt|;
else|else
operator|(
cast|static_cast
argument_list|<
name|QFbScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|)
operator|->
name|addBackingStore
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QFbBackingStore
name|QFbBackingStore
operator|::
name|~
name|QFbBackingStore
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|flush
name|void
name|QFbBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
operator|(
cast|static_cast
argument_list|<
name|QFbWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
operator|)
operator|->
name|repaint
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QFbBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|staticContents
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|staticContents
argument_list|)
expr_stmt|;
if|if
condition|(
name|mImage
operator|.
name|size
argument_list|()
operator|!=
name|size
condition|)
name|mImage
operator|=
name|QImage
argument_list|(
name|size
argument_list|,
name|window
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|image
specifier|const
name|QImage
name|QFbBackingStore
operator|::
name|image
parameter_list|()
block|{
return|return
name|mImage
return|;
block|}
end_function
begin_function
DECL|function|lock
name|void
name|QFbBackingStore
operator|::
name|lock
parameter_list|()
block|{
name|mImageMutex
operator|.
name|lock
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unlock
name|void
name|QFbBackingStore
operator|::
name|unlock
parameter_list|()
block|{
name|mImageMutex
operator|.
name|unlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QFbBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
block|{
name|lock
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QFbBackingStore
operator|::
name|endPaint
parameter_list|()
block|{
name|unlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
