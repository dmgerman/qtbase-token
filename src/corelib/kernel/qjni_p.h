begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifndef
ifndef|#
directive|ifndef
name|QJNI_P_H
end_ifndef
begin_define
DECL|macro|QJNI_P_H
define|#
directive|define
name|QJNI_P_H
end_define
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QJNILocalRefDeleter
struct|struct
name|Q_CORE_EXPORT
name|QJNILocalRefDeleter
block|{
specifier|static
name|void
name|cleanup
parameter_list|(
name|jobject
name|obj
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_comment
comment|// To simplify this we only define it for jobjects.
end_comment
begin_typedef
DECL|typedef|_jobject
DECL|typedef|QJNIScopedLocalRef
typedef|typedef
name|QScopedPointer
operator|<
name|_jobject
operator|,
name|QJNILocalRefDeleter
operator|>
name|QJNIScopedLocalRef
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QJNIEnvironmentPrivate
block|{
name|public
label|:
name|QJNIEnvironmentPrivate
argument_list|()
expr_stmt|;
operator|~
name|QJNIEnvironmentPrivate
argument_list|()
expr_stmt|;
name|JNIEnv
operator|*
name|operator
operator|->
expr|(
block|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|operator
name|JNIEnv
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|jclass
name|findClass
parameter_list|(
specifier|const
name|char
modifier|*
name|className
parameter_list|,
name|JNIEnv
modifier|*
name|env
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|friend
name|class
name|QAndroidJniEnvironment
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QJNIEnvironmentPrivate
argument_list|)
end_macro
begin_decl_stmt
name|JNIEnv
modifier|*
name|jniEnv
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_CORE_EXPORT
name|QJNIObjectData
block|{
name|public
label|:
name|QJNIObjectData
argument_list|()
expr_stmt|;
operator|~
name|QJNIObjectData
argument_list|()
expr_stmt|;
name|jobject
name|m_jobject
decl_stmt|;
name|jclass
name|m_jclass
decl_stmt|;
name|bool
name|m_own_jclass
decl_stmt|;
name|QByteArray
name|m_className
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QJNIObjectPrivate
block|{
name|public
label|:
name|QJNIObjectPrivate
argument_list|()
expr_stmt|;
name|explicit
name|QJNIObjectPrivate
parameter_list|(
specifier|const
name|char
modifier|*
name|className
parameter_list|)
function_decl|;
name|QJNIObjectPrivate
argument_list|(
specifier|const
name|char
operator|*
name|className
argument_list|,
specifier|const
name|char
operator|*
name|sig
argument_list|,
operator|...
argument_list|)
expr_stmt|;
name|explicit
name|QJNIObjectPrivate
parameter_list|(
name|jclass
name|clazz
parameter_list|)
function_decl|;
name|QJNIObjectPrivate
argument_list|(
argument|jclass clazz
argument_list|,
argument|const char *sig
argument_list|,
argument|...
argument_list|)
empty_stmt|;
comment|// In most cases you should never call this function with a local ref. unless you intend
comment|// to manage the local ref. yourself.
comment|// NOTE: see fromLocalRef() for converting a local ref. to QJNIObjectPrivate.
name|explicit
name|QJNIObjectPrivate
parameter_list|(
name|jobject
name|globalRef
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|callMethod
argument_list|(
argument|const char *methodName
argument_list|,
argument|const char *sig
argument_list|,
argument|...
argument_list|)
specifier|const
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|callMethod
argument_list|(
argument|const char *methodName
argument_list|)
specifier|const
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|QJNIObjectPrivate
name|callObjectMethod
argument_list|(
argument|const char *methodName
argument_list|)
specifier|const
expr_stmt|;
name|QJNIObjectPrivate
name|callObjectMethod
argument_list|(
specifier|const
name|char
operator|*
name|methodName
argument_list|,
specifier|const
name|char
operator|*
name|sig
argument_list|,
operator|...
argument_list|)
decl|const
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|callStaticMethod
argument_list|(
specifier|const
name|char
operator|*
name|className
argument_list|,
specifier|const
name|char
operator|*
name|methodName
argument_list|,
specifier|const
name|char
operator|*
name|sig
argument_list|,
operator|...
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|callStaticMethod
argument_list|(
specifier|const
name|char
operator|*
name|className
argument_list|,
specifier|const
name|char
operator|*
name|methodName
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|callStaticMethod
argument_list|(
argument|jclass clazz
argument_list|,
argument|const char *methodName
argument_list|,
argument|const char *sig
argument_list|,
argument|...
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|callStaticMethod
argument_list|(
argument|jclass clazz
argument_list|,
argument|const char *methodName
argument_list|)
expr_stmt|;
specifier|static
name|QJNIObjectPrivate
name|callStaticObjectMethod
parameter_list|(
specifier|const
name|char
modifier|*
name|className
parameter_list|,
specifier|const
name|char
modifier|*
name|methodName
parameter_list|,
specifier|const
name|char
modifier|*
name|sig
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
specifier|static
name|QJNIObjectPrivate
name|callStaticObjectMethod
parameter_list|(
name|jclass
name|clazz
parameter_list|,
specifier|const
name|char
modifier|*
name|methodName
parameter_list|,
specifier|const
name|char
modifier|*
name|sig
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|getField
argument_list|(
argument|const char *fieldName
argument_list|)
specifier|const
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|getStaticField
argument_list|(
specifier|const
name|char
operator|*
name|className
argument_list|,
specifier|const
name|char
operator|*
name|fieldName
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|getStaticField
argument_list|(
argument|jclass clazz
argument_list|,
argument|const char *fieldName
argument_list|)
expr_stmt|;
name|QJNIObjectPrivate
name|getObjectField
argument_list|(
specifier|const
name|char
operator|*
name|fieldName
argument_list|,
specifier|const
name|char
operator|*
name|sig
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QJNIObjectPrivate
name|getStaticObjectField
parameter_list|(
specifier|const
name|char
modifier|*
name|className
parameter_list|,
specifier|const
name|char
modifier|*
name|fieldName
parameter_list|,
specifier|const
name|char
modifier|*
name|sig
parameter_list|)
function_decl|;
specifier|static
name|QJNIObjectPrivate
name|getStaticObjectField
parameter_list|(
name|jclass
name|clazz
parameter_list|,
specifier|const
name|char
modifier|*
name|fieldName
parameter_list|,
specifier|const
name|char
modifier|*
name|sig
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|setField
argument_list|(
argument|const char *fieldName
argument_list|,
argument|T value
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|setField
argument_list|(
argument|const char *fieldName
argument_list|,
argument|const char *sig
argument_list|,
argument|T value
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|setStaticField
argument_list|(
argument|const char *className
argument_list|,
argument|const char *fieldName
argument_list|,
argument|T value
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|setStaticField
argument_list|(
argument|const char *className
argument_list|,
argument|const char *fieldName
argument_list|,
argument|const char *sig
argument_list|,
argument|T value
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|setStaticField
argument_list|(
argument|jclass clazz
argument_list|,
argument|const char *fieldName
argument_list|,
argument|const char *sig
argument_list|,
argument|T value
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
name|setStaticField
argument_list|(
argument|jclass clazz
argument_list|,
argument|const char *fieldName
argument_list|,
argument|T value
argument_list|)
expr_stmt|;
specifier|static
name|QJNIObjectPrivate
name|fromString
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
function_decl|;
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|isClassAvailable
parameter_list|(
specifier|const
name|char
modifier|*
name|className
parameter_list|)
function_decl|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|jobject
name|object
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_jobject
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QJNIObjectPrivate
operator|&
name|operator
operator|=
operator|(
name|T
name|o
operator|)
block|{
name|jobject
name|jobj
operator|=
name|static_cast
operator|<
name|jobject
operator|>
operator|(
name|o
operator|)
block|;
if|if
condition|(
operator|!
name|isSameObject
argument_list|(
name|jobj
argument_list|)
condition|)
block|{
name|d
operator|=
name|QSharedPointer
operator|<
name|QJNIObjectData
operator|>
operator|::
name|create
argument_list|()
expr_stmt|;
if|if
condition|(
name|jobj
condition|)
block|{
name|QJNIEnvironmentPrivate
name|env
decl_stmt|;
name|d
operator|->
name|m_jobject
operator|=
name|env
operator|->
name|NewGlobalRef
argument_list|(
name|jobj
argument_list|)
expr_stmt|;
name|jclass
name|objectClass
init|=
name|env
operator|->
name|GetObjectClass
argument_list|(
name|jobj
argument_list|)
decl_stmt|;
name|d
operator|->
name|m_jclass
operator|=
name|static_cast
operator|<
name|jclass
operator|>
operator|(
name|env
operator|->
name|NewGlobalRef
argument_list|(
name|objectClass
argument_list|)
operator|)
expr_stmt|;
name|env
operator|->
name|DeleteLocalRef
argument_list|(
name|objectClass
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|*
name|this
return|;
block|}
comment|// This function takes ownership of the jobject and releases the local ref. before returning.
specifier|static
name|QJNIObjectPrivate
name|fromLocalRef
parameter_list|(
name|jobject
name|lref
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|QAndroidJniObject
decl_stmt|;
struct|struct
name|QVaListPrivate
block|{
name|operator
name|va_list
operator|&
operator|(
operator|)
specifier|const
block|{
return|return
name|m_args
return|;
block|}
name|va_list
modifier|&
name|m_args
decl_stmt|;
block|}
struct|;
name|QJNIObjectPrivate
argument_list|(
specifier|const
name|char
operator|*
name|className
argument_list|,
specifier|const
name|char
operator|*
name|sig
argument_list|,
specifier|const
name|QVaListPrivate
operator|&
name|args
argument_list|)
expr_stmt|;
name|QJNIObjectPrivate
argument_list|(
argument|jclass clazz
argument_list|,
argument|const char *sig
argument_list|,
argument|const QVaListPrivate&args
argument_list|)
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|callMethodV
argument_list|(
argument|const char *methodName
argument_list|,
argument|const char *sig
argument_list|,
argument|va_list args
argument_list|)
specifier|const
expr_stmt|;
name|QJNIObjectPrivate
name|callObjectMethodV
argument_list|(
specifier|const
name|char
operator|*
name|methodName
argument_list|,
specifier|const
name|char
operator|*
name|sig
argument_list|,
name|va_list
name|args
argument_list|)
decl|const
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|callStaticMethodV
argument_list|(
argument|const char *className
argument_list|,
argument|const char *methodName
argument_list|,
argument|const char *sig
argument_list|,
argument|va_list args
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|T
name|callStaticMethodV
argument_list|(
argument|jclass clazz
argument_list|,
argument|const char *methodName
argument_list|,
argument|const char *sig
argument_list|,
argument|va_list args
argument_list|)
expr_stmt|;
specifier|static
name|QJNIObjectPrivate
name|callStaticObjectMethodV
parameter_list|(
specifier|const
name|char
modifier|*
name|className
parameter_list|,
specifier|const
name|char
modifier|*
name|methodName
parameter_list|,
specifier|const
name|char
modifier|*
name|sig
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
specifier|static
name|QJNIObjectPrivate
name|callStaticObjectMethodV
parameter_list|(
name|jclass
name|clazz
parameter_list|,
specifier|const
name|char
modifier|*
name|methodName
parameter_list|,
specifier|const
name|char
modifier|*
name|sig
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
name|bool
name|isSameObject
argument_list|(
name|jobject
name|obj
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isSameObject
argument_list|(
specifier|const
name|QJNIObjectPrivate
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJNIObjectPrivate
operator|&
operator|,
specifier|const
name|QJNIObjectPrivate
operator|&
operator|)
expr_stmt|;
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJNIObjectPrivate
operator|&
operator|,
specifier|const
name|QJNIObjectPrivate
operator|&
operator|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJNIObjectPrivate
operator|&
operator|,
name|T
operator|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJNIObjectPrivate
operator|&
operator|,
name|T
operator|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|bool
name|operator
operator|!=
operator|(
name|T
operator|,
specifier|const
name|QJNIObjectPrivate
operator|&
operator|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|bool
name|operator
operator|==
operator|(
name|T
operator|,
specifier|const
name|QJNIObjectPrivate
operator|&
operator|)
expr_stmt|;
name|QSharedPointer
operator|<
name|QJNIObjectData
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJNIObjectPrivate
operator|&
name|obj1
operator|,
specifier|const
name|QJNIObjectPrivate
operator|&
name|obj2
operator|)
block|{
return|return
name|obj1
operator|.
name|isSameObject
argument_list|(
name|obj2
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJNIObjectPrivate
operator|&
name|obj1
operator|,
specifier|const
name|QJNIObjectPrivate
operator|&
name|obj2
operator|)
block|{
return|return
operator|!
name|obj1
operator|.
name|isSameObject
argument_list|(
name|obj2
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QJNIObjectPrivate
operator|&
name|obj1
operator|,
name|T
name|obj2
operator|)
block|{
return|return
name|obj1
operator|.
name|isSameObject
argument_list|(
name|static_cast
operator|<
name|jobject
operator|>
operator|(
name|obj2
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|T
name|obj1
operator|,
specifier|const
name|QJNIObjectPrivate
operator|&
name|obj2
operator|)
block|{
return|return
name|obj2
operator|.
name|isSameObject
argument_list|(
name|static_cast
operator|<
name|jobject
operator|>
operator|(
name|obj1
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QJNIObjectPrivate
operator|&
name|obj1
operator|,
name|T
name|obj2
operator|)
block|{
return|return
operator|!
name|obj1
operator|.
name|isSameObject
argument_list|(
name|obj2
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|T
name|obj1
operator|,
specifier|const
name|QJNIObjectPrivate
operator|&
name|obj2
operator|)
block|{
return|return
operator|!
name|obj2
operator|.
name|isSameObject
argument_list|(
name|obj1
argument_list|)
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QJNI_P_H
end_comment
end_unit
