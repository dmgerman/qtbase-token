begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QANDROIDSTYLE_P_H
define|#
directive|define
name|QANDROIDSTYLE_P_H
end_define
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qstylefactory.cpp.  This header may change from version to version
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
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMargins>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariantMap>
end_include
begin_include
include|#
directive|include
file|"qfusionstyle_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_ANDROID
argument_list|)
name|class
name|Q_WIDGETS_EXPORT
name|QAndroidStyle
range|:
name|public
name|QFusionStyle
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ItemType
block|{
name|QC_UnknownType
operator|=
operator|-
literal|1
block|,
name|QC_View
block|,
name|QC_GroupBox
block|,
name|QC_Button
block|,
name|QC_Checkbox
block|,
name|QC_RadioButton
block|,
name|QC_Slider
block|,
name|QC_Switch
block|,
name|QC_EditText
block|,
name|QC_Combobox
block|,
name|QC_BusyIndicator
block|,
name|QC_ProgressBar
block|,
name|QC_Tab
block|,
name|QC_TabButton
block|,
name|QC_RatingIndicator
block|,
name|QC_SearchBox
block|,
name|QC_CustomControl
operator|=
literal|0xf00
block|,
name|QC_ControlMask
operator|=
literal|0xfff
block|}
block|;      struct
name|Android9PatchChunk
block|{
name|QVector
operator|<
name|int
operator|>
name|xDivs
block|;
name|QVector
operator|<
name|int
operator|>
name|yDivs
block|;
name|QVector
operator|<
name|int
operator|>
name|colors
block|;     }
block|;      struct
name|AndroidItemStateInfo
block|{
name|AndroidItemStateInfo
argument_list|()
operator|:
name|state
argument_list|(
literal|0
argument_list|)
block|{}
name|int
name|state
block|;
name|QByteArray
name|filePath
block|;
name|QByteArray
name|hashKey
block|;
name|Android9PatchChunk
name|chunkData
block|;
name|QSize
name|size
block|;
name|QMargins
name|padding
block|;     }
block|;      enum
name|AndroidDrawableType
block|{
name|Color
block|,
name|Image
block|,
name|Clip
block|,
name|NinePatch
block|,
name|Gradient
block|,
name|State
block|,
name|Layer
block|}
block|;
name|class
name|AndroidDrawable
block|{
name|public
operator|:
name|AndroidDrawable
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
operator|~
name|AndroidDrawable
argument_list|()
block|;
name|virtual
name|void
name|initPadding
argument_list|(
specifier|const
name|QVariantMap
operator|&
name|drawable
argument_list|)
block|;
name|virtual
name|AndroidDrawableType
name|type
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
operator|=
literal|0
block|;
specifier|const
name|QMargins
operator|&
name|padding
argument_list|()
specifier|const
block|;
name|virtual
name|QSize
name|size
argument_list|()
specifier|const
block|;
specifier|static
name|AndroidDrawable
operator|*
name|fromMap
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
specifier|static
name|QMargins
name|extractMargins
argument_list|(
specifier|const
name|QVariantMap
operator|&
name|value
argument_list|)
block|;
name|virtual
name|void
name|setPaddingLeftToSizeWidth
argument_list|()
block|;
name|protected
operator|:
name|ItemType
name|m_itemType
block|;
name|QMargins
name|m_padding
block|;     }
block|;
name|class
name|AndroidColorDrawable
operator|:
name|public
name|AndroidDrawable
block|{
name|public
operator|:
name|AndroidColorDrawable
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
name|AndroidDrawableType
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QColor
name|m_color
block|;     }
block|;
name|class
name|AndroidImageDrawable
operator|:
name|public
name|AndroidDrawable
block|{
name|public
operator|:
name|AndroidImageDrawable
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
name|AndroidDrawableType
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|virtual
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QString
name|m_filePath
block|;
name|mutable
name|QString
name|m_hashKey
block|;
name|QSize
name|m_size
block|;     }
block|;
name|class
name|Android9PatchDrawable
operator|:
name|public
name|AndroidImageDrawable
block|{
name|public
operator|:
name|Android9PatchDrawable
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
name|AndroidDrawableType
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|private
operator|:
specifier|static
name|int
name|calculateStretch
argument_list|(
argument|int boundsLimit
argument_list|,
argument|int startingPoint
argument_list|,
argument|int srcSpace
argument_list|,
argument|int numStrechyPixelsRemaining
argument_list|,
argument|int numFixedPixelsRemaining
argument_list|)
block|;
name|void
name|extractIntArray
argument_list|(
specifier|const
name|QVariantList
operator|&
name|values
argument_list|,
name|QVector
operator|<
name|int
operator|>
operator|&
name|array
argument_list|)
block|;
name|private
operator|:
name|Android9PatchChunk
name|m_chunkData
block|;     }
block|;
name|class
name|AndroidGradientDrawable
operator|:
name|public
name|AndroidDrawable
block|{
name|public
operator|:
expr|enum
name|GradientOrientation
block|{
name|TOP_BOTTOM
block|,
name|TR_BL
block|,
name|RIGHT_LEFT
block|,
name|BR_TL
block|,
name|BOTTOM_TOP
block|,
name|BL_TR
block|,
name|LEFT_RIGHT
block|,
name|TL_BR
block|}
block|;
name|public
operator|:
name|AndroidGradientDrawable
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
name|AndroidDrawableType
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|private
operator|:
name|mutable
name|QLinearGradient
name|m_gradient
block|;
name|GradientOrientation
name|m_orientation
block|;
name|int
name|m_radius
block|;     }
block|;
name|class
name|AndroidClipDrawable
operator|:
name|public
name|AndroidDrawable
block|{
name|public
operator|:
name|AndroidClipDrawable
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
operator|~
name|AndroidClipDrawable
argument_list|()
block|;
name|virtual
name|AndroidDrawableType
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setFactor
argument_list|(
argument|double factor
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|private
operator|:
name|double
name|m_factor
block|;
name|Qt
operator|::
name|Orientation
name|m_orientation
block|;
specifier|const
name|AndroidDrawable
operator|*
name|m_drawable
block|;     }
block|;
name|class
name|AndroidStateDrawable
operator|:
name|public
name|AndroidDrawable
block|{
name|public
operator|:
name|AndroidStateDrawable
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
operator|~
name|AndroidStateDrawable
argument_list|()
block|;
name|virtual
name|AndroidDrawableType
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
specifier|inline
specifier|const
name|AndroidDrawable
operator|*
name|bestAndroidStateMatch
argument_list|(
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
specifier|static
name|int
name|extractState
argument_list|(
specifier|const
name|QVariantMap
operator|&
name|value
argument_list|)
block|;
name|virtual
name|void
name|setPaddingLeftToSizeWidth
argument_list|()
block|;
name|QSize
name|sizeImage
argument_list|(
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|private
operator|:
typedef|typedef
name|QPair
operator|<
name|int
operator|,
specifier|const
name|AndroidDrawable
operator|*
operator|>
name|StateType
expr_stmt|;
name|QList
operator|<
name|StateType
operator|>
name|m_states
block|;     }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|AndroidLayerDrawable
range|:
name|public
name|AndroidDrawable
block|{
name|public
operator|:
name|AndroidLayerDrawable
argument_list|(
argument|const QVariantMap&drawable
argument_list|,
argument|QAndroidStyle::ItemType itemType
argument_list|)
block|;
operator|~
name|AndroidLayerDrawable
argument_list|()
block|;
name|virtual
name|AndroidDrawableType
name|type
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setFactor
argument_list|(
argument|int id
argument_list|,
argument|double factor
argument_list|,
argument|Qt::Orientation orientation
argument_list|)
block|;
name|virtual
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|AndroidDrawable
operator|*
name|layer
argument_list|(
argument|int id
argument_list|)
specifier|const
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|private
operator|:
typedef|typedef
name|QPair
operator|<
name|int
operator|,
name|AndroidDrawable
operator|*
operator|>
name|LayerType
expr_stmt|;
name|QList
operator|<
name|LayerType
operator|>
name|m_layers
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_id
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|double
name|m_factor
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|Orientation
name|m_orientation
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|};
name|class
name|AndroidControl
block|{
name|public
label|:
name|AndroidControl
argument_list|(
argument|const QVariantMap&control
argument_list|,
argument|ItemType itemType
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|AndroidControl
argument_list|()
expr_stmt|;
name|virtual
name|void
name|drawControl
parameter_list|(
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|,
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
function_decl|;
name|virtual
name|QRect
name|subElementRect
argument_list|(
name|SubElement
name|subElement
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QRect
name|subControlRect
argument_list|(
specifier|const
name|QStyleOptionComplex
operator|*
name|option
argument_list|,
name|SubControl
name|sc
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QSize
name|sizeFromContents
argument_list|(
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
specifier|const
name|QSize
operator|&
name|contentsSize
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QMargins
name|padding
parameter_list|()
function_decl|;
name|virtual
name|QSize
name|size
parameter_list|(
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|)
function_decl|;
name|protected
label|:
name|virtual
specifier|const
name|AndroidDrawable
operator|*
name|backgroundDrawable
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|AndroidDrawable
modifier|*
name|m_background
decl_stmt|;
name|QSize
name|m_minSize
decl_stmt|;
name|QSize
name|m_maxSize
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|AndroidCompoundButtonControl
range|:
name|public
name|AndroidControl
block|{
name|public
operator|:
name|AndroidCompoundButtonControl
argument_list|(
argument|const QVariantMap&control
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
operator|~
name|AndroidCompoundButtonControl
argument_list|()
block|;
name|virtual
name|void
name|drawControl
argument_list|(
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|virtual
name|QMargins
name|padding
argument_list|()
block|;
name|virtual
name|QSize
name|size
argument_list|(
specifier|const
name|QStyleOption
operator|*
name|option
argument_list|)
block|;
name|protected
operator|:
name|virtual
specifier|const
name|AndroidDrawable
operator|*
name|backgroundDrawable
argument_list|()
specifier|const
block|;
specifier|const
name|AndroidDrawable
operator|*
name|m_button
block|;     }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|AndroidProgressBarControl
range|:
name|public
name|AndroidControl
block|{
name|public
operator|:
name|AndroidProgressBarControl
argument_list|(
argument|const QVariantMap&control
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
operator|~
name|AndroidProgressBarControl
argument_list|()
block|;
name|virtual
name|void
name|drawControl
argument_list|(
specifier|const
name|QStyleOption
operator|*
name|option
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|virtual
name|QRect
name|subElementRect
argument_list|(
argument|SubElement subElement
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|QSize
name|sizeFromContents
argument_list|(
argument|const QStyleOption *opt
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *w
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|AndroidDrawable
operator|*
name|m_progressDrawable
block|;
name|AndroidDrawable
operator|*
name|m_indeterminateDrawable
block|;
name|int
name|m_secondaryProgress_id
block|;
name|int
name|m_progressId
block|;     }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|AndroidSeekBarControl
range|:
name|public
name|AndroidProgressBarControl
block|{
name|public
operator|:
name|AndroidSeekBarControl
argument_list|(
argument|const QVariantMap&control
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
operator|~
name|AndroidSeekBarControl
argument_list|()
block|;
name|virtual
name|void
name|drawControl
argument_list|(
specifier|const
name|QStyleOption
operator|*
name|option
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|QSize
name|sizeFromContents
argument_list|(
argument|const QStyleOption *opt
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *w
argument_list|)
specifier|const
block|;
name|QRect
name|subControlRect
argument_list|(
argument|const QStyleOptionComplex *option
argument_list|,
argument|SubControl sc
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|private
operator|:
name|AndroidDrawable
operator|*
name|m_seekBarThumb
block|;     }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|AndroidSpinnerControl
range|:
name|public
name|AndroidControl
block|{
name|public
operator|:
name|AndroidSpinnerControl
argument_list|(
argument|const QVariantMap&control
argument_list|,
argument|ItemType itemType
argument_list|)
block|;
name|virtual
operator|~
name|AndroidSpinnerControl
argument_list|()
block|{}
name|virtual
name|QRect
name|subControlRect
argument_list|(
argument|const QStyleOptionComplex *option
argument_list|,
argument|SubControl sc
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;     }
decl_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|QList
operator|<
name|AndroidItemStateInfo
operator|*
operator|>
name|AndroidItemStateInfoList
expr_stmt|;
end_typedef
begin_label
name|public
label|:
end_label
begin_expr_stmt
name|QAndroidStyle
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QAndroidStyle
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|virtual
name|void
name|drawPrimitive
argument_list|(
name|PrimitiveElement
name|pe
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|void
name|drawControl
argument_list|(
name|QStyle
operator|::
name|ControlElement
name|element
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QRect
name|subElementRect
argument_list|(
name|SubElement
name|subElement
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|void
name|drawComplexControl
argument_list|(
name|ComplexControl
name|cc
argument_list|,
specifier|const
name|QStyleOptionComplex
operator|*
name|opt
argument_list|,
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|SubControl
name|hitTestComplexControl
argument_list|(
name|ComplexControl
name|cc
argument_list|,
specifier|const
name|QStyleOptionComplex
operator|*
name|opt
argument_list|,
specifier|const
name|QPoint
operator|&
name|pt
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QRect
name|subControlRect
argument_list|(
name|ComplexControl
name|cc
argument_list|,
specifier|const
name|QStyleOptionComplex
operator|*
name|opt
argument_list|,
name|SubControl
name|sc
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|int
name|pixelMetric
argument_list|(
name|PixelMetric
name|metric
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
operator|=
literal|0
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QSize
name|sizeFromContents
argument_list|(
name|ContentsType
name|ct
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|,
specifier|const
name|QSize
operator|&
name|contentsSize
argument_list|,
specifier|const
name|QWidget
operator|*
name|w
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QPixmap
name|standardPixmap
argument_list|(
name|StandardPixmap
name|standardPixmap
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
operator|=
literal|0
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|QPixmap
name|generatedIconPixmap
argument_list|(
name|QIcon
operator|::
name|Mode
name|iconMode
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|opt
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|styleHint
argument_list|(
name|StyleHint
name|hint
argument_list|,
specifier|const
name|QStyleOption
operator|*
name|option
operator|=
literal|0
argument_list|,
specifier|const
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|,
name|QStyleHintReturn
operator|*
name|returnData
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|virtual
name|QPalette
name|standardPalette
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|polish
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unpolish
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QAndroidStyle
argument_list|)
end_macro
begin_decl_stmt
specifier|static
name|ItemType
name|qtControl
argument_list|(
name|QStyle
operator|::
name|ComplexControl
name|control
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|ItemType
name|qtControl
argument_list|(
name|QStyle
operator|::
name|ContentsType
name|contentsType
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|ItemType
name|qtControl
argument_list|(
name|QStyle
operator|::
name|ControlElement
name|controlElement
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|ItemType
name|qtControl
argument_list|(
name|QStyle
operator|::
name|PrimitiveElement
name|primitiveElement
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|ItemType
name|qtControl
argument_list|(
name|QStyle
operator|::
name|SubElement
name|subElement
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|ItemType
name|qtControl
parameter_list|(
specifier|const
name|QString
modifier|&
name|android
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_typedef
typedef|typedef
name|QHash
operator|<
name|int
operator|,
name|AndroidControl
operator|*
operator|>
name|AndroidControlsHash
expr_stmt|;
end_typedef
begin_decl_stmt
name|AndroidControlsHash
name|m_androidControlsHash
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPalette
name|m_standardPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|AndroidCompoundButtonControl
modifier|*
name|checkBoxControl
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_ANDROID
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QANDROIDSTYLE_P_H
end_comment
end_unit
