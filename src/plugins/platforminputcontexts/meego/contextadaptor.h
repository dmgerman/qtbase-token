begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONTEXT_H_1318935171
end_ifndef
begin_define
DECL|macro|CONTEXT_H_1318935171
define|#
directive|define
name|CONTEXT_H_1318935171
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
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QMap
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|Value
operator|>
name|class
name|QMap
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*  * Adaptor class for interface com.meego.inputmethod.inputcontext1  */
end_comment
begin_decl_stmt
name|class
name|Inputcontext1Adaptor
range|:
name|public
name|QDBusAbstractAdaptor
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"com.meego.inputmethod.inputcontext1"
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Introspection"
argument_list|,
literal|""
literal|"<interface name=\"com.meego.inputmethod.inputcontext1\">\n"
literal|"<method name=\"activationLostEvent\"/>\n"
literal|"<method name=\"imInitiatedHide\"/>\n"
literal|"<method name=\"commitString\">\n"
literal|"<arg type=\"s\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"</method>\n"
literal|"<method name=\"updatePreedit\">\n"
literal|"<arg type=\"s\"/>\n"
literal|"<arg type=\"a(iii)\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"</method>\n"
literal|"<method name=\"keyEvent\">\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"s\"/>\n"
literal|"<arg type=\"b\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"y\"/>\n"
literal|"</method>\n"
literal|"<method name=\"updateInputMethodArea\">\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"</method>\n"
literal|"<method name=\"setGlobalCorrectionEnabled\">\n"
literal|"<arg type=\"b\"/>\n"
literal|"</method>\n"
literal|"<method name=\"preeditRectangle\">\n"
literal|"<arg direction=\"out\" type=\"b\"/>\n"
literal|"<arg direction=\"out\" type=\"i\"/>\n"
literal|"<arg direction=\"out\" type=\"i\"/>\n"
literal|"<arg direction=\"out\" type=\"i\"/>\n"
literal|"<arg direction=\"out\" type=\"i\"/>\n"
literal|"</method>\n"
literal|"<method name=\"copy\"/>\n"
literal|"<method name=\"paste\"/>\n"
literal|"<method name=\"setRedirectKeys\">\n"
literal|"<arg type=\"b\"/>\n"
literal|"</method>\n"
literal|"<method name=\"setDetectableAutoRepeat\">\n"
literal|"<arg type=\"b\"/>\n"
literal|"</method>\n"
literal|"<method name=\"setSelection\">\n"
literal|"<arg type=\"i\"/>\n"
literal|"<arg type=\"i\"/>\n"
literal|"</method>\n"
literal|"<method name=\"selection\">\n"
literal|"<arg direction=\"out\" type=\"b\"/>\n"
literal|"<arg direction=\"out\" type=\"s\"/>\n"
literal|"</method>\n"
literal|"<method name=\"setLanguage\">\n"
literal|"<arg type=\"s\"/>\n"
literal|"</method>\n"
literal|"</interface>\n"
literal|""
argument_list|)
name|public
operator|:
name|Inputcontext1Adaptor
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|virtual
operator|~
name|Inputcontext1Adaptor
argument_list|()
block|;
name|public
operator|:
comment|// PROPERTIES
name|public
name|Q_SLOTS
operator|:
comment|// METHODS
name|void
name|activationLostEvent
argument_list|()
block|;
name|void
name|commitString
argument_list|(
argument|const QString&in0
argument_list|,
argument|int in1
argument_list|,
argument|int in2
argument_list|,
argument|int in3
argument_list|)
block|;
name|void
name|updatePreedit
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|message
argument_list|)
block|;
name|void
name|copy
argument_list|()
block|;
name|void
name|imInitiatedHide
argument_list|()
block|;
name|void
name|keyEvent
argument_list|(
argument|int in0
argument_list|,
argument|int in1
argument_list|,
argument|int in2
argument_list|,
argument|const QString&in3
argument_list|,
argument|bool in4
argument_list|,
argument|int in5
argument_list|,
argument|uchar in6
argument_list|)
block|;
name|void
name|paste
argument_list|()
block|;
name|bool
name|preeditRectangle
argument_list|(
name|int
operator|&
name|out1
argument_list|,
name|int
operator|&
name|out2
argument_list|,
name|int
operator|&
name|out3
argument_list|,
name|int
operator|&
name|out4
argument_list|)
block|;
name|bool
name|selection
argument_list|(
name|QString
operator|&
name|out1
argument_list|)
block|;
name|void
name|setDetectableAutoRepeat
argument_list|(
argument|bool in0
argument_list|)
block|;
name|void
name|setGlobalCorrectionEnabled
argument_list|(
argument|bool in0
argument_list|)
block|;
name|void
name|setLanguage
argument_list|(
specifier|const
name|QString
operator|&
name|in0
argument_list|)
block|;
name|void
name|setRedirectKeys
argument_list|(
argument|bool in0
argument_list|)
block|;
name|void
name|setSelection
argument_list|(
argument|int in0
argument_list|,
argument|int in1
argument_list|)
block|;
name|void
name|updateInputMethodArea
argument_list|(
argument|int in0
argument_list|,
argument|int in1
argument_list|,
argument|int in2
argument_list|,
argument|int in3
argument_list|)
block|;
name|Q_SIGNALS
operator|:
comment|// SIGNALS
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
