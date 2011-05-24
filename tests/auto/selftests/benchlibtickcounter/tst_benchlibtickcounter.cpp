begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<private/cycle_p.h>
end_include
begin_class
DECL|class|tst_BenchlibTickCounter
class|class
name|tst_BenchlibTickCounter
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|threeBillionTicks
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|threeBillionTicks
name|void
name|tst_BenchlibTickCounter
operator|::
name|threeBillionTicks
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|HAVE_TICK_COUNTER
name|QSKIP
argument_list|(
literal|"Tick counter not available on this platform"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
else|#
directive|else
name|QBENCHMARK
block|{
name|CycleCounterTicks
name|start
init|=
name|getticks
argument_list|()
decl_stmt|;
name|double
name|el
init|=
literal|0.
decl_stmt|;
name|double
name|max
init|=
name|el
decl_stmt|;
while|while
condition|(
name|el
operator|<
literal|3000000000.
condition|)
block|{
comment|/* Verify that elapsed time never decreases */
name|QVERIFY2
argument_list|(
name|el
operator|>=
name|max
argument_list|,
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"Tick counter is not monotonic\nElapsed moved from %1 to %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|max
argument_list|)
operator|.
name|arg
argument_list|(
name|el
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|max
operator|=
name|el
expr_stmt|;
name|el
operator|=
name|elapsed
argument_list|(
name|getticks
argument_list|()
argument_list|,
name|start
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_BenchlibTickCounter
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_benchlibtickcounter.moc"
end_include
end_unit
