begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"qplatformscreen_qpa.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QScreenPrivate
class|class
name|QScreenPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
DECL|function|QScreenPrivate
name|QScreenPrivate
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|platformScreen
argument_list|(
name|screen
argument_list|)
block|{     }
DECL|member|platformScreen
name|QPlatformScreen
modifier|*
name|platformScreen
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QScreen     \brief The QScreen class is used to query screen properties.      \inmodule QtGui */
end_comment
begin_constructor
DECL|function|QScreen
name|QScreen
operator|::
name|QScreen
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QScreenPrivate
argument_list|(
name|screen
argument_list|)
argument_list|,
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Get the platform screen handle. */
end_comment
begin_function
DECL|function|handle
name|QPlatformScreen
modifier|*
name|QScreen
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::name   \brief a user presentable string representing the screen    For example, on X11 these correspond to the XRandr screen names,   typically "VGA1", "HDMI1", etc. */
end_comment
begin_function
DECL|function|name
name|QString
name|QScreen
operator|::
name|name
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|name
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::depth   \brief the color depth of the screen */
end_comment
begin_function
DECL|function|depth
name|int
name|QScreen
operator|::
name|depth
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|depth
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::size   \brief the pixel resolution of the screen */
end_comment
begin_function
DECL|function|size
name|QSize
name|QScreen
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalDotsPerInchX   \brief the number of physical dots or pixels per inch in the horizontal direction    This value represents the actual horizontal pixel density on the screen's display.   Depending on what information the underlying system provides the value might not be   entirely accurate.    \sa physicalDotsPerInchY() */
end_comment
begin_function
DECL|function|physicalDotsPerInchX
name|qreal
name|QScreen
operator|::
name|physicalDotsPerInchX
parameter_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|/
name|physicalSize
argument_list|()
operator|.
name|width
argument_list|()
operator|*
literal|25.4
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalDotsPerInchY   \brief the number of physical dots or pixels per inch in the vertical direction    This value represents the actual vertical pixel density on the screen's display.   Depending on what information the underlying system provides the value might not be   entirely accurate.    \sa physicalDotsPerInchX() */
end_comment
begin_function
DECL|function|physicalDotsPerInchY
name|qreal
name|QScreen
operator|::
name|physicalDotsPerInchY
parameter_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|/
name|physicalSize
argument_list|()
operator|.
name|height
argument_list|()
operator|*
literal|25.4
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::logicalDotsPerInchX   \brief the number of logical dots or pixels per inch in the horizontal direction    This value is used to convert font point sizes to pixel sizes.    \sa logicalDotsPerInchY() */
end_comment
begin_function
DECL|function|logicalDotsPerInchX
name|qreal
name|QScreen
operator|::
name|logicalDotsPerInchX
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|logicalDpi
argument_list|()
operator|.
name|first
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::logicalDotsPerInchY   \brief the number of logical dots or pixels per inch in the vertical direction    This value is used to convert font point sizes to pixel sizes.    \sa logicalDotsPerInchX() */
end_comment
begin_function
DECL|function|logicalDotsPerInchY
name|qreal
name|QScreen
operator|::
name|logicalDotsPerInchY
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|logicalDpi
argument_list|()
operator|.
name|second
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::physicalSize   \brief the screen's physical size (in millimeters)    The physical size represents the actual physical dimensions of the   screen's display.    Depending on what information the underlying system provides the value   might not be entirely accurate. */
end_comment
begin_function
DECL|function|physicalSize
name|QSizeF
name|QScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|physicalSize
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableSize   \brief the screen's available size in pixels    The available size is the size excluding window manager reserved areas   such as task bars and system menus. */
end_comment
begin_function
DECL|function|availableSize
name|QSize
name|QScreen
operator|::
name|availableSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|availableGeometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::geometry   \brief the screen's geometry in pixels    As an example this might return QRect(0, 0, 1280, 1024), or in a   virtual desktop setting QRect(1280, 0, 1280, 1024). */
end_comment
begin_function
DECL|function|geometry
name|QRect
name|QScreen
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|geometry
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableGeometry   \brief the screen's available geometry in pixels    The available geometry is the geometry excluding window manager reserved areas   such as task bars and system menus. */
end_comment
begin_function
DECL|function|availableGeometry
name|QRect
name|QScreen
operator|::
name|availableGeometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|availableGeometry
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   Get the screen's virtual siblings.    The virtual siblings are the screen instances sharing the same virtual desktop.   They share a common coordinate system, and windows can freely be moved or   positioned across them without having to be re-created. */
end_comment
begin_function
DECL|function|virtualSiblings
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|QScreen
operator|::
name|virtualSiblings
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|platformScreens
init|=
name|d
operator|->
name|platformScreen
operator|->
name|virtualSiblings
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|screens
decl_stmt|;
foreach|foreach
control|(
name|QPlatformScreen
modifier|*
name|platformScreen
decl|,
name|platformScreens
control|)
name|screens
operator|<<
name|platformScreen
operator|->
name|screen
argument_list|()
expr_stmt|;
return|return
name|screens
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::virtualSize   \brief the pixel size of the virtual desktop corresponding to this screen    This is the combined size of the virtual siblings' individual geometries.    \sa virtualSiblings() */
end_comment
begin_function
DECL|function|virtualSize
name|QSize
name|QScreen
operator|::
name|virtualSize
parameter_list|()
specifier|const
block|{
return|return
name|virtualGeometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::virtualGeometry   \brief the pixel geometry of the virtual desktop corresponding to this screen    This is the union of the virtual siblings' individual geometries.    \sa virtualSiblings() */
end_comment
begin_function
DECL|function|virtualGeometry
name|QRect
name|QScreen
operator|::
name|virtualGeometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
name|QRect
name|result
decl_stmt|;
foreach|foreach
control|(
name|QPlatformScreen
modifier|*
name|platformScreen
decl|,
name|d
operator|->
name|platformScreen
operator|->
name|virtualSiblings
argument_list|()
control|)
name|result
operator||=
name|platformScreen
operator|->
name|geometry
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableVirtualSize   \brief the available pixel size of the virtual desktop corresponding to this screen    This is the combined size of the virtual siblings' individual available geometries.    \sa availableSize()   \sa virtualSiblings() */
end_comment
begin_function
DECL|function|availableVirtualSize
name|QSize
name|QScreen
operator|::
name|availableVirtualSize
parameter_list|()
specifier|const
block|{
return|return
name|availableVirtualGeometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!   \property QScreen::availableVirtualGeometry   \brief the available size of the virtual desktop corresponding to this screen    This is the union of the virtual siblings' individual available geometries.    \sa availableGeometry()   \sa virtualSiblings() */
end_comment
begin_function
DECL|function|availableVirtualGeometry
name|QRect
name|QScreen
operator|::
name|availableVirtualGeometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
name|QRect
name|result
decl_stmt|;
foreach|foreach
control|(
name|QPlatformScreen
modifier|*
name|platformScreen
decl|,
name|d
operator|->
name|platformScreen
operator|->
name|virtualSiblings
argument_list|()
control|)
name|result
operator||=
name|platformScreen
operator|->
name|availableGeometry
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::primaryOrientation     \brief the primary screen orientation      The primary screen orientation is the orientation that corresponds     to an un-rotated screen buffer. When the current orientation is equal     to the primary orientation no rotation needs to be done by the     application. */
end_comment
begin_function
DECL|function|primaryOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QScreen
operator|::
name|primaryOrientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|primaryOrientation
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \property QScreen::primaryOrientation     \brief the current screen orientation      The current orientation is a hint to the application saying     what the preferred application orientation should be, based on the     current orientation of the physical display and / or other factors.      \sa primaryOrientation()     \sa currentOrientationChanged() */
end_comment
begin_function
DECL|function|currentOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QScreen
operator|::
name|currentOrientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformScreen
operator|->
name|currentOrientation
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function to compute the angle of rotation to get from     rotation \a a to rotation \a b.      The result will be 0, 90, 180, or 270. */
end_comment
begin_function
DECL|function|angleBetween
name|int
name|QScreen
operator|::
name|angleBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|UnknownOrientation
operator|||
name|b
operator|==
name|Qt
operator|::
name|UnknownOrientation
operator|||
name|a
operator|==
name|b
condition|)
return|return
literal|0
return|;
name|int
name|delta
init|=
name|int
argument_list|(
name|b
argument_list|)
operator|-
name|int
argument_list|(
name|a
argument_list|)
decl_stmt|;
if|if
condition|(
name|delta
operator|<
literal|0
condition|)
name|delta
operator|=
name|delta
operator|+
literal|4
expr_stmt|;
name|int
name|angles
index|[]
init|=
block|{
literal|0
block|,
literal|90
block|,
literal|180
block|,
literal|270
block|}
decl_stmt|;
return|return
name|angles
index|[
name|delta
index|]
return|;
block|}
end_function
begin_comment
comment|/*!     Convenience function to compute a transform that maps from the coordinate system     defined by orientation \a a into the coordinate system defined by orientation     \a b and target dimensions \a target.      Example, \a a is Qt::Landscape, \a b is Qt::Portrait, and \a target is QRect(0, 0, w, h)     the resulting transform will be such that the point QPoint(0, 0) is mapped to QPoint(0, w),     and QPoint(h, w) is mapped to QPoint(0, h). Thus, the landscape coordinate system QRect(0, 0, h, w)     is mapped (with a 90 degree rotation) into the portrait coordinate system QRect(0, 0, w, h). */
end_comment
begin_function
DECL|function|transformBetween
name|QTransform
name|QScreen
operator|::
name|transformBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|,
specifier|const
name|QRect
modifier|&
name|target
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|UnknownOrientation
operator|||
name|b
operator|==
name|Qt
operator|::
name|UnknownOrientation
operator|||
name|a
operator|==
name|b
condition|)
return|return
name|QTransform
argument_list|()
return|;
name|int
name|angle
init|=
name|angleBetween
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
name|QTransform
name|result
decl_stmt|;
switch|switch
condition|(
name|angle
condition|)
block|{
case|case
literal|90
case|:
name|result
operator|.
name|translate
argument_list|(
name|target
operator|.
name|width
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|180
case|:
name|result
operator|.
name|translate
argument_list|(
name|target
operator|.
name|width
argument_list|()
argument_list|,
name|target
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
literal|270
case|:
name|result
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
name|target
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
name|Q_ASSERT
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
name|result
operator|.
name|rotate
argument_list|(
name|angle
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Maps the rect between two screen orientations.      This will flip the x and y dimensions of the rectangle if orientation \a is     Qt::PortraitOrientation or Qt::InvertedPortraitOrientation and orientation \b is     Qt::LandscapeOrientation or Qt::InvertedLandscapeOrientation, or vice versa. */
end_comment
begin_function
DECL|function|mapBetween
name|QRect
name|QScreen
operator|::
name|mapBetween
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|a
parameter_list|,
name|Qt
operator|::
name|ScreenOrientation
name|b
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
if|if
condition|(
name|a
operator|==
name|Qt
operator|::
name|UnknownOrientation
operator|||
name|b
operator|==
name|Qt
operator|::
name|UnknownOrientation
operator|||
name|a
operator|==
name|b
condition|)
return|return
name|rect
return|;
if|if
condition|(
operator|(
name|a
operator|==
name|Qt
operator|::
name|PortraitOrientation
operator|||
name|a
operator|==
name|Qt
operator|::
name|InvertedPortraitOrientation
operator|)
operator|!=
operator|(
name|b
operator|==
name|Qt
operator|::
name|PortraitOrientation
operator|||
name|b
operator|==
name|Qt
operator|::
name|InvertedPortraitOrientation
operator|)
condition|)
block|{
return|return
name|QRect
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|)
return|;
block|}
return|return
name|rect
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QScreen::currentOrientationChanged(Qt::ScreenOrientation orientation)      This signal is emitted when the current orientation of the screen     changes. The current orientation is a hint to the application saying     what the preferred application orientation should be, based on the     current orientation of the physical display and / or other factors.      \sa currentOrientation() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
