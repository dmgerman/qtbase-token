begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QColorDialog>
end_include
begin_include
include|#
directive|include
file|<QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QFontDialog>
end_include
begin_include
include|#
directive|include
file|<QInputDialog>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QSignalMapper>
end_include
begin_include
include|#
directive|include
file|"ui_keypadnavigation.h"
end_include
begin_class
DECL|class|KeypadNavigation
class|class
name|KeypadNavigation
super|:
specifier|public
name|QMainWindow
block|{
name|Q_OBJECT
public|public:
DECL|function|KeypadNavigation
name|KeypadNavigation
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|ui
argument_list|(
operator|new
name|Ui_KeypadNavigation
argument_list|)
block|{
name|ui
operator|->
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
specifier|const
struct|struct
block|{
name|QObject
modifier|*
name|action
decl_stmt|;
name|QWidget
modifier|*
name|page
decl_stmt|;
block|}
name|layoutMappings
index|[]
init|=
block|{
block|{
name|ui
operator|->
name|m_actionLayoutVerticalSimple
block|,
name|ui
operator|->
name|m_pageVerticalSimple
block|}
block|,
block|{
name|ui
operator|->
name|m_actionLayoutVerticalComplex
block|,
name|ui
operator|->
name|m_pageVerticalComplex
block|}
block|,
block|{
name|ui
operator|->
name|m_actionLayoutTwoDimensional
block|,
name|ui
operator|->
name|m_pageTwoDimensional
block|}
block|,
block|{
name|ui
operator|->
name|m_actionLayoutSliderMagic
block|,
name|ui
operator|->
name|m_pageSliderMagic
block|}
block|,
block|{
name|ui
operator|->
name|m_actionLayoutChaos
block|,
name|ui
operator|->
name|m_pageChaos
block|}
block|,
block|{
name|ui
operator|->
name|m_actionLayoutDialogs
block|,
name|ui
operator|->
name|m_pageDialogs
block|}
block|}
struct|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|int
argument_list|(
sizeof|sizeof
name|layoutMappings
operator|/
sizeof|sizeof
name|layoutMappings
index|[
literal|0
index|]
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|connect
argument_list|(
name|layoutMappings
index|[
name|i
index|]
operator|.
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
operator|&
name|m_layoutSignalMapper
argument_list|,
name|SLOT
argument_list|(
name|map
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_layoutSignalMapper
operator|.
name|setMapping
argument_list|(
name|layoutMappings
index|[
name|i
index|]
operator|.
name|action
argument_list|,
name|layoutMappings
index|[
name|i
index|]
operator|.
name|page
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
operator|&
name|m_layoutSignalMapper
argument_list|,
name|SIGNAL
argument_list|(
name|mapped
argument_list|(
name|QWidget
operator|*
argument_list|)
argument_list|)
argument_list|,
name|ui
operator|->
name|m_stackWidget
argument_list|,
name|SLOT
argument_list|(
name|setCurrentWidget
argument_list|(
name|QWidget
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
specifier|const
struct|struct
block|{
name|QObject
modifier|*
name|action
decl_stmt|;
name|Qt
operator|::
name|NavigationMode
name|mode
decl_stmt|;
block|}
name|modeMappings
index|[]
init|=
block|{
block|{
name|ui
operator|->
name|m_actionModeNone
block|,
name|Qt
operator|::
name|NavigationModeNone
block|}
block|,
block|{
name|ui
operator|->
name|m_actionModeKeypadTabOrder
block|,
name|Qt
operator|::
name|NavigationModeKeypadTabOrder
block|}
block|,
block|{
name|ui
operator|->
name|m_actionModeKeypadDirectional
block|,
name|Qt
operator|::
name|NavigationModeKeypadDirectional
block|}
block|,
block|{
name|ui
operator|->
name|m_actionModeCursorAuto
block|,
name|Qt
operator|::
name|NavigationModeCursorAuto
block|}
block|,
block|{
name|ui
operator|->
name|m_actionModeCursorForceVisible
block|,
name|Qt
operator|::
name|NavigationModeCursorForceVisible
block|}
block|}
struct|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|int
argument_list|(
sizeof|sizeof
name|modeMappings
operator|/
sizeof|sizeof
name|modeMappings
index|[
literal|0
index|]
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|connect
argument_list|(
name|modeMappings
index|[
name|i
index|]
operator|.
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
operator|&
name|m_modeSignalMapper
argument_list|,
name|SLOT
argument_list|(
name|map
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_modeSignalMapper
operator|.
name|setMapping
argument_list|(
name|modeMappings
index|[
name|i
index|]
operator|.
name|action
argument_list|,
name|int
argument_list|(
name|modeMappings
index|[
name|i
index|]
operator|.
name|mode
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
operator|&
name|m_modeSignalMapper
argument_list|,
name|SIGNAL
argument_list|(
name|mapped
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|setNavigationMode
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// QT_KEYPAD_NAVIGATION
name|ui
operator|->
name|m_menuNavigation_mode
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// QT_KEYPAD_NAVIGATION
specifier|const
struct|struct
block|{
name|QObject
modifier|*
name|button
decl_stmt|;
name|Dialog
name|dialog
decl_stmt|;
block|}
name|openDialogMappings
index|[]
init|=
block|{
block|{
name|ui
operator|->
name|m_buttonGetOpenFileName
block|,
name|DialogGetOpenFileName
block|}
block|,
block|{
name|ui
operator|->
name|m_buttonGetSaveFileName
block|,
name|DialogGetSaveFileName
block|}
block|,
block|{
name|ui
operator|->
name|m_buttonGetExistingDirectory
block|,
name|DialogGetExistingDirectory
block|}
block|,
block|{
name|ui
operator|->
name|m_buttonGetColor
block|,
name|DialogGetColor
block|}
block|,
block|{
name|ui
operator|->
name|m_buttonGetFont
block|,
name|DialogGetFont
block|}
block|,
block|{
name|ui
operator|->
name|m_buttonQuestion
block|,
name|DialogQuestion
block|}
block|,
block|{
name|ui
operator|->
name|m_buttonAboutQt
block|,
name|DialogAboutQt
block|}
block|,
block|{
name|ui
operator|->
name|m_buttonGetItem
block|,
name|DialogGetItem
block|}
block|}
struct|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|int
argument_list|(
sizeof|sizeof
name|openDialogMappings
operator|/
sizeof|sizeof
name|openDialogMappings
index|[
literal|0
index|]
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|connect
argument_list|(
name|openDialogMappings
index|[
name|i
index|]
operator|.
name|button
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
operator|&
name|m_dialogSignalMapper
argument_list|,
name|SLOT
argument_list|(
name|map
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_dialogSignalMapper
operator|.
name|setMapping
argument_list|(
name|openDialogMappings
index|[
name|i
index|]
operator|.
name|button
argument_list|,
name|int
argument_list|(
name|openDialogMappings
index|[
name|i
index|]
operator|.
name|dialog
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
operator|&
name|m_dialogSignalMapper
argument_list|,
name|SIGNAL
argument_list|(
name|mapped
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|openDialog
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|~KeypadNavigation
name|~
name|KeypadNavigation
parameter_list|()
block|{
operator|delete
name|ui
expr_stmt|;
block|}
protected|protected
name|slots
protected|:
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
DECL|function|setNavigationMode
name|void
name|setNavigationMode
parameter_list|(
name|int
name|mode
parameter_list|)
block|{
name|QApplication
operator|::
name|setNavigationMode
argument_list|(
name|Qt
operator|::
name|NavigationMode
argument_list|(
name|mode
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// QT_KEYPAD_NAVIGATION
DECL|function|openDialog
name|void
name|openDialog
parameter_list|(
name|int
name|dialog
parameter_list|)
block|{
switch|switch
condition|(
name|Dialog
argument_list|(
name|dialog
argument_list|)
condition|)
block|{
case|case
name|DialogGetOpenFileName
case|:
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|,
name|QLatin1String
argument_list|(
literal|"getOpenFileName"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|DialogGetSaveFileName
case|:
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|QLatin1String
argument_list|(
literal|"getSaveFileName"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|DialogGetExistingDirectory
case|:
name|QFileDialog
operator|::
name|getExistingDirectory
argument_list|(
name|this
argument_list|,
name|QLatin1String
argument_list|(
literal|"getExistingDirectory"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|DialogGetColor
case|:
name|QColorDialog
operator|::
name|getColor
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
argument_list|,
name|this
argument_list|,
name|QLatin1String
argument_list|(
literal|"getColor"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|DialogGetFont
case|:
name|QFontDialog
operator|::
name|getFont
argument_list|(
literal|0
argument_list|,
name|this
argument_list|)
expr_stmt|;
break|break;
case|case
name|DialogQuestion
case|:
name|QMessageBox
operator|::
name|question
argument_list|(
name|this
argument_list|,
name|QLatin1String
argument_list|(
literal|"question"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\xbfHola, que tal?"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|DialogAboutQt
case|:
name|QMessageBox
operator|::
name|aboutQt
argument_list|(
name|this
argument_list|)
expr_stmt|;
break|break;
case|case
name|DialogGetItem
case|:
name|QInputDialog
operator|::
name|getItem
argument_list|(
name|this
argument_list|,
name|QLatin1String
argument_list|(
literal|"getItem"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Choose a color"
argument_list|)
argument_list|,
name|QColor
operator|::
name|colorNames
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
private|private:
DECL|enum|Dialog
enum|enum
name|Dialog
block|{
DECL|enumerator|DialogGetOpenFileName
name|DialogGetOpenFileName
block|,
DECL|enumerator|DialogGetSaveFileName
name|DialogGetSaveFileName
block|,
DECL|enumerator|DialogGetExistingDirectory
name|DialogGetExistingDirectory
block|,
DECL|enumerator|DialogGetColor
name|DialogGetColor
block|,
DECL|enumerator|DialogGetFont
name|DialogGetFont
block|,
DECL|enumerator|DialogQuestion
name|DialogQuestion
block|,
DECL|enumerator|DialogAboutQt
name|DialogAboutQt
block|,
DECL|enumerator|DialogGetItem
name|DialogGetItem
block|}
enum|;
DECL|member|ui
name|Ui_KeypadNavigation
modifier|*
name|ui
decl_stmt|;
DECL|member|m_layoutSignalMapper
name|QSignalMapper
name|m_layoutSignalMapper
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
DECL|member|m_modeSignalMapper
name|QSignalMapper
name|m_modeSignalMapper
decl_stmt|;
endif|#
directive|endif
comment|// QT_KEYPAD_NAVIGATION
DECL|member|m_dialogSignalMapper
name|QSignalMapper
name|m_dialogSignalMapper
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|KeypadNavigation
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|a
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
