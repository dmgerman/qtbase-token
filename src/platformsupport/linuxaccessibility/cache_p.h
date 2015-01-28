begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_SPI_CACHE_H
end_ifndef
begin_define
DECL|macro|Q_SPI_CACHE_H
define|#
directive|define
name|Q_SPI_CACHE_H
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
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|"struct_marshallers_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSpiDBusCache
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QSpiDBusCache
argument_list|(
argument|QDBusConnection c
argument_list|,
argument|QObject* parent =
literal|0
argument_list|)
block|;
name|void
name|emitAddAccessible
argument_list|(
specifier|const
name|QSpiAccessibleCacheItem
operator|&
name|item
argument_list|)
block|;
name|void
name|emitRemoveAccessible
argument_list|(
specifier|const
name|QSpiObjectReference
operator|&
name|item
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|AddAccessible
argument_list|(
specifier|const
name|QSpiAccessibleCacheItem
operator|&
name|nodeAdded
argument_list|)
block|;
name|void
name|RemoveAccessible
argument_list|(
specifier|const
name|QSpiObjectReference
operator|&
name|nodeRemoved
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|QSpiAccessibleCacheArray
name|GetItems
argument_list|()
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
comment|//QT_NO_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Q_SPI_CACHE_H */
end_comment
end_unit
