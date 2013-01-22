begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QModelIndex>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
DECL|function|QT_FORWARD_DECLARE_CLASS
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QStringListModel
argument_list|)
end_macro
begin_decl_stmt
name|class
name|QModelListener
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QModelListener
argument_list|(
argument|QStringList  *pAboutToStringlist
argument_list|,
argument|QStringList  *pExpectedStringlist
argument_list|,
argument|QStringListModel  *pModel
argument_list|)
block|{
name|setTestData
argument_list|(
name|pAboutToStringlist
argument_list|,
name|pExpectedStringlist
argument_list|,
name|pModel
argument_list|)
block|;     }
name|virtual
operator|~
name|QModelListener
argument_list|()
block|{  }
name|void
name|setTestData
argument_list|(
argument|QStringList  *pAboutToStringlist
argument_list|,
argument|QStringList  *pExpectedStringlist
argument_list|,
argument|QStringListModel  *pModel
argument_list|)
block|{
name|m_pAboutToStringlist
operator|=
name|pAboutToStringlist
block|;
name|m_pExpectedStringlist
operator|=
name|pExpectedStringlist
block|;
name|m_pModel
operator|=
name|pModel
block|;     }
name|private
operator|:
name|QStringList
operator|*
name|m_pAboutToStringlist
block|;
name|QStringList
operator|*
name|m_pExpectedStringlist
block|;
name|QStringListModel
operator|*
name|m_pModel
block|;
name|public
name|slots
operator|:
name|void
name|rowsAboutToBeRemovedOrInserted
argument_list|(
argument|const QModelIndex& parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|void
name|rowsRemovedOrInserted
argument_list|(
argument|const QModelIndex& parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
end_unit
