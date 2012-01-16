begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOREAPPLICATION_H
end_ifndef
begin_define
DECL|macro|QCOREAPPLICATION_H
define|#
directive|define
name|QCOREAPPLICATION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qeventloop.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|tagMSG
argument_list|)
end_if
begin_typedef
DECL|typedef|MSG
typedef|typedef
name|struct
name|tagMSG
name|MSG
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|QCoreApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCodec
name|class
name|QTextCodec
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTranslator
name|class
name|QTranslator
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPostEventList
name|class
name|QPostEventList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|qApp
define|#
directive|define
name|qApp
value|QCoreApplication::instance()
end_define
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QCoreApplication
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString applicationName READ applicationName WRITE setApplicationName
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString applicationVersion READ applicationVersion WRITE setApplicationVersion
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString organizationName READ organizationName WRITE setOrganizationName
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString organizationDomain READ organizationDomain WRITE setOrganizationDomain
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QCoreApplication
argument_list|)
name|public
operator|:
expr|enum
block|{
name|ApplicationFlags
operator|=
name|QT_VERSION
block|}
block|;      enum
name|Type
block|{
name|Tty
block|,
name|GuiClient
block|,
name|GuiServer
comment|// # deprecated
block|}
block|;
name|QCoreApplication
argument_list|(
name|int
operator|&
name|argc
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|,
name|int
operator|=
name|ApplicationFlags
argument_list|)
block|;
operator|~
name|QCoreApplication
argument_list|()
block|;
ifdef|#
directive|ifdef
name|QT_DEPRECATED
name|QT_DEPRECATED
specifier|static
name|int
name|argc
argument_list|()
block|;
name|QT_DEPRECATED
specifier|static
name|char
operator|*
operator|*
name|argv
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|QStringList
name|arguments
argument_list|()
block|;
specifier|static
name|void
name|setAttribute
argument_list|(
argument|Qt::ApplicationAttribute attribute
argument_list|,
argument|bool on = true
argument_list|)
block|;
specifier|static
name|bool
name|testAttribute
argument_list|(
argument|Qt::ApplicationAttribute attribute
argument_list|)
block|;
specifier|static
name|void
name|setOrganizationDomain
argument_list|(
specifier|const
name|QString
operator|&
name|orgDomain
argument_list|)
block|;
specifier|static
name|QString
name|organizationDomain
argument_list|()
block|;
specifier|static
name|void
name|setOrganizationName
argument_list|(
specifier|const
name|QString
operator|&
name|orgName
argument_list|)
block|;
specifier|static
name|QString
name|organizationName
argument_list|()
block|;
specifier|static
name|void
name|setApplicationName
argument_list|(
specifier|const
name|QString
operator|&
name|application
argument_list|)
block|;
specifier|static
name|QString
name|applicationName
argument_list|()
block|;
specifier|static
name|void
name|setApplicationVersion
argument_list|(
specifier|const
name|QString
operator|&
name|version
argument_list|)
block|;
specifier|static
name|QString
name|applicationVersion
argument_list|()
block|;
specifier|static
name|QCoreApplication
operator|*
name|instance
argument_list|()
block|{
return|return
name|self
return|;
block|}
specifier|static
name|int
name|exec
argument_list|()
block|;
specifier|static
name|void
name|processEvents
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags = QEventLoop::AllEvents
argument_list|)
block|;
specifier|static
name|void
name|processEvents
argument_list|(
argument|QEventLoop::ProcessEventsFlags flags
argument_list|,
argument|int maxtime
argument_list|)
block|;
specifier|static
name|void
name|exit
argument_list|(
argument|int retcode=
literal|0
argument_list|)
block|;
specifier|static
name|bool
name|sendEvent
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
specifier|static
name|void
name|postEvent
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
specifier|static
name|void
name|postEvent
argument_list|(
argument|QObject *receiver
argument_list|,
argument|QEvent *event
argument_list|,
argument|int priority
argument_list|)
block|;
specifier|static
name|void
name|sendPostedEvents
argument_list|(
argument|QObject *receiver
argument_list|,
argument|int event_type
argument_list|)
block|;
specifier|static
name|void
name|sendPostedEvents
argument_list|()
block|;
specifier|static
name|void
name|removePostedEvents
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|)
block|;
specifier|static
name|void
name|removePostedEvents
argument_list|(
argument|QObject *receiver
argument_list|,
argument|int eventType
argument_list|)
block|;
specifier|static
name|bool
name|hasPendingEvents
argument_list|()
block|;
specifier|static
name|QAbstractEventDispatcher
operator|*
name|eventDispatcher
argument_list|()
block|;
specifier|static
name|void
name|setEventDispatcher
argument_list|(
name|QAbstractEventDispatcher
operator|*
name|eventDispatcher
argument_list|)
block|;
name|virtual
name|bool
name|notify
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
specifier|static
name|bool
name|startingUp
argument_list|()
block|;
specifier|static
name|bool
name|closingDown
argument_list|()
block|;
specifier|static
name|QString
name|applicationDirPath
argument_list|()
block|;
specifier|static
name|QString
name|applicationFilePath
argument_list|()
block|;
specifier|static
name|qint64
name|applicationPid
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
specifier|static
name|void
name|setLibraryPaths
argument_list|(
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
specifier|static
name|QStringList
name|libraryPaths
argument_list|()
block|;
specifier|static
name|void
name|addLibraryPath
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
specifier|static
name|void
name|removeLibraryPath
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_LIBRARY
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
specifier|static
name|void
name|installTranslator
argument_list|(
name|QTranslator
operator|*
name|messageFile
argument_list|)
block|;
specifier|static
name|void
name|removeTranslator
argument_list|(
name|QTranslator
operator|*
name|messageFile
argument_list|)
block|;
endif|#
directive|endif
block|enum
name|Encoding
block|{
name|CodecForTr
block|,
name|UnicodeUTF8
block|,
name|DefaultCodec
operator|=
name|CodecForTr
block|}
block|;
specifier|static
name|QString
name|translate
argument_list|(
argument|const char * context
argument_list|,
argument|const char * key
argument_list|,
argument|const char * disambiguation =
literal|0
argument_list|,
argument|Encoding encoding = CodecForTr
argument_list|,
argument|int n = -
literal|1
argument_list|)
block|;
specifier|static
name|void
name|flush
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|virtual
name|bool
name|winEventFilter
argument_list|(
name|MSG
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
specifier|static
name|void
name|watchUnixSignal
argument_list|(
argument|int signal
argument_list|,
argument|bool watch
argument_list|)
block|;
endif|#
directive|endif
typedef|typedef
name|bool
function_decl|(
modifier|*
name|EventFilter
function_decl|)
parameter_list|(
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
name|EventFilter
name|setEventFilter
argument_list|(
argument|EventFilter filter
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|filterEvent
parameter_list|(
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|public
name|Q_SLOTS
range|:
specifier|static
name|void
name|quit
argument_list|()
decl_stmt|;
end_decl_stmt
begin_label
name|Q_SIGNALS
label|:
end_label
begin_function_decl
name|void
name|aboutToQuit
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|unixSignal
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_function_decl
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|compressEvent
parameter_list|(
name|QEvent
modifier|*
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
name|QPostEventList
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QCoreApplication
argument_list|(
name|QCoreApplicationPrivate
operator|&
name|p
argument_list|)
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_initializeProcessManager()
argument_list|)
end_macro
begin_function_decl
specifier|static
name|bool
name|sendSpontaneousEvent
parameter_list|(
name|QObject
modifier|*
name|receiver
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|notifyInternal
parameter_list|(
name|QObject
modifier|*
name|receiver
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|init
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|QCoreApplication
modifier|*
name|self
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QCoreApplication
argument_list|)
end_macro
begin_decl_stmt
name|friend
name|class
name|QEventDispatcherUNIXPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QApplication
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QGuiApplication
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QGuiApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QETWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QWidgetWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QCocoaEventDispatcherPrivate
decl_stmt|;
end_decl_stmt
begin_function_decl
name|friend
name|bool
name|qt_sendSpontaneousEvent
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|QEvent
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|friend
name|Q_CORE_EXPORT
name|QString
name|qAppName
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|friend
name|class
name|QClassFactory
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
DECL|function|sendEvent
specifier|inline
name|bool
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
argument|QObject *receiver
argument_list|,
argument|QEvent *event
argument_list|)
block|{
if|if
condition|(
name|event
condition|)
name|event
operator|->
name|spont
operator|=
name|false
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|self
condition|?
name|self
operator|->
name|notifyInternal
argument_list|(
name|receiver
argument_list|,
name|event
argument_list|)
else|:
name|false
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|sendSpontaneousEvent
name|bool
name|QCoreApplication
operator|::
name|sendSpontaneousEvent
argument_list|(
argument|QObject *receiver
argument_list|,
argument|QEvent *event
argument_list|)
block|{
if|if
condition|(
name|event
condition|)
name|event
operator|->
name|spont
operator|=
name|true
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|self
condition|?
name|self
operator|->
name|notifyInternal
argument_list|(
name|receiver
argument_list|,
name|event
argument_list|)
else|:
name|false
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|sendPostedEvents
name|void
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
block|{
name|sendPostedEvents
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|; }
ifdef|#
directive|ifdef
name|QT_NO_TRANSLATION
comment|// Simple versions
DECL|function|translate
specifier|inline
name|QString
name|QCoreApplication
operator|::
name|translate
argument_list|(
argument|const char *
argument_list|,
argument|const char *sourceText
argument_list|,
argument|const char *
argument_list|,
argument|Encoding encoding
argument_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
if|if
condition|(
name|encoding
operator|==
name|UnicodeUTF8
condition|)
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|sourceText
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|encoding
argument_list|)
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|sourceText
argument_list|)
return|;
end_return
begin_comment
unit|}
comment|// Simple versions
end_comment
begin_expr_stmt
unit|inline
DECL|function|translate
name|QString
name|QCoreApplication
operator|::
name|translate
argument_list|(
argument|const char *
argument_list|,
argument|const char *sourceText
argument_list|,
argument|const char *
argument_list|,
argument|Encoding encoding
argument_list|,
argument|int
argument_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
if|if
condition|(
name|encoding
operator|==
name|UnicodeUTF8
condition|)
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|sourceText
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|encoding
argument_list|)
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|sourceText
argument_list|)
return|;
end_return
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_DECLARE_TR_FUNCTIONS
define|#
directive|define
name|Q_DECLARE_TR_FUNCTIONS
parameter_list|(
name|context
parameter_list|)
define|\
value|public: \     static inline QString tr(const char *sourceText, const char *disambiguation = 0, int n = -1) \         { return QCoreApplication::translate(#context, sourceText, disambiguation, \                                              QCoreApplication::CodecForTr, n); } \     static inline QString trUtf8(const char *sourceText, const char *disambiguation = 0, int n = -1) \         { return QCoreApplication::translate(#context, sourceText, disambiguation, \                                              QCoreApplication::UnicodeUTF8, n); } \ private:
end_define
begin_function_decl
unit|typedef
DECL|typedef|QtCleanUpFunction
name|void
function_decl|(
modifier|*
name|QtCleanUpFunction
function_decl|)
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qAddPostRoutine
parameter_list|(
name|QtCleanUpFunction
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qRemovePostRoutine
parameter_list|(
name|QtCleanUpFunction
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|QString
name|qAppName
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// get application name
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
end_if
begin_function_decl
name|Q_CORE_EXPORT
name|QString
name|decodeMSG
parameter_list|(
specifier|const
name|MSG
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|MSG
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOREAPPLICATION_H
end_comment
end_unit
