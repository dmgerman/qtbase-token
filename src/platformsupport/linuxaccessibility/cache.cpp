begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"cache_p.h"
end_include
begin_include
include|#
directive|include
file|"bridge_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"cache_adaptor.h"
end_include
begin_define
DECL|macro|QSPI_OBJECT_PATH_CACHE
define|#
directive|define
name|QSPI_OBJECT_PATH_CACHE
value|"/org/a11y/atspi/cache"
end_define
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QSpiDBusCache     \internal     \brief This class is responsible for the AT-SPI cache interface.      The idea behind the cache is that starting an application would     result in many dbus calls. The way GTK/Gail/ATK work is that     they create accessibles for all objects on startup.     In order to avoid querying all the objects individually via DBus     they get sent by using the GetItems call of the cache.      Additionally the AddAccessible and RemoveAccessible signals     are responsible for adding/removing objects from the cache.      Currently the Qt bridge chooses to ignore these. */
end_comment
begin_constructor
DECL|function|QSpiDBusCache
name|QSpiDBusCache
operator|::
name|QSpiDBusCache
parameter_list|(
name|QDBusConnection
name|c
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{
operator|new
name|CacheAdaptor
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|c
operator|.
name|registerObject
argument_list|(
name|QLatin1String
argument_list|(
name|QSPI_OBJECT_PATH_CACHE
argument_list|)
argument_list|,
name|this
argument_list|,
name|QDBusConnection
operator|::
name|ExportAdaptors
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|emitAddAccessible
name|void
name|QSpiDBusCache
operator|::
name|emitAddAccessible
parameter_list|(
specifier|const
name|QSpiAccessibleCacheItem
modifier|&
name|item
parameter_list|)
block|{
emit|emit
name|AddAccessible
argument_list|(
name|item
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|emitRemoveAccessible
name|void
name|QSpiDBusCache
operator|::
name|emitRemoveAccessible
parameter_list|(
specifier|const
name|QSpiObjectReference
modifier|&
name|item
parameter_list|)
block|{
emit|emit
name|RemoveAccessible
argument_list|(
name|item
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|GetItems
name|QSpiAccessibleCacheArray
name|QSpiDBusCache
operator|::
name|GetItems
parameter_list|()
block|{
name|QList
argument_list|<
name|QSpiAccessibleCacheItem
argument_list|>
name|cacheArray
decl_stmt|;
return|return
name|cacheArray
return|;
block|}
end_function
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
end_unit
