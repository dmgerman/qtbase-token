begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 ThorbjÃ¸rn Lund Martsum - tmartsum[at]gmail.com ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_decl_stmt
DECL|variable|columnCount
specifier|const
name|int
name|columnCount
init|=
literal|1500
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
literal|2
argument_list|,
name|columnCount
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
literal|1200
argument_list|,
literal|400
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
name|columnCount
operator|+
literal|2
argument_list|)
expr_stmt|;
name|QFont
name|f
init|=
name|QApplication
operator|::
name|font
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|u
init|=
literal|0
init|;
name|u
operator|<
name|columnCount
condition|;
operator|++
name|u
control|)
block|{
name|int
name|size
init|=
literal|10
operator|+
operator|(
name|u
operator|%
literal|63
operator|)
decl_stmt|;
name|f
operator|.
name|setPixelSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|QString
name|col
decl_stmt|;
if|if
condition|(
name|u
operator|%
literal|50
operator|<
literal|25
condition|)
name|col
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
else|else
name|col
operator|=
name|QChar
operator|::
name|fromLatin1
argument_list|(
literal|'A'
operator|+
operator|(
name|u
operator|%
literal|25
operator|)
argument_list|)
expr_stmt|;
name|int
name|v
init|=
name|columnCount
operator|-
name|u
operator|-
literal|1
decl_stmt|;
name|model
operator|.
name|setData
argument_list|(
name|model
operator|.
name|index
argument_list|(
literal|0
argument_list|,
name|u
argument_list|)
argument_list|,
name|col
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
literal|1
argument_list|,
name|v
argument_list|)
argument_list|,
name|col
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
literal|0
argument_list|,
name|u
argument_list|)
argument_list|,
name|f
argument_list|,
name|Qt
operator|::
name|FontRole
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
literal|1
argument_list|,
name|v
argument_list|)
argument_list|,
name|f
argument_list|,
name|Qt
operator|::
name|FontRole
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
for|for
control|(
name|int
name|u
init|=
literal|0
init|;
name|u
operator|<
name|columnCount
condition|;
operator|++
name|u
control|)
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|resizeSection
argument_list|(
name|u
argument_list|,
literal|60
argument_list|)
expr_stmt|;
comment|// Make last index in first row a bit special
name|f
operator|.
name|setPixelSize
argument_list|(
literal|96
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
literal|0
argument_list|,
name|columnCount
operator|-
literal|1
argument_list|)
argument_list|,
name|f
argument_list|,
name|Qt
operator|::
name|FontRole
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
literal|0
argument_list|,
name|columnCount
operator|-
literal|1
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"qI"
argument_list|)
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|resizeSection
argument_list|(
name|columnCount
operator|-
literal|1
argument_list|,
literal|140
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|verticalHeader
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
name|verticalHeader
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
name|spinPrecision
operator|->
name|setValue
argument_list|(
name|tableView
operator|->
name|verticalHeader
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
name|verticalHeader
argument_list|()
operator|->
name|setResizeContentsPrecision
argument_list|(
name|newval
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|resizeRowsToContents
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
file|"testtable2.moc"
end_include
end_unit
