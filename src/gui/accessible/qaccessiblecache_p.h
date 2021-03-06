begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLECACHE_P
end_ifndef
begin_define
DECL|macro|QACCESSIBLECACHE_P
define|#
directive|define
name|QACCESSIBLECACHE_P
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
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|"qaccessible.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_expr_stmt
name|Q_FORWARD_DECLARE_OBJC_CLASS
argument_list|(
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QMacAccessibilityElement
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QAccessibleCache
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
name|QAccessibleCache
operator|*
name|instance
argument_list|()
block|;
name|QAccessibleInterface
operator|*
name|interfaceForId
argument_list|(
argument|QAccessible::Id id
argument_list|)
specifier|const
block|;
name|QAccessible
operator|::
name|Id
name|insert
argument_list|(
argument|QObject *object
argument_list|,
argument|QAccessibleInterface *iface
argument_list|)
specifier|const
block|;
name|void
name|deleteInterface
argument_list|(
argument|QAccessible::Id id
argument_list|,
argument|QObject *obj =
literal|0
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QMacAccessibilityElement
argument_list|)
operator|*
name|elementForId
argument_list|(
argument|QAccessible::Id axid
argument_list|)
specifier|const
block|;
name|void
name|insertElement
argument_list|(
argument|QAccessible::Id axid
argument_list|,
argument|QT_MANGLE_NAMESPACE(QMacAccessibilityElement) *element
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|private
name|Q_SLOTS
operator|:
name|void
name|objectDestroyed
argument_list|(
name|QObject
operator|*
name|obj
argument_list|)
block|;
name|private
operator|:
name|QAccessible
operator|::
name|Id
name|acquireId
argument_list|()
specifier|const
block|;
name|mutable
name|QHash
operator|<
name|QAccessible
operator|::
name|Id
block|,
name|QAccessibleInterface
operator|*
operator|>
name|idToInterface
block|;
name|mutable
name|QHash
operator|<
name|QObject
operator|*
block|,
name|QAccessible
operator|::
name|Id
operator|>
name|objectToId
block|;
ifdef|#
directive|ifdef
name|Q_OS_MAC
name|void
name|removeCocoaElement
argument_list|(
argument|QAccessible::Id axid
argument_list|)
block|;
name|mutable
name|QHash
operator|<
name|QAccessible
operator|::
name|Id
block|,
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QMacAccessibilityElement
argument_list|)
operator|*
operator|>
name|cocoaElements
block|;
endif|#
directive|endif
name|friend
name|class
name|QAccessible
block|;
name|friend
name|class
name|QAccessibleInterface
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
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
