begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhighdpiscaling_p.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication.h"
end_include
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"qplatformintegration.h"
end_include
begin_include
include|#
directive|include
file|"private/qscreen_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcScaling
argument_list|,
literal|"qt.scaling"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HIGHDPISCALING
end_ifndef
begin_decl_stmt
DECL|variable|legacyDevicePixelEnvVar
specifier|static
specifier|const
name|char
name|legacyDevicePixelEnvVar
index|[]
init|=
literal|"QT_DEVICE_PIXEL_RATIO"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|scaleFactorEnvVar
specifier|static
specifier|const
name|char
name|scaleFactorEnvVar
index|[]
init|=
literal|"QT_SCALE_FACTOR"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|autoScreenEnvVar
specifier|static
specifier|const
name|char
name|autoScreenEnvVar
index|[]
init|=
literal|"QT_AUTO_SCREEN_SCALE_FACTOR"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|screenFactorsEnvVar
specifier|static
specifier|const
name|char
name|screenFactorsEnvVar
index|[]
init|=
literal|"QT_SCREEN_SCALE_FACTORS"
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|initialGlobalScaleFactor
specifier|static
specifier|inline
name|qreal
name|initialGlobalScaleFactor
parameter_list|()
block|{
name|qreal
name|result
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
name|scaleFactorEnvVar
argument_list|)
condition|)
block|{
name|bool
name|ok
decl_stmt|;
specifier|const
name|qreal
name|f
init|=
name|qgetenv
argument_list|(
name|scaleFactorEnvVar
argument_list|)
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
operator|&&
name|f
operator|>
literal|0
condition|)
block|{
name|qCDebug
argument_list|(
name|lcScaling
argument_list|)
operator|<<
literal|"Apply "
operator|<<
name|scaleFactorEnvVar
operator|<<
name|f
expr_stmt|;
name|result
operator|=
name|f
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
name|legacyDevicePixelEnvVar
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Warning:"
operator|<<
name|legacyDevicePixelEnvVar
operator|<<
literal|"is deprecated. Instead use:"
operator|<<
name|endl
operator|<<
literal|"   "
operator|<<
name|autoScreenEnvVar
operator|<<
literal|"to enable platform plugin controlled per-screen factors."
operator|<<
name|endl
operator|<<
literal|"   "
operator|<<
name|screenFactorsEnvVar
operator|<<
literal|"to set per-screen factors."
operator|<<
name|endl
operator|<<
literal|"   "
operator|<<
name|scaleFactorEnvVar
operator|<<
literal|"to set the application global scale factor."
expr_stmt|;
name|int
name|dpr
init|=
name|qEnvironmentVariableIntValue
argument_list|(
name|legacyDevicePixelEnvVar
argument_list|)
decl_stmt|;
if|if
condition|(
name|dpr
operator|>
literal|0
condition|)
name|result
operator|=
name|dpr
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \class QHighDpiScaling     \since 5.6     \internal     \preliminary     \ingroup qpa      \brief Collection of utility functions for UI scaling.      QHighDpiScaling implements utility functions for high-dpi scaling for use     on operating systems that provide limited support for native scaling. In     addition this functionality can be used for simulation and testing purposes.      The functions support scaling between the device independent coordinate     system used by Qt applications and the native coordinate system used by     the platform plugins. Intended usage locations are the low level / platform     plugin interfacing parts of QtGui, for example the QWindow, QScreen and     QWindowSystemInterface implementation.      There are now up to three active coordinate systems in Qt:       ---------------------------------------------------     |  Application            Device Independent Pixels |   devicePixelRatio     |  Qt Widgets                                       |         =     |  Qt Gui                                           |     |---------------------------------------------------|   Qt Scale Factor     |  Qt Gui QPlatform*      Native Pixels             |         *     |  Qt platform plugin                               |     |---------------------------------------------------|   OS Scale Factor     |  Display                Device Pixels             |     |  (Graphics Buffers)                               |     -----------------------------------------------------      This is an simplification and shows the main coordinate system. All layers     may work with device pixels in specific cases: OpenGL, creating the backing     store, and QPixmap management. The "Native Pixels" coordinate system is     internal to Qt and should not be exposed to Qt users: Seen from the outside     there are only two coordinate systems: device independent pixels and device     pixels.      The devicePixelRatio seen by applications is the product of the Qt scale     factor and the OS scale factor. The value of the scale factors may be 1,     in which case two or more of the coordinate systems are equivalent. Platforms     that (may) have an OS scale factor include OS X, iOS and Wayland.      Note that the functions in this file do not work with the OS scale factor     directly and are limited to converting between device independent and native     pixels. The OS scale factor is accunted for by QWindow::devicePixelRatio()     and similar functions.      Configuration Examples:      'Classic': Device Independent Pixels = Native Pixels = Device Pixels      ---------------------------------------------------    devicePixelRatio: 1     |  Application / Qt Gui             100 x 100       |     |                                                   |   Qt Scale Factor: 1     |  Qt Platform / OS                 100 x 100       |     |                                                   |   OS Scale Factor: 1     |  Display                          100 x 100       |     -----------------------------------------------------      'Retina Device': Device Independent Pixels = Native Pixels      ---------------------------------------------------    devicePixelRatio: 2     |  Application / Qt Gui             100 x 100       |     |                                                   |   Qt Scale Factor: 1     |  Qt Platform / OS                 100 x 100       |     |---------------------------------------------------|   OS Scale Factor: 2     |  Display                          200 x 200       |     -----------------------------------------------------      '2x Qt Scaling': Native Pixels = Device Pixels      ---------------------------------------------------    devicePixelRatio: 2     |  Application / Qt Gui             100 x 100       |     |---------------------------------------------------|   Qt Scale Factor: 2     |  Qt Platform / OS                 200 x 200       |     |                                                   |   OS Scale Factor: 1     |  Display                          200 x 200       |     -----------------------------------------------------      The Qt Scale Factor is the product of two sub-scale factors, which     are independently either set or determined by the platform plugin.     Several APIs are offered for this, targeting both developers and     end users. All scale factors are of type qreal.      1) A global scale factor         The QT_SCALE_FACTOR environment variable can be used to set         a global scale factor for all windows in the processs. This         is useful for testing and debugging (you can simulate any         devicePixelRatio without needing access to sepcial hardware),         and perhaps also for targeting a specific application to         a specific display type (embedded use cases).      2) A per-screen scale factors         Some platform plugins support providing a per-screen scale         factor based on display density information. These platforms         include X11, Windows, and Android.          There are two APIs for enabling or disabling this behavior:             - The QT_AUTO_SCALE_FACTOR environment variable.             - The AA_EnableHighDpiScaling and AA_DisableHighDpiScaling               application attributes          Enabling either will make QHighDpiScaling call QPlatformScreen::pixelDensity()         and use the value provided as the scale factor for the screen in         question. Disabling is done on a 'veto' basis where either the         environment or the application source can disable. The intended use         cases are 'My system is not providing correct display density         information' and 'My application needs to work in display pixels',         respectively.          The QT_SCREEN_SCALE_FACTORS environment variable can be used to set the screen         scale factors manually.Set this to a semicolon-separated         list of scale factors (matching the order of QGuiApplications::screens()),         or to a list of name=value pairs (where name matches QScreen::name()).      Coordinate conversion functions must be used when writing code that passes     geometry across the Qt Gui / Platform plugin boundary. The main conversion     functions are:         T toNativePixels(T, QWindow *)         T fromNativePixels(T, QWindow*)      The following classes in QtGui use native pixels, for the convenience of the     plataform plugins:         QPlatformWindow         QPlatformScreen         QWindowSystemInterface (API only - Events are in device independent pixels)      As a special consideration platform plugin code should be careful about     calling QtGui geometry accessor functions:         QRect r = window->geometry();     Here the returned geometry is in device independent pixels. Add a conversion call:         QRect r = QHighDpi::toNativePixels(window->geometry());     (Avoiding calling QWindow and instead using the QPlatformWindow geometry      might be a better course of action in this case.) */
end_comment
begin_decl_stmt
DECL|member|m_factor
name|qreal
name|QHighDpiScaling
operator|::
name|m_factor
init|=
literal|1.0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_active
name|bool
name|QHighDpiScaling
operator|::
name|m_active
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_comment
DECL|member|m_active
comment|//"overall active" - is there any scale factor set.
end_comment
begin_decl_stmt
DECL|member|m_usePixelDensity
name|bool
name|QHighDpiScaling
operator|::
name|m_usePixelDensity
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_comment
DECL|member|m_usePixelDensity
comment|// use scale factor from platform plugin
end_comment
begin_decl_stmt
DECL|member|m_pixelDensityScalingActive
name|bool
name|QHighDpiScaling
operator|::
name|m_pixelDensityScalingActive
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_comment
DECL|member|m_pixelDensityScalingActive
comment|// pixel density scale factor> 1
end_comment
begin_decl_stmt
DECL|member|m_globalScalingActive
name|bool
name|QHighDpiScaling
operator|::
name|m_globalScalingActive
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_comment
DECL|member|m_globalScalingActive
comment|// global scale factor is active
end_comment
begin_decl_stmt
DECL|member|m_screenFactorSet
name|bool
name|QHighDpiScaling
operator|::
name|m_screenFactorSet
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_comment
DECL|member|m_screenFactorSet
comment|// QHighDpiScaling::setScreenFactor has been used
end_comment
begin_decl_stmt
DECL|member|m_logicalDpi
name|QDpi
name|QHighDpiScaling
operator|::
name|m_logicalDpi
init|=
name|QDpi
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
DECL|member|m_logicalDpi
comment|// The scaled logical DPI of the primary screen
end_comment
begin_comment
comment|/*     Initializes the QHighDpiScaling global variables. Called before the     platform plugin is created. */
end_comment
begin_function
DECL|function|usePixelDensity
specifier|static
specifier|inline
name|bool
name|usePixelDensity
parameter_list|()
block|{
comment|// Determine if we should set a scale factor based on the pixel density
comment|// reported by the platform plugin. There are several enablers and several
comment|// disablers. A single disable may veto all other enablers.
if|if
condition|(
name|QCoreApplication
operator|::
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_DisableHighDpiScaling
argument_list|)
condition|)
return|return
literal|false
return|;
name|bool
name|screenEnvValueOk
decl_stmt|;
specifier|const
name|int
name|screenEnvValue
init|=
name|qEnvironmentVariableIntValue
argument_list|(
name|autoScreenEnvVar
argument_list|,
operator|&
name|screenEnvValueOk
argument_list|)
decl_stmt|;
if|if
condition|(
name|screenEnvValueOk
operator|&&
name|screenEnvValue
operator|<
literal|1
condition|)
return|return
literal|false
return|;
return|return
name|QCoreApplication
operator|::
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_EnableHighDpiScaling
argument_list|)
operator|||
operator|(
name|screenEnvValueOk
operator|&&
name|screenEnvValue
operator|>
literal|0
operator|)
operator|||
operator|(
name|qEnvironmentVariableIsSet
argument_list|(
name|legacyDevicePixelEnvVar
argument_list|)
operator|&&
name|qgetenv
argument_list|(
name|legacyDevicePixelEnvVar
argument_list|)
operator|.
name|toLower
argument_list|()
operator|==
literal|"auto"
operator|)
return|;
block|}
end_function
begin_function
DECL|function|initHighDpiScaling
name|void
name|QHighDpiScaling
operator|::
name|initHighDpiScaling
parameter_list|()
block|{
comment|// Determine if there is a global scale factor set.
name|m_factor
operator|=
name|initialGlobalScaleFactor
argument_list|()
expr_stmt|;
name|m_globalScalingActive
operator|=
operator|!
name|qFuzzyCompare
argument_list|(
name|m_factor
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|m_usePixelDensity
operator|=
name|usePixelDensity
argument_list|()
expr_stmt|;
name|m_pixelDensityScalingActive
operator|=
literal|false
expr_stmt|;
comment|//set in updateHighDpiScaling below
comment|// we update m_active in updateHighDpiScaling, but while we create the
comment|// screens, we have to assume that m_usePixelDensity implies scaling
name|m_active
operator|=
name|m_globalScalingActive
operator|||
name|m_usePixelDensity
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateHighDpiScaling
name|void
name|QHighDpiScaling
operator|::
name|updateHighDpiScaling
parameter_list|()
block|{
if|if
condition|(
name|QCoreApplication
operator|::
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_DisableHighDpiScaling
argument_list|)
condition|)
return|return;
if|if
condition|(
name|m_usePixelDensity
operator|&&
operator|!
name|m_pixelDensityScalingActive
condition|)
block|{
name|Q_FOREACH
argument_list|(
argument|QScreen *screen
argument_list|,
argument|QGuiApplication::screens()
argument_list|)
block|{
if|if
condition|(
operator|!
name|qFuzzyCompare
argument_list|(
name|screenSubfactor
argument_list|(
name|screen
operator|->
name|handle
argument_list|()
argument_list|)
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
condition|)
block|{
name|m_pixelDensityScalingActive
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
name|screenFactorsEnvVar
argument_list|)
condition|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QByteArray&spec
argument_list|,
argument|qgetenv(screenFactorsEnvVar).split(
literal|';'
argument|)
argument_list|)
block|{
name|QScreen
modifier|*
name|screen
init|=
literal|0
decl_stmt|;
name|int
name|equalsPos
init|=
name|spec
operator|.
name|lastIndexOf
argument_list|(
literal|'='
argument_list|)
decl_stmt|;
name|double
name|factor
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|equalsPos
operator|>
literal|0
condition|)
block|{
comment|// support "name=factor"
name|QByteArray
name|name
init|=
name|spec
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
name|equalsPos
argument_list|)
decl_stmt|;
name|QByteArray
name|f
init|=
name|spec
operator|.
name|mid
argument_list|(
name|equalsPos
operator|+
literal|1
argument_list|)
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|factor
operator|=
name|f
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
name|Q_FOREACH
argument_list|(
argument|QScreen *s
argument_list|,
argument|QGuiApplication::screens()
argument_list|)
block|{
if|if
condition|(
name|s
operator|->
name|name
argument_list|()
operator|==
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|name
argument_list|)
condition|)
block|{
name|screen
operator|=
name|s
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
else|else
block|{
comment|// listing screens in order
name|bool
name|ok
decl_stmt|;
name|factor
operator|=
name|spec
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
name|ok
operator|&&
name|i
operator|<
name|QGuiApplication
operator|::
name|screens
argument_list|()
operator|.
name|count
argument_list|()
condition|)
name|screen
operator|=
name|QGuiApplication
operator|::
name|screens
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|screen
condition|)
name|setScreenFactor
argument_list|(
name|screen
argument_list|,
name|factor
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
block|}
name|m_active
operator|=
name|m_globalScalingActive
operator|||
name|m_screenFactorSet
operator|||
name|m_pixelDensityScalingActive
expr_stmt|;
name|QPlatformScreen
modifier|*
name|primaryScreen
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|handle
argument_list|()
decl_stmt|;
name|qreal
name|sf
init|=
name|screenSubfactor
argument_list|(
name|primaryScreen
argument_list|)
decl_stmt|;
name|QDpi
name|primaryDpi
init|=
name|primaryScreen
operator|->
name|logicalDpi
argument_list|()
decl_stmt|;
name|m_logicalDpi
operator|=
name|QDpi
argument_list|(
name|primaryDpi
operator|.
name|first
operator|/
name|sf
argument_list|,
name|primaryDpi
operator|.
name|second
operator|/
name|sf
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Sets the global scale factor which is applied to all windows. */
end_comment
begin_function
DECL|function|setGlobalFactor
name|void
name|QHighDpiScaling
operator|::
name|setGlobalFactor
parameter_list|(
name|qreal
name|factor
parameter_list|)
block|{
if|if
condition|(
name|qFuzzyCompare
argument_list|(
name|factor
argument_list|,
name|m_factor
argument_list|)
condition|)
return|return;
if|if
condition|(
operator|!
name|QGuiApplication
operator|::
name|allWindows
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QHighDpiScaling::setFactor: Should only be called when no windows exist."
argument_list|)
expr_stmt|;
name|m_globalScalingActive
operator|=
operator|!
name|qFuzzyCompare
argument_list|(
name|factor
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|m_factor
operator|=
name|m_globalScalingActive
condition|?
name|factor
else|:
name|qreal
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|m_active
operator|=
name|m_globalScalingActive
operator|||
name|m_screenFactorSet
operator|||
name|m_pixelDensityScalingActive
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|QScreen *screen
argument_list|,
argument|QGuiApplication::screens()
argument_list|)
name|screen
operator|->
name|d_func
argument_list|()
operator|->
name|updateHighDpi
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|scaleFactorProperty
specifier|static
specifier|const
name|char
name|scaleFactorProperty
index|[]
init|=
literal|"_q_scaleFactor"
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*     Sets a per-screen scale factor. */
end_comment
begin_function
DECL|function|setScreenFactor
name|void
name|QHighDpiScaling
operator|::
name|setScreenFactor
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|,
name|qreal
name|factor
parameter_list|)
block|{
name|m_screenFactorSet
operator|=
literal|true
expr_stmt|;
name|m_active
operator|=
literal|true
expr_stmt|;
name|screen
operator|->
name|setProperty
argument_list|(
name|scaleFactorProperty
argument_list|,
name|QVariant
argument_list|(
name|factor
argument_list|)
argument_list|)
expr_stmt|;
comment|// hack to force re-evaluation of screen geometry
if|if
condition|(
name|screen
operator|->
name|handle
argument_list|()
condition|)
name|screen
operator|->
name|d_func
argument_list|()
operator|->
name|setPlatformScreen
argument_list|(
name|screen
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
comment|// updates geometries based on scale factor
block|}
end_function
begin_function
DECL|function|mapPositionToNative
name|QPoint
name|QHighDpiScaling
operator|::
name|mapPositionToNative
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QPlatformScreen
modifier|*
name|platformScreen
parameter_list|)
block|{
if|if
condition|(
operator|!
name|platformScreen
condition|)
return|return
name|pos
return|;
specifier|const
name|qreal
name|scaleFactor
init|=
name|factor
argument_list|(
name|platformScreen
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|topLeft
init|=
name|platformScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
return|return
operator|(
name|pos
operator|-
name|topLeft
operator|)
operator|*
name|scaleFactor
operator|+
name|topLeft
return|;
block|}
end_function
begin_function
DECL|function|mapPositionFromNative
name|QPoint
name|QHighDpiScaling
operator|::
name|mapPositionFromNative
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QPlatformScreen
modifier|*
name|platformScreen
parameter_list|)
block|{
if|if
condition|(
operator|!
name|platformScreen
condition|)
return|return
name|pos
return|;
specifier|const
name|qreal
name|scaleFactor
init|=
name|factor
argument_list|(
name|platformScreen
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|topLeft
init|=
name|platformScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
return|return
operator|(
name|pos
operator|-
name|topLeft
operator|)
operator|/
name|scaleFactor
operator|+
name|topLeft
return|;
block|}
end_function
begin_function
DECL|function|screenSubfactor
name|qreal
name|QHighDpiScaling
operator|::
name|screenSubfactor
parameter_list|(
specifier|const
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
block|{
name|qreal
name|factor
init|=
name|qreal
argument_list|(
literal|1.0
argument_list|)
decl_stmt|;
if|if
condition|(
name|screen
condition|)
block|{
if|if
condition|(
name|m_usePixelDensity
condition|)
name|factor
operator|*=
name|screen
operator|->
name|pixelDensity
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_screenFactorSet
condition|)
block|{
name|QVariant
name|screenFactor
init|=
name|screen
operator|->
name|screen
argument_list|()
operator|->
name|property
argument_list|(
name|scaleFactorProperty
argument_list|)
decl_stmt|;
if|if
condition|(
name|screenFactor
operator|.
name|isValid
argument_list|()
condition|)
name|factor
operator|*=
name|screenFactor
operator|.
name|toReal
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|factor
return|;
block|}
end_function
begin_function
DECL|function|logicalDpi
name|QDpi
name|QHighDpiScaling
operator|::
name|logicalDpi
parameter_list|()
block|{
return|return
name|m_logicalDpi
return|;
block|}
end_function
begin_function
DECL|function|factor
name|qreal
name|QHighDpiScaling
operator|::
name|factor
parameter_list|(
specifier|const
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
comment|// Fast path for when scaling in Qt is not used at all.
if|if
condition|(
operator|!
name|m_active
condition|)
return|return
name|qreal
argument_list|(
literal|1.0
argument_list|)
return|;
comment|// The effective factor for a given screen is the product of the
comment|// screen and global sub-factors
name|qreal
name|factor
init|=
name|m_factor
decl_stmt|;
if|if
condition|(
name|screen
condition|)
name|factor
operator|*=
name|screenSubfactor
argument_list|(
name|screen
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|factor
return|;
block|}
end_function
begin_function
DECL|function|factor
name|qreal
name|QHighDpiScaling
operator|::
name|factor
parameter_list|(
specifier|const
name|QPlatformScreen
modifier|*
name|platformScreen
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_active
condition|)
return|return
name|qreal
argument_list|(
literal|1.0
argument_list|)
return|;
return|return
name|m_factor
operator|*
name|screenSubfactor
argument_list|(
name|platformScreen
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|factor
name|qreal
name|QHighDpiScaling
operator|::
name|factor
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_active
condition|)
return|return
name|qreal
argument_list|(
literal|1.0
argument_list|)
return|;
return|return
name|factor
argument_list|(
name|window
condition|?
name|window
operator|->
name|screen
argument_list|()
else|:
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|origin
name|QPoint
name|QHighDpiScaling
operator|::
name|origin
parameter_list|(
specifier|const
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
return|return
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|origin
name|QPoint
name|QHighDpiScaling
operator|::
name|origin
parameter_list|(
specifier|const
name|QPlatformScreen
modifier|*
name|platformScreen
parameter_list|)
block|{
return|return
name|platformScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_HIGHDPISCALING
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
