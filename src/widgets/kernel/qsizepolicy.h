begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIZEPOLICY_H
end_ifndef
begin_define
DECL|macro|QSIZEPOLICY_H
define|#
directive|define
name|QSIZEPOLICY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QSizePolicy
block|{
name|Q_GADGET
name|Q_FLAGS
argument_list|(
name|ControlTypes
argument_list|)
name|public
range|:     enum
name|PolicyFlag
block|{
name|GrowFlag
operator|=
literal|1
block|,
name|ExpandFlag
operator|=
literal|2
block|,
name|ShrinkFlag
operator|=
literal|4
block|,
name|IgnoreFlag
operator|=
literal|8
block|}
decl_stmt|;
enum|enum
name|Policy
block|{
name|Fixed
init|=
literal|0
block|,
name|Minimum
init|=
name|GrowFlag
block|,
name|Maximum
init|=
name|ShrinkFlag
block|,
name|Preferred
init|=
name|GrowFlag
operator||
name|ShrinkFlag
block|,
name|MinimumExpanding
init|=
name|GrowFlag
operator||
name|ExpandFlag
block|,
name|Expanding
init|=
name|GrowFlag
operator||
name|ShrinkFlag
operator||
name|ExpandFlag
block|,
name|Ignored
init|=
name|ShrinkFlag
operator||
name|GrowFlag
operator||
name|IgnoreFlag
block|}
enum|;
name|Q_ENUM
argument_list|(
name|Policy
argument_list|)
expr|enum
name|ControlType
block|{
name|DefaultType
operator|=
literal|0x00000001
block|,
name|ButtonBox
operator|=
literal|0x00000002
block|,
name|CheckBox
operator|=
literal|0x00000004
block|,
name|ComboBox
operator|=
literal|0x00000008
block|,
name|Frame
operator|=
literal|0x00000010
block|,
name|GroupBox
operator|=
literal|0x00000020
block|,
name|Label
operator|=
literal|0x00000040
block|,
name|Line
operator|=
literal|0x00000080
block|,
name|LineEdit
operator|=
literal|0x00000100
block|,
name|PushButton
operator|=
literal|0x00000200
block|,
name|RadioButton
operator|=
literal|0x00000400
block|,
name|Slider
operator|=
literal|0x00000800
block|,
name|SpinBox
operator|=
literal|0x00001000
block|,
name|TabWidget
operator|=
literal|0x00002000
block|,
name|ToolButton
operator|=
literal|0x00004000
block|}
expr_stmt|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ControlTypes
argument_list|,
argument|ControlType
argument_list|)
name|QSizePolicy
argument_list|()
operator|:
name|data
argument_list|(
literal|0
argument_list|)
block|{ }
name|QSizePolicy
argument_list|(
argument|Policy horizontal
argument_list|,
argument|Policy vertical
argument_list|,
argument|ControlType type = DefaultType
argument_list|)
operator|:
name|data
argument_list|(
literal|0
argument_list|)
block|{
name|bits
operator|.
name|horPolicy
operator|=
name|horizontal
block|;
name|bits
operator|.
name|verPolicy
operator|=
name|vertical
block|;
name|setControlType
argument_list|(
name|type
argument_list|)
block|;     }
name|Policy
name|horizontalPolicy
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Policy
operator|>
operator|(
name|bits
operator|.
name|horPolicy
operator|)
return|;
block|}
name|Policy
name|verticalPolicy
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Policy
operator|>
operator|(
name|bits
operator|.
name|verPolicy
operator|)
return|;
block|}
name|ControlType
name|controlType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setHorizontalPolicy
parameter_list|(
name|Policy
name|d
parameter_list|)
block|{
name|bits
operator|.
name|horPolicy
operator|=
name|d
expr_stmt|;
block|}
name|void
name|setVerticalPolicy
parameter_list|(
name|Policy
name|d
parameter_list|)
block|{
name|bits
operator|.
name|verPolicy
operator|=
name|d
expr_stmt|;
block|}
name|void
name|setControlType
parameter_list|(
name|ControlType
name|type
parameter_list|)
function_decl|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|verticalPolicy
argument_list|()
operator|&
name|ExpandFlag
operator|)
operator|?
name|Qt
operator|::
name|Vertical
operator|:
name|Qt
operator|::
name|Orientations
argument_list|()
operator|)
operator||
operator|(
operator|(
name|horizontalPolicy
argument_list|()
operator|&
name|ExpandFlag
operator|)
operator|?
name|Qt
operator|::
name|Horizontal
operator|:
name|Qt
operator|::
name|Orientations
argument_list|()
operator|)
return|;
block|}
name|void
name|setHeightForWidth
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|bits
operator|.
name|hfw
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
block|{
return|return
name|bits
operator|.
name|hfw
return|;
block|}
name|void
name|setWidthForHeight
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|bits
operator|.
name|wfh
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|hasWidthForHeight
argument_list|()
specifier|const
block|{
return|return
name|bits
operator|.
name|wfh
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSizePolicy
operator|&
name|s
operator|)
specifier|const
block|{
return|return
name|data
operator|==
name|s
operator|.
name|data
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSizePolicy
operator|&
name|s
operator|)
specifier|const
block|{
return|return
name|data
operator|!=
name|s
operator|.
name|data
return|;
block|}
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
comment|// implemented in qlayoutitem.cpp
name|int
name|horizontalStretch
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|bits
operator|.
name|horStretch
operator|)
return|;
block|}
name|int
name|verticalStretch
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|bits
operator|.
name|verStretch
operator|)
return|;
block|}
name|void
name|setHorizontalStretch
parameter_list|(
name|int
name|stretchFactor
parameter_list|)
block|{
name|bits
operator|.
name|horStretch
operator|=
name|static_cast
operator|<
name|quint32
operator|>
operator|(
name|qBound
argument_list|(
literal|0
argument_list|,
name|stretchFactor
argument_list|,
literal|255
argument_list|)
operator|)
expr_stmt|;
block|}
name|void
name|setVerticalStretch
parameter_list|(
name|int
name|stretchFactor
parameter_list|)
block|{
name|bits
operator|.
name|verStretch
operator|=
name|static_cast
operator|<
name|quint32
operator|>
operator|(
name|qBound
argument_list|(
literal|0
argument_list|,
name|stretchFactor
argument_list|,
literal|255
argument_list|)
operator|)
expr_stmt|;
block|}
name|bool
name|retainSizeWhenHidden
argument_list|()
specifier|const
block|{
return|return
name|bits
operator|.
name|retainSizeWhenHidden
return|;
block|}
name|void
name|setRetainSizeWhenHidden
parameter_list|(
name|bool
name|retainSize
parameter_list|)
block|{
name|bits
operator|.
name|retainSizeWhenHidden
operator|=
name|retainSize
expr_stmt|;
block|}
name|void
name|transpose
parameter_list|()
function_decl|;
name|private
label|:
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
name|QSizePolicy
argument_list|(
argument|int i
argument_list|)
block|:
name|data
argument_list|(
argument|i
argument_list|)
block|{ }
struct|struct
name|Bits
block|{
name|quint32
name|horStretch
range|:
literal|8
decl_stmt|;
name|quint32
name|verStretch
range|:
literal|8
decl_stmt|;
name|quint32
name|horPolicy
range|:
literal|4
decl_stmt|;
name|quint32
name|verPolicy
range|:
literal|4
decl_stmt|;
name|quint32
name|ctype
range|:
literal|5
decl_stmt|;
name|quint32
name|hfw
range|:
literal|1
decl_stmt|;
name|quint32
name|wfh
range|:
literal|1
decl_stmt|;
name|quint32
name|retainSizeWhenHidden
range|:
literal|1
decl_stmt|;
block|}
struct|;
union|union
block|{
name|Bits
name|bits
decl_stmt|;
name|quint32
name|data
decl_stmt|;
block|}
union|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_if
if|#
directive|if
name|QT_VERSION
operator|>=
name|QT_VERSION_CHECK
argument_list|(
literal|6
operator|,
literal|0
operator|,
literal|0
argument_list|)
end_if
begin_comment
comment|// Can't add in Qt 5, as QList<QSizePolicy> would be BiC:
end_comment
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QSizePolicy
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QSizePolicy::ControlTypes
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|// implemented in qlayout.cpp
end_comment
begin_expr_stmt
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_WIDGETS_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_WIDGETS_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|dbg
operator|,
specifier|const
name|QSizePolicy
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
DECL|function|transpose
specifier|inline
name|void
name|QSizePolicy
operator|::
name|transpose
argument_list|()
block|{
name|Policy
name|hData
operator|=
name|horizontalPolicy
argument_list|()
block|;
name|Policy
name|vData
operator|=
name|verticalPolicy
argument_list|()
block|;
name|int
name|hStretch
operator|=
name|horizontalStretch
argument_list|()
block|;
name|int
name|vStretch
operator|=
name|verticalStretch
argument_list|()
block|;
name|setHorizontalPolicy
argument_list|(
name|vData
argument_list|)
block|;
name|setVerticalPolicy
argument_list|(
name|hData
argument_list|)
block|;
name|setHorizontalStretch
argument_list|(
name|vStretch
argument_list|)
block|;
name|setVerticalStretch
argument_list|(
name|hStretch
argument_list|)
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIZEPOLICY_H
end_comment
end_unit
