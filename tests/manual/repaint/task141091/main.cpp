begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QPaintEvent>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_class
DECL|class|MyWidget
class|class
name|MyWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|MyWidget
name|MyWidget
parameter_list|()
member_init_list|:
name|QWidget
argument_list|()
block|{
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_OpaquePaintEvent
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|e
parameter_list|)
block|{
name|qDebug
argument_list|()
operator|<<
name|e
operator|->
name|rect
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
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
modifier|*
name|argv
parameter_list|)
block|{
name|QApplication
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|MyWidget
name|w
decl_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|a
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
