begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<private/qwinoverlappedionotifier_p.h>
end_include
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|PIPE_REJECT_REMOTE_CLIENTS
end_ifndef
begin_define
DECL|macro|PIPE_REJECT_REMOTE_CLIENTS
define|#
directive|define
name|PIPE_REJECT_REMOTE_CLIENTS
value|0x08
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QWinOverlappedIoNotifier
class|class
name|tst_QWinOverlappedIoNotifier
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|readFile_data
parameter_list|()
function_decl|;
name|void
name|readFile
parameter_list|()
function_decl|;
name|void
name|waitForNotified_data
parameter_list|()
function_decl|;
name|void
name|waitForNotified
parameter_list|()
function_decl|;
name|void
name|waitForAnyNotified
parameter_list|()
function_decl|;
name|void
name|brokenPipe
parameter_list|()
function_decl|;
name|void
name|multipleOperations
parameter_list|()
function_decl|;
private|private:
DECL|member|sourceFileInfo
name|QFileInfo
name|sourceFileInfo
decl_stmt|;
DECL|member|notifiedBytesRead
name|DWORD
name|notifiedBytesRead
decl_stmt|;
DECL|member|notifiedErrorCode
name|DWORD
name|notifiedErrorCode
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|NotifierSink
class|class
name|NotifierSink
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|NotifierSink
name|NotifierSink
parameter_list|(
name|QWinOverlappedIoNotifier
modifier|*
name|notifier
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|notifier
argument_list|)
member_init_list|,
name|threshold
argument_list|(
literal|1
argument_list|)
block|{
name|connect
argument_list|(
name|notifier
argument_list|,
operator|&
name|QWinOverlappedIoNotifier
operator|::
name|notified
argument_list|,
name|this
argument_list|,
operator|&
name|NotifierSink
operator|::
name|notified
argument_list|)
expr_stmt|;
block|}
protected|protected
name|slots
protected|:
DECL|function|notified
name|void
name|notified
parameter_list|(
name|DWORD
name|bytesRead
parameter_list|,
name|DWORD
name|errorCode
parameter_list|,
name|OVERLAPPED
modifier|*
name|overlapped
parameter_list|)
block|{
name|IOResult
name|ioResult
decl_stmt|;
name|ioResult
operator|.
name|bytes
operator|=
name|bytesRead
expr_stmt|;
name|ioResult
operator|.
name|errorCode
operator|=
name|errorCode
expr_stmt|;
name|ioResult
operator|.
name|overlapped
operator|=
name|overlapped
expr_stmt|;
name|notifications
operator|.
name|append
argument_list|(
name|ioResult
argument_list|)
expr_stmt|;
if|if
condition|(
name|notifications
operator|.
name|count
argument_list|()
operator|>=
name|threshold
condition|)
emit|emit
name|notificationReceived
argument_list|()
emit|;
block|}
signals|signals:
name|void
name|notificationReceived
parameter_list|()
function_decl|;
public|public:
DECL|member|threshold
name|int
name|threshold
decl_stmt|;
DECL|struct|IOResult
struct|struct
name|IOResult
block|{
DECL|function|IOResult
name|IOResult
parameter_list|()
member_init_list|:
name|bytes
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|errorCode
argument_list|(
name|ERROR_SUCCESS
argument_list|)
member_init_list|,
name|overlapped
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|bytes
name|DWORD
name|bytes
decl_stmt|;
DECL|member|errorCode
name|DWORD
name|errorCode
decl_stmt|;
DECL|member|overlapped
name|OVERLAPPED
modifier|*
name|overlapped
decl_stmt|;
block|}
struct|;
DECL|member|notifications
name|QList
argument_list|<
name|IOResult
argument_list|>
name|notifications
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QWinOverlappedIoNotifier
operator|::
name|initTestCase
parameter_list|()
block|{
name|sourceFileInfo
operator|.
name|setFile
argument_list|(
name|QFINDTESTDATA
argument_list|(
literal|"tst_qwinoverlappedionotifier.cpp"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|sourceFileInfo
operator|.
name|exists
argument_list|()
argument_list|,
literal|"File tst_qwinoverlappedionotifier.cpp not found."
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readFile_data
name|void
name|tst_QWinOverlappedIoNotifier
operator|::
name|readFile_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"fileName"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"readBufferSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|DWORD
argument_list|>
argument_list|(
literal|"expectedBytesRead"
argument_list|)
expr_stmt|;
name|QString
name|sourceFileName
init|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|sourceFileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|sourceFileSize
init|=
name|sourceFileInfo
operator|.
name|size
argument_list|()
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"read file, less than available"
argument_list|)
operator|<<
name|sourceFileName
operator|<<
name|sourceFileSize
operator|/
literal|2
operator|<<
name|DWORD
argument_list|(
name|sourceFileSize
operator|/
literal|2
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"read file, more than available"
argument_list|)
operator|<<
name|sourceFileName
operator|<<
name|sourceFileSize
operator|*
literal|2
operator|<<
name|DWORD
argument_list|(
name|sourceFileSize
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readFile
name|void
name|tst_QWinOverlappedIoNotifier
operator|::
name|readFile
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|readBufferSize
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|DWORD
argument_list|,
name|expectedBytesRead
argument_list|)
expr_stmt|;
name|QWinOverlappedIoNotifier
name|notifier
decl_stmt|;
name|NotifierSink
name|sink
argument_list|(
operator|&
name|notifier
argument_list|)
decl_stmt|;
name|connect
argument_list|(
operator|&
name|sink
argument_list|,
operator|&
name|NotifierSink
operator|::
name|notificationReceived
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|exitLoop
argument_list|)
expr_stmt|;
name|HANDLE
name|hFile
init|=
name|CreateFile
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|fileName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|GENERIC_READ
argument_list|,
name|FILE_SHARE_READ
argument_list|,
name|NULL
argument_list|,
name|OPEN_EXISTING
argument_list|,
name|FILE_FLAG_OVERLAPPED
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|notifier
operator|.
name|setHandle
argument_list|(
name|hFile
argument_list|)
expr_stmt|;
name|notifier
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|OVERLAPPED
name|overlapped
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|overlapped
argument_list|,
sizeof|sizeof
argument_list|(
name|OVERLAPPED
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|buffer
argument_list|(
name|readBufferSize
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|BOOL
name|readSuccess
init|=
name|ReadFile
argument_list|(
name|hFile
argument_list|,
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|overlapped
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|readSuccess
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_IO_PENDING
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|hFile
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|bytes
argument_list|,
name|expectedBytesRead
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|errorCode
argument_list|,
name|DWORD
argument_list|(
name|ERROR_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|overlapped
argument_list|,
operator|&
name|overlapped
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForNotified_data
name|void
name|tst_QWinOverlappedIoNotifier
operator|::
name|waitForNotified_data
parameter_list|()
block|{
name|readFile_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForNotified
name|void
name|tst_QWinOverlappedIoNotifier
operator|::
name|waitForNotified
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|readBufferSize
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|DWORD
argument_list|,
name|expectedBytesRead
argument_list|)
expr_stmt|;
name|QWinOverlappedIoNotifier
name|notifier
decl_stmt|;
name|NotifierSink
name|sink
argument_list|(
operator|&
name|notifier
argument_list|)
decl_stmt|;
name|HANDLE
name|hFile
init|=
name|CreateFile
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|fileName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|GENERIC_READ
argument_list|,
name|FILE_SHARE_READ
argument_list|,
name|NULL
argument_list|,
name|OPEN_EXISTING
argument_list|,
name|FILE_FLAG_OVERLAPPED
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|notifier
operator|.
name|setHandle
argument_list|(
name|hFile
argument_list|)
expr_stmt|;
name|notifier
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|notifier
operator|.
name|waitForNotified
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|OVERLAPPED
name|overlapped
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|overlapped
argument_list|,
sizeof|sizeof
argument_list|(
name|OVERLAPPED
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|buffer
argument_list|(
name|readBufferSize
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|BOOL
name|readSuccess
init|=
name|ReadFile
argument_list|(
name|hFile
argument_list|,
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|overlapped
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|readSuccess
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_IO_PENDING
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|notifier
operator|.
name|waitForNotified
argument_list|(
literal|3000
argument_list|,
operator|&
name|overlapped
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|hFile
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|bytes
argument_list|,
name|expectedBytesRead
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|errorCode
argument_list|,
name|DWORD
argument_list|(
name|ERROR_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|overlapped
argument_list|,
operator|&
name|overlapped
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|notifier
operator|.
name|waitForNotified
argument_list|(
literal|100
argument_list|,
operator|&
name|overlapped
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForAnyNotified
name|void
name|tst_QWinOverlappedIoNotifier
operator|::
name|waitForAnyNotified
parameter_list|()
block|{
specifier|const
name|QString
name|fileName
init|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|sourceFileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|int
name|readBufferSize
init|=
name|sourceFileInfo
operator|.
name|size
argument_list|()
decl_stmt|;
name|QWinOverlappedIoNotifier
name|notifier
decl_stmt|;
name|HANDLE
name|hFile
init|=
name|CreateFile
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|fileName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|GENERIC_READ
argument_list|,
name|FILE_SHARE_READ
argument_list|,
name|NULL
argument_list|,
name|OPEN_EXISTING
argument_list|,
name|FILE_FLAG_OVERLAPPED
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|notifier
operator|.
name|setHandle
argument_list|(
name|hFile
argument_list|)
expr_stmt|;
name|notifier
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|notifier
operator|.
name|waitForAnyNotified
argument_list|(
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|OVERLAPPED
name|overlapped1
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|overlapped1
argument_list|,
sizeof|sizeof
argument_list|(
name|OVERLAPPED
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|buffer1
argument_list|(
name|readBufferSize
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|BOOL
name|readSuccess
init|=
name|ReadFile
argument_list|(
name|hFile
argument_list|,
name|buffer1
operator|.
name|data
argument_list|()
argument_list|,
name|buffer1
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|overlapped1
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|readSuccess
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_IO_PENDING
argument_list|)
expr_stmt|;
name|OVERLAPPED
name|overlapped2
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|overlapped2
argument_list|,
sizeof|sizeof
argument_list|(
name|OVERLAPPED
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|buffer2
argument_list|(
name|readBufferSize
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|readSuccess
operator|=
name|ReadFile
argument_list|(
name|hFile
argument_list|,
name|buffer2
operator|.
name|data
argument_list|()
argument_list|,
name|buffer2
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|overlapped2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|readSuccess
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_IO_PENDING
argument_list|)
expr_stmt|;
name|QSet
argument_list|<
name|OVERLAPPED
modifier|*
argument_list|>
name|overlappedObjects
decl_stmt|;
name|overlappedObjects
operator|<<
operator|&
name|overlapped1
operator|<<
operator|&
name|overlapped2
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<=
literal|2
condition|;
operator|++
name|i
control|)
block|{
name|OVERLAPPED
modifier|*
name|notifiedOverlapped
init|=
name|notifier
operator|.
name|waitForAnyNotified
argument_list|(
literal|3000
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|overlappedObjects
operator|.
name|contains
argument_list|(
name|notifiedOverlapped
argument_list|)
argument_list|)
expr_stmt|;
name|overlappedObjects
operator|.
name|remove
argument_list|(
name|notifiedOverlapped
argument_list|)
expr_stmt|;
block|}
name|CloseHandle
argument_list|(
name|hFile
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|overlappedObjects
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|notifier
operator|.
name|waitForAnyNotified
argument_list|(
literal|100
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|brokenPipe
name|void
name|tst_QWinOverlappedIoNotifier
operator|::
name|brokenPipe
parameter_list|()
block|{
name|QWinOverlappedIoNotifier
name|notifier
decl_stmt|;
name|NotifierSink
name|sink
argument_list|(
operator|&
name|notifier
argument_list|)
decl_stmt|;
name|connect
argument_list|(
operator|&
name|sink
argument_list|,
operator|&
name|NotifierSink
operator|::
name|notificationReceived
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|exitLoop
argument_list|)
expr_stmt|;
name|wchar_t
name|pipeName
index|[]
init|=
literal|L"\\\\.\\pipe\\tst_QWinOverlappedIoNotifier_brokenPipe"
decl_stmt|;
name|HANDLE
name|hPipe
init|=
name|CreateNamedPipe
argument_list|(
name|pipeName
argument_list|,
name|PIPE_ACCESS_DUPLEX
argument_list|,
name|PIPE_TYPE_BYTE
operator||
name|PIPE_NOWAIT
operator||
name|PIPE_REJECT_REMOTE_CLIENTS
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|hPipe
operator|!=
name|INVALID_HANDLE_VALUE
argument_list|)
expr_stmt|;
name|HANDLE
name|hReadEnd
init|=
name|CreateFile
argument_list|(
name|pipeName
argument_list|,
name|GENERIC_READ
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|OPEN_EXISTING
argument_list|,
name|FILE_FLAG_OVERLAPPED
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|hReadEnd
operator|!=
name|INVALID_HANDLE_VALUE
argument_list|)
expr_stmt|;
name|notifier
operator|.
name|setHandle
argument_list|(
name|hReadEnd
argument_list|)
expr_stmt|;
name|notifier
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|OVERLAPPED
name|overlapped
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|overlapped
argument_list|,
sizeof|sizeof
argument_list|(
name|OVERLAPPED
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|buffer
argument_list|(
literal|1024
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|BOOL
name|readSuccess
init|=
name|ReadFile
argument_list|(
name|hReadEnd
argument_list|,
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|overlapped
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|readSuccess
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_IO_PENDING
argument_list|)
expr_stmt|;
comment|// close the write end of the pipe
name|CloseHandle
argument_list|(
name|hPipe
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|hReadEnd
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|bytes
argument_list|,
name|DWORD
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|errorCode
argument_list|,
name|DWORD
argument_list|(
name|ERROR_BROKEN_PIPE
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|last
argument_list|()
operator|.
name|overlapped
argument_list|,
operator|&
name|overlapped
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|multipleOperations
name|void
name|tst_QWinOverlappedIoNotifier
operator|::
name|multipleOperations
parameter_list|()
block|{
name|QWinOverlappedIoNotifier
name|clientNotifier
decl_stmt|;
name|NotifierSink
name|sink
argument_list|(
operator|&
name|clientNotifier
argument_list|)
decl_stmt|;
name|sink
operator|.
name|threshold
operator|=
literal|2
expr_stmt|;
name|connect
argument_list|(
operator|&
name|sink
argument_list|,
operator|&
name|NotifierSink
operator|::
name|notificationReceived
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|exitLoop
argument_list|)
expr_stmt|;
name|wchar_t
name|pipeName
index|[]
init|=
literal|L"\\\\.\\pipe\\tst_QWinOverlappedIoNotifier_multipleOperations"
decl_stmt|;
name|HANDLE
name|hServer
init|=
name|CreateNamedPipe
argument_list|(
name|pipeName
argument_list|,
name|PIPE_ACCESS_DUPLEX
argument_list|,
name|PIPE_TYPE_BYTE
operator||
name|PIPE_NOWAIT
operator||
name|PIPE_REJECT_REMOTE_CLIENTS
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|hServer
operator|!=
name|INVALID_HANDLE_VALUE
argument_list|)
expr_stmt|;
name|HANDLE
name|hClient
init|=
name|CreateFile
argument_list|(
name|pipeName
argument_list|,
name|GENERIC_READ
operator||
name|GENERIC_WRITE
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|OPEN_EXISTING
argument_list|,
name|FILE_FLAG_OVERLAPPED
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|hClient
operator|!=
name|INVALID_HANDLE_VALUE
argument_list|)
expr_stmt|;
name|clientNotifier
operator|.
name|setHandle
argument_list|(
name|hClient
argument_list|)
expr_stmt|;
name|clientNotifier
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// start async read on client
name|QByteArray
name|clientReadBuffer
argument_list|(
literal|377
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|OVERLAPPED
name|clientReadOverlapped
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|clientReadOverlapped
argument_list|,
sizeof|sizeof
argument_list|(
name|clientReadOverlapped
argument_list|)
argument_list|)
expr_stmt|;
name|BOOL
name|readSuccess
init|=
name|ReadFile
argument_list|(
name|hClient
argument_list|,
name|clientReadBuffer
operator|.
name|data
argument_list|()
argument_list|,
name|clientReadBuffer
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|clientReadOverlapped
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|readSuccess
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_IO_PENDING
argument_list|)
expr_stmt|;
comment|// start async write client -> server
name|QByteArray
name|clientDataToWrite
argument_list|(
literal|233
argument_list|,
literal|'B'
argument_list|)
decl_stmt|;
name|OVERLAPPED
name|clientWriteOverlapped
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|clientWriteOverlapped
argument_list|,
sizeof|sizeof
argument_list|(
name|clientWriteOverlapped
argument_list|)
argument_list|)
expr_stmt|;
name|BOOL
name|writeSuccess
init|=
name|WriteFile
argument_list|(
name|hClient
argument_list|,
name|clientDataToWrite
operator|.
name|data
argument_list|()
argument_list|,
name|clientDataToWrite
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|clientWriteOverlapped
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|writeSuccess
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_IO_PENDING
argument_list|)
expr_stmt|;
comment|// start async write server -> client
name|QByteArray
name|serverDataToWrite
argument_list|(
literal|144
argument_list|,
literal|'A'
argument_list|)
decl_stmt|;
name|OVERLAPPED
name|serverOverlapped
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|serverOverlapped
argument_list|,
sizeof|sizeof
argument_list|(
name|serverOverlapped
argument_list|)
argument_list|)
expr_stmt|;
name|writeSuccess
operator|=
name|WriteFile
argument_list|(
name|hServer
argument_list|,
name|serverDataToWrite
operator|.
name|data
argument_list|()
argument_list|,
name|serverDataToWrite
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|serverOverlapped
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|writeSuccess
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_IO_PENDING
argument_list|)
expr_stmt|;
comment|// read synchronously on server to complete the client -> server write
name|QByteArray
name|serverReadBuffer
argument_list|(
literal|610
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
name|DWORD
name|dwBytesRead
init|=
literal|0
decl_stmt|;
name|readSuccess
operator|=
name|ReadFile
argument_list|(
name|hServer
argument_list|,
name|serverReadBuffer
operator|.
name|data
argument_list|()
argument_list|,
name|serverReadBuffer
operator|.
name|size
argument_list|()
argument_list|,
operator|&
name|dwBytesRead
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|readSuccess
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|int
argument_list|(
name|dwBytesRead
argument_list|)
argument_list|,
name|clientDataToWrite
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|serverReadBuffer
operator|.
name|resize
argument_list|(
name|dwBytesRead
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|serverReadBuffer
argument_list|,
name|clientDataToWrite
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|sink
operator|.
name|notifications
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|NotifierSink
operator|::
name|IOResult
modifier|&
name|r
decl|,
name|sink
operator|.
name|notifications
control|)
block|{
name|QCOMPARE
argument_list|(
name|r
operator|.
name|errorCode
argument_list|,
name|DWORD
argument_list|(
name|ERROR_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|.
name|bytes
operator|==
name|DWORD
argument_list|(
name|serverDataToWrite
operator|.
name|count
argument_list|()
argument_list|)
condition|)
name|QCOMPARE
argument_list|(
name|r
operator|.
name|overlapped
argument_list|,
operator|&
name|clientReadOverlapped
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|.
name|bytes
operator|==
name|DWORD
argument_list|(
name|clientDataToWrite
operator|.
name|count
argument_list|()
argument_list|)
condition|)
name|QCOMPARE
argument_list|(
name|r
operator|.
name|overlapped
argument_list|,
operator|&
name|clientWriteOverlapped
argument_list|)
expr_stmt|;
else|else
name|QVERIFY2
argument_list|(
literal|false
argument_list|,
literal|"Unexpected number of bytes received."
argument_list|)
expr_stmt|;
block|}
name|CloseHandle
argument_list|(
name|hClient
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|hServer
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QWinOverlappedIoNotifier
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwinoverlappedionotifier.moc"
end_include
end_unit
