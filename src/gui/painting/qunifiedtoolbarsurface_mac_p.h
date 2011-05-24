begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUNIFIEDTOOLBARSURFACE_MAC_P_H
end_ifndef
begin_define
DECL|macro|QUNIFIEDTOOLBARSURFACE_MAC_P_H
define|#
directive|define
name|QUNIFIEDTOOLBARSURFACE_MAC_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<private/qwindowsurface_raster_p.h>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QToolBar>
end_include
begin_include
include|#
directive|include
file|<private/qwidget_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qnativeimage_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
end_ifdef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNativeImage
name|class
name|QNativeImage
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// This is the implementation of the unified toolbar on Mac OS X
end_comment
begin_comment
comment|// with the graphics system raster.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// General idea:
end_comment
begin_comment
comment|// -------------
end_comment
begin_comment
comment|// We redirect the painting of widgets inside the unified toolbar
end_comment
begin_comment
comment|// to a special window surface, the QUnifiedToolbarSurface.
end_comment
begin_comment
comment|// We need a separate window surface because the unified toolbar
end_comment
begin_comment
comment|// is out of the content view.
end_comment
begin_comment
comment|// The input system is the same as for the unified toolbar with the
end_comment
begin_comment
comment|// native (CoreGraphics) engine.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Execution flow:
end_comment
begin_comment
comment|// ---------------
end_comment
begin_comment
comment|// The unified toolbar is triggered by QMainWindow::setUnifiedTitleAndToolBarOnMac().
end_comment
begin_comment
comment|// It calls QMainWindowLayout::insertIntoMacToolbar() which will
end_comment
begin_comment
comment|// set all the appropriate variables (offsets, redirection, ...).
end_comment
begin_comment
comment|// When Qt tells a widget to repaint, QWidgetPrivate::drawWidget()
end_comment
begin_comment
comment|// checks if the widget is inside the unified toolbar and exits without
end_comment
begin_comment
comment|// painting is that is the case.
end_comment
begin_comment
comment|// We trigger the rendering of the unified toolbar in QWidget::repaint()
end_comment
begin_comment
comment|// and QWidget::update().
end_comment
begin_comment
comment|// We keep track of flush requests via "flushRequested" variable. That
end_comment
begin_comment
comment|// allow flush() to be a no-op if no repaint occured for a widget.
end_comment
begin_comment
comment|// We rely on the needsDisplay: and drawRect: mecanism for drawing our
end_comment
begin_comment
comment|// content into the graphics context.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Notes:
end_comment
begin_comment
comment|// ------
end_comment
begin_comment
comment|// The painting of items inside the unified toolbar is expensive.
end_comment
begin_comment
comment|// Too many repaints will drastically slow down the whole application.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|QUnifiedToolbarSurfacePrivate
block|{
name|public
label|:
name|QNativeImage
modifier|*
name|image
decl_stmt|;
name|uint
name|inSetGeometry
range|:
literal|1
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QUnifiedToolbarSurface
range|:
name|public
name|QRasterWindowSurface
block|{
name|public
operator|:
name|QUnifiedToolbarSurface
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
operator|~
name|QUnifiedToolbarSurface
argument_list|()
block|;
name|void
name|flush
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|flush
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
name|rgn
argument_list|)
block|;
name|void
name|insertToolbar
argument_list|(
name|QWidget
operator|*
name|toolbar
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|void
name|removeToolbar
argument_list|(
name|QToolBar
operator|*
name|toolbar
argument_list|)
block|;
name|void
name|updateToolbarOffset
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|renderToolbar
argument_list|(
argument|QWidget *widget
argument_list|,
argument|bool forceFlush = false
argument_list|)
block|;
name|void
name|recursiveRedirect
argument_list|(
name|QObject
operator|*
name|widget
argument_list|,
name|QWidget
operator|*
name|parent_toolbar
argument_list|,
specifier|const
name|QPoint
operator|&
name|offset
argument_list|)
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
block|;
name|CGContextRef
name|imageContext
argument_list|()
block|;
name|private
operator|:
name|void
name|prepareBuffer
argument_list|(
argument|QImage::Format format
argument_list|,
argument|QWidget *widget
argument_list|)
block|;
name|void
name|recursiveRemoval
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QUnifiedToolbarSurface
argument_list|)
name|QScopedPointer
operator|<
name|QUnifiedToolbarSurfacePrivate
operator|>
name|d_ptr
block|; }
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
comment|// QT_MAC_USE_COCOA
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUNIFIEDTOOLBARSURFACE_MAC_P_H
end_comment
end_unit
