begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIRECTFBCONVENIENCE_H
end_ifndef
begin_define
DECL|macro|QDIRECTFBCONVENIENCE_H
define|#
directive|define
name|QDIRECTFBCONVENIENCE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QEvent>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_include
include|#
directive|include
file|<directfb.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDirectFbScreen
name|class
name|QDirectFbScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformScreen
name|class
name|QPlatformScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DFBInputDeviceKeySymbol
name|class
name|QDirectFbKeyMap
range|:
name|public
name|QHash
operator|<
name|DFBInputDeviceKeySymbol
decl_stmt|,
name|Qt
decl|::
name|Key
decl|>
block|{
name|public
label|:
name|QDirectFbKeyMap
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QDirectFbConvenience
block|{
name|public
label|:
specifier|static
name|QImage
operator|::
name|Format
name|imageFormatFromSurfaceFormat
argument_list|(
argument|const DFBSurfacePixelFormat format
argument_list|,
argument|const DFBSurfaceCapabilities caps
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|pixelFomatHasAlpha
parameter_list|(
specifier|const
name|DFBSurfacePixelFormat
name|format
parameter_list|)
block|{
return|return
operator|(
literal|1
operator|<<
literal|16
operator|)
operator|&
name|format
return|;
block|}
specifier|static
name|int
name|colorDepthForSurface
parameter_list|(
specifier|const
name|DFBSurfacePixelFormat
name|format
parameter_list|)
function_decl|;
comment|//This is set by the graphicssystem constructor
specifier|static
name|IDirectFB
modifier|*
name|dfbInterface
parameter_list|()
function_decl|;
specifier|static
name|IDirectFBDisplayLayer
modifier|*
name|dfbDisplayLayer
parameter_list|(
name|int
name|display
init|=
name|DLID_PRIMARY
parameter_list|)
function_decl|;
specifier|static
name|IDirectFBSurface
modifier|*
name|dfbSurfaceForPlatformPixmap
parameter_list|(
name|QPlatformPixmap
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|Qt
operator|::
name|MouseButton
name|mouseButton
argument_list|(
argument|DFBInputDeviceButtonIdentifier identifier
argument_list|)
expr_stmt|;
specifier|static
name|Qt
operator|::
name|MouseButtons
name|mouseButtons
argument_list|(
argument|DFBInputDeviceButtonMask mask
argument_list|)
expr_stmt|;
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
argument_list|(
argument|DFBInputDeviceModifierMask mask
argument_list|)
expr_stmt|;
specifier|static
name|QEvent
operator|::
name|Type
name|eventType
argument_list|(
argument|DFBWindowEventType type
argument_list|)
expr_stmt|;
specifier|static
name|QDirectFbKeyMap
modifier|*
name|keyMap
parameter_list|()
function_decl|;
name|private
label|:
specifier|static
name|QDirectFbKeyMap
modifier|*
name|dfbKeymap
decl_stmt|;
name|friend
name|class
name|QDirectFbIntegration
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|struct|QDirectFBInterfaceCleanupHandler
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|QDirectFBInterfaceCleanupHandler
block|{
DECL|function|cleanup
specifier|static
name|void
name|cleanup
argument_list|(
argument|T *t
argument_list|)
block|{
if|if
condition|(
operator|!
name|t
condition|)
return|return;
name|t
operator|->
name|Release
argument_list|(
name|t
argument_list|)
block|;     }
end_expr_stmt
begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
DECL|variable|T
name|class
name|QDirectFBPointer
operator|:
name|public
name|QScopedPointer
operator|<
name|T
operator|,
name|QDirectFBInterfaceCleanupHandler
operator|<
name|T
operator|>
expr|>
block|{
name|public
operator|:
name|QDirectFBPointer
argument_list|(
name|T
operator|*
name|t
operator|=
literal|0
argument_list|)
operator|:
name|QScopedPointer
operator|<
name|T
block|,
name|QDirectFBInterfaceCleanupHandler
operator|<
name|T
operator|>
expr|>
operator|(
name|t
operator|)
block|{}
name|T
operator|*
operator|*
name|outPtr
argument_list|()
block|{
name|this
operator|->
name|reset
argument_list|(
literal|0
argument_list|)
block|;
return|return
operator|&
name|this
operator|->
name|d
return|;
block|}
end_expr_stmt
begin_comment
unit|};
comment|// Helper conversions from internal to DFB types
end_comment
begin_function_decl
name|QDirectFbScreen
modifier|*
name|toDfbScreen
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|IDirectFBDisplayLayer
modifier|*
name|toDfbLayer
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|QDFB_STRINGIFY
define|#
directive|define
name|QDFB_STRINGIFY
parameter_list|(
name|x
parameter_list|)
value|#x
end_define
begin_define
DECL|macro|QDFB_TOSTRING
define|#
directive|define
name|QDFB_TOSTRING
parameter_list|(
name|x
parameter_list|)
value|QDFB_STRINGIFY(x)
end_define
begin_define
DECL|macro|QDFB_PRETTY
define|#
directive|define
name|QDFB_PRETTY
define|\
value|(__FILE__ ":" QDFB_TOSTRING(__LINE__))
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIRECTFBCONVENIENCE_H
end_comment
end_unit
