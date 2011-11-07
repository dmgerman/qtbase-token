begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=corelib/global/qglobal.h corelib/global/qglobal.cpp
end_comment
begin_class
DECL|class|tst_QGetPutEnv
class|class
name|tst_QGetPutEnv
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|getSetCheck
name|void
name|tst_QGetPutEnv
operator|::
name|getSetCheck
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|varName
init|=
literal|"should_not_exist"
decl_stmt|;
name|QByteArray
name|result
init|=
name|qgetenv
argument_list|(
name|varName
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qputenv
argument_list|(
name|varName
argument_list|,
name|QByteArray
argument_list|(
literal|"supervalue"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|qgetenv
argument_list|(
name|varName
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|==
literal|"supervalue"
argument_list|)
expr_stmt|;
name|qputenv
argument_list|(
name|varName
argument_list|,
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGetPutEnv
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgetputenv.moc"
end_include
end_unit
