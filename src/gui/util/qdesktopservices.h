begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDESKTOPSERVICES_H
end_ifndef
begin_define
DECL|macro|QDESKTOPSERVICES_H
define|#
directive|define
name|QDESKTOPSERVICES_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstandardpaths.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_DESKTOPSERVICES
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDesktopServices
block|{
name|public
label|:
specifier|static
name|bool
name|openUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
specifier|static
name|void
name|setUrlHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|scheme
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|method
parameter_list|)
function_decl|;
specifier|static
name|void
name|unsetUrlHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|scheme
parameter_list|)
function_decl|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
comment|//Must match QStandardPaths::StandardLocation
enum|enum
name|StandardLocation
block|{
name|DesktopLocation
block|,
name|DocumentsLocation
block|,
name|FontsLocation
block|,
name|ApplicationsLocation
block|,
name|MusicLocation
block|,
name|MoviesLocation
block|,
name|PicturesLocation
block|,
name|TempLocation
block|,
name|HomeLocation
block|,
name|DataLocation
block|,
name|CacheLocation
block|}
enum|;
name|QT_DEPRECATED
specifier|static
name|QString
name|storageLocation
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
return|return
name|storageLocationImpl
argument_list|(
name|static_cast
operator|<
name|QStandardPaths
operator|::
name|StandardLocation
operator|>
operator|(
name|type
operator|)
argument_list|)
return|;
block|}
name|QT_DEPRECATED
specifier|static
name|QString
name|displayName
parameter_list|(
name|StandardLocation
name|type
parameter_list|)
block|{
return|return
name|QStandardPaths
operator|::
name|displayName
argument_list|(
name|static_cast
operator|<
name|QStandardPaths
operator|::
name|StandardLocation
operator|>
operator|(
name|type
operator|)
argument_list|)
return|;
block|}
endif|#
directive|endif
name|private
label|:
specifier|static
name|QString
name|storageLocationImpl
argument_list|(
name|QStandardPaths
operator|::
name|StandardLocation
name|type
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DESKTOPSERVICES
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDESKTOPSERVICES_H
end_comment
end_unit
