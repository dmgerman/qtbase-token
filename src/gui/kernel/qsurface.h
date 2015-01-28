begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSURFACE_H
end_ifndef
begin_define
DECL|macro|QSURFACE_H
define|#
directive|define
name|QSURFACE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qsurfaceformat.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformSurface
name|class
name|QPlatformSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSurfacePrivate
name|class
name|QSurfacePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QSurface
block|{
name|public
label|:
enum|enum
name|SurfaceClass
block|{
name|Window
block|,
name|Offscreen
block|}
enum|;
enum|enum
name|SurfaceType
block|{
name|RasterSurface
block|,
name|OpenGLSurface
block|,
name|RasterGLSurface
block|}
enum|;
name|virtual
operator|~
name|QSurface
argument_list|()
expr_stmt|;
name|SurfaceClass
name|surfaceClass
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QPlatformSurface
operator|*
name|surfaceHandle
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|SurfaceType
name|surfaceType
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|bool
name|supportsOpenGL
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QSize
name|size
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|explicit
name|QSurface
parameter_list|(
name|SurfaceClass
name|type
parameter_list|)
function_decl|;
name|SurfaceClass
name|m_type
decl_stmt|;
name|QSurfacePrivate
modifier|*
name|m_reserved
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSurface
operator|*
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QSURFACE_H
end_comment
end_unit
