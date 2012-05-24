begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxvirtualkeyboardbps.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<bps/event.h>
end_include
begin_include
include|#
directive|include
file|<bps/locale.h>
end_include
begin_include
include|#
directive|include
file|<bps/virtualkeyboard.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QQNXVIRTUALKEYBOARD_DEBUG
end_ifdef
begin_define
DECL|macro|qVirtualKeyboardDebug
define|#
directive|define
name|qVirtualKeyboardDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qVirtualKeyboardDebug
define|#
directive|define
name|qVirtualKeyboardDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxVirtualKeyboardBps
name|QQnxVirtualKeyboardBps
operator|::
name|QQnxVirtualKeyboardBps
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QQnxAbstractVirtualKeyboard
argument_list|(
name|parent
argument_list|)
block|{
if|if
condition|(
name|locale_request_events
argument_list|(
literal|0
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: Failed to register for locale events"
argument_list|)
expr_stmt|;
if|if
condition|(
name|virtualkeyboard_request_events
argument_list|(
literal|0
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: Failed to register for virtual keyboard events"
argument_list|)
expr_stmt|;
name|int
name|height
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|virtualkeyboard_get_height
argument_list|(
operator|&
name|height
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: Failed to get virtual keyboard height"
argument_list|)
expr_stmt|;
name|setHeight
argument_list|(
name|height
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|handleEvent
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|handleEvent
parameter_list|(
name|bps_event_t
modifier|*
name|event
parameter_list|)
block|{
specifier|const
name|int
name|eventDomain
init|=
name|bps_event_get_domain
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|eventDomain
operator|==
name|locale_get_domain
argument_list|()
condition|)
return|return
name|handleLocaleEvent
argument_list|(
name|event
argument_list|)
return|;
if|if
condition|(
name|eventDomain
operator|==
name|virtualkeyboard_get_domain
argument_list|()
condition|)
return|return
name|handleVirtualKeyboardEvent
argument_list|(
name|event
argument_list|)
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|showKeyboard
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|showKeyboard
parameter_list|()
block|{
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"current visibility="
operator|<<
name|isVisible
argument_list|()
expr_stmt|;
name|virtualkeyboard_show
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hideKeyboard
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|hideKeyboard
parameter_list|()
block|{
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"current visibility="
operator|<<
name|isVisible
argument_list|()
expr_stmt|;
name|virtualkeyboard_hide
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|applyKeyboardMode
name|void
name|QQnxVirtualKeyboardBps
operator|::
name|applyKeyboardMode
parameter_list|(
name|KeyboardMode
name|mode
parameter_list|)
block|{
name|virtualkeyboard_layout_t
name|layout
init|=
name|VIRTUALKEYBOARD_LAYOUT_DEFAULT
decl_stmt|;
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|Url
case|:
name|layout
operator|=
name|VIRTUALKEYBOARD_LAYOUT_URL
expr_stmt|;
break|break;
case|case
name|Email
case|:
name|layout
operator|=
name|VIRTUALKEYBOARD_LAYOUT_EMAIL
expr_stmt|;
break|break;
case|case
name|Web
case|:
name|layout
operator|=
name|VIRTUALKEYBOARD_LAYOUT_WEB
expr_stmt|;
break|break;
case|case
name|NumPunc
case|:
name|layout
operator|=
name|VIRTUALKEYBOARD_LAYOUT_NUM_PUNC
expr_stmt|;
break|break;
case|case
name|Symbol
case|:
name|layout
operator|=
name|VIRTUALKEYBOARD_LAYOUT_SYMBOL
expr_stmt|;
break|break;
case|case
name|Phone
case|:
name|layout
operator|=
name|VIRTUALKEYBOARD_LAYOUT_PHONE
expr_stmt|;
break|break;
case|case
name|Pin
case|:
name|layout
operator|=
name|VIRTUALKEYBOARD_LAYOUT_PIN
expr_stmt|;
break|break;
case|case
name|Default
case|:
comment|// fall through
default|default:
name|layout
operator|=
name|VIRTUALKEYBOARD_LAYOUT_DEFAULT
expr_stmt|;
break|break;
block|}
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"mode="
operator|<<
name|mode
expr_stmt|;
name|virtualkeyboard_change_options
argument_list|(
name|layout
argument_list|,
name|VIRTUALKEYBOARD_ENTER_DEFAULT
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handleLocaleEvent
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|handleLocaleEvent
parameter_list|(
name|bps_event_t
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
operator|==
name|LOCALE_INFO
condition|)
block|{
specifier|const
name|QString
name|language
init|=
name|QString
operator|::
name|fromAscii
argument_list|(
name|locale_event_get_language
argument_list|(
name|event
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|country
init|=
name|QString
operator|::
name|fromAscii
argument_list|(
name|locale_event_get_country
argument_list|(
name|event
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QLocale
name|newLocale
argument_list|(
name|language
operator|+
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
operator|+
name|country
argument_list|)
decl_stmt|;
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"current locale"
operator|<<
name|locale
argument_list|()
operator|<<
literal|"new locale="
operator|<<
name|newLocale
expr_stmt|;
name|setLocale
argument_list|(
name|newLocale
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Unhandled locale event. code="
operator|<<
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|handleVirtualKeyboardEvent
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|handleVirtualKeyboardEvent
parameter_list|(
name|bps_event_t
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
condition|)
block|{
case|case
name|VIRTUALKEYBOARD_EVENT_VISIBLE
case|:
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"EVENT VISIBLE: current visibility="
operator|<<
name|isVisible
argument_list|()
expr_stmt|;
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
break|break;
case|case
name|VIRTUALKEYBOARD_EVENT_HIDDEN
case|:
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"EVENT HIDDEN: current visibility="
operator|<<
name|isVisible
argument_list|()
expr_stmt|;
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
break|break;
case|case
name|VIRTUALKEYBOARD_EVENT_INFO
case|:
block|{
specifier|const
name|int
name|newHeight
init|=
name|virtualkeyboard_event_get_height
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"EVENT INFO: current height="
operator|<<
name|height
argument_list|()
operator|<<
literal|"new height="
operator|<<
name|newHeight
expr_stmt|;
name|setHeight
argument_list|(
name|newHeight
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Unhandled virtual keyboard event. code="
operator|<<
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
