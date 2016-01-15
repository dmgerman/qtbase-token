begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
DECL|class|tst_qurl
class|class
name|tst_qurl
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|emptyUrl
parameter_list|()
function_decl|;
name|void
name|relativeUrl
parameter_list|()
function_decl|;
name|void
name|absoluteUrl
parameter_list|()
function_decl|;
name|void
name|isRelative_data
parameter_list|()
function_decl|;
name|void
name|isRelative
parameter_list|()
function_decl|;
name|void
name|toLocalFile_data
parameter_list|()
function_decl|;
name|void
name|toLocalFile
parameter_list|()
function_decl|;
name|void
name|toString_data
parameter_list|()
function_decl|;
name|void
name|toString
parameter_list|()
function_decl|;
name|void
name|resolved_data
parameter_list|()
function_decl|;
name|void
name|resolved
parameter_list|()
function_decl|;
name|void
name|equality_data
parameter_list|()
function_decl|;
name|void
name|equality
parameter_list|()
function_decl|;
name|void
name|qmlPropertyWriteUseCase
parameter_list|()
function_decl|;
private|private:
name|void
name|generateFirstRunData
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|emptyUrl
name|void
name|tst_qurl
operator|::
name|emptyUrl
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QUrl
name|url
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|relativeUrl
name|void
name|tst_qurl
operator|::
name|relativeUrl
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|absoluteUrl
name|void
name|tst_qurl
operator|::
name|absoluteUrl
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QUrl
name|url
argument_list|(
literal|"/tmp/avatar.png"
argument_list|)
decl_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|generateFirstRunData
name|void
name|tst_qurl
operator|::
name|generateFirstRunData
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"firstRun"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"construction + first run"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"subsequent runs"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isRelative_data
name|void
name|tst_qurl
operator|::
name|isRelative_data
parameter_list|()
block|{
name|generateFirstRunData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isRelative
name|void
name|tst_qurl
operator|::
name|isRelative
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|firstRun
argument_list|)
expr_stmt|;
if|if
condition|(
name|firstRun
condition|)
block|{
name|QBENCHMARK
block|{
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
name|url
operator|.
name|isRelative
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|url
operator|.
name|isRelative
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|toLocalFile_data
name|void
name|tst_qurl
operator|::
name|toLocalFile_data
parameter_list|()
block|{
name|generateFirstRunData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toLocalFile
name|void
name|tst_qurl
operator|::
name|toLocalFile
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|firstRun
argument_list|)
expr_stmt|;
if|if
condition|(
name|firstRun
condition|)
block|{
name|QBENCHMARK
block|{
name|QUrl
name|url
argument_list|(
literal|"/tmp/avatar.png"
argument_list|)
decl_stmt|;
name|url
operator|.
name|toLocalFile
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|QUrl
name|url
argument_list|(
literal|"/tmp/avatar.png"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|url
operator|.
name|toLocalFile
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|toString_data
name|void
name|tst_qurl
operator|::
name|toString_data
parameter_list|()
block|{
name|generateFirstRunData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toString
name|void
name|tst_qurl
operator|::
name|toString
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|firstRun
argument_list|)
expr_stmt|;
if|if
condition|(
name|firstRun
condition|)
block|{
name|QBENCHMARK
block|{
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
name|url
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|url
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|resolved_data
name|void
name|tst_qurl
operator|::
name|resolved_data
parameter_list|()
block|{
name|generateFirstRunData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resolved
name|void
name|tst_qurl
operator|::
name|resolved
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|firstRun
argument_list|)
expr_stmt|;
if|if
condition|(
name|firstRun
condition|)
block|{
name|QBENCHMARK
block|{
name|QUrl
name|baseUrl
argument_list|(
literal|"/home/user/"
argument_list|)
decl_stmt|;
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
name|baseUrl
operator|.
name|resolved
argument_list|(
name|url
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|QUrl
name|baseUrl
argument_list|(
literal|"/home/user/"
argument_list|)
decl_stmt|;
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|baseUrl
operator|.
name|resolved
argument_list|(
name|url
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|equality_data
name|void
name|tst_qurl
operator|::
name|equality_data
parameter_list|()
block|{
name|generateFirstRunData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|equality
name|void
name|tst_qurl
operator|::
name|equality
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|firstRun
argument_list|)
expr_stmt|;
if|if
condition|(
name|firstRun
condition|)
block|{
name|QBENCHMARK
block|{
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
name|QUrl
name|url2
argument_list|(
literal|"pics/avatar2.png"
argument_list|)
decl_stmt|;
comment|//url == url2;
block|}
block|}
else|else
block|{
name|QUrl
name|url
argument_list|(
literal|"pics/avatar.png"
argument_list|)
decl_stmt|;
name|QUrl
name|url2
argument_list|(
literal|"pics/avatar2.png"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|url
operator|==
name|url2
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|qmlPropertyWriteUseCase
name|void
name|tst_qurl
operator|::
name|qmlPropertyWriteUseCase
parameter_list|()
block|{
name|QUrl
name|base
argument_list|(
literal|"file:///home/user/qt/examples/declarative/samegame/SamegameCore/"
argument_list|)
decl_stmt|;
name|QString
name|str
argument_list|(
literal|"pics/redStar.png"
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QUrl
name|u
init|=
name|QUrl
argument_list|(
name|str
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|u
operator|.
name|isEmpty
argument_list|()
operator|&&
name|u
operator|.
name|isRelative
argument_list|()
condition|)
name|u
operator|=
name|base
operator|.
name|resolved
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qurl
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
