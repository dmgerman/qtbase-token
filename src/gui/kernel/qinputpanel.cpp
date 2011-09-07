begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qinputpanel.h>
end_include
begin_include
include|#
directive|include
file|<private/qinputpanel_p.h>
end_include
begin_include
include|#
directive|include
file|<qplatforminputcontext_qpa.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_constructor
DECL|function|QInputPanel
name|QInputPanel
operator|::
name|QInputPanel
parameter_list|()
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QInputPanelPrivate
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QInputPanel
name|QInputPanel
operator|::
name|~
name|QInputPanel
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|inputItem
name|QObject
modifier|*
name|QInputPanel
operator|::
name|inputItem
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputPanel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|inputItem
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setInputItem
name|void
name|QInputPanel
operator|::
name|setInputItem
parameter_list|(
name|QObject
modifier|*
name|inputItem
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QInputPanel
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|inputItem
operator|.
name|data
argument_list|()
operator|==
name|inputItem
condition|)
return|return;
name|d
operator|->
name|inputItem
operator|=
name|inputItem
expr_stmt|;
emit|emit
name|inputItemChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|inputWindow
name|QWindow
modifier|*
name|QInputPanel
operator|::
name|inputWindow
parameter_list|()
specifier|const
block|{
return|return
name|qApp
operator|->
name|activeWindow
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|inputItemTransform
name|QTransform
name|QInputPanel
operator|::
name|inputItemTransform
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputPanel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|inputItemTransform
return|;
block|}
end_function
begin_function
DECL|function|setInputItemTranform
name|void
name|QInputPanel
operator|::
name|setInputItemTranform
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|transform
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QInputPanel
argument_list|)
expr_stmt|;
name|d
operator|->
name|inputItemTransform
operator|=
name|transform
expr_stmt|;
emit|emit
name|cursorRectangleChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|cursorRectangle
name|QRectF
name|QInputPanel
operator|::
name|cursorRectangle
parameter_list|()
specifier|const
block|{
name|QInputMethodQueryEvent
name|query
argument_list|(
name|Qt
operator|::
name|ImMicroFocus
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|inputItem
argument_list|()
argument_list|,
operator|&
name|query
argument_list|)
expr_stmt|;
name|QRect
name|r
init|=
name|query
operator|.
name|value
argument_list|()
operator|.
name|toRect
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|r
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
name|Q_D
argument_list|(
specifier|const
name|QInputPanel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|inputItemTransform
operator|.
name|mapRect
argument_list|(
name|r
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|keyboardRectangle
name|QRectF
name|QInputPanel
operator|::
name|keyboardRectangle
parameter_list|()
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
return|return
name|ic
operator|->
name|keyboardRect
argument_list|()
return|;
return|return
name|QRectF
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|show
name|void
name|QInputPanel
operator|::
name|show
parameter_list|()
block|{
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hide
name|void
name|QInputPanel
operator|::
name|hide
parameter_list|()
block|{
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visible
name|bool
name|QInputPanel
operator|::
name|visible
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputPanel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|visible
return|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QInputPanel
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QInputPanel
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|visible
operator|==
name|visible
condition|)
return|return;
name|d
operator|->
name|visible
operator|=
name|visible
expr_stmt|;
emit|emit
name|visibleChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|isAnimating
name|bool
name|QInputPanel
operator|::
name|isAnimating
parameter_list|()
specifier|const
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
return|return
name|ic
operator|->
name|isAnimating
argument_list|()
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QInputPanel
operator|::
name|update
parameter_list|(
name|Qt
operator|::
name|InputMethodQueries
name|queries
parameter_list|)
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|update
argument_list|(
name|queries
argument_list|)
expr_stmt|;
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImMicroFocus
condition|)
emit|emit
name|cursorRectangleChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QInputPanel
operator|::
name|reset
parameter_list|()
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|commit
name|void
name|QInputPanel
operator|::
name|commit
parameter_list|()
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|commit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|invokeAction
name|void
name|QInputPanel
operator|::
name|invokeAction
parameter_list|(
name|Action
name|a
parameter_list|,
name|int
name|cursorPosition
parameter_list|)
block|{
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|invokeAction
argument_list|(
name|a
argument_list|,
name|cursorPosition
argument_list|)
expr_stmt|;
block|}
end_function
begin_include
include|#
directive|include
file|"moc_qinputpanel.cpp"
end_include
end_unit
