begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qloggingcategory.h"
end_include
begin_include
include|#
directive|include
file|"qloggingregistry_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|qtDefaultCategoryName
specifier|const
name|char
name|qtDefaultCategoryName
index|[]
init|=
literal|"default"
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
argument|QLoggingCategory
argument_list|,
argument|qtDefaultCategory
argument_list|,
argument|(qtDefaultCategoryName)
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|Q_ATOMIC_INT8_IS_SUPPORTED
end_ifndef
begin_function
DECL|function|setBoolLane
specifier|static
name|void
name|setBoolLane
parameter_list|(
name|QBasicAtomicInt
modifier|*
name|atomic
parameter_list|,
name|bool
name|enable
parameter_list|,
name|int
name|shift
parameter_list|)
block|{
specifier|const
name|int
name|bit
init|=
literal|1
operator|<<
name|shift
decl_stmt|;
if|if
condition|(
name|enable
condition|)
name|atomic
operator|->
name|fetchAndOrRelaxed
argument_list|(
name|bit
argument_list|)
expr_stmt|;
else|else
name|atomic
operator|->
name|fetchAndAndRelaxed
argument_list|(
operator|~
name|bit
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \class QLoggingCategory     \inmodule QtCore     \since 5.2      \brief The QLoggingCategory class represents a category, or 'area' in the     logging infrastructure.      QLoggingCategory represents a certain logging category - identified by a     string - at runtime. A category can be configured to enable or disable     logging of messages per message type. Whether a message type is enabled or     not can be checked with the \l isDebugEnabled(), \l isWarningEnabled(), and     \l isCriticalEnabled() methods.      All objects are meant to be configured by a common registry (see also     \l{Configuring Categories}). Different objects can also represent the same     category. It is therefore not recommended to export objects across module     boundaries, nor to manipulate the objects directly, nor to inherit from     QLoggingCategory.      \section1 Creating Category Objects      The Q_DECLARE_LOGGING_CATEGORY() and Q_LOGGING_CATEGORY() macros     conveniently declare and create QLoggingCategory objects:      \snippet qloggingcategory/main.cpp 1      \section1 Checking Category Configuration      QLoggingCategory provides \l isDebugEnabled(), \l isWarningEnabled(),     \l isCriticalEnabled(), as well as \l isEnabled()     to check whether messages for the given message type should be logged.      \note The qCDebug(), qCWarning(), qCCritical() macros prevent arguments     from being evaluated if the respective message types are not enabled for the     category, so explicit checking is not needed:      \snippet qloggingcategory/main.cpp 4      \section1 Default Category Configuration      Both the QLoggingCategory constructor and the Q_LOGGING_CATEGORY() macro     accept an optional QtMsgType argument, which disables all message types with     a lower severity. That is, a category declared with      \snippet qloggingcategory/main.cpp 5      will log messages of type \c QtWarningMsg, \c QtCriticalMsg, \c QtFatalMsg, but will     ignore messages of type \c QtDebugMsg.      If no argument is passed, all messages will be logged.      \section1 Configuring Categories      The default configuration of categories can be overridden either by setting logging     rules, or by installing a custom filter.      \section2 Logging Rules      Logging rules allow logging for categories to be enabled or disabled in a     flexible way. Rules are specified in text, where every line must have the     format      \code<category>[.<type>] = true|false     \endcode      \c<category> is the name of the category, potentially with \c{*} as a     wildcard symbol as the first or last character (or at both positions).     The optional \c<type> must be either \c debug, \c warning, or \c critical.     Lines that do not fit this scheme are ignored.      Rules are evaluated in text order, from first to last. That is, if two rules     apply to a category/type, the rule that comes later is applied.      Rules can be set via \l setFilterRules(). Since Qt 5.3, logging rules can also     be set in the \c QT_LOGGING_RULES environment variable, and     are automatically loaded from the \c [Rules] section of a logging     configuration file. Such configuration files are looked up in the QtProject     configuration directory, or explicitly set in a \c QT_LOGGING_CONF     environment variable:      \code     [Rules]     *.debug=false     driver.usb.debug=true     \endcode      Rules set by \l setFilterRules() take precedence over rules specified     in the QtProject configuration directory, and can, in turn, be     overwritten by rules from the configuration file specified by     \c QT_LOGGING_CONF, and rules set by \c QT_LOGGING_RULES.       Order of evaluation:     \list     \li Rules from QtProject/qtlogging.ini     \li Rules set by \l setFilterRules()     \li Rules from file in \c QT_LOGGING_CONF     \li Rules from environment variable QT_LOGGING_RULES     \endlist      The \c QtProject/qtlogging.ini file is looked up in all directories returned     by QStandardPaths::GenericConfigLocation, e.g.      \list     \li on Mac OS X: \c ~/Library/Preferences     \li on Unix: \c ~/.config, \c /etc/xdg     \li on Windows: \c %LOCALAPPDATA%, \c %ProgramData%,         \l QCoreApplication::applicationDirPath(),         QCoreApplication::applicationDirPath() + \c "/data"     \endlist      Set the \c QT_LOGGING_DEBUG environment variable to see from where     logging rules are loaded.      \section2 Installing a Custom Filter      As a lower-level alternative to the text rules, you can also implement a     custom filter via \l installFilter(). All filter rules are ignored in this     case.      \section1 Printing the Category      Use the \c %{category} placeholder to print the category in the default     message handler:      \snippet qloggingcategory/main.cpp 3 */
end_comment
begin_comment
comment|/*!     Constructs a QLoggingCategory object with the provided \a category name.     All message types for this category are enabled by default.      If \a category is \c{0}, the category name is changed to \c "default". */
end_comment
begin_constructor
DECL|function|QLoggingCategory
name|QLoggingCategory
operator|::
name|QLoggingCategory
parameter_list|(
specifier|const
name|char
modifier|*
name|category
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|name
argument_list|(
literal|0
argument_list|)
block|{
name|init
argument_list|(
name|category
argument_list|,
name|QtDebugMsg
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QLoggingCategory object with the provided \a category name,     and enables all messages with types more severe or equal than \a enableForLevel.      If \a category is \c{0}, the category name is changed to \c "default".      \since 5.4 */
end_comment
begin_constructor
DECL|function|QLoggingCategory
name|QLoggingCategory
operator|::
name|QLoggingCategory
parameter_list|(
specifier|const
name|char
modifier|*
name|category
parameter_list|,
name|QtMsgType
name|enableForLevel
parameter_list|)
member_init_list|:
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|name
argument_list|(
literal|0
argument_list|)
block|{
name|init
argument_list|(
name|category
argument_list|,
name|enableForLevel
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|init
name|void
name|QLoggingCategory
operator|::
name|init
parameter_list|(
specifier|const
name|char
modifier|*
name|category
parameter_list|,
name|QtMsgType
name|severityLevel
parameter_list|)
block|{
name|enabled
operator|.
name|store
argument_list|(
literal|0x01010101
argument_list|)
expr_stmt|;
comment|// enabledDebug = enabledWarning = enabledCritical = true;
if|if
condition|(
name|category
condition|)
name|name
operator|=
name|category
expr_stmt|;
else|else
name|name
operator|=
name|qtDefaultCategoryName
expr_stmt|;
if|if
condition|(
name|QLoggingRegistry
modifier|*
name|reg
init|=
name|QLoggingRegistry
operator|::
name|instance
argument_list|()
condition|)
name|reg
operator|->
name|registerCategory
argument_list|(
name|this
argument_list|,
name|severityLevel
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Destructs a QLoggingCategory object. */
end_comment
begin_destructor
DECL|function|~QLoggingCategory
name|QLoggingCategory
operator|::
name|~
name|QLoggingCategory
parameter_list|()
block|{
if|if
condition|(
name|QLoggingRegistry
modifier|*
name|reg
init|=
name|QLoggingRegistry
operator|::
name|instance
argument_list|()
condition|)
name|reg
operator|->
name|unregisterCategory
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!    \fn const char *QLoggingCategory::categoryName() const      Returns the name of the category. */
end_comment
begin_comment
comment|/*!     \fn bool QLoggingCategory::isDebugEnabled() const      Returns \c true if debug messages should be shown for this category.     Returns \c false otherwise.      \note The \l qCDebug() macro already does this check before executing any     code. However, calling this method may be useful to avoid     expensive generation of data that is only used for debug output. */
end_comment
begin_comment
comment|/*!     \fn bool QLoggingCategory::isWarningEnabled() const      Returns \c true if warning messages should be shown for this category.     Returns \c false otherwise.      \note The \l qCWarning() macro already does this check before executing any     code. However, calling this method may be useful to avoid     expensive generation of data that is only used for debug output. */
end_comment
begin_comment
comment|/*!     \fn bool QLoggingCategory::isCriticalEnabled() const      Returns \c true if critical messages should be shown for this category.     Returns \c false otherwise.      \note The \l qCCritical() macro already does this check before executing any     code. However, calling this method may be useful to avoid     expensive generation of data that is only used for debug output. */
end_comment
begin_comment
comment|/*!     Returns \c true if a message of type \a msgtype for the category should be     shown. Returns \c false otherwise. */
end_comment
begin_function
DECL|function|isEnabled
name|bool
name|QLoggingCategory
operator|::
name|isEnabled
parameter_list|(
name|QtMsgType
name|msgtype
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|msgtype
condition|)
block|{
case|case
name|QtDebugMsg
case|:
return|return
name|isDebugEnabled
argument_list|()
return|;
case|case
name|QtWarningMsg
case|:
return|return
name|isWarningEnabled
argument_list|()
return|;
case|case
name|QtCriticalMsg
case|:
return|return
name|isCriticalEnabled
argument_list|()
return|;
case|case
name|QtFatalMsg
case|:
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Changes the message type \a type for the category to \a enable.      \note Changes only affect the current QLoggingCategory object, and won't     change the settings of other objects for the same category name.     Use either \l setFilterRules() or \l installFilter() to change the     configuration globally.      \note \c QtFatalMsg cannot be changed. It will always return \c true. */
end_comment
begin_function
DECL|function|setEnabled
name|void
name|QLoggingCategory
operator|::
name|setEnabled
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
name|bool
name|enable
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_ATOMIC_INT8_IS_SUPPORTED
case|case
name|QtDebugMsg
case|:
name|bools
operator|.
name|enabledDebug
operator|.
name|store
argument_list|(
name|enable
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtWarningMsg
case|:
name|bools
operator|.
name|enabledWarning
operator|.
name|store
argument_list|(
name|enable
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtCriticalMsg
case|:
name|bools
operator|.
name|enabledCritical
operator|.
name|store
argument_list|(
name|enable
argument_list|)
expr_stmt|;
break|break;
else|#
directive|else
case|case
name|QtDebugMsg
case|:
name|setBoolLane
argument_list|(
operator|&
name|enabled
argument_list|,
name|enable
argument_list|,
name|DebugShift
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtWarningMsg
case|:
name|setBoolLane
argument_list|(
operator|&
name|enabled
argument_list|,
name|enable
argument_list|,
name|WarningShift
argument_list|)
expr_stmt|;
break|break;
case|case
name|QtCriticalMsg
case|:
name|setBoolLane
argument_list|(
operator|&
name|enabled
argument_list|,
name|enable
argument_list|,
name|CriticalShift
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
case|case
name|QtFatalMsg
case|:
break|break;
block|}
block|}
end_function
begin_comment
comment|/*!     \fn QLoggingCategory&QLoggingCategory::operator()()      Returns the object itself. This allows both a QLoggingCategory variable, and     a factory method returning a QLoggingCategory, to be used in \l qCDebug(),     \l qCWarning(), \l qCCritical() macros.  */
end_comment
begin_comment
comment|/*!     \fn const QLoggingCategory&QLoggingCategory::operator()() const      Returns the object itself. This allows both a QLoggingCategory variable, and     a factory method returning a QLoggingCategory, to be used in \l qCDebug(),     \l qCWarning(), \l qCCritical() macros.  */
end_comment
begin_comment
comment|/*!     Returns a pointer to the global category \c "default" that     is used e.g. by qDebug(), qWarning(), qCritical(), qFatal().      \note The returned pointer may be null during destruction of     static objects.      \note Ownership of the category is not transferred, do not     \c delete the returned pointer.   */
end_comment
begin_function
DECL|function|defaultCategory
name|QLoggingCategory
modifier|*
name|QLoggingCategory
operator|::
name|defaultCategory
parameter_list|()
block|{
return|return
name|qtDefaultCategory
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \typedef QLoggingCategory::CategoryFilter      This is a typedef for a pointer to a function with the following     signature:      \snippet qloggingcategory/main.cpp 20      A function with this signature can be installed with \l installFilter(). */
end_comment
begin_comment
comment|/*!     Installs a function \a filter that is used to determine which categories     and message types should be enabled. Returns a pointer to the previous     installed filter.      Every QLoggingCategory object created is passed to the filter, and the     filter is free to change the respective category configuration with     \l setEnabled().      The filter might be called concurrently from different threads, and     therefore has to be reentrant.      Example:     \snippet qloggingcategory/main.cpp 21      An alternative way of configuring the default filter is via     \l setFilterRules().  */
end_comment
begin_function
name|QLoggingCategory
operator|::
name|CategoryFilter
DECL|function|installFilter
name|QLoggingCategory
operator|::
name|installFilter
parameter_list|(
name|QLoggingCategory
operator|::
name|CategoryFilter
name|filter
parameter_list|)
block|{
return|return
name|QLoggingRegistry
operator|::
name|instance
argument_list|()
operator|->
name|installFilter
argument_list|(
name|filter
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Configures which categories and message types should be enabled through a     a set of \a rules.      Example:      \snippet qloggingcategory/main.cpp 2      \note The rules might be ignored if a custom category filter is installed     with \l installFilter(), or if the user defined \c QT_LOGGING_CONF or \c QT_LOGGING_RULES     environment variable. */
end_comment
begin_function
DECL|function|setFilterRules
name|void
name|QLoggingCategory
operator|::
name|setFilterRules
parameter_list|(
specifier|const
name|QString
modifier|&
name|rules
parameter_list|)
block|{
name|QLoggingRegistry
operator|::
name|instance
argument_list|()
operator|->
name|setApiRules
argument_list|(
name|rules
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \macro qCDebug(category)     \relates QLoggingCategory     \since 5.2      Returns an output stream for debug messages in the logging category     \a category.      The macro expands to code that checks whether     \l QLoggingCategory::isDebugEnabled() evaluates to \c true.     If so, the stream arguments are processed and sent to the message handler.      Example:      \snippet qloggingcategory/main.cpp 10      \note Arguments are not processed if debug output for the category is not     enabled, so do not rely on any side effects.      \sa qDebug() */
end_comment
begin_comment
comment|/*!     \macro qCDebug(category, const char *message, ...)     \relates QLoggingCategory     \since 5.3      Logs a debug message \a message in the logging category \a category.     \a message might contain place holders that are replaced by additional     arguments, similar to the C printf() function.      Example:      \snippet qloggingcategory/main.cpp 13      \note Arguments might not be processed if debug output for the category is     not enabled, so do not rely on any side effects.      \sa qDebug() */
end_comment
begin_comment
comment|/*!     \macro qCWarning(category)     \relates QLoggingCategory     \since 5.2      Returns an output stream for warning messages in the logging category     \a category.      The macro expands to code that checks whether     \l QLoggingCategory::isWarningEnabled() evaluates to \c true.     If so, the stream arguments are processed and sent to the message handler.      Example:      \snippet qloggingcategory/main.cpp 11      \note Arguments are not processed if warning output for the category is not     enabled, so do not rely on any side effects.      \sa qWarning() */
end_comment
begin_comment
comment|/*!     \macro qCWarning(category, const char *message, ...)     \relates QLoggingCategory     \since 5.3      Logs a warning message \a message in the logging category \a category.     \a message might contain place holders that are replaced by additional     arguments, similar to the C printf() function.      Example:      \snippet qloggingcategory/main.cpp 14      \note Arguments might not be processed if warning output for the category is     not enabled, so do not rely on any side effects.      \sa qWarning() */
end_comment
begin_comment
comment|/*!     \macro qCCritical(category)     \relates QLoggingCategory     \since 5.2      Returns an output stream for critical messages in the logging category     \a category.      The macro expands to code that checks whether     \l QLoggingCategory::isCriticalEnabled() evaluates to \c true.     If so, the stream arguments are processed and sent to the message handler.      Example:      \snippet qloggingcategory/main.cpp 12      \note Arguments are not processed if critical output for the category is not     enabled, so do not rely on any side effects.      \sa qCritical() */
end_comment
begin_comment
comment|/*!     \macro qCCritical(category, const char *message, ...)     \relates QLoggingCategory     \since 5.3      Logs a critical message \a message in the logging category \a category.     \a message might contain place holders that are replaced by additional     arguments, similar to the C printf() function.      Example:      \snippet qloggingcategory/main.cpp 15      \note Arguments might not be processed if critical output for the category     is not enabled, so do not rely on any side effects.      \sa qCritical() */
end_comment
begin_comment
comment|/*!     \macro Q_DECLARE_LOGGING_CATEGORY(name)     \sa Q_LOGGING_CATEGORY()     \relates QLoggingCategory     \since 5.2      Declares a logging category \a name. The macro can be used to declare     a common logging category shared in different parts of the program.      This macro must be used outside of a class or method. */
end_comment
begin_comment
comment|/*!     \macro Q_LOGGING_CATEGORY(name, string)     \sa Q_DECLARE_LOGGING_CATEGORY()     \relates QLoggingCategory     \since 5.2      Defines a logging category \a name, and makes it configurable under the     \a string identifier. By default, all message types are enabled.      Only one translation unit in a library or executable can define a category     with a specific name.      This macro must be used outside of a class or method. */
end_comment
begin_comment
comment|/*!     \macro Q_LOGGING_CATEGORY(name, string, msgType)     \sa Q_DECLARE_LOGGING_CATEGORY()     \relates QLoggingCategory     \since 5.4      Defines a logging category \a name, and makes it configurable under the     \a string identifier. By default, messages of QtMsgType \a msgType     and more severe are enabled, types with a lower severity are disabled.      Only one translation unit in a library or executable can define a category     with a specific name.      This macro must be used outside of a class or method. It is only defined     if variadic macros are supported. */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
