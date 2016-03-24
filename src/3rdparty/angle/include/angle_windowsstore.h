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
comment|// angle_windowsstore.h:
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANGLE_WINDOWSSTORE_H_
end_ifndef
begin_define
DECL|macro|ANGLE_WINDOWSSTORE_H_
define|#
directive|define
name|ANGLE_WINDOWSSTORE_H_
end_define
begin_comment
comment|// The following properties can be set on the CoreApplication to support additional
end_comment
begin_comment
comment|// ANGLE configuration options.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// The Visual Studio sample templates provided with this version of ANGLE have examples
end_comment
begin_comment
comment|// of how to set these property values.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Property: EGLNativeWindowTypeProperty
end_comment
begin_comment
comment|// Type: IInspectable
end_comment
begin_comment
comment|// Description: Set this property to specify the window type to use for creating a surface.
end_comment
begin_comment
comment|//              If this property is missing, surface creation will fail.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
DECL|variable|EGLNativeWindowTypeProperty
specifier|const
name|wchar_t
name|EGLNativeWindowTypeProperty
index|[]
init|=
literal|L"EGLNativeWindowTypeProperty"
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// Property: EGLRenderSurfaceSizeProperty
end_comment
begin_comment
comment|// Type: Size
end_comment
begin_comment
comment|// Description: Set this property to specify a preferred size in pixels of the render surface.
end_comment
begin_comment
comment|//              The render surface size width and height must be greater than 0.
end_comment
begin_comment
comment|//              If this property is set, then the render surface size is fixed.
end_comment
begin_comment
comment|//              The render surface will then be scaled to the window dimensions.
end_comment
begin_comment
comment|//              If this property is missing, a default behavior will be provided.
end_comment
begin_comment
comment|//              The default behavior uses the window size if a CoreWindow is specified or
end_comment
begin_comment
comment|//              the size of the SwapChainPanel control if one is specified.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
DECL|variable|EGLRenderSurfaceSizeProperty
specifier|const
name|wchar_t
name|EGLRenderSurfaceSizeProperty
index|[]
init|=
literal|L"EGLRenderSurfaceSizeProperty"
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// Property: EGLRenderResolutionScaleProperty
end_comment
begin_comment
comment|// Type: Single
end_comment
begin_comment
comment|// Description: Use this to specify a preferred scale for the render surface compared to the window.
end_comment
begin_comment
comment|//              For example, if the window is 800x480, and:
end_comment
begin_comment
comment|//                - scale is set to 0.5f then the surface will be 400x240
end_comment
begin_comment
comment|//                - scale is set to 1.2f then the surface will be 960x576
end_comment
begin_comment
comment|//              If the window resizes or rotates then the surface will resize accordingly.
end_comment
begin_comment
comment|//              EGLRenderResolutionScaleProperty and EGLRenderSurfaceSizeProperty cannot both be set.
end_comment
begin_comment
comment|//              The scale factor should be> 0.0f.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
DECL|variable|EGLRenderResolutionScaleProperty
specifier|const
name|wchar_t
name|EGLRenderResolutionScaleProperty
index|[]
init|=
literal|L"EGLRenderResolutionScaleProperty"
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ANGLE_WINDOWSSTORE_H_
end_comment
end_unit
