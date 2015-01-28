begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB). ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLTIMERQUERY_H
end_ifndef
begin_define
DECL|macro|QOPENGLTIMERQUERY_H
define|#
directive|define
name|QOPENGLTIMERQUERY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLTimerQueryPrivate
name|class
name|QOpenGLTimerQueryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLTimerQuery
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QOpenGLTimerQuery
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOpenGLTimerQuery
argument_list|()
block|;
name|bool
name|create
argument_list|()
block|;
name|void
name|destroy
argument_list|()
block|;
name|bool
name|isCreated
argument_list|()
specifier|const
block|;
name|GLuint
name|objectId
argument_list|()
specifier|const
block|;
name|void
name|begin
argument_list|()
block|;
name|void
name|end
argument_list|()
block|;
name|GLuint64
name|waitForTimestamp
argument_list|()
specifier|const
block|;
name|void
name|recordTimestamp
argument_list|()
block|;
name|bool
name|isResultAvailable
argument_list|()
specifier|const
block|;
name|GLuint64
name|waitForResult
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLTimerQuery
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLTimerQuery
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLTimeMonitorPrivate
name|class
name|QOpenGLTimeMonitorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLTimeMonitor
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QOpenGLTimeMonitor
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOpenGLTimeMonitor
argument_list|()
block|;
name|void
name|setSampleCount
argument_list|(
argument|int sampleCount
argument_list|)
block|;
name|int
name|sampleCount
argument_list|()
specifier|const
block|;
name|bool
name|create
argument_list|()
block|;
name|void
name|destroy
argument_list|()
block|;
name|bool
name|isCreated
argument_list|()
specifier|const
block|;
name|QVector
operator|<
name|GLuint
operator|>
name|objectIds
argument_list|()
specifier|const
block|;
name|int
name|recordSample
argument_list|()
block|;
name|bool
name|isResultAvailable
argument_list|()
specifier|const
block|;
name|QVector
operator|<
name|GLuint64
operator|>
name|waitForSamples
argument_list|()
specifier|const
block|;
name|QVector
operator|<
name|GLuint64
operator|>
name|waitForIntervals
argument_list|()
specifier|const
block|;
name|void
name|reset
argument_list|()
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLTimeMonitor
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLTimeMonitor
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
begin_comment
comment|// QOPENGLTIMERQUERY_H
end_comment
end_unit
