begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
comment|// main.h: Management of thread-local data.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBEGL_MAIN_H_
end_ifndef
begin_define
DECL|macro|LIBEGL_MAIN_H_
define|#
directive|define
name|LIBEGL_MAIN_H_
end_define
begin_undef
DECL|macro|EGLAPI
undef|#
directive|undef
name|EGLAPI
end_undef
begin_define
DECL|macro|EGLAPI
define|#
directive|define
name|EGLAPI
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_decl_stmt
name|namespace
name|egl
block|{
struct|struct
name|Current
block|{
name|EGLint
name|error
decl_stmt|;
name|EGLenum
name|API
decl_stmt|;
name|EGLDisplay
name|display
decl_stmt|;
name|EGLSurface
name|drawSurface
decl_stmt|;
name|EGLSurface
name|readSurface
decl_stmt|;
block|}
struct|;
name|void
name|setCurrentError
parameter_list|(
name|EGLint
name|error
parameter_list|)
function_decl|;
name|EGLint
name|getCurrentError
parameter_list|()
function_decl|;
name|void
name|setCurrentAPI
parameter_list|(
name|EGLenum
name|API
parameter_list|)
function_decl|;
name|EGLenum
name|getCurrentAPI
parameter_list|()
function_decl|;
name|void
name|setCurrentDisplay
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|)
function_decl|;
name|EGLDisplay
name|getCurrentDisplay
parameter_list|()
function_decl|;
name|void
name|setCurrentDrawSurface
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
name|EGLSurface
name|getCurrentDrawSurface
parameter_list|()
function_decl|;
name|void
name|setCurrentReadSurface
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
name|EGLSurface
name|getCurrentReadSurface
parameter_list|()
function_decl|;
name|void
name|error
parameter_list|(
name|EGLint
name|errorCode
parameter_list|)
function_decl|;
name|template
operator|<
name|class
name|T
operator|>
specifier|const
name|T
operator|&
name|error
argument_list|(
argument|EGLint errorCode
argument_list|,
argument|const T&returnValue
argument_list|)
block|{
name|error
argument_list|(
name|errorCode
argument_list|)
block|;
return|return
name|returnValue
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
specifier|const
name|T
operator|&
name|success
argument_list|(
argument|const T&returnValue
argument_list|)
block|{
name|egl
operator|::
name|setCurrentError
argument_list|(
name|EGL_SUCCESS
argument_list|)
block|;
return|return
name|returnValue
return|;
block|}
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBEGL_MAIN_H_
end_comment
end_unit
