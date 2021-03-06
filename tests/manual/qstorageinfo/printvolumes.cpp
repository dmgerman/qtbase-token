begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QStorageInfo>
end_include
begin_function
DECL|function|printVolumes
name|void
name|printVolumes
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QStorageInfo
argument_list|>
modifier|&
name|volumes
parameter_list|,
name|int
function_decl|(
modifier|*
name|printer
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
parameter_list|)
block|{
comment|// Sample output:
comment|//  Filesystem (Type)            Size  Available BSize  Label            Mounted on
comment|//  /dev/sda2 (ext4)    RO     388480     171218  1024                   /boot
comment|//  /dev/mapper/system-root (btrfs) RW
comment|//                          214958080   39088272  4096                   /
comment|//  /dev/disk1s2 (hfs)  RW  488050672  419909696  4096  Macintosh HD2    /Volumes/Macintosh HD2
name|printf
argument_list|(
literal|"Filesystem (Type)            Size  Available BSize  Label            Mounted on\n"
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QStorageInfo
modifier|&
name|info
decl|,
name|volumes
control|)
block|{
name|QByteArray
name|fsAndType
init|=
name|info
operator|.
name|device
argument_list|()
decl_stmt|;
if|if
condition|(
name|info
operator|.
name|fileSystemType
argument_list|()
operator|!=
name|fsAndType
condition|)
name|fsAndType
operator|+=
literal|" ("
operator|+
name|info
operator|.
name|fileSystemType
argument_list|()
operator|+
literal|')'
expr_stmt|;
name|printf
argument_list|(
literal|"%-19s R%c "
argument_list|,
name|fsAndType
operator|.
name|constData
argument_list|()
argument_list|,
name|info
operator|.
name|isReadOnly
argument_list|()
condition|?
literal|'O'
else|:
literal|'W'
argument_list|)
expr_stmt|;
if|if
condition|(
name|fsAndType
operator|.
name|size
argument_list|()
operator|>
literal|19
condition|)
name|printf
argument_list|(
literal|"\n%23s"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%10llu %10llu %5u  "
argument_list|,
name|info
operator|.
name|bytesTotal
argument_list|()
operator|/
literal|1024
argument_list|,
name|info
operator|.
name|bytesFree
argument_list|()
operator|/
literal|1024
argument_list|,
name|info
operator|.
name|blockSize
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%-16s %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|info
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|info
operator|.
name|rootPath
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
