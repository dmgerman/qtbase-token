begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdirectfbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbinput.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<directfb.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QDirectFbWindow
name|QDirectFbWindow
operator|::
name|QDirectFbWindow
parameter_list|(
name|QWindow
modifier|*
name|tlw
parameter_list|,
name|QDirectFbInput
modifier|*
name|inputhandler
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|tlw
argument_list|)
member_init_list|,
name|m_inputHandler
argument_list|(
name|inputhandler
argument_list|)
block|{
name|DFBDisplayLayerConfig
name|layerConfig
decl_stmt|;
name|IDirectFBDisplayLayer
modifier|*
name|layer
decl_stmt|;
name|layer
operator|=
name|toDfbScreen
argument_list|(
name|tlw
argument_list|)
operator|->
name|dfbLayer
argument_list|()
expr_stmt|;
name|toDfbScreen
argument_list|(
name|tlw
argument_list|)
operator|->
name|dfbLayer
argument_list|()
operator|->
name|GetConfiguration
argument_list|(
name|layer
argument_list|,
operator|&
name|layerConfig
argument_list|)
expr_stmt|;
name|DFBWindowDescription
name|description
decl_stmt|;
name|memset
argument_list|(
operator|&
name|description
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|DFBWindowDescription
argument_list|)
argument_list|)
expr_stmt|;
name|description
operator|.
name|flags
operator|=
name|DFBWindowDescriptionFlags
argument_list|(
name|DWDESC_WIDTH
operator||
name|DWDESC_HEIGHT
operator||
name|DWDESC_POSX
operator||
name|DWDESC_POSY
operator||
name|DWDESC_SURFACE_CAPS
if|#
directive|if
name|DIRECTFB_MINOR_VERSION
operator|>=
literal|1
operator||
name|DWDESC_OPTIONS
endif|#
directive|endif
operator||
name|DWDESC_CAPS
argument_list|)
expr_stmt|;
name|description
operator|.
name|width
operator|=
name|qMax
argument_list|(
literal|1
argument_list|,
name|tlw
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|description
operator|.
name|height
operator|=
name|qMax
argument_list|(
literal|1
argument_list|,
name|tlw
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|description
operator|.
name|posx
operator|=
name|tlw
operator|->
name|x
argument_list|()
expr_stmt|;
name|description
operator|.
name|posy
operator|=
name|tlw
operator|->
name|y
argument_list|()
expr_stmt|;
if|if
condition|(
name|layerConfig
operator|.
name|surface_caps
operator|&
name|DSCAPS_PREMULTIPLIED
condition|)
name|description
operator|.
name|surface_caps
operator|=
name|DSCAPS_PREMULTIPLIED
expr_stmt|;
name|description
operator|.
name|pixelformat
operator|=
name|layerConfig
operator|.
name|pixelformat
expr_stmt|;
if|#
directive|if
name|DIRECTFB_MINOR_VERSION
operator|>=
literal|1
name|description
operator|.
name|options
operator|=
name|DFBWindowOptions
argument_list|(
name|DWOP_ALPHACHANNEL
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|description
operator|.
name|caps
operator|=
name|DFBWindowCapabilities
argument_list|(
name|DWCAPS_DOUBLEBUFFER
operator||
name|DWCAPS_ALPHACHANNEL
argument_list|)
expr_stmt|;
name|DFBResult
name|result
init|=
name|layer
operator|->
name|CreateWindow
argument_list|(
name|layer
argument_list|,
operator|&
name|description
argument_list|,
name|m_dfbWindow
operator|.
name|outPtr
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
name|DFB_OK
condition|)
block|{
name|DirectFBError
argument_list|(
literal|"QDirectFbWindow: failed to create window"
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
name|m_dfbWindow
operator|->
name|SetOpacity
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
literal|0xff
argument_list|)
expr_stmt|;
name|m_inputHandler
operator|->
name|addWindow
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
name|tlw
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QDirectFbWindow
name|QDirectFbWindow
operator|::
name|~
name|QDirectFbWindow
parameter_list|()
block|{
name|m_inputHandler
operator|->
name|removeWindow
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|m_dfbWindow
operator|->
name|Destroy
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setGeometry
name|void
name|QDirectFbWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
comment|//    bool isMoveOnly = (rect.topLeft() != geometry().topLeft())&& (rect.size() == geometry().size());
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|m_dfbWindow
operator|->
name|SetBounds
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
comment|// ### TODO port, verify if this is needed
if|#
directive|if
literal|0
comment|//Hack. When moving since the WindowSurface of a window becomes invalid when moved
block|if (isMoveOnly) {
comment|//if resize then windowsurface is updated.
block|widget()->windowSurface()->resize(rect.size());             window()->update();         }
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|setOpacity
name|void
name|QDirectFbWindow
operator|::
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
block|{
specifier|const
name|quint8
name|windowOpacity
init|=
name|quint8
argument_list|(
name|level
operator|*
literal|0xff
argument_list|)
decl_stmt|;
name|m_dfbWindow
operator|->
name|SetOpacity
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
name|windowOpacity
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QDirectFbWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
if|if
condition|(
name|visible
condition|)
block|{
name|int
name|x
init|=
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
decl_stmt|;
name|int
name|y
init|=
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
decl_stmt|;
name|m_dfbWindow
operator|->
name|MoveTo
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QDirectFBPointer
argument_list|<
name|IDirectFBDisplayLayer
argument_list|>
name|displayLayer
decl_stmt|;
name|QDirectFbConvenience
operator|::
name|dfbInterface
argument_list|()
operator|->
name|GetDisplayLayer
argument_list|(
name|QDirectFbConvenience
operator|::
name|dfbInterface
argument_list|()
argument_list|,
name|DLID_PRIMARY
argument_list|,
name|displayLayer
operator|.
name|outPtr
argument_list|()
argument_list|)
expr_stmt|;
name|DFBDisplayLayerConfig
name|config
decl_stmt|;
name|displayLayer
operator|->
name|GetConfiguration
argument_list|(
name|displayLayer
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|config
argument_list|)
expr_stmt|;
name|m_dfbWindow
operator|->
name|MoveTo
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
name|config
operator|.
name|width
operator|+
literal|1
argument_list|,
name|config
operator|.
name|height
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
operator|&&
name|visible
condition|)
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|window
argument_list|()
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWindowFlags
name|Qt
operator|::
name|WindowFlags
name|QDirectFbWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
switch|switch
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowType_Mask
condition|)
block|{
case|case
name|Qt
operator|::
name|ToolTip
case|:
block|{
name|DFBWindowOptions
name|options
decl_stmt|;
name|m_dfbWindow
operator|->
name|GetOptions
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|options
argument_list|)
expr_stmt|;
name|options
operator|=
name|DFBWindowOptions
argument_list|(
name|options
operator||
name|DWOP_GHOST
argument_list|)
expr_stmt|;
name|m_dfbWindow
operator|->
name|SetOptions
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
name|options
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
name|m_dfbWindow
operator|->
name|SetStackingClass
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
name|flags
operator|&
name|Qt
operator|::
name|WindowStaysOnTopHint
condition|?
name|DWSC_UPPER
else|:
name|DWSC_MIDDLE
argument_list|)
expr_stmt|;
return|return
name|flags
return|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QDirectFbWindow
operator|::
name|raise
parameter_list|()
block|{
name|m_dfbWindow
operator|->
name|RaiseToTop
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lower
name|void
name|QDirectFbWindow
operator|::
name|lower
parameter_list|()
block|{
name|m_dfbWindow
operator|->
name|LowerToBottom
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|winId
name|WId
name|QDirectFbWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
name|DFBWindowID
name|id
decl_stmt|;
name|m_dfbWindow
operator|->
name|GetID
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|id
argument_list|)
expr_stmt|;
return|return
name|WId
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setKeyboardGrabEnabled
name|bool
name|QDirectFbWindow
operator|::
name|setKeyboardGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
block|{
name|DFBResult
name|res
decl_stmt|;
if|if
condition|(
name|grab
condition|)
name|res
operator|=
name|m_dfbWindow
operator|->
name|GrabKeyboard
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|res
operator|=
name|m_dfbWindow
operator|->
name|UngrabKeyboard
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|res
operator|==
name|DFB_OK
return|;
block|}
end_function
begin_function
DECL|function|setMouseGrabEnabled
name|bool
name|QDirectFbWindow
operator|::
name|setMouseGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
block|{
name|DFBResult
name|res
decl_stmt|;
if|if
condition|(
name|grab
condition|)
name|res
operator|=
name|m_dfbWindow
operator|->
name|GrabPointer
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|res
operator|=
name|m_dfbWindow
operator|->
name|UngrabPointer
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|res
operator|==
name|DFB_OK
return|;
block|}
end_function
begin_function
DECL|function|dfbWindow
name|IDirectFBWindow
modifier|*
name|QDirectFbWindow
operator|::
name|dfbWindow
parameter_list|()
specifier|const
block|{
return|return
name|m_dfbWindow
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|dfbSurface
name|IDirectFBSurface
modifier|*
name|QDirectFbWindow
operator|::
name|dfbSurface
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_dfbSurface
condition|)
block|{
name|DFBResult
name|res
init|=
name|m_dfbWindow
operator|->
name|GetSurface
argument_list|(
name|m_dfbWindow
operator|.
name|data
argument_list|()
argument_list|,
name|m_dfbSurface
operator|.
name|outPtr
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|res
operator|!=
name|DFB_OK
condition|)
name|DirectFBError
argument_list|(
name|QDFB_PRETTY
argument_list|,
name|res
argument_list|)
expr_stmt|;
block|}
return|return
name|m_dfbSurface
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
