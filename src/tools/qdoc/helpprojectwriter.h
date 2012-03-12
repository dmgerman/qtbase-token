begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HELPPROJECTWRITER_H
end_ifndef
begin_define
DECL|macro|HELPPROJECTWRITER_H
define|#
directive|define
name|HELPPROJECTWRITER_H
end_define
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QXmlStreamReader>
end_include
begin_include
include|#
directive|include
file|<QXmlStreamWriter>
end_include
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Tree
name|class
name|Tree
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QString
DECL|typedef|QStringNodePair
typedef|typedef
name|QPair
operator|<
name|QString
operator|,
specifier|const
name|Node
operator|*
operator|>
name|QStringNodePair
expr_stmt|;
end_typedef
begin_struct
DECL|struct|SubProject
struct|struct
name|SubProject
block|{
DECL|member|title
name|QString
name|title
decl_stmt|;
DECL|member|indexTitle
name|QString
name|indexTitle
decl_stmt|;
DECL|member|Type
DECL|member|selectors
name|QHash
operator|<
name|Node
operator|::
name|Type
operator|,
name|QSet
operator|<
name|FakeNode
operator|::
name|SubType
operator|>
expr|>
name|selectors
expr_stmt|;
DECL|member|sortPages
name|bool
name|sortPages
decl_stmt|;
DECL|member|type
name|QString
name|type
decl_stmt|;
DECL|member|QString
DECL|member|nodes
name|QHash
operator|<
name|QString
operator|,
specifier|const
name|Node
operator|*
operator|>
name|nodes
expr_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|HelpProject
struct|struct
name|HelpProject
block|{
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|helpNamespace
name|QString
name|helpNamespace
decl_stmt|;
DECL|member|virtualFolder
name|QString
name|virtualFolder
decl_stmt|;
DECL|member|fileName
name|QString
name|fileName
decl_stmt|;
DECL|member|indexRoot
name|QString
name|indexRoot
decl_stmt|;
DECL|member|indexTitle
name|QString
name|indexTitle
decl_stmt|;
DECL|member|keywords
name|QList
operator|<
name|QStringList
operator|>
name|keywords
expr_stmt|;
DECL|member|files
name|QSet
operator|<
name|QString
operator|>
name|files
expr_stmt|;
DECL|member|extraFiles
name|QSet
operator|<
name|QString
operator|>
name|extraFiles
expr_stmt|;
DECL|member|filterAttributes
name|QSet
operator|<
name|QString
operator|>
name|filterAttributes
expr_stmt|;
DECL|member|QString
DECL|member|customFilters
name|QHash
operator|<
name|QString
operator|,
name|QSet
operator|<
name|QString
operator|>
expr|>
name|customFilters
expr_stmt|;
DECL|member|excluded
name|QSet
operator|<
name|QString
operator|>
name|excluded
expr_stmt|;
DECL|member|QString
DECL|member|subprojects
name|QMap
operator|<
name|QString
operator|,
name|SubProject
operator|>
name|subprojects
expr_stmt|;
DECL|member|Node
DECL|member|memberStatus
name|QHash
operator|<
specifier|const
name|Node
operator|*
operator|,
name|QSet
operator|<
name|Node
operator|::
name|Status
operator|>
expr|>
name|memberStatus
expr_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|HelpProjectWriter
block|{
name|public
label|:
name|HelpProjectWriter
argument_list|(
specifier|const
name|Config
operator|&
name|config
argument_list|,
specifier|const
name|QString
operator|&
name|defaultFileName
argument_list|)
expr_stmt|;
name|void
name|addExtraFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|file
parameter_list|)
function_decl|;
name|void
name|addExtraFiles
argument_list|(
specifier|const
name|QSet
operator|<
name|QString
operator|>
operator|&
name|files
argument_list|)
decl_stmt|;
name|void
name|generate
parameter_list|(
specifier|const
name|Tree
modifier|*
name|tre
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|generateProject
parameter_list|(
name|HelpProject
modifier|&
name|project
parameter_list|)
function_decl|;
name|void
name|generateSections
parameter_list|(
name|HelpProject
modifier|&
name|project
parameter_list|,
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|bool
name|generateSection
parameter_list|(
name|HelpProject
modifier|&
name|project
parameter_list|,
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|QStringList
name|keywordDetails
argument_list|(
specifier|const
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeNode
parameter_list|(
name|HelpProject
modifier|&
name|project
parameter_list|,
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|readSelectors
parameter_list|(
name|SubProject
modifier|&
name|subproject
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|selectors
parameter_list|)
function_decl|;
specifier|const
name|Tree
modifier|*
name|tree
decl_stmt|;
name|QString
name|outputDir
decl_stmt|;
name|QList
operator|<
name|HelpProject
operator|>
name|projects
expr_stmt|;
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
end_unit
