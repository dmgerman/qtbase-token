begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCORE_MAC_P_H
end_ifndef
begin_define
DECL|macro|QCORE_MAC_P_H
define|#
directive|define
name|QCORE_MAC_P_H
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
comment|// of other Qt classes.  This header file may change from version to
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
begin_ifndef
ifndef|#
directive|ifndef
name|__IMAGECAPTURE__
end_ifndef
begin_define
DECL|macro|__IMAGECAPTURE__
define|#
directive|define
name|__IMAGECAPTURE__
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_undef
DECL|macro|OLD_DEBUG
undef|#
directive|undef
name|OLD_DEBUG
end_undef
begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef
begin_define
DECL|macro|OLD_DEBUG
define|#
directive|define
name|OLD_DEBUG
value|DEBUG
end_define
begin_undef
DECL|macro|DEBUG
undef|#
directive|undef
name|DEBUG
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|DEBUG
define|#
directive|define
name|DEBUG
value|0
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|qDebug
end_ifdef
begin_define
DECL|macro|old_qDebug
define|#
directive|define
name|old_qDebug
value|qDebug
end_define
begin_undef
DECL|macro|qDebug
undef|#
directive|undef
name|qDebug
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_QMAKE
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_include
include|#
directive|include
file|<ApplicationServices/ApplicationServices.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<CoreFoundation/CoreFoundation.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CORESERVICES
end_ifndef
begin_include
include|#
directive|include
file|<CoreServices/CoreServices.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_undef
DECL|macro|DEBUG
undef|#
directive|undef
name|DEBUG
end_undef
begin_ifdef
ifdef|#
directive|ifdef
name|OLD_DEBUG
end_ifdef
begin_define
DECL|macro|DEBUG
define|#
directive|define
name|DEBUG
value|OLD_DEBUG
end_define
begin_undef
DECL|macro|OLD_DEBUG
undef|#
directive|undef
name|OLD_DEBUG
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|old_qDebug
end_ifdef
begin_undef
DECL|macro|qDebug
undef|#
directive|undef
name|qDebug
end_undef
begin_define
DECL|macro|qDebug
define|#
directive|define
name|qDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_undef
DECL|macro|old_qDebug
undef|#
directive|undef
name|old_qDebug
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|/*     Helper class that automates refernce counting for CFtypes.     After constructing the QCFType object, it can be copied like a     value-based type.      Note that you must own the object you are wrapping.     This is typically the case if you get the object from a Core     Foundation function with the word "Create" or "Copy" in it. If     you got the object from a "Get" function, either retain it or use     constructFromGet(). One exception to this rule is the     HIThemeGet*Shape functions, which in reality are "Copy" functions. */
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Q_CORE_EXPORT
name|QCFType
block|{
name|public
operator|:
specifier|inline
name|QCFType
argument_list|(
specifier|const
name|T
operator|&
name|t
operator|=
literal|0
argument_list|)
operator|:
name|type
argument_list|(
argument|t
argument_list|)
block|{}
specifier|inline
name|QCFType
argument_list|(
specifier|const
name|QCFType
operator|&
name|helper
argument_list|)
operator|:
name|type
argument_list|(
argument|helper.type
argument_list|)
block|{
if|if
condition|(
name|type
condition|)
name|CFRetain
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
specifier|inline
operator|~
name|QCFType
argument_list|()
block|{
if|if
condition|(
name|type
condition|)
name|CFRelease
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|operator
name|T
parameter_list|()
block|{
return|return
name|type
return|;
block|}
end_function
begin_decl_stmt
specifier|inline
name|QCFType
name|operator
init|=
operator|(
specifier|const
name|QCFType
operator|&
name|helper
operator|)
block|{
if|if
condition|(
name|helper
operator|.
name|type
condition|)
name|CFRetain
argument_list|(
name|helper
operator|.
name|type
argument_list|)
expr_stmt|;
name|CFTypeRef
name|type2
operator|=
name|type
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|type
operator|=
name|helper
operator|.
name|type
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|type2
condition|)
name|CFRelease
argument_list|(
name|type2
argument_list|)
expr_stmt|;
end_if
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_function
unit|}     inline
name|T
modifier|*
name|operator
function|&()
block|{
return|return
operator|&
name|type
return|;
block|}
end_function
begin_function
specifier|static
name|QCFType
name|constructFromGet
parameter_list|(
specifier|const
name|T
modifier|&
name|t
parameter_list|)
block|{
name|CFRetain
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
name|QCFType
operator|<
name|T
operator|>
operator|(
name|t
operator|)
return|;
block|}
end_function
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|T
name|type
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_CORE_EXPORT
name|QCFString
range|:
name|public
name|QCFType
operator|<
name|CFStringRef
operator|>
block|{
name|public
operator|:
specifier|inline
name|QCFString
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|)
operator|:
name|QCFType
operator|<
name|CFStringRef
operator|>
operator|(
literal|0
operator|)
block|,
name|string
argument_list|(
argument|str
argument_list|)
block|{}
specifier|inline
name|QCFString
argument_list|(
argument|const CFStringRef cfstr =
literal|0
argument_list|)
operator|:
name|QCFType
operator|<
name|CFStringRef
operator|>
operator|(
name|cfstr
operator|)
block|{}
specifier|inline
name|QCFString
argument_list|(
specifier|const
name|QCFType
operator|<
name|CFStringRef
operator|>
operator|&
name|other
argument_list|)
operator|:
name|QCFType
operator|<
name|CFStringRef
operator|>
operator|(
name|other
operator|)
block|{}
name|operator
name|QString
argument_list|()
specifier|const
block|;
name|operator
name|CFStringRef
argument_list|()
specifier|const
block|;
specifier|static
name|QString
name|toQString
argument_list|(
argument|CFStringRef cfstr
argument_list|)
block|;
specifier|static
name|CFStringRef
name|toCFStringRef
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|)
block|;
name|private
operator|:
name|QString
name|string
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_if
if|#
directive|if
operator|(
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|<
name|MAC_OS_X_VERSION_10_5
operator|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|__LP64__
end_ifndef
begin_typedef
DECL|typedef|CGFloat
typedef|typedef
name|float
name|CGFloat
typedef|;
end_typedef
begin_typedef
DECL|typedef|NSInteger
typedef|typedef
name|int
name|NSInteger
typedef|;
end_typedef
begin_typedef
DECL|typedef|NSUInteger
typedef|typedef
name|unsigned
name|int
name|NSUInteger
typedef|;
end_typedef
begin_define
DECL|macro|SRefCon
define|#
directive|define
name|SRefCon
value|SInt32
end_define
begin_define
DECL|macro|URefCon
define|#
directive|define
name|URefCon
value|UInt32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCORE_MAC_P_H
end_comment
end_unit
