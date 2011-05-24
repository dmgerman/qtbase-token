begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qs60style.h"
end_include
begin_include
include|#
directive|include
file|"qs60style_p.h"
end_include
begin_include
include|#
directive|include
file|"qfile.h"
end_include
begin_include
include|#
directive|include
file|"qhash.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qpicture.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"qtransform.h"
end_include
begin_include
include|#
directive|include
file|"qlayout.h"
end_include
begin_include
include|#
directive|include
file|"qpixmapcache.h"
end_include
begin_include
include|#
directive|include
file|"qmetaobject.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"qbuffer.h"
end_include
begin_include
include|#
directive|include
file|"qdesktopwidget.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_S60
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_PLUGIN
argument_list|)
end_if
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|blobVersion
specifier|static
specifier|const
name|quint32
name|blobVersion
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|pictureSize
specifier|static
specifier|const
name|int
name|pictureSize
init|=
literal|256
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if
begin_define
DECL|macro|__FUNCTION__
define|#
directive|define
name|__FUNCTION__
value|__func__
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|saveThemeToBlob
name|bool
name|saveThemeToBlob
parameter_list|(
specifier|const
name|QString
modifier|&
name|themeBlob
parameter_list|,
specifier|const
name|QHash
argument_list|<
name|QString
argument_list|,
name|QPicture
argument_list|>
modifier|&
name|partPictures
parameter_list|,
specifier|const
name|QHash
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|,
name|QColor
argument_list|>
modifier|&
name|colors
parameter_list|)
block|{
name|QFile
name|blob
argument_list|(
name|themeBlob
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|blob
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|": Could not create blob: "
operator|<<
name|themeBlob
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QByteArray
name|data
decl_stmt|;
name|QBuffer
name|dataBuffer
argument_list|(
operator|&
name|data
argument_list|)
decl_stmt|;
name|dataBuffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|dataOut
argument_list|(
operator|&
name|dataBuffer
argument_list|)
decl_stmt|;
specifier|const
name|int
name|colorsCount
init|=
name|colors
operator|.
name|count
argument_list|()
decl_stmt|;
name|dataOut
operator|<<
name|colorsCount
expr_stmt|;
specifier|const
name|QList
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|>
name|colorKeys
init|=
name|colors
operator|.
name|keys
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|colorsCount
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
modifier|&
name|key
init|=
name|colorKeys
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|dataOut
operator|<<
name|key
expr_stmt|;
specifier|const
name|QColor
name|color
init|=
name|colors
operator|.
name|value
argument_list|(
name|key
argument_list|)
decl_stmt|;
name|dataOut
operator|<<
name|color
expr_stmt|;
block|}
name|dataOut
operator|<<
name|partPictures
operator|.
name|count
argument_list|()
expr_stmt|;
name|QHashIterator
argument_list|<
name|QString
argument_list|,
name|QPicture
argument_list|>
name|i
argument_list|(
name|partPictures
argument_list|)
decl_stmt|;
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
name|dataOut
operator|<<
name|i
operator|.
name|key
argument_list|()
expr_stmt|;
name|dataOut
operator|<<
name|i
operator|.
name|value
argument_list|()
expr_stmt|;
comment|// the QPicture
block|}
name|QDataStream
name|blobOut
argument_list|(
operator|&
name|blob
argument_list|)
decl_stmt|;
name|blobOut
operator|<<
name|blobVersion
expr_stmt|;
name|blobOut
operator|<<
name|qCompress
argument_list|(
name|data
argument_list|)
expr_stmt|;
return|return
name|blobOut
operator|.
name|status
argument_list|()
operator|==
name|QDataStream
operator|::
name|Ok
return|;
block|}
end_function
begin_function
DECL|function|loadThemeFromBlob
name|bool
name|loadThemeFromBlob
parameter_list|(
specifier|const
name|QString
modifier|&
name|themeBlob
parameter_list|,
name|QHash
argument_list|<
name|QString
argument_list|,
name|QPicture
argument_list|>
modifier|&
name|partPictures
parameter_list|,
name|QHash
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|,
name|QColor
argument_list|>
modifier|&
name|colors
parameter_list|)
block|{
name|QFile
name|blob
argument_list|(
name|themeBlob
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|blob
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|": Could not read blob: "
operator|<<
name|themeBlob
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QDataStream
name|blobIn
argument_list|(
operator|&
name|blob
argument_list|)
decl_stmt|;
name|quint32
name|version
decl_stmt|;
name|blobIn
operator|>>
name|version
expr_stmt|;
if|if
condition|(
name|version
operator|!=
name|blobVersion
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|": Invalid blob version: "
operator|<<
name|version
operator|<<
literal|" ...expected: "
operator|<<
name|blobVersion
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QByteArray
name|data
decl_stmt|;
name|blobIn
operator|>>
name|data
expr_stmt|;
name|data
operator|=
name|qUncompress
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|QBuffer
name|dataBuffer
argument_list|(
operator|&
name|data
argument_list|)
decl_stmt|;
name|dataBuffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QDataStream
name|dataIn
argument_list|(
operator|&
name|dataBuffer
argument_list|)
decl_stmt|;
name|int
name|colorsCount
decl_stmt|;
name|dataIn
operator|>>
name|colorsCount
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|colorsCount
condition|;
operator|++
name|i
control|)
block|{
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|key
decl_stmt|;
name|dataIn
operator|>>
name|key
expr_stmt|;
name|QColor
name|value
decl_stmt|;
name|dataIn
operator|>>
name|value
expr_stmt|;
name|colors
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
name|int
name|picturesCount
decl_stmt|;
name|dataIn
operator|>>
name|picturesCount
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|picturesCount
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|key
decl_stmt|;
name|dataIn
operator|>>
name|key
expr_stmt|;
name|QPicture
name|value
decl_stmt|;
name|dataIn
operator|>>
name|value
expr_stmt|;
name|value
operator|.
name|setBoundingRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pictureSize
argument_list|,
name|pictureSize
argument_list|)
argument_list|)
expr_stmt|;
comment|// Bug? The forced bounding rect was not deserialized.
name|partPictures
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dataIn
operator|.
name|status
argument_list|()
operator|!=
name|QDataStream
operator|::
name|Ok
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|": Invalid data blob: "
operator|<<
name|themeBlob
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
begin_class
DECL|class|QS60StyleModeSpecifics
class|class
name|QS60StyleModeSpecifics
block|{
public|public:
specifier|static
name|QPixmap
name|skinnedGraphics
parameter_list|(
name|QS60StyleEnums
operator|::
name|SkinParts
name|stylepart
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QS60StylePrivate
operator|::
name|SkinElementFlags
name|flags
parameter_list|)
function_decl|;
DECL|member|m_partPictures
specifier|static
name|QHash
argument_list|<
name|QString
argument_list|,
name|QPicture
argument_list|>
name|m_partPictures
decl_stmt|;
DECL|member|m_colors
specifier|static
name|QHash
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|,
name|QColor
argument_list|>
name|m_colors
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|m_partPictures
name|QHash
argument_list|<
name|QString
argument_list|,
name|QPicture
argument_list|>
name|QS60StyleModeSpecifics
operator|::
name|m_partPictures
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_colors
name|QHash
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|,
name|QColor
argument_list|>
name|QS60StyleModeSpecifics
operator|::
name|m_colors
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QS60StylePrivate
name|QS60StylePrivate
operator|::
name|QS60StylePrivate
parameter_list|()
block|{
name|setCurrentLayout
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|s60Color
name|QColor
name|QS60StylePrivate
operator|::
name|s60Color
parameter_list|(
name|QS60StyleEnums
operator|::
name|ColorLists
name|list
parameter_list|,
name|int
name|index
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|)
block|{
specifier|const
name|QString
name|listKey
init|=
name|QS60Style
operator|::
name|colorListKeys
argument_list|()
operator|.
name|at
argument_list|(
name|list
argument_list|)
decl_stmt|;
return|return
name|QS60StylePrivate
operator|::
name|stateColor
argument_list|(
name|QS60StyleModeSpecifics
operator|::
name|m_colors
operator|.
name|value
argument_list|(
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|(
name|listKey
argument_list|,
name|index
argument_list|)
argument_list|)
argument_list|,
name|option
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|part
name|QPixmap
name|QS60StylePrivate
operator|::
name|part
parameter_list|(
name|QS60StyleEnums
operator|::
name|SkinParts
name|part
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
name|QS60StylePrivate
operator|::
name|SkinElementFlags
name|flags
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|painter
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|partKey
init|=
name|QS60Style
operator|::
name|partKeys
argument_list|()
operator|.
name|at
argument_list|(
name|part
argument_list|)
decl_stmt|;
specifier|const
name|QPicture
name|partPicture
init|=
name|QS60StyleModeSpecifics
operator|::
name|m_partPictures
operator|.
name|value
argument_list|(
name|partKey
argument_list|)
decl_stmt|;
name|QSize
name|partSize
argument_list|(
name|partPicture
operator|.
name|boundingRect
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|flags
operator|&
operator|(
name|SF_PointEast
operator||
name|SF_PointWest
operator|)
condition|)
block|{
specifier|const
name|int
name|temp
init|=
name|partSize
operator|.
name|width
argument_list|()
decl_stmt|;
name|partSize
operator|.
name|setWidth
argument_list|(
name|partSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|partSize
operator|.
name|setHeight
argument_list|(
name|temp
argument_list|)
expr_stmt|;
block|}
specifier|const
name|qreal
name|scaleX
init|=
name|size
operator|.
name|width
argument_list|()
operator|/
operator|(
name|qreal
operator|)
name|partSize
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|qreal
name|scaleY
init|=
name|size
operator|.
name|height
argument_list|()
operator|/
operator|(
name|qreal
operator|)
name|partSize
operator|.
name|height
argument_list|()
decl_stmt|;
name|QImage
name|partImage
argument_list|(
name|size
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
name|partImage
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|resultPainter
argument_list|(
operator|&
name|partImage
argument_list|)
decl_stmt|;
name|QTransform
name|t
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|SF_PointEast
condition|)
name|t
operator|.
name|translate
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|SF_PointSouth
condition|)
name|t
operator|.
name|translate
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|SF_PointWest
condition|)
name|t
operator|.
name|translate
argument_list|(
literal|0
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|t
operator|.
name|scale
argument_list|(
name|scaleX
argument_list|,
name|scaleY
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|SF_PointEast
condition|)
name|t
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|SF_PointSouth
condition|)
name|t
operator|.
name|rotate
argument_list|(
literal|180
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|flags
operator|&
name|SF_PointWest
condition|)
name|t
operator|.
name|rotate
argument_list|(
literal|270
argument_list|)
expr_stmt|;
name|resultPainter
operator|.
name|setTransform
argument_list|(
name|t
argument_list|,
literal|true
argument_list|)
expr_stmt|;
cast|const_cast
argument_list|<
name|QPicture
operator|*
argument_list|>
argument_list|(
operator|&
name|partPicture
argument_list|)
operator|->
name|play
argument_list|(
operator|&
name|resultPainter
argument_list|)
expr_stmt|;
name|resultPainter
operator|.
name|end
argument_list|()
expr_stmt|;
name|QPixmap
name|result
init|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|partImage
argument_list|)
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|SF_StateDisabled
condition|)
block|{
name|QStyleOption
name|opt
decl_stmt|;
name|QPalette
modifier|*
name|themePalette
init|=
name|QS60StylePrivate
operator|::
name|themePalette
argument_list|()
decl_stmt|;
if|if
condition|(
name|themePalette
condition|)
name|opt
operator|.
name|palette
operator|=
operator|*
name|themePalette
expr_stmt|;
name|result
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|generatedIconPixmap
argument_list|(
name|QIcon
operator|::
name|Disabled
argument_list|,
name|result
argument_list|,
operator|&
name|opt
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|frame
name|QPixmap
name|QS60StylePrivate
operator|::
name|frame
parameter_list|(
name|SkinFrameElements
name|frame
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|SkinElementFlags
name|flags
parameter_list|)
block|{
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|center
init|=
name|m_frameElementsData
index|[
name|frame
index|]
operator|.
name|center
decl_stmt|;
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|topLeft
init|=
name|QS60StyleEnums
operator|::
name|SkinParts
argument_list|(
name|center
operator|-
literal|8
argument_list|)
decl_stmt|;
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|topRight
init|=
name|QS60StyleEnums
operator|::
name|SkinParts
argument_list|(
name|center
operator|-
literal|7
argument_list|)
decl_stmt|;
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|bottomLeft
init|=
name|QS60StyleEnums
operator|::
name|SkinParts
argument_list|(
name|center
operator|-
literal|6
argument_list|)
decl_stmt|;
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|bottomRight
init|=
name|QS60StyleEnums
operator|::
name|SkinParts
argument_list|(
name|center
operator|-
literal|5
argument_list|)
decl_stmt|;
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|top
init|=
name|QS60StyleEnums
operator|::
name|SkinParts
argument_list|(
name|center
operator|-
literal|4
argument_list|)
decl_stmt|;
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|bottom
init|=
name|QS60StyleEnums
operator|::
name|SkinParts
argument_list|(
name|center
operator|-
literal|3
argument_list|)
decl_stmt|;
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|left
init|=
name|QS60StyleEnums
operator|::
name|SkinParts
argument_list|(
name|center
operator|-
literal|2
argument_list|)
decl_stmt|;
specifier|const
name|QS60StyleEnums
operator|::
name|SkinParts
name|right
init|=
name|QS60StyleEnums
operator|::
name|SkinParts
argument_list|(
name|center
operator|-
literal|1
argument_list|)
decl_stmt|;
comment|// The size of topLeft defines all other sizes
specifier|const
name|QSize
name|cornerSize
argument_list|(
name|partSize
argument_list|(
name|topLeft
argument_list|)
argument_list|)
decl_stmt|;
comment|// if frame is so small that corners would cover it completely, draw only center piece
specifier|const
name|bool
name|drawOnlyCenter
init|=
literal|2
operator|*
name|cornerSize
operator|.
name|width
argument_list|()
operator|+
literal|1
operator|>=
name|size
operator|.
name|width
argument_list|()
operator|||
literal|2
operator|*
name|cornerSize
operator|.
name|height
argument_list|()
operator|+
literal|1
operator|>=
name|size
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|int
name|cornerWidth
init|=
name|cornerSize
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|cornerHeight
init|=
name|cornerSize
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|int
name|rectWidth
init|=
name|size
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|rectHeight
init|=
name|size
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|QRect
name|rect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|size
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|topLeftRect
init|=
name|QRect
argument_list|(
name|rect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|cornerSize
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|topRect
init|=
name|rect
operator|.
name|adjusted
argument_list|(
name|cornerWidth
argument_list|,
literal|0
argument_list|,
operator|-
name|cornerWidth
argument_list|,
operator|-
operator|(
name|rectHeight
operator|-
name|cornerHeight
operator|)
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|topRightRect
init|=
name|topLeftRect
operator|.
name|translated
argument_list|(
name|rectWidth
operator|-
name|cornerWidth
argument_list|,
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|rightRect
init|=
name|rect
operator|.
name|adjusted
argument_list|(
name|rectWidth
operator|-
name|cornerWidth
argument_list|,
name|cornerHeight
argument_list|,
literal|0
argument_list|,
operator|-
name|cornerHeight
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|bottomRightRect
init|=
name|topRightRect
operator|.
name|translated
argument_list|(
literal|0
argument_list|,
name|rectHeight
operator|-
name|cornerHeight
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|bottomRect
init|=
name|topRect
operator|.
name|translated
argument_list|(
literal|0
argument_list|,
name|rectHeight
operator|-
name|cornerHeight
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|bottomLeftRect
init|=
name|topLeftRect
operator|.
name|translated
argument_list|(
literal|0
argument_list|,
name|rectHeight
operator|-
name|cornerHeight
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|leftRect
init|=
name|rightRect
operator|.
name|translated
argument_list|(
name|cornerWidth
operator|-
name|rectWidth
argument_list|,
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|centerRect
init|=
name|drawOnlyCenter
condition|?
name|rect
else|:
name|rect
operator|.
name|adjusted
argument_list|(
name|cornerWidth
argument_list|,
name|cornerWidth
argument_list|,
operator|-
name|cornerWidth
argument_list|,
operator|-
name|cornerWidth
argument_list|)
decl_stmt|;
name|QPixmap
name|result
argument_list|(
name|size
argument_list|)
decl_stmt|;
name|result
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
if|#
directive|if
literal|0
block|painter.save();     painter.setOpacity(.3);     painter.fillRect(topLeftRect, Qt::red);     painter.fillRect(topRect, Qt::green);     painter.fillRect(topRightRect, Qt::blue);     painter.fillRect(rightRect, Qt::green);     painter.fillRect(bottomRightRect, Qt::red);     painter.fillRect(bottomRect, Qt::blue);     painter.fillRect(bottomLeftRect, Qt::green);     painter.fillRect(leftRect, Qt::blue);     painter.fillRect(centerRect, Qt::red);     painter.restore();
else|#
directive|else
name|drawPart
argument_list|(
name|topLeft
argument_list|,
operator|&
name|painter
argument_list|,
name|topLeftRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|drawPart
argument_list|(
name|top
argument_list|,
operator|&
name|painter
argument_list|,
name|topRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|drawPart
argument_list|(
name|topRight
argument_list|,
operator|&
name|painter
argument_list|,
name|topRightRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|drawPart
argument_list|(
name|right
argument_list|,
operator|&
name|painter
argument_list|,
name|rightRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|drawPart
argument_list|(
name|bottomRight
argument_list|,
operator|&
name|painter
argument_list|,
name|bottomRightRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|drawPart
argument_list|(
name|bottom
argument_list|,
operator|&
name|painter
argument_list|,
name|bottomRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|drawPart
argument_list|(
name|bottomLeft
argument_list|,
operator|&
name|painter
argument_list|,
name|bottomLeftRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|drawPart
argument_list|(
name|left
argument_list|,
operator|&
name|painter
argument_list|,
name|leftRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|drawPart
argument_list|(
name|center
argument_list|,
operator|&
name|painter
argument_list|,
name|centerRect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|backgroundTexture
name|QPixmap
name|QS60StylePrivate
operator|::
name|backgroundTexture
parameter_list|(
name|bool
comment|/*skipCreation*/
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_background
condition|)
block|{
specifier|const
name|QSize
name|size
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|size
argument_list|()
decl_stmt|;
name|QPixmap
name|background
init|=
name|part
argument_list|(
name|QS60StyleEnums
operator|::
name|SP_QsnBgScreen
argument_list|,
name|size
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|m_background
operator|=
operator|new
name|QPixmap
argument_list|(
name|background
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|m_background
return|;
block|}
end_function
begin_function
DECL|function|isTouchSupported
name|bool
name|QS60StylePrivate
operator|::
name|isTouchSupported
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
return|return
operator|!
name|QApplication
operator|::
name|keypadNavigationEnabled
argument_list|()
return|;
else|#
directive|else
return|return
literal|true
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|isToolBarBackground
name|bool
name|QS60StylePrivate
operator|::
name|isToolBarBackground
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hasSliderGrooveGraphic
name|bool
name|QS60StylePrivate
operator|::
name|hasSliderGrooveGraphic
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isSingleClickUi
name|bool
name|QS60StylePrivate
operator|::
name|isSingleClickUi
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|s60Font_specific
name|QFont
name|QS60StylePrivate
operator|::
name|s60Font_specific
parameter_list|(
name|QS60StyleEnums
operator|::
name|FontCategories
name|fontCategory
parameter_list|,
name|int
name|pointSize
parameter_list|,
name|bool
name|resolveFontSize
parameter_list|)
block|{
name|QFont
name|result
decl_stmt|;
if|if
condition|(
name|resolveFontSize
condition|)
name|result
operator|.
name|setPointSize
argument_list|(
name|pointSize
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|fontCategory
condition|)
block|{
case|case
name|QS60StyleEnums
operator|::
name|FC_Primary
case|:
name|result
operator|.
name|setBold
argument_list|(
literal|true
argument_list|)
expr_stmt|;
break|break;
case|case
name|QS60StyleEnums
operator|::
name|FC_Secondary
case|:
case|case
name|QS60StyleEnums
operator|::
name|FC_Title
case|:
case|case
name|QS60StyleEnums
operator|::
name|FC_PrimarySmall
case|:
case|case
name|QS60StyleEnums
operator|::
name|FC_Digital
case|:
case|case
name|QS60StyleEnums
operator|::
name|FC_Undefined
case|:
default|default:
break|break;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|currentAnimationFrame
name|int
name|QS60StylePrivate
operator|::
name|currentAnimationFrame
parameter_list|(
name|QS60StyleEnums
operator|::
name|SkinParts
name|part
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!   Constructs a QS60Style object. */
end_comment
begin_constructor
DECL|function|QS60Style
name|QS60Style
operator|::
name|QS60Style
parameter_list|()
member_init_list|:
name|QCommonStyle
argument_list|(
operator|*
operator|new
name|QS60StylePrivate
argument_list|)
block|{
specifier|const
name|QString
name|defaultBlob
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|":/trolltech/styles/s60style/images/defaults60theme.blob"
argument_list|)
decl_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|defaultBlob
argument_list|)
condition|)
name|loadS60ThemeFromBlob
argument_list|(
name|defaultBlob
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_macro
name|Q_GLOBAL_STATIC_WITH_INITIALIZER
argument_list|(
argument|QStringList
argument_list|,
argument|enumPartKeys
argument_list|,
argument|{     const int enumIndex = QS60StyleEnums::staticMetaObject.indexOfEnumerator(
literal|"SkinParts"
argument|);     Q_ASSERT(enumIndex>=
literal|0
argument|);     const QMetaEnum metaEnum = QS60StyleEnums::staticMetaObject.enumerator(enumIndex);     for (int i =
literal|0
argument|; i< metaEnum.keyCount(); ++i) {         const QString enumKey = QString::fromLatin1(metaEnum.key(i));         QString partKey;
comment|// Following loop does following conversions: "SP_QgnNoteInfo" to "qgn_note_info"...
argument|for (int charPosition =
literal|3
argument|; charPosition< enumKey.length(); charPosition++) {             if (charPosition>
literal|3
argument|&& enumKey[charPosition].isUpper())                 partKey.append(QChar::fromLatin1(
literal|'_'
argument|));             partKey.append(enumKey[charPosition].toLower());         }         x->append(partKey);     } }
argument_list|)
end_macro
begin_function
DECL|function|partKeys
name|QStringList
name|QS60Style
operator|::
name|partKeys
parameter_list|()
block|{
return|return
operator|*
name|enumPartKeys
argument_list|()
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC_WITH_INITIALIZER
argument_list|(
argument|QStringList
argument_list|,
argument|enumColorListKeys
argument_list|,
argument|{     const int enumIndex = QS60StyleEnums::staticMetaObject.indexOfEnumerator(
literal|"ColorLists"
argument|);     Q_ASSERT(enumIndex>=
literal|0
argument|);     const QMetaEnum metaEnum = QS60StyleEnums::staticMetaObject.enumerator(enumIndex);     for (int i =
literal|0
argument|; i< metaEnum.keyCount(); i++) {         const QString enumKey = QString::fromLatin1(metaEnum.key(i));
comment|// Following line does following conversions: CL_QsnTextColors to "text"...
argument|x->append(enumKey.mid(
literal|6
argument|, enumKey.length() -
literal|12
argument|).toLower());     } }
argument_list|)
end_macro
begin_function
DECL|function|colorListKeys
name|QStringList
name|QS60Style
operator|::
name|colorListKeys
parameter_list|()
block|{
return|return
operator|*
name|enumColorListKeys
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setS60Theme
name|void
name|QS60Style
operator|::
name|setS60Theme
parameter_list|(
specifier|const
name|QHash
argument_list|<
name|QString
argument_list|,
name|QPicture
argument_list|>
modifier|&
name|parts
parameter_list|,
specifier|const
name|QHash
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|,
name|QColor
argument_list|>
modifier|&
name|colors
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QS60Style
argument_list|)
expr_stmt|;
name|QS60StyleModeSpecifics
operator|::
name|m_partPictures
operator|=
name|parts
expr_stmt|;
name|QS60StyleModeSpecifics
operator|::
name|m_colors
operator|=
name|colors
expr_stmt|;
name|d
operator|->
name|clearCaches
argument_list|(
name|QS60StylePrivate
operator|::
name|CC_ThemeChange
argument_list|)
expr_stmt|;
name|d
operator|->
name|setBackgroundTexture
argument_list|(
name|qApp
argument_list|)
expr_stmt|;
name|d
operator|->
name|setThemePalette
argument_list|(
name|qApp
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadS60ThemeFromBlob
name|bool
name|QS60Style
operator|::
name|loadS60ThemeFromBlob
parameter_list|(
specifier|const
name|QString
modifier|&
name|blobFile
parameter_list|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QPicture
argument_list|>
name|partPictures
decl_stmt|;
name|QHash
argument_list|<
name|QPair
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
argument_list|,
name|QColor
argument_list|>
name|colors
decl_stmt|;
if|if
condition|(
operator|!
name|loadThemeFromBlob
argument_list|(
name|blobFile
argument_list|,
name|partPictures
argument_list|,
name|colors
argument_list|)
condition|)
return|return
literal|false
return|;
name|setS60Theme
argument_list|(
name|partPictures
argument_list|,
name|colors
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|saveS60ThemeToBlob
name|bool
name|QS60Style
operator|::
name|saveS60ThemeToBlob
parameter_list|(
specifier|const
name|QString
modifier|&
name|blobFile
parameter_list|)
specifier|const
block|{
return|return
name|saveThemeToBlob
argument_list|(
name|blobFile
argument_list|,
name|QS60StyleModeSpecifics
operator|::
name|m_partPictures
argument_list|,
name|QS60StyleModeSpecifics
operator|::
name|m_colors
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_s60_fill_background_offset
name|QPoint
name|qt_s60_fill_background_offset
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|targetWidget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|targetWidget
argument_list|)
return|return
name|QPoint
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_S60 || QT_PLUGIN
end_comment
end_unit
