begin_unit
begin_include
include|#
directive|include
file|"xqvibra.h"
end_include
begin_include
include|#
directive|include
file|"xqvibra_p.h"
end_include
begin_comment
comment|/*!     \class XQVibra      \brief The XQVibra class is used to control the device's vibra. The XQVibra     class provides also information of vibration setting in the user profile.      Example:     \code     XQVibra *vibra = new XQVibra(this);     QPushButton *startButton = new QPushButton(this);     QPushButton *stopButton = new QPushButton(this);     connect(startButton, SIGNAL(clicked()), vibra, SLOT(start()));     connect(stopButton, SIGNAL(clicked()), vibra, SLOT(stop()));     \endcode */
end_comment
begin_comment
comment|/*! \var XQVibra::InfiniteDuration     With this constant vibration can be set to work indefinitely (Note! Depends on the HW) */
end_comment
begin_comment
comment|/*! \var XQVibra::MaxIntensity     Maximum intensity as percentages */
end_comment
begin_comment
comment|/*! \var XQVibra::MinIntensity     Minumum intensity as percentages */
end_comment
begin_comment
comment|/*!     Constructs a XQVibra object with the given parent.     Call error() to get a value of XQVibra::Error that indicates which error occurred during initialisation if any.     \sa start(), setIntensity(), error() */
end_comment
begin_constructor
DECL|function|XQVibra
name|XQVibra
operator|::
name|XQVibra
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d
argument_list|(
operator|new
name|XQVibraPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the XQVibra object. */
end_comment
begin_destructor
DECL|function|~XQVibra
name|XQVibra
operator|::
name|~
name|XQVibra
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \enum XQVibra::Error      This enum defines the possible errors for a XQVibra object. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::NoError     No error occured. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::OutOfMemoryError     Not enough memory. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::ArgumentError     Duration is invalid. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::VibraInUseError     Vibra is already in used by other client. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::HardwareError     There is a hardware error. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::TimeOutError     Timeout occurred in controlling vibra. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::VibraLockedError     Vibra is locked down because too much continuous use or explicitly blocked by     for example some vibration sensitive accessory. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::AccessDeniedError     Vibration setting in the user profile is not set. */
end_comment
begin_comment
comment|/*! \var XQVibra::Error XQVibra::UnknownError     Unknown error. */
end_comment
begin_comment
comment|/*!     \enum XQVibra::Status      This enum defines the possible statuses of the vibration */
end_comment
begin_comment
comment|/*! \var XQVibra::Status XQVibra::StatusNotAllowed     Vibra is set off in the user profile or status is unknow */
end_comment
begin_comment
comment|/*! \var XQVibra::Status XQVibra::StatusOff     Vibration is non-active */
end_comment
begin_comment
comment|/*! \var XQVibra::Status XQVibra::StatusOn     Vibration is active */
end_comment
begin_comment
comment|/*!     Starts vibrating. If duration hasn't been set the vibration continues     indefinitely unless stopped with stop() function. Calling the start while vibration     is active the active vibration is interrupted and the new vibration starts immediately.      \param duration Specifies duration how long vibration should last     \return If false is returned, an error has occurred. Call error() to get a value of     XQVibra::Error that indicates which error occurred     \sa stop(), setIntensity(), error() */
end_comment
begin_function
DECL|function|start
name|bool
name|XQVibra
operator|::
name|start
parameter_list|(
name|int
name|duration
parameter_list|)
block|{
return|return
name|d
operator|->
name|start
argument_list|(
name|duration
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Interrupts the device vibration immediately.      \return If false is returned, an error has occurred. Call error() to get a value of     XQVibra::Error that indicates which error occurred     \sa start(), setIntensity(), error() */
end_comment
begin_function
DECL|function|stop
name|bool
name|XQVibra
operator|::
name|stop
parameter_list|()
block|{
return|return
name|d
operator|->
name|stop
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the intensity of the vibration. Allowed values for the intensity are     between -100 and 100. 0 means no vibrating. NOTE: The device might have     hardware-imposed limits on supported vibra intensity values, so actual     effect might vary between different hardware.      \param intensity Intensity of the vibra in decimals     \return If false is returned, an error has occurred. Call error() to get a value of     XQVibra::Error that indicates which error occurred     \sa error() */
end_comment
begin_function
DECL|function|setIntensity
name|bool
name|XQVibra
operator|::
name|setIntensity
parameter_list|(
name|int
name|intensity
parameter_list|)
block|{
return|return
name|d
operator|->
name|setIntensity
argument_list|(
name|intensity
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the current status of the vibration. This function can be used to check has vibration     allowed in the user profile.      \return current status     \sa statusChanged() */
end_comment
begin_function
DECL|function|currentStatus
name|XQVibra
operator|::
name|Status
name|XQVibra
operator|::
name|currentStatus
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|currentStatus
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the type of error that occurred if the latest function call failed; otherwise returns NoError     \return Error code */
end_comment
begin_function
DECL|function|error
name|XQVibra
operator|::
name|Error
name|XQVibra
operator|::
name|error
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|error
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void XQVibra::statusChanged(Status status)      This signal is emitted when the there is a change of the vibration status.      \param status a vibration status     \sa currentStatus() */
end_comment
begin_comment
comment|// End of file
end_comment
end_unit
