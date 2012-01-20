begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QResourcePrivate
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QResource
decl_stmt|{ public:     QResource(const QString&file=QString(
end_function
begin_operator
unit|)
operator|,
end_operator
begin_decl_stmt
specifier|const
name|QLocale
modifier|&
name|locale
init|=
name|QLocale
argument_list|()
init|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|~
name|QResource
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|absoluteFilePath
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setLocale
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|locale
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QLocale
name|locale
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isCompressed
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qint64
name|size
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|uchar
operator|*
name|data
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
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
end_function_decl
begin_function_decl
specifier|static
name|QStringList
name|searchPaths
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
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
end_function_decl
begin_function_decl
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
end_function_decl
begin_function_decl
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
end_function_decl
begin_function_decl
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
end_function_decl
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|friend
name|class
name|QResourceFileEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QResourceFileEngineIterator
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|bool
name|isDir
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
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
end_expr_stmt
begin_expr_stmt
name|QStringList
name|children
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QScopedPointer
operator|<
name|QResourcePrivate
operator|>
name|d_ptr
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QResource
argument_list|)
end_macro
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QRESOURCE_H
end_comment
end_unit
