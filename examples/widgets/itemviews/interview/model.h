begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MODEL_H
end_ifndef
begin_define
DECL|macro|MODEL_H
define|#
directive|define
name|MODEL_H
end_define
begin_include
include|#
directive|include
file|<QAbstractItemModel>
end_include
begin_include
include|#
directive|include
file|<QFileIconProvider>
end_include
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_decl_stmt
name|class
name|Model
range|:
name|public
name|QAbstractItemModel
block|{
name|Q_OBJECT
name|public
operator|:
name|Model
argument_list|(
argument|int rows
argument_list|,
argument|int columns
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|Model
argument_list|()
block|;
name|QModelIndex
name|index
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QModelIndex
name|parent
argument_list|(
argument|const QModelIndex&child
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasChildren
argument_list|(
argument|const QModelIndex&parent
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|ItemFlags
name|flags
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
expr|struct
name|Node
block|{
name|Node
argument_list|(
name|Node
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|parent
argument_list|(
name|parent
argument_list|)
block|,
name|children
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|Node
argument_list|()
block|{
name|delete
name|children
block|; }
name|Node
operator|*
name|parent
block|;
name|QVector
operator|<
name|Node
operator|>
operator|*
name|children
block|;     }
block|;
name|Node
operator|*
name|node
argument_list|(
argument|int row
argument_list|,
argument|Node *parent
argument_list|)
specifier|const
block|;
name|Node
operator|*
name|parent
argument_list|(
argument|Node *child
argument_list|)
specifier|const
block|;
name|int
name|row
argument_list|(
argument|Node *node
argument_list|)
specifier|const
block|;
name|QIcon
name|services
block|;
name|int
name|rc
block|;
name|int
name|cc
block|;
name|QVector
operator|<
name|Node
operator|>
operator|*
name|tree
block|;
name|QFileIconProvider
name|iconProvider
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MODEL_H
end_comment
end_unit
