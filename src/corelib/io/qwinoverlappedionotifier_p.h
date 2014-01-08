begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINOVERLAPPEDIONOTIFIER_P_H
end_ifndef
begin_define
DECL|macro|QWINOVERLAPPEDIONOTIFIER_P_H
define|#
directive|define
name|QWINOVERLAPPEDIONOTIFIER_P_H
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
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWinOverlappedIoNotifierPrivate
name|class
name|QWinOverlappedIoNotifierPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QWinOverlappedIoNotifier
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DISABLE_COPY
argument_list|(
argument|QWinOverlappedIoNotifier
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWinOverlappedIoNotifier
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|OVERLAPPED *_q_notified()
argument_list|)
name|friend
name|class
name|QWinIoCompletionPort
block|;
name|public
operator|:
name|QWinOverlappedIoNotifier
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QWinOverlappedIoNotifier
argument_list|()
block|;
name|void
name|setHandle
argument_list|(
argument|HANDLE h
argument_list|)
block|;
name|HANDLE
name|handle
argument_list|()
specifier|const
block|;
name|void
name|setEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|waitForNotified
argument_list|(
argument|int msecs
argument_list|,
argument|OVERLAPPED *overlapped
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|notified
argument_list|(
argument|DWORD numberOfBytes
argument_list|,
argument|DWORD errorCode
argument_list|,
argument|OVERLAPPED *overlapped
argument_list|)
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|void
name|_q_notify
argument_list|()
block|;
endif|#
directive|endif
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
comment|// QWINOVERLAPPEDIONOTIFIER_P_H
end_comment
end_unit
