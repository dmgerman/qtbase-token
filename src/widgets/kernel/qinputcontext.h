begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Definition of QInputContext class ** ** Copyright (C) 2003-2004 immodule for Qt Project.  All rights reserved. ** ** This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own ** license. You may use this file under your Qt license. Following ** description is copied from their original file headers. Contact ** immodule-qt@freedesktop.org if any conditions of this licensing are ** not clear to you. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QINPUTCONTEXT_H
define|#
directive|define
name|QINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qaction.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IM
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPopupMenu
name|class
name|QPopupMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QInputContextPrivate
name|class
name|QInputContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QInputContext
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QInputContext
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QInputContext
argument_list|()
block|;
name|virtual
name|QString
name|identifierName
argument_list|()
block|;
name|virtual
name|QString
name|language
argument_list|()
block|;
name|virtual
name|void
name|reset
argument_list|()
block|;
name|virtual
name|void
name|update
argument_list|()
block|;
name|virtual
name|void
name|mouseHandler
argument_list|(
argument|int x
argument_list|,
argument|QMouseEvent *event
argument_list|)
block|;
name|virtual
name|QFont
name|font
argument_list|()
specifier|const
block|;
name|QWidget
operator|*
name|focusWidget
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setFocusWidget
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|virtual
name|void
name|widgetDestroyed
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|virtual
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|()
block|;
name|void
name|sendEvent
argument_list|(
specifier|const
name|QInputMethodEvent
operator|&
name|event
argument_list|)
block|;
name|virtual
name|bool
name|isComposing
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
expr|enum
name|StandardFormat
block|{
name|PreeditFormat
block|,
name|SelectionFormat
block|}
block|;
name|QTextFormat
name|standardFormat
argument_list|(
argument|StandardFormat s
argument_list|)
specifier|const
block|;
name|private
operator|:
name|friend
name|class
name|QWidget
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|friend
name|class
name|QInputContextFactory
block|;
name|friend
name|class
name|QApplication
block|;
name|private
operator|:
comment|// Disabled copy constructor and operator=
name|QInputContext
argument_list|(
specifier|const
name|QInputContext
operator|&
argument_list|)
block|;
name|QInputContext
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QInputContext
operator|&
operator|)
block|;  }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_NO_IM
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QINPUTCONTEXT_H
end_comment
end_unit
