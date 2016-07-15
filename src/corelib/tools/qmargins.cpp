begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
comment|/*****************************************************************************   QMargins stream functions  *****************************************************************************/
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QMargins&m)     \relates QMargins      Writes the given \a margin to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
DECL|function|operator <<
name|QDataStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QDataStream
modifier|&
name|s
parameter_list|,
specifier|const
name|QMargins
modifier|&
name|m
parameter_list|)
block|{
name|s
operator|<<
name|m
operator|.
name|left
argument_list|()
operator|<<
name|m
operator|.
name|top
argument_list|()
operator|<<
name|m
operator|.
name|right
argument_list|()
operator|<<
name|m
operator|.
name|bottom
argument_list|()
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QMargins&m)     \relates QMargins      Reads a margin from the given \a stream into the given \a margin     and returns a reference to the stream.      \sa {Serializing Qt Data Types} */
end_comment
begin_function
DECL|function|operator >>
name|QDataStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QDataStream
modifier|&
name|s
parameter_list|,
name|QMargins
modifier|&
name|m
parameter_list|)
block|{
name|int
name|left
decl_stmt|,
name|top
decl_stmt|,
name|right
decl_stmt|,
name|bottom
decl_stmt|;
name|s
operator|>>
name|left
expr_stmt|;
name|m
operator|.
name|setLeft
argument_list|(
name|left
argument_list|)
expr_stmt|;
name|s
operator|>>
name|top
expr_stmt|;
name|m
operator|.
name|setTop
argument_list|(
name|top
argument_list|)
expr_stmt|;
name|s
operator|>>
name|right
expr_stmt|;
name|m
operator|.
name|setRight
argument_list|(
name|right
argument_list|)
expr_stmt|;
name|s
operator|>>
name|bottom
expr_stmt|;
name|m
operator|.
name|setBottom
argument_list|(
name|bottom
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
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
