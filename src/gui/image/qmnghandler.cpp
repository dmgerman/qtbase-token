begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmnghandler_p.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_include
include|#
directive|include
file|"qcolor.h"
end_include
begin_define
DECL|macro|MNG_USE_SO
define|#
directive|define
name|MNG_USE_SO
end_define
begin_include
include|#
directive|include
file|<libmng.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QMngHandlerPrivate
class|class
name|QMngHandlerPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QMngHandler
parameter_list|)
specifier|public
private|:
DECL|member|haveReadNone
name|bool
name|haveReadNone
decl_stmt|;
DECL|member|haveReadAll
name|bool
name|haveReadAll
decl_stmt|;
DECL|member|hMNG
name|mng_handle
name|hMNG
decl_stmt|;
DECL|member|image
name|QImage
name|image
decl_stmt|;
DECL|member|elapsed
name|int
name|elapsed
decl_stmt|;
DECL|member|nextDelay
name|int
name|nextDelay
decl_stmt|;
DECL|member|iterCount
name|int
name|iterCount
decl_stmt|;
DECL|member|frameIndex
name|int
name|frameIndex
decl_stmt|;
DECL|member|nextIndex
name|int
name|nextIndex
decl_stmt|;
DECL|member|frameCount
name|int
name|frameCount
decl_stmt|;
DECL|member|iStyle
name|mng_uint32
name|iStyle
decl_stmt|;
name|mng_bool
name|readData
parameter_list|(
name|mng_ptr
name|pBuf
parameter_list|,
name|mng_uint32
name|iSize
parameter_list|,
name|mng_uint32p
name|pRead
parameter_list|)
function_decl|;
name|mng_bool
name|writeData
parameter_list|(
name|mng_ptr
name|pBuf
parameter_list|,
name|mng_uint32
name|iSize
parameter_list|,
name|mng_uint32p
name|pWritten
parameter_list|)
function_decl|;
name|mng_bool
name|processHeader
parameter_list|(
name|mng_uint32
name|iWidth
parameter_list|,
name|mng_uint32
name|iHeight
parameter_list|)
function_decl|;
name|QMngHandlerPrivate
parameter_list|(
name|QMngHandler
modifier|*
name|q_ptr
parameter_list|)
constructor_decl|;
name|~
name|QMngHandlerPrivate
parameter_list|()
destructor_decl|;
name|bool
name|getNextImage
parameter_list|(
name|QImage
modifier|*
name|result
parameter_list|)
function_decl|;
name|bool
name|writeImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
name|int
name|currentImageNumber
parameter_list|()
specifier|const
function_decl|;
name|int
name|imageCount
parameter_list|()
specifier|const
function_decl|;
name|bool
name|jumpToImage
parameter_list|(
name|int
name|imageNumber
parameter_list|)
function_decl|;
name|bool
name|jumpToNextImage
parameter_list|()
function_decl|;
name|int
name|nextImageDelay
parameter_list|()
specifier|const
function_decl|;
name|bool
name|setBackgroundColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
name|QColor
name|backgroundColor
parameter_list|()
specifier|const
function_decl|;
DECL|member|q_ptr
name|QMngHandler
modifier|*
name|q_ptr
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|myerror
specifier|static
name|mng_bool
name|myerror
parameter_list|(
name|mng_handle
comment|/*hMNG*/
parameter_list|,
name|mng_int32
name|iErrorcode
parameter_list|,
name|mng_int8
comment|/*iSeverity*/
parameter_list|,
name|mng_chunkid
name|iChunkname
parameter_list|,
name|mng_uint32
comment|/*iChunkseq*/
parameter_list|,
name|mng_int32
name|iExtra1
parameter_list|,
name|mng_int32
name|iExtra2
parameter_list|,
name|mng_pchar
name|zErrortext
parameter_list|)
block|{
name|qWarning
argument_list|(
literal|"MNG error %d: %s; chunk %c%c%c%c; subcode %d:%d"
argument_list|,
name|iErrorcode
argument_list|,
name|zErrortext
argument_list|,
operator|(
name|iChunkname
operator|>>
literal|24
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
name|iChunkname
operator|>>
literal|16
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
name|iChunkname
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
name|iChunkname
operator|>>
literal|0
operator|)
operator|&
literal|0xff
argument_list|,
name|iExtra1
argument_list|,
name|iExtra2
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function
begin_function
DECL|function|myalloc
specifier|static
name|mng_ptr
name|myalloc
parameter_list|(
name|mng_size_t
name|iSize
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|mng_ptr
name|ptr
init|=
name|malloc
argument_list|(
name|iSize
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|ptr
argument_list|,
literal|0
argument_list|,
name|iSize
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
else|#
directive|else
return|return
operator|(
name|mng_ptr
operator|)
name|calloc
argument_list|(
literal|1
argument_list|,
name|iSize
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|myfree
specifier|static
name|void
name|myfree
parameter_list|(
name|mng_ptr
name|pPtr
parameter_list|,
name|mng_size_t
comment|/*iSize*/
parameter_list|)
block|{
name|free
argument_list|(
name|pPtr
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|myopenstream
specifier|static
name|mng_bool
name|myopenstream
parameter_list|(
name|mng_handle
parameter_list|)
block|{
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_function
DECL|function|myclosestream
specifier|static
name|mng_bool
name|myclosestream
parameter_list|(
name|mng_handle
name|hMNG
parameter_list|)
block|{
name|QMngHandlerPrivate
modifier|*
name|pMydata
init|=
cast|reinterpret_cast
argument_list|<
name|QMngHandlerPrivate
operator|*
argument_list|>
argument_list|(
name|mng_get_userdata
argument_list|(
name|hMNG
argument_list|)
argument_list|)
decl_stmt|;
name|pMydata
operator|->
name|haveReadAll
operator|=
literal|true
expr_stmt|;
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_function
DECL|function|myreaddata
specifier|static
name|mng_bool
name|myreaddata
parameter_list|(
name|mng_handle
name|hMNG
parameter_list|,
name|mng_ptr
name|pBuf
parameter_list|,
name|mng_uint32
name|iSize
parameter_list|,
name|mng_uint32p
name|pRead
parameter_list|)
block|{
name|QMngHandlerPrivate
modifier|*
name|pMydata
init|=
cast|reinterpret_cast
argument_list|<
name|QMngHandlerPrivate
operator|*
argument_list|>
argument_list|(
name|mng_get_userdata
argument_list|(
name|hMNG
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|pMydata
operator|->
name|readData
argument_list|(
name|pBuf
argument_list|,
name|iSize
argument_list|,
name|pRead
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mywritedata
specifier|static
name|mng_bool
name|mywritedata
parameter_list|(
name|mng_handle
name|hMNG
parameter_list|,
name|mng_ptr
name|pBuf
parameter_list|,
name|mng_uint32
name|iSize
parameter_list|,
name|mng_uint32p
name|pWritten
parameter_list|)
block|{
name|QMngHandlerPrivate
modifier|*
name|pMydata
init|=
cast|reinterpret_cast
argument_list|<
name|QMngHandlerPrivate
operator|*
argument_list|>
argument_list|(
name|mng_get_userdata
argument_list|(
name|hMNG
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|pMydata
operator|->
name|writeData
argument_list|(
name|pBuf
argument_list|,
name|iSize
argument_list|,
name|pWritten
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|myprocessheader
specifier|static
name|mng_bool
name|myprocessheader
parameter_list|(
name|mng_handle
name|hMNG
parameter_list|,
name|mng_uint32
name|iWidth
parameter_list|,
name|mng_uint32
name|iHeight
parameter_list|)
block|{
name|QMngHandlerPrivate
modifier|*
name|pMydata
init|=
cast|reinterpret_cast
argument_list|<
name|QMngHandlerPrivate
operator|*
argument_list|>
argument_list|(
name|mng_get_userdata
argument_list|(
name|hMNG
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|pMydata
operator|->
name|processHeader
argument_list|(
name|iWidth
argument_list|,
name|iHeight
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mygetcanvasline
specifier|static
name|mng_ptr
name|mygetcanvasline
parameter_list|(
name|mng_handle
name|hMNG
parameter_list|,
name|mng_uint32
name|iLinenr
parameter_list|)
block|{
name|QMngHandlerPrivate
modifier|*
name|pMydata
init|=
cast|reinterpret_cast
argument_list|<
name|QMngHandlerPrivate
operator|*
argument_list|>
argument_list|(
name|mng_get_userdata
argument_list|(
name|hMNG
argument_list|)
argument_list|)
decl_stmt|;
return|return
operator|(
name|mng_ptr
operator|)
name|pMydata
operator|->
name|image
operator|.
name|scanLine
argument_list|(
name|iLinenr
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|myrefresh
specifier|static
name|mng_bool
name|myrefresh
parameter_list|(
name|mng_handle
comment|/*hMNG*/
parameter_list|,
name|mng_uint32
comment|/*iX*/
parameter_list|,
name|mng_uint32
comment|/*iY*/
parameter_list|,
name|mng_uint32
comment|/*iWidth*/
parameter_list|,
name|mng_uint32
comment|/*iHeight*/
parameter_list|)
block|{
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_function
DECL|function|mygettickcount
specifier|static
name|mng_uint32
name|mygettickcount
parameter_list|(
name|mng_handle
name|hMNG
parameter_list|)
block|{
name|QMngHandlerPrivate
modifier|*
name|pMydata
init|=
cast|reinterpret_cast
argument_list|<
name|QMngHandlerPrivate
operator|*
argument_list|>
argument_list|(
name|mng_get_userdata
argument_list|(
name|hMNG
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|pMydata
operator|->
name|elapsed
operator|++
return|;
block|}
end_function
begin_function
DECL|function|mysettimer
specifier|static
name|mng_bool
name|mysettimer
parameter_list|(
name|mng_handle
name|hMNG
parameter_list|,
name|mng_uint32
name|iMsecs
parameter_list|)
block|{
name|QMngHandlerPrivate
modifier|*
name|pMydata
init|=
cast|reinterpret_cast
argument_list|<
name|QMngHandlerPrivate
operator|*
argument_list|>
argument_list|(
name|mng_get_userdata
argument_list|(
name|hMNG
argument_list|)
argument_list|)
decl_stmt|;
name|pMydata
operator|->
name|elapsed
operator|+=
name|iMsecs
expr_stmt|;
name|pMydata
operator|->
name|nextDelay
operator|=
name|iMsecs
expr_stmt|;
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_function
DECL|function|myprocessterm
specifier|static
name|mng_bool
name|myprocessterm
parameter_list|(
name|mng_handle
name|hMNG
parameter_list|,
name|mng_uint8
name|iTermaction
parameter_list|,
name|mng_uint8
comment|/*iIteraction*/
parameter_list|,
name|mng_uint32
comment|/*iDelay*/
parameter_list|,
name|mng_uint32
name|iItermax
parameter_list|)
block|{
name|QMngHandlerPrivate
modifier|*
name|pMydata
init|=
cast|reinterpret_cast
argument_list|<
name|QMngHandlerPrivate
operator|*
argument_list|>
argument_list|(
name|mng_get_userdata
argument_list|(
name|hMNG
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|iTermaction
operator|==
literal|3
condition|)
name|pMydata
operator|->
name|iterCount
operator|=
name|iItermax
expr_stmt|;
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_function
DECL|function|mytrace
specifier|static
name|mng_bool
name|mytrace
parameter_list|(
name|mng_handle
parameter_list|,
name|mng_int32
name|iFuncnr
parameter_list|,
name|mng_int32
name|iFuncseq
parameter_list|,
name|mng_pchar
name|zFuncname
parameter_list|)
block|{
name|qDebug
argument_list|(
literal|"mng trace: iFuncnr: %d iFuncseq: %d zFuncname: %s"
argument_list|,
name|iFuncnr
argument_list|,
name|iFuncseq
argument_list|,
name|zFuncname
argument_list|)
expr_stmt|;
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_constructor
DECL|function|QMngHandlerPrivate
name|QMngHandlerPrivate
operator|::
name|QMngHandlerPrivate
parameter_list|(
name|QMngHandler
modifier|*
name|q_ptr
parameter_list|)
member_init_list|:
name|haveReadNone
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|haveReadAll
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|elapsed
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|nextDelay
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|iterCount
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|frameIndex
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|nextIndex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|frameCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|q_ptr
argument_list|(
name|q_ptr
argument_list|)
block|{
name|iStyle
operator|=
operator|(
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|LittleEndian
operator|)
condition|?
name|MNG_CANVAS_BGRA8
else|:
name|MNG_CANVAS_ARGB8
expr_stmt|;
comment|// Initialize libmng
name|hMNG
operator|=
name|mng_initialize
argument_list|(
operator|(
name|mng_ptr
operator|)
name|this
argument_list|,
name|myalloc
argument_list|,
name|myfree
argument_list|,
name|mytrace
argument_list|)
expr_stmt|;
if|if
condition|(
name|hMNG
condition|)
block|{
comment|// Set callback functions
name|mng_setcb_errorproc
argument_list|(
name|hMNG
argument_list|,
name|myerror
argument_list|)
expr_stmt|;
name|mng_setcb_openstream
argument_list|(
name|hMNG
argument_list|,
name|myopenstream
argument_list|)
expr_stmt|;
name|mng_setcb_closestream
argument_list|(
name|hMNG
argument_list|,
name|myclosestream
argument_list|)
expr_stmt|;
name|mng_setcb_readdata
argument_list|(
name|hMNG
argument_list|,
name|myreaddata
argument_list|)
expr_stmt|;
name|mng_setcb_writedata
argument_list|(
name|hMNG
argument_list|,
name|mywritedata
argument_list|)
expr_stmt|;
name|mng_setcb_processheader
argument_list|(
name|hMNG
argument_list|,
name|myprocessheader
argument_list|)
expr_stmt|;
name|mng_setcb_getcanvasline
argument_list|(
name|hMNG
argument_list|,
name|mygetcanvasline
argument_list|)
expr_stmt|;
name|mng_setcb_refresh
argument_list|(
name|hMNG
argument_list|,
name|myrefresh
argument_list|)
expr_stmt|;
name|mng_setcb_gettickcount
argument_list|(
name|hMNG
argument_list|,
name|mygettickcount
argument_list|)
expr_stmt|;
name|mng_setcb_settimer
argument_list|(
name|hMNG
argument_list|,
name|mysettimer
argument_list|)
expr_stmt|;
name|mng_setcb_processterm
argument_list|(
name|hMNG
argument_list|,
name|myprocessterm
argument_list|)
expr_stmt|;
name|mng_set_doprogressive
argument_list|(
name|hMNG
argument_list|,
name|MNG_FALSE
argument_list|)
expr_stmt|;
name|mng_set_suspensionmode
argument_list|(
name|hMNG
argument_list|,
name|MNG_TRUE
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QMngHandlerPrivate
name|QMngHandlerPrivate
operator|::
name|~
name|QMngHandlerPrivate
parameter_list|()
block|{
name|mng_cleanup
argument_list|(
operator|&
name|hMNG
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|readData
name|mng_bool
name|QMngHandlerPrivate
operator|::
name|readData
parameter_list|(
name|mng_ptr
name|pBuf
parameter_list|,
name|mng_uint32
name|iSize
parameter_list|,
name|mng_uint32p
name|pRead
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QMngHandler
argument_list|)
expr_stmt|;
operator|*
name|pRead
operator|=
name|q
operator|->
name|device
argument_list|()
operator|->
name|read
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pBuf
argument_list|,
name|iSize
argument_list|)
expr_stmt|;
return|return
operator|(
operator|*
name|pRead
operator|>
literal|0
operator|)
condition|?
name|MNG_TRUE
else|:
name|MNG_FALSE
return|;
block|}
end_function
begin_function
DECL|function|writeData
name|mng_bool
name|QMngHandlerPrivate
operator|::
name|writeData
parameter_list|(
name|mng_ptr
name|pBuf
parameter_list|,
name|mng_uint32
name|iSize
parameter_list|,
name|mng_uint32p
name|pWritten
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QMngHandler
argument_list|)
expr_stmt|;
operator|*
name|pWritten
operator|=
name|q
operator|->
name|device
argument_list|()
operator|->
name|write
argument_list|(
operator|(
name|char
operator|*
operator|)
name|pBuf
argument_list|,
name|iSize
argument_list|)
expr_stmt|;
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_function
DECL|function|processHeader
name|mng_bool
name|QMngHandlerPrivate
operator|::
name|processHeader
parameter_list|(
name|mng_uint32
name|iWidth
parameter_list|,
name|mng_uint32
name|iHeight
parameter_list|)
block|{
if|if
condition|(
name|mng_set_canvasstyle
argument_list|(
name|hMNG
argument_list|,
name|iStyle
argument_list|)
operator|!=
name|MNG_NOERROR
condition|)
return|return
name|MNG_FALSE
return|;
name|image
operator|=
name|QImage
argument_list|(
name|iWidth
argument_list|,
name|iHeight
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
name|image
operator|.
name|fill
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_function
DECL|function|getNextImage
name|bool
name|QMngHandlerPrivate
operator|::
name|getNextImage
parameter_list|(
name|QImage
modifier|*
name|result
parameter_list|)
block|{
name|mng_retcode
name|ret
decl_stmt|;
if|if
condition|(
name|haveReadNone
condition|)
block|{
name|haveReadNone
operator|=
literal|false
expr_stmt|;
name|ret
operator|=
name|mng_readdisplay
argument_list|(
name|hMNG
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ret
operator|=
name|mng_display_resume
argument_list|(
name|hMNG
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|MNG_NOERROR
operator|==
name|ret
operator|)
operator|||
operator|(
name|MNG_NEEDTIMERWAIT
operator|==
name|ret
operator|)
condition|)
block|{
operator|*
name|result
operator|=
name|image
expr_stmt|;
name|frameIndex
operator|=
name|nextIndex
operator|++
expr_stmt|;
if|if
condition|(
name|haveReadAll
operator|&&
operator|(
name|frameCount
operator|==
literal|0
operator|)
condition|)
name|frameCount
operator|=
name|nextIndex
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|writeImage
name|bool
name|QMngHandlerPrivate
operator|::
name|writeImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|mng_reset
argument_list|(
name|hMNG
argument_list|)
expr_stmt|;
if|if
condition|(
name|mng_create
argument_list|(
name|hMNG
argument_list|)
operator|!=
name|MNG_NOERROR
condition|)
return|return
literal|false
return|;
name|this
operator|->
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
name|int
name|w
init|=
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|image
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
comment|// width, height, ticks, layercount, framecount, playtime, simplicity
operator|(
name|mng_putchunk_mhdr
argument_list|(
name|hMNG
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
literal|1000
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|7
argument_list|)
operator|==
name|MNG_NOERROR
operator|)
operator|&&
comment|// termination_action, action_after_iterations, delay, iteration_max
operator|(
name|mng_putchunk_term
argument_list|(
name|hMNG
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0x7FFFFFFF
argument_list|)
operator|==
name|MNG_NOERROR
operator|)
operator|&&
comment|// width, height, bitdepth, colortype, compression, filter, interlace
operator|(
name|mng_putchunk_ihdr
argument_list|(
name|hMNG
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
literal|8
argument_list|,
literal|6
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|==
name|MNG_NOERROR
operator|)
operator|&&
comment|// width, height, colortype, bitdepth, compression, filter, interlace, canvasstyle, getcanvasline
operator|(
name|mng_putimgdata_ihdr
argument_list|(
name|hMNG
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
literal|6
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|iStyle
argument_list|,
name|mygetcanvasline
argument_list|)
operator|==
name|MNG_NOERROR
operator|)
operator|&&
operator|(
name|mng_putchunk_iend
argument_list|(
name|hMNG
argument_list|)
operator|==
name|MNG_NOERROR
operator|)
operator|&&
operator|(
name|mng_putchunk_mend
argument_list|(
name|hMNG
argument_list|)
operator|==
name|MNG_NOERROR
operator|)
operator|&&
operator|(
name|mng_write
argument_list|(
name|hMNG
argument_list|)
operator|==
name|MNG_NOERROR
operator|)
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|currentImageNumber
name|int
name|QMngHandlerPrivate
operator|::
name|currentImageNumber
parameter_list|()
specifier|const
block|{
comment|//    return mng_get_currentframe(hMNG) % imageCount(); not implemented, apparently
return|return
name|frameIndex
return|;
block|}
end_function
begin_function
DECL|function|imageCount
name|int
name|QMngHandlerPrivate
operator|::
name|imageCount
parameter_list|()
specifier|const
block|{
comment|//    return mng_get_totalframes(hMNG); not implemented, apparently
if|if
condition|(
name|haveReadAll
condition|)
return|return
name|frameCount
return|;
return|return
literal|0
return|;
comment|// Don't know
block|}
end_function
begin_function
DECL|function|jumpToImage
name|bool
name|QMngHandlerPrivate
operator|::
name|jumpToImage
parameter_list|(
name|int
name|imageNumber
parameter_list|)
block|{
if|if
condition|(
name|imageNumber
operator|==
name|nextIndex
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|(
name|imageNumber
operator|==
literal|0
operator|)
operator|&&
name|haveReadAll
operator|&&
operator|(
name|nextIndex
operator|==
name|frameCount
operator|)
condition|)
block|{
comment|// Loop!
name|nextIndex
operator|=
literal|0
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|mng_display_freeze
argument_list|(
name|hMNG
argument_list|)
operator|==
name|MNG_NOERROR
condition|)
block|{
if|if
condition|(
name|mng_display_goframe
argument_list|(
name|hMNG
argument_list|,
name|imageNumber
argument_list|)
operator|==
name|MNG_NOERROR
condition|)
block|{
name|nextIndex
operator|=
name|imageNumber
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|jumpToNextImage
name|bool
name|QMngHandlerPrivate
operator|::
name|jumpToNextImage
parameter_list|()
block|{
return|return
name|jumpToImage
argument_list|(
operator|(
name|currentImageNumber
argument_list|()
operator|+
literal|1
operator|)
operator|%
name|imageCount
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nextImageDelay
name|int
name|QMngHandlerPrivate
operator|::
name|nextImageDelay
parameter_list|()
specifier|const
block|{
return|return
name|nextDelay
return|;
block|}
end_function
begin_function
DECL|function|setBackgroundColor
name|bool
name|QMngHandlerPrivate
operator|::
name|setBackgroundColor
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|mng_uint16
name|iRed
init|=
call|(
name|mng_uint16
call|)
argument_list|(
name|color
operator|.
name|red
argument_list|()
operator|<<
literal|8
argument_list|)
decl_stmt|;
name|mng_uint16
name|iBlue
init|=
call|(
name|mng_uint16
call|)
argument_list|(
name|color
operator|.
name|blue
argument_list|()
operator|<<
literal|8
argument_list|)
decl_stmt|;
name|mng_uint16
name|iGreen
init|=
call|(
name|mng_uint16
call|)
argument_list|(
name|color
operator|.
name|green
argument_list|()
operator|<<
literal|8
argument_list|)
decl_stmt|;
return|return
operator|(
name|mng_set_bgcolor
argument_list|(
name|hMNG
argument_list|,
name|iRed
argument_list|,
name|iBlue
argument_list|,
name|iGreen
argument_list|)
operator|==
name|MNG_NOERROR
operator|)
return|;
block|}
end_function
begin_function
DECL|function|backgroundColor
name|QColor
name|QMngHandlerPrivate
operator|::
name|backgroundColor
parameter_list|()
specifier|const
block|{
name|mng_uint16
name|iRed
decl_stmt|;
name|mng_uint16
name|iBlue
decl_stmt|;
name|mng_uint16
name|iGreen
decl_stmt|;
if|if
condition|(
name|mng_get_bgcolor
argument_list|(
name|hMNG
argument_list|,
operator|&
name|iRed
argument_list|,
operator|&
name|iBlue
argument_list|,
operator|&
name|iGreen
argument_list|)
operator|==
name|MNG_NOERROR
condition|)
return|return
name|QColor
argument_list|(
operator|(
name|iRed
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
argument_list|,
operator|(
name|iGreen
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
argument_list|,
operator|(
name|iBlue
operator|>>
literal|8
operator|)
operator|&
literal|0xFF
argument_list|)
return|;
return|return
name|QColor
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QMngHandler
name|QMngHandler
operator|::
name|QMngHandler
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QMngHandlerPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QMngHandler
name|QMngHandler
operator|::
name|~
name|QMngHandler
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|canRead
name|bool
name|QMngHandler
operator|::
name|canRead
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMngHandler
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|!
name|d
operator|->
name|haveReadNone
operator|&&
operator|(
operator|!
name|d
operator|->
name|haveReadAll
operator|||
operator|(
name|d
operator|->
name|haveReadAll
operator|&&
operator|(
name|d
operator|->
name|nextIndex
operator|<
name|d
operator|->
name|frameCount
operator|)
operator|)
operator|)
operator|)
operator|||
name|canRead
argument_list|(
name|device
argument_list|()
argument_list|)
condition|)
block|{
name|setFormat
argument_list|(
literal|"mng"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|canRead
name|bool
name|QMngHandler
operator|::
name|canRead
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
if|if
condition|(
operator|!
name|device
condition|)
block|{
name|qWarning
argument_list|(
literal|"QMngHandler::canRead() called with no device"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
name|device
operator|->
name|peek
argument_list|(
literal|8
argument_list|)
operator|==
literal|"\x8A\x4D\x4E\x47\x0D\x0A\x1A\x0A"
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|name
name|QByteArray
name|QMngHandler
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
literal|"mng"
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|read
name|bool
name|QMngHandler
operator|::
name|read
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMngHandler
argument_list|)
expr_stmt|;
return|return
name|canRead
argument_list|()
condition|?
name|d
operator|->
name|getNextImage
argument_list|(
name|image
argument_list|)
else|:
literal|false
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|write
name|bool
name|QMngHandler
operator|::
name|write
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMngHandler
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|writeImage
argument_list|(
name|image
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|currentImageNumber
name|int
name|QMngHandler
operator|::
name|currentImageNumber
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMngHandler
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|currentImageNumber
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|imageCount
name|int
name|QMngHandler
operator|::
name|imageCount
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMngHandler
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|imageCount
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|jumpToImage
name|bool
name|QMngHandler
operator|::
name|jumpToImage
parameter_list|(
name|int
name|imageNumber
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QMngHandler
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|jumpToImage
argument_list|(
name|imageNumber
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|jumpToNextImage
name|bool
name|QMngHandler
operator|::
name|jumpToNextImage
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QMngHandler
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|jumpToNextImage
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|loopCount
name|int
name|QMngHandler
operator|::
name|loopCount
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMngHandler
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|iterCount
operator|==
literal|0x7FFFFFFF
condition|)
return|return
operator|-
literal|1
return|;
comment|// infinite loop
return|return
name|d
operator|->
name|iterCount
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|nextImageDelay
name|int
name|QMngHandler
operator|::
name|nextImageDelay
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMngHandler
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|nextImageDelay
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|option
name|QVariant
name|QMngHandler
operator|::
name|option
parameter_list|(
name|ImageOption
name|option
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QMngHandler
argument_list|)
expr_stmt|;
if|if
condition|(
name|option
operator|==
name|QImageIOHandler
operator|::
name|Animation
condition|)
return|return
literal|true
return|;
elseif|else
if|if
condition|(
name|option
operator|==
name|QImageIOHandler
operator|::
name|BackgroundColor
condition|)
return|return
name|d
operator|->
name|backgroundColor
argument_list|()
return|;
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|setOption
name|void
name|QMngHandler
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
name|Q_D
argument_list|(
name|QMngHandler
argument_list|)
expr_stmt|;
if|if
condition|(
name|option
operator|==
name|QImageIOHandler
operator|::
name|BackgroundColor
condition|)
name|d
operator|->
name|setBackgroundColor
argument_list|(
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|supportsOption
name|bool
name|QMngHandler
operator|::
name|supportsOption
parameter_list|(
name|ImageOption
name|option
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|option
operator|==
name|QImageIOHandler
operator|::
name|Animation
condition|)
return|return
literal|true
return|;
elseif|else
if|if
condition|(
name|option
operator|==
name|QImageIOHandler
operator|::
name|BackgroundColor
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
