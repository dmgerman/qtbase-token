begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qjnihelpers_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|g_javaVM
specifier|static
name|JavaVM
modifier|*
name|g_javaVM
init|=
name|Q_NULLPTR
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|g_jActivity
specifier|static
name|jobject
name|g_jActivity
init|=
name|Q_NULLPTR
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|exceptionCheck
specifier|static
specifier|inline
name|bool
name|exceptionCheck
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|)
block|{
if|if
condition|(
name|env
operator|->
name|ExceptionCheck
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG
name|env
operator|->
name|ExceptionDescribe
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// QT_DEBUG
name|env
operator|->
name|ExceptionClear
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|initJNI
name|jint
name|QtAndroidPrivate
operator|::
name|initJNI
parameter_list|(
name|JavaVM
modifier|*
name|vm
parameter_list|,
name|JNIEnv
modifier|*
name|env
parameter_list|)
block|{
name|jclass
name|jQtNative
init|=
name|env
operator|->
name|FindClass
argument_list|(
literal|"org/qtproject/qt5/android/QtNative"
argument_list|)
decl_stmt|;
if|if
condition|(
name|env
operator|->
name|ExceptionCheck
argument_list|()
condition|)
block|{
name|env
operator|->
name|ExceptionClear
argument_list|()
expr_stmt|;
return|return
name|JNI_ERR
return|;
block|}
name|jmethodID
name|activityMethodID
init|=
name|env
operator|->
name|GetStaticMethodID
argument_list|(
name|jQtNative
argument_list|,
literal|"activity"
argument_list|,
literal|"()Landroid/app/Activity;"
argument_list|)
decl_stmt|;
if|if
condition|(
name|exceptionCheck
argument_list|(
name|env
argument_list|)
condition|)
return|return
name|JNI_ERR
return|;
name|jobject
name|activity
init|=
name|env
operator|->
name|CallStaticObjectMethod
argument_list|(
name|jQtNative
argument_list|,
name|activityMethodID
argument_list|)
decl_stmt|;
if|if
condition|(
name|exceptionCheck
argument_list|(
name|env
argument_list|)
condition|)
return|return
name|JNI_ERR
return|;
name|g_jActivity
operator|=
name|env
operator|->
name|NewGlobalRef
argument_list|(
name|activity
argument_list|)
expr_stmt|;
name|g_javaVM
operator|=
name|vm
expr_stmt|;
return|return
name|JNI_OK
return|;
block|}
end_function
begin_function
DECL|function|activity
name|jobject
name|QtAndroidPrivate
operator|::
name|activity
parameter_list|()
block|{
return|return
name|g_jActivity
return|;
block|}
end_function
begin_function
DECL|function|javaVM
name|JavaVM
modifier|*
name|QtAndroidPrivate
operator|::
name|javaVM
parameter_list|()
block|{
return|return
name|g_javaVM
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit