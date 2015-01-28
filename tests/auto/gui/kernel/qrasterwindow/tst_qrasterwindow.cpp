begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QRasterWindow>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_class
DECL|class|tst_QRasterWindow
class|class
name|tst_QRasterWindow
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|create
parameter_list|()
function_decl|;
name|void
name|basic
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|create
name|void
name|tst_QRasterWindow
operator|::
name|create
parameter_list|()
block|{
name|QRasterWindow
name|w
decl_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|640
argument_list|,
literal|480
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|PainterWindow
class|class
name|PainterWindow
super|:
specifier|public
name|QRasterWindow
block|{
public|public:
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|paintCount
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
operator|++
name|paintCount
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
DECL|member|paintCount
name|int
name|paintCount
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|basic
name|void
name|tst_QRasterWindow
operator|::
name|basic
parameter_list|()
block|{
name|PainterWindow
name|w
decl_stmt|;
name|w
operator|.
name|reset
argument_list|()
expr_stmt|;
name|w
operator|.
name|resize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|w
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowExposed
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|paintCount
operator|>=
literal|1
argument_list|)
expr_stmt|;
name|w
operator|.
name|reset
argument_list|()
expr_stmt|;
name|w
operator|.
name|update
argument_list|()
expr_stmt|;
name|int
name|maxWait
init|=
literal|1000
decl_stmt|;
while|while
condition|(
name|w
operator|.
name|paintCount
operator|==
literal|0
operator|&&
operator|--
name|maxWait
operator|>
literal|0
condition|)
name|QTest
operator|::
name|qWait
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|w
operator|.
name|paintCount
operator|>=
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|<tst_qrasterwindow.moc>
end_include
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QRasterWindow
argument_list|)
end_macro
end_unit
