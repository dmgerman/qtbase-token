begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget.h"
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwidget_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|screenGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|screenGeometry
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|widget
condition|)
block|{
name|qWarning
argument_list|(
literal|"QDesktopWidget::screenGeometry(): Attempt "
literal|"to get the screen geometry of a null widget"
argument_list|)
expr_stmt|;
return|return
name|QRect
argument_list|()
return|;
block|}
name|QRect
name|rect
init|=
name|QWidgetPrivate
operator|::
name|screenGeometry
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|screenGeometry
argument_list|(
name|screenNumber
argument_list|(
name|widget
argument_list|)
argument_list|)
return|;
else|else
return|return
name|rect
return|;
block|}
end_function
begin_function
DECL|function|availableGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|availableGeometry
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|widget
condition|)
block|{
name|qWarning
argument_list|(
literal|"QDesktopWidget::availableGeometry(): Attempt "
literal|"to get the available geometry of a null widget"
argument_list|)
expr_stmt|;
return|return
name|QRect
argument_list|()
return|;
block|}
name|QRect
name|rect
init|=
name|QWidgetPrivate
operator|::
name|screenGeometry
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|availableGeometry
argument_list|(
name|screenNumber
argument_list|(
name|widget
argument_list|)
argument_list|)
return|;
else|else
return|return
name|rect
return|;
block|}
end_function
begin_function
DECL|function|_q_updateScreens
name|void
name|QDesktopWidgetPrivate
operator|::
name|_q_updateScreens
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QDesktopWidget
argument_list|)
expr_stmt|;
specifier|const
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screenList
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
specifier|const
name|int
name|targetLength
init|=
name|screenList
operator|.
name|length
argument_list|()
decl_stmt|;
specifier|const
name|int
name|oldLength
init|=
name|screens
operator|.
name|length
argument_list|()
decl_stmt|;
name|int
name|currentLength
init|=
name|oldLength
decl_stmt|;
comment|// Add or remove screen widgets as necessary
if|if
condition|(
name|currentLength
operator|>
name|targetLength
condition|)
block|{
name|QDesktopScreenWidget
modifier|*
name|screen
decl_stmt|;
while|while
condition|(
name|currentLength
operator|--
operator|>
name|targetLength
condition|)
block|{
name|screen
operator|=
name|screens
operator|.
name|takeLast
argument_list|()
expr_stmt|;
operator|delete
name|screen
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|currentLength
operator|<
name|targetLength
condition|)
block|{
while|while
condition|(
name|currentLength
operator|<
name|targetLength
condition|)
block|{
name|QScreen
modifier|*
name|qScreen
init|=
name|screenList
operator|.
name|at
argument_list|(
name|currentLength
argument_list|)
decl_stmt|;
name|QDesktopScreenWidget
modifier|*
name|screenWidget
init|=
operator|new
name|QDesktopScreenWidget
argument_list|(
name|currentLength
operator|++
argument_list|)
decl_stmt|;
name|screenWidget
operator|->
name|setGeometry
argument_list|(
name|qScreen
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|qScreen
argument_list|,
name|SIGNAL
argument_list|(
name|geometryChanged
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_updateScreens
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|qScreen
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_updateScreens
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|screens
operator|.
name|append
argument_list|(
name|screenWidget
argument_list|)
expr_stmt|;
block|}
block|}
name|QRegion
name|virtualGeometry
decl_stmt|;
comment|// update the geometry of each screen widget, determine virtual geometry
comment|// and emit change signals afterwards.
name|QList
argument_list|<
name|int
argument_list|>
name|changedScreens
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
name|screens
operator|.
name|length
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|QRect
name|screenGeometry
init|=
name|screenList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|geometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|screenGeometry
operator|!=
name|screens
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|geometry
argument_list|()
condition|)
block|{
name|screens
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|setGeometry
argument_list|(
name|screenGeometry
argument_list|)
expr_stmt|;
name|changedScreens
operator|.
name|push_back
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|virtualGeometry
operator|+=
name|screenGeometry
expr_stmt|;
block|}
name|q
operator|->
name|setGeometry
argument_list|(
name|virtualGeometry
operator|.
name|boundingRect
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|oldLength
operator|!=
name|targetLength
condition|)
emit|emit
name|q
operator|->
name|screenCountChanged
argument_list|(
name|targetLength
argument_list|)
emit|;
foreach|foreach
control|(
name|int
name|changedScreen
decl|,
name|changedScreens
control|)
block|{
emit|emit
name|q
operator|->
name|resized
argument_list|(
name|changedScreen
argument_list|)
emit|;
emit|emit
name|q
operator|->
name|workAreaResized
argument_list|(
name|changedScreen
argument_list|)
emit|;
block|}
block|}
end_function
begin_constructor
DECL|function|QDesktopWidget
name|QDesktopWidget
operator|::
name|QDesktopWidget
parameter_list|()
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QDesktopWidgetPrivate
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|Desktop
argument_list|)
block|{
name|Q_D
argument_list|(
name|QDesktopWidget
argument_list|)
expr_stmt|;
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"desktop"
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|_q_updateScreens
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|qApp
argument_list|,
name|SIGNAL
argument_list|(
name|screenAdded
argument_list|(
name|QScreen
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_updateScreens
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDesktopWidget
name|QDesktopWidget
operator|::
name|~
name|QDesktopWidget
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isVirtualDesktop
name|bool
name|QDesktopWidget
operator|::
name|isVirtualDesktop
parameter_list|()
specifier|const
block|{
return|return
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|virtualSiblings
argument_list|()
operator|.
name|size
argument_list|()
operator|>
literal|1
return|;
block|}
end_function
begin_function
DECL|function|primaryScreen
name|int
name|QDesktopWidget
operator|::
name|primaryScreen
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|numScreens
name|int
name|QDesktopWidget
operator|::
name|numScreens
parameter_list|()
specifier|const
block|{
return|return
name|qMax
argument_list|(
name|QGuiApplication
operator|::
name|screens
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screen
name|QWidget
modifier|*
name|QDesktopWidget
operator|::
name|screen
parameter_list|(
name|int
name|screen
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDesktopWidget
argument_list|)
expr_stmt|;
if|if
condition|(
name|screen
operator|<
literal|0
operator|||
name|screen
operator|>=
name|d
operator|->
name|screens
operator|.
name|length
argument_list|()
condition|)
return|return
name|d
operator|->
name|screens
operator|.
name|at
argument_list|(
literal|0
argument_list|)
return|;
return|return
name|d
operator|->
name|screens
operator|.
name|at
argument_list|(
name|screen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|availableGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|availableGeometry
parameter_list|(
name|int
name|screenNo
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
if|if
condition|(
name|screenNo
operator|==
operator|-
literal|1
condition|)
name|screenNo
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|screenNo
operator|<
literal|0
operator|||
name|screenNo
operator|>=
name|screens
operator|.
name|size
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
else|else
return|return
name|screens
operator|.
name|at
argument_list|(
name|screenNo
argument_list|)
operator|->
name|availableGeometry
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|screenGeometry
specifier|const
name|QRect
name|QDesktopWidget
operator|::
name|screenGeometry
parameter_list|(
name|int
name|screenNo
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
decl_stmt|;
if|if
condition|(
name|screenNo
operator|==
operator|-
literal|1
condition|)
name|screenNo
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|screenNo
operator|<
literal|0
operator|||
name|screenNo
operator|>=
name|screens
operator|.
name|size
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
else|else
return|return
name|screens
operator|.
name|at
argument_list|(
name|screenNo
argument_list|)
operator|->
name|geometry
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|screenNumber
name|int
name|QDesktopWidget
operator|::
name|screenNumber
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|w
condition|)
return|return
literal|0
return|;
name|QRect
name|frame
init|=
name|w
operator|->
name|frameGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|w
operator|->
name|isWindow
argument_list|()
condition|)
name|frame
operator|.
name|moveTopLeft
argument_list|(
name|w
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QPoint
name|midpoint
init|=
operator|(
name|frame
operator|.
name|topLeft
argument_list|()
operator|+
name|frame
operator|.
name|bottomRight
argument_list|()
operator|)
operator|/
literal|2
decl_stmt|;
return|return
name|screenNumber
argument_list|(
name|midpoint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|screenNumber
name|int
name|QDesktopWidget
operator|::
name|screenNumber
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
init|=
name|QGuiApplication
operator|::
name|screens
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
name|screens
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|screens
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|p
argument_list|)
condition|)
return|return
name|i
return|;
return|return
name|primaryScreen
argument_list|()
return|;
comment|//even better would be closest screen
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QDesktopWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qdesktopwidget.cpp"
end_include
end_unit
