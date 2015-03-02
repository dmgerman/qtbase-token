begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"propertywatcher.h"
end_include
begin_include
include|#
directive|include
file|<QMetaProperty>
end_include
begin_include
include|#
directive|include
file|<QFormLayout>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|"propertyfield.h"
end_include
begin_constructor
DECL|function|PropertyWatcher
name|PropertyWatcher
operator|::
name|PropertyWatcher
parameter_list|(
name|QObject
modifier|*
name|subject
parameter_list|,
name|QString
name|annotation
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_subject
argument_list|(
name|subject
argument_list|)
member_init_list|,
name|m_layout
argument_list|(
operator|new
name|QFormLayout
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|QString
argument_list|(
literal|"Properties of %1 %2 %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|subject
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|subject
operator|->
name|objectName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|annotation
argument_list|)
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
literal|450
argument_list|,
literal|300
argument_list|)
expr_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|meta
init|=
name|m_subject
operator|->
name|metaObject
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|meta
operator|->
name|propertyCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QMetaProperty
name|prop
init|=
name|meta
operator|->
name|property
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|prop
operator|.
name|isReadable
argument_list|()
condition|)
block|{
name|PropertyField
modifier|*
name|field
init|=
operator|new
name|PropertyField
argument_list|(
name|m_subject
argument_list|,
name|prop
argument_list|)
decl_stmt|;
name|m_layout
operator|->
name|addRow
argument_list|(
name|prop
operator|.
name|name
argument_list|()
argument_list|,
name|field
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qstrcmp
argument_list|(
name|prop
operator|.
name|name
argument_list|()
argument_list|,
literal|"name"
argument_list|)
condition|)
name|setWindowIconText
argument_list|(
name|prop
operator|.
name|read
argument_list|(
name|subject
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|QPushButton
modifier|*
name|updateButton
init|=
operator|new
name|QPushButton
argument_list|(
literal|"update"
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|updateButton
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|PropertyWatcher
operator|::
name|updateAllFields
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|addRow
argument_list|(
literal|""
argument_list|,
name|updateButton
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setFieldGrowthPolicy
argument_list|(
name|QFormLayout
operator|::
name|ExpandingFieldsGrow
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|m_layout
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|subject
argument_list|,
operator|&
name|QObject
operator|::
name|destroyed
argument_list|,
name|this
argument_list|,
operator|&
name|PropertyWatcher
operator|::
name|subjectDestroyed
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~PropertyWatcher
name|PropertyWatcher
operator|::
name|~
name|PropertyWatcher
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|updateAllFields
name|void
name|PropertyWatcher
operator|::
name|updateAllFields
parameter_list|()
block|{
name|QList
argument_list|<
name|PropertyField
modifier|*
argument_list|>
name|fields
init|=
name|findChildren
argument_list|<
name|PropertyField
operator|*
argument_list|>
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|PropertyField
modifier|*
name|field
decl|,
name|fields
control|)
name|field
operator|->
name|propertyChanged
argument_list|()
expr_stmt|;
emit|emit
name|updatedAllFields
argument_list|(
name|this
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|subjectDestroyed
name|void
name|PropertyWatcher
operator|::
name|subjectDestroyed
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"screen destroyed"
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
