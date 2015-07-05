begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSMENUTYPES_H
end_ifndef
begin_define
DECL|macro|QDBUSMENUTYPES_H
define|#
directive|define
name|QDBUSMENUTYPES_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QDBusArgument>
end_include
begin_include
include|#
directive|include
file|<QDBusConnection>
end_include
begin_include
include|#
directive|include
file|<QDBusObjectPath>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusPlatformMenu
name|class
name|QDBusPlatformMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusPlatformMenuItem
name|class
name|QDBusPlatformMenuItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusMenuItem
name|class
name|QDBusMenuItem
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QDBusMenuItemList
typedef|typedef
name|QVector
operator|<
name|QDBusMenuItem
operator|>
name|QDBusMenuItemList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QDBusMenuItem
block|{
name|public
label|:
name|QDBusMenuItem
argument_list|()
block|{ }
name|QDBusMenuItem
argument_list|(
specifier|const
name|QDBusPlatformMenuItem
operator|*
name|item
argument_list|)
expr_stmt|;
specifier|static
name|QDBusMenuItemList
name|items
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|ids
argument_list|,
specifier|const
name|QStringList
operator|&
name|propertyNames
argument_list|)
decl_stmt|;
specifier|static
name|QString
name|convertMnemonic
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|)
function_decl|;
specifier|static
name|void
name|registerDBusTypes
parameter_list|()
function_decl|;
name|int
name|m_id
decl_stmt|;
name|QVariantMap
name|m_properties
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QDBusMenuItem
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|arg
operator|,
specifier|const
name|QDBusMenuItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|arg
operator|,
name|QDBusMenuItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QDBusMenuItemKeys
block|{
name|public
label|:
name|int
name|id
decl_stmt|;
name|QStringList
name|properties
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QDBusMenuItemKeys
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|arg
operator|,
specifier|const
name|QDBusMenuItemKeys
operator|&
name|keys
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|arg
operator|,
name|QDBusMenuItemKeys
operator|&
name|keys
operator|)
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QDBusMenuItemKeysList
typedef|typedef
name|QVector
operator|<
name|QDBusMenuItemKeys
operator|>
name|QDBusMenuItemKeysList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QDBusMenuLayoutItem
block|{
name|public
label|:
name|uint
name|populate
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|propertyNames
parameter_list|)
function_decl|;
name|void
name|populate
parameter_list|(
specifier|const
name|QDBusPlatformMenu
modifier|*
name|menu
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|propertyNames
parameter_list|)
function_decl|;
name|void
name|populate
parameter_list|(
specifier|const
name|QDBusPlatformMenuItem
modifier|*
name|item
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|propertyNames
parameter_list|)
function_decl|;
name|int
name|m_id
decl_stmt|;
name|QVariantMap
name|m_properties
decl_stmt|;
name|QVector
operator|<
name|QDBusMenuLayoutItem
operator|>
name|m_children
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QDBusMenuLayoutItem
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|arg
operator|,
specifier|const
name|QDBusMenuLayoutItem
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|arg
operator|,
name|QDBusMenuLayoutItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QDBusMenuLayoutItemList
typedef|typedef
name|QVector
operator|<
name|QDBusMenuLayoutItem
operator|>
name|QDBusMenuLayoutItemList
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|QDBusMenuEvent
block|{
name|public
label|:
name|int
name|m_id
decl_stmt|;
name|QString
name|m_eventId
decl_stmt|;
name|QDBusVariant
name|m_data
decl_stmt|;
name|uint
name|m_timestamp
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QDBusMenuEvent
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// QDBusVariant is movable, even though it cannot
end_comment
begin_comment
comment|// be marked as such until Qt 6.
end_comment
begin_expr_stmt
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|arg
operator|,
specifier|const
name|QDBusMenuEvent
operator|&
name|ev
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|arg
operator|,
name|QDBusMenuEvent
operator|&
name|ev
operator|)
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QDBusMenuEventList
typedef|typedef
name|QVector
operator|<
name|QDBusMenuEvent
operator|>
name|QDBusMenuEventList
expr_stmt|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QDBusMenuItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QDBusMenuLayoutItem
operator|&
name|item
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMenuItem
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMenuItemList
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMenuItemKeys
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMenuItemKeysList
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMenuLayoutItem
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMenuLayoutItemList
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMenuEvent
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusMenuEventList
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
