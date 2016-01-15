begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"cppwritedeclaration.h"
end_include
begin_include
include|#
directive|include
file|"cppwriteicondeclaration.h"
end_include
begin_include
include|#
directive|include
file|"cppwriteinitialization.h"
end_include
begin_include
include|#
directive|include
file|"cppwriteiconinitialization.h"
end_include
begin_include
include|#
directive|include
file|"cppextractimages.h"
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
file|"customwidgetsinfo.h"
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_namespace
namespace|namespace
block|{
DECL|function|openNameSpaces
name|void
name|openNameSpaces
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|namespaceList
parameter_list|,
name|QTextStream
modifier|&
name|output
parameter_list|)
block|{
if|if
condition|(
name|namespaceList
operator|.
name|empty
argument_list|()
condition|)
return|return;
specifier|const
name|QStringList
operator|::
name|const_iterator
name|cend
init|=
name|namespaceList
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
name|QStringList
operator|::
name|const_iterator
name|it
init|=
name|namespaceList
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
block|{
if|if
condition|(
operator|!
name|it
operator|->
name|isEmpty
argument_list|()
condition|)
block|{
name|output
operator|<<
literal|"namespace "
operator|<<
operator|*
name|it
operator|<<
literal|" {\n"
expr_stmt|;
block|}
block|}
block|}
DECL|function|closeNameSpaces
name|void
name|closeNameSpaces
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|namespaceList
parameter_list|,
name|QTextStream
modifier|&
name|output
parameter_list|)
block|{
if|if
condition|(
name|namespaceList
operator|.
name|empty
argument_list|()
condition|)
return|return;
name|QListIterator
argument_list|<
name|QString
argument_list|>
name|it
argument_list|(
name|namespaceList
argument_list|)
decl_stmt|;
name|it
operator|.
name|toBack
argument_list|()
expr_stmt|;
while|while
condition|(
name|it
operator|.
name|hasPrevious
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|ns
init|=
name|it
operator|.
name|previous
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ns
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|output
operator|<<
literal|"} // namespace "
operator|<<
name|ns
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
block|}
DECL|function|writeScriptContextClass
name|void
name|writeScriptContextClass
parameter_list|(
specifier|const
name|QString
modifier|&
name|indent
parameter_list|,
name|QTextStream
modifier|&
name|str
parameter_list|)
block|{
name|str
operator|<<
name|indent
operator|<<
literal|"class ScriptContext\n"
operator|<<
name|indent
operator|<<
literal|"{\n"
operator|<<
name|indent
operator|<<
literal|"public:\n"
operator|<<
name|indent
operator|<<
literal|"    void run(const QString&script, QWidget *widget, const QWidgetList&childWidgets)\n"
operator|<<
name|indent
operator|<<
literal|"    {\n"
operator|<<
name|indent
operator|<<
literal|"        QScriptValue widgetObject =  scriptEngine.newQObject(widget);\n"
operator|<<
name|indent
operator|<<
literal|"        QScriptValue childWidgetArray = scriptEngine.newArray (childWidgets.size());\n"
operator|<<
name|indent
operator|<<
literal|"        for (int i = 0; i< childWidgets.size(); i++)\n"
operator|<<
name|indent
operator|<<
literal|"               childWidgetArray.setProperty(i, scriptEngine.newQObject(childWidgets[i]));\n"
operator|<<
name|indent
operator|<<
literal|"        QScriptContext *ctx = scriptEngine.pushContext();\n"
operator|<<
name|indent
operator|<<
literal|"        ctx ->activationObject().setProperty(QLatin1String(\"widget\"), widgetObject);\n"
operator|<<
name|indent
operator|<<
literal|"        ctx ->activationObject().setProperty(QLatin1String(\"childWidgets\"), childWidgetArray);\n\n"
operator|<<
name|indent
operator|<<
literal|"        scriptEngine.evaluate(script);\n"
operator|<<
name|indent
operator|<<
literal|"        if (scriptEngine.hasUncaughtException ()) {\n"
operator|<<
name|indent
operator|<<
literal|"            qWarning()<< \"An exception occurred at line \"<< scriptEngine.uncaughtExceptionLineNumber()\n"
operator|<<
name|indent
operator|<<
literal|"<< \" of the script for \"<< widget->objectName()<< \": \"<< engineError()<< '\\n'\n"
operator|<<
name|indent
operator|<<
literal|"<< script;\n"
operator|<<
name|indent
operator|<<
literal|"        }\n\n"
operator|<<
name|indent
operator|<<
literal|"        scriptEngine.popContext();\n"
operator|<<
name|indent
operator|<<
literal|"    }\n\n"
operator|<<
name|indent
operator|<<
literal|"private:\n"
operator|<<
name|indent
operator|<<
literal|"    QString engineError()\n"
operator|<<
name|indent
operator|<<
literal|"    {\n"
operator|<<
name|indent
operator|<<
literal|"        QScriptValue error = scriptEngine.evaluate(\"Error\");\n"
operator|<<
name|indent
operator|<<
literal|"        return error.toString();\n"
operator|<<
name|indent
operator|<<
literal|"    }\n\n"
operator|<<
name|indent
operator|<<
literal|"    QScriptEngine scriptEngine;\n"
operator|<<
name|indent
operator|<<
literal|"};\n\n"
expr_stmt|;
block|}
block|}
end_namespace
begin_namespace
DECL|namespace|CPP
namespace|namespace
name|CPP
block|{
DECL|function|WriteDeclaration
name|WriteDeclaration
operator|::
name|WriteDeclaration
parameter_list|(
name|Uic
modifier|*
name|uic
parameter_list|,
name|bool
name|activateScripts
parameter_list|)
member_init_list|:
name|m_uic
argument_list|(
name|uic
argument_list|)
member_init_list|,
name|m_driver
argument_list|(
name|uic
operator|->
name|driver
argument_list|()
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
name|m_option
argument_list|(
name|uic
operator|->
name|option
argument_list|()
argument_list|)
member_init_list|,
name|m_activateScripts
argument_list|(
name|activateScripts
argument_list|)
block|{ }
DECL|function|acceptUI
name|void
name|WriteDeclaration
operator|::
name|acceptUI
parameter_list|(
name|DomUI
modifier|*
name|node
parameter_list|)
block|{
name|QString
name|qualifiedClassName
init|=
name|node
operator|->
name|elementClass
argument_list|()
operator|+
name|m_option
operator|.
name|postfix
decl_stmt|;
name|QString
name|className
init|=
name|qualifiedClassName
decl_stmt|;
name|QString
name|varName
init|=
name|m_driver
operator|->
name|findOrInsertWidget
argument_list|(
name|node
operator|->
name|elementWidget
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|widgetClassName
init|=
name|node
operator|->
name|elementWidget
argument_list|()
operator|->
name|attributeClass
argument_list|()
decl_stmt|;
name|QString
name|exportMacro
init|=
name|node
operator|->
name|elementExportMacro
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|exportMacro
operator|.
name|isEmpty
argument_list|()
condition|)
name|exportMacro
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|namespaceList
init|=
name|qualifiedClassName
operator|.
name|split
argument_list|(
name|QLatin1String
argument_list|(
literal|"::"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|namespaceList
operator|.
name|count
argument_list|()
condition|)
block|{
name|className
operator|=
name|namespaceList
operator|.
name|last
argument_list|()
expr_stmt|;
name|namespaceList
operator|.
name|removeLast
argument_list|()
expr_stmt|;
block|}
comment|// This is a bit of the hack but covers the cases Qt in/without namespaces
comment|// and User defined classes in/without namespaces. The "strange" case
comment|// is a User using Qt-in-namespace having his own classes not in a namespace.
comment|// In this case the generated Ui helper classes will also end up in
comment|// the Qt namespace (which is harmless, but not "pretty")
specifier|const
name|bool
name|needsMacro
init|=
name|namespaceList
operator|.
name|count
argument_list|()
operator|==
literal|0
operator|||
name|namespaceList
index|[
literal|0
index|]
operator|==
name|QLatin1String
argument_list|(
literal|"qdesigner_internal"
argument_list|)
decl_stmt|;
if|if
condition|(
name|needsMacro
condition|)
name|m_output
operator|<<
literal|"QT_BEGIN_NAMESPACE\n\n"
expr_stmt|;
name|openNameSpaces
argument_list|(
name|namespaceList
argument_list|,
name|m_output
argument_list|)
expr_stmt|;
if|if
condition|(
name|namespaceList
operator|.
name|count
argument_list|()
condition|)
name|m_output
operator|<<
literal|"\n"
expr_stmt|;
name|m_output
operator|<<
literal|"class "
operator|<<
name|exportMacro
operator|<<
name|m_option
operator|.
name|prefix
operator|<<
name|className
operator|<<
literal|"\n"
operator|<<
literal|"{\n"
operator|<<
literal|"public:\n"
expr_stmt|;
specifier|const
name|QStringList
name|connections
init|=
name|m_uic
operator|->
name|databaseInfo
argument_list|()
operator|->
name|connections
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|connections
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
name|connection
init|=
name|connections
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|connection
operator|==
name|QLatin1String
argument_list|(
literal|"(default)"
argument_list|)
condition|)
continue|continue;
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"QSqlDatabase "
operator|<<
name|connection
operator|<<
literal|"Connection;\n"
expr_stmt|;
block|}
name|TreeWalker
operator|::
name|acceptWidget
argument_list|(
name|node
operator|->
name|elementWidget
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|DomButtonGroups
modifier|*
name|domButtonGroups
init|=
name|node
operator|->
name|elementButtonGroups
argument_list|()
condition|)
name|acceptButtonGroups
argument_list|(
name|domButtonGroups
argument_list|)
expr_stmt|;
name|m_output
operator|<<
literal|"\n"
expr_stmt|;
name|WriteInitialization
argument_list|(
name|m_uic
argument_list|,
name|m_activateScripts
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|node
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|elementImages
argument_list|()
condition|)
block|{
if|if
condition|(
name|m_option
operator|.
name|extractImages
condition|)
block|{
name|ExtractImages
argument_list|(
name|m_uic
operator|->
name|option
argument_list|()
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_output
operator|<<
literal|"\n"
operator|<<
literal|"protected:\n"
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"enum IconID\n"
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"{\n"
expr_stmt|;
name|WriteIconDeclaration
argument_list|(
name|m_uic
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|node
argument_list|)
expr_stmt|;
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"unknown_ID\n"
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"};\n"
expr_stmt|;
name|WriteIconInitialization
argument_list|(
name|m_uic
argument_list|)
operator|.
name|acceptUI
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_activateScripts
condition|)
block|{
name|m_output
operator|<<
literal|"\nprivate:\n\n"
expr_stmt|;
name|writeScriptContextClass
argument_list|(
name|m_option
operator|.
name|indent
argument_list|,
name|m_output
argument_list|)
expr_stmt|;
block|}
name|m_output
operator|<<
literal|"};\n\n"
expr_stmt|;
name|closeNameSpaces
argument_list|(
name|namespaceList
argument_list|,
name|m_output
argument_list|)
expr_stmt|;
if|if
condition|(
name|namespaceList
operator|.
name|count
argument_list|()
condition|)
name|m_output
operator|<<
literal|"\n"
expr_stmt|;
if|if
condition|(
name|m_option
operator|.
name|generateNamespace
operator|&&
operator|!
name|m_option
operator|.
name|prefix
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|namespaceList
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"Ui"
argument_list|)
argument_list|)
expr_stmt|;
name|openNameSpaces
argument_list|(
name|namespaceList
argument_list|,
name|m_output
argument_list|)
expr_stmt|;
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"class "
operator|<<
name|exportMacro
operator|<<
name|className
operator|<<
literal|": public "
operator|<<
name|m_option
operator|.
name|prefix
operator|<<
name|className
operator|<<
literal|" {};\n"
expr_stmt|;
name|closeNameSpaces
argument_list|(
name|namespaceList
argument_list|,
name|m_output
argument_list|)
expr_stmt|;
if|if
condition|(
name|namespaceList
operator|.
name|count
argument_list|()
condition|)
name|m_output
operator|<<
literal|"\n"
expr_stmt|;
block|}
if|if
condition|(
name|needsMacro
condition|)
name|m_output
operator|<<
literal|"QT_END_NAMESPACE\n\n"
expr_stmt|;
block|}
DECL|function|acceptWidget
name|void
name|WriteDeclaration
operator|::
name|acceptWidget
parameter_list|(
name|DomWidget
modifier|*
name|node
parameter_list|)
block|{
name|QString
name|className
init|=
name|QLatin1String
argument_list|(
literal|"QWidget"
argument_list|)
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|hasAttributeClass
argument_list|()
condition|)
name|className
operator|=
name|node
operator|->
name|attributeClass
argument_list|()
expr_stmt|;
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
name|m_uic
operator|->
name|customWidgetsInfo
argument_list|()
operator|->
name|realClassName
argument_list|(
name|className
argument_list|)
operator|<<
literal|" *"
operator|<<
name|m_driver
operator|->
name|findOrInsertWidget
argument_list|(
name|node
argument_list|)
operator|<<
literal|";\n"
expr_stmt|;
name|TreeWalker
operator|::
name|acceptWidget
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptSpacer
name|void
name|WriteDeclaration
operator|::
name|acceptSpacer
parameter_list|(
name|DomSpacer
modifier|*
name|node
parameter_list|)
block|{
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"QSpacerItem *"
operator|<<
name|m_driver
operator|->
name|findOrInsertSpacer
argument_list|(
name|node
argument_list|)
operator|<<
literal|";\n"
expr_stmt|;
name|TreeWalker
operator|::
name|acceptSpacer
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptLayout
name|void
name|WriteDeclaration
operator|::
name|acceptLayout
parameter_list|(
name|DomLayout
modifier|*
name|node
parameter_list|)
block|{
name|QString
name|className
init|=
name|QLatin1String
argument_list|(
literal|"QLayout"
argument_list|)
decl_stmt|;
if|if
condition|(
name|node
operator|->
name|hasAttributeClass
argument_list|()
condition|)
name|className
operator|=
name|node
operator|->
name|attributeClass
argument_list|()
expr_stmt|;
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
name|className
operator|<<
literal|" *"
operator|<<
name|m_driver
operator|->
name|findOrInsertLayout
argument_list|(
name|node
argument_list|)
operator|<<
literal|";\n"
expr_stmt|;
name|TreeWalker
operator|::
name|acceptLayout
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptActionGroup
name|void
name|WriteDeclaration
operator|::
name|acceptActionGroup
parameter_list|(
name|DomActionGroup
modifier|*
name|node
parameter_list|)
block|{
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"QActionGroup *"
operator|<<
name|m_driver
operator|->
name|findOrInsertActionGroup
argument_list|(
name|node
argument_list|)
operator|<<
literal|";\n"
expr_stmt|;
name|TreeWalker
operator|::
name|acceptActionGroup
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptAction
name|void
name|WriteDeclaration
operator|::
name|acceptAction
parameter_list|(
name|DomAction
modifier|*
name|node
parameter_list|)
block|{
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"QAction *"
operator|<<
name|m_driver
operator|->
name|findOrInsertAction
argument_list|(
name|node
argument_list|)
operator|<<
literal|";\n"
expr_stmt|;
name|TreeWalker
operator|::
name|acceptAction
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
DECL|function|acceptButtonGroup
name|void
name|WriteDeclaration
operator|::
name|acceptButtonGroup
parameter_list|(
specifier|const
name|DomButtonGroup
modifier|*
name|buttonGroup
parameter_list|)
block|{
name|m_output
operator|<<
name|m_option
operator|.
name|indent
operator|<<
literal|"QButtonGroup *"
operator|<<
name|m_driver
operator|->
name|findOrInsertButtonGroup
argument_list|(
name|buttonGroup
argument_list|)
operator|<<
literal|";\n"
expr_stmt|;
name|TreeWalker
operator|::
name|acceptButtonGroup
argument_list|(
name|buttonGroup
argument_list|)
expr_stmt|;
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
