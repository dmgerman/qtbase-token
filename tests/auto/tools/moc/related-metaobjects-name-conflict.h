begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RELATED_METAOBJECTS_NAME_CONFLICT_H
end_ifndef
begin_define
DECL|macro|RELATED_METAOBJECTS_NAME_CONFLICT_H
define|#
directive|define
name|RELATED_METAOBJECTS_NAME_CONFLICT_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_define
DECL|macro|DECLARE_GADGET_AND_OBJECT_CLASSES
define|#
directive|define
name|DECLARE_GADGET_AND_OBJECT_CLASSES
define|\
value|class Gadget { \         Q_GADGET \         Q_ENUMS(SomeEnum) \     public: \         enum SomeEnum { SomeEnumValue = 0 }; \     }; \     class Object : public QObject{ \         Q_OBJECT \         Q_ENUMS(SomeEnum) \     public: \         enum SomeEnum { SomeEnumValue = 0 }; \     };
end_define
begin_define
DECL|macro|DECLARE_DEPENDING_CLASSES
define|#
directive|define
name|DECLARE_DEPENDING_CLASSES
define|\
value|class DependingObject : public QObject \     { \         Q_OBJECT \         Q_PROPERTY(Gadget::SomeEnum gadgetPoperty READ gadgetPoperty) \         Q_PROPERTY(Object::SomeEnum objectPoperty READ objectPoperty) \     public: \         Gadget::SomeEnum gadgetPoperty() const { return Gadget::SomeEnumValue; } \         Object::SomeEnum objectPoperty() const { return Object::SomeEnumValue; } \     };\     struct DependingNestedGadget : public QObject \     { \         Q_OBJECT \         Q_PROPERTY(Nested::Gadget::SomeEnum nestedGadgetPoperty READ nestedGadgetPoperty) \         Nested::Gadget::SomeEnum nestedGadgetPoperty() const { return Nested::Gadget::SomeEnumValue; } \     };\     struct DependingNestedObject : public QObject \     { \         Q_OBJECT \         Q_PROPERTY(Nested::Object::SomeEnum nestedObjectPoperty READ nestedObjectPoperty) \         Nested::Object::SomeEnum nestedObjectPoperty() const { return Nested::Object::SomeEnumValue; } \     };\   namespace Unsused {
end_define
begin_expr_stmt
name|DECLARE_GADGET_AND_OBJECT_CLASSES
end_expr_stmt
begin_comment
unit|}
comment|// Unused
end_comment
begin_macro
unit|namespace
name|NS1
end_macro
begin_block
block|{
name|namespace
name|Nested
block|{
name|DECLARE_GADGET_AND_OBJECT_CLASSES
block|}
comment|// Nested
name|namespace
name|NestedUnsused
block|{
name|DECLARE_GADGET_AND_OBJECT_CLASSES
block|}
comment|// NestedUnused
name|DECLARE_GADGET_AND_OBJECT_CLASSES
name|DECLARE_DEPENDING_CLASSES
block|}
end_block
begin_comment
comment|// NS1
end_comment
begin_decl_stmt
name|namespace
name|NS2
block|{
name|namespace
name|Nested
block|{
name|DECLARE_GADGET_AND_OBJECT_CLASSES
block|}
comment|// Nested
name|namespace
name|NestedUnsused
block|{
name|DECLARE_GADGET_AND_OBJECT_CLASSES
block|}
comment|// NestedUnused
name|DECLARE_GADGET_AND_OBJECT_CLASSES
name|DECLARE_DEPENDING_CLASSES
block|}
end_decl_stmt
begin_comment
comment|// NS2
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// RELATED_METAOBJECTS_NAME_CONFLICT_H
end_comment
end_unit
