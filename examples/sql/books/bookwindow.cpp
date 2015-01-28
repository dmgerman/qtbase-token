begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"bookwindow.h"
end_include
begin_include
include|#
directive|include
file|"bookdelegate.h"
end_include
begin_include
include|#
directive|include
file|"initdb.h"
end_include
begin_include
include|#
directive|include
file|<QtSql>
end_include
begin_constructor
DECL|function|BookWindow
name|BookWindow
operator|::
name|BookWindow
parameter_list|()
block|{
name|ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QSqlDatabase
operator|::
name|drivers
argument_list|()
operator|.
name|contains
argument_list|(
literal|"QSQLITE"
argument_list|)
condition|)
name|QMessageBox
operator|::
name|critical
argument_list|(
name|this
argument_list|,
literal|"Unable to load database"
argument_list|,
literal|"This demo needs the SQLITE driver"
argument_list|)
expr_stmt|;
comment|// initialize the database
name|QSqlError
name|err
init|=
name|initDb
argument_list|()
decl_stmt|;
if|if
condition|(
name|err
operator|.
name|type
argument_list|()
operator|!=
name|QSqlError
operator|::
name|NoError
condition|)
block|{
name|showError
argument_list|(
name|err
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Create the data model
name|model
operator|=
operator|new
name|QSqlRelationalTableModel
argument_list|(
name|ui
operator|.
name|bookTable
argument_list|)
expr_stmt|;
name|model
operator|->
name|setEditStrategy
argument_list|(
name|QSqlTableModel
operator|::
name|OnManualSubmit
argument_list|)
expr_stmt|;
name|model
operator|->
name|setTable
argument_list|(
literal|"books"
argument_list|)
expr_stmt|;
comment|// Remember the indexes of the columns
name|authorIdx
operator|=
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"author"
argument_list|)
expr_stmt|;
name|genreIdx
operator|=
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"genre"
argument_list|)
expr_stmt|;
comment|// Set the relations to the other database tables
name|model
operator|->
name|setRelation
argument_list|(
name|authorIdx
argument_list|,
name|QSqlRelation
argument_list|(
literal|"authors"
argument_list|,
literal|"id"
argument_list|,
literal|"name"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setRelation
argument_list|(
name|genreIdx
argument_list|,
name|QSqlRelation
argument_list|(
literal|"genres"
argument_list|,
literal|"id"
argument_list|,
literal|"name"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Set the localized header captions
name|model
operator|->
name|setHeaderData
argument_list|(
name|authorIdx
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Author Name"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
name|genreIdx
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Genre"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"title"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Title"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"year"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Year"
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHeaderData
argument_list|(
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"rating"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
name|tr
argument_list|(
literal|"Rating"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Populate the model
if|if
condition|(
operator|!
name|model
operator|->
name|select
argument_list|()
condition|)
block|{
name|showError
argument_list|(
name|model
operator|->
name|lastError
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Set the model and hide the ID column
name|ui
operator|.
name|bookTable
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|ui
operator|.
name|bookTable
operator|->
name|setItemDelegate
argument_list|(
operator|new
name|BookDelegate
argument_list|(
name|ui
operator|.
name|bookTable
argument_list|)
argument_list|)
expr_stmt|;
name|ui
operator|.
name|bookTable
operator|->
name|setColumnHidden
argument_list|(
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"id"
argument_list|)
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|ui
operator|.
name|bookTable
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|SingleSelection
argument_list|)
expr_stmt|;
comment|// Initialize the Author combo box
name|ui
operator|.
name|authorEdit
operator|->
name|setModel
argument_list|(
name|model
operator|->
name|relationModel
argument_list|(
name|authorIdx
argument_list|)
argument_list|)
expr_stmt|;
name|ui
operator|.
name|authorEdit
operator|->
name|setModelColumn
argument_list|(
name|model
operator|->
name|relationModel
argument_list|(
name|authorIdx
argument_list|)
operator|->
name|fieldIndex
argument_list|(
literal|"name"
argument_list|)
argument_list|)
expr_stmt|;
name|ui
operator|.
name|genreEdit
operator|->
name|setModel
argument_list|(
name|model
operator|->
name|relationModel
argument_list|(
name|genreIdx
argument_list|)
argument_list|)
expr_stmt|;
name|ui
operator|.
name|genreEdit
operator|->
name|setModelColumn
argument_list|(
name|model
operator|->
name|relationModel
argument_list|(
name|genreIdx
argument_list|)
operator|->
name|fieldIndex
argument_list|(
literal|"name"
argument_list|)
argument_list|)
expr_stmt|;
name|QDataWidgetMapper
modifier|*
name|mapper
init|=
operator|new
name|QDataWidgetMapper
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|mapper
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|setItemDelegate
argument_list|(
operator|new
name|BookDelegate
argument_list|(
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|addMapping
argument_list|(
name|ui
operator|.
name|titleEdit
argument_list|,
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"title"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|addMapping
argument_list|(
name|ui
operator|.
name|yearEdit
argument_list|,
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"year"
argument_list|)
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|addMapping
argument_list|(
name|ui
operator|.
name|authorEdit
argument_list|,
name|authorIdx
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|addMapping
argument_list|(
name|ui
operator|.
name|genreEdit
argument_list|,
name|genreIdx
argument_list|)
expr_stmt|;
name|mapper
operator|->
name|addMapping
argument_list|(
name|ui
operator|.
name|ratingEdit
argument_list|,
name|model
operator|->
name|fieldIndex
argument_list|(
literal|"rating"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|.
name|bookTable
operator|->
name|selectionModel
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|currentRowChanged
argument_list|(
name|QModelIndex
argument_list|,
name|QModelIndex
argument_list|)
argument_list|)
argument_list|,
name|mapper
argument_list|,
name|SLOT
argument_list|(
name|setCurrentModelIndex
argument_list|(
name|QModelIndex
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ui
operator|.
name|bookTable
operator|->
name|setCurrentIndex
argument_list|(
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|showError
name|void
name|BookWindow
operator|::
name|showError
parameter_list|(
specifier|const
name|QSqlError
modifier|&
name|err
parameter_list|)
block|{
name|QMessageBox
operator|::
name|critical
argument_list|(
name|this
argument_list|,
literal|"Unable to initialize Database"
argument_list|,
literal|"Error initializing database: "
operator|+
name|err
operator|.
name|text
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
