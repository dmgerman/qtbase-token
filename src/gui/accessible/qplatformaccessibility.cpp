begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformaccessibility.h"
end_include
begin_include
include|#
directive|include
file|<private/qfactoryloader_p.h>
end_include
begin_include
include|#
directive|include
file|"qaccessibleplugin.h"
end_include
begin_include
include|#
directive|include
file|"qaccessibleobject.h"
end_include
begin_include
include|#
directive|include
file|"qaccessiblebridge.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
comment|/* accessiblebridge plugin discovery stuff */
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|bridgeloader
argument_list|,
operator|(
name|QAccessibleBridgeFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/accessiblebridge"
argument_list|)
operator|)
argument_list|)
name|Q_GLOBAL_STATIC
argument_list|(
name|QVector
argument_list|<
name|QAccessibleBridge
operator|*
argument_list|>
argument_list|,
name|bridges
argument_list|)
comment|/*!     \class QPlatformAccessibility     \since 5.0     \internal     \preliminary     \ingroup qpa     \ingroup accessibility      \brief The QPlatformAccessibility class is the base class for     integrating accessibility backends      \sa QAccessible */
DECL|function|QPlatformAccessibility
name|QPlatformAccessibility
operator|::
name|QPlatformAccessibility
argument_list|()
range|:
name|m_active
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|~QPlatformAccessibility
name|QPlatformAccessibility
operator|::
name|~
name|QPlatformAccessibility
operator|(
operator|)
block|{ }
DECL|function|notifyAccessibilityUpdate
name|void
name|QPlatformAccessibility
operator|::
name|notifyAccessibilityUpdate
operator|(
name|QAccessibleEvent
operator|*
name|event
operator|)
block|{
name|initialize
argument_list|()
block|;
if|if
condition|(
operator|!
name|bridges
argument_list|()
operator|||
name|bridges
argument_list|()
operator|->
name|isEmpty
argument_list|()
condition|)
return|return;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|bridges
argument_list|()
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|bridges
argument_list|()
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|notifyAccessibilityUpdate
argument_list|(
name|event
argument_list|)
expr_stmt|;
end_for
begin_macro
unit|}  void
DECL|function|setRootObject
name|QPlatformAccessibility
end_macro
begin_expr_stmt
DECL|function|setRootObject
operator|::
name|setRootObject
operator|(
name|QObject
operator|*
name|o
operator|)
block|{
name|initialize
argument_list|()
block|;
if|if
condition|(
name|bridges
argument_list|()
operator|->
name|isEmpty
argument_list|()
condition|)
return|return;
end_expr_stmt
begin_if
if|if
condition|(
operator|!
name|o
condition|)
return|return;
end_if
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|bridges
argument_list|()
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAccessibleInterface
modifier|*
name|iface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|o
argument_list|)
decl_stmt|;
name|bridges
argument_list|()
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|setRootObject
argument_list|(
name|iface
argument_list|)
expr_stmt|;
block|}
end_for
begin_macro
unit|}  void
DECL|function|initialize
name|QPlatformAccessibility
end_macro
begin_expr_stmt
DECL|function|initialize
operator|::
name|initialize
operator|(
operator|)
block|{
specifier|static
name|bool
name|isInit
operator|=
literal|false
block|;
if|if
condition|(
name|isInit
condition|)
return|return;
name|isInit
operator|=
literal|true
expr_stmt|;
end_expr_stmt
begin_comment
comment|// ### not atomic
end_comment
begin_typedef
typedef|typedef
name|QMultiMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|PluginKeyMap
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|PluginKeyMap
operator|::
name|const_iterator
name|PluginKeyMapConstIterator
typedef|;
end_typedef
begin_decl_stmt
specifier|const
name|PluginKeyMap
name|keyMap
init|=
name|bridgeloader
argument_list|()
operator|->
name|keyMap
argument_list|()
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAccessibleBridgePlugin
modifier|*
name|factory
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|i
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|PluginKeyMapConstIterator
name|cend
init|=
name|keyMap
operator|.
name|constEnd
argument_list|()
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|PluginKeyMapConstIterator
name|it
init|=
name|keyMap
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
name|it
operator|.
name|key
argument_list|()
operator|!=
name|i
condition|)
block|{
name|i
operator|=
name|it
operator|.
name|key
argument_list|()
expr_stmt|;
name|factory
operator|=
name|qobject_cast
argument_list|<
name|QAccessibleBridgePlugin
operator|*
argument_list|>
argument_list|(
name|bridgeloader
argument_list|()
operator|->
name|instance
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|factory
condition|)
if|if
condition|(
name|QAccessibleBridge
modifier|*
name|bridge
init|=
name|factory
operator|->
name|create
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
condition|)
name|bridges
argument_list|()
operator|->
name|append
argument_list|(
name|bridge
argument_list|)
expr_stmt|;
block|}
end_for
begin_macro
unit|}  void
DECL|function|cleanup
name|QPlatformAccessibility
end_macro
begin_expr_stmt
DECL|function|cleanup
operator|::
name|cleanup
operator|(
operator|)
block|{
name|qDeleteAll
argument_list|(
operator|*
name|bridges
argument_list|()
argument_list|)
block|; }
DECL|function|setActive
name|void
name|QPlatformAccessibility
operator|::
name|setActive
operator|(
name|bool
name|active
operator|)
block|{
name|m_active
operator|=
name|active
block|;
name|QAccessible
operator|::
name|setActive
argument_list|(
name|active
argument_list|)
block|; }
endif|#
directive|endif
comment|// QT_NO_ACCESSIBILITY
name|QT_END_NAMESPACE
end_expr_stmt
end_unit
