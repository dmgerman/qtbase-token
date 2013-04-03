begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// VertexDeclarationCache.h: Defines a helper class to construct and cache vertex declarations.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_RENDERER_VERTEXDECLARATIONCACHE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_RENDERER_VERTEXDECLARATIONCACHE_H_
define|#
directive|define
name|LIBGLESV2_RENDERER_VERTEXDECLARATIONCACHE_H_
end_define
begin_include
include|#
directive|include
file|"libGLESv2/renderer/VertexDataManager.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|VertexDataManager
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|VertexDeclarationCache
block|{
name|public
label|:
name|VertexDeclarationCache
argument_list|()
expr_stmt|;
operator|~
name|VertexDeclarationCache
argument_list|()
expr_stmt|;
name|GLenum
name|applyDeclaration
argument_list|(
name|IDirect3DDevice9
operator|*
name|device
argument_list|,
name|TranslatedAttribute
name|attributes
index|[]
argument_list|,
name|gl
operator|::
name|ProgramBinary
operator|*
name|programBinary
argument_list|,
name|GLsizei
name|instances
argument_list|,
name|GLsizei
operator|*
name|repeatDraw
argument_list|)
decl_stmt|;
name|void
name|markStateDirty
parameter_list|()
function_decl|;
name|private
label|:
name|UINT
name|mMaxLru
decl_stmt|;
enum|enum
block|{
name|NUM_VERTEX_DECL_CACHE_ENTRIES
init|=
literal|32
block|}
enum|;
struct|struct
name|VBData
block|{
name|unsigned
name|int
name|serial
decl_stmt|;
name|unsigned
name|int
name|stride
decl_stmt|;
name|unsigned
name|int
name|offset
decl_stmt|;
block|}
struct|;
name|VBData
name|mAppliedVBs
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
decl_stmt|;
name|IDirect3DVertexDeclaration9
modifier|*
name|mLastSetVDecl
decl_stmt|;
name|bool
name|mInstancingEnabled
decl_stmt|;
struct|struct
name|VertexDeclCacheEntry
block|{
name|D3DVERTEXELEMENT9
name|cachedElements
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
operator|+
literal|1
index|]
decl_stmt|;
name|UINT
name|lruCount
decl_stmt|;
name|IDirect3DVertexDeclaration9
modifier|*
name|vertexDeclaration
decl_stmt|;
block|}
name|mVertexDeclCache
index|[
name|NUM_VERTEX_DECL_CACHE_ENTRIES
index|]
struct|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_RENDERER_VERTEXDECLARATIONCACHE_H_
end_comment
end_unit
