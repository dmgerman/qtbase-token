begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_include
include|#
directive|include
file|"qqnxclipboard.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMimeData>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<clipboard/clipboard.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QQNXCLIPBOARD_DEBUG
end_ifdef
begin_define
DECL|macro|qClipboardDebug
define|#
directive|define
name|qClipboardDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qClipboardDebug
define|#
directive|define
name|qClipboardDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// null terminated array
DECL|variable|typeList
specifier|static
specifier|const
name|char
modifier|*
name|typeList
index|[]
init|=
block|{
literal|"text/html"
block|,
literal|"text/plain"
block|,
literal|"image/png"
block|,
literal|"image/jpeg"
block|,
literal|"application/x-color"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|readClipboardBuff
specifier|static
name|QByteArray
name|readClipboardBuff
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
block|{
name|char
modifier|*
name|pbuffer
decl_stmt|;
if|if
condition|(
name|is_clipboard_format_present
argument_list|(
name|type
argument_list|)
operator|==
literal|0
condition|)
block|{
name|int
name|size
init|=
name|get_clipboard_data
argument_list|(
name|type
argument_list|,
operator|&
name|pbuffer
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|!=
operator|-
literal|1
operator|&&
name|pbuffer
condition|)
block|{
specifier|const
name|QByteArray
name|result
init|=
name|QByteArray
argument_list|(
name|pbuffer
argument_list|,
name|size
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|pbuffer
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
block|}
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_class
DECL|class|MimeData
class|class
name|QQnxClipboard
operator|::
name|MimeData
super|:
specifier|public
name|QMimeData
block|{
name|Q_OBJECT
public|public:
DECL|function|MimeData
name|MimeData
parameter_list|(
name|QQnxClipboard
modifier|*
name|clipboard
parameter_list|)
member_init_list|:
name|QMimeData
argument_list|()
member_init_list|,
name|m_clipboard
argument_list|(
name|clipboard
argument_list|)
member_init_list|,
name|m_userMimeData
argument_list|(
literal|0
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|clipboard
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|typeList
index|[
name|i
index|]
operator|!=
literal|0
condition|;
operator|++
name|i
control|)
block|{
name|m_formatsToCheck
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
name|typeList
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|~MimeData
name|~
name|MimeData
parameter_list|()
block|{
operator|delete
name|m_userMimeData
expr_stmt|;
block|}
DECL|function|addFormatToCheck
name|void
name|addFormatToCheck
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|)
block|{
name|m_formatsToCheck
operator|<<
name|format
expr_stmt|;
name|qClipboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"formats="
operator|<<
name|m_formatsToCheck
expr_stmt|;
block|}
DECL|function|hasFormat
name|bool
name|hasFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimetype
parameter_list|)
specifier|const
block|{
specifier|const
name|bool
name|result
init|=
name|is_clipboard_format_present
argument_list|(
name|mimetype
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|==
literal|0
decl_stmt|;
name|qClipboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"mimetype="
operator|<<
name|mimetype
operator|<<
literal|"result="
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|formats
name|QStringList
name|formats
parameter_list|()
specifier|const
block|{
name|QStringList
name|result
decl_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QString&format
argument_list|,
argument|m_formatsToCheck
argument_list|)
block|{
if|if
condition|(
name|is_clipboard_format_present
argument_list|(
name|format
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|==
literal|0
condition|)
name|result
operator|<<
name|format
expr_stmt|;
block|}
name|qClipboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"result="
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|setUserMimeData
name|void
name|setUserMimeData
parameter_list|(
name|QMimeData
modifier|*
name|userMimeData
parameter_list|)
block|{
operator|delete
name|m_userMimeData
expr_stmt|;
name|m_userMimeData
operator|=
name|userMimeData
expr_stmt|;
comment|// system clipboard API doesn't allow detection of changes by other applications
comment|// simulate an owner change through delayed invocation
comment|// basically transfer ownership of data to the system clipboard once event processing resumes
if|if
condition|(
name|m_userMimeData
condition|)
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|this
argument_list|,
literal|"releaseOwnership"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
DECL|function|userMimeData
name|QMimeData
modifier|*
name|userMimeData
parameter_list|()
block|{
return|return
name|m_userMimeData
return|;
block|}
protected|protected:
DECL|function|retrieveData
name|QVariant
name|retrieveData
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimetype
parameter_list|,
name|QVariant
operator|::
name|Type
name|preferredType
parameter_list|)
specifier|const
block|{
name|qClipboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"mimetype="
operator|<<
name|mimetype
operator|<<
literal|"preferredType="
operator|<<
name|preferredType
expr_stmt|;
if|if
condition|(
name|is_clipboard_format_present
argument_list|(
name|mimetype
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|QMimeData
operator|::
name|retrieveData
argument_list|(
name|mimetype
argument_list|,
name|preferredType
argument_list|)
return|;
specifier|const
name|QByteArray
name|data
init|=
name|readClipboardBuff
argument_list|(
name|mimetype
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|data
argument_list|)
return|;
block|}
private|private
name|Q_SLOTS
private|:
DECL|function|releaseOwnership
name|void
name|releaseOwnership
parameter_list|()
block|{
if|if
condition|(
name|m_userMimeData
condition|)
block|{
name|qClipboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"user data formats="
operator|<<
name|m_userMimeData
operator|->
name|formats
argument_list|()
operator|<<
literal|"system formats="
operator|<<
name|formats
argument_list|()
expr_stmt|;
operator|delete
name|m_userMimeData
expr_stmt|;
name|m_userMimeData
operator|=
literal|0
expr_stmt|;
name|m_clipboard
operator|->
name|emitChanged
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
block|}
block|}
private|private:
DECL|member|m_clipboard
name|QQnxClipboard
modifier|*
specifier|const
name|m_clipboard
decl_stmt|;
DECL|member|m_formatsToCheck
name|QSet
argument_list|<
name|QString
argument_list|>
name|m_formatsToCheck
decl_stmt|;
DECL|member|m_userMimeData
name|QMimeData
modifier|*
name|m_userMimeData
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QQnxClipboard
name|QQnxClipboard
operator|::
name|QQnxClipboard
parameter_list|()
member_init_list|:
name|m_mimeData
argument_list|(
operator|new
name|MimeData
argument_list|(
name|this
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QQnxClipboard
name|QQnxClipboard
operator|::
name|~
name|QQnxClipboard
parameter_list|()
block|{
operator|delete
name|m_mimeData
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setMimeData
name|void
name|QQnxClipboard
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|data
parameter_list|,
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|mode
operator|!=
name|QClipboard
operator|::
name|Clipboard
condition|)
return|return;
if|if
condition|(
name|data
operator|==
name|m_mimeData
operator|||
name|data
operator|==
name|m_mimeData
operator|->
name|userMimeData
argument_list|()
condition|)
return|return;
name|empty_clipboard
argument_list|()
expr_stmt|;
name|m_mimeData
operator|->
name|clear
argument_list|()
expr_stmt|;
name|m_mimeData
operator|->
name|setUserMimeData
argument_list|(
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
operator|==
literal|0
condition|)
return|return;
specifier|const
name|QStringList
name|formats
init|=
name|data
operator|->
name|formats
argument_list|()
decl_stmt|;
name|qClipboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"formats="
operator|<<
name|formats
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QString&format
argument_list|,
argument|formats
argument_list|)
block|{
specifier|const
name|QByteArray
name|buf
init|=
name|data
operator|->
name|data
argument_list|(
name|format
argument_list|)
decl_stmt|;
if|if
condition|(
name|buf
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
name|int
name|ret
init|=
name|set_clipboard_data
argument_list|(
name|format
operator|.
name|toUtf8
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|buf
operator|.
name|size
argument_list|()
argument_list|,
name|buf
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|qClipboardDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"set "
operator|<<
name|format
operator|<<
literal|"to clipboard, size="
operator|<<
name|buf
operator|.
name|size
argument_list|()
operator|<<
literal|";ret="
operator|<<
name|ret
expr_stmt|;
if|if
condition|(
name|ret
condition|)
name|m_mimeData
operator|->
name|addFormatToCheck
argument_list|(
name|format
argument_list|)
expr_stmt|;
block|}
name|emitChanged
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QQnxClipboard
operator|::
name|mimeData
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|mode
operator|!=
name|QClipboard
operator|::
name|Clipboard
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|m_mimeData
operator|->
name|userMimeData
argument_list|()
condition|)
return|return
name|m_mimeData
operator|->
name|userMimeData
argument_list|()
return|;
name|m_mimeData
operator|->
name|clear
argument_list|()
expr_stmt|;
return|return
name|m_mimeData
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qqnxclipboard.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_CLIPBOARD
end_comment
end_unit
