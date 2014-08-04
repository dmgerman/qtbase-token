begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDOCDATABASE_H
end_ifndef
begin_define
DECL|macro|QDOCDATABASE_H
define|#
directive|define
name|QDOCDATABASE_H
end_define
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|"tree.h"
end_include
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_include
include|#
directive|include
file|"text.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QString
DECL|typedef|NodeMapMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|NodeMap
operator|>
name|NodeMapMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|NodeMultiMapMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|NodeMultiMap
operator|>
name|NodeMultiMapMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QDocMultiMap
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|Node
operator|*
operator|>
name|QDocMultiMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|Text
DECL|typedef|TextToNodeMap
typedef|typedef
name|QMap
operator|<
name|Text
operator|,
specifier|const
name|Node
operator|*
operator|>
name|TextToNodeMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|CollectionList
typedef|typedef
name|QList
operator|<
name|CollectionNode
operator|*
operator|>
name|CollectionList
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|variable|Atom
name|class
name|Atom
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Generator
name|class
name|Generator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDocDatabase
name|class
name|QDocDatabase
decl_stmt|;
end_decl_stmt
begin_enum
DECL|enum|FindFlag
enum|enum
name|FindFlag
block|{
DECL|enumerator|SearchBaseClasses
name|SearchBaseClasses
init|=
literal|0x1
block|,
DECL|enumerator|SearchEnumValues
name|SearchEnumValues
init|=
literal|0x2
block|,
DECL|enumerator|NonFunction
name|NonFunction
init|=
literal|0x4
block|}
enum|;
end_enum
begin_decl_stmt
name|class
name|QDocForest
block|{
name|public
label|:
name|friend
name|class
name|QDocDatabase
decl_stmt|;
name|QDocForest
argument_list|(
name|QDocDatabase
operator|*
name|qdb
argument_list|)
operator|:
name|qdb_
argument_list|(
name|qdb
argument_list|)
operator|,
name|primaryTree_
argument_list|(
literal|0
argument_list|)
operator|,
name|currentIndex_
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|QDocForest
argument_list|()
expr_stmt|;
name|NamespaceNode
modifier|*
name|firstRoot
parameter_list|()
function_decl|;
name|NamespaceNode
modifier|*
name|nextRoot
parameter_list|()
function_decl|;
name|Tree
modifier|*
name|firstTree
parameter_list|()
function_decl|;
name|Tree
modifier|*
name|nextTree
parameter_list|()
function_decl|;
name|Tree
modifier|*
name|primaryTree
parameter_list|()
block|{
return|return
name|primaryTree_
return|;
block|}
name|Tree
modifier|*
name|findTree
parameter_list|(
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
block|{
return|return
name|forest_
operator|.
name|value
argument_list|(
name|t
argument_list|)
return|;
block|}
name|NamespaceNode
modifier|*
name|primaryTreeRoot
parameter_list|()
block|{
return|return
operator|(
name|primaryTree_
condition|?
name|primaryTree_
operator|->
name|root
argument_list|()
else|:
literal|0
operator|)
return|;
block|}
name|bool
name|isEmpty
parameter_list|()
block|{
return|return
name|searchOrder
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
name|bool
name|done
parameter_list|()
block|{
return|return
operator|(
name|currentIndex_
operator|>=
name|searchOrder
argument_list|()
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
specifier|const
name|QVector
operator|<
name|Tree
operator|*
operator|>
operator|&
name|searchOrder
argument_list|()
expr_stmt|;
specifier|const
name|QVector
operator|<
name|Tree
operator|*
operator|>
operator|&
name|indexSearchOrder
argument_list|()
expr_stmt|;
name|void
name|setSearchOrder
parameter_list|()
function_decl|;
specifier|const
name|Node
modifier|*
name|findNode
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|int
name|findFlags
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
specifier|const
name|Node
modifier|*
name|n
init|=
name|t
operator|->
name|findNode
argument_list|(
name|path
argument_list|,
name|relative
argument_list|,
name|findFlags
argument_list|,
name|genus
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
return|return
name|n
return|;
name|relative
operator|=
literal|0
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
name|Node
modifier|*
name|findNodeByNameAndType
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
name|Node
operator|::
name|Type
name|type
argument_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
name|Node
modifier|*
name|n
init|=
name|t
operator|->
name|findNodeByNameAndType
argument_list|(
name|path
argument_list|,
name|type
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
return|return
name|n
return|;
block|}
return|return
literal|0
return|;
block|}
name|ClassNode
modifier|*
name|findClassNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
name|ClassNode
modifier|*
name|n
init|=
name|t
operator|->
name|findClassNode
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
return|return
name|n
return|;
block|}
return|return
literal|0
return|;
block|}
name|Node
modifier|*
name|findNodeForInclude
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
name|Node
modifier|*
name|n
init|=
name|t
operator|->
name|findNodeForInclude
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
return|return
name|n
return|;
block|}
return|return
literal|0
return|;
block|}
name|InnerNode
modifier|*
name|findRelatesNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
name|InnerNode
modifier|*
name|n
init|=
name|t
operator|->
name|findRelatesNode
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
return|return
name|n
return|;
block|}
return|return
literal|0
return|;
block|}
specifier|const
name|Node
modifier|*
name|findFunctionNode
argument_list|(
specifier|const
name|QString
operator|&
name|target
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
specifier|const
name|Node
modifier|*
name|n
init|=
name|t
operator|->
name|findFunctionNode
argument_list|(
name|target
argument_list|,
name|relative
argument_list|,
name|genus
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
return|return
name|n
return|;
name|relative
operator|=
literal|0
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
specifier|const
name|Node
modifier|*
name|findNodeForTarget
argument_list|(
name|QStringList
operator|&
name|targetPath
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|,
name|QString
operator|&
name|ref
argument_list|)
decl_stmt|;
specifier|const
name|Node
modifier|*
name|findTypeNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
name|int
name|flags
init|=
name|SearchBaseClasses
operator||
name|SearchEnumValues
operator||
name|NonFunction
decl_stmt|;
specifier|const
name|Node
modifier|*
name|n
init|=
name|t
operator|->
name|findNode
argument_list|(
name|path
argument_list|,
name|relative
argument_list|,
name|flags
argument_list|,
name|Node
operator|::
name|DontCare
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
return|return
name|n
return|;
name|relative
operator|=
literal|0
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
specifier|const
name|DocNode
modifier|*
name|findDocNodeByTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
specifier|const
name|DocNode
modifier|*
name|n
init|=
name|t
operator|->
name|findDocNodeByTitle
argument_list|(
name|title
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
return|return
name|n
return|;
block|}
return|return
literal|0
return|;
block|}
name|QmlClassNode
modifier|*
name|lookupQmlType
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
name|QmlClassNode
modifier|*
name|qcn
init|=
name|t
operator|->
name|lookupQmlType
argument_list|(
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|qcn
condition|)
return|return
name|qcn
return|;
block|}
return|return
literal|0
return|;
block|}
name|void
name|mergeCollectionMaps
argument_list|(
name|Node
operator|::
name|Type
name|nt
argument_list|,
name|CNMultiMap
operator|&
name|cnmm
argument_list|)
decl_stmt|;
name|void
name|getCorrespondingCollections
parameter_list|(
name|CollectionNode
modifier|*
name|cn
parameter_list|,
name|CollectionList
modifier|&
name|cl
parameter_list|)
block|{
name|foreach
argument_list|(
argument|Tree* t
argument_list|,
argument|searchOrder()
argument_list|)
block|{
name|CollectionNode
modifier|*
name|ccn
init|=
name|t
operator|->
name|getCorrespondingCollection
argument_list|(
name|cn
argument_list|)
decl_stmt|;
if|if
condition|(
name|ccn
condition|)
name|cl
operator|.
name|append
argument_list|(
name|ccn
argument_list|)
expr_stmt|;
block|}
block|}
name|private
label|:
name|void
name|newPrimaryTree
parameter_list|(
specifier|const
name|QString
modifier|&
name|module
parameter_list|)
function_decl|;
name|NamespaceNode
modifier|*
name|newIndexTree
parameter_list|(
specifier|const
name|QString
modifier|&
name|module
parameter_list|)
function_decl|;
name|private
label|:
name|QDocDatabase
modifier|*
name|qdb_
decl_stmt|;
name|Tree
modifier|*
name|primaryTree_
decl_stmt|;
name|int
name|currentIndex_
decl_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|Tree
operator|*
operator|>
name|forest_
expr_stmt|;
name|QVector
operator|<
name|Tree
operator|*
operator|>
name|searchOrder_
expr_stmt|;
name|QVector
operator|<
name|Tree
operator|*
operator|>
name|indexSearchOrder_
expr_stmt|;
name|QVector
operator|<
name|QString
operator|>
name|moduleNames_
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QDocDatabase
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::QDocDatabase
argument_list|)
name|public
label|:
specifier|static
name|QDocDatabase
modifier|*
name|qdocDB
parameter_list|()
function_decl|;
specifier|static
name|void
name|destroyQdocDB
parameter_list|()
function_decl|;
operator|~
name|QDocDatabase
argument_list|()
expr_stmt|;
name|Tree
modifier|*
name|findTree
parameter_list|(
specifier|const
name|QString
modifier|&
name|t
parameter_list|)
block|{
return|return
name|forest_
operator|.
name|findTree
argument_list|(
name|t
argument_list|)
return|;
block|}
specifier|const
name|CNMap
modifier|&
name|groups
parameter_list|()
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|groups
argument_list|()
return|;
block|}
specifier|const
name|CNMap
modifier|&
name|modules
parameter_list|()
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|modules
argument_list|()
return|;
block|}
specifier|const
name|CNMap
modifier|&
name|qmlModules
parameter_list|()
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|qmlModules
argument_list|()
return|;
block|}
name|GroupNode
modifier|*
name|getGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|getGroup
argument_list|(
name|name
argument_list|)
return|;
block|}
name|GroupNode
modifier|*
name|findGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|findGroup
argument_list|(
name|name
argument_list|)
return|;
block|}
name|ModuleNode
modifier|*
name|findModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|findModule
argument_list|(
name|name
argument_list|)
return|;
block|}
name|QmlModuleNode
modifier|*
name|findQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|findQmlModule
argument_list|(
name|name
argument_list|)
return|;
block|}
name|GroupNode
modifier|*
name|addGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|addGroup
argument_list|(
name|name
argument_list|)
return|;
block|}
name|ModuleNode
modifier|*
name|addModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|addModule
argument_list|(
name|name
argument_list|)
return|;
block|}
name|QmlModuleNode
modifier|*
name|addQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|addQmlModule
argument_list|(
name|name
argument_list|)
return|;
block|}
name|GroupNode
modifier|*
name|addToGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|addToGroup
argument_list|(
name|name
argument_list|,
name|node
argument_list|)
return|;
block|}
name|ModuleNode
modifier|*
name|addToModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|addToModule
argument_list|(
name|name
argument_list|,
name|node
argument_list|)
return|;
block|}
name|QmlModuleNode
modifier|*
name|addToQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|addToQmlModule
argument_list|(
name|name
argument_list|,
name|node
argument_list|)
return|;
block|}
name|void
name|addExampleNode
parameter_list|(
name|ExampleNode
modifier|*
name|n
parameter_list|)
block|{
name|primaryTree
argument_list|()
operator|->
name|addExampleNode
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
name|ExampleNodeMap
modifier|&
name|exampleNodeMap
parameter_list|()
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|exampleNodeMap
argument_list|()
return|;
block|}
name|QmlClassNode
modifier|*
name|findQmlType
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QmlClassNode
modifier|*
name|findQmlType
parameter_list|(
specifier|const
name|QString
modifier|&
name|qmid
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QmlClassNode
modifier|*
name|findQmlType
parameter_list|(
specifier|const
name|ImportRec
modifier|&
name|import
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|findAllClasses
parameter_list|(
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllFunctions
parameter_list|(
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllLegaleseTexts
parameter_list|(
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllNamespaces
parameter_list|(
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllObsoleteThings
parameter_list|(
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllSince
parameter_list|(
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|public
label|:
comment|/*******************************************************************      special collection access functions     ********************************************************************/
name|NodeMap
modifier|&
name|getCppClasses
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getMainClasses
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getCompatibilityClasses
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getObsoleteClasses
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getClassesWithObsoleteMembers
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getObsoleteQmlTypes
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getQmlTypesWithObsoleteMembers
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getNamespaces
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getServiceClasses
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getQmlBasicTypes
parameter_list|()
function_decl|;
name|NodeMap
modifier|&
name|getQmlTypes
parameter_list|()
function_decl|;
name|NodeMapMap
modifier|&
name|getFunctionIndex
parameter_list|()
function_decl|;
name|TextToNodeMap
modifier|&
name|getLegaleseTexts
parameter_list|()
function_decl|;
specifier|const
name|NodeMap
modifier|&
name|getClassMap
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
specifier|const
name|NodeMap
modifier|&
name|getQmlTypeMap
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
specifier|const
name|NodeMultiMap
modifier|&
name|getSinceMap
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
comment|/*******************************************************************       Many of these will be either eliminated or replaced.     ********************************************************************/
name|void
name|resolveInheritance
parameter_list|()
block|{
name|primaryTree
argument_list|()
operator|->
name|resolveInheritance
argument_list|()
expr_stmt|;
block|}
name|void
name|resolveQmlInheritance
parameter_list|(
name|InnerNode
modifier|*
name|root
parameter_list|)
function_decl|;
name|void
name|resolveIssues
parameter_list|()
function_decl|;
name|void
name|fixInheritance
parameter_list|()
block|{
name|primaryTree
argument_list|()
operator|->
name|fixInheritance
argument_list|()
expr_stmt|;
block|}
name|void
name|resolveProperties
parameter_list|()
block|{
name|primaryTree
argument_list|()
operator|->
name|resolveProperties
argument_list|()
expr_stmt|;
block|}
name|void
name|resolveTargets
parameter_list|()
block|{
name|primaryTree
argument_list|()
operator|->
name|resolveTargets
argument_list|(
name|primaryTreeRoot
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|insertTarget
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|title
argument_list|,
name|TargetRec
operator|::
name|Type
name|type
argument_list|,
name|Node
operator|*
name|node
argument_list|,
name|int
name|priority
argument_list|)
block|{
name|primaryTree
argument_list|()
operator|->
name|insertTarget
argument_list|(
name|name
argument_list|,
name|title
argument_list|,
name|type
argument_list|,
name|node
argument_list|,
name|priority
argument_list|)
expr_stmt|;
block|}
comment|/*******************************************************************       The functions declared below are called for the current tree only.     ********************************************************************/
name|FunctionNode
modifier|*
name|findFunctionNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|parentPath
parameter_list|,
specifier|const
name|FunctionNode
modifier|*
name|clone
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|findFunctionNode
argument_list|(
name|parentPath
argument_list|,
name|clone
argument_list|)
return|;
block|}
name|FunctionNode
modifier|*
name|findNodeInOpenNamespace
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|parentPath
parameter_list|,
specifier|const
name|FunctionNode
modifier|*
name|clone
parameter_list|)
function_decl|;
name|Node
modifier|*
name|findNodeInOpenNamespace
argument_list|(
name|QStringList
operator|&
name|path
argument_list|,
name|Node
operator|::
name|Type
name|type
argument_list|)
decl_stmt|;
specifier|const
name|Node
modifier|*
name|checkForCollision
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|primaryTree
argument_list|()
operator|->
name|checkForCollision
argument_list|(
name|name
argument_list|)
return|;
block|}
comment|/*******************************************************************/
comment|/*******************************************************************       The functions declared below handle the parameters in '[' ']'.     ********************************************************************/
specifier|const
name|Node
modifier|*
name|findNodeForAtom
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|,
name|QString
modifier|&
name|ref
parameter_list|)
function_decl|;
comment|/*******************************************************************/
comment|/*******************************************************************       The functions declared below are called for all trees.     ********************************************************************/
name|ClassNode
modifier|*
name|findClassNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
return|return
name|forest_
operator|.
name|findClassNode
argument_list|(
name|path
argument_list|)
return|;
block|}
name|Node
modifier|*
name|findNodeForInclude
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
return|return
name|forest_
operator|.
name|findNodeForInclude
argument_list|(
name|path
argument_list|)
return|;
block|}
name|InnerNode
modifier|*
name|findRelatesNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
return|return
name|forest_
operator|.
name|findRelatesNode
argument_list|(
name|path
argument_list|)
return|;
block|}
specifier|const
name|Node
modifier|*
name|findFunctionNode
argument_list|(
specifier|const
name|QString
operator|&
name|target
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|)
block|{
return|return
name|forest_
operator|.
name|findFunctionNode
argument_list|(
name|target
argument_list|,
name|relative
argument_list|,
name|genus
argument_list|)
return|;
block|}
specifier|const
name|Node
modifier|*
name|findTypeNode
parameter_list|(
specifier|const
name|QString
modifier|&
name|type
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|)
function_decl|;
specifier|const
name|Node
modifier|*
name|findNodeForTarget
parameter_list|(
specifier|const
name|QString
modifier|&
name|target
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|)
function_decl|;
specifier|const
name|DocNode
modifier|*
name|findDocNodeByTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
return|return
name|forest_
operator|.
name|findDocNodeByTitle
argument_list|(
name|title
argument_list|)
return|;
block|}
name|Node
modifier|*
name|findNodeByNameAndType
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
name|Node
operator|::
name|Type
name|type
argument_list|)
block|{
return|return
name|forest_
operator|.
name|findNodeByNameAndType
argument_list|(
name|path
argument_list|,
name|type
argument_list|)
return|;
block|}
name|private
label|:
specifier|const
name|Node
modifier|*
name|findNodeForTarget
argument_list|(
name|QStringList
operator|&
name|targetPath
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|,
name|QString
operator|&
name|ref
argument_list|)
block|{
return|return
name|forest_
operator|.
name|findNodeForTarget
argument_list|(
name|targetPath
argument_list|,
name|relative
argument_list|,
name|genus
argument_list|,
name|ref
argument_list|)
return|;
block|}
comment|/*******************************************************************/
name|public
label|:
name|void
name|addPropertyFunction
argument_list|(
name|PropertyNode
operator|*
name|property
argument_list|,
specifier|const
name|QString
operator|&
name|funcName
argument_list|,
name|PropertyNode
operator|::
name|FunctionRole
name|funcRole
argument_list|)
block|{
name|primaryTree
argument_list|()
operator|->
name|addPropertyFunction
argument_list|(
name|property
argument_list|,
name|funcName
argument_list|,
name|funcRole
argument_list|)
expr_stmt|;
block|}
name|void
name|setVersion
parameter_list|(
specifier|const
name|QString
modifier|&
name|v
parameter_list|)
block|{
name|version_
operator|=
name|v
expr_stmt|;
block|}
name|QString
name|version
argument_list|()
specifier|const
block|{
return|return
name|version_
return|;
block|}
name|void
name|generateTagFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|Generator
modifier|*
name|g
parameter_list|)
function_decl|;
name|void
name|readIndexes
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|indexFiles
parameter_list|)
function_decl|;
name|void
name|generateIndex
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|url
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|Generator
modifier|*
name|g
parameter_list|,
name|bool
name|generateInternalNodes
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|clearOpenNamespaces
parameter_list|()
block|{
name|openNamespaces_
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|void
name|insertOpenNamespace
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|openNamespaces_
operator|.
name|insert
argument_list|(
name|path
argument_list|)
expr_stmt|;
block|}
name|void
name|setShowInternal
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|showInternal_
operator|=
name|value
expr_stmt|;
block|}
comment|// Try to make this function private.
name|QDocForest
modifier|&
name|forest
parameter_list|()
block|{
return|return
name|forest_
return|;
block|}
name|NamespaceNode
modifier|*
name|primaryTreeRoot
parameter_list|()
block|{
return|return
name|forest_
operator|.
name|primaryTreeRoot
argument_list|()
return|;
block|}
name|void
name|newPrimaryTree
parameter_list|(
specifier|const
name|QString
modifier|&
name|module
parameter_list|)
block|{
name|forest_
operator|.
name|newPrimaryTree
argument_list|(
name|module
argument_list|)
expr_stmt|;
block|}
name|NamespaceNode
modifier|*
name|newIndexTree
parameter_list|(
specifier|const
name|QString
modifier|&
name|module
parameter_list|)
block|{
return|return
name|forest_
operator|.
name|newIndexTree
argument_list|(
name|module
argument_list|)
return|;
block|}
specifier|const
name|QVector
operator|<
name|Tree
operator|*
operator|>
operator|&
name|searchOrder
argument_list|()
block|{
return|return
name|forest_
operator|.
name|searchOrder
argument_list|()
return|;
block|}
name|void
name|setSearchOrder
parameter_list|()
block|{
name|forest_
operator|.
name|setSearchOrder
argument_list|()
expr_stmt|;
block|}
name|void
name|mergeCollections
argument_list|(
name|Node
operator|::
name|Type
name|nt
argument_list|,
name|CNMap
operator|&
name|cnm
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|)
decl_stmt|;
name|void
name|mergeCollections
parameter_list|(
name|CollectionNode
modifier|*
name|cn
parameter_list|)
function_decl|;
name|private
label|:
name|friend
name|class
name|QDocIndexFiles
decl_stmt|;
name|friend
name|class
name|QDocTagFiles
decl_stmt|;
specifier|const
name|Node
modifier|*
name|findNode
argument_list|(
specifier|const
name|QStringList
operator|&
name|path
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
name|int
name|findFlags
argument_list|,
name|Node
operator|::
name|Genus
name|genus
argument_list|)
block|{
return|return
name|forest_
operator|.
name|findNode
argument_list|(
name|path
argument_list|,
name|relative
argument_list|,
name|findFlags
argument_list|,
name|genus
argument_list|)
return|;
block|}
name|void
name|processForest
argument_list|(
name|void
argument_list|(
name|QDocDatabase
operator|::
operator|*
argument_list|)
argument_list|(
name|InnerNode
operator|*
argument_list|)
argument_list|)
decl_stmt|;
specifier|static
name|void
name|initializeDB
parameter_list|()
function_decl|;
name|private
label|:
name|QDocDatabase
argument_list|()
expr_stmt|;
name|QDocDatabase
argument_list|(
name|QDocDatabase
specifier|const
operator|&
argument_list|)
operator|:
name|showInternal_
argument_list|(
name|false
argument_list|)
operator|,
name|forest_
argument_list|(
argument|this
argument_list|)
block|{ }
name|QDocDatabase
operator|&
name|operator
operator|=
operator|(
name|QDocDatabase
specifier|const
operator|&
operator|)
expr_stmt|;
name|Tree
modifier|*
name|primaryTree
parameter_list|()
block|{
return|return
name|forest_
operator|.
name|primaryTree
argument_list|()
return|;
block|}
name|public
label|:
specifier|static
name|bool
name|debug
decl_stmt|;
name|private
label|:
specifier|static
name|QDocDatabase
modifier|*
name|qdocDB_
decl_stmt|;
specifier|static
name|NodeMap
name|typeNodeMap_
decl_stmt|;
name|bool
name|showInternal_
decl_stmt|;
name|QString
name|version_
decl_stmt|;
name|QDocForest
name|forest_
decl_stmt|;
name|NodeMap
name|nonCompatClasses_
decl_stmt|;
name|NodeMap
name|mainClasses_
decl_stmt|;
name|NodeMap
name|compatClasses_
decl_stmt|;
name|NodeMap
name|obsoleteClasses_
decl_stmt|;
name|NodeMap
name|classesWithObsoleteMembers_
decl_stmt|;
name|NodeMap
name|obsoleteQmlTypes_
decl_stmt|;
name|NodeMap
name|qmlTypesWithObsoleteMembers_
decl_stmt|;
name|NodeMap
name|namespaceIndex_
decl_stmt|;
name|NodeMap
name|serviceClasses_
decl_stmt|;
name|NodeMap
name|qmlBasicTypes_
decl_stmt|;
name|NodeMap
name|qmlClasses_
decl_stmt|;
name|NodeMapMap
name|newClassMaps_
decl_stmt|;
name|NodeMapMap
name|newQmlTypeMaps_
decl_stmt|;
name|NodeMultiMapMap
name|newSinceMaps_
decl_stmt|;
name|NodeMapMap
name|funcIndex_
decl_stmt|;
name|TextToNodeMap
name|legaleseTexts_
decl_stmt|;
name|QSet
operator|<
name|QString
operator|>
name|openNamespaces_
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
