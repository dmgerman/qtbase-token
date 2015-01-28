begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSDIRECT2DCONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSDIRECT2DCONTEXT_H
define|#
directive|define
name|QWINDOWSDIRECT2DCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_struct_decl
struct_decl|struct
name|ID3D11Device
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|ID2D1Device
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|ID2D1Factory1
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDXGIFactory2
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|ID3D11DeviceContext
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteFactory
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteGdiInterop
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsDirect2DContextPrivate
name|class
name|QWindowsDirect2DContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsDirect2DContext
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWindowsDirect2DContext
argument_list|)
name|public
label|:
name|QWindowsDirect2DContext
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QWindowsDirect2DContext
argument_list|()
expr_stmt|;
name|bool
name|init
parameter_list|()
function_decl|;
specifier|static
name|QWindowsDirect2DContext
modifier|*
name|instance
parameter_list|()
function_decl|;
name|ID3D11Device
operator|*
name|d3dDevice
argument_list|()
specifier|const
expr_stmt|;
name|ID2D1Device
operator|*
name|d2dDevice
argument_list|()
specifier|const
expr_stmt|;
name|ID2D1Factory1
operator|*
name|d2dFactory
argument_list|()
specifier|const
expr_stmt|;
name|IDXGIFactory2
operator|*
name|dxgiFactory
argument_list|()
specifier|const
expr_stmt|;
name|ID3D11DeviceContext
operator|*
name|d3dDeviceContext
argument_list|()
specifier|const
expr_stmt|;
name|IDWriteFactory
operator|*
name|dwriteFactory
argument_list|()
specifier|const
expr_stmt|;
name|IDWriteGdiInterop
operator|*
name|dwriteGdiInterop
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QScopedPointer
operator|<
name|QWindowsDirect2DContextPrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSDIRECT2DCONTEXT_H
end_comment
end_unit
