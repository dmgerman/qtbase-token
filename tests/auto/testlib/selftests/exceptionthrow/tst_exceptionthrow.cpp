begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_Exception
class|class
name|tst_Exception
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|throwException
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/*!  \internal   We simply throw an exception to check that we get sane output/reporting.  */
end_comment
begin_function
DECL|function|throwException
name|void
name|tst_Exception
operator|::
name|throwException
parameter_list|()
specifier|const
block|{
comment|/* When exceptions are disabled, some compilers, at least linux-g++, treat      * exception clauses as hard errors. */
ifndef|#
directive|ifndef
name|QT_NO_EXCEPTIONS
throw|throw
literal|3
throw|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Exception
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_exceptionthrow.moc"
end_include
end_unit
