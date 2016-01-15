begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qglfunctions.h>
end_include
begin_class
DECL|class|tst_QGLFunctions
class|class
name|tst_QGLFunctions
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QGLFunctions
name|tst_QGLFunctions
parameter_list|()
block|{}
DECL|function|~tst_QGLFunctions
name|~
name|tst_QGLFunctions
parameter_list|()
block|{}
private|private
name|slots
private|:
name|void
name|features
parameter_list|()
function_decl|;
name|void
name|multitexture
parameter_list|()
function_decl|;
name|void
name|blendColor
parameter_list|()
function_decl|;
private|private:
specifier|static
name|bool
name|hasExtension
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|hasExtension
name|bool
name|tst_QGLFunctions
operator|::
name|hasExtension
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|QString
name|extensions
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glGetString
argument_list|(
name|GL_EXTENSIONS
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|extensions
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
operator|.
name|contains
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|name
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// Check that the reported features are consistent with the platform.
end_comment
begin_function
DECL|function|features
name|void
name|tst_QGLFunctions
operator|::
name|features
parameter_list|()
block|{
comment|// Before being associated with a context, there should be
comment|// no features enabled.
name|QGLFunctions
name|funcs
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|openGLFeatures
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Multitexture
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Shaders
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Buffers
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Framebuffers
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendColor
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendEquation
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendEquationSeparate
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendFuncSeparate
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendSubtract
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|CompressedTextures
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Multisample
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|StencilSeparate
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|NPOTTextures
argument_list|)
argument_list|)
expr_stmt|;
comment|// Make a context current.
name|QGLWidget
name|glw
decl_stmt|;
if|if
condition|(
operator|!
name|glw
operator|.
name|isValid
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Could not create a GL context"
argument_list|)
expr_stmt|;
name|glw
operator|.
name|makeCurrent
argument_list|()
expr_stmt|;
name|funcs
operator|.
name|initializeGLFunctions
argument_list|()
expr_stmt|;
comment|// Validate the features against what we expect for this platform.
if|if
condition|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
name|QGLFunctions
operator|::
name|OpenGLFeatures
name|allFeatures
init|=
operator|(
name|QGLFunctions
operator|::
name|Multitexture
operator||
name|QGLFunctions
operator|::
name|Shaders
operator||
name|QGLFunctions
operator|::
name|Buffers
operator||
name|QGLFunctions
operator|::
name|Framebuffers
operator||
name|QGLFunctions
operator|::
name|BlendColor
operator||
name|QGLFunctions
operator|::
name|BlendEquation
operator||
name|QGLFunctions
operator|::
name|BlendEquationSeparate
operator||
name|QGLFunctions
operator|::
name|BlendFuncSeparate
operator||
name|QGLFunctions
operator|::
name|BlendSubtract
operator||
name|QGLFunctions
operator|::
name|CompressedTextures
operator||
name|QGLFunctions
operator|::
name|Multisample
operator||
name|QGLFunctions
operator|::
name|StencilSeparate
operator||
name|QGLFunctions
operator|::
name|NPOTTextures
operator|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|(
name|funcs
operator|.
name|openGLFeatures
argument_list|()
operator|&
name|allFeatures
operator|)
operator|==
name|allFeatures
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Multitexture
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Shaders
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Buffers
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Framebuffers
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendColor
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendEquation
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendEquationSeparate
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendFuncSeparate
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendSubtract
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|CompressedTextures
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Multisample
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|StencilSeparate
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|NPOTTextures
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|QT_OPENGL_ES
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Multitexture
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Buffers
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|CompressedTextures
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Multisample
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Shaders
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendColor
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|StencilSeparate
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Framebuffers
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_OES_framebuffer_object"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendEquationSeparate
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_OES_blend_equation_separate"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendFuncSeparate
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_OES_blend_func_separate"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendSubtract
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_OES_blend_subtract"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|NPOTTextures
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_OES_texture_npot"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
comment|// We check for both the extension name and the minimum OpenGL version
comment|// for the feature.  This will help us catch situations where a platform
comment|// doesn't list an extension by name but does have the feature by virtue
comment|// of its version number.
name|QGLFormat
operator|::
name|OpenGLVersionFlags
name|versions
init|=
name|QGLFormat
operator|::
name|openGLVersionFlags
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Multitexture
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_ARB_multitexture"
argument_list|)
operator|||
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_1_3
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Shaders
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_ARB_shader_objects"
argument_list|)
operator|||
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_2_0
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Buffers
argument_list|)
argument_list|,
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_1_5
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Framebuffers
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_EXT_framebuffer_object"
argument_list|)
operator|||
name|hasExtension
argument_list|(
literal|"GL_ARB_framebuffer_object"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendColor
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_EXT_blend_color"
argument_list|)
operator|||
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_1_2
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendEquation
argument_list|)
argument_list|,
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_1_2
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendEquationSeparate
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_EXT_blend_equation_separate"
argument_list|)
operator|||
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_2_0
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendFuncSeparate
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_EXT_blend_func_separate"
argument_list|)
operator|||
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_1_4
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|BlendSubtract
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_EXT_blend_subtract"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|CompressedTextures
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_ARB_texture_compression"
argument_list|)
operator|||
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_1_3
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|Multisample
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_ARB_multisample"
argument_list|)
operator|||
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_1_3
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|StencilSeparate
argument_list|)
argument_list|,
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_2_0
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QGLFunctions
operator|::
name|NPOTTextures
argument_list|)
argument_list|,
name|hasExtension
argument_list|(
literal|"GL_ARB_texture_non_power_of_two"
argument_list|)
operator|||
operator|(
name|versions
operator|&
name|QGLFormat
operator|::
name|OpenGL_Version_2_0
operator|)
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// Verify that the multitexture functions appear to resolve and work.
end_comment
begin_function
DECL|function|multitexture
name|void
name|tst_QGLFunctions
operator|::
name|multitexture
parameter_list|()
block|{
name|QOpenGLFunctions
name|funcs
decl_stmt|;
name|QGLWidget
name|glw
decl_stmt|;
if|if
condition|(
operator|!
name|glw
operator|.
name|isValid
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Could not create a GL context"
argument_list|)
expr_stmt|;
name|glw
operator|.
name|makeCurrent
argument_list|()
expr_stmt|;
name|funcs
operator|.
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QOpenGLFunctions
operator|::
name|Multitexture
argument_list|)
condition|)
name|QSKIP
argument_list|(
literal|"Multitexture functions are not supported"
argument_list|)
expr_stmt|;
name|funcs
operator|.
name|glActiveTexture
argument_list|(
name|GL_TEXTURE1
argument_list|)
expr_stmt|;
name|GLint
name|active
init|=
literal|0
decl_stmt|;
name|funcs
operator|.
name|glGetIntegerv
argument_list|(
name|GL_ACTIVE_TEXTURE
argument_list|,
operator|&
name|active
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|active
argument_list|,
name|GL_TEXTURE1
argument_list|)
expr_stmt|;
name|funcs
operator|.
name|glActiveTexture
argument_list|(
name|GL_TEXTURE0
argument_list|)
expr_stmt|;
name|active
operator|=
literal|0
expr_stmt|;
name|funcs
operator|.
name|glGetIntegerv
argument_list|(
name|GL_ACTIVE_TEXTURE
argument_list|,
operator|&
name|active
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|active
argument_list|,
name|GL_TEXTURE0
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Verify that the glBlendColor() function appears to resolve and work.
end_comment
begin_function
DECL|function|blendColor
name|void
name|tst_QGLFunctions
operator|::
name|blendColor
parameter_list|()
block|{
name|QOpenGLFunctions
name|funcs
decl_stmt|;
name|QGLWidget
name|glw
decl_stmt|;
if|if
condition|(
operator|!
name|glw
operator|.
name|isValid
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Could not create a GL context"
argument_list|)
expr_stmt|;
name|glw
operator|.
name|makeCurrent
argument_list|()
expr_stmt|;
name|funcs
operator|.
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|funcs
operator|.
name|hasOpenGLFeature
argument_list|(
name|QOpenGLFunctions
operator|::
name|BlendColor
argument_list|)
condition|)
name|QSKIP
argument_list|(
literal|"glBlendColor() is not supported"
argument_list|)
expr_stmt|;
name|funcs
operator|.
name|glBlendColor
argument_list|(
literal|0.0f
argument_list|,
literal|1.0f
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|GLfloat
name|colors
index|[
literal|4
index|]
init|=
block|{
literal|0.5f
block|,
literal|0.5f
block|,
literal|0.5f
block|,
literal|0.5f
block|}
decl_stmt|;
name|funcs
operator|.
name|glGetFloatv
argument_list|(
name|GL_BLEND_COLOR
argument_list|,
name|colors
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|colors
index|[
literal|0
index|]
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|colors
index|[
literal|1
index|]
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|colors
index|[
literal|2
index|]
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|colors
index|[
literal|3
index|]
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGLFunctions
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qglfunctions.moc"
end_include
end_unit
