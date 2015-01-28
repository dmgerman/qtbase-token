begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 John Layt<jlayt@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformprintplugin.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformprintersupport.h>
end_include
begin_include
include|#
directive|include
file|<private/qprintdevice_p.h>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMimeType>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_comment
comment|/*     This test is designed to dump the current printer configuration details     to output, to assist in debugging of print device problems. */
end_comment
begin_function
DECL|function|stateToString
specifier|static
name|QString
name|stateToString
parameter_list|(
name|QPrint
operator|::
name|DeviceState
name|state
parameter_list|)
block|{
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|QPrint
operator|::
name|Idle
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Idle"
argument_list|)
return|;
case|case
name|QPrint
operator|::
name|Active
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Active"
argument_list|)
return|;
case|case
name|QPrint
operator|::
name|Aborted
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Aborted"
argument_list|)
return|;
case|case
name|QPrint
operator|::
name|Error
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Error"
argument_list|)
return|;
block|}
return|return
name|QStringLiteral
argument_list|(
literal|"Invalid DeviceState"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|duplexToString
specifier|static
name|QString
name|duplexToString
parameter_list|(
name|QPrint
operator|::
name|DuplexMode
name|duplex
parameter_list|)
block|{
switch|switch
condition|(
name|duplex
condition|)
block|{
case|case
name|QPrint
operator|::
name|DuplexNone
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"DuplexNone"
argument_list|)
return|;
case|case
name|QPrint
operator|::
name|DuplexAuto
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"DuplexAuto"
argument_list|)
return|;
case|case
name|QPrint
operator|::
name|DuplexLongSide
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"DuplexLongSide"
argument_list|)
return|;
case|case
name|QPrint
operator|::
name|DuplexShortSide
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"DuplexShortSide"
argument_list|)
return|;
block|}
return|return
name|QStringLiteral
argument_list|(
literal|"Invalid DuplexMode"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|colorToString
specifier|static
name|QString
name|colorToString
parameter_list|(
name|QPrint
operator|::
name|ColorMode
name|color
parameter_list|)
block|{
switch|switch
condition|(
name|color
condition|)
block|{
case|case
name|QPrint
operator|::
name|GrayScale
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"GrayScale"
argument_list|)
return|;
case|case
name|QPrint
operator|::
name|Color
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Color"
argument_list|)
return|;
block|}
return|return
name|QStringLiteral
argument_list|(
literal|"Invalid ColorMode"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|a
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"\n********************************"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"***** QPrintDevice Details *****"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"********************************\n"
expr_stmt|;
name|QPlatformPrinterSupport
modifier|*
name|ps
init|=
name|QPlatformPrinterSupportPlugin
operator|::
name|get
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ps
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Could not load platform plugin!"
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|QString
name|defaultId
init|=
name|ps
operator|->
name|defaultPrintDeviceId
argument_list|()
decl_stmt|;
if|if
condition|(
name|defaultId
operator|.
name|isEmpty
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"No default printer found"
expr_stmt|;
else|else
name|qDebug
argument_list|()
operator|<<
literal|"Default Printer ID    :"
operator|<<
name|defaultId
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Available Printer IDs :"
operator|<<
name|ps
operator|->
name|availablePrintDeviceIds
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
name|id
decl|,
name|ps
operator|->
name|availablePrintDeviceIds
argument_list|()
control|)
block|{
name|QPrintDevice
name|printDevice
init|=
name|ps
operator|->
name|createPrintDevice
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
name|printDevice
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"==="
operator|<<
name|printDevice
operator|.
name|id
argument_list|()
operator|<<
literal|"===\n"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Device ID       :"
operator|<<
name|printDevice
operator|.
name|id
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Device Name     :"
operator|<<
name|printDevice
operator|.
name|name
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Device Location :"
operator|<<
name|printDevice
operator|.
name|location
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Device Make     :"
operator|<<
name|printDevice
operator|.
name|makeAndModel
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"isValid   :"
operator|<<
name|printDevice
operator|.
name|isValid
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"isDefault :"
operator|<<
name|printDevice
operator|.
name|isDefault
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"isRemote  :"
operator|<<
name|printDevice
operator|.
name|isRemote
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"state :"
operator|<<
name|stateToString
argument_list|(
name|printDevice
operator|.
name|state
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportsMultipleCopies :"
operator|<<
name|printDevice
operator|.
name|supportsMultipleCopies
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportsCollateCopies  :"
operator|<<
name|printDevice
operator|.
name|supportsCollateCopies
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"defaultPageSize    :"
operator|<<
name|printDevice
operator|.
name|defaultPageSize
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportedPageSizes :"
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QPageSize
modifier|&
name|page
decl|,
name|printDevice
operator|.
name|supportedPageSizes
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
literal|"                    "
operator|<<
name|page
operator|<<
name|printDevice
operator|.
name|printableMargins
argument_list|(
name|page
argument_list|,
name|QPageLayout
operator|::
name|Portrait
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportsCustomPageSizes :"
operator|<<
name|printDevice
operator|.
name|supportsCustomPageSizes
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"minimumPhysicalPageSize :"
operator|<<
name|printDevice
operator|.
name|minimumPhysicalPageSize
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"maximumPhysicalPageSize :"
operator|<<
name|printDevice
operator|.
name|maximumPhysicalPageSize
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"defaultResolution    :"
operator|<<
name|printDevice
operator|.
name|defaultResolution
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportedResolutions :"
operator|<<
name|printDevice
operator|.
name|supportedResolutions
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"defaultInputSlot    :"
operator|<<
name|printDevice
operator|.
name|defaultInputSlot
argument_list|()
operator|.
name|key
operator|<<
name|printDevice
operator|.
name|defaultInputSlot
argument_list|()
operator|.
name|name
operator|<<
name|printDevice
operator|.
name|defaultInputSlot
argument_list|()
operator|.
name|id
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportedInputSlots :"
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QPrint
operator|::
name|InputSlot
modifier|&
name|slot
decl|,
name|printDevice
operator|.
name|supportedInputSlots
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
literal|"                     "
operator|<<
name|slot
operator|.
name|key
operator|<<
name|slot
operator|.
name|name
operator|<<
name|slot
operator|.
name|id
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"defaultOutputBin    :"
operator|<<
name|printDevice
operator|.
name|defaultOutputBin
argument_list|()
operator|.
name|key
operator|<<
name|printDevice
operator|.
name|defaultOutputBin
argument_list|()
operator|.
name|name
operator|<<
name|printDevice
operator|.
name|defaultOutputBin
argument_list|()
operator|.
name|id
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportedOutputBins :"
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QPrint
operator|::
name|OutputBin
modifier|&
name|bin
decl|,
name|printDevice
operator|.
name|supportedOutputBins
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
literal|"                     "
operator|<<
name|bin
operator|.
name|key
operator|<<
name|bin
operator|.
name|name
operator|<<
name|bin
operator|.
name|id
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"defaultDuplexMode    :"
operator|<<
name|duplexToString
argument_list|(
name|printDevice
operator|.
name|defaultDuplexMode
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportedDuplexModes :"
expr_stmt|;
foreach|foreach
control|(
name|QPrint
operator|::
name|DuplexMode
name|mode
decl|,
name|printDevice
operator|.
name|supportedDuplexModes
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
literal|"                      "
operator|<<
name|duplexToString
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"defaultColorMode    :"
operator|<<
name|colorToString
argument_list|(
name|printDevice
operator|.
name|defaultColorMode
argument_list|()
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportedColorModes :"
expr_stmt|;
foreach|foreach
control|(
name|QPrint
operator|::
name|ColorMode
name|mode
decl|,
name|printDevice
operator|.
name|supportedColorModes
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
literal|"                     "
operator|<<
name|colorToString
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|""
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"supportedMimeTypes :"
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QMimeType
modifier|&
name|type
decl|,
name|printDevice
operator|.
name|supportedMimeTypes
argument_list|()
control|)
name|qDebug
argument_list|()
operator|<<
literal|"                    "
operator|<<
name|type
operator|.
name|name
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Create printer failed"
operator|<<
name|id
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
end_function
end_unit
