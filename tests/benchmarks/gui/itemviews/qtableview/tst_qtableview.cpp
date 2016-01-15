begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QTableView>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QStandardItemModel>
end_include
begin_class
DECL|class|QtTestTableModel
class|class
name|QtTestTableModel
super|:
specifier|public
name|QAbstractTableModel
block|{
name|Q_OBJECT
public|public:
DECL|function|QtTestTableModel
name|QtTestTableModel
parameter_list|(
name|int
name|rows
init|=
literal|0
parameter_list|,
name|int
name|columns
init|=
literal|0
parameter_list|,
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QAbstractTableModel
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|row_count
argument_list|(
name|rows
argument_list|)
member_init_list|,
name|column_count
argument_list|(
name|columns
argument_list|)
block|{}
DECL|function|rowCount
name|int
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
init|=
name|QModelIndex
argument_list|()
parameter_list|)
specifier|const
block|{
return|return
name|row_count
return|;
block|}
DECL|function|columnCount
name|int
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
init|=
name|QModelIndex
argument_list|()
parameter_list|)
specifier|const
block|{
return|return
name|column_count
return|;
block|}
DECL|function|isEditable
name|bool
name|isEditable
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
literal|true
return|;
block|}
DECL|function|data
name|QVariant
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|idx
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|idx
operator|.
name|isValid
argument_list|()
operator|||
name|idx
operator|.
name|row
argument_list|()
operator|>=
name|row_count
operator|||
name|idx
operator|.
name|column
argument_list|()
operator|>=
name|column_count
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Invalid modelIndex [%d,%d,%p]"
operator|<<
name|idx
expr_stmt|;
return|return
name|QVariant
argument_list|()
return|;
block|}
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
operator|||
name|role
operator|==
name|Qt
operator|::
name|EditRole
condition|)
return|return
name|QString
argument_list|(
literal|"[%1,%2,%3]"
argument_list|)
operator|.
name|arg
argument_list|(
name|idx
operator|.
name|row
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|idx
operator|.
name|column
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
literal|0
argument_list|)
return|;
return|return
name|QVariant
argument_list|()
return|;
block|}
DECL|function|insertRows
name|bool
name|insertRows
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
init|=
name|QModelIndex
argument_list|()
parameter_list|)
block|{
if|if
condition|(
name|start
argument_list|<
literal|0
operator|||
name|start
argument_list|>
name|row_count
condition|)
return|return
literal|false
return|;
name|beginInsertRows
argument_list|(
name|parent
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|count
operator|-
literal|1
argument_list|)
expr_stmt|;
name|row_count
operator|+=
name|count
expr_stmt|;
name|endInsertRows
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|function|removeRows
name|bool
name|removeRows
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
init|=
name|QModelIndex
argument_list|()
parameter_list|)
block|{
if|if
condition|(
name|start
operator|<
literal|0
operator|||
name|start
operator|>=
name|row_count
operator|||
name|row_count
operator|<
name|count
condition|)
return|return
literal|false
return|;
name|beginRemoveRows
argument_list|(
name|parent
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|count
operator|-
literal|1
argument_list|)
expr_stmt|;
name|row_count
operator|-=
name|count
expr_stmt|;
name|endRemoveRows
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|function|insertColumns
name|bool
name|insertColumns
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
init|=
name|QModelIndex
argument_list|()
parameter_list|)
block|{
if|if
condition|(
name|start
argument_list|<
literal|0
operator|||
name|start
argument_list|>
name|column_count
condition|)
return|return
literal|false
return|;
name|beginInsertColumns
argument_list|(
name|parent
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|count
operator|-
literal|1
argument_list|)
expr_stmt|;
name|column_count
operator|+=
name|count
expr_stmt|;
name|endInsertColumns
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|function|removeColumns
name|bool
name|removeColumns
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
init|=
name|QModelIndex
argument_list|()
parameter_list|)
block|{
if|if
condition|(
name|start
operator|<
literal|0
operator|||
name|start
operator|>=
name|column_count
operator|||
name|column_count
operator|<
name|count
condition|)
return|return
literal|false
return|;
name|beginRemoveColumns
argument_list|(
name|parent
argument_list|,
name|start
argument_list|,
name|start
operator|+
name|count
operator|-
literal|1
argument_list|)
expr_stmt|;
name|column_count
operator|-=
name|count
expr_stmt|;
name|endRemoveColumns
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|member|row_count
name|int
name|row_count
decl_stmt|;
DECL|member|column_count
name|int
name|column_count
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|tst_QTableView
class|class
name|tst_QTableView
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QTableView
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QTableView
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|spanInit
parameter_list|()
function_decl|;
name|void
name|spanDraw
parameter_list|()
function_decl|;
name|void
name|spanSelectColumn
parameter_list|()
function_decl|;
name|void
name|spanSelectAll
parameter_list|()
function_decl|;
name|void
name|rowInsertion_data
parameter_list|()
function_decl|;
name|void
name|rowInsertion
parameter_list|()
function_decl|;
name|void
name|rowRemoval_data
parameter_list|()
function_decl|;
name|void
name|rowRemoval
parameter_list|()
function_decl|;
name|void
name|columnInsertion_data
parameter_list|()
function_decl|;
name|void
name|columnInsertion
parameter_list|()
function_decl|;
name|void
name|columnRemoval_data
parameter_list|()
function_decl|;
name|void
name|columnRemoval
parameter_list|()
function_decl|;
name|void
name|sizeHintForColumnWhenHidden
parameter_list|()
function_decl|;
private|private:
specifier|static
specifier|inline
name|void
name|spanInit_helper
parameter_list|(
name|QTableView
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QTableView
name|tst_QTableView
operator|::
name|tst_QTableView
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QTableView
name|tst_QTableView
operator|::
name|~
name|tst_QTableView
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QTableView
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QTableView
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|spanInit_helper
name|void
name|tst_QTableView
operator|::
name|spanInit_helper
parameter_list|(
name|QTableView
modifier|*
name|view
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|40
condition|;
name|i
operator|++
control|)
block|{
name|view
operator|->
name|setSpan
argument_list|(
literal|1
operator|+
name|i
operator|%
literal|2
argument_list|,
literal|1
operator|+
literal|4
operator|*
name|i
argument_list|,
literal|1
operator|+
name|i
operator|%
literal|3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|40
condition|;
name|i
operator|++
control|)
block|{
name|view
operator|->
name|setSpan
argument_list|(
literal|6
operator|+
name|i
operator|*
literal|7
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
literal|50
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|spanInit
name|void
name|tst_QTableView
operator|::
name|spanInit
parameter_list|()
block|{
name|QtTestTableModel
name|model
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
decl_stmt|;
name|QTableView
name|v
decl_stmt|;
name|v
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|spanInit_helper
argument_list|(
operator|&
name|v
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|spanDraw
name|void
name|tst_QTableView
operator|::
name|spanDraw
parameter_list|()
block|{
name|QtTestTableModel
name|model
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
decl_stmt|;
name|QTableView
name|v
decl_stmt|;
name|v
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|spanInit_helper
argument_list|(
operator|&
name|v
argument_list|)
expr_stmt|;
name|v
operator|.
name|show
argument_list|()
expr_stmt|;
name|v
operator|.
name|resize
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|QImage
name|image
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|image
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|v
operator|.
name|render
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|spanSelectAll
name|void
name|tst_QTableView
operator|::
name|spanSelectAll
parameter_list|()
block|{
name|QtTestTableModel
name|model
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
decl_stmt|;
name|QTableView
name|v
decl_stmt|;
name|v
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|spanInit_helper
argument_list|(
operator|&
name|v
argument_list|)
expr_stmt|;
name|v
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|v
operator|.
name|selectAll
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|spanSelectColumn
name|void
name|tst_QTableView
operator|::
name|spanSelectColumn
parameter_list|()
block|{
name|QtTestTableModel
name|model
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
decl_stmt|;
name|QTableView
name|v
decl_stmt|;
name|v
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|spanInit_helper
argument_list|(
operator|&
name|v
argument_list|)
expr_stmt|;
name|v
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|v
operator|.
name|selectColumn
argument_list|(
literal|22
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_typedef
DECL|typedef|SpanList
typedef|typedef
name|QVector
argument_list|<
name|QRect
argument_list|>
name|SpanList
typedef|;
end_typedef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|SpanList
argument_list|)
end_macro
begin_function
DECL|function|spansData
name|void
name|spansData
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|SpanList
argument_list|>
argument_list|(
literal|"spans"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Without spans"
argument_list|)
operator|<<
name|SpanList
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"With spans"
argument_list|)
operator|<<
operator|(
name|SpanList
argument_list|()
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|2
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|5
argument_list|,
literal|6
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|6
argument_list|,
literal|7
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rowInsertion_data
name|void
name|tst_QTableView
operator|::
name|rowInsertion_data
parameter_list|()
block|{
name|spansData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rowInsertion
name|void
name|tst_QTableView
operator|::
name|rowInsertion
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|SpanList
argument_list|,
name|spans
argument_list|)
expr_stmt|;
name|QtTestTableModel
name|model
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QTableView
name|view
decl_stmt|;
name|view
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QRect
name|span
decl|,
name|spans
control|)
name|view
operator|.
name|setSpan
argument_list|(
name|span
operator|.
name|top
argument_list|()
argument_list|,
name|span
operator|.
name|left
argument_list|()
argument_list|,
name|span
operator|.
name|height
argument_list|()
argument_list|,
name|span
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QBENCHMARK_ONCE
block|{
name|view
operator|.
name|model
argument_list|()
operator|->
name|insertRows
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|view
operator|.
name|model
argument_list|()
operator|->
name|insertRows
argument_list|(
literal|5
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|view
operator|.
name|model
argument_list|()
operator|->
name|insertRows
argument_list|(
literal|8
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|view
operator|.
name|model
argument_list|()
operator|->
name|insertRows
argument_list|(
literal|12
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rowRemoval_data
name|void
name|tst_QTableView
operator|::
name|rowRemoval_data
parameter_list|()
block|{
name|spansData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rowRemoval
name|void
name|tst_QTableView
operator|::
name|rowRemoval
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|SpanList
argument_list|,
name|spans
argument_list|)
expr_stmt|;
name|QtTestTableModel
name|model
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QTableView
name|view
decl_stmt|;
name|view
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QRect
name|span
decl|,
name|spans
control|)
name|view
operator|.
name|setSpan
argument_list|(
name|span
operator|.
name|top
argument_list|()
argument_list|,
name|span
operator|.
name|left
argument_list|()
argument_list|,
name|span
operator|.
name|height
argument_list|()
argument_list|,
name|span
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QBENCHMARK_ONCE
block|{
name|view
operator|.
name|model
argument_list|()
operator|->
name|removeRows
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|columnInsertion_data
name|void
name|tst_QTableView
operator|::
name|columnInsertion_data
parameter_list|()
block|{
name|spansData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|columnInsertion
name|void
name|tst_QTableView
operator|::
name|columnInsertion
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|SpanList
argument_list|,
name|spans
argument_list|)
expr_stmt|;
name|QtTestTableModel
name|model
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QTableView
name|view
decl_stmt|;
name|view
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
comment|// Same set as for rowInsertion, just swapping columns and rows.
foreach|foreach
control|(
name|QRect
name|span
decl|,
name|spans
control|)
name|view
operator|.
name|setSpan
argument_list|(
name|span
operator|.
name|left
argument_list|()
argument_list|,
name|span
operator|.
name|top
argument_list|()
argument_list|,
name|span
operator|.
name|width
argument_list|()
argument_list|,
name|span
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QBENCHMARK_ONCE
block|{
name|view
operator|.
name|model
argument_list|()
operator|->
name|insertColumns
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|view
operator|.
name|model
argument_list|()
operator|->
name|insertColumns
argument_list|(
literal|5
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|view
operator|.
name|model
argument_list|()
operator|->
name|insertColumns
argument_list|(
literal|8
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|view
operator|.
name|model
argument_list|()
operator|->
name|insertColumns
argument_list|(
literal|12
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|columnRemoval_data
name|void
name|tst_QTableView
operator|::
name|columnRemoval_data
parameter_list|()
block|{
name|spansData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|columnRemoval
name|void
name|tst_QTableView
operator|::
name|columnRemoval
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|SpanList
argument_list|,
name|spans
argument_list|)
expr_stmt|;
name|QtTestTableModel
name|model
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QTableView
name|view
decl_stmt|;
name|view
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
comment|// Same set as for rowRemoval, just swapping columns and rows.
foreach|foreach
control|(
name|QRect
name|span
decl|,
name|spans
control|)
name|view
operator|.
name|setSpan
argument_list|(
name|span
operator|.
name|left
argument_list|()
argument_list|,
name|span
operator|.
name|top
argument_list|()
argument_list|,
name|span
operator|.
name|width
argument_list|()
argument_list|,
name|span
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QBENCHMARK_ONCE
block|{
name|view
operator|.
name|model
argument_list|()
operator|->
name|removeColumns
argument_list|(
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|sizeHintForColumnWhenHidden
name|void
name|tst_QTableView
operator|::
name|sizeHintForColumnWhenHidden
parameter_list|()
block|{
name|QTableView
name|view
decl_stmt|;
name|QStandardItemModel
name|model
argument_list|(
literal|12500
argument_list|,
literal|6
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|r
init|=
literal|0
init|;
name|r
operator|<
name|model
operator|.
name|rowCount
argument_list|()
condition|;
operator|++
name|r
control|)
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|model
operator|.
name|columnCount
argument_list|()
condition|;
operator|++
name|c
control|)
block|{
name|QStandardItem
modifier|*
name|item
init|=
operator|new
name|QStandardItem
argument_list|(
name|QString
argument_list|(
literal|"row %0, column %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|r
argument_list|)
operator|.
name|arg
argument_list|(
name|c
argument_list|)
argument_list|)
decl_stmt|;
name|model
operator|.
name|setItem
argument_list|(
name|r
argument_list|,
name|c
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
name|view
operator|.
name|horizontalHeader
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
name|QHeaderView
operator|::
name|ResizeToContents
argument_list|)
expr_stmt|;
name|view
operator|.
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|QBENCHMARK_ONCE
block|{
name|view
operator|.
name|horizontalHeader
argument_list|()
operator|->
name|resizeSection
argument_list|(
literal|0
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|// this force resizeSections - on a hidden view.
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QTableView
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qtableview.moc"
end_include
end_unit
