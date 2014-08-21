begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Richard J. Moore<rich@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSSLCERTIFICATEEXTENSION_P_H
end_ifndef
begin_define
DECL|macro|QSSLCERTIFICATEEXTENSION_P_H
define|#
directive|define
name|QSSLCERTIFICATEEXTENSION_P_H
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
file|"qsslcertificateextension.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSslCertificateExtensionPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
specifier|inline
name|QSslCertificateExtensionPrivate
argument_list|()
operator|:
name|critical
argument_list|(
name|false
argument_list|)
block|,
name|supported
argument_list|(
argument|false
argument_list|)
block|{     }
name|QString
name|oid
block|;
name|QString
name|name
block|;
name|QVariant
name|value
block|;
name|bool
name|critical
block|;
name|bool
name|supported
block|; }
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
comment|// QSSLCERTIFICATEEXTENSION_P_H
end_comment
end_unit
