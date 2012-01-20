begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qiconengine.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!   \class QIconEngine    \brief The QIconEngine class provides an abstract base class for QIcon renderers.    \ingroup painting   \inmodule QtWidgets    \bold {Use QIconEngineV2 instead.}    An icon engine provides the rendering functions for a QIcon. Each icon has a   corresponding icon engine that is responsible for drawing the icon with a   requested size, mode and state.    The icon is rendered by the paint() function, and the icon can additionally be   obtained as a pixmap with the pixmap() function (the default implementation   simply uses paint() to achieve this). The addPixmap() function can be used to   add new pixmaps to the icon engine, and is used by QIcon to add specialized   custom pixmaps.    The paint(), pixmap(), and addPixmap() functions are all virtual, and can   therefore be reimplemented in subclasses of QIconEngine.    \sa QIconEngineV2, QIconEnginePlugin  */
comment|/*!   \fn virtual void QIconEngine::paint(QPainter *painter, const QRect&rect, QIcon::Mode mode, QIcon::State state) = 0;    Uses the given \a painter to paint the icon with the required \a mode and   \a state into the rectangle \a rect. */
comment|/*!  Returns the actual size of the icon the engine provides for the   requested \a size, \a mode and \a state. The default implementation   returns the given \a size.  */
DECL|function|actualSize
name|QSize
name|QIconEngine
operator|::
name|actualSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QIcon
operator|::
name|Mode
comment|/*mode*/
parameter_list|,
name|QIcon
operator|::
name|State
comment|/*state*/
parameter_list|)
block|{
return|return
name|size
return|;
block|}
end_function
begin_comment
comment|/*!   Destroys the icon engine.  */
end_comment
begin_destructor
DECL|function|~QIconEngine
name|QIconEngine
operator|::
name|~
name|QIconEngine
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns the icon as a pixmap with the required \a size, \a mode,   and \a state. The default implementation creates a new pixmap and   calls paint() to fill it. */
end_comment
begin_function
DECL|function|pixmap
name|QPixmap
name|QIconEngine
operator|::
name|pixmap
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QIcon
operator|::
name|Mode
name|mode
parameter_list|,
name|QIcon
operator|::
name|State
name|state
parameter_list|)
block|{
name|QPixmap
name|pm
argument_list|(
name|size
argument_list|)
decl_stmt|;
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|pm
argument_list|)
decl_stmt|;
name|paint
argument_list|(
operator|&
name|p
argument_list|,
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
argument_list|)
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
expr_stmt|;
block|}
return|return
name|pm
return|;
block|}
end_function
begin_comment
comment|/*!   Called by QIcon::addPixmap(). Adds a specialized \a pixmap for the given   \a mode and \a state. The default pixmap-based engine stores any supplied   pixmaps, and it uses them instead of scaled pixmaps if the size of a pixmap   matches the size of icon requested. Custom icon engines that implement   scalable vector formats are free to ignores any extra pixmaps.  */
end_comment
begin_function
DECL|function|addPixmap
name|void
name|QIconEngine
operator|::
name|addPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
comment|/*pixmap*/
parameter_list|,
name|QIcon
operator|::
name|Mode
comment|/*mode*/
parameter_list|,
name|QIcon
operator|::
name|State
comment|/*state*/
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!  Called by QIcon::addFile(). Adds a specialized pixmap from the   file with the given \a fileName, \a size, \a mode and \a state. The   default pixmap-based engine stores any supplied file names, and it   loads the pixmaps on demand instead of using scaled pixmaps if the   size of a pixmap matches the size of icon requested. Custom icon   engines that implement scalable vector formats are free to ignores   any extra files.  */
end_comment
begin_function
DECL|function|addFile
name|void
name|QIconEngine
operator|::
name|addFile
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/*fileName*/
parameter_list|,
specifier|const
name|QSize
modifier|&
comment|/*size*/
parameter_list|,
name|QIcon
operator|::
name|Mode
comment|/*mode*/
parameter_list|,
name|QIcon
operator|::
name|State
comment|/*state*/
parameter_list|)
block|{ }
end_function
begin_comment
comment|// version 2 functions
end_comment
begin_comment
comment|/*!     \class QIconEngineV2      \brief The QIconEngineV2 class provides an abstract base class for QIcon renderers.      \ingroup painting     \inmodule QtWidgets      \since 4.3      An icon engine renders \l{QIcon}s. With icon engines, you can     customize icons. Qt provides a default engine that makes icons     adhere to the current style by scaling the icons and providing a     disabled appearance.      An engine is installed on an icon either through a QIcon     constructor or through a QIconEnginePluginV2. The plugins are used     by Qt if a specific engine is not given when the icon is created.     See the QIconEngineV2 class description to learn how to create     icon engine plugins.      An icon engine provides the rendering functions for a QIcon. Each     icon has a corresponding icon engine that is responsible for drawing     the icon with a requested size, mode and state.      QIconEngineV2 extends the API of QIconEngine to allow streaming of     the icon engine contents, and should be used instead of QIconEngine     for implementing new icon engines.      \sa QIconEnginePluginV2  */
end_comment
begin_comment
comment|/*!     \enum QIconEngineV2::IconEngineHook     \since 4.5      These enum values are used for virtual_hook() to allow additional     queries to icon engine without breaking binary compatibility.      \value AvailableSizesHook Allows to query the sizes of the     contained pixmaps for pixmap-based engines. The \a data argument     of the virtual_hook() function is a AvailableSizesArgument pointer     that should be filled with icon sizes. Engines that work in terms     of a scalable, vectorial format normally return an empty list.      \value IconNameHook Allows to query the name used to create the     icon, for example when instantiating an icon using     QIcon::fromTheme().      \sa virtual_hook()  */
end_comment
begin_comment
comment|/*!     \class QIconEngineV2::AvailableSizesArgument     \since 4.5      \inmodule QtWidgets      This struct represents arguments to virtual_hook() function when     \a id parameter is QIconEngineV2::AvailableSizesHook.      \sa virtual_hook(), QIconEngineV2::IconEngineHook  */
end_comment
begin_comment
comment|/*!     \variable QIconEngineV2::AvailableSizesArgument::mode     \brief the requested mode of an image.      \sa QIcon::Mode */
end_comment
begin_comment
comment|/*!     \variable QIconEngineV2::AvailableSizesArgument::state     \brief the requested state of an image.      \sa QIcon::State */
end_comment
begin_comment
comment|/*!     \variable QIconEngineV2::AvailableSizesArgument::sizes      \brief image sizes that are available with specified \a mode and     \a state. This is an output parameter and is filled after call to     virtual_hook(). Engines that work in terms of a scalable,     vectorial format normally return an empty list. */
end_comment
begin_comment
comment|/*!     Returns a key that identifies this icon engine.  */
end_comment
begin_function
DECL|function|key
name|QString
name|QIconEngineV2
operator|::
name|key
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a clone of this icon engine.  */
end_comment
begin_function
DECL|function|clone
name|QIconEngineV2
modifier|*
name|QIconEngineV2
operator|::
name|clone
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Reads icon engine contents from the QDataStream \a in. Returns     true if the contents were read; otherwise returns false.      QIconEngineV2's default implementation always return false.  */
end_comment
begin_function
DECL|function|read
name|bool
name|QIconEngineV2
operator|::
name|read
parameter_list|(
name|QDataStream
modifier|&
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Writes the contents of this engine to the QDataStream \a out.     Returns true if the contents were written; otherwise returns false.      QIconEngineV2's default implementation always return false.  */
end_comment
begin_function
DECL|function|write
name|bool
name|QIconEngineV2
operator|::
name|write
parameter_list|(
name|QDataStream
modifier|&
parameter_list|)
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.5      Additional method to allow extending QIconEngineV2 without     adding new virtual methods (and without breaking binary compatibility).     The actual action and format of \a data depends on \a id argument     which is in fact a constant from IconEngineHook enum.      \sa IconEngineHook */
end_comment
begin_function
DECL|function|virtual_hook
name|void
name|QIconEngineV2
operator|::
name|virtual_hook
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
switch|switch
condition|(
name|id
condition|)
block|{
case|case
name|QIconEngineV2
operator|::
name|AvailableSizesHook
case|:
block|{
name|QIconEngineV2
operator|::
name|AvailableSizesArgument
modifier|&
name|arg
init|=
operator|*
cast|reinterpret_cast
argument_list|<
name|QIconEngineV2
operator|::
name|AvailableSizesArgument
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|arg
operator|.
name|sizes
operator|.
name|clear
argument_list|()
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
block|}
end_function
begin_comment
comment|/*!     \since 4.5      Returns sizes of all images that are contained in the engine for the     specific \a mode and \a state.      \note This is a helper method and the actual work is done by     virtual_hook() method, hence this method depends on icon engine support     and may not work with all icon engines.  */
end_comment
begin_function
DECL|function|availableSizes
name|QList
argument_list|<
name|QSize
argument_list|>
name|QIconEngineV2
operator|::
name|availableSizes
parameter_list|(
name|QIcon
operator|::
name|Mode
name|mode
parameter_list|,
name|QIcon
operator|::
name|State
name|state
parameter_list|)
block|{
name|AvailableSizesArgument
name|arg
decl_stmt|;
name|arg
operator|.
name|mode
operator|=
name|mode
expr_stmt|;
name|arg
operator|.
name|state
operator|=
name|state
expr_stmt|;
name|virtual_hook
argument_list|(
name|QIconEngineV2
operator|::
name|AvailableSizesHook
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|arg
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|arg
operator|.
name|sizes
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.7      Returns the name used to create the engine, if available.      \note This is a helper method and the actual work is done by     virtual_hook() method, hence this method depends on icon engine support     and may not work with all icon engines.  */
end_comment
begin_function
DECL|function|iconName
name|QString
name|QIconEngineV2
operator|::
name|iconName
parameter_list|()
block|{
name|QString
name|name
decl_stmt|;
name|virtual_hook
argument_list|(
name|QIconEngineV2
operator|::
name|IconNameHook
argument_list|,
cast|reinterpret_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|name
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
