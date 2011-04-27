begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmargins.h"
end_include
begin_include
include|#
directive|include
file|"qdatastream.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QMargins     \ingroup painting     \since 4.6      \brief The QMargins class defines the four margins of a rectangle.       QMargin defines a set of four margins; left, top, right and bottom,     that describe the size of the borders surrounding a rectangle.      The isNull() function returns true only if all margins are set to zero.      QMargin objects can be streamed as well as compared. */
comment|/*****************************************************************************   QMargins member functions  *****************************************************************************/
comment|/*!     \fn QMargins::QMargins()      Constructs a margins object with all margins set to 0.      \sa isNull() */
comment|/*!     \fn QMargins::QMargins(int left, int top, int right, int bottom)      Constructs margins with the given \a left, \a top, \a right, \a bottom      \sa setLeft(), setRight(), setTop(), setBottom() */
comment|/*!     \fn bool QMargins::isNull() const      Returns true if all margins are is 0; otherwise returns     false. */
comment|/*!     \fn int QMargins::left() const      Returns the left margin.      \sa setLeft() */
comment|/*!     \fn int QMargins::top() const      Returns the top margin.      \sa setTop() */
comment|/*!     \fn int QMargins::right() const      Returns the right margin. */
comment|/*!     \fn int QMargins::bottom() const      Returns the bottom margin. */
comment|/*!     \fn void QMargins::setLeft(int left)      Sets the left margin to \a left. */
comment|/*!     \fn void QMargins::setTop(int Top)      Sets the Top margin to \a Top. */
comment|/*!     \fn void QMargins::setRight(int right)      Sets the right margin to \a right. */
comment|/*!     \fn void QMargins::setBottom(int bottom)      Sets the bottom margin to \a bottom. */
comment|/*!     \fn bool operator==(const QMargins&m1, const QMargins&m2)     \relates QMargins      Returns true if \a m1 and \a m2 are equal; otherwise returns false. */
comment|/*!     \fn bool operator!=(const QMargins&m1, const QMargins&m2)     \relates QMargins      Returns true if \a m1 and \a m2 are different; otherwise returns false. */
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QMargins
modifier|&
name|m
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QMargins("
operator|<<
name|m
operator|.
name|left
argument_list|()
operator|<<
literal|", "
operator|<<
name|m
operator|.
name|top
argument_list|()
operator|<<
literal|", "
operator|<<
name|m
operator|.
name|right
argument_list|()
operator|<<
literal|", "
operator|<<
name|m
operator|.
name|bottom
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
