begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// Renderer.h: Defines a back-end specific class that hides the details of the
end_comment
begin_comment
comment|// implementation-specific renderer.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_RENDERER_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_RENDERER_H_
define|#
directive|define
name|LIBANGLE_RENDERER_RENDERER_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/Caps.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Framebuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/State.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Uniform.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/ImplFactory.h"
end_include
begin_include
include|#
directive|include
file|"common/mathutil.h"
end_include
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|AttributeMap
decl_stmt|;
name|class
name|Display
decl_stmt|;
name|class
name|Surface
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
struct_decl|struct
name|TranslatedIndexData
struct_decl|;
struct_decl|struct
name|SourceIndexData
struct_decl|;
struct_decl|struct
name|WorkaroundsD3D
struct_decl|;
name|class
name|DisplayImpl
decl_stmt|;
name|class
name|Renderer
range|:
name|public
name|ImplFactory
block|{
name|public
operator|:
name|Renderer
argument_list|()
block|;
name|virtual
operator|~
name|Renderer
argument_list|()
block|;
name|virtual
name|gl
operator|::
name|Error
name|flush
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|finish
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|drawArrays
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|drawArraysInstanced
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLsizei instanceCount
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|drawElements
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|const gl::IndexRange&indexRange
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|drawElementsInstanced
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|GLsizei instances
argument_list|,
argument|const gl::IndexRange&indexRange
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|gl
operator|::
name|Error
name|drawRangeElements
argument_list|(
argument|const gl::Data&data
argument_list|,
argument|GLenum mode
argument_list|,
argument|GLuint start
argument_list|,
argument|GLuint end
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid *indices
argument_list|,
argument|const gl::IndexRange&indexRange
argument_list|)
operator|=
literal|0
block|;
comment|// lost device
comment|//TODO(jmadill): investigate if this stuff is necessary in GL
name|virtual
name|void
name|notifyDeviceLost
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|isDeviceLost
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|testDeviceLost
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|testDeviceResettable
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|std
operator|::
name|string
name|getVendorString
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|std
operator|::
name|string
name|getRendererDescription
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|insertEventMarker
argument_list|(
argument|GLsizei length
argument_list|,
argument|const char *marker
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|pushGroupMarker
argument_list|(
argument|GLsizei length
argument_list|,
argument|const char *marker
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|popGroupMarker
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|syncState
argument_list|(
specifier|const
name|gl
operator|::
name|State
operator|&
name|state
argument_list|,
specifier|const
name|gl
operator|::
name|State
operator|::
name|DirtyBits
operator|&
name|dirtyBits
argument_list|)
operator|=
literal|0
block|;
comment|// Disjoint timer queries
name|virtual
name|GLint
name|getGPUDisjoint
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|GLint64
name|getTimestamp
argument_list|()
operator|=
literal|0
block|;
comment|// Context switching
name|virtual
name|void
name|onMakeCurrent
argument_list|(
specifier|const
name|gl
operator|::
name|Data
operator|&
name|data
argument_list|)
operator|=
literal|0
block|;
comment|// Renderer capabilities
specifier|const
name|gl
operator|::
name|Caps
operator|&
name|getRendererCaps
argument_list|()
specifier|const
block|;
specifier|const
name|gl
operator|::
name|TextureCapsMap
operator|&
name|getRendererTextureCaps
argument_list|()
specifier|const
block|;
specifier|const
name|gl
operator|::
name|Extensions
operator|&
name|getRendererExtensions
argument_list|()
specifier|const
block|;
specifier|const
name|gl
operator|::
name|Limitations
operator|&
name|getRendererLimitations
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|ensureCapsInitialized
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|generateCaps
argument_list|(
argument|gl::Caps *outCaps
argument_list|,
argument|gl::TextureCapsMap* outTextureCaps
argument_list|,
argument|gl::Extensions *outExtensions
argument_list|,
argument|gl::Limitations *outLimitations
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|mutable
name|bool
name|mCapsInitialized
block|;
name|mutable
name|gl
operator|::
name|Caps
name|mCaps
block|;
name|mutable
name|gl
operator|::
name|TextureCapsMap
name|mTextureCaps
block|;
name|mutable
name|gl
operator|::
name|Extensions
name|mExtensions
block|;
name|mutable
name|gl
operator|::
name|Limitations
name|mLimitations
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_RENDERER_H_
end_comment
end_unit
