begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|QString
DECL|typedef|DocNodeMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|DocNode
operator|*
operator|>
name|DocNodeMap
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QString
DECL|typedef|QmlTypeMap
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QmlClassNode
operator|*
operator|>
name|QmlTypeMap
expr_stmt|;
end_typedef
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
DECL|typedef|QString
DECL|typedef|DocNodeMultiMap
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|DocNode
operator|*
operator|>
name|DocNodeMultiMap
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
name|QDocDatabase
block|{
struct|struct
name|Target
block|{
name|public
label|:
name|Target
argument_list|()
operator|:
name|node_
argument_list|(
literal|0
argument_list|)
operator|,
name|priority_
argument_list|(
argument|INT_MAX
argument_list|)
block|{ }
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|ref_
operator|.
name|isEmpty
argument_list|()
return|;
block|}
comment|//void debug(int idx, const QString& key);
name|Node
modifier|*
name|node_
decl_stmt|;
name|QString
name|ref_
decl_stmt|;
name|int
name|priority_
decl_stmt|;
block|}
struct|;
typedef|typedef
name|QMultiMap
operator|<
name|QString
operator|,
name|Target
operator|>
name|TargetMultiMap
expr_stmt|;
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
specifier|const
name|DocNodeMap
operator|&
name|modules
argument_list|()
specifier|const
block|{
return|return
name|modules_
return|;
block|}
specifier|const
name|DocNodeMap
operator|&
name|qmlModules
argument_list|()
specifier|const
block|{
return|return
name|qmlModules_
return|;
block|}
name|DocNode
modifier|*
name|addModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|DocNode
modifier|*
name|addQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|DocNode
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
function_decl|;
name|DocNode
modifier|*
name|addToQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|moduleName
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|)
function_decl|;
name|DocNode
modifier|*
name|findModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|qmlModuleName
parameter_list|,
name|bool
name|addIfNotFound
init|=
name|false
parameter_list|)
function_decl|;
name|DocNode
modifier|*
name|findQmlModule
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|bool
name|addIfNotFound
init|=
name|false
parameter_list|)
function_decl|;
name|QmlClassNode
modifier|*
name|findQmlType
argument_list|(
specifier|const
name|QString
operator|&
name|qmid
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|void
name|findAllClasses
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllFunctions
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllLegaleseTexts
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllNamespaces
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|findAllSince
parameter_list|(
specifier|const
name|InnerNode
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|buildCollections
parameter_list|()
function_decl|;
comment|// special collection access functions
name|NodeMap
modifier|&
name|getCppClasses
parameter_list|()
block|{
return|return
name|nonCompatClasses_
return|;
block|}
name|NodeMap
modifier|&
name|getMainClasses
parameter_list|()
block|{
return|return
name|mainClasses_
return|;
block|}
name|NodeMap
modifier|&
name|getCompatibilityClasses
parameter_list|()
block|{
return|return
name|compatClasses_
return|;
block|}
name|NodeMap
modifier|&
name|getObsoleteClasses
parameter_list|()
block|{
return|return
name|obsoleteClasses_
return|;
block|}
name|NodeMap
modifier|&
name|getNamespaces
parameter_list|()
block|{
return|return
name|namespaceIndex_
return|;
block|}
name|NodeMap
modifier|&
name|getServiceClasses
parameter_list|()
block|{
return|return
name|serviceClasses_
return|;
block|}
name|NodeMap
modifier|&
name|getQmlTypes
parameter_list|()
block|{
return|return
name|qmlClasses_
return|;
block|}
name|NodeMapMap
modifier|&
name|getFunctionIndex
parameter_list|()
block|{
return|return
name|funcIndex_
return|;
block|}
name|TextToNodeMap
modifier|&
name|getLegaleseTexts
parameter_list|()
block|{
return|return
name|legaleseTexts_
return|;
block|}
specifier|const
name|NodeMultiMap
operator|&
name|groups
argument_list|()
specifier|const
block|{
return|return
name|tree_
operator|->
name|groups
argument_list|()
return|;
block|}
specifier|const
name|NodeList
name|getGroup
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
block|{
return|return
name|tree_
operator|->
name|groups
argument_list|()
operator|.
name|values
argument_list|(
name|name
argument_list|)
return|;
block|}
name|void
name|getGroup
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|NodeMap
operator|&
name|group
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|NodeMap
modifier|&
name|getClassMap
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|NodeMap
modifier|&
name|getQmlTypeMap
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|NodeMultiMap
modifier|&
name|getSinceMap
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|Node
modifier|*
name|resolveTarget
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
parameter_list|,
specifier|const
name|Node
modifier|*
name|self
init|=
literal|0
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
name|void
name|insertTarget
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|Node
modifier|*
name|node
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
comment|/* convenience functions        Many of these will be either eliminated or replaced.     */
name|QString
name|refForAtom
parameter_list|(
specifier|const
name|Atom
modifier|*
name|atom
parameter_list|)
function_decl|;
name|Tree
modifier|*
name|tree
parameter_list|()
block|{
return|return
name|tree_
return|;
block|}
name|NamespaceNode
modifier|*
name|treeRoot
parameter_list|()
block|{
return|return
name|tree_
operator|->
name|root
argument_list|()
return|;
block|}
name|void
name|resolveInheritance
parameter_list|()
block|{
name|tree_
operator|->
name|resolveInheritance
argument_list|()
expr_stmt|;
block|}
name|void
name|resolveIssues
parameter_list|()
function_decl|;
name|void
name|addToGroup
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|,
specifier|const
name|QString
modifier|&
name|group
parameter_list|)
block|{
name|tree_
operator|->
name|addToGroup
argument_list|(
name|node
argument_list|,
name|group
argument_list|)
expr_stmt|;
block|}
name|void
name|addToPublicGroup
parameter_list|(
name|Node
modifier|*
name|node
parameter_list|,
specifier|const
name|QString
modifier|&
name|group
parameter_list|)
block|{
name|tree_
operator|->
name|addToPublicGroup
argument_list|(
name|node
argument_list|,
name|group
argument_list|)
expr_stmt|;
block|}
name|void
name|fixInheritance
parameter_list|()
block|{
name|tree_
operator|->
name|fixInheritance
argument_list|()
expr_stmt|;
block|}
name|void
name|resolveProperties
parameter_list|()
block|{
name|tree_
operator|->
name|resolveProperties
argument_list|()
expr_stmt|;
block|}
specifier|const
name|Node
modifier|*
name|findNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
return|return
name|tree_
operator|->
name|findNode
argument_list|(
name|path
argument_list|)
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
return|return
name|tree_
operator|->
name|findClassNode
argument_list|(
name|path
argument_list|)
return|;
block|}
name|NamespaceNode
modifier|*
name|findNamespaceNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
return|return
name|tree_
operator|->
name|findNamespaceNode
argument_list|(
name|path
argument_list|)
return|;
block|}
name|DocNode
modifier|*
name|findGroupNode
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|path
parameter_list|)
block|{
return|return
name|tree_
operator|->
name|findGroupNode
argument_list|(
name|path
argument_list|)
return|;
block|}
name|NameCollisionNode
modifier|*
name|findCollisionNode
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
block|{
return|return
name|tree_
operator|->
name|findCollisionNode
argument_list|(
name|name
argument_list|)
return|;
block|}
specifier|const
name|DocNode
modifier|*
name|findDocNodeByTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|,
specifier|const
name|Node
operator|*
name|relative
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|Node
modifier|*
name|findUnambiguousTarget
parameter_list|(
specifier|const
name|QString
modifier|&
name|target
parameter_list|,
name|QString
modifier|&
name|ref
parameter_list|,
specifier|const
name|Node
modifier|*
name|relative
parameter_list|)
function_decl|;
name|QString
name|findTarget
argument_list|(
specifier|const
name|QString
operator|&
name|target
argument_list|,
specifier|const
name|Node
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
name|void
name|resolveTargets
parameter_list|(
name|InnerNode
modifier|*
name|root
parameter_list|)
function_decl|;
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
name|tree_
operator|->
name|findFunctionNode
argument_list|(
name|parentPath
argument_list|,
name|clone
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
argument_list|,
name|Node
operator|::
name|SubType
name|subtype
argument_list|)
block|{
return|return
name|tree_
operator|->
name|findNodeByNameAndType
argument_list|(
name|path
argument_list|,
name|type
argument_list|,
name|subtype
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|NameCollisionNode
modifier|*
name|checkForCollision
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
block|{
return|return
name|tree_
operator|->
name|checkForCollision
argument_list|(
name|name
argument_list|)
return|;
block|}
name|void
name|addBaseClass
argument_list|(
name|ClassNode
operator|*
name|subclass
argument_list|,
name|Node
operator|::
name|Access
name|access
argument_list|,
specifier|const
name|QStringList
operator|&
name|basePath
argument_list|,
specifier|const
name|QString
operator|&
name|dataTypeWithTemplateArgs
argument_list|,
name|InnerNode
operator|*
name|parent
argument_list|)
block|{
name|tree_
operator|->
name|addBaseClass
argument_list|(
name|subclass
argument_list|,
name|access
argument_list|,
name|basePath
argument_list|,
name|dataTypeWithTemplateArgs
argument_list|,
name|parent
argument_list|)
expr_stmt|;
block|}
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
name|tree_
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
comment|/* debugging functions */
name|void
name|printModules
argument_list|()
specifier|const
expr_stmt|;
name|void
name|printQmlModules
argument_list|()
specifier|const
expr_stmt|;
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
parameter_list|,
name|int
name|findFlags
parameter_list|)
block|{
return|return
name|tree_
operator|->
name|findNode
argument_list|(
name|path
argument_list|,
name|relative
argument_list|,
name|findFlags
argument_list|)
return|;
block|}
name|private
label|:
name|QDocDatabase
argument_list|()
expr_stmt|;
name|QDocDatabase
argument_list|(
argument|QDocDatabase const&
argument_list|)
block|{ }
empty_stmt|;
comment|// copy constructor is private
name|QDocDatabase
modifier|&
name|operator
init|=
operator|(
name|QDocDatabase
specifier|const
operator|&
operator|)
decl_stmt|;
comment|// assignment operator is private
name|private
label|:
specifier|static
name|QDocDatabase
modifier|*
name|qdocDB_
decl_stmt|;
name|QString
name|version_
decl_stmt|;
name|QDocMultiMap
name|masterMap_
decl_stmt|;
name|Tree
modifier|*
name|tree_
decl_stmt|;
name|DocNodeMap
name|modules_
decl_stmt|;
name|DocNodeMap
name|qmlModules_
decl_stmt|;
name|QmlTypeMap
name|qmlTypeMap_
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
name|namespaceIndex_
decl_stmt|;
name|NodeMap
name|serviceClasses_
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
name|DocNodeMultiMap
name|docNodesByTitle_
decl_stmt|;
name|TargetMultiMap
name|targetMultiMap_
decl_stmt|;
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
