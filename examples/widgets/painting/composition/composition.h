begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPOSITION_H
end_ifndef
begin_define
DECL|macro|COMPOSITION_H
define|#
directive|define
name|COMPOSITION_H
end_define
begin_include
include|#
directive|include
file|"arthurwidgets.h"
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRadioButton
name|class
name|QRadioButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
include|#
directive|include
file|<QtOpenGL>
endif|#
directive|endif
name|class
name|CompositionWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|CompositionWidget
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|nextMode
argument_list|()
block|;
name|private
operator|:
name|bool
name|m_cycle_enabled
block|;
name|QRadioButton
operator|*
name|rbClear
block|;
name|QRadioButton
operator|*
name|rbSource
block|;
name|QRadioButton
operator|*
name|rbDest
block|;
name|QRadioButton
operator|*
name|rbSourceOver
block|;
name|QRadioButton
operator|*
name|rbDestOver
block|;
name|QRadioButton
operator|*
name|rbSourceIn
block|;
name|QRadioButton
operator|*
name|rbDestIn
block|;
name|QRadioButton
operator|*
name|rbSourceOut
block|;
name|QRadioButton
operator|*
name|rbDestOut
block|;
name|QRadioButton
operator|*
name|rbSourceAtop
block|;
name|QRadioButton
operator|*
name|rbDestAtop
block|;
name|QRadioButton
operator|*
name|rbXor
block|;
name|QRadioButton
operator|*
name|rbPlus
block|;
name|QRadioButton
operator|*
name|rbMultiply
block|;
name|QRadioButton
operator|*
name|rbScreen
block|;
name|QRadioButton
operator|*
name|rbOverlay
block|;
name|QRadioButton
operator|*
name|rbDarken
block|;
name|QRadioButton
operator|*
name|rbLighten
block|;
name|QRadioButton
operator|*
name|rbColorDodge
block|;
name|QRadioButton
operator|*
name|rbColorBurn
block|;
name|QRadioButton
operator|*
name|rbHardLight
block|;
name|QRadioButton
operator|*
name|rbSoftLight
block|;
name|QRadioButton
operator|*
name|rbDifference
block|;
name|QRadioButton
operator|*
name|rbExclusion
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CompositionRenderer
range|:
name|public
name|ArthurFrame
block|{
name|Q_OBJECT
expr|enum
name|ObjectType
block|{
name|NoObject
block|,
name|Circle
block|,
name|Rectangle
block|,
name|Image
block|}
block|;
name|Q_PROPERTY
argument_list|(
argument|int circleColor READ circleColor WRITE setCircleColor
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int circleAlpha READ circleAlpha WRITE setCircleAlpha
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool animation READ animationEnabled WRITE setAnimationEnabled
argument_list|)
name|public
operator|:
name|CompositionRenderer
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|void
name|paint
argument_list|(
argument|QPainter *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setCirclePos
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|QSize
argument_list|(
literal|500
argument_list|,
literal|400
argument_list|)
return|;
block|}
name|bool
name|animationEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_animation_enabled
return|;
block|}
name|int
name|circleColor
argument_list|()
specifier|const
block|{
return|return
name|m_circle_hue
return|;
block|}
name|int
name|circleAlpha
argument_list|()
specifier|const
block|{
return|return
name|m_circle_alpha
return|;
block|}
name|protected
operator|:
name|void
name|mousePressEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QMouseEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|public
name|slots
operator|:
name|void
name|setClearMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Clear
block|;
name|update
argument_list|()
block|; }
name|void
name|setSourceMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Source
block|;
name|update
argument_list|()
block|; }
name|void
name|setDestMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Destination
block|;
name|update
argument_list|()
block|; }
name|void
name|setSourceOverMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_SourceOver
block|;
name|update
argument_list|()
block|; }
name|void
name|setDestOverMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_DestinationOver
block|;
name|update
argument_list|()
block|; }
name|void
name|setSourceInMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_SourceIn
block|;
name|update
argument_list|()
block|; }
name|void
name|setDestInMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_DestinationIn
block|;
name|update
argument_list|()
block|; }
name|void
name|setSourceOutMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_SourceOut
block|;
name|update
argument_list|()
block|; }
name|void
name|setDestOutMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_DestinationOut
block|;
name|update
argument_list|()
block|; }
name|void
name|setSourceAtopMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_SourceAtop
block|;
name|update
argument_list|()
block|; }
name|void
name|setDestAtopMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_DestinationAtop
block|;
name|update
argument_list|()
block|; }
name|void
name|setXorMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Xor
block|;
name|update
argument_list|()
block|; }
name|void
name|setPlusMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Plus
block|;
name|update
argument_list|()
block|; }
name|void
name|setMultiplyMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Multiply
block|;
name|update
argument_list|()
block|; }
name|void
name|setScreenMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Screen
block|;
name|update
argument_list|()
block|; }
name|void
name|setOverlayMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Overlay
block|;
name|update
argument_list|()
block|; }
name|void
name|setDarkenMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Darken
block|;
name|update
argument_list|()
block|; }
name|void
name|setLightenMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Lighten
block|;
name|update
argument_list|()
block|; }
name|void
name|setColorDodgeMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_ColorDodge
block|;
name|update
argument_list|()
block|; }
name|void
name|setColorBurnMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_ColorBurn
block|;
name|update
argument_list|()
block|; }
name|void
name|setHardLightMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_HardLight
block|;
name|update
argument_list|()
block|; }
name|void
name|setSoftLightMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_SoftLight
block|;
name|update
argument_list|()
block|; }
name|void
name|setDifferenceMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Difference
block|;
name|update
argument_list|()
block|; }
name|void
name|setExclusionMode
argument_list|()
block|{
name|m_composition_mode
operator|=
name|QPainter
operator|::
name|CompositionMode_Exclusion
block|;
name|update
argument_list|()
block|; }
name|void
name|setCircleAlpha
argument_list|(
argument|int alpha
argument_list|)
block|{
name|m_circle_alpha
operator|=
name|alpha
block|;
name|update
argument_list|()
block|; }
name|void
name|setCircleColor
argument_list|(
argument|int hue
argument_list|)
block|{
name|m_circle_hue
operator|=
name|hue
block|;
name|update
argument_list|()
block|; }
name|void
name|setAnimationEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|private
operator|:
name|void
name|updateCirclePos
argument_list|()
block|;
name|void
name|drawBase
argument_list|(
name|QPainter
operator|&
name|p
argument_list|)
block|;
name|void
name|drawSource
argument_list|(
name|QPainter
operator|&
name|p
argument_list|)
block|;
name|QPainter
operator|::
name|CompositionMode
name|m_composition_mode
block|;
name|QImage
name|m_image
block|;
name|QImage
name|m_buffer
block|;
name|QImage
name|m_base_buffer
block|;
name|int
name|m_circle_alpha
block|;
name|int
name|m_circle_hue
block|;
name|QPointF
name|m_circle_pos
block|;
name|QPointF
name|m_offset
block|;
name|ObjectType
name|m_current_object
block|;
name|bool
name|m_animation_enabled
block|;
name|int
name|m_animationTimer
block|;
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
name|QGLPixelBuffer
operator|*
name|m_pbuffer
block|;
name|GLuint
name|m_base_tex
block|;
name|GLuint
name|m_compositing_tex
block|;
name|int
name|m_pbuffer_size
block|;
comment|// width==height==size of pbuffer
name|QSize
name|m_previous_size
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPOSITION_H
end_comment
end_unit
