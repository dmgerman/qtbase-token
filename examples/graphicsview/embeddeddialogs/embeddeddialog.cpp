begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"embeddeddialog.h"
end_include
begin_include
include|#
directive|include
file|"ui_embeddeddialog.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_constructor
DECL|function|EmbeddedDialog
name|EmbeddedDialog
operator|::
name|EmbeddedDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|ui
operator|=
operator|new
name|Ui_embeddedDialog
expr_stmt|;
name|ui
operator|->
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|ui
operator|->
name|layoutDirection
operator|->
name|setCurrentIndex
argument_list|(
name|layoutDirection
argument_list|()
operator|!=
name|Qt
operator|::
name|LeftToRight
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QString
name|styleName
decl|,
name|QStyleFactory
operator|::
name|keys
argument_list|()
control|)
block|{
name|ui
operator|->
name|style
operator|->
name|addItem
argument_list|(
name|styleName
argument_list|)
expr_stmt|;
if|if
condition|(
name|style
argument_list|()
operator|->
name|objectName
argument_list|()
operator|.
name|toLower
argument_list|()
operator|==
name|styleName
operator|.
name|toLower
argument_list|()
condition|)
name|ui
operator|->
name|style
operator|->
name|setCurrentIndex
argument_list|(
name|ui
operator|->
name|style
operator|->
name|count
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
name|ui
operator|->
name|layoutDirection
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|layoutDirectionChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|->
name|spacing
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|spacingChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|->
name|fontComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|currentFontChanged
argument_list|(
name|QFont
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|fontChanged
argument_list|(
name|QFont
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ui
operator|->
name|style
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|styleChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~EmbeddedDialog
name|EmbeddedDialog
operator|::
name|~
name|EmbeddedDialog
parameter_list|()
block|{
operator|delete
name|ui
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|layoutDirectionChanged
name|void
name|EmbeddedDialog
operator|::
name|layoutDirectionChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|setLayoutDirection
argument_list|(
name|index
operator|==
literal|0
condition|?
name|Qt
operator|::
name|LeftToRight
else|:
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|spacingChanged
name|void
name|EmbeddedDialog
operator|::
name|spacingChanged
parameter_list|(
name|int
name|spacing
parameter_list|)
block|{
name|layout
argument_list|()
operator|->
name|setSpacing
argument_list|(
name|spacing
argument_list|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fontChanged
name|void
name|EmbeddedDialog
operator|::
name|fontChanged
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setStyleHelper
specifier|static
name|void
name|setStyleHelper
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QStyle
modifier|*
name|style
parameter_list|)
block|{
name|widget
operator|->
name|setStyle
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setPalette
argument_list|(
name|style
operator|->
name|standardPalette
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QObject
modifier|*
name|child
decl|,
name|widget
operator|->
name|children
argument_list|()
control|)
block|{
if|if
condition|(
name|QWidget
modifier|*
name|childWidget
init|=
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|child
argument_list|)
condition|)
name|setStyleHelper
argument_list|(
name|childWidget
argument_list|,
name|style
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|styleChanged
name|void
name|EmbeddedDialog
operator|::
name|styleChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|styleName
parameter_list|)
block|{
name|QStyle
modifier|*
name|style
init|=
name|QStyleFactory
operator|::
name|create
argument_list|(
name|styleName
argument_list|)
decl_stmt|;
if|if
condition|(
name|style
condition|)
name|setStyleHelper
argument_list|(
name|this
argument_list|,
name|style
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
