begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QTableView>
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QItemDelegate>
end_include
begin_include
include|#
directive|include
file|<QItemEditorFactory>
end_include
begin_include
include|#
directive|include
file|<QDoubleSpinBox>
end_include
begin_include
include|#
directive|include
file|"localewidget.h"
end_include
begin_include
include|#
directive|include
file|"localemodel.h"
end_include
begin_class
DECL|class|DoubleEditorCreator
class|class
name|DoubleEditorCreator
super|:
specifier|public
name|QItemEditorCreatorBase
block|{
public|public:
DECL|function|createWidget
name|QWidget
modifier|*
name|createWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
specifier|const
block|{
name|QDoubleSpinBox
modifier|*
name|w
init|=
operator|new
name|QDoubleSpinBox
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|w
operator|->
name|setDecimals
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|w
operator|->
name|setRange
argument_list|(
operator|-
literal|10000.0
argument_list|,
literal|10000.0
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
DECL|function|valuePropertyName
specifier|virtual
name|QByteArray
name|valuePropertyName
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
literal|"value"
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|EditorFactory
class|class
name|EditorFactory
super|:
specifier|public
name|QItemEditorFactory
block|{
public|public:
DECL|function|EditorFactory
name|EditorFactory
parameter_list|()
block|{
specifier|static
name|DoubleEditorCreator
name|double_editor_creator
decl_stmt|;
name|registerEditor
argument_list|(
name|QVariant
operator|::
name|Double
argument_list|,
operator|&
name|double_editor_creator
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_constructor
DECL|function|LocaleWidget
name|LocaleWidget
operator|::
name|LocaleWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|m_model
operator|=
operator|new
name|LocaleModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_view
operator|=
operator|new
name|QTableView
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QItemDelegate
modifier|*
name|delegate
init|=
name|qobject_cast
argument_list|<
name|QItemDelegate
operator|*
argument_list|>
argument_list|(
name|m_view
operator|->
name|itemDelegate
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|delegate
operator|!=
literal|0
argument_list|)
expr_stmt|;
specifier|static
name|EditorFactory
name|editor_factory
decl_stmt|;
name|delegate
operator|->
name|setItemEditorFactory
argument_list|(
operator|&
name|editor_factory
argument_list|)
expr_stmt|;
name|m_view
operator|->
name|setModel
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|m_view
argument_list|)
expr_stmt|;
block|}
end_constructor
end_unit
