begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOANATIVEINTERFACE_H
end_ifndef
begin_define
DECL|macro|QCOCOANATIVEINTERFACE_H
define|#
directive|define
name|QCOCOANATIVEINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<ApplicationServices/ApplicationServices.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformPrinterSupport
name|class
name|QPlatformPrinterSupport
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPrintEngine
name|class
name|QPrintEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformMenu
name|class
name|QPlatformMenu
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformMenuBar
name|class
name|QPlatformMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaNativeInterface
range|:
name|public
name|QPlatformNativeInterface
block|{
name|Q_OBJECT
name|public
operator|:
name|QCocoaNativeInterface
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|void
operator|*
name|nativeResourceForContext
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resourceString
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
endif|#
directive|endif
name|void
operator|*
name|nativeResourceForWindow
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resourceString
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|NativeResourceForIntegrationFunction
name|nativeResourceFunctionForIntegration
argument_list|(
argument|const QByteArray&resource
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Q_INVOKABLE
name|void
name|beep
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
specifier|static
name|void
operator|*
name|cglContextForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
specifier|static
name|void
operator|*
name|nsOpenGLContextForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
endif|#
directive|endif
name|public
name|Q_SLOTS
operator|:
name|void
name|onAppFocusWindowChanged
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|private
operator|:
comment|/*         "Virtual" function to create the platform printer support         implementation.          We use an invokable function instead of a virtual one, we do not want         this in the QPlatform* API yet.          This was added here only because QPlatformNativeInterface is a QObject         and allow us to use QMetaObject::indexOfMethod() from the printsupport         plugin.     */
name|Q_INVOKABLE
name|QPlatformPrinterSupport
operator|*
name|createPlatformPrinterSupport
argument_list|()
block|;
comment|/*         Function to return the NSPrintInfo * from QMacPaintEnginePrivate.         Needed by the native print dialog in the Qt Print Support module.     */
name|Q_INVOKABLE
name|void
operator|*
name|NSPrintInfoForPrintEngine
argument_list|(
name|QPrintEngine
operator|*
name|printEngine
argument_list|)
block|;
comment|/*         Function to return the default background pixmap.         Needed by QWizard in the Qt widget module.     */
name|Q_INVOKABLE
name|QPixmap
name|defaultBackgroundPixmapForQWizard
argument_list|()
block|;
comment|// QMacPastebardMime support. The mac pasteboard void pointers are
comment|// QMacPastebardMime instances from the cocoa plugin or qtmacextras
comment|// These two classes are kept in sync and can be casted between.
specifier|static
name|void
name|addToMimeList
argument_list|(
name|void
operator|*
name|macPasteboardMime
argument_list|)
block|;
specifier|static
name|void
name|removeFromMimeList
argument_list|(
name|void
operator|*
name|macPasteboardMime
argument_list|)
block|;
specifier|static
name|void
name|registerDraggedTypes
argument_list|(
specifier|const
name|QStringList
operator|&
name|types
argument_list|)
block|;
comment|// Dock menu support
specifier|static
name|void
name|setDockMenu
argument_list|(
name|QPlatformMenu
operator|*
name|platformMenu
argument_list|)
block|;
comment|// Function to return NSMenu * from QPlatformMenu
specifier|static
name|void
operator|*
name|qMenuToNSMenu
argument_list|(
name|QPlatformMenu
operator|*
name|platformMenu
argument_list|)
block|;
comment|// Function to return NSMenu * from QPlatformMenuBar
specifier|static
name|void
operator|*
name|qMenuBarToNSMenu
argument_list|(
name|QPlatformMenuBar
operator|*
name|platformMenuBar
argument_list|)
block|;
comment|// QImage<-> CGImage conversion functions
specifier|static
name|CGImageRef
name|qImageToCGImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
specifier|static
name|QImage
name|cgImageToQImage
argument_list|(
argument|CGImageRef image
argument_list|)
block|;
comment|// Embedding NSViews as child QWindows
specifier|static
name|void
name|setWindowContentView
argument_list|(
name|QPlatformWindow
operator|*
name|window
argument_list|,
name|void
operator|*
name|nsViewContentView
argument_list|)
block|;
comment|// Set a QWindow as a "guest" (subwindow) of a non-QWindow
specifier|static
name|void
name|setEmbeddedInForeignView
argument_list|(
argument|QPlatformWindow *window
argument_list|,
argument|bool embedded
argument_list|)
block|;
comment|// Register if a window should deliver touch events. Enabling
comment|// touch events has implications for delivery of other events,
comment|// for example by causing scrolling event lag.
comment|//
comment|// The registration is ref-counted: multiple widgets can enable
comment|// touch events, which then will be delivered until the widget
comment|// deregisters.
specifier|static
name|void
name|registerTouchWindow
argument_list|(
argument|QWindow *window
argument_list|,
argument|bool enable
argument_list|)
block|;
comment|// Enable the unified title and toolbar area for a window.
specifier|static
name|void
name|setContentBorderEnabled
argument_list|(
argument|QWindow *window
argument_list|,
argument|bool enable
argument_list|)
block|;
comment|// Set the size of the unified title and toolbar area.
specifier|static
name|void
name|setContentBorderThickness
argument_list|(
argument|QWindow *window
argument_list|,
argument|int topThickness
argument_list|,
argument|int bottomThickness
argument_list|)
block|;
comment|// Set the size for a unified toolbar content border area.
comment|// Multiple callers can register areas and the platform plugin
comment|// will extend the "unified" area to cover them.
specifier|static
name|void
name|registerContentBorderArea
argument_list|(
argument|QWindow *window
argument_list|,
argument|quintptr identifer
argument_list|,
argument|int upper
argument_list|,
argument|int lower
argument_list|)
block|;
comment|// Enables or disiables a content border area.
specifier|static
name|void
name|setContentBorderAreaEnabled
argument_list|(
argument|QWindow *window
argument_list|,
argument|quintptr identifier
argument_list|,
argument|bool enable
argument_list|)
block|;
comment|// Returns true if the given coordinate is inside the current
comment|// content border.
specifier|static
name|bool
name|testContentBorderPosition
argument_list|(
argument|QWindow *window
argument_list|,
argument|int position
argument_list|)
block|;
comment|// Sets a NSToolbar instance for the given QWindow. The
comment|// toolbar will be attached to the native NSWindow when
comment|// that is created;
specifier|static
name|void
name|setNSToolbar
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|void
operator|*
name|nsToolbar
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOCOANATIVEINTERFACE_H
end_comment
end_unit
