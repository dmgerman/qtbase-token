begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"animation.h"
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|"lifecycle.h"
end_include
begin_include
include|#
directive|include
file|"stickman.h"
end_include
begin_include
include|#
directive|include
file|"graphicsview.h"
end_include
begin_include
include|#
directive|include
file|"rectbutton.h"
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_INIT_RESOURCE
argument_list|(
name|stickman
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|StickMan
modifier|*
name|stickMan
init|=
operator|new
name|StickMan
decl_stmt|;
name|stickMan
operator|->
name|setDrawSticks
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QGraphicsTextItem
modifier|*
name|textItem
init|=
operator|new
name|QGraphicsTextItem
argument_list|()
decl_stmt|;
name|textItem
operator|->
name|setHtml
argument_list|(
literal|"<font color=\"white\"><b>Stickman</b>"
literal|"<p>"
literal|"Tell the stickman what to do!"
literal|"</p>"
literal|"<p><i>"
literal|"<li>Press<font color=\"purple\">J</font> to make the stickman jump.</li>"
literal|"<li>Press<font color=\"purple\">D</font> to make the stickman dance.</li>"
literal|"<li>Press<font color=\"purple\">C</font> to make him chill out.</li>"
literal|"<li>When you are done, press<font color=\"purple\">Escape</font>.</li>"
literal|"</i></p>"
literal|"<p>If he is unlucky, the stickman will get struck by lightning, and never jump, dance or chill out again."
literal|"</p></font>"
argument_list|)
expr_stmt|;
name|qreal
name|w
init|=
name|textItem
operator|->
name|boundingRect
argument_list|()
operator|.
name|width
argument_list|()
decl_stmt|;
name|QRectF
name|stickManBoundingRect
init|=
name|stickMan
operator|->
name|mapToScene
argument_list|(
name|stickMan
operator|->
name|boundingRect
argument_list|()
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|textItem
operator|->
name|setPos
argument_list|(
operator|-
name|w
operator|/
literal|2.0
argument_list|,
name|stickManBoundingRect
operator|.
name|bottom
argument_list|()
operator|+
literal|25.0
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|stickMan
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|textItem
argument_list|)
expr_stmt|;
name|scene
operator|.
name|setBackgroundBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|GraphicsView
name|view
decl_stmt|;
name|view
operator|.
name|setRenderHints
argument_list|(
name|QPainter
operator|::
name|Antialiasing
argument_list|)
expr_stmt|;
name|view
operator|.
name|setTransformationAnchor
argument_list|(
name|QGraphicsView
operator|::
name|NoAnchor
argument_list|)
expr_stmt|;
name|view
operator|.
name|setScene
argument_list|(
operator|&
name|scene
argument_list|)
expr_stmt|;
name|QRectF
name|sceneRect
init|=
name|scene
operator|.
name|sceneRect
argument_list|()
decl_stmt|;
comment|// making enough room in the scene for stickman to jump and die
name|view
operator|.
name|resize
argument_list|(
name|sceneRect
operator|.
name|width
argument_list|()
operator|+
literal|100
argument_list|,
name|sceneRect
operator|.
name|height
argument_list|()
operator|+
literal|100
argument_list|)
expr_stmt|;
name|view
operator|.
name|setSceneRect
argument_list|(
name|sceneRect
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|view
operator|.
name|setFocus
argument_list|()
expr_stmt|;
name|LifeCycle
name|cycle
argument_list|(
name|stickMan
argument_list|,
operator|&
name|view
argument_list|)
decl_stmt|;
name|cycle
operator|.
name|setDeathAnimation
argument_list|(
literal|":/animations/dead"
argument_list|)
expr_stmt|;
name|cycle
operator|.
name|addActivity
argument_list|(
literal|":/animations/jumping"
argument_list|,
name|Qt
operator|::
name|Key_J
argument_list|)
expr_stmt|;
name|cycle
operator|.
name|addActivity
argument_list|(
literal|":/animations/dancing"
argument_list|,
name|Qt
operator|::
name|Key_D
argument_list|)
expr_stmt|;
name|cycle
operator|.
name|addActivity
argument_list|(
literal|":/animations/chilling"
argument_list|,
name|Qt
operator|::
name|Key_C
argument_list|)
expr_stmt|;
name|cycle
operator|.
name|start
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
