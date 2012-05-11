begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qsystemtrayicon.h>
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_class
DECL|class|tst_QSystemTrayIcon
class|class
name|tst_QSystemTrayIcon
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QSystemTrayIcon
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QSystemTrayIcon
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|showHide
parameter_list|()
function_decl|;
name|void
name|showMessage
parameter_list|()
function_decl|;
name|void
name|supportsMessages
parameter_list|()
function_decl|;
name|void
name|lastWindowClosed
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QSystemTrayIcon
name|tst_QSystemTrayIcon
operator|::
name|tst_QSystemTrayIcon
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QSystemTrayIcon
name|tst_QSystemTrayIcon
operator|::
name|~
name|tst_QSystemTrayIcon
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|showHide
name|void
name|tst_QSystemTrayIcon
operator|::
name|showHide
parameter_list|()
block|{
name|QSystemTrayIcon
name|icon
decl_stmt|;
name|icon
operator|.
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|"icons/icon.png"
argument_list|)
argument_list|)
expr_stmt|;
name|icon
operator|.
name|show
argument_list|()
expr_stmt|;
name|icon
operator|.
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|"icons/icon.png"
argument_list|)
argument_list|)
expr_stmt|;
name|icon
operator|.
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|showMessage
name|void
name|tst_QSystemTrayIcon
operator|::
name|showMessage
parameter_list|()
block|{
name|QSystemTrayIcon
name|icon
decl_stmt|;
name|icon
operator|.
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|"icons/icon.png"
argument_list|)
argument_list|)
expr_stmt|;
name|icon
operator|.
name|showMessage
argument_list|(
literal|"Title"
argument_list|,
literal|"Messagecontents"
argument_list|)
expr_stmt|;
name|icon
operator|.
name|showMessage
argument_list|(
literal|"Title"
argument_list|,
literal|"Messagecontents"
argument_list|,
name|QSystemTrayIcon
operator|::
name|NoIcon
argument_list|)
expr_stmt|;
name|icon
operator|.
name|showMessage
argument_list|(
literal|"Title"
argument_list|,
literal|"Messagecontents"
argument_list|,
name|QSystemTrayIcon
operator|::
name|Warning
argument_list|)
expr_stmt|;
name|icon
operator|.
name|showMessage
argument_list|(
literal|"Title"
argument_list|,
literal|"Messagecontents"
argument_list|,
name|QSystemTrayIcon
operator|::
name|Critical
argument_list|)
expr_stmt|;
name|icon
operator|.
name|show
argument_list|()
expr_stmt|;
name|icon
operator|.
name|showMessage
argument_list|(
literal|"Title"
argument_list|,
literal|"Messagecontents"
argument_list|)
expr_stmt|;
name|icon
operator|.
name|showMessage
argument_list|(
literal|"Title"
argument_list|,
literal|"Messagecontents"
argument_list|,
name|QSystemTrayIcon
operator|::
name|NoIcon
argument_list|)
expr_stmt|;
name|icon
operator|.
name|showMessage
argument_list|(
literal|"Title"
argument_list|,
literal|"Messagecontents"
argument_list|,
name|QSystemTrayIcon
operator|::
name|Warning
argument_list|)
expr_stmt|;
name|icon
operator|.
name|showMessage
argument_list|(
literal|"Title"
argument_list|,
literal|"Messagecontents"
argument_list|,
name|QSystemTrayIcon
operator|::
name|Critical
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QSystemTrayIcon
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QSystemTrayIcon
name|icon
decl_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|icon
operator|.
name|toolTip
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|icon
operator|.
name|setToolTip
argument_list|(
literal|"testToolTip"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
literal|"testToolTip"
operator|==
name|icon
operator|.
name|toolTip
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|icon
operator|.
name|icon
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|icon
operator|.
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|"icons/icon.png"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|false
argument_list|,
name|icon
operator|.
name|icon
argument_list|()
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QMenu
name|menu
decl_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|icon
operator|.
name|contextMenu
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
name|icon
operator|.
name|setContextMenu
argument_list|(
operator|&
name|menu
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|false
argument_list|,
name|icon
operator|.
name|contextMenu
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsMessages
name|void
name|tst_QSystemTrayIcon
operator|::
name|supportsMessages
parameter_list|()
block|{
comment|// ### fixme: Check platforms.
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|QCOMPARE
argument_list|(
name|QSystemTrayIcon
operator|::
name|supportsMessages
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
else|#
directive|else
specifier|const
name|QString
name|platform
init|=
name|QGuiApplication
operator|::
name|platformName
argument_list|()
decl_stmt|;
if|if
condition|(
name|platform
operator|.
name|compare
argument_list|(
name|QStringLiteral
argument_list|(
literal|"xcb"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|&&
name|platform
operator|.
name|compare
argument_list|(
name|QStringLiteral
argument_list|(
literal|"windows"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|&&
name|platform
operator|.
name|compare
argument_list|(
name|QStringLiteral
argument_list|(
literal|"cocoa"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
block|{
name|QEXPECT_FAIL
argument_list|(
literal|""
argument_list|,
literal|"QTBUG-20978 QSystemTrayIcon is unimplemented for this platform"
argument_list|,
name|Abort
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|QSystemTrayIcon
operator|::
name|supportsMessages
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|lastWindowClosed
name|void
name|tst_QSystemTrayIcon
operator|::
name|lastWindowClosed
parameter_list|()
block|{
name|QSignalSpy
name|spy
argument_list|(
name|qApp
argument_list|,
name|SIGNAL
argument_list|(
name|lastWindowClosed
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QWidget
name|window
decl_stmt|;
name|QSystemTrayIcon
name|icon
decl_stmt|;
name|icon
operator|.
name|setIcon
argument_list|(
name|QIcon
argument_list|(
literal|"whatever.png"
argument_list|)
argument_list|)
expr_stmt|;
name|icon
operator|.
name|show
argument_list|()
expr_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|2500
argument_list|,
operator|&
name|window
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|20000
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// in case the test fails
name|qApp
operator|->
name|exec
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|spy
operator|.
name|count
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSystemTrayIcon
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsystemtrayicon.moc"
end_include
end_unit
