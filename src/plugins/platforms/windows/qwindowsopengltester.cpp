begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsopengltester.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariantMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStandardPaths>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLibraryInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<private/qopengl_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<private/qsystemlibrary_p.h>
end_include
begin_include
include|#
directive|include
file|<d3d9.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|detect
name|GpuDescription
name|GpuDescription
operator|::
name|detect
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
typedef|typedef
name|IDirect3D9
modifier|*
function_decl|(
name|WINAPI
modifier|*
name|PtrDirect3DCreate9
function_decl|)
parameter_list|(
name|UINT
parameter_list|)
function_decl|;
name|GpuDescription
name|result
decl_stmt|;
name|QSystemLibrary
name|d3d9lib
argument_list|(
name|QStringLiteral
argument_list|(
literal|"d3d9"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d3d9lib
operator|.
name|load
argument_list|()
condition|)
return|return
name|result
return|;
name|PtrDirect3DCreate9
name|direct3DCreate9
init|=
operator|(
name|PtrDirect3DCreate9
operator|)
name|d3d9lib
operator|.
name|resolve
argument_list|(
literal|"Direct3DCreate9"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|direct3DCreate9
condition|)
return|return
name|result
return|;
name|IDirect3D9
modifier|*
name|direct3D9
init|=
name|direct3DCreate9
argument_list|(
name|D3D_SDK_VERSION
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|direct3D9
condition|)
return|return
name|result
return|;
name|D3DADAPTER_IDENTIFIER9
name|adapterIdentifier
decl_stmt|;
specifier|const
name|HRESULT
name|hr
init|=
name|direct3D9
operator|->
name|GetAdapterIdentifier
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|adapterIdentifier
argument_list|)
decl_stmt|;
name|direct3D9
operator|->
name|Release
argument_list|()
expr_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|result
operator|.
name|vendorId
operator|=
name|int
argument_list|(
name|adapterIdentifier
operator|.
name|VendorId
argument_list|)
expr_stmt|;
name|result
operator|.
name|deviceId
operator|=
name|int
argument_list|(
name|adapterIdentifier
operator|.
name|DeviceId
argument_list|)
expr_stmt|;
name|result
operator|.
name|revision
operator|=
name|int
argument_list|(
name|adapterIdentifier
operator|.
name|Revision
argument_list|)
expr_stmt|;
name|result
operator|.
name|subSysId
operator|=
name|int
argument_list|(
name|adapterIdentifier
operator|.
name|SubSysId
argument_list|)
expr_stmt|;
name|QVector
argument_list|<
name|int
argument_list|>
name|version
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|version
index|[
literal|0
index|]
operator|=
name|HIWORD
argument_list|(
name|adapterIdentifier
operator|.
name|DriverVersion
operator|.
name|HighPart
argument_list|)
expr_stmt|;
comment|// Product
name|version
index|[
literal|1
index|]
operator|=
name|LOWORD
argument_list|(
name|adapterIdentifier
operator|.
name|DriverVersion
operator|.
name|HighPart
argument_list|)
expr_stmt|;
comment|// Version
name|version
index|[
literal|2
index|]
operator|=
name|HIWORD
argument_list|(
name|adapterIdentifier
operator|.
name|DriverVersion
operator|.
name|LowPart
argument_list|)
expr_stmt|;
comment|// Sub version
name|version
index|[
literal|3
index|]
operator|=
name|LOWORD
argument_list|(
name|adapterIdentifier
operator|.
name|DriverVersion
operator|.
name|LowPart
argument_list|)
expr_stmt|;
comment|// build
name|result
operator|.
name|driverVersion
operator|=
name|QVersionNumber
argument_list|(
name|version
argument_list|)
expr_stmt|;
name|result
operator|.
name|driverName
operator|=
name|adapterIdentifier
operator|.
name|Driver
expr_stmt|;
name|result
operator|.
name|description
operator|=
name|adapterIdentifier
operator|.
name|Description
expr_stmt|;
block|}
return|return
name|result
return|;
else|#
directive|else
comment|// !Q_OS_WINCE
name|GpuDescription
name|result
decl_stmt|;
name|result
operator|.
name|vendorId
operator|=
name|result
operator|.
name|deviceId
operator|=
name|result
operator|.
name|revision
operator|=
literal|1
expr_stmt|;
name|result
operator|.
name|driverVersion
operator|=
name|QVersionNumber
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|result
operator|.
name|driverName
operator|=
name|result
operator|.
name|description
operator|=
name|QByteArrayLiteral
argument_list|(
literal|"Generic"
argument_list|)
expr_stmt|;
return|return
name|result
return|;
endif|#
directive|endif
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
specifier|const
name|GpuDescription
modifier|&
name|gd
parameter_list|)
block|{
name|QDebugStateSaver
name|s
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|d
operator|.
name|nospace
argument_list|()
expr_stmt|;
name|d
operator|<<
name|hex
operator|<<
name|showbase
operator|<<
literal|"GpuDescription(vendorId="
operator|<<
name|gd
operator|.
name|vendorId
operator|<<
literal|", deviceId="
operator|<<
name|gd
operator|.
name|deviceId
operator|<<
literal|", subSysId="
operator|<<
name|gd
operator|.
name|subSysId
operator|<<
name|dec
operator|<<
name|noshowbase
operator|<<
literal|", revision="
operator|<<
name|gd
operator|.
name|revision
operator|<<
literal|", driver: "
operator|<<
name|gd
operator|.
name|driverName
operator|<<
literal|", version="
operator|<<
name|gd
operator|.
name|driverVersion
operator|<<
literal|", "
operator|<<
name|gd
operator|.
name|description
operator|<<
literal|')'
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_DEBUG_STREAM
end_comment
begin_comment
comment|// Return printable string formatted like the output of the dxdiag tool.
end_comment
begin_function
DECL|function|toString
name|QString
name|GpuDescription
operator|::
name|toString
parameter_list|()
specifier|const
block|{
name|QString
name|result
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|"         Card name: "
operator|<<
name|description
operator|<<
literal|"\n       Driver Name: "
operator|<<
name|driverName
operator|<<
literal|"\n    Driver Version: "
operator|<<
name|driverVersion
operator|.
name|toString
argument_list|()
operator|<<
literal|"\n         Vendor ID: 0x"
operator|<<
name|qSetPadChar
argument_list|(
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
operator|<<
name|uppercasedigits
operator|<<
name|hex
operator|<<
name|qSetFieldWidth
argument_list|(
literal|4
argument_list|)
operator|<<
name|vendorId
operator|<<
literal|"\n         Device ID: 0x"
operator|<<
name|qSetFieldWidth
argument_list|(
literal|4
argument_list|)
operator|<<
name|deviceId
operator|<<
literal|"\n         SubSys ID: 0x"
operator|<<
name|qSetFieldWidth
argument_list|(
literal|8
argument_list|)
operator|<<
name|subSysId
operator|<<
literal|"\n       Revision ID: 0x"
operator|<<
name|qSetFieldWidth
argument_list|(
literal|4
argument_list|)
operator|<<
name|revision
operator|<<
name|dec
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|toVariant
name|QVariant
name|GpuDescription
operator|::
name|toVariant
parameter_list|()
specifier|const
block|{
name|QVariantMap
name|result
decl_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"vendorId"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|vendorId
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"deviceId"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|deviceId
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"subSysId"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|subSysId
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"revision"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|revision
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"driver"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|QLatin1String
argument_list|(
name|driverName
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"driverProduct"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|driverVersion
operator|.
name|segmentAt
argument_list|(
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"driverVersion"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|driverVersion
operator|.
name|segmentAt
argument_list|(
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"driverSubVersion"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|driverVersion
operator|.
name|segmentAt
argument_list|(
literal|2
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"driverBuild"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|driverVersion
operator|.
name|segmentAt
argument_list|(
literal|3
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"driverVersionString"
argument_list|)
argument_list|,
name|driverVersion
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"description"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|QLatin1String
argument_list|(
name|description
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|QStringLiteral
argument_list|(
literal|"printable"
argument_list|)
argument_list|,
name|QVariant
argument_list|(
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|requestedGlesRenderer
name|QWindowsOpenGLTester
operator|::
name|Renderer
name|QWindowsOpenGLTester
operator|::
name|requestedGlesRenderer
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|const
name|char
name|platformVar
index|[]
init|=
literal|"QT_ANGLE_PLATFORM"
decl_stmt|;
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
name|platformVar
argument_list|)
condition|)
block|{
specifier|const
name|QByteArray
name|anglePlatform
init|=
name|qgetenv
argument_list|(
name|platformVar
argument_list|)
decl_stmt|;
if|if
condition|(
name|anglePlatform
operator|==
literal|"d3d11"
condition|)
return|return
name|QWindowsOpenGLTester
operator|::
name|AngleRendererD3d11
return|;
if|if
condition|(
name|anglePlatform
operator|==
literal|"d3d9"
condition|)
return|return
name|QWindowsOpenGLTester
operator|::
name|AngleRendererD3d9
return|;
if|if
condition|(
name|anglePlatform
operator|==
literal|"warp"
condition|)
return|return
name|QWindowsOpenGLTester
operator|::
name|AngleRendererD3d11Warp
return|;
name|qCWarning
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
literal|"Invalid value set for "
operator|<<
name|platformVar
operator|<<
literal|": "
operator|<<
name|anglePlatform
expr_stmt|;
block|}
endif|#
directive|endif
comment|// !Q_OS_WINCE
return|return
name|QWindowsOpenGLTester
operator|::
name|InvalidRenderer
return|;
block|}
end_function
begin_function
DECL|function|requestedRenderer
name|QWindowsOpenGLTester
operator|::
name|Renderer
name|QWindowsOpenGLTester
operator|::
name|requestedRenderer
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|const
name|char
name|openGlVar
index|[]
init|=
literal|"QT_OPENGL"
decl_stmt|;
if|if
condition|(
name|QCoreApplication
operator|::
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_UseOpenGLES
argument_list|)
condition|)
block|{
specifier|const
name|Renderer
name|glesRenderer
init|=
name|QWindowsOpenGLTester
operator|::
name|requestedGlesRenderer
argument_list|()
decl_stmt|;
return|return
name|glesRenderer
operator|!=
name|InvalidRenderer
condition|?
name|glesRenderer
else|:
name|Gles
return|;
block|}
if|if
condition|(
name|QCoreApplication
operator|::
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_UseDesktopOpenGL
argument_list|)
condition|)
return|return
name|QWindowsOpenGLTester
operator|::
name|DesktopGl
return|;
if|if
condition|(
name|QCoreApplication
operator|::
name|testAttribute
argument_list|(
name|Qt
operator|::
name|AA_UseSoftwareOpenGL
argument_list|)
condition|)
return|return
name|QWindowsOpenGLTester
operator|::
name|SoftwareRasterizer
return|;
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
name|openGlVar
argument_list|)
condition|)
block|{
specifier|const
name|QByteArray
name|requested
init|=
name|qgetenv
argument_list|(
name|openGlVar
argument_list|)
decl_stmt|;
if|if
condition|(
name|requested
operator|==
literal|"angle"
condition|)
block|{
specifier|const
name|Renderer
name|glesRenderer
init|=
name|QWindowsOpenGLTester
operator|::
name|requestedGlesRenderer
argument_list|()
decl_stmt|;
return|return
name|glesRenderer
operator|!=
name|InvalidRenderer
condition|?
name|glesRenderer
else|:
name|Gles
return|;
block|}
if|if
condition|(
name|requested
operator|==
literal|"desktop"
condition|)
return|return
name|QWindowsOpenGLTester
operator|::
name|DesktopGl
return|;
if|if
condition|(
name|requested
operator|==
literal|"software"
condition|)
return|return
name|QWindowsOpenGLTester
operator|::
name|SoftwareRasterizer
return|;
name|qCWarning
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
literal|"Invalid value set for "
operator|<<
name|openGlVar
operator|<<
literal|": "
operator|<<
name|requested
expr_stmt|;
block|}
endif|#
directive|endif
comment|// !Q_OS_WINCE
return|return
name|QWindowsOpenGLTester
operator|::
name|InvalidRenderer
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_function
DECL|function|resolveBugListFile
specifier|static
specifier|inline
name|QString
name|resolveBugListFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
if|if
condition|(
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|isAbsolute
argument_list|()
condition|)
return|return
name|fileName
return|;
comment|// Try QLibraryInfo::SettingsPath which is typically empty unless specified in qt.conf,
comment|// then resolve via QStandardPaths::ConfigLocation.
specifier|const
name|QString
name|settingsPath
init|=
name|QLibraryInfo
operator|::
name|location
argument_list|(
name|QLibraryInfo
operator|::
name|SettingsPath
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|settingsPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// SettingsPath is empty unless specified in qt.conf.
specifier|const
name|QFileInfo
name|fi
argument_list|(
name|settingsPath
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|isFile
argument_list|()
condition|)
return|return
name|fi
operator|.
name|absoluteFilePath
argument_list|()
return|;
block|}
return|return
name|QStandardPaths
operator|::
name|locate
argument_list|(
name|QStandardPaths
operator|::
name|ConfigLocation
argument_list|,
name|fileName
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_typedef
DECL|typedef|SupportedRenderersCache
typedef|typedef
name|QHash
argument_list|<
name|QOpenGLConfig
operator|::
name|Gpu
argument_list|,
name|QWindowsOpenGLTester
operator|::
name|Renderers
argument_list|>
name|SupportedRenderersCache
typedef|;
end_typedef
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|SupportedRenderersCache
argument_list|,
argument|supportedRenderersCache
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !Q_OS_WINCE
end_comment
begin_function
DECL|function|detectSupportedRenderers
name|QWindowsOpenGLTester
operator|::
name|Renderers
name|QWindowsOpenGLTester
operator|::
name|detectSupportedRenderers
parameter_list|(
specifier|const
name|GpuDescription
modifier|&
name|gpu
parameter_list|,
name|bool
name|glesOnly
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|gpu
argument_list|)
name|Q_UNUSED
argument_list|(
argument|glesOnly
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
return|return
literal|0
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
return|return
name|QWindowsOpenGLTester
operator|::
name|Gles
return|;
else|#
directive|else
name|QOpenGLConfig
operator|::
name|Gpu
name|qgpu
init|=
name|QOpenGLConfig
operator|::
name|Gpu
operator|::
name|fromDevice
argument_list|(
name|gpu
operator|.
name|vendorId
argument_list|,
name|gpu
operator|.
name|deviceId
argument_list|,
name|gpu
operator|.
name|driverVersion
argument_list|,
name|gpu
operator|.
name|description
argument_list|)
decl_stmt|;
name|SupportedRenderersCache
modifier|*
name|srCache
init|=
name|supportedRenderersCache
argument_list|()
decl_stmt|;
name|SupportedRenderersCache
operator|::
name|const_iterator
name|it
init|=
name|srCache
operator|->
name|find
argument_list|(
name|qgpu
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|srCache
operator|->
name|cend
argument_list|()
condition|)
return|return
operator|*
name|it
return|;
name|QWindowsOpenGLTester
operator|::
name|Renderers
name|result
argument_list|(
name|QWindowsOpenGLTester
operator|::
name|AngleRendererD3d11
operator||
name|QWindowsOpenGLTester
operator|::
name|AngleRendererD3d9
operator||
name|QWindowsOpenGLTester
operator|::
name|AngleRendererD3d11Warp
operator||
name|QWindowsOpenGLTester
operator|::
name|SoftwareRasterizer
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|glesOnly
operator|&&
name|testDesktopGL
argument_list|()
condition|)
name|result
operator||=
name|QWindowsOpenGLTester
operator|::
name|DesktopGl
expr_stmt|;
name|QSet
argument_list|<
name|QString
argument_list|>
name|features
decl_stmt|;
specifier|const
name|char
name|bugListFileVar
index|[]
init|=
literal|"QT_OPENGL_BUGLIST"
decl_stmt|;
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
name|bugListFileVar
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|fileName
init|=
name|resolveBugListFile
argument_list|(
name|QFile
operator|::
name|decodeName
argument_list|(
name|qgetenv
argument_list|(
name|bugListFileVar
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
name|features
operator|=
name|QOpenGLConfig
operator|::
name|gpuFeatures
argument_list|(
name|qgpu
argument_list|,
name|fileName
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|features
operator|=
name|QOpenGLConfig
operator|::
name|gpuFeatures
argument_list|(
name|qgpu
argument_list|,
name|QStringLiteral
argument_list|(
literal|":/qt-project.org/windows/openglblacklists/default.json"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
literal|"GPU features:"
operator|<<
name|features
expr_stmt|;
if|if
condition|(
name|features
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"disable_desktopgl"
argument_list|)
argument_list|)
condition|)
block|{
comment|// Qt-specific
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
literal|"Disabling Desktop GL: "
operator|<<
name|gpu
expr_stmt|;
name|result
operator|&=
operator|~
name|QWindowsOpenGLTester
operator|::
name|DesktopGl
expr_stmt|;
block|}
if|if
condition|(
name|features
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"disable_angle"
argument_list|)
argument_list|)
condition|)
block|{
comment|// Qt-specific keyword
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
literal|"Disabling ANGLE: "
operator|<<
name|gpu
expr_stmt|;
name|result
operator|&=
operator|~
name|QWindowsOpenGLTester
operator|::
name|GlesMask
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|features
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"disable_d3d11"
argument_list|)
argument_list|)
condition|)
block|{
comment|// standard keyword
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
literal|"Disabling D3D11: "
operator|<<
name|gpu
expr_stmt|;
name|result
operator|&=
operator|~
name|QWindowsOpenGLTester
operator|::
name|AngleRendererD3d11
expr_stmt|;
block|}
if|if
condition|(
name|features
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"disable_d3d9"
argument_list|)
argument_list|)
condition|)
block|{
comment|// Qt-specific
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
literal|"Disabling D3D9: "
operator|<<
name|gpu
expr_stmt|;
name|result
operator|&=
operator|~
name|QWindowsOpenGLTester
operator|::
name|AngleRendererD3d9
expr_stmt|;
block|}
block|}
if|if
condition|(
name|features
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"disable_rotation"
argument_list|)
argument_list|)
condition|)
block|{
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
literal|"Disabling rotation: "
operator|<<
name|gpu
expr_stmt|;
name|result
operator||=
name|DisableRotationFlag
expr_stmt|;
block|}
name|srCache
operator|->
name|insert
argument_list|(
name|qgpu
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|result
return|;
endif|#
directive|endif
comment|// !Q_OS_WINCE&& !QT_NO_OPENGL
block|}
end_function
begin_function
DECL|function|supportedGlesRenderers
name|QWindowsOpenGLTester
operator|::
name|Renderers
name|QWindowsOpenGLTester
operator|::
name|supportedGlesRenderers
parameter_list|()
block|{
specifier|const
name|GpuDescription
name|gpu
init|=
name|GpuDescription
operator|::
name|detect
argument_list|()
decl_stmt|;
specifier|const
name|QWindowsOpenGLTester
operator|::
name|Renderers
name|result
init|=
name|detectSupportedRenderers
argument_list|(
name|gpu
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|gpu
operator|<<
literal|"renderer: "
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|supportedRenderers
name|QWindowsOpenGLTester
operator|::
name|Renderers
name|QWindowsOpenGLTester
operator|::
name|supportedRenderers
parameter_list|()
block|{
specifier|const
name|GpuDescription
name|gpu
init|=
name|GpuDescription
operator|::
name|detect
argument_list|()
decl_stmt|;
specifier|const
name|QWindowsOpenGLTester
operator|::
name|Renderers
name|result
init|=
name|detectSupportedRenderers
argument_list|(
name|gpu
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|gpu
operator|<<
literal|"renderer: "
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|testDesktopGL
name|bool
name|QWindowsOpenGLTester
operator|::
name|testDesktopGL
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|HMODULE
name|lib
init|=
literal|0
decl_stmt|;
name|HWND
name|wnd
init|=
literal|0
decl_stmt|;
name|HDC
name|dc
init|=
literal|0
decl_stmt|;
name|HGLRC
name|context
init|=
literal|0
decl_stmt|;
name|LPCTSTR
name|className
init|=
literal|L"qtopengltest"
decl_stmt|;
name|HGLRC
function_decl|(
name|WINAPI
modifier|*
name|CreateContext
function_decl|)
parameter_list|(
name|HDC
name|dc
parameter_list|)
function_decl|=
literal|0
function_decl|;
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|DeleteContext
function_decl|)
parameter_list|(
name|HGLRC
name|context
parameter_list|)
function_decl|=
literal|0
function_decl|;
name|BOOL
function_decl|(
name|WINAPI
modifier|*
name|MakeCurrent
function_decl|)
parameter_list|(
name|HDC
name|dc
parameter_list|,
name|HGLRC
name|context
parameter_list|)
function_decl|=
literal|0
function_decl|;
name|PROC
function_decl|(
name|WINAPI
modifier|*
name|WGL_GetProcAddress
function_decl|)
parameter_list|(
name|LPCSTR
name|name
parameter_list|)
function_decl|=
literal|0
function_decl|;
name|bool
name|result
init|=
literal|false
decl_stmt|;
comment|// Test #1: Load opengl32.dll and try to resolve an OpenGL 2 function.
comment|// This will typically fail on systems that do not have a real OpenGL driver.
name|lib
operator|=
name|LoadLibraryA
argument_list|(
literal|"opengl32.dll"
argument_list|)
expr_stmt|;
if|if
condition|(
name|lib
condition|)
block|{
name|CreateContext
operator|=
cast|reinterpret_cast
argument_list|<
name|HGLRC
operator|(
name|WINAPI
operator|*
operator|)
operator|(
name|HDC
operator|)
argument_list|>
argument_list|(
operator|::
name|GetProcAddress
argument_list|(
name|lib
argument_list|,
literal|"wglCreateContext"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|CreateContext
condition|)
goto|goto
name|cleanup
goto|;
name|DeleteContext
operator|=
cast|reinterpret_cast
argument_list|<
name|BOOL
operator|(
name|WINAPI
operator|*
operator|)
operator|(
name|HGLRC
operator|)
argument_list|>
argument_list|(
operator|::
name|GetProcAddress
argument_list|(
name|lib
argument_list|,
literal|"wglDeleteContext"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|DeleteContext
condition|)
goto|goto
name|cleanup
goto|;
name|MakeCurrent
operator|=
expr|reinterpret_cast
operator|<
name|BOOL
argument_list|(
name|WINAPI
operator|*
argument_list|)
argument_list|(
name|HDC
argument_list|,
name|HGLRC
argument_list|)
operator|>
operator|(
operator|::
name|GetProcAddress
argument_list|(
name|lib
argument_list|,
literal|"wglMakeCurrent"
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|MakeCurrent
condition|)
goto|goto
name|cleanup
goto|;
name|WGL_GetProcAddress
operator|=
cast|reinterpret_cast
argument_list|<
name|PROC
operator|(
name|WINAPI
operator|*
operator|)
operator|(
name|LPCSTR
operator|)
argument_list|>
argument_list|(
operator|::
name|GetProcAddress
argument_list|(
name|lib
argument_list|,
literal|"wglGetProcAddress"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|WGL_GetProcAddress
condition|)
goto|goto
name|cleanup
goto|;
name|WNDCLASS
name|wclass
decl_stmt|;
name|wclass
operator|.
name|cbClsExtra
operator|=
literal|0
expr_stmt|;
name|wclass
operator|.
name|cbWndExtra
operator|=
literal|0
expr_stmt|;
name|wclass
operator|.
name|hInstance
operator|=
operator|(
name|HINSTANCE
operator|)
name|GetModuleHandle
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|wclass
operator|.
name|hIcon
operator|=
literal|0
expr_stmt|;
name|wclass
operator|.
name|hCursor
operator|=
literal|0
expr_stmt|;
name|wclass
operator|.
name|hbrBackground
operator|=
call|(
name|HBRUSH
call|)
argument_list|(
name|COLOR_BACKGROUND
argument_list|)
expr_stmt|;
name|wclass
operator|.
name|lpszMenuName
operator|=
literal|0
expr_stmt|;
name|wclass
operator|.
name|lpfnWndProc
operator|=
name|DefWindowProc
expr_stmt|;
name|wclass
operator|.
name|lpszClassName
operator|=
name|className
expr_stmt|;
name|wclass
operator|.
name|style
operator|=
name|CS_OWNDC
expr_stmt|;
if|if
condition|(
operator|!
name|RegisterClass
argument_list|(
operator|&
name|wclass
argument_list|)
condition|)
goto|goto
name|cleanup
goto|;
name|wnd
operator|=
name|CreateWindow
argument_list|(
name|className
argument_list|,
literal|L"qtopenglproxytest"
argument_list|,
name|WS_OVERLAPPED
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|640
argument_list|,
literal|480
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|wclass
operator|.
name|hInstance
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|wnd
condition|)
goto|goto
name|cleanup
goto|;
name|dc
operator|=
name|GetDC
argument_list|(
name|wnd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|dc
condition|)
goto|goto
name|cleanup
goto|;
name|PIXELFORMATDESCRIPTOR
name|pfd
decl_stmt|;
name|memset
argument_list|(
operator|&
name|pfd
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|PIXELFORMATDESCRIPTOR
argument_list|)
argument_list|)
expr_stmt|;
name|pfd
operator|.
name|nSize
operator|=
sizeof|sizeof
argument_list|(
name|PIXELFORMATDESCRIPTOR
argument_list|)
expr_stmt|;
name|pfd
operator|.
name|nVersion
operator|=
literal|1
expr_stmt|;
name|pfd
operator|.
name|dwFlags
operator|=
name|PFD_SUPPORT_OPENGL
operator||
name|PFD_DRAW_TO_WINDOW
operator||
name|PFD_GENERIC_FORMAT
expr_stmt|;
name|pfd
operator|.
name|iPixelType
operator|=
name|PFD_TYPE_RGBA
expr_stmt|;
comment|// Use the GDI functions. Under the hood this will call the wgl variants in opengl32.dll.
name|int
name|pixelFormat
init|=
name|ChoosePixelFormat
argument_list|(
name|dc
argument_list|,
operator|&
name|pfd
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|pixelFormat
condition|)
goto|goto
name|cleanup
goto|;
if|if
condition|(
operator|!
name|SetPixelFormat
argument_list|(
name|dc
argument_list|,
name|pixelFormat
argument_list|,
operator|&
name|pfd
argument_list|)
condition|)
goto|goto
name|cleanup
goto|;
name|context
operator|=
name|CreateContext
argument_list|(
name|dc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|context
condition|)
goto|goto
name|cleanup
goto|;
if|if
condition|(
operator|!
name|MakeCurrent
argument_list|(
name|dc
argument_list|,
name|context
argument_list|)
condition|)
goto|goto
name|cleanup
goto|;
comment|// Now that there is finally a context current, try doing something useful.
comment|// Check the version. If we got 1.x then it's all hopeless and we can stop right here.
typedef|typedef
specifier|const
name|GLubyte
modifier|*
function_decl|(
name|APIENTRY
modifier|*
name|GetString_t
function_decl|)
parameter_list|(
name|GLenum
name|name
parameter_list|)
function_decl|;
name|GetString_t
name|GetString
init|=
cast|reinterpret_cast
argument_list|<
name|GetString_t
argument_list|>
argument_list|(
operator|::
name|GetProcAddress
argument_list|(
name|lib
argument_list|,
literal|"glGetString"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|GetString
condition|)
block|{
specifier|const
name|char
modifier|*
name|versionStr
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|GetString
argument_list|(
name|GL_VERSION
argument_list|)
decl_stmt|;
if|if
condition|(
name|versionStr
condition|)
block|{
specifier|const
name|QByteArray
name|version
argument_list|(
name|versionStr
argument_list|)
decl_stmt|;
specifier|const
name|int
name|majorDot
init|=
name|version
operator|.
name|indexOf
argument_list|(
literal|'.'
argument_list|)
decl_stmt|;
if|if
condition|(
name|majorDot
operator|!=
operator|-
literal|1
condition|)
block|{
name|int
name|minorDot
init|=
name|version
operator|.
name|indexOf
argument_list|(
literal|'.'
argument_list|,
name|majorDot
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|minorDot
operator|==
operator|-
literal|1
condition|)
name|minorDot
operator|=
name|version
operator|.
name|size
argument_list|()
expr_stmt|;
specifier|const
name|int
name|major
init|=
name|version
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
name|majorDot
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
specifier|const
name|int
name|minor
init|=
name|version
operator|.
name|mid
argument_list|(
name|majorDot
operator|+
literal|1
argument_list|,
name|minorDot
operator|-
name|majorDot
operator|-
literal|1
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|,
literal|"Basic wglCreateContext gives version %d.%d"
argument_list|,
name|major
argument_list|,
name|minor
argument_list|)
expr_stmt|;
comment|// Try to be as lenient as possible. Missing version, bogus values and
comment|// such are all accepted. The driver may still be functional. Only
comment|// check for known-bad cases, like versions "1.4.0 ...".
if|if
condition|(
name|major
operator|==
literal|1
condition|)
block|{
name|result
operator|=
literal|false
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|,
literal|"OpenGL version too low"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
else|else
block|{
name|result
operator|=
literal|false
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|,
literal|"OpenGL 1.x entry points not found"
argument_list|)
expr_stmt|;
block|}
comment|// Check for a shader-specific function.
if|if
condition|(
name|WGL_GetProcAddress
argument_list|(
literal|"glCreateShader"
argument_list|)
condition|)
block|{
name|result
operator|=
literal|true
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|,
literal|"OpenGL 2.0 entry points available"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|,
literal|"OpenGL 2.0 entry points not found"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|qCDebug
argument_list|(
name|lcQpaGl
argument_list|,
literal|"Failed to load opengl32.dll"
argument_list|)
expr_stmt|;
block|}
name|cleanup
label|:
if|if
condition|(
name|MakeCurrent
condition|)
name|MakeCurrent
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|context
condition|)
name|DeleteContext
argument_list|(
name|context
argument_list|)
expr_stmt|;
if|if
condition|(
name|dc
operator|&&
name|wnd
condition|)
name|ReleaseDC
argument_list|(
name|wnd
argument_list|,
name|dc
argument_list|)
expr_stmt|;
if|if
condition|(
name|wnd
condition|)
block|{
name|DestroyWindow
argument_list|(
name|wnd
argument_list|)
expr_stmt|;
name|UnregisterClass
argument_list|(
name|className
argument_list|,
name|GetModuleHandle
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// No FreeLibrary. Some implementations, Mesa in particular, deadlock when trying to unload.
return|return
name|result
return|;
else|#
directive|else
return|return
literal|false
return|;
endif|#
directive|endif
comment|// !QT_NO_OPENGL&& !Q_OS_WINCE
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
