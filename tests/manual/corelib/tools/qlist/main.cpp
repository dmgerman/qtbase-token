begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 ThorbjÃ¸rn Lund Martsum - tmartsum[at]gmail.com ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_comment
comment|//#define QT_STRICT_ITERATORS
end_comment
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_function
DECL|function|testErase
name|void
name|testErase
parameter_list|()
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|a
decl_stmt|,
name|b
decl_stmt|;
name|a
operator|.
name|append
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|a
operator|.
name|append
argument_list|(
literal|6
argument_list|)
expr_stmt|;
name|a
operator|.
name|append
argument_list|(
literal|7
argument_list|)
expr_stmt|;
name|b
operator|=
name|a
expr_stmt|;
name|a
operator|.
name|erase
argument_list|(
name|a
operator|.
name|begin
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"erase - Executing line with error now."
expr_stmt|;
comment|// a.erase(a.end());
name|a
operator|.
name|erase
argument_list|(
name|b
operator|.
name|begin
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testInsert
name|void
name|testInsert
parameter_list|()
block|{
name|QList
argument_list|<
name|int
argument_list|>
name|a
decl_stmt|,
name|b
decl_stmt|;
name|a
operator|.
name|insert
argument_list|(
name|a
operator|.
name|begin
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|a
operator|.
name|insert
argument_list|(
name|a
operator|.
name|begin
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|a
operator|.
name|insert
argument_list|(
name|a
operator|.
name|end
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|b
operator|=
name|a
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"insert - Executing line with error now."
expr_stmt|;
name|a
operator|.
name|insert
argument_list|(
name|b
operator|.
name|begin
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
comment|// testErase();
name|testInsert
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
