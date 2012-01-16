begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QImageIOHandler     \brief The QImageIOHandler class defines the common image I/O     interface for all image formats in Qt.     \reentrant      Qt uses QImageIOHandler for reading and writing images through     QImageReader and QImageWriter. You can also derive from this class     to write your own image format handler using Qt's plugin mechanism.      Call setDevice() to assign a device to the handler, and     setFormat() to assign a format to it. One QImageIOHandler may     support more than one image format. canRead() returns true if an     image can be read from the device, and read() and write() return     true if reading or writing an image was completed successfully.      QImageIOHandler also has support for animations formats, through     the functions loopCount(), imageCount(), nextImageDelay() and     currentImageNumber().      In order to determine what options an image handler supports, Qt     will call supportsOption() and setOption(). Make sure to     reimplement these functions if you can provide support for any of     the options in the ImageOption enum.      To write your own image handler, you must at least reimplement     canRead() and read(). Then create a QImageIOPlugin that     can create the handler. Finally, install your plugin, and     QImageReader and QImageWriter will then automatically load the     plugin, and start using it.      \sa QImageIOPlugin, QImageReader, QImageWriter */
end_comment
begin_comment
comment|/*! \enum QImageIOHandler::ImageOption      This enum describes the different options supported by     QImageIOHandler.  Some options are used to query an image for     properties, and others are used to toggle the way in which an     image should be written.      \value Size The original size of an image. A handler that supports     this option is expected to read the size of the image from the     image metadata, and return this size from option() as a QSize.      \value ClipRect The clip rect, or ROI (Region Of Interest). A     handler that supports this option is expected to only read the     provided QRect area from the original image in read(), before any     other transformation is applied.      \value ScaledSize The scaled size of the image. A handler that     supports this option is expected to scale the image to the     provided size (a QSize), after applying any clip rect     transformation (ClipRect). If the handler does not support this     option, QImageReader will perform the scaling after the image has     been read.      \value ScaledClipRect The scaled clip rect (or ROI, Region Of     Interest) of the image. A handler that supports this option is     expected to apply the provided clip rect (a QRect), after applying     any scaling (ScaleSize) or regular clipping (ClipRect). If the     handler does not support this option, QImageReader will apply the     scaled clip rect after the image has been read.      \value Description The image description. Some image formats,     such as GIF and PNG, allow embedding of text     or comments into the image data (e.g., for storing copyright     information). It's common that the text is stored in key-value     pairs, but some formats store all text in one continuous block.     QImageIOHandler returns the text as one     QString, where keys and values are separated by a ':', and     keys-value pairs are separated by two newlines (\\n\\n). For example,     "Title: Sunset\\n\\nAuthor: Jim Smith\\nSarah Jones\\n\\n". Formats that     store text in a single block can use "Description" as the key.      \value CompressionRatio The compression ratio of the image data. A     handler that supports this option is expected to set its     compression rate depending on the value of this option (an int)     when writing.      \value Gamma The gamma level of the image. A handler that supports     this option is expected to set the image gamma level depending on     the value of this option (a float) when writing.      \value Quality The quality level of the image. A handler that     supports this option is expected to set the image quality level     depending on the value of this option (an int) when writing.      \value Name The name of the image. A handler that supports this     option is expected to read the name from the image metadata and     return this as a QString, or when writing an image it is expected     to store the name in the image metadata.      \value SubType The subtype of the image. A handler that supports     this option can use the subtype value to help when reading and     writing images. For example, a PPM handler may have a subtype     value of "ppm" or "ppmraw".      \value IncrementalReading A handler that supports this option is     expected to read the image in several passes, as if it was an     animation. QImageReader will treat the image as an animation.      \value Endianness The endianness of the image. Certain image     formats can be stored as BigEndian or LittleEndian. A handler that     supports Endianness uses the value of this option to determine how     the image should be stored.      \value Animation Image formats that support animation return     true for this value in supportsOption(); otherwise, false is returned.      \value BackgroundColor Certain image formats allow the     background color to be specified. A handler that supports     BackgroundColor initializes the background color to this option     (a QColor) when reading an image.      \value ImageFormat The image's data format returned by the handler.     This can be any of the formats listed in QImage::Format. */
end_comment
begin_comment
comment|/*!     \class QImageIOPlugin     \brief The QImageIOPlugin class defines an interface for writing     an image format plugin.     \reentrant      \ingroup plugins      QImageIOPlugin is a factory for creating QImageIOHandler objects,     which are used internally by QImageReader and QImageWriter to add     support for different image formats to Qt.      Writing an image I/O plugin is achieved by subclassing this     base class, reimplementing the pure virtual functions capabilities(),     create(), and keys(), and exporting the class with the     Q_EXPORT_PLUGIN2() macro. See \l{How to Create Qt Plugins} for details.      An image format plugin can support three capabilities: reading (\l     CanRead), writing (\l CanWrite) and \e incremental reading (\l     CanReadIncremental). Reimplement capabilities() in you subclass to     expose the capabilities of your image format.      create() should create an instance of your QImageIOHandler     subclass, with the provided device and format properly set, and     return this handler. You must also reimplement keys() so that Qt     knows which image formats your plugin supports.      Different plugins can support different capabilities. For example,     you may have one plugin that supports reading the GIF format, and     another that supports writing. Qt will select the correct plugin     for the job, depending on the return value of capabilities(). If     several plugins support the same capability, Qt will select one     arbitrarily.      \sa QImageIOHandler, {How to Create Qt Plugins} */
end_comment
begin_comment
comment|/*!     \enum QImageIOPlugin::Capability      This enum describes the capabilities of a QImageIOPlugin.      \value CanRead The plugin can read images.     \value CanWrite The plugin can write images.     \value CanReadIncremental The plugin can read images incrementally. */
end_comment
begin_comment
comment|/*!     \class QImageIOHandlerFactoryInterface     \brief The QImageIOHandlerFactoryInterface class provides the factory     interface for QImageIOPlugin.     \reentrant      \internal      \sa QImageIOPlugin */
end_comment
begin_include
include|#
directive|include
file|"qimageiohandler.h"
end_include
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class_decl
class_decl|class
name|QIODevice
class_decl|;
end_class_decl
begin_class
DECL|class|QImageIOHandlerPrivate
class|class
name|QImageIOHandlerPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QImageIOHandler
parameter_list|)
specifier|public
private|:
name|QImageIOHandlerPrivate
parameter_list|(
name|QImageIOHandler
modifier|*
name|q
parameter_list|)
constructor_decl|;
specifier|virtual
name|~
name|QImageIOHandlerPrivate
parameter_list|()
destructor_decl|;
DECL|member|device
name|QIODevice
modifier|*
name|device
decl_stmt|;
DECL|member|format
specifier|mutable
name|QByteArray
name|format
decl_stmt|;
DECL|member|q_ptr
name|QImageIOHandler
modifier|*
name|q_ptr
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QImageIOHandlerPrivate
name|QImageIOHandlerPrivate
operator|::
name|QImageIOHandlerPrivate
parameter_list|(
name|QImageIOHandler
modifier|*
name|q
parameter_list|)
block|{
name|device
operator|=
literal|0
expr_stmt|;
name|q_ptr
operator|=
name|q
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QImageIOHandlerPrivate
name|QImageIOHandlerPrivate
operator|::
name|~
name|QImageIOHandlerPrivate
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Constructs a QImageIOHandler object. */
end_comment
begin_constructor
DECL|function|QImageIOHandler
name|QImageIOHandler
operator|::
name|QImageIOHandler
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QImageIOHandlerPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*! \internal      Constructs a QImageIOHandler object, using the private member \a     dd. */
end_comment
begin_constructor
DECL|function|QImageIOHandler
name|QImageIOHandler
operator|::
name|QImageIOHandler
parameter_list|(
name|QImageIOHandlerPrivate
modifier|&
name|dd
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|&
name|dd
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destructs the QImageIOHandler object. */
end_comment
begin_destructor
DECL|function|~QImageIOHandler
name|QImageIOHandler
operator|::
name|~
name|QImageIOHandler
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Sets the device of the QImageIOHandler to \a device. The image     handler will use this device when reading and writing images.      The device can only be set once and must be set before calling     canRead(), read(), write(), etc. If you need to read multiple     files, construct multiple instances of the appropriate     QImageIOHandler subclass.      \sa device() */
end_comment
begin_function
DECL|function|setDevice
name|void
name|QImageIOHandler
operator|::
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QImageIOHandler
argument_list|)
expr_stmt|;
name|d
operator|->
name|device
operator|=
name|device
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the device currently assigned to the QImageIOHandler. If     not device has been assigned, 0 is returned. */
end_comment
begin_function
DECL|function|device
name|QIODevice
modifier|*
name|QImageIOHandler
operator|::
name|device
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QImageIOHandler
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|device
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the format of the QImageIOHandler to \a format. The format is     most useful for handlers that support multiple image formats.      \sa format() */
end_comment
begin_function
DECL|function|setFormat
name|void
name|QImageIOHandler
operator|::
name|setFormat
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QImageIOHandler
argument_list|)
expr_stmt|;
name|d
operator|->
name|format
operator|=
name|format
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the format of the QImageIOHandler to \a format. The format is     most useful for handlers that support multiple image formats.      This function is declared const so that it can be called from canRead().      \sa format() */
end_comment
begin_function
DECL|function|setFormat
name|void
name|QImageIOHandler
operator|::
name|setFormat
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QImageIOHandler
argument_list|)
expr_stmt|;
name|d
operator|->
name|format
operator|=
name|format
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the format that is currently assigned to     QImageIOHandler. If no format has been assigned, an empty string     is returned.      \sa setFormat() */
end_comment
begin_function
DECL|function|format
name|QByteArray
name|QImageIOHandler
operator|::
name|format
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QImageIOHandler
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|format
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QImageIOHandler::read(QImage *image)      Read an image from the device, and stores it in \a image.     Returns true if the image is successfully read; otherwise returns     false.      For image formats that support incremental loading, and for animation     formats, the image handler can assume that \a image points to the     previous frame.      \sa canRead() */
end_comment
begin_comment
comment|/*!     \fn bool QImageIOHandler::canRead() const      Returns true if an image can be read from the device (i.e., the     image format is supported, the device can be read from and the     initial header information suggests that the image can be read);     otherwise returns false.      When reimplementing canRead(), make sure that the I/O device     (device()) is left in its original state (e.g., by using peek()     rather than read()).      \sa read(), QIODevice::peek() */
end_comment
begin_comment
comment|/*!     \obsolete      Use format() instead. */
end_comment
begin_function
DECL|function|name
name|QByteArray
name|QImageIOHandler
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|format
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Writes the image \a image to the assigned device. Returns true on     success; otherwise returns false.      The default implementation does nothing, and simply returns false. */
end_comment
begin_function
DECL|function|write
name|bool
name|QImageIOHandler
operator|::
name|write
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|image
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the option \a option with the value \a value.      \sa option(), ImageOption */
end_comment
begin_function
DECL|function|setOption
name|void
name|QImageIOHandler
operator|::
name|setOption
parameter_list|(
name|ImageOption
name|option
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the value assigned to \a option as a QVariant. The type of     the value depends on the option. For example, option(Size) returns     a QSize variant.      \sa setOption(), supportsOption() */
end_comment
begin_function
DECL|function|option
name|QVariant
name|QImageIOHandler
operator|::
name|option
parameter_list|(
name|ImageOption
name|option
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the QImageIOHandler supports the option \a option;     otherwise returns false. For example, if the QImageIOHandler     supports the \l Size option, supportsOption(Size) must return     true.      \sa setOption(), option() */
end_comment
begin_function
DECL|function|supportsOption
name|bool
name|QImageIOHandler
operator|::
name|supportsOption
parameter_list|(
name|ImageOption
name|option
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     For image formats that support animation, this function returns     the sequence number of the current image in the animation. If     this function is called before any image is read(), -1 is     returned. The number of the first image in the sequence is 0.          If the image format does not support animation, 0 is returned.      \sa read() */
end_comment
begin_function
DECL|function|currentImageNumber
name|int
name|QImageIOHandler
operator|::
name|currentImageNumber
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the rect of the current image. If no rect is defined for the     image, and empty QRect() is returned.      This function is useful for animations, where only parts of the frame     may be updated at a time. */
end_comment
begin_function
DECL|function|currentImageRect
name|QRect
name|QImageIOHandler
operator|::
name|currentImageRect
parameter_list|()
specifier|const
block|{
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     For image formats that support animation, this function returns     the number of images in the animation. If the image format does     not support animation, or if it is unable to determine the number     of images, 0 is returned.      The default implementation returns 1 if canRead() returns true;     otherwise 0 is returned. */
end_comment
begin_function
DECL|function|imageCount
name|int
name|QImageIOHandler
operator|::
name|imageCount
parameter_list|()
specifier|const
block|{
return|return
name|canRead
argument_list|()
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!    For image formats that support animation, this function jumps to the    next image.     The default implementation does nothing, and returns false. */
end_comment
begin_function
DECL|function|jumpToNextImage
name|bool
name|QImageIOHandler
operator|::
name|jumpToNextImage
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!    For image formats that support animation, this function jumps to the image    whose sequence number is \a imageNumber. The next call to read() will    attempt to read this image.     The default implementation does nothing, and returns false. */
end_comment
begin_function
DECL|function|jumpToImage
name|bool
name|QImageIOHandler
operator|::
name|jumpToImage
parameter_list|(
name|int
name|imageNumber
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|imageNumber
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     For image formats that support animation, this function returns     the number of times the animation should loop. If the image format     does not support animation, 0 is returned. */
end_comment
begin_function
DECL|function|loopCount
name|int
name|QImageIOHandler
operator|::
name|loopCount
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     For image formats that support animation, this function returns     the number of milliseconds to wait until reading the next     image. If the image format does not support animation, 0 is     returned. */
end_comment
begin_function
DECL|function|nextImageDelay
name|int
name|QImageIOHandler
operator|::
name|nextImageDelay
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Constructs an image plugin with the given \a parent. This is     invoked automatically by the Q_EXPORT_PLUGIN2() macro. */
end_comment
begin_constructor
DECL|function|QImageIOPlugin
name|QImageIOPlugin
operator|::
name|QImageIOPlugin
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
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the picture format plugin.      You never have to call this explicitly. Qt destroys a plugin     automatically when it is no longer used. */
end_comment
begin_destructor
DECL|function|~QImageIOPlugin
name|QImageIOPlugin
operator|::
name|~
name|QImageIOPlugin
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*! \fn QImageIOPlugin::capabilities(QIODevice *device, const QByteArray&format) const      Returns the capabilities on the plugin, based on the data in \a     device and the format \a format. For example, if the     QImageIOHandler supports the BMP format, and the data in the     device starts with the characters "BM", this function should     return \l CanRead. If \a format is "bmp" and the handler supports     both reading and writing, this function should return \l CanRead |     \l CanWrite. */
end_comment
begin_comment
comment|/*!     \fn QImageIOPlugin::keys() const      Returns the list of image keys this plugin supports.      These keys are usually the names of the image formats that are implemented     in the plugin (e.g., "jpg" or "gif").      \sa capabilities() */
end_comment
begin_comment
comment|/*!     \fn QImageIOHandler *QImageIOPlugin::create(QIODevice *device, const QByteArray&format) const      Creates and returns a QImageIOHandler subclass, with \a device     and \a format set. The \a format must come from the list returned by keys().     Format names are case sensitive.      \sa keys() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
