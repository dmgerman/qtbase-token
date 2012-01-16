begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|REPORT_H
end_ifndef
begin_define
DECL|macro|REPORT_H
define|#
directive|define
name|REPORT_H
end_define
begin_include
include|#
directive|include
file|"baselineprotocol.h"
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QTextStream>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_decl_stmt
DECL|variable|BaselineHandler
name|class
name|BaselineHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Report
block|{
name|public
label|:
name|Report
argument_list|()
expr_stmt|;
operator|~
name|Report
argument_list|()
expr_stmt|;
name|void
name|init
parameter_list|(
specifier|const
name|BaselineHandler
modifier|*
name|h
parameter_list|,
specifier|const
name|QString
modifier|&
name|r
parameter_list|,
specifier|const
name|PlatformInfo
modifier|&
name|p
parameter_list|)
function_decl|;
name|void
name|addItems
parameter_list|(
specifier|const
name|ImageItemList
modifier|&
name|items
parameter_list|)
function_decl|;
name|void
name|addMismatch
parameter_list|(
specifier|const
name|ImageItem
modifier|&
name|item
parameter_list|)
function_decl|;
name|void
name|end
parameter_list|()
function_decl|;
name|QString
name|filePath
parameter_list|()
function_decl|;
specifier|static
name|void
name|handleCGIQuery
parameter_list|(
specifier|const
name|QString
modifier|&
name|query
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|write
parameter_list|()
function_decl|;
name|void
name|writeFunctionResults
parameter_list|(
specifier|const
name|ImageItemList
modifier|&
name|list
parameter_list|)
function_decl|;
name|void
name|writeItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|baseline
parameter_list|,
specifier|const
name|QString
modifier|&
name|rendered
parameter_list|,
specifier|const
name|ImageItem
modifier|&
name|item
parameter_list|,
specifier|const
name|QString
modifier|&
name|itemFile
parameter_list|,
specifier|const
name|QString
modifier|&
name|ctx
parameter_list|,
specifier|const
name|QString
modifier|&
name|misCtx
parameter_list|,
specifier|const
name|QString
modifier|&
name|metadata
parameter_list|)
function_decl|;
name|void
name|writeHeader
parameter_list|()
function_decl|;
name|void
name|writeFooter
parameter_list|()
function_decl|;
name|QString
name|generateCompared
parameter_list|(
specifier|const
name|QString
modifier|&
name|baseline
parameter_list|,
specifier|const
name|QString
modifier|&
name|rendered
parameter_list|,
name|bool
name|fuzzy
init|=
name|false
parameter_list|)
function_decl|;
name|QString
name|generateThumbnail
parameter_list|(
specifier|const
name|QString
modifier|&
name|image
parameter_list|)
function_decl|;
specifier|const
name|BaselineHandler
modifier|*
name|handler
decl_stmt|;
name|QString
name|runId
decl_stmt|;
name|PlatformInfo
name|plat
decl_stmt|;
name|QString
name|rootDir
decl_stmt|;
name|QString
name|reportDir
decl_stmt|;
name|QString
name|path
decl_stmt|;
name|QStringList
name|testFunctions
decl_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|ImageItemList
operator|>
name|itemLists
expr_stmt|;
name|bool
name|written
decl_stmt|;
name|int
name|numItems
decl_stmt|;
name|int
name|numMismatches
decl_stmt|;
name|QTextStream
name|out
decl_stmt|;
name|bool
name|hasOverride
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
comment|// REPORT_H
end_comment
end_unit
