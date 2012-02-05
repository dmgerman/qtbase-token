begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MOC_H
end_ifndef
begin_define
DECL|macro|MOC_H
define|#
directive|define
name|MOC_H
end_define
begin_include
include|#
directive|include
file|"parser.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QPair>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct_decl
struct_decl|struct
name|QMetaObject
struct_decl|;
end_struct_decl
begin_struct
DECL|struct|Type
struct|struct
name|Type
block|{
DECL|enum|ReferenceType
DECL|enumerator|NoReference
DECL|enumerator|Reference
DECL|enumerator|RValueReference
DECL|enumerator|Pointer
enum|enum
name|ReferenceType
block|{
name|NoReference
block|,
name|Reference
block|,
name|RValueReference
block|,
name|Pointer
block|}
enum|;
DECL|function|Type
specifier|inline
name|Type
argument_list|()
operator|:
name|isVolatile
argument_list|(
name|false
argument_list|)
operator|,
name|isScoped
argument_list|(
name|false
argument_list|)
operator|,
name|firstToken
argument_list|(
name|NOTOKEN
argument_list|)
operator|,
name|referenceType
argument_list|(
argument|NoReference
argument_list|)
block|{}
DECL|function|Type
specifier|inline
name|explicit
name|Type
argument_list|(
specifier|const
name|QByteArray
operator|&
name|_name
argument_list|)
operator|:
name|name
argument_list|(
name|_name
argument_list|)
operator|,
name|rawName
argument_list|(
name|name
argument_list|)
operator|,
name|isVolatile
argument_list|(
name|false
argument_list|)
operator|,
name|isScoped
argument_list|(
name|false
argument_list|)
operator|,
name|firstToken
argument_list|(
name|NOTOKEN
argument_list|)
operator|,
name|referenceType
argument_list|(
argument|NoReference
argument_list|)
block|{}
DECL|member|name
name|QByteArray
name|name
expr_stmt|;
comment|//When used as a return type, the type name may be modified to remove the references.
comment|// rawName is the type as found in the function signature
DECL|member|rawName
name|QByteArray
name|rawName
decl_stmt|;
DECL|member|isVolatile
name|uint
name|isVolatile
range|:
literal|1
decl_stmt|;
DECL|member|isScoped
name|uint
name|isScoped
range|:
literal|1
decl_stmt|;
DECL|member|firstToken
name|Token
name|firstToken
decl_stmt|;
DECL|member|referenceType
name|ReferenceType
name|referenceType
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|EnumDef
struct|struct
name|EnumDef
block|{
DECL|member|name
name|QByteArray
name|name
decl_stmt|;
DECL|member|values
name|QList
operator|<
name|QByteArray
operator|>
name|values
expr_stmt|;
DECL|member|isEnumClass
name|bool
name|isEnumClass
decl_stmt|;
comment|// c++11 enum class
DECL|function|EnumDef
name|EnumDef
argument_list|()
operator|:
name|isEnumClass
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_struct
DECL|struct|ArgumentDef
struct|struct
name|ArgumentDef
block|{
DECL|function|ArgumentDef
name|ArgumentDef
argument_list|()
operator|:
name|isDefault
argument_list|(
argument|false
argument_list|)
block|{}
DECL|member|type
name|Type
name|type
expr_stmt|;
DECL|member|rightType
DECL|member|normalizedType
DECL|member|name
name|QByteArray
name|rightType
decl_stmt|,
name|normalizedType
decl_stmt|,
name|name
decl_stmt|;
DECL|member|typeNameForCast
name|QByteArray
name|typeNameForCast
decl_stmt|;
comment|// type name to be used in cast from void * in metacall
DECL|member|isDefault
name|bool
name|isDefault
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|FunctionDef
struct|struct
name|FunctionDef
block|{
DECL|function|FunctionDef
name|FunctionDef
argument_list|()
operator|:
name|returnTypeIsVolatile
argument_list|(
name|false
argument_list|)
operator|,
name|access
argument_list|(
name|Private
argument_list|)
operator|,
name|isConst
argument_list|(
name|false
argument_list|)
operator|,
name|isVirtual
argument_list|(
name|false
argument_list|)
operator|,
name|isStatic
argument_list|(
name|false
argument_list|)
operator|,
name|inlineCode
argument_list|(
name|false
argument_list|)
operator|,
name|wasCloned
argument_list|(
name|false
argument_list|)
operator|,
name|isCompat
argument_list|(
name|false
argument_list|)
operator|,
name|isInvokable
argument_list|(
name|false
argument_list|)
operator|,
name|isScriptable
argument_list|(
name|false
argument_list|)
operator|,
name|isSlot
argument_list|(
name|false
argument_list|)
operator|,
name|isSignal
argument_list|(
name|false
argument_list|)
operator|,
name|isConstructor
argument_list|(
name|false
argument_list|)
operator|,
name|isDestructor
argument_list|(
name|false
argument_list|)
operator|,
name|isAbstract
argument_list|(
name|false
argument_list|)
operator|,
name|revision
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|type
name|Type
name|type
expr_stmt|;
DECL|member|normalizedType
name|QByteArray
name|normalizedType
decl_stmt|;
DECL|member|tag
name|QByteArray
name|tag
decl_stmt|;
DECL|member|name
name|QByteArray
name|name
decl_stmt|;
DECL|member|returnTypeIsVolatile
name|bool
name|returnTypeIsVolatile
decl_stmt|;
DECL|member|arguments
name|QList
operator|<
name|ArgumentDef
operator|>
name|arguments
expr_stmt|;
DECL|enum|Access
DECL|enumerator|Private
DECL|enumerator|Protected
DECL|enumerator|Public
enum|enum
name|Access
block|{
name|Private
block|,
name|Protected
block|,
name|Public
block|}
enum|;
DECL|member|access
name|Access
name|access
decl_stmt|;
DECL|member|isConst
name|bool
name|isConst
decl_stmt|;
DECL|member|isVirtual
name|bool
name|isVirtual
decl_stmt|;
DECL|member|isStatic
name|bool
name|isStatic
decl_stmt|;
DECL|member|inlineCode
name|bool
name|inlineCode
decl_stmt|;
DECL|member|wasCloned
name|bool
name|wasCloned
decl_stmt|;
DECL|member|inPrivateClass
name|QByteArray
name|inPrivateClass
decl_stmt|;
DECL|member|isCompat
name|bool
name|isCompat
decl_stmt|;
DECL|member|isInvokable
name|bool
name|isInvokable
decl_stmt|;
DECL|member|isScriptable
name|bool
name|isScriptable
decl_stmt|;
DECL|member|isSlot
name|bool
name|isSlot
decl_stmt|;
DECL|member|isSignal
name|bool
name|isSignal
decl_stmt|;
DECL|member|isConstructor
name|bool
name|isConstructor
decl_stmt|;
DECL|member|isDestructor
name|bool
name|isDestructor
decl_stmt|;
DECL|member|isAbstract
name|bool
name|isAbstract
decl_stmt|;
DECL|member|revision
name|int
name|revision
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|PropertyDef
struct|struct
name|PropertyDef
block|{
DECL|function|PropertyDef
name|PropertyDef
argument_list|()
operator|:
name|notifyId
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|constant
argument_list|(
name|false
argument_list|)
operator|,
name|final
argument_list|(
name|false
argument_list|)
operator|,
name|gspec
argument_list|(
name|ValueSpec
argument_list|)
operator|,
name|revision
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|name
DECL|member|type
DECL|member|read
DECL|member|write
DECL|member|reset
DECL|member|designable
DECL|member|scriptable
DECL|member|editable
DECL|member|stored
DECL|member|user
DECL|member|notify
DECL|member|inPrivateClass
name|QByteArray
name|name
operator|,
name|type
operator|,
name|read
operator|,
name|write
operator|,
name|reset
operator|,
name|designable
operator|,
name|scriptable
operator|,
name|editable
operator|,
name|stored
operator|,
name|user
operator|,
name|notify
operator|,
name|inPrivateClass
expr_stmt|;
DECL|member|notifyId
name|int
name|notifyId
decl_stmt|;
DECL|member|constant
name|bool
name|constant
decl_stmt|;
DECL|member|final
name|bool
name|final
decl_stmt|;
DECL|enum|Specification
DECL|enumerator|ValueSpec
DECL|enumerator|ReferenceSpec
DECL|enumerator|PointerSpec
enum|enum
name|Specification
block|{
name|ValueSpec
block|,
name|ReferenceSpec
block|,
name|PointerSpec
block|}
enum|;
DECL|member|gspec
name|Specification
name|gspec
decl_stmt|;
DECL|function|stdCppSet
name|bool
name|stdCppSet
argument_list|()
specifier|const
block|{
name|QByteArray
name|s
argument_list|(
literal|"set"
argument_list|)
block|;
name|s
operator|+=
name|toupper
argument_list|(
name|name
index|[
literal|0
index|]
argument_list|)
block|;
name|s
operator|+=
name|name
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
block|;
return|return
operator|(
name|s
operator|==
name|write
operator|)
return|;
block|}
DECL|member|revision
name|int
name|revision
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|ClassInfoDef
struct|struct
name|ClassInfoDef
block|{
DECL|member|name
name|QByteArray
name|name
decl_stmt|;
DECL|member|value
name|QByteArray
name|value
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|ClassDef
struct|struct
name|ClassDef
block|{
DECL|function|ClassDef
name|ClassDef
argument_list|()
operator|:
name|hasQObject
argument_list|(
name|false
argument_list|)
operator|,
name|hasQGadget
argument_list|(
name|false
argument_list|)
operator|,
name|notifyableProperties
argument_list|(
literal|0
argument_list|)
operator|,
name|revisionedMethods
argument_list|(
literal|0
argument_list|)
operator|,
name|revisionedProperties
argument_list|(
literal|0
argument_list|)
operator|,
name|begin
argument_list|(
literal|0
argument_list|)
operator|,
name|end
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|classname
name|QByteArray
name|classname
expr_stmt|;
DECL|member|qualified
name|QByteArray
name|qualified
decl_stmt|;
DECL|member|QByteArray
DECL|member|superclassList
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
operator|,
name|FunctionDef
operator|::
name|Access
operator|>
expr|>
name|superclassList
expr_stmt|;
DECL|struct|Interface
struct|struct
name|Interface
block|{
DECL|function|Interface
specifier|inline
name|explicit
name|Interface
argument_list|(
specifier|const
name|QByteArray
operator|&
name|_className
argument_list|)
operator|:
name|className
argument_list|(
argument|_className
argument_list|)
block|{}
DECL|member|className
name|QByteArray
name|className
expr_stmt|;
DECL|member|interfaceId
name|QByteArray
name|interfaceId
decl_stmt|;
block|}
struct|;
DECL|member|interfaceList
name|QList
operator|<
name|QList
operator|<
name|Interface
operator|>
expr|>
name|interfaceList
expr_stmt|;
DECL|member|hasQObject
name|bool
name|hasQObject
decl_stmt|;
DECL|member|hasQGadget
name|bool
name|hasQGadget
decl_stmt|;
DECL|member|constructorList
name|QList
operator|<
name|FunctionDef
operator|>
name|constructorList
expr_stmt|;
DECL|member|signalList
DECL|member|slotList
DECL|member|methodList
DECL|member|publicList
name|QList
operator|<
name|FunctionDef
operator|>
name|signalList
operator|,
name|slotList
operator|,
name|methodList
operator|,
name|publicList
expr_stmt|;
DECL|member|notifyableProperties
name|int
name|notifyableProperties
decl_stmt|;
DECL|member|propertyList
name|QList
operator|<
name|PropertyDef
operator|>
name|propertyList
expr_stmt|;
DECL|member|classInfoList
name|QList
operator|<
name|ClassInfoDef
operator|>
name|classInfoList
expr_stmt|;
DECL|member|QByteArray
DECL|member|enumDeclarations
name|QMap
operator|<
name|QByteArray
operator|,
name|bool
operator|>
name|enumDeclarations
expr_stmt|;
DECL|member|enumList
name|QList
operator|<
name|EnumDef
operator|>
name|enumList
expr_stmt|;
DECL|member|QByteArray
DECL|member|flagAliases
name|QMap
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
name|flagAliases
expr_stmt|;
DECL|member|revisionedMethods
name|int
name|revisionedMethods
decl_stmt|;
DECL|member|revisionedProperties
name|int
name|revisionedProperties
decl_stmt|;
DECL|member|begin
name|int
name|begin
decl_stmt|;
DECL|member|end
name|int
name|end
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|NamespaceDef
struct|struct
name|NamespaceDef
block|{
DECL|member|name
name|QByteArray
name|name
decl_stmt|;
DECL|member|begin
name|int
name|begin
decl_stmt|;
DECL|member|end
name|int
name|end
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Moc
range|:
name|public
name|Parser
block|{
name|public
operator|:
name|Moc
argument_list|()
operator|:
name|noInclude
argument_list|(
name|false
argument_list|)
block|,
name|generatedCode
argument_list|(
name|false
argument_list|)
block|,
name|mustIncludeQMetaTypeH
argument_list|(
argument|false
argument_list|)
block|{}
name|QByteArray
name|filename
block|;
name|bool
name|noInclude
block|;
name|bool
name|generatedCode
block|;
name|bool
name|mustIncludeQMetaTypeH
block|;
name|QByteArray
name|includePath
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|includeFiles
block|;
name|QList
operator|<
name|ClassDef
operator|>
name|classList
block|;
name|QMap
operator|<
name|QByteArray
block|,
name|QByteArray
operator|>
name|interface2IdMap
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|metaTypes
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|knownQObjectClasses
block|;
name|void
name|parse
argument_list|()
block|;
name|void
name|generate
argument_list|(
name|FILE
operator|*
name|out
argument_list|)
block|;
name|bool
name|parseClassHead
argument_list|(
name|ClassDef
operator|*
name|def
argument_list|)
block|;
specifier|inline
name|bool
name|inClass
argument_list|(
argument|const ClassDef *def
argument_list|)
specifier|const
block|{
return|return
name|index
operator|>
name|def
operator|->
name|begin
operator|&&
name|index
operator|<
name|def
operator|->
name|end
operator|-
literal|1
return|;
block|}
specifier|inline
name|bool
name|inNamespace
argument_list|(
argument|const NamespaceDef *def
argument_list|)
specifier|const
block|{
return|return
name|index
operator|>
name|def
operator|->
name|begin
operator|&&
name|index
operator|<
name|def
operator|->
name|end
operator|-
literal|1
return|;
block|}
name|Type
name|parseType
argument_list|()
block|;
name|bool
name|parseEnum
argument_list|(
name|EnumDef
operator|*
name|def
argument_list|)
block|;
name|bool
name|parseFunction
argument_list|(
argument|FunctionDef *def
argument_list|,
argument|bool inMacro = false
argument_list|)
block|;
name|bool
name|parseMaybeFunction
argument_list|(
specifier|const
name|ClassDef
operator|*
name|cdef
argument_list|,
name|FunctionDef
operator|*
name|def
argument_list|)
block|;
name|void
name|parseSlots
argument_list|(
argument|ClassDef *def
argument_list|,
argument|FunctionDef::Access access
argument_list|)
block|;
name|void
name|parseSignals
argument_list|(
name|ClassDef
operator|*
name|def
argument_list|)
block|;
name|void
name|parseProperty
argument_list|(
name|ClassDef
operator|*
name|def
argument_list|)
block|;
name|void
name|createPropertyDef
argument_list|(
name|PropertyDef
operator|&
name|def
argument_list|)
block|;
name|void
name|parseEnumOrFlag
argument_list|(
argument|ClassDef *def
argument_list|,
argument|bool isFlag
argument_list|)
block|;
name|void
name|parseFlag
argument_list|(
name|ClassDef
operator|*
name|def
argument_list|)
block|;
name|void
name|parseClassInfo
argument_list|(
name|ClassDef
operator|*
name|def
argument_list|)
block|;
name|void
name|parseInterfaces
argument_list|(
name|ClassDef
operator|*
name|def
argument_list|)
block|;
name|void
name|parseDeclareInterface
argument_list|()
block|;
name|void
name|parseDeclareMetatype
argument_list|()
block|;
name|void
name|parseSlotInPrivate
argument_list|(
argument|ClassDef *def
argument_list|,
argument|FunctionDef::Access access
argument_list|)
block|;
name|void
name|parsePrivateProperty
argument_list|(
name|ClassDef
operator|*
name|def
argument_list|)
block|;
name|void
name|parseFunctionArguments
argument_list|(
name|FunctionDef
operator|*
name|def
argument_list|)
block|;
name|QByteArray
name|lexemUntil
argument_list|(
name|Token
argument_list|)
block|;
name|bool
name|until
argument_list|(
name|Token
argument_list|)
block|;
comment|// test for Q_INVOCABLE, Q_SCRIPTABLE, etc. and set the flags
comment|// in FunctionDef accordingly
name|bool
name|testFunctionAttribute
argument_list|(
name|FunctionDef
operator|*
name|def
argument_list|)
block|;
name|bool
name|testFunctionAttribute
argument_list|(
argument|Token tok
argument_list|,
argument|FunctionDef *def
argument_list|)
block|;
name|bool
name|testFunctionRevision
argument_list|(
name|FunctionDef
operator|*
name|def
argument_list|)
block|;
name|void
name|checkSuperClasses
argument_list|(
name|ClassDef
operator|*
name|def
argument_list|)
block|;
name|void
name|checkProperties
argument_list|(
name|ClassDef
operator|*
name|cdef
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|noRef
specifier|inline
name|QByteArray
name|noRef
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|.
name|endsWith
argument_list|(
literal|'&'
argument_list|)
condition|)
block|{
if|if
condition|(
name|type
operator|.
name|endsWith
argument_list|(
literal|"&&"
argument_list|)
condition|)
return|return
name|type
operator|.
name|left
argument_list|(
name|type
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
return|;
return|return
name|type
operator|.
name|left
argument_list|(
name|type
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
return|return
name|type
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MOC_H
end_comment
end_unit
