begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowcontainer_p.h"
end_include
begin_include
include|#
directive|include
file|"qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QMdiSubWindow>
end_include
begin_include
include|#
directive|include
file|<QAbstractScrollArea>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWindowContainerPrivate
class|class
name|QWindowContainerPrivate
super|:
specifier|public
name|QWidgetPrivate
block|{
public|public:
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QWindowContainer
argument_list|)
DECL|function|QWindowContainerPrivate
name|QWindowContainerPrivate
parameter_list|()
member_init_list|:
name|window
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|oldFocusWindow
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|usesNativeWidgets
argument_list|(
literal|false
argument_list|)
block|{     }
DECL|function|~QWindowContainerPrivate
name|~
name|QWindowContainerPrivate
parameter_list|()
block|{ }
DECL|function|get
specifier|static
name|QWindowContainerPrivate
modifier|*
name|get
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
name|QWindowContainer
modifier|*
name|wc
init|=
name|qobject_cast
argument_list|<
name|QWindowContainer
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
decl_stmt|;
if|if
condition|(
name|wc
condition|)
return|return
name|wc
operator|->
name|d_func
argument_list|()
return|;
return|return
literal|0
return|;
block|}
DECL|function|updateGeometry
name|void
name|updateGeometry
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QWindowContainer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|q
operator|->
name|isWindow
argument_list|()
operator|&&
operator|(
name|q
operator|->
name|geometry
argument_list|()
operator|.
name|bottom
argument_list|()
operator|<=
literal|0
operator|||
name|q
operator|->
name|geometry
argument_list|()
operator|.
name|right
argument_list|()
operator|<=
literal|0
operator|)
condition|)
comment|/* Qt (e.g. QSplitter) sometimes prefer to hide a widget by *not* calling                setVisible(false). This is often done by setting its coordinates to a sufficiently                negative value so that its clipped outside the parent. Since a QWindow is not clipped                to widgets in general, it needs to be dealt with as a special case.             */
name|window
operator|->
name|setGeometry
argument_list|(
name|q
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|usesNativeWidgets
condition|)
name|window
operator|->
name|setGeometry
argument_list|(
name|q
operator|->
name|rect
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|window
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|q
operator|->
name|mapTo
argument_list|(
name|q
operator|->
name|window
argument_list|()
argument_list|,
name|QPoint
argument_list|()
argument_list|)
argument_list|,
name|q
operator|->
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|updateUsesNativeWidgets
name|void
name|updateUsesNativeWidgets
parameter_list|()
block|{
if|if
condition|(
name|usesNativeWidgets
operator|||
name|window
operator|->
name|parent
argument_list|()
operator|==
literal|0
condition|)
return|return;
name|Q_Q
argument_list|(
name|QWindowContainer
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|internalWinId
argument_list|()
condition|)
block|{
comment|// Allow use native widgets if the window container is already a native widget
name|usesNativeWidgets
operator|=
literal|true
expr_stmt|;
return|return;
block|}
name|QWidget
modifier|*
name|p
init|=
name|q
operator|->
name|parentWidget
argument_list|()
decl_stmt|;
while|while
condition|(
name|p
condition|)
block|{
if|if
condition|(
ifndef|#
directive|ifndef
name|QT_NO_MDIAREA
name|qobject_cast
argument_list|<
name|QMdiSubWindow
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
operator|!=
literal|0
operator|||
endif|#
directive|endif
name|qobject_cast
argument_list|<
name|QAbstractScrollArea
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|q
operator|->
name|winId
argument_list|()
expr_stmt|;
name|usesNativeWidgets
operator|=
literal|true
expr_stmt|;
break|break;
block|}
name|p
operator|=
name|p
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|markParentChain
name|void
name|markParentChain
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QWindowContainer
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|p
init|=
name|q
decl_stmt|;
while|while
condition|(
name|p
condition|)
block|{
name|QWidgetPrivate
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QWidgetPrivate
operator|*
argument_list|>
argument_list|(
name|QWidgetPrivate
operator|::
name|get
argument_list|(
name|p
argument_list|)
argument_list|)
decl_stmt|;
name|d
operator|->
name|createExtra
argument_list|()
expr_stmt|;
name|d
operator|->
name|extra
operator|->
name|hasWindowContainer
operator|=
literal|true
expr_stmt|;
name|p
operator|=
name|p
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|isStillAnOrphan
name|bool
name|isStillAnOrphan
parameter_list|()
specifier|const
block|{
return|return
name|window
operator|->
name|parent
argument_list|()
operator|==
operator|&
name|fakeParent
return|;
block|}
DECL|member|window
name|QPointer
argument_list|<
name|QWindow
argument_list|>
name|window
decl_stmt|;
DECL|member|oldFocusWindow
name|QWindow
modifier|*
name|oldFocusWindow
decl_stmt|;
DECL|member|fakeParent
name|QWindow
name|fakeParent
decl_stmt|;
name|uint
name|usesNativeWidgets
range|:
literal|1
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \fn QWidget *QWidget::createWindowContainer(QWindow *window, QWidget *parent, Qt::WindowFlags flags);      Creates a QWidget that makes it possible to embed \a window into     a QWidget-based application.      The window container is created as a child of \a parent and with     window flags \a flags.      Once the window has been embedded into the container, the     container will control the window's geometry and     visibility. Explicit calls to QWindow::setGeometry(),     QWindow::show() or QWindow::hide() on an embedded window is not     recommended.      The container takes over ownership of \a window. The window can     be removed from the window container with a call to     QWindow::setParent().      The window container is attached as a native child window to the     toplevel window it is a child of. When a window container is used     as a child of a QAbstractScrollArea or QMdiArea, it will     create a \l {Native Widgets vs Alien Widgets} {native window} for     every widget in its parent chain to allow for proper stacking and     clipping in this use case. Creating a native window for the window     container also allows for proper stacking and clipping. This must     be done before showing the window container. Applications with     many native child windows may suffer from performance issues.      The window container has a number of known limitations:      \list      \li Stacking order; The embedded window will stack on top of the     widget hierarchy as an opaque box. The stacking order of multiple     overlapping window container instances is undefined.      \li Rendering Integration; The window container does not interoperate     with QGraphicsProxyWidget, QWidget::render() or similar functionality.      \li Focus Handling; It is possible to let the window container     instance have any focus policy and it will delegate focus to the     window via a call to QWindow::requestActivate(). However,     returning to the normal focus chain from the QWindow instance will     be up to the QWindow instance implementation itself. For instance,     when entering a Qt Quick based window with tab focus, it is quite     likely that further tab presses will only cycle inside the QML     application. Also, whether QWindow::requestActivate() actually     gives the window focus, is platform dependent.      \li Using many window container instances in a QWidget-based     application can greatly hurt the overall performance of the     application.      \endlist  */
end_comment
begin_function
DECL|function|createWindowContainer
name|QWidget
modifier|*
name|QWidget
operator|::
name|createWindowContainer
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
return|return
operator|new
name|QWindowContainer
argument_list|(
name|window
argument_list|,
name|parent
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_constructor
DECL|function|QWindowContainer
name|QWindowContainer
operator|::
name|QWindowContainer
parameter_list|(
name|QWindow
modifier|*
name|embeddedWindow
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QWindowContainerPrivate
argument_list|,
name|parent
argument_list|,
name|flags
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWindowContainer
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|embeddedWindow
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWindowContainer: embedded window cannot be null"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// The embedded QWindow must use the same logic as QWidget when it comes to the surface type.
comment|// Otherwise we may end up with BadMatch failures on X11.
if|if
condition|(
name|embeddedWindow
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterSurface
operator|&&
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|hasCapability
argument_list|(
name|QPlatformIntegration
operator|::
name|RasterGLSurface
argument_list|)
operator|&&
operator|!
name|QApplication
operator|::
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_ForceRasterWidgets
argument_list|)
condition|)
name|embeddedWindow
operator|->
name|setSurfaceType
argument_list|(
name|QSurface
operator|::
name|RasterGLSurface
argument_list|)
expr_stmt|;
name|d
operator|->
name|window
operator|=
name|embeddedWindow
expr_stmt|;
name|d
operator|->
name|window
operator|->
name|setParent
argument_list|(
operator|&
name|d
operator|->
name|fakeParent
argument_list|)
expr_stmt|;
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|QGuiApplication
operator|::
name|instance
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|focusWindowChanged
argument_list|(
name|QWindow
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|focusWindowChanged
argument_list|(
name|QWindow
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|containedWindow
name|QWindow
modifier|*
name|QWindowContainer
operator|::
name|containedWindow
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowContainer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|window
return|;
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_destructor
DECL|function|~QWindowContainer
name|QWindowContainer
operator|::
name|~
name|QWindowContainer
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindowContainer
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|window
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|focusWindowChanged
name|void
name|QWindowContainer
operator|::
name|focusWindowChanged
parameter_list|(
name|QWindow
modifier|*
name|focusWindow
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindowContainer
argument_list|)
expr_stmt|;
name|d
operator|->
name|oldFocusWindow
operator|=
name|focusWindow
expr_stmt|;
if|if
condition|(
name|focusWindow
operator|==
name|d
operator|->
name|window
condition|)
block|{
name|QWidget
modifier|*
name|widget
init|=
name|QApplication
operator|::
name|focusWidget
argument_list|()
decl_stmt|;
if|if
condition|(
name|widget
condition|)
name|widget
operator|->
name|clearFocus
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_function
DECL|function|event
name|bool
name|QWindowContainer
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindowContainer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|window
condition|)
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
name|QEvent
operator|::
name|Type
name|type
init|=
name|e
operator|->
name|type
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QEvent
operator|::
name|ChildRemoved
case|:
block|{
name|QChildEvent
modifier|*
name|ce
init|=
cast|static_cast
argument_list|<
name|QChildEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
if|if
condition|(
name|ce
operator|->
name|child
argument_list|()
operator|==
name|d
operator|->
name|window
condition|)
name|d
operator|->
name|window
operator|=
literal|0
expr_stmt|;
break|break;
block|}
comment|// The only thing we are interested in is making sure our sizes stay
comment|// in sync, so do a catch-all case.
case|case
name|QEvent
operator|::
name|Resize
case|:
name|d
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Move
case|:
name|d
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|PolishRequest
case|:
name|d
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|Show
case|:
name|d
operator|->
name|updateUsesNativeWidgets
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|isStillAnOrphan
argument_list|()
condition|)
block|{
name|d
operator|->
name|window
operator|->
name|setParent
argument_list|(
name|d
operator|->
name|usesNativeWidgets
condition|?
name|windowHandle
argument_list|()
else|:
name|window
argument_list|()
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
condition|)
block|{
name|d
operator|->
name|markParentChain
argument_list|()
expr_stmt|;
name|d
operator|->
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|QEvent
operator|::
name|Hide
case|:
if|if
condition|(
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
condition|)
name|d
operator|->
name|window
operator|->
name|hide
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|FocusIn
case|:
if|if
condition|(
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|oldFocusWindow
operator|!=
name|d
operator|->
name|window
condition|)
block|{
name|d
operator|->
name|window
operator|->
name|requestActivate
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QWidget
modifier|*
name|next
init|=
name|nextInFocusChain
argument_list|()
decl_stmt|;
name|next
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
block|}
break|break;
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
case|case
name|QEvent
operator|::
name|Drop
case|:
case|case
name|QEvent
operator|::
name|DragMove
case|:
case|case
name|QEvent
operator|::
name|DragLeave
case|:
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|d
operator|->
name|window
argument_list|,
name|e
argument_list|)
expr_stmt|;
return|return
name|e
operator|->
name|isAccepted
argument_list|()
return|;
case|case
name|QEvent
operator|::
name|DragEnter
case|:
comment|// Don't reject drag events for the entire widget when one
comment|// item rejects the drag enter
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|d
operator|->
name|window
argument_list|,
name|e
argument_list|)
expr_stmt|;
name|e
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
endif|#
directive|endif
default|default:
break|break;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_typedef
DECL|typedef|qwindowcontainer_traverse_callback
typedef|typedef
name|void
function_decl|(
modifier|*
name|qwindowcontainer_traverse_callback
function_decl|)
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
function_decl|;
end_typedef
begin_function
DECL|function|qwindowcontainer_traverse
specifier|static
name|void
name|qwindowcontainer_traverse
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|qwindowcontainer_traverse_callback
name|callback
parameter_list|)
block|{
specifier|const
name|QObjectList
modifier|&
name|children
init|=
name|parent
operator|->
name|children
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
name|children
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|children
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|w
condition|)
block|{
name|QWidgetPrivate
modifier|*
name|wd
init|=
cast|static_cast
argument_list|<
name|QWidgetPrivate
operator|*
argument_list|>
argument_list|(
name|QWidgetPrivate
operator|::
name|get
argument_list|(
name|w
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|wd
operator|->
name|extra
operator|&&
name|wd
operator|->
name|extra
operator|->
name|hasWindowContainer
condition|)
name|callback
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|toplevelAboutToBeDestroyed
name|void
name|QWindowContainer
operator|::
name|toplevelAboutToBeDestroyed
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
if|if
condition|(
name|QWindowContainerPrivate
modifier|*
name|d
init|=
name|QWindowContainerPrivate
operator|::
name|get
argument_list|(
name|parent
argument_list|)
condition|)
block|{
name|d
operator|->
name|window
operator|->
name|setParent
argument_list|(
operator|&
name|d
operator|->
name|fakeParent
argument_list|)
expr_stmt|;
block|}
name|qwindowcontainer_traverse
argument_list|(
name|parent
argument_list|,
name|toplevelAboutToBeDestroyed
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parentWasChanged
name|void
name|QWindowContainer
operator|::
name|parentWasChanged
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
if|if
condition|(
name|QWindowContainerPrivate
modifier|*
name|d
init|=
name|QWindowContainerPrivate
operator|::
name|get
argument_list|(
name|parent
argument_list|)
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
condition|)
block|{
name|d
operator|->
name|updateUsesNativeWidgets
argument_list|()
expr_stmt|;
name|d
operator|->
name|markParentChain
argument_list|()
expr_stmt|;
name|QWidget
modifier|*
name|toplevel
init|=
name|d
operator|->
name|usesNativeWidgets
condition|?
name|parent
else|:
name|parent
operator|->
name|window
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|toplevel
operator|->
name|windowHandle
argument_list|()
condition|)
block|{
name|QWidgetPrivate
modifier|*
name|tld
init|=
cast|static_cast
argument_list|<
name|QWidgetPrivate
operator|*
argument_list|>
argument_list|(
name|QWidgetPrivate
operator|::
name|get
argument_list|(
name|toplevel
argument_list|)
argument_list|)
decl_stmt|;
name|tld
operator|->
name|createTLExtra
argument_list|()
expr_stmt|;
name|tld
operator|->
name|createTLSysExtra
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|toplevel
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|window
operator|->
name|setParent
argument_list|(
name|toplevel
operator|->
name|windowHandle
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
block|}
name|qwindowcontainer_traverse
argument_list|(
name|parent
argument_list|,
name|parentWasChanged
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parentWasMoved
name|void
name|QWindowContainer
operator|::
name|parentWasMoved
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
if|if
condition|(
name|QWindowContainerPrivate
modifier|*
name|d
init|=
name|QWindowContainerPrivate
operator|::
name|get
argument_list|(
name|parent
argument_list|)
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
condition|)
name|d
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
name|qwindowcontainer_traverse
argument_list|(
name|parent
argument_list|,
name|parentWasMoved
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parentWasRaised
name|void
name|QWindowContainer
operator|::
name|parentWasRaised
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
if|if
condition|(
name|QWindowContainerPrivate
modifier|*
name|d
init|=
name|QWindowContainerPrivate
operator|::
name|get
argument_list|(
name|parent
argument_list|)
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
condition|)
name|d
operator|->
name|window
operator|->
name|raise
argument_list|()
expr_stmt|;
block|}
name|qwindowcontainer_traverse
argument_list|(
name|parent
argument_list|,
name|parentWasRaised
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parentWasLowered
name|void
name|QWindowContainer
operator|::
name|parentWasLowered
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
if|if
condition|(
name|QWindowContainerPrivate
modifier|*
name|d
init|=
name|QWindowContainerPrivate
operator|::
name|get
argument_list|(
name|parent
argument_list|)
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|window
operator|->
name|parent
argument_list|()
condition|)
name|d
operator|->
name|window
operator|->
name|lower
argument_list|()
expr_stmt|;
block|}
name|qwindowcontainer_traverse
argument_list|(
name|parent
argument_list|,
name|parentWasLowered
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qwindowcontainer_p.cpp"
end_include
end_unit
