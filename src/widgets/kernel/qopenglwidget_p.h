begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API. It may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLWIDGET_H
end_ifndef
begin_define
DECL|macro|QOPENGLWIDGET_H
define|#
directive|define
name|QOPENGLWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLWidgetPrivate
name|class
name|QOpenGLWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QOpenGLWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLWidget
argument_list|)
name|public
operator|:
name|explicit
name|QOpenGLWidget
argument_list|(
argument|QWidget* parent=
literal|0
argument_list|,
argument|Qt::WindowFlags f=
literal|0
argument_list|)
block|;
comment|// This API is not finalized yet. The commented-out functions below are
comment|// QGLWidget functions that have not been implemented for QOpenGLWidget.
comment|// Some of them may not end up in the final version (which is planned for a
comment|// future release of Qt).
comment|//    explicit QOpenGLWidget(const QSurfaceFormat& format, QWidget* parent=0,
comment|//                       Qt::WindowFlags f=0);
operator|~
name|QOpenGLWidget
argument_list|()
block|;
comment|//    void qglClearColor(const QColor& c) const;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
comment|//    bool isSharing() const;
name|void
name|makeCurrent
argument_list|()
block|;
name|void
name|doneCurrent
argument_list|()
block|;
comment|//    void swapBuffers();
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|GLuint
name|defaultFramebufferObject
argument_list|()
specifier|const
block|;
comment|//    QPixmap renderPixmap(int w = 0, int h = 0, bool useContext = false);
name|QImage
name|grabFrameBuffer
argument_list|(
argument|bool withAlpha = false
argument_list|)
block|;
comment|//    static QImage convertToGLFormat(const QImage& img);
comment|//    QPaintEngine *paintEngine() const;
comment|//    void drawTexture(const QRectF&target, GLuint textureId, GLenum textureTarget = GL_TEXTURE_2D);
comment|//    void drawTexture(const QPointF&point, GLuint textureId, GLenum textureTarget = GL_TEXTURE_2D);
name|public
name|Q_SLOTS
operator|:
name|void
name|updateGL
argument_list|()
block|;
name|protected
operator|:
comment|//    bool event(QEvent *);
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
comment|//    void setAutoBufferSwap(bool on);
comment|//    bool autoBufferSwap() const;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
comment|//    virtual void glInit();
comment|//    virtual void glDraw();
comment|//    QOpenGLWidget(QOpenGLWidgetPrivate&dd,
comment|//              const QGLFormat&format = QGLFormat(),
comment|//              QWidget *parent = 0,
comment|//              const QOpenGLWidget* shareWidget = 0,
comment|//              Qt::WindowFlags f = 0);
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLWidget
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
comment|// QOPENGLWIDGET_H
end_comment
end_unit
