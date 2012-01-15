begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QREGION_H
end_ifndef
begin_define
DECL|macro|QREGION_H
define|#
directive|define
name|QREGION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|template
decl|<
name|class
name|T
decl|>
name|class
name|QVector
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QRegionPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QBitmap
name|class
name|QBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRegion
block|{
name|public
label|:
enum|enum
name|RegionType
block|{
name|Rectangle
block|,
name|Ellipse
block|}
enum|;
name|QRegion
argument_list|()
expr_stmt|;
name|QRegion
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|RegionType t = Rectangle
argument_list|)
empty_stmt|;
name|QRegion
argument_list|(
argument|const QRect&r
argument_list|,
argument|RegionType t = Rectangle
argument_list|)
empty_stmt|;
name|QRegion
argument_list|(
argument|const QPolygon&pa
argument_list|,
argument|Qt::FillRule fillRule = Qt::OddEvenFill
argument_list|)
empty_stmt|;
name|QRegion
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
expr_stmt|;
name|QRegion
argument_list|(
specifier|const
name|QBitmap
operator|&
name|bitmap
argument_list|)
expr_stmt|;
operator|~
name|QRegion
argument_list|()
expr_stmt|;
name|QRegion
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QRegion
operator|&
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QRegion
modifier|&
name|operator
init|=
operator|(
name|QRegion
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QRegion
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|contains
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
name|bool
name|contains
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|void
name|translate
parameter_list|(
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
function_decl|;
specifier|inline
name|void
name|translate
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
name|translate
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QRegion
name|translated
argument_list|(
name|int
name|dx
argument_list|,
name|int
name|dy
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QRegion
name|translated
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
block|{
return|return
name|translated
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
name|QRegion
name|united
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QRegion
name|united
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QRegion
name|intersected
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QRegion
name|intersected
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QRegion
name|subtracted
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QRegion
name|xored
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
specifier|inline
name|QT_DEPRECATED
name|QRegion
name|unite
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
block|{
return|return
name|united
argument_list|(
name|r
argument_list|)
return|;
block|}
specifier|inline
name|QT_DEPRECATED
name|QRegion
name|unite
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
block|{
return|return
name|united
argument_list|(
name|r
argument_list|)
return|;
block|}
specifier|inline
name|QT_DEPRECATED
name|QRegion
name|intersect
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
block|{
return|return
name|intersected
argument_list|(
name|r
argument_list|)
return|;
block|}
specifier|inline
name|QT_DEPRECATED
name|QRegion
name|intersect
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
block|{
return|return
name|intersected
argument_list|(
name|r
argument_list|)
return|;
block|}
specifier|inline
name|QT_DEPRECATED
name|QRegion
name|subtract
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
block|{
return|return
name|subtracted
argument_list|(
name|r
argument_list|)
return|;
block|}
specifier|inline
name|QT_DEPRECATED
name|QRegion
name|eor
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
block|{
return|return
name|xored
argument_list|(
name|r
argument_list|)
return|;
block|}
endif|#
directive|endif
name|bool
name|intersects
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|bool
name|intersects
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|boundingRect
argument_list|()
specifier|const
expr_stmt|;
name|QVector
operator|<
name|QRect
operator|>
name|rects
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRects
parameter_list|(
specifier|const
name|QRect
modifier|*
name|rect
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|QT_DEPRECATED
name|QT_DEPRECATED
name|int
name|numRects
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|int
name|rectCount
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QRegion
name|operator
operator||
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
specifier|const
expr_stmt|;
specifier|const
name|QRegion
name|operator
operator|+
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
specifier|const
expr_stmt|;
specifier|const
name|QRegion
name|operator
operator|+
operator|(
specifier|const
name|QRect
operator|&
name|r
operator|)
specifier|const
expr_stmt|;
specifier|const
name|QRegion
name|operator
modifier|&
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QRegion
name|operator
modifier|&
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QRegion
name|operator
operator|-
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
specifier|const
expr_stmt|;
specifier|const
name|QRegion
name|operator
modifier|^
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QRegion
operator|&
name|operator
operator||=
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
expr_stmt|;
name|QRegion
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
expr_stmt|;
name|QRegion
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QRect
operator|&
name|r
operator|)
expr_stmt|;
name|QRegion
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
expr_stmt|;
name|QRegion
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|QRect
operator|&
name|r
operator|)
expr_stmt|;
name|QRegion
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
expr_stmt|;
name|QRegion
operator|&
name|operator
operator|^=
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QRegion
operator|&
name|r
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|operator
operator|==
operator|(
name|r
operator|)
operator|)
return|;
block|}
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
ifdef|#
directive|ifdef
name|qdoc
name|Handle
name|handle
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|qdoc
specifier|inline
name|void
operator|*
name|handle
argument_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|qt_rgn
return|;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QRegion
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QRegion
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
name|private
label|:
name|QRegion
name|copy
argument_list|()
specifier|const
expr_stmt|;
comment|// helper of detach.
name|void
name|detach
parameter_list|()
function_decl|;
name|Q_GUI_EXPORT
name|friend
name|bool
name|qt_region_strictContains
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|friend
struct_decl|struct
name|QRegionPrivate
struct_decl|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|void
name|exec
argument_list|(
specifier|const
name|QByteArray
operator|&
name|ba
argument_list|,
name|int
name|ver
operator|=
literal|0
argument_list|,
name|QDataStream
operator|::
name|ByteOrder
name|byteOrder
operator|=
name|QDataStream
operator|::
name|BigEndian
argument_list|)
decl_stmt|;
endif|#
directive|endif
struct|struct
name|QRegionData
block|{
name|QBasicAtomicInt
name|ref
decl_stmt|;
name|QRegionPrivate
modifier|*
name|qt_rgn
decl_stmt|;
block|}
struct|;
name|struct
name|QRegionData
modifier|*
name|d
decl_stmt|;
specifier|static
name|struct
name|QRegionData
name|shared_empty
decl_stmt|;
specifier|static
name|void
name|cleanUp
parameter_list|(
name|QRegionData
modifier|*
name|x
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*****************************************************************************   QRegion stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QRegion
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QRegion
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QRegion
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QREGION_H
end_comment
end_unit
