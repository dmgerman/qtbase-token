begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIMAGEREADER_H
end_ifndef
begin_define
DECL|macro|QIMAGEREADER_H
define|#
directive|define
name|QIMAGEREADER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimageiohandler.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QColor
decl_stmt|;
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
DECL|variable|QImageReaderPrivate
name|class
name|QImageReaderPrivate
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QImageReader
decl_stmt|{ public:     enum ImageReaderError
block|{
name|UnknownError
operator|,
name|FileNotFoundError
operator|,
name|DeviceError
operator|,
name|UnsupportedFormatError
operator|,
name|InvalidDataError
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QImageReader
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|explicit
name|QImageReader
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|format
init|=
name|QByteArray
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|explicit
name|QImageReader
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|format
init|=
name|QByteArray
argument_list|()
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
operator|~
name|QImageReader
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFormat
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QByteArray
name|format
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setAutoDetectImageFormat
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|autoDetectImageFormat
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDecideFormatFromContent
parameter_list|(
name|bool
name|ignored
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|decideFormatFromContent
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QSize
name|size
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QImage
operator|::
name|Format
name|imageFormat
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QStringList
name|textKeys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|text
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|setClipRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QRect
name|clipRect
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setScaledSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QSize
name|scaledSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setQuality
parameter_list|(
name|int
name|quality
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|quality
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setScaledClipRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QRect
name|scaledClipRect
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setBackgroundColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QColor
name|backgroundColor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|supportsAnimation
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|canRead
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QImage
name|read
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|read
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|jumpToNextImage
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|jumpToImage
parameter_list|(
name|int
name|imageNumber
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|int
name|loopCount
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|imageCount
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|nextImageDelay
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|int
name|currentImageNumber
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QRect
name|currentImageRect
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|ImageReaderError
name|error
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|supportsOption
argument_list|(
name|QImageIOHandler
operator|::
name|ImageOption
name|option
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|QByteArray
name|imageFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QByteArray
name|imageFormat
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|supportedImageFormats
argument_list|()
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QImageReader
argument_list|)
end_macro
begin_decl_stmt
name|QImageReaderPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIMAGEREADER_H
end_comment
end_unit
