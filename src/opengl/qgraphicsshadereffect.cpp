begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgraphicsshadereffect_p.h"
end_include
begin_include
include|#
directive|include
file|"qglshaderprogram.h"
end_include
begin_include
include|#
directive|include
file|"gl2paintengineex/qglcustomshaderstage_p.h"
end_include
begin_define
DECL|macro|QGL_HAVE_CUSTOM_SHADERS
define|#
directive|define
name|QGL_HAVE_CUSTOM_SHADERS
value|1
end_define
begin_include
include|#
directive|include
file|<QtGui/qpainter.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicsitem.h>
end_include
begin_include
include|#
directive|include
file|<private/qgraphicseffect_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*#     \class QGraphicsShaderEffect     \brief The QGraphicsShaderEffect class is the base class for creating     custom GLSL shader effects in a QGraphicsScene.     \since 4.6     \ingroup multimedia     \ingroup graphicsview-api      The specific effect is defined by a fragment of GLSL source code     supplied to setPixelShaderFragment().  This source code must define a     function with the signature     \c{lowp vec4 customShader(lowp sampler2D imageTexture, highp vec2 textureCoords)}     that returns the source pixel value     to use in the paint engine's shader program.  The shader fragment     is linked with the regular shader code used by the GL2 paint engine     to construct a complete QGLShaderProgram.      The following example shader converts the incoming pixmap to     grayscale and then applies a colorize operation using the     \c effectColor value:      \code     static char const colorizeShaderCode[] =         "uniform lowp vec4 effectColor;\n"         "lowp vec4 customShader(lowp sampler2D imageTexture, highp vec2 textureCoords) {\n"         "    vec4 src = texture2D(imageTexture, textureCoords);\n"         "    float gray = dot(src.rgb, vec3(0.212671, 0.715160, 0.072169));\n"         "    vec4 colorize = 1.0-((1.0-gray)*(1.0-effectColor));\n"         "    return vec4(colorize.rgb, src.a);\n"         "}";     \endcode      To use this shader code, it is necessary to define a subclass     of QGraphicsShaderEffect as follows:      \code     class ColorizeEffect : public QGraphicsShaderEffect     {         Q_OBJECT     public:         ColorizeEffect(QObject *parent = 0)             : QGraphicsShaderEffect(parent), color(Qt::black)         {             setPixelShaderFragment(colorizeShaderCode);         }          QColor effectColor() const { return color; }         void setEffectColor(const QColor& c)         {             color = c;             setUniformsDirty();         }      protected:         void setUniforms(QGLShaderProgram *program)         {             program->setUniformValue("effectColor", color);         }      private:         QColor color;     };     \endcode      The setUniforms() function is called when the effect is about     to be used for drawing to give the subclass the opportunity to     set effect-specific uniform variables.      QGraphicsShaderEffect is only supported when the GL2 paint engine     is in use.  When any other paint engine is in use (GL1, raster, etc),     the drawItem() method will draw its item argument directly with     no effect applied.      \sa QGraphicsEffect */
DECL|variable|qglslDefaultImageFragmentShader
specifier|static
specifier|const
name|char
name|qglslDefaultImageFragmentShader
index|[]
init|=
literal|"\     lowp vec4 customShader(lowp sampler2D imageTexture, highp vec2 textureCoords) { \         return texture2D(imageTexture, textureCoords); \     }\n"
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QGL_HAVE_CUSTOM_SHADERS
end_ifdef
begin_class
DECL|class|QGLCustomShaderEffectStage
class|class
name|QGLCustomShaderEffectStage
super|:
specifier|public
name|QGLCustomShaderStage
block|{
public|public:
DECL|function|QGLCustomShaderEffectStage
name|QGLCustomShaderEffectStage
parameter_list|(
name|QGraphicsShaderEffect
modifier|*
name|e
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|source
parameter_list|)
member_init_list|:
name|QGLCustomShaderStage
argument_list|()
member_init_list|,
name|effect
argument_list|(
name|e
argument_list|)
block|{
name|setSource
argument_list|(
name|source
argument_list|)
expr_stmt|;
block|}
name|void
name|setUniforms
parameter_list|(
name|QGLShaderProgram
modifier|*
name|program
parameter_list|)
function_decl|;
DECL|member|effect
name|QGraphicsShaderEffect
modifier|*
name|effect
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|setUniforms
name|void
name|QGLCustomShaderEffectStage
operator|::
name|setUniforms
parameter_list|(
name|QGLShaderProgram
modifier|*
name|program
parameter_list|)
block|{
name|effect
operator|->
name|setUniforms
argument_list|(
name|program
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|QGraphicsShaderEffectPrivate
class|class
name|QGraphicsShaderEffectPrivate
super|:
specifier|public
name|QGraphicsEffectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QGraphicsShaderEffect
parameter_list|)
specifier|public
private|:
DECL|function|QGraphicsShaderEffectPrivate
name|QGraphicsShaderEffectPrivate
parameter_list|()
member_init_list|:
name|pixelShaderFragment
argument_list|(
name|qglslDefaultImageFragmentShader
argument_list|)
ifdef|#
directive|ifdef
name|QGL_HAVE_CUSTOM_SHADERS
member_init_list|,
name|customShaderStage
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{     }
DECL|member|pixelShaderFragment
name|QByteArray
name|pixelShaderFragment
decl_stmt|;
ifdef|#
directive|ifdef
name|QGL_HAVE_CUSTOM_SHADERS
DECL|member|customShaderStage
name|QGLCustomShaderEffectStage
modifier|*
name|customShaderStage
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_comment
comment|/*#     Constructs a shader effect and attaches it to \a parent. */
end_comment
begin_constructor
DECL|function|QGraphicsShaderEffect
name|QGraphicsShaderEffect
operator|::
name|QGraphicsShaderEffect
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsEffect
argument_list|(
operator|*
operator|new
name|QGraphicsShaderEffectPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*#     Destroys this shader effect. */
end_comment
begin_destructor
DECL|function|~QGraphicsShaderEffect
name|QGraphicsShaderEffect
operator|::
name|~
name|QGraphicsShaderEffect
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QGL_HAVE_CUSTOM_SHADERS
name|Q_D
argument_list|(
name|QGraphicsShaderEffect
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|customShaderStage
expr_stmt|;
endif|#
directive|endif
block|}
end_destructor
begin_comment
comment|/*#     Returns the source code for the pixel shader fragment for     this shader effect.  The default is a shader that copies     its incoming pixmap directly to the output with no effect     applied.      \sa setPixelShaderFragment() */
end_comment
begin_function
DECL|function|pixelShaderFragment
name|QByteArray
name|QGraphicsShaderEffect
operator|::
name|pixelShaderFragment
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsShaderEffect
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|pixelShaderFragment
return|;
block|}
end_function
begin_comment
comment|/*#     Sets the source code for the pixel shader fragment for     this shader effect to \a code.      The \a code must define a GLSL function with the signature     \c{lowp vec4 customShader(lowp sampler2D imageTexture, highp vec2 textureCoords)}     that returns the source pixel value to use in the paint engine's     shader program.  The following is the default pixel shader fragment,     which draws a pixmap with no effect applied:      \code     lowp vec4 customShader(lowp sampler2D imageTexture, highp vec2 textureCoords) {         return texture2D(imageTexture, textureCoords);     }     \endcode      \sa pixelShaderFragment(), setUniforms() */
end_comment
begin_function
DECL|function|setPixelShaderFragment
name|void
name|QGraphicsShaderEffect
operator|::
name|setPixelShaderFragment
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|code
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsShaderEffect
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|pixelShaderFragment
operator|!=
name|code
condition|)
block|{
name|d
operator|->
name|pixelShaderFragment
operator|=
name|code
expr_stmt|;
ifdef|#
directive|ifdef
name|QGL_HAVE_CUSTOM_SHADERS
operator|delete
name|d
operator|->
name|customShaderStage
expr_stmt|;
name|d
operator|->
name|customShaderStage
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_comment
comment|/*#     \reimp */
end_comment
begin_function
DECL|function|draw
name|void
name|QGraphicsShaderEffect
operator|::
name|draw
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsShaderEffect
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QGL_HAVE_CUSTOM_SHADERS
comment|// Set the custom shader on the paint engine.  The setOnPainter()
comment|// call may fail if the paint engine is not GL2.  In that case,
comment|// we fall through to drawing the pixmap normally.
if|if
condition|(
operator|!
name|d
operator|->
name|customShaderStage
condition|)
block|{
name|d
operator|->
name|customShaderStage
operator|=
operator|new
name|QGLCustomShaderEffectStage
argument_list|(
name|this
argument_list|,
name|d
operator|->
name|pixelShaderFragment
argument_list|)
expr_stmt|;
block|}
name|bool
name|usingShader
init|=
name|d
operator|->
name|customShaderStage
operator|->
name|setOnPainter
argument_list|(
name|painter
argument_list|)
decl_stmt|;
name|QPoint
name|offset
decl_stmt|;
if|if
condition|(
name|sourceIsPixmap
argument_list|()
condition|)
block|{
comment|// No point in drawing in device coordinates (pixmap will be scaled anyways).
specifier|const
name|QPixmap
name|pixmap
init|=
name|sourcePixmap
argument_list|(
name|Qt
operator|::
name|LogicalCoordinates
argument_list|,
operator|&
name|offset
argument_list|)
decl_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|offset
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Draw pixmap in device coordinates to avoid pixmap scaling.
specifier|const
name|QPixmap
name|pixmap
init|=
name|sourcePixmap
argument_list|(
name|Qt
operator|::
name|DeviceCoordinates
argument_list|,
operator|&
name|offset
argument_list|)
decl_stmt|;
name|QTransform
name|restoreTransform
init|=
name|painter
operator|->
name|worldTransform
argument_list|()
decl_stmt|;
name|painter
operator|->
name|setWorldTransform
argument_list|(
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|offset
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setWorldTransform
argument_list|(
name|restoreTransform
argument_list|)
expr_stmt|;
block|}
comment|// Remove the custom shader to return to normal painting operations.
if|if
condition|(
name|usingShader
condition|)
name|d
operator|->
name|customShaderStage
operator|->
name|removeFromPainter
argument_list|(
name|painter
argument_list|)
expr_stmt|;
else|#
directive|else
name|drawSource
argument_list|(
name|painter
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*#     Sets the custom uniform variables on this shader effect to     be dirty.  The setUniforms() function will be called the next     time the shader program corresponding to this effect is used.      This function is typically called by subclasses when an     effect-specific parameter is changed by the application.      \sa setUniforms() */
end_comment
begin_function
DECL|function|setUniformsDirty
name|void
name|QGraphicsShaderEffect
operator|::
name|setUniformsDirty
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QGL_HAVE_CUSTOM_SHADERS
name|Q_D
argument_list|(
name|QGraphicsShaderEffect
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|customShaderStage
condition|)
name|d
operator|->
name|customShaderStage
operator|->
name|setUniformsDirty
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*#     Sets custom uniform variables on the current GL context when     \a program is about to be used by the paint engine.      This function should be overridden if the shader set with     setPixelShaderFragment() has additional parameters beyond     those that the paint engine normally sets itself.      \sa setUniformsDirty() */
end_comment
begin_function
DECL|function|setUniforms
name|void
name|QGraphicsShaderEffect
operator|::
name|setUniforms
parameter_list|(
name|QGLShaderProgram
modifier|*
name|program
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|program
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
