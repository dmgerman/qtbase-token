begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtcursor.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.core.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWinRTCursorPrivate
class|class
name|QWinRTCursorPrivate
block|{
public|public:
DECL|member|cursorFactory
name|ComPtr
argument_list|<
name|ICoreCursorFactory
argument_list|>
name|cursorFactory
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWinRTCursor
name|QWinRTCursor
operator|::
name|QWinRTCursor
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QWinRTCursorPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTCursor
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_UI_Core_CoreCursor
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|d
operator|->
name|cursorFactory
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWinRTCursor
name|QWinRTCursor
operator|::
name|~
name|QWinRTCursor
parameter_list|()
block|{ }
end_destructor
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_function
DECL|function|changeCursor
name|void
name|QWinRTCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|windowCursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTCursor
argument_list|)
expr_stmt|;
name|ICoreWindow
modifier|*
name|coreWindow
init|=
cast|static_cast
argument_list|<
name|QWinRTScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|coreWindow
argument_list|()
decl_stmt|;
name|CoreCursorType
name|type
decl_stmt|;
switch|switch
condition|(
name|windowCursor
condition|?
name|windowCursor
operator|->
name|shape
argument_list|()
else|:
name|Qt
operator|::
name|ArrowCursor
condition|)
block|{
case|case
name|Qt
operator|::
name|BlankCursor
case|:
name|coreWindow
operator|->
name|put_PointerCursor
argument_list|(
name|Q_NULLPTR
argument_list|)
expr_stmt|;
return|return;
default|default:
case|case
name|Qt
operator|::
name|OpenHandCursor
case|:
case|case
name|Qt
operator|::
name|ClosedHandCursor
case|:
case|case
name|Qt
operator|::
name|DragCopyCursor
case|:
case|case
name|Qt
operator|::
name|DragMoveCursor
case|:
case|case
name|Qt
operator|::
name|DragLinkCursor
case|:
comment|// (unavailable)
case|case
name|Qt
operator|::
name|ArrowCursor
case|:
name|type
operator|=
name|CoreCursorType_Arrow
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|UpArrowCursor
case|:
name|type
operator|=
name|CoreCursorType_UpArrow
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|CrossCursor
case|:
name|type
operator|=
name|CoreCursorType_Cross
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|WaitCursor
case|:
case|case
name|Qt
operator|::
name|BusyCursor
case|:
name|type
operator|=
name|CoreCursorType_Wait
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|IBeamCursor
case|:
name|type
operator|=
name|CoreCursorType_IBeam
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeVerCursor
case|:
case|case
name|Qt
operator|::
name|SplitVCursor
case|:
name|type
operator|=
name|CoreCursorType_SizeNorthSouth
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeHorCursor
case|:
case|case
name|Qt
operator|::
name|SplitHCursor
case|:
name|type
operator|=
name|CoreCursorType_SizeWestEast
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeBDiagCursor
case|:
name|type
operator|=
name|CoreCursorType_SizeNortheastSouthwest
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeFDiagCursor
case|:
name|type
operator|=
name|CoreCursorType_SizeNorthwestSoutheast
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|SizeAllCursor
case|:
name|type
operator|=
name|CoreCursorType_SizeAll
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|PointingHandCursor
case|:
name|type
operator|=
name|CoreCursorType_Hand
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|ForbiddenCursor
case|:
name|type
operator|=
name|CoreCursorType_UniversalNo
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|WhatsThisCursor
case|:
name|type
operator|=
name|CoreCursorType_Help
expr_stmt|;
break|break;
case|case
name|Qt
operator|::
name|BitmapCursor
case|:
case|case
name|Qt
operator|::
name|CustomCursor
case|:
comment|// TODO: figure out if arbitrary bitmaps can be made into resource IDs
comment|// For now, we don't get enough info from QCursor to set a custom cursor
name|type
operator|=
name|CoreCursorType_Custom
expr_stmt|;
break|break;
block|}
name|ComPtr
argument_list|<
name|ICoreCursor
argument_list|>
name|cursor
decl_stmt|;
name|HRESULT
name|hr
init|=
name|d
operator|->
name|cursorFactory
operator|->
name|CreateCursor
argument_list|(
name|type
argument_list|,
literal|0
argument_list|,
operator|&
name|cursor
argument_list|)
decl_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to create native cursor."
argument_list|)
expr_stmt|;
name|hr
operator|=
name|coreWindow
operator|->
name|put_PointerCursor
argument_list|(
name|cursor
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to set native cursor."
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CURSOR
end_comment
begin_function
DECL|function|pos
name|QPoint
name|QWinRTCursor
operator|::
name|pos
parameter_list|()
specifier|const
block|{
name|ICoreWindow
modifier|*
name|coreWindow
init|=
cast|static_cast
argument_list|<
name|QWinRTScreen
operator|*
argument_list|>
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|coreWindow
argument_list|()
decl_stmt|;
name|Point
name|point
decl_stmt|;
name|coreWindow
operator|->
name|get_PointerPosition
argument_list|(
operator|&
name|point
argument_list|)
expr_stmt|;
return|return
name|QPoint
argument_list|(
name|point
operator|.
name|X
argument_list|,
name|point
operator|.
name|Y
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
