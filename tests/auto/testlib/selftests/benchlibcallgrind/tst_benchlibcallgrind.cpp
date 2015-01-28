begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
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
