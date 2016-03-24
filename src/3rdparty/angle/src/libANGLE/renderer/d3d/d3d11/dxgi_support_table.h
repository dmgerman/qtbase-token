begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2015 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// dxgi_support_table:
end_comment
begin_comment
comment|//   Queries for DXGI support of various texture formats. Depends on DXGI
end_comment
begin_comment
comment|//   version, D3D feature level, and is sometimes guaranteed or optional.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|namespace
name|d3d11
block|{
struct|struct
name|DXGISupport
block|{
name|DXGISupport
argument_list|()
operator|:
name|alwaysSupportedFlags
argument_list|(
literal|0
argument_list|)
operator|,
name|neverSupportedFlags
argument_list|(
literal|0
argument_list|)
operator|,
name|optionallySupportedFlags
argument_list|(
literal|0
argument_list|)
block|{     }
name|DXGISupport
argument_list|(
argument|UINT alwaysSupportedIn
argument_list|,
argument|UINT neverSupportedIn
argument_list|,
argument|UINT optionallySupportedIn
argument_list|)
operator|:
name|alwaysSupportedFlags
argument_list|(
name|alwaysSupportedIn
argument_list|)
operator|,
name|neverSupportedFlags
argument_list|(
name|neverSupportedIn
argument_list|)
operator|,
name|optionallySupportedFlags
argument_list|(
argument|optionallySupportedIn
argument_list|)
block|{     }
name|UINT
name|alwaysSupportedFlags
expr_stmt|;
name|UINT
name|neverSupportedFlags
decl_stmt|;
name|UINT
name|optionallySupportedFlags
decl_stmt|;
block|}
struct|;
specifier|const
name|DXGISupport
modifier|&
name|GetDXGISupport
parameter_list|(
name|DXGI_FORMAT
name|dxgiFormat
parameter_list|,
name|D3D_FEATURE_LEVEL
name|featureLevel
parameter_list|)
function_decl|;
block|}
comment|// namespace d3d11
block|}
end_decl_stmt
begin_comment
comment|// namespace rx
end_comment
end_unit
