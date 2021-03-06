begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|<QSettings>
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
parameter_list|,
specifier|const
name|QSettings
modifier|*
name|s
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
name|addResult
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
name|bool
name|reportProduced
parameter_list|()
function_decl|;
name|int
name|numberOfMismatches
parameter_list|()
function_decl|;
name|QString
name|summary
parameter_list|()
function_decl|;
name|QString
name|filePath
parameter_list|()
function_decl|;
name|QString
name|writeResultsXmlFiles
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
specifier|static
name|QString
name|generateThumbnail
parameter_list|(
specifier|const
name|QString
modifier|&
name|image
parameter_list|,
specifier|const
name|QString
modifier|&
name|rootDir
init|=
name|QString
argument_list|()
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
name|void
name|updateLatestPointer
parameter_list|()
function_decl|;
name|void
name|computeStats
parameter_list|()
function_decl|;
name|bool
name|initialized
decl_stmt|;
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
name|baseDir
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
specifier|const
name|QSettings
modifier|*
name|settings
decl_stmt|;
typedef|typedef
name|QMap
operator|<
name|ImageItem
operator|::
name|ItemStatus
operator|,
name|int
operator|>
name|FuncStats
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|FuncStats
operator|>
name|stats
expr_stmt|;
name|bool
name|hasStats
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
