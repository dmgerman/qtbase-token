begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRESOURCE_H
end_ifndef
begin_define
DECL|macro|QRESOURCE_H
define|#
directive|define
name|QRESOURCE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QResourcePrivate
name|class
name|QResourcePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QResource
block|{
name|public
label|:
name|QResource
argument_list|(
specifier|const
name|QString
operator|&
name|file
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QLocale
operator|&
name|locale
operator|=
name|QLocale
argument_list|()
argument_list|)
expr_stmt|;
operator|~
name|QResource
argument_list|()
expr_stmt|;
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|absoluteFilePath
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLocale
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|locale
parameter_list|)
function_decl|;
name|QLocale
name|locale
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isCompressed
argument_list|()
specifier|const
expr_stmt|;
name|qint64
name|size
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|uchar
operator|*
name|data
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|void
name|addSearchPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|searchPaths
parameter_list|()
function_decl|;
specifier|static
name|bool
name|registerResource
parameter_list|(
specifier|const
name|QString
modifier|&
name|rccFilename
parameter_list|,
specifier|const
name|QString
modifier|&
name|resourceRoot
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|bool
name|unregisterResource
parameter_list|(
specifier|const
name|QString
modifier|&
name|rccFilename
parameter_list|,
specifier|const
name|QString
modifier|&
name|resourceRoot
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|bool
name|registerResource
parameter_list|(
specifier|const
name|uchar
modifier|*
name|rccData
parameter_list|,
specifier|const
name|QString
modifier|&
name|resourceRoot
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|bool
name|unregisterResource
parameter_list|(
specifier|const
name|uchar
modifier|*
name|rccData
parameter_list|,
specifier|const
name|QString
modifier|&
name|resourceRoot
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|protected
label|:
name|friend
name|class
name|QResourceFileEngine
decl_stmt|;
name|friend
name|class
name|QResourceFileEngineIterator
decl_stmt|;
name|bool
name|isDir
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isFile
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isDir
argument_list|()
return|;
block|}
name|QStringList
name|children
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|QScopedPointer
operator|<
name|QResourcePrivate
operator|>
name|d_ptr
expr_stmt|;
name|private
label|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QResource
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QRESOURCE_H
end_comment
end_unit
