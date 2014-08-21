begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbmime.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextCodec>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImageWriter>
end_include
begin_include
include|#
directive|include
file|<QtCore/QBuffer>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include
begin_undef
DECL|macro|XCB_ATOM_STRING
undef|#
directive|undef
name|XCB_ATOM_STRING
end_undef
begin_undef
DECL|macro|XCB_ATOM_PIXMAP
undef|#
directive|undef
name|XCB_ATOM_PIXMAP
end_undef
begin_undef
DECL|macro|XCB_ATOM_BITMAP
undef|#
directive|undef
name|XCB_ATOM_BITMAP
end_undef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|QT_NO_DRAGANDDROP
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_NO_CLIPBOARD
argument_list|)
operator|)
end_if
begin_constructor
DECL|function|QXcbMime
name|QXcbMime
operator|::
name|QXcbMime
parameter_list|()
member_init_list|:
name|QInternalMimeData
argument_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QXcbMime
name|QXcbMime
operator|::
name|~
name|QXcbMime
parameter_list|()
block|{}
end_destructor
begin_function
DECL|function|mimeAtomToString
name|QString
name|QXcbMime
operator|::
name|mimeAtomToString
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_atom_t
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
name|XCB_NONE
condition|)
return|return
name|QString
argument_list|()
return|;
comment|// special cases for string type
if|if
condition|(
name|a
operator|==
name|XCB_ATOM_STRING
operator|||
name|a
operator|==
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
operator|||
name|a
operator|==
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|TEXT
argument_list|)
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
return|;
comment|// special case for images
if|if
condition|(
name|a
operator|==
name|XCB_ATOM_PIXMAP
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"image/ppm"
argument_list|)
return|;
name|QByteArray
name|atomName
init|=
name|connection
operator|->
name|atomName
argument_list|(
name|a
argument_list|)
decl_stmt|;
comment|// special cases for uris
if|if
condition|(
name|atomName
operator|==
literal|"text/x-moz-url"
condition|)
name|atomName
operator|=
literal|"text/uri-list"
expr_stmt|;
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|atomName
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mimeDataForAtom
name|bool
name|QXcbMime
operator|::
name|mimeDataForAtom
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_atom_t
name|a
parameter_list|,
name|QMimeData
modifier|*
name|mimeData
parameter_list|,
name|QByteArray
modifier|*
name|data
parameter_list|,
name|xcb_atom_t
modifier|*
name|atomFormat
parameter_list|,
name|int
modifier|*
name|dataFormat
parameter_list|)
block|{
if|if
condition|(
operator|!
name|data
condition|)
return|return
literal|false
return|;
name|bool
name|ret
init|=
literal|false
decl_stmt|;
operator|*
name|atomFormat
operator|=
name|a
expr_stmt|;
operator|*
name|dataFormat
operator|=
literal|8
expr_stmt|;
if|if
condition|(
operator|(
name|a
operator|==
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
operator|||
name|a
operator|==
name|XCB_ATOM_STRING
operator|||
name|a
operator|==
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|TEXT
argument_list|)
operator|)
operator|&&
name|QInternalMimeData
operator|::
name|hasFormatHelper
argument_list|(
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|,
name|mimeData
argument_list|)
condition|)
block|{
if|if
condition|(
name|a
operator|==
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
condition|)
block|{
operator|*
name|data
operator|=
name|QInternalMimeData
operator|::
name|renderDataHelper
argument_list|(
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|,
name|mimeData
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|a
operator|==
name|XCB_ATOM_STRING
operator|||
name|a
operator|==
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|TEXT
argument_list|)
condition|)
block|{
comment|// ICCCM says STRING is latin1
operator|*
name|data
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|QInternalMimeData
operator|::
name|renderDataHelper
argument_list|(
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|,
name|mimeData
argument_list|)
argument_list|)
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
name|ret
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
name|QString
name|atomName
init|=
name|mimeAtomToString
argument_list|(
name|connection
argument_list|,
name|a
argument_list|)
decl_stmt|;
if|if
condition|(
name|QInternalMimeData
operator|::
name|hasFormatHelper
argument_list|(
name|atomName
argument_list|,
name|mimeData
argument_list|)
condition|)
block|{
operator|*
name|data
operator|=
name|QInternalMimeData
operator|::
name|renderDataHelper
argument_list|(
name|atomName
argument_list|,
name|mimeData
argument_list|)
expr_stmt|;
if|if
condition|(
name|atomName
operator|==
name|QLatin1String
argument_list|(
literal|"application/x-color"
argument_list|)
condition|)
operator|*
name|dataFormat
operator|=
literal|16
expr_stmt|;
name|ret
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|atomName
operator|==
name|QLatin1String
argument_list|(
literal|"text/x-moz-url"
argument_list|)
operator|&&
name|QInternalMimeData
operator|::
name|hasFormatHelper
argument_list|(
name|QLatin1String
argument_list|(
literal|"text/uri-list"
argument_list|)
argument_list|,
name|mimeData
argument_list|)
condition|)
block|{
name|QByteArray
name|uri
init|=
name|QInternalMimeData
operator|::
name|renderDataHelper
argument_list|(
name|QLatin1String
argument_list|(
literal|"text/uri-list"
argument_list|)
argument_list|,
name|mimeData
argument_list|)
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|)
operator|.
name|first
argument_list|()
decl_stmt|;
name|QString
name|mozUri
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|uri
argument_list|,
name|uri
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|mozUri
operator|+=
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
operator|*
name|data
operator|=
name|QByteArray
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|mozUri
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|mozUri
operator|.
name|length
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|a
operator|==
name|XCB_ATOM_PIXMAP
operator|||
name|a
operator|==
name|XCB_ATOM_BITMAP
operator|)
operator|&&
name|mimeData
operator|->
name|hasImage
argument_list|()
condition|)
block|{
name|ret
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|mimeAtomsForFormat
name|QVector
argument_list|<
name|xcb_atom_t
argument_list|>
name|QXcbMime
operator|::
name|mimeAtomsForFormat
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
block|{
name|QVector
argument_list|<
name|xcb_atom_t
argument_list|>
name|atoms
decl_stmt|;
name|atoms
operator|.
name|reserve
argument_list|(
literal|7
argument_list|)
expr_stmt|;
name|atoms
operator|.
name|append
argument_list|(
name|connection
operator|->
name|internAtom
argument_list|(
name|format
operator|.
name|toLatin1
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// special cases for strings
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
condition|)
block|{
name|atoms
operator|.
name|append
argument_list|(
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
argument_list|)
expr_stmt|;
name|atoms
operator|.
name|append
argument_list|(
name|XCB_ATOM_STRING
argument_list|)
expr_stmt|;
name|atoms
operator|.
name|append
argument_list|(
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|TEXT
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// special cases for uris
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"text/uri-list"
argument_list|)
condition|)
name|atoms
operator|.
name|append
argument_list|(
name|connection
operator|->
name|internAtom
argument_list|(
literal|"text/x-moz-url"
argument_list|)
argument_list|)
expr_stmt|;
comment|//special cases for images
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"image/ppm"
argument_list|)
condition|)
name|atoms
operator|.
name|append
argument_list|(
name|XCB_ATOM_PIXMAP
argument_list|)
expr_stmt|;
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"image/pbm"
argument_list|)
condition|)
name|atoms
operator|.
name|append
argument_list|(
name|XCB_ATOM_BITMAP
argument_list|)
expr_stmt|;
return|return
name|atoms
return|;
block|}
end_function
begin_function
DECL|function|mimeConvertToFormat
name|QVariant
name|QXcbMime
operator|::
name|mimeConvertToFormat
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_atom_t
name|a
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
name|QVariant
operator|::
name|Type
name|requestedType
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|encoding
parameter_list|)
block|{
name|QString
name|atomName
init|=
name|mimeAtomToString
argument_list|(
name|connection
argument_list|,
name|a
argument_list|)
decl_stmt|;
comment|//    qDebug()<< "mimeConvertDataToFormat"<< format<< atomName<< data;
if|if
condition|(
operator|!
name|encoding
operator|.
name|isEmpty
argument_list|()
operator|&&
name|atomName
operator|==
name|format
operator|+
name|QLatin1String
argument_list|(
literal|";charset="
argument_list|)
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
name|encoding
argument_list|)
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
if|if
condition|(
name|requestedType
operator|==
name|QVariant
operator|::
name|String
condition|)
block|{
name|QTextCodec
modifier|*
name|codec
init|=
name|QTextCodec
operator|::
name|codecForName
argument_list|(
name|encoding
argument_list|)
decl_stmt|;
if|if
condition|(
name|codec
condition|)
return|return
name|codec
operator|->
name|toUnicode
argument_list|(
name|data
argument_list|)
return|;
block|}
endif|#
directive|endif
return|return
name|data
return|;
block|}
comment|// special cases for string types
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
condition|)
block|{
if|if
condition|(
name|a
operator|==
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
condition|)
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|data
argument_list|)
return|;
if|if
condition|(
name|a
operator|==
name|XCB_ATOM_STRING
operator|||
name|a
operator|==
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|TEXT
argument_list|)
condition|)
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|data
argument_list|)
return|;
block|}
comment|// special case for uri types
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"text/uri-list"
argument_list|)
condition|)
block|{
if|if
condition|(
name|atomName
operator|==
name|QLatin1String
argument_list|(
literal|"text/x-moz-url"
argument_list|)
condition|)
block|{
comment|// we expect this as utf16<url><space><title>
comment|// the first part is a url that should only contain ascci char
comment|// so it should be safe to check that the second char is 0
comment|// to verify that it is utf16
if|if
condition|(
name|data
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|&&
name|data
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
literal|0
condition|)
return|return
name|QString
operator|::
name|fromRawData
argument_list|(
operator|(
specifier|const
name|QChar
operator|*
operator|)
name|data
operator|.
name|constData
argument_list|()
argument_list|,
name|data
operator|.
name|size
argument_list|()
operator|/
literal|2
argument_list|)
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
operator|.
name|first
argument_list|()
operator|.
name|toLatin1
argument_list|()
return|;
block|}
block|}
if|if
condition|(
name|atomName
operator|==
name|format
condition|)
return|return
name|data
return|;
if|#
directive|if
literal|0
comment|// ###
comment|// special case for images
block|if (format == QLatin1String("image/ppm")) {         if (a == XCB_ATOM_PIXMAP&& data.size() == sizeof(Pixmap)) {             Pixmap xpm = *((Pixmap*)data.data());             if (!xpm)                 return QByteArray();             Window root;             int x;             int y;             uint width;             uint height;             uint border_width;             uint depth;              XGetGeometry(display, xpm,&root,&x,&y,&width,&height,&border_width,&depth);             XImage *ximg = XGetImage(display,xpm,x,y,width,height,AllPlanes,depth==1 ? XYPixmap : ZPixmap);             QImage qimg = QXlibStatic::qimageFromXImage(ximg);             XDestroyImage(ximg);              QImageWriter imageWriter;             imageWriter.setFormat("PPMRAW");             QBuffer buf;             buf.open(QIODevice::WriteOnly);             imageWriter.setDevice(&buf);             imageWriter.write(qimg);             return buf.buffer();         }     }
endif|#
directive|endif
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|mimeAtomForFormat
name|xcb_atom_t
name|QXcbMime
operator|::
name|mimeAtomForFormat
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
name|QVariant
operator|::
name|Type
name|requestedType
parameter_list|,
specifier|const
name|QVector
argument_list|<
name|xcb_atom_t
argument_list|>
modifier|&
name|atoms
parameter_list|,
name|QByteArray
modifier|*
name|requestedEncoding
parameter_list|)
block|{
name|requestedEncoding
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|// find matches for string types
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
condition|)
block|{
if|if
condition|(
name|atoms
operator|.
name|contains
argument_list|(
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
argument_list|)
condition|)
return|return
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|UTF8_STRING
argument_list|)
return|;
if|if
condition|(
name|atoms
operator|.
name|contains
argument_list|(
name|XCB_ATOM_STRING
argument_list|)
condition|)
return|return
name|XCB_ATOM_STRING
return|;
if|if
condition|(
name|atoms
operator|.
name|contains
argument_list|(
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|TEXT
argument_list|)
argument_list|)
condition|)
return|return
name|connection
operator|->
name|atom
argument_list|(
name|QXcbAtom
operator|::
name|TEXT
argument_list|)
return|;
block|}
comment|// find matches for uri types
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"text/uri-list"
argument_list|)
condition|)
block|{
name|xcb_atom_t
name|a
init|=
name|connection
operator|->
name|internAtom
argument_list|(
name|format
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|&&
name|atoms
operator|.
name|contains
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|a
return|;
name|a
operator|=
name|connection
operator|->
name|internAtom
argument_list|(
literal|"text/x-moz-url"
argument_list|)
expr_stmt|;
if|if
condition|(
name|a
operator|&&
name|atoms
operator|.
name|contains
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|a
return|;
block|}
comment|// find match for image
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"image/ppm"
argument_list|)
condition|)
block|{
if|if
condition|(
name|atoms
operator|.
name|contains
argument_list|(
name|XCB_ATOM_PIXMAP
argument_list|)
condition|)
return|return
name|XCB_ATOM_PIXMAP
return|;
block|}
comment|// for string/text requests try to use a format with a well-defined charset
comment|// first to avoid encoding problems
if|if
condition|(
name|requestedType
operator|==
name|QVariant
operator|::
name|String
operator|&&
name|format
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"text/"
argument_list|)
argument_list|)
operator|&&
operator|!
name|format
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"charset="
argument_list|)
argument_list|)
condition|)
block|{
name|QString
name|formatWithCharset
init|=
name|format
decl_stmt|;
name|formatWithCharset
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|";charset=utf-8"
argument_list|)
argument_list|)
expr_stmt|;
name|xcb_atom_t
name|a
init|=
name|connection
operator|->
name|internAtom
argument_list|(
name|formatWithCharset
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|&&
name|atoms
operator|.
name|contains
argument_list|(
name|a
argument_list|)
condition|)
block|{
operator|*
name|requestedEncoding
operator|=
literal|"utf-8"
expr_stmt|;
return|return
name|a
return|;
block|}
block|}
name|xcb_atom_t
name|a
init|=
name|connection
operator|->
name|internAtom
argument_list|(
name|format
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|a
operator|&&
name|atoms
operator|.
name|contains
argument_list|(
name|a
argument_list|)
condition|)
return|return
name|a
return|;
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !(defined(QT_NO_DRAGANDDROP)&& defined(QT_NO_CLIPBOARD))
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
