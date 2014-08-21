begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETATYPESWITCHER_P_H
end_ifndef
begin_define
DECL|macro|QMETATYPESWITCHER_P_H
define|#
directive|define
name|QMETATYPESWITCHER_P_H
end_define
begin_include
include|#
directive|include
file|"qmetatype.h"
end_include
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QMetaTypeSwitcher
block|{
name|public
label|:
name|class
name|NotBuiltinType
decl_stmt|;
comment|// type is not a built-in type, but it may be a custom type or an unknown type
name|class
name|UnknownType
decl_stmt|;
comment|// type not known to QMetaType system
name|template
operator|<
name|class
name|ReturnType
operator|,
name|class
name|DelegateObject
operator|>
specifier|static
name|ReturnType
name|switcher
argument_list|(
argument|DelegateObject&logic
argument_list|,
argument|int type
argument_list|,
argument|const void *data
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|QT_METATYPE_SWICHER_CASE
define|#
directive|define
name|QT_METATYPE_SWICHER_CASE
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|case QMetaType::TypeName: return logic.delegate(static_cast<Name const *>(data));
end_define
begin_expr_stmt
DECL|variable|ReturnType
name|template
operator|<
name|class
name|ReturnType
operator|,
name|class
name|DelegateObject
operator|>
DECL|function|switcher
name|ReturnType
name|QMetaTypeSwitcher
operator|::
name|switcher
argument_list|(
argument|DelegateObject&logic
argument_list|,
argument|int type
argument_list|,
argument|const void *data
argument_list|)
block|{
switch|switch
condition|(
name|QMetaType
operator|::
name|Type
argument_list|(
name|type
argument_list|)
condition|)
block|{
name|QT_FOR_EACH_STATIC_TYPE
argument_list|(
argument|QT_METATYPE_SWICHER_CASE
argument_list|)
case|case
name|QMetaType
operator|::
name|UnknownType
case|:
return|return
name|logic
operator|.
name|delegate
argument_list|(
name|static_cast
operator|<
name|UnknownType
specifier|const
operator|*
operator|>
operator|(
name|data
operator|)
argument_list|)
return|;
default|default:
if|if
condition|(
name|type
operator|<
name|QMetaType
operator|::
name|User
condition|)
return|return
name|logic
operator|.
name|delegate
argument_list|(
name|static_cast
operator|<
name|UnknownType
specifier|const
operator|*
operator|>
operator|(
name|data
operator|)
argument_list|)
return|;
return|return
name|logic
operator|.
name|delegate
argument_list|(
name|static_cast
operator|<
name|NotBuiltinType
specifier|const
operator|*
operator|>
operator|(
name|data
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_undef
DECL|macro|QT_METATYPE_SWICHER_CASE
unit|}
undef|#
directive|undef
name|QT_METATYPE_SWICHER_CASE
end_undef
begin_endif
unit|QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QMETATYPESWITCHER_P_H
end_comment
end_unit
