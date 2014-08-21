begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEDEVICE_H
end_ifndef
begin_define
DECL|macro|QFILEDEVICE_H
define|#
directive|define
name|QFILEDEVICE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFileDevicePrivate
name|class
name|QFileDevicePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFileDevice
range|:
name|public
name|QIODevice
block|{
ifndef|#
directive|ifndef
name|QT_NO_QOBJECT
name|Q_OBJECT
endif|#
directive|endif
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFileDevice
argument_list|)
name|public
operator|:
expr|enum
name|FileError
block|{
name|NoError
operator|=
literal|0
block|,
name|ReadError
operator|=
literal|1
block|,
name|WriteError
operator|=
literal|2
block|,
name|FatalError
operator|=
literal|3
block|,
name|ResourceError
operator|=
literal|4
block|,
name|OpenError
operator|=
literal|5
block|,
name|AbortError
operator|=
literal|6
block|,
name|TimeOutError
operator|=
literal|7
block|,
name|UnspecifiedError
operator|=
literal|8
block|,
name|RemoveError
operator|=
literal|9
block|,
name|RenameError
operator|=
literal|10
block|,
name|PositionError
operator|=
literal|11
block|,
name|ResizeError
operator|=
literal|12
block|,
name|PermissionsError
operator|=
literal|13
block|,
name|CopyError
operator|=
literal|14
block|}
block|;      enum
name|Permission
block|{
name|ReadOwner
operator|=
literal|0x4000
block|,
name|WriteOwner
operator|=
literal|0x2000
block|,
name|ExeOwner
operator|=
literal|0x1000
block|,
name|ReadUser
operator|=
literal|0x0400
block|,
name|WriteUser
operator|=
literal|0x0200
block|,
name|ExeUser
operator|=
literal|0x0100
block|,
name|ReadGroup
operator|=
literal|0x0040
block|,
name|WriteGroup
operator|=
literal|0x0020
block|,
name|ExeGroup
operator|=
literal|0x0010
block|,
name|ReadOther
operator|=
literal|0x0004
block|,
name|WriteOther
operator|=
literal|0x0002
block|,
name|ExeOther
operator|=
literal|0x0001
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|Permissions
argument_list|,
name|Permission
argument_list|)
expr|enum
name|FileHandleFlag
block|{
name|AutoCloseHandle
operator|=
literal|0x0001
block|,
name|DontCloseHandle
operator|=
literal|0
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|FileHandleFlags
argument_list|,
name|FileHandleFlag
argument_list|)
operator|~
name|QFileDevice
argument_list|()
block|;
name|FileError
name|error
argument_list|()
specifier|const
block|;
name|void
name|unsetError
argument_list|()
block|;
name|virtual
name|void
name|close
argument_list|()
block|;
name|bool
name|isSequential
argument_list|()
specifier|const
block|;
name|int
name|handle
argument_list|()
specifier|const
block|;
name|virtual
name|QString
name|fileName
argument_list|()
specifier|const
block|;
name|qint64
name|pos
argument_list|()
specifier|const
block|;
name|bool
name|seek
argument_list|(
argument|qint64 offset
argument_list|)
block|;
name|bool
name|atEnd
argument_list|()
specifier|const
block|;
name|bool
name|flush
argument_list|()
block|;
name|qint64
name|size
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|resize
argument_list|(
argument|qint64 sz
argument_list|)
block|;
name|virtual
name|Permissions
name|permissions
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|setPermissions
argument_list|(
argument|Permissions permissionSpec
argument_list|)
block|;
comment|// ### Qt 6: rename to MemoryMapFlag& make it a QFlags
block|enum
name|MemoryMapFlags
block|{
name|NoOptions
operator|=
literal|0
block|,
name|MapPrivateOption
operator|=
literal|0x0001
block|}
block|;
name|uchar
operator|*
name|map
argument_list|(
argument|qint64 offset
argument_list|,
argument|qint64 size
argument_list|,
argument|MemoryMapFlags flags = NoOptions
argument_list|)
block|;
name|bool
name|unmap
argument_list|(
name|uchar
operator|*
name|address
argument_list|)
block|;
name|protected
operator|:
name|QFileDevice
argument_list|()
block|;
ifdef|#
directive|ifdef
name|QT_NO_QOBJECT
name|QFileDevice
argument_list|(
name|QFileDevicePrivate
operator|&
name|dd
argument_list|)
block|;
else|#
directive|else
name|explicit
name|QFileDevice
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QFileDevice
argument_list|(
name|QFileDevicePrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
endif|#
directive|endif
name|qint64
name|readData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|qint64
name|writeData
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
block|;
name|qint64
name|readLineData
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QFileDevice
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFileDevice::Permissions
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEDEVICE_H
end_comment
end_unit
