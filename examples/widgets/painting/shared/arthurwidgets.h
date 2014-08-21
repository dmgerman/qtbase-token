begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ARTHURWIDGETS_H
end_ifndef
begin_define
DECL|macro|ARTHURWIDGETS_H
define|#
directive|define
name|ARTHURWIDGETS_H
end_define
begin_include
include|#
directive|include
file|"arthurstyle.h"
end_include
begin_include
include|#
directive|include
file|<QBitmap>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_SUPPORT
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QGLWidget>
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_decl_stmt
name|class
name|GLWidget
range|:
name|public
name|QGLWidget
block|{
name|public
operator|:
name|GLWidget
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
operator|:
name|QGLWidget
argument_list|(
argument|QGLFormat(QGL::SampleBuffers)
argument_list|,
argument|parent
argument_list|)
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_AcceptTouchEvents
argument_list|)
block|;     }
name|void
name|disableAutoBufferSwap
argument_list|()
block|{
name|setAutoBufferSwap
argument_list|(
name|false
argument_list|)
block|; }
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|parentWidget
argument_list|()
operator|->
name|update
argument_list|()
block|; }
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|{
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|TouchBegin
case|:
case|case
name|QEvent
operator|::
name|TouchUpdate
case|:
case|case
name|QEvent
operator|::
name|TouchEnd
case|:
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return
name|false
return|;
break|break;
default|default:
break|break;
block|}
return|return
name|QGLWidget
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTextDocument
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QTextEdit
argument_list|)
end_macro
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QVBoxLayout
argument_list|)
end_macro
begin_decl_stmt
name|class
name|ArthurFrame
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|ArthurFrame
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|virtual
name|void
name|paint
argument_list|(
argument|QPainter *
argument_list|)
block|{}
name|void
name|paintDescription
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|void
name|loadDescription
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|)
block|;
name|void
name|setDescription
argument_list|(
specifier|const
name|QString
operator|&
name|htmlDesc
argument_list|)
block|;
name|void
name|loadSourceFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|bool
name|preferImage
argument_list|()
specifier|const
block|{
return|return
name|m_prefer_image
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_SUPPORT
argument_list|)
name|QGLWidget
operator|*
name|glWidget
argument_list|()
specifier|const
block|{
return|return
name|glw
return|;
block|}
endif|#
directive|endif
name|public
name|slots
operator|:
name|void
name|setPreferImage
argument_list|(
argument|bool pi
argument_list|)
block|{
name|m_prefer_image
operator|=
name|pi
block|; }
name|void
name|setDescriptionEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|showSource
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_SUPPORT
argument_list|)
name|void
name|enableOpenGL
argument_list|(
argument|bool use_opengl
argument_list|)
block|;
name|bool
name|usesOpenGL
argument_list|()
block|{
return|return
name|m_use_opengl
return|;
block|}
endif|#
directive|endif
name|signals
operator|:
name|void
name|descriptionEnabledChanged
argument_list|(
name|bool
argument_list|)
block|;
name|protected
operator|:
name|void
name|paintEvent
argument_list|(
argument|QPaintEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_SUPPORT
argument_list|)
name|GLWidget
operator|*
name|glw
block|;
name|bool
name|m_use_opengl
block|;
endif|#
directive|endif
name|QPixmap
name|m_tile
block|;
name|bool
name|m_show_doc
block|;
name|bool
name|m_prefer_image
block|;
name|QTextDocument
operator|*
name|m_document
block|;
name|QString
name|m_sourceFileName
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
