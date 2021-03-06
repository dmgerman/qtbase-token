begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmimedata.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"qurl.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"qtextcodec.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|textUriListLiteral
specifier|static
specifier|inline
name|QString
name|textUriListLiteral
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"text/uri-list"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|textHtmlLiteral
specifier|static
specifier|inline
name|QString
name|textHtmlLiteral
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"text/html"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|textPlainLiteral
specifier|static
specifier|inline
name|QString
name|textPlainLiteral
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"text/plain"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|applicationXColorLiteral
specifier|static
specifier|inline
name|QString
name|applicationXColorLiteral
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"application/x-color"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|applicationXQtImageLiteral
specifier|static
specifier|inline
name|QString
name|applicationXQtImageLiteral
parameter_list|()
block|{
return|return
name|QStringLiteral
argument_list|(
literal|"application/x-qt-image"
argument_list|)
return|;
block|}
end_function
begin_struct
DECL|struct|QMimeDataStruct
struct|struct
name|QMimeDataStruct
block|{
DECL|member|format
name|QString
name|format
decl_stmt|;
DECL|member|data
name|QVariant
name|data
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMimeDataStruct
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_class
DECL|class|QMimeDataPrivate
class|class
name|QMimeDataPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QMimeData
parameter_list|)
specifier|public
private|:
name|void
name|removeData
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|setData
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|data
parameter_list|)
function_decl|;
name|QVariant
name|getData
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
specifier|const
function_decl|;
name|QVariant
name|retrieveTypedData
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
specifier|const
function_decl|;
DECL|member|dataList
name|QVector
argument_list|<
name|QMimeDataStruct
argument_list|>
name|dataList
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|removeData
name|void
name|QMimeDataPrivate
operator|::
name|removeData
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
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
name|dataList
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|dataList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|format
operator|==
name|format
condition|)
block|{
name|dataList
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_function
begin_function
DECL|function|setData
name|void
name|QMimeDataPrivate
operator|::
name|setData
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|data
parameter_list|)
block|{
comment|// remove it first if the format is already here.
name|removeData
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|QMimeDataStruct
name|mimeData
decl_stmt|;
name|mimeData
operator|.
name|format
operator|=
name|format
expr_stmt|;
name|mimeData
operator|.
name|data
operator|=
name|data
expr_stmt|;
name|dataList
operator|+=
name|mimeData
expr_stmt|;
block|}
end_function
begin_function
DECL|function|getData
name|QVariant
name|QMimeDataPrivate
operator|::
name|getData
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
specifier|const
block|{
name|QVariant
name|data
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
name|dataList
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|dataList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|format
operator|==
name|format
condition|)
block|{
name|data
operator|=
name|dataList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|data
expr_stmt|;
break|break;
block|}
block|}
return|return
name|data
return|;
block|}
end_function
begin_function
DECL|function|retrieveTypedData
name|QVariant
name|QMimeDataPrivate
operator|::
name|retrieveTypedData
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
name|QVariant
name|data
init|=
name|q
operator|->
name|retrieveData
argument_list|(
name|format
argument_list|,
name|type
argument_list|)
decl_stmt|;
comment|// Text data requested: fallback to URL data if available
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"text/plain"
argument_list|)
operator|&&
operator|!
name|data
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|data
operator|=
name|retrieveTypedData
argument_list|(
name|textUriListLiteral
argument_list|()
argument_list|,
name|QVariant
operator|::
name|List
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Url
condition|)
block|{
name|data
operator|=
name|QVariant
argument_list|(
name|data
operator|.
name|toUrl
argument_list|()
operator|.
name|toDisplayString
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|List
condition|)
block|{
name|QString
name|text
decl_stmt|;
name|int
name|numUrls
init|=
literal|0
decl_stmt|;
specifier|const
name|QList
argument_list|<
name|QVariant
argument_list|>
name|list
init|=
name|data
operator|.
name|toList
argument_list|()
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
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Url
condition|)
block|{
name|text
operator|.
name|append
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toUrl
argument_list|()
operator|.
name|toDisplayString
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
expr_stmt|;
operator|++
name|numUrls
expr_stmt|;
block|}
block|}
if|if
condition|(
name|numUrls
operator|==
literal|1
condition|)
name|text
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// no final '\n' if there's only one URL
name|data
operator|=
name|QVariant
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|type
operator|||
operator|!
name|data
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|data
return|;
comment|// provide more conversion possiblities than just what QVariant provides
comment|// URLs can be lists as well...
if|if
condition|(
operator|(
name|type
operator|==
name|QVariant
operator|::
name|Url
operator|&&
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|List
operator|)
operator|||
operator|(
name|type
operator|==
name|QVariant
operator|::
name|List
operator|&&
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Url
operator|)
condition|)
return|return
name|data
return|;
comment|// images and pixmaps are interchangeable
if|if
condition|(
operator|(
name|type
operator|==
name|QVariant
operator|::
name|Pixmap
operator|&&
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Image
operator|)
operator|||
operator|(
name|type
operator|==
name|QVariant
operator|::
name|Image
operator|&&
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Pixmap
operator|)
condition|)
return|return
name|data
return|;
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|ByteArray
condition|)
block|{
comment|// see if we can convert to the requested type
switch|switch
condition|(
name|type
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
case|case
name|QVariant
operator|::
name|String
case|:
block|{
specifier|const
name|QByteArray
name|ba
init|=
name|data
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
name|QTextCodec
modifier|*
name|codec
init|=
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"utf-8"
argument_list|)
decl_stmt|;
if|if
condition|(
name|format
operator|==
name|QLatin1String
argument_list|(
literal|"text/html"
argument_list|)
condition|)
name|codec
operator|=
name|QTextCodec
operator|::
name|codecForHtml
argument_list|(
name|ba
argument_list|,
name|codec
argument_list|)
expr_stmt|;
return|return
name|codec
operator|->
name|toUnicode
argument_list|(
name|ba
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// QT_NO_TEXTCODEC
case|case
name|QVariant
operator|::
name|Color
case|:
block|{
name|QVariant
name|newData
init|=
name|data
decl_stmt|;
name|newData
operator|.
name|convert
argument_list|(
name|QVariant
operator|::
name|Color
argument_list|)
expr_stmt|;
return|return
name|newData
return|;
block|}
case|case
name|QVariant
operator|::
name|List
case|:
block|{
if|if
condition|(
name|format
operator|!=
name|QLatin1String
argument_list|(
literal|"text/uri-list"
argument_list|)
condition|)
break|break;
comment|// fall through
block|}
case|case
name|QVariant
operator|::
name|Url
case|:
block|{
name|QByteArray
name|ba
init|=
name|data
operator|.
name|toByteArray
argument_list|()
decl_stmt|;
comment|// Qt 3.x will send text/uri-list with a trailing
comment|// null-terminator (that is *not* sent for any other
comment|// text/* mime-type), so chop it off
if|if
condition|(
name|ba
operator|.
name|endsWith
argument_list|(
literal|'\0'
argument_list|)
condition|)
name|ba
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|urls
init|=
name|ba
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|list
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
name|urls
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QByteArray
name|ba
init|=
name|urls
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ba
operator|.
name|isEmpty
argument_list|()
condition|)
name|list
operator|.
name|append
argument_list|(
name|QUrl
operator|::
name|fromEncoded
argument_list|(
name|ba
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|list
return|;
block|}
default|default:
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|type
operator|==
name|QVariant
operator|::
name|ByteArray
condition|)
block|{
comment|// try to convert to bytearray
switch|switch
condition|(
name|data
operator|.
name|type
argument_list|()
condition|)
block|{
case|case
name|QVariant
operator|::
name|ByteArray
case|:
case|case
name|QVariant
operator|::
name|Color
case|:
return|return
name|data
operator|.
name|toByteArray
argument_list|()
return|;
case|case
name|QVariant
operator|::
name|String
case|:
return|return
name|data
operator|.
name|toString
argument_list|()
operator|.
name|toUtf8
argument_list|()
return|;
case|case
name|QVariant
operator|::
name|Url
case|:
return|return
name|data
operator|.
name|toUrl
argument_list|()
operator|.
name|toEncoded
argument_list|()
return|;
case|case
name|QVariant
operator|::
name|List
case|:
block|{
comment|// has to be list of URLs
name|QByteArray
name|result
decl_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|list
init|=
name|data
operator|.
name|toList
argument_list|()
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
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Url
condition|)
block|{
name|result
operator|+=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toUrl
argument_list|()
operator|.
name|toEncoded
argument_list|()
expr_stmt|;
name|result
operator|+=
literal|"\r\n"
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|result
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|result
return|;
break|break;
block|}
default|default:
break|break;
block|}
block|}
return|return
name|data
return|;
block|}
end_function
begin_comment
comment|/*!     \class QMimeData     \inmodule QtCore     \brief The QMimeData class provides a container for data that records information     about its MIME type.      QMimeData is used to describe information that can be stored in     the \l{QClipboard}{clipboard}, and transferred via the \l{drag     and drop} mechanism. QMimeData objects associate the data that     they hold with the corresponding MIME types to ensure that     information can be safely transferred between applications, and     copied around within the same application.      QMimeData objects are usually created using \c new and supplied     to QDrag or QClipboard objects. This is to enable Qt to manage     the memory that they use.      A single QMimeData object can store the same data using several     different formats at the same time. The formats() function     returns a list of the available formats in order of preference.     The data() function returns the raw data associated with a MIME     type, and setData() allows you to set the data for a MIME type.      For the most common MIME types, QMimeData provides convenience     functions to access the data:      \table     \header \li Tester       \li Getter       \li Setter           \li MIME Types     \row    \li hasText()    \li text()       \li setText()        \li \c text/plain     \row    \li hasHtml()    \li html()       \li setHtml()        \li \c text/html     \row    \li hasUrls()    \li urls()       \li setUrls()        \li \c text/uri-list     \row    \li hasImage()   \li imageData()  \li setImageData()   \li \c image/ *     \row    \li hasColor()   \li colorData()  \li setColorData()   \li \c application/x-color     \endtable      For example, if your write a widget that accepts URL drags, you     would end up writing code like this:      \snippet code/src_corelib_kernel_qmimedata.cpp 0      There are three approaches for storing custom data in a QMimeData     object:      \list 1     \li  Custom data can be stored directly in a QMimeData object as a         QByteArray using setData(). For example:          \snippet code/src_corelib_kernel_qmimedata.cpp 1      \li  We can subclass QMimeData and reimplement hasFormat(),         formats(), and retrieveData().      \li  If the drag and drop operation occurs within a single         application, we can subclass QMimeData and add extra data in         it, and use a qobject_cast() in the receiver's drop event         handler. For example:          \snippet code/src_corelib_kernel_qmimedata.cpp 2     \endlist      \section1 Platform-Specific MIME Types      On Windows, formats() will also return custom formats available     in the MIME data, using the \c{x-qt-windows-mime} subtype to     indicate that they represent data in non-standard formats.     The formats will take the following form:      \snippet code/src_corelib_kernel_qmimedata.cpp 3      The following are examples of custom MIME types:      \snippet code/src_corelib_kernel_qmimedata.cpp 4      The \c value declaration of each format describes the way in which the     data is encoded.      In some cases (e.g. dropping multiple email attachments), multiple data     values are available. They can be accessed by adding an \c index value:      \snippet code/src_corelib_kernel_qmimedata.cpp 8      On Windows, the MIME format does not always map directly to the     clipboard formats. Qt provides QWinMime to map clipboard     formats to open-standard MIME formats. Similarly, the     QMacPasteboardMime maps MIME to Mac flavors.      \sa QClipboard, QDragEnterEvent, QDragMoveEvent, QDropEvent, QDrag,         QMacPasteboardMime, {Drag and Drop} */
end_comment
begin_comment
comment|/*!     Constructs a new MIME data object with no data in it. */
end_comment
begin_constructor
DECL|function|QMimeData
name|QMimeData
operator|::
name|QMimeData
parameter_list|()
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QMimeDataPrivate
argument_list|,
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the MIME data object. */
end_comment
begin_destructor
DECL|function|~QMimeData
name|QMimeData
operator|::
name|~
name|QMimeData
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns a list of URLs contained within the MIME data object.      URLs correspond to the MIME type \c text/uri-list.      \sa hasUrls(), data() */
end_comment
begin_function
DECL|function|urls
name|QList
argument_list|<
name|QUrl
argument_list|>
name|QMimeData
operator|::
name|urls
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
name|QVariant
name|data
init|=
name|d
operator|->
name|retrieveTypedData
argument_list|(
name|textUriListLiteral
argument_list|()
argument_list|,
name|QVariant
operator|::
name|List
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QUrl
argument_list|>
name|urls
decl_stmt|;
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Url
condition|)
name|urls
operator|.
name|append
argument_list|(
name|data
operator|.
name|toUrl
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|List
condition|)
block|{
name|QList
argument_list|<
name|QVariant
argument_list|>
name|list
init|=
name|data
operator|.
name|toList
argument_list|()
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
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Url
condition|)
name|urls
operator|.
name|append
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toUrl
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|urls
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the URLs stored in the MIME data object to those specified by \a urls.      URLs correspond to the MIME type \c text/uri-list.      Since Qt 5.0, setUrls also exports the urls as plain text, if setText     was not called before, to make it possible to drop them into any lineedit     and text editor.      \sa hasUrls(), setData() */
end_comment
begin_function
DECL|function|setUrls
name|void
name|QMimeData
operator|::
name|setUrls
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QUrl
argument_list|>
modifier|&
name|urls
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMimeData
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|list
decl_stmt|;
specifier|const
name|int
name|numUrls
init|=
name|urls
operator|.
name|size
argument_list|()
decl_stmt|;
name|list
operator|.
name|reserve
argument_list|(
name|numUrls
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
name|numUrls
condition|;
operator|++
name|i
control|)
name|list
operator|.
name|append
argument_list|(
name|urls
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|setData
argument_list|(
name|textUriListLiteral
argument_list|()
argument_list|,
name|list
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the object can return a list of urls; otherwise     returns \c false.      URLs correspond to the MIME type \c text/uri-list.      \sa setUrls(), urls(), hasFormat() */
end_comment
begin_function
DECL|function|hasUrls
name|bool
name|QMimeData
operator|::
name|hasUrls
parameter_list|()
specifier|const
block|{
return|return
name|hasFormat
argument_list|(
name|textUriListLiteral
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a plain text (MIME type \c text/plain) representation of     the data.      \sa hasText(), html(), data() */
end_comment
begin_function
DECL|function|text
name|QString
name|QMimeData
operator|::
name|text
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
name|QVariant
name|data
init|=
name|d
operator|->
name|retrieveTypedData
argument_list|(
name|textPlainLiteral
argument_list|()
argument_list|,
name|QVariant
operator|::
name|String
argument_list|)
decl_stmt|;
return|return
name|data
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets \a text as the plain text (MIME type \c text/plain) used to     represent the data.      \sa hasText(), setHtml(), setData() */
end_comment
begin_function
DECL|function|setText
name|void
name|QMimeData
operator|::
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMimeData
argument_list|)
expr_stmt|;
name|d
operator|->
name|setData
argument_list|(
name|textPlainLiteral
argument_list|()
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the object can return plain text (MIME type \c     text/plain); otherwise returns \c false.      \sa setText(), text(), hasHtml(), hasFormat() */
end_comment
begin_function
DECL|function|hasText
name|bool
name|QMimeData
operator|::
name|hasText
parameter_list|()
specifier|const
block|{
return|return
name|hasFormat
argument_list|(
name|textPlainLiteral
argument_list|()
argument_list|)
operator|||
name|hasUrls
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a string if the data stored in the object is HTML (MIME     type \c text/html); otherwise returns an empty string.      \sa hasHtml(), setData() */
end_comment
begin_function
DECL|function|html
name|QString
name|QMimeData
operator|::
name|html
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
name|QVariant
name|data
init|=
name|d
operator|->
name|retrieveTypedData
argument_list|(
name|textHtmlLiteral
argument_list|()
argument_list|,
name|QVariant
operator|::
name|String
argument_list|)
decl_stmt|;
return|return
name|data
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets \a html as the HTML (MIME type \c text/html) used to     represent the data.      \sa hasHtml(), setText(), setData() */
end_comment
begin_function
DECL|function|setHtml
name|void
name|QMimeData
operator|::
name|setHtml
parameter_list|(
specifier|const
name|QString
modifier|&
name|html
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMimeData
argument_list|)
expr_stmt|;
name|d
operator|->
name|setData
argument_list|(
name|textHtmlLiteral
argument_list|()
argument_list|,
name|html
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the object can return HTML (MIME type \c     text/html); otherwise returns \c false.      \sa setHtml(), html(), hasFormat() */
end_comment
begin_function
DECL|function|hasHtml
name|bool
name|QMimeData
operator|::
name|hasHtml
parameter_list|()
specifier|const
block|{
return|return
name|hasFormat
argument_list|(
name|textHtmlLiteral
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a QVariant storing a QImage if the object can return an     image; otherwise returns a null variant.      A QVariant is used because QMimeData belongs to the Qt Core     module, whereas QImage belongs to Qt GUI. To convert the     QVariant to a QImage, simply use qvariant_cast(). For example:      \snippet code/src_corelib_kernel_qmimedata.cpp 5      \sa hasImage() */
end_comment
begin_function
DECL|function|imageData
name|QVariant
name|QMimeData
operator|::
name|imageData
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|retrieveTypedData
argument_list|(
name|applicationXQtImageLiteral
argument_list|()
argument_list|,
name|QVariant
operator|::
name|Image
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the data in the object to the given \a image.      A QVariant is used because QMimeData belongs to the Qt Core     module, whereas QImage belongs to Qt GUI. The conversion     from QImage to QVariant is implicit. For example:      \snippet code/src_corelib_kernel_qmimedata.cpp 6      \sa hasImage(), setData() */
end_comment
begin_function
DECL|function|setImageData
name|void
name|QMimeData
operator|::
name|setImageData
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|image
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMimeData
argument_list|)
expr_stmt|;
name|d
operator|->
name|setData
argument_list|(
name|applicationXQtImageLiteral
argument_list|()
argument_list|,
name|image
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the object can return an image; otherwise returns     false.      \sa setImageData(), imageData(), hasFormat() */
end_comment
begin_function
DECL|function|hasImage
name|bool
name|QMimeData
operator|::
name|hasImage
parameter_list|()
specifier|const
block|{
return|return
name|hasFormat
argument_list|(
name|applicationXQtImageLiteral
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a color if the data stored in the object represents a     color (MIME type \c application/x-color); otherwise returns a     null variant.      A QVariant is used because QMimeData belongs to the Qt Core     module, whereas QColor belongs to Qt GUI. To convert the     QVariant to a QColor, simply use qvariant_cast(). For example:      \snippet code/src_corelib_kernel_qmimedata.cpp 7      \sa hasColor(), setColorData(), data() */
end_comment
begin_function
DECL|function|colorData
name|QVariant
name|QMimeData
operator|::
name|colorData
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|retrieveTypedData
argument_list|(
name|applicationXColorLiteral
argument_list|()
argument_list|,
name|QVariant
operator|::
name|Color
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the color data in the object to the given \a color.      Colors correspond to the MIME type \c application/x-color.      \sa hasColor(), setData() */
end_comment
begin_function
DECL|function|setColorData
name|void
name|QMimeData
operator|::
name|setColorData
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|color
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMimeData
argument_list|)
expr_stmt|;
name|d
operator|->
name|setData
argument_list|(
name|applicationXColorLiteral
argument_list|()
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the object can return a color (MIME type \c     application/x-color); otherwise returns \c false.      \sa setColorData(), colorData(), hasFormat() */
end_comment
begin_function
DECL|function|hasColor
name|bool
name|QMimeData
operator|::
name|hasColor
parameter_list|()
specifier|const
block|{
return|return
name|hasFormat
argument_list|(
name|applicationXColorLiteral
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the data stored in the object in the format described by     the MIME type specified by \a mimeType. */
end_comment
begin_function
DECL|function|data
name|QByteArray
name|QMimeData
operator|::
name|data
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
name|QVariant
name|data
init|=
name|d
operator|->
name|retrieveTypedData
argument_list|(
name|mimeType
argument_list|,
name|QVariant
operator|::
name|ByteArray
argument_list|)
decl_stmt|;
return|return
name|data
operator|.
name|toByteArray
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the data associated with the MIME type given by \a mimeType     to the specified \a data.      For the most common types of data, you can call the higher-level     functions setText(), setHtml(), setUrls(), setImageData(), and     setColorData() instead.      Note that if you want to use a custom data type in an item view drag and drop     operation, you must register it as a Qt \l{QMetaType}{meta type}, using the     Q_DECLARE_METATYPE() macro, and implement stream operators for it. The stream     operators must then be registered with the qRegisterMetaTypeStreamOperators()     function.      \sa hasFormat(), QMetaType, {QMetaType::}{qRegisterMetaTypeStreamOperators()} */
end_comment
begin_function
DECL|function|setData
name|void
name|QMimeData
operator|::
name|setData
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMimeData
argument_list|)
expr_stmt|;
if|if
condition|(
name|mimeType
operator|==
name|QLatin1String
argument_list|(
literal|"text/uri-list"
argument_list|)
condition|)
block|{
name|QByteArray
name|ba
init|=
name|data
decl_stmt|;
if|if
condition|(
name|ba
operator|.
name|endsWith
argument_list|(
literal|'\0'
argument_list|)
condition|)
name|ba
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|urls
init|=
name|ba
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|list
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
name|urls
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QByteArray
name|ba
init|=
name|urls
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ba
operator|.
name|isEmpty
argument_list|()
condition|)
name|list
operator|.
name|append
argument_list|(
name|QUrl
operator|::
name|fromEncoded
argument_list|(
name|ba
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|setData
argument_list|(
name|mimeType
argument_list|,
name|list
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|setData
argument_list|(
name|mimeType
argument_list|,
name|QVariant
argument_list|(
name|data
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the object can return data for the MIME type     specified by \a mimeType; otherwise returns \c false.      For the most common types of data, you can call the higher-level     functions hasText(), hasHtml(), hasUrls(), hasImage(), and     hasColor() instead.      \sa formats(), setData(), data() */
end_comment
begin_function
DECL|function|hasFormat
name|bool
name|QMimeData
operator|::
name|hasFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|)
specifier|const
block|{
return|return
name|formats
argument_list|()
operator|.
name|contains
argument_list|(
name|mimeType
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of formats supported by the object. This is a list     of MIME types for which the object can return suitable data. The     formats in the list are in a priority order.      For the most common types of data, you can call the higher-level     functions hasText(), hasHtml(), hasUrls(), hasImage(), and     hasColor() instead.      \sa hasFormat(), setData(), data() */
end_comment
begin_function
DECL|function|formats
name|QStringList
name|QMimeData
operator|::
name|formats
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
name|QStringList
name|list
decl_stmt|;
specifier|const
name|int
name|size
init|=
name|d
operator|->
name|dataList
operator|.
name|size
argument_list|()
decl_stmt|;
name|list
operator|.
name|reserve
argument_list|(
name|size
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
name|size
condition|;
operator|++
name|i
control|)
name|list
operator|+=
name|d
operator|->
name|dataList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|format
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a variant with the given \a type containing data for the     MIME type specified by \a mimeType. If the object does not     support the MIME type or variant type given, a null variant is     returned instead.      This function is called by the general data() getter and by the     convenience getters (text(), html(), urls(), imageData(), and     colorData()). You can reimplement it if you want to store your     data using a custom data structure (instead of a QByteArray,     which is what setData() provides). You would then also need     to reimplement hasFormat() and formats().      \sa data() */
end_comment
begin_function
DECL|function|retrieveData
name|QVariant
name|QMimeData
operator|::
name|retrieveData
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|,
name|QVariant
operator|::
name|Type
name|type
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
specifier|const
name|QMimeData
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|getData
argument_list|(
name|mimeType
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Removes all the MIME type and data entries in the object. */
end_comment
begin_function
DECL|function|clear
name|void
name|QMimeData
operator|::
name|clear
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QMimeData
argument_list|)
expr_stmt|;
name|d
operator|->
name|dataList
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4      Removes the data entry for \a mimeType in the object. */
end_comment
begin_function
DECL|function|removeFormat
name|void
name|QMimeData
operator|::
name|removeFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMimeData
argument_list|)
expr_stmt|;
name|d
operator|->
name|removeData
argument_list|(
name|mimeType
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
