begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qwindowseglcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_elif
begin_include
include|#
directive|include
file|"qwindowsglcontext.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qwindowsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwindowstheme.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsservices.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FREETYPE
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsfontdatabase_ft.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qwindowsfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsguieventdispatcher.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsclipboard.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qwindowsdrag.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsinputcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowskeymapper.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"accessible/qwindowsaccessibility.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QBackingStore>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qpixmap_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qeventdispatcher_win_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWindowsNativeInterface     \brief Provides access to native handles.      Currently implemented keys     \list     \li handle (HWND)     \li getDC (DC)     \li releaseDC Releases the previously acquired DC and returns 0.     \endlist      \internal     \ingroup qt-lighthouse-win */
end_comment
begin_class
DECL|class|QWindowsNativeInterface
class|class
name|QWindowsNativeInterface
super|:
specifier|public
name|QPlatformNativeInterface
block|{
name|Q_OBJECT
public|public:
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
specifier|virtual
name|void
modifier|*
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
endif|#
directive|endif
specifier|virtual
name|void
modifier|*
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
specifier|virtual
name|void
modifier|*
name|nativeResourceForBackingStore
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QBackingStore
modifier|*
name|bs
parameter_list|)
function_decl|;
name|Q_INVOKABLE
name|void
modifier|*
name|createMessageWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|classNameTemplate
parameter_list|,
specifier|const
name|QString
modifier|&
name|windowName
parameter_list|,
name|void
modifier|*
name|eventProc
parameter_list|)
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
name|window
operator|||
operator|!
name|window
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null window or window without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QWindowsWindow
modifier|*
name|bw
init|=
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resource
operator|==
literal|"handle"
condition|)
return|return
name|bw
operator|->
name|handle
argument_list|()
return|;
if|if
condition|(
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QWindow
operator|::
name|RasterSurface
condition|)
block|{
if|if
condition|(
name|resource
operator|==
literal|"getDC"
condition|)
return|return
name|bw
operator|->
name|getDC
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
literal|"releaseDC"
condition|)
block|{
name|bw
operator|->
name|releaseDC
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForBackingStore
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|nativeResourceForBackingStore
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QBackingStore
modifier|*
name|bs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|bs
operator|||
operator|!
name|bs
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null backingstore or backingstore without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QWindowsBackingStore
modifier|*
name|wbs
init|=
cast|static_cast
argument_list|<
name|QWindowsBackingStore
operator|*
argument_list|>
argument_list|(
name|bs
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resource
operator|==
literal|"getDC"
condition|)
return|return
name|wbs
operator|->
name|getDC
argument_list|()
return|;
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
if|if
condition|(
operator|!
name|context
operator|||
operator|!
name|context
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null context or context without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
name|QWindowsEGLContext
modifier|*
name|windowsEglContext
init|=
cast|static_cast
argument_list|<
name|QWindowsEGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"eglDisplay"
argument_list|)
condition|)
return|return
name|windowsEglContext
operator|->
name|eglDisplay
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"eglContext"
argument_list|)
condition|)
return|return
name|windowsEglContext
operator|->
name|eglContext
argument_list|()
return|;
if|if
condition|(
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"eglConfig"
argument_list|)
condition|)
return|return
name|windowsEglContext
operator|->
name|eglConfig
argument_list|()
return|;
else|#
directive|else
comment|// QT_OPENGL_ES_2
name|QWindowsGLContext
modifier|*
name|windowsContext
init|=
cast|static_cast
argument_list|<
name|QWindowsGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|resource
operator|==
name|QByteArrayLiteral
argument_list|(
literal|"renderingContext"
argument_list|)
condition|)
return|return
name|windowsContext
operator|->
name|renderingContext
argument_list|()
return|;
endif|#
directive|endif
comment|// !QT_OPENGL_ES_2
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_OPENGL
end_comment
begin_comment
comment|/*!     \brief Creates a non-visible window handle for filtering messages. */
end_comment
begin_function
DECL|function|createMessageWindow
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|createMessageWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|classNameTemplate
parameter_list|,
specifier|const
name|QString
modifier|&
name|windowName
parameter_list|,
name|void
modifier|*
name|eventProc
parameter_list|)
specifier|const
block|{
name|QWindowsContext
modifier|*
name|ctx
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
decl_stmt|;
specifier|const
name|HWND
name|hwnd
init|=
name|ctx
operator|->
name|createDummyWindow
argument_list|(
name|classNameTemplate
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|windowName
operator|.
name|utf16
argument_list|()
argument_list|,
operator|(
name|WNDPROC
operator|)
name|eventProc
argument_list|)
decl_stmt|;
return|return
name|hwnd
return|;
block|}
end_function
begin_comment
comment|/*!     \class QWindowsIntegration     \brief QPlatformIntegration implementation for Windows.     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_struct
DECL|struct|QWindowsIntegrationPrivate
struct|struct
name|QWindowsIntegrationPrivate
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
DECL|typedef|QEGLStaticContextPtr
typedef|typedef
name|QSharedPointer
argument_list|<
name|QWindowsEGLStaticContext
argument_list|>
name|QEGLStaticContextPtr
typedef|;
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
typedef|typedef
name|QSharedPointer
argument_list|<
name|QOpenGLStaticContext
argument_list|>
name|QOpenGLStaticContextPtr
typedef|;
endif|#
directive|endif
name|QWindowsIntegrationPrivate
parameter_list|()
constructor_decl|;
name|~
name|QWindowsIntegrationPrivate
parameter_list|()
destructor_decl|;
DECL|member|m_context
name|QWindowsContext
name|m_context
decl_stmt|;
DECL|member|m_fontDatabase
name|QPlatformFontDatabase
modifier|*
name|m_fontDatabase
decl_stmt|;
DECL|member|m_nativeInterface
name|QWindowsNativeInterface
name|m_nativeInterface
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
DECL|member|m_clipboard
name|QWindowsClipboard
name|m_clipboard
decl_stmt|;
endif|#
directive|endif
DECL|member|m_drag
name|QWindowsDrag
name|m_drag
decl_stmt|;
DECL|member|m_eventDispatcher
name|QWindowsGuiEventDispatcher
modifier|*
name|m_eventDispatcher
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
DECL|member|m_staticEGLContext
name|QEGLStaticContextPtr
name|m_staticEGLContext
decl_stmt|;
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
DECL|member|m_staticOpenGLContext
name|QOpenGLStaticContextPtr
name|m_staticOpenGLContext
decl_stmt|;
endif|#
directive|endif
DECL|member|m_inputContext
name|QWindowsInputContext
name|m_inputContext
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
DECL|member|m_accessibility
name|QWindowsAccessibility
name|m_accessibility
decl_stmt|;
endif|#
directive|endif
DECL|member|m_services
name|QWindowsServices
name|m_services
decl_stmt|;
block|}
struct|;
end_struct
begin_constructor
DECL|function|QWindowsIntegrationPrivate
name|QWindowsIntegrationPrivate
operator|::
name|QWindowsIntegrationPrivate
parameter_list|()
member_init_list|:
name|m_fontDatabase
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_eventDispatcher
argument_list|(
operator|new
name|QWindowsGuiEventDispatcher
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QWindowsIntegrationPrivate
name|QWindowsIntegrationPrivate
operator|::
name|~
name|QWindowsIntegrationPrivate
parameter_list|()
block|{
if|if
condition|(
name|m_fontDatabase
condition|)
operator|delete
name|m_fontDatabase
expr_stmt|;
block|}
end_destructor
begin_constructor
DECL|function|QWindowsIntegration
name|QWindowsIntegration
operator|::
name|QWindowsIntegration
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QWindowsIntegrationPrivate
argument_list|)
block|{
name|QGuiApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|setEventDispatcher
argument_list|(
name|d
operator|->
name|m_eventDispatcher
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|d
operator|->
name|m_clipboard
operator|.
name|registerViewer
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|d
operator|->
name|m_context
operator|.
name|screenManager
argument_list|()
operator|.
name|handleScreenChanges
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsIntegration
name|QWindowsIntegration
operator|::
name|~
name|QWindowsIntegration
parameter_list|()
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|hasCapability
name|bool
name|QWindowsIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
case|case
name|OpenGL
case|:
return|return
literal|true
return|;
case|case
name|ThreadedOpenGL
case|:
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
return|return
name|QWindowsEGLContext
operator|::
name|hasThreadedOpenGLCapability
argument_list|()
return|;
else|#
directive|else
return|return
literal|true
return|;
endif|#
directive|endif
comment|// QT_OPENGL_ES_2
endif|#
directive|endif
comment|// !QT_NO_OPENGL
case|case
name|WindowMasks
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createPlatformPixmap
name|QPlatformPixmap
modifier|*
name|QWindowsIntegration
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
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QWindowsIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QWindowsWindow
operator|::
name|WindowData
name|requested
decl_stmt|;
name|requested
operator|.
name|flags
operator|=
name|window
operator|->
name|windowFlags
argument_list|()
expr_stmt|;
name|requested
operator|.
name|geometry
operator|=
name|window
operator|->
name|geometry
argument_list|()
expr_stmt|;
specifier|const
name|QWindowsWindow
operator|::
name|WindowData
name|obtained
init|=
name|QWindowsWindow
operator|::
name|WindowData
operator|::
name|create
argument_list|(
name|window
argument_list|,
name|requested
argument_list|,
name|window
operator|->
name|windowTitle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
operator|||
name|QWindowsContext
operator|::
name|verboseWindows
condition|)
name|qDebug
argument_list|()
operator|.
name|nospace
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|'<'
operator|<<
name|window
operator|<<
literal|'\n'
operator|<<
literal|"    Requested: "
operator|<<
name|requested
operator|.
name|geometry
operator|<<
literal|"frame incl.: "
operator|<<
name|QWindowsGeometryHint
operator|::
name|positionIncludesFrame
argument_list|(
name|window
argument_list|)
operator|<<
literal|" Flags="
operator|<<
name|QWindowsWindow
operator|::
name|debugWindowFlags
argument_list|(
name|requested
operator|.
name|flags
argument_list|)
operator|<<
literal|'\n'
operator|<<
literal|"    Obtained : "
operator|<<
name|obtained
operator|.
name|geometry
operator|<<
literal|" Margins "
operator|<<
name|obtained
operator|.
name|frame
operator|<<
literal|" Flags="
operator|<<
name|QWindowsWindow
operator|::
name|debugWindowFlags
argument_list|(
name|obtained
operator|.
name|flags
argument_list|)
operator|<<
literal|" Handle="
operator|<<
name|obtained
operator|.
name|hwnd
operator|<<
literal|'\n'
expr_stmt|;
if|if
condition|(
operator|!
name|obtained
operator|.
name|hwnd
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|requested
operator|.
name|flags
operator|!=
name|obtained
operator|.
name|flags
condition|)
name|window
operator|->
name|setWindowFlags
argument_list|(
name|obtained
operator|.
name|flags
argument_list|)
expr_stmt|;
return|return
operator|new
name|QWindowsWindow
argument_list|(
name|window
argument_list|,
name|obtained
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QWindowsIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|window
expr_stmt|;
return|return
operator|new
name|QWindowsBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_function
name|QPlatformOpenGLContext
DECL|function|createPlatformOpenGLContext
modifier|*
name|QWindowsIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseIntegration
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|context
operator|->
name|format
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_OPENGL_ES_2
if|if
condition|(
name|d
operator|->
name|m_staticEGLContext
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QWindowsEGLStaticContext
modifier|*
name|staticContext
init|=
name|QWindowsEGLStaticContext
operator|::
name|create
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|staticContext
condition|)
return|return
literal|0
return|;
name|d
operator|->
name|m_staticEGLContext
operator|=
name|QSharedPointer
argument_list|<
name|QWindowsEGLStaticContext
argument_list|>
argument_list|(
name|staticContext
argument_list|)
expr_stmt|;
block|}
return|return
operator|new
name|QWindowsEGLContext
argument_list|(
name|d
operator|->
name|m_staticEGLContext
argument_list|,
name|context
operator|->
name|format
argument_list|()
argument_list|,
name|context
operator|->
name|handle
argument_list|()
argument_list|)
return|;
else|#
directive|else
comment|// QT_OPENGL_ES_2
if|if
condition|(
name|d
operator|->
name|m_staticOpenGLContext
operator|.
name|isNull
argument_list|()
condition|)
name|d
operator|->
name|m_staticOpenGLContext
operator|=
name|QSharedPointer
argument_list|<
name|QOpenGLStaticContext
argument_list|>
argument_list|(
name|QOpenGLStaticContext
operator|::
name|create
argument_list|()
argument_list|)
expr_stmt|;
name|QScopedPointer
argument_list|<
name|QWindowsGLContext
argument_list|>
name|result
argument_list|(
operator|new
name|QWindowsGLContext
argument_list|(
name|d
operator|->
name|m_staticOpenGLContext
argument_list|,
name|context
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|->
name|isValid
argument_list|()
condition|)
return|return
name|result
operator|.
name|take
argument_list|()
return|;
return|return
literal|0
return|;
endif|#
directive|endif
comment|// !QT_OPENGL_ES_2
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_OPENGL
end_comment
begin_comment
comment|/* Workaround for QTBUG-24205: In 'Auto', pick the FreeType engine for  * QML2 applications. */
end_comment
begin_enum
DECL|enum|FontDatabaseOption
enum|enum
name|FontDatabaseOption
block|{
DECL|enumerator|FontDatabaseFreeType
name|FontDatabaseFreeType
block|,
DECL|enumerator|FontDatabaseNative
name|FontDatabaseNative
block|}
enum|;
end_enum
begin_function
DECL|function|fontDatabaseOption
specifier|static
specifier|inline
name|FontDatabaseOption
name|fontDatabaseOption
parameter_list|(
specifier|const
name|QObject
modifier|&
name|nativeInterface
parameter_list|)
block|{
specifier|const
name|QVariant
name|argumentV
init|=
name|nativeInterface
operator|.
name|property
argument_list|(
literal|"fontengine"
argument_list|)
decl_stmt|;
if|if
condition|(
name|argumentV
operator|.
name|isValid
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|argument
init|=
name|argumentV
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|argument
operator|==
name|QLatin1String
argument_list|(
literal|"freetype"
argument_list|)
condition|)
return|return
name|FontDatabaseFreeType
return|;
if|if
condition|(
name|argument
operator|==
name|QLatin1String
argument_list|(
literal|"native"
argument_list|)
condition|)
return|return
name|FontDatabaseNative
return|;
block|}
return|return
name|FontDatabaseNative
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QWindowsIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|m_fontDatabase
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_NO_FREETYPE
name|d
operator|->
name|m_fontDatabase
operator|=
operator|new
name|QWindowsFontDatabase
argument_list|()
expr_stmt|;
else|#
directive|else
name|FontDatabaseOption
name|option
init|=
name|fontDatabaseOption
argument_list|(
name|d
operator|->
name|m_nativeInterface
argument_list|)
decl_stmt|;
if|if
condition|(
name|option
operator|==
name|FontDatabaseFreeType
condition|)
block|{
name|d
operator|->
name|m_fontDatabase
operator|=
operator|new
name|QWindowsFontDatabaseFT
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|m_fontDatabase
operator|=
operator|new
name|QWindowsFontDatabase
expr_stmt|;
block|}
endif|#
directive|endif
block|}
return|return
name|d
operator|->
name|m_fontDatabase
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|SPI_GETKEYBOARDSPEED
end_ifdef
begin_function
DECL|function|keyBoardAutoRepeatRateMS
specifier|static
specifier|inline
name|int
name|keyBoardAutoRepeatRateMS
parameter_list|()
block|{
name|DWORD
name|time
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|SystemParametersInfo
argument_list|(
name|SPI_GETKEYBOARDSPEED
argument_list|,
literal|0
argument_list|,
operator|&
name|time
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|time
condition|?
literal|1000
operator|/
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|time
argument_list|)
else|:
literal|500
return|;
return|return
literal|30
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|styleHint
name|QVariant
name|QWindowsIntegration
operator|::
name|styleHint
parameter_list|(
name|QPlatformIntegration
operator|::
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
name|QPlatformIntegration
operator|::
name|CursorFlashTime
case|:
if|if
condition|(
specifier|const
name|unsigned
name|timeMS
init|=
name|GetCaretBlinkTime
argument_list|()
condition|)
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
name|timeMS
argument_list|)
argument_list|)
return|;
break|break;
ifdef|#
directive|ifdef
name|SPI_GETKEYBOARDSPEED
case|case
name|KeyboardAutoRepeatRate
case|:
return|return
name|QVariant
argument_list|(
name|keyBoardAutoRepeatRateMS
argument_list|()
argument_list|)
return|;
endif|#
directive|endif
case|case
name|QPlatformIntegration
operator|::
name|StartDragTime
case|:
case|case
name|QPlatformIntegration
operator|::
name|StartDragDistance
case|:
case|case
name|QPlatformIntegration
operator|::
name|KeyboardInputInterval
case|:
case|case
name|QPlatformIntegration
operator|::
name|ShowIsFullScreen
case|:
case|case
name|QPlatformIntegration
operator|::
name|PasswordMaskDelay
case|:
case|case
name|QPlatformIntegration
operator|::
name|StartDragVelocity
case|:
break|break;
comment|// Not implemented
case|case
name|QPlatformIntegration
operator|::
name|FontSmoothingGamma
case|:
return|return
name|QVariant
argument_list|(
name|QWindowsFontDatabase
operator|::
name|fontSmoothingGamma
argument_list|()
argument_list|)
return|;
case|case
name|QPlatformIntegration
operator|::
name|MouseDoubleClickInterval
case|:
if|if
condition|(
specifier|const
name|int
name|ms
init|=
name|GetDoubleClickTime
argument_list|()
condition|)
return|return
name|QVariant
argument_list|(
name|ms
argument_list|)
return|;
break|break;
case|case
name|QPlatformIntegration
operator|::
name|UseRtlExtensions
case|:
return|return
name|QVariant
argument_list|(
name|d
operator|->
name|m_context
operator|.
name|useRTLExtensions
argument_list|()
argument_list|)
return|;
block|}
return|return
name|QPlatformIntegration
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|queryKeyboardModifiers
name|Qt
operator|::
name|KeyboardModifiers
name|QWindowsIntegration
operator|::
name|queryKeyboardModifiers
parameter_list|()
specifier|const
block|{
return|return
name|QWindowsKeyMapper
operator|::
name|queryKeyboardModifiers
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|nativeInterface
name|QPlatformNativeInterface
modifier|*
name|QWindowsIntegration
operator|::
name|nativeInterface
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_nativeInterface
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QWindowsIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_clipboard
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_CLIPBOARD
end_comment
begin_function
DECL|function|drag
name|QPlatformDrag
modifier|*
name|QWindowsIntegration
operator|::
name|drag
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_drag
return|;
block|}
end_function
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QWindowsIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_inputContext
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_function
DECL|function|accessibility
name|QPlatformAccessibility
modifier|*
name|QWindowsIntegration
operator|::
name|accessibility
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_accessibility
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|instance
name|QWindowsIntegration
modifier|*
name|QWindowsIntegration
operator|::
name|instance
parameter_list|()
block|{
return|return
cast|static_cast
argument_list|<
name|QWindowsIntegration
operator|*
argument_list|>
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|guiThreadEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QWindowsIntegration
operator|::
name|guiThreadEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|m_eventDispatcher
return|;
block|}
end_function
begin_function
DECL|function|themeNames
name|QStringList
name|QWindowsIntegration
operator|::
name|themeNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QLatin1String
argument_list|(
name|QWindowsTheme
operator|::
name|name
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformTheme
name|QPlatformTheme
modifier|*
name|QWindowsIntegration
operator|::
name|createPlatformTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
name|QWindowsTheme
operator|::
name|name
argument_list|)
condition|)
return|return
operator|new
name|QWindowsTheme
return|;
return|return
name|QPlatformIntegration
operator|::
name|createPlatformTheme
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QWindowsIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|d
operator|->
name|m_services
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qwindowsintegration.moc"
end_include
end_unit
