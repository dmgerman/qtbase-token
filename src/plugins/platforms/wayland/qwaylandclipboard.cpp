begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qwaylanddisplay.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandinputdevice.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformNativeInterface>
end_include
begin_include
include|#
directive|include
file|<QtGui/QApplication>
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
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QtDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qdnd_p.h>
end_include
begin_decl_stmt
DECL|variable|clipboard
specifier|static
name|QWaylandClipboard
modifier|*
name|clipboard
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|QWaylandMimeData
class|class
name|QWaylandMimeData
super|:
specifier|public
name|QInternalMimeData
block|{
public|public:
name|void
name|clearAll
parameter_list|()
function_decl|;
name|void
name|setFormats
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|formatList
parameter_list|)
function_decl|;
name|bool
name|hasFormat_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|)
specifier|const
function_decl|;
name|QStringList
name|formats_sys
parameter_list|()
specifier|const
function_decl|;
name|QVariant
name|retrieveData_sys
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
function_decl|;
private|private:
DECL|member|mFormatList
name|QStringList
name|mFormatList
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|clearAll
name|void
name|QWaylandMimeData
operator|::
name|clearAll
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
name|mFormatList
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFormats
name|void
name|QWaylandMimeData
operator|::
name|setFormats
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|formatList
parameter_list|)
block|{
name|mFormatList
operator|=
name|formatList
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasFormat_sys
name|bool
name|QWaylandMimeData
operator|::
name|hasFormat_sys
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
begin_function
DECL|function|formats_sys
name|QStringList
name|QWaylandMimeData
operator|::
name|formats_sys
parameter_list|()
specifier|const
block|{
return|return
name|mFormatList
return|;
block|}
end_function
begin_function
DECL|function|retrieveData_sys
name|QVariant
name|QWaylandMimeData
operator|::
name|retrieveData_sys
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
return|return
name|clipboard
operator|->
name|retrieveData
argument_list|(
name|mimeType
argument_list|,
name|type
argument_list|)
return|;
block|}
end_function
begin_class
DECL|class|QWaylandSelection
class|class
name|QWaylandSelection
block|{
public|public:
name|QWaylandSelection
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|,
name|QMimeData
modifier|*
name|data
parameter_list|)
constructor_decl|;
name|~
name|QWaylandSelection
parameter_list|()
destructor_decl|;
specifier|static
name|uint32_t
name|getTime
parameter_list|()
function_decl|;
specifier|static
name|void
name|send
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_selection
modifier|*
name|selection
parameter_list|,
specifier|const
name|char
modifier|*
name|mime_type
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
specifier|static
name|void
name|cancelled
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_selection
modifier|*
name|selection
parameter_list|)
function_decl|;
DECL|member|selectionListener
specifier|static
specifier|const
name|struct
name|wl_selection_listener
name|selectionListener
decl_stmt|;
DECL|member|mMimeData
name|QMimeData
modifier|*
name|mMimeData
decl_stmt|;
DECL|member|mSelection
name|struct
name|wl_selection
modifier|*
name|mSelection
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|selectionListener
specifier|const
name|struct
name|wl_selection_listener
name|QWaylandSelection
operator|::
name|selectionListener
init|=
block|{
name|QWaylandSelection
operator|::
name|send
block|,
name|QWaylandSelection
operator|::
name|cancelled
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|getTime
name|uint32_t
name|QWaylandSelection
operator|::
name|getTime
parameter_list|()
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|tv
operator|.
name|tv_sec
operator|*
literal|1000
operator|+
name|tv
operator|.
name|tv_usec
operator|/
literal|1000
return|;
block|}
end_function
begin_constructor
DECL|function|QWaylandSelection
name|QWaylandSelection
operator|::
name|QWaylandSelection
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|,
name|QMimeData
modifier|*
name|data
parameter_list|)
member_init_list|:
name|mMimeData
argument_list|(
name|data
argument_list|)
member_init_list|,
name|mSelection
argument_list|(
literal|0
argument_list|)
block|{
name|struct
name|wl_shell
modifier|*
name|shell
init|=
name|display
operator|->
name|wl_shell
argument_list|()
decl_stmt|;
name|mSelection
operator|=
name|wl_shell_create_selection
argument_list|(
name|shell
argument_list|)
expr_stmt|;
name|wl_selection_add_listener
argument_list|(
name|mSelection
argument_list|,
operator|&
name|selectionListener
argument_list|,
name|this
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|format
decl|,
name|data
operator|->
name|formats
argument_list|()
control|)
name|wl_selection_offer
argument_list|(
name|mSelection
argument_list|,
name|format
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|wl_selection_activate
argument_list|(
name|mSelection
argument_list|,
name|display
operator|->
name|inputDevices
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|->
name|wl_input_device
argument_list|()
argument_list|,
name|getTime
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandSelection
name|QWaylandSelection
operator|::
name|~
name|QWaylandSelection
parameter_list|()
block|{
if|if
condition|(
name|mSelection
condition|)
block|{
name|clipboard
operator|->
name|unregisterSelection
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|wl_selection_destroy
argument_list|(
name|mSelection
argument_list|)
expr_stmt|;
block|}
operator|delete
name|mMimeData
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|send
name|void
name|QWaylandSelection
operator|::
name|send
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_selection
modifier|*
name|selection
parameter_list|,
specifier|const
name|char
modifier|*
name|mime_type
parameter_list|,
name|int
name|fd
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|selection
argument_list|)
expr_stmt|;
name|QWaylandSelection
modifier|*
name|self
init|=
cast|static_cast
argument_list|<
name|QWaylandSelection
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|QString
name|mimeType
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|mime_type
argument_list|)
decl_stmt|;
name|QByteArray
name|content
init|=
name|self
operator|->
name|mMimeData
operator|->
name|data
argument_list|(
name|mimeType
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|content
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QFile
name|f
decl_stmt|;
if|if
condition|(
name|f
operator|.
name|open
argument_list|(
name|fd
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
name|f
operator|.
name|write
argument_list|(
name|content
argument_list|)
expr_stmt|;
block|}
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cancelled
name|void
name|QWaylandSelection
operator|::
name|cancelled
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_selection
modifier|*
name|selection
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|selection
argument_list|)
expr_stmt|;
operator|delete
cast|static_cast
argument_list|<
name|QWaylandSelection
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QWaylandClipboard
name|QWaylandClipboard
operator|::
name|QWaylandClipboard
parameter_list|(
name|QWaylandDisplay
modifier|*
name|display
parameter_list|)
member_init_list|:
name|mDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|mMimeDataIn
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mOffer
argument_list|(
literal|0
argument_list|)
block|{
name|clipboard
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandClipboard
name|QWaylandClipboard
operator|::
name|~
name|QWaylandClipboard
parameter_list|()
block|{
if|if
condition|(
name|mOffer
condition|)
name|wl_selection_offer_destroy
argument_list|(
name|mOffer
argument_list|)
expr_stmt|;
operator|delete
name|mMimeDataIn
expr_stmt|;
name|qDeleteAll
argument_list|(
name|mSelections
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|unregisterSelection
name|void
name|QWaylandClipboard
operator|::
name|unregisterSelection
parameter_list|(
name|QWaylandSelection
modifier|*
name|selection
parameter_list|)
block|{
name|mSelections
operator|.
name|removeOne
argument_list|(
name|selection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|syncCallback
name|void
name|QWaylandClipboard
operator|::
name|syncCallback
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
block|{
operator|*
cast|static_cast
argument_list|<
name|bool
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|forceRoundtrip
name|void
name|QWaylandClipboard
operator|::
name|forceRoundtrip
parameter_list|(
name|struct
name|wl_display
modifier|*
name|display
parameter_list|)
block|{
name|bool
name|done
init|=
literal|false
decl_stmt|;
name|wl_display_sync_callback
argument_list|(
name|display
argument_list|,
name|syncCallback
argument_list|,
operator|&
name|done
argument_list|)
expr_stmt|;
name|wl_display_iterate
argument_list|(
name|display
argument_list|,
name|WL_DISPLAY_WRITABLE
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|done
condition|)
name|wl_display_iterate
argument_list|(
name|display
argument_list|,
name|WL_DISPLAY_READABLE
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|retrieveData
name|QVariant
name|QWaylandClipboard
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
if|if
condition|(
name|mOfferedMimeTypes
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|mOffer
condition|)
return|return
name|QVariant
argument_list|()
return|;
name|int
name|pipefd
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|pipe
argument_list|(
name|pipefd
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QWaylandClipboard: pipe() failed"
argument_list|)
expr_stmt|;
return|return
name|QVariant
argument_list|()
return|;
block|}
name|QByteArray
name|mimeTypeBa
init|=
name|mimeType
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
name|wl_selection_offer_receive
argument_list|(
name|mOffer
argument_list|,
name|mimeTypeBa
operator|.
name|constData
argument_list|()
argument_list|,
name|pipefd
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|QByteArray
name|content
decl_stmt|;
name|forceRoundtrip
argument_list|(
name|mDisplay
operator|->
name|wl_display
argument_list|()
argument_list|)
expr_stmt|;
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
name|int
name|n
decl_stmt|;
name|close
argument_list|(
name|pipefd
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|n
operator|=
name|read
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
operator|&
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|)
operator|)
operator|>
literal|0
condition|)
name|content
operator|.
name|append
argument_list|(
name|buf
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
name|content
return|;
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QWaylandClipboard
operator|::
name|mimeData
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mSelections
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|mSelections
operator|.
name|last
argument_list|()
operator|->
name|mMimeData
return|;
if|if
condition|(
operator|!
name|mMimeDataIn
condition|)
name|mMimeDataIn
operator|=
operator|new
name|QWaylandMimeData
expr_stmt|;
name|mMimeDataIn
operator|->
name|clearAll
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|mOfferedMimeTypes
operator|.
name|isEmpty
argument_list|()
operator|&&
name|mOffer
condition|)
name|mMimeDataIn
operator|->
name|setFormats
argument_list|(
name|mOfferedMimeTypes
argument_list|)
expr_stmt|;
return|return
name|mMimeDataIn
return|;
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|QWaylandClipboard
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
name|Q_ASSERT
argument_list|(
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mDisplay
operator|->
name|inputDevices
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|data
condition|)
name|data
operator|=
operator|new
name|QMimeData
expr_stmt|;
name|mSelections
operator|.
name|append
argument_list|(
operator|new
name|QWaylandSelection
argument_list|(
name|mDisplay
argument_list|,
name|data
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QWaylandClipboard::setMimeData: No input devices"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|supportsMode
name|bool
name|QWaylandClipboard
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
begin_decl_stmt
DECL|member|selectionOfferListener
specifier|const
name|struct
name|wl_selection_offer_listener
name|QWaylandClipboard
operator|::
name|selectionOfferListener
init|=
block|{
name|QWaylandClipboard
operator|::
name|offer
block|,
name|QWaylandClipboard
operator|::
name|keyboardFocus
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|createSelectionOffer
name|void
name|QWaylandClipboard
operator|::
name|createSelectionOffer
parameter_list|(
name|uint32_t
name|id
parameter_list|)
block|{
name|mOfferedMimeTypes
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|mOffer
condition|)
name|wl_selection_offer_destroy
argument_list|(
name|mOffer
argument_list|)
expr_stmt|;
name|mOffer
operator|=
literal|0
expr_stmt|;
name|struct
name|wl_selection_offer
modifier|*
name|offer
init|=
name|wl_selection_offer_create
argument_list|(
name|mDisplay
operator|->
name|wl_display
argument_list|()
argument_list|,
name|id
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|wl_selection_offer_add_listener
argument_list|(
name|offer
argument_list|,
operator|&
name|selectionOfferListener
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|offer
name|void
name|QWaylandClipboard
operator|::
name|offer
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_selection_offer
modifier|*
name|selection_offer
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|selection_offer
argument_list|)
expr_stmt|;
name|clipboard
operator|->
name|mOfferedMimeTypes
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboardFocus
name|void
name|QWaylandClipboard
operator|::
name|keyboardFocus
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_selection_offer
modifier|*
name|selection_offer
parameter_list|,
name|wl_input_device
modifier|*
name|input_device
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|data
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|input_device
condition|)
block|{
name|wl_selection_offer_destroy
argument_list|(
name|selection_offer
argument_list|)
expr_stmt|;
name|clipboard
operator|->
name|mOffer
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|clipboard
operator|->
name|mOffer
operator|=
name|selection_offer
expr_stmt|;
if|if
condition|(
name|clipboard
operator|->
name|mSelections
operator|.
name|isEmpty
argument_list|()
condition|)
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
operator|&
name|clipboard
operator|->
name|mEmitter
argument_list|,
literal|"emitChanged"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|emitChanged
name|void
name|QWaylandClipboardSignalEmitter
operator|::
name|emitChanged
parameter_list|()
block|{
name|clipboard
operator|->
name|emitChanged
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
