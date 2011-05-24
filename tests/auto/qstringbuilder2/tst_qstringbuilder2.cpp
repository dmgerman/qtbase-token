begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// SCENARIO 2
end_comment
begin_comment
comment|// this is the "full" version. Operator+ is replaced by a QStringBuilder
end_comment
begin_comment
comment|// based version
end_comment
begin_comment
comment|// with NO_CAST * defined
end_comment
begin_define
DECL|macro|P
define|#
directive|define
name|P
value|+
end_define
begin_define
DECL|macro|QT_USE_QSTRINGBUILDER
define|#
directive|define
name|QT_USE_QSTRINGBUILDER
end_define
begin_define
DECL|macro|QT_NO_CAST_FROM_ASCII
define|#
directive|define
name|QT_NO_CAST_FROM_ASCII
end_define
begin_define
DECL|macro|QT_NO_CAST_TO_ASCII
define|#
directive|define
name|QT_NO_CAST_TO_ASCII
end_define
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_comment
comment|//TESTED_CLASS=QStringBuilder
end_comment
begin_comment
comment|//TESTED_FILES=qstringbuilder.cpp
end_comment
begin_define
DECL|macro|LITERAL
define|#
directive|define
name|LITERAL
value|"some literal"
end_define
begin_function_decl
name|void
name|runScenario
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// Defined in stringbuilder.cpp #included below.
end_comment
begin_class
DECL|class|tst_QStringBuilder2
class|class
name|tst_QStringBuilder2
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
DECL|function|scenario
name|void
name|scenario
parameter_list|()
block|{
name|runScenario
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_include
include|#
directive|include
file|"../qstringbuilder1/stringbuilder.cpp"
end_include
begin_include
include|#
directive|include
file|"tst_qstringbuilder2.moc"
end_include
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QStringBuilder2
argument_list|)
end_macro
end_unit
