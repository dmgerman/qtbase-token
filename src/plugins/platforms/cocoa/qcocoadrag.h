begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOADRAG_H
end_ifndef
begin_define
DECL|macro|QCOCOADRAG_H
define|#
directive|define
name|QCOCOADRAG_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdrag.h>
end_include
begin_include
include|#
directive|include
file|<private/qsimpledrag_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qdnd_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaDrag
range|:
name|public
name|QPlatformDrag
block|{
name|public
operator|:
name|QCocoaDrag
argument_list|()
block|;
name|virtual
operator|~
name|QCocoaDrag
argument_list|()
block|;
name|virtual
name|QMimeData
operator|*
name|platformDropData
argument_list|()
block|;
name|virtual
name|Qt
operator|::
name|DropAction
name|drag
argument_list|(
name|QDrag
operator|*
name|m_drag
argument_list|)
block|;
name|virtual
name|Qt
operator|::
name|DropAction
name|defaultAction
argument_list|(
argument|Qt::DropActions possibleActions
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
specifier|const
block|;
comment|/**     * to meet NSView dragImage:at guarantees, we need to record the original     * event and view when handling an event in QNSView     */
name|void
name|setLastMouseEvent
argument_list|(
name|NSEvent
operator|*
name|event
argument_list|,
name|NSView
operator|*
name|view
argument_list|)
block|;
name|void
name|setAcceptedAction
argument_list|(
argument|Qt::DropAction act
argument_list|)
block|;
name|private
operator|:
name|QDrag
operator|*
name|m_drag
block|;
name|NSEvent
operator|*
name|m_lastEvent
block|;
name|NSView
operator|*
name|m_lastView
block|;
name|Qt
operator|::
name|DropAction
name|m_executed_drop_action
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaDropData
range|:
name|public
name|QInternalMimeData
block|{
name|public
operator|:
name|QCocoaDropData
argument_list|(
name|NSPasteboard
operator|*
name|pasteboard
argument_list|)
block|;
operator|~
name|QCocoaDropData
argument_list|()
block|;
name|protected
operator|:
name|bool
name|hasFormat_sys
argument_list|(
argument|const QString&mimeType
argument_list|)
specifier|const
block|;
name|QStringList
name|formats_sys
argument_list|()
specifier|const
block|;
name|QVariant
name|retrieveData_sys
argument_list|(
argument|const QString&mimeType
argument_list|,
argument|QVariant::Type type
argument_list|)
specifier|const
block|;
name|public
operator|:
name|CFStringRef
name|dropPasteboard
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
end_unit
