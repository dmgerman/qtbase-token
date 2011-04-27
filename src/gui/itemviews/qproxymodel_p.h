begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPROXYMODEL_P_H
end_ifndef
begin_define
DECL|macro|QPROXYMODEL_P_H
define|#
directive|define
name|QPROXYMODEL_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of QAbstractItemModel*.  This header file may change from version
end_comment
begin_comment
comment|// to version without notice, or even be removed.
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
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qabstractitemmodel.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractitemmodel_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROXYMODEL
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QEmptyModel
range|:
name|public
name|QAbstractItemModel
block|{
name|public
operator|:
name|explicit
name|QEmptyModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QAbstractItemModel
argument_list|(
argument|parent
argument_list|)
block|{}
name|QModelIndex
name|index
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|,
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&
argument_list|,
argument|int
argument_list|)
specifier|const
block|{
return|return
name|QVariant
argument_list|()
return|;
block|}
expr|}
block|;
name|class
name|QProxyModelPrivate
operator|:
name|private
name|QAbstractItemModelPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QProxyModel
argument_list|)
name|public
operator|:
name|void
name|_q_sourceDataChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|tl
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|br
argument_list|)
block|;
name|void
name|_q_sourceRowsAboutToBeInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|_q_sourceRowsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|_q_sourceRowsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|_q_sourceRowsRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|_q_sourceColumnsAboutToBeInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|_q_sourceColumnsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|_q_sourceColumnsAboutToBeRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|void
name|_q_sourceColumnsRemoved
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int first
argument_list|,
argument|int last
argument_list|)
block|;
name|QProxyModelPrivate
argument_list|()
operator|:
name|QAbstractItemModelPrivate
argument_list|()
block|,
name|model
argument_list|(
literal|0
argument_list|)
block|{}
name|QAbstractItemModel
operator|*
name|model
block|;
name|QEmptyModel
name|empty
block|; }
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROXYMODEL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPROXYMODEL_P_H
end_comment
end_unit
