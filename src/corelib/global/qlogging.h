begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QLOGGING_H
end_ifndef
begin_define
DECL|macro|QLOGGING_H
define|#
directive|define
name|QLOGGING_H
end_define
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// header is automatically included in qglobal.h
end_comment
begin_pragma
pragma|#
directive|pragma
name|qt_no_master_include
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*   Forward declarations only.    In order to use the qDebug() stream, you must #include<QDebug> */
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNoDebug
name|class
name|QNoDebug
decl_stmt|;
end_decl_stmt
begin_enum
DECL|enum|QtMsgType
DECL|enumerator|QtDebugMsg
DECL|enumerator|QtWarningMsg
DECL|enumerator|QtCriticalMsg
DECL|enumerator|QtFatalMsg
DECL|enumerator|QtSystemMsg
enum|enum
name|QtMsgType
block|{
name|QtDebugMsg
block|,
name|QtWarningMsg
block|,
name|QtCriticalMsg
block|,
name|QtFatalMsg
block|,
name|QtSystemMsg
init|=
name|QtCriticalMsg
block|}
enum|;
end_enum
begin_decl_stmt
name|class
name|QMessageLogContext
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QMessageLogContext
argument_list|)
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QMessageLogContext
argument_list|()
operator|:
name|version
argument_list|(
literal|1
argument_list|)
operator|,
name|line
argument_list|(
literal|0
argument_list|)
operator|,
name|file
argument_list|(
literal|0
argument_list|)
operator|,
name|function
argument_list|(
literal|0
argument_list|)
operator|,
name|category
argument_list|(
literal|0
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QMessageLogContext
argument_list|(
argument|const char *fileName
argument_list|,
argument|int lineNumber
argument_list|,
argument|const char *functionName
argument_list|,
argument|const char *categoryName
argument_list|)
operator|:
name|version
argument_list|(
literal|1
argument_list|)
operator|,
name|line
argument_list|(
name|lineNumber
argument_list|)
operator|,
name|file
argument_list|(
name|fileName
argument_list|)
operator|,
name|function
argument_list|(
name|functionName
argument_list|)
operator|,
name|category
argument_list|(
argument|categoryName
argument_list|)
block|{}
name|void
name|copy
argument_list|(
specifier|const
name|QMessageLogContext
operator|&
name|logContext
argument_list|)
expr_stmt|;
name|int
name|version
decl_stmt|;
name|int
name|line
decl_stmt|;
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
specifier|const
name|char
modifier|*
name|function
decl_stmt|;
specifier|const
name|char
modifier|*
name|category
decl_stmt|;
name|private
label|:
name|friend
name|class
name|QMessageLogger
decl_stmt|;
name|friend
name|class
name|QDebug
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QLoggingCategory
name|class
name|QLoggingCategory
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QMessageLogger
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QMessageLogger
argument_list|)
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QMessageLogger
argument_list|()
operator|:
name|context
argument_list|()
block|{}
name|Q_DECL_CONSTEXPR
name|QMessageLogger
argument_list|(
argument|const char *file
argument_list|,
argument|int line
argument_list|,
argument|const char *function
argument_list|)
operator|:
name|context
argument_list|(
argument|file
argument_list|,
argument|line
argument_list|,
argument|function
argument_list|,
literal|"default"
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QMessageLogger
argument_list|(
argument|const char *file
argument_list|,
argument|int line
argument_list|,
argument|const char *function
argument_list|,
argument|const char *category
argument_list|)
operator|:
name|context
argument_list|(
argument|file
argument_list|,
argument|line
argument_list|,
argument|function
argument_list|,
argument|category
argument_list|)
block|{}
name|void
name|debug
argument_list|(
argument|const char *msg
argument_list|,
argument|...
argument_list|)
specifier|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|void
name|noDebug
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
block|{}
name|void
name|warning
argument_list|(
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|void
name|critical
argument_list|(
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
typedef|typedef
name|QLoggingCategory
modifier|&
function_decl|(
modifier|*
name|CategoryFunction
function_decl|)
parameter_list|()
function_decl|;
name|void
name|debug
argument_list|(
specifier|const
name|QLoggingCategory
operator|&
name|cat
argument_list|,
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|void
name|debug
argument_list|(
name|CategoryFunction
name|catFunc
argument_list|,
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|void
name|warning
argument_list|(
specifier|const
name|QLoggingCategory
operator|&
name|cat
argument_list|,
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|void
name|warning
argument_list|(
name|CategoryFunction
name|catFunc
argument_list|,
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|void
name|critical
argument_list|(
specifier|const
name|QLoggingCategory
operator|&
name|cat
argument_list|,
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|void
name|critical
argument_list|(
name|CategoryFunction
name|catFunc
argument_list|,
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_CC_MSVC
name|Q_NORETURN
endif|#
directive|endif
name|void
name|fatal
argument_list|(
specifier|const
name|char
operator|*
name|msg
argument_list|,
operator|...
argument_list|)
decl|const
name|Q_DECL_NOTHROW
name|Q_ATTRIBUTE_FORMAT_PRINTF
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|QDebug
name|debug
argument_list|()
specifier|const
expr_stmt|;
name|QDebug
name|debug
argument_list|(
specifier|const
name|QLoggingCategory
operator|&
name|cat
argument_list|)
decl|const
decl_stmt|;
name|QDebug
name|debug
argument_list|(
name|CategoryFunction
name|catFunc
argument_list|)
decl|const
decl_stmt|;
name|QDebug
name|warning
argument_list|()
specifier|const
expr_stmt|;
name|QDebug
name|warning
argument_list|(
specifier|const
name|QLoggingCategory
operator|&
name|cat
argument_list|)
decl|const
decl_stmt|;
name|QDebug
name|warning
argument_list|(
name|CategoryFunction
name|catFunc
argument_list|)
decl|const
decl_stmt|;
name|QDebug
name|critical
argument_list|()
specifier|const
expr_stmt|;
name|QDebug
name|critical
argument_list|(
specifier|const
name|QLoggingCategory
operator|&
name|cat
argument_list|)
decl|const
decl_stmt|;
name|QDebug
name|critical
argument_list|(
name|CategoryFunction
name|catFunc
argument_list|)
decl|const
decl_stmt|;
name|QNoDebug
name|noDebug
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_DEBUG_STREAM
name|private
label|:
name|QMessageLogContext
name|context
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*   qDebug, qWarning, qCritical, qFatal are redefined to automatically include context information  */
end_comment
begin_define
DECL|macro|qDebug
define|#
directive|define
name|qDebug
value|QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).debug
end_define
begin_define
DECL|macro|qWarning
define|#
directive|define
name|qWarning
value|QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).warning
end_define
begin_define
DECL|macro|qCritical
define|#
directive|define
name|qCritical
value|QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).critical
end_define
begin_define
DECL|macro|qFatal
define|#
directive|define
name|qFatal
value|QMessageLogger(__FILE__, __LINE__, Q_FUNC_INFO).fatal
end_define
begin_define
DECL|macro|QT_NO_QDEBUG_MACRO
define|#
directive|define
name|QT_NO_QDEBUG_MACRO
value|while (false) QMessageLogger().noDebug
end_define
begin_define
DECL|macro|QT_NO_QWARNING_MACRO
define|#
directive|define
name|QT_NO_QWARNING_MACRO
value|while (false) QMessageLogger().noDebug
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DEBUG_OUTPUT
argument_list|)
end_if
begin_undef
DECL|macro|qDebug
undef|#
directive|undef
name|qDebug
end_undef
begin_define
DECL|macro|qDebug
define|#
directive|define
name|qDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_WARNING_OUTPUT
argument_list|)
end_if
begin_undef
DECL|macro|qWarning
undef|#
directive|undef
name|qWarning
end_undef
begin_define
DECL|macro|qWarning
define|#
directive|define
name|qWarning
value|QT_NO_QWARNING_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qt_message_output
parameter_list|(
name|QtMsgType
parameter_list|,
specifier|const
name|QMessageLogContext
modifier|&
name|context
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qErrnoWarning
parameter_list|(
name|int
name|code
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qErrnoWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
end_if
begin_comment
comment|// deprecated. Use qInstallMessageHandler instead!
end_comment
begin_typedef
DECL|typedef|QtMsgHandler
typedef|typedef
name|void
function_decl|(
modifier|*
name|QtMsgHandler
function_decl|)
parameter_list|(
name|QtMsgType
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
name|Q_CORE_EXPORT
name|QT_DEPRECATED
name|QtMsgHandler
name|qInstallMsgHandler
parameter_list|(
name|QtMsgHandler
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|QtMessageHandler
typedef|typedef
name|void
function_decl|(
modifier|*
name|QtMessageHandler
function_decl|)
parameter_list|(
name|QtMsgType
parameter_list|,
specifier|const
name|QMessageLogContext
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
name|Q_CORE_EXPORT
name|QtMessageHandler
name|qInstallMessageHandler
parameter_list|(
name|QtMessageHandler
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qSetMessagePattern
parameter_list|(
specifier|const
name|QString
modifier|&
name|messagePattern
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOGGING_H
end_comment
end_unit
