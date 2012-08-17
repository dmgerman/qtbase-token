begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtouchdevice.h"
end_include
begin_include
include|#
directive|include
file|"qtouchdevice_p.h"
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QTouchDevice     \brief The QTouchDevice class describes the device from with touch events originate.     \since 5.0     \ingroup touch     \inmodule QtGui      Each QTouchEvent contains a QTouchDevice pointer to allow accessing     device-specific properties like type and capabilities. It is the     responsibility of the platform or generic plug-ins to register the     available touch devices via QWindowSystemInterface before generating any     touch events. Applications do not need to instantiate this class, they     should just access the global instances pointed to by QTouchEvent::device(). */
end_comment
begin_comment
comment|/*! \enum QTouchDevice::DeviceType      This enum represents the type of device that generated a QTouchEvent.      \value TouchScreen In this type of device, the touch surface and display are integrated. This                        means the surface and display typically have the same size, such that there                        is a direct relationship between the touch points' physical positions and the                        coordinate reported by QTouchEvent::TouchPoint. As a result, Qt allows the                        user to interact directly with multiple QWidgets and QGraphicsItems at the                        same time.      \value TouchPad In this type of device, the touch surface is separate from the display. There                     is not a direct relationship between the physical touch location and the                     on-screen coordinates. Instead, they are calculated relative to the current                     mouse position, and the user must use the touch-pad to move this reference                     point. Unlike touch-screens, Qt allows users to only interact with a single                     QWidget or QGraphicsItem at a time. */
end_comment
begin_comment
comment|/*! \enum QTouchDevice::CapabilityFlag      This enum is used with QTouchDevice::capabilities() to indicate what kind of information the     touch device or its driver can provide.      \value Position Indicates that position information is available, meaning                     that the pos() family of functions in the touch points return valid points.      \value Area Indicates that touch area information is available, meaning that the rect() family                 of functions in the touch points return valid rectangles.      \value Pressure Indicates that pressure information is available, meaning that pressure()                     returns a valid value.      \value Velocity Indicates that velocity information is available, meaning that velocity()                     returns a valid vector.      \value RawPositions Indicates that the list returned by QTouchEvent::TouchPoint::rawScreenPositions()                         may contain one or more positions for each touch point. This is relevant when                         the touch input gets filtered or corrected on driver level.      \value NormalizedPosition Indicates that the normalized position is available, meaning that normalizedPos()                               returns a valid value. */
end_comment
begin_comment
comment|/*!   Creates a new touch device instance.   By default the name is empty, the only capability is Position and type is TouchScreen.   */
end_comment
begin_constructor
DECL|function|QTouchDevice
name|QTouchDevice
operator|::
name|QTouchDevice
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QTouchDevicePrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys a touch device instance.   */
end_comment
begin_destructor
DECL|function|~QTouchDevice
name|QTouchDevice
operator|::
name|~
name|QTouchDevice
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the touch device type. */
end_comment
begin_function
DECL|function|type
name|QTouchDevice
operator|::
name|DeviceType
name|QTouchDevice
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|type
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the touch device capabilities.   */
end_comment
begin_function
DECL|function|capabilities
name|QTouchDevice
operator|::
name|Capabilities
name|QTouchDevice
operator|::
name|capabilities
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|caps
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the touch device name.      This string may often be empty. It is however useful for systems that have     more than one touch input device because there it can be used to     differentiate between the devices (i.e. to tell from which device a     QTouchEvent originates from). */
end_comment
begin_function
DECL|function|name
name|QString
name|QTouchDevice
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the device type \a devType.   */
end_comment
begin_function
DECL|function|setType
name|void
name|QTouchDevice
operator|::
name|setType
parameter_list|(
name|DeviceType
name|devType
parameter_list|)
block|{
name|d
operator|->
name|type
operator|=
name|devType
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Sets the capabilities \a caps supported by the device and its driver.   */
end_comment
begin_function
DECL|function|setCapabilities
name|void
name|QTouchDevice
operator|::
name|setCapabilities
parameter_list|(
name|Capabilities
name|caps
parameter_list|)
block|{
name|d
operator|->
name|caps
operator|=
name|caps
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Sets the \a name (a unique identifier) for the device. In most systems it is   enough to leave this unset and keep the default empty name. This identifier   becomes important when having multiple touch devices and a need to   differentiate between them.   */
end_comment
begin_function
DECL|function|setName
name|void
name|QTouchDevice
operator|::
name|setName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
block|}
end_function
begin_typedef
DECL|typedef|TouchDevices
typedef|typedef
name|QList
argument_list|<
name|QTouchDevice
modifier|*
argument_list|>
name|TouchDevices
typedef|;
end_typedef
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|TouchDevices
argument_list|,
argument|deviceList
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|devicesMutex
specifier|static
name|QBasicMutex
name|devicesMutex
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|cleanupDevicesList
specifier|static
name|void
name|cleanupDevicesList
parameter_list|()
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|devicesMutex
argument_list|)
decl_stmt|;
name|qDeleteAll
argument_list|(
operator|*
name|deviceList
argument_list|()
argument_list|)
expr_stmt|;
name|deviceList
argument_list|()
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns a list of all registered devices.    \note The returned list cannot be used to add new devices. Use QWindowSystemInterface::registerTouchDevice() instead.   */
end_comment
begin_function
DECL|function|devices
name|QList
argument_list|<
specifier|const
name|QTouchDevice
modifier|*
argument_list|>
name|QTouchDevice
operator|::
name|devices
parameter_list|()
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|devicesMutex
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QTouchDevice
modifier|*
argument_list|>
modifier|*
name|devList
init|=
name|deviceList
argument_list|()
decl_stmt|;
name|QList
argument_list|<
specifier|const
name|QTouchDevice
modifier|*
argument_list|>
name|constDevList
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|count
init|=
name|devList
operator|->
name|count
argument_list|()
init|;
name|i
operator|!=
name|count
condition|;
operator|++
name|i
control|)
name|constDevList
operator|.
name|append
argument_list|(
name|devList
operator|->
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|constDevList
return|;
block|}
end_function
begin_comment
comment|/*!   \internal   */
end_comment
begin_function
DECL|function|isRegistered
name|bool
name|QTouchDevicePrivate
operator|::
name|isRegistered
parameter_list|(
name|QTouchDevice
modifier|*
name|dev
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|devicesMutex
argument_list|)
decl_stmt|;
return|return
name|deviceList
argument_list|()
operator|->
name|contains
argument_list|(
name|dev
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \internal   */
end_comment
begin_function
DECL|function|registerDevice
name|void
name|QTouchDevicePrivate
operator|::
name|registerDevice
parameter_list|(
name|QTouchDevice
modifier|*
name|dev
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|devicesMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|deviceList
argument_list|()
operator|->
name|isEmpty
argument_list|()
condition|)
name|qAddPostRoutine
argument_list|(
name|cleanupDevicesList
argument_list|)
expr_stmt|;
name|deviceList
argument_list|()
operator|->
name|append
argument_list|(
name|dev
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
