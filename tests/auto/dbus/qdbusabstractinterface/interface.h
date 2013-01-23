begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|INTERFACE_H
end_ifndef
begin_define
DECL|macro|INTERFACE_H
define|#
directive|define
name|INTERFACE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QDBusArgument>
end_include
begin_struct
DECL|struct|RegisteredType
struct|struct
name|RegisteredType
block|{
DECL|function|RegisteredType
specifier|inline
name|RegisteredType
argument_list|(
specifier|const
name|QString
operator|&
name|str
operator|=
name|QString
argument_list|()
argument_list|)
operator|:
name|s
argument_list|(
argument|str
argument_list|)
block|{}
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RegisteredType
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|s
operator|==
name|other
operator|.
name|s
return|;
block|}
DECL|member|s
name|QString
name|s
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
DECL|function|Q_DECLARE_METATYPE
name|Q_DECLARE_METATYPE
argument_list|(
argument|RegisteredType
argument_list|)
end_macro
begin_expr_stmt
specifier|inline
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|s
operator|,
specifier|const
name|RegisteredType
operator|&
name|data
operator|)
block|{
name|s
operator|.
name|beginStructure
argument_list|()
block|;
name|s
operator|<<
name|data
operator|.
name|s
block|;
name|s
operator|.
name|endStructure
argument_list|()
block|;
return|return
name|s
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|s
operator|,
name|RegisteredType
operator|&
name|data
operator|)
block|{
name|s
operator|.
name|beginStructure
argument_list|()
block|;
name|s
operator|>>
name|data
operator|.
name|s
block|;
name|s
operator|.
name|endStructure
argument_list|()
block|;
return|return
name|s
return|;
block|}
end_expr_stmt
begin_struct
DECL|struct|UnregisteredType
struct|struct
name|UnregisteredType
block|{
DECL|member|s
name|QString
name|s
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
DECL|function|Q_DECLARE_METATYPE
name|Q_DECLARE_METATYPE
argument_list|(
argument|UnregisteredType
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Interface
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.qtproject.QtDBus.Pinger"
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString stringProp READ stringProp WRITE setStringProp SCRIPTABLE true
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QDBusVariant variantProp READ variantProp WRITE setVariantProp SCRIPTABLE true
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|RegisteredType complexProp READ complexProp WRITE setComplexProp SCRIPTABLE true
argument_list|)
name|friend
name|class
name|tst_QDBusAbstractInterface
block|;
name|friend
name|class
name|PingerServer
block|;
name|QString
name|m_stringProp
block|;
name|QDBusVariant
name|m_variantProp
block|;
name|RegisteredType
name|m_complexProp
block|;
name|public
operator|:
name|Interface
argument_list|()
block|;
name|QString
name|stringProp
argument_list|()
specifier|const
block|{
return|return
name|m_stringProp
return|;
block|}
name|void
name|setStringProp
argument_list|(
argument|const QString&s
argument_list|)
block|{
name|m_stringProp
operator|=
name|s
block|; }
name|QDBusVariant
name|variantProp
argument_list|()
specifier|const
block|{
return|return
name|m_variantProp
return|;
block|}
name|void
name|setVariantProp
argument_list|(
argument|const QDBusVariant&v
argument_list|)
block|{
name|m_variantProp
operator|=
name|v
block|; }
name|RegisteredType
name|complexProp
argument_list|()
specifier|const
block|{
return|return
name|m_complexProp
return|;
block|}
name|void
name|setComplexProp
argument_list|(
argument|const RegisteredType&r
argument_list|)
block|{
name|m_complexProp
operator|=
name|r
block|; }
name|public
name|slots
operator|:
name|Q_SCRIPTABLE
name|void
name|voidMethod
argument_list|()
block|{}
name|Q_SCRIPTABLE
name|int
name|sleepMethod
argument_list|(
name|int
argument_list|)
block|;
name|Q_SCRIPTABLE
name|QString
name|stringMethod
argument_list|()
block|{
return|return
literal|"Hello, world"
return|;
block|}
name|Q_SCRIPTABLE
name|RegisteredType
name|complexMethod
argument_list|()
block|{
return|return
name|RegisteredType
argument_list|(
literal|"Hello, world"
argument_list|)
return|;
block|}
name|Q_SCRIPTABLE
name|QString
name|multiOutMethod
argument_list|(
argument|int&value
argument_list|)
block|{
name|value
operator|=
literal|42
block|;
return|return
literal|"Hello, world"
return|;
block|}
name|signals
operator|:
name|Q_SCRIPTABLE
name|void
name|voidSignal
argument_list|()
block|;
name|Q_SCRIPTABLE
name|void
name|stringSignal
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|Q_SCRIPTABLE
name|void
name|complexSignal
argument_list|(
name|RegisteredType
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// INTERFACE_H
end_comment
end_unit
