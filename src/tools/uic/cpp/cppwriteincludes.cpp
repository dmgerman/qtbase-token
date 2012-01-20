begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"cppwriteincludes.h"
end_include
begin_include
include|#
directive|include
file|"driver.h"
end_include
begin_include
include|#
directive|include
file|"ui4.h"
end_include
begin_include
include|#
directive|include
file|"uic.h"
end_include
begin_include
include|#
directive|include
file|"databaseinfo.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enumerator|debugWriteIncludes
name|enum
type|{
name|debugWriteIncludes
init|=
literal|0
end_decl_stmt
begin_enum
DECL|enumerator|warnHeaderGeneration
unit|};
enum|enum
block|{
name|warnHeaderGeneration
init|=
literal|0
block|}
enum|;
end_enum
begin_struct
DECL|struct|ClassInfoEntry
struct|struct
name|ClassInfoEntry
block|{
DECL|member|klass
specifier|const
name|char
modifier|*
name|klass
decl_stmt|;
DECL|member|module
specifier|const
name|char
modifier|*
name|module
decl_stmt|;
DECL|member|header
specifier|const
name|char
modifier|*
name|header
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|qclass_lib_map
specifier|static
specifier|const
name|ClassInfoEntry
name|qclass_lib_map
index|[]
init|=
block|{
DECL|macro|QT_CLASS_LIB
define|#
directive|define
name|QT_CLASS_LIB
parameter_list|(
name|klass
parameter_list|,
name|module
parameter_list|,
name|header
parameter_list|)
value|{ #klass, #module, #header },
include|#
directive|include
file|"qclass_lib_map.h"
DECL|macro|QT_CLASS_LIB
undef|#
directive|undef
name|QT_CLASS_LIB
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Format a module header as 'QtCore/QObject'
end_comment
begin_function
DECL|function|moduleHeader
specifier|static
specifier|inline
name|QString
name|moduleHeader
parameter_list|(
specifier|const
name|QString
modifier|&
name|module
parameter_list|,
specifier|const
name|QString
modifier|&
name|header
parameter_list|)
block|{
name|QString
name|rc
init|=
name|module
decl_stmt|;
name|rc
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
name|rc
operator|+=
name|header
expr_stmt|;
return|return
name|rc
return|;
block|}
end_function
begin_namespace
DECL|namespace|CPP
namespace|namespace
name|CPP
block|{
DECL|function|WriteIncludes
name|WriteIncludes
operator|::
name|WriteIncludes
parameter_list|(
name|Uic
modifier|*
name|uic
parameter_list|)
member_init_list|:
name|m_uic
argument_list|(
name|uic
argument_list|)
member_init_list|,
name|m_output
argument_list|(
name|uic
operator|->
name|output
argument_list|()
argument_list|)
member_init_list|,
name|m_scriptsActivated
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_laidOut
argument_list|(
literal|false
argument_list|)
block|{
comment|// When possible (no namespace) use the "QtModule/QClass" convention
comment|// and create a re-mapping of the old header "qclass.h" to it. Do not do this
comment|// for the "Phonon::Someclass" classes, however.
specifier|const
name|QString
name|namespaceDelimiter
init|=
name|QLatin1String
argument_list|(
literal|"::"
argument_list|)
decl_stmt|;
specifier|const
name|ClassInfoEntry
modifier|*
name|classLibEnd
init|=
name|qclass_lib_map
operator|+
sizeof|sizeof
argument_list|(
name|qclass_lib_map
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ClassInfoEntry
argument_list|)
decl_stmt|;
for|for
control|(
specifier|const
name|ClassInfoEntry
modifier|*
name|it
init|=
name|qclass_lib_map
init|;
name|it
operator|<
name|classLibEnd
condition|;
operator|++
name|it
control|)
block|{
specifier|const
name|QString
name|klass
init|=
name|QLatin1String
argument_list|(
name|it
operator|->
name|klass
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|module
init|=
name|QLatin1String
argument_list|(
name|it
operator|->
name|module
argument_list|)
decl_stmt|;
name|QLatin1String
name|header
init|=
name|QLatin1String
argument_list|(
name|it
operator|->
name|header
argument_list|)
decl_stmt|;
if|if
condition|(
name|klass
operator|.
name|contains
argument_list|(
name|namespaceDelimiter
argument_list|)
condition|)
block|{
name|m_classToHeader
operator|.
name|insert
argument_list|(
name|klass
argument_list|,
name|moduleHeader
argument_list|(
name|module
argument_list|,
name|header
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QString
name|newHeader
init|=
name|moduleHeader
argument_list|(
name|module
argument_list|,
name|klass
argument_list|)
decl_stmt|;
name|m_classToHeader
operator|.
name|insert
argument_list|(
name|klass
argument_list|,
name|newHeader
argument_list|)
expr_stmt|;
name|m_oldHeaderToNewHeader
operator|.
name|insert
argument_list|(
name|header
argument_list|,
name|newHeader
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|function|acceptUI
name|void
name|WriteIncludes
operator|::
name|acceptUI
parameter_list|(
name|DomUI
modifier|*
name|node
parameter_list|)
block|{
name|m_scriptsActivated
operator|=
literal|false
expr_stmt|;
name|m_laidOut
operator|=
literal|false
expr_stmt|;
name|m_localIncludes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_globalIncludes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_knownClasses
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_includeBaseNames
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|elementIncludes
argument_list|()
condition|)
name|acceptIncludes
argument_list|(
name|node
operator|->
name|elementIncludes
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|elementCustomWidgets
argument_list|()
condition|)
name|TreeWalker
operator|::
name|acceptCustomWidgets
argument_list|(
name|node
operator|->
name|elementCustomWidgets
argument_list|()
argument_list|)
expr_stmt|;
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QApplication"
argument_list|)
argument_list|)
expr_stmt|;
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QVariant"
argument_list|)
argument_list|)
expr_stmt|;
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QAction"
argument_list|)
argument_list|)
expr_stmt|;
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QButtonGroup"
argument_list|)
argument_list|)
expr_stmt|;
comment|// ### only if it is really necessary
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QHeaderView"
argument_list|)
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptUI
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|writeHeaders
argument_list|(
name|m_globalIncludes
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|writeHeaders
argument_list|(
name|m_localIncludes
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|m_output
operator|<<
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptWidget
name|void
name|WriteIncludes
operator|::
name|acceptWidget
parameter_list|(
name|DomWidget
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|debugWriteIncludes
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s '%s'\n"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|qPrintable
argument_list|(
name|node
operator|->
name|attributeClass
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|add
argument_list|(
name|node
operator|->
name|attributeClass
argument_list|()
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptWidget
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptLayout
name|void
name|WriteIncludes
operator|::
name|acceptLayout
parameter_list|(
name|DomLayout
modifier|*
name|node
parameter_list|)
block|{
name|add
argument_list|(
name|node
operator|->
name|attributeClass
argument_list|()
argument_list|)
expr_stmt|;
name|m_laidOut
operator|=
literal|true
expr_stmt|;
name|TreeWalker
operator|::
name|acceptLayout
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptSpacer
name|void
name|WriteIncludes
operator|::
name|acceptSpacer
parameter_list|(
name|DomSpacer
modifier|*
name|node
parameter_list|)
block|{
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QSpacerItem"
argument_list|)
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptSpacer
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptProperty
name|void
name|WriteIncludes
operator|::
name|acceptProperty
parameter_list|(
name|DomProperty
modifier|*
name|node
parameter_list|)
block|{
if|if
condition|(
name|node
operator|->
name|kind
argument_list|()
operator|==
name|DomProperty
operator|::
name|Date
condition|)
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QDate"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|kind
argument_list|()
operator|==
name|DomProperty
operator|::
name|Locale
condition|)
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocale"
argument_list|)
argument_list|)
expr_stmt|;
name|TreeWalker
operator|::
name|acceptProperty
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|insertIncludeForClass
name|void
name|WriteIncludes
operator|::
name|insertIncludeForClass
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|,
name|QString
name|header
parameter_list|,
name|bool
name|global
parameter_list|)
block|{
if|if
condition|(
name|debugWriteIncludes
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s %s '%s' %d\n"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|qPrintable
argument_list|(
name|className
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|header
argument_list|)
argument_list|,
name|global
argument_list|)
expr_stmt|;
do|do
block|{
if|if
condition|(
operator|!
name|header
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
comment|// Known class
specifier|const
name|StringMap
operator|::
name|const_iterator
name|it
init|=
name|m_classToHeader
operator|.
name|constFind
argument_list|(
name|className
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|m_classToHeader
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|header
operator|=
name|it
operator|.
name|value
argument_list|()
expr_stmt|;
name|global
operator|=
literal|true
expr_stmt|;
break|break;
block|}
comment|// Quick check by class name to detect includehints provided for custom widgets.
comment|// Remove namespaces
name|QString
name|lowerClassName
init|=
name|className
operator|.
name|toLower
argument_list|()
decl_stmt|;
specifier|static
specifier|const
name|QString
name|namespaceSeparator
init|=
name|QLatin1String
argument_list|(
literal|"::"
argument_list|)
decl_stmt|;
specifier|const
name|int
name|namespaceIndex
init|=
name|lowerClassName
operator|.
name|lastIndexOf
argument_list|(
name|namespaceSeparator
argument_list|)
decl_stmt|;
if|if
condition|(
name|namespaceIndex
operator|!=
operator|-
literal|1
condition|)
name|lowerClassName
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|namespaceIndex
operator|+
name|namespaceSeparator
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_includeBaseNames
operator|.
name|contains
argument_list|(
name|lowerClassName
argument_list|)
condition|)
block|{
name|header
operator|.
name|clear
argument_list|()
expr_stmt|;
break|break;
block|}
comment|// Last resort: Create default header
if|if
condition|(
operator|!
name|m_uic
operator|->
name|option
argument_list|()
operator|.
name|implicitIncludes
condition|)
break|break;
name|header
operator|=
name|lowerClassName
expr_stmt|;
name|header
operator|+=
name|QLatin1String
argument_list|(
literal|".h"
argument_list|)
expr_stmt|;
if|if
condition|(
name|warnHeaderGeneration
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Warning: generated header '%s' for class '%s'."
argument_list|,
name|qPrintable
argument_list|(
name|m_uic
operator|->
name|option
argument_list|()
operator|.
name|messagePrefix
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|header
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|className
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|global
operator|=
literal|true
expr_stmt|;
block|}
do|while
condition|(
literal|false
condition|)
do|;
if|if
condition|(
operator|!
name|header
operator|.
name|isEmpty
argument_list|()
condition|)
name|insertInclude
argument_list|(
name|header
argument_list|,
name|global
argument_list|)
expr_stmt|;
block|}
DECL|function|add
name|void
name|WriteIncludes
operator|::
name|add
parameter_list|(
specifier|const
name|QString
modifier|&
name|className
parameter_list|,
name|bool
name|determineHeader
parameter_list|,
specifier|const
name|QString
modifier|&
name|header
parameter_list|,
name|bool
name|global
parameter_list|)
block|{
if|if
condition|(
name|debugWriteIncludes
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s %s '%s' %d\n"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|qPrintable
argument_list|(
name|className
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|header
argument_list|)
argument_list|,
name|global
argument_list|)
expr_stmt|;
if|if
condition|(
name|className
operator|.
name|isEmpty
argument_list|()
operator|||
name|m_knownClasses
operator|.
name|contains
argument_list|(
name|className
argument_list|)
condition|)
return|return;
name|m_knownClasses
operator|.
name|insert
argument_list|(
name|className
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_laidOut
operator|&&
name|m_uic
operator|->
name|customWidgetsInfo
argument_list|()
operator|->
name|extends
argument_list|(
name|className
argument_list|,
name|QLatin1String
argument_list|(
literal|"QToolBox"
argument_list|)
argument_list|)
condition|)
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLayout"
argument_list|)
argument_list|)
expr_stmt|;
comment|// spacing property of QToolBox)
if|if
condition|(
name|className
operator|==
name|QLatin1String
argument_list|(
literal|"Line"
argument_list|)
condition|)
block|{
comment|// ### hmm, deprecate me!
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QFrame"
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|determineHeader
condition|)
name|insertIncludeForClass
argument_list|(
name|className
argument_list|,
name|header
argument_list|,
name|global
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptCustomWidget
name|void
name|WriteIncludes
operator|::
name|acceptCustomWidget
parameter_list|(
name|DomCustomWidget
modifier|*
name|node
parameter_list|)
block|{
specifier|const
name|QString
name|className
init|=
name|node
operator|->
name|elementClass
argument_list|()
decl_stmt|;
if|if
condition|(
name|className
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
if|if
condition|(
specifier|const
name|DomScript
modifier|*
name|domScript
init|=
name|node
operator|->
name|elementScript
argument_list|()
condition|)
if|if
condition|(
operator|!
name|domScript
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|activateScripts
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|node
operator|->
name|elementHeader
argument_list|()
operator|||
name|node
operator|->
name|elementHeader
argument_list|()
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|add
argument_list|(
name|className
argument_list|,
literal|false
argument_list|)
expr_stmt|;
comment|// no header specified
block|}
else|else
block|{
comment|// custom header unless it is a built-in qt class
name|QString
name|header
decl_stmt|;
name|bool
name|global
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|m_classToHeader
operator|.
name|contains
argument_list|(
name|className
argument_list|)
condition|)
block|{
name|global
operator|=
name|node
operator|->
name|elementHeader
argument_list|()
operator|->
name|attributeLocation
argument_list|()
operator|.
name|toLower
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"global"
argument_list|)
expr_stmt|;
name|header
operator|=
name|node
operator|->
name|elementHeader
argument_list|()
operator|->
name|text
argument_list|()
expr_stmt|;
block|}
name|add
argument_list|(
name|className
argument_list|,
literal|true
argument_list|,
name|header
argument_list|,
name|global
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|acceptCustomWidgets
name|void
name|WriteIncludes
operator|::
name|acceptCustomWidgets
parameter_list|(
name|DomCustomWidgets
modifier|*
name|node
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptIncludes
name|void
name|WriteIncludes
operator|::
name|acceptIncludes
parameter_list|(
name|DomIncludes
modifier|*
name|node
parameter_list|)
block|{
name|TreeWalker
operator|::
name|acceptIncludes
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptInclude
name|void
name|WriteIncludes
operator|::
name|acceptInclude
parameter_list|(
name|DomInclude
modifier|*
name|node
parameter_list|)
block|{
name|bool
name|global
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|hasAttributeLocation
argument_list|()
condition|)
name|global
operator|=
name|node
operator|->
name|attributeLocation
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"global"
argument_list|)
expr_stmt|;
name|insertInclude
argument_list|(
name|node
operator|->
name|text
argument_list|()
argument_list|,
name|global
argument_list|)
expr_stmt|;
block|}
DECL|function|insertInclude
name|void
name|WriteIncludes
operator|::
name|insertInclude
parameter_list|(
specifier|const
name|QString
modifier|&
name|header
parameter_list|,
name|bool
name|global
parameter_list|)
block|{
if|if
condition|(
name|debugWriteIncludes
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s %s %d\n"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|qPrintable
argument_list|(
name|header
argument_list|)
argument_list|,
name|global
argument_list|)
expr_stmt|;
name|OrderedSet
modifier|&
name|includes
init|=
name|global
condition|?
name|m_globalIncludes
else|:
name|m_localIncludes
decl_stmt|;
if|if
condition|(
name|includes
operator|.
name|contains
argument_list|(
name|header
argument_list|)
condition|)
return|return;
comment|// Insert. Also remember base name for quick check of suspicious custom plugins
name|includes
operator|.
name|insert
argument_list|(
name|header
argument_list|,
literal|false
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|lowerBaseName
init|=
name|QFileInfo
argument_list|(
name|header
argument_list|)
operator|.
name|completeBaseName
argument_list|()
operator|.
name|toLower
argument_list|()
decl_stmt|;
name|m_includeBaseNames
operator|.
name|insert
argument_list|(
name|lowerBaseName
argument_list|)
expr_stmt|;
block|}
DECL|function|writeHeaders
name|void
name|WriteIncludes
operator|::
name|writeHeaders
parameter_list|(
specifier|const
name|OrderedSet
modifier|&
name|headers
parameter_list|,
name|bool
name|global
parameter_list|)
block|{
specifier|const
name|QChar
name|openingQuote
init|=
name|global
condition|?
name|QLatin1Char
argument_list|(
literal|'<'
argument_list|)
else|:
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
decl_stmt|;
specifier|const
name|QChar
name|closingQuote
init|=
name|global
condition|?
name|QLatin1Char
argument_list|(
literal|'>'
argument_list|)
else|:
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
decl_stmt|;
comment|// Check for the old headers 'qslider.h' and replace by 'QtGui/QSlider'
specifier|const
name|OrderedSet
operator|::
name|const_iterator
name|cend
init|=
name|headers
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
name|OrderedSet
operator|::
name|const_iterator
name|sit
init|=
name|headers
operator|.
name|constBegin
argument_list|()
init|;
name|sit
operator|!=
name|cend
condition|;
operator|++
name|sit
control|)
block|{
specifier|const
name|StringMap
operator|::
name|const_iterator
name|hit
init|=
name|m_oldHeaderToNewHeader
operator|.
name|constFind
argument_list|(
name|sit
operator|.
name|key
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|mapped
init|=
name|hit
operator|!=
name|m_oldHeaderToNewHeader
operator|.
name|constEnd
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|header
init|=
name|mapped
condition|?
name|hit
operator|.
name|value
argument_list|()
else|:
name|sit
operator|.
name|key
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|header
operator|.
name|trimmed
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|m_output
operator|<<
literal|"#include "
operator|<<
name|openingQuote
operator|<<
name|header
operator|<<
name|closingQuote
operator|<<
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|function|acceptWidgetScripts
name|void
name|WriteIncludes
operator|::
name|acceptWidgetScripts
parameter_list|(
specifier|const
name|DomScripts
modifier|&
name|scripts
parameter_list|,
name|DomWidget
modifier|*
parameter_list|,
specifier|const
name|DomWidgets
modifier|&
parameter_list|)
block|{
if|if
condition|(
operator|!
name|scripts
operator|.
name|empty
argument_list|()
condition|)
block|{
name|activateScripts
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|activateScripts
name|void
name|WriteIncludes
operator|::
name|activateScripts
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_scriptsActivated
condition|)
block|{
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QScriptEngine"
argument_list|)
argument_list|)
expr_stmt|;
name|add
argument_list|(
name|QLatin1String
argument_list|(
literal|"QDebug"
argument_list|)
argument_list|)
expr_stmt|;
name|m_scriptsActivated
operator|=
literal|true
expr_stmt|;
block|}
block|}
block|}
end_namespace
begin_comment
comment|// namespace CPP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
