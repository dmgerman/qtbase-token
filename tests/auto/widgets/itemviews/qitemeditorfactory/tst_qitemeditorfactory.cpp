begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QItemEditorFactory
class|class
name|tst_QItemEditorFactory
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|createEditor
parameter_list|()
function_decl|;
name|void
name|createCustomEditor
parameter_list|()
function_decl|;
name|void
name|uintValues
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|createEditor
name|void
name|tst_QItemEditorFactory
operator|::
name|createEditor
parameter_list|()
block|{
specifier|const
name|QItemEditorFactory
modifier|*
name|factory
init|=
name|QItemEditorFactory
operator|::
name|defaultFactory
argument_list|()
decl_stmt|;
name|QWidget
name|parent
decl_stmt|;
name|QWidget
modifier|*
name|w
init|=
name|factory
operator|->
name|createEditor
argument_list|(
name|QVariant
operator|::
name|String
argument_list|,
operator|&
name|parent
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|,
literal|"QExpandingLineEdit"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//we make it inherit from QObject so that we can use QPointer
end_comment
begin_class
DECL|class|MyEditor
class|class
name|MyEditor
super|:
specifier|public
name|QObject
super|,
specifier|public
name|QStandardItemEditorCreator
argument_list|<
name|QDoubleSpinBox
argument_list|>
block|{
block|}
class|;
end_class
begin_function
DECL|function|createCustomEditor
name|void
name|tst_QItemEditorFactory
operator|::
name|createCustomEditor
parameter_list|()
block|{
name|QPointer
argument_list|<
name|MyEditor
argument_list|>
name|creator
init|=
operator|new
name|MyEditor
decl_stmt|;
name|QPointer
argument_list|<
name|MyEditor
argument_list|>
name|creator2
init|=
operator|new
name|MyEditor
decl_stmt|;
block|{
name|QItemEditorFactory
name|editorFactory
decl_stmt|;
name|editorFactory
operator|.
name|registerEditor
argument_list|(
name|QVariant
operator|::
name|Rect
argument_list|,
name|creator
argument_list|)
expr_stmt|;
name|editorFactory
operator|.
name|registerEditor
argument_list|(
name|QVariant
operator|::
name|RectF
argument_list|,
name|creator
argument_list|)
expr_stmt|;
comment|//creator should not be deleted as a result of calling the next line
name|editorFactory
operator|.
name|registerEditor
argument_list|(
name|QVariant
operator|::
name|Rect
argument_list|,
name|creator2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|creator
argument_list|)
expr_stmt|;
comment|//this should erase creator2
name|editorFactory
operator|.
name|registerEditor
argument_list|(
name|QVariant
operator|::
name|Rect
argument_list|,
name|creator
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|creator2
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QWidget
name|parent
decl_stmt|;
name|QWidget
modifier|*
name|w
init|=
name|editorFactory
operator|.
name|createEditor
argument_list|(
name|QVariant
operator|::
name|Rect
argument_list|,
operator|&
name|parent
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|,
literal|"QDoubleSpinBox"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|w
operator|->
name|metaObject
argument_list|()
operator|->
name|userProperty
argument_list|()
operator|.
name|type
argument_list|()
argument_list|,
name|QVariant
operator|::
name|Double
argument_list|)
expr_stmt|;
block|}
comment|//editorFactory has been deleted, so should be creator
comment|//because editorFActory has the ownership
name|QVERIFY
argument_list|(
name|creator
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|creator2
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|creator
expr_stmt|;
block|}
end_function
begin_function
DECL|function|uintValues
name|void
name|tst_QItemEditorFactory
operator|::
name|uintValues
parameter_list|()
block|{
name|QItemEditorFactory
name|editorFactory
decl_stmt|;
name|QWidget
name|parent
decl_stmt|;
block|{
name|QWidget
modifier|*
name|editor
init|=
name|editorFactory
operator|.
name|createEditor
argument_list|(
name|QMetaType
operator|::
name|UInt
argument_list|,
operator|&
name|parent
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|editor
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|,
literal|"QUIntSpinBox"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|editor
operator|->
name|metaObject
argument_list|()
operator|->
name|userProperty
argument_list|()
operator|.
name|type
argument_list|()
argument_list|,
name|QVariant
operator|::
name|UInt
argument_list|)
expr_stmt|;
block|}
block|{
name|QWidget
modifier|*
name|editor
init|=
name|editorFactory
operator|.
name|createEditor
argument_list|(
name|QMetaType
operator|::
name|Int
argument_list|,
operator|&
name|parent
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|editor
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|,
literal|"QSpinBox"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|editor
operator|->
name|metaObject
argument_list|()
operator|->
name|userProperty
argument_list|()
operator|.
name|type
argument_list|()
argument_list|,
name|QVariant
operator|::
name|Int
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QItemEditorFactory
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qitemeditorfactory.moc"
end_include
end_unit
