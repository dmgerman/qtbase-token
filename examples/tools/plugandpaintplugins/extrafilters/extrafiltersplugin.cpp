begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|"extrafiltersplugin.h"
end_include
begin_function
DECL|function|filters
name|QStringList
name|ExtraFiltersPlugin
operator|::
name|filters
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|tr
argument_list|(
literal|"Flip Horizontally"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Flip Vertically"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Smudge..."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Threshold..."
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|filterImage
name|QImage
name|ExtraFiltersPlugin
operator|::
name|filterImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
name|QImage
name|original
init|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|QImage
name|result
init|=
name|original
decl_stmt|;
if|if
condition|(
name|filter
operator|==
name|tr
argument_list|(
literal|"Flip Horizontally"
argument_list|)
condition|)
block|{
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|original
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
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
name|original
operator|.
name|width
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
name|int
name|pixel
init|=
name|original
operator|.
name|pixel
argument_list|(
name|original
operator|.
name|width
argument_list|()
operator|-
name|x
operator|-
literal|1
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|result
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixel
argument_list|)
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|filter
operator|==
name|tr
argument_list|(
literal|"Flip Vertically"
argument_list|)
condition|)
block|{
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|original
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
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
name|original
operator|.
name|width
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
name|int
name|pixel
init|=
name|original
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|original
operator|.
name|height
argument_list|()
operator|-
name|y
operator|-
literal|1
argument_list|)
decl_stmt|;
name|result
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixel
argument_list|)
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|filter
operator|==
name|tr
argument_list|(
literal|"Smudge..."
argument_list|)
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|int
name|numIters
init|=
name|QInputDialog
operator|::
name|getInteger
argument_list|(
name|parent
argument_list|,
name|tr
argument_list|(
literal|"Smudge Filter"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Enter number of iterations:"
argument_list|)
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|20
argument_list|,
literal|1
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|numIters
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|y
init|=
literal|1
init|;
name|y
operator|<
name|original
operator|.
name|height
argument_list|()
operator|-
literal|1
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|1
init|;
name|x
operator|<
name|original
operator|.
name|width
argument_list|()
operator|-
literal|1
condition|;
operator|++
name|x
control|)
block|{
name|int
name|p1
init|=
name|original
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|int
name|p2
init|=
name|original
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
operator|+
literal|1
argument_list|)
decl_stmt|;
name|int
name|p3
init|=
name|original
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
operator|-
literal|1
argument_list|)
decl_stmt|;
name|int
name|p4
init|=
name|original
operator|.
name|pixel
argument_list|(
name|x
operator|+
literal|1
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|int
name|p5
init|=
name|original
operator|.
name|pixel
argument_list|(
name|x
operator|-
literal|1
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|int
name|red
init|=
operator|(
name|qRed
argument_list|(
name|p1
argument_list|)
operator|+
name|qRed
argument_list|(
name|p2
argument_list|)
operator|+
name|qRed
argument_list|(
name|p3
argument_list|)
operator|+
name|qRed
argument_list|(
name|p4
argument_list|)
operator|+
name|qRed
argument_list|(
name|p5
argument_list|)
operator|)
operator|/
literal|5
decl_stmt|;
name|int
name|green
init|=
operator|(
name|qGreen
argument_list|(
name|p1
argument_list|)
operator|+
name|qGreen
argument_list|(
name|p2
argument_list|)
operator|+
name|qGreen
argument_list|(
name|p3
argument_list|)
operator|+
name|qGreen
argument_list|(
name|p4
argument_list|)
operator|+
name|qGreen
argument_list|(
name|p5
argument_list|)
operator|)
operator|/
literal|5
decl_stmt|;
name|int
name|blue
init|=
operator|(
name|qBlue
argument_list|(
name|p1
argument_list|)
operator|+
name|qBlue
argument_list|(
name|p2
argument_list|)
operator|+
name|qBlue
argument_list|(
name|p3
argument_list|)
operator|+
name|qBlue
argument_list|(
name|p4
argument_list|)
operator|+
name|qBlue
argument_list|(
name|p5
argument_list|)
operator|)
operator|/
literal|5
decl_stmt|;
name|int
name|alpha
init|=
operator|(
name|qAlpha
argument_list|(
name|p1
argument_list|)
operator|+
name|qAlpha
argument_list|(
name|p2
argument_list|)
operator|+
name|qAlpha
argument_list|(
name|p3
argument_list|)
operator|+
name|qAlpha
argument_list|(
name|p4
argument_list|)
operator|+
name|qAlpha
argument_list|(
name|p5
argument_list|)
operator|)
operator|/
literal|5
decl_stmt|;
name|result
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|qRgba
argument_list|(
name|red
argument_list|,
name|green
argument_list|,
name|blue
argument_list|,
name|alpha
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|filter
operator|==
name|tr
argument_list|(
literal|"Threshold..."
argument_list|)
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|int
name|threshold
init|=
name|QInputDialog
operator|::
name|getInteger
argument_list|(
name|parent
argument_list|,
name|tr
argument_list|(
literal|"Threshold Filter"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Enter threshold:"
argument_list|)
argument_list|,
literal|10
argument_list|,
literal|1
argument_list|,
literal|256
argument_list|,
literal|1
argument_list|,
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
name|int
name|factor
init|=
literal|256
operator|/
name|threshold
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|original
operator|.
name|height
argument_list|()
condition|;
operator|++
name|y
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
name|original
operator|.
name|width
argument_list|()
condition|;
operator|++
name|x
control|)
block|{
name|int
name|pixel
init|=
name|original
operator|.
name|pixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
name|result
operator|.
name|setPixel
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|qRgba
argument_list|(
name|qRed
argument_list|(
name|pixel
argument_list|)
operator|/
name|factor
operator|*
name|factor
argument_list|,
name|qGreen
argument_list|(
name|pixel
argument_list|)
operator|/
name|factor
operator|*
name|factor
argument_list|,
name|qBlue
argument_list|(
name|pixel
argument_list|)
operator|/
name|factor
operator|*
name|factor
argument_list|,
name|qAlpha
argument_list|(
name|pixel
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
return|return
name|result
return|;
block|}
end_function
end_unit
