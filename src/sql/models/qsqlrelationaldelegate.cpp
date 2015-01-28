begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QSqlRelationalDelegate     \inmodule QtSql     \brief The QSqlRelationalDelegate class provides a delegate that is used to     display and edit data from a QSqlRelationalTableModel.      Unlike the default delegate, QSqlRelationalDelegate provides a     combobox for fields that are foreign keys into other tables. To     use the class, simply call QAbstractItemView::setItemDelegate()     on the view with an instance of QSqlRelationalDelegate:      \snippet relationaltablemodel/relationaltablemodel.cpp 4      The \l{relationaltablemodel}{Relational Table Model} example     (shown below) illustrates how to use QSqlRelationalDelegate in     conjunction with QSqlRelationalTableModel to provide tables with     foreign key support.      \image relationaltable.png      \sa QSqlRelationalTableModel, {Model/View Programming} */
comment|/*!     \fn QSqlRelationalDelegate::QSqlRelationalDelegate(QObject *parent)      Constructs a QSqlRelationalDelegate object with the given \a     parent. */
comment|/*!     \fn QSqlRelationalDelegate::~QSqlRelationalDelegate()      Destroys the QSqlRelationalDelegate object and frees any     allocated resources. */
comment|/*!     \fn QWidget *QSqlRelationalDelegate::createEditor(QWidget *parent,                                                       const QStyleOptionViewItem&option,                                                       const QModelIndex&index) const     \reimp */
comment|/*!     \fn void QSqlRelationalDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,                                                   const QModelIndex&index) const     \reimp */
name|QT_END_NAMESPACE
end_decl_stmt
end_unit
