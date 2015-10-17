begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglfunctions.h"
end_include
begin_include
include|#
directive|include
file|"qopenglextrafunctions.h"
end_include
begin_include
include|#
directive|include
file|"qopenglextensions_p.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qopengl_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qloggingcategory.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|GL_FRAMEBUFFER_SRGB_CAPABLE_EXT
end_ifndef
begin_define
DECL|macro|GL_FRAMEBUFFER_SRGB_CAPABLE_EXT
define|#
directive|define
name|GL_FRAMEBUFFER_SRGB_CAPABLE_EXT
value|0x8DBA
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcGLES3
argument_list|,
literal|"qt.opengl.es3"
argument_list|)
DECL|macro|QT_OPENGL_COUNT_FUNCTIONS
define|#
directive|define
name|QT_OPENGL_COUNT_FUNCTIONS
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
value|+1
DECL|macro|QT_OPENGL_FUNCTION_NAMES
define|#
directive|define
name|QT_OPENGL_FUNCTION_NAMES
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
define|\
value|"gl"#name"\0"
DECL|macro|QT_OPENGL_FLAGS
define|#
directive|define
name|QT_OPENGL_FLAGS
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|,
name|args
parameter_list|)
define|\
value|0,
DECL|macro|QT_OPENGL_IMPLEMENT
define|#
directive|define
name|QT_OPENGL_IMPLEMENT
parameter_list|(
name|CLASS
parameter_list|,
name|FUNCTIONS
parameter_list|)
define|\
value|void CLASS::init(QOpenGLContext *context) \ { \     const char *names = FUNCTIONS(QT_OPENGL_FUNCTION_NAMES); \     const char *name = names; \     for (int i = 0; i< FUNCTIONS(QT_OPENGL_COUNT_FUNCTIONS); ++i) { \         functions[i] = QT_PREPEND_NAMESPACE(getProcAddress(context, name)); \         name += strlen(name) + 1; \     } \ }
comment|/*!     \class QOpenGLFunctions     \brief The QOpenGLFunctions class provides cross-platform access to the OpenGL ES 2.0 API.     \since 5.0     \ingroup painting-3D     \inmodule QtGui      OpenGL ES 2.0 defines a subset of the OpenGL specification that is     common across many desktop and embedded OpenGL implementations.     However, it can be difficult to use the functions from that subset     because they need to be resolved manually on desktop systems.      QOpenGLFunctions provides a guaranteed API that is available on all     OpenGL systems and takes care of function resolution on systems     that need it.  The recommended way to use QOpenGLFunctions is by     direct inheritance:      \code     class MyGLWindow : public QWindow, protected QOpenGLFunctions     {         Q_OBJECT     public:         MyGLWindow(QScreen *screen = 0);      protected:         void initializeGL();         void paintGL();          QOpenGLContext *m_context;     };      MyGLWindow(QScreen *screen)       : QWindow(screen), QOpenGLWidget(parent)     {         setSurfaceType(OpenGLSurface);         create();          // Create an OpenGL context         m_context = new QOpenGLContext;         m_context->create();          // Setup scene and render it         initializeGL();         paintGL();     }      void MyGLWindow::initializeGL()     {         m_context->makeCurrent(this);         initializeOpenGLFunctions();     }     \endcode      The \c{paintGL()} function can then use any of the OpenGL ES 2.0     functions without explicit resolution, such as glActiveTexture()     in the following example:      \code     void MyGLWindow::paintGL()     {         m_context->makeCurrent(this);         glActiveTexture(GL_TEXTURE1);         glBindTexture(GL_TEXTURE_2D, textureId);         ...         m_context->swapBuffers(this);         m_context->doneCurrent();     }     \endcode      QOpenGLFunctions can also be used directly for ad-hoc invocation     of OpenGL ES 2.0 functions on all platforms:      \code     QOpenGLFunctions glFuncs(QOpenGLContext::currentContext());     glFuncs.glActiveTexture(GL_TEXTURE1);     \endcode      An alternative approach is to query the context's associated     QOpenGLFunctions instance. This is somewhat faster than the previous     approach due to avoiding the creation of a new instance, but the difference     is fairly small since the internal data structures are shared, and function     resolving happens only once for a given context, regardless of the number of     QOpenGLFunctions instances initialized for it.      \code     QOpenGLFunctions *glFuncs = QOpenGLContext::currentContext()->functions();     glFuncs->glActiveTexture(GL_TEXTURE1);     \endcode      QOpenGLFunctions provides wrappers for all OpenGL ES 2.0     functions, including the common subset of OpenGL 1.x and ES     2.0. While such functions, for example glClear() or     glDrawArrays(), can be called also directly, as long as the     application links to the platform-specific OpenGL library, calling     them via QOpenGLFunctions enables the possibility of dynamically     loading the OpenGL implementation.      The hasOpenGLFeature() and openGLFeatures() functions can be used     to determine if the OpenGL implementation has a major OpenGL ES 2.0     feature.  For example, the following checks if non power of two     textures are available:      \code     QOpenGLFunctions funcs(QOpenGLContext::currentContext());     bool npot = funcs.hasOpenGLFeature(QOpenGLFunctions::NPOTTextures);     \endcode      \sa QOpenGLContext, QSurfaceFormat */
comment|/*!     \enum QOpenGLFunctions::OpenGLFeature     This enum defines OpenGL and OpenGL ES features whose presence     may depend on the implementation.      \value Multitexture glActiveTexture() function is available.     \value Shaders Shader functions are available.     \value Buffers Vertex and index buffer functions are available.     \value Framebuffers Framebuffer object functions are available.     \value BlendColor glBlendColor() is available.     \value BlendEquation glBlendEquation() is available.     \value BlendEquationSeparate glBlendEquationSeparate() is available.     \value BlendFuncSeparate glBlendFuncSeparate() is available.     \value BlendSubtract Blend subtract mode is available.     \value CompressedTextures Compressed texture functions are available.     \value Multisample glSampleCoverage() function is available.     \value StencilSeparate Separate stencil functions are available.     \value NPOTTextures Non power of two textures are available.     \value NPOTTextureRepeat Non power of two textures can use GL_REPEAT as wrap parameter.     \value FixedFunctionPipeline The fixed function pipeline is available.     \value TextureRGFormats The GL_RED and GL_RG texture formats are available.     \value MultipleRenderTargets Multiple color attachments to framebuffer objects are available. */
comment|// Hidden private fields for additional extension data.
decl|struct
DECL|struct|QOpenGLFunctionsPrivateEx
name|QOpenGLFunctionsPrivateEx
range|:
specifier|public
name|QOpenGLExtensionsPrivate
decl_stmt|, public
name|QOpenGLSharedResource
argument_list|{
DECL|function|QOpenGLFunctionsPrivateEx
name|QOpenGLFunctionsPrivateEx
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
operator|:
name|QOpenGLExtensionsPrivate
argument_list|(
name|context
argument_list|)
argument_list|,
name|QOpenGLSharedResource
argument_list|(
name|context
operator|->
name|shareGroup
argument_list|()
argument_list|)
argument_list|,
name|m_features
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|,
name|m_extensions
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|void
name|invalidateResource
argument_list|()
name|Q_DECL_OVERRIDE
block|{
name|m_features
operator|=
operator|-
literal|1
block|;
name|m_extensions
operator|=
operator|-
literal|1
block|;     }
name|void
name|freeResource
argument_list|(
argument|QOpenGLContext *
argument_list|)
name|Q_DECL_OVERRIDE
block|{
comment|// no gl resources to free
block|}
DECL|member|m_features
name|int
name|m_features
argument_list|;
DECL|member|m_extensions
name|int
name|m_extensions
argument_list|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QOpenGLMultiGroupSharedResource
argument_list|,
argument|qt_gl_functions_resource
argument_list|)
end_macro
begin_function
DECL|function|qt_gl_functions
specifier|static
name|QOpenGLFunctionsPrivateEx
modifier|*
name|qt_gl_functions
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
operator|!
name|context
condition|)
name|context
operator|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QOpenGLFunctionsPrivateEx
modifier|*
name|funcs
init|=
name|qt_gl_functions_resource
argument_list|()
operator|->
name|value
argument_list|<
name|QOpenGLFunctionsPrivateEx
argument_list|>
argument_list|(
name|context
argument_list|)
decl_stmt|;
return|return
name|funcs
return|;
block|}
end_function
begin_comment
comment|/*!     Constructs a default function resolver. The resolver cannot     be used until initializeOpenGLFunctions() is called to specify     the context.      \sa initializeOpenGLFunctions() */
end_comment
begin_constructor
DECL|function|QOpenGLFunctions
name|QOpenGLFunctions
operator|::
name|QOpenGLFunctions
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a function resolver for \a context.  If \a context     is null, then the resolver will be created for the current QOpenGLContext.      The context or another context in the group must be current.      An object constructed in this way can only be used with \a context     and other contexts that share with it.  Use initializeOpenGLFunctions()     to change the object's context association.      \sa initializeOpenGLFunctions() */
end_comment
begin_constructor
DECL|function|QOpenGLFunctions
name|QOpenGLFunctions
operator|::
name|QOpenGLFunctions
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|context
operator|&&
name|QOpenGLContextGroup
operator|::
name|currentContextGroup
argument_list|()
operator|==
name|context
operator|->
name|shareGroup
argument_list|()
condition|)
name|d_ptr
operator|=
name|qt_gl_functions
argument_list|(
name|context
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"QOpenGLFunctions created with non-current context"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|QOpenGLExtensions
name|QOpenGLExtensions
operator|::
name|QOpenGLExtensions
parameter_list|()
block|{ }
end_constructor
begin_constructor
DECL|function|QOpenGLExtensions
name|QOpenGLExtensions
operator|::
name|QOpenGLExtensions
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
member_init_list|:
name|QOpenGLExtraFunctions
argument_list|(
name|context
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QOpenGLFunctions::~QOpenGLFunctions()      Destroys this function resolver. */
end_comment
begin_function
DECL|function|qt_gl_resolve_features
specifier|static
name|int
name|qt_gl_resolve_features
parameter_list|()
block|{
name|QOpenGLContext
modifier|*
name|ctx
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ctx
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
comment|// OpenGL ES
name|int
name|features
init|=
name|QOpenGLFunctions
operator|::
name|Multitexture
operator||
name|QOpenGLFunctions
operator|::
name|Shaders
operator||
name|QOpenGLFunctions
operator|::
name|Buffers
operator||
name|QOpenGLFunctions
operator|::
name|Framebuffers
operator||
name|QOpenGLFunctions
operator|::
name|BlendColor
operator||
name|QOpenGLFunctions
operator|::
name|BlendEquation
operator||
name|QOpenGLFunctions
operator|::
name|BlendEquationSeparate
operator||
name|QOpenGLFunctions
operator|::
name|BlendFuncSeparate
operator||
name|QOpenGLFunctions
operator|::
name|BlendSubtract
operator||
name|QOpenGLFunctions
operator|::
name|CompressedTextures
operator||
name|QOpenGLFunctions
operator|::
name|Multisample
operator||
name|QOpenGLFunctions
operator|::
name|StencilSeparate
decl_stmt|;
name|QOpenGLExtensionMatcher
name|extensions
decl_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_IMG_texture_npot"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|NPOTTextures
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_OES_texture_npot"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|NPOTTextures
operator||
name|QOpenGLFunctions
operator|::
name|NPOTTextureRepeat
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|format
argument_list|()
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|3
operator|||
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_EXT_texture_rg"
argument_list|)
condition|)
block|{
comment|// Mesa's GLES implementation (as of 10.6.0) is unable to handle this, even though it provides 3.0.
specifier|const
name|char
modifier|*
name|renderer
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|ctx
operator|->
name|functions
argument_list|()
operator|->
name|glGetString
argument_list|(
name|GL_RENDERER
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|renderer
operator|&&
name|strstr
argument_list|(
name|renderer
argument_list|,
literal|"Mesa"
argument_list|)
operator|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|TextureRGFormats
expr_stmt|;
block|}
if|if
condition|(
name|ctx
operator|->
name|format
argument_list|()
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|3
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|MultipleRenderTargets
expr_stmt|;
return|return
name|features
return|;
block|}
else|else
block|{
comment|// OpenGL
name|int
name|features
init|=
name|QOpenGLFunctions
operator|::
name|TextureRGFormats
decl_stmt|;
name|QSurfaceFormat
name|format
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|format
argument_list|()
decl_stmt|;
name|QOpenGLExtensionMatcher
name|extensions
decl_stmt|;
if|if
condition|(
name|format
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|3
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|Framebuffers
operator||
name|QOpenGLFunctions
operator|::
name|MultipleRenderTargets
expr_stmt|;
elseif|else
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_EXT_framebuffer_object"
argument_list|)
operator|||
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_ARB_framebuffer_object"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|Framebuffers
operator||
name|QOpenGLFunctions
operator|::
name|MultipleRenderTargets
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|2
condition|)
block|{
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|BlendColor
operator||
name|QOpenGLFunctions
operator|::
name|BlendEquation
operator||
name|QOpenGLFunctions
operator|::
name|BlendSubtract
operator||
name|QOpenGLFunctions
operator|::
name|Multitexture
operator||
name|QOpenGLFunctions
operator|::
name|CompressedTextures
operator||
name|QOpenGLFunctions
operator|::
name|Multisample
operator||
name|QOpenGLFunctions
operator|::
name|BlendFuncSeparate
operator||
name|QOpenGLFunctions
operator|::
name|Buffers
operator||
name|QOpenGLFunctions
operator|::
name|Shaders
operator||
name|QOpenGLFunctions
operator|::
name|StencilSeparate
operator||
name|QOpenGLFunctions
operator|::
name|BlendEquationSeparate
operator||
name|QOpenGLFunctions
operator|::
name|NPOTTextures
operator||
name|QOpenGLFunctions
operator|::
name|NPOTTextureRepeat
expr_stmt|;
block|}
else|else
block|{
comment|// Recognize features by extension name.
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_ARB_multitexture"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|Multitexture
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_ARB_shader_objects"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|Shaders
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_EXT_blend_color"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|BlendColor
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_EXT_blend_equation_separate"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|BlendEquationSeparate
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_EXT_blend_subtract"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|BlendSubtract
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_EXT_blend_func_separate"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|BlendFuncSeparate
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_ARB_texture_compression"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|CompressedTextures
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_ARB_multisample"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|Multisample
expr_stmt|;
if|if
condition|(
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_ARB_texture_non_power_of_two"
argument_list|)
condition|)
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|NPOTTextures
operator||
name|QOpenGLFunctions
operator|::
name|NPOTTextureRepeat
expr_stmt|;
block|}
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|version
init|=
name|format
operator|.
name|version
argument_list|()
decl_stmt|;
if|if
condition|(
name|version
operator|<
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
operator|||
operator|(
name|version
operator|==
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
operator|&&
name|format
operator|.
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DeprecatedFunctions
argument_list|)
operator|)
operator|||
operator|(
name|version
operator|==
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
operator|&&
name|extensions
operator|.
name|match
argument_list|(
literal|"GL_ARB_compatibility"
argument_list|)
operator|)
operator|||
operator|(
name|version
operator|>=
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
operator|&&
name|format
operator|.
name|profile
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|CompatibilityProfile
operator|)
condition|)
block|{
name|features
operator||=
name|QOpenGLFunctions
operator|::
name|FixedFunctionPipeline
expr_stmt|;
block|}
return|return
name|features
return|;
block|}
block|}
end_function
begin_function
DECL|function|qt_gl_resolve_extensions
specifier|static
name|int
name|qt_gl_resolve_extensions
parameter_list|()
block|{
name|int
name|extensions
init|=
literal|0
decl_stmt|;
name|QOpenGLExtensionMatcher
name|extensionMatcher
decl_stmt|;
name|QOpenGLContext
modifier|*
name|ctx
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
name|QSurfaceFormat
name|format
init|=
name|ctx
operator|->
name|format
argument_list|()
decl_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_bgra"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|BGRATextureFormat
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ARB_texture_rectangle"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|TextureRectangle
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ARB_texture_compression"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|TextureCompression
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_texture_compression_s3tc"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|DDSTextureCompression
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_OES_compressed_ETC1_RGB8_texture"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|ETC1TextureCompression
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_IMG_texture_compression_pvrtc"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|PVRTCTextureCompression
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ARB_texture_mirrored_repeat"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|MirroredRepeat
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_stencil_two_side"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|StencilTwoSide
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_stencil_wrap"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|StencilWrap
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_NV_float_buffer"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|NVFloatBuffer
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ARB_pixel_buffer_object"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|PixelBufferObject
expr_stmt|;
if|if
condition|(
name|ctx
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
if|if
condition|(
name|format
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|2
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|GenerateMipmap
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|3
condition|)
block|{
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|PackedDepthStencil
operator||
name|QOpenGLExtensions
operator|::
name|Depth24
operator||
name|QOpenGLExtensions
operator|::
name|ElementIndexUint
operator||
name|QOpenGLExtensions
operator|::
name|MapBufferRange
operator||
name|QOpenGLExtensions
operator|::
name|FramebufferBlit
operator||
name|QOpenGLExtensions
operator|::
name|FramebufferMultisample
operator||
name|QOpenGLExtensions
operator|::
name|Sized8Formats
expr_stmt|;
block|}
else|else
block|{
comment|// Recognize features by extension name.
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_OES_packed_depth_stencil"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|PackedDepthStencil
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_OES_depth24"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|Depth24
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ANGLE_framebuffer_blit"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|FramebufferBlit
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ANGLE_framebuffer_multisample"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|FramebufferMultisample
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_NV_framebuffer_blit"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|FramebufferBlit
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_NV_framebuffer_multisample"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|FramebufferMultisample
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_OES_rgb8_rgba8"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|Sized8Formats
expr_stmt|;
block|}
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_OES_mapbuffer"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|MapBuffer
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_OES_element_index_uint"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|ElementIndexUint
expr_stmt|;
comment|// We don't match GL_APPLE_texture_format_BGRA8888 here because it has different semantics.
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_IMG_texture_format_BGRA8888"
argument_list|)
operator|||
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_texture_format_BGRA8888"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|BGRATextureFormat
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_discard_framebuffer"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|DiscardFramebuffer
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_texture_norm16"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|Sized16Formats
expr_stmt|;
block|}
else|else
block|{
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|ElementIndexUint
operator||
name|QOpenGLExtensions
operator|::
name|MapBuffer
operator||
name|QOpenGLExtensions
operator|::
name|Sized16Formats
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|version
argument_list|()
operator|>=
name|qMakePair
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|BGRATextureFormat
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|version
argument_list|()
operator|>=
name|qMakePair
argument_list|(
literal|1
argument_list|,
literal|4
argument_list|)
operator|||
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_SGIS_generate_mipmap"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|GenerateMipmap
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|3
operator|||
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ARB_framebuffer_object"
argument_list|)
condition|)
block|{
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|FramebufferMultisample
operator||
name|QOpenGLExtensions
operator|::
name|FramebufferBlit
operator||
name|QOpenGLExtensions
operator|::
name|PackedDepthStencil
operator||
name|QOpenGLExtensions
operator|::
name|Sized8Formats
expr_stmt|;
block|}
else|else
block|{
comment|// Recognize features by extension name.
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_framebuffer_multisample"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|FramebufferMultisample
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_framebuffer_blit"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|FramebufferBlit
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_packed_depth_stencil"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|PackedDepthStencil
expr_stmt|;
block|}
if|if
condition|(
name|format
operator|.
name|version
argument_list|()
operator|>=
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
operator|||
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ARB_geometry_shader4"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|GeometryShaders
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_ARB_map_buffer_range"
argument_list|)
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|MapBufferRange
expr_stmt|;
if|if
condition|(
name|extensionMatcher
operator|.
name|match
argument_list|(
literal|"GL_EXT_framebuffer_sRGB"
argument_list|)
condition|)
block|{
name|GLboolean
name|srgbCapableFramebuffers
init|=
literal|false
decl_stmt|;
name|ctx
operator|->
name|functions
argument_list|()
operator|->
name|glGetBooleanv
argument_list|(
name|GL_FRAMEBUFFER_SRGB_CAPABLE_EXT
argument_list|,
operator|&
name|srgbCapableFramebuffers
argument_list|)
expr_stmt|;
if|if
condition|(
name|srgbCapableFramebuffers
condition|)
name|extensions
operator||=
name|QOpenGLExtensions
operator|::
name|SRGBFrameBuffer
expr_stmt|;
block|}
block|}
return|return
name|extensions
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the set of features that are present on this system's     OpenGL implementation.      It is assumed that the QOpenGLContext associated with this function     resolver is current.      \sa hasOpenGLFeature() */
end_comment
begin_function
DECL|function|openGLFeatures
name|QOpenGLFunctions
operator|::
name|OpenGLFeatures
name|QOpenGLFunctions
operator|::
name|openGLFeatures
parameter_list|()
specifier|const
block|{
name|QOpenGLFunctionsPrivateEx
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QOpenGLFunctionsPrivateEx
operator|*
argument_list|>
argument_list|(
name|d_ptr
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|d
operator|->
name|m_features
operator|==
operator|-
literal|1
condition|)
name|d
operator|->
name|m_features
operator|=
name|qt_gl_resolve_features
argument_list|()
expr_stmt|;
return|return
name|QOpenGLFunctions
operator|::
name|OpenGLFeatures
argument_list|(
name|d
operator|->
name|m_features
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if \a feature is present on this system's OpenGL     implementation; false otherwise.      It is assumed that the QOpenGLContext associated with this function     resolver is current.      \sa openGLFeatures() */
end_comment
begin_function
DECL|function|hasOpenGLFeature
name|bool
name|QOpenGLFunctions
operator|::
name|hasOpenGLFeature
parameter_list|(
name|QOpenGLFunctions
operator|::
name|OpenGLFeature
name|feature
parameter_list|)
specifier|const
block|{
name|QOpenGLFunctionsPrivateEx
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QOpenGLFunctionsPrivateEx
operator|*
argument_list|>
argument_list|(
name|d_ptr
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|d
operator|->
name|m_features
operator|==
operator|-
literal|1
condition|)
name|d
operator|->
name|m_features
operator|=
name|qt_gl_resolve_features
argument_list|()
expr_stmt|;
return|return
operator|(
name|d
operator|->
name|m_features
operator|&
name|int
argument_list|(
name|feature
argument_list|)
operator|)
operator|!=
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the set of extensions that are present on this system's     OpenGL implementation.      It is assumed that the QOpenGLContext associated with this extension     resolver is current.      \sa hasOpenGLExtensions() */
end_comment
begin_function
DECL|function|openGLExtensions
name|QOpenGLExtensions
operator|::
name|OpenGLExtensions
name|QOpenGLExtensions
operator|::
name|openGLExtensions
parameter_list|()
block|{
name|QOpenGLFunctionsPrivateEx
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QOpenGLFunctionsPrivateEx
operator|*
argument_list|>
argument_list|(
name|d_ptr
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|d
operator|->
name|m_extensions
operator|==
operator|-
literal|1
condition|)
name|d
operator|->
name|m_extensions
operator|=
name|qt_gl_resolve_extensions
argument_list|()
expr_stmt|;
return|return
name|QOpenGLExtensions
operator|::
name|OpenGLExtensions
argument_list|(
name|d
operator|->
name|m_extensions
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if \a extension is present on this system's OpenGL     implementation; false otherwise.      It is assumed that the QOpenGLContext associated with this extension     resolver is current.      \sa openGLFeatures() */
end_comment
begin_function
DECL|function|hasOpenGLExtension
name|bool
name|QOpenGLExtensions
operator|::
name|hasOpenGLExtension
parameter_list|(
name|QOpenGLExtensions
operator|::
name|OpenGLExtension
name|extension
parameter_list|)
specifier|const
block|{
name|QOpenGLFunctionsPrivateEx
modifier|*
name|d
init|=
cast|static_cast
argument_list|<
name|QOpenGLFunctionsPrivateEx
operator|*
argument_list|>
argument_list|(
name|d_ptr
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|d
operator|->
name|m_extensions
operator|==
operator|-
literal|1
condition|)
name|d
operator|->
name|m_extensions
operator|=
name|qt_gl_resolve_extensions
argument_list|()
expr_stmt|;
return|return
operator|(
name|d
operator|->
name|m_extensions
operator|&
name|int
argument_list|(
name|extension
argument_list|)
operator|)
operator|!=
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QOpenGLFunctions::initializeGLFunctions()     \obsolete      Use initializeOpenGLFunctions() instead. */
end_comment
begin_comment
comment|/*!     Initializes OpenGL function resolution for the current context.      After calling this function, the QOpenGLFunctions object can only be     used with the current context and other contexts that share with it.     Call initializeOpenGLFunctions() again to change the object's context     association. */
end_comment
begin_function
DECL|function|initializeOpenGLFunctions
name|void
name|QOpenGLFunctions
operator|::
name|initializeOpenGLFunctions
parameter_list|()
block|{
name|d_ptr
operator|=
name|qt_gl_functions
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBindTexture(GLenum target, GLuint texture)      Convenience function that calls glBindTexture(\a target, \a texture).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBindTexture.xml}{glBindTexture()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBlendFunc(GLenum sfactor, GLenum dfactor)      Convenience function that calls glBlendFunc(\a sfactor, \a dfactor).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBlendFunc.xml}{glBlendFunc()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glClear(GLbitfield mask)      Convenience function that calls glClear(\a mask).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glClear.xml}{glClear()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)      Convenience function that calls glClearColor(\a red, \a green, \a blue, \a alpha).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glClearColor.xml}{glClearColor()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glClearStencil(GLint s)      Convenience function that calls glClearStencil(\a s).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glClearStencil.xml}{glClearStencil()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)      Convenience function that calls glColorMask(\a red, \a green, \a blue, \a alpha).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glColorMask.xml}{glColorMask()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)      Convenience function that calls glCopyTexImage2D(\a target, \a level, \a internalformat, \a x, \a y, \a width, \a height, \a border).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCopyTexImage2D.xml}{glCopyTexImage2D()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)      Convenience function that calls glCopyTexSubImage2D(\a target, \a level, \a xoffset, \a yoffset, \a x, \a y, \a width, \a height).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCopyTexSubImage2D.xml}{glCopyTexSubImage2D()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glCullFace(GLenum mode)      Convenience function that calls glCullFace(\a mode).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCullFace.xml}{glCullFace()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDeleteTextures(GLsizei n, const GLuint* textures)      Convenience function that calls glDeleteTextures(\a n, \a textures).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDeleteTextures.xml}{glDeleteTextures()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDepthFunc(GLenum func)      Convenience function that calls glDepthFunc(\a func).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDepthFunc.xml}{glDepthFunc()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDepthMask(GLboolean flag)      Convenience function that calls glDepthMask(\a flag).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDepthMask.xml}{glDepthMask()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDisable(GLenum cap)      Convenience function that calls glDisable(\a cap).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDisable.xml}{glDisable()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDrawArrays(GLenum mode, GLint first, GLsizei count)      Convenience function that calls glDrawArrays(\a mode, \a first, \a count).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDrawArrays.xml}{glDrawArrays()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices)      Convenience function that calls glDrawElements(\a mode, \a count, \a type, \a indices).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDrawElements.xml}{glDrawElements()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glEnable(GLenum cap)      Convenience function that calls glEnable(\a cap).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glEnable.xml}{glEnable()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glFinish()      Convenience function that calls glFinish().      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glFinish.xml}{glFinish()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glFlush()      Convenience function that calls glFlush().      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glFlush.xml}{glFlush()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glFrontFace(GLenum mode)      Convenience function that calls glFrontFace(\a mode).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glFrontFace.xml}{glFrontFace()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGenTextures(GLsizei n, GLuint* textures)      Convenience function that calls glGenTextures(\a n, \a textures).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGenTextures.xml}{glGenTextures()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetBooleanv(GLenum pname, GLboolean* params)      Convenience function that calls glGetBooleanv(\a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetBooleanv.xml}{glGetBooleanv()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn GLenum QOpenGLFunctions::glGetError()      Convenience function that calls glGetError().      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetError.xml}{glGetError()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetFloatv(GLenum pname, GLfloat* params)      Convenience function that calls glGetFloatv(\a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetFloatv.xml}{glGetFloatv()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetIntegerv(GLenum pname, GLint* params)      Convenience function that calls glGetIntegerv(\a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetIntegerv.xml}{glGetIntegerv()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn const GLubyte *QOpenGLFunctions::glGetString(GLenum name)      Convenience function that calls glGetString(\a name).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetString.xml}{glGetString()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params)      Convenience function that calls glGetTexParameterfv(\a target, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetTexParameterfv.xml}{glGetTexParameterfv()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetTexParameteriv(GLenum target, GLenum pname, GLint* params)      Convenience function that calls glGetTexParameteriv(\a target, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetTexParameteriv.xml}{glGetTexParameteriv()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glHint(GLenum target, GLenum mode)      Convenience function that calls glHint(\a target, \a mode).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glHint.xml}{glHint()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLFunctions::glIsEnabled(GLenum cap)      Convenience function that calls glIsEnabled(\a cap).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glIsEnabled.xml}{glIsEnabled()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLFunctions::glIsTexture(GLuint texture)      Convenience function that calls glIsTexture(\a texture).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glIsTexture.xml}{glIsTexture()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glLineWidth(GLfloat width)      Convenience function that calls glLineWidth(\a width).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glLineWidth.xml}{glLineWidth()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glPixelStorei(GLenum pname, GLint param)      Convenience function that calls glPixelStorei(\a pname, \a param).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glPixelStorei.xml}{glPixelStorei()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glPolygonOffset(GLfloat factor, GLfloat units)      Convenience function that calls glPolygonOffset(\a factor, \a units).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glPolygonOffset.xml}{glPolygonOffset()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels)      Convenience function that calls glReadPixels(\a x, \a y, \a width, \a height, \a format, \a type, \a pixels).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glReadPixels.xml}{glReadPixels()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glScissor(GLint x, GLint y, GLsizei width, GLsizei height)      Convenience function that calls glScissor(\a x, \a y, \a width, \a height).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glScissor.xml}{glScissor()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glStencilFunc(GLenum func, GLint ref, GLuint mask)      Convenience function that calls glStencilFunc(\a func, \a ref, \a mask).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glStencilFunc.xml}{glStencilFunc()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glStencilMask(GLuint mask)      Convenience function that calls glStencilMask(\a mask).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glStencilMask.xml}{glStencilMask()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)      Convenience function that calls glStencilOp(\a fail, \a zfail, \a zpass).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glStencilOp.xml}{glStencilOp()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels)      Convenience function that calls glTexImage2D(\a target, \a level, \a internalformat, \a width, \a height, \a border, \a format, \a type, \a pixels).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glTexImage2D.xml}{glTexImage2D()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glTexParameterf(GLenum target, GLenum pname, GLfloat param)      Convenience function that calls glTexParameterf(\a target, \a pname, \a param).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glTexParameterf.xml}{glTexParameterf()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params)      Convenience function that calls glTexParameterfv(\a target, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glTexParameterfv.xml}{glTexParameterfv()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glTexParameteri(GLenum target, GLenum pname, GLint param)      Convenience function that calls glTexParameteri(\a target, \a pname, \a param).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glTexParameteri.xml}{glTexParameteri()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glTexParameteriv(GLenum target, GLenum pname, const GLint* params)      Convenience function that calls glTexParameteriv(\a target, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glTexParameteriv.xml}{glTexParameteriv()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels)      Convenience function that calls glTexSubImage2D(\a target, \a level, \a xoffset, \a yoffset, \a width, \a height, \a format, \a type, \a pixels).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glTexSubImage2D.xml}{glTexSubImage2D()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glViewport(GLint x, GLint y, GLsizei width, GLsizei height)      Convenience function that calls glViewport(\a x, \a y, \a width, \a height).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glViewport.xml}{glViewport()}.      \since 5.3 */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glActiveTexture(GLenum texture)      Convenience function that calls glActiveTexture(\a texture).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glActiveTexture.xml}{glActiveTexture()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glAttachShader(GLuint program, GLuint shader)      Convenience function that calls glAttachShader(\a program, \a shader).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glAttachShader.xml}{glAttachShader()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBindAttribLocation(GLuint program, GLuint index, const char* name)      Convenience function that calls glBindAttribLocation(\a program, \a index, \a name).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBindAttribLocation.xml}{glBindAttribLocation()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBindBuffer(GLenum target, GLuint buffer)      Convenience function that calls glBindBuffer(\a target, \a buffer).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBindBuffer.xml}{glBindBuffer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBindFramebuffer(GLenum target, GLuint framebuffer)      Convenience function that calls glBindFramebuffer(\a target, \a framebuffer).      Note that Qt will translate a \a framebuffer argument of 0 to the currently     bound QOpenGLContext's defaultFramebufferObject().      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBindFramebuffer.xml}{glBindFramebuffer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBindRenderbuffer(GLenum target, GLuint renderbuffer)      Convenience function that calls glBindRenderbuffer(\a target, \a renderbuffer).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBindRenderbuffer.xml}{glBindRenderbuffer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)      Convenience function that calls glBlendColor(\a red, \a green, \a blue, \a alpha).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBlendColor.xml}{glBlendColor()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBlendEquation(GLenum mode)      Convenience function that calls glBlendEquation(\a mode).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBlendEquation.xml}{glBlendEquation()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)      Convenience function that calls glBlendEquationSeparate(\a modeRGB, \a modeAlpha).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBlendEquationSeparate.xml}{glBlendEquationSeparate()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)      Convenience function that calls glBlendFuncSeparate(\a srcRGB, \a dstRGB, \a srcAlpha, \a dstAlpha).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBlendFuncSeparate.xml}{glBlendFuncSeparate()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBufferData(GLenum target, qopengl_GLsizeiptr size, const void* data, GLenum usage)      Convenience function that calls glBufferData(\a target, \a size, \a data, \a usage).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBufferData.xml}{glBufferData()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glBufferSubData(GLenum target, qopengl_GLintptr offset, qopengl_GLsizeiptr size, const void* data)      Convenience function that calls glBufferSubData(\a target, \a offset, \a size, \a data).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glBufferSubData.xml}{glBufferSubData()}. */
end_comment
begin_comment
comment|/*!     \fn GLenum QOpenGLFunctions::glCheckFramebufferStatus(GLenum target)      Convenience function that calls glCheckFramebufferStatus(\a target).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCheckFramebufferStatus.xml}{glCheckFramebufferStatus()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glClearDepthf(GLclampf depth)      Convenience function that calls glClearDepth(\a depth) on     desktop OpenGL systems and glClearDepthf(\a depth) on     embedded OpenGL ES systems.      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glClearDepthf.xml}{glClearDepthf()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glCompileShader(GLuint shader)      Convenience function that calls glCompileShader(\a shader).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCompileShader.xml}{glCompileShader()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data)      Convenience function that calls glCompressedTexImage2D(\a target, \a level, \a internalformat, \a width, \a height, \a border, \a imageSize, \a data).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCompressedTexImage2D.xml}{glCompressedTexImage2D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data)      Convenience function that calls glCompressedTexSubImage2D(\a target, \a level, \a xoffset, \a yoffset, \a width, \a height, \a format, \a imageSize, \a data).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCompressedTexSubImage2D.xml}{glCompressedTexSubImage2D()}. */
end_comment
begin_comment
comment|/*!     \fn GLuint QOpenGLFunctions::glCreateProgram()      Convenience function that calls glCreateProgram().      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCreateProgram.xml}{glCreateProgram()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn GLuint QOpenGLFunctions::glCreateShader(GLenum type)      Convenience function that calls glCreateShader(\a type).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glCreateShader.xml}{glCreateShader()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDeleteBuffers(GLsizei n, const GLuint* buffers)      Convenience function that calls glDeleteBuffers(\a n, \a buffers).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDeleteBuffers.xml}{glDeleteBuffers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers)      Convenience function that calls glDeleteFramebuffers(\a n, \a framebuffers).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDeleteFramebuffers.xml}{glDeleteFramebuffers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDeleteProgram(GLuint program)      Convenience function that calls glDeleteProgram(\a program).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDeleteProgram.xml}{glDeleteProgram()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers)      Convenience function that calls glDeleteRenderbuffers(\a n, \a renderbuffers).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDeleteRenderbuffers.xml}{glDeleteRenderbuffers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDeleteShader(GLuint shader)      Convenience function that calls glDeleteShader(\a shader).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDeleteShader.xml}{glDeleteShader()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDepthRangef(GLclampf zNear, GLclampf zFar)      Convenience function that calls glDepthRange(\a zNear, \a zFar) on     desktop OpenGL systems and glDepthRangef(\a zNear, \a zFar) on     embedded OpenGL ES systems.      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDepthRangef.xml}{glDepthRangef()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDetachShader(GLuint program, GLuint shader)      Convenience function that calls glDetachShader(\a program, \a shader).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDetachShader.xml}{glDetachShader()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glDisableVertexAttribArray(GLuint index)      Convenience function that calls glDisableVertexAttribArray(\a index).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glDisableVertexAttribArray.xml}{glDisableVertexAttribArray()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glEnableVertexAttribArray(GLuint index)      Convenience function that calls glEnableVertexAttribArray(\a index).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glEnableVertexAttribArray.xml}{glEnableVertexAttribArray()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)      Convenience function that calls glFramebufferRenderbuffer(\a target, \a attachment, \a renderbuffertarget, \a renderbuffer).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glFramebufferRenderbuffer.xml}{glFramebufferRenderbuffer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)      Convenience function that calls glFramebufferTexture2D(\a target, \a attachment, \a textarget, \a texture, \a level).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glFramebufferTexture2D.xml}{glFramebufferTexture2D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGenBuffers(GLsizei n, GLuint* buffers)      Convenience function that calls glGenBuffers(\a n, \a buffers).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGenBuffers.xml}{glGenBuffers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGenerateMipmap(GLenum target)      Convenience function that calls glGenerateMipmap(\a target).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGenerateMipmap.xml}{glGenerateMipmap()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGenFramebuffers(GLsizei n, GLuint* framebuffers)      Convenience function that calls glGenFramebuffers(\a n, \a framebuffers).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGenFramebuffers.xml}{glGenFramebuffers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGenRenderbuffers(GLsizei n, GLuint* renderbuffers)      Convenience function that calls glGenRenderbuffers(\a n, \a renderbuffers).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGenRenderbuffers.xml}{glGenRenderbuffers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name)      Convenience function that calls glGetActiveAttrib(\a program, \a index, \a bufsize, \a length, \a size, \a type, \a name).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetActiveAttrib.xml}{glGetActiveAttrib()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name)      Convenience function that calls glGetActiveUniform(\a program, \a index, \a bufsize, \a length, \a size, \a type, \a name).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetActiveUniform.xml}{glGetActiveUniform()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)      Convenience function that calls glGetAttachedShaders(\a program, \a maxcount, \a count, \a shaders).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetAttachedShaders.xml}{glGetAttachedShaders()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn GLint QOpenGLFunctions::glGetAttribLocation(GLuint program, const char* name)      Convenience function that calls glGetAttribLocation(\a program, \a name).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetAttribLocation.xml}{glGetAttribLocation()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params)      Convenience function that calls glGetBufferParameteriv(\a target, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetBufferParameteriv.xml}{glGetBufferParameteriv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params)      Convenience function that calls glGetFramebufferAttachmentParameteriv(\a target, \a attachment, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetFramebufferAttachmentParameteriv.xml}{glGetFramebufferAttachmentParameteriv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetProgramiv(GLuint program, GLenum pname, GLint* params)      Convenience function that calls glGetProgramiv(\a program, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetProgramiv.xml}{glGetProgramiv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei* length, char* infolog)      Convenience function that calls glGetProgramInfoLog(\a program, \a bufsize, \a length, \a infolog).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetProgramInfoLog.xml}{glGetProgramInfoLog()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params)      Convenience function that calls glGetRenderbufferParameteriv(\a target, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetRenderbufferParameteriv.xml}{glGetRenderbufferParameteriv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetShaderiv(GLuint shader, GLenum pname, GLint* params)      Convenience function that calls glGetShaderiv(\a shader, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetShaderiv.xml}{glGetShaderiv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei* length, char* infolog)      Convenience function that calls glGetShaderInfoLog(\a shader, \a bufsize, \a length, \a infolog).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetShaderInfoLog.xml}{glGetShaderInfoLog()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision)      Convenience function that calls glGetShaderPrecisionFormat(\a shadertype, \a precisiontype, \a range, \a precision).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetShaderPrecisionFormat.xml}{glGetShaderPrecisionFormat()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei* length, char* source)      Convenience function that calls glGetShaderSource(\a shader, \a bufsize, \a length, \a source).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetShaderSource.xml}{glGetShaderSource()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetUniformfv(GLuint program, GLint location, GLfloat* params)      Convenience function that calls glGetUniformfv(\a program, \a location, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetUniformfv.xml}{glGetUniformfv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetUniformiv(GLuint program, GLint location, GLint* params)      Convenience function that calls glGetUniformiv(\a program, \a location, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetUniformiv.xml}{glGetUniformiv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn GLint QOpenGLFunctions::glGetUniformLocation(GLuint program, const char* name)      Convenience function that calls glGetUniformLocation(\a program, \a name).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetUniformLocation.xml}{glGetUniformLocation()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params)      Convenience function that calls glGetVertexAttribfv(\a index, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetVertexAttribfv.xml}{glGetVertexAttribfv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params)      Convenience function that calls glGetVertexAttribiv(\a index, \a pname, \a params).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetVertexAttribiv.xml}{glGetVertexAttribiv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glGetVertexAttribPointerv(GLuint index, GLenum pname, void** pointer)      Convenience function that calls glGetVertexAttribPointerv(\a index, \a pname, \a pointer).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glGetVertexAttribPointerv.xml}{glGetVertexAttribPointerv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLFunctions::glIsBuffer(GLuint buffer)      Convenience function that calls glIsBuffer(\a buffer).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glIsBuffer.xml}{glIsBuffer()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLFunctions::glIsFramebuffer(GLuint framebuffer)      Convenience function that calls glIsFramebuffer(\a framebuffer).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glIsFramebuffer.xml}{glIsFramebuffer()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLFunctions::glIsProgram(GLuint program)      Convenience function that calls glIsProgram(\a program).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glIsProgram.xml}{glIsProgram()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLFunctions::glIsRenderbuffer(GLuint renderbuffer)      Convenience function that calls glIsRenderbuffer(\a renderbuffer).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glIsRenderbuffer.xml}{glIsRenderbuffer()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLFunctions::glIsShader(GLuint shader)      Convenience function that calls glIsShader(\a shader).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glIsShader.xml}{glIsShader()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glLinkProgram(GLuint program)      Convenience function that calls glLinkProgram(\a program).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glLinkProgram.xml}{glLinkProgram()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glReleaseShaderCompiler()      Convenience function that calls glReleaseShaderCompiler().      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glReleaseShaderCompiler.xml}{glReleaseShaderCompiler()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)      Convenience function that calls glRenderbufferStorage(\a target, \a internalformat, \a width, \a height).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glRenderbufferStorage.xml}{glRenderbufferStorage()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glSampleCoverage(GLclampf value, GLboolean invert)      Convenience function that calls glSampleCoverage(\a value, \a invert).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glSampleCoverage.xml}{glSampleCoverage()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glShaderBinary(GLint n, const GLuint* shaders, GLenum binaryformat, const void* binary, GLint length)      Convenience function that calls glShaderBinary(\a n, \a shaders, \a binaryformat, \a binary, \a length).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glShaderBinary.xml}{glShaderBinary()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glShaderSource(GLuint shader, GLsizei count, const char** string, const GLint* length)      Convenience function that calls glShaderSource(\a shader, \a count, \a string, \a length).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glShaderSource.xml}{glShaderSource()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)      Convenience function that calls glStencilFuncSeparate(\a face, \a func, \a ref, \a mask).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glStencilFuncSeparate.xml}{glStencilFuncSeparate()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glStencilMaskSeparate(GLenum face, GLuint mask)      Convenience function that calls glStencilMaskSeparate(\a face, \a mask).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glStencilMaskSeparate.xml}{glStencilMaskSeparate()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)      Convenience function that calls glStencilOpSeparate(\a face, \a fail, \a zfail, \a zpass).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glStencilOpSeparate.xml}{glStencilOpSeparate()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform1f(GLint location, GLfloat x)      Convenience function that calls glUniform1f(\a location, \a x).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform1f.xml}{glUniform1f()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform1fv(GLint location, GLsizei count, const GLfloat* v)      Convenience function that calls glUniform1fv(\a location, \a count, \a v).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform1fv.xml}{glUniform1fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform1i(GLint location, GLint x)      Convenience function that calls glUniform1i(\a location, \a x).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform1i.xml}{glUniform1i()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform1iv(GLint location, GLsizei count, const GLint* v)      Convenience function that calls glUniform1iv(\a location, \a count, \a v).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform1iv.xml}{glUniform1iv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform2f(GLint location, GLfloat x, GLfloat y)      Convenience function that calls glUniform2f(\a location, \a x, \a y).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform2f.xml}{glUniform2f()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform2fv(GLint location, GLsizei count, const GLfloat* v)      Convenience function that calls glUniform2fv(\a location, \a count, \a v).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform2fv.xml}{glUniform2fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform2i(GLint location, GLint x, GLint y)      Convenience function that calls glUniform2i(\a location, \a x, \a y).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform2i.xml}{glUniform2i()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform2iv(GLint location, GLsizei count, const GLint* v)      Convenience function that calls glUniform2iv(\a location, \a count, \a v).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform2iv.xml}{glUniform2iv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z)      Convenience function that calls glUniform3f(\a location, \a x, \a y, \a z).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform3f.xml}{glUniform3f()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform3fv(GLint location, GLsizei count, const GLfloat* v)      Convenience function that calls glUniform3fv(\a location, \a count, \a v).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform3fv.xml}{glUniform3fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform3i(GLint location, GLint x, GLint y, GLint z)      Convenience function that calls glUniform3i(\a location, \a x, \a y, \a z).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform3i.xml}{glUniform3i()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform3iv(GLint location, GLsizei count, const GLint* v)      Convenience function that calls glUniform3iv(\a location, \a count, \a v).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform3iv.xml}{glUniform3iv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)      Convenience function that calls glUniform4f(\a location, \a x, \a y, \a z, \a w).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform4f.xml}{glUniform4f()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform4fv(GLint location, GLsizei count, const GLfloat* v)      Convenience function that calls glUniform4fv(\a location, \a count, \a v).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform4fv.xml}{glUniform4fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)      Convenience function that calls glUniform4i(\a location, \a x, \a y, \a z, \a w).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform4i.xml}{glUniform4i()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniform4iv(GLint location, GLsizei count, const GLint* v)      Convenience function that calls glUniform4iv(\a location, \a count, \a v).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniform4iv.xml}{glUniform4iv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)      Convenience function that calls glUniformMatrix2fv(\a location, \a count, \a transpose, \a value).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniformMatrix2fv.xml}{glUniformMatrix2fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)      Convenience function that calls glUniformMatrix3fv(\a location, \a count, \a transpose, \a value).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniformMatrix3fv.xml}{glUniformMatrix3fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)      Convenience function that calls glUniformMatrix4fv(\a location, \a count, \a transpose, \a value).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUniformMatrix4fv.xml}{glUniformMatrix4fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glUseProgram(GLuint program)      Convenience function that calls glUseProgram(\a program).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glUseProgram.xml}{glUseProgram()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glValidateProgram(GLuint program)      Convenience function that calls glValidateProgram(\a program).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glValidateProgram.xml}{glValidateProgram()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttrib1f(GLuint indx, GLfloat x)      Convenience function that calls glVertexAttrib1f(\a indx, \a x).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttrib1f.xml}{glVertexAttrib1f()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttrib1fv(GLuint indx, const GLfloat* values)      Convenience function that calls glVertexAttrib1fv(\a indx, \a values).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttrib1fv.xml}{glVertexAttrib1fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttrib2f(GLuint indx, GLfloat x, GLfloat y)      Convenience function that calls glVertexAttrib2f(\a indx, \a x, \a y).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttrib2f.xml}{glVertexAttrib2f()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttrib2fv(GLuint indx, const GLfloat* values)      Convenience function that calls glVertexAttrib2fv(\a indx, \a values).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttrib2fv.xml}{glVertexAttrib2fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z)      Convenience function that calls glVertexAttrib3f(\a indx, \a x, \a y, \a z).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttrib3f.xml}{glVertexAttrib3f()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttrib3fv(GLuint indx, const GLfloat* values)      Convenience function that calls glVertexAttrib3fv(\a indx, \a values).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttrib3fv.xml}{glVertexAttrib3fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)      Convenience function that calls glVertexAttrib4f(\a indx, \a x, \a y, \a z, \a w).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttrib4f.xml}{glVertexAttrib4f()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttrib4fv(GLuint indx, const GLfloat* values)      Convenience function that calls glVertexAttrib4fv(\a indx, \a values).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttrib4fv.xml}{glVertexAttrib4fv()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLFunctions::glVertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr)      Convenience function that calls glVertexAttribPointer(\a indx, \a size, \a type, \a normalized, \a stride, \a ptr).      For more information, see the OpenGL ES 2.0 documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man/glVertexAttribPointer.xml}{glVertexAttribPointer()}.      This convenience function will do nothing on OpenGL ES 1.x systems. */
end_comment
begin_comment
comment|/*!     \fn bool QOpenGLFunctions::isInitialized(const QOpenGLFunctionsPrivate *d)     \internal */
end_comment
begin_namespace
namespace|namespace
block|{
comment|// this function tries hard to get the opengl function we're looking for by also
comment|// trying to resolve it with some of the common extensions if the generic name
comment|// can't be found.
DECL|function|getProcAddress
specifier|static
name|QFunctionPointer
name|getProcAddress
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|funcName
parameter_list|)
block|{
name|QFunctionPointer
name|function
init|=
name|context
operator|->
name|getProcAddress
argument_list|(
name|funcName
argument_list|)
decl_stmt|;
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|// includes trailing \0
block|}
name|extensions
index|[]
init|=
block|{
block|{
literal|"ARB"
block|,
literal|4
block|}
block|,
block|{
literal|"OES"
block|,
literal|4
block|}
block|,
block|{
literal|"EXT"
block|,
literal|4
block|}
block|,
block|{
literal|"ANGLE"
block|,
literal|6
block|}
block|,
block|{
literal|"NV"
block|,
literal|3
block|}
block|,     }
struct|;
if|if
condition|(
operator|!
name|function
condition|)
block|{
name|char
name|fn
index|[
literal|512
index|]
decl_stmt|;
name|size_t
name|size
init|=
name|strlen
argument_list|(
name|funcName
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|size
operator|<
literal|500
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|fn
argument_list|,
name|funcName
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|char
modifier|*
name|ext
init|=
name|fn
operator|+
name|size
decl_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|e
range|:
name|extensions
control|)
block|{
name|memcpy
argument_list|(
name|ext
argument_list|,
name|e
operator|.
name|name
argument_list|,
name|e
operator|.
name|len
argument_list|)
expr_stmt|;
name|function
operator|=
name|context
operator|->
name|getProcAddress
argument_list|(
name|fn
argument_list|)
expr_stmt|;
if|if
condition|(
name|function
condition|)
break|break;
block|}
block|}
return|return
name|function
return|;
block|}
template|template
parameter_list|<
name|typename
name|Func
parameter_list|>
DECL|function|resolve
name|Func
name|resolve
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|Func
parameter_list|)
block|{
return|return
cast|reinterpret_cast
argument_list|<
name|Func
argument_list|>
argument_list|(
name|getProcAddress
argument_list|(
name|context
argument_list|,
name|name
argument_list|)
argument_list|)
return|;
block|}
block|}
end_namespace
begin_define
DECL|macro|RESOLVE
define|#
directive|define
name|RESOLVE
parameter_list|(
name|name
parameter_list|)
define|\
value|resolve(context, "gl"#name, name)
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
end_ifndef
begin_comment
comment|// some fallback functions
end_comment
begin_function
DECL|function|qopenglfSpecialClearDepthf
specifier|static
name|void
name|QOPENGLF_APIENTRY
name|qopenglfSpecialClearDepthf
parameter_list|(
name|GLclampf
name|depth
parameter_list|)
block|{
name|QOpenGLContext
modifier|*
name|context
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
name|QOpenGLFunctionsPrivate
modifier|*
name|funcs
init|=
name|qt_gl_functions
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|funcs
operator|->
name|f
operator|.
name|ClearDepth
argument_list|(
operator|(
name|GLdouble
operator|)
name|depth
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qopenglfSpecialDepthRangef
specifier|static
name|void
name|QOPENGLF_APIENTRY
name|qopenglfSpecialDepthRangef
parameter_list|(
name|GLclampf
name|zNear
parameter_list|,
name|GLclampf
name|zFar
parameter_list|)
block|{
name|QOpenGLContext
modifier|*
name|context
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
name|QOpenGLFunctionsPrivate
modifier|*
name|funcs
init|=
name|qt_gl_functions
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|funcs
operator|->
name|f
operator|.
name|DepthRange
argument_list|(
operator|(
name|GLdouble
operator|)
name|zNear
argument_list|,
operator|(
name|GLdouble
operator|)
name|zFar
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qopenglfSpecialGetShaderPrecisionFormat
specifier|static
name|void
name|QOPENGLF_APIENTRY
name|qopenglfSpecialGetShaderPrecisionFormat
parameter_list|(
name|GLenum
name|shadertype
parameter_list|,
name|GLenum
name|precisiontype
parameter_list|,
name|GLint
modifier|*
name|range
parameter_list|,
name|GLint
modifier|*
name|precision
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|shadertype
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|precisiontype
argument_list|)
expr_stmt|;
name|range
index|[
literal|0
index|]
operator|=
name|range
index|[
literal|1
index|]
operator|=
name|precision
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qopenglfSpecialIsProgram
specifier|static
name|GLboolean
name|QOPENGLF_APIENTRY
name|qopenglfSpecialIsProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
block|{
return|return
name|program
operator|!=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qopenglfSpecialIsShader
specifier|static
name|GLboolean
name|QOPENGLF_APIENTRY
name|qopenglfSpecialIsShader
parameter_list|(
name|GLuint
name|shader
parameter_list|)
block|{
return|return
name|shader
operator|!=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qopenglfSpecialReleaseShaderCompiler
specifier|static
name|void
name|QOPENGLF_APIENTRY
name|qopenglfSpecialReleaseShaderCompiler
parameter_list|()
block|{ }
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_OPENGL_ES_2
end_comment
begin_constructor
DECL|function|QOpenGLFunctionsPrivate
name|QOpenGLFunctionsPrivate
operator|::
name|QOpenGLFunctionsPrivate
parameter_list|(
name|QOpenGLContext
modifier|*
name|c
parameter_list|)
block|{
name|init
argument_list|(
name|c
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2
comment|// setup fallbacks in case some methods couldn't get resolved
if|if
condition|(
operator|!
name|f
operator|.
name|ClearDepthf
condition|)
name|f
operator|.
name|ClearDepthf
operator|=
name|qopenglfSpecialClearDepthf
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|DepthRangef
condition|)
name|f
operator|.
name|DepthRangef
operator|=
name|qopenglfSpecialDepthRangef
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|GetShaderPrecisionFormat
condition|)
name|f
operator|.
name|GetShaderPrecisionFormat
operator|=
name|qopenglfSpecialGetShaderPrecisionFormat
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|IsProgram
condition|)
name|f
operator|.
name|IsProgram
operator|=
name|qopenglfSpecialIsProgram
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|IsShader
condition|)
name|f
operator|.
name|IsShader
operator|=
name|qopenglfSpecialIsShader
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|ReleaseShaderCompiler
condition|)
name|f
operator|.
name|ReleaseShaderCompiler
operator|=
name|qopenglfSpecialReleaseShaderCompiler
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLFunctionsPrivate
argument_list|,
argument|QT_OPENGL_FUNCTIONS
argument_list|)
end_macro
begin_comment
comment|/*!     \class QOpenGLExtraFunctions     \brief The QOpenGLExtraFunctions class provides cross-platform access to the OpenGL ES 3.0 and 3.1 API.     \since 5.6     \ingroup painting-3D     \inmodule QtGui      This subclass of QOpenGLFunctions includes the OpenGL ES 3.0 and 3.1     functions. These will only work when an OpenGL ES 3.0 or 3.1 context, or an     OpenGL context of a version containing the functions in question either in     core or as extension, is in use. This allows developing GLES 3.0 and 3.1     applications in a cross-platform manner: development can happen on a desktop     platform with OpenGL 3.x or 4.x, deploying to a real GLES 3.1 device later     on will require no or minimal changes to the application.      \note This class is different from the versioned OpenGL wrappers, for     instance QOpenGLFunctions_3_2_Core. The versioned function wrappers target a     given version and profile of OpenGL. They are therefore not suitable for     cross-OpenGL-OpenGLES development.  */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBeginQuery(GLenum target, GLuint id)      Convenience function that calls glBeginQuery(\a target, \a id).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBeginQuery.xml}{glBeginQuery()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBeginTransformFeedback(GLenum primitiveMode)      Convenience function that calls glBeginTransformFeedback(\a primitiveMode).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBeginTransformFeedback.xml}{glBeginTransformFeedback()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBindBufferBase(GLenum target, GLuint index, GLuint buffer)      Convenience function that calls glBindBufferBase(\a target, \a index, \a buffer).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBindBufferBase.xml}{glBindBufferBase()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)      Convenience function that calls glBindBufferRange(\a target, \a index, \a buffer, \a offset, \a size).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBindBufferRange.xml}{glBindBufferRange()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBindSampler(GLuint unit, GLuint sampler)      Convenience function that calls glBindSampler(\a unit, \a sampler).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBindSampler.xml}{glBindSampler()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBindTransformFeedback(GLenum target, GLuint id)      Convenience function that calls glBindTransformFeedback(\a target, \a id).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBindTransformFeedback.xml}{glBindTransformFeedback()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBindVertexArray(GLuint array)      Convenience function that calls glBindVertexArray(\a array).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBindVertexArray.xml}{glBindVertexArray()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)      Convenience function that calls glBlitFramebuffer(\a srcX0, \a srcY0, \a srcX1, \a srcY1, \a dstX0, \a dstY0, \a dstX1, \a dstY1, \a mask, \a filter).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBlitFramebuffer.xml}{glBlitFramebuffer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)      Convenience function that calls glClearBufferfi(\a buffer, \a drawbuffer, \a depth, \a stencil).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glClearBufferfi.xml}{glClearBufferfi()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value)      Convenience function that calls glClearBufferfv(\a buffer, \a drawbuffer, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glClearBufferfv.xml}{glClearBufferfv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value)      Convenience function that calls glClearBufferiv(\a buffer, \a drawbuffer, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glClearBufferiv.xml}{glClearBufferiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value)      Convenience function that calls glClearBufferuiv(\a buffer, \a drawbuffer, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glClearBufferuiv.xml}{glClearBufferuiv()}. */
end_comment
begin_comment
comment|/*!     \fn GLenum QOpenGLExtraFunctions::glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)      Convenience function that calls glClientWaitSync(\a sync, \a flags, \a timeout).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glClientWaitSync.xml}{glClientWaitSync()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data)      Convenience function that calls glCompressedTexImage3D(\a target, \a level, \a internalformat, \a width, \a height, \a depth, \a border, \a imageSize, \a data).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glCompressedTexImage3D.xml}{glCompressedTexImage3D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data)      Convenience function that calls glCompressedTexSubImage3D(\a target, \a level, \a xoffset, \a yoffset, \a zoffset, \a width, \a height, \a depth, \a format, \a imageSize, \a data).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glCompressedTexSubImage3D.xml}{glCompressedTexSubImage3D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)      Convenience function that calls glCopyBufferSubData(\a readTarget, \a writeTarget, \a readOffset, \a writeOffset, \a size).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glCopyBufferSubData.xml}{glCopyBufferSubData()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)      Convenience function that calls glCopyTexSubImage3D(\a target, \a level, \a xoffset, \a yoffset, \a zoffset, \a x, \a y, \a width, \a height).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glCopyTexSubImage3D.xml}{glCopyTexSubImage3D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDeleteQueries(GLsizei n, const GLuint * ids)      Convenience function that calls glDeleteQueries(\a n, \a ids).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDeleteQueries.xml}{glDeleteQueries()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDeleteSamplers(GLsizei count, const GLuint * samplers)      Convenience function that calls glDeleteSamplers(\a count, \a samplers).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDeleteSamplers.xml}{glDeleteSamplers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDeleteSync(GLsync sync)      Convenience function that calls glDeleteSync(\a sync).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDeleteSync.xml}{glDeleteSync()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDeleteTransformFeedbacks(GLsizei n, const GLuint * ids)      Convenience function that calls glDeleteTransformFeedbacks(\a n, \a ids).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDeleteTransformFeedbacks.xml}{glDeleteTransformFeedbacks()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDeleteVertexArrays(GLsizei n, const GLuint * arrays)      Convenience function that calls glDeleteVertexArrays(\a n, \a arrays).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDeleteVertexArrays.xml}{glDeleteVertexArrays()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)      Convenience function that calls glDrawArraysInstanced(\a mode, \a first, \a count, \a instancecount).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDrawArraysInstanced.xml}{glDrawArraysInstanced()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDrawBuffers(GLsizei n, const GLenum * bufs)      Convenience function that calls glDrawBuffers(\a n, \a bufs).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDrawBuffers.xml}{glDrawBuffers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount)      Convenience function that calls glDrawElementsInstanced(\a mode, \a count, \a type, \a indices, \a instancecount).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDrawElementsInstanced.xml}{glDrawElementsInstanced()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices)      Convenience function that calls glDrawRangeElements(\a mode, \a start, \a end, \a count, \a type, \a indices).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDrawRangeElements.xml}{glDrawRangeElements()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glEndQuery(GLenum target)      Convenience function that calls glEndQuery(\a target).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glEndQuery.xml}{glEndQuery()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glEndTransformFeedback(void)      Convenience function that calls glEndTransformFeedback().      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glEndTransformFeedback.xml}{glEndTransformFeedback()}. */
end_comment
begin_comment
comment|/*!     \fn GLsync QOpenGLExtraFunctions::glFenceSync(GLenum condition, GLbitfield flags)      Convenience function that calls glFenceSync(\a condition, \a flags).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glFenceSync.xml}{glFenceSync()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)      Convenience function that calls glFlushMappedBufferRange(\a target, \a offset, \a length).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glFlushMappedBufferRange.xml}{glFlushMappedBufferRange()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)      Convenience function that calls glFramebufferTextureLayer(\a target, \a attachment, \a texture, \a level, \a layer).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glFramebufferTextureLayer.xml}{glFramebufferTextureLayer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGenQueries(GLsizei n, GLuint* ids)      Convenience function that calls glGenQueries(\a n, \a ids).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGenQueries.xml}{glGenQueries()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGenSamplers(GLsizei count, GLuint* samplers)      Convenience function that calls glGenSamplers(\a count, \a samplers).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGenSamplers.xml}{glGenSamplers()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGenTransformFeedbacks(GLsizei n, GLuint* ids)      Convenience function that calls glGenTransformFeedbacks(\a n, \a ids).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGenTransformFeedbacks.xml}{glGenTransformFeedbacks()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGenVertexArrays(GLsizei n, GLuint* arrays)      Convenience function that calls glGenVertexArrays(\a n, \a arrays).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGenVertexArrays.xml}{glGenVertexArrays()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName)      Convenience function that calls glGetActiveUniformBlockName(\a program, \a uniformBlockIndex, \a bufSize, \a length, \a uniformBlockName).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetActiveUniformBlockName.xml}{glGetActiveUniformBlockName()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params)      Convenience function that calls glGetActiveUniformBlockiv(\a program, \a uniformBlockIndex, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetActiveUniformBlockiv.xml}{glGetActiveUniformBlockiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint* params)      Convenience function that calls glGetActiveUniformsiv(\a program, \a uniformCount, \a uniformIndices, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetActiveUniformsiv.xml}{glGetActiveUniformsiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64* params)      Convenience function that calls glGetBufferParameteri64v(\a target, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetBufferParameteri64v.xml}{glGetBufferParameteri64v()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetBufferPointerv(GLenum target, GLenum pname, void ** params)      Convenience function that calls glGetBufferPointerv(\a target, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetBufferPointerv.xml}{glGetBufferPointerv()}. */
end_comment
begin_comment
comment|/*!     \fn GLint QOpenGLExtraFunctions::glGetFragDataLocation(GLuint program, const GLchar * name)      Convenience function that calls glGetFragDataLocation(\a program, \a name).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetFragDataLocation.xml}{glGetFragDataLocation()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetInteger64i_v(GLenum target, GLuint index, GLint64* data)      Convenience function that calls glGetInteger64i_v(\a target, \a index, \a data).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetInteger64i_v.xml}{glGetInteger64i_v()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetInteger64v(GLenum pname, GLint64* data)      Convenience function that calls glGetInteger64v(\a pname, \a data).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetInteger64v.xml}{glGetInteger64v()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetIntegeri_v(GLenum target, GLuint index, GLint* data)      Convenience function that calls glGetIntegeri_v(\a target, \a index, \a data).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetIntegeri_v.xml}{glGetIntegeri_v()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params)      Convenience function that calls glGetInternalformativ(\a target, \a internalformat, \a pname, \a bufSize, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetInternalformativ.xml}{glGetInternalformativ()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void * binary)      Convenience function that calls glGetProgramBinary(\a program, \a bufSize, \a length, \a binaryFormat, \a binary).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetProgramBinary.xml}{glGetProgramBinary()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint* params)      Convenience function that calls glGetQueryObjectuiv(\a id, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetQueryObjectuiv.xml}{glGetQueryObjectuiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetQueryiv(GLenum target, GLenum pname, GLint* params)      Convenience function that calls glGetQueryiv(\a target, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetQueryiv.xml}{glGetQueryiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat* params)      Convenience function that calls glGetSamplerParameterfv(\a sampler, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetSamplerParameterfv.xml}{glGetSamplerParameterfv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint* params)      Convenience function that calls glGetSamplerParameteriv(\a sampler, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetSamplerParameteriv.xml}{glGetSamplerParameteriv()}. */
end_comment
begin_comment
comment|/*!     \fn const GLubyte * QOpenGLExtraFunctions::glGetStringi(GLenum name, GLuint index)      Convenience function that calls glGetStringi(\a name, \a index).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetStringi.xml}{glGetStringi()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values)      Convenience function that calls glGetSynciv(\a sync, \a pname, \a bufSize, \a length, \a values).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetSynciv.xml}{glGetSynciv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name)      Convenience function that calls glGetTransformFeedbackVarying(\a program, \a index, \a bufSize, \a length, \a size, \a type, \a name).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetTransformFeedbackVarying.xml}{glGetTransformFeedbackVarying()}. */
end_comment
begin_comment
comment|/*!     \fn GLuint QOpenGLExtraFunctions::glGetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName)      Convenience function that calls glGetUniformBlockIndex(\a program, \a uniformBlockName).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetUniformBlockIndex.xml}{glGetUniformBlockIndex()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint* uniformIndices)      Convenience function that calls glGetUniformIndices(\a program, \a uniformCount, \a uniformNames, \a uniformIndices).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetUniformIndices.xml}{glGetUniformIndices()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetUniformuiv(GLuint program, GLint location, GLuint* params)      Convenience function that calls glGetUniformuiv(\a program, \a location, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetUniformuiv.xml}{glGetUniformuiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetVertexAttribIiv(GLuint index, GLenum pname, GLint* params)      Convenience function that calls glGetVertexAttribIiv(\a index, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetVertexAttribIiv.xml}{glGetVertexAttribIiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint* params)      Convenience function that calls glGetVertexAttribIuiv(\a index, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetVertexAttribIuiv.xml}{glGetVertexAttribIuiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments)      Convenience function that calls glInvalidateFramebuffer(\a target, \a numAttachments, \a attachments).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glInvalidateFramebuffer.xml}{glInvalidateFramebuffer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height)      Convenience function that calls glInvalidateSubFramebuffer(\a target, \a numAttachments, \a attachments, \a x, \a y, \a width, \a height).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glInvalidateSubFramebuffer.xml}{glInvalidateSubFramebuffer()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLExtraFunctions::glIsQuery(GLuint id)      Convenience function that calls glIsQuery(\a id).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glIsQuery.xml}{glIsQuery()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLExtraFunctions::glIsSampler(GLuint sampler)      Convenience function that calls glIsSampler(\a sampler).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glIsSampler.xml}{glIsSampler()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLExtraFunctions::glIsSync(GLsync sync)      Convenience function that calls glIsSync(\a sync).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glIsSync.xml}{glIsSync()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLExtraFunctions::glIsTransformFeedback(GLuint id)      Convenience function that calls glIsTransformFeedback(\a id).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glIsTransformFeedback.xml}{glIsTransformFeedback()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLExtraFunctions::glIsVertexArray(GLuint array)      Convenience function that calls glIsVertexArray(\a array).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glIsVertexArray.xml}{glIsVertexArray()}. */
end_comment
begin_comment
comment|/*!     \fn void * QOpenGLExtraFunctions::glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)      Convenience function that calls glMapBufferRange(\a target, \a offset, \a length, \a access).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glMapBufferRange.xml}{glMapBufferRange()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glPauseTransformFeedback(void)      Convenience function that calls glPauseTransformFeedback().      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glPauseTransformFeedback.xml}{glPauseTransformFeedback()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length)      Convenience function that calls glProgramBinary(\a program, \a binaryFormat, \a binary, \a length).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramBinary.xml}{glProgramBinary()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramParameteri(GLuint program, GLenum pname, GLint value)      Convenience function that calls glProgramParameteri(\a program, \a pname, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramParameteri.xml}{glProgramParameteri()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glReadBuffer(GLenum src)      Convenience function that calls glReadBuffer(\a src).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glReadBuffer.xml}{glReadBuffer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)      Convenience function that calls glRenderbufferStorageMultisample(\a target, \a samples, \a internalformat, \a width, \a height).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glRenderbufferStorageMultisample.xml}{glRenderbufferStorageMultisample()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glResumeTransformFeedback(void)      Convenience function that calls glResumeTransformFeedback().      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glResumeTransformFeedback.xml}{glResumeTransformFeedback()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)      Convenience function that calls glSamplerParameterf(\a sampler, \a pname, \a param).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glSamplerParameterf.xml}{glSamplerParameterf()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * param)      Convenience function that calls glSamplerParameterfv(\a sampler, \a pname, \a param).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glSamplerParameterfv.xml}{glSamplerParameterfv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)      Convenience function that calls glSamplerParameteri(\a sampler, \a pname, \a param).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glSamplerParameteri.xml}{glSamplerParameteri()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * param)      Convenience function that calls glSamplerParameteriv(\a sampler, \a pname, \a param).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glSamplerParameteriv.xml}{glSamplerParameteriv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels)      Convenience function that calls glTexImage3D(\a target, \a level, \a internalformat, \a width, \a height, \a depth, \a border, \a format, \a type, \a pixels).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glTexImage3D.xml}{glTexImage3D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)      Convenience function that calls glTexStorage2D(\a target, \a levels, \a internalformat, \a width, \a height).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glTexStorage2D.xml}{glTexStorage2D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)      Convenience function that calls glTexStorage3D(\a target, \a levels, \a internalformat, \a width, \a height, \a depth).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glTexStorage3D.xml}{glTexStorage3D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels)      Convenience function that calls glTexSubImage3D(\a target, \a level, \a xoffset, \a yoffset, \a zoffset, \a width, \a height, \a depth, \a format, \a type, \a pixels).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glTexSubImage3D.xml}{glTexSubImage3D()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode)      Convenience function that calls glTransformFeedbackVaryings(\a program, \a count, \a varyings, \a bufferMode).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glTransformFeedbackVaryings.xml}{glTransformFeedbackVaryings()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniform1ui(GLint location, GLuint v0)      Convenience function that calls glUniform1ui(\a location, \a v0).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniform1ui.xml}{glUniform1ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniform1uiv(GLint location, GLsizei count, const GLuint * value)      Convenience function that calls glUniform1uiv(\a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniform1uiv.xml}{glUniform1uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniform2ui(GLint location, GLuint v0, GLuint v1)      Convenience function that calls glUniform2ui(\a location, \a v0, \a v1).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniform2ui.xml}{glUniform2ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniform2uiv(GLint location, GLsizei count, const GLuint * value)      Convenience function that calls glUniform2uiv(\a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniform2uiv.xml}{glUniform2uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)      Convenience function that calls glUniform3ui(\a location, \a v0, \a v1, \a v2).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniform3ui.xml}{glUniform3ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniform3uiv(GLint location, GLsizei count, const GLuint * value)      Convenience function that calls glUniform3uiv(\a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniform3uiv.xml}{glUniform3uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)      Convenience function that calls glUniform4ui(\a location, \a v0, \a v1, \a v2, \a v3).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniform4ui.xml}{glUniform4ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniform4uiv(GLint location, GLsizei count, const GLuint * value)      Convenience function that calls glUniform4uiv(\a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniform4uiv.xml}{glUniform4uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)      Convenience function that calls glUniformBlockBinding(\a program, \a uniformBlockIndex, \a uniformBlockBinding).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniformBlockBinding.xml}{glUniformBlockBinding()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glUniformMatrix2x3fv(\a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniformMatrix2x3fv.xml}{glUniformMatrix2x3fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glUniformMatrix2x4fv(\a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniformMatrix2x4fv.xml}{glUniformMatrix2x4fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glUniformMatrix3x2fv(\a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniformMatrix3x2fv.xml}{glUniformMatrix3x2fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glUniformMatrix3x4fv(\a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniformMatrix3x4fv.xml}{glUniformMatrix3x4fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glUniformMatrix4x2fv(\a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniformMatrix4x2fv.xml}{glUniformMatrix4x2fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glUniformMatrix4x3fv(\a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUniformMatrix4x3fv.xml}{glUniformMatrix4x3fv()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLExtraFunctions::glUnmapBuffer(GLenum target)      Convenience function that calls glUnmapBuffer(\a target).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUnmapBuffer.xml}{glUnmapBuffer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribDivisor(GLuint index, GLuint divisor)      Convenience function that calls glVertexAttribDivisor(\a index, \a divisor).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribDivisor.xml}{glVertexAttribDivisor()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)      Convenience function that calls glVertexAttribI4i(\a index, \a x, \a y, \a z, \a w).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribI4i.xml}{glVertexAttribI4i()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribI4iv(GLuint index, const GLint * v)      Convenience function that calls glVertexAttribI4iv(\a index, \a v).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribI4iv.xml}{glVertexAttribI4iv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)      Convenience function that calls glVertexAttribI4ui(\a index, \a x, \a y, \a z, \a w).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribI4ui.xml}{glVertexAttribI4ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribI4uiv(GLuint index, const GLuint * v)      Convenience function that calls glVertexAttribI4uiv(\a index, \a v).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribI4uiv.xml}{glVertexAttribI4uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer)      Convenience function that calls glVertexAttribIPointer(\a index, \a size, \a type, \a stride, \a pointer).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribIPointer.xml}{glVertexAttribIPointer()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)      Convenience function that calls glWaitSync(\a sync, \a flags, \a timeout).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glWaitSync.xml}{glWaitSync()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glActiveShaderProgram(GLuint pipeline, GLuint program)      Convenience function that calls glActiveShaderProgram(\a pipeline, \a program).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glActiveShaderProgram.xml}{glActiveShaderProgram()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)      Convenience function that calls glBindImageTexture(\a unit, \a texture, \a level, \a layered, \a layer, \a access, \a format).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBindImageTexture.xml}{glBindImageTexture()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBindProgramPipeline(GLuint pipeline)      Convenience function that calls glBindProgramPipeline(\a pipeline).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBindProgramPipeline.xml}{glBindProgramPipeline()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)      Convenience function that calls glBindVertexBuffer(\a bindingindex, \a buffer, \a offset, \a stride).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glBindVertexBuffer.xml}{glBindVertexBuffer()}. */
end_comment
begin_comment
comment|/*!     \fn GLuint QOpenGLExtraFunctions::glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const* strings)      Convenience function that calls glCreateShaderProgramv(\a type, \a count, \a strings).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glCreateShaderProgramv.xml}{glCreateShaderProgramv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDeleteProgramPipelines(GLsizei n, const GLuint * pipelines)      Convenience function that calls glDeleteProgramPipelines(\a n, \a pipelines).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDeleteProgramPipelines.xml}{glDeleteProgramPipelines()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)      Convenience function that calls glDispatchCompute(\a num_groups_x, \a num_groups_y, \a num_groups_z).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDispatchCompute.xml}{glDispatchCompute()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDispatchComputeIndirect(GLintptr indirect)      Convenience function that calls glDispatchComputeIndirect(\a indirect).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDispatchComputeIndirect.xml}{glDispatchComputeIndirect()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDrawArraysIndirect(GLenum mode, const void * indirect)      Convenience function that calls glDrawArraysIndirect(\a mode, \a indirect).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDrawArraysIndirect.xml}{glDrawArraysIndirect()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect)      Convenience function that calls glDrawElementsIndirect(\a mode, \a type, \a indirect).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glDrawElementsIndirect.xml}{glDrawElementsIndirect()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glFramebufferParameteri(GLenum target, GLenum pname, GLint param)      Convenience function that calls glFramebufferParameteri(\a target, \a pname, \a param).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glFramebufferParameteri.xml}{glFramebufferParameteri()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGenProgramPipelines(GLsizei n, GLuint* pipelines)      Convenience function that calls glGenProgramPipelines(\a n, \a pipelines).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGenProgramPipelines.xml}{glGenProgramPipelines()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetBooleani_v(GLenum target, GLuint index, GLboolean* data)      Convenience function that calls glGetBooleani_v(\a target, \a index, \a data).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetBooleani_v.xml}{glGetBooleani_v()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint* params)      Convenience function that calls glGetFramebufferParameteriv(\a target, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetFramebufferParameteriv.xml}{glGetFramebufferParameteriv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetMultisamplefv(GLenum pname, GLuint index, GLfloat* val)      Convenience function that calls glGetMultisamplefv(\a pname, \a index, \a val).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetMultisamplefv.xml}{glGetMultisamplefv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint* params)      Convenience function that calls glGetProgramInterfaceiv(\a program, \a programInterface, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetProgramInterfaceiv.xml}{glGetProgramInterfaceiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog)      Convenience function that calls glGetProgramPipelineInfoLog(\a pipeline, \a bufSize, \a length, \a infoLog).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetProgramPipelineInfoLog.xml}{glGetProgramPipelineInfoLog()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint* params)      Convenience function that calls glGetProgramPipelineiv(\a pipeline, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetProgramPipelineiv.xml}{glGetProgramPipelineiv()}. */
end_comment
begin_comment
comment|/*!     \fn GLuint QOpenGLExtraFunctions::glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name)      Convenience function that calls glGetProgramResourceIndex(\a program, \a programInterface, \a name).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetProgramResourceIndex.xml}{glGetProgramResourceIndex()}. */
end_comment
begin_comment
comment|/*!     \fn GLint QOpenGLExtraFunctions::glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name)      Convenience function that calls glGetProgramResourceLocation(\a program, \a programInterface, \a name).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetProgramResourceLocation.xml}{glGetProgramResourceLocation()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name)      Convenience function that calls glGetProgramResourceName(\a program, \a programInterface, \a index, \a bufSize, \a length, \a name).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetProgramResourceName.xml}{glGetProgramResourceName()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei* length, GLint* params)      Convenience function that calls glGetProgramResourceiv(\a program, \a programInterface, \a index, \a propCount, \a props, \a bufSize, \a length, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetProgramResourceiv.xml}{glGetProgramResourceiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params)      Convenience function that calls glGetTexLevelParameterfv(\a target, \a level, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetTexLevelParameterfv.xml}{glGetTexLevelParameterfv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params)      Convenience function that calls glGetTexLevelParameteriv(\a target, \a level, \a pname, \a params).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glGetTexLevelParameteriv.xml}{glGetTexLevelParameteriv()}. */
end_comment
begin_comment
comment|/*!     \fn GLboolean QOpenGLExtraFunctions::glIsProgramPipeline(GLuint pipeline)      Convenience function that calls glIsProgramPipeline(\a pipeline).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glIsProgramPipeline.xml}{glIsProgramPipeline()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glMemoryBarrier(GLbitfield barriers)      Convenience function that calls glMemoryBarrier(\a barriers).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glMemoryBarrier.xml}{glMemoryBarrier()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glMemoryBarrierByRegion(GLbitfield barriers)      Convenience function that calls glMemoryBarrierByRegion(\a barriers).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glMemoryBarrierByRegion.xml}{glMemoryBarrierByRegion()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform1f(GLuint program, GLint location, GLfloat v0)      Convenience function that calls glProgramUniform1f(\a program, \a location, \a v0).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform1f.xml}{glProgramUniform1f()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat * value)      Convenience function that calls glProgramUniform1fv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform1fv.xml}{glProgramUniform1fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform1i(GLuint program, GLint location, GLint v0)      Convenience function that calls glProgramUniform1i(\a program, \a location, \a v0).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform1i.xml}{glProgramUniform1i()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint * value)      Convenience function that calls glProgramUniform1iv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform1iv.xml}{glProgramUniform1iv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform1ui(GLuint program, GLint location, GLuint v0)      Convenience function that calls glProgramUniform1ui(\a program, \a location, \a v0).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform1ui.xml}{glProgramUniform1ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint * value)      Convenience function that calls glProgramUniform1uiv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform1uiv.xml}{glProgramUniform1uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1)      Convenience function that calls glProgramUniform2f(\a program, \a location, \a v0, \a v1).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform2f.xml}{glProgramUniform2f()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat * value)      Convenience function that calls glProgramUniform2fv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform2fv.xml}{glProgramUniform2fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1)      Convenience function that calls glProgramUniform2i(\a program, \a location, \a v0, \a v1).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform2i.xml}{glProgramUniform2i()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint * value)      Convenience function that calls glProgramUniform2iv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform2iv.xml}{glProgramUniform2iv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1)      Convenience function that calls glProgramUniform2ui(\a program, \a location, \a v0, \a v1).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform2ui.xml}{glProgramUniform2ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint * value)      Convenience function that calls glProgramUniform2uiv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform2uiv.xml}{glProgramUniform2uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)      Convenience function that calls glProgramUniform3f(\a program, \a location, \a v0, \a v1, \a v2).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform3f.xml}{glProgramUniform3f()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat * value)      Convenience function that calls glProgramUniform3fv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform3fv.xml}{glProgramUniform3fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)      Convenience function that calls glProgramUniform3i(\a program, \a location, \a v0, \a v1, \a v2).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform3i.xml}{glProgramUniform3i()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint * value)      Convenience function that calls glProgramUniform3iv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform3iv.xml}{glProgramUniform3iv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)      Convenience function that calls glProgramUniform3ui(\a program, \a location, \a v0, \a v1, \a v2).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform3ui.xml}{glProgramUniform3ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint * value)      Convenience function that calls glProgramUniform3uiv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform3uiv.xml}{glProgramUniform3uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)      Convenience function that calls glProgramUniform4f(\a program, \a location, \a v0, \a v1, \a v2, \a v3).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform4f.xml}{glProgramUniform4f()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat * value)      Convenience function that calls glProgramUniform4fv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform4fv.xml}{glProgramUniform4fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)      Convenience function that calls glProgramUniform4i(\a program, \a location, \a v0, \a v1, \a v2, \a v3).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform4i.xml}{glProgramUniform4i()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint * value)      Convenience function that calls glProgramUniform4iv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform4iv.xml}{glProgramUniform4iv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)      Convenience function that calls glProgramUniform4ui(\a program, \a location, \a v0, \a v1, \a v2, \a v3).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform4ui.xml}{glProgramUniform4ui()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint * value)      Convenience function that calls glProgramUniform4uiv(\a program, \a location, \a count, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniform4uiv.xml}{glProgramUniform4uiv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix2fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix2fv.xml}{glProgramUniformMatrix2fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix2x3fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix2x3fv.xml}{glProgramUniformMatrix2x3fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix2x4fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix2x4fv.xml}{glProgramUniformMatrix2x4fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix3fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix3fv.xml}{glProgramUniformMatrix3fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix3x2fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix3x2fv.xml}{glProgramUniformMatrix3x2fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix3x4fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix3x4fv.xml}{glProgramUniformMatrix3x4fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix4fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix4fv.xml}{glProgramUniformMatrix4fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix4x2fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix4x2fv.xml}{glProgramUniformMatrix4x2fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)      Convenience function that calls glProgramUniformMatrix4x3fv(\a program, \a location, \a count, \a transpose, \a value).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glProgramUniformMatrix4x3fv.xml}{glProgramUniformMatrix4x3fv()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glSampleMaski(GLuint maskNumber, GLbitfield mask)      Convenience function that calls glSampleMaski(\a maskNumber, \a mask).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glSampleMaski.xml}{glSampleMaski()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)      Convenience function that calls glTexStorage2DMultisample(\a target, \a samples, \a internalformat, \a width, \a height, \a fixedsamplelocations).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glTexStorage2DMultisample.xml}{glTexStorage2DMultisample()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)      Convenience function that calls glUseProgramStages(\a pipeline, \a stages, \a program).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glUseProgramStages.xml}{glUseProgramStages()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glValidateProgramPipeline(GLuint pipeline)      Convenience function that calls glValidateProgramPipeline(\a pipeline).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glValidateProgramPipeline.xml}{glValidateProgramPipeline()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribBinding(GLuint attribindex, GLuint bindingindex)      Convenience function that calls glVertexAttribBinding(\a attribindex, \a bindingindex).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribBinding.xml}{glVertexAttribBinding()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)      Convenience function that calls glVertexAttribFormat(\a attribindex, \a size, \a type, \a normalized, \a relativeoffset).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribFormat.xml}{glVertexAttribFormat()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)      Convenience function that calls glVertexAttribIFormat(\a attribindex, \a size, \a type, \a relativeoffset).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexAttribIFormat.xml}{glVertexAttribIFormat()}. */
end_comment
begin_comment
comment|/*!     \fn void QOpenGLExtraFunctions::glVertexBindingDivisor(GLuint bindingindex, GLuint divisor)      Convenience function that calls glVertexBindingDivisor(\a bindingindex, \a divisor).      This function is only available in OpenGL ES 3.x, or OpenGL 3.x or 4.x contexts. When running     with plain OpenGL, the function is only usable when the given profile and version contains the     function either in core or as an extension.      For more information, see the OpenGL ES 3.x documentation for     \l{http://www.khronos.org/opengles/sdk/docs/man31/glVertexBindingDivisor.xml}{glVertexBindingDivisor()}. */
end_comment
begin_comment
comment|/*!     \fn bool QOpenGLExtraFunctions::isInitialized(const QOpenGLExtraFunctionsPrivate *d)     \internal */
end_comment
begin_comment
comment|/*!     Constructs a default function resolver. The resolver cannot be used until     \l {QOpenGLFunctions::}{initializeOpenGLFunctions()} is called to specify     the context. */
end_comment
begin_constructor
DECL|function|QOpenGLExtraFunctions
name|QOpenGLExtraFunctions
operator|::
name|QOpenGLExtraFunctions
parameter_list|()
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a function resolver for context. If \a context is null, then     the resolver will be created for the current QOpenGLContext.      The context or another context in the group must be current.      An object constructed in this way can only be used with context and other     contexts that share with it. Use \l {QOpenGLFunctions::}     {initializeOpenGLFunctions()} to change the object's context association. */
end_comment
begin_constructor
DECL|function|QOpenGLExtraFunctions
name|QOpenGLExtraFunctions
operator|::
name|QOpenGLExtraFunctions
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
member_init_list|:
name|QOpenGLFunctions
argument_list|(
name|context
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QOpenGLExtraFunctionsPrivate
name|QOpenGLExtraFunctionsPrivate
operator|::
name|QOpenGLExtraFunctionsPrivate
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|)
member_init_list|:
name|QOpenGLFunctionsPrivate
argument_list|(
name|ctx
argument_list|)
block|{
name|init
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_macro
name|QT_OPENGL_IMPLEMENT
argument_list|(
argument|QOpenGLExtraFunctionsPrivate
argument_list|,
argument|QT_OPENGL_EXTRA_FUNCTIONS
argument_list|)
end_macro
begin_constructor
DECL|function|QOpenGLExtensionsPrivate
name|QOpenGLExtensionsPrivate
operator|::
name|QOpenGLExtensionsPrivate
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|)
member_init_list|:
name|QOpenGLExtraFunctionsPrivate
argument_list|(
name|ctx
argument_list|)
member_init_list|,
name|flushVendorChecked
argument_list|(
literal|false
argument_list|)
block|{
name|QOpenGLContext
modifier|*
name|context
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
name|MapBuffer
operator|=
name|RESOLVE
argument_list|(
name|MapBuffer
argument_list|)
expr_stmt|;
name|GetBufferSubData
operator|=
name|RESOLVE
argument_list|(
name|GetBufferSubData
argument_list|)
expr_stmt|;
name|DiscardFramebuffer
operator|=
name|RESOLVE
argument_list|(
name|DiscardFramebuffer
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|flushShared
name|void
name|QOpenGLExtensions
operator|::
name|flushShared
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QOpenGLExtensions
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|flushVendorChecked
condition|)
block|{
name|d
operator|->
name|flushVendorChecked
operator|=
literal|true
expr_stmt|;
comment|// It is not quite clear if glFlush() is sufficient to synchronize access to
comment|// resources between sharing contexts in the same thread. On most platforms this
comment|// is enough (e.g. iOS explicitly documents it), while certain drivers only work
comment|// properly when doing glFinish().
name|d
operator|->
name|flushIsSufficientToSyncContexts
operator|=
literal|false
expr_stmt|;
comment|// default to false, not guaranteed by the spec
specifier|const
name|char
modifier|*
name|vendor
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_VENDOR
argument_list|)
decl_stmt|;
if|if
condition|(
name|vendor
condition|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|flushEnough
index|[]
init|=
block|{
literal|"Apple"
block|,
literal|"ATI"
block|,
literal|"Intel"
block|,
literal|"NVIDIA"
block|}
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|flushEnough
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|strstr
argument_list|(
name|vendor
argument_list|,
name|flushEnough
index|[
name|i
index|]
argument_list|)
condition|)
block|{
name|d
operator|->
name|flushIsSufficientToSyncContexts
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
if|if
condition|(
name|d
operator|->
name|flushIsSufficientToSyncContexts
condition|)
name|glFlush
argument_list|()
expr_stmt|;
else|else
name|glFinish
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
