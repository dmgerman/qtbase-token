begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SPREADSHEETITEM_H
end_ifndef
begin_define
DECL|macro|SPREADSHEETITEM_H
define|#
directive|define
name|SPREADSHEETITEM_H
end_define
begin_include
include|#
directive|include
file|"spreadsheet.h"
end_include
begin_include
include|#
directive|include
file|<QTableWidgetItem>
end_include
begin_decl_stmt
name|class
name|SpreadSheetItem
range|:
name|public
name|QTableWidgetItem
block|{
name|public
operator|:
name|SpreadSheetItem
argument_list|()
block|;
name|SpreadSheetItem
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QTableWidgetItem
operator|*
name|clone
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|data
argument_list|(
argument|int role
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setData
argument_list|(
argument|int role
argument_list|,
argument|const QVariant&value
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|display
argument_list|()
specifier|const
block|;
specifier|inline
name|QString
name|formula
argument_list|()
specifier|const
block|{
return|return
name|QTableWidgetItem
operator|::
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
specifier|static
name|QVariant
name|computeFormula
argument_list|(
specifier|const
name|QString
operator|&
name|formula
argument_list|,
specifier|const
name|QTableWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QTableWidgetItem
operator|*
name|self
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|mutable
name|bool
name|isResolving
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SPREADSHEETITEM_H
end_comment
end_unit
