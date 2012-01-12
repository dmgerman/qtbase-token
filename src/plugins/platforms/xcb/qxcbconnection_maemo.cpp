begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbconnection.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|XCB_USE_XINPUT2_MAEMO
end_ifdef
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<X11/extensions/XInput2.h>
end_include
begin_include
include|#
directive|include
file|<X11/extensions/XI2proto.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// Define it here to work around XLib defining Bool and stuff.
end_comment
begin_comment
comment|// We can't declare those variables in the header without facing include order headaches.
end_comment
begin_struct
DECL|struct|XInput2Data
struct|struct
name|XInput2Data
block|{
DECL|function|XInput2Data
name|XInput2Data
parameter_list|()
member_init_list|:
name|use_xinput
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|xinput_opcode
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|xinput_eventbase
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|xinput_errorbase
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|xideviceinfo
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|xibuttonclassinfo
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|xiMaxContacts
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|qtTouchDevice
argument_list|(
literal|0
argument_list|)
block|{     }
comment|// true if Qt is compiled w/ XInput2 or Tablet support and we have a tablet.
DECL|member|use_xinput
name|bool
name|use_xinput
decl_stmt|;
DECL|member|xinput_opcode
name|int
name|xinput_opcode
decl_stmt|;
DECL|member|xinput_eventbase
name|int
name|xinput_eventbase
decl_stmt|;
DECL|member|xinput_errorbase
name|int
name|xinput_errorbase
decl_stmt|;
comment|// device info for the master pointer Qt is using
DECL|member|xideviceinfo
name|XIDeviceInfo
modifier|*
name|xideviceinfo
decl_stmt|;
DECL|member|xibuttonclassinfo
name|XIButtonClassInfo
modifier|*
name|xibuttonclassinfo
decl_stmt|;
DECL|member|xiMaxContacts
name|int
name|xiMaxContacts
decl_stmt|;
DECL|member|allTouchPoints
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
name|allTouchPoints
decl_stmt|;
DECL|member|qtTouchDevice
name|QTouchDevice
modifier|*
name|qtTouchDevice
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|isUsingXInput2
name|bool
name|QXcbConnection
operator|::
name|isUsingXInput2
parameter_list|()
block|{
return|return
name|m_xinputData
operator|&&
name|m_xinputData
operator|->
name|use_xinput
operator|&&
name|m_xinputData
operator|->
name|xiMaxContacts
operator|!=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|initializeXInput2
name|void
name|QXcbConnection
operator|::
name|initializeXInput2
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|m_xinputData
argument_list|)
expr_stmt|;
name|m_xinputData
operator|=
operator|new
name|XInput2Data
expr_stmt|;
name|m_xinputData
operator|->
name|use_xinput
operator|=
name|XQueryExtension
argument_list|(
operator|(
name|Display
operator|*
operator|)
name|m_xlib_display
argument_list|,
literal|"XInputExtension"
argument_list|,
operator|&
name|m_xinputData
operator|->
name|xinput_opcode
argument_list|,
operator|&
name|m_xinputData
operator|->
name|xinput_eventbase
argument_list|,
operator|&
name|m_xinputData
operator|->
name|xinput_errorbase
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_xinputData
operator|->
name|use_xinput
condition|)
block|{
comment|// we want XInput2
name|int
name|ximajor
init|=
literal|2
decl_stmt|,
name|ximinor
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|XIQueryVersion
argument_list|(
operator|(
name|Display
operator|*
operator|)
name|m_xlib_display
argument_list|,
operator|&
name|ximajor
argument_list|,
operator|&
name|ximinor
argument_list|)
operator|==
name|BadRequest
condition|)
block|{
comment|// XInput2 not available
name|m_xinputData
operator|->
name|use_xinput
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
comment|// find the first master pointer and use this throughout Qt
comment|// when making XI2 calls that need a device id (rationale is that
comment|// for the time being, most setups will only have one master
comment|// pointer (despite having multiple slaves)
name|int
name|deviceCount
init|=
literal|0
decl_stmt|;
name|XIDeviceInfo
modifier|*
name|devices
init|=
name|XIQueryDevice
argument_list|(
operator|(
name|Display
operator|*
operator|)
name|m_xlib_display
argument_list|,
name|XIAllMasterDevices
argument_list|,
operator|&
name|deviceCount
argument_list|)
decl_stmt|;
if|if
condition|(
name|devices
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|deviceCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|devices
index|[
name|i
index|]
operator|.
name|use
operator|==
name|XIMasterPointer
condition|)
block|{
name|int
name|unused
init|=
literal|0
decl_stmt|;
name|m_xinputData
operator|->
name|xideviceinfo
operator|=
name|XIQueryDevice
argument_list|(
operator|(
name|Display
operator|*
operator|)
name|m_xlib_display
argument_list|,
name|devices
index|[
name|i
index|]
operator|.
name|deviceid
argument_list|,
operator|&
name|unused
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|XIFreeDeviceInfo
argument_list|(
name|devices
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_xinputData
operator|->
name|xideviceinfo
condition|)
name|qFatal
argument_list|(
literal|"Qt: Internal error, no XI2 master pointer found."
argument_list|)
expr_stmt|;
comment|// find the button info
name|m_xinputData
operator|->
name|xibuttonclassinfo
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_xinputData
operator|->
name|xideviceinfo
operator|->
name|num_classes
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|m_xinputData
operator|->
name|xideviceinfo
operator|->
name|classes
index|[
name|i
index|]
operator|->
name|type
operator|==
name|XIButtonClass
condition|)
block|{
name|m_xinputData
operator|->
name|xibuttonclassinfo
operator|=
operator|(
name|XIButtonClassInfo
operator|*
operator|)
name|m_xinputData
operator|->
name|xideviceinfo
operator|->
name|classes
index|[
name|i
index|]
expr_stmt|;
break|break;
block|}
block|}
comment|// find the "Max Contacts" property on the device
name|Atom
name|typeReturn
decl_stmt|;
name|int
name|formatReturn
decl_stmt|;
name|ulong
name|countReturn
decl_stmt|,
name|bytesReturn
decl_stmt|;
name|uchar
modifier|*
name|data
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|XIGetProperty
argument_list|(
operator|(
name|Display
operator|*
operator|)
name|m_xlib_display
argument_list|,
name|m_xinputData
operator|->
name|xibuttonclassinfo
operator|->
name|sourceid
argument_list|,
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|MaxContacts
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|False
argument_list|,
name|XA_INTEGER
argument_list|,
operator|&
name|typeReturn
argument_list|,
operator|&
name|formatReturn
argument_list|,
operator|&
name|countReturn
argument_list|,
operator|&
name|bytesReturn
argument_list|,
operator|&
name|data
argument_list|)
operator|==
name|Success
operator|&&
name|data
operator|!=
literal|0
operator|&&
name|typeReturn
operator|==
name|XA_INTEGER
operator|&&
name|formatReturn
operator|==
literal|8
operator|&&
name|countReturn
operator|==
literal|1
condition|)
block|{
comment|// touch driver reported the max number of touch-points
name|m_xinputData
operator|->
name|xiMaxContacts
operator|=
name|data
index|[
literal|0
index|]
expr_stmt|;
block|}
else|else
block|{
name|m_xinputData
operator|->
name|xiMaxContacts
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|data
condition|)
name|XFree
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|XFlush
argument_list|(
operator|(
name|Display
operator|*
operator|)
name|m_xlib_display
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|finalizeXInput2
name|void
name|QXcbConnection
operator|::
name|finalizeXInput2
parameter_list|()
block|{
if|if
condition|(
name|m_xinputData
operator|&&
name|m_xinputData
operator|->
name|xideviceinfo
condition|)
block|{
name|XIFreeDeviceInfo
argument_list|(
name|m_xinputData
operator|->
name|xideviceinfo
argument_list|)
expr_stmt|;
block|}
operator|delete
name|m_xinputData
expr_stmt|;
block|}
end_function
begin_comment
comment|// Borrowed from libXi.
end_comment
begin_function
DECL|function|count_bits
specifier|static
name|int
name|count_bits
parameter_list|(
name|unsigned
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|len
parameter_list|)
block|{
name|int
name|bits
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
name|unsigned
name|char
name|x
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
name|x
operator|=
name|ptr
index|[
name|i
index|]
expr_stmt|;
while|while
condition|(
name|x
operator|>
literal|0
condition|)
block|{
name|bits
operator|+=
operator|(
name|x
operator|&
literal|0x1
operator|)
expr_stmt|;
name|x
operator|>>=
literal|1
expr_stmt|;
block|}
block|}
return|return
name|bits
return|;
block|}
end_function
begin_function
DECL|function|getValuatorValueIfSet
specifier|static
name|bool
name|getValuatorValueIfSet
parameter_list|(
name|xXIDeviceEvent
modifier|*
name|xideviceevent
parameter_list|,
name|int
name|valuatorNum
parameter_list|,
name|double
modifier|*
name|value
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|buttonsMaskAddr
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|&
name|xideviceevent
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
modifier|*
name|valuatorsMaskAddr
init|=
name|buttonsMaskAddr
operator|+
name|xideviceevent
operator|->
name|buttons_len
operator|*
literal|4
decl_stmt|;
name|FP3232
modifier|*
name|valuatorsValuesAddr
init|=
operator|(
name|FP3232
operator|*
operator|)
operator|(
name|valuatorsMaskAddr
operator|+
name|xideviceevent
operator|->
name|valuators_len
operator|*
literal|4
operator|)
decl_stmt|;
name|int
name|numValuatorValues
init|=
name|count_bits
argument_list|(
name|valuatorsMaskAddr
argument_list|,
name|xideviceevent
operator|->
name|valuators_len
operator|*
literal|4
argument_list|)
decl_stmt|;
comment|// This relies on all bit being set until a certain number i.e. it doesn't support only bit 0 and 5 being set in the mask.
comment|// Just like the original code, works for now.
if|if
condition|(
name|valuatorNum
operator|>=
name|numValuatorValues
condition|)
return|return
literal|false
return|;
operator|*
name|value
operator|=
name|valuatorsValuesAddr
index|[
name|valuatorNum
index|]
operator|.
name|integral
expr_stmt|;
operator|*
name|value
operator|+=
operator|(
operator|(
name|double
operator|)
name|valuatorsValuesAddr
index|[
name|valuatorNum
index|]
operator|.
name|frac
operator|/
operator|(
literal|1
operator|<<
literal|16
operator|)
operator|/
operator|(
literal|1
operator|<<
literal|16
operator|)
operator|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|handleGenericEvent
name|void
name|QXcbConnection
operator|::
name|handleGenericEvent
parameter_list|(
name|xcb_ge_event_t
modifier|*
name|event
parameter_list|)
block|{
comment|// xGenericEvent has "extension" on the second byte, xcb_ge_event_t has "pad0".
if|if
condition|(
name|m_xinputData
operator|->
name|use_xinput
operator|&&
name|event
operator|->
name|pad0
operator|==
name|m_xinputData
operator|->
name|xinput_opcode
condition|)
block|{
comment|// xcb event structs contain stuff that wasn't on the wire, the full_sequence field
comment|// adds an extra 4 bytes and generic events cookie data is on the wire right after the standard 32 bytes.
comment|// Move this data back to have the same layout in memory as it was on the wire
comment|// and allow casting, overwritting the full_sequence field.
name|memmove
argument_list|(
operator|(
name|char
operator|*
operator|)
name|event
operator|+
literal|32
argument_list|,
operator|(
name|char
operator|*
operator|)
name|event
operator|+
literal|36
argument_list|,
name|event
operator|->
name|length
operator|*
literal|4
argument_list|)
expr_stmt|;
name|xXIGenericDeviceEvent
modifier|*
name|xievent
init|=
operator|(
name|xXIGenericDeviceEvent
operator|*
operator|)
name|event
decl_stmt|;
comment|// On Harmattan XInput2 is hacked to give touch points updates into standard mouse button press/motion events.
if|if
condition|(
name|m_xinputData
operator|->
name|xiMaxContacts
operator|!=
literal|0
operator|&&
operator|(
name|xievent
operator|->
name|evtype
operator|==
name|XI_ButtonPress
operator|||
name|xievent
operator|->
name|evtype
operator|==
name|XI_ButtonRelease
operator|||
name|xievent
operator|->
name|evtype
operator|==
name|XI_Motion
operator|)
condition|)
block|{
name|xXIDeviceEvent
modifier|*
name|xideviceevent
init|=
operator|(
name|xXIDeviceEvent
operator|*
operator|)
name|xievent
decl_stmt|;
name|QList
argument_list|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
argument_list|>
name|touchPoints
init|=
name|m_xinputData
operator|->
name|allTouchPoints
decl_stmt|;
if|if
condition|(
name|touchPoints
operator|.
name|count
argument_list|()
operator|!=
name|m_xinputData
operator|->
name|xiMaxContacts
condition|)
block|{
comment|// initial event, allocate space for all (potential) touch points
name|touchPoints
operator|.
name|reserve
argument_list|(
name|m_xinputData
operator|->
name|xiMaxContacts
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_xinputData
operator|->
name|xiMaxContacts
condition|;
operator|++
name|i
control|)
block|{
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|tp
decl_stmt|;
name|tp
operator|.
name|id
operator|=
name|i
expr_stmt|;
name|tp
operator|.
name|state
operator|=
name|Qt
operator|::
name|TouchPointReleased
expr_stmt|;
name|touchPoints
operator|<<
name|tp
expr_stmt|;
block|}
block|}
name|qreal
name|x
decl_stmt|,
name|y
decl_stmt|,
name|nx
decl_stmt|,
name|ny
decl_stmt|,
name|w
init|=
literal|0.0
decl_stmt|,
name|h
init|=
literal|0.0
decl_stmt|,
name|p
init|=
operator|-
literal|1.0
decl_stmt|;
name|int
name|id
decl_stmt|;
name|uint
name|active
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_xinputData
operator|->
name|xideviceinfo
operator|->
name|num_classes
condition|;
operator|++
name|i
control|)
block|{
name|XIAnyClassInfo
modifier|*
name|classinfo
init|=
name|m_xinputData
operator|->
name|xideviceinfo
operator|->
name|classes
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|classinfo
operator|->
name|type
operator|==
name|XIValuatorClass
condition|)
block|{
name|XIValuatorClassInfo
modifier|*
name|valuatorclassinfo
init|=
cast|reinterpret_cast
argument_list|<
name|XIValuatorClassInfo
operator|*
argument_list|>
argument_list|(
name|classinfo
argument_list|)
decl_stmt|;
name|int
name|n
init|=
name|valuatorclassinfo
operator|->
name|number
decl_stmt|;
name|double
name|value
decl_stmt|;
if|if
condition|(
operator|!
name|getValuatorValueIfSet
argument_list|(
name|xideviceevent
argument_list|,
name|n
argument_list|,
operator|&
name|value
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|valuatorclassinfo
operator|->
name|label
operator|==
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|AbsMTPositionX
argument_list|)
condition|)
block|{
name|x
operator|=
name|value
expr_stmt|;
name|nx
operator|=
operator|(
name|x
operator|-
name|valuatorclassinfo
operator|->
name|min
operator|)
operator|/
operator|(
name|valuatorclassinfo
operator|->
name|max
operator|-
name|valuatorclassinfo
operator|->
name|min
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|valuatorclassinfo
operator|->
name|label
operator|==
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|AbsMTPositionY
argument_list|)
condition|)
block|{
name|y
operator|=
name|value
expr_stmt|;
name|ny
operator|=
operator|(
name|y
operator|-
name|valuatorclassinfo
operator|->
name|min
operator|)
operator|/
operator|(
name|valuatorclassinfo
operator|->
name|max
operator|-
name|valuatorclassinfo
operator|->
name|min
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|valuatorclassinfo
operator|->
name|label
operator|==
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|AbsMTTouchMajor
argument_list|)
condition|)
block|{
name|w
operator|=
name|value
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|valuatorclassinfo
operator|->
name|label
operator|==
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|AbsMTTouchMinor
argument_list|)
condition|)
block|{
name|h
operator|=
name|value
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|valuatorclassinfo
operator|->
name|label
operator|==
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|AbsMTPressure
argument_list|)
condition|)
block|{
name|p
operator|=
operator|(
name|value
operator|-
name|valuatorclassinfo
operator|->
name|min
operator|)
operator|/
operator|(
name|valuatorclassinfo
operator|->
name|max
operator|-
name|valuatorclassinfo
operator|->
name|min
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|valuatorclassinfo
operator|->
name|label
operator|==
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|AbsMTTrackingID
argument_list|)
condition|)
block|{
name|id
operator|=
name|value
expr_stmt|;
name|active
operator||=
literal|1
operator|<<
name|id
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|TouchPoint
modifier|&
name|touchPoint
init|=
name|touchPoints
index|[
name|id
index|]
decl_stmt|;
name|Qt
operator|::
name|TouchPointState
name|newstate
decl_stmt|;
if|if
condition|(
name|touchPoint
operator|.
name|state
operator|==
name|Qt
operator|::
name|TouchPointReleased
condition|)
block|{
name|newstate
operator|=
name|Qt
operator|::
name|TouchPointPressed
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|touchPoint
operator|.
name|area
operator|.
name|center
argument_list|()
operator|!=
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
condition|)
name|newstate
operator|=
name|Qt
operator|::
name|TouchPointMoved
expr_stmt|;
else|else
name|newstate
operator|=
name|Qt
operator|::
name|TouchPointStationary
expr_stmt|;
block|}
name|touchPoint
operator|.
name|state
operator|=
name|newstate
expr_stmt|;
name|touchPoint
operator|.
name|area
operator|=
name|QRectF
argument_list|(
name|x
operator|-
name|w
operator|/
literal|2
argument_list|,
name|y
operator|-
name|h
operator|/
literal|2
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|touchPoint
operator|.
name|normalPosition
operator|=
name|QPointF
argument_list|(
name|nx
argument_list|,
name|ny
argument_list|)
expr_stmt|;
name|touchPoint
operator|.
name|pressure
operator|=
name|p
expr_stmt|;
block|}
block|}
block|}
comment|// mark previously-active-but-now-inactive touch points as released
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|touchPoints
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
operator|(
name|active
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
operator|)
operator|&&
name|touchPoints
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|state
operator|!=
name|Qt
operator|::
name|TouchPointReleased
condition|)
name|touchPoints
index|[
name|i
index|]
operator|.
name|state
operator|=
name|Qt
operator|::
name|TouchPointReleased
expr_stmt|;
if|if
condition|(
name|QXcbWindow
modifier|*
name|platformWindow
init|=
name|platformWindowFromId
argument_list|(
name|xideviceevent
operator|->
name|event
argument_list|)
condition|)
block|{
name|QTouchDevice
modifier|*
name|dev
init|=
name|m_xinputData
operator|->
name|qtTouchDevice
decl_stmt|;
if|if
condition|(
operator|!
name|dev
condition|)
block|{
name|dev
operator|=
operator|new
name|QTouchDevice
expr_stmt|;
name|dev
operator|->
name|setType
argument_list|(
name|QTouchDevice
operator|::
name|TouchScreen
argument_list|)
expr_stmt|;
name|dev
operator|->
name|setCapabilities
argument_list|(
name|QTouchDevice
operator|::
name|Position
operator||
name|QTouchDevice
operator|::
name|Area
operator||
name|QTouchDevice
operator|::
name|Pressure
operator||
name|QTouchDevice
operator|::
name|NormalizedPosition
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|registerTouchDevice
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|m_xinputData
operator|->
name|qtTouchDevice
operator|=
name|dev
expr_stmt|;
block|}
name|QWindowSystemInterface
operator|::
name|handleTouchEvent
argument_list|(
name|platformWindow
operator|->
name|window
argument_list|()
argument_list|,
name|xideviceevent
operator|->
name|time
argument_list|,
name|dev
argument_list|,
name|touchPoints
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|xideviceevent
operator|->
name|evtype
operator|==
name|XI_ButtonRelease
condition|)
block|{
comment|// final event, forget touch state
name|m_xinputData
operator|->
name|allTouchPoints
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// save current state so that we have something to reuse later
name|m_xinputData
operator|->
name|allTouchPoints
operator|=
name|touchPoints
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// XCB_USE_XINPUT2_MAEMO
end_comment
end_unit
