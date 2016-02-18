begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSTABLETSUPPORT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSTABLETSUPPORT_H
define|#
directive|define
name|QWINDOWSTABLETSUPPORT_H
end_define
begin_include
include|#
directive|include
file|"qtwindowsglobal.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_TABLETEVENT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointF>
end_include
begin_include
include|#
directive|include
file|<wintab.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QWindowsWinTab32DLL
struct|struct
name|QWindowsWinTab32DLL
block|{
DECL|function|QWindowsWinTab32DLL
name|QWindowsWinTab32DLL
argument_list|()
operator|:
name|wTOpen
argument_list|(
literal|0
argument_list|)
operator|,
name|wTClose
argument_list|(
literal|0
argument_list|)
operator|,
name|wTInfo
argument_list|(
literal|0
argument_list|)
operator|,
name|wTEnable
argument_list|(
literal|0
argument_list|)
operator|,
name|wTOverlap
argument_list|(
literal|0
argument_list|)
operator|,
name|wTPacketsGet
argument_list|(
literal|0
argument_list|)
operator|,
name|wTGet
argument_list|(
literal|0
argument_list|)
operator|,
name|wTQueueSizeGet
argument_list|(
literal|0
argument_list|)
operator|,
name|wTQueueSizeSet
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|init
argument_list|()
expr_stmt|;
DECL|typedef|PtrWTOpen
typedef|typedef
name|HCTX
function_decl|(
name|API
modifier|*
name|PtrWTOpen
function_decl|)
parameter_list|(
name|HWND
parameter_list|,
name|LPLOGCONTEXT
parameter_list|,
name|BOOL
parameter_list|)
function_decl|;
DECL|typedef|PtrWTClose
typedef|typedef
name|BOOL
function_decl|(
name|API
modifier|*
name|PtrWTClose
function_decl|)
parameter_list|(
name|HCTX
parameter_list|)
function_decl|;
DECL|typedef|PtrWTInfo
typedef|typedef
name|UINT
function_decl|(
name|API
modifier|*
name|PtrWTInfo
function_decl|)
parameter_list|(
name|UINT
parameter_list|,
name|UINT
parameter_list|,
name|LPVOID
parameter_list|)
function_decl|;
DECL|typedef|PtrWTEnable
typedef|typedef
name|BOOL
function_decl|(
name|API
modifier|*
name|PtrWTEnable
function_decl|)
parameter_list|(
name|HCTX
parameter_list|,
name|BOOL
parameter_list|)
function_decl|;
DECL|typedef|PtrWTOverlap
typedef|typedef
name|BOOL
function_decl|(
name|API
modifier|*
name|PtrWTOverlap
function_decl|)
parameter_list|(
name|HCTX
parameter_list|,
name|BOOL
parameter_list|)
function_decl|;
DECL|typedef|PtrWTPacketsGet
typedef|typedef
name|int
function_decl|(
name|API
modifier|*
name|PtrWTPacketsGet
function_decl|)
parameter_list|(
name|HCTX
parameter_list|,
name|int
parameter_list|,
name|LPVOID
parameter_list|)
function_decl|;
DECL|typedef|PtrWTGet
typedef|typedef
name|BOOL
function_decl|(
name|API
modifier|*
name|PtrWTGet
function_decl|)
parameter_list|(
name|HCTX
parameter_list|,
name|LPLOGCONTEXT
parameter_list|)
function_decl|;
DECL|typedef|PtrWTQueueSizeGet
typedef|typedef
name|int
function_decl|(
name|API
modifier|*
name|PtrWTQueueSizeGet
function_decl|)
parameter_list|(
name|HCTX
parameter_list|)
function_decl|;
DECL|typedef|PtrWTQueueSizeSet
typedef|typedef
name|BOOL
function_decl|(
name|API
modifier|*
name|PtrWTQueueSizeSet
function_decl|)
parameter_list|(
name|HCTX
parameter_list|,
name|int
parameter_list|)
function_decl|;
DECL|member|wTOpen
name|PtrWTOpen
name|wTOpen
decl_stmt|;
DECL|member|wTClose
name|PtrWTClose
name|wTClose
decl_stmt|;
DECL|member|wTInfo
name|PtrWTInfo
name|wTInfo
decl_stmt|;
DECL|member|wTEnable
name|PtrWTEnable
name|wTEnable
decl_stmt|;
DECL|member|wTOverlap
name|PtrWTOverlap
name|wTOverlap
decl_stmt|;
DECL|member|wTPacketsGet
name|PtrWTPacketsGet
name|wTPacketsGet
decl_stmt|;
DECL|member|wTGet
name|PtrWTGet
name|wTGet
decl_stmt|;
DECL|member|wTQueueSizeGet
name|PtrWTQueueSizeGet
name|wTQueueSizeGet
decl_stmt|;
DECL|member|wTQueueSizeSet
name|PtrWTQueueSizeSet
name|wTQueueSizeSet
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QWindowsTabletDeviceData
struct|struct
name|QWindowsTabletDeviceData
block|{
DECL|function|QWindowsTabletDeviceData
name|QWindowsTabletDeviceData
argument_list|()
operator|:
name|minPressure
argument_list|(
literal|0
argument_list|)
operator|,
name|maxPressure
argument_list|(
literal|0
argument_list|)
operator|,
name|minTanPressure
argument_list|(
literal|0
argument_list|)
operator|,
name|maxTanPressure
argument_list|(
literal|0
argument_list|)
operator|,
name|minX
argument_list|(
literal|0
argument_list|)
operator|,
name|maxX
argument_list|(
literal|0
argument_list|)
operator|,
name|minY
argument_list|(
literal|0
argument_list|)
operator|,
name|maxY
argument_list|(
literal|0
argument_list|)
operator|,
name|minZ
argument_list|(
literal|0
argument_list|)
operator|,
name|maxZ
argument_list|(
literal|0
argument_list|)
operator|,
name|uniqueId
argument_list|(
literal|0
argument_list|)
operator|,
name|currentDevice
argument_list|(
literal|0
argument_list|)
operator|,
name|currentPointerType
argument_list|(
literal|0
argument_list|)
block|{}
name|QPointF
name|scaleCoordinates
argument_list|(
argument|int coordX
argument_list|,
argument|int coordY
argument_list|,
argument|const QRect&targetArea
argument_list|)
specifier|const
expr_stmt|;
DECL|function|scalePressure
name|qreal
name|scalePressure
argument_list|(
name|qreal
name|p
argument_list|)
decl|const
block|{
return|return
name|p
operator|/
name|qreal
argument_list|(
name|maxPressure
operator|-
name|minPressure
argument_list|)
return|;
block|}
DECL|function|scaleTangentialPressure
name|qreal
name|scaleTangentialPressure
argument_list|(
name|qreal
name|p
argument_list|)
decl|const
block|{
return|return
name|p
operator|/
name|qreal
argument_list|(
name|maxTanPressure
operator|-
name|minTanPressure
argument_list|)
return|;
block|}
DECL|member|minPressure
name|int
name|minPressure
decl_stmt|;
DECL|member|maxPressure
name|int
name|maxPressure
decl_stmt|;
DECL|member|minTanPressure
name|int
name|minTanPressure
decl_stmt|;
DECL|member|maxTanPressure
name|int
name|maxTanPressure
decl_stmt|;
DECL|member|minX
DECL|member|maxX
DECL|member|minY
DECL|member|maxY
DECL|member|minZ
DECL|member|maxZ
name|int
name|minX
decl_stmt|,
name|maxX
decl_stmt|,
name|minY
decl_stmt|,
name|maxY
decl_stmt|,
name|minZ
decl_stmt|,
name|maxZ
decl_stmt|;
DECL|member|uniqueId
name|qint64
name|uniqueId
decl_stmt|;
DECL|member|currentDevice
name|int
name|currentDevice
decl_stmt|;
DECL|member|currentPointerType
name|int
name|currentPointerType
decl_stmt|;
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QWindowsTabletDeviceData
operator|&
name|t
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QWindowsTabletSupport
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsTabletSupport
argument_list|)
name|explicit
name|QWindowsTabletSupport
parameter_list|(
name|HWND
name|window
parameter_list|,
name|HCTX
name|context
parameter_list|)
function_decl|;
name|public
label|:
operator|~
name|QWindowsTabletSupport
argument_list|()
expr_stmt|;
specifier|static
name|QWindowsTabletSupport
modifier|*
name|create
parameter_list|()
function_decl|;
name|void
name|notifyActivate
parameter_list|()
function_decl|;
name|QString
name|description
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|translateTabletProximityEvent
parameter_list|(
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
function_decl|;
name|bool
name|translateTabletPacketEvent
parameter_list|()
function_decl|;
name|int
name|absoluteRange
argument_list|()
specifier|const
block|{
return|return
name|m_absoluteRange
return|;
block|}
name|void
name|setAbsoluteRange
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|m_absoluteRange
operator|=
name|a
expr_stmt|;
block|}
name|private
label|:
name|unsigned
name|options
argument_list|()
specifier|const
expr_stmt|;
name|QWindowsTabletDeviceData
name|tabletInit
argument_list|(
name|qint64
name|uniqueId
argument_list|,
name|UINT
name|cursorType
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QWindowsWinTab32DLL
name|m_winTab32DLL
decl_stmt|;
specifier|const
name|HWND
name|m_window
decl_stmt|;
specifier|const
name|HCTX
name|m_context
decl_stmt|;
name|int
name|m_absoluteRange
decl_stmt|;
name|bool
name|m_tiltSupport
decl_stmt|;
name|QVector
operator|<
name|QWindowsTabletDeviceData
operator|>
name|m_devices
expr_stmt|;
name|int
name|m_currentDevice
decl_stmt|;
name|QPointF
name|m_oldGlobalPosF
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
comment|// !QT_NO_TABLETEVENT&& !Q_OS_WINCE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSTABLETSUPPORT_H
end_comment
end_unit
