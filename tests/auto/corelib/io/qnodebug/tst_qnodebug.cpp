begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// This test is for "release" mode, with -DQT_NO_DEBUG -DQT_NO_DEBUG_OUTPUT
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
end_ifndef
begin_define
DECL|macro|QT_NO_DEBUG
define|#
directive|define
name|QT_NO_DEBUG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_OUTPUT
end_ifndef
begin_define
DECL|macro|QT_NO_DEBUG_OUTPUT
define|#
directive|define
name|QT_NO_DEBUG_OUTPUT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_include
include|#
directive|include
file|<QtCore/QtDebug>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QNoDebug
class|class
name|tst_QNoDebug
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|noDebugOutput
parameter_list|()
specifier|const
function_decl|;
name|void
name|streaming
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|noDebugOutput
name|void
name|tst_QNoDebug
operator|::
name|noDebugOutput
parameter_list|()
specifier|const
block|{
comment|// should do nothing
name|qDebug
argument_list|()
operator|<<
literal|"foo"
expr_stmt|;
comment|// qWarning still works, though
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"bar "
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"bar"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|streaming
name|void
name|tst_QNoDebug
operator|::
name|streaming
parameter_list|()
specifier|const
block|{
name|QDateTime
name|dt
argument_list|(
name|QDate
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
argument_list|,
name|QTime
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"QDateTime(\"%1\") "
argument_list|)
operator|.
name|arg
argument_list|(
name|dt
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
name|dt
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|tst_QNoDebug
name|QTEST_MAIN
argument_list|(
name|tst_QNoDebug
argument_list|)
expr_stmt|;
end_expr_stmt
begin_include
include|#
directive|include
file|"tst_qnodebug.moc"
end_include
end_unit
