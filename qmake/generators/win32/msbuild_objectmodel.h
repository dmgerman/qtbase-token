begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MSBUILD_OBJECTMODEL_H
end_ifndef
begin_define
DECL|macro|MSBUILD_OBJECTMODEL_H
define|#
directive|define
name|MSBUILD_OBJECTMODEL_H
end_define
begin_include
include|#
directive|include
file|"project.h"
end_include
begin_include
include|#
directive|include
file|"xmloutput.h"
end_include
begin_include
include|#
directive|include
file|"msvc_objectmodel.h"
end_include
begin_include
include|#
directive|include
file|<qatomic.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// Tree& Flat view of files --------------------------------------------------
name|class
name|XNode
block|{
name|public
label|:
name|virtual
operator|~
name|XNode
argument_list|()
block|{ }
name|void
name|addElement
argument_list|(
argument|const VCFilterFile&file
argument_list|)
block|{
name|addElement
argument_list|(
name|file
operator|.
name|file
argument_list|,
name|file
argument_list|)
block|;     }
name|virtual
name|void
name|addElement
argument_list|(
specifier|const
name|QString
operator|&
name|filepath
argument_list|,
specifier|const
name|VCFilterFile
operator|&
name|allInfo
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|removeElements
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|generateXML
parameter_list|(
name|XmlOutput
modifier|&
name|xml
parameter_list|,
name|XmlOutput
modifier|&
name|xmlFilter
parameter_list|,
specifier|const
name|QString
modifier|&
name|tagName
parameter_list|,
name|VCProject
modifier|&
name|tool
parameter_list|,
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|hasElements
parameter_list|()
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|XTreeNode
range|:
name|public
name|XNode
block|{
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|XTreeNode
operator|*
operator|>
name|ChildrenMap
expr_stmt|;
name|VCFilterFile
name|info
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ChildrenMap
name|children
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_expr_stmt
name|virtual
operator|~
name|XTreeNode
argument_list|()
block|{
name|removeElements
argument_list|()
block|; }
name|int
name|pathIndex
argument_list|(
argument|const QString&filepath
argument_list|)
block|{
name|int
name|Windex
operator|=
name|filepath
operator|.
name|indexOf
argument_list|(
literal|"\\"
argument_list|)
block|;
name|int
name|Uindex
operator|=
name|filepath
operator|.
name|indexOf
argument_list|(
literal|"/"
argument_list|)
block|;
if|if
condition|(
name|Windex
operator|!=
operator|-
literal|1
operator|&&
name|Uindex
operator|!=
operator|-
literal|1
condition|)
return|return
name|qMin
argument_list|(
name|Windex
argument_list|,
name|Uindex
argument_list|)
return|;
elseif|else
if|if
condition|(
name|Windex
operator|!=
operator|-
literal|1
condition|)
return|return
name|Windex
return|;
end_expr_stmt
begin_return
return|return
name|Uindex
return|;
end_return
begin_macro
unit|}      void
name|addElement
argument_list|(
argument|const QString&filepath
argument_list|,
argument|const VCFilterFile&allInfo
argument_list|)
end_macro
begin_block
block|{
name|QString
name|newNodeName
parameter_list|(
name|filepath
parameter_list|)
function_decl|;
name|int
name|index
init|=
name|pathIndex
argument_list|(
name|filepath
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
name|newNodeName
operator|=
name|filepath
operator|.
name|left
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|XTreeNode
modifier|*
name|n
init|=
name|children
operator|.
name|value
argument_list|(
name|newNodeName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|n
condition|)
block|{
name|n
operator|=
name|new
name|XTreeNode
expr_stmt|;
name|n
operator|->
name|info
operator|=
name|allInfo
expr_stmt|;
name|children
operator|.
name|insert
argument_list|(
name|newNodeName
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
name|n
operator|->
name|addElement
argument_list|(
name|filepath
operator|.
name|mid
argument_list|(
name|index
operator|+
literal|1
argument_list|)
argument_list|,
name|allInfo
argument_list|)
expr_stmt|;
block|}
end_block
begin_function
name|void
name|removeElements
parameter_list|()
block|{
name|ChildrenMap
operator|::
name|ConstIterator
name|it
operator|=
name|children
operator|.
name|constBegin
argument_list|()
expr_stmt|;
name|ChildrenMap
operator|::
name|ConstIterator
name|end
operator|=
name|children
operator|.
name|constEnd
argument_list|()
expr_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|end
condition|;
name|it
operator|++
control|)
block|{
operator|(
operator|*
name|it
operator|)
operator|->
name|removeElements
argument_list|()
expr_stmt|;
name|delete
name|it
operator|.
name|value
parameter_list|()
function_decl|;
block|}
name|children
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|generateXML
parameter_list|(
name|XmlOutput
modifier|&
name|xml
parameter_list|,
name|XmlOutput
modifier|&
name|xmlFilter
parameter_list|,
specifier|const
name|QString
modifier|&
name|tagName
parameter_list|,
name|VCProject
modifier|&
name|tool
parameter_list|,
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
function_decl|;
end_function_decl
begin_function
name|bool
name|hasElements
parameter_list|()
block|{
return|return
name|children
operator|.
name|size
argument_list|()
operator|!=
literal|0
return|;
block|}
end_function
begin_decl_stmt
unit|};
name|class
name|XFlatNode
range|:
name|public
name|XNode
block|{
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|VCFilterFile
operator|>
name|ChildrenMapFlat
expr_stmt|;
name|ChildrenMapFlat
name|children
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_expr_stmt
name|virtual
operator|~
name|XFlatNode
argument_list|()
block|{
name|removeElements
argument_list|()
block|; }
name|int
name|pathIndex
argument_list|(
argument|const QString&filepath
argument_list|)
block|{
name|int
name|Windex
operator|=
name|filepath
operator|.
name|lastIndexOf
argument_list|(
literal|"\\"
argument_list|)
block|;
name|int
name|Uindex
operator|=
name|filepath
operator|.
name|lastIndexOf
argument_list|(
literal|"/"
argument_list|)
block|;
if|if
condition|(
name|Windex
operator|!=
operator|-
literal|1
operator|&&
name|Uindex
operator|!=
operator|-
literal|1
condition|)
return|return
name|qMax
argument_list|(
name|Windex
argument_list|,
name|Uindex
argument_list|)
return|;
elseif|else
if|if
condition|(
name|Windex
operator|!=
operator|-
literal|1
condition|)
return|return
name|Windex
return|;
end_expr_stmt
begin_return
return|return
name|Uindex
return|;
end_return
begin_macro
unit|}      void
name|addElement
argument_list|(
argument|const QString&filepath
argument_list|,
argument|const VCFilterFile&allInfo
argument_list|)
end_macro
begin_block
block|{
name|QString
name|newKey
parameter_list|(
name|filepath
parameter_list|)
function_decl|;
name|int
name|index
init|=
name|pathIndex
argument_list|(
name|filepath
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
name|newKey
operator|=
name|filepath
operator|.
name|mid
argument_list|(
name|index
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|// Key designed to sort files with same
comment|// name in different paths correctly
name|children
operator|.
name|insert
argument_list|(
name|newKey
operator|+
literal|"\0"
operator|+
name|allInfo
operator|.
name|file
argument_list|,
name|allInfo
argument_list|)
expr_stmt|;
block|}
end_block
begin_function
name|void
name|removeElements
parameter_list|()
block|{
name|children
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function_decl
name|void
name|generateXML
parameter_list|(
name|XmlOutput
modifier|&
name|xml
parameter_list|,
name|XmlOutput
modifier|&
name|xmlFilter
parameter_list|,
specifier|const
name|QString
modifier|&
name|tagName
parameter_list|,
name|VCProject
modifier|&
name|proj
parameter_list|,
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
function_decl|;
end_function_decl
begin_function
name|bool
name|hasElements
parameter_list|()
block|{
return|return
name|children
operator|.
name|size
argument_list|()
operator|!=
literal|0
return|;
block|}
end_function
begin_decl_stmt
unit|};
name|class
name|VCXProjectWriter
range|:
name|public
name|VCProjectWriter
block|{
name|public
operator|:
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
name|VCProjectSingleConfig
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
name|VCProject
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCCLCompilerTool
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCLinkerTool
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCMIDLTool
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCCustomBuildTool
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCLibrarianTool
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCResourceCompilerTool
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCEventTool
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCDeploymentTool
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
specifier|const
name|VCConfiguration
operator|&
argument_list|)
block|;
name|void
name|write
argument_list|(
name|XmlOutput
operator|&
argument_list|,
name|VCFilter
operator|&
argument_list|)
block|;
name|private
operator|:
specifier|static
name|void
name|addFilters
argument_list|(
name|VCProject
operator|&
name|project
argument_list|,
name|XmlOutput
operator|&
name|xmlFilter
argument_list|,
specifier|const
name|QString
operator|&
name|filterName
argument_list|)
block|;
specifier|static
name|void
name|outputFilter
argument_list|(
name|VCProject
operator|&
name|project
argument_list|,
name|XmlOutput
operator|&
name|xml
argument_list|,
name|XmlOutput
operator|&
name|xmlFilter
argument_list|,
specifier|const
name|QString
operator|&
name|filtername
argument_list|)
block|;
specifier|static
name|void
name|outputFileConfigs
argument_list|(
name|VCProject
operator|&
name|project
argument_list|,
name|XmlOutput
operator|&
name|xml
argument_list|,
name|XmlOutput
operator|&
name|xmlFilter
argument_list|,
specifier|const
name|VCFilterFile
operator|&
name|info
argument_list|,
specifier|const
name|QString
operator|&
name|filtername
argument_list|)
block|;
specifier|static
name|bool
name|outputFileConfig
argument_list|(
argument|VCFilter&filter
argument_list|,
argument|XmlOutput&xml
argument_list|,
argument|XmlOutput&xmlFilter
argument_list|,
argument|const QString&filename
argument_list|,
argument|const QString&filtername
argument_list|,
argument|bool fileAllreadyAdded
argument_list|)
block|;
name|friend
name|class
name|XTreeNode
block|;
name|friend
name|class
name|XFlatNode
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MSVC_OBJECTMODEL_H
end_comment
end_unit
