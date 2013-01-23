begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpoint.h"
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
comment|/*!     \class QPoint     \inmodule QtCore     \ingroup painting      \brief The QPoint class defines a point in the plane using integer     precision.      A point is specified by a x coordinate and an y coordinate which     can be accessed using the x() and y() functions. The isNull()     function returns true if both x and y are set to 0. The     coordinates can be set (or altered) using the setX() and setY()     functions, or alternatively the rx() and ry() functions which     return references to the coordinates (allowing direct     manipulation).      Given a point \e p, the following statements are all equivalent:      \snippet code/src_corelib_tools_qpoint.cpp 0      A QPoint object can also be used as a vector: Addition and     subtraction are defined as for vectors (each component is added     separately). A QPoint object can also be divided or multiplied by     an \c int or a \c qreal.      In addition, the QPoint class provides the manhattanLength()     function which gives an inexpensive approximation of the length of     the QPoint object interpreted as a vector. Finally, QPoint objects     can be streamed as well as compared.      \sa QPointF, QPolygon */
comment|/*****************************************************************************   QPoint member functions  *****************************************************************************/
comment|/*!     \fn QPoint::QPoint()      Constructs a null point, i.e. with coordinates (0, 0)      \sa isNull() */
comment|/*!     \fn QPoint::QPoint(int xpos, int ypos)      Constructs a point with the given coordinates (\a xpos, \a ypos).      \sa setX(), setY() */
comment|/*!     \fn bool QPoint::isNull() const      Returns true if both the x and y coordinates are set to 0,     otherwise returns false. */
comment|/*!     \fn int QPoint::x() const      Returns the x coordinate of this point.      \sa setX(), rx() */
comment|/*!     \fn int QPoint::y() const      Returns the y coordinate of this point.      \sa setY(), ry() */
comment|/*!     \fn void QPoint::setX(int x)      Sets the x coordinate of this point to the given \a x coordinate.      \sa x(), setY() */
comment|/*!     \fn void QPoint::setY(int y)      Sets the y coordinate of this point to the given \a y coordinate.      \sa y(), setX() */
comment|/*!     \fn int&QPoint::rx()      Returns a reference to the x coordinate of this point.      Using a reference makes it possible to directly manipulate x. For example:      \snippet code/src_corelib_tools_qpoint.cpp 1      \sa x(), setX() */
comment|/*!     \fn int&QPoint::ry()      Returns a reference to the y coordinate of this point.      Using a reference makes it possible to directly manipulate y. For     example:      \snippet code/src_corelib_tools_qpoint.cpp 2      \sa y(), setY() */
comment|/*!     \fn QPoint&QPoint::operator+=(const QPoint&point)      Adds the given \a point to this point and returns a reference to     this point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 3      \sa operator-=() */
comment|/*!     \fn QPoint&QPoint::operator-=(const QPoint&point)      Subtracts the given \a point from this point and returns a     reference to this point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 4      \sa operator+=() */
comment|/*!     \fn QPoint&QPoint::operator*=(float factor)      Multiplies this point's coordinates by the given \a factor, and     returns a reference to this point.      Note that the result is rounded to the nearest integer as points are held as     integers. Use QPointF for floating point accuracy.      \sa operator/=() */
comment|/*!     \fn QPoint&QPoint::operator*=(double factor)      Multiplies this point's coordinates by the given \a factor, and     returns a reference to this point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 5      Note that the result is rounded to the nearest integer as points are held as     integers. Use QPointF for floating point accuracy.      \sa operator/=() */
comment|/*!     \fn QPoint&QPoint::operator*=(int factor)      Multiplies this point's coordinates by the given \a factor, and     returns a reference to this point.      \sa operator/=() */
comment|/*!     \fn bool operator==(const QPoint&p1, const QPoint&p2)     \relates QPoint      Returns true if \a p1 and \a p2 are equal; otherwise returns     false. */
comment|/*!     \fn bool operator!=(const QPoint&p1, const QPoint&p2)     \relates QPoint      Returns true if \a p1 and \a p2 are not equal; otherwise returns false. */
comment|/*!     \fn const QPoint operator+(const QPoint&p1, const QPoint&p2)     \relates QPoint      Returns a QPoint object that is the sum of the given points, \a p1     and \a p2; each component is added separately.      \sa QPoint::operator+=() */
comment|/*!     \fn const QPoint operator-(const QPoint&p1, const QPoint&p2)     \relates QPoint      Returns a QPoint object that is formed by subtracting \a p2 from     \a p1; each component is subtracted separately.      \sa QPoint::operator-=() */
comment|/*!     \fn const QPoint operator*(const QPoint&point, float factor)     \relates QPoint      Returns a copy of the given \a point multiplied by the given \a factor.      Note that the result is rounded to the nearest integer as points     are held as integers. Use QPointF for floating point accuracy.      \sa QPoint::operator*=() */
comment|/*!     \fn const QPoint operator*(const QPoint&point, double factor)     \relates QPoint      Returns a copy of the given \a point multiplied by the given \a factor.      Note that the result is rounded to the nearest integer as points     are held as integers. Use QPointF for floating point accuracy.      \sa QPoint::operator*=() */
comment|/*!     \fn const QPoint operator*(const QPoint&point, int factor)     \relates QPoint      Returns a copy of the given \a point multiplied by the given \a factor.      \sa QPoint::operator*=() */
comment|/*!     \fn const QPoint operator*(float factor, const QPoint&point)     \overload     \relates QPoint      Returns a copy of the given \a point multiplied by the given \a factor.      Note that the result is rounded to the nearest integer as points     are held as integers. Use QPointF for floating point accuracy.      \sa QPoint::operator*=() */
comment|/*!     \fn const QPoint operator*(double factor, const QPoint&point)     \overload     \relates QPoint      Returns a copy of the given \a point multiplied by the given \a factor.      Note that the result is rounded to the nearest integer as points     are held as integers. Use QPointF for floating point accuracy.      \sa QPoint::operator*=() */
comment|/*!     \fn const QPoint operator*(int factor, const QPoint&point)     \overload     \relates QPoint      Returns a copy of the given \a point multiplied by the given \a factor.      \sa QPoint::operator*=() */
comment|/*!     \fn const QPoint operator+(const QPoint&point)     \relates QPoint     \since 5.0      Returns \a point unmodified. */
comment|/*!     \fn const QPoint operator-(const QPoint&point)     \overload     \relates QPoint      Returns a QPoint object that is formed by changing the sign of     both components of the given \a point.      Equivalent to \c{QPoint(0,0) - point}. */
comment|/*!     \fn QPoint&QPoint::operator/=(qreal divisor)     \overload      Divides both x and y by the given \a divisor, and returns a reference to this     point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 6      Note that the result is rounded to the nearest integer as points are held as     integers. Use QPointF for floating point accuracy.      \sa operator*=() */
comment|/*!     \fn const QPoint operator/(const QPoint&point, qreal divisor)     \relates QPoint      Returns the QPoint formed by dividing both components of the given \a point     by the given \a divisor.      Note that the result is rounded to the nearest integer as points are held as     integers. Use QPointF for floating point accuracy.      \sa QPoint::operator/=() */
comment|/*****************************************************************************   QPoint stream functions  *****************************************************************************/
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QPoint&point)     \relates QPoint      Writes the given \a point to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
if|if
condition|(
name|s
operator|.
name|version
argument_list|()
operator|==
literal|1
condition|)
name|s
operator|<<
operator|(
name|qint16
operator|)
name|p
operator|.
name|x
argument_list|()
operator|<<
operator|(
name|qint16
operator|)
name|p
operator|.
name|y
argument_list|()
expr_stmt|;
else|else
name|s
operator|<<
operator|(
name|qint32
operator|)
name|p
operator|.
name|x
argument_list|()
operator|<<
operator|(
name|qint32
operator|)
name|p
operator|.
name|y
argument_list|()
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QPoint&point)     \relates QPoint      Reads a point from the given \a stream into the given \a point     and returns a reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
if|if
condition|(
name|s
operator|.
name|version
argument_list|()
operator|==
literal|1
condition|)
block|{
name|qint16
name|x
decl_stmt|,
name|y
decl_stmt|;
name|s
operator|>>
name|x
expr_stmt|;
name|p
operator|.
name|rx
argument_list|()
operator|=
name|x
expr_stmt|;
name|s
operator|>>
name|y
expr_stmt|;
name|p
operator|.
name|ry
argument_list|()
operator|=
name|y
expr_stmt|;
block|}
else|else
block|{
name|qint32
name|x
decl_stmt|,
name|y
decl_stmt|;
name|s
operator|>>
name|x
expr_stmt|;
name|p
operator|.
name|rx
argument_list|()
operator|=
name|x
expr_stmt|;
name|s
operator|>>
name|y
expr_stmt|;
name|p
operator|.
name|ry
argument_list|()
operator|=
name|y
expr_stmt|;
block|}
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
begin_comment
comment|/*!     \fn int QPoint::manhattanLength() const      Returns the sum of the absolute values of x() and y(),     traditionally known as the "Manhattan length" of the vector from     the origin to the point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 7      This is a useful, and quick to calculate, approximation to the     true length:      \snippet code/src_corelib_tools_qpoint.cpp 8      The tradition of "Manhattan length" arises because such distances     apply to travelers who can only travel on a rectangular grid, like     the streets of Manhattan. */
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
name|QPoint
modifier|&
name|p
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QPoint("
operator|<<
name|p
operator|.
name|x
argument_list|()
operator|<<
literal|','
operator|<<
name|p
operator|.
name|y
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
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
block|{
name|d
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QPointF("
operator|<<
name|p
operator|.
name|x
argument_list|()
operator|<<
literal|", "
operator|<<
name|p
operator|.
name|y
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|d
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
begin_comment
comment|/*!     \class QPointF     \inmodule QtCore     \ingroup painting      \brief The QPointF class defines a point in the plane using     floating point precision.      A point is specified by a x coordinate and an y coordinate which     can be accessed using the x() and y() functions. The coordinates     of the point are specified using floating point numbers for     accuracy. The isNull() function returns true if both x and y are     set to 0.0. The coordinates can be set (or altered) using the setX()     and setY() functions, or alternatively the rx() and ry() functions which     return references to the coordinates (allowing direct     manipulation).      Given a point \e p, the following statements are all equivalent:      \snippet code/src_corelib_tools_qpoint.cpp 9      A QPointF object can also be used as a vector: Addition and     subtraction are defined as for vectors (each component is added     separately). A QPointF object can also be divided or multiplied by     an \c int or a \c qreal.      In addition, the QPointF class provides a constructor converting a     QPoint object into a QPointF object, and a corresponding toPoint()     function which returns a QPoint copy of \e this point. Finally,     QPointF objects can be streamed as well as compared.      \sa QPoint, QPolygonF */
end_comment
begin_comment
comment|/*!     \fn QPointF::QPointF()      Constructs a null point, i.e. with coordinates (0.0, 0.0)      \sa isNull() */
end_comment
begin_comment
comment|/*!     \fn QPointF::QPointF(const QPoint&point)      Constructs a copy of the given \a point.      \sa toPoint() */
end_comment
begin_comment
comment|/*!     \fn QPointF::QPointF(qreal xpos, qreal ypos)      Constructs a point with the given coordinates (\a xpos, \a ypos).      \sa setX(), setY() */
end_comment
begin_comment
comment|/*!     \fn bool QPointF::isNull() const      Returns true if both the x and y coordinates are set to +0.0;     otherwise returns false.      \note Since this function treats +0.0 and -0.0 differently, points     with zero-valued coordinates where either or both values have a     negative sign are not defined to be null points. */
end_comment
begin_comment
comment|/*!     \fn qreal QPointF::manhattanLength() const     \since 4.6      Returns the sum of the absolute values of x() and y(),     traditionally known as the "Manhattan length" of the vector from     the origin to the point.      \sa QPoint::manhattanLength() */
end_comment
begin_comment
comment|/*!     \fn qreal QPointF::x() const      Returns the x coordinate of this point.      \sa setX(), rx() */
end_comment
begin_comment
comment|/*!     \fn qreal QPointF::y() const      Returns the y coordinate of this point.      \sa setY(), ry() */
end_comment
begin_comment
comment|/*!     \fn void QPointF::setX(qreal x)      Sets the x coordinate of this point to the given \a x coordinate.      \sa x(), setY() */
end_comment
begin_comment
comment|/*!     \fn void QPointF::setY(qreal y)      Sets the y coordinate of this point to the given \a y coordinate.      \sa y(), setX() */
end_comment
begin_comment
comment|/*!     \fn qreal& QPointF::rx()      Returns a reference to the x coordinate of this point.      Using a reference makes it possible to directly manipulate x. For example:      \snippet code/src_corelib_tools_qpoint.cpp 10      \sa x(), setX() */
end_comment
begin_comment
comment|/*!     \fn qreal& QPointF::ry()      Returns a reference to the y coordinate of this point.      Using a reference makes it possible to directly manipulate y. For example:      \snippet code/src_corelib_tools_qpoint.cpp 11      \sa y(), setY() */
end_comment
begin_comment
comment|/*!     \fn QPointF& QPointF::operator+=(const QPointF&point)      Adds the given \a point to this point and returns a reference to     this point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 12      \sa operator-=() */
end_comment
begin_comment
comment|/*!     \fn QPointF& QPointF::operator-=(const QPointF&point)      Subtracts the given \a point from this point and returns a reference     to this point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 13      \sa operator+=() */
end_comment
begin_comment
comment|/*!     \fn QPointF& QPointF::operator*=(qreal factor)      Multiplies this point's coordinates by the given \a factor, and     returns a reference to this point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 14      \sa operator/=() */
end_comment
begin_comment
comment|/*!     \fn QPointF& QPointF::operator/=(qreal divisor)      Divides both x and y by the given \a divisor, and returns a reference     to this point. For example:      \snippet code/src_corelib_tools_qpoint.cpp 15      \sa operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QPointF operator+(const QPointF&p1, const QPointF&p2)     \relates QPointF      Returns a QPointF object that is the sum of the given points, \a p1     and \a p2; each component is added separately.      \sa QPointF::operator+=() */
end_comment
begin_comment
comment|/*!     \fn const QPointF operator-(const QPointF&p1, const QPointF&p2)     \relates QPointF      Returns a QPointF object that is formed by subtracting \a p2 from \a p1;     each component is subtracted separately.      \sa QPointF::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QPointF operator*(const QPointF&point, qreal factor)     \relates QPointF      Returns a copy of the given \a point,  multiplied by the given \a factor.      \sa QPointF::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QPointF operator*(qreal factor, const QPointF&point)     \relates QPointF      \overload      Returns a copy of the given \a point, multiplied by the given \a factor. */
end_comment
begin_comment
comment|/*!     \fn const QPointF operator+(const QPointF&point)     \relates QPointF     \since 5.0      Returns \a point unmodified. */
end_comment
begin_comment
comment|/*!     \fn const QPointF operator-(const QPointF&point)     \relates QPointF     \overload      Returns a QPointF object that is formed by changing the sign of     both components of the given \a point.      Equivalent to \c {QPointF(0,0) - point}. */
end_comment
begin_comment
comment|/*!     \fn const QPointF operator/(const QPointF&point, qreal divisor)     \relates QPointF      Returns the QPointF object formed by dividing both components of     the given \a point by the given \a divisor.      \sa QPointF::operator/=() */
end_comment
begin_comment
comment|/*!     \fn QPoint QPointF::toPoint() const      Rounds the coordinates of this point to the nearest integer, and     returns a QPoint object with the rounded coordinates.      \sa QPointF() */
end_comment
begin_comment
comment|/*!     \fn bool operator==(const QPointF&p1, const QPointF&p2)     \relates QPointF      Returns true if \a p1 is equal to \a p2; otherwise returns false. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QPointF&p1, const QPointF&p2);     \relates QPointF      Returns true if \a p1 is not equal to \a p2; otherwise returns false. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QPointF&point)     \relates QPointF      Writes the given \a point to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QPointF
modifier|&
name|p
parameter_list|)
block|{
name|s
operator|<<
name|double
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|)
operator|<<
name|double
argument_list|(
name|p
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QPointF&point)     \relates QPointF      Reads a point from the given \a stream into the given \a point     and returns a reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QPointF
modifier|&
name|p
parameter_list|)
block|{
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
name|s
operator|>>
name|x
expr_stmt|;
name|s
operator|>>
name|y
expr_stmt|;
name|p
operator|.
name|setX
argument_list|(
name|qreal
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setY
argument_list|(
name|qreal
argument_list|(
name|y
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
