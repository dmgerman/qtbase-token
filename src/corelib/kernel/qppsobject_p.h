begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2013 BlackBerry Limited. All rights reserved.  ** Contact: https://www.qt.io/licensing/  **  ** This file is part of the QtCore module of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and The Qt Company. For licensing terms  ** and conditions see https://www.qt.io/terms-conditions. For further  ** information use the contact form at https://www.qt.io/contact-us.  **  ** GNU Lesser General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU Lesser  ** General Public License version 3 as published by the Free Software  ** Foundation and appearing in the file LICENSE.LGPL3 included in the  ** packaging of this file. Please review the following information to  ** ensure the GNU Lesser General Public License version 3 requirements  ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.  **  ** GNU General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU  ** General Public License version 2.0 or (at your option) the GNU General  ** Public license version 3 or any later version approved by the KDE Free  ** Qt Foundation. The licenses are as published by the Free Software  ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3  ** included in the packaging of this file. Please review the following  ** information to ensure the GNU General Public License requirements will  ** be met: https://www.gnu.org/licenses/gpl-2.0.html and  ** https://www.gnu.org/licenses/gpl-3.0.html.  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPPSOBJECT_P_H
end_ifndef
begin_define
DECL|macro|QPPSOBJECT_P_H
define|#
directive|define
name|QPPSOBJECT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qppsattribute_p.h"
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QVariantMap>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPpsObjectPrivate
name|class
name|QPpsObjectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QPpsObject
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|OpenMode
block|{
name|Publish
operator|=
literal|1
block|,
name|Subscribe
operator|=
literal|2
block|,
name|PublishSubscribe
operator|=
name|Publish
operator||
name|Subscribe
block|,
name|Create
operator|=
literal|4
block|,
name|DeleteContents
operator|=
literal|8
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|OpenModes
argument_list|,
argument|OpenMode
argument_list|)
name|explicit
name|QPpsObject
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QPpsObject
argument_list|()
block|;
name|int
name|error
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|bool
name|isReadyReadEnabled
argument_list|()
specifier|const
block|;
name|bool
name|isBlocking
argument_list|()
specifier|const
block|;
name|bool
name|setBlocking
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|isOpen
argument_list|()
specifier|const
block|;
name|bool
name|open
argument_list|(
argument|QPpsObject::OpenModes mode = QPpsObject::PublishSubscribe
argument_list|)
block|;
name|bool
name|close
argument_list|()
block|;
name|bool
name|remove
argument_list|()
block|;
name|QByteArray
name|read
argument_list|(
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
block|;
name|bool
name|write
argument_list|(
specifier|const
name|QByteArray
operator|&
name|byteArray
argument_list|)
block|;
name|int
name|writeMessage
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|dat
argument_list|)
block|;
name|int
name|writeMessage
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|,
specifier|const
name|QString
operator|&
name|id
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|dat
argument_list|)
block|;
specifier|static
name|QVariantMap
name|decode
argument_list|(
specifier|const
name|QByteArray
operator|&
name|rawData
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QPpsAttributeMap
name|decodeWithFlags
argument_list|(
specifier|const
name|QByteArray
operator|&
name|rawData
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QPpsAttributeMap
name|decodeWithFlags
argument_list|(
specifier|const
name|QByteArray
operator|&
name|rawData
argument_list|,
name|QPpsAttribute
operator|*
name|objectAttribute
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QByteArray
name|encode
argument_list|(
specifier|const
name|QVariantMap
operator|&
name|ppsData
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QByteArray
name|encodeMessage
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|dat
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QByteArray
name|encodeMessage
argument_list|(
specifier|const
name|QString
operator|&
name|msg
argument_list|,
specifier|const
name|QString
operator|&
name|id
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|dat
argument_list|,
name|bool
operator|*
name|ok
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|int
name|sendMessage
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QString
operator|&
name|message
argument_list|)
block|;
specifier|static
name|int
name|sendMessage
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|message
argument_list|)
block|;
specifier|static
name|int
name|sendMessage
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QString
operator|&
name|msg
argument_list|,
specifier|const
name|QVariantMap
operator|&
name|dat
argument_list|)
block|;
specifier|static
name|int
name|sendMessage
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QByteArray
operator|&
name|ppsData
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setReadyReadEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|readyRead
argument_list|()
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QPpsObjectPrivate
operator|>
name|d_ptr
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPpsObject
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QPpsObject
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPPSOBJECT_P_H
end_comment
end_unit
