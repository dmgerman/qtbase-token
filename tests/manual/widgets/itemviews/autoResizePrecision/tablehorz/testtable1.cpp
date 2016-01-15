begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 ThorbjÃ¸rn Lund Martsum - tmartsum[at]gmail.com ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_decl_stmt
DECL|variable|rowCount
specifier|const
name|int
name|rowCount
init|=
literal|2000
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|TableDialog
class|class
name|TableDialog
super|:
specifier|public
name|QDialog
block|{
name|Q_OBJECT
public|public:
DECL|function|TableDialog
name|TableDialog
parameter_list|()
member_init_list|:
name|model
argument_list|(
name|rowCount
argument_list|,
literal|3
argument_list|)
block|{
name|create
argument_list|()
expr_stmt|;
block|}
DECL|function|create
name|void
name|create
parameter_list|()
block|{
name|resize
argument_list|(
literal|1000
argument_list|,
literal|233
argument_list|)
expr_stmt|;
name|gridLayout
operator|=
operator|new
name|QGridLayout
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|tableView
operator|=
operator|new
name|QTableView
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|tableView
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|spinPrecision
operator|=
operator|new
name|QSpinBox
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addWidget
argument_list|(
name|spinPrecision
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|verticalSpacer
operator|=
operator|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|gridLayout
operator|->
name|addItem
argument_list|(
name|verticalSpacer
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QString
name|ii
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"ii"
argument_list|)
decl_stmt|;
name|QStringList
name|is
decl_stmt|;
name|spinPrecision
operator|->
name|setMinimum
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|spinPrecision
operator|->
name|setMaximum
argument_list|(
name|rowCount
operator|+
literal|2
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|u
init|=
literal|0
init|;
name|u
operator|<
name|rowCount
condition|;
operator|++
name|u
control|)
block|{
if|if
condition|(
name|u
operator|%
literal|25
operator|==
literal|0
condition|)
name|ii
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"i"
argument_list|)
expr_stmt|;
else|else
name|ii
index|[
name|ii
operator|.
name|length
argument_list|()
operator|-
literal|1
index|]
operator|=
name|QChar
operator|::
name|fromLatin1
argument_list|(
literal|'a'
operator|+
operator|(
name|u
operator|%
literal|25
operator|)
argument_list|)
expr_stmt|;
name|ii
index|[
name|ii
operator|.
name|length
argument_list|()
operator|-
literal|2
index|]
operator|=
name|QChar
operator|::
name|fromLatin1
argument_list|(
literal|'i'
argument_list|)
expr_stmt|;
name|is
operator|.
name|append
argument_list|(
name|ii
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|u
init|=
literal|0
init|;
name|u
operator|<
name|rowCount
condition|;
operator|++
name|u
control|)
block|{
name|QString
name|col1
decl_stmt|;
name|col1
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Row: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|u
argument_list|)
expr_stmt|;
name|model
operator|.
name|setData
argument_list|(
name|model
operator|.
name|index
argument_list|(
name|u
argument_list|,
literal|0
argument_list|)
argument_list|,
name|col1
argument_list|)
expr_stmt|;
name|model
operator|.
name|setData
argument_list|(
name|model
operator|.
name|index
argument_list|(
name|u
argument_list|,
literal|1
argument_list|)
argument_list|,
name|is
index|[
name|u
index|]
argument_list|)
expr_stmt|;
name|model
operator|.
name|setData
argument_list|(
name|model
operator|.
name|index
argument_list|(
name|u
argument_list|,
literal|2
argument_list|)
argument_list|,
name|is
index|[
name|rowCount
operator|-
name|u
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
name|tableView
operator|->
name|setModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|0
argument_list|,
name|QHeaderView
operator|::
name|ResizeToContents
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|1
argument_list|,
name|QHeaderView
operator|::
name|ResizeToContents
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setSectionResizeMode
argument_list|(
literal|2
argument_list|,
name|QHeaderView
operator|::
name|ResizeToContents
argument_list|)
expr_stmt|;
name|spinPrecision
operator|->
name|setValue
argument_list|(
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|resizeContentsPrecision
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|spinPrecision
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotValueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
protected|protected
name|slots
protected|:
name|void
name|slotValueChanged
parameter_list|(
name|int
name|newval
parameter_list|)
function_decl|;
protected|protected:
DECL|member|gridLayout
name|QGridLayout
modifier|*
name|gridLayout
decl_stmt|;
DECL|member|tableView
name|QTableView
modifier|*
name|tableView
decl_stmt|;
DECL|member|spinPrecision
name|QSpinBox
modifier|*
name|spinPrecision
decl_stmt|;
DECL|member|verticalSpacer
name|QSpacerItem
modifier|*
name|verticalSpacer
decl_stmt|;
DECL|member|model
name|QStandardItemModel
name|model
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|slotValueChanged
name|void
name|TableDialog
operator|::
name|slotValueChanged
parameter_list|(
name|int
name|newval
parameter_list|)
block|{
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setResizeContentsPrecision
argument_list|(
name|newval
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|resizeColumnsToContents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|TableDialog
name|d1
decl_stmt|;
name|d1
operator|.
name|show
argument_list|()
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"testtable1.moc"
end_include
end_unit
