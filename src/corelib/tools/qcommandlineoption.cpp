begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Laszlo Papp<lpapp@kde.org> ** Copyright (C) 2013 David Faure<faure@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcommandlineoption.h"
end_include
begin_include
include|#
directive|include
file|"qset.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QCommandLineOptionPrivate
class|class
name|QCommandLineOptionPrivate
super|:
specifier|public
name|QSharedData
block|{
public|public:
name|Q_NEVER_INLINE
DECL|function|QCommandLineOptionPrivate
specifier|explicit
name|QCommandLineOptionPrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
member_init_list|:
name|names
argument_list|(
name|removeInvalidNames
argument_list|(
name|QStringList
argument_list|(
name|name
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|hidden
argument_list|(
literal|false
argument_list|)
block|{ }
name|Q_NEVER_INLINE
DECL|function|QCommandLineOptionPrivate
specifier|explicit
name|QCommandLineOptionPrivate
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|names
parameter_list|)
member_init_list|:
name|names
argument_list|(
name|removeInvalidNames
argument_list|(
name|names
argument_list|)
argument_list|)
member_init_list|,
name|hidden
argument_list|(
literal|false
argument_list|)
block|{ }
specifier|static
name|QStringList
name|removeInvalidNames
parameter_list|(
name|QStringList
name|nameList
parameter_list|)
function_decl|;
comment|//! The list of names used for this option.
DECL|member|names
name|QStringList
name|names
decl_stmt|;
comment|//! The documentation name for the value, if one is expected
comment|//! Example: "-o<file>" means valueName == "file"
DECL|member|valueName
name|QString
name|valueName
decl_stmt|;
comment|//! The description used for this option.
DECL|member|description
name|QString
name|description
decl_stmt|;
comment|//! The list of default values used for this option.
DECL|member|defaultValues
name|QStringList
name|defaultValues
decl_stmt|;
comment|//! Show or hide in --help
DECL|member|hidden
name|bool
name|hidden
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \since 5.2     \class QCommandLineOption     \brief The QCommandLineOption class defines a possible command-line option.     \inmodule QtCore     \ingroup shared     \ingroup tools      This class is used to describe an option on the command line. It allows     different ways of defining the same option with multiple aliases possible.     It is also used to describe how the option is used - it may be a flag (e.g. \c{-v})     or take a value (e.g. \c{-o file}).      Examples:     \snippet code/src_corelib_tools_qcommandlineoption.cpp 0      \sa QCommandLineParser */
end_comment
begin_comment
comment|/*!     \fn QCommandLineOption&QCommandLineOption::operator=(QCommandLineOption&&other)      Move-assigns \a other to this QCommandLineOption instance.      \since 5.2 */
end_comment
begin_comment
comment|/*!     Constructs a command line option object with the name \a name.      The name can be either short or long. If the name is one character in     length, it is considered a short name. Option names must not be empty,     must not start with a dash or a slash character, must not contain a \c{=}     and cannot be repeated.      \sa setDescription(), setValueName(), setDefaultValues() */
end_comment
begin_constructor
DECL|function|QCommandLineOption
name|QCommandLineOption
operator|::
name|QCommandLineOption
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QCommandLineOptionPrivate
argument_list|(
name|name
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a command line option object with the names \a names.      This overload allows to set multiple names for the option, for instance     \c{o} and \c{output}.      The names can be either short or long. Any name in the list that is one     character in length is a short name. Option names must not be empty,     must not start with a dash or a slash character, must not contain a \c{=}     and cannot be repeated.      \sa setDescription(), setValueName(), setDefaultValues() */
end_comment
begin_constructor
DECL|function|QCommandLineOption
name|QCommandLineOption
operator|::
name|QCommandLineOption
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|names
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QCommandLineOptionPrivate
argument_list|(
name|names
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a command line option object with the given arguments.      The name of the option is set to \a name.     The name can be either short or long. If the name is one character in     length, it is considered a short name. Option names must not be empty,     must not start with a dash or a slash character, must not contain a \c{=}     and cannot be repeated.      The description is set to \a description. It is customary to add a "."     at the end of the description.      In addition, the \a valueName can be set if the option expects a value.     The default value for the option is set to \a defaultValue.      In Qt versions before 5.4, this constructor was \c explicit. In Qt 5.4     and later, it no longer is and can be used for C++11-style uniform     initialization:      \snippet code/src_corelib_tools_qcommandlineoption.cpp cxx11-init      \sa setDescription(), setValueName(), setDefaultValues() */
end_comment
begin_constructor
DECL|function|QCommandLineOption
name|QCommandLineOption
operator|::
name|QCommandLineOption
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|description
parameter_list|,
specifier|const
name|QString
modifier|&
name|valueName
parameter_list|,
specifier|const
name|QString
modifier|&
name|defaultValue
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QCommandLineOptionPrivate
argument_list|(
name|name
argument_list|)
argument_list|)
block|{
name|setValueName
argument_list|(
name|valueName
argument_list|)
expr_stmt|;
name|setDescription
argument_list|(
name|description
argument_list|)
expr_stmt|;
name|setDefaultValue
argument_list|(
name|defaultValue
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a command line option object with the given arguments.      This overload allows to set multiple names for the option, for instance     \c{o} and \c{output}.      The names of the option are set to \a names.     The names can be either short or long. Any name in the list that is one     character in length is a short name. Option names must not be empty,     must not start with a dash or a slash character, must not contain a \c{=}     and cannot be repeated.      The description is set to \a description. It is customary to add a "."     at the end of the description.      In addition, the \a valueName can be set if the option expects a value.     The default value for the option is set to \a defaultValue.      In Qt versions before 5.4, this constructor was \c explicit. In Qt 5.4     and later, it no longer is and can be used for C++11-style uniform     initialization:      \snippet code/src_corelib_tools_qcommandlineoption.cpp cxx11-init-list      \sa setDescription(), setValueName(), setDefaultValues() */
end_comment
begin_constructor
DECL|function|QCommandLineOption
name|QCommandLineOption
operator|::
name|QCommandLineOption
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|names
parameter_list|,
specifier|const
name|QString
modifier|&
name|description
parameter_list|,
specifier|const
name|QString
modifier|&
name|valueName
parameter_list|,
specifier|const
name|QString
modifier|&
name|defaultValue
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QCommandLineOptionPrivate
argument_list|(
name|names
argument_list|)
argument_list|)
block|{
name|setValueName
argument_list|(
name|valueName
argument_list|)
expr_stmt|;
name|setDescription
argument_list|(
name|description
argument_list|)
expr_stmt|;
name|setDefaultValue
argument_list|(
name|defaultValue
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QCommandLineOption object that is a copy of the QCommandLineOption     object \a other.      \sa operator=() */
end_comment
begin_constructor
DECL|function|QCommandLineOption
name|QCommandLineOption
operator|::
name|QCommandLineOption
parameter_list|(
specifier|const
name|QCommandLineOption
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the command line option object. */
end_comment
begin_destructor
DECL|function|~QCommandLineOption
name|QCommandLineOption
operator|::
name|~
name|QCommandLineOption
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Makes a copy of the \a other object and assigns it to this QCommandLineOption     object. */
end_comment
begin_function
DECL|function|operator =
name|QCommandLineOption
modifier|&
name|QCommandLineOption
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QCommandLineOption
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QCommandLineOption::swap(QCommandLineOption&other)      Swaps option \a other with this option. This operation is very     fast and never fails. */
end_comment
begin_comment
comment|/*!     Returns the names set for this option.  */
end_comment
begin_function
DECL|function|names
name|QStringList
name|QCommandLineOption
operator|::
name|names
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|names
return|;
block|}
end_function
begin_namespace
namespace|namespace
block|{
DECL|struct|IsInvalidName
struct|struct
name|IsInvalidName
block|{
DECL|typedef|result_type
typedef|typedef
name|bool
name|result_type
typedef|;
DECL|typedef|argument_type
typedef|typedef
name|QString
name|argument_type
typedef|;
name|Q_NEVER_INLINE
name|result_type
name|operator
name|()
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
name|Q_DECL_NOEXCEPT
block|{
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|name
operator|.
name|isEmpty
argument_list|()
argument_list|)
condition|)
return|return
name|warn
argument_list|(
literal|"be empty"
argument_list|)
return|;
specifier|const
name|QChar
name|c
init|=
name|name
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|c
operator|==
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
argument_list|)
condition|)
return|return
name|warn
argument_list|(
literal|"start with a '-'"
argument_list|)
return|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|c
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
return|return
name|warn
argument_list|(
literal|"start with a '/'"
argument_list|)
return|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|name
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|)
argument_list|)
condition|)
return|return
name|warn
argument_list|(
literal|"contain a '='"
argument_list|)
return|;
return|return
literal|false
return|;
block|}
name|Q_NEVER_INLINE
specifier|static
name|bool
name|warn
parameter_list|(
specifier|const
name|char
modifier|*
name|what
parameter_list|)
name|Q_DECL_NOEXCEPT
block|{
name|qWarning
argument_list|(
literal|"QCommandLineOption: Option names cannot %s"
argument_list|,
name|what
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
struct|;
block|}
end_namespace
begin_comment
comment|// unnamed namespace
end_comment
begin_comment
comment|// static
end_comment
begin_function
DECL|function|removeInvalidNames
name|QStringList
name|QCommandLineOptionPrivate
operator|::
name|removeInvalidNames
parameter_list|(
name|QStringList
name|nameList
parameter_list|)
block|{
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|nameList
operator|.
name|isEmpty
argument_list|()
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QCommandLineOption: Options must have at least one name"
argument_list|)
expr_stmt|;
else|else
name|nameList
operator|.
name|erase
argument_list|(
name|std
operator|::
name|remove_if
argument_list|(
name|nameList
operator|.
name|begin
argument_list|()
argument_list|,
name|nameList
operator|.
name|end
argument_list|()
argument_list|,
name|IsInvalidName
argument_list|()
argument_list|)
argument_list|,
name|nameList
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|nameList
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the name of the expected value, for the documentation, to \a valueName.      Options without a value assigned have a boolean-like behavior:     either the user specifies --option or they don't.      Options with a value assigned need to set a name for the expected value,     for the documentation of the option in the help output. An option with names \c{o} and \c{output},     and a value name of \c{file} will appear as \c{-o, --output<file>}.      Call QCommandLineParser::value() if you expect the option to be present     only once, and QCommandLineParser::values() if you expect that option     to be present multiple times.      \sa valueName()  */
end_comment
begin_function
DECL|function|setValueName
name|void
name|QCommandLineOption
operator|::
name|setValueName
parameter_list|(
specifier|const
name|QString
modifier|&
name|valueName
parameter_list|)
block|{
name|d
operator|->
name|valueName
operator|=
name|valueName
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the expected value.      If empty, the option doesn't take a value.      \sa setValueName()  */
end_comment
begin_function
DECL|function|valueName
name|QString
name|QCommandLineOption
operator|::
name|valueName
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|valueName
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the description used for this option to \a description.      It is customary to add a "." at the end of the description.      The description is used by QCommandLineParser::showHelp().      \sa description()  */
end_comment
begin_function
DECL|function|setDescription
name|void
name|QCommandLineOption
operator|::
name|setDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|description
parameter_list|)
block|{
name|d
operator|->
name|description
operator|=
name|description
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the description set for this option.      \sa setDescription()  */
end_comment
begin_function
DECL|function|description
name|QString
name|QCommandLineOption
operator|::
name|description
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|description
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the default value used for this option to \a defaultValue.      The default value is used if the user of the application does not specify     the option on the command line.      If \a defaultValue is empty, the option has no default values.      \sa defaultValues() setDefaultValues()  */
end_comment
begin_function
DECL|function|setDefaultValue
name|void
name|QCommandLineOption
operator|::
name|setDefaultValue
parameter_list|(
specifier|const
name|QString
modifier|&
name|defaultValue
parameter_list|)
block|{
name|QStringList
name|newDefaultValues
decl_stmt|;
if|if
condition|(
operator|!
name|defaultValue
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|newDefaultValues
operator|.
name|reserve
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|newDefaultValues
operator|<<
name|defaultValue
expr_stmt|;
block|}
comment|// commit:
name|d
operator|->
name|defaultValues
operator|.
name|swap
argument_list|(
name|newDefaultValues
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the list of default values used for this option to \a defaultValues.      The default values are used if the user of the application does not specify     the option on the command line.      \sa defaultValues() setDefaultValue()  */
end_comment
begin_function
DECL|function|setDefaultValues
name|void
name|QCommandLineOption
operator|::
name|setDefaultValues
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|defaultValues
parameter_list|)
block|{
name|d
operator|->
name|defaultValues
operator|=
name|defaultValues
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the default values set for this option.      \sa setDefaultValues()  */
end_comment
begin_function
DECL|function|defaultValues
name|QStringList
name|QCommandLineOption
operator|::
name|defaultValues
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|defaultValues
return|;
block|}
end_function
begin_comment
comment|/*!     Sets whether to hide this option in the user-visible help output.      All options are visible by default. Setting \a hidden to true for     a particular option makes it internal, i.e. not listed in the help output.      \since 5.6     \sa isHidden  */
end_comment
begin_function
DECL|function|setHidden
name|void
name|QCommandLineOption
operator|::
name|setHidden
parameter_list|(
name|bool
name|hide
parameter_list|)
block|{
name|d
operator|->
name|hidden
operator|=
name|hide
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if this option is omitted from the help output,     false if the option is listed.      \since 5.6     \sa setHidden()  */
end_comment
begin_function
DECL|function|isHidden
name|bool
name|QCommandLineOption
operator|::
name|isHidden
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|hidden
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
