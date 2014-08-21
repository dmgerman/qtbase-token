begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"hbwidget.h"
end_include
begin_include
include|#
directive|include
file|"vbwidget.h"
end_include
begin_include
include|#
directive|include
file|"gridwidget.h"
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QComboBox>
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|QWidget
modifier|*
name|widget
init|=
operator|new
name|QWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|setCentralWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|m_mainLayout
operator|=
operator|new
name|QGridLayout
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|QComboBox
modifier|*
name|combo
init|=
operator|new
name|QComboBox
argument_list|()
decl_stmt|;
name|combo
operator|->
name|addItem
argument_list|(
literal|"HBox Layout"
argument_list|)
expr_stmt|;
name|combo
operator|->
name|addItem
argument_list|(
literal|"VBox Layout"
argument_list|)
expr_stmt|;
name|combo
operator|->
name|addItem
argument_list|(
literal|"Grid Layout"
argument_list|)
expr_stmt|;
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
name|layoutIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|HbWidget
modifier|*
name|hbWidget
init|=
operator|new
name|HbWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|m_mainLayout
operator|->
name|addWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|m_mainLayout
operator|->
name|addWidget
argument_list|(
name|hbWidget
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~MainWindow
name|MainWindow
operator|::
name|~
name|MainWindow
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|layoutIndexChanged
name|void
name|MainWindow
operator|::
name|layoutIndexChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
operator|delete
name|m_mainLayout
operator|->
name|takeAt
argument_list|(
literal|1
argument_list|)
operator|->
name|widget
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|index
condition|)
block|{
case|case
literal|0
case|:
block|{
name|HbWidget
modifier|*
name|hbWidget
init|=
operator|new
name|HbWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|m_mainLayout
operator|->
name|addWidget
argument_list|(
name|hbWidget
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
literal|1
case|:
block|{
name|VbWidget
modifier|*
name|vbWidget
init|=
operator|new
name|VbWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|m_mainLayout
operator|->
name|addWidget
argument_list|(
name|vbWidget
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
block|{
name|GridWidget
modifier|*
name|gridW
init|=
operator|new
name|GridWidget
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|m_mainLayout
operator|->
name|addWidget
argument_list|(
name|gridW
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
end_unit
