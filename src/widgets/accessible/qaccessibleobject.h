begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLEOBJECT_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLEOBJECT_H
define|#
directive|define
name|QACCESSIBLEOBJECT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qaccessible.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|class
name|QAccessibleObjectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleObject
range|:
name|public
name|QAccessibleInterface
block|{
name|public
operator|:
name|explicit
name|QAccessibleObject
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|;
comment|// properties
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|,
argument|const QString&text
argument_list|)
block|;
comment|// actions
name|int
name|userActionCount
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|virtual
operator|~
name|QAccessibleObject
argument_list|()
block|;
name|private
operator|:
name|friend
name|class
name|QAccessibleObjectEx
block|;
name|QAccessibleObjectPrivate
operator|*
name|d
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QAccessibleObject
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleObjectEx
range|:
name|public
name|QAccessibleInterfaceEx
block|{
name|public
operator|:
name|explicit
name|QAccessibleObjectEx
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|;
comment|// properties
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|,
argument|const QString&text
argument_list|)
block|;
comment|// actions
name|int
name|userActionCount
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|virtual
operator|~
name|QAccessibleObjectEx
argument_list|()
block|;
name|private
operator|:
name|QAccessibleObjectPrivate
operator|*
name|d
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QAccessibleObjectEx
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleApplication
range|:
name|public
name|QAccessibleObject
block|{
name|public
operator|:
name|QAccessibleApplication
argument_list|()
block|;
comment|// relations
name|int
name|childCount
argument_list|()
specifier|const
block|;
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface*
argument_list|)
specifier|const
block|;
name|Relation
name|relationTo
argument_list|(
argument|int
argument_list|,
argument|const QAccessibleInterface *
argument_list|,
argument|int
argument_list|)
specifier|const
block|;
comment|// navigation
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
block|;
name|int
name|navigate
argument_list|(
argument|RelationFlag
argument_list|,
argument|int
argument_list|,
argument|QAccessibleInterface **
argument_list|)
specifier|const
block|;
comment|// properties and state
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|;
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
comment|// actions
name|int
name|userActionCount
argument_list|(
argument|int child
argument_list|)
specifier|const
block|;
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
block|;
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACCESSIBLEOBJECT_H
end_comment
end_unit
