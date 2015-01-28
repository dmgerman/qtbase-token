begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|variable|QObject
name|class
name|MyObject
range|:
name|public
name|QObject
decl_stmt|,
name|protected
name|QDBusContext
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
name|int
name|prop1
name|READ
name|prop1
name|WRITE
name|setProp1
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QList
operator|<
name|int
operator|>
name|complexProp
name|READ
name|complexProp
name|WRITE
name|setComplexProp
argument_list|)
name|public
range|:
specifier|static
name|int
name|callCount
decl_stmt|;
specifier|static
name|QVariantList
name|callArgs
decl_stmt|;
name|MyObject
argument_list|()
block|{
name|QObject
modifier|*
name|subObject
init|=
name|new
name|QObject
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|subObject
operator|->
name|setObjectName
argument_list|(
literal|"subObject"
argument_list|)
expr_stmt|;
block|}
name|int
name|m_prop1
decl_stmt|;
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
parameter_list|(
name|int
name|value
parameter_list|)
block|{
operator|++
name|callCount
expr_stmt|;
name|m_prop1
operator|=
name|value
expr_stmt|;
block|}
name|QList
operator|<
name|int
operator|>
name|m_complexProp
expr_stmt|;
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
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|value
argument_list|)
block|{
operator|++
name|callCount
expr_stmt|;
name|m_complexProp
operator|=
name|value
expr_stmt|;
block|}
name|Q_INVOKABLE
name|void
name|ping_invokable
parameter_list|(
name|QDBusMessage
name|msg
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|QDBusContext
operator|::
name|calledFromDBus
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|callCount
expr_stmt|;
name|callArgs
operator|=
name|msg
operator|.
name|arguments
argument_list|()
expr_stmt|;
name|msg
operator|.
name|setDelayedReply
argument_list|(
name|true
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QDBusContext
operator|::
name|connection
argument_list|()
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
name|public
name|slots
range|:
name|void
name|ping
argument_list|(
argument|QDBusMessage msg
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|QDBusContext
operator|::
name|calledFromDBus
argument_list|()
argument_list|)
block|;
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
name|QDBusContext
operator|::
name|connection
argument_list|()
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
block|}
end_decl_stmt
begin_empty_stmt
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
