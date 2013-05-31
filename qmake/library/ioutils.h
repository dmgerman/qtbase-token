begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|IOUTILS_H
end_ifndef
begin_define
DECL|macro|IOUTILS_H
define|#
directive|define
name|IOUTILS_H
end_define
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QMakeInternal
block|{
comment|/*!   This class provides replacement functionality for QFileInfo, QFile& QDir,   as these are abysmally slow. */
name|class
name|IoUtils
block|{
name|public
label|:
enum|enum
name|FileType
block|{
name|FileNotFound
init|=
literal|0
block|,
name|FileIsRegular
init|=
literal|1
block|,
name|FileIsDir
init|=
literal|2
block|}
enum|;
specifier|static
name|FileType
name|fileType
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|bool
name|exists
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
return|return
name|fileType
argument_list|(
name|fileName
argument_list|)
operator|!=
name|FileNotFound
return|;
block|}
specifier|static
name|bool
name|isRelativePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isAbsolutePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
return|return
operator|!
name|isRelativePath
argument_list|(
name|fileName
argument_list|)
return|;
block|}
specifier|static
name|QStringRef
name|pathName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
comment|// Requires normalized path
specifier|static
name|QStringRef
name|fileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
comment|// Requires normalized path
specifier|static
name|QString
name|resolvePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|baseDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|QString
name|shellQuoteUnix
parameter_list|(
specifier|const
name|QString
modifier|&
name|arg
parameter_list|)
function_decl|;
specifier|static
name|QString
name|shellQuoteWin
parameter_list|(
specifier|const
name|QString
modifier|&
name|arg
parameter_list|)
function_decl|;
specifier|static
name|QString
name|shellQuote
parameter_list|(
specifier|const
name|QString
modifier|&
name|arg
parameter_list|)
ifdef|#
directive|ifdef
name|Q_OS_UNIX
block|{
return|return
name|shellQuoteUnix
argument_list|(
name|arg
argument_list|)
return|;
block|}
else|#
directive|else
block|{
return|return
name|shellQuoteWin
argument_list|(
name|arg
argument_list|)
return|;
block|}
endif|#
directive|endif
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace ProFileEvaluatorInternal
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// IOUTILS_H
end_comment
end_unit
