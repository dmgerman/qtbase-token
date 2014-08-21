begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 KDAB ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_class
DECL|class|Responder
class|class
name|Responder
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|Responder
name|Responder
parameter_list|(
name|QObject
modifier|*
name|pr
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|pr
argument_list|)
member_init_list|,
name|visibleMenu
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|visibleSubMenu
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|enabledMenu
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|enabledSubMenu
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|visibleAction
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|enabledAction
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|setVisibleObjects
name|void
name|setVisibleObjects
parameter_list|(
name|QMenu
modifier|*
name|vm
parameter_list|,
name|QMenu
modifier|*
name|vsm
parameter_list|,
name|QAction
modifier|*
name|va
parameter_list|)
block|{
name|visibleMenu
operator|=
name|vm
expr_stmt|;
name|visibleSubMenu
operator|=
name|vsm
expr_stmt|;
name|visibleAction
operator|=
name|va
expr_stmt|;
block|}
DECL|function|setEnabledObjects
name|void
name|setEnabledObjects
parameter_list|(
name|QMenu
modifier|*
name|em
parameter_list|,
name|QMenu
modifier|*
name|esm
parameter_list|,
name|QAction
modifier|*
name|ea
parameter_list|)
block|{
name|enabledMenu
operator|=
name|em
expr_stmt|;
name|enabledSubMenu
operator|=
name|esm
expr_stmt|;
name|enabledAction
operator|=
name|ea
expr_stmt|;
block|}
public|public
name|slots
public|:
DECL|function|toggleVisiblity
name|void
name|toggleVisiblity
parameter_list|()
block|{
name|visibleMenu
operator|->
name|menuAction
argument_list|()
operator|->
name|setVisible
argument_list|(
operator|!
name|visibleMenu
operator|->
name|menuAction
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|visibleSubMenu
operator|->
name|menuAction
argument_list|()
operator|->
name|setVisible
argument_list|(
operator|!
name|visibleSubMenu
operator|->
name|menuAction
argument_list|()
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|visibleAction
operator|->
name|setVisible
argument_list|(
operator|!
name|visibleAction
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|toggleEnabled
name|void
name|toggleEnabled
parameter_list|()
block|{
name|enabledMenu
operator|->
name|menuAction
argument_list|()
operator|->
name|setEnabled
argument_list|(
operator|!
name|enabledMenu
operator|->
name|menuAction
argument_list|()
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|enabledSubMenu
operator|->
name|menuAction
argument_list|()
operator|->
name|setEnabled
argument_list|(
operator|!
name|enabledSubMenu
operator|->
name|menuAction
argument_list|()
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|enabledAction
operator|->
name|setEnabled
argument_list|(
operator|!
name|enabledAction
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|toggleChecked
name|void
name|toggleChecked
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|QAction
modifier|*
name|a
init|=
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|sender
argument_list|()
argument_list|)
decl_stmt|;
block|}
DECL|function|showModalDialog
name|void
name|showModalDialog
parameter_list|()
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|NULL
argument_list|,
literal|"Something"
argument_list|,
literal|"Something happened. Modally."
argument_list|)
expr_stmt|;
block|}
DECL|function|doPreferences
name|void
name|doPreferences
parameter_list|()
block|{
name|qDebug
argument_list|()
operator|<<
literal|"show preferences"
expr_stmt|;
block|}
DECL|function|aboutToShowSubmenu
name|void
name|aboutToShowSubmenu
parameter_list|()
block|{
name|QMenu
modifier|*
name|m
init|=
operator|(
name|QMenu
operator|*
operator|)
name|sender
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"will show"
operator|<<
name|m
expr_stmt|;
name|m
operator|->
name|clear
argument_list|()
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
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|m
operator|->
name|addAction
argument_list|(
name|QString
argument_list|(
literal|"Recent File %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
private|private:
DECL|member|visibleMenu
DECL|member|visibleSubMenu
DECL|member|enabledMenu
DECL|member|enabledSubMenu
name|QMenu
modifier|*
name|visibleMenu
decl_stmt|,
modifier|*
name|visibleSubMenu
decl_stmt|,
modifier|*
name|enabledMenu
decl_stmt|,
modifier|*
name|enabledSubMenu
decl_stmt|;
DECL|member|visibleAction
DECL|member|enabledAction
name|QAction
modifier|*
name|visibleAction
decl_stmt|,
modifier|*
name|enabledAction
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|createWindow1
name|void
name|createWindow1
parameter_list|()
block|{
name|QMainWindow
modifier|*
name|window
init|=
operator|new
name|QMainWindow
decl_stmt|;
name|QMenu
modifier|*
name|menu
init|=
operator|new
name|QMenu
argument_list|(
literal|"TestMenu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|Responder
modifier|*
name|r
init|=
operator|new
name|Responder
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|a
init|=
name|menu
operator|->
name|addAction
argument_list|(
literal|"TestMenuItem1"
argument_list|)
decl_stmt|;
name|a
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|Key_A
operator||
name|Qt
operator|::
name|SHIFT
operator||
name|Qt
operator|::
name|CTRL
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|a
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|r
argument_list|,
name|SLOT
argument_list|(
name|showModalDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
literal|"T&estMenuItem2"
argument_list|)
expr_stmt|;
name|a
operator|=
name|menu
operator|->
name|addAction
argument_list|(
literal|"Preferences"
argument_list|)
expr_stmt|;
name|a
operator|->
name|setMenuRole
argument_list|(
name|QAction
operator|::
name|PreferencesRole
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|a
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|r
argument_list|,
name|SLOT
argument_list|(
name|doPreferences
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|a
operator|=
name|menu
operator|->
name|addAction
argument_list|(
literal|"TestMenuItem4"
argument_list|)
expr_stmt|;
name|a
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|Key_W
operator||
name|Qt
operator|::
name|CTRL
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu2
init|=
operator|new
name|QMenu
argument_list|(
literal|"SecondMenu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu2
argument_list|)
expr_stmt|;
name|menu2
operator|->
name|addAction
argument_list|(
literal|"Yellow"
argument_list|)
expr_stmt|;
name|a
operator|=
name|menu2
operator|->
name|addAction
argument_list|(
literal|"Mau&ve"
argument_list|)
expr_stmt|;
name|QFont
name|f
decl_stmt|;
name|f
operator|.
name|setPointSize
argument_list|(
literal|9
argument_list|)
expr_stmt|;
name|a
operator|->
name|setFont
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|menu2
operator|->
name|addAction
argument_list|(
literal|"Taupe"
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|submenu1
init|=
operator|new
name|QMenu
argument_list|(
literal|"Submenu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|submenu1
operator|->
name|addAction
argument_list|(
literal|"Sub Item 1"
argument_list|)
expr_stmt|;
name|submenu1
operator|->
name|addAction
argument_list|(
literal|"Sub Item 2"
argument_list|)
expr_stmt|;
name|submenu1
operator|->
name|addAction
argument_list|(
literal|"Sub Item 3"
argument_list|)
expr_stmt|;
name|menu2
operator|->
name|addMenu
argument_list|(
name|submenu1
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|submenu2
init|=
operator|new
name|QMenu
argument_list|(
literal|"Deeper"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|submenu2
operator|->
name|addAction
argument_list|(
literal|"Sub Sub Item 1"
argument_list|)
expr_stmt|;
name|submenu2
operator|->
name|addAction
argument_list|(
literal|"Sub Sub Item 2"
argument_list|)
expr_stmt|;
name|submenu2
operator|->
name|addAction
argument_list|(
literal|"Sub Sub Item 3"
argument_list|)
expr_stmt|;
name|submenu1
operator|->
name|addMenu
argument_list|(
name|submenu2
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu3
init|=
operator|new
name|QMenu
argument_list|(
literal|"A Third Menu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|menu3
operator|->
name|addAction
argument_list|(
literal|"Eins"
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|submenu3
init|=
operator|new
name|QMenu
argument_list|(
literal|"Dynamic"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|submenu3
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToShow
argument_list|()
argument_list|)
argument_list|,
name|r
argument_list|,
name|SLOT
argument_list|(
name|aboutToShowSubmenu
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|menu3
operator|->
name|addMenu
argument_list|(
name|submenu3
argument_list|)
expr_stmt|;
name|a
operator|=
name|menu3
operator|->
name|addAction
argument_list|(
literal|"Zwei"
argument_list|)
expr_stmt|;
name|a
operator|->
name|setShortcut
argument_list|(
name|Qt
operator|::
name|Key_3
operator||
name|Qt
operator|::
name|ALT
argument_list|)
expr_stmt|;
name|a
operator|=
name|menu3
operator|->
name|addAction
argument_list|(
literal|"About Drei..."
argument_list|)
expr_stmt|;
name|a
operator|->
name|setMenuRole
argument_list|(
name|QAction
operator|::
name|AboutRole
argument_list|)
expr_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu3
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|checkableAction
init|=
operator|new
name|QAction
argument_list|(
literal|"Thing Enabled"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|checkableAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|checkableAction
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|checkableAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|r
argument_list|,
name|SLOT
argument_list|(
name|toggleChecked
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|menu2
operator|->
name|addAction
argument_list|(
name|checkableAction
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu4
init|=
operator|new
name|QMenu
argument_list|(
literal|"Toggle menu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|toggleVisiblity
init|=
operator|new
name|QAction
argument_list|(
literal|"Toggle visibility"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|toggleEnabled
init|=
operator|new
name|QAction
argument_list|(
literal|"Toggle enabled"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|toggleVisiblity
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|r
argument_list|,
name|SLOT
argument_list|(
name|toggleVisiblity
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|toggleEnabled
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|r
argument_list|,
name|SLOT
argument_list|(
name|toggleEnabled
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|menu4
operator|->
name|addAction
argument_list|(
name|toggleVisiblity
argument_list|)
expr_stmt|;
name|menu4
operator|->
name|addAction
argument_list|(
name|toggleEnabled
argument_list|)
expr_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu4
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu5
init|=
operator|new
name|QMenu
argument_list|(
literal|"Visible Menu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|menu5
operator|->
name|addAction
argument_list|(
literal|"Dummy action"
argument_list|)
expr_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu5
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu6
init|=
operator|new
name|QMenu
argument_list|(
literal|"Menu with visible action and submenu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|visibleAction
init|=
operator|new
name|QAction
argument_list|(
literal|"Visible action"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|menu6
operator|->
name|addAction
argument_list|(
name|visibleAction
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|subMenu6
init|=
operator|new
name|QMenu
argument_list|(
literal|"Submenu"
argument_list|)
decl_stmt|;
name|subMenu6
operator|->
name|addAction
argument_list|(
literal|"Dummy action"
argument_list|)
expr_stmt|;
name|menu6
operator|->
name|addMenu
argument_list|(
name|subMenu6
argument_list|)
expr_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu6
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu7
init|=
operator|new
name|QMenu
argument_list|(
literal|"Enabled Menu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|menu7
operator|->
name|addAction
argument_list|(
literal|"Dummy action"
argument_list|)
expr_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu7
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu8
init|=
operator|new
name|QMenu
argument_list|(
literal|"Menu with enabled action and submenu"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|enabledAction
init|=
operator|new
name|QAction
argument_list|(
literal|"Enabled action"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|menu8
operator|->
name|addAction
argument_list|(
name|enabledAction
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|subMenu8
init|=
operator|new
name|QMenu
argument_list|(
literal|"Submenu"
argument_list|)
decl_stmt|;
name|subMenu8
operator|->
name|addAction
argument_list|(
literal|"Dummy action"
argument_list|)
expr_stmt|;
name|menu8
operator|->
name|addMenu
argument_list|(
name|subMenu8
argument_list|)
expr_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu8
argument_list|)
expr_stmt|;
name|r
operator|->
name|setVisibleObjects
argument_list|(
name|menu5
argument_list|,
name|subMenu6
argument_list|,
name|visibleAction
argument_list|)
expr_stmt|;
name|r
operator|->
name|setEnabledObjects
argument_list|(
name|menu7
argument_list|,
name|subMenu8
argument_list|,
name|enabledAction
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createWindow2
name|void
name|createWindow2
parameter_list|()
block|{
name|QMainWindow
modifier|*
name|window
init|=
operator|new
name|QMainWindow
decl_stmt|;
name|QMenu
modifier|*
name|menu
init|=
operator|new
name|QMenu
argument_list|(
literal|"Nuts"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
literal|"Peanuts"
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
literal|"Walnuts"
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu2
init|=
operator|new
name|QMenu
argument_list|(
literal|"Colours"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu2
argument_list|)
expr_stmt|;
name|menu2
operator|->
name|addAction
argument_list|(
literal|"Pink"
argument_list|)
expr_stmt|;
name|menu2
operator|->
name|addAction
argument_list|(
literal|"Yellow"
argument_list|)
expr_stmt|;
name|menu2
operator|->
name|addAction
argument_list|(
literal|"Grape"
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu3
init|=
operator|new
name|QMenu
argument_list|(
literal|"Edit"
argument_list|,
name|window
argument_list|)
decl_stmt|;
name|menu3
operator|->
name|addAction
argument_list|(
literal|"Cut"
argument_list|)
expr_stmt|;
name|menu3
operator|->
name|addAction
argument_list|(
literal|"Copy boring way"
argument_list|)
expr_stmt|;
name|menu3
operator|->
name|addAction
argument_list|(
literal|"Copy awesomely"
argument_list|)
expr_stmt|;
name|menu3
operator|->
name|addAction
argument_list|(
literal|"Paste"
argument_list|)
expr_stmt|;
name|window
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|menu3
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
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
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|app
operator|.
name|setApplicationName
argument_list|(
literal|"Banana"
argument_list|)
expr_stmt|;
name|createWindow1
argument_list|()
expr_stmt|;
name|createWindow2
argument_list|()
expr_stmt|;
return|return
name|app
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
