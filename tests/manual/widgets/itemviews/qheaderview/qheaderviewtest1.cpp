begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 ThorbjÃ¸rn Lund Martsum - tmartsum[at]gmail.com ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_struct
DECL|struct|ManualTask
struct|struct
name|ManualTask
block|{
DECL|member|title
specifier|const
name|char
modifier|*
name|title
decl_stmt|;
DECL|member|instructions
specifier|const
name|char
modifier|*
name|instructions
decl_stmt|;
DECL|member|sectionsMovable
name|unsigned
name|sectionsMovable
range|:
literal|1
decl_stmt|;
DECL|member|selectionMode
name|unsigned
name|selectionMode
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|tasks
name|ManualTask
name|tasks
index|[]
init|=
block|{
block|{
name|QT_TR_NOOP
argument_list|(
literal|"0. Default"
argument_list|)
block|,
literal|"Please provide instructions"
block|,
literal|true
block|,
name|QAbstractItemView
operator|::
name|SingleSelection
block|}
block|,
block|{
name|QT_TR_NOOP
argument_list|(
literal|"1. Autoscroll"
argument_list|)
block|,
literal|"<ol>"
literal|"<li>Press and hold on section 9 of vertical header.<br/>"
literal|"<em>(all cells in the row will be selected)</em>"
literal|"</li>"
literal|"<li>Extend the selection by moving the mouse down.<br/>"
literal|"<em>(selection will extend to the next rows)</em>"
literal|"</li>"
literal|"<li>Continue to move the mouse down and outside the window geometry.<br/>"
literal|"<em>(The view should scroll automatically and the selection should still extend)</em>"
literal|"</li>"
literal|"<li>While still holding the button, do the same in the opposite direction, i.e. move mouse up and outside the window geometry.<br/>"
literal|"<em>(Verify that the view scrolls automatically and the selection changes)</em>"
literal|"</li>"
literal|"<li>Verify that it works in the other dimension, i.e Press and hold section 9 of the horizontal header.<br/>"
literal|"<em>All cells in the column will be selected</em>"
literal|"</li>"
literal|"<li>Extend the selection by moving the mouse to the far right and outside the window geometry.<br/>"
literal|"<em>(selection will extend to the next columns)</em>"
literal|"</li>"
literal|"<li>Verify that it works in the opposite direction (i.e. move mouse to the left of the window geometry).<br/>"
literal|"<em>(Verify that the view scrolls automatically and the selection changes)</em>"
literal|"</li>"
literal|"</ol>"
block|,
literal|false
block|,
name|QAbstractItemView
operator|::
name|ExtendedSelection
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|Window
class|class
name|Window
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|Window
name|Window
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|ckMovable
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|tableView
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|cbSelectionMode
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_taskInstructions
argument_list|(
literal|0
argument_list|)
block|{
name|m_taskInstructions
operator|=
operator|new
name|QLabel
argument_list|()
expr_stmt|;
if|if
condition|(
sizeof|sizeof
argument_list|(
name|tasks
argument_list|)
operator|>
literal|0
condition|)
name|m_taskInstructions
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
name|tasks
index|[
literal|0
index|]
operator|.
name|instructions
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|vbox
operator|->
name|addLayout
argument_list|(
name|setupComboBox
argument_list|()
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|setupGroupBox
argument_list|()
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|setupTableView
argument_list|()
argument_list|)
expr_stmt|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|m_taskInstructions
argument_list|)
expr_stmt|;
block|}
DECL|function|updateControls
name|void
name|updateControls
parameter_list|()
block|{
name|ckMovable
operator|->
name|setChecked
argument_list|(
name|tableView
operator|->
name|verticalHeader
argument_list|()
operator|->
name|sectionsMovable
argument_list|()
argument_list|)
expr_stmt|;
name|QAbstractItemView
operator|::
name|SelectionMode
name|sMode
init|=
name|tableView
operator|->
name|selectionMode
argument_list|()
decl_stmt|;
name|cbSelectionMode
operator|->
name|setCurrentIndex
argument_list|(
operator|(
name|int
operator|)
name|sMode
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|function|setupComboBox
name|QFormLayout
modifier|*
name|setupComboBox
parameter_list|()
block|{
name|QComboBox
modifier|*
name|combo
init|=
operator|new
name|QComboBox
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|tasks
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|tasks
index|[
literal|0
index|]
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|combo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
name|tasks
index|[
name|i
index|]
operator|.
name|title
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
name|combo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|on_taskCombo_currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QFormLayout
modifier|*
name|form
init|=
operator|new
name|QFormLayout
decl_stmt|;
name|form
operator|->
name|addRow
argument_list|(
name|tr
argument_list|(
literal|"Choose task:"
argument_list|)
argument_list|,
name|combo
argument_list|)
expr_stmt|;
return|return
name|form
return|;
block|}
DECL|function|setupGroupBox
name|QGroupBox
modifier|*
name|setupGroupBox
parameter_list|()
block|{
name|QGroupBox
modifier|*
name|grp
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Properties"
argument_list|)
argument_list|)
decl_stmt|;
name|QFormLayout
modifier|*
name|form
init|=
operator|new
name|QFormLayout
decl_stmt|;
name|grp
operator|->
name|setLayout
argument_list|(
name|form
argument_list|)
expr_stmt|;
name|ckMovable
operator|=
operator|new
name|QCheckBox
expr_stmt|;
name|ckMovable
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"ckMovable"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ckMovable
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|on_ckMovable_toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|form
operator|->
name|addRow
argument_list|(
name|tr
argument_list|(
literal|"SectionsMovable"
argument_list|)
argument_list|,
name|ckMovable
argument_list|)
expr_stmt|;
name|cbSelectionMode
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|cbSelectionMode
operator|->
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"cbSelectionMode"
argument_list|)
argument_list|)
expr_stmt|;
name|cbSelectionMode
operator|->
name|addItems
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"NoSelection"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"SingleSelection"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"MultiSelection"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"ExtendedSelection"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"ContiguousSelection"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cbSelectionMode
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|on_cbSelectionMode_currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|form
operator|->
name|addRow
argument_list|(
name|tr
argument_list|(
literal|"SelectionMode"
argument_list|)
argument_list|,
name|cbSelectionMode
argument_list|)
expr_stmt|;
return|return
name|grp
return|;
block|}
DECL|function|setupTableView
name|QTableView
modifier|*
name|setupTableView
parameter_list|()
block|{
name|tableView
operator|=
operator|new
name|QTableView
expr_stmt|;
specifier|const
name|int
name|rowCount
init|=
literal|200
decl_stmt|;
name|m
operator|.
name|setRowCount
argument_list|(
name|rowCount
argument_list|)
expr_stmt|;
name|m
operator|.
name|setColumnCount
argument_list|(
literal|250
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|setSelectionMode
argument_list|(
name|QAbstractItemView
operator|::
name|SingleSelection
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|setModel
argument_list|(
operator|&
name|m
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|verticalHeader
argument_list|()
operator|->
name|swapSections
argument_list|(
name|rowCount
operator|-
literal|1
argument_list|,
literal|5
argument_list|)
expr_stmt|;
return|return
name|tableView
return|;
block|}
private|private
name|Q_SLOTS
private|:
DECL|function|on_ckMovable_toggled
name|void
name|on_ckMovable_toggled
parameter_list|(
name|bool
name|arg
parameter_list|)
block|{
name|tableView
operator|->
name|verticalHeader
argument_list|()
operator|->
name|setSectionsMovable
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|tableView
operator|->
name|horizontalHeader
argument_list|()
operator|->
name|setSectionsMovable
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
DECL|function|on_cbSelectionMode_currentIndexChanged
name|void
name|on_cbSelectionMode_currentIndexChanged
parameter_list|(
name|int
name|idx
parameter_list|)
block|{
name|tableView
operator|->
name|setSelectionMode
argument_list|(
operator|(
name|QAbstractItemView
operator|::
name|SelectionMode
operator|)
name|idx
argument_list|)
expr_stmt|;
block|}
DECL|function|on_taskCombo_currentIndexChanged
name|void
name|on_taskCombo_currentIndexChanged
parameter_list|(
name|int
name|idx
parameter_list|)
block|{
name|ManualTask
modifier|&
name|task
init|=
name|tasks
index|[
name|idx
index|]
decl_stmt|;
name|m_taskInstructions
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
name|task
operator|.
name|instructions
argument_list|)
argument_list|)
expr_stmt|;
name|ckMovable
operator|->
name|setChecked
argument_list|(
name|task
operator|.
name|sectionsMovable
argument_list|)
expr_stmt|;
name|cbSelectionMode
operator|->
name|setCurrentIndex
argument_list|(
operator|(
name|QAbstractItemView
operator|::
name|SelectionMode
operator|)
name|task
operator|.
name|selectionMode
argument_list|)
expr_stmt|;
block|}
public|public:
DECL|member|ckMovable
name|QCheckBox
modifier|*
name|ckMovable
decl_stmt|;
DECL|member|tableView
name|QTableView
modifier|*
name|tableView
decl_stmt|;
DECL|member|m
name|QStandardItemModel
name|m
decl_stmt|;
DECL|member|cbSelectionMode
name|QComboBox
modifier|*
name|cbSelectionMode
decl_stmt|;
DECL|member|m_taskInstructions
name|QLabel
modifier|*
name|m_taskInstructions
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|SomeHandler
class|class
name|SomeHandler
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|m_hv
name|QHeaderView
modifier|*
name|m_hv
decl_stmt|;
DECL|member|m_tv
name|QTableView
modifier|*
name|m_tv
decl_stmt|;
public|public:
name|SomeHandler
parameter_list|(
name|QHeaderView
modifier|*
name|hv
parameter_list|,
name|QTableView
modifier|*
name|tv
parameter_list|)
constructor_decl|;
public|public
name|slots
public|:
name|void
name|slotSectionResized
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|SomeHandler
name|SomeHandler
operator|::
name|SomeHandler
parameter_list|(
name|QHeaderView
modifier|*
name|hv
parameter_list|,
name|QTableView
modifier|*
name|tv
parameter_list|)
block|{
name|m_hv
operator|=
name|hv
expr_stmt|;
name|m_tv
operator|=
name|tv
expr_stmt|;
name|m_tv
operator|->
name|setHorizontalScrollMode
argument_list|(
name|QAbstractItemView
operator|::
name|ScrollPerPixel
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|hv
argument_list|,
name|SIGNAL
argument_list|(
name|sectionResized
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|slotSectionResized
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|slotSectionResized
name|void
name|SomeHandler
operator|::
name|slotSectionResized
parameter_list|(
name|int
name|logsection
parameter_list|,
name|int
name|oldsize
parameter_list|,
name|int
name|newsize
parameter_list|)
block|{
name|int
name|offset
init|=
name|m_hv
operator|->
name|offset
argument_list|()
decl_stmt|;
name|m_tv
operator|->
name|setUpdatesEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// Do some manual resizing - lets make every section having the new size.
name|m_hv
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|setDefaultSectionSize
argument_list|(
name|newsize
argument_list|)
expr_stmt|;
name|m_hv
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// Adjust offset and scrollbar. Maybe it isn't 100% perfect
comment|// but proof of concept
comment|// The test has sense without the define, too.
DECL|macro|DO_CORRECT_OFFSET_AND_SB
define|#
directive|define
name|DO_CORRECT_OFFSET_AND_SB
ifdef|#
directive|ifdef
name|DO_CORRECT_OFFSET_AND_SB
name|int
name|leftRemoved
init|=
operator|(
name|m_hv
operator|->
name|visualIndex
argument_list|(
name|logsection
argument_list|)
operator|)
operator|*
operator|(
name|oldsize
operator|-
name|newsize
operator|)
decl_stmt|;
name|int
name|newoffset
init|=
name|offset
operator|-
name|leftRemoved
decl_stmt|;
if|if
condition|(
name|newoffset
operator|<
literal|0
condition|)
name|newoffset
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|newoffset
operator|>
literal|0
operator|&&
name|newoffset
operator|>=
name|m_hv
operator|->
name|count
argument_list|()
operator|*
name|newsize
operator|-
name|m_tv
operator|->
name|viewport
argument_list|()
operator|->
name|width
argument_list|()
condition|)
name|m_hv
operator|->
name|setOffsetToLastSection
argument_list|()
expr_stmt|;
else|else
name|m_hv
operator|->
name|setOffset
argument_list|(
name|newoffset
argument_list|)
expr_stmt|;
name|m_tv
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|blockSignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_tv
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
name|m_hv
operator|->
name|count
argument_list|()
operator|*
name|newsize
operator|-
name|m_tv
operator|->
name|viewport
argument_list|()
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|m_tv
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|setValue
argument_list|(
name|newoffset
argument_list|)
expr_stmt|;
name|m_tv
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|blockSignals
argument_list|(
literal|false
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_tv
operator|->
name|setUpdatesEnabled
argument_list|(
literal|true
argument_list|)
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
name|Window
name|window
decl_stmt|;
comment|// Comment in the line below to test selection with keyboard (space)
comment|// tv.setEditTriggers(QAbstractItemView::NoEditTriggers);
name|QHeaderView
modifier|*
name|hHeader
init|=
name|window
operator|.
name|tableView
operator|->
name|horizontalHeader
argument_list|()
decl_stmt|;
name|QHeaderView
modifier|*
name|vHeader
init|=
name|window
operator|.
name|tableView
operator|->
name|verticalHeader
argument_list|()
decl_stmt|;
name|SomeHandler
name|handler
argument_list|(
name|hHeader
argument_list|,
name|window
operator|.
name|tableView
argument_list|)
decl_stmt|;
name|hHeader
operator|->
name|setDefaultSectionSize
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|window
operator|.
name|resize
argument_list|(
literal|600
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
name|hHeader
operator|->
name|setSectionsMovable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|vHeader
operator|->
name|setSectionsMovable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|window
operator|.
name|updateControls
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
file|"qheaderviewtest1.moc"
end_include
end_unit
