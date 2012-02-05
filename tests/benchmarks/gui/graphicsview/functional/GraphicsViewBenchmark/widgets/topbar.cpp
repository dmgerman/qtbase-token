begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QStyleOptionGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QGraphicsSceneResizeEvent>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QFont>
end_include
begin_include
include|#
directive|include
file|"themeevent.h"
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_include
include|#
directive|include
file|"topbar.h"
end_include
begin_include
include|#
directive|include
file|"mainview.h"
end_include
begin_constructor
DECL|function|TopBar
name|TopBar
operator|::
name|TopBar
parameter_list|(
name|QGraphicsView
modifier|*
name|mainView
parameter_list|,
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|GvbWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_mainView
argument_list|(
name|mainView
argument_list|)
member_init_list|,
name|m_isLimeTheme
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_orientation
argument_list|(
name|TopBar
operator|::
name|None
argument_list|)
member_init_list|,
name|m_topBarPixmap
argument_list|()
member_init_list|,
name|m_sizesBlue
argument_list|()
member_init_list|,
name|m_sizesLime
argument_list|()
block|{
name|setDefaultSizes
argument_list|()
expr_stmt|;
name|m_titleFont
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|TitleBar
argument_list|)
expr_stmt|;
name|m_statusFont
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|StatusBar
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|themeChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|themeChange
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~TopBar
name|TopBar
operator|::
name|~
name|TopBar
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|resizeEvent
name|void
name|TopBar
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
comment|/*event*/
parameter_list|)
block|{
comment|//Check orientation
name|QString
name|topbarName
decl_stmt|;
name|QSize
name|mainViewSize
init|=
name|m_mainView
operator|->
name|size
argument_list|()
decl_stmt|;
name|int
name|rotationAngle
init|=
cast|static_cast
argument_list|<
name|MainView
operator|*
argument_list|>
argument_list|(
name|m_mainView
argument_list|)
operator|->
name|rotationAngle
argument_list|()
decl_stmt|;
if|if
condition|(
name|rotationAngle
operator|==
literal|90
operator|||
name|rotationAngle
operator|==
literal|270
condition|)
block|{
name|int
name|wd
init|=
name|mainViewSize
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|ht
init|=
name|mainViewSize
operator|.
name|height
argument_list|()
decl_stmt|;
name|mainViewSize
operator|.
name|setWidth
argument_list|(
name|ht
argument_list|)
expr_stmt|;
name|mainViewSize
operator|.
name|setHeight
argument_list|(
name|wd
argument_list|)
expr_stmt|;
block|}
name|bool
name|m_orientationChanged
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|mainViewSize
operator|.
name|height
argument_list|()
operator|>=
name|mainViewSize
operator|.
name|width
argument_list|()
condition|)
block|{
if|if
condition|(
name|m_orientation
operator|==
name|TopBar
operator|::
name|Landscape
condition|)
name|m_orientationChanged
operator|=
literal|true
expr_stmt|;
name|m_orientation
operator|=
name|TopBar
operator|::
name|Portrait
expr_stmt|;
name|topbarName
operator|=
literal|"topbar.svg"
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|m_orientation
operator|==
name|TopBar
operator|::
name|Portrait
condition|)
name|m_orientationChanged
operator|=
literal|true
expr_stmt|;
name|m_orientation
operator|=
name|TopBar
operator|::
name|Landscape
expr_stmt|;
name|topbarName
operator|=
literal|"topbar_horisontal.svg"
expr_stmt|;
block|}
comment|//Calculate new size, resize by height, don't make it wider than the screen
name|QHash
argument_list|<
name|QString
argument_list|,
name|QSize
argument_list|>
name|sizes
init|=
operator|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|theme
argument_list|()
operator|==
name|Theme
operator|::
name|Blue
operator|)
condition|?
name|m_sizesBlue
else|:
name|m_sizesLime
decl_stmt|;
comment|//Get current size for topbarpixmap
name|QSize
name|currentSize
init|=
operator|!
name|m_topBarPixmap
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|m_orientationChanged
condition|?
name|m_topBarPixmap
operator|.
name|size
argument_list|()
else|:
name|sizes
index|[
name|topbarName
index|]
decl_stmt|;
name|QSize
name|newSize
init|=
operator|!
name|m_orientationChanged
condition|?
name|QSize
argument_list|(
name|currentSize
argument_list|)
else|:
name|sizes
index|[
name|topbarName
index|]
decl_stmt|;
comment|//Scale according to aspect ratio
name|newSize
operator|.
name|scale
argument_list|(
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
comment|//fix width to window widht if previous scaling produced too narrow image
if|if
condition|(
name|newSize
operator|.
name|width
argument_list|()
operator|<
name|size
argument_list|()
operator|.
name|width
argument_list|()
condition|)
block|{
name|newSize
operator|.
name|scale
argument_list|(
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatioByExpanding
argument_list|)
expr_stmt|;
block|}
comment|//Calculate scaling factor for rest of the graphics scaling
name|qreal
name|scaleFactor
init|=
operator|(
name|newSize
operator|.
name|width
argument_list|()
operator|*
literal|1.0
operator|)
operator|/
operator|(
name|currentSize
operator|.
name|width
argument_list|()
operator|*
literal|1.0
operator|)
decl_stmt|;
comment|//Scale graphics, if the scalefactor applies
comment|//This is really heavy since the SVG graphics are read again from the resource
if|if
condition|(
name|scaleFactor
operator|!=
literal|1
operator|||
name|m_topBarPixmap
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|m_topBarPixmap
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
name|topbarName
argument_list|,
name|newSize
argument_list|)
expr_stmt|;
name|m_topBarUserIcon
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"user_default_icon.svg"
argument_list|,
operator|!
name|m_topBarUserIcon
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|m_orientationChanged
condition|?
name|m_topBarUserIcon
operator|.
name|size
argument_list|()
operator|*
name|scaleFactor
else|:
name|sizes
index|[
literal|"user_default_icon.svg"
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
name|m_topBarUserStatus
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"user_status_online.svg"
argument_list|,
operator|!
name|m_topBarUserStatus
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|m_orientationChanged
condition|?
name|m_topBarUserStatus
operator|.
name|size
argument_list|()
operator|*
name|scaleFactor
else|:
name|sizes
index|[
literal|"user_status_online.svg"
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
name|m_topBarStatusBarLeft
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"status_field_left.svg"
argument_list|,
operator|!
name|m_topBarStatusBarLeft
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|m_orientationChanged
condition|?
name|m_topBarStatusBarLeft
operator|.
name|size
argument_list|()
operator|*
name|scaleFactor
else|:
name|sizes
index|[
literal|"status_field_left.svg"
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
name|m_topBarStatusBarRight
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"status_field_right.svg"
argument_list|,
operator|!
name|m_topBarStatusBarRight
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|m_orientationChanged
condition|?
name|m_topBarStatusBarRight
operator|.
name|size
argument_list|()
operator|*
name|scaleFactor
else|:
name|sizes
index|[
literal|"status_field_right.svg"
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
name|m_topBarStatusBarMiddle
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"status_field_middle.svg"
argument_list|,
operator|!
name|m_topBarStatusBarMiddle
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|m_orientationChanged
condition|?
name|m_topBarStatusBarMiddle
operator|.
name|size
argument_list|()
operator|*
name|scaleFactor
else|:
name|QSize
argument_list|(
literal|185
argument_list|,
name|sizes
index|[
literal|"status_field_middle.svg"
index|]
operator|.
name|height
argument_list|()
argument_list|)
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
comment|//Update the sizeHint to match the size of the scaled m_topBarPixmap
name|updateGeometry
argument_list|()
expr_stmt|;
comment|//Point Update - Positions relative to the Top Bar "Backgroud" size.
comment|//TODO: consider some layout instead of calculating relative locations
name|QSize
name|topBarPixmapSize
init|=
name|m_topBarPixmap
operator|.
name|size
argument_list|()
decl_stmt|;
name|QSize
name|topBarUserIconSize
init|=
name|m_topBarUserIcon
operator|.
name|size
argument_list|()
decl_stmt|;
name|QSize
name|topBarUserStatusSize
init|=
name|m_topBarUserStatus
operator|.
name|size
argument_list|()
decl_stmt|;
name|QSize
name|topBarStatusBarLeftSize
init|=
name|m_topBarStatusBarLeft
operator|.
name|size
argument_list|()
decl_stmt|;
name|QSize
name|topBarStatusBarMiddleSize
init|=
name|m_topBarStatusBarMiddle
operator|.
name|size
argument_list|()
decl_stmt|;
comment|//Location for Title text 5% width, 35% heigth of the background pixmap
name|m_topBarTitlePoint
operator|=
name|QPoint
argument_list|(
name|topBarPixmapSize
operator|.
name|width
argument_list|()
operator|*
literal|0.05
argument_list|,
name|topBarPixmapSize
operator|.
name|height
argument_list|()
operator|*
literal|0.35
argument_list|)
expr_stmt|;
comment|//User Icon location
comment|//Placing 70% of the width and 10% of the height of the top bar background
name|m_topBarUserIconPoint
operator|=
name|QPoint
argument_list|(
operator|(
name|topBarPixmapSize
operator|.
name|width
argument_list|()
operator|*
literal|0.7
operator|)
argument_list|,
operator|(
name|topBarPixmapSize
operator|.
name|height
argument_list|()
operator|*
literal|0.1
operator|)
argument_list|)
expr_stmt|;
comment|//If Blue theme is in use - position user status icon on the right side of the user icon
if|if
condition|(
operator|!
name|m_isLimeTheme
condition|)
block|{
comment|//Place the status icon on top of the right edge of the user icon, lower it by 35% of the height of the user icon
name|m_topBarUserStatusPoint
operator|=
name|QPoint
argument_list|(
operator|(
operator|(
name|m_topBarUserIconPoint
operator|.
name|x
argument_list|()
operator|+
name|topBarUserIconSize
operator|.
name|width
argument_list|()
operator|)
operator|-
operator|(
name|topBarUserStatusSize
operator|.
name|width
argument_list|()
operator|/
literal|2
operator|)
operator|)
argument_list|,
operator|(
name|m_topBarUserIconPoint
operator|.
name|y
argument_list|()
operator|+
operator|(
name|topBarUserIconSize
operator|.
name|height
argument_list|()
operator|*
literal|0.35
operator|)
operator|)
argument_list|)
expr_stmt|;
block|}
comment|//If Lime theme is in use - position user status icon on the left side of the user icon
else|else
block|{
comment|//Place the status icon on top of the left side of the user icon, lower it by 50% of the height of the user icon
comment|//and move left by 5% of the icon
name|m_topBarUserStatusPoint
operator|=
name|QPoint
argument_list|(
name|m_topBarUserIconPoint
operator|.
name|x
argument_list|()
operator|+
operator|(
name|topBarUserIconSize
operator|.
name|width
argument_list|()
operator|*
literal|0.05
operator|)
argument_list|,
operator|(
name|m_topBarUserIconPoint
operator|.
name|y
argument_list|()
operator|+
operator|(
name|topBarUserIconSize
operator|.
name|height
argument_list|()
operator|*
literal|0.5
operator|)
operator|)
argument_list|)
expr_stmt|;
block|}
comment|//Status bar
comment|//Placing the left side of the status bar  5% of the width, 50% of the height of the top bar background
comment|//Set the text baseline 80% of the height of the status bar
name|m_topBarStatusBarLeftPoint
operator|=
name|QPoint
argument_list|(
operator|(
name|topBarPixmapSize
operator|.
name|width
argument_list|()
operator|*
literal|0.05
operator|)
argument_list|,
operator|(
name|topBarPixmapSize
operator|.
name|height
argument_list|()
operator|*
literal|0.5
operator|)
argument_list|)
expr_stmt|;
name|m_topBarStatusBarMiddlePoint
operator|=
name|QPoint
argument_list|(
operator|(
name|m_topBarStatusBarLeftPoint
operator|.
name|x
argument_list|()
operator|+
name|topBarStatusBarLeftSize
operator|.
name|width
argument_list|()
operator|)
argument_list|,
operator|(
name|m_topBarStatusBarLeftPoint
operator|.
name|y
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|m_topBarStatusBarRightPoint
operator|=
name|QPoint
argument_list|(
operator|(
name|m_topBarStatusBarMiddlePoint
operator|.
name|x
argument_list|()
operator|+
name|topBarStatusBarMiddleSize
operator|.
name|width
argument_list|()
operator|)
argument_list|,
operator|(
name|m_topBarStatusBarMiddlePoint
operator|.
name|y
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|m_topBarStatusBarTextPoint
operator|=
name|QPoint
argument_list|(
name|m_topBarStatusBarMiddlePoint
operator|.
name|x
argument_list|()
argument_list|,
name|m_topBarStatusBarMiddlePoint
operator|.
name|y
argument_list|()
operator|+
operator|(
name|topBarStatusBarMiddleSize
operator|.
name|height
argument_list|()
operator|*
literal|0.8
operator|)
argument_list|)
expr_stmt|;
block|}
comment|//if scalefactor
block|}
end_function
begin_function
DECL|function|paint
name|void
name|TopBar
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
comment|/*widget*/
parameter_list|)
block|{
comment|//Topbar background
name|painter
operator|->
name|drawPixmap
argument_list|(
name|option
operator|->
name|exposedRect
argument_list|,
name|m_topBarPixmap
argument_list|,
name|option
operator|->
name|exposedRect
argument_list|)
expr_stmt|;
comment|//User Icon
name|painter
operator|->
name|drawPixmap
argument_list|(
name|m_topBarUserIconPoint
argument_list|,
name|m_topBarUserIcon
argument_list|)
expr_stmt|;
comment|//User Status
name|painter
operator|->
name|drawPixmap
argument_list|(
name|m_topBarUserStatusPoint
argument_list|,
name|m_topBarUserStatus
argument_list|)
expr_stmt|;
comment|//Status bar
name|painter
operator|->
name|drawPixmap
argument_list|(
name|m_topBarStatusBarLeftPoint
argument_list|,
name|m_topBarStatusBarLeft
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|m_topBarStatusBarMiddlePoint
argument_list|,
name|m_topBarStatusBarMiddle
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|m_topBarStatusBarRightPoint
argument_list|,
name|m_topBarStatusBarRight
argument_list|)
expr_stmt|;
comment|//Title text
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setFont
argument_list|(
name|m_titleFont
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setOpacity
argument_list|(
literal|0.7
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|m_topBarTitlePoint
argument_list|,
name|QString
argument_list|(
literal|"Contacts"
argument_list|)
argument_list|)
expr_stmt|;
comment|//Status text
name|painter
operator|->
name|setFont
argument_list|(
name|m_statusFont
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setOpacity
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|m_topBarStatusBarTextPoint
argument_list|,
name|QString
argument_list|(
literal|"My Status (fixed)"
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|QRectF
name|TopBar
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
comment|//It's possible that m_topBarPixmap is not allocated yet,
comment|//in this case default size is used for setting boundingRect
name|QHash
argument_list|<
name|QString
argument_list|,
name|QSize
argument_list|>
name|sizes
init|=
operator|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|theme
argument_list|()
operator|==
name|Theme
operator|::
name|Blue
operator|)
condition|?
name|m_sizesBlue
else|:
name|m_sizesLime
decl_stmt|;
if|if
condition|(
operator|!
name|m_topBarPixmap
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|m_topBarPixmap
operator|.
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|m_topBarPixmap
operator|.
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
return|;
else|else
return|return
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|sizes
index|[
literal|"topbar.svg"
index|]
operator|.
name|width
argument_list|()
argument_list|,
name|sizes
index|[
literal|"topbar.svg"
index|]
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|themeChange
name|void
name|TopBar
operator|::
name|themeChange
parameter_list|()
block|{
name|m_titleFont
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|TitleBar
argument_list|)
expr_stmt|;
name|m_statusFont
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|StatusBar
argument_list|)
expr_stmt|;
comment|//Calculate the scaling factor
name|QHash
argument_list|<
name|QString
argument_list|,
name|QSize
argument_list|>
name|sizes
init|=
operator|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|theme
argument_list|()
operator|==
name|Theme
operator|::
name|Blue
operator|)
condition|?
name|m_sizesBlue
else|:
name|m_sizesLime
decl_stmt|;
name|QString
name|topbarString
init|=
name|m_orientation
operator|==
name|TopBar
operator|::
name|Portrait
condition|?
literal|"topbar.svg"
else|:
literal|"topbar_horisontal.svg"
decl_stmt|;
name|QSize
name|topBarSize
init|=
name|sizes
index|[
name|topbarString
index|]
decl_stmt|;
name|QSize
name|newSize
init|=
name|QSize
argument_list|(
name|topBarSize
argument_list|)
decl_stmt|;
comment|//Scale according to aspect ratio
name|newSize
operator|.
name|scale
argument_list|(
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatio
argument_list|)
expr_stmt|;
comment|//fix width to window widht if previous scaling produced too narrow image
if|if
condition|(
name|newSize
operator|.
name|width
argument_list|()
operator|<
name|size
argument_list|()
operator|.
name|width
argument_list|()
condition|)
block|{
name|newSize
operator|.
name|scale
argument_list|(
name|size
argument_list|()
operator|.
name|toSize
argument_list|()
argument_list|,
name|Qt
operator|::
name|KeepAspectRatioByExpanding
argument_list|)
expr_stmt|;
block|}
comment|//Calculate scaling factor for rest of the graphics scaling
name|qreal
name|scaleFactor
init|=
operator|(
name|newSize
operator|.
name|width
argument_list|()
operator|*
literal|1.0
operator|)
operator|/
operator|(
name|topBarSize
operator|.
name|width
argument_list|()
operator|*
literal|1.0
operator|)
decl_stmt|;
comment|//Background
name|m_topBarPixmap
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
name|topbarString
argument_list|,
name|sizes
index|[
name|topbarString
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
comment|//User Icon
name|m_topBarUserIcon
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"user_default_icon.svg"
argument_list|,
name|sizes
index|[
literal|"user_default_icon.svg"
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
comment|//User Status
name|m_topBarUserStatus
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"user_status_online.svg"
argument_list|,
name|sizes
index|[
literal|"user_status_online.svg"
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
comment|//Status Bar
name|m_topBarStatusBarLeft
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"status_field_left.svg"
argument_list|,
name|sizes
index|[
literal|"status_field_left.svg"
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
name|m_topBarStatusBarRight
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"status_field_right.svg"
argument_list|,
name|sizes
index|[
literal|"status_field_right.svg"
index|]
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
name|m_topBarStatusBarMiddle
operator|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmap
argument_list|(
literal|"status_field_middle.svg"
argument_list|,
name|QSize
argument_list|(
literal|185
argument_list|,
name|sizes
index|[
literal|"status_field_middle.svg"
index|]
operator|.
name|height
argument_list|()
argument_list|)
operator|*
name|scaleFactor
argument_list|)
expr_stmt|;
comment|//Update Drawing points for Top Bar elements, points are relative to the top bar background size
name|QSize
name|topBarPixmapSize
init|=
name|m_topBarPixmap
operator|.
name|size
argument_list|()
decl_stmt|;
name|QSize
name|topBarUserIconSize
init|=
name|m_topBarUserIcon
operator|.
name|size
argument_list|()
decl_stmt|;
name|QSize
name|topBarUserStatusSize
init|=
name|m_topBarUserStatus
operator|.
name|size
argument_list|()
decl_stmt|;
name|QSize
name|topBarStatusBarLeftSize
init|=
name|m_topBarStatusBarLeft
operator|.
name|size
argument_list|()
decl_stmt|;
name|QSize
name|topBarStatusBarMiddleSize
init|=
name|m_topBarStatusBarMiddle
operator|.
name|size
argument_list|()
decl_stmt|;
comment|//Theme Check
operator|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|theme
argument_list|()
operator|==
name|Theme
operator|::
name|Lime
operator|)
condition|?
name|m_isLimeTheme
operator|=
literal|true
else|:
name|m_isLimeTheme
operator|=
literal|false
expr_stmt|;
comment|//User Icon location
comment|//Placing 70% of the width and 10% of the height of the top bar background
name|m_topBarUserIconPoint
operator|=
name|QPoint
argument_list|(
operator|(
literal|0.7
operator|*
name|topBarPixmapSize
operator|.
name|width
argument_list|()
operator|)
argument_list|,
operator|(
literal|0.1
operator|*
name|topBarPixmapSize
operator|.
name|height
argument_list|()
operator|)
argument_list|)
expr_stmt|;
comment|//If Blue theme is in use - position user status icon on the right side of the user icon
if|if
condition|(
operator|!
name|m_isLimeTheme
condition|)
block|{
comment|//Place the status icon on top of the right edge of the user icon, lower it by 35% of the height of the user icon
name|m_topBarUserStatusPoint
operator|=
name|QPoint
argument_list|(
operator|(
operator|(
name|m_topBarUserIconPoint
operator|.
name|x
argument_list|()
operator|+
name|topBarUserIconSize
operator|.
name|width
argument_list|()
operator|)
operator|-
operator|(
name|topBarUserStatusSize
operator|.
name|width
argument_list|()
operator|/
literal|2
operator|)
operator|)
argument_list|,
operator|(
name|m_topBarUserIconPoint
operator|.
name|y
argument_list|()
operator|+
operator|(
name|topBarUserIconSize
operator|.
name|height
argument_list|()
operator|*
literal|0.35
operator|)
operator|)
argument_list|)
expr_stmt|;
block|}
comment|//If Lime theme is in use - position user status icon on the left side of the user icon
else|else
block|{
comment|//Place the status icon on top of the left side of the user icon, lower it by 50% of the height of the user icon
comment|//and move left by 5% of the icon
name|m_topBarUserStatusPoint
operator|=
name|QPoint
argument_list|(
name|m_topBarUserIconPoint
operator|.
name|x
argument_list|()
operator|+
operator|(
name|topBarUserIconSize
operator|.
name|width
argument_list|()
operator|*
literal|0.05
operator|)
argument_list|,
operator|(
name|m_topBarUserIconPoint
operator|.
name|y
argument_list|()
operator|+
operator|(
name|topBarUserIconSize
operator|.
name|height
argument_list|()
operator|*
literal|0.5
operator|)
operator|)
argument_list|)
expr_stmt|;
block|}
comment|//Status bar
comment|//Placing the left side of the status bar  5% of the width, 50% of the height of the top bar background
comment|//Set the text baseline 80% of the height of the status bar
name|m_topBarStatusBarLeftPoint
operator|=
name|QPoint
argument_list|(
operator|(
name|topBarPixmapSize
operator|.
name|width
argument_list|()
operator|*
literal|0.05
operator|)
argument_list|,
operator|(
name|topBarPixmapSize
operator|.
name|height
argument_list|()
operator|*
literal|0.5
operator|)
argument_list|)
expr_stmt|;
name|m_topBarStatusBarMiddlePoint
operator|=
name|QPoint
argument_list|(
operator|(
name|m_topBarStatusBarLeftPoint
operator|.
name|x
argument_list|()
operator|+
name|topBarStatusBarLeftSize
operator|.
name|width
argument_list|()
operator|)
argument_list|,
operator|(
name|m_topBarStatusBarLeftPoint
operator|.
name|y
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|m_topBarStatusBarRightPoint
operator|=
name|QPoint
argument_list|(
operator|(
name|m_topBarStatusBarMiddlePoint
operator|.
name|x
argument_list|()
operator|+
name|topBarStatusBarMiddleSize
operator|.
name|width
argument_list|()
operator|)
argument_list|,
operator|(
name|m_topBarStatusBarMiddlePoint
operator|.
name|y
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|m_topBarStatusBarTextPoint
operator|=
name|QPoint
argument_list|(
name|m_topBarStatusBarMiddlePoint
operator|.
name|x
argument_list|()
argument_list|,
name|m_topBarStatusBarMiddlePoint
operator|.
name|y
argument_list|()
operator|+
operator|(
name|topBarStatusBarMiddleSize
operator|.
name|height
argument_list|()
operator|*
literal|0.8
operator|)
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSizeF
name|TopBar
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
comment|//It's possible that m_topBarPixmap is not allocated yet,
comment|//in this case default size is used for setting size hint
name|QHash
argument_list|<
name|QString
argument_list|,
name|QSize
argument_list|>
name|sizes
init|=
operator|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|theme
argument_list|()
operator|==
name|Theme
operator|::
name|Blue
operator|)
condition|?
name|m_sizesBlue
else|:
name|m_sizesLime
decl_stmt|;
name|int
name|height
init|=
operator|!
name|m_topBarPixmap
operator|.
name|isNull
argument_list|()
condition|?
name|m_topBarPixmap
operator|.
name|height
argument_list|()
else|:
name|sizes
index|[
literal|"topbar.svg"
index|]
operator|.
name|height
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|which
condition|)
block|{
case|case
name|Qt
operator|::
name|MinimumSize
case|:
return|return
name|QSizeF
argument_list|(
operator|-
literal|1
argument_list|,
name|height
argument_list|)
return|;
case|case
name|Qt
operator|::
name|MaximumSize
case|:
return|return
name|QSizeF
argument_list|(
operator|-
literal|1
argument_list|,
name|height
argument_list|)
return|;
default|default:
return|return
name|QGraphicsWidget
operator|::
name|sizeHint
argument_list|(
name|which
argument_list|,
name|constraint
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|setDefaultSizes
name|void
name|TopBar
operator|::
name|setDefaultSizes
parameter_list|()
block|{
name|m_sizesBlue
index|[
literal|"topbar.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|356
argument_list|,
literal|96
argument_list|)
expr_stmt|;
name|m_sizesBlue
index|[
literal|"topbar_horisontal.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|636
argument_list|,
literal|96
argument_list|)
expr_stmt|;
name|m_sizesBlue
index|[
literal|"user_default_icon.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|68
argument_list|,
literal|68
argument_list|)
expr_stmt|;
name|m_sizesBlue
index|[
literal|"user_status_online.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|38
argument_list|,
literal|38
argument_list|)
expr_stmt|;
name|m_sizesBlue
index|[
literal|"status_field_left.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|14
argument_list|,
literal|24
argument_list|)
expr_stmt|;
name|m_sizesBlue
index|[
literal|"status_field_right.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|10
argument_list|,
literal|24
argument_list|)
expr_stmt|;
name|m_sizesBlue
index|[
literal|"status_field_middle.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|14
argument_list|,
literal|24
argument_list|)
expr_stmt|;
name|m_sizesLime
index|[
literal|"topbar.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|356
argument_list|,
literal|96
argument_list|)
expr_stmt|;
name|m_sizesLime
index|[
literal|"topbar_horisontal.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|636
argument_list|,
literal|96
argument_list|)
expr_stmt|;
name|m_sizesLime
index|[
literal|"user_default_icon.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|84
argument_list|,
literal|68
argument_list|)
expr_stmt|;
name|m_sizesLime
index|[
literal|"user_status_online.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|24
argument_list|,
literal|24
argument_list|)
expr_stmt|;
name|m_sizesLime
index|[
literal|"status_field_left.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|14
argument_list|,
literal|24
argument_list|)
expr_stmt|;
name|m_sizesLime
index|[
literal|"status_field_right.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|10
argument_list|,
literal|24
argument_list|)
expr_stmt|;
name|m_sizesLime
index|[
literal|"status_field_middle.svg"
index|]
operator|=
name|QSize
argument_list|(
literal|14
argument_list|,
literal|24
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|TopBar
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QRect
name|rect
init|=
name|m_topBarStatusBarMiddle
operator|.
name|rect
argument_list|()
decl_stmt|;
name|rect
operator|.
name|moveTopLeft
argument_list|(
name|m_topBarStatusBarMiddlePoint
argument_list|)
expr_stmt|;
name|QPointF
name|scenePoint
init|=
name|event
operator|->
name|scenePos
argument_list|()
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|contains
argument_list|(
name|scenePoint
operator|.
name|toPoint
argument_list|()
argument_list|)
condition|)
block|{
emit|emit
name|clicked
argument_list|()
emit|;
block|}
block|}
end_function
end_unit
