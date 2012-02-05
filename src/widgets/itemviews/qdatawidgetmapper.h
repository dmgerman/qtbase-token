begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDATAWIDGETMAPPER_H
end_ifndef
begin_define
DECL|macro|QDATAWIDGETMAPPER_H
define|#
directive|define
name|QDATAWIDGETMAPPER_H
end_define
begin_include
include|#
directive|include
file|"QtCore/qobject.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATAWIDGETMAPPER
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractItemDelegate
name|class
name|QAbstractItemDelegate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractItemModel
name|class
name|QAbstractItemModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QModelIndex
name|class
name|QModelIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDataWidgetMapperPrivate
name|class
name|QDataWidgetMapperPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDataWidgetMapper
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|SubmitPolicy
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Orientation orientation READ orientation WRITE setOrientation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|SubmitPolicy submitPolicy READ submitPolicy WRITE setSubmitPolicy
argument_list|)
name|public
operator|:
name|QDataWidgetMapper
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QDataWidgetMapper
argument_list|()
block|;
name|void
name|setModel
argument_list|(
name|QAbstractItemModel
operator|*
name|model
argument_list|)
block|;
name|QAbstractItemModel
operator|*
name|model
argument_list|()
specifier|const
block|;
name|void
name|setItemDelegate
argument_list|(
name|QAbstractItemDelegate
operator|*
name|delegate
argument_list|)
block|;
name|QAbstractItemDelegate
operator|*
name|itemDelegate
argument_list|()
specifier|const
block|;
name|void
name|setRootIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|QModelIndex
name|rootIndex
argument_list|()
specifier|const
block|;
name|void
name|setOrientation
argument_list|(
argument|Qt::Orientation aOrientation
argument_list|)
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;      enum
name|SubmitPolicy
block|{
name|AutoSubmit
block|,
name|ManualSubmit
block|}
block|;
name|void
name|setSubmitPolicy
argument_list|(
argument|SubmitPolicy policy
argument_list|)
block|;
name|SubmitPolicy
name|submitPolicy
argument_list|()
specifier|const
block|;
name|void
name|addMapping
argument_list|(
argument|QWidget *widget
argument_list|,
argument|int section
argument_list|)
block|;
name|void
name|addMapping
argument_list|(
argument|QWidget *widget
argument_list|,
argument|int section
argument_list|,
argument|const QByteArray&propertyName
argument_list|)
block|;
name|void
name|removeMapping
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|int
name|mappedSection
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|QByteArray
name|mappedPropertyName
argument_list|(
argument|QWidget *widget
argument_list|)
specifier|const
block|;
name|QWidget
operator|*
name|mappedWidgetAt
argument_list|(
argument|int section
argument_list|)
specifier|const
block|;
name|void
name|clearMapping
argument_list|()
block|;
name|int
name|currentIndex
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|revert
argument_list|()
block|;
name|bool
name|submit
argument_list|()
block|;
name|void
name|toFirst
argument_list|()
block|;
name|void
name|toLast
argument_list|()
block|;
name|void
name|toNext
argument_list|()
block|;
name|void
name|toPrevious
argument_list|()
block|;
name|virtual
name|void
name|setCurrentIndex
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|setCurrentModelIndex
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|currentIndexChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDataWidgetMapper
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QDataWidgetMapper
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_dataChanged(const QModelIndex&, const QModelIndex&, const QSet<int>&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_commitData(QWidget *)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_closeEditor(QWidget *, QAbstractItemDelegate::EndEditHint)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_modelDestroyed()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATAWIDGETMAPPER
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
