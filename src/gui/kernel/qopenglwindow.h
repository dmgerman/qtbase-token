begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLWINDOW_H
end_ifndef
begin_define
DECL|macro|QOPENGLWINDOW_H
define|#
directive|define
name|QOPENGLWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/QPaintDeviceWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLWindowPrivate
name|class
name|QOpenGLWindowPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLWindow
range|:
name|public
name|QPaintDeviceWindow
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLWindow
argument_list|)
name|public
operator|:
expr|enum
name|UpdateBehavior
block|{
name|NoPartialUpdate
block|,
name|PartialUpdateBlit
block|,
name|PartialUpdateBlend
block|}
block|;
name|explicit
name|QOpenGLWindow
argument_list|(
argument|UpdateBehavior updateBehavior = NoPartialUpdate
argument_list|,
argument|QWindow *parent =
literal|0
argument_list|)
block|;
name|explicit
name|QOpenGLWindow
argument_list|(
argument|QOpenGLContext *shareContext
argument_list|,
argument|UpdateBehavior updateBehavior = NoPartialUpdate
argument_list|,
argument|QWindow *parent =
literal|0
argument_list|)
block|;
operator|~
name|QOpenGLWindow
argument_list|()
block|;
name|UpdateBehavior
name|updateBehavior
argument_list|()
specifier|const
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|void
name|makeCurrent
argument_list|()
block|;
name|void
name|doneCurrent
argument_list|()
block|;
name|QOpenGLContext
operator|*
name|context
argument_list|()
specifier|const
block|;
name|QOpenGLContext
operator|*
name|shareContext
argument_list|()
specifier|const
block|;
name|GLuint
name|defaultFramebufferObject
argument_list|()
specifier|const
block|;
name|QImage
name|grabFramebuffer
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|frameSwapped
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|void
name|initializeGL
argument_list|()
block|;
name|virtual
name|void
name|resizeGL
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|virtual
name|void
name|paintGL
argument_list|()
block|;
name|virtual
name|void
name|paintUnderGL
argument_list|()
block|;
name|virtual
name|void
name|paintOverGL
argument_list|()
block|;
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric metric
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPaintDevice
operator|*
name|redirected
argument_list|(
argument|QPoint *
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLWindow
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
