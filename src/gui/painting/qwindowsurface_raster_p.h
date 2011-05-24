begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSURFACE_RASTER_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSURFACE_RASTER_P_H
define|#
directive|define
name|QWINDOWSURFACE_RASTER_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|"private/qwindowsurface_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
end_ifdef
begin_include
include|#
directive|include
file|<private/qt_cocoa_helpers_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_MAC_USE_COCOA
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_define
DECL|macro|Q_WS_EX_LAYERED
define|#
directive|define
name|Q_WS_EX_LAYERED
value|0x00080000
end_define
begin_comment
DECL|macro|Q_WS_EX_LAYERED
comment|// copied from WS_EX_LAYERED in winuser.h
end_comment
begin_define
DECL|macro|Q_LWA_ALPHA
define|#
directive|define
name|Q_LWA_ALPHA
value|0x00000002
end_define
begin_comment
DECL|macro|Q_LWA_ALPHA
comment|// copied from LWA_ALPHA in winuser.h
end_comment
begin_define
DECL|macro|Q_ULW_ALPHA
define|#
directive|define
name|Q_ULW_ALPHA
value|0x00000002
end_define
begin_comment
DECL|macro|Q_ULW_ALPHA
comment|// copied from ULW_ALPHA in winuser.h
end_comment
begin_define
DECL|macro|Q_AC_SRC_ALPHA
define|#
directive|define
name|Q_AC_SRC_ALPHA
value|0x00000001
end_define
begin_comment
DECL|macro|Q_AC_SRC_ALPHA
comment|// copied from AC_SRC_ALPHA in winuser.h
end_comment
begin_struct
DECL|struct|Q_UPDATELAYEREDWINDOWINFO
struct|struct
name|Q_UPDATELAYEREDWINDOWINFO
block|{
DECL|member|cbSize
name|DWORD
name|cbSize
decl_stmt|;
DECL|member|hdcDst
name|HDC
name|hdcDst
decl_stmt|;
DECL|member|pptDst
specifier|const
name|POINT
modifier|*
name|pptDst
decl_stmt|;
DECL|member|psize
specifier|const
name|SIZE
modifier|*
name|psize
decl_stmt|;
DECL|member|hdcSrc
name|HDC
name|hdcSrc
decl_stmt|;
DECL|member|pptSrc
specifier|const
name|POINT
modifier|*
name|pptSrc
decl_stmt|;
DECL|member|crKey
name|COLORREF
name|crKey
decl_stmt|;
DECL|member|pblend
specifier|const
name|BLENDFUNCTION
modifier|*
name|pblend
decl_stmt|;
DECL|member|dwFlags
name|DWORD
name|dwFlags
decl_stmt|;
DECL|member|prcDirty
specifier|const
name|RECT
modifier|*
name|prcDirty
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|PtrUpdateLayeredWindow
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrUpdateLayeredWindow
function_decl|)
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|HDC
name|hdcDst
parameter_list|,
specifier|const
name|POINT
modifier|*
name|pptDst
parameter_list|,
specifier|const
name|SIZE
modifier|*
name|psize
parameter_list|,
name|HDC
name|hdcSrc
parameter_list|,
specifier|const
name|POINT
modifier|*
name|pptSrc
parameter_list|,
name|COLORREF
name|crKey
parameter_list|,
specifier|const
name|BLENDFUNCTION
modifier|*
name|pblend
parameter_list|,
name|DWORD
name|dwflags
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|PtrUpdateLayeredWindowIndirect
typedef|typedef
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|PtrUpdateLayeredWindowIndirect
function_decl|)
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
specifier|const
name|Q_UPDATELAYEREDWINDOWINFO
modifier|*
name|pULWInfo
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
specifier|extern
name|PtrUpdateLayeredWindow
name|ptrUpdateLayeredWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|PtrUpdateLayeredWindowIndirect
name|ptrUpdateLayeredWindowIndirect
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QPaintDevice
name|class
name|QPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRasterWindowSurfacePrivate
name|class
name|QRasterWindowSurfacePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNativeImage
name|class
name|QNativeImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRasterWindowSurface
range|:
name|public
name|QWindowSurface
block|{
name|public
operator|:
name|QRasterWindowSurface
argument_list|(
argument|QWidget *widget
argument_list|,
argument|bool setDefaultSurface = true
argument_list|)
block|;
operator|~
name|QRasterWindowSurface
argument_list|()
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
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
name|beginPaint
argument_list|(
specifier|const
name|QRegion
operator|&
name|rgn
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
name|bool
name|scroll
argument_list|(
argument|const QRegion&area
argument_list|,
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|WindowSurfaceFeatures
name|features
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT_MAC_USE_COCOA
name|CGContextRef
name|imageContext
argument_list|()
block|;
name|bool
name|needsFlush
block|;
name|QRegion
name|regionToFlush
block|;
endif|#
directive|endif
comment|// QT_MAC_USE_COCOA
name|private
operator|:
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MITSHM
argument_list|)
name|void
name|syncX
argument_list|()
block|;
endif|#
directive|endif
name|void
name|prepareBuffer
argument_list|(
argument|QImage::Format format
argument_list|,
argument|QWidget *widget
argument_list|)
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QRasterWindowSurface
argument_list|)
name|QScopedPointer
operator|<
name|QRasterWindowSurfacePrivate
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
comment|// QWINDOWSURFACE_RASTER_P_H
end_comment
end_unit
