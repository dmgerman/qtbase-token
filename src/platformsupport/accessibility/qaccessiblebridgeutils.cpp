begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessiblebridgeutils_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
DECL|namespace|QAccessibleBridgeUtils
namespace|namespace
name|QAccessibleBridgeUtils
block|{
DECL|function|performAction
specifier|static
name|bool
name|performAction
parameter_list|(
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|,
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
block|{
if|if
condition|(
name|QAccessibleActionInterface
modifier|*
name|actionIface
init|=
name|iface
operator|->
name|actionInterface
argument_list|()
condition|)
block|{
if|if
condition|(
name|actionIface
operator|->
name|actionNames
argument_list|()
operator|.
name|contains
argument_list|(
name|actionName
argument_list|)
condition|)
block|{
name|actionIface
operator|->
name|doAction
argument_list|(
name|actionName
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
DECL|function|effectiveActionNames
name|QStringList
name|effectiveActionNames
parameter_list|(
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|)
block|{
name|QStringList
name|actions
decl_stmt|;
if|if
condition|(
name|QAccessibleActionInterface
modifier|*
name|actionIface
init|=
name|iface
operator|->
name|actionInterface
argument_list|()
condition|)
name|actions
operator|=
name|actionIface
operator|->
name|actionNames
argument_list|()
expr_stmt|;
if|if
condition|(
name|iface
operator|->
name|valueInterface
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|actions
operator|.
name|contains
argument_list|(
name|QAccessibleActionInterface
operator|::
name|increaseAction
argument_list|()
argument_list|)
condition|)
name|actions
operator|<<
name|QAccessibleActionInterface
operator|::
name|increaseAction
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|actions
operator|.
name|contains
argument_list|(
name|QAccessibleActionInterface
operator|::
name|decreaseAction
argument_list|()
argument_list|)
condition|)
name|actions
operator|<<
name|QAccessibleActionInterface
operator|::
name|decreaseAction
argument_list|()
expr_stmt|;
block|}
return|return
name|actions
return|;
block|}
DECL|function|performEffectiveAction
name|bool
name|performEffectiveAction
parameter_list|(
name|QAccessibleInterface
modifier|*
name|iface
parameter_list|,
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
block|{
if|if
condition|(
operator|!
name|iface
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|performAction
argument_list|(
name|iface
argument_list|,
name|actionName
argument_list|)
condition|)
return|return
literal|true
return|;
if|if
condition|(
name|actionName
operator|!=
name|QAccessibleActionInterface
operator|::
name|increaseAction
argument_list|()
operator|&&
name|actionName
operator|!=
name|QAccessibleActionInterface
operator|::
name|decreaseAction
argument_list|()
condition|)
return|return
literal|false
return|;
name|QAccessibleValueInterface
modifier|*
name|valueIface
init|=
name|iface
operator|->
name|valueInterface
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|valueIface
condition|)
return|return
literal|false
return|;
name|bool
name|success
decl_stmt|;
specifier|const
name|QVariant
name|currentVariant
init|=
name|valueIface
operator|->
name|currentValue
argument_list|()
decl_stmt|;
name|double
name|stepSize
init|=
name|valueIface
operator|->
name|minimumStepSize
argument_list|()
operator|.
name|toDouble
argument_list|(
operator|&
name|success
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
operator|||
name|qFuzzyIsNull
argument_list|(
name|stepSize
argument_list|)
condition|)
block|{
specifier|const
name|double
name|min
init|=
name|valueIface
operator|->
name|minimumValue
argument_list|()
operator|.
name|toDouble
argument_list|(
operator|&
name|success
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
return|return
literal|false
return|;
specifier|const
name|double
name|max
init|=
name|valueIface
operator|->
name|maximumValue
argument_list|()
operator|.
name|toDouble
argument_list|(
operator|&
name|success
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
return|return
literal|false
return|;
name|stepSize
operator|=
operator|(
name|max
operator|-
name|min
operator|)
operator|/
literal|10
expr_stmt|;
comment|// this is pretty arbitrary, we just need to provide something
specifier|const
name|int
name|typ
init|=
name|currentVariant
operator|.
name|type
argument_list|()
decl_stmt|;
if|if
condition|(
name|typ
operator|!=
name|QMetaType
operator|::
name|Float
operator|&&
name|typ
operator|!=
name|QMetaType
operator|::
name|Double
condition|)
block|{
comment|// currentValue is an integer. Round it up to ensure stepping in case it was below 1
name|stepSize
operator|=
name|qCeil
argument_list|(
name|stepSize
argument_list|)
expr_stmt|;
block|}
block|}
specifier|const
name|double
name|current
init|=
name|currentVariant
operator|.
name|toDouble
argument_list|(
operator|&
name|success
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|actionName
operator|==
name|QAccessibleActionInterface
operator|::
name|decreaseAction
argument_list|()
condition|)
name|stepSize
operator|=
operator|-
name|stepSize
expr_stmt|;
name|valueIface
operator|->
name|setCurrentValue
argument_list|(
name|current
operator|+
name|stepSize
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
end_namespace
begin_comment
comment|//namespace
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
