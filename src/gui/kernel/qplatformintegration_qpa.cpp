begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformintegration_qpa.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformFontDatabase>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformClipboard>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformAccessibility>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qplatformscreen_qpa_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdnd_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     Accessor for the platform integration's fontdatabase.      Default implementation returns a default QPlatformFontDatabase.      \sa QPlatformFontDatabase */
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QPlatformIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
specifier|static
name|QPlatformFontDatabase
modifier|*
name|db
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|db
condition|)
block|{
name|db
operator|=
operator|new
name|QPlatformFontDatabase
expr_stmt|;
block|}
return|return
name|db
return|;
block|}
end_function
begin_comment
comment|/*!     Accessor for the platform integration's clipboard.      Default implementation returns a default QPlatformClipboard.      \sa QPlatformClipboard  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QPlatformIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
specifier|static
name|QPlatformClipboard
modifier|*
name|clipboard
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|clipboard
condition|)
block|{
name|clipboard
operator|=
operator|new
name|QPlatformClipboard
expr_stmt|;
block|}
return|return
name|clipboard
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_comment
comment|/*!     Accessor for the platform integration's drag object.      Default implementation returns 0, implying no drag and drop support.  */
end_comment
begin_function
DECL|function|drag
name|QPlatformDrag
modifier|*
name|QPlatformIntegration
operator|::
name|drag
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QPlatformIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \class QPlatformIntegration     \since 4.8     \internal     \preliminary     \ingroup qpa     \brief The QPlatformIntegration class is the entry for WindowSystem specific functionality.      QPlatformIntegration is the single entry point for windowsystem specific functionality when     using the QPA platform. It has factory functions for creating platform specific pixmaps and     windows. The class also controls the font subsystem.      QPlatformIntegration is a singleton class which gets instantiated in the QGuiApplication     constructor. The QPlatformIntegration instance do not have ownership of objects it creates in     functions where the name starts with create. However, functions which don't have a name     starting with create acts as accessors to member variables.      It is not trivial to create or build a platform plugin outside of the Qt source tree. Therefore     the recommended approach for making new platform plugin is to copy an existing plugin inside     the QTSRCTREE/src/plugins/platform and develop the plugin inside the source tree.      The minimal platform integration is the smallest platform integration it is possible to make,     which makes it an ideal starting point for new plugins. For a slightly more advanced plugin,     consider reviewing the directfb plugin, or the testlite plugin. */
end_comment
begin_comment
comment|/*!     \fn QPlatformPixmap *QPlatformIntegration::createPlatformPixmap(QPlatformPixmap::PixelType type) const      Factory function for QPlatformPixmap. PixelType can be either PixmapType or BitmapType.     \sa QPlatformPixmap */
end_comment
begin_comment
comment|/*!     \fn QPlatformWindow *QPlatformIntegration::createPlatformWindow(QWindow *window) const      Factory function for QPlatformWindow. The \a window parameter is a pointer to the top level     window which the QPlatformWindow is supposed to be created for.      All top level windows have to have a QPlatformWindow, and it will be created when the     QPlatformWindow is set to be visible for the first time. If the top level window's flags are     changed, or if the top level window's QPlatformWindowFormat is changed, then the top level     window's QPlatformWindow is deleted and a new one is created.      In the constructor, of the QPlatformWindow, the window flags, state, title and geometry     of the \a window should be applied to the underlying window. If the resulting flags or state     differs, the resulting values should be set on the \a window using QWindow::setWindowFlags()     or QWindow::setWindowState(), respectively.      \sa QPlatformWindow, QPlatformWindowFormat     \sa createPlatformBackingStore(QWindow *window) const */
end_comment
begin_comment
comment|/*!     \fn QPlatformBackingStore *QPlatformIntegration::createPlatformBackingStore(QWindow *window) const      Factory function for QPlatformBackingStore. The QWindow parameter is a pointer to the     top level widget(tlw) the window surface is created for. A QPlatformWindow is always created     before the QPlatformBackingStore for tlw where the widget also requires a backing store.      \sa QBackingStore     \sa createPlatformWindow(QWindow *window, WId winId = 0) const */
end_comment
begin_comment
comment|/*!     \enum QPlatformIntegration::Capability      Capabilities are used to determing specific features of a platform integration      \value ThreadedPixmaps The platform uses a pixmap implementation that is reentrant     and can be used from multiple threads, like the raster paint engine and QImage based     pixmaps.      \value OpenGL The platform supports OpenGL      \value ThreadedOpenGL The platform supports using OpenGL outside the GUI thread.      \value SharedGraphicsCache The platform supports a shared graphics cache      \value BufferQueueingOpenGL The OpenGL implementation on the platform will queue     up buffers when swapBuffers() is called and block only when its buffer pipeline     is full, rather than block immediately.  */
end_comment
begin_comment
comment|/*!      \fn QAbstractEventDispatcher *QPlatformIntegration::guiThreadEventDispatcher() const = 0      Accessor function for the event dispatcher. The platform plugin should create     an instance of the QAbstractEventDispatcher in its constructor and set it     on the application using QGuiApplicationPrivate::instance()->setEventDispatcher().     The event dispatcher is owned by QGuiApplication, the accessor should return     a flat pointer.     \sa QGuiApplicationPrivate */
end_comment
begin_function
DECL|function|hasCapability
name|bool
name|QPlatformIntegration
operator|::
name|hasCapability
parameter_list|(
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|cap
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createPlatformPixmap
name|QPlatformPixmap
modifier|*
name|QPlatformIntegration
operator|::
name|createPlatformPixmap
parameter_list|(
name|QPlatformPixmap
operator|::
name|PixelType
name|type
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QRasterPlatformPixmap
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QPlatformIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support createPlatformOpenGLContext!"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!    Factory function for QPlatformSharedGraphicsCache. This function will return 0 if the platform    integration does not support any shared graphics cache mechanism for the given \a cacheId. */
end_comment
begin_function
DECL|function|createPlatformSharedGraphicsCache
name|QPlatformSharedGraphicsCache
modifier|*
name|QPlatformIntegration
operator|::
name|createPlatformSharedGraphicsCache
parameter_list|(
specifier|const
name|char
modifier|*
name|cacheId
parameter_list|)
specifier|const
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support createPlatformSharedGraphicsBuffer for cacheId: %s!"
argument_list|,
name|cacheId
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the platforms input context.    The default implementation returns 0, implying no input method support. */
end_comment
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QPlatformIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the platforms accessibility.    The default implementation returns 0, implying no accessibility support. */
end_comment
begin_function
DECL|function|accessibility
name|QPlatformAccessibility
modifier|*
name|QPlatformIntegration
operator|::
name|accessibility
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QPlatformIntegration
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|CursorFlashTime
case|:
return|return
literal|1000
return|;
case|case
name|KeyboardInputInterval
case|:
return|return
literal|400
return|;
case|case
name|KeyboardAutoRepeatRate
case|:
return|return
literal|30
return|;
case|case
name|MouseDoubleClickInterval
case|:
return|return
literal|400
return|;
case|case
name|StartDragDistance
case|:
return|return
literal|10
return|;
case|case
name|StartDragTime
case|:
return|return
literal|500
return|;
case|case
name|ShowIsFullScreen
case|:
return|return
literal|false
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!   Should be called by the implementation whenever a new screen is added.    The first screen added will be the primary screen, used for default-created   windows, GL contexts, and other resources unless otherwise specified.    This adds the screen to QGuiApplication::screens(), and emits the   QGuiApplication::screenAdded() signal.    The screen is automatically removed when the QPlatformScreen is destroyed. */
end_comment
begin_function
DECL|function|screenAdded
name|void
name|QPlatformIntegration
operator|::
name|screenAdded
parameter_list|(
name|QPlatformScreen
modifier|*
name|ps
parameter_list|)
block|{
name|QScreen
modifier|*
name|screen
init|=
operator|new
name|QScreen
argument_list|(
name|ps
argument_list|)
decl_stmt|;
name|ps
operator|->
name|d_func
argument_list|()
operator|->
name|screen
operator|=
name|screen
expr_stmt|;
name|QGuiApplicationPrivate
operator|::
name|screen_list
operator|<<
name|screen
expr_stmt|;
emit|emit
name|qGuiApp
operator|->
name|screenAdded
argument_list|(
name|screen
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|platformTheme
name|class
name|QPlatformTheme
modifier|*
name|QPlatformIntegration
operator|::
name|platformTheme
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
