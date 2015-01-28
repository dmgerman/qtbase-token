begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLIBINPUTTOUCH_P_H
end_ifndef
begin_define
DECL|macro|QLIBINPUTTOUCH_P_H
define|#
directive|define
name|QLIBINPUTTOUCH_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
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
begin_struct_decl
struct_decl|struct
name|libinput_event_touch
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|libinput_device
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QLibInputTouch
block|{
name|public
label|:
name|void
name|registerDevice
parameter_list|(
name|libinput_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
name|unregisterDevice
parameter_list|(
name|libinput_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
name|processTouchDown
parameter_list|(
name|libinput_event_touch
modifier|*
name|e
parameter_list|)
function_decl|;
name|void
name|processTouchMotion
parameter_list|(
name|libinput_event_touch
modifier|*
name|e
parameter_list|)
function_decl|;
name|void
name|processTouchUp
parameter_list|(
name|libinput_event_touch
modifier|*
name|e
parameter_list|)
function_decl|;
name|void
name|processTouchCancel
parameter_list|(
name|libinput_event_touch
modifier|*
name|e
parameter_list|)
function_decl|;
name|void
name|processTouchFrame
parameter_list|(
name|libinput_event_touch
modifier|*
name|e
parameter_list|)
function_decl|;
name|private
label|:
struct|struct
name|DeviceState
block|{
name|DeviceState
argument_list|()
operator|:
name|m_touchDevice
argument_list|(
literal|0
argument_list|)
block|{ }
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|*
name|point
argument_list|(
argument|int32_t slot
argument_list|)
expr_stmt|;
name|QList
operator|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
name|m_points
expr_stmt|;
name|QTouchDevice
modifier|*
name|m_touchDevice
decl_stmt|;
block|}
struct|;
name|DeviceState
modifier|*
name|deviceState
parameter_list|(
name|libinput_event_touch
modifier|*
name|e
parameter_list|)
function_decl|;
name|QHash
operator|<
name|libinput_device
operator|*
operator|,
name|DeviceState
operator|>
name|m_devState
expr_stmt|;
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
end_unit
