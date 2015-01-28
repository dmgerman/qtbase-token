begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSWINDOWFUNCTIONS_H
end_ifndef
begin_define
DECL|macro|QWINDOWSWINDOWFUNCTIONS_H
define|#
directive|define
name|QWINDOWSWINDOWFUNCTIONS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsWindowFunctions
block|{
name|public
label|:
enum|enum
name|TouchWindowTouchType
block|{
name|NormalTouch
init|=
literal|0x00000000
block|,
name|FineTouch
init|=
literal|0x00000001
block|,
name|WantPalmTouch
init|=
literal|0x00000002
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|TouchWindowTouchTypes
argument_list|,
argument|TouchWindowTouchType
argument_list|)
typedef|typedef
name|void
argument_list|(
argument|*SetTouchWindowTouchType
argument_list|)
operator|(
name|QWindow
operator|*
name|window
operator|,
name|QWindowsWindowFunctions
operator|::
name|TouchWindowTouchTypes
name|touchType
operator|)
expr_stmt|;
specifier|static
specifier|const
name|QByteArray
name|setTouchWindowTouchTypeIdentifier
parameter_list|()
block|{
return|return
name|QByteArrayLiteral
argument_list|(
literal|"WindowsSetTouchWindowTouchType"
argument_list|)
return|;
block|}
specifier|static
name|void
name|setTouchWindowTouchType
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|TouchWindowTouchTypes
name|type
parameter_list|)
block|{
name|SetTouchWindowTouchType
name|func
init|=
name|reinterpret_cast
operator|<
name|SetTouchWindowTouchType
operator|>
operator|(
name|QGuiApplication
operator|::
name|platformFunction
argument_list|(
name|setTouchWindowTouchTypeIdentifier
argument_list|()
argument_list|)
operator|)
decl_stmt|;
if|if
condition|(
name|func
condition|)
name|func
argument_list|(
name|window
argument_list|,
name|type
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QWindowsWindowFunctions::TouchWindowTouchTypes
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSWINDOWFUNCTIONS_H
end_comment
end_unit
