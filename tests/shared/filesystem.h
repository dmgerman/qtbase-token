begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_TESTS_SHARED_FILESYSTEM_H_INCLUDED
end_ifndef
begin_define
DECL|macro|QT_TESTS_SHARED_FILESYSTEM_H_INCLUDED
define|#
directive|define
name|QT_TESTS_SHARED_FILESYSTEM_H_INCLUDED
end_define
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QTemporaryDir>
end_include
begin_include
include|#
directive|include
file|<QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_include
include|#
directive|include
file|<winioctl.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|IO_REPARSE_TAG_MOUNT_POINT
end_ifndef
begin_define
DECL|macro|IO_REPARSE_TAG_MOUNT_POINT
define|#
directive|define
name|IO_REPARSE_TAG_MOUNT_POINT
value|(0xA0000003L)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|REPARSE_MOUNTPOINT_HEADER_SIZE
define|#
directive|define
name|REPARSE_MOUNTPOINT_HEADER_SIZE
value|8
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|FSCTL_SET_REPARSE_POINT
end_ifndef
begin_define
DECL|macro|FSCTL_SET_REPARSE_POINT
define|#
directive|define
name|FSCTL_SET_REPARSE_POINT
value|CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 41, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTemporaryDir-based helper class for creating file-system hierarchies and cleaning up.
end_comment
begin_decl_stmt
name|class
name|FileSystem
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|FileSystem
argument_list|)
name|public
label|:
name|FileSystem
argument_list|()
operator|:
name|m_temporaryDir
argument_list|(
argument|FileSystem::tempFilePattern()
argument_list|)
block|{}
name|QString
name|path
argument_list|()
specifier|const
block|{
return|return
name|m_temporaryDir
operator|.
name|path
argument_list|()
return|;
block|}
name|QString
name|absoluteFilePath
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
block|{
return|return
name|path
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|fileName
return|;
block|}
name|bool
name|createDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|relativeDirName
parameter_list|)
block|{
if|if
condition|(
name|m_temporaryDir
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QDir
name|dir
argument_list|(
name|m_temporaryDir
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|dir
operator|.
name|mkpath
argument_list|(
name|relativeDirName
argument_list|)
return|;
block|}
return|return
name|false
return|;
block|}
name|bool
name|createFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|relativeFileName
parameter_list|)
block|{
name|QScopedPointer
operator|<
name|QFile
operator|>
name|file
argument_list|(
name|openFileForWrite
argument_list|(
name|relativeFileName
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|!
name|file
operator|.
name|isNull
argument_list|()
return|;
block|}
name|qint64
name|createFileWithContent
parameter_list|(
specifier|const
name|QString
modifier|&
name|relativeFileName
parameter_list|)
block|{
name|QScopedPointer
operator|<
name|QFile
operator|>
name|file
argument_list|(
name|openFileForWrite
argument_list|(
name|relativeFileName
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|file
operator|.
name|isNull
argument_list|()
condition|?
name|qint64
argument_list|(
operator|-
literal|1
argument_list|)
else|:
name|file
operator|->
name|write
argument_list|(
name|relativeFileName
operator|.
name|toUtf8
argument_list|()
argument_list|)
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
specifier|static
name|void
name|createNtfsJunction
parameter_list|(
name|QString
name|target
parameter_list|,
name|QString
name|linkName
parameter_list|)
block|{
typedef|typedef
struct|struct
block|{
name|DWORD
name|ReparseTag
decl_stmt|;
name|DWORD
name|ReparseDataLength
decl_stmt|;
name|WORD
name|Reserved
decl_stmt|;
name|WORD
name|ReparseTargetLength
decl_stmt|;
name|WORD
name|ReparseTargetMaximumLength
decl_stmt|;
name|WORD
name|Reserved1
decl_stmt|;
name|WCHAR
name|ReparseTarget
index|[
literal|1
index|]
decl_stmt|;
block|}
name|REPARSE_MOUNTPOINT_DATA_BUFFER
operator|,
typedef|*
name|PREPARSE_MOUNTPOINT_DATA_BUFFER
typedef|;
name|char
name|reparseBuffer
index|[
name|MAX_PATH
operator|*
literal|3
index|]
decl_stmt|;
name|HANDLE
name|hFile
decl_stmt|;
name|DWORD
name|returnedLength
decl_stmt|;
name|wchar_t
name|fileSystem
index|[
name|MAX_PATH
index|]
init|=
literal|L""
decl_stmt|;
name|PREPARSE_MOUNTPOINT_DATA_BUFFER
name|reparseInfo
init|=
operator|(
name|PREPARSE_MOUNTPOINT_DATA_BUFFER
operator|)
name|reparseBuffer
decl_stmt|;
name|QFileInfo
name|junctionInfo
argument_list|(
name|linkName
argument_list|)
decl_stmt|;
name|linkName
operator|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|junctionInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
name|GetVolumeInformationW
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|linkName
operator|.
name|left
argument_list|(
literal|3
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|fileSystem
argument_list|,
sizeof|sizeof
argument_list|(
name|fileSystem
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|WCHAR
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QString
argument_list|()
operator|.
name|fromWCharArray
argument_list|(
name|fileSystem
argument_list|)
operator|!=
literal|"NTFS"
condition|)
name|QSKIP
argument_list|(
literal|"This seems not to be an NTFS volume. Junctions are not allowed."
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|target
operator|.
name|startsWith
argument_list|(
literal|"\\??\\"
argument_list|)
operator|&&
operator|!
name|target
operator|.
name|startsWith
argument_list|(
literal|"\\\\?\\"
argument_list|)
condition|)
block|{
name|QFileInfo
name|targetInfo
argument_list|(
name|target
argument_list|)
decl_stmt|;
name|target
operator|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|targetInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
name|target
operator|.
name|prepend
argument_list|(
literal|"\\??\\"
argument_list|)
expr_stmt|;
if|if
condition|(
name|target
operator|.
name|endsWith
argument_list|(
literal|'\\'
argument_list|)
operator|&&
name|target
operator|.
name|at
argument_list|(
name|target
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
operator|!=
literal|':'
condition|)
name|target
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|QDir
argument_list|()
operator|.
name|mkdir
argument_list|(
name|linkName
argument_list|)
expr_stmt|;
name|hFile
operator|=
name|CreateFileW
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|linkName
operator|.
name|utf16
argument_list|()
argument_list|,
name|GENERIC_WRITE
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|OPEN_EXISTING
argument_list|,
name|FILE_FLAG_OPEN_REPARSE_POINT
operator||
name|FILE_FLAG_BACKUP_SEMANTICS
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hFile
operator|!=
name|INVALID_HANDLE_VALUE
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|reparseInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|reparseInfo
argument_list|)
argument_list|)
expr_stmt|;
name|reparseInfo
operator|->
name|ReparseTag
operator|=
name|IO_REPARSE_TAG_MOUNT_POINT
expr_stmt|;
name|reparseInfo
operator|->
name|ReparseTargetLength
operator|=
name|DWORD
argument_list|(
name|target
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
expr_stmt|;
name|reparseInfo
operator|->
name|ReparseTargetMaximumLength
operator|=
name|reparseInfo
operator|->
name|ReparseTargetLength
operator|+
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
expr_stmt|;
name|target
operator|.
name|toWCharArray
argument_list|(
name|reparseInfo
operator|->
name|ReparseTarget
argument_list|)
expr_stmt|;
name|reparseInfo
operator|->
name|ReparseDataLength
operator|=
name|reparseInfo
operator|->
name|ReparseTargetLength
operator|+
literal|12
expr_stmt|;
name|bool
name|ioc
init|=
name|DeviceIoControl
argument_list|(
name|hFile
argument_list|,
name|FSCTL_SET_REPARSE_POINT
argument_list|,
name|reparseInfo
argument_list|,
name|reparseInfo
operator|->
name|ReparseDataLength
operator|+
name|REPARSE_MOUNTPOINT_HEADER_SIZE
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|&
name|returnedLength
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|CloseHandle
argument_list|(
name|hFile
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|ioc
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|private
label|:
specifier|static
name|QString
name|tempFilePattern
parameter_list|()
block|{
name|QString
name|result
init|=
name|QDir
operator|::
name|tempPath
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|result
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|result
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|+=
name|QStringLiteral
argument_list|(
literal|"qt-test-filesystem-"
argument_list|)
expr_stmt|;
name|result
operator|+=
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
expr_stmt|;
name|result
operator|+=
name|QStringLiteral
argument_list|(
literal|"-XXXXXX"
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
name|QFile
modifier|*
name|openFileForWrite
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
block|{
if|if
condition|(
name|m_temporaryDir
operator|.
name|isValid
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|absName
init|=
name|absoluteFilePath
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|QScopedPointer
operator|<
name|QFile
operator|>
name|file
argument_list|(
argument|new QFile(absName)
argument_list|)
expr_stmt|;
if|if
condition|(
name|file
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
return|return
name|file
operator|.
name|take
argument_list|()
return|;
name|qWarning
argument_list|(
literal|"Cannot open '%s' for writing: %s"
argument_list|,
name|qPrintable
argument_list|(
name|absName
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
name|QTemporaryDir
name|m_temporaryDir
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// include guard
end_comment
end_unit
