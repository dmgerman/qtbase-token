begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMSCREEN_H
end_ifndef
begin_define
DECL|macro|QPLATFORMSCREEN_H
define|#
directive|define
name|QPLATFORMSCREEN_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformpixmap.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformBackingStore
name|class
name|QPlatformBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformOpenGLContext
name|class
name|QPlatformOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformScreenPrivate
name|class
name|QPlatformScreenPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformWindow
name|class
name|QPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformCursor
name|class
name|QPlatformCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScreen
name|class
name|QScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSurfaceFormat
name|class
name|QSurfaceFormat
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|qreal
DECL|typedef|QDpi
typedef|typedef
name|QPair
operator|<
name|qreal
operator|,
name|qreal
operator|>
name|QDpi
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformScreen
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlatformScreen
argument_list|)
name|public
label|:
enum|enum
name|SubpixelAntialiasingType
block|{
comment|// copied from qfontengine_p.h since we can't include private headers
name|Subpixel_None
block|,
name|Subpixel_RGB
block|,
name|Subpixel_BGR
block|,
name|Subpixel_VRGB
block|,
name|Subpixel_VBGR
block|}
enum|;
name|QPlatformScreen
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QPlatformScreen
argument_list|()
expr_stmt|;
name|virtual
name|QPixmap
name|grabWindow
argument_list|(
name|WId
name|window
argument_list|,
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
name|width
argument_list|,
name|int
name|height
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QRect
name|geometry
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QRect
name|availableGeometry
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
return|;
block|}
name|virtual
name|int
name|depth
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|qreal
name|refreshRate
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|setOrientationUpdateMask
argument_list|(
name|Qt
operator|::
name|ScreenOrientations
name|mask
argument_list|)
decl_stmt|;
name|virtual
name|QWindow
modifier|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|virtualSiblings
argument_list|()
specifier|const
expr_stmt|;
name|QScreen
operator|*
name|screen
argument_list|()
specifier|const
expr_stmt|;
comment|//jl: should this function be in QPlatformIntegration
comment|//jl: maybe screenForWindow is a better name?
specifier|static
name|QPlatformScreen
modifier|*
name|platformScreenForWindow
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|virtual
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|SubpixelAntialiasingType
name|subpixelAntialiasingTypeHint
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|int
name|angleBetween
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
argument_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
argument_list|)
decl_stmt|;
specifier|static
name|QTransform
name|transformBetween
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
argument_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
argument_list|,
specifier|const
name|QRect
operator|&
name|target
argument_list|)
decl_stmt|;
specifier|static
name|QRect
name|mapBetween
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
argument_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
decl_stmt|;
name|protected
label|:
name|void
name|resizeMaximizedWindows
parameter_list|()
function_decl|;
name|QScopedPointer
operator|<
name|QPlatformScreenPrivate
operator|>
name|d_ptr
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPlatformScreen
argument_list|)
name|friend
name|class
name|QPlatformIntegration
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMSCREEN_H
end_comment
end_unit
