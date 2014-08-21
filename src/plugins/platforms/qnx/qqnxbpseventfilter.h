begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXBPSEVENTFILTER_H
end_ifndef
begin_define
DECL|macro|QQNXBPSEVENTFILTER_H
define|#
directive|define
name|QQNXBPSEVENTFILTER_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QAbstractNativeEventFilter>
end_include
begin_include
include|#
directive|include
file|<bps/dialog.h>
end_include
begin_struct_decl
struct_decl|struct
name|bps_event_t
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxNavigatorEventHandler
name|class
name|QQnxNavigatorEventHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxFileDialogHelper
name|class
name|QQnxFileDialogHelper
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxScreen
name|class
name|QQnxScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxScreenEventHandler
name|class
name|QQnxScreenEventHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxVirtualKeyboardBps
name|class
name|QQnxVirtualKeyboardBps
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QQnxBpsEventFilter
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QAbstractNativeEventFilter
block|{
name|Q_OBJECT
name|public
range|:
name|QQnxBpsEventFilter
argument_list|(
name|QQnxNavigatorEventHandler
operator|*
name|navigatorEventHandler
argument_list|,
name|QQnxScreenEventHandler
operator|*
name|screenEventHandler
argument_list|,
name|QQnxVirtualKeyboardBps
operator|*
name|virtualKeyboard
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QQnxBpsEventFilter
argument_list|()
expr_stmt|;
name|void
name|installOnEventDispatcher
parameter_list|(
name|QAbstractEventDispatcher
modifier|*
name|dispatcher
parameter_list|)
function_decl|;
name|void
name|registerForScreenEvents
parameter_list|(
name|QQnxScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
name|void
name|unregisterForScreenEvents
parameter_list|(
name|QQnxScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|Q_OS_BLACKBERRY_TABLET
name|void
name|registerForDialogEvents
parameter_list|(
name|QQnxFileDialogHelper
modifier|*
name|dialog
parameter_list|)
function_decl|;
name|void
name|unregisterForDialogEvents
parameter_list|(
name|QQnxFileDialogHelper
modifier|*
name|dialog
parameter_list|)
function_decl|;
endif|#
directive|endif
name|private
label|:
name|bool
name|nativeEventFilter
argument_list|(
specifier|const
name|QByteArray
operator|&
name|eventType
argument_list|,
name|void
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|handleNavigatorEvent
parameter_list|(
name|bps_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
name|private
label|:
name|QQnxNavigatorEventHandler
modifier|*
name|m_navigatorEventHandler
decl_stmt|;
name|QQnxScreenEventHandler
modifier|*
name|m_screenEventHandler
decl_stmt|;
name|QQnxVirtualKeyboardBps
modifier|*
name|m_virtualKeyboard
decl_stmt|;
name|QHash
operator|<
name|dialog_instance_t
operator|,
name|QQnxFileDialogHelper
operator|*
operator|>
name|m_dialogMapper
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
begin_comment
comment|// QQNXBPSEVENTFILTER_H
end_comment
end_unit
