begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|variable|QCoreApplicationPrivate
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
begin_decl_stmt
DECL|variable|QAbstractNativeEventFilter
name|class
name|QAbstractNativeEventFilter
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
name|Q_PROPERTY
argument_list|(
argument|bool quitLockEnabled READ isQuitLockEnabled WRITE setQuitLockEnabled
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
ifndef|#
directive|ifndef
name|Q_QDOC
argument_list|,
name|int
operator|=
name|ApplicationFlags
endif|#
directive|endif
argument_list|)
block|;
operator|~
name|QCoreApplication
argument_list|()
block|;
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
argument|QObject *receiver
argument_list|,
argument|QEvent *event
argument_list|,
argument|int priority = Qt::NormalEventPriority
argument_list|)
block|;
specifier|static
name|void
name|sendPostedEvents
argument_list|(
argument|QObject *receiver =
literal|0
argument_list|,
argument|int event_type =
literal|0
argument_list|)
block|;
specifier|static
name|void
name|removePostedEvents
argument_list|(
argument|QObject *receiver
argument_list|,
argument|int eventType =
literal|0
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
name|bool
name|installTranslator
argument_list|(
name|QTranslator
operator|*
name|messageFile
argument_list|)
block|;
specifier|static
name|bool
name|removeTranslator
argument_list|(
name|QTranslator
operator|*
name|messageFile
argument_list|)
block|;
endif|#
directive|endif
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
argument|int n = -
literal|1
argument_list|)
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
block|enum
name|Encoding
block|{
name|UnicodeUTF8
block|,
name|Latin1
block|,
name|DefaultCodec
operator|=
name|UnicodeUTF8
block|,
name|CodecForTr
operator|=
name|UnicodeUTF8
block|}
block|;
name|QT_DEPRECATED
specifier|static
specifier|inline
name|QString
name|translate
argument_list|(
argument|const char * context
argument_list|,
argument|const char * key
argument_list|,
argument|const char * disambiguation
argument_list|,
argument|Encoding
argument_list|,
argument|int n = -
literal|1
argument_list|)
block|{
return|return
name|translate
argument_list|(
name|context
argument_list|,
name|key
argument_list|,
name|disambiguation
argument_list|,
name|n
argument_list|)
return|;
block|}
endif|#
directive|endif
specifier|static
name|void
name|flush
argument_list|()
block|;
name|void
name|installNativeEventFilter
argument_list|(
name|QAbstractNativeEventFilter
operator|*
name|filterObj
argument_list|)
block|;
name|void
name|removeNativeEventFilter
argument_list|(
name|QAbstractNativeEventFilter
operator|*
name|filterObj
argument_list|)
block|;
specifier|static
name|bool
name|isQuitLockEnabled
argument_list|()
block|;
specifier|static
name|void
name|setQuitLockEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
specifier|static
name|void
name|quit
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|aboutToQuit
argument_list|(
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|QPrivateSignal
endif|#
directive|endif
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|compressEvent
argument_list|(
name|QEvent
operator|*
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
name|QPostEventList
operator|*
argument_list|)
block|;
name|protected
operator|:
name|QCoreApplication
argument_list|(
name|QCoreApplicationPrivate
operator|&
name|p
argument_list|)
block|;
name|private
operator|:
specifier|static
name|bool
name|sendSpontaneousEvent
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
name|bool
name|notifyInternal
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
name|void
name|init
argument_list|()
block|;
specifier|static
name|QCoreApplication
operator|*
name|self
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QCoreApplication
argument_list|)
name|friend
name|class
name|QEventDispatcherUNIXPrivate
block|;
name|friend
name|class
name|QApplication
block|;
name|friend
name|class
name|QApplicationPrivate
block|;
name|friend
name|class
name|QGuiApplication
block|;
name|friend
name|class
name|QGuiApplicationPrivate
block|;
name|friend
name|class
name|QETWidget
block|;
name|friend
name|class
name|QWidget
block|;
name|friend
name|class
name|QWidgetWindow
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|friend
name|class
name|QCocoaEventDispatcherPrivate
block|;
name|friend
name|bool
name|qt_sendSpontaneousEvent
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|friend
name|Q_CORE_EXPORT
name|QString
name|qAppName
argument_list|()
block|;
name|friend
name|class
name|QClassFactory
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
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
begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|QT_NO_TRANSLATION
end_ifdef
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
argument|int
argument_list|)
block|{
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|sourceText
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
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
value|public: \     static inline QString tr(const char *sourceText, const char *disambiguation = 0, int n = -1) \         { return QCoreApplication::translate(#context, sourceText, disambiguation, n); } \     QT_DEPRECATED static inline QString trUtf8(const char *sourceText, const char *disambiguation = 0, int n = -1) \         { return QCoreApplication::translate(#context, sourceText, disambiguation, n); } \ private:
end_define
begin_typedef
DECL|typedef|QtStartUpFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|QtStartUpFunction
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_typedef
DECL|typedef|QtCleanUpFunction
typedef|typedef
name|void
function_decl|(
modifier|*
name|QtCleanUpFunction
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_function_decl
name|Q_CORE_EXPORT
name|void
name|qAddPreRoutine
parameter_list|(
name|QtStartUpFunction
parameter_list|)
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
begin_define
DECL|macro|Q_COREAPP_STARTUP_FUNCTION
define|#
directive|define
name|Q_COREAPP_STARTUP_FUNCTION
parameter_list|(
name|AFUNC
parameter_list|)
define|\
value|static void AFUNC ## _ctor_function() {  \         qAddPreRoutine(AFUNC);        \     }                                 \     Q_CONSTRUCTOR_FUNCTION(AFUNC ## _ctor_function)
end_define
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
