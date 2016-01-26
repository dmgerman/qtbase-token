begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtextoption.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QTextOptionPrivate
struct|struct
name|QTextOptionPrivate
block|{
DECL|member|tabStops
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
name|tabStops
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|/*!     Constructs a text option with default properties for text.     The text alignment property is set to Qt::AlignLeft. The     word wrap property is set to QTextOption::WordWrap. The     using of design metrics flag is set to false. */
end_comment
begin_constructor
DECL|function|QTextOption
name|QTextOption
operator|::
name|QTextOption
parameter_list|()
member_init_list|:
name|align
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|wordWrap
argument_list|(
name|QTextOption
operator|::
name|WordWrap
argument_list|)
member_init_list|,
name|design
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|unused
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|unused2
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|f
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|tab
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|direction
operator|=
name|Qt
operator|::
name|LayoutDirectionAuto
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a text option with the given \a alignment for text.     The word wrap property is set to QTextOption::WordWrap. The using     of design metrics flag is set to false. */
end_comment
begin_constructor
DECL|function|QTextOption
name|QTextOption
operator|::
name|QTextOption
parameter_list|(
name|Qt
operator|::
name|Alignment
name|alignment
parameter_list|)
member_init_list|:
name|align
argument_list|(
name|alignment
argument_list|)
member_init_list|,
name|wordWrap
argument_list|(
name|QTextOption
operator|::
name|WordWrap
argument_list|)
member_init_list|,
name|design
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|unused
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|unused2
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|f
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|tab
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|direction
operator|=
name|QGuiApplication
operator|::
name|layoutDirection
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the text option. */
end_comment
begin_destructor
DECL|function|~QTextOption
name|QTextOption
operator|::
name|~
name|QTextOption
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \fn QTextOption::QTextOption(const QTextOption&other)      Construct a copy of the \a other text option. */
end_comment
begin_constructor
DECL|function|QTextOption
name|QTextOption
operator|::
name|QTextOption
parameter_list|(
specifier|const
name|QTextOption
modifier|&
name|o
parameter_list|)
member_init_list|:
name|align
argument_list|(
name|o
operator|.
name|align
argument_list|)
member_init_list|,
name|wordWrap
argument_list|(
name|o
operator|.
name|wordWrap
argument_list|)
member_init_list|,
name|design
argument_list|(
name|o
operator|.
name|design
argument_list|)
member_init_list|,
name|direction
argument_list|(
name|o
operator|.
name|direction
argument_list|)
member_init_list|,
name|unused
argument_list|(
name|o
operator|.
name|unused
argument_list|)
member_init_list|,
name|unused2
argument_list|(
name|o
operator|.
name|unused2
argument_list|)
member_init_list|,
name|f
argument_list|(
name|o
operator|.
name|f
argument_list|)
member_init_list|,
name|tab
argument_list|(
name|o
operator|.
name|tab
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|o
operator|.
name|d
condition|)
name|d
operator|=
operator|new
name|QTextOptionPrivate
argument_list|(
operator|*
name|o
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \fn QTextOption&QTextOption::operator=(const QTextOption&other)      Returns \c true if the text option is the same as the \a other text option;     otherwise returns \c false. */
end_comment
begin_function
DECL|function|operator =
name|QTextOption
modifier|&
name|QTextOption
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QTextOption
modifier|&
name|o
parameter_list|)
block|{
if|if
condition|(
name|this
operator|==
operator|&
name|o
condition|)
return|return
operator|*
name|this
return|;
name|QTextOptionPrivate
modifier|*
name|dNew
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|o
operator|.
name|d
condition|)
name|dNew
operator|=
operator|new
name|QTextOptionPrivate
argument_list|(
operator|*
name|o
operator|.
name|d
argument_list|)
expr_stmt|;
operator|delete
name|d
expr_stmt|;
name|d
operator|=
name|dNew
expr_stmt|;
name|align
operator|=
name|o
operator|.
name|align
expr_stmt|;
name|wordWrap
operator|=
name|o
operator|.
name|wordWrap
expr_stmt|;
name|design
operator|=
name|o
operator|.
name|design
expr_stmt|;
name|direction
operator|=
name|o
operator|.
name|direction
expr_stmt|;
name|unused
operator|=
name|o
operator|.
name|unused
expr_stmt|;
name|f
operator|=
name|o
operator|.
name|f
expr_stmt|;
name|tab
operator|=
name|o
operator|.
name|tab
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the tab positions for the text layout to those specified by     \a tabStops.      \sa tabArray(), setTabStop(), setTabs() */
end_comment
begin_function
DECL|function|setTabArray
name|void
name|QTextOption
operator|::
name|setTabArray
parameter_list|(
specifier|const
name|QList
argument_list|<
name|qreal
argument_list|>
modifier|&
name|tabStops
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QTextOptionPrivate
expr_stmt|;
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
name|tabs
decl_stmt|;
name|QTextOption
operator|::
name|Tab
name|tab
decl_stmt|;
name|tabs
operator|.
name|reserve
argument_list|(
name|tabStops
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|qreal
name|pos
range|:
name|tabStops
control|)
block|{
name|tab
operator|.
name|position
operator|=
name|pos
expr_stmt|;
name|tabs
operator|.
name|append
argument_list|(
name|tab
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|tabStops
operator|=
name|tabs
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4     Sets the tab positions for the text layout to those specified by     \a tabStops.      \sa tabStops() */
end_comment
begin_function
DECL|function|setTabs
name|void
name|QTextOption
operator|::
name|setTabs
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
modifier|&
name|tabStops
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QTextOptionPrivate
expr_stmt|;
name|d
operator|->
name|tabStops
operator|=
name|tabStops
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of tab positions defined for the text layout.      \sa setTabArray(), tabStop() */
end_comment
begin_function
DECL|function|tabArray
name|QList
argument_list|<
name|qreal
argument_list|>
name|QTextOption
operator|::
name|tabArray
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|qreal
argument_list|>
name|answer
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|answer
return|;
name|answer
operator|.
name|reserve
argument_list|(
name|d
operator|->
name|tabStops
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
operator|::
name|ConstIterator
name|iter
init|=
name|d
operator|->
name|tabStops
operator|.
name|constBegin
argument_list|()
decl_stmt|;
while|while
condition|(
name|iter
operator|!=
name|d
operator|->
name|tabStops
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|answer
operator|.
name|append
argument_list|(
operator|(
operator|*
name|iter
operator|)
operator|.
name|position
argument_list|)
expr_stmt|;
operator|++
name|iter
expr_stmt|;
block|}
return|return
name|answer
return|;
block|}
end_function
begin_function
DECL|function|tabs
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
name|QTextOption
operator|::
name|tabs
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QList
argument_list|<
name|QTextOption
operator|::
name|Tab
argument_list|>
argument_list|()
return|;
return|return
name|d
operator|->
name|tabStops
return|;
block|}
end_function
begin_comment
comment|/*!     \class QTextOption     \reentrant      \brief The QTextOption class provides a description of general rich text     properties.     \inmodule QtGui      \ingroup richtext-processing      QTextOption is used to encapsulate common rich text properties in a single     object. It contains information about text alignment, layout direction,     word wrapping, and other standard properties associated with text rendering     and layout.      \sa QTextEdit, QTextDocument, QTextCursor */
end_comment
begin_comment
comment|/*!     \enum QTextOption::WrapMode      This enum describes how text is wrapped in a document.      \value NoWrap       Text is not wrapped at all.     \value WordWrap     Text is wrapped at word boundaries.     \value ManualWrap   Same as QTextOption::NoWrap     \value WrapAnywhere Text can be wrapped at any point on a line, even if                         it occurs in the middle of a word.     \value WrapAtWordBoundaryOrAnywhere If possible, wrapping occurs at a word                         boundary; otherwise it will occur at the appropriate                         point on the line, even in the middle of a word. */
end_comment
begin_comment
comment|/*!   \fn void QTextOption::setUseDesignMetrics(bool enable)      If \a enable is true then the layout will use design metrics;     otherwise it will use the metrics of the paint device (which is     the default behavior).      \sa useDesignMetrics() */
end_comment
begin_comment
comment|/*!   \fn bool QTextOption::useDesignMetrics() const      Returns \c true if the layout uses design rather than device metrics;     otherwise returns \c false.      \sa setUseDesignMetrics() */
end_comment
begin_comment
comment|/*!   \fn Qt::Alignment QTextOption::alignment() const    Returns the text alignment defined by the option.    \sa setAlignment() */
end_comment
begin_comment
comment|/*!   \fn void QTextOption::setAlignment(Qt::Alignment alignment);    Sets the option's text alignment to the specified \a alignment.    \sa alignment() */
end_comment
begin_comment
comment|/*!   \fn Qt::LayoutDirection QTextOption::textDirection() const    Returns the direction of the text layout defined by the option.    \sa setTextDirection() */
end_comment
begin_comment
comment|/*!   \fn void QTextOption::setTextDirection(Qt::LayoutDirection direction)    Sets the direction of the text layout defined by the option to the   given \a direction.    \sa textDirection() */
end_comment
begin_comment
comment|/*!   \fn WrapMode QTextOption::wrapMode() const    Returns the text wrap mode defined by the option.    \sa setWrapMode() */
end_comment
begin_comment
comment|/*!   \fn void QTextOption::setWrapMode(WrapMode mode)    Sets the option's text wrap mode to the given \a mode. */
end_comment
begin_comment
comment|/*!   \enum QTextOption::Flag    \value IncludeTrailingSpaces When this option is set, QTextLine::naturalTextWidth() and naturalTextRect() will                                return a value that includes the width of trailing spaces in the text; otherwise                                this width is excluded.   \value ShowTabsAndSpaces Visualize spaces with little dots, and tabs with little arrows.   \value ShowLineAndParagraphSeparators Visualize line and paragraph separators with appropriate symbol characters.   \value AddSpaceForLineAndParagraphSeparators While determining the line-break positions take into account the             space added for drawing a separator character.   \value SuppressColors Suppress all color changes in the character formats (except the main selection). */
end_comment
begin_comment
comment|/*!   \fn Flags QTextOption::flags() const    Returns the flags associated with the option.    \sa setFlags() */
end_comment
begin_comment
comment|/*!   \fn void QTextOption::setFlags(Flags flags)    Sets the flags associated with the option to the given \a flags.    \sa flags() */
end_comment
begin_comment
comment|/*!   \fn qreal QTextOption::tabStop() const    Returns the distance in device units between tab stops.   Convenient function for the above method    \sa setTabStop(), tabArray(), setTabs(), tabs() */
end_comment
begin_comment
comment|/*!   \fn void QTextOption::setTabStop(qreal tabStop)    Sets the default distance in device units between tab stops to the value specified   by \a tabStop.    \sa tabStop(), setTabArray(), setTabs(), tabs() */
end_comment
begin_comment
comment|/*!     \enum QTextOption::TabType     \since 4.4      This enum holds the different types of tabulator      \value LeftTab      A left-tab     \value RightTab     A right-tab     \value CenterTab    A centered-tab     \value DelimiterTab A tab stopping at a certain delimiter-character */
end_comment
begin_comment
comment|/*!     \class QTextOption::Tab     \since 4.4     \inmodule QtGui     Each tab definition is represented by this struct. */
end_comment
begin_comment
comment|/*!     \variable Tab::position     Distance from the start of the paragraph.     The position of a tab is from the start of the paragraph which implies that when     the alignment of the paragraph is set to centered, the tab is interpreted to be     moved the same distance as the left ege of the paragraph does.     In case the paragraph is set to have a layoutDirection() RightToLeft the position     is interpreted to be from the right side of the paragraph with higher numbers moving     the tab to the left. */
end_comment
begin_comment
comment|/*!     \variable Tab::type     Determine which type is used.     In a paragraph that has layoutDirection() RightToLeft the type LeftTab will     be interpreted to be a RightTab and vice versa. */
end_comment
begin_comment
comment|/*!     \variable Tab::delimiter     If type is DelimitorTab; tab until this char is found in the text. */
end_comment
begin_comment
comment|/*!     \fn Tab::Tab()     Creates a default left tab with position 80. */
end_comment
begin_comment
comment|/*!     \fn Tab::Tab(qreal pos, TabType tabType, QChar delim = QChar())      Creates a tab with the given position, tab type, and delimiter     (\a pos, \a tabType, \a delim).      \note \a delim is only used when \a tabType is DelimiterTab.      \since 4.7 */
end_comment
begin_comment
comment|/*!     \fn bool Tab::operator==(const Tab&other) const      Returns \c true if tab \a other is equal to this tab;     otherwise returns \c false. */
end_comment
begin_comment
comment|/*!     \fn bool Tab::operator!=(const Tab&other) const      Returns \c true if tab \a other is not equal to this tab;     otherwise returns \c false. */
end_comment
begin_comment
comment|/*!   \fn void setTabs(const QList<Tab>&tabStops)   Set the Tab properties to \a tabStops.    \sa tabStop(), tabs() */
end_comment
begin_comment
comment|/*!   \since 4.4   \fn QList<QTextOption::Tab> QTextOption::tabs() const   Returns a list of tab positions defined for the text layout.    \sa tabStop(), setTabs(), setTabStop() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
