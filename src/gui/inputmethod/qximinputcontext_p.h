begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Definition of QXIMInputContext class ** ** Copyright (C) 2003-2004 immodule for Qt Project.  All rights reserved. ** ** This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own ** license. You may use this file under your Qt license. Following ** description is copied from their original file headers. Contact ** immodule-qt@freedesktop.org if any conditions of this licensing are ** not clear to you. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXIMINPUTCONTEXT_P_H
end_ifndef
begin_define
DECL|macro|QXIMINPUTCONTEXT_P_H
define|#
directive|define
name|QXIMINPUTCONTEXT_P_H
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
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_NO_IM
argument_list|)
end_if
begin_include
include|#
directive|include
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qinputcontext.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qfont.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_X11
end_ifdef
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbitarray.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qwindowdefs.h"
end_include
begin_include
include|#
directive|include
file|"private/qt_x11_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
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
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXIMInputContext
range|:
name|public
name|QInputContext
block|{
name|Q_OBJECT
name|public
operator|:
expr|struct
name|ICData
block|{
name|XIC
name|ic
block|;
name|XFontSet
name|fontset
block|;
name|QWidget
operator|*
name|widget
block|;
name|QString
name|text
block|;
name|QBitArray
name|selectedChars
block|;
name|bool
name|composing
block|;
name|bool
name|preeditEmpty
block|;
name|void
name|clear
argument_list|()
block|;     }
block|;
name|QXIMInputContext
argument_list|()
block|;
operator|~
name|QXIMInputContext
argument_list|()
block|;
name|QString
name|identifierName
argument_list|()
block|;
name|QString
name|language
argument_list|()
block|;
name|void
name|reset
argument_list|()
block|;
name|void
name|mouseHandler
argument_list|(
argument|int x
argument_list|,
argument|QMouseEvent *event
argument_list|)
block|;
name|bool
name|isComposing
argument_list|()
specifier|const
block|;
name|void
name|setFocusWidget
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|void
name|widgetDestroyed
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|void
name|create_xim
argument_list|()
block|;
name|void
name|close_xim
argument_list|()
block|;
name|void
name|update
argument_list|()
block|;
name|ICData
operator|*
name|icData
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|bool
name|x11FilterEvent
argument_list|(
name|QWidget
operator|*
name|keywidget
argument_list|,
name|XEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
specifier|static
name|XIMStyle
name|xim_style
block|;
name|QString
name|_language
block|;
name|XIM
name|xim
block|;
name|QHash
operator|<
name|WId
block|,
name|ICData
operator|*
operator|>
name|ximData
block|;
name|ICData
operator|*
name|createICData
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
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
comment|// Q_NO_IM
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXIMINPUTCONTEXT_P_H
end_comment
end_unit
