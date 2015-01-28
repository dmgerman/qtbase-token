begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QComboBox>
end_include
begin_include
include|#
directive|include
file|<QDateTimeEdit>
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QSpinBox>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_constructor
DECL|function|GridWidget
name|GridWidget
operator|::
name|GridWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QGridLayout
modifier|*
name|hb
init|=
operator|new
name|QGridLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|hb
operator|->
name|setObjectName
argument_list|(
literal|"GridWidget"
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
literal|"123"
argument_list|)
expr_stmt|;
name|QComboBox
modifier|*
name|combo2
init|=
operator|new
name|QComboBox
argument_list|()
decl_stmt|;
name|combo2
operator|->
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|combo2
operator|->
name|addItem
argument_list|(
literal|"123"
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
literal|"123"
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
literal|"123"
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QLineEdit
argument_list|(
literal|"123"
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QLineEdit
argument_list|(
literal|"123"
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QCheckBox
argument_list|(
literal|"123"
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QCheckBox
argument_list|(
literal|"123"
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
name|combo
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
name|combo2
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QDateTimeEdit
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QPushButton
argument_list|(
literal|"123"
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QSpinBox
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
operator|new
name|QSpinBox
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"There should be four warnings, but no crash or freeze:"
argument_list|)
expr_stmt|;
name|hb
operator|->
name|addWidget
argument_list|(
name|this
argument_list|,
literal|6
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|///< This command should print a warning, but should not add "this"
name|hb
operator|->
name|addWidget
argument_list|(
name|Q_NULLPTR
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|///< This command should print a warning, but should not add "NULL"
name|hb
operator|->
name|addLayout
argument_list|(
name|hb
argument_list|,
literal|7
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|///< This command should print a warning, but should not add "hb"
name|hb
operator|->
name|addLayout
argument_list|(
name|Q_NULLPTR
argument_list|,
literal|7
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|///< This command should print a warning, but should not add "NULL"
name|qDebug
argument_list|(
literal|"Neither crashed nor frozen"
argument_list|)
expr_stmt|;
block|}
end_constructor
end_unit
