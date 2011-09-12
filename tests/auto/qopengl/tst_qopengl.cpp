begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QOpenGL
class|class
name|tst_QOpenGL
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|sharedResourceCleanup
parameter_list|()
function_decl|;
name|void
name|fboSimpleRendering
parameter_list|()
function_decl|;
name|void
name|fboRendering
parameter_list|()
function_decl|;
name|void
name|fboHandleNulledAfterContextDestroyed
parameter_list|()
function_decl|;
name|void
name|openGLPaintDevice
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_struct
DECL|struct|SharedResourceTracker
struct|struct
name|SharedResourceTracker
block|{
DECL|function|SharedResourceTracker
name|SharedResourceTracker
parameter_list|()
block|{
name|reset
argument_list|()
expr_stmt|;
block|}
DECL|function|reset
name|void
name|reset
parameter_list|()
block|{
name|invalidateResourceCalls
operator|=
literal|0
expr_stmt|;
name|freeResourceCalls
operator|=
literal|0
expr_stmt|;
name|destructorCalls
operator|=
literal|0
expr_stmt|;
block|}
DECL|member|invalidateResourceCalls
name|int
name|invalidateResourceCalls
decl_stmt|;
DECL|member|freeResourceCalls
name|int
name|freeResourceCalls
decl_stmt|;
DECL|member|destructorCalls
name|int
name|destructorCalls
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|SharedResource
struct|struct
name|SharedResource
super|:
specifier|public
name|QOpenGLSharedResource
block|{
DECL|function|SharedResource
name|SharedResource
parameter_list|(
name|SharedResourceTracker
modifier|*
name|t
parameter_list|)
member_init_list|:
name|QOpenGLSharedResource
argument_list|(
name|QOpenGLContextGroup
operator|::
name|currentContextGroup
argument_list|()
argument_list|)
member_init_list|,
name|resource
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|tracker
argument_list|(
name|t
argument_list|)
block|{     }
DECL|function|~SharedResource
name|~
name|SharedResource
parameter_list|()
block|{
name|tracker
operator|->
name|destructorCalls
operator|++
expr_stmt|;
block|}
DECL|function|invalidateResource
name|void
name|invalidateResource
parameter_list|()
block|{
name|resource
operator|=
literal|0
expr_stmt|;
name|tracker
operator|->
name|invalidateResourceCalls
operator|++
expr_stmt|;
block|}
DECL|function|freeResource
name|void
name|freeResource
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
operator|==
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
expr_stmt|;
name|resource
operator|=
literal|0
expr_stmt|;
name|tracker
operator|->
name|freeResourceCalls
operator|++
expr_stmt|;
block|}
DECL|member|resource
name|int
name|resource
decl_stmt|;
DECL|member|tracker
name|SharedResourceTracker
modifier|*
name|tracker
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|sharedResourceCleanup
name|void
name|tst_QOpenGL
operator|::
name|sharedResourceCleanup
parameter_list|()
block|{
name|QWindow
name|window
decl_stmt|;
name|window
operator|.
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|window
operator|.
name|create
argument_list|()
expr_stmt|;
name|QOpenGLContext
modifier|*
name|ctx
init|=
operator|new
name|QOpenGLContext
decl_stmt|;
name|ctx
operator|->
name|create
argument_list|()
expr_stmt|;
name|ctx
operator|->
name|makeCurrent
argument_list|(
operator|&
name|window
argument_list|)
expr_stmt|;
name|SharedResourceTracker
name|tracker
decl_stmt|;
name|SharedResource
modifier|*
name|resource
init|=
operator|new
name|SharedResource
argument_list|(
operator|&
name|tracker
argument_list|)
decl_stmt|;
name|resource
operator|->
name|free
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|invalidateResourceCalls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|freeResourceCalls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|destructorCalls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|tracker
operator|.
name|reset
argument_list|()
expr_stmt|;
name|resource
operator|=
operator|new
name|SharedResource
argument_list|(
operator|&
name|tracker
argument_list|)
expr_stmt|;
name|QOpenGLContext
modifier|*
name|ctx2
init|=
operator|new
name|QOpenGLContext
decl_stmt|;
name|ctx2
operator|->
name|setShareContext
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|ctx2
operator|->
name|create
argument_list|()
expr_stmt|;
operator|delete
name|ctx
expr_stmt|;
name|resource
operator|->
name|free
argument_list|()
expr_stmt|;
comment|// no current context, freeResource() delayed
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|invalidateResourceCalls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|freeResourceCalls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|destructorCalls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ctx2
operator|->
name|makeCurrent
argument_list|(
operator|&
name|window
argument_list|)
expr_stmt|;
comment|// freeResource() should now have been called
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|invalidateResourceCalls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|freeResourceCalls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|destructorCalls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|tracker
operator|.
name|reset
argument_list|()
expr_stmt|;
name|resource
operator|=
operator|new
name|SharedResource
argument_list|(
operator|&
name|tracker
argument_list|)
expr_stmt|;
comment|// this should cause invalidateResource() to be called
operator|delete
name|ctx2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|invalidateResourceCalls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|freeResourceCalls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|destructorCalls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// should have no effect other than destroying the resource,
comment|// as it has already been invalidated
name|resource
operator|->
name|free
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|invalidateResourceCalls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|freeResourceCalls
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|tracker
operator|.
name|destructorCalls
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fuzzyComparePixels
specifier|static
name|bool
name|fuzzyComparePixels
parameter_list|(
specifier|const
name|QRgb
name|testPixel
parameter_list|,
specifier|const
name|QRgb
name|refPixel
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|int
name|x
init|=
operator|-
literal|1
parameter_list|,
name|int
name|y
init|=
operator|-
literal|1
parameter_list|)
block|{
specifier|static
name|int
name|maxFuzz
init|=
literal|1
decl_stmt|;
specifier|static
name|bool
name|maxFuzzSet
init|=
literal|false
decl_stmt|;
comment|// On 16 bpp systems, we need to allow for more fuzz:
if|if
condition|(
operator|!
name|maxFuzzSet
condition|)
block|{
name|maxFuzzSet
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|depth
argument_list|()
operator|<
literal|24
condition|)
name|maxFuzz
operator|=
literal|32
expr_stmt|;
block|}
name|int
name|redFuzz
init|=
name|qAbs
argument_list|(
name|qRed
argument_list|(
name|testPixel
argument_list|)
operator|-
name|qRed
argument_list|(
name|refPixel
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|greenFuzz
init|=
name|qAbs
argument_list|(
name|qGreen
argument_list|(
name|testPixel
argument_list|)
operator|-
name|qGreen
argument_list|(
name|refPixel
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|blueFuzz
init|=
name|qAbs
argument_list|(
name|qBlue
argument_list|(
name|testPixel
argument_list|)
operator|-
name|qBlue
argument_list|(
name|refPixel
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|alphaFuzz
init|=
name|qAbs
argument_list|(
name|qAlpha
argument_list|(
name|testPixel
argument_list|)
operator|-
name|qAlpha
argument_list|(
name|refPixel
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|refPixel
operator|!=
literal|0
operator|&&
name|testPixel
operator|==
literal|0
condition|)
block|{
name|QString
name|msg
decl_stmt|;
if|if
condition|(
name|x
operator|>=
literal|0
condition|)
block|{
name|msg
operator|=
name|QString
argument_list|(
literal|"Test pixel [%1, %2] is null (black) when it should be (%3,%4,%5,%6)"
argument_list|)
operator|.
name|arg
argument_list|(
name|x
argument_list|)
operator|.
name|arg
argument_list|(
name|y
argument_list|)
operator|.
name|arg
argument_list|(
name|qRed
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qGreen
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qBlue
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qAlpha
argument_list|(
name|refPixel
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|msg
operator|=
name|QString
argument_list|(
literal|"Test pixel is null (black) when it should be (%2,%3,%4,%5)"
argument_list|)
operator|.
name|arg
argument_list|(
name|qRed
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qGreen
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qBlue
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qAlpha
argument_list|(
name|refPixel
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QTest
operator|::
name|qFail
argument_list|(
name|msg
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|redFuzz
operator|>
name|maxFuzz
operator|||
name|greenFuzz
operator|>
name|maxFuzz
operator|||
name|blueFuzz
operator|>
name|maxFuzz
operator|||
name|alphaFuzz
operator|>
name|maxFuzz
condition|)
block|{
name|QString
name|msg
decl_stmt|;
if|if
condition|(
name|x
operator|>=
literal|0
condition|)
name|msg
operator|=
name|QString
argument_list|(
literal|"Pixel [%1,%2]: "
argument_list|)
operator|.
name|arg
argument_list|(
name|x
argument_list|)
operator|.
name|arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
else|else
name|msg
operator|=
name|QString
argument_list|(
literal|"Pixel "
argument_list|)
expr_stmt|;
name|msg
operator|+=
name|QString
argument_list|(
literal|"Max fuzz (%1) exceeded: (%2,%3,%4,%5) vs (%6,%7,%8,%9)"
argument_list|)
operator|.
name|arg
argument_list|(
name|maxFuzz
argument_list|)
operator|.
name|arg
argument_list|(
name|qRed
argument_list|(
name|testPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qGreen
argument_list|(
name|testPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qBlue
argument_list|(
name|testPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qAlpha
argument_list|(
name|testPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qRed
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qGreen
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qBlue
argument_list|(
name|refPixel
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|qAlpha
argument_list|(
name|refPixel
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qFail
argument_list|(
name|msg
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|fuzzyCompareImages
specifier|static
name|void
name|fuzzyCompareImages
parameter_list|(
specifier|const
name|QImage
modifier|&
name|testImage
parameter_list|,
specifier|const
name|QImage
modifier|&
name|referenceImage
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|QCOMPARE
argument_list|(
name|testImage
operator|.
name|width
argument_list|()
argument_list|,
name|referenceImage
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|testImage
operator|.
name|height
argument_list|()
argument_list|,
name|referenceImage
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|testImage
operator|.
name|height
argument_list|()
condition|;
name|y
operator|++
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|testImage
operator|.
name|width
argument_list|()
condition|;
name|x
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|fuzzyComparePixels
argument_list|(
name|testImage
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|,
name|referenceImage
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|,
name|file
argument_list|,
name|line
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
condition|)
block|{
comment|// Might as well save the images for easier debugging:
name|referenceImage
operator|.
name|save
argument_list|(
literal|"referenceImage.png"
argument_list|)
expr_stmt|;
name|testImage
operator|.
name|save
argument_list|(
literal|"testImage.png"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
block|}
end_function
begin_define
DECL|macro|QFUZZY_COMPARE_IMAGES
define|#
directive|define
name|QFUZZY_COMPARE_IMAGES
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|fuzzyCompareImages(A, B, __FILE__, __LINE__)
end_define
begin_define
DECL|macro|QFUZZY_COMPARE_PIXELS
define|#
directive|define
name|QFUZZY_COMPARE_PIXELS
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|fuzzyComparePixels(A, B, __FILE__, __LINE__)
end_define
begin_function
DECL|function|qt_opengl_draw_test_pattern
name|void
name|qt_opengl_draw_test_pattern
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QPainterPath
name|intersectingPath
decl_stmt|;
name|intersectingPath
operator|.
name|moveTo
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|intersectingPath
operator|.
name|lineTo
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|intersectingPath
operator|.
name|lineTo
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|intersectingPath
operator|.
name|lineTo
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|intersectingPath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
name|QPainterPath
name|trianglePath
decl_stmt|;
name|trianglePath
operator|.
name|moveTo
argument_list|(
literal|50
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|trianglePath
operator|.
name|lineTo
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|trianglePath
operator|.
name|lineTo
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|trianglePath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setTransform
argument_list|(
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
comment|// reset xform
name|painter
operator|->
name|fillRect
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
name|width
operator|+
literal|2
argument_list|,
name|height
operator|+
literal|2
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
comment|// Background
name|painter
operator|->
name|translate
argument_list|(
literal|14
argument_list|,
literal|14
argument_list|)
expr_stmt|;
name|painter
operator|->
name|fillPath
argument_list|(
name|intersectingPath
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
comment|// Test stencil buffer works
name|painter
operator|->
name|translate
argument_list|(
literal|128
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipPath
argument_list|(
name|trianglePath
argument_list|)
expr_stmt|;
comment|// Test depth buffer works
name|painter
operator|->
name|setTransform
argument_list|(
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
comment|// reset xform ready for fill
name|painter
operator|->
name|fillRect
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
name|width
operator|+
literal|2
argument_list|,
name|height
operator|+
literal|2
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_opengl_check_test_pattern
name|void
name|qt_opengl_check_test_pattern
parameter_list|(
specifier|const
name|QImage
modifier|&
name|img
parameter_list|)
block|{
comment|// As we're doing more than trivial painting, we can't just compare to
comment|// an image rendered with raster. Instead, we sample at well-defined
comment|// test-points:
name|QFUZZY_COMPARE_PIXELS
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
literal|39
argument_list|,
literal|64
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
name|QFUZZY_COMPARE_PIXELS
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
literal|89
argument_list|,
literal|64
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
name|QFUZZY_COMPARE_PIXELS
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
literal|64
argument_list|,
literal|39
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
name|QFUZZY_COMPARE_PIXELS
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
literal|64
argument_list|,
literal|89
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
name|QFUZZY_COMPARE_PIXELS
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
literal|167
argument_list|,
literal|39
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
name|QFUZZY_COMPARE_PIXELS
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
literal|217
argument_list|,
literal|39
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
name|QFUZZY_COMPARE_PIXELS
argument_list|(
name|img
operator|.
name|pixel
argument_list|(
literal|192
argument_list|,
literal|64
argument_list|)
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fboSimpleRendering
name|void
name|tst_QOpenGL
operator|::
name|fboSimpleRendering
parameter_list|()
block|{
name|QWindow
name|window
decl_stmt|;
name|window
operator|.
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|window
operator|.
name|create
argument_list|()
expr_stmt|;
name|QOpenGLContext
name|ctx
decl_stmt|;
name|ctx
operator|.
name|create
argument_list|()
expr_stmt|;
name|ctx
operator|.
name|makeCurrent
argument_list|(
operator|&
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QOpenGLFramebufferObject
operator|::
name|hasOpenGLFramebufferObjects
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"QOpenGLFramebufferObject not supported on this platform"
argument_list|,
name|SkipSingle
argument_list|)
expr_stmt|;
comment|// No multisample with combined depth/stencil attachment:
name|QOpenGLFramebufferObjectFormat
name|fboFormat
decl_stmt|;
name|fboFormat
operator|.
name|setAttachment
argument_list|(
name|QOpenGLFramebufferObject
operator|::
name|NoAttachment
argument_list|)
expr_stmt|;
name|QOpenGLFramebufferObject
modifier|*
name|fbo
init|=
operator|new
name|QOpenGLFramebufferObject
argument_list|(
literal|200
argument_list|,
literal|100
argument_list|,
name|fboFormat
argument_list|)
decl_stmt|;
name|fbo
operator|->
name|bind
argument_list|()
expr_stmt|;
name|glClearColor
argument_list|(
literal|1.0
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
name|glFinish
argument_list|()
expr_stmt|;
name|QImage
name|fb
init|=
name|fbo
operator|->
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|QImage
name|reference
argument_list|(
name|fb
operator|.
name|size
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|reference
operator|.
name|fill
argument_list|(
literal|0xffff0000
argument_list|)
expr_stmt|;
name|QFUZZY_COMPARE_IMAGES
argument_list|(
name|fb
argument_list|,
name|reference
argument_list|)
expr_stmt|;
operator|delete
name|fbo
expr_stmt|;
block|}
end_function
begin_comment
comment|// NOTE: This tests that CombinedDepthStencil attachment works by assuming the
end_comment
begin_comment
comment|//       GL2 engine is being used and is implemented the same way as it was when
end_comment
begin_comment
comment|//       this autotest was written. If this is not the case, there may be some
end_comment
begin_comment
comment|//       false-positives: I.e. The test passes when either the depth or stencil
end_comment
begin_comment
comment|//       buffer is actually missing. But that's probably ok anyway.
end_comment
begin_function
DECL|function|fboRendering
name|void
name|tst_QOpenGL
operator|::
name|fboRendering
parameter_list|()
block|{
name|QWindow
name|window
decl_stmt|;
name|window
operator|.
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|window
operator|.
name|create
argument_list|()
expr_stmt|;
name|QOpenGLContext
name|ctx
decl_stmt|;
name|ctx
operator|.
name|create
argument_list|()
expr_stmt|;
name|ctx
operator|.
name|makeCurrent
argument_list|(
operator|&
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QOpenGLFramebufferObject
operator|::
name|hasOpenGLFramebufferObjects
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"QOpenGLFramebufferObject not supported on this platform"
argument_list|,
name|SkipSingle
argument_list|)
expr_stmt|;
comment|// No multisample with combined depth/stencil attachment:
name|QOpenGLFramebufferObjectFormat
name|fboFormat
decl_stmt|;
name|fboFormat
operator|.
name|setAttachment
argument_list|(
name|QOpenGLFramebufferObject
operator|::
name|CombinedDepthStencil
argument_list|)
expr_stmt|;
comment|// Uncomplicate things by using NPOT:
name|QOpenGLFramebufferObject
name|fbo
argument_list|(
literal|256
argument_list|,
literal|128
argument_list|,
name|fboFormat
argument_list|)
decl_stmt|;
if|if
condition|(
name|fbo
operator|.
name|attachment
argument_list|()
operator|!=
name|QOpenGLFramebufferObject
operator|::
name|CombinedDepthStencil
condition|)
name|QSKIP
argument_list|(
literal|"FBOs missing combined depth~stencil support"
argument_list|,
name|SkipSingle
argument_list|)
expr_stmt|;
name|fbo
operator|.
name|bind
argument_list|()
expr_stmt|;
name|QPainter
name|fboPainter
decl_stmt|;
name|QOpenGLPaintDevice
name|device
argument_list|(
name|fbo
operator|.
name|width
argument_list|()
argument_list|,
name|fbo
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|painterBegun
init|=
name|fboPainter
operator|.
name|begin
argument_list|(
operator|&
name|device
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|painterBegun
argument_list|)
expr_stmt|;
name|qt_opengl_draw_test_pattern
argument_list|(
operator|&
name|fboPainter
argument_list|,
name|fbo
operator|.
name|width
argument_list|()
argument_list|,
name|fbo
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|fboPainter
operator|.
name|end
argument_list|()
expr_stmt|;
name|QImage
name|fb
init|=
name|fbo
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|qt_opengl_check_test_pattern
argument_list|(
name|fb
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fboHandleNulledAfterContextDestroyed
name|void
name|tst_QOpenGL
operator|::
name|fboHandleNulledAfterContextDestroyed
parameter_list|()
block|{
name|QWindow
name|window
decl_stmt|;
name|window
operator|.
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|window
operator|.
name|create
argument_list|()
expr_stmt|;
name|QOpenGLFramebufferObject
modifier|*
name|fbo
init|=
literal|0
decl_stmt|;
block|{
name|QOpenGLContext
name|ctx
decl_stmt|;
name|ctx
operator|.
name|create
argument_list|()
expr_stmt|;
name|ctx
operator|.
name|makeCurrent
argument_list|(
operator|&
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QOpenGLFramebufferObject
operator|::
name|hasOpenGLFramebufferObjects
argument_list|()
condition|)
block|{
name|QSKIP
argument_list|(
literal|"QOpenGLFramebufferObject not supported on this platform"
argument_list|,
name|SkipSingle
argument_list|)
expr_stmt|;
block|}
name|fbo
operator|=
operator|new
name|QOpenGLFramebufferObject
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fbo
operator|->
name|handle
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|fbo
operator|->
name|handle
argument_list|()
argument_list|,
literal|0U
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openGLPaintDevice
name|void
name|tst_QOpenGL
operator|::
name|openGLPaintDevice
parameter_list|()
block|{
name|QWindow
name|window
decl_stmt|;
name|window
operator|.
name|setGeometry
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|window
operator|.
name|create
argument_list|()
expr_stmt|;
name|QOpenGLContext
name|ctx
decl_stmt|;
name|ctx
operator|.
name|create
argument_list|()
expr_stmt|;
name|ctx
operator|.
name|makeCurrent
argument_list|(
operator|&
name|window
argument_list|)
expr_stmt|;
name|QImage
name|image
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|image
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
literal|0
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QOpenGLFramebufferObject
name|fbo
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|)
decl_stmt|;
name|fbo
operator|.
name|bind
argument_list|()
expr_stmt|;
name|QOpenGLPaintDevice
name|device
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|)
decl_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|device
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
literal|0
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|image
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
argument_list|,
name|fbo
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
argument_list|)
expr_stmt|;
name|QSKIP
argument_list|(
literal|"Image / pixmap painting needs to be implemented"
argument_list|,
name|SkipSingle
argument_list|)
expr_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|device
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|image
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
argument_list|,
name|fbo
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QOpenGL
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qopengl.moc"
end_include
end_unit
