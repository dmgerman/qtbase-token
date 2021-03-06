begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVARIANTANIMATION_H
end_ifndef
begin_define
DECL|macro|QVARIANTANIMATION_H
define|#
directive|define
name|QVARIANTANIMATION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qeasingcurve.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
DECL|variable|QVariantAnimationPrivate
name|class
name|QVariantAnimationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QVariantAnimation
range|:
name|public
name|QAbstractAnimation
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QVariant startValue READ startValue WRITE setStartValue
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QVariant endValue READ endValue WRITE setEndValue
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QVariant currentValue READ currentValue NOTIFY valueChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int duration READ duration WRITE setDuration
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QEasingCurve easingCurve READ easingCurve WRITE setEasingCurve
argument_list|)
name|public
operator|:
typedef|typedef
name|QPair
operator|<
name|qreal
operator|,
name|QVariant
operator|>
name|KeyValue
expr_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|QVector
operator|<
name|KeyValue
operator|>
name|KeyValues
expr_stmt|;
end_typedef
begin_expr_stmt
name|QVariantAnimation
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QVariantAnimation
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QVariant
name|startValue
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setStartValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QVariant
name|endValue
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEndValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QVariant
name|keyValueAt
argument_list|(
name|qreal
name|step
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setKeyValueAt
parameter_list|(
name|qreal
name|step
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|KeyValues
name|keyValues
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setKeyValues
parameter_list|(
specifier|const
name|KeyValues
modifier|&
name|values
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QVariant
name|currentValue
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|duration
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDuration
parameter_list|(
name|int
name|msecs
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QEasingCurve
name|easingCurve
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setEasingCurve
parameter_list|(
specifier|const
name|QEasingCurve
modifier|&
name|easing
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
typedef|typedef
name|QVariant
function_decl|(
modifier|*
name|Interpolator
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|from
parameter_list|,
specifier|const
name|void
modifier|*
name|to
parameter_list|,
name|qreal
name|progress
parameter_list|)
function_decl|;
end_typedef
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|void
name|valueChanged
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QVariantAnimation
argument_list|(
name|QVariantAnimationPrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|updateCurrentTime
argument_list|(
name|int
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|updateState
argument_list|(
name|QAbstractAnimation
operator|::
name|State
name|newState
argument_list|,
name|QAbstractAnimation
operator|::
name|State
name|oldState
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
end_decl_stmt
begin_function_decl
name|virtual
name|void
name|updateCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|QVariant
name|interpolated
argument_list|(
specifier|const
name|QVariant
operator|&
name|from
argument_list|,
specifier|const
name|QVariant
operator|&
name|to
argument_list|,
name|qreal
name|progress
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|void
name|qRegisterAnimationInterpolator
argument_list|(
name|QVariant
argument_list|(
operator|*
name|func
argument_list|)
argument_list|(
specifier|const
name|T
operator|&
argument_list|,
specifier|const
name|T
operator|&
argument_list|,
name|qreal
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|void
name|registerInterpolator
parameter_list|(
name|Interpolator
name|func
parameter_list|,
name|int
name|interpolationType
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QVariantAnimation
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QVariantAnimation
argument_list|)
end_macro
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qRegisterAnimationInterpolator
name|void
name|qRegisterAnimationInterpolator
argument_list|(
argument|QVariant (*func)(const T&from, const T&to, qreal progress)
argument_list|)
block|{
name|QVariantAnimation
operator|::
name|registerInterpolator
argument_list|(
name|reinterpret_cast
operator|<
name|QVariantAnimation
operator|::
name|Interpolator
operator|>
operator|(
name|func
operator|)
argument_list|,
name|qMetaTypeId
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
block|; }
endif|#
directive|endif
comment|//QT_NO_ANIMATION
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QVARIANTANIMATION_H
end_comment
end_unit
