begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMETATYPE_P_H
end_ifndef
begin_define
DECL|macro|QMETATYPE_P_H
define|#
directive|define
name|QMETATYPE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qmetatype.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QModulesPrivate
block|{
enum|enum
name|Names
block|{
name|Core
block|,
name|Gui
block|,
name|Widgets
block|,
name|Unknown
block|,
name|ModulesCount
comment|/* ModulesCount has to be at the end */
block|}
enum|;
specifier|static
specifier|inline
name|int
name|moduleForType
parameter_list|(
specifier|const
name|int
name|typeId
parameter_list|)
block|{
if|if
condition|(
name|typeId
operator|<=
name|QMetaType
operator|::
name|LastCoreType
condition|)
return|return
name|Core
return|;
if|if
condition|(
name|typeId
operator|<=
name|QMetaType
operator|::
name|LastGuiType
condition|)
return|return
name|Gui
return|;
if|if
condition|(
name|typeId
operator|<=
name|QMetaType
operator|::
name|LastWidgetsType
condition|)
return|return
name|Widgets
return|;
return|return
name|Unknown
return|;
block|}
block|}
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QTypeModuleInfo
block|{
name|public
operator|:
expr|enum
name|Module
block|{
name|IsCore
operator|=
operator|!
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
block|,
comment|// Primitive types are in Core
name|IsWidget
operator|=
name|false
block|,
name|IsGui
operator|=
name|false
block|,
name|IsUnknown
operator|=
operator|!
name|IsCore
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|QT_ASSIGN_TYPE_TO_MODULE
define|#
directive|define
name|QT_ASSIGN_TYPE_TO_MODULE
parameter_list|(
name|TYPE
parameter_list|,
name|MODULE
parameter_list|)
define|\
value|template<> \ class QTypeModuleInfo<TYPE> \ { \ public: \     enum Module { \         IsCore = (((MODULE) == (QModulesPrivate::Core))), \         IsWidget = (((MODULE) == (QModulesPrivate::Widgets))), \         IsGui = (((MODULE) == (QModulesPrivate::Gui))), \         IsUnknown = !(IsCore || IsWidget || IsGui) \     }; \     static inline int module() { return MODULE; } \     Q_STATIC_ASSERT((IsUnknown&& !(IsCore || IsWidget || IsGui)) \                  || (IsCore&& !(IsUnknown || IsWidget || IsGui)) \                  || (IsWidget&& !(IsUnknown || IsCore || IsGui)) \                  || (IsGui&& !(IsUnknown || IsCore || IsWidget))); \ };
end_define
begin_define
DECL|macro|QT_DECLARE_CORE_MODULE_TYPES_ITER
define|#
directive|define
name|QT_DECLARE_CORE_MODULE_TYPES_ITER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|QT_ASSIGN_TYPE_TO_MODULE(Name, QModulesPrivate::Core);
end_define
begin_define
DECL|macro|QT_DECLARE_GUI_MODULE_TYPES_ITER
define|#
directive|define
name|QT_DECLARE_GUI_MODULE_TYPES_ITER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|QT_ASSIGN_TYPE_TO_MODULE(Name, QModulesPrivate::Gui);
end_define
begin_define
DECL|macro|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
define|#
directive|define
name|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
parameter_list|(
name|TypeName
parameter_list|,
name|TypeId
parameter_list|,
name|Name
parameter_list|)
define|\
value|QT_ASSIGN_TYPE_TO_MODULE(Name, QModulesPrivate::Widgets);
end_define
begin_macro
DECL|function|QT_FOR_EACH_STATIC_CORE_CLASS
name|QT_FOR_EACH_STATIC_CORE_CLASS
argument_list|(
argument|QT_DECLARE_CORE_MODULE_TYPES_ITER
argument_list|)
end_macro
begin_macro
name|QT_FOR_EACH_STATIC_CORE_TEMPLATE
argument_list|(
argument|QT_DECLARE_CORE_MODULE_TYPES_ITER
argument_list|)
end_macro
begin_macro
name|QT_FOR_EACH_STATIC_GUI_CLASS
argument_list|(
argument|QT_DECLARE_GUI_MODULE_TYPES_ITER
argument_list|)
end_macro
begin_macro
name|QT_FOR_EACH_STATIC_WIDGETS_CLASS
argument_list|(
argument|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
argument_list|)
end_macro
begin_undef
DECL|macro|QT_DECLARE_CORE_MODULE_TYPES_ITER
undef|#
directive|undef
name|QT_DECLARE_CORE_MODULE_TYPES_ITER
end_undef
begin_undef
DECL|macro|QT_DECLARE_GUI_MODULE_TYPES_ITER
undef|#
directive|undef
name|QT_DECLARE_GUI_MODULE_TYPES_ITER
end_undef
begin_undef
DECL|macro|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
undef|#
directive|undef
name|QT_DECLARE_WIDGETS_MODULE_TYPES_ITER
end_undef
begin_decl_stmt
name|class
name|QMetaTypeInterface
block|{
name|public
label|:
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Impl
block|{
specifier|static
name|void
operator|*
name|creator
argument_list|(
argument|const T *t
argument_list|)
block|{
if|if
condition|(
name|t
condition|)
return|return
name|new
name|T
argument_list|(
operator|*
name|t
argument_list|)
return|;
return|return
name|new
name|T
argument_list|()
return|;
block|}
specifier|static
name|void
name|deleter
parameter_list|(
name|T
modifier|*
name|t
parameter_list|)
block|{
name|delete
name|t
decl_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
specifier|static
name|void
name|saver
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
specifier|const
name|T
modifier|*
name|t
parameter_list|)
block|{
name|stream
operator|<<
operator|*
name|t
expr_stmt|;
block|}
specifier|static
name|void
name|loader
parameter_list|(
name|QDataStream
modifier|&
name|stream
parameter_list|,
name|T
modifier|*
name|t
parameter_list|)
block|{
name|stream
operator|>>
operator|*
name|t
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_NO_DATASTREAM
specifier|static
name|void
name|destructor
parameter_list|(
name|T
modifier|*
name|t
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|t
argument_list|)
comment|// Silence MSVC that warns for POD types.
name|t
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
block|}
specifier|static
name|void
modifier|*
name|constructor
parameter_list|(
name|void
modifier|*
name|where
parameter_list|,
specifier|const
name|T
modifier|*
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
condition|)
return|return
name|new
argument_list|(
argument|where
argument_list|)
name|T
argument_list|(
operator|*
name|static_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|t
operator|)
argument_list|)
return|;
return|return
name|new
argument_list|(
argument|where
argument_list|)
name|T
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QMetaType
operator|::
name|Creator
name|creator
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMetaType
operator|::
name|Deleter
name|deleter
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|QMetaType
operator|::
name|SaveOperator
name|saveOp
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMetaType
operator|::
name|LoadOperator
name|loadOp
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QMetaType
operator|::
name|Constructor
name|constructor
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMetaType
operator|::
name|Destructor
name|destructor
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|size
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|quint32
name|flags
decl_stmt|;
end_decl_stmt
begin_comment
comment|// same as QMetaType::TypeFlags
end_comment
begin_ifndef
unit|};
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL
parameter_list|(
name|Type
parameter_list|)
define|\
comment|/*saveOp*/
value|(reinterpret_cast<QMetaType::SaveOperator>(QMetaTypeInterface::Impl<Type>::saver)), \
comment|/*loadOp*/
value|(reinterpret_cast<QMetaType::LoadOperator>(QMetaTypeInterface::Impl<Type>::loader)),
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL
parameter_list|(
name|Type
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_METATYPE_INTERFACE_INIT
define|#
directive|define
name|QT_METATYPE_INTERFACE_INIT
parameter_list|(
name|Type
parameter_list|)
define|\
value|{ \
comment|/*creator*/
value|(reinterpret_cast<QMetaType::Creator>(QMetaTypeInterface::Impl<Type>::creator)), \
comment|/*deleter*/
value|(reinterpret_cast<QMetaType::Deleter>(QMetaTypeInterface::Impl<Type>::deleter)), \     QT_METATYPE_INTERFACE_INIT_DATASTREAM_IMPL(Type) \
comment|/*constructor*/
value|(reinterpret_cast<QMetaType::Constructor>(QMetaTypeInterface::Impl<Type>::constructor)), \
comment|/*destructor*/
value|(reinterpret_cast<QMetaType::Destructor>(QMetaTypeInterface::Impl<Type>::destructor)), \
comment|/*size*/
value|(sizeof(Type)), \
comment|/*flags*/
value|(!QTypeInfo<Type>::isStatic * QMetaType::MovableType) \             | (QTypeInfo<Type>::isComplex * QMetaType::NeedsConstruction) \             | (QTypeInfo<Type>::isComplex * QMetaType::NeedsDestruction) \ }
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMETATYPE_P_H
end_comment
end_unit
