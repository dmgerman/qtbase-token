begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTRANSPORTAUTH_QWS_P_H
end_ifndef
begin_define
DECL|macro|QTRANSPORTAUTH_QWS_P_H
define|#
directive|define
name|QTRANSPORTAUTH_QWS_P_H
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
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SXE
end_ifndef
begin_include
include|#
directive|include
file|"qtransportauth_qws.h"
end_include
begin_include
include|#
directive|include
file|"qtransportauthdefs_qws.h"
end_include
begin_include
include|#
directive|include
file|"qbuffer.h"
end_include
begin_include
include|#
directive|include
file|<qmutex.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qcache.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
comment|// Uncomment to generate debug output
comment|// #define QTRANSPORTAUTH_DEBUG 1
ifdef|#
directive|ifdef
name|QTRANSPORTAUTH_DEBUG
name|void
name|hexstring
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|size_t
name|sz
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// proj id for ftok usage in sxe
end_comment
begin_define
DECL|macro|SXE_PROJ
define|#
directive|define
name|SXE_PROJ
value|10022
end_define
begin_comment
comment|/*!   \internal   memset for security purposes, guaranteed not to be optimized away   http://www.faqs.org/docs/Linux-HOWTO/Secure-Programs-HOWTO.html */
end_comment
begin_function_decl
name|void
modifier|*
name|guaranteed_memset
parameter_list|(
name|void
modifier|*
name|v
parameter_list|,
name|int
name|c
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|QUnixSocketMessage
name|class
name|QUnixSocketMessage
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   \internal   \class AuthCookie   Struct to carry process authentication key and id */
end_comment
begin_define
DECL|macro|QSXE_HEADER_LEN
define|#
directive|define
name|QSXE_HEADER_LEN
value|24
end_define
begin_comment
comment|/*!   \macro AUTH_ID   Macro to manage authentication header.  Format of header is:   \table   \header \i BYTES  \i  CONTENT      \row \i 0-3    \i  magic numbers      \row \i 4      \i  length of authenticated data (max 255 bytes)      \row i\ 5      \i  reserved      \row \i 6-21   \i  MAC digest, or shared secret in case of simple auth      \row \i 22     \i  program id      \row \i 23     \i  sequence number   \endtable   Total length of the header is 24 bytes    However this may change.  Instead of coding these numbers use the AUTH_ID,   AUTH_KEY, AUTH_DATA and AUTH_SPACE macros. */
end_comment
begin_define
DECL|macro|AUTH_ID
define|#
directive|define
name|AUTH_ID
parameter_list|(
name|k
parameter_list|)
value|((unsigned char)(k[QSXE_KEY_LEN]))
end_define
begin_define
DECL|macro|AUTH_KEY
define|#
directive|define
name|AUTH_KEY
parameter_list|(
name|k
parameter_list|)
value|((unsigned char *)(k))
end_define
begin_define
DECL|macro|AUTH_DATA
define|#
directive|define
name|AUTH_DATA
parameter_list|(
name|x
parameter_list|)
value|(unsigned char *)((x) + QSXE_HEADER_LEN)
end_define
begin_define
DECL|macro|AUTH_SPACE
define|#
directive|define
name|AUTH_SPACE
parameter_list|(
name|x
parameter_list|)
value|((x) + QSXE_HEADER_LEN)
end_define
begin_define
DECL|macro|QSXE_LEN_IDX
define|#
directive|define
name|QSXE_LEN_IDX
value|4
end_define
begin_define
DECL|macro|QSXE_KEY_IDX
define|#
directive|define
name|QSXE_KEY_IDX
value|6
end_define
begin_define
DECL|macro|QSXE_PROG_IDX
define|#
directive|define
name|QSXE_PROG_IDX
value|22
end_define
begin_define
DECL|macro|QSXE_SEQ_IDX
define|#
directive|define
name|QSXE_SEQ_IDX
value|23
end_define
begin_decl_stmt
name|class
name|SxeRegistryLocker
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|SxeRegistryLocker
argument_list|(
name|QObject
operator|*
argument_list|)
block|;
operator|~
name|SxeRegistryLocker
argument_list|()
block|;
name|bool
name|success
argument_list|()
specifier|const
block|{
return|return
name|m_success
return|;
block|}
name|private
operator|:
name|bool
name|m_success
block|;
name|QObject
operator|*
name|m_reg
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTransportAuthPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTransportAuth
argument_list|)
name|public
operator|:
name|QTransportAuthPrivate
argument_list|()
block|;
operator|~
name|QTransportAuthPrivate
argument_list|()
block|;
specifier|const
name|unsigned
name|char
operator|*
name|getClientKey
argument_list|(
argument|unsigned char progId
argument_list|)
block|;
name|void
name|invalidateClientKeyCache
argument_list|()
block|;
name|bool
name|keyInitialised
block|;
name|QString
name|m_logFilePath
block|;
name|QString
name|m_keyFilePath
block|;
name|QObject
operator|*
name|m_packageRegistry
block|;
name|AuthCookie
name|authKey
block|;
name|QCache
operator|<
name|unsigned
name|char
block|,
name|char
operator|>
name|keyCache
block|;
name|QHash
operator|<
name|QObject
operator|*
block|,
name|QIODevice
operator|*
operator|>
name|buffersByClient
block|;
name|QMutex
name|keyfileMutex
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!   \internal   Enforces the False Authentication Rate.  If more than 4 authentications   are received per minute the sxemonitor is notified that the FAR has been exceeded */
end_comment
begin_decl_stmt
name|class
name|FAREnforcer
block|{
name|public
label|:
specifier|static
name|FAREnforcer
modifier|*
name|getInstance
parameter_list|()
function_decl|;
name|void
name|logAuthAttempt
parameter_list|(
name|QDateTime
name|time
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
parameter_list|)
function_decl|;
name|void
name|reset
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|TEST_FAR_ENFORCER
name|private
label|:
endif|#
directive|endif
name|FAREnforcer
argument_list|()
expr_stmt|;
name|FAREnforcer
argument_list|(
specifier|const
name|FAREnforcer
operator|&
argument_list|)
expr_stmt|;
name|FAREnforcer
modifier|&
name|operator
init|=
operator|(
name|FAREnforcer
specifier|const
operator|&
operator|)
decl_stmt|;
specifier|static
specifier|const
name|QString
name|FARMessage
decl_stmt|;
specifier|static
specifier|const
name|int
name|minutelyRate
decl_stmt|;
specifier|static
specifier|const
name|QString
name|SxeTag
decl_stmt|;
specifier|static
specifier|const
name|int
name|minute
decl_stmt|;
name|QList
operator|<
name|QDateTime
operator|>
name|authAttempts
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SXE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTRANSPORTAUTH_QWS_P_H
end_comment
end_unit
