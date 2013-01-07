begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MYOBJECT_H
end_ifndef
begin_define
DECL|macro|MYOBJECT_H
define|#
directive|define
name|MYOBJECT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_decl_stmt
name|class
name|MyObject
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.qtproject.QtDBus.MyObject"
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Introspection"
argument_list|,
literal|""
literal|"<interface name=\"org.qtproject.QtDBus.MyObject\">\n"
literal|"<property access=\"readwrite\" type=\"i\" name=\"prop1\" />\n"
literal|"<property name=\"complexProp\" type=\"ai\" access=\"readwrite\">\n"
literal|"<annotation name=\"org.qtproject.QtDBus.QtTypeName\" value=\"QList&lt;int&gt;\"/>\n"
literal|"</property>\n"
literal|"<signal name=\"somethingHappened\">\n"
literal|"<arg direction=\"out\" type=\"s\" />\n"
literal|"</signal>\n"
literal|"<method name=\"ping\">\n"
literal|"<arg direction=\"in\" type=\"v\" name=\"ping\" />\n"
literal|"<arg direction=\"out\" type=\"v\" name=\"ping\" />\n"
literal|"</method>\n"
literal|"<method name=\"ping_invokable\">\n"
literal|"<arg direction=\"in\" type=\"v\" name=\"ping_invokable\" />\n"
literal|"<arg direction=\"out\" type=\"v\" name=\"ping_invokable\" />\n"
literal|"</method>\n"
literal|"<method name=\"ping\">\n"
literal|"<arg direction=\"in\" type=\"v\" name=\"ping1\" />\n"
literal|"<arg direction=\"in\" type=\"v\" name=\"ping2\" />\n"
literal|"<arg direction=\"out\" type=\"v\" name=\"pong1\" />\n"
literal|"<arg direction=\"out\" type=\"v\" name=\"pong2\" />\n"
literal|"</method>\n"
literal|"<method name=\"ping_invokable\">\n"
literal|"<arg direction=\"in\" type=\"v\" name=\"ping1_invokable\" />\n"
literal|"<arg direction=\"in\" type=\"v\" name=\"ping2_invokable\" />\n"
literal|"<arg direction=\"out\" type=\"v\" name=\"pong1_invokable\" />\n"
literal|"<arg direction=\"out\" type=\"v\" name=\"pong2_invokable\" />\n"
literal|"</method>\n"
literal|"<method name=\"ping\">\n"
literal|"<arg direction=\"in\" type=\"ai\" name=\"ping\" />\n"
literal|"<arg direction=\"out\" type=\"ai\" name=\"ping\" />\n"
literal|"<annotation name=\"org.qtproject.QtDBus.QtTypeName.In0\" value=\"QList&lt;int&gt;\"/>\n"
literal|"<annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"QList&lt;int&gt;\"/>\n"
literal|"</method>\n"
literal|"<method name=\"ping_invokable\">\n"
literal|"<arg direction=\"in\" type=\"ai\" name=\"ping_invokable\" />\n"
literal|"<arg direction=\"out\" type=\"ai\" name=\"ping_invokable\" />\n"
literal|"<annotation name=\"org.qtproject.QtDBus.QtTypeName.In0\" value=\"QList&lt;int&gt;\"/>\n"
literal|"<annotation name=\"org.qtproject.QtDBus.QtTypeName.Out0\" value=\"QList&lt;int&gt;\"/>\n"
literal|"</method>\n"
literal|"</interface>\n"
literal|""
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int prop1 READ prop1 WRITE setProp1
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QList<int> complexProp READ complexProp WRITE setComplexProp
argument_list|)
name|public
operator|:
specifier|static
name|int
name|callCount
block|;
specifier|static
name|QVariantList
name|callArgs
block|;
name|MyObject
argument_list|()
block|{
name|QObject
operator|*
name|subObject
operator|=
name|new
name|QObject
argument_list|(
name|this
argument_list|)
block|;
name|subObject
operator|->
name|setObjectName
argument_list|(
literal|"subObject"
argument_list|)
block|;     }
name|int
name|m_prop1
block|;
name|int
name|prop1
argument_list|()
specifier|const
block|{
operator|++
name|callCount
block|;
return|return
name|m_prop1
return|;
block|}
name|void
name|setProp1
argument_list|(
argument|int value
argument_list|)
block|{
operator|++
name|callCount
block|;
name|m_prop1
operator|=
name|value
block|;     }
name|QList
operator|<
name|int
operator|>
name|m_complexProp
block|;
name|QList
operator|<
name|int
operator|>
name|complexProp
argument_list|()
specifier|const
block|{
operator|++
name|callCount
block|;
return|return
name|m_complexProp
return|;
block|}
name|void
name|setComplexProp
argument_list|(
argument|const QList<int>&value
argument_list|)
block|{
operator|++
name|callCount
block|;
name|m_complexProp
operator|=
name|value
block|;     }
name|Q_INVOKABLE
name|void
name|ping_invokable
argument_list|(
argument|QDBusMessage msg
argument_list|)
block|{
name|QDBusConnection
name|sender
operator|=
name|QDBusConnection
operator|::
name|sender
argument_list|()
block|;
if|if
condition|(
operator|!
name|sender
operator|.
name|isConnected
argument_list|()
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|++
name|callCount
block|;
name|callArgs
operator|=
name|msg
operator|.
name|arguments
argument_list|()
block|;
name|msg
operator|.
name|setDelayedReply
argument_list|(
name|true
argument_list|)
block|;
if|if
condition|(
operator|!
name|sender
operator|.
name|send
argument_list|(
name|msg
operator|.
name|createReply
argument_list|(
name|callArgs
argument_list|)
argument_list|)
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|public
name|slots
range|:
name|void
name|ping
argument_list|(
argument|QDBusMessage msg
argument_list|)
block|{
name|QDBusConnection
name|sender
operator|=
name|QDBusConnection
operator|::
name|sender
argument_list|()
block|;
if|if
condition|(
operator|!
name|sender
operator|.
name|isConnected
argument_list|()
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|++
name|callCount
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|callArgs
operator|=
name|msg
operator|.
name|arguments
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|msg
operator|.
name|setDelayedReply
argument_list|(
name|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|sender
operator|.
name|send
argument_list|(
name|msg
operator|.
name|createReply
argument_list|(
name|callArgs
argument_list|)
argument_list|)
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_if
begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// INTERFACE_H
end_comment
end_unit
