begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"driver.h"
end_include
begin_include
include|#
directive|include
file|"uic.h"
end_include
begin_include
include|#
directive|include
file|"ui4.h"
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|Driver
name|Driver
operator|::
name|Driver
parameter_list|()
member_init_list|:
name|m_stdout
argument_list|(
name|stdout
argument_list|,
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
block|{
name|m_output
operator|=
operator|&
name|m_stdout
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Driver
name|Driver
operator|::
name|~
name|Driver
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|findOrInsertWidget
name|QString
name|Driver
operator|::
name|findOrInsertWidget
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_widgets
operator|.
name|contains
argument_list|(
name|ui_widget
argument_list|)
condition|)
name|m_widgets
operator|.
name|insert
argument_list|(
name|ui_widget
argument_list|,
name|unique
argument_list|(
name|ui_widget
operator|->
name|attributeName
argument_list|()
argument_list|,
name|ui_widget
operator|->
name|attributeClass
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|m_widgets
operator|.
name|value
argument_list|(
name|ui_widget
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|findOrInsertSpacer
name|QString
name|Driver
operator|::
name|findOrInsertSpacer
parameter_list|(
name|DomSpacer
modifier|*
name|ui_spacer
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_spacers
operator|.
name|contains
argument_list|(
name|ui_spacer
argument_list|)
condition|)
block|{
name|QString
name|name
decl_stmt|;
if|if
condition|(
name|ui_spacer
operator|->
name|hasAttributeName
argument_list|()
condition|)
name|name
operator|=
name|ui_spacer
operator|->
name|attributeName
argument_list|()
expr_stmt|;
name|m_spacers
operator|.
name|insert
argument_list|(
name|ui_spacer
argument_list|,
name|unique
argument_list|(
name|name
argument_list|,
name|QLatin1String
argument_list|(
literal|"QSpacerItem"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|m_spacers
operator|.
name|value
argument_list|(
name|ui_spacer
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|findOrInsertLayout
name|QString
name|Driver
operator|::
name|findOrInsertLayout
parameter_list|(
name|DomLayout
modifier|*
name|ui_layout
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_layouts
operator|.
name|contains
argument_list|(
name|ui_layout
argument_list|)
condition|)
block|{
name|QString
name|name
decl_stmt|;
if|if
condition|(
name|ui_layout
operator|->
name|hasAttributeName
argument_list|()
condition|)
name|name
operator|=
name|ui_layout
operator|->
name|attributeName
argument_list|()
expr_stmt|;
name|m_layouts
operator|.
name|insert
argument_list|(
name|ui_layout
argument_list|,
name|unique
argument_list|(
name|name
argument_list|,
name|ui_layout
operator|->
name|attributeClass
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|m_layouts
operator|.
name|value
argument_list|(
name|ui_layout
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|findOrInsertLayoutItem
name|QString
name|Driver
operator|::
name|findOrInsertLayoutItem
parameter_list|(
name|DomLayoutItem
modifier|*
name|ui_layoutItem
parameter_list|)
block|{
switch|switch
condition|(
name|ui_layoutItem
operator|->
name|kind
argument_list|()
condition|)
block|{
case|case
name|DomLayoutItem
operator|::
name|Widget
case|:
return|return
name|findOrInsertWidget
argument_list|(
name|ui_layoutItem
operator|->
name|elementWidget
argument_list|()
argument_list|)
return|;
case|case
name|DomLayoutItem
operator|::
name|Spacer
case|:
return|return
name|findOrInsertSpacer
argument_list|(
name|ui_layoutItem
operator|->
name|elementSpacer
argument_list|()
argument_list|)
return|;
case|case
name|DomLayoutItem
operator|::
name|Layout
case|:
return|return
name|findOrInsertLayout
argument_list|(
name|ui_layoutItem
operator|->
name|elementLayout
argument_list|()
argument_list|)
return|;
case|case
name|DomLayoutItem
operator|::
name|Unknown
case|:
break|break;
block|}
name|Q_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|findOrInsertActionGroup
name|QString
name|Driver
operator|::
name|findOrInsertActionGroup
parameter_list|(
name|DomActionGroup
modifier|*
name|ui_group
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_actionGroups
operator|.
name|contains
argument_list|(
name|ui_group
argument_list|)
condition|)
name|m_actionGroups
operator|.
name|insert
argument_list|(
name|ui_group
argument_list|,
name|unique
argument_list|(
name|ui_group
operator|->
name|attributeName
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"QActionGroup"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|m_actionGroups
operator|.
name|value
argument_list|(
name|ui_group
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|findOrInsertAction
name|QString
name|Driver
operator|::
name|findOrInsertAction
parameter_list|(
name|DomAction
modifier|*
name|ui_action
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_actions
operator|.
name|contains
argument_list|(
name|ui_action
argument_list|)
condition|)
name|m_actions
operator|.
name|insert
argument_list|(
name|ui_action
argument_list|,
name|unique
argument_list|(
name|ui_action
operator|->
name|attributeName
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"QAction"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|m_actions
operator|.
name|value
argument_list|(
name|ui_action
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|findOrInsertButtonGroup
name|QString
name|Driver
operator|::
name|findOrInsertButtonGroup
parameter_list|(
specifier|const
name|DomButtonGroup
modifier|*
name|ui_group
parameter_list|)
block|{
name|ButtonGroupNameHash
operator|::
name|iterator
name|it
init|=
name|m_buttonGroups
operator|.
name|find
argument_list|(
name|ui_group
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|==
name|m_buttonGroups
operator|.
name|end
argument_list|()
condition|)
name|it
operator|=
name|m_buttonGroups
operator|.
name|insert
argument_list|(
name|ui_group
argument_list|,
name|unique
argument_list|(
name|ui_group
operator|->
name|attributeName
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"QButtonGroup"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|it
operator|.
name|value
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Find a group by its non-uniqified name
end_comment
begin_function
DECL|function|findButtonGroup
specifier|const
name|DomButtonGroup
modifier|*
name|Driver
operator|::
name|findButtonGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|attributeName
parameter_list|)
specifier|const
block|{
specifier|const
name|ButtonGroupNameHash
operator|::
name|const_iterator
name|cend
init|=
name|m_buttonGroups
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
name|ButtonGroupNameHash
operator|::
name|const_iterator
name|it
init|=
name|m_buttonGroups
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
if|if
condition|(
name|it
operator|.
name|key
argument_list|()
operator|->
name|attributeName
argument_list|()
operator|==
name|attributeName
condition|)
return|return
name|it
operator|.
name|key
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|findOrInsertName
name|QString
name|Driver
operator|::
name|findOrInsertName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|unique
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|normalizedName
name|QString
name|Driver
operator|::
name|normalizedName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|QString
name|result
init|=
name|name
decl_stmt|;
name|QChar
modifier|*
name|data
init|=
name|result
operator|.
name|data
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|name
operator|.
name|size
argument_list|()
init|;
operator|--
name|i
operator|>=
literal|0
condition|;
operator|++
name|data
control|)
block|{
if|if
condition|(
operator|!
name|data
operator|->
name|isLetterOrNumber
argument_list|()
condition|)
operator|*
name|data
operator|=
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|unique
name|QString
name|Driver
operator|::
name|unique
parameter_list|(
specifier|const
name|QString
modifier|&
name|instanceName
parameter_list|,
specifier|const
name|QString
modifier|&
name|className
parameter_list|)
block|{
name|QString
name|name
decl_stmt|;
name|bool
name|alreadyUsed
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|instanceName
operator|.
name|size
argument_list|()
condition|)
block|{
name|int
name|id
init|=
literal|1
decl_stmt|;
name|name
operator|=
name|instanceName
expr_stmt|;
name|name
operator|=
name|normalizedName
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|QString
name|base
init|=
name|name
decl_stmt|;
while|while
condition|(
name|m_nameRepository
operator|.
name|contains
argument_list|(
name|name
argument_list|)
condition|)
block|{
name|alreadyUsed
operator|=
literal|true
expr_stmt|;
name|name
operator|=
name|base
operator|+
name|QString
operator|::
name|number
argument_list|(
name|id
operator|++
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|className
operator|.
name|size
argument_list|()
condition|)
block|{
name|name
operator|=
name|unique
argument_list|(
name|qtify
argument_list|(
name|className
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|name
operator|=
name|unique
argument_list|(
name|QLatin1String
argument_list|(
literal|"var"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|alreadyUsed
operator|&&
name|className
operator|.
name|size
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Warning: The name '%s' (%s) is already in use, defaulting to '%s'.\n"
argument_list|,
name|qPrintable
argument_list|(
name|m_option
operator|.
name|messagePrefix
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|instanceName
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|className
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|m_nameRepository
operator|.
name|insert
argument_list|(
name|name
argument_list|,
literal|true
argument_list|)
expr_stmt|;
return|return
name|name
return|;
block|}
end_function
begin_function
DECL|function|qtify
name|QString
name|Driver
operator|::
name|qtify
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|QString
name|qname
init|=
name|name
decl_stmt|;
if|if
condition|(
name|qname
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'Q'
argument_list|)
operator|||
name|qname
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'K'
argument_list|)
condition|)
name|qname
operator|=
name|qname
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|qname
operator|.
name|length
argument_list|()
condition|)
block|{
if|if
condition|(
name|qname
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLower
argument_list|()
operator|!=
name|qname
operator|.
name|at
argument_list|(
name|i
argument_list|)
condition|)
name|qname
index|[
name|i
index|]
operator|=
name|qname
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLower
argument_list|()
expr_stmt|;
else|else
break|break;
operator|++
name|i
expr_stmt|;
block|}
return|return
name|qname
return|;
block|}
end_function
begin_function
DECL|function|isAnsiCCharacter
specifier|static
name|bool
name|isAnsiCCharacter
parameter_list|(
name|QChar
name|c
parameter_list|)
block|{
return|return
operator|(
name|c
operator|.
name|toUpper
argument_list|()
operator|>=
name|QLatin1Char
argument_list|(
literal|'A'
argument_list|)
operator|&&
name|c
operator|.
name|toUpper
argument_list|()
operator|<=
name|QLatin1Char
argument_list|(
literal|'Z'
argument_list|)
operator|)
operator|||
name|c
operator|.
name|isDigit
argument_list|()
operator|||
name|c
operator|==
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|headerFileName
name|QString
name|Driver
operator|::
name|headerFileName
parameter_list|()
specifier|const
block|{
name|QString
name|name
init|=
name|m_option
operator|.
name|outputFile
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|name
operator|=
name|QLatin1String
argument_list|(
literal|"ui_"
argument_list|)
expr_stmt|;
comment|// ### use ui_ as prefix.
name|name
operator|.
name|append
argument_list|(
name|m_option
operator|.
name|inputFile
argument_list|)
expr_stmt|;
block|}
return|return
name|headerFileName
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|headerFileName
name|QString
name|Driver
operator|::
name|headerFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|headerFileName
argument_list|(
name|QLatin1String
argument_list|(
literal|"noname"
argument_list|)
argument_list|)
return|;
name|QFileInfo
name|info
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|QString
name|baseName
init|=
name|info
operator|.
name|baseName
argument_list|()
decl_stmt|;
comment|// Transform into a valid C++ identifier
if|if
condition|(
operator|!
name|baseName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|baseName
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isDigit
argument_list|()
condition|)
name|baseName
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|baseName
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QChar
name|c
init|=
name|baseName
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|isAnsiCCharacter
argument_list|(
name|c
argument_list|)
condition|)
block|{
comment|// Replace character by its unicode value
name|QString
name|hex
init|=
name|QString
operator|::
name|number
argument_list|(
name|c
operator|.
name|unicode
argument_list|()
argument_list|,
literal|16
argument_list|)
decl_stmt|;
name|baseName
operator|.
name|replace
argument_list|(
name|i
argument_list|,
literal|1
argument_list|,
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
operator|+
name|hex
operator|+
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
argument_list|)
expr_stmt|;
name|i
operator|+=
name|hex
operator|.
name|size
argument_list|()
operator|+
literal|1
expr_stmt|;
block|}
block|}
return|return
name|baseName
operator|.
name|toUpper
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"_H"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|printDependencies
name|bool
name|Driver
operator|::
name|printDependencies
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|m_option
operator|.
name|dependencies
operator|==
literal|true
argument_list|)
expr_stmt|;
name|m_option
operator|.
name|inputFile
operator|=
name|fileName
expr_stmt|;
name|Uic
name|tool
argument_list|(
name|this
argument_list|)
decl_stmt|;
return|return
name|tool
operator|.
name|printDependencies
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|uic
name|bool
name|Driver
operator|::
name|uic
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|DomUI
modifier|*
name|ui
parameter_list|,
name|QTextStream
modifier|*
name|out
parameter_list|)
block|{
name|m_option
operator|.
name|inputFile
operator|=
name|fileName
expr_stmt|;
name|QTextStream
modifier|*
name|oldOutput
init|=
name|m_output
decl_stmt|;
name|m_output
operator|=
name|out
operator|!=
literal|0
condition|?
name|out
else|:
operator|&
name|m_stdout
expr_stmt|;
name|Uic
name|tool
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|bool
name|rtn
init|=
literal|false
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_UIC_CPP_GENERATOR
name|rtn
operator|=
name|tool
operator|.
name|write
argument_list|(
name|ui
argument_list|)
expr_stmt|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|ui
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"uic: option to generate cpp code not compiled in [%s:%d]\n"
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_output
operator|=
name|oldOutput
expr_stmt|;
return|return
name|rtn
return|;
block|}
end_function
begin_function
DECL|function|uic
name|bool
name|Driver
operator|::
name|uic
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QTextStream
modifier|*
name|out
parameter_list|)
block|{
name|QFile
name|f
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|f
operator|.
name|open
argument_list|(
name|stdin
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
else|else
block|{
name|f
operator|.
name|setFileName
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return
literal|false
return|;
block|}
name|m_option
operator|.
name|inputFile
operator|=
name|fileName
expr_stmt|;
name|QTextStream
modifier|*
name|oldOutput
init|=
name|m_output
decl_stmt|;
name|bool
name|deleteOutput
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|out
condition|)
block|{
name|m_output
operator|=
name|out
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// As one might also redirect the output to a file on win,
comment|// we should not create the textstream with QFile::Text flag.
comment|// The redirected file is opened in TextMode and this will
comment|// result in broken line endings as writing will replace \n again.
name|m_output
operator|=
operator|new
name|QTextStream
argument_list|(
name|stdout
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
else|#
directive|else
name|m_output
operator|=
operator|new
name|QTextStream
argument_list|(
name|stdout
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|deleteOutput
operator|=
literal|true
expr_stmt|;
block|}
name|Uic
name|tool
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|bool
name|rtn
init|=
name|tool
operator|.
name|write
argument_list|(
operator|&
name|f
argument_list|)
decl_stmt|;
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|deleteOutput
condition|)
operator|delete
name|m_output
expr_stmt|;
name|m_output
operator|=
name|oldOutput
expr_stmt|;
return|return
name|rtn
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|Driver
operator|::
name|reset
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|m_output
operator|==
literal|0
argument_list|)
expr_stmt|;
name|m_option
operator|=
name|Option
argument_list|()
expr_stmt|;
name|m_output
operator|=
literal|0
expr_stmt|;
name|m_problems
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QStringList
name|m_problems
decl_stmt|;
name|m_widgets
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_spacers
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_layouts
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_actionGroups
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_actions
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_nameRepository
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_pixmaps
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertPixmap
name|void
name|Driver
operator|::
name|insertPixmap
parameter_list|(
specifier|const
name|QString
modifier|&
name|pixmap
parameter_list|)
block|{
name|m_pixmaps
operator|.
name|insert
argument_list|(
name|pixmap
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|containsPixmap
name|bool
name|Driver
operator|::
name|containsPixmap
parameter_list|(
specifier|const
name|QString
modifier|&
name|pixmap
parameter_list|)
specifier|const
block|{
return|return
name|m_pixmaps
operator|.
name|contains
argument_list|(
name|pixmap
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|widgetByName
name|DomWidget
modifier|*
name|Driver
operator|::
name|widgetByName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
return|return
name|m_widgets
operator|.
name|key
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|spacerByName
name|DomSpacer
modifier|*
name|Driver
operator|::
name|spacerByName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
return|return
name|m_spacers
operator|.
name|key
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|layoutByName
name|DomLayout
modifier|*
name|Driver
operator|::
name|layoutByName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
return|return
name|m_layouts
operator|.
name|key
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|actionGroupByName
name|DomActionGroup
modifier|*
name|Driver
operator|::
name|actionGroupByName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
return|return
name|m_actionGroups
operator|.
name|key
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|actionByName
name|DomAction
modifier|*
name|Driver
operator|::
name|actionByName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
return|return
name|m_actions
operator|.
name|key
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
