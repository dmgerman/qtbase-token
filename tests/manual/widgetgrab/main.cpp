begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QStatusBar>
end_include
begin_include
include|#
directive|include
file|<QPlainTextEdit>
end_include
begin_include
include|#
directive|include
file|<QMenuBar>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QAction>
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QComboBox>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_comment
comment|// Compiles with Qt 4.8 and Qt 5.
end_comment
begin_class
DECL|class|MainWindow
class|class
name|MainWindow
super|:
specifier|public
name|QMainWindow
block|{
name|Q_OBJECT
public|public:
name|MainWindow
parameter_list|()
constructor_decl|;
name|bool
name|eventFilter
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|QEvent
modifier|*
parameter_list|)
function_decl|;
private|private
name|slots
private|:
name|void
name|showModalDialog
parameter_list|()
function_decl|;
name|void
name|mouseGrabToggled
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|void
name|delayedMouseGrab
parameter_list|()
function_decl|;
name|void
name|grabMouseWindowToggled
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|void
name|delayedMouseWindowGrab
parameter_list|()
function_decl|;
name|void
name|keyboardGrabToggled
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|void
name|grabKeyboardWindowToggled
parameter_list|(
name|bool
parameter_list|)
function_decl|;
name|void
name|forceNativeWidgets
parameter_list|()
function_decl|;
private|private:
name|void
name|toggleMouseWidgetGrab
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|bool
name|on
parameter_list|)
function_decl|;
name|void
name|toggleKeyboardWidgetGrab
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|bool
name|on
parameter_list|)
function_decl|;
DECL|member|m_mouseEventCount
name|int
name|m_mouseEventCount
decl_stmt|;
DECL|member|m_enterLeaveEventCount
name|int
name|m_enterLeaveEventCount
decl_stmt|;
DECL|member|m_logEdit
name|QPlainTextEdit
modifier|*
name|m_logEdit
decl_stmt|;
DECL|member|m_grabMouseCheckBox
name|QCheckBox
modifier|*
name|m_grabMouseCheckBox
decl_stmt|;
DECL|member|m_grabMouseWindowCheckBox
name|QCheckBox
modifier|*
name|m_grabMouseWindowCheckBox
decl_stmt|;
DECL|member|m_grabKeyboardCheckBox
name|QCheckBox
modifier|*
name|m_grabKeyboardCheckBox
decl_stmt|;
DECL|member|m_grabKeyboardWindowCheckBox
name|QCheckBox
modifier|*
name|m_grabKeyboardWindowCheckBox
decl_stmt|;
DECL|member|m_forceNativeButton
name|QPushButton
modifier|*
name|m_forceNativeButton
decl_stmt|;
DECL|member|m_lastMouseMoveEvent
name|QString
name|m_lastMouseMoveEvent
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|ClickableLabel
class|class
name|ClickableLabel
super|:
specifier|public
name|QLabel
block|{
name|Q_OBJECT
public|public:
DECL|function|ClickableLabel
specifier|explicit
name|ClickableLabel
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QLabel
argument_list|(
name|text
argument_list|,
name|parent
argument_list|)
block|{}
signals|signals:
name|void
name|pressed
parameter_list|()
function_decl|;
protected|protected:
DECL|function|mousePressEvent
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
block|{
emit|emit
name|pressed
argument_list|()
emit|;
name|QLabel
operator|::
name|mousePressEvent
argument_list|(
name|ev
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|testCasesC
specifier|static
specifier|const
name|char
name|testCasesC
index|[]
init|=
literal|"- Drag a scrollbar, move mouse out of the window. The scrollbar should still react.\n\n"
literal|"- Press mouse inside window, move outside while pressing the button. Mouse events"
literal|" should be reported until the button is released.\n\n"
literal|"- 'Show modal dialog on press' opens a modal dialog on mouse press. This should not lock up.\n\n"
literal|"- Check the 'Grab Mouse' box. Only the checkbox should then receive mouse move events.\n\n"
literal|"- Open popup menu. Mouse events should all go to popup menu while it is visible.\n\n"
literal|"- Click delayed grab and then open popup immediately. Wait for Grab checkbox to be marked. "
literal|"Click on popup menu to close it. Mouse events should be going to Grab checkbox. "
literal|"Click on Grab checkbox to clear it. UI should respond normally after that. \n\n"
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
member_init_list|:
name|m_mouseEventCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_enterLeaveEventCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_logEdit
argument_list|(
operator|new
name|QPlainTextEdit
argument_list|(
name|this
argument_list|)
argument_list|)
member_init_list|,
name|m_grabMouseCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|QLatin1String
argument_list|(
literal|"Grab Mouse"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_grabMouseWindowCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|QLatin1String
argument_list|(
literal|"Grab Mouse Window Ctrl+W"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_grabKeyboardCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|QLatin1String
argument_list|(
literal|"Grab Keyboard"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_grabKeyboardWindowCheckBox
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|QLatin1String
argument_list|(
literal|"Grab Keyboard Window"
argument_list|)
argument_list|)
argument_list|)
member_init_list|,
name|m_forceNativeButton
argument_list|(
operator|new
name|QPushButton
argument_list|(
name|QLatin1String
argument_list|(
literal|"Force native widgets"
argument_list|)
argument_list|)
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"MainWindow"
argument_list|)
argument_list|)
expr_stmt|;
name|setMinimumWidth
argument_list|(
literal|800
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Manual Grab Test %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|fileMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|QLatin1String
argument_list|(
literal|"File"
argument_list|)
argument_list|)
decl_stmt|;
name|fileMenu
operator|->
name|setObjectName
argument_list|(
literal|"FileMenu"
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|quit
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|QLatin1String
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
decl_stmt|;
name|quit
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quit
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|editMenu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|QLatin1String
argument_list|(
literal|"Edit"
argument_list|)
argument_list|)
decl_stmt|;
name|editMenu
operator|->
name|setObjectName
argument_list|(
literal|"EditMenu"
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|clearLog
init|=
name|editMenu
operator|->
name|addAction
argument_list|(
name|QLatin1String
argument_list|(
literal|"Clear Log"
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|clearLog
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|m_logEdit
argument_list|,
name|SLOT
argument_list|(
name|clear
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|w
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"CentralWidget"
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|QPlainTextEdit
modifier|*
name|instructions
init|=
operator|new
name|QPlainTextEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|instructions
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"InstructionsEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|instructions
operator|->
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOn
argument_list|)
expr_stmt|;
name|instructions
operator|->
name|setPlainText
argument_list|(
name|QLatin1String
argument_list|(
name|testCasesC
argument_list|)
argument_list|)
expr_stmt|;
name|instructions
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|instructions
argument_list|)
expr_stmt|;
name|int
name|row
init|=
literal|0
decl_stmt|;
name|QGridLayout
modifier|*
name|controlLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addLayout
argument_list|(
name|controlLayout
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|modalDialogButton
init|=
operator|new
name|QPushButton
argument_list|(
literal|"Show modal dialog on release"
argument_list|)
decl_stmt|;
name|modalDialogButton
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"ModalDialogButton"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|modalDialogButton
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
name|showModalDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|modalDialogButton
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ClickableLabel
modifier|*
name|modalDialogLabel
init|=
operator|new
name|ClickableLabel
argument_list|(
literal|"Show modal dialog on press"
argument_list|)
decl_stmt|;
name|modalDialogLabel
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"ModalDialogLabel"
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|modalDialogLabel
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|modalDialogLabel
argument_list|,
name|SIGNAL
argument_list|(
name|pressed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showModalDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|row
operator|++
expr_stmt|;
name|m_grabMouseCheckBox
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"GrabCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_grabMouseCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|mouseGrabToggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|m_grabMouseCheckBox
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|delayedGrabButton
init|=
operator|new
name|QPushButton
argument_list|(
literal|"Delayed grab"
argument_list|)
decl_stmt|;
name|delayedGrabButton
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"DelayedGrabButton"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|delayedGrabButton
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
name|delayedMouseGrab
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|delayedGrabButton
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|row
operator|++
expr_stmt|;
name|m_grabMouseWindowCheckBox
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"GrabWindowCheckBox"
argument_list|)
argument_list|)
expr_stmt|;
name|m_grabMouseWindowCheckBox
operator|->
name|setShortcut
argument_list|(
name|QKeySequence
argument_list|(
name|Qt
operator|::
name|CTRL
operator||
name|Qt
operator|::
name|Key_W
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_grabMouseWindowCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|grabMouseWindowToggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|m_grabMouseWindowCheckBox
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|delayedWindowGrabButton
init|=
operator|new
name|QPushButton
argument_list|(
literal|"Delayed window grab"
argument_list|)
decl_stmt|;
name|delayedWindowGrabButton
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"DelayedWindowGrabButton"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|delayedWindowGrabButton
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
name|delayedMouseWindowGrab
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|delayedWindowGrabButton
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|row
operator|++
expr_stmt|;
name|m_grabKeyboardCheckBox
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"GrabKeyboardBox"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_grabKeyboardCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|keyboardGrabToggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|m_grabKeyboardCheckBox
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_grabKeyboardWindowCheckBox
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"GrabKeyboardWindowBox"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_grabKeyboardWindowCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|grabKeyboardWindowToggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|m_grabKeyboardWindowCheckBox
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|row
operator|++
expr_stmt|;
name|QComboBox
modifier|*
name|combo
init|=
operator|new
name|QComboBox
decl_stmt|;
name|combo
operator|->
name|addItems
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"Popup test 1"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"Popup test 2"
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|combo
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|popupMenuButton
init|=
operator|new
name|QPushButton
argument_list|(
literal|"Popup menu"
argument_list|)
decl_stmt|;
name|popupMenuButton
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"PopupMenuButton"
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|popupMenu
init|=
operator|new
name|QMenu
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|popupMenu
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"PopupMenu"
argument_list|)
argument_list|)
expr_stmt|;
name|popupMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&First Item"
argument_list|)
argument_list|)
expr_stmt|;
name|popupMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Second Item"
argument_list|)
argument_list|)
expr_stmt|;
name|popupMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Third Item"
argument_list|)
argument_list|)
expr_stmt|;
name|popupMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"F&ourth Item"
argument_list|)
argument_list|)
expr_stmt|;
name|popupMenuButton
operator|->
name|setMenu
argument_list|(
name|popupMenu
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|popupMenuButton
argument_list|,
name|row
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|row
operator|++
expr_stmt|;
name|m_forceNativeButton
operator|->
name|setObjectName
argument_list|(
literal|"ForceNativeWidgetsButton"
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|m_forceNativeButton
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_forceNativeButton
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
name|forceNativeWidgets
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|row
operator|++
expr_stmt|;
name|QLineEdit
modifier|*
name|lineEdit
init|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|lineEdit
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"LineEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|controlLayout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|,
name|row
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|m_logEdit
operator|->
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAlwaysOn
argument_list|)
expr_stmt|;
name|m_logEdit
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"LogEdit"
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|m_logEdit
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|eventFilter
name|bool
name|MainWindow
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|o
operator|->
name|isWidgetType
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|Enter
case|:
block|{
name|QString
name|message
decl_stmt|;
name|QDebug
name|debug
argument_list|(
operator|&
name|message
argument_list|)
decl_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
specifier|const
name|QEnterEvent
modifier|*
name|ee
init|=
cast|static_cast
argument_list|<
name|QEnterEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|'#'
operator|<<
name|m_enterLeaveEventCount
operator|++
operator|<<
literal|" Enter for "
operator|<<
name|o
operator|->
name|objectName
argument_list|()
operator|<<
literal|" at "
operator|<<
name|ee
operator|->
name|localPos
argument_list|()
operator|<<
literal|" global: "
operator|<<
name|ee
operator|->
name|globalPos
argument_list|()
expr_stmt|;
else|#
directive|else
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|'#'
operator|<<
name|m_enterLeaveEventCount
operator|++
operator|<<
literal|" Enter for "
operator|<<
name|o
operator|->
name|objectName
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|Leave
case|:
block|{
name|QString
name|message
decl_stmt|;
name|QDebug
name|debug
argument_list|(
operator|&
name|message
argument_list|)
decl_stmt|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|'#'
operator|<<
name|m_enterLeaveEventCount
operator|++
operator|<<
literal|" Leave for "
operator|<<
name|o
operator|->
name|objectName
argument_list|()
expr_stmt|;
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|MouseButtonPress
case|:
case|case
name|QEvent
operator|::
name|MouseButtonRelease
case|:
block|{
specifier|const
name|QMouseEvent
modifier|*
name|me
init|=
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QString
name|message
decl_stmt|;
name|QDebug
name|debug
init|=
name|QDebug
argument_list|(
operator|&
name|message
argument_list|)
operator|.
name|nospace
argument_list|()
decl_stmt|;
name|debug
operator|<<
literal|'#'
operator|<<
name|m_mouseEventCount
operator|++
operator|<<
literal|' '
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseButtonPress
condition|)
block|{
if|if
condition|(
name|me
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
condition|)
name|debug
operator|<<
literal|"Left button press"
expr_stmt|;
if|if
condition|(
name|me
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|MiddleButton
condition|)
name|debug
operator|<<
literal|"Middle button press"
expr_stmt|;
if|if
condition|(
name|me
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|RightButton
condition|)
name|debug
operator|<<
literal|"Right button press"
expr_stmt|;
block|}
else|else
block|{
name|debug
operator|<<
literal|"Button release"
expr_stmt|;
block|}
name|debug
operator|<<
literal|" on "
operator|<<
name|o
operator|->
name|objectName
argument_list|()
operator|<<
literal|" Mousegrabber "
operator|<<
name|QWidget
operator|::
name|mouseGrabber
argument_list|()
expr_stmt|;
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|MouseMove
case|:
block|{
specifier|const
name|QMouseEvent
modifier|*
name|me
init|=
cast|static_cast
argument_list|<
specifier|const
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
specifier|const
name|QWidget
modifier|*
name|widgetUnderMouse
init|=
name|QApplication
operator|::
name|widgetAt
argument_list|(
name|me
operator|->
name|globalPos
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|message
decl_stmt|;
name|QDebug
name|d
init|=
name|QDebug
argument_list|(
operator|&
name|message
argument_list|)
operator|.
name|nospace
argument_list|()
decl_stmt|;
name|d
operator|<<
literal|" Mouse move reported for "
operator|<<
name|o
operator|->
name|objectName
argument_list|()
expr_stmt|;
if|if
condition|(
name|widgetUnderMouse
condition|)
block|{
name|d
operator|<<
literal|" over "
operator|<<
name|widgetUnderMouse
expr_stmt|;
block|}
else|else
block|{
name|d
operator|<<
literal|" outside "
expr_stmt|;
block|}
name|d
operator|<<
literal|" mouse grabber "
operator|<<
name|QWidget
operator|::
name|mouseGrabber
argument_list|()
expr_stmt|;
comment|// Compress mouse move event logging.
if|if
condition|(
name|message
operator|!=
name|m_lastMouseMoveEvent
condition|)
block|{
name|m_lastMouseMoveEvent
operator|=
name|message
expr_stmt|;
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"#%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|m_mouseEventCount
operator|++
argument_list|)
operator|.
name|arg
argument_list|(
name|message
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
name|QEvent
operator|::
name|KeyRelease
case|:
case|case
name|QEvent
operator|::
name|KeyPress
case|:
block|{
specifier|const
name|QKeyEvent
modifier|*
name|ke
init|=
cast|static_cast
argument_list|<
specifier|const
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|QString
name|message
decl_stmt|;
name|QDebug
name|d
init|=
name|QDebug
argument_list|(
operator|&
name|message
argument_list|)
operator|.
name|nospace
argument_list|()
decl_stmt|;
name|d
operator|<<
operator|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|?
literal|"Key press"
else|:
literal|"Key release"
operator|)
operator|<<
literal|' '
operator|<<
name|ke
operator|->
name|text
argument_list|()
operator|<<
literal|" on "
operator|<<
name|o
operator|<<
literal|" key grabber "
operator|<<
name|QWidget
operator|::
name|keyboardGrabber
argument_list|()
expr_stmt|;
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|message
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
block|}
return|return
name|QMainWindow
operator|::
name|eventFilter
argument_list|(
name|o
argument_list|,
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|showModalDialog
name|void
name|MainWindow
operator|::
name|showModalDialog
parameter_list|()
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|QLatin1String
argument_list|(
literal|"Information"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"Modal Dialog"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toggleMouseWidgetGrab
name|void
name|MainWindow
operator|::
name|toggleMouseWidgetGrab
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|bool
name|on
parameter_list|)
block|{
if|if
condition|(
name|on
condition|)
block|{
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|w
operator|->
name|objectName
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|" grabbed mouse."
argument_list|)
argument_list|)
expr_stmt|;
name|w
operator|->
name|grabMouse
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|w
operator|->
name|releaseMouse
argument_list|()
expr_stmt|;
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|w
operator|->
name|objectName
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|" released mouse."
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toggleKeyboardWidgetGrab
name|void
name|MainWindow
operator|::
name|toggleKeyboardWidgetGrab
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|bool
name|on
parameter_list|)
block|{
if|if
condition|(
name|on
condition|)
block|{
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|w
operator|->
name|objectName
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|" grabbed keyboard."
argument_list|)
argument_list|)
expr_stmt|;
name|w
operator|->
name|grabKeyboard
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|w
operator|->
name|releaseKeyboard
argument_list|()
expr_stmt|;
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|w
operator|->
name|objectName
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|" released keyboard."
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|mouseGrabToggled
name|void
name|MainWindow
operator|::
name|mouseGrabToggled
parameter_list|(
name|bool
name|g
parameter_list|)
block|{
name|toggleMouseWidgetGrab
argument_list|(
name|m_grabMouseCheckBox
argument_list|,
name|g
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|delayedMouseGrab
name|void
name|MainWindow
operator|::
name|delayedMouseGrab
parameter_list|()
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|2000
argument_list|,
name|m_grabMouseCheckBox
argument_list|,
name|SLOT
argument_list|(
name|animateClick
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|grabMouseWindowToggled
name|void
name|MainWindow
operator|::
name|grabMouseWindowToggled
parameter_list|(
name|bool
name|g
parameter_list|)
block|{
name|toggleMouseWidgetGrab
argument_list|(
name|this
argument_list|,
name|g
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|delayedMouseWindowGrab
name|void
name|MainWindow
operator|::
name|delayedMouseWindowGrab
parameter_list|()
block|{
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|2000
argument_list|,
name|m_grabMouseWindowCheckBox
argument_list|,
name|SLOT
argument_list|(
name|animateClick
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboardGrabToggled
name|void
name|MainWindow
operator|::
name|keyboardGrabToggled
parameter_list|(
name|bool
name|g
parameter_list|)
block|{
name|toggleKeyboardWidgetGrab
argument_list|(
name|m_grabKeyboardCheckBox
argument_list|,
name|g
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|grabKeyboardWindowToggled
name|void
name|MainWindow
operator|::
name|grabKeyboardWindowToggled
parameter_list|(
name|bool
name|g
parameter_list|)
block|{
name|toggleKeyboardWidgetGrab
argument_list|(
name|this
argument_list|,
name|g
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|forceNativeWidgets
name|void
name|MainWindow
operator|::
name|forceNativeWidgets
parameter_list|()
block|{
specifier|const
name|WId
name|platformWid
init|=
name|m_forceNativeButton
operator|->
name|winId
argument_list|()
decl_stmt|;
if|#
directive|if
name|QT_VERSION
operator|<
literal|0x050000
operator|&&
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
specifier|const
name|quintptr
name|wid
init|=
name|quintptr
argument_list|(
name|platformWid
argument_list|)
decl_stmt|;
comment|// HWND on Qt 4.8/Windows.
else|#
directive|else
specifier|const
name|WId
name|wid
init|=
name|platformWid
decl_stmt|;
endif|#
directive|endif
name|m_logEdit
operator|->
name|appendPlainText
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Created native widget %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|wid
argument_list|)
argument_list|)
expr_stmt|;
name|m_forceNativeButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|m_forceNativeButton
operator|->
name|setText
argument_list|(
name|QLatin1String
argument_list|(
literal|"Native widgets created"
argument_list|)
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
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|MainWindow
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
