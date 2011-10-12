begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_RAWFONT
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qglyphrun.h"
end_include
begin_include
include|#
directive|include
file|"qglyphrun_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QGlyphRun     \brief The QGlyphRun class provides direct access to the internal glyphs in a font.     \since 4.8      \ingroup text     \mainclass      When Qt displays a string of text encoded in Unicode, it will first convert the Unicode points     into a list of glyph indexes and a list of positions based on one or more fonts. The Unicode     representation of the text and the QFont object will in this case serve as a convenient     abstraction that hides the details of what actually takes place when displaying the text     on-screen. For instance, by the time the text actually reaches the screen, it may be represented     by a set of fonts in addition to the one specified by the user, e.g. in case the originally     selected font did not support all the writing systems contained in the text.      Under certain circumstances, it can be useful as an application developer to have more low-level     control over which glyphs in a specific font are drawn to the screen. This could for instance     be the case in applications that use an external font engine and text shaper together with Qt.     QGlyphRun provides an interface to the raw data needed to get text on the screen. It     contains a list of glyph indexes, a position for each glyph and a font.      It is the user's responsibility to ensure that the selected font actually contains the     provided glyph indexes.      QTextLayout::glyphRuns() or QTextFragment::glyphRuns() can be used to convert unicode encoded     text into a list of QGlyphRun objects, and QPainter::drawGlyphRun() can be used to draw the     glyphs.      \note Please note that QRawFont is considered local to the thread in which it is constructed.     This in turn means that a new QRawFont will have to be created and set on the QGlyphRun if it is     moved to a different thread. If the QGlyphRun contains a reference to a QRawFont from a different     thread than the current, it will not be possible to draw the glyphs using a QPainter, as the     QRawFont is considered invalid and inaccessible in this case. */
end_comment
begin_comment
comment|/*!   \enum QGlyphRun::GlyphRunFlag   \since 5.0    This enum describes flags that alter the way the run of glyphs might be presented or behave in   a visual layout. The layout which generates the glyph runs can set these flags based on relevant   internal data, to retain information needed to present the text as intended by the user of the   layout.    \value Overline Indicates that the glyphs should be visualized together with an overline.   \value Underline Indicates that the glyphs should be visualized together with an underline.   \value StrikeOut Indicates that the glyphs should be struck out visually.   \value RightToLeft Indicates that the glyphs are ordered right to left. This can affect the   positioning of other screen elements that are relative to the glyph run, such as an inline   text object.   \value SplitLigature Indicates that the glyph run splits a ligature glyph. This means   that a ligature glyph is included in the run, but the characters represented by it corresponds   only to part of that ligature. The glyph run's boundingRect() function can in this case be used   to retrieve the area covered by glyphs that correspond to the characters represented by the   glyph run. When visualizing the glyphs, care needs to be taken to clip to this bounding rect to   ensure that only the corresponding part of the ligature is painted. In particular, this can be   the case when retrieving a glyph run from a QTextLayout for a specific character range, e.g.   when retrieving the selected area of a QTextLayout. */
end_comment
begin_comment
comment|/*!     Constructs an empty QGlyphRun object. */
end_comment
begin_constructor
DECL|function|QGlyphRun
name|QGlyphRun
operator|::
name|QGlyphRun
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QGlyphRunPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QGlyphRun object which is a copy of \a other. */
end_comment
begin_constructor
DECL|function|QGlyphRun
name|QGlyphRun
operator|::
name|QGlyphRun
parameter_list|(
specifier|const
name|QGlyphRun
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QGlyphRun. */
end_comment
begin_destructor
DECL|function|~QGlyphRun
name|QGlyphRun
operator|::
name|~
name|QGlyphRun
parameter_list|()
block|{
comment|// Required for QExplicitlySharedDataPointer
block|}
end_destructor
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|detach
name|void
name|QGlyphRun
operator|::
name|detach
parameter_list|()
block|{
if|if
condition|(
name|d
operator|->
name|ref
operator|!=
literal|1
condition|)
name|d
operator|.
name|detach
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Assigns \a other to this QGlyphRun object. */
end_comment
begin_function
DECL|function|operator =
name|QGlyphRun
modifier|&
name|QGlyphRun
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QGlyphRun
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Compares \a other to this QGlyphRun object. Returns true if the list of glyph indexes,     the list of positions and the font are all equal, otherwise returns false. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QGlyphRun
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QGlyphRun
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|==
name|other
operator|.
name|d
condition|)
return|return
literal|true
return|;
if|if
condition|(
operator|(
name|d
operator|->
name|glyphIndexDataSize
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphIndexDataSize
operator|)
operator|||
operator|(
name|d
operator|->
name|glyphPositionDataSize
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphPositionDataSize
operator|)
condition|)
block|{
return|return
literal|false
return|;
block|}
if|if
condition|(
name|d
operator|->
name|glyphIndexData
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphIndexData
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|glyphIndexDataSize
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|d
operator|->
name|glyphIndexData
index|[
name|i
index|]
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphIndexData
index|[
name|i
index|]
condition|)
return|return
literal|false
return|;
block|}
block|}
if|if
condition|(
name|d
operator|->
name|glyphPositionData
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphPositionData
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|glyphPositionDataSize
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|d
operator|->
name|glyphPositionData
index|[
name|i
index|]
operator|!=
name|other
operator|.
name|d
operator|->
name|glyphPositionData
index|[
name|i
index|]
condition|)
return|return
literal|false
return|;
block|}
block|}
return|return
operator|(
name|d
operator|->
name|flags
operator|==
name|other
operator|.
name|d
operator|->
name|flags
operator|&&
name|d
operator|->
name|rawFont
operator|==
name|other
operator|.
name|d
operator|->
name|rawFont
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QGlyphRun::operator!=(const QGlyphRun&other) const      Compares \a other to this QGlyphRun object. Returns true if any of the list of glyph     indexes, the list of positions or the font are different, otherwise returns false. */
end_comment
begin_comment
comment|/*!     Returns the font selected for this QGlyphRun object.      \sa setRawFont() */
end_comment
begin_function
DECL|function|rawFont
name|QRawFont
name|QGlyphRun
operator|::
name|rawFont
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|rawFont
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the font in which to look up the glyph indexes to the \a rawFont     specified.      \sa rawFont(), setGlyphIndexes() */
end_comment
begin_function
DECL|function|setRawFont
name|void
name|QGlyphRun
operator|::
name|setRawFont
parameter_list|(
specifier|const
name|QRawFont
modifier|&
name|rawFont
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|rawFont
operator|=
name|rawFont
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the glyph indexes for this QGlyphRun object.      \sa setGlyphIndexes(), setPositions() */
end_comment
begin_function
DECL|function|glyphIndexes
name|QVector
argument_list|<
name|quint32
argument_list|>
name|QGlyphRun
operator|::
name|glyphIndexes
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|glyphIndexes
operator|.
name|constData
argument_list|()
operator|==
name|d
operator|->
name|glyphIndexData
condition|)
block|{
return|return
name|d
operator|->
name|glyphIndexes
return|;
block|}
else|else
block|{
name|QVector
argument_list|<
name|quint32
argument_list|>
name|indexes
argument_list|(
name|d
operator|->
name|glyphIndexDataSize
argument_list|)
decl_stmt|;
name|qMemCopy
argument_list|(
name|indexes
operator|.
name|data
argument_list|()
argument_list|,
name|d
operator|->
name|glyphIndexData
argument_list|,
name|d
operator|->
name|glyphIndexDataSize
operator|*
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|indexes
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Set the glyph indexes for this QGlyphRun object to \a glyphIndexes. The glyph indexes must     be valid for the selected font. */
end_comment
begin_function
DECL|function|setGlyphIndexes
name|void
name|QGlyphRun
operator|::
name|setGlyphIndexes
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|quint32
argument_list|>
modifier|&
name|glyphIndexes
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphIndexes
operator|=
name|glyphIndexes
expr_stmt|;
comment|// Keep a reference to the QVector to avoid copying
name|d
operator|->
name|glyphIndexData
operator|=
name|glyphIndexes
operator|.
name|constData
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphIndexDataSize
operator|=
name|glyphIndexes
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the position of the edge of the baseline for each glyph in this set of glyph indexes. */
end_comment
begin_function
DECL|function|positions
name|QVector
argument_list|<
name|QPointF
argument_list|>
name|QGlyphRun
operator|::
name|positions
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|glyphPositions
operator|.
name|constData
argument_list|()
operator|==
name|d
operator|->
name|glyphPositionData
condition|)
block|{
return|return
name|d
operator|->
name|glyphPositions
return|;
block|}
else|else
block|{
name|QVector
argument_list|<
name|QPointF
argument_list|>
name|glyphPositions
argument_list|(
name|d
operator|->
name|glyphPositionDataSize
argument_list|)
decl_stmt|;
name|qMemCopy
argument_list|(
name|glyphPositions
operator|.
name|data
argument_list|()
argument_list|,
name|d
operator|->
name|glyphPositionData
argument_list|,
name|d
operator|->
name|glyphPositionDataSize
operator|*
sizeof|sizeof
argument_list|(
name|QPointF
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|glyphPositions
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Sets the positions of the edge of the baseline for each glyph in this set of glyph indexes to     \a positions. */
end_comment
begin_function
DECL|function|setPositions
name|void
name|QGlyphRun
operator|::
name|setPositions
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|QPointF
argument_list|>
modifier|&
name|positions
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphPositions
operator|=
name|positions
expr_stmt|;
comment|// Keep a reference to the vector to avoid copying
name|d
operator|->
name|glyphPositionData
operator|=
name|positions
operator|.
name|constData
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphPositionDataSize
operator|=
name|positions
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Clears all data in the QGlyphRun object. */
end_comment
begin_function
DECL|function|clear
name|void
name|QGlyphRun
operator|::
name|clear
parameter_list|()
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|rawFont
operator|=
name|QRawFont
argument_list|()
expr_stmt|;
name|d
operator|->
name|flags
operator|=
literal|0
expr_stmt|;
name|setPositions
argument_list|(
name|QVector
argument_list|<
name|QPointF
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
name|setGlyphIndexes
argument_list|(
name|QVector
argument_list|<
name|quint32
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the glyph indexes and positions of this QGlyphRun to use the first \a size     elements in the arrays \a glyphIndexArray and \a glyphPositionArray. The data is     \e not copied. The caller must guarantee that the arrays are not deleted as long     as this QGlyphRun and any copies of it exists.      \sa setGlyphIndexes(), setPositions() */
end_comment
begin_function
DECL|function|setRawData
name|void
name|QGlyphRun
operator|::
name|setRawData
parameter_list|(
specifier|const
name|quint32
modifier|*
name|glyphIndexArray
parameter_list|,
specifier|const
name|QPointF
modifier|*
name|glyphPositionArray
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphIndexes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphPositions
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|glyphIndexData
operator|=
name|glyphIndexArray
expr_stmt|;
name|d
operator|->
name|glyphPositionData
operator|=
name|glyphPositionArray
expr_stmt|;
name|d
operator|->
name|glyphIndexDataSize
operator|=
name|d
operator|->
name|glyphPositionDataSize
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Returns true if this QGlyphRun should be painted with an overline decoration.     \sa setOverline(), flags() */
end_comment
begin_function
DECL|function|overline
name|bool
name|QGlyphRun
operator|::
name|overline
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|flags
operator|&
name|Overline
return|;
block|}
end_function
begin_comment
comment|/*!   Indicates that this QGlyphRun should be painted with an overline decoration if \a overline is true.   Otherwise the QGlyphRun should be painted with no overline decoration.    \sa overline(), setFlag(), setFlags() */
end_comment
begin_function
DECL|function|setOverline
name|void
name|QGlyphRun
operator|::
name|setOverline
parameter_list|(
name|bool
name|overline
parameter_list|)
block|{
name|setFlag
argument_list|(
name|Overline
argument_list|,
name|overline
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Returns true if this QGlyphRun should be painted with an underline decoration.     \sa setUnderline(), flags() */
end_comment
begin_function
DECL|function|underline
name|bool
name|QGlyphRun
operator|::
name|underline
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|flags
operator|&
name|Underline
return|;
block|}
end_function
begin_comment
comment|/*!   Indicates that this QGlyphRun should be painted with an underline decoration if \a underline is   true. Otherwise the QGlyphRun should be painted with no underline decoration.    \sa underline(), setFlag(), setFlags() */
end_comment
begin_function
DECL|function|setUnderline
name|void
name|QGlyphRun
operator|::
name|setUnderline
parameter_list|(
name|bool
name|underline
parameter_list|)
block|{
name|setFlag
argument_list|(
name|Underline
argument_list|,
name|underline
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Returns true if this QGlyphRun should be painted with a strike out decoration.     \sa setStrikeOut(), flags() */
end_comment
begin_function
DECL|function|strikeOut
name|bool
name|QGlyphRun
operator|::
name|strikeOut
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|flags
operator|&
name|StrikeOut
return|;
block|}
end_function
begin_comment
comment|/*!   Indicates that this QGlyphRun should be painted with an strike out decoration if \a strikeOut is   true. Otherwise the QGlyphRun should be painted with no strike out decoration.    \sa strikeOut(), setFlag(), setFlags() */
end_comment
begin_function
DECL|function|setStrikeOut
name|void
name|QGlyphRun
operator|::
name|setStrikeOut
parameter_list|(
name|bool
name|strikeOut
parameter_list|)
block|{
name|setFlag
argument_list|(
name|StrikeOut
argument_list|,
name|strikeOut
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns true if this QGlyphRun contains glyphs that are painted from the right to the left.    \since 5.0   \sa setRightToLeft(), flags() */
end_comment
begin_function
DECL|function|isRightToLeft
name|bool
name|QGlyphRun
operator|::
name|isRightToLeft
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|flags
operator|&
name|RightToLeft
return|;
block|}
end_function
begin_comment
comment|/*!   Indicates that this QGlyphRun contains glyphs that should be ordered from the right to left   if \a rightToLeft is true. Otherwise the order of the glyphs is assumed to be left to right.    \since 5.0   \sa isRightToLeft(), setFlag(), setFlags() */
end_comment
begin_function
DECL|function|setRightToLeft
name|void
name|QGlyphRun
operator|::
name|setRightToLeft
parameter_list|(
name|bool
name|rightToLeft
parameter_list|)
block|{
name|setFlag
argument_list|(
name|RightToLeft
argument_list|,
name|rightToLeft
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the flags set for this QGlyphRun.    \since 5.0   \sa setFlag(), setFlag() */
end_comment
begin_function
DECL|function|flags
name|QGlyphRun
operator|::
name|GlyphRunFlags
name|QGlyphRun
operator|::
name|flags
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|flags
return|;
block|}
end_function
begin_comment
comment|/*!   If \a enabled is true, then \a flag is enabled; otherwise, it is disabled.    \since 5.0   \sa flags(), setFlags() */
end_comment
begin_function
DECL|function|setFlag
name|void
name|QGlyphRun
operator|::
name|setFlag
parameter_list|(
name|GlyphRunFlag
name|flag
parameter_list|,
name|bool
name|enabled
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|flags
operator|.
name|testFlag
argument_list|(
name|flag
argument_list|)
operator|==
name|enabled
condition|)
return|return;
name|detach
argument_list|()
expr_stmt|;
if|if
condition|(
name|enabled
condition|)
name|d
operator|->
name|flags
operator||=
name|flag
expr_stmt|;
else|else
name|d
operator|->
name|flags
operator|&=
operator|~
name|flag
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Sets the flags of this QGlyphRun to \a flags.    \since 5.0   \sa setFlag(), flags() */
end_comment
begin_function
DECL|function|setFlags
name|void
name|QGlyphRun
operator|::
name|setFlags
parameter_list|(
name|GlyphRunFlags
name|flags
parameter_list|)
block|{
if|if
condition|(
name|d
operator|->
name|flags
operator|==
name|flags
condition|)
return|return;
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|flags
operator|=
name|flags
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Sets the bounding rect of the glyphs in this QGlyphRun to be \a boundingRect. This rectangle   will be returned by boundingRect() unless it is empty, in which case the bounding rectangle of the   glyphs in the glyph run will be returned instead.    \note Unless you are implementing text shaping, you should not have to use this function.   It is used specifically when the QGlyphRun should represent an area which is smaller than the   area of the glyphs it contains. This could happen e.g. if the glyph run is retrieved by calling   QTextLayout::glyphRuns() and the specified range only includes part of a ligature (where two or   more characters are combined to a single glyph.) When this is the case, the bounding rect should   only include the appropriate part of the ligature glyph, based on a calculation of the average   width of the characters in the ligature.    In order to support such a case (an example is selections which should be drawn with a different   color than the main text color), it is necessary to clip the painting mechanism to the rectangle   returned from boundingRect() to avoid drawing the entire ligature glyph.    \sa boundingRect()    \since 5.0 */
end_comment
begin_function
DECL|function|setBoundingRect
name|void
name|QGlyphRun
operator|::
name|setBoundingRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|boundingRect
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
name|d
operator|->
name|boundingRect
operator|=
name|boundingRect
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the smallest rectangle that contains all glyphs in this QGlyphRun. If a bounding rect   has been set using setBoundingRect(), then this will be returned. Otherwise the bounding rect   will be calculated based on the font metrics of the glyphs in the glyph run.    \since 5.0 */
end_comment
begin_function
DECL|function|boundingRect
name|QRectF
name|QGlyphRun
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|boundingRect
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|d
operator|->
name|boundingRect
return|;
name|qreal
name|minX
decl_stmt|,
name|minY
decl_stmt|,
name|maxX
decl_stmt|,
name|maxY
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
name|qMin
argument_list|(
name|d
operator|->
name|glyphPositions
operator|.
name|size
argument_list|()
argument_list|,
name|d
operator|->
name|glyphIndexes
operator|.
name|size
argument_list|()
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|QRectF
name|glyphRect
init|=
name|d
operator|->
name|rawFont
operator|.
name|boundingRect
argument_list|(
name|d
operator|->
name|glyphIndexes
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|glyphRect
operator|.
name|translate
argument_list|(
name|d
operator|->
name|glyphPositions
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
block|{
name|minX
operator|=
name|glyphRect
operator|.
name|left
argument_list|()
expr_stmt|;
name|minY
operator|=
name|glyphRect
operator|.
name|top
argument_list|()
expr_stmt|;
name|maxX
operator|=
name|glyphRect
operator|.
name|right
argument_list|()
expr_stmt|;
name|maxY
operator|=
name|glyphRect
operator|.
name|bottom
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|minX
operator|=
name|qMin
argument_list|(
name|glyphRect
operator|.
name|left
argument_list|()
argument_list|,
name|minX
argument_list|)
expr_stmt|;
name|minY
operator|=
name|qMin
argument_list|(
name|glyphRect
operator|.
name|top
argument_list|()
argument_list|,
name|minY
argument_list|)
expr_stmt|;
name|maxX
operator|=
name|qMax
argument_list|(
name|glyphRect
operator|.
name|right
argument_list|()
argument_list|,
name|maxX
argument_list|)
expr_stmt|;
name|maxY
operator|=
name|qMax
argument_list|(
name|glyphRect
operator|.
name|bottom
argument_list|()
argument_list|,
name|maxY
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|QRectF
argument_list|(
name|QPointF
argument_list|(
name|minX
argument_list|,
name|minY
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|maxX
argument_list|,
name|maxY
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Returns true if the QGlyphRun does not contain any glyphs.    \since 5.0 */
end_comment
begin_function
DECL|function|isEmpty
name|bool
name|QGlyphRun
operator|::
name|isEmpty
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|glyphIndexes
operator|.
name|isEmpty
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
comment|// QT_NO_RAWFONT
end_comment
end_unit
