begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSDIRECT2DDEVICECONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSDIRECT2DDEVICECONTEXT_H
define|#
directive|define
name|QWINDOWSDIRECT2DDEVICECONTEXT_H
end_define
begin_include
include|#
directive|include
file|"qwindowsdirect2dhelpers.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*  * Convenience class for handling device contexts. We have to call BeginDraw  * before anything can happen, and EndDraw once we're done, for every frame and  * pretty much any kind of operation.  *  * Unfortunately, these calls cannot be interleaved, and there is no way to check  * what state a device context is in.  *  * The end result is that the following throws an error if we don't track it:  *      QPixmap pmap;  *      QPainter painter(&pmap);  *      pmap.clear();  *  * Here BeginDraw would first be called through the paint device, then when we clear  * the pixmap we would have to call it again. There is no way to know what state  * the device context is in when performing the clear, and activating the dc is an  * error. Bummer.  *  * Hence we keep a reference count here and only activate/deactivate the device  * if the refcount is zero.  *  * In a nutshell: Do not call BeginDraw/EndDraw yourself on the device pointer, do  * so through the begin/end members below.  */
DECL|variable|QWindowsDirect2DDeviceContextPrivate
name|class
name|QWindowsDirect2DDeviceContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsDirect2DDeviceContext
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWindowsDirect2DDeviceContext
argument_list|)
name|friend
name|class
name|QWindowsDirect2DDeviceContextSuspender
decl_stmt|;
name|public
label|:
name|QWindowsDirect2DDeviceContext
argument_list|(
name|ID2D1DeviceContext
operator|*
name|dc
argument_list|)
expr_stmt|;
operator|~
name|QWindowsDirect2DDeviceContext
argument_list|()
expr_stmt|;
name|ID2D1DeviceContext
operator|*
name|get
argument_list|()
specifier|const
expr_stmt|;
name|void
name|begin
parameter_list|()
function_decl|;
name|bool
name|end
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|suspend
parameter_list|()
function_decl|;
name|void
name|resume
parameter_list|()
function_decl|;
name|QScopedPointer
operator|<
name|QWindowsDirect2DDeviceContextPrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QWindowsDirect2DDeviceContextSuspender
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsDirect2DDeviceContextSuspender
argument_list|)
name|QWindowsDirect2DDeviceContext
modifier|*
name|m_dc
decl_stmt|;
name|public
label|:
name|QWindowsDirect2DDeviceContextSuspender
argument_list|(
name|QWindowsDirect2DDeviceContext
operator|*
name|dc
argument_list|)
expr_stmt|;
operator|~
name|QWindowsDirect2DDeviceContextSuspender
argument_list|()
expr_stmt|;
name|void
name|resume
parameter_list|()
function_decl|;
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
comment|// QWINDOWSDIRECT2DDEVICECONTEXT_H
end_comment
end_unit
