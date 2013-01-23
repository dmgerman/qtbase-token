begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|XFORM_H
end_ifndef
begin_define
DECL|macro|XFORM_H
define|#
directive|define
name|XFORM_H
end_define
begin_include
include|#
directive|include
file|"arthurwidgets.h"
end_include
begin_include
include|#
directive|include
file|<QBasicTimer>
end_include
begin_include
include|#
directive|include
file|<QPolygonF>
end_include
begin_decl_stmt
DECL|variable|HoverPoints
name|class
name|HoverPoints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|XFormView
range|:
name|public
name|ArthurFrame
block|{
name|public
operator|:
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|XFormType type READ type WRITE setType
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool animation READ animation WRITE setAnimation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal shear READ shear WRITE setShear
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal rotation READ rotation WRITE setRotation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal scale READ scale WRITE setScale
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString text READ text WRITE setText
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QPixmap pixmap READ pixmap WRITE setPixmap
argument_list|)
name|Q_ENUMS
argument_list|(
argument|XFormType
argument_list|)
name|public
operator|:
expr|enum
name|XFormType
block|{
name|VectorType
block|,
name|PixmapType
block|,
name|TextType
block|}
block|;
name|XFormView
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|void
name|paint
argument_list|(
name|QPainter
operator|*
argument_list|)
block|;
name|void
name|drawVectorType
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|void
name|drawPixmapType
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|void
name|drawTextType
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
return|;
block|}
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|e
argument_list|)
block|;
name|HoverPoints
operator|*
name|hoverPoints
argument_list|()
block|{
return|return
name|pts
return|;
block|}
name|bool
name|animation
argument_list|()
specifier|const
block|{
return|return
name|timer
operator|.
name|isActive
argument_list|()
return|;
block|}
name|qreal
name|shear
argument_list|()
specifier|const
block|{
return|return
name|m_shear
return|;
block|}
name|qreal
name|scale
argument_list|()
specifier|const
block|{
return|return
name|m_scale
return|;
block|}
name|qreal
name|rotation
argument_list|()
specifier|const
block|{
return|return
name|m_rotation
return|;
block|}
name|void
name|setShear
argument_list|(
argument|qreal s
argument_list|)
block|;
name|void
name|setScale
argument_list|(
argument|qreal s
argument_list|)
block|;
name|void
name|setRotation
argument_list|(
argument|qreal r
argument_list|)
block|;
name|XFormType
name|type
argument_list|()
specifier|const
block|;
name|QPixmap
name|pixmap
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|()
specifier|const
block|;
name|public
name|slots
operator|:
name|void
name|setAnimation
argument_list|(
argument|bool animate
argument_list|)
block|;
name|void
name|updateCtrlPoints
argument_list|(
specifier|const
name|QPolygonF
operator|&
argument_list|)
block|;
name|void
name|changeRotation
argument_list|(
argument|int rotation
argument_list|)
block|;
name|void
name|changeScale
argument_list|(
argument|int scale
argument_list|)
block|;
name|void
name|changeShear
argument_list|(
argument|int shear
argument_list|)
block|;
name|void
name|setText
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|setPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
name|void
name|setType
argument_list|(
argument|XFormType t
argument_list|)
block|;
name|void
name|setVectorType
argument_list|()
block|;
name|void
name|setPixmapType
argument_list|()
block|;
name|void
name|setTextType
argument_list|()
block|;
name|void
name|reset
argument_list|()
block|;
name|signals
operator|:
name|void
name|rotationChanged
argument_list|(
argument|int rotation
argument_list|)
block|;
name|void
name|scaleChanged
argument_list|(
argument|int scale
argument_list|)
block|;
name|void
name|shearChanged
argument_list|(
argument|int shear
argument_list|)
block|;
name|protected
operator|:
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|e
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|QPolygonF
name|ctrlPoints
block|;
name|HoverPoints
operator|*
name|pts
block|;
name|qreal
name|m_rotation
block|;
name|qreal
name|m_scale
block|;
name|qreal
name|m_shear
block|;
name|XFormType
name|m_type
block|;
name|QPixmap
name|m_pixmap
block|;
name|QString
name|m_text
block|;
name|QBasicTimer
name|timer
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|XFormWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|XFormWidget
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|XFormView
operator|*
name|view
block|;
name|QLineEdit
operator|*
name|textEditor
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// XFORM_H
end_comment
end_unit
