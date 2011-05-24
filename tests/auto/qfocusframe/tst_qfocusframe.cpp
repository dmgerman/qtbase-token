begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qfocusframe.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QFocusFrame
class|class
name|tst_QFocusFrame
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QFocusFrame
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QFocusFrame
parameter_list|()
destructor_decl|;
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
begin_constructor
DECL|function|tst_QFocusFrame
name|tst_QFocusFrame
operator|::
name|tst_QFocusFrame
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QFocusFrame
name|tst_QFocusFrame
operator|::
name|~
name|tst_QFocusFrame
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QFocusFrame
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QFocusFrame
modifier|*
name|obj1
init|=
operator|new
name|QFocusFrame
argument_list|()
decl_stmt|;
comment|// QWidget * QFocusFrame::widget()
comment|// void QFocusFrame::setWidget(QWidget *)
name|QWidget
name|var1
decl_stmt|;
name|QWidget
modifier|*
name|var2
init|=
operator|new
name|QWidget
argument_list|(
operator|&
name|var1
argument_list|)
decl_stmt|;
name|obj1
operator|->
name|setWidget
argument_list|(
name|var2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var2
argument_list|,
name|obj1
operator|->
name|widget
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|->
name|setWidget
argument_list|(
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QWidget
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|->
name|widget
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|obj1
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QFocusFrame
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qfocusframe.moc"
end_include
end_unit
