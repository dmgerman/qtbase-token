begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTTABLE_P_H
end_ifndef
begin_define
DECL|macro|QTEXTTABLE_P_H
define|#
directive|define
name|QTEXTTABLE_P_H
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
file|"private/qtextobject_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtextdocument_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QTextTablePrivate
range|:
name|public
name|QTextFramePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTextTable
argument_list|)
name|public
operator|:
name|QTextTablePrivate
argument_list|(
name|QTextDocument
operator|*
name|document
argument_list|)
operator|:
name|QTextFramePrivate
argument_list|(
name|document
argument_list|)
block|,
name|grid
argument_list|(
literal|0
argument_list|)
block|,
name|nRows
argument_list|(
literal|0
argument_list|)
block|,
name|nCols
argument_list|(
literal|0
argument_list|)
block|,
name|dirty
argument_list|(
name|true
argument_list|)
block|,
name|blockFragmentUpdates
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|QTextTablePrivate
argument_list|()
block|;
specifier|static
name|QTextTable
operator|*
name|createTable
argument_list|(
argument|QTextDocumentPrivate *
argument_list|,
argument|int pos
argument_list|,
argument|int rows
argument_list|,
argument|int cols
argument_list|,
argument|const QTextTableFormat&tableFormat
argument_list|)
block|;
name|void
name|fragmentAdded
argument_list|(
argument|QChar type
argument_list|,
argument|uint fragment
argument_list|)
block|;
name|void
name|fragmentRemoved
argument_list|(
argument|QChar type
argument_list|,
argument|uint fragment
argument_list|)
block|;
name|void
name|update
argument_list|()
specifier|const
block|;
name|int
name|findCellIndex
argument_list|(
argument|int fragment
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|int
operator|>
name|cells
block|;
comment|// symmetric to cells array and maps to indecs in grid,
comment|// used for fast-lookup for row/column by fragment
name|mutable
name|QVector
operator|<
name|int
operator|>
name|cellIndices
block|;
name|mutable
name|int
operator|*
name|grid
block|;
name|mutable
name|int
name|nRows
block|;
name|mutable
name|int
name|nCols
block|;
name|mutable
name|bool
name|dirty
block|;
name|bool
name|blockFragmentUpdates
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
comment|// QTEXTTABLE_P_H
end_comment
end_unit
