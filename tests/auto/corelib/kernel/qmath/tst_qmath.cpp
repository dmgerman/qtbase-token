begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_decl_stmt
DECL|variable|PI
specifier|static
specifier|const
name|qreal
name|PI
init|=
literal|3.14159265358979323846264338327950288
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|tst_QMath
class|class
name|tst_QMath
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|fastSinCos
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|fastSinCos
name|void
name|tst_QMath
operator|::
name|fastSinCos
parameter_list|()
block|{
comment|// Test evenly spaced angles from 0 to 2pi radians.
specifier|const
name|int
name|LOOP_COUNT
init|=
literal|100000
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|LOOP_COUNT
condition|;
operator|++
name|i
control|)
block|{
name|qreal
name|angle
init|=
name|i
operator|*
literal|2
operator|*
name|PI
operator|/
operator|(
name|LOOP_COUNT
operator|-
literal|1
operator|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|qAbs
argument_list|(
name|qSin
argument_list|(
name|angle
argument_list|)
operator|-
name|qFastSin
argument_list|(
name|angle
argument_list|)
argument_list|)
operator|<
literal|1e-5
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qAbs
argument_list|(
name|qCos
argument_list|(
name|angle
argument_list|)
operator|-
name|qFastCos
argument_list|(
name|angle
argument_list|)
argument_list|)
operator|<
literal|1e-5
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QMath
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmath.moc"
end_include
end_unit
