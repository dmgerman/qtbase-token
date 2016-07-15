begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<private/qdebug_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QMargins     \inmodule QtCore     \ingroup painting     \since 4.6      \brief The QMargins class defines the four margins of a rectangle.      QMargin defines a set of four margins; left, top, right and bottom,     that describe the size of the borders surrounding a rectangle.      The isNull() function returns \c true only if all margins are set to zero.      QMargin objects can be streamed as well as compared. */
comment|/*****************************************************************************   QMargins member functions  *****************************************************************************/
comment|/*!     \fn QMargins::QMargins()      Constructs a margins object with all margins set to 0.      \sa isNull() */
comment|/*!     \fn QMargins::QMargins(int left, int top, int right, int bottom)      Constructs margins with the given \a left, \a top, \a right, \a bottom      \sa setLeft(), setRight(), setTop(), setBottom() */
comment|/*!     \fn bool QMargins::isNull() const      Returns \c true if all margins are is 0; otherwise returns     false. */
comment|/*!     \fn int QMargins::left() const      Returns the left margin.      \sa setLeft() */
comment|/*!     \fn int QMargins::top() const      Returns the top margin.      \sa setTop() */
comment|/*!     \fn int QMargins::right() const      Returns the right margin. */
comment|/*!     \fn int QMargins::bottom() const      Returns the bottom margin. */
comment|/*!     \fn void QMargins::setLeft(int left)      Sets the left margin to \a left. */
comment|/*!     \fn void QMargins::setTop(int Top)      Sets the Top margin to \a Top. */
comment|/*!     \fn void QMargins::setRight(int right)      Sets the right margin to \a right. */
comment|/*!     \fn void QMargins::setBottom(int bottom)      Sets the bottom margin to \a bottom. */
comment|/*!     \fn bool operator==(const QMargins&m1, const QMargins&m2)     \relates QMargins      Returns \c true if \a m1 and \a m2 are equal; otherwise returns \c false. */
comment|/*!     \fn bool operator!=(const QMargins&m1, const QMargins&m2)     \relates QMargins      Returns \c true if \a m1 and \a m2 are different; otherwise returns \c false. */
comment|/*!     \fn const QMargins operator+(const QMargins&m1, const QMargins&m2)     \relates QMargins      Returns a QMargins object that is the sum of the given margins, \a m1     and \a m2; each component is added separately.      \sa QMargins::operator+=(), QMargins::operator-=()      \since 5.1 */
comment|/*!     \fn const QMargins operator-(const QMargins&m1, const QMargins&m2)     \relates QMargins      Returns a QMargins object that is formed by subtracting \a m2 from     \a m1; each component is subtracted separately.      \sa QMargins::operator+=(), QMargins::operator-=()      \since 5.1 */
comment|/*!     \fn const QMargins operator+(const QMargins&lhs, int rhs)     \relates QMargins      Returns a QMargins object that is formed by adding \a rhs to     \a lhs.      \sa QMargins::operator+=(), QMargins::operator-=()      \since 5.3 */
comment|/*!     \fn const QMargins operator+(int lhs, const QMargins&rhs)     \relates QMargins      Returns a QMargins object that is formed by adding \a lhs to     \a rhs.      \sa QMargins::operator+=(), QMargins::operator-=()      \since 5.3 */
comment|/*!     \fn const QMargins operator-(const QMargins&lhs, int rhs)     \relates QMargins      Returns a QMargins object that is formed by subtracting \a rhs from     \a lhs.      \sa QMargins::operator+=(), QMargins::operator-=()      \since 5.3 */
comment|/*!     \fn const QMargins operator*(const QMargins&margins, int factor)     \relates QMargins      Returns a QMargins object that is formed by multiplying each component     of the given \a margins by \a factor.      \sa QMargins::operator*=(), QMargins::operator/=()      \since 5.1 */
comment|/*!     \fn const QMargins operator*(int factor, const QMargins&margins)     \relates QMargins     \overload      Returns a QMargins object that is formed by multiplying each component     of the given \a margins by \a factor.      \sa QMargins::operator*=(), QMargins::operator/=()      \since 5.1 */
comment|/*!     \fn const QMargins operator*(const QMargins&margins, qreal factor)     \relates QMargins     \overload      Returns a QMargins object that is formed by multiplying each component     of the given \a margins by \a factor.      \sa QMargins::operator*=(), QMargins::operator/=()      \since 5.1 */
comment|/*!     \fn const QMargins operator*(qreal factor, const QMargins&margins)     \relates QMargins     \overload      Returns a QMargins object that is formed by multiplying each component     of the given \a margins by \a factor.      \sa QMargins::operator*=(), QMargins::operator/=()      \since 5.1 */
comment|/*!     \fn const QMargins operator/(const QMargins&margins, int divisor)     \relates QMargins      Returns a QMargins object that is formed by dividing the components of     the given \a margins by the given \a divisor.      \sa QMargins::operator*=(), QMargins::operator/=()      \since 5.1 */
comment|/*!     \fn const QMargins operator/(const QMargins&, qreal)     \relates QMargins     \overload      Returns a QMargins object that is formed by dividing the components of     the given \a margins by the given \a divisor.      \sa QMargins::operator*=(), QMargins::operator/=()      \since 5.1 */
comment|/*!     \fn QMargins operator+(const QMargins&margins)     \relates QMargins      Returns a QMargin object that is formed from all components of \a margins.      \since 5.3 */
comment|/*!     \fn QMargins operator-(const QMargins&margins)     \relates QMargins      Returns a QMargin object that is formed by negating all components of \a margins.      \since 5.1 */
comment|/*!     \fn QMargins&QMargins::operator+=(const QMargins&margins)      Add each component of \a margins to the respective component of this object     and returns a reference to it.      \sa operator-=()      \since 5.1 */
comment|/*!     \fn QMargins&QMargins::operator-=(const QMargins&margins)      Subtract each component of \a margins from the respective component of this object     and returns a reference to it.      \sa operator+=()      \since 5.1 */
comment|/*!     \fn QMargins&QMargins::operator+=(int addend)     \overload      Adds the \a addend to each component of this object     and returns a reference to it.      \sa operator-=() */
comment|/*!     \fn QMargins&QMargins::operator-=(int subtrahend)     \overload      Subtracts the \a subtrahend from each component of this object     and returns a reference to it.      \sa operator+=() */
comment|/*!     \fn QMargins&QMargins::operator*=(int factor)      Multiplies each component of this object by \a factor     and returns a reference to it.      \sa operator/=()      \since 5.1 */
comment|/*!     \fn QMargins&QMargins::operator*=(qreal factor)     \overload      Multiplies each component of this object by \a factor     and returns a reference to it.      \sa operator/=()      \since 5.1 */
comment|/*!     \fn QMargins&QMargins::operator/=(int divisor)      Divides each component of this object by \a divisor     and returns a reference to it.      \sa operator*=()      \since 5.1 */
comment|/*!     \fn QMargins&QMargins::operator/=(qreal divisor)      \overload      \sa operator*=()      \since 5.1 */
comment|/*****************************************************************************   QMargins stream functions  *****************************************************************************/
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QMargins&m)     \relates QMargins      Writes margin \a m to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
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
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QMargins&m)     \relates QMargins      Reads a margin from the given \a stream into margin \a m     and returns a reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QDebugStateSaver
name|saver
argument_list|(
name|dbg
argument_list|)
decl_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
expr_stmt|;
name|dbg
operator|<<
literal|"QMargins"
operator|<<
literal|'('
expr_stmt|;
name|QtDebugUtils
operator|::
name|formatQMargins
argument_list|(
name|dbg
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|dbg
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \class QMarginsF     \inmodule QtCore     \ingroup painting     \since 5.3      \brief The QMarginsF class defines the four margins of a rectangle.      QMarginsF defines a set of four margins; left, top, right and bottom,     that describe the size of the borders surrounding a rectangle.      The isNull() function returns \c true only if all margins are set to zero.      QMarginsF objects can be streamed as well as compared. */
end_comment
begin_comment
comment|/*****************************************************************************   QMarginsF member functions  *****************************************************************************/
end_comment
begin_comment
comment|/*!     \fn QMarginsF::QMarginsF()      Constructs a margins object with all margins set to 0.      \sa isNull() */
end_comment
begin_comment
comment|/*!     \fn QMarginsF::QMarginsF(qreal left, qreal top, qreal right, qreal bottom)      Constructs margins with the given \a left, \a top, \a right, \a bottom      \sa setLeft(), setRight(), setTop(), setBottom() */
end_comment
begin_comment
comment|/*!     \fn QMarginsF::QMarginsF(const QMargins&margins)      Constructs margins copied from the given \a margins */
end_comment
begin_comment
comment|/*!     \fn bool QMarginsF::isNull() const      Returns \c true if all margins are 0; otherwise returns     false. */
end_comment
begin_comment
comment|/*!     \fn qreal QMarginsF::left() const      Returns the left margin.      \sa setLeft() */
end_comment
begin_comment
comment|/*!     \fn qreal QMarginsF::top() const      Returns the top margin.      \sa setTop() */
end_comment
begin_comment
comment|/*!     \fn qreal QMarginsF::right() const      Returns the right margin. */
end_comment
begin_comment
comment|/*!     \fn qreal QMarginsF::bottom() const      Returns the bottom margin. */
end_comment
begin_comment
comment|/*!     \fn void QMarginsF::setLeft(qreal left)      Sets the left margin to \a left. */
end_comment
begin_comment
comment|/*!     \fn void QMarginsF::setTop(qreal Top)      Sets the Top margin to \a Top. */
end_comment
begin_comment
comment|/*!     \fn void QMarginsF::setRight(qreal right)      Sets the right margin to \a right. */
end_comment
begin_comment
comment|/*!     \fn void QMarginsF::setBottom(qreal bottom)      Sets the bottom margin to \a bottom. */
end_comment
begin_comment
comment|/*!     \fn bool operator==(const QMarginsF&lhs, const QMarginsF&rhs)     \relates QMarginsF      Returns \c true if \a lhs and \a rhs are equal; otherwise returns \c false. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QMarginsF&lhs, const QMarginsF&rhs)     \relates QMarginsF      Returns \c true if \a lhs and \a rhs are different; otherwise returns \c false. */
end_comment
begin_comment
comment|/*!     \fn const QMarginsF operator+(const QMarginsF&lhs, const QMarginsF&rhs)     \relates QMarginsF      Returns a QMarginsF object that is the sum of the given margins, \a lhs     and \a rhs; each component is added separately.      \sa QMarginsF::operator+=(), QMarginsF::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QMarginsF operator-(const QMarginsF&lhs, const QMarginsF&rhs)     \relates QMarginsF      Returns a QMarginsF object that is formed by subtracting \a rhs from     \a lhs; each component is subtracted separately.      \sa QMarginsF::operator+=(), QMarginsF::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QMarginsF operator+(const QMarginsF&lhs, qreal rhs)     \relates QMarginsF      Returns a QMarginsF object that is formed by adding \a rhs to     \a lhs.      \sa QMarginsF::operator+=(), QMarginsF::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QMarginsF operator+(qreal lhs, const QMarginsF&rhs)     \relates QMarginsF      Returns a QMarginsF object that is formed by adding \a lhs to     \a rhs.      \sa QMarginsF::operator+=(), QMarginsF::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QMarginsF operator-(const QMarginsF&lhs, qreal rhs)     \relates QMarginsF      Returns a QMarginsF object that is formed by subtracting \a rhs from     \a lhs.      \sa QMarginsF::operator+=(), QMarginsF::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QMarginsF operator*(const QMarginsF&lhs, qreal rhs)     \relates QMarginsF     \overload      Returns a QMarginsF object that is formed by multiplying each component     of the given \a lhs margins by \a rhs factor.      \sa QMarginsF::operator*=(), QMarginsF::operator/=() */
end_comment
begin_comment
comment|/*!     \fn const QMarginsF operator*(qreal lhs, const QMarginsF&rhs)     \relates QMarginsF     \overload      Returns a QMarginsF object that is formed by multiplying each component     of the given \a lhs margins by \a rhs factor.      \sa QMarginsF::operator*=(), QMarginsF::operator/=() */
end_comment
begin_comment
comment|/*!     \fn const QMarginsF operator/(const QMarginsF&lhs, qreal rhs)     \relates QMarginsF     \overload      Returns a QMarginsF object that is formed by dividing the components of     the given \a lhs margins by the given \a rhs divisor.      \sa QMarginsF::operator*=(), QMarginsF::operator/=() */
end_comment
begin_comment
comment|/*!     \fn QMarginsF operator+(const QMarginsF&margins)     \relates QMarginsF      Returns a QMargin object that is formed from all components of \a margins. */
end_comment
begin_comment
comment|/*!     \fn QMarginsF operator-(const QMarginsF&margins)     \relates QMarginsF      Returns a QMargin object that is formed by negating all components of \a margins. */
end_comment
begin_comment
comment|/*!     \fn QMarginsF&QMarginsF::operator+=(const QMarginsF&margins)      Add each component of \a margins to the respective component of this object     and returns a reference to it.      \sa operator-=() */
end_comment
begin_comment
comment|/*!     \fn QMarginsF&QMarginsF::operator-=(const QMarginsF&margins)      Subtract each component of \a margins from the respective component of this object     and returns a reference to it.      \sa operator+=() */
end_comment
begin_comment
comment|/*!     \fn QMarginsF&QMarginsF::operator+=(qreal addend)     \overload      Adds the \a addend to each component of this object     and returns a reference to it.      \sa operator-=() */
end_comment
begin_comment
comment|/*!     \fn QMarginsF&QMarginsF::operator-=(qreal subtrahend)     \overload      Subtracts the \a subtrahend from each component of this object     and returns a reference to it.      \sa operator+=() */
end_comment
begin_comment
comment|/*!     \fn QMarginsF&QMarginsF::operator*=(qreal factor)      Multiplies each component of this object by \a factor     and returns a reference to it.      \sa operator/=() */
end_comment
begin_comment
comment|/*!     \fn QMarginsF&QMarginsF::operator/=(qreal divisor)      Divides each component of this object by \a divisor     and returns a reference to it.      \sa operator*=() */
end_comment
begin_comment
comment|/*!     \fn QMargins QMarginsF::toMargins() const      Returns an integer based copy of this margins object.      Note that the components in the returned margins will be rounded to     the nearest integer.      \sa QMarginsF() */
end_comment
begin_comment
comment|/*****************************************************************************   QMarginsF stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QMarginsF&m)     \relates QMarginsF      Writes margin \a m to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
end_comment
begin_function
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
name|QMarginsF
modifier|&
name|m
parameter_list|)
block|{
name|s
operator|<<
name|double
argument_list|(
name|m
operator|.
name|left
argument_list|()
argument_list|)
operator|<<
name|double
argument_list|(
name|m
operator|.
name|top
argument_list|()
argument_list|)
operator|<<
name|double
argument_list|(
name|m
operator|.
name|right
argument_list|()
argument_list|)
operator|<<
name|double
argument_list|(
name|m
operator|.
name|bottom
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QMarginsF&m)     \relates QMarginsF      Reads a margin from the given \a stream into margin \a m     and returns a reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QMarginsF
modifier|&
name|m
parameter_list|)
block|{
name|double
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
name|s
operator|>>
name|top
expr_stmt|;
name|s
operator|>>
name|right
expr_stmt|;
name|s
operator|>>
name|bottom
expr_stmt|;
name|m
operator|=
name|QMarginsF
argument_list|(
name|qreal
argument_list|(
name|left
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|top
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|right
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|bottom
argument_list|)
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
name|QMarginsF
modifier|&
name|m
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|dbg
argument_list|)
decl_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
expr_stmt|;
name|dbg
operator|<<
literal|"QMarginsF"
operator|<<
literal|'('
expr_stmt|;
name|QtDebugUtils
operator|::
name|formatQMargins
argument_list|(
name|dbg
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|dbg
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
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
