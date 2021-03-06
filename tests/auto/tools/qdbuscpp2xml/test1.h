begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Stephen Kelly<stephen.kelly@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSCPP2XML_TEST1_H
end_ifndef
begin_define
DECL|macro|QDBUSCPP2XML_TEST1_H
define|#
directive|define
name|QDBUSCPP2XML_TEST1_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_decl_stmt
DECL|variable|QDBusObjectPath
name|class
name|QDBusObjectPath
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusUnixFileDescriptor
name|class
name|QDBusUnixFileDescriptor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusSignature
name|class
name|QDBusSignature
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Test1
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.qtProject.qdbuscpp2xmlTests.Test1"
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int numProperty1 READ numProperty1 CONSTANT
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int numProperty2 READ numProperty2 WRITE setNumProperty2
argument_list|)
name|Q_ENUMS
argument_list|(
argument|Salaries
argument_list|)
name|public
operator|:
comment|// C++1y allows use of single quote as a digit separator, useful for large
comment|// numbers. http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3781.pdf
comment|// Ensure that qdbuscpp2xml does not get confused with this appearing.
expr|enum
name|Salaries
block|{
name|Steve
ifdef|#
directive|ifdef
name|Q_MOC_RUN
operator|=
literal|1
literal|'234'
literal|567
endif|#
directive|endif
block|}
block|;
name|Test1
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
name|int
name|numProperty1
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|int
name|numProperty2
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|void
name|setNumProperty2
argument_list|(
argument|int
argument_list|)
block|{}
name|signals
operator|:
name|void
name|signalVoidType
argument_list|()
block|;
name|int
name|signalIntType
argument_list|()
block|;
name|void
name|signal_primitive_args
argument_list|(
argument|int a1
argument_list|,
argument|bool a2
argument_list|,
argument|short a3
argument_list|,
argument|ushort a4
argument_list|,
argument|uint a5
argument_list|,
argument|qlonglong a6
argument_list|,
argument|double a7
argument_list|,
argument|qlonglong a8 =
literal|0
argument_list|)
block|;
name|void
name|signal_string_args
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ba
argument_list|,
specifier|const
name|QString
operator|&
name|a2
argument_list|)
block|;
name|void
name|signal_Qt_args1
argument_list|(
specifier|const
name|QDate
operator|&
name|a1
argument_list|,
specifier|const
name|QTime
operator|&
name|a2
argument_list|,
specifier|const
name|QDateTime
operator|&
name|a3
argument_list|,
specifier|const
name|QRect
operator|&
name|a4
argument_list|,
specifier|const
name|QRectF
operator|&
name|a5
argument_list|,
specifier|const
name|QSize
operator|&
name|a6
argument_list|,
specifier|const
name|QSizeF
operator|&
name|a7
argument_list|)
block|;
name|void
name|signal_Qt_args2
argument_list|(
specifier|const
name|QPoint
operator|&
name|a1
argument_list|,
specifier|const
name|QPointF
operator|&
name|a2
argument_list|,
specifier|const
name|QLine
operator|&
name|a3
argument_list|,
specifier|const
name|QLineF
operator|&
name|a4
argument_list|,
specifier|const
name|QVariantList
operator|&
name|a5
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|a6
argument_list|,
specifier|const
name|QVariantHash
operator|&
name|a7
argument_list|)
block|;
name|void
name|signal_QDBus_args
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|a1
argument_list|,
specifier|const
name|QDBusSignature
operator|&
name|a2
argument_list|,
specifier|const
name|QDBusUnixFileDescriptor
operator|&
name|a3
argument_list|)
block|;
name|void
name|signal_container_args1
argument_list|(
specifier|const
name|QList
operator|<
name|bool
operator|>
operator|&
name|a1
argument_list|,
specifier|const
name|QList
operator|<
name|short
operator|>
operator|&
name|a2
argument_list|,
specifier|const
name|QList
operator|<
name|ushort
operator|>
operator|&
name|a3
argument_list|,
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|a4
argument_list|,
specifier|const
name|QList
operator|<
name|uint
operator|>
operator|&
name|a5
argument_list|)
block|;
name|void
name|signal_container_args2
argument_list|(
specifier|const
name|QList
operator|<
name|qlonglong
operator|>
operator|&
name|a1
argument_list|,
specifier|const
name|QList
operator|<
name|qulonglong
operator|>
operator|&
name|a2
argument_list|,
specifier|const
name|QList
operator|<
name|double
operator|>
operator|&
name|a3
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusObjectPath
operator|>
operator|&
name|a4
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusSignature
operator|>
operator|&
name|a5
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusUnixFileDescriptor
operator|>
operator|&
name|a6
argument_list|)
block|;
name|Q_SCRIPTABLE
name|void
name|signalVoidType_scriptable
argument_list|()
block|;
name|Q_SCRIPTABLE
name|int
name|signalIntType_scriptable
argument_list|()
block|;
name|Q_SCRIPTABLE
name|void
name|signal_primitive_args_scriptable
argument_list|(
argument|int a1
argument_list|,
argument|bool a2
argument_list|,
argument|short a3
argument_list|,
argument|ushort a4
argument_list|,
argument|uint a5
argument_list|,
argument|qlonglong a6
argument_list|,
argument|double a7
argument_list|,
argument|qlonglong a8 =
literal|0
argument_list|)
block|;
name|Q_SCRIPTABLE
name|void
name|signal_string_args_scriptable
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ba
argument_list|,
specifier|const
name|QString
operator|&
name|a2
argument_list|)
block|;
name|Q_SCRIPTABLE
name|void
name|signal_Qt_args1_scriptable
argument_list|(
specifier|const
name|QDate
operator|&
name|a1
argument_list|,
specifier|const
name|QTime
operator|&
name|a2
argument_list|,
specifier|const
name|QDateTime
operator|&
name|a3
argument_list|,
specifier|const
name|QRect
operator|&
name|a4
argument_list|,
specifier|const
name|QRectF
operator|&
name|a5
argument_list|,
specifier|const
name|QSize
operator|&
name|a6
argument_list|,
specifier|const
name|QSizeF
operator|&
name|a7
argument_list|)
block|;
name|Q_SCRIPTABLE
name|void
name|signal_Qt_args2_scriptable
argument_list|(
specifier|const
name|QPoint
operator|&
name|a1
argument_list|,
specifier|const
name|QPointF
operator|&
name|a2
argument_list|,
specifier|const
name|QLine
operator|&
name|a3
argument_list|,
specifier|const
name|QLineF
operator|&
name|a4
argument_list|,
specifier|const
name|QVariantList
operator|&
name|a5
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|a6
argument_list|,
specifier|const
name|QVariantHash
operator|&
name|a7
argument_list|)
block|;
name|Q_SCRIPTABLE
name|void
name|signal_QDBus_args_scriptable
argument_list|(
specifier|const
name|QDBusObjectPath
operator|&
name|a1
argument_list|,
specifier|const
name|QDBusSignature
operator|&
name|a2
argument_list|,
specifier|const
name|QDBusUnixFileDescriptor
operator|&
name|a3
argument_list|)
block|;
name|Q_SCRIPTABLE
name|void
name|signal_container_args1_scriptable
argument_list|(
specifier|const
name|QList
operator|<
name|bool
operator|>
operator|&
name|a1
argument_list|,
specifier|const
name|QList
operator|<
name|short
operator|>
operator|&
name|a2
argument_list|,
specifier|const
name|QList
operator|<
name|ushort
operator|>
operator|&
name|a3
argument_list|,
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|a4
argument_list|,
specifier|const
name|QList
operator|<
name|uint
operator|>
operator|&
name|a5
argument_list|)
block|;
name|Q_SCRIPTABLE
name|void
name|signal_container_args2_scriptable
argument_list|(
specifier|const
name|QList
operator|<
name|qlonglong
operator|>
operator|&
name|a1
argument_list|,
specifier|const
name|QList
operator|<
name|qulonglong
operator|>
operator|&
name|a2
argument_list|,
specifier|const
name|QList
operator|<
name|double
operator|>
operator|&
name|a3
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusObjectPath
operator|>
operator|&
name|a4
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusSignature
operator|>
operator|&
name|a5
argument_list|,
specifier|const
name|QList
operator|<
name|QDBusUnixFileDescriptor
operator|>
operator|&
name|a6
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|slotVoidType
argument_list|()
block|{}
name|int
name|slotIntType
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|Q_SCRIPTABLE
name|void
name|slotVoidType_scriptable
argument_list|()
block|{}
name|Q_SCRIPTABLE
name|int
name|slotIntType_scriptable
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|protected
name|slots
operator|:
name|void
name|neverExported1
argument_list|()
block|{}
name|int
name|neverExported2
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|Q_SCRIPTABLE
name|void
name|neverExported3
argument_list|()
block|{}
name|Q_SCRIPTABLE
name|int
name|neverExported4
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|private
name|slots
operator|:
name|void
name|neverExported5
argument_list|()
block|{}
name|int
name|neverExported6
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|Q_SCRIPTABLE
name|void
name|neverExported7
argument_list|()
block|{}
name|Q_SCRIPTABLE
name|int
name|neverExported8
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|public
operator|:
name|Q_SCRIPTABLE
name|void
name|methodVoidType
argument_list|()
block|{}
name|Q_SCRIPTABLE
name|int
name|methodIntType
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|protected
operator|:
name|Q_SCRIPTABLE
name|void
name|neverExported9
argument_list|()
block|{}
name|Q_SCRIPTABLE
name|int
name|neverExported10
argument_list|()
block|{
return|return
literal|42
return|;
block|}
name|private
operator|:
name|Q_SCRIPTABLE
name|void
name|neverExported11
argument_list|()
block|{}
name|Q_SCRIPTABLE
name|int
name|neverExported12
argument_list|()
block|{
return|return
literal|42
return|;
block|}
expr|}
block|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
