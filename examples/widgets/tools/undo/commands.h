begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMMANDS_H
end_ifndef
begin_define
DECL|macro|COMMANDS_H
define|#
directive|define
name|COMMANDS_H
end_define
begin_include
include|#
directive|include
file|<QUndoCommand>
end_include
begin_include
include|#
directive|include
file|"document.h"
end_include
begin_decl_stmt
name|class
name|AddShapeCommand
range|:
name|public
name|QUndoCommand
block|{
name|public
operator|:
name|AddShapeCommand
argument_list|(
name|Document
operator|*
name|doc
argument_list|,
specifier|const
name|Shape
operator|&
name|shape
argument_list|,
name|QUndoCommand
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|undo
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|redo
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Document
operator|*
name|m_doc
block|;
name|Shape
name|m_shape
block|;
name|QString
name|m_shapeName
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|RemoveShapeCommand
range|:
name|public
name|QUndoCommand
block|{
name|public
operator|:
name|RemoveShapeCommand
argument_list|(
name|Document
operator|*
name|doc
argument_list|,
specifier|const
name|QString
operator|&
name|shapeName
argument_list|,
name|QUndoCommand
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|undo
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|redo
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Document
operator|*
name|m_doc
block|;
name|Shape
name|m_shape
block|;
name|QString
name|m_shapeName
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SetShapeColorCommand
range|:
name|public
name|QUndoCommand
block|{
name|public
operator|:
name|SetShapeColorCommand
argument_list|(
name|Document
operator|*
name|doc
argument_list|,
specifier|const
name|QString
operator|&
name|shapeName
argument_list|,
specifier|const
name|QColor
operator|&
name|color
argument_list|,
name|QUndoCommand
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|undo
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|redo
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|mergeWith
argument_list|(
argument|const QUndoCommand *command
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|id
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Document
operator|*
name|m_doc
block|;
name|QString
name|m_shapeName
block|;
name|QColor
name|m_oldColor
block|;
name|QColor
name|m_newColor
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SetShapeRectCommand
range|:
name|public
name|QUndoCommand
block|{
name|public
operator|:
name|SetShapeRectCommand
argument_list|(
name|Document
operator|*
name|doc
argument_list|,
specifier|const
name|QString
operator|&
name|shapeName
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|QUndoCommand
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|undo
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|redo
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|mergeWith
argument_list|(
argument|const QUndoCommand *command
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|id
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Document
operator|*
name|m_doc
block|;
name|QString
name|m_shapeName
block|;
name|QRect
name|m_oldRect
block|;
name|QRect
name|m_newRect
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMMANDS_H
end_comment
end_unit
