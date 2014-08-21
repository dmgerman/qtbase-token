begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_empty
empty|#import<UIKit/UIKit.h>
end_empty
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_decl_stmt
DECL|variable|QIOSWindow
name|class
name|QIOSWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIOSWindow
unit|@
name|interface
name|QUIView
range|:
name|UIView
block|{   @
name|public
name|QIOSWindow
operator|*
name|m_qioswindow
block|;   @
name|private
name|QHash
operator|<
name|UITouch
operator|*
block|,
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
name|m_activeTouches
block|;
name|int
name|m_nextTouchId
block|;    @
name|private
name|NSMutableArray
operator|*
name|m_accessibleElements
block|; }
operator|-
operator|(
name|id
operator|)
name|initWithQIOSWindow
operator|:
operator|(
name|QIOSWindow
operator|*
operator|)
name|window
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|sendUpdatedExposeEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|QUIView
argument_list|(
name|Accessibility
argument_list|)
operator|-
operator|(
name|void
operator|)
name|clearAccessibleCache
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
end_unit
