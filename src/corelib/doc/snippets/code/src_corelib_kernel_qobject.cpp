begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|lineEdit
name|QLineEdit
modifier|*
name|lineEdit
init|=
cast|static_cast
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|qt_find_obj_child
argument_list|(
name|myWidget
argument_list|,
literal|"QLineEdit"
argument_list|,
literal|"my line edit"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|lineEdit
condition|)
name|lineEdit
operator|->
name|setText
argument_list|(
literal|"Default"
argument_list|)
expr_stmt|;
end_if
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|obj
name|QObject
modifier|*
name|obj
init|=
operator|new
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|obj
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "QPushButton"
end_comment
begin_expr_stmt
name|QPushButton
operator|::
name|staticMetaObject
operator|.
name|className
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "QPushButton"
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|QPushButton
operator|::
name|staticMetaObject
operator|.
name|className
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "QPushButton"
end_comment
begin_decl_stmt
DECL|variable|obj
name|QObject
modifier|*
name|obj
init|=
operator|new
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|obj
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "QPushButton"
end_comment
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|obj
name|QObject
modifier|*
name|obj
init|=
operator|new
name|QTimer
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|obj
comment|// QTimer inherits QObject
end_comment
begin_decl_stmt
DECL|variable|timer
name|QTimer
modifier|*
name|timer
init|=
name|qobject_cast
argument_list|<
name|QTimer
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// timer == (QObject *)obj
end_comment
begin_decl_stmt
DECL|variable|button
name|QAbstractButton
modifier|*
name|button
init|=
name|qobject_cast
argument_list|<
name|QAbstractButton
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// button == 0
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|timer
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|timer
comment|// QTimer inherits QObject
end_comment
begin_expr_stmt
name|timer
operator|->
name|inherits
argument_list|(
literal|"QTimer"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|timer
operator|->
name|inherits
argument_list|(
literal|"QObject"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|timer
operator|->
name|inherits
argument_list|(
literal|"QAbstractButton"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns false
end_comment
begin_comment
comment|// QVBoxLayout inherits QObject and QLayoutItem
end_comment
begin_decl_stmt
DECL|variable|layout
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|layout
operator|->
name|inherits
argument_list|(
literal|"QObject"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true
end_comment
begin_expr_stmt
name|layout
operator|->
name|inherits
argument_list|(
literal|"QLayoutItem"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns true (even though QLayoutItem is not a QObject)
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_expr_stmt
name|qDebug
argument_list|(
literal|"MyClass::setPrecision(): (%s) invalid precision %f"
argument_list|,
name|qPrintable
argument_list|(
name|objectName
argument_list|()
argument_list|)
argument_list|,
name|newPrecision
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_class
DECL|class|MainWindow
class|class
name|MainWindow
super|:
specifier|public
name|QMainWindow
block|{
public|public:
name|MainWindow
parameter_list|()
constructor_decl|;
protected|protected:
name|bool
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
name|QEvent
modifier|*
name|ev
parameter_list|)
function_decl|;
private|private:
DECL|member|textEdit
name|QTextEdit
modifier|*
name|textEdit
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|textEdit
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|setCentralWidget
argument_list|(
name|textEdit
argument_list|)
expr_stmt|;
name|textEdit
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
name|obj
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|obj
operator|==
name|textEdit
condition|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
block|{
name|QKeyEvent
modifier|*
name|keyEvent
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Ate key press"
operator|<<
name|keyEvent
operator|->
name|key
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
return|return
literal|false
return|;
block|}
block|}
else|else
block|{
comment|// pass the event on to the parent class
return|return
name|QMainWindow
operator|::
name|eventFilter
argument_list|(
name|obj
argument_list|,
name|event
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_expr_stmt
name|myObject
operator|->
name|moveToThread
argument_list|(
name|QApplication
operator|::
name|instance
argument_list|()
operator|->
name|thread
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_class
DECL|class|MyObject
class|class
name|MyObject
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|MyObject
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
protected|protected:
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|MyObject
name|MyObject
operator|::
name|MyObject
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{
name|startTimer
argument_list|(
literal|50
argument_list|)
expr_stmt|;
comment|// 50-millisecond timer
name|startTimer
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|// 1-second timer
name|startTimer
argument_list|(
literal|60000
argument_list|)
expr_stmt|;
comment|// 1-minute timer
block|}
end_constructor
begin_function
DECL|function|timerEvent
name|void
name|MyObject
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|event
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Timer ID:"
operator|<<
name|event
operator|->
name|timerId
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|QObject
modifier|*
argument_list|>
name|list
init|=
name|window
argument_list|()
operator|->
name|queryList
argument_list|(
literal|"QAbstractButton"
argument_list|)
init|)
decl_stmt|;
end_decl_stmt
begin_foreach
foreach|foreach
control|(
name|QObject
modifier|*
name|obj
decl|,
name|list
control|)
DECL|variable|false
cast|static_cast
argument_list|<
name|QAbstractButton
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
end_foreach
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|button
name|QPushButton
modifier|*
name|button
init|=
name|parentWidget
operator|->
name|findChild
argument_list|<
name|QPushButton
operator|*
argument_list|>
argument_list|(
literal|"button1"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|list
name|QListWidget
modifier|*
name|list
init|=
name|parentWidget
operator|->
name|findChild
argument_list|<
name|QListWidget
operator|*
argument_list|>
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
DECL|variable|widgets
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|widgets
init|=
name|parentWidget
operator|.
name|findChildren
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
literal|"widgetname"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_decl_stmt
DECL|variable|allPButtons
name|QList
argument_list|<
name|QPushButton
modifier|*
argument_list|>
name|allPButtons
init|=
name|parentWidget
operator|.
name|findChildren
argument_list|<
name|QPushButton
operator|*
argument_list|>
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_expr_stmt
name|monitoredObj
operator|->
name|installEventFilter
argument_list|(
name|filterObj
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_class
DECL|class|KeyPressEater
class|class
name|KeyPressEater
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
operator|...
specifier|protected
operator|:
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
expr_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|eventFilter
name|bool
name|KeyPressEater
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
block|{
name|QKeyEvent
modifier|*
name|keyEvent
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qDebug
argument_list|(
literal|"Ate key press %d"
argument_list|,
name|keyEvent
operator|->
name|key
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
block|{
comment|// standard event processing
return|return
name|QObject
operator|::
name|eventFilter
argument_list|(
name|obj
argument_list|,
name|event
argument_list|)
return|;
block|}
block|}
end_function
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_decl_stmt
DECL|variable|keyPressEater
name|KeyPressEater
modifier|*
name|keyPressEater
init|=
operator|new
name|KeyPressEater
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|pushButton
name|QPushButton
modifier|*
name|pushButton
init|=
operator|new
name|QPushButton
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|listView
name|QListView
modifier|*
name|listView
init|=
operator|new
name|QListView
argument_list|(
name|this
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|pushButton
operator|->
name|installEventFilter
argument_list|(
name|keyPressEater
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|listView
operator|->
name|installEventFilter
argument_list|(
name|keyPressEater
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_constructor
DECL|function|MyWindow
name|MyWindow
operator|::
name|MyWindow
parameter_list|()
block|{
name|QLabel
modifier|*
name|senderLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Name:"
argument_list|)
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|recipientLabel
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Name:"
argument_list|,
literal|"recipient"
argument_list|)
argument_list|)
decl_stmt|;
comment|//! [17]
block|}
end_constructor
begin_comment
comment|//! [18]
end_comment
begin_decl_stmt
DECL|variable|n
name|int
name|n
init|=
name|messages
operator|.
name|count
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"%n message(s) saved"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_expr_stmt
name|n
operator|==
literal|1
condition|?
name|tr
argument_list|(
literal|"%n message saved"
argument_list|)
else|:
name|tr
argument_list|(
literal|"%n messages saved"
argument_list|)
comment|//! [19]
comment|//! [20]
name|label
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"F\374r \310lise"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_if
if|if
condition|(
name|receivers
argument_list|(
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|QByteArray
argument_list|)
argument_list|)
argument_list|)
operator|>
literal|0
condition|)
block|{
name|QByteArray
name|data
decl_stmt|;
name|get_the_value
argument_list|(
operator|&
name|data
argument_list|)
expr_stmt|;
comment|// expensive operation
emit|emit
name|valueChanged
argument_list|(
name|data
argument_list|)
emit|;
block|}
end_if
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_decl_stmt
DECL|variable|label
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|scrollBar
name|QScrollBar
modifier|*
name|scrollBar
init|=
operator|new
name|QScrollBar
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QObject
operator|::
name|connect
argument_list|(
name|scrollBar
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|label
argument_list|,
name|SLOT
argument_list|(
name|setNum
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|// WRONG
end_comment
begin_expr_stmt
name|QObject
operator|::
name|connect
argument_list|(
name|scrollBar
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
argument|int value
argument_list|)
argument_list|)
argument_list|,
name|label
argument_list|,
name|SLOT
argument_list|(
name|setNum
argument_list|(
argument|int value
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_class
DECL|class|MyWidget
class|class
name|MyWidget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
name|MyWidget
parameter_list|()
constructor_decl|;
signals|signals:
name|void
name|buttonClicked
parameter_list|()
function_decl|;
private|private:
DECL|member|myButton
name|QPushButton
modifier|*
name|myButton
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|MyWidget
name|MyWidget
operator|::
name|MyWidget
parameter_list|()
block|{
name|myButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|myButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|buttonClicked
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_label
name|QObject
end_label
begin_label
unit|::
name|connect
label|:
end_label
begin_decl_stmt
name|Cannot
name|queue
name|arguments
name|of
name|type
decl|'MyType'
argument_list|(
name|Make
name|sure
literal|'MyType'
name|is
name|registered
expr|using
name|qRegisterMetaType
argument_list|()
operator|.
argument_list|)
comment|//! [25]
comment|//! [26]
name|disconnect
argument_list|(
name|myObject
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [26]
end_comment
begin_comment
comment|//! [27]
end_comment
begin_expr_stmt
name|myObject
operator|->
name|disconnect
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [27]
end_comment
begin_comment
comment|//! [28]
end_comment
begin_expr_stmt
name|disconnect
argument_list|(
name|myObject
argument_list|,
name|SIGNAL
argument_list|(
name|mySignal
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [28]
end_comment
begin_comment
comment|//! [29]
end_comment
begin_expr_stmt
name|myObject
operator|->
name|disconnect
argument_list|(
name|SIGNAL
argument_list|(
name|mySignal
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [29]
end_comment
begin_comment
comment|//! [30]
end_comment
begin_expr_stmt
name|disconnect
argument_list|(
name|myObject
argument_list|,
literal|0
argument_list|,
name|myReceiver
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [30]
end_comment
begin_comment
comment|//! [31]
end_comment
begin_expr_stmt
name|myObject
operator|->
name|disconnect
argument_list|(
name|myReceiver
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [31]
end_comment
begin_comment
comment|//! [32]
end_comment
begin_if
if|if
condition|(
name|signal
operator|==
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|MyObject
operator|::
name|valueChanged
argument_list|)
condition|)
block|{
comment|// signal is valueChanged
block|}
end_if
begin_comment
comment|//! [32]
end_comment
begin_comment
comment|//! [33]
end_comment
begin_decl_stmt
name|void
name|on_
argument_list|<
name|object
name|name
argument_list|>
name|_
argument_list|<
name|signal
name|name
argument_list|>
argument_list|(
operator|<
name|signal
name|parameters
operator|>
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [33]
end_comment
begin_comment
comment|//! [34]
end_comment
begin_function_decl
name|void
name|on_button1_clicked
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//! [34]
end_comment
begin_comment
comment|//! [35]
end_comment
begin_class
DECL|class|MyClass
class|class
name|MyClass
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"Author"
argument_list|,
literal|"Pierre Gendron"
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"URL"
argument_list|,
literal|"http://www.my-organization.qc.ca"
argument_list|)
decl|public
range|:
operator|...
block|}
class|;
end_class
begin_comment
comment|//! [35]
end_comment
begin_comment
comment|//! [37]
end_comment
begin_macro
name|Q_PROPERTY
argument_list|(
argument|QString title READ title WRITE setTitle USER
literal|true
argument_list|)
end_macro
begin_comment
comment|//! [37]
end_comment
begin_comment
comment|//! [38]
end_comment
begin_class
DECL|class|MyClass
class|class
name|MyClass
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|MyClass
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|~
name|MyClass
parameter_list|()
destructor_decl|;
DECL|enum|Priority
DECL|enumerator|High
DECL|enumerator|Low
DECL|enumerator|VeryHigh
DECL|enumerator|VeryLow
enum|enum
name|Priority
block|{
name|High
block|,
name|Low
block|,
name|VeryHigh
block|,
name|VeryLow
block|}
enum|;
name|Q_ENUM
argument_list|(
argument|Priority
argument_list|)
name|void
name|setPriority
parameter_list|(
name|Priority
name|priority
parameter_list|)
function_decl|;
name|Priority
name|priority
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [38]
end_comment
begin_comment
comment|//! [39]
end_comment
begin_class
DECL|class|QLibrary
class|class
name|QLibrary
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
operator|...
expr|enum
DECL|enum|LoadHint
name|LoadHint
block|{
DECL|enumerator|ResolveAllSymbolsHint
name|ResolveAllSymbolsHint
operator|=
literal|0x01
block|,
DECL|enumerator|ExportExternalSymbolsHint
name|ExportExternalSymbolsHint
operator|=
literal|0x02
block|,
DECL|enumerator|LoadArchiveMemberHint
name|LoadArchiveMemberHint
operator|=
literal|0x04
block|}
expr_stmt|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|LoadHints
argument_list|,
argument|LoadHint
argument_list|)
name|Q_FLAG
argument_list|(
argument|LoadHints
argument_list|)
operator|...
block|}
comment|//! [39]
comment|//! [40]
comment|//: This name refers to a host name.
name|hostNameLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Name:"
argument_list|)
argument_list|)
class|;
end_class
begin_comment
comment|/*: This text refers to a C++ code example. */
end_comment
begin_decl_stmt
DECL|variable|example
name|QString
name|example
init|=
name|tr
argument_list|(
literal|"Example"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [40]
end_comment
begin_comment
comment|//! [41]
end_comment
begin_decl_stmt
DECL|variable|button
name|QPushButton
modifier|*
name|button
init|=
name|parentWidget
operator|->
name|findChild
argument_list|<
name|QPushButton
operator|*
argument_list|>
argument_list|(
literal|"button1"
argument_list|,
name|Qt
operator|::
name|FindDirectChildrenOnly
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [41]
end_comment
begin_comment
comment|//! [42]
end_comment
begin_decl_stmt
DECL|variable|list
name|QListWidget
modifier|*
name|list
init|=
name|parentWidget
operator|->
name|findChild
argument_list|<
name|QListWidget
operator|*
argument_list|>
argument_list|(
name|QString
argument_list|()
argument_list|,
name|Qt
operator|::
name|FindDirectChildrenOnly
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [42]
end_comment
begin_comment
comment|//! [43]
end_comment
begin_decl_stmt
DECL|variable|childButtons
name|QList
argument_list|<
name|QPushButton
modifier|*
argument_list|>
name|childButtons
init|=
name|parentWidget
operator|.
name|findChildren
argument_list|<
name|QPushButton
operator|*
argument_list|>
argument_list|(
name|QString
argument_list|()
argument_list|,
name|Qt
operator|::
name|FindDirectChildrenOnly
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [43]
end_comment
begin_comment
comment|//! [44]
end_comment
begin_decl_stmt
DECL|variable|label
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|lineEdit
name|QLineEdit
modifier|*
name|lineEdit
init|=
operator|new
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QObject
operator|::
name|connect
argument_list|(
name|lineEdit
argument_list|,
operator|&
name|QLineEdit
operator|::
name|textChanged
argument_list|,
name|label
argument_list|,
operator|&
name|QLabel
operator|::
name|setText
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [44]
end_comment
begin_comment
comment|//! [45]
end_comment
begin_function_decl
name|void
name|someFunction
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|button
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QObject
operator|::
name|connect
argument_list|(
name|button
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|someFunction
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [45]
end_comment
begin_comment
comment|//! [46]
end_comment
begin_decl_stmt
DECL|variable|page
name|QByteArray
name|page
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|socket
name|QTcpSocket
modifier|*
name|socket
init|=
operator|new
name|QTcpSocket
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|socket
operator|->
name|connectToHost
argument_list|(
literal|"qt-project.org"
argument_list|,
literal|80
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QObject
operator|::
name|connect
argument_list|(
name|socket
argument_list|,
operator|&
name|QTcpSocket
operator|::
name|connected
argument_list|,
capture|[
modifier|=
capture|]
parameter_list|()
block|{
name|socket
operator|->
name|write
argument_list|(
literal|"GET "
operator|+
name|page
operator|+
literal|"\r\n"
argument_list|)
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [46]
end_comment
begin_comment
comment|//! [47]
end_comment
begin_expr_stmt
name|disconnect
argument_list|(
name|myObject
argument_list|,
operator|&
name|MyObject
operator|::
name|mySignal
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [47]
end_comment
begin_comment
comment|//! [48]
end_comment
begin_expr_stmt
name|QObject
operator|::
name|disconnect
argument_list|(
name|lineEdit
argument_list|,
operator|&
name|QLineEdit
operator|::
name|textChanged
argument_list|,
name|label
argument_list|,
operator|&
name|QLabel
operator|::
name|setText
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [48]
end_comment
begin_comment
comment|//! [49]
end_comment
begin_decl_stmt
DECL|variable|valueChangedSignal
specifier|static
specifier|const
name|QMetaMethod
name|valueChangedSignal
init|=
name|QMetaMethod
operator|::
name|fromSignal
argument_list|(
operator|&
name|MyObject
operator|::
name|valueChanged
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|isSignalConnected
argument_list|(
name|valueChangedSignal
argument_list|)
condition|)
block|{
name|QByteArray
name|data
decl_stmt|;
name|data
operator|=
name|get_the_value
argument_list|()
expr_stmt|;
comment|// expensive operation
emit|emit
name|valueChanged
argument_list|(
name|data
argument_list|)
emit|;
block|}
end_if
begin_comment
comment|//! [49]
end_comment
begin_comment
comment|//! [50]
end_comment
begin_function_decl
name|void
name|someFunction
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|button
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QObject
operator|::
name|connect
argument_list|(
name|button
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
name|someFunction
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [50]
end_comment
begin_comment
comment|//! [51]
end_comment
begin_decl_stmt
DECL|variable|page
name|QByteArray
name|page
init|=
operator|...
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|socket
name|QTcpSocket
modifier|*
name|socket
init|=
operator|new
name|QTcpSocket
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|socket
operator|->
name|connectToHost
argument_list|(
literal|"qt-project.org"
argument_list|,
literal|80
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QObject
operator|::
name|connect
argument_list|(
name|socket
argument_list|,
operator|&
name|QTcpSocket
operator|::
name|connected
argument_list|,
name|this
argument_list|,
capture|[
modifier|=
capture|]
parameter_list|()
block|{
name|socket
operator|->
name|write
argument_list|(
literal|"GET "
operator|+
name|page
operator|+
literal|"\r\n"
argument_list|)
expr_stmt|;
block|}
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [51]
end_comment
begin_comment
comment|//! [52]
end_comment
begin_class
DECL|class|MyClass
class|class
name|MyClass
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
name|MyClass
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|~
name|MyClass
parameter_list|()
destructor_decl|;
DECL|function|event
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|ev
parameter_list|)
block|{
if|if
condition|(
name|ev
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|PolishRequest
condition|)
block|{
comment|// overwrite handling of PolishRequest if any
name|doThings
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
elseif|else
if|if
condition|(
name|ev
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Show
condition|)
block|{
comment|// complement handling of Show if any
name|doThings2
argument_list|()
expr_stmt|;
name|QWidget
operator|::
name|event
argument_list|(
name|ev
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
comment|// Make sure the rest of events are handled
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|ev
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_comment
comment|//! [52]
end_comment
begin_comment
comment|//! [meta data]
end_comment
begin_comment
comment|//: This is a comment for the translator.
end_comment
begin_comment
comment|//= qtn_foo_bar
end_comment
begin_comment
comment|//~ loc-layout_id foo_dialog
end_comment
begin_comment
comment|//~ loc-blank False
end_comment
begin_comment
comment|//~ magic-stuff This might mean something magic.
end_comment
begin_decl_stmt
DECL|variable|text
name|QString
name|text
init|=
name|MyMagicClass
operator|::
name|tr
argument_list|(
literal|"Sim sala bim."
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [meta data]
end_comment
begin_comment
comment|//! [explicit tr context]
end_comment
begin_decl_stmt
DECL|variable|text
name|QString
name|text
init|=
name|QScrollBar
operator|::
name|tr
argument_list|(
literal|"Page up"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [explicit tr context]
end_comment
end_unit
