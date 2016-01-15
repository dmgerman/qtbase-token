begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Make sure we get a real Q_ASSERT even in release builds
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_DEBUG
end_ifdef
begin_undef
DECL|macro|QT_NO_DEBUG
undef|#
directive|undef
name|QT_NO_DEBUG
end_undef
begin_endif
endif|#
directive|endif
end_endif
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
begin_class
DECL|class|tst_Assert
class|class
name|tst_Assert
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|testNumber1
parameter_list|()
specifier|const
function_decl|;
name|void
name|testNumber2
parameter_list|()
specifier|const
function_decl|;
name|void
name|testNumber3
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|testNumber1
name|void
name|tst_Assert
operator|::
name|testNumber1
parameter_list|()
specifier|const
block|{ }
end_function
begin_function
DECL|function|testNumber2
name|void
name|tst_Assert
operator|::
name|testNumber2
parameter_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testNumber3
name|void
name|tst_Assert
operator|::
name|testNumber3
parameter_list|()
specifier|const
block|{ }
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_Assert
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_assert.moc"
end_include
end_unit
