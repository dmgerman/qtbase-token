begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).  ** Contact: http://www.qt-project.org/legal  **  ** This file is part of the test suite of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and Digia.  For licensing terms and  ** conditions see http://qt.digia.com/licensing.  For further information  ** use the contact form at http://qt.digia.com/contact-us.  **  ** GNU Lesser General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU Lesser  ** General Public License version 2.1 as published by the Free Software  ** Foundation and appearing in the file LICENSE.LGPL included in the  ** packaging of this file.  Please review the following information to  ** ensure the GNU Lesser General Public License version 2.1 requirements  ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.  **  ** In addition, as a special exception, Digia gives you certain additional  ** rights.  These rights are described in the Digia Qt LGPL Exception  ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.  **  ** GNU General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU  ** General Public License version 3.0 as published by the Free Software  ** Foundation and appearing in the file LICENSE.GPL included in the  ** packaging of this file.  Please review the following information to  ** ensure the GNU General Public License version 3.0 requirements will be  ** met: http://www.gnu.org/copyleft/gpl.html.  **  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|PixmapPainter
class|class
name|PixmapPainter
super|:
specifier|public
name|QWidget
block|{
public|public:
name|PixmapPainter
parameter_list|()
constructor_decl|;
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
function_decl|;
DECL|member|pixmap1X
name|QPixmap
name|pixmap1X
decl_stmt|;
DECL|member|pixmap2X
name|QPixmap
name|pixmap2X
decl_stmt|;
DECL|member|pixmapLarge
name|QPixmap
name|pixmapLarge
decl_stmt|;
DECL|member|image1X
name|QImage
name|image1X
decl_stmt|;
DECL|member|image2X
name|QImage
name|image2X
decl_stmt|;
DECL|member|imageLarge
name|QImage
name|imageLarge
decl_stmt|;
DECL|member|qtIcon
name|QIcon
name|qtIcon
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|PixmapPainter
name|PixmapPainter
operator|::
name|PixmapPainter
parameter_list|()
block|{
name|pixmap1X
operator|=
name|QPixmap
argument_list|(
literal|":/qticon32.png"
argument_list|)
expr_stmt|;
name|pixmap2X
operator|=
name|QPixmap
argument_list|(
literal|":/qticon32@2x.png"
argument_list|)
expr_stmt|;
name|pixmapLarge
operator|=
name|QPixmap
argument_list|(
literal|":/qticon64.png"
argument_list|)
expr_stmt|;
name|image1X
operator|=
name|QImage
argument_list|(
literal|":/qticon32.png"
argument_list|)
expr_stmt|;
name|image2X
operator|=
name|QImage
argument_list|(
literal|":/qticon32@2x.png"
argument_list|)
expr_stmt|;
name|imageLarge
operator|=
name|QImage
argument_list|(
literal|":/qticon64.png"
argument_list|)
expr_stmt|;
name|qtIcon
operator|.
name|addFile
argument_list|(
literal|":/qticon32.png"
argument_list|)
expr_stmt|;
name|qtIcon
operator|.
name|addFile
argument_list|(
literal|":/qticon32@2x.png"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|paintEvent
name|void
name|PixmapPainter
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|,
name|QBrush
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
argument_list|)
expr_stmt|;
name|int
name|pixmapPointSize
init|=
literal|32
decl_stmt|;
name|int
name|y
init|=
literal|30
decl_stmt|;
name|int
name|dy
init|=
literal|90
decl_stmt|;
name|int
name|x
init|=
literal|10
decl_stmt|;
name|int
name|dx
init|=
literal|40
decl_stmt|;
comment|// draw at point
comment|//          qDebug()<< "paint pixmap"<< pixmap1X.devicePixelRatio();
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmap1X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmap2X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapLarge
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
operator|*
literal|2
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|qtIcon
operator|.
name|pixmap
argument_list|(
name|QSize
argument_list|(
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|image1X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|image2X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|imageLarge
argument_list|)
expr_stmt|;
comment|// draw at 32x32 rect
name|y
operator|+=
name|dy
expr_stmt|;
name|x
operator|=
literal|10
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|,
name|pixmap1X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|,
name|pixmap2X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|,
name|pixmapLarge
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|,
name|qtIcon
operator|.
name|pixmap
argument_list|(
name|QSize
argument_list|(
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|,
name|image1X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|,
name|image2X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|,
name|imageLarge
argument_list|)
expr_stmt|;
comment|// draw at 64x64 rect
name|y
operator|+=
name|dy
operator|-
literal|50
expr_stmt|;
name|x
operator|=
literal|10
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|)
argument_list|,
name|pixmap1X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
operator|*
literal|2
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|)
argument_list|,
name|pixmap2X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
operator|*
literal|2
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|)
argument_list|,
name|pixmapLarge
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
operator|*
literal|2
expr_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|)
argument_list|,
name|qtIcon
operator|.
name|pixmap
argument_list|(
name|QSize
argument_list|(
name|pixmapPointSize
argument_list|,
name|pixmapPointSize
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
operator|*
literal|2
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|)
argument_list|,
name|image1X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
operator|*
literal|2
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|)
argument_list|,
name|image2X
argument_list|)
expr_stmt|;
name|x
operator|+=
name|dx
operator|*
literal|2
expr_stmt|;
name|p
operator|.
name|drawImage
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|,
name|pixmapPointSize
operator|*
literal|2
argument_list|)
argument_list|,
name|imageLarge
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|Labels
class|class
name|Labels
super|:
specifier|public
name|QWidget
block|{
public|public:
name|Labels
parameter_list|()
constructor_decl|;
DECL|member|pixmap1X
name|QPixmap
name|pixmap1X
decl_stmt|;
DECL|member|pixmap2X
name|QPixmap
name|pixmap2X
decl_stmt|;
DECL|member|pixmapLarge
name|QPixmap
name|pixmapLarge
decl_stmt|;
DECL|member|qtIcon
name|QIcon
name|qtIcon
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|Labels
name|Labels
operator|::
name|Labels
parameter_list|()
block|{
name|pixmap1X
operator|=
name|QPixmap
argument_list|(
literal|":/qticon32.png"
argument_list|)
expr_stmt|;
name|pixmap2X
operator|=
name|QPixmap
argument_list|(
literal|":/qticon32@2x.png"
argument_list|)
expr_stmt|;
name|pixmapLarge
operator|=
name|QPixmap
argument_list|(
literal|":/qticon64.png"
argument_list|)
expr_stmt|;
name|qtIcon
operator|.
name|addFile
argument_list|(
literal|":/qticon32.png"
argument_list|)
expr_stmt|;
name|qtIcon
operator|.
name|addFile
argument_list|(
literal|":/qticon32@2x.png"
argument_list|)
expr_stmt|;
name|setWindowIcon
argument_list|(
name|qtIcon
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
literal|"Labels"
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|label1x
init|=
operator|new
name|QLabel
argument_list|()
decl_stmt|;
name|label1x
operator|->
name|setPixmap
argument_list|(
name|pixmap1X
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|label2x
init|=
operator|new
name|QLabel
argument_list|()
decl_stmt|;
name|label2x
operator|->
name|setPixmap
argument_list|(
name|pixmap2X
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|labelIcon
init|=
operator|new
name|QLabel
argument_list|()
decl_stmt|;
name|labelIcon
operator|->
name|setPixmap
argument_list|(
name|qtIcon
operator|.
name|pixmap
argument_list|(
name|QSize
argument_list|(
literal|32
argument_list|,
literal|32
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|labelLarge
init|=
operator|new
name|QLabel
argument_list|()
decl_stmt|;
name|labelLarge
operator|->
name|setPixmap
argument_list|(
name|pixmapLarge
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|label1x
argument_list|)
expr_stmt|;
comment|//expected low-res on high-dpi displays
name|layout
operator|->
name|addWidget
argument_list|(
name|label2x
argument_list|)
expr_stmt|;
comment|//expected high-res on high-dpi displays
name|layout
operator|->
name|addWidget
argument_list|(
name|labelIcon
argument_list|)
expr_stmt|;
comment|//expected high-res on high-dpi displays
name|layout
operator|->
name|addWidget
argument_list|(
name|labelLarge
argument_list|)
expr_stmt|;
comment|// expected large size and low-res
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_class
DECL|class|MainWindow
class|class
name|MainWindow
super|:
specifier|public
name|QMainWindow
block|{
public|public:
name|MainWindow
parameter_list|()
constructor_decl|;
DECL|member|qtIcon
name|QIcon
name|qtIcon
decl_stmt|;
DECL|member|qtIcon1x
name|QIcon
name|qtIcon1x
decl_stmt|;
DECL|member|qtIcon2x
name|QIcon
name|qtIcon2x
decl_stmt|;
DECL|member|fileToolBar
name|QToolBar
modifier|*
name|fileToolBar
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
comment|// beware that QIcon auto-loads the @2x versions.
name|qtIcon1x
operator|.
name|addFile
argument_list|(
literal|":/qticon16.png"
argument_list|)
expr_stmt|;
name|qtIcon2x
operator|.
name|addFile
argument_list|(
literal|":/qticon32.png"
argument_list|)
expr_stmt|;
name|setWindowIcon
argument_list|(
name|qtIcon
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
literal|"MainWindow"
argument_list|)
expr_stmt|;
name|fileToolBar
operator|=
name|addToolBar
argument_list|(
name|tr
argument_list|(
literal|"File"
argument_list|)
argument_list|)
expr_stmt|;
comment|//    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
name|fileToolBar
operator|->
name|addAction
argument_list|(
operator|new
name|QAction
argument_list|(
name|qtIcon1x
argument_list|,
name|QString
argument_list|(
literal|"1x"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
operator|new
name|QAction
argument_list|(
name|qtIcon2x
argument_list|,
name|QString
argument_list|(
literal|"2x"
argument_list|)
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_class
DECL|class|StandardIcons
class|class
name|StandardIcons
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|int
name|x
init|=
literal|10
decl_stmt|;
name|int
name|y
init|=
literal|10
decl_stmt|;
name|int
name|dx
init|=
literal|50
decl_stmt|;
name|int
name|dy
init|=
literal|50
decl_stmt|;
name|int
name|maxX
init|=
literal|500
decl_stmt|;
for|for
control|(
name|int
name|iconIndex
init|=
name|QStyle
operator|::
name|SP_TitleBarMenuButton
init|;
name|iconIndex
operator|<
name|QStyle
operator|::
name|SP_MediaVolumeMuted
condition|;
operator|++
name|iconIndex
control|)
block|{
name|QIcon
name|icon
init|=
name|qApp
operator|->
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|StandardPixmap
argument_list|(
name|iconIndex
argument_list|)
argument_list|)
decl_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|icon
operator|.
name|pixmap
argument_list|(
name|dx
operator|-
literal|5
argument_list|,
name|dy
operator|-
literal|5
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|+
name|dx
operator|>
name|maxX
condition|)
name|y
operator|+=
name|dy
expr_stmt|;
name|x
operator|=
operator|(
operator|(
name|x
operator|+
name|dx
operator|)
operator|%
name|maxX
operator|)
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|Caching
class|class
name|Caching
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QSize
name|layoutSize
argument_list|(
literal|75
argument_list|,
literal|75
argument_list|)
decl_stmt|;
name|QPainter
name|widgetPainter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|widgetPainter
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|this
operator|->
name|size
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
block|{
specifier|const
name|qreal
name|devicePixelRatio
init|=
name|this
operator|->
name|windowHandle
argument_list|()
operator|->
name|devicePixelRatio
argument_list|()
decl_stmt|;
name|QPixmap
name|cache
argument_list|(
name|layoutSize
operator|*
name|devicePixelRatio
argument_list|)
decl_stmt|;
name|cache
operator|.
name|setDevicePixelRatio
argument_list|(
name|devicePixelRatio
argument_list|)
expr_stmt|;
name|QPainter
name|cachedPainter
argument_list|(
operator|&
name|cache
argument_list|)
decl_stmt|;
name|cachedPainter
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|75
argument_list|,
literal|75
argument_list|)
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|cachedPainter
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|55
argument_list|,
literal|55
argument_list|)
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|cachedPainter
operator|.
name|drawEllipse
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|55
argument_list|,
literal|55
argument_list|)
argument_list|)
expr_stmt|;
name|QPainter
name|widgetPainter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|widgetPainter
operator|.
name|drawPixmap
argument_list|(
name|QPoint
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|,
name|cache
argument_list|)
expr_stmt|;
block|}
block|{
specifier|const
name|qreal
name|devicePixelRatio
init|=
name|this
operator|->
name|windowHandle
argument_list|()
operator|->
name|devicePixelRatio
argument_list|()
decl_stmt|;
name|QImage
name|cache
init|=
name|QImage
argument_list|(
name|layoutSize
operator|*
name|devicePixelRatio
argument_list|,
name|QImage
operator|::
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|cache
operator|.
name|setDevicePixelRatio
argument_list|(
name|devicePixelRatio
argument_list|)
expr_stmt|;
name|QPainter
name|cachedPainter
argument_list|(
operator|&
name|cache
argument_list|)
decl_stmt|;
name|cachedPainter
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|75
argument_list|,
literal|75
argument_list|)
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|cachedPainter
operator|.
name|fillRect
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|55
argument_list|,
literal|55
argument_list|)
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|cachedPainter
operator|.
name|drawEllipse
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|55
argument_list|,
literal|55
argument_list|)
argument_list|)
expr_stmt|;
name|QPainter
name|widgetPainter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|widgetPainter
operator|.
name|drawImage
argument_list|(
name|QPoint
argument_list|(
literal|95
argument_list|,
literal|10
argument_list|)
argument_list|,
name|cache
argument_list|)
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_class
DECL|class|Style
class|class
name|Style
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|member|button
name|QPushButton
modifier|*
name|button
decl_stmt|;
DECL|member|lineEdit
name|QLineEdit
modifier|*
name|lineEdit
decl_stmt|;
DECL|member|slider
name|QSlider
modifier|*
name|slider
decl_stmt|;
DECL|member|row1
name|QHBoxLayout
modifier|*
name|row1
decl_stmt|;
DECL|function|Style
name|Style
parameter_list|()
block|{
name|row1
operator|=
operator|new
name|QHBoxLayout
argument_list|()
expr_stmt|;
name|setLayout
argument_list|(
name|row1
argument_list|)
expr_stmt|;
name|button
operator|=
operator|new
name|QPushButton
argument_list|()
expr_stmt|;
name|button
operator|->
name|setText
argument_list|(
literal|"Test Button"
argument_list|)
expr_stmt|;
name|row1
operator|->
name|addWidget
argument_list|(
name|button
argument_list|)
expr_stmt|;
name|lineEdit
operator|=
operator|new
name|QLineEdit
argument_list|()
expr_stmt|;
name|lineEdit
operator|->
name|setText
argument_list|(
literal|"Test Lineedit"
argument_list|)
expr_stmt|;
name|row1
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|)
expr_stmt|;
name|slider
operator|=
operator|new
name|QSlider
argument_list|()
expr_stmt|;
name|row1
operator|->
name|addWidget
argument_list|(
name|slider
argument_list|)
expr_stmt|;
name|row1
operator|->
name|addWidget
argument_list|(
operator|new
name|QSpinBox
argument_list|)
expr_stmt|;
name|row1
operator|->
name|addWidget
argument_list|(
operator|new
name|QScrollBar
argument_list|)
expr_stmt|;
name|QTabBar
modifier|*
name|tab
init|=
operator|new
name|QTabBar
argument_list|()
decl_stmt|;
name|tab
operator|->
name|addTab
argument_list|(
literal|"Foo"
argument_list|)
expr_stmt|;
name|tab
operator|->
name|addTab
argument_list|(
literal|"Bar"
argument_list|)
expr_stmt|;
name|row1
operator|->
name|addWidget
argument_list|(
name|tab
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|Fonts
class|class
name|Fonts
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|int
name|y
init|=
literal|40
decl_stmt|;
for|for
control|(
name|int
name|fontSize
init|=
literal|2
init|;
name|fontSize
operator|<
literal|18
condition|;
name|fontSize
operator|+=
literal|2
control|)
block|{
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setPointSize
argument_list|(
name|fontSize
argument_list|)
expr_stmt|;
name|QString
name|string
init|=
name|QString
argument_list|(
name|QStringLiteral
argument_list|(
literal|"%1 The quick brown fox jumped over the lazy Doug."
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|fontSize
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
literal|10
argument_list|,
name|y
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|y
operator|+=
operator|(
name|fontSize
operator|*
literal|2.5
operator|)
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|apiTestdevicePixelRatioGetter
name|void
name|apiTestdevicePixelRatioGetter
parameter_list|()
block|{
if|if
condition|(
literal|0
condition|)
block|{
name|T
modifier|*
name|t
init|=
literal|0
decl_stmt|;
name|t
operator|->
name|devicePixelRatio
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
template|template
parameter_list|<
name|typename
name|T
parameter_list|>
DECL|function|apiTestdevicePixelRatioSetter
name|void
name|apiTestdevicePixelRatioSetter
parameter_list|()
block|{
if|if
condition|(
literal|0
condition|)
block|{
name|T
modifier|*
name|t
init|=
literal|0
decl_stmt|;
name|t
operator|->
name|setDevicePixelRatio
argument_list|(
literal|2.0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|apiTest
name|void
name|apiTest
parameter_list|()
block|{
comment|// compile call to devicePixelRatio getter and setter (verify spelling)
name|apiTestdevicePixelRatioGetter
argument_list|<
name|QWindow
argument_list|>
argument_list|()
expr_stmt|;
name|apiTestdevicePixelRatioGetter
argument_list|<
name|QScreen
argument_list|>
argument_list|()
expr_stmt|;
name|apiTestdevicePixelRatioGetter
argument_list|<
name|QGuiApplication
argument_list|>
argument_list|()
expr_stmt|;
name|apiTestdevicePixelRatioGetter
argument_list|<
name|QImage
argument_list|>
argument_list|()
expr_stmt|;
name|apiTestdevicePixelRatioSetter
argument_list|<
name|QImage
argument_list|>
argument_list|()
expr_stmt|;
name|apiTestdevicePixelRatioGetter
argument_list|<
name|QPixmap
argument_list|>
argument_list|()
expr_stmt|;
name|apiTestdevicePixelRatioSetter
argument_list|<
name|QPixmap
argument_list|>
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// Request and draw an icon at different sizes
end_comment
begin_class
DECL|class|IconDrawing
class|class
name|IconDrawing
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|member|iconHighDPI
name|QIcon
modifier|*
name|iconHighDPI
decl_stmt|;
DECL|member|iconNormalDpi
name|QIcon
modifier|*
name|iconNormalDpi
decl_stmt|;
DECL|function|IconDrawing
name|IconDrawing
parameter_list|()
block|{
name|QFile
operator|::
name|copy
argument_list|(
literal|":/qticon32.png"
argument_list|,
literal|"/tmp/qticon32-2.png"
argument_list|)
expr_stmt|;
name|QFile
operator|::
name|copy
argument_list|(
literal|":/qticon32.png"
argument_list|,
literal|"/tmp/qticon32.png"
argument_list|)
expr_stmt|;
name|QFile
operator|::
name|copy
argument_list|(
literal|":/qticon32@2x.png"
argument_list|,
literal|"/tmp/qticon32@2x.png"
argument_list|)
expr_stmt|;
name|iconHighDPI
operator|=
operator|new
name|QIcon
argument_list|(
literal|"/tmp/qticon32.png"
argument_list|)
expr_stmt|;
comment|// will auto-load @2x version.
name|iconNormalDpi
operator|=
operator|new
name|QIcon
argument_list|(
literal|"/tmp/qticon32-2.png"
argument_list|)
expr_stmt|;
comment|// does not have a 2x version.
block|}
DECL|function|~IconDrawing
name|~
name|IconDrawing
parameter_list|()
block|{
operator|delete
name|iconHighDPI
expr_stmt|;
operator|delete
name|iconNormalDpi
expr_stmt|;
comment|//        Qile::
block|}
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|int
name|x
init|=
literal|10
decl_stmt|;
name|int
name|y
init|=
literal|10
decl_stmt|;
name|int
name|dx
init|=
literal|50
decl_stmt|;
name|int
name|dy
init|=
literal|50
decl_stmt|;
name|int
name|maxX
init|=
literal|600
decl_stmt|;
name|int
name|minSize
init|=
literal|5
decl_stmt|;
name|int
name|maxSize
init|=
literal|64
decl_stmt|;
name|int
name|sizeIncrement
init|=
literal|5
decl_stmt|;
comment|// Disable high-dpi icons
name|qApp
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|AA_UseHighDpiPixmaps
argument_list|,
literal|false
argument_list|)
expr_stmt|;
comment|// normal icon
for|for
control|(
name|int
name|size
init|=
name|minSize
init|;
name|size
operator|<
name|maxSize
condition|;
name|size
operator|+=
name|sizeIncrement
control|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|iconNormalDpi
operator|->
name|pixmap
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|+
name|dx
operator|>
name|maxX
condition|)
name|y
operator|+=
name|dy
expr_stmt|;
name|x
operator|=
operator|(
operator|(
name|x
operator|+
name|dx
operator|)
operator|%
name|maxX
operator|)
expr_stmt|;
block|}
name|x
operator|=
literal|10
expr_stmt|;
name|y
operator|+=
name|dy
expr_stmt|;
comment|// high-dpi icon
for|for
control|(
name|int
name|size
init|=
name|minSize
init|;
name|size
operator|<
name|maxSize
condition|;
name|size
operator|+=
name|sizeIncrement
control|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|iconHighDPI
operator|->
name|pixmap
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|+
name|dx
operator|>
name|maxX
condition|)
name|y
operator|+=
name|dy
expr_stmt|;
name|x
operator|=
operator|(
operator|(
name|x
operator|+
name|dx
operator|)
operator|%
name|maxX
operator|)
expr_stmt|;
block|}
name|x
operator|=
literal|10
expr_stmt|;
name|y
operator|+=
name|dy
expr_stmt|;
comment|// Enable high-dpi icons
name|qApp
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|AA_UseHighDpiPixmaps
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|// normal icon
for|for
control|(
name|int
name|size
init|=
name|minSize
init|;
name|size
operator|<
name|maxSize
condition|;
name|size
operator|+=
name|sizeIncrement
control|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|iconNormalDpi
operator|->
name|pixmap
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|+
name|dx
operator|>
name|maxX
condition|)
name|y
operator|+=
name|dy
expr_stmt|;
name|x
operator|=
operator|(
operator|(
name|x
operator|+
name|dx
operator|)
operator|%
name|maxX
operator|)
expr_stmt|;
block|}
name|x
operator|=
literal|10
expr_stmt|;
name|y
operator|+=
name|dy
expr_stmt|;
comment|// high-dpi icon (draw point)
for|for
control|(
name|int
name|size
init|=
name|minSize
init|;
name|size
operator|<
name|maxSize
condition|;
name|size
operator|+=
name|sizeIncrement
control|)
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawPixmap
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|iconHighDPI
operator|->
name|pixmap
argument_list|(
name|size
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|+
name|dx
operator|>
name|maxX
condition|)
name|y
operator|+=
name|dy
expr_stmt|;
name|x
operator|=
operator|(
operator|(
name|x
operator|+
name|dx
operator|)
operator|%
name|maxX
operator|)
expr_stmt|;
block|}
name|x
operator|=
literal|10
expr_stmt|;
name|y
operator|+=
name|dy
expr_stmt|;
block|}
empty_stmt|;
block|}
class|;
end_class
begin_comment
comment|// Icons on buttons
end_comment
begin_class
DECL|class|Buttons
class|class
name|Buttons
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|Buttons
name|Buttons
parameter_list|()
block|{
name|QIcon
name|icon
decl_stmt|;
name|icon
operator|.
name|addFile
argument_list|(
literal|":/qticon16@2x.png"
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|button
init|=
operator|new
name|QPushButton
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|button
operator|->
name|setIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
name|button
operator|->
name|setText
argument_list|(
literal|"16@2x"
argument_list|)
expr_stmt|;
name|QTabBar
modifier|*
name|tab
init|=
operator|new
name|QTabBar
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|tab
operator|->
name|addTab
argument_list|(
name|QIcon
argument_list|(
literal|":/qticon16.png"
argument_list|)
argument_list|,
literal|"16@1x"
argument_list|)
expr_stmt|;
name|tab
operator|->
name|addTab
argument_list|(
name|QIcon
argument_list|(
literal|":/qticon16@2x.png"
argument_list|)
argument_list|,
literal|"16@2x"
argument_list|)
expr_stmt|;
name|tab
operator|->
name|addTab
argument_list|(
name|QIcon
argument_list|(
literal|":/qticon16.png"
argument_list|)
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|tab
operator|->
name|addTab
argument_list|(
name|QIcon
argument_list|(
literal|":/qticon16@2x.png"
argument_list|)
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|tab
operator|->
name|move
argument_list|(
literal|10
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|tab
operator|->
name|show
argument_list|()
expr_stmt|;
name|QToolBar
modifier|*
name|toolBar
init|=
operator|new
name|QToolBar
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|toolBar
operator|->
name|addAction
argument_list|(
name|QIcon
argument_list|(
literal|":/qticon16.png"
argument_list|)
argument_list|,
literal|"16"
argument_list|)
expr_stmt|;
name|toolBar
operator|->
name|addAction
argument_list|(
name|QIcon
argument_list|(
literal|":/qticon16@2x.png"
argument_list|)
argument_list|,
literal|"16@2x"
argument_list|)
expr_stmt|;
name|toolBar
operator|->
name|addAction
argument_list|(
name|QIcon
argument_list|(
literal|":/qticon32.png"
argument_list|)
argument_list|,
literal|"32"
argument_list|)
expr_stmt|;
name|toolBar
operator|->
name|addAction
argument_list|(
name|QIcon
argument_list|(
literal|":/qticon32@2x.png"
argument_list|)
argument_list|,
literal|"32@2x"
argument_list|)
expr_stmt|;
name|toolBar
operator|->
name|move
argument_list|(
literal|10
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|toolBar
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
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
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|qApp
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|AA_UseHighDpiPixmaps
argument_list|)
expr_stmt|;
name|PixmapPainter
name|pixmapPainter
decl_stmt|;
name|pixmapPainter
operator|.
name|show
argument_list|()
expr_stmt|;
name|Labels
name|label
decl_stmt|;
name|label
operator|.
name|resize
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
comment|//    label.show();
name|MainWindow
name|mainWindow
decl_stmt|;
comment|//    mainWindow.show();
name|StandardIcons
name|icons
decl_stmt|;
name|icons
operator|.
name|resize
argument_list|(
literal|510
argument_list|,
literal|510
argument_list|)
expr_stmt|;
comment|//    icons.show();
name|Caching
name|caching
decl_stmt|;
name|caching
operator|.
name|resize
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
expr_stmt|;
comment|//    caching.show();
name|Style
name|style
decl_stmt|;
comment|//    style.show();
name|Fonts
name|fonts
decl_stmt|;
comment|//    fonts.show();
name|IconDrawing
name|iconDrawing
decl_stmt|;
comment|//    iconDrawing.show();
name|Buttons
name|buttons
decl_stmt|;
comment|//    buttons.show();
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
