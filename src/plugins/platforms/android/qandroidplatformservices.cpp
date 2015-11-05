begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformservices.h"
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QMimeDatabase>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qjni_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QAndroidPlatformServices
name|QAndroidPlatformServices
operator|::
name|QAndroidPlatformServices
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|openUrl
name|bool
name|QAndroidPlatformServices
operator|::
name|openUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|theUrl
parameter_list|)
block|{
name|QString
name|mime
decl_stmt|;
name|QUrl
name|url
argument_list|(
name|theUrl
argument_list|)
decl_stmt|;
comment|// if the file is local, we need to pass the MIME type, otherwise Android
comment|// does not start an Intent to view this file
if|if
condition|(
operator|(
name|url
operator|.
name|scheme
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|QFile
operator|::
name|exists
argument_list|(
name|url
operator|.
name|path
argument_list|()
argument_list|)
operator|)
operator|||
name|url
operator|.
name|isLocalFile
argument_list|()
condition|)
block|{
comment|// a real URL including the scheme is needed, else the Intent can not be started
name|url
operator|.
name|setScheme
argument_list|(
name|QLatin1String
argument_list|(
literal|"file"
argument_list|)
argument_list|)
expr_stmt|;
name|QMimeDatabase
name|mimeDb
decl_stmt|;
name|mime
operator|=
name|mimeDb
operator|.
name|mimeTypeForUrl
argument_list|(
name|url
argument_list|)
operator|.
name|name
argument_list|()
expr_stmt|;
block|}
name|QJNIObjectPrivate
name|urlString
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
name|QJNIObjectPrivate
name|mimeString
init|=
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|mime
argument_list|)
decl_stmt|;
return|return
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
name|QtAndroid
operator|::
name|applicationClass
argument_list|()
argument_list|,
literal|"openURL"
argument_list|,
literal|"(Ljava/lang/String;Ljava/lang/String;)Z"
argument_list|,
name|urlString
operator|.
name|object
argument_list|()
argument_list|,
name|mimeString
operator|.
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|openDocument
name|bool
name|QAndroidPlatformServices
operator|::
name|openDocument
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|openUrl
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|desktopEnvironment
name|QByteArray
name|QAndroidPlatformServices
operator|::
name|desktopEnvironment
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
literal|"Android"
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
