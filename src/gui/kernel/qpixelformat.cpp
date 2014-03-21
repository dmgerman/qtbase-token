begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpixelformat.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPixelFormat     \inmodule QtGui     \since 5.4     \brief QPixelFormat is a class for describing different pixel     layouts in graphics buffers      In Qt there is a often a need to represent the layout of the pixels in a     graphics buffer. Internally QPixelFormat stores everything in a 64 bit     datastructure. This gives performance but also some limitations.      QPixelFormat can describe 5 color channels and 1 alpha channel, each can use     6 bits to describe the size of the color channel.      The position of the alpha channel is described with a separate enum. This is     to make it possible to describe QImage formats like ARGB32, and also     describe typical OpenGL formats like RBGA8888.      How pixels are suppose to be read is determined by the TypeInterpretation     enum.  It describes if color values are suppose to be read byte per byte,     or if a pixel is suppose to be read as a complete int and then masked.     \sa TypeInterpretation      There is no support for describing YUV's macro pixels. Instead a list of YUV     formats has been made. When a QPixelFormat is describing a YUV format, the     bitsPerPixel value has been deduced by the YUV Layout enum. Also, the color     channels should all be set to zero except the fifth color channel that     should store the bitsPerPixel value. */
comment|/*!     \enum QPixelFormat::ColorModel      This enum type is used to describe the color model of the pixelformat.      \value RGB The color model is RGB.      \value BGR This is logically the opposite endian version of RGB. However,     for ease of use it has its own model.      \value Indexed The color model uses a color palette.      \value GrayScale The color model is GrayScale.      \value CMYK The color model is CMYK.      \value HSL The color model is HSL.      \value HSV The color model is HSV.      \value YUV The color model is YUV. */
comment|/*!     \enum QPixelFormat::AlphaUsage      This enum describes if the alpha channel is used or not. Sometimes the     pixelformat will have a size for the alpha channel, but the pixel format     does actually not use the alpha channel. For example  RGB32 is such a     format. The RGB channels are 8 bits each, and there is no alpha channel.     But the complete size for each pixel is 32. Therefore the alpha channel size     is 8, but the alpha channel is ignored. Its important to note that in such     situations the position of the alpha channel is significant.      \value IgnoresAlpha The alpha channel is not used.      \value UsesAlpha    The alpha channel is used. */
comment|/*!     \enum QPixelFormat::AlphaPosition      This enum type is used to describe the alpha channels position relative to the     color channels.      \value AtBeginning The alpha channel will be put in front of the color                        channels . E.g. ARGB.      \value AtEnd       The alpha channel will be put in the back of the color                        channels. E.g. RGBA. */
comment|/*!     \enum QPixelFormat::AlphaPremultiplied      This enum type describes the boolean state if the alpha channel is multiplied     into the color channels or not.      \value NotPremultiplied The alpha channel is not multiplied into the color channels.      \value Premultiplied    The alpha channel is multiplied into the color channels. */
comment|/*!     \enum QPixelFormat::TypeInterpretation      This enum describes how each pixel is interpreted. If a pixel is read as a     full 32 bit unsigned integer and then each channel is masked out, or if     each byte is read as unsigned char values. Typically QImage formats     interpret one pixel as an unsigned integer and then the color channels are     masked out. OpenGL on the other hand typically interpreted pixels "one byte     after the other", Ie. unsigned byte.      QImage also have the format Format_RGBA8888 (and its derivatives), where     the pixels are interpreted as unsigned bytes. OpenGL has extensions that makes it     possible to upload pixel buffers in an unsigned integer format.      \image qpixelformat-argb32buffer.png An unsigned integer ARGB32 pixel.      The image above shows a ARGB pixel in memory read as an unsigned integer.     However, if this pixel was read byte for byte on a little endian system the     first byte would be the byte containing the B-channel. The next byte would     be the G-channel, then the R-channel and finally the A-channel. This shows     that on little endian systems, how each pixel is interpreted is significant     for integer formats. This is not the case on big endian systems.      \value UnsignedInteger     \value UnsignedShort     \value UnsignedByte     \value FloatingPoint */
comment|/*!     \enum QPixelFormat::ByteOrder      This enum describes the ByteOrder of the pixel format. This enum is mostly     ignored but have some use cases for YUV formats. BGR formats have their own     color model, and should not be described by using the opposite endianness     on an RGB format.      \value LittleEndian        The byte order is little endian.     \value BigEndian           The byte order is big endian.     \value CurrentSystemEndian This enum will not be stored, but is converted in                                the constructor to the endian enum that matches                                the enum of the current system.  */
comment|/*!     \enum QPixelFormat::YUVLayout      YUV is not represented by describing the size of the color channels. This is     because YUV often use macro pixels, making the concept of sperate color channels     invalid. Instead the different YUV layouts are described with this enum.      \value YUV444     \value YUV422     \value YUV411     \value YUV420P     \value YUV420SP     \value YV12     \value UYVY     \value YUYV     \value NV12     \value NV21     \value IMC1     \value IMC2     \value IMC3     \value IMC4     \value Y8     \value Y16 */
comment|/*!     \fn QPixelFormat::QPixelFormat()      Creates a null pixelformat. This format maps to QImage::Format_Invalid. */
comment|/*!     \fn QPixelFormat::QPixelFormat(ColorModel colorModel,                                    uchar firstSize,                                    uchar secondSize,                                    uchar thirdSize,                                    uchar fourthSize,                                    uchar fifthSize,                                    uchar alphaSize,                                    AlphaUsage alphaUsage,                                    AlphaPosition alphaPosition,                                    AlphaPremultiplied premultiplied,                                    TypeInterpretation typeInterpretation,                                    ByteOrder byteOrder = CurrentSystemEndian,                                    uchar subEnum = 0)      Creates a QPixelFormat which assigns its data to the attributes.     \a colorModel will be put into a buffer which is 4 bits long.      \a firstSize \a secondSize \a thirdSize \a fourthSize \a fifthSize \a     alphaSize are all meant to represent the size of a channel. The channels will     be used for different uses dependent on the \a colorModel. For RGB the     firstSize will represent the Red channel. On CMYK it will represent the     value of the Cyan channel.      \a alphaUsage represents if the alpha channel is used or not.      \a alphaPosition is the position of the alpha channel.      \a premultiplied represents if the alpha channel is already multiplied with     the color channels.      \a typeInterpretation is how the pixel is interpreted.      \a byteOrder represents the endianness of the pixelformat. This defaults to     CurrentSystemEndian.      \a subEnum is used for colorModels that have to store some extra     information with supplying an extra enum. This is used by YUV to store the     YUV type The default value is 0. */
DECL|variable|sizeof
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QPixelFormatRgb
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QPixelFormat
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \class QPixelFormatRgb     \inmodule QtGui     \since 5.4     \brief QPixelFormatRgb is a helper class for creating pixel formats with     the rgb color model      The size of QPixelFormatRgb is guaranteed to be the size of QPixelFormat. */
end_comment
begin_comment
comment|/*!     \fn QPixelFormatRgb::QPixelFormatRgb(uchar redSize,                                          uchar greenSize,                                          uchar blueSize,                                          uchar alphaSize,                                          AlphaUsage alphaUsage,                                          AlphaPosition alphaPosition,                                          AlphaPremultiplied premultiplied = NotPremultiplied,                                          TypeInterpretation typeInterpretation = UnsignedInteger)      Constructor making an RGB pixelformat. \a redSize \a greenSize \a     blueSize represent the size of each color channel. \a alphaSize describes     the alpha channel size and its position is described with \a alphaPosition.     \a alphaUsage is used to determine if the alpha channel is used or not.     Setting the alpha channel size to 8 and alphaUsage to IgnoresAlpha is how     it is possible to create a 32 bit format where the rgb channels only use 24     bits combined. \a premultiplied \a typeInterpretation are     accessible with accessors with the same name.      \sa TypeInterpretation */
end_comment
begin_expr_stmt
DECL|variable|sizeof
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QPixelFormatGrayScale
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QPixelFormat
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!     \class QPixelFormatGrayScale     \inmodule QtGui     \since 5.4     \brief QPixelFormatGrayScale is a helper class for creating pixel formats with     the gray scale color model.      The size of QPixelFormatGrayScale is guaranteed to be the size of QPixelFormat. */
end_comment
begin_comment
comment|/*!     \fn QPixelFormatGrayScale::QPixelFormatGrayScale(uchar channelSize,                                                      TypeInterpretation typeInterpretation = UnsignedInteger)      Constructor for creating a GrayScale format. Monochrome formats can be     described by passing 1 to \a channelSize. Its also possible to define very     accurate greyscale formats using doubles to describe each pixel by passing 8     as \a channelSize and FloatingPoint as \a typeInterpretation.      \sa TypeInterpretation */
end_comment
begin_expr_stmt
DECL|variable|sizeof
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QPixelFormatCmyk
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QPixelFormat
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!     \class QPixelFormatCmyk     \inmodule QtGui     \since 5.4     \brief QPixelFormatCmyk is a helper class for creating pixel formats with     the CMYK color model      The size of QPixelFormatCmyk is guaranteed to be the size of QPixelFormat. */
end_comment
begin_comment
comment|/*!     \fn QPixelFormatCmyk::QPixelFormatCmyk(uchar channelSize,                                            uchar alphaSize = 0,                                            AlphaUsage alphaUsage = IgnoresAlpha,                                            AlphaPosition alphaPosition = AtBeginning,                                            TypeInterpretation typeInterpretation = UnsignedInteger)      Constructor for creating CMYK formats. The channel count will be 4 or     5 depending on if \a alphaSize is bigger than zero or not. The CMYK color     channels will all be set to the value of \a channelSize.      \a alphaUsage \a alphaPosition and \a typeInterpretation are all accessible with     the accessors with the same name.      \sa TypeInterpretation */
end_comment
begin_expr_stmt
DECL|variable|sizeof
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QPixelFormatHsl
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QPixelFormat
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!     \class QPixelFormatHsl     \inmodule QtGui     \since 5.4     \brief QPixelFormatHsl is a helper class for creating pixel formats with     the HSL color model.      The size of QPixelFormatHsl is guaranteed to be the size of QPixelFormat. */
end_comment
begin_comment
comment|/*!     \fn QPixelFormatHsl::QPixelFormatHsl(uchar channelSize,                                          uchar alphaSize = 0,                                          AlphaUsage alphaUsage = IgnoresAlpha,                                          AlphaPosition alphaPosition = AtBeginning,                                          TypeInterpretation typeInterpretation = FloatingPoint)      Constructor for creating HSL formats. The channel count will be 3 or 4     depending on if \a alphaSize is bigger than 0.      \a channelSize will set the hueSize saturationSize and lightnessSize to the same value.      \a alphaUsage \a alphaPosition and \a typeInterpretation are all accessible with     the accessors with the same name. */
end_comment
begin_expr_stmt
DECL|variable|sizeof
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QPixelFormatHsv
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QPixelFormat
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!     \class QPixelFormatHsv     \inmodule QtGui     \since 5.4     \brief QPixelFormatHsv is a helper class for creating pixel formats with     the HSV color model.      The size of QPixelFormatHsv is guaranteed to be the size of QPixelFormat. */
end_comment
begin_comment
comment|/*!     \fn QPixelFormatHsv::QPixelFormatHsv(uchar channelSize,                                          uchar alphaSize = 0,                                          AlphaUsage alphaUsage = IgnoresAlpha,                                          AlphaPosition alphaPosition = AtBeginning,                                          TypeInterpretation typeInterpretation = FloatingPoint)      Constructor for creating HSV formats. The channel count will be 3 or 4     depending on if \a alphaSize is bigger than 0.      \a channelSize will set the hueSize saturationSize and brightnessSize to the same value.      \a alphaUsage \a alphaPosition and \a typeInterpretation are all accessible with     the accessors with the same name. */
end_comment
begin_expr_stmt
DECL|variable|sizeof
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QPixelFormatYuv
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|QPixelFormat
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!     \class QPixelFormatYuv     \inmodule QtGui     \since 5.4     \brief QPixelFormatYuv is a helper class for creating pixel formats with     the YUV color model.      The size of QPixelFormatYuv is guaranteed to be the size of QPixelFormat. */
end_comment
begin_comment
comment|/*!     \fn QPixelFormatYuv::QPixelFormatYuv(YUVLayout yuvLayout,                                          uchar alphaSize = 0,                                          AlphaUsage alphaUsage = IgnoresAlpha,                                          AlphaPosition alphaPosition = AtBeginning,                                          AlphaPremultiplied premultiplied = NotPremultiplied,                                          TypeInterpretation typeInterpretation = UnsignedByte,                                          ByteOrder byteOrder = LittleEndian)      Constructor for creating a QPixelFormat describing a YUV format with     \a yuvLayout.  \a alphaSize describes the size of a potential alpha channel     and is position is described with \a alphaPosition. The "first" "second" ..     "fifth" channels are all set to 0. \a alphaUsage \a premultiplied \a     typeInterpretation and \a byteOrder will work as with other formats. */
end_comment
begin_comment
comment|/*!     \fn ColorModel QPixelFormat::colorModel() const      Accessor function for getting the colorModel. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::channelCount() const      Accessor function for getting the channelCount. Channel Count is deduced     by color channels with a size> 0 and if the size of the alpha channel is> 0. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::redSize() const      Accessor function for the size of the red color channel. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::greenSize() const      Accessor function for the size of the green color channel. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::blueSize() const      Accessor function for the size of the blue color channel. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::cyanSize() const      Accessor function for the cyan color channel. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::magentaSize() const      Accessor function for the megenta color channel. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::yellowSize() const      Accessor function for the yellow color channel. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::blackSize() const      Accessor function for the black/key color channel. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::hueSize() const      Accessor function for the hue channel size. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::saturationSize() const      Accessor function for the saturation channel size. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::lightnessSize() const      Accessor function for the lightness channel size. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::brightnessSize() const      Accessor function for the brightness channel size. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::alphaSize() const      Accessor function for the alpha channel size. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::bitsPerPixel() const      Accessor function for the bits used per pixel. This function returns the     sum of the color channels + the size of the alpha channel. */
end_comment
begin_comment
comment|/*!     \fn AlphaPremultiplied QPixelFormat::premultiplied() const      Accessor function for the AlphaPremultiplied enum. This indicates if the     alpha channel is multiplied in to the color channels.  */
end_comment
begin_comment
comment|/*!     \fn TypeInterpretation QPixelFormat::typeInterpretation() const      Accessor function for the type representation of a color channel or a pixel.      \sa TypeInterpretation */
end_comment
begin_comment
comment|/*!     \fn ByteOrder QPixelFormat::byteOrder() const      The byte order is almost always set the the byte order of the current     system. However, it can be useful to describe some YUV formats. This     function should never return QPixelFormat::CurrentSystemEndian as this     value is translated to a endian value in the constructor. */
end_comment
begin_comment
comment|/*!     \fn AlphaUsage QPixelFormat::alphaUsage() const      Accessor function for alphaUsage. */
end_comment
begin_comment
comment|/*!     \fn AlphaPosition QPixelFormat::alphaPosition() const      Accessor function for alphaPosition. */
end_comment
begin_comment
comment|/*!     \fn YUVLayout QPixelFormat::yuvLayout() const      Accessor function for the YUVLayout. It is difficult to describe the color     channels of a YUV pixel format since YUV color model uses macro pixels.     Instead the layout of the pixels are stored as an enum. */
end_comment
begin_comment
comment|/*!     \fn uchar QPixelFormat::subEnum() const      Accessor for the datapart which contains subEnums     This is the same as the yuvLayout() function.      \sa yuvLayout()     \internal */
end_comment
begin_expr_stmt
DECL|variable|sizeof
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QPixelFormat
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|quint64
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_namespace
DECL|namespace|QtPrivate
namespace|namespace
name|QtPrivate
block|{
DECL|function|QPixelFormat_createYUV
name|QPixelFormat
name|QPixelFormat_createYUV
parameter_list|(
name|QPixelFormat
operator|::
name|YUVLayout
name|yuvLayout
parameter_list|,
name|uchar
name|alphaSize
parameter_list|,
name|QPixelFormat
operator|::
name|AlphaUsage
name|alphaUsage
parameter_list|,
name|QPixelFormat
operator|::
name|AlphaPosition
name|alphaPosition
parameter_list|,
name|QPixelFormat
operator|::
name|AlphaPremultiplied
name|premultiplied
parameter_list|,
name|QPixelFormat
operator|::
name|TypeInterpretation
name|typeInterpretation
parameter_list|,
name|QPixelFormat
operator|::
name|ByteOrder
name|byteOrder
parameter_list|)
block|{
name|uchar
name|bits_per_pixel
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|yuvLayout
condition|)
block|{
case|case
name|QPixelFormat
operator|::
name|YUV444
case|:
name|bits_per_pixel
operator|=
literal|24
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|YUV422
case|:
name|bits_per_pixel
operator|=
literal|16
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|YUV411
case|:
case|case
name|QPixelFormat
operator|::
name|YUV420P
case|:
case|case
name|QPixelFormat
operator|::
name|YUV420SP
case|:
case|case
name|QPixelFormat
operator|::
name|YV12
case|:
name|bits_per_pixel
operator|=
literal|12
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|UYVY
case|:
case|case
name|QPixelFormat
operator|::
name|YUYV
case|:
name|bits_per_pixel
operator|=
literal|16
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|NV12
case|:
case|case
name|QPixelFormat
operator|::
name|NV21
case|:
name|bits_per_pixel
operator|=
literal|12
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|IMC1
case|:
case|case
name|QPixelFormat
operator|::
name|IMC2
case|:
case|case
name|QPixelFormat
operator|::
name|IMC3
case|:
case|case
name|QPixelFormat
operator|::
name|IMC4
case|:
name|bits_per_pixel
operator|=
literal|12
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|Y8
case|:
name|bits_per_pixel
operator|=
literal|8
expr_stmt|;
break|break;
case|case
name|QPixelFormat
operator|::
name|Y16
case|:
name|bits_per_pixel
operator|=
literal|16
expr_stmt|;
break|break;
block|}
return|return
name|QPixelFormat
argument_list|(
name|QPixelFormat
operator|::
name|YUV
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|bits_per_pixel
argument_list|,
name|alphaSize
argument_list|,
name|alphaUsage
argument_list|,
name|alphaPosition
argument_list|,
name|premultiplied
argument_list|,
name|typeInterpretation
argument_list|,
name|byteOrder
argument_list|,
name|yuvLayout
argument_list|)
return|;
block|}
block|}
end_namespace
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
