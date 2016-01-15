begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
