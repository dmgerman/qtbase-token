begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsole.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsmime.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QClipboard>
end_include
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
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
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qwindowsguieventdispatcher_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QWindowsClipboard     \brief Clipboard implementation.      Registers a non-visible clipboard viewer window that     receives clipboard events in its own window procedure to be     able to receive clipboard-changed events, which     QPlatformClipboard needs to emit. That requires housekeeping     of the next in the viewer chain.      \note The OLE-functions used in this class require OleInitialize().      \internal     \ingroup qt-lighthouse-win */
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
DECL|function|operator <<
specifier|static
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
specifier|const
name|QMimeData
modifier|*
name|mimeData
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
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
literal|"QMimeData("
expr_stmt|;
if|if
condition|(
name|mimeData
condition|)
block|{
specifier|const
name|QStringList
name|formats
init|=
name|mimeData
operator|->
name|formats
argument_list|()
decl_stmt|;
name|d
operator|<<
literal|"formats="
operator|<<
name|formats
operator|.
name|join
argument_list|(
name|QStringLiteral
argument_list|(
literal|", "
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|mimeData
operator|->
name|hasText
argument_list|()
condition|)
name|d
operator|<<
literal|", text="
operator|<<
name|mimeData
operator|->
name|text
argument_list|()
expr_stmt|;
if|if
condition|(
name|mimeData
operator|->
name|hasHtml
argument_list|()
condition|)
name|d
operator|<<
literal|", html="
operator|<<
name|mimeData
operator|->
name|html
argument_list|()
expr_stmt|;
if|if
condition|(
name|mimeData
operator|->
name|hasColor
argument_list|()
condition|)
name|d
operator|<<
literal|", colorData="
operator|<<
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|mimeData
operator|->
name|colorData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|mimeData
operator|->
name|hasImage
argument_list|()
condition|)
name|d
operator|<<
literal|", imageData="
operator|<<
name|qvariant_cast
argument_list|<
name|QImage
argument_list|>
argument_list|(
name|mimeData
operator|->
name|imageData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|mimeData
operator|->
name|hasUrls
argument_list|()
condition|)
name|d
operator|<<
literal|", urls="
operator|<<
name|mimeData
operator|->
name|urls
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|d
operator|<<
literal|'0'
expr_stmt|;
block|}
name|d
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
comment|/*!     \class QWindowsClipboardRetrievalMimeData     \brief Special mime data class managing delayed retrieval of clipboard data.      Implementation of QWindowsInternalMimeDataBase that obtains the     IDataObject from the clipboard.      \sa QWindowsInternalMimeDataBase, QWindowsClipboard     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_function
DECL|function|retrieveDataObject
name|IDataObject
modifier|*
name|QWindowsClipboardRetrievalMimeData
operator|::
name|retrieveDataObject
parameter_list|()
specifier|const
block|{
name|IDataObject
modifier|*
name|pDataObj
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|OleGetClipboard
argument_list|(
operator|&
name|pDataObj
argument_list|)
operator|==
name|S_OK
condition|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verbose
operator|>
literal|1
condition|)
name|qCDebug
argument_list|(
name|lcQpaMime
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|pDataObj
expr_stmt|;
return|return
name|pDataObj
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|releaseDataObject
name|void
name|QWindowsClipboardRetrievalMimeData
operator|::
name|releaseDataObject
parameter_list|(
name|IDataObject
modifier|*
name|dataObject
parameter_list|)
specifier|const
block|{
name|dataObject
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
end_function
begin_extern
DECL|function|qClipboardViewerWndProc
extern|extern
literal|"C"
name|LRESULT
name|QT_WIN_CALLBACK
name|qClipboardViewerWndProc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
block|{
name|LRESULT
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|QWindowsClipboard
operator|::
name|instance
argument_list|()
operator|&&
name|QWindowsClipboard
operator|::
name|instance
argument_list|()
operator|->
name|clipboardViewerWndProc
argument_list|(
name|hwnd
argument_list|,
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|,
operator|&
name|result
argument_list|)
condition|)
return|return
name|result
return|;
return|return
name|DefWindowProc
argument_list|(
name|hwnd
argument_list|,
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
return|;
block|}
end_extern
begin_comment
comment|// QTBUG-36958, ensure the clipboard is flushed before
end_comment
begin_comment
comment|// QGuiApplication is destroyed since OleFlushClipboard()
end_comment
begin_comment
comment|// might query the data again which causes problems
end_comment
begin_comment
comment|// for QMimeData-derived classes using QPixmap/QImage.
end_comment
begin_function
DECL|function|cleanClipboardPostRoutine
specifier|static
name|void
name|cleanClipboardPostRoutine
parameter_list|()
block|{
if|if
condition|(
name|QWindowsClipboard
modifier|*
name|cl
init|=
name|QWindowsClipboard
operator|::
name|instance
argument_list|()
condition|)
name|cl
operator|->
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|member|m_instance
name|QWindowsClipboard
modifier|*
name|QWindowsClipboard
operator|::
name|m_instance
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QWindowsClipboard
name|QWindowsClipboard
operator|::
name|QWindowsClipboard
parameter_list|()
member_init_list|:
name|m_data
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_clipboardViewer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_nextClipboardViewer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_formatListenerRegistered
argument_list|(
literal|false
argument_list|)
block|{
name|QWindowsClipboard
operator|::
name|m_instance
operator|=
name|this
expr_stmt|;
name|qAddPostRoutine
argument_list|(
name|cleanClipboardPostRoutine
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsClipboard
name|QWindowsClipboard
operator|::
name|~
name|QWindowsClipboard
parameter_list|()
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|QWindowsClipboard
operator|::
name|m_instance
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|cleanup
name|void
name|QWindowsClipboard
operator|::
name|cleanup
parameter_list|()
block|{
name|unregisterViewer
argument_list|()
expr_stmt|;
comment|// Should release data if owner.
name|releaseIData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|releaseIData
name|void
name|QWindowsClipboard
operator|::
name|releaseIData
parameter_list|()
block|{
if|if
condition|(
name|m_data
condition|)
block|{
operator|delete
name|m_data
operator|->
name|mimeData
argument_list|()
expr_stmt|;
name|m_data
operator|->
name|releaseQt
argument_list|()
expr_stmt|;
name|m_data
operator|->
name|Release
argument_list|()
expr_stmt|;
name|m_data
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|registerViewer
name|void
name|QWindowsClipboard
operator|::
name|registerViewer
parameter_list|()
block|{
name|m_clipboardViewer
operator|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|createDummyWindow
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Qt5ClipboardView"
argument_list|)
argument_list|,
literal|L"Qt5ClipboardView"
argument_list|,
name|qClipboardViewerWndProc
argument_list|,
name|WS_OVERLAPPED
argument_list|)
expr_stmt|;
comment|// Try format listener API (Vista onwards) first.
if|if
condition|(
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|addClipboardFormatListener
operator|&&
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|removeClipboardFormatListener
condition|)
block|{
name|m_formatListenerRegistered
operator|=
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|addClipboardFormatListener
argument_list|(
name|m_clipboardViewer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_formatListenerRegistered
condition|)
name|qErrnoWarning
argument_list|(
literal|"AddClipboardFormatListener() failed."
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_formatListenerRegistered
condition|)
name|m_nextClipboardViewer
operator|=
name|SetClipboardViewer
argument_list|(
name|m_clipboardViewer
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaMime
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
literal|"m_clipboardViewer:"
operator|<<
name|m_clipboardViewer
operator|<<
literal|"format listener:"
operator|<<
name|m_formatListenerRegistered
operator|<<
literal|"next:"
operator|<<
name|m_nextClipboardViewer
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterViewer
name|void
name|QWindowsClipboard
operator|::
name|unregisterViewer
parameter_list|()
block|{
if|if
condition|(
name|m_clipboardViewer
condition|)
block|{
if|if
condition|(
name|m_formatListenerRegistered
condition|)
block|{
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|removeClipboardFormatListener
argument_list|(
name|m_clipboardViewer
argument_list|)
expr_stmt|;
name|m_formatListenerRegistered
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|ChangeClipboardChain
argument_list|(
name|m_clipboardViewer
argument_list|,
name|m_nextClipboardViewer
argument_list|)
expr_stmt|;
name|m_nextClipboardViewer
operator|=
literal|0
expr_stmt|;
block|}
name|DestroyWindow
argument_list|(
name|m_clipboardViewer
argument_list|)
expr_stmt|;
name|m_clipboardViewer
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// ### FIXME: Qt 6: Remove the clipboard chain handling code and make the
end_comment
begin_comment
comment|// format listener the default.
end_comment
begin_function
DECL|function|isProcessBeingDebugged
specifier|static
name|bool
name|isProcessBeingDebugged
parameter_list|(
name|HWND
name|hwnd
parameter_list|)
block|{
name|DWORD
name|pid
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|GetWindowThreadProcessId
argument_list|(
name|hwnd
argument_list|,
operator|&
name|pid
argument_list|)
operator|||
operator|!
name|pid
condition|)
return|return
literal|false
return|;
specifier|const
name|HANDLE
name|processHandle
init|=
name|OpenProcess
argument_list|(
name|PROCESS_QUERY_INFORMATION
argument_list|,
name|FALSE
argument_list|,
name|pid
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|processHandle
condition|)
return|return
literal|false
return|;
name|BOOL
name|debugged
init|=
name|FALSE
decl_stmt|;
name|CheckRemoteDebuggerPresent
argument_list|(
name|processHandle
argument_list|,
operator|&
name|debugged
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|processHandle
argument_list|)
expr_stmt|;
return|return
name|debugged
operator|!=
name|FALSE
return|;
block|}
end_function
begin_function
DECL|function|propagateClipboardMessage
name|void
name|QWindowsClipboard
operator|::
name|propagateClipboardMessage
parameter_list|(
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_nextClipboardViewer
condition|)
return|return;
comment|// In rare cases, a clipboard viewer can hang (application crashed,
comment|// suspended by a shell prompt 'Select' or debugger).
if|if
condition|(
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|isHungAppWindow
operator|&&
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|isHungAppWindow
argument_list|(
name|m_nextClipboardViewer
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Cowardly refusing to send clipboard message to hung application..."
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Do not block if the process is being debugged, specifically, if it is
comment|// displaying a runtime assert, which is not caught by isHungAppWindow().
if|if
condition|(
name|isProcessBeingDebugged
argument_list|(
name|m_nextClipboardViewer
argument_list|)
condition|)
name|PostMessage
argument_list|(
name|m_nextClipboardViewer
argument_list|,
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
expr_stmt|;
else|else
name|SendMessage
argument_list|(
name|m_nextClipboardViewer
argument_list|,
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \brief Windows procedure of the clipboard viewer. Emits changed and does     housekeeping of the viewer chain. */
end_comment
begin_function
DECL|function|clipboardViewerWndProc
name|bool
name|QWindowsClipboard
operator|::
name|clipboardViewerWndProc
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|UINT
name|message
parameter_list|,
name|WPARAM
name|wParam
parameter_list|,
name|LPARAM
name|lParam
parameter_list|,
name|LRESULT
modifier|*
name|result
parameter_list|)
block|{
enum|enum
block|{
name|wMClipboardUpdate
init|=
literal|0x031D
block|}
enum|;
operator|*
name|result
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verbose
condition|)
name|qCDebug
argument_list|(
name|lcQpaMime
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|hwnd
operator|<<
name|message
operator|<<
name|QWindowsGuiEventDispatcher
operator|::
name|windowsMessageName
argument_list|(
name|message
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|message
condition|)
block|{
case|case
name|WM_CHANGECBCHAIN
case|:
block|{
specifier|const
name|HWND
name|toBeRemoved
init|=
cast|reinterpret_cast
argument_list|<
name|HWND
argument_list|>
argument_list|(
name|wParam
argument_list|)
decl_stmt|;
if|if
condition|(
name|toBeRemoved
operator|==
name|m_nextClipboardViewer
condition|)
block|{
name|m_nextClipboardViewer
operator|=
cast|reinterpret_cast
argument_list|<
name|HWND
argument_list|>
argument_list|(
name|lParam
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|propagateClipboardMessage
argument_list|(
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
case|case
name|wMClipboardUpdate
case|:
comment|// Clipboard Format listener (Vista onwards)
case|case
name|WM_DRAWCLIPBOARD
case|:
block|{
comment|// Clipboard Viewer Chain handling (up to XP)
specifier|const
name|bool
name|owned
init|=
name|ownsClipboard
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|lcQpaMime
argument_list|)
operator|<<
literal|"Clipboard changed owned "
operator|<<
name|owned
expr_stmt|;
name|emitChanged
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
comment|// clean up the clipboard object if we no longer own the clipboard
if|if
condition|(
operator|!
name|owned
operator|&&
name|m_data
condition|)
name|releaseIData
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_formatListenerRegistered
condition|)
name|propagateClipboardMessage
argument_list|(
name|message
argument_list|,
name|wParam
argument_list|,
name|lParam
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
case|case
name|WM_DESTROY
case|:
comment|// Recommended shutdown
if|if
condition|(
name|ownsClipboard
argument_list|()
condition|)
block|{
name|qCDebug
argument_list|(
name|lcQpaMime
argument_list|)
operator|<<
literal|"Clipboard owner on shutdown, releasing."
expr_stmt|;
name|OleFlushClipboard
argument_list|()
expr_stmt|;
name|releaseIData
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
comment|// switch (message)
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QWindowsClipboard
operator|::
name|mimeData
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|lcQpaMime
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|mode
expr_stmt|;
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
name|ownsClipboard
argument_list|()
condition|)
return|return
name|m_data
operator|->
name|mimeData
argument_list|()
return|;
return|return
operator|&
name|m_retrievalData
return|;
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|QWindowsClipboard
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|mimeData
parameter_list|,
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|lcQpaMime
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|mode
operator|<<
name|mimeData
expr_stmt|;
if|if
condition|(
name|mode
operator|!=
name|QClipboard
operator|::
name|Clipboard
condition|)
return|return;
specifier|const
name|bool
name|newData
init|=
operator|!
name|m_data
operator|||
name|m_data
operator|->
name|mimeData
argument_list|()
operator|!=
name|mimeData
decl_stmt|;
if|if
condition|(
name|newData
condition|)
block|{
name|releaseIData
argument_list|()
expr_stmt|;
if|if
condition|(
name|mimeData
condition|)
name|m_data
operator|=
operator|new
name|QWindowsOleDataObject
argument_list|(
name|mimeData
argument_list|)
expr_stmt|;
block|}
specifier|const
name|HRESULT
name|src
init|=
name|OleSetClipboard
argument_list|(
name|m_data
argument_list|)
decl_stmt|;
if|if
condition|(
name|src
operator|!=
name|S_OK
condition|)
block|{
name|QString
name|mimeDataFormats
init|=
name|mimeData
condition|?
name|mimeData
operator|->
name|formats
argument_list|()
operator|.
name|join
argument_list|(
name|QStringLiteral
argument_list|(
literal|", "
argument_list|)
argument_list|)
else|:
name|QString
argument_list|(
name|QStringLiteral
argument_list|(
literal|"NULL"
argument_list|)
argument_list|)
decl_stmt|;
name|qErrnoWarning
argument_list|(
literal|"OleSetClipboard: Failed to set mime data (%s) on clipboard: %s"
argument_list|,
name|qPrintable
argument_list|(
name|mimeDataFormats
argument_list|)
argument_list|,
name|QWindowsContext
operator|::
name|comErrorString
argument_list|(
name|src
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|releaseIData
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
end_function
begin_function
DECL|function|clear
name|void
name|QWindowsClipboard
operator|::
name|clear
parameter_list|()
block|{
specifier|const
name|HRESULT
name|src
init|=
name|OleSetClipboard
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|src
operator|!=
name|S_OK
condition|)
name|qErrnoWarning
argument_list|(
literal|"OleSetClipboard: Failed to clear the clipboard: 0x%lx"
argument_list|,
name|src
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsMode
name|bool
name|QWindowsClipboard
operator|::
name|supportsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
return|return
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
return|;
block|}
end_function
begin_comment
comment|// Need a non-virtual in destructor.
end_comment
begin_function
DECL|function|ownsClipboard
name|bool
name|QWindowsClipboard
operator|::
name|ownsClipboard
parameter_list|()
specifier|const
block|{
return|return
name|m_data
operator|&&
name|OleIsCurrentClipboard
argument_list|(
name|m_data
argument_list|)
operator|==
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|ownsMode
name|bool
name|QWindowsClipboard
operator|::
name|ownsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
specifier|const
name|bool
name|result
init|=
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
condition|?
name|ownsClipboard
argument_list|()
else|:
literal|false
decl_stmt|;
name|qCDebug
argument_list|(
name|lcQpaMime
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|mode
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
