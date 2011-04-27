begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EGLNULLWSSCREEN
end_ifndef
begin_define
DECL|macro|EGLNULLWSSCREEN
define|#
directive|define
name|EGLNULLWSSCREEN
end_define
begin_include
include|#
directive|include
file|<QGLScreen>
end_include
begin_decl_stmt
name|class
name|EGLNullWSScreen
range|:
name|public
name|QGLScreen
block|{
name|public
operator|:
name|EGLNullWSScreen
argument_list|(
argument|int displayId
argument_list|)
block|;
operator|~
name|EGLNullWSScreen
argument_list|()
block|;
name|bool
name|initDevice
argument_list|()
block|;
name|bool
name|connect
argument_list|(
specifier|const
name|QString
operator|&
name|displaySpec
argument_list|)
block|;
name|void
name|disconnect
argument_list|()
block|;
name|void
name|shutdownDevice
argument_list|()
block|;
name|void
name|setMode
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int depth
argument_list|)
block|;
name|void
name|blank
argument_list|(
argument|bool on
argument_list|)
block|;
name|void
name|exposeRegion
argument_list|(
argument|QRegion r
argument_list|,
argument|int changing
argument_list|)
block|;
name|QWSWindowSurface
operator|*
name|createSurface
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|QWSWindowSurface
operator|*
name|createSurface
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|;
name|bool
name|hasOpenGL
argument_list|()
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// EGLNULLWSSCREEN
end_comment
end_unit
