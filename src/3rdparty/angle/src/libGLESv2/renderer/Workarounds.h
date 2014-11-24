begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// angletypes.h: Workarounds for driver bugs and other issues.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_WORKAROUNDS_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_WORKAROUNDS_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_WORKAROUNDS_H_
end_define
begin_comment
comment|// TODO(jmadill,zmo,geofflang): make a workarounds library that can operate
end_comment
begin_comment
comment|// independent of ANGLE's renderer. Workarounds should also be accessible
end_comment
begin_comment
comment|// outside of the Renderer.
end_comment
begin_decl_stmt
name|namespace
name|rx
block|{
enum|enum
name|D3DWorkaroundType
block|{
name|ANGLE_D3D_WORKAROUND_NONE
block|,
name|ANGLE_D3D_WORKAROUND_SKIP_OPTIMIZATION
block|,
name|ANGLE_D3D_WORKAROUND_MAX_OPTIMIZATION
block|}
enum|;
struct|struct
name|Workarounds
block|{
name|Workarounds
argument_list|()
operator|:
name|mrtPerfWorkaround
argument_list|(
name|false
argument_list|)
operator|,
name|setDataFasterThanImageUpload
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|mrtPerfWorkaround
expr_stmt|;
name|bool
name|setDataFasterThanImageUpload
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_WORKAROUNDS_H_
end_comment
end_unit
