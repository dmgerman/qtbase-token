begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
name|Window
parameter_list|()
constructor_decl|;
public|public
name|slots
public|:
name|void
name|triggered
parameter_list|(
name|QAction
modifier|*
parameter_list|)
function_decl|;
name|void
name|clean
parameter_list|()
function_decl|;
name|void
name|showPoppWindow
parameter_list|()
function_decl|;
private|private:
DECL|member|explanation
name|QLabel
modifier|*
name|explanation
decl_stmt|;
DECL|member|toolButton
name|QToolButton
modifier|*
name|toolButton
decl_stmt|;
DECL|member|menu
name|QMenu
modifier|*
name|menu
decl_stmt|;
DECL|member|echo
name|QLineEdit
modifier|*
name|echo
decl_stmt|;
DECL|member|comboBox
name|QComboBox
modifier|*
name|comboBox
decl_stmt|;
DECL|member|pushButton
name|QPushButton
modifier|*
name|pushButton
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|QGroupBox
modifier|*
name|group
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"test the popup"
argument_list|)
argument_list|)
decl_stmt|;
name|explanation
operator|=
operator|new
name|QLabel
argument_list|(
literal|"This test is used to verify that popup windows will be closed "
literal|"as expected. This includes when clicking outside the popup or moving the "
literal|"parent window. Tested popups include context menus, combo box popups, tooltips "
literal|"and QWindow with Qt::Popup set."
argument_list|)
expr_stmt|;
name|explanation
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|explanation
operator|->
name|setToolTip
argument_list|(
literal|"I'm a tool tip!"
argument_list|)
expr_stmt|;
name|menu
operator|=
operator|new
name|QMenu
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"line one"
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"line two"
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"line three"
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"line four"
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"line five"
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|subMenu1
init|=
operator|new
name|QMenu
argument_list|()
decl_stmt|;
name|subMenu1
operator|->
name|addAction
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
name|subMenu1
operator|->
name|addAction
argument_list|(
literal|"2"
argument_list|)
expr_stmt|;
name|subMenu1
operator|->
name|addAction
argument_list|(
literal|"3"
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addMenu
argument_list|(
name|subMenu1
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|subMenu2
init|=
operator|new
name|QMenu
argument_list|()
decl_stmt|;
name|subMenu2
operator|->
name|addAction
argument_list|(
literal|"2 1"
argument_list|)
expr_stmt|;
name|subMenu2
operator|->
name|addAction
argument_list|(
literal|"2 2"
argument_list|)
expr_stmt|;
name|subMenu2
operator|->
name|addAction
argument_list|(
literal|"2 3"
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addMenu
argument_list|(
name|subMenu2
argument_list|)
expr_stmt|;
name|toolButton
operator|=
operator|new
name|QToolButton
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setMenu
argument_list|(
name|menu
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setPopupMode
argument_list|(
name|QToolButton
operator|::
name|MenuButtonPopup
argument_list|)
expr_stmt|;
name|toolButton
operator|->
name|setText
argument_list|(
literal|"select me"
argument_list|)
expr_stmt|;
name|echo
operator|=
operator|new
name|QLineEdit
argument_list|(
name|group
argument_list|)
expr_stmt|;
name|echo
operator|->
name|setPlaceholderText
argument_list|(
literal|"not triggered"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|menu
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|menu
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToShow
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|clean
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|comboBox
operator|=
operator|new
name|QComboBox
argument_list|()
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
literal|"Item 1"
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
literal|"Item 2"
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
literal|"Item 3"
argument_list|)
expr_stmt|;
name|pushButton
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"Show popup window"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pushButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showPoppWindow
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|explanation
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|toolButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|echo
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|comboBox
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|pushButton
argument_list|)
expr_stmt|;
name|group
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Popup Window Testing"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|clean
name|void
name|Window
operator|::
name|clean
parameter_list|()
block|{
name|echo
operator|->
name|setText
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showPoppWindow
name|void
name|Window
operator|::
name|showPoppWindow
parameter_list|()
block|{
name|QWindow
modifier|*
name|window
init|=
operator|new
name|QWindow
argument_list|()
decl_stmt|;
name|window
operator|->
name|setTransientParent
argument_list|(
name|this
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
name|window
operator|->
name|setPosition
argument_list|(
name|this
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|window
operator|->
name|setWidth
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|window
operator|->
name|setHeight
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|window
operator|->
name|setFlags
argument_list|(
name|Qt
operator|::
name|Window
operator||
name|Qt
operator|::
name|Popup
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
DECL|function|triggered
name|void
name|Window
operator|::
name|triggered
parameter_list|(
name|QAction
modifier|*
name|act
parameter_list|)
block|{
if|if
condition|(
operator|!
name|act
condition|)
return|return;
name|echo
operator|->
name|setText
argument_list|(
name|act
operator|->
name|text
argument_list|()
argument_list|)
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
name|argv
index|[]
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
name|Window
name|window
decl_stmt|;
name|window
operator|.
name|show
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
