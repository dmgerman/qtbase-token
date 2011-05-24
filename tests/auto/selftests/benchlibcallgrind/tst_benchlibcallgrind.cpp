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
begin_comment
comment|/* This test must be explicitly enabled since there are no compile tests for valgrind.h */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUG236484
end_ifdef
begin_include
include|#
directive|include
file|<valgrind/valgrind.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_BenchlibCallgrind
class|class
name|tst_BenchlibCallgrind
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
ifdef|#
directive|ifdef
name|QT_BUG236484
name|void
name|failInChildProcess
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|twoHundredMillionInstructions
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUG236484
end_ifdef
begin_function
DECL|function|failInChildProcess
name|void
name|tst_BenchlibCallgrind
operator|::
name|failInChildProcess
parameter_list|()
block|{
specifier|static
name|double
name|f
init|=
literal|1.0
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|1000000
condition|;
operator|++
name|i
control|)
block|{
name|f
operator|*=
literal|1.1
expr_stmt|;
if|if
condition|(
name|RUNNING_ON_VALGRIND
condition|)
name|QFAIL
argument_list|(
literal|"Running under valgrind!"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|twoHundredMillionInstructions
name|void
name|tst_BenchlibCallgrind
operator|::
name|twoHundredMillionInstructions
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__i386
argument_list|)
name|QSKIP
argument_list|(
literal|"This test is only defined for gcc and x86."
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
else|#
directive|else
name|QBENCHMARK
block|{
asm|__asm__
specifier|__volatile__
asm|(             "mov $100000000,%%eax   \n"             "LOOPTOP:               \n"             "dec %%eax              \n"             "jnz LOOPTOP            \n"             :
comment|/* no output */
asm|:
comment|/* no input */
asm|:
comment|/* clobber */
asm|"eax"         );
block|}
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_BenchlibCallgrind
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_benchlibcallgrind.moc"
end_include
end_unit
