begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Laszlo Papp<lpapp@kde.org> ** Copyright (C) 2013 David Faure<faure@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|function|QCommandLineOptionPrivate
specifier|inline
name|QCommandLineOptionPrivate
parameter_list|()
block|{ }
name|void
name|setNames
parameter_list|(
specifier|const
name|QStringList
modifier|&
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
block|}
class|;
end_class
begin_comment
comment|/*!     \since 5.2     \class QCommandLineOption     \brief The QCommandLineOption class defines a possible command-line option.     \inmodule QtCore     \ingroup shared     \ingroup tools      This class is used to describe an option on the command line. It allows     different ways of defining the same option with multiple aliases possible.     It is also used to describe how the option is used - it may be a flag (e.g. \c{-v})     or take an argument (e.g. \c{-o file}).      Examples:     \snippet code/src_corelib_tools_qcommandlineoption.cpp 0      \sa QCommandLineParser */
end_comment
begin_comment
comment|/*!     Constructs a command line option object with the given arguments.      The name of the option is set to \a name.     The name can be either short or long. If the name is one character in     length, it is considered a short name. Option names must not be empty,     must not start with a dash or a slash character, must not contain a \c{=}     and cannot be repeated.      The description is set to \a description. It is customary to add a "."     at the end of the description.      In addition, the \a valueName can be set if the option expects a value.     The default value for the option is set to \a defaultValue.      \sa setDescription(), setValueName(), setDefaultValues() */
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
argument_list|)
block|{
name|d
operator|->
name|setNames
argument_list|(
name|QStringList
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
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
comment|/*!     Constructs a command line option object with the given arguments.      This overload allows to set multiple names for the option, for instance     \c{o} and \c{output}.      The names of the option are set to \a names.     The names can be either short or long. Any name in the list that is one     character in length is a short name. Option names must not be empty,     must not start with a dash or a slash character, must not contain a \c{=}     and cannot be repeated.      The description is set to \a description. It is customary to add a "."     at the end of the description.      In addition, the \a valueName can be set if the option expects a value.     The default value for the option is set to \a defaultValue.      \sa setDescription(), setValueName(), setDefaultValues() */
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
argument_list|)
block|{
name|d
operator|->
name|setNames
argument_list|(
name|names
argument_list|)
expr_stmt|;
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
begin_function
DECL|function|setNames
name|void
name|QCommandLineOptionPrivate
operator|::
name|setNames
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|nameList
parameter_list|)
block|{
name|names
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|nameList
operator|.
name|isEmpty
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QCommandLineOption: Options must have at least one name"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|name
decl|,
name|nameList
control|)
block|{
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QCommandLineOption: Option names cannot be empty"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
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
name|c
operator|==
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QCommandLineOption: Option names cannot start with a '-'"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QCommandLineOption: Option names cannot start with a '/'"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|name
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|)
condition|)
name|qWarning
argument_list|(
literal|"QCommandLineOption: Option names cannot contain a '='"
argument_list|)
expr_stmt|;
else|else
name|names
operator|.
name|append
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     Sets the name of the expected value, for the documentation, to \a valueName.      Options without a value assigned have a boolean-like behavior:     either the user specifies --option or they don't.      Options with a value assigned need to set a name for the expected value,     for the documentation of the option in the help output. An option with names \c{o} and \c{output},     and a value name of \c{file} will appear as \c{-o, --output<file>}.      Call QCommandLineParser::argument() if you expect the option to be present     only once, and QCommandLineParser::arguments() if you expect that option     to be present multiple times.      \sa valueName()  */
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
name|d
operator|->
name|defaultValues
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|defaultValue
operator|.
name|isEmpty
argument_list|()
condition|)
name|d
operator|->
name|defaultValues
operator|<<
name|defaultValue
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
