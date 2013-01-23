begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|"atom.h"
end_include
begin_include
include|#
directive|include
file|"location.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|QLatin1String
name|Atom
operator|::
name|BOLD_
argument_list|(
literal|"bold"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|INDEX_
argument_list|(
literal|"index"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|ITALIC_
argument_list|(
literal|"italic"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|LINK_
argument_list|(
literal|"link"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|PARAMETER_
argument_list|(
literal|"parameter"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|SPAN_
argument_list|(
literal|"span"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|SUBSCRIPT_
argument_list|(
literal|"subscript"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|SUPERSCRIPT_
argument_list|(
literal|"superscript"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|TELETYPE_
argument_list|(
literal|"teletype"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|UICONTROL_
argument_list|(
literal|"uicontrol"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|UNDERLINE_
argument_list|(
literal|"underline"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|BULLET_
argument_list|(
literal|"bullet"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|TAG_
argument_list|(
literal|"tag"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|VALUE_
argument_list|(
literal|"value"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|LOWERALPHA_
argument_list|(
literal|"loweralpha"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|LOWERROMAN_
argument_list|(
literal|"lowerroman"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|NUMERIC_
argument_list|(
literal|"numeric"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|UPPERALPHA_
argument_list|(
literal|"upperalpha"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLatin1String
name|Atom
operator|::
name|UPPERROMAN_
argument_list|(
literal|"upperroman"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*! \class Atom     \brief The Atom class is the fundamental unit for representing     documents internally.    Atoms have a \i type and are completed by a \i string whose   meaning depends on the \i type. For example, the string   \quotation       \i italic text looks nicer than \bold bold text   \endquotation   is represented by the following atoms:   \quotation       (FormattingLeft, ATOM_FORMATTING_ITALIC)       (String, "italic")       (FormattingRight, ATOM_FORMATTING_ITALIC)       (String, " text is more attractive than ")       (FormattingLeft, ATOM_FORMATTING_BOLD)       (String, "bold")       (FormattingRight, ATOM_FORMATTING_BOLD)       (String, " text")   \endquotation    \also Text */
end_comment
begin_comment
comment|/*! \enum Atom::Type    \value AbstractLeft   \value AbstractRight   \value AnnotatedList   \value AutoLink   \value BaseName   \value BriefLeft   \value BriefRight   \value C   \value CaptionLeft   \value CaptionRight   \value Code   \value CodeBad   \value CodeNew   \value CodeOld   \value CodeQuoteArgument   \value CodeQuoteCommand   \value DivLeft   \value DivRight   \value EndQmlText   \value FormatElse   \value FormatEndif   \value FormatIf   \value FootnoteLeft   \value FootnoteRight   \value FormattingLeft   \value FormattingRight   \value GeneratedList   \value Image   \value ImageText   \value ImportantNote   \value InlineImage   \value LineBreak   \value Link   \value LinkNode   \value ListLeft   \value ListItemNumber   \value ListTagLeft   \value ListTagRight   \value ListItemLeft   \value ListItemRight   \value ListRight   \value Nop   \value Note   \value ParaLeft   \value ParaRight   \value Qml   \value QmlText   \value QuotationLeft   \value QuotationRight   \value RawString   \value SectionLeft   \value SectionRight   \value SectionHeadingLeft   \value SectionHeadingRight   \value SidebarLeft   \value SidebarRight   \value SinceList   \value String   \value TableLeft   \value TableRight   \value TableHeaderLeft   \value TableHeaderRight   \value TableRowLeft   \value TableRowRight   \value TableItemLeft   \value TableItemRight   \value TableOfContents   \value Target   \value UnhandledFormat   \value UnknownCommand */
end_comment
begin_struct
specifier|static
specifier|const
struct|struct
block|{
DECL|member|english
specifier|const
name|char
modifier|*
name|english
decl_stmt|;
DECL|member|no
name|int
name|no
decl_stmt|;
block|}
DECL|variable|atms
name|atms
index|[]
init|=
block|{
block|{
literal|"AbstractLeft"
block|,
name|Atom
operator|::
name|AbstractLeft
block|}
block|,
block|{
literal|"AbstractRight"
block|,
name|Atom
operator|::
name|AbstractRight
block|}
block|,
block|{
literal|"AnnotatedList"
block|,
name|Atom
operator|::
name|AnnotatedList
block|}
block|,
block|{
literal|"AutoLink"
block|,
name|Atom
operator|::
name|AutoLink
block|}
block|,
block|{
literal|"BaseName"
block|,
name|Atom
operator|::
name|BaseName
block|}
block|,
block|{
literal|"br"
block|,
name|Atom
operator|::
name|BR
block|}
block|,
block|{
literal|"BriefLeft"
block|,
name|Atom
operator|::
name|BriefLeft
block|}
block|,
block|{
literal|"BriefRight"
block|,
name|Atom
operator|::
name|BriefRight
block|}
block|,
block|{
literal|"C"
block|,
name|Atom
operator|::
name|C
block|}
block|,
block|{
literal|"CaptionLeft"
block|,
name|Atom
operator|::
name|CaptionLeft
block|}
block|,
block|{
literal|"CaptionRight"
block|,
name|Atom
operator|::
name|CaptionRight
block|}
block|,
block|{
literal|"Code"
block|,
name|Atom
operator|::
name|Code
block|}
block|,
block|{
literal|"CodeBad"
block|,
name|Atom
operator|::
name|CodeBad
block|}
block|,
block|{
literal|"CodeNew"
block|,
name|Atom
operator|::
name|CodeNew
block|}
block|,
block|{
literal|"CodeOld"
block|,
name|Atom
operator|::
name|CodeOld
block|}
block|,
block|{
literal|"CodeQuoteArgument"
block|,
name|Atom
operator|::
name|CodeQuoteArgument
block|}
block|,
block|{
literal|"CodeQuoteCommand"
block|,
name|Atom
operator|::
name|CodeQuoteCommand
block|}
block|,
block|{
literal|"DivLeft"
block|,
name|Atom
operator|::
name|DivLeft
block|}
block|,
block|{
literal|"DivRight"
block|,
name|Atom
operator|::
name|DivRight
block|}
block|,
block|{
literal|"EndQmlText"
block|,
name|Atom
operator|::
name|EndQmlText
block|}
block|,
block|{
literal|"FootnoteLeft"
block|,
name|Atom
operator|::
name|FootnoteLeft
block|}
block|,
block|{
literal|"FootnoteRight"
block|,
name|Atom
operator|::
name|FootnoteRight
block|}
block|,
block|{
literal|"FormatElse"
block|,
name|Atom
operator|::
name|FormatElse
block|}
block|,
block|{
literal|"FormatEndif"
block|,
name|Atom
operator|::
name|FormatEndif
block|}
block|,
block|{
literal|"FormatIf"
block|,
name|Atom
operator|::
name|FormatIf
block|}
block|,
block|{
literal|"FormattingLeft"
block|,
name|Atom
operator|::
name|FormattingLeft
block|}
block|,
block|{
literal|"FormattingRight"
block|,
name|Atom
operator|::
name|FormattingRight
block|}
block|,
block|{
literal|"GeneratedList"
block|,
name|Atom
operator|::
name|GeneratedList
block|}
block|,
block|{
literal|"GuidLink"
block|,
name|Atom
operator|::
name|GuidLink
block|}
block|,
block|{
literal|"hr"
block|,
name|Atom
operator|::
name|HR
block|}
block|,
block|{
literal|"Image"
block|,
name|Atom
operator|::
name|Image
block|}
block|,
block|{
literal|"ImageText"
block|,
name|Atom
operator|::
name|ImageText
block|}
block|,
block|{
literal|"ImportantLeft"
block|,
name|Atom
operator|::
name|ImportantLeft
block|}
block|,
block|{
literal|"ImportantRight"
block|,
name|Atom
operator|::
name|ImportantRight
block|}
block|,
block|{
literal|"InlineImage"
block|,
name|Atom
operator|::
name|InlineImage
block|}
block|,
block|{
literal|"JavaScript"
block|,
name|Atom
operator|::
name|JavaScript
block|}
block|,
block|{
literal|"EndJavaScript"
block|,
name|Atom
operator|::
name|EndJavaScript
block|}
block|,
block|{
literal|"LegaleseLeft"
block|,
name|Atom
operator|::
name|LegaleseLeft
block|}
block|,
block|{
literal|"LegaleseRight"
block|,
name|Atom
operator|::
name|LegaleseRight
block|}
block|,
block|{
literal|"LineBreak"
block|,
name|Atom
operator|::
name|LineBreak
block|}
block|,
block|{
literal|"Link"
block|,
name|Atom
operator|::
name|Link
block|}
block|,
block|{
literal|"LinkNode"
block|,
name|Atom
operator|::
name|LinkNode
block|}
block|,
block|{
literal|"ListLeft"
block|,
name|Atom
operator|::
name|ListLeft
block|}
block|,
block|{
literal|"ListItemNumber"
block|,
name|Atom
operator|::
name|ListItemNumber
block|}
block|,
block|{
literal|"ListTagLeft"
block|,
name|Atom
operator|::
name|ListTagLeft
block|}
block|,
block|{
literal|"ListTagRight"
block|,
name|Atom
operator|::
name|ListTagRight
block|}
block|,
block|{
literal|"ListItemLeft"
block|,
name|Atom
operator|::
name|ListItemLeft
block|}
block|,
block|{
literal|"ListItemRight"
block|,
name|Atom
operator|::
name|ListItemRight
block|}
block|,
block|{
literal|"ListRight"
block|,
name|Atom
operator|::
name|ListRight
block|}
block|,
block|{
literal|"Nop"
block|,
name|Atom
operator|::
name|Nop
block|}
block|,
block|{
literal|"NoteLeft"
block|,
name|Atom
operator|::
name|NoteLeft
block|}
block|,
block|{
literal|"NoteRight"
block|,
name|Atom
operator|::
name|NoteRight
block|}
block|,
block|{
literal|"ParaLeft"
block|,
name|Atom
operator|::
name|ParaLeft
block|}
block|,
block|{
literal|"ParaRight"
block|,
name|Atom
operator|::
name|ParaRight
block|}
block|,
block|{
literal|"Qml"
block|,
name|Atom
operator|::
name|Qml
block|}
block|,
block|{
literal|"QmlText"
block|,
name|Atom
operator|::
name|QmlText
block|}
block|,
block|{
literal|"QuotationLeft"
block|,
name|Atom
operator|::
name|QuotationLeft
block|}
block|,
block|{
literal|"QuotationRight"
block|,
name|Atom
operator|::
name|QuotationRight
block|}
block|,
block|{
literal|"RawString"
block|,
name|Atom
operator|::
name|RawString
block|}
block|,
block|{
literal|"SectionLeft"
block|,
name|Atom
operator|::
name|SectionLeft
block|}
block|,
block|{
literal|"SectionRight"
block|,
name|Atom
operator|::
name|SectionRight
block|}
block|,
block|{
literal|"SectionHeadingLeft"
block|,
name|Atom
operator|::
name|SectionHeadingLeft
block|}
block|,
block|{
literal|"SectionHeadingRight"
block|,
name|Atom
operator|::
name|SectionHeadingRight
block|}
block|,
block|{
literal|"SidebarLeft"
block|,
name|Atom
operator|::
name|SidebarLeft
block|}
block|,
block|{
literal|"SidebarRight"
block|,
name|Atom
operator|::
name|SidebarRight
block|}
block|,
block|{
literal|"SinceList"
block|,
name|Atom
operator|::
name|SinceList
block|}
block|,
block|{
literal|"SnippetCommand"
block|,
name|Atom
operator|::
name|SnippetCommand
block|}
block|,
block|{
literal|"SnippetIdentifier"
block|,
name|Atom
operator|::
name|SnippetIdentifier
block|}
block|,
block|{
literal|"SnippetLocation"
block|,
name|Atom
operator|::
name|SnippetLocation
block|}
block|,
block|{
literal|"String"
block|,
name|Atom
operator|::
name|String
block|}
block|,
block|{
literal|"TableLeft"
block|,
name|Atom
operator|::
name|TableLeft
block|}
block|,
block|{
literal|"TableRight"
block|,
name|Atom
operator|::
name|TableRight
block|}
block|,
block|{
literal|"TableHeaderLeft"
block|,
name|Atom
operator|::
name|TableHeaderLeft
block|}
block|,
block|{
literal|"TableHeaderRight"
block|,
name|Atom
operator|::
name|TableHeaderRight
block|}
block|,
block|{
literal|"TableRowLeft"
block|,
name|Atom
operator|::
name|TableRowLeft
block|}
block|,
block|{
literal|"TableRowRight"
block|,
name|Atom
operator|::
name|TableRowRight
block|}
block|,
block|{
literal|"TableItemLeft"
block|,
name|Atom
operator|::
name|TableItemLeft
block|}
block|,
block|{
literal|"TableItemRight"
block|,
name|Atom
operator|::
name|TableItemRight
block|}
block|,
block|{
literal|"TableOfContents"
block|,
name|Atom
operator|::
name|TableOfContents
block|}
block|,
block|{
literal|"Target"
block|,
name|Atom
operator|::
name|Target
block|}
block|,
block|{
literal|"UnhandledFormat"
block|,
name|Atom
operator|::
name|UnhandledFormat
block|}
block|,
block|{
literal|"UnknownCommand"
block|,
name|Atom
operator|::
name|UnknownCommand
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
struct|;
end_struct
begin_comment
comment|/*! \fn Atom::Atom(Type type, const QString& string)    Constructs an atom of the specified \a type with the single   parameter \a string and does not put the new atom in a list. */
end_comment
begin_comment
comment|/*! \fn Atom::Atom(Type type, const QString& p1, const QString& p2)    Constructs an atom of the specified \a type with the two   parameters \a p1 and \a p2 and does not put the new atom   in a list. */
end_comment
begin_comment
comment|/*! \fn Atom(Atom *previous, Type type, const QString& string)    Constructs an atom of the specified \a type with the single   parameter \a string and inserts the new atom into the list   after the \a previous atom. */
end_comment
begin_comment
comment|/*! \fn Atom::Atom(Atom* previous, Type type, const QString& p1, const QString& p2)    Constructs an atom of the specified \a type with the two   parameters \a p1 and \a p2 and inserts the new atom into   the list after the \a previous atom. */
end_comment
begin_comment
comment|/*! \fn void Atom::appendChar(QChar ch)    Appends \a ch to the string parameter of this atom.    \also string() */
end_comment
begin_comment
comment|/*! \fn void Atom::appendString(const QString& string)    Appends \a string to the string parameter of this atom.    \also string() */
end_comment
begin_comment
comment|/*! \fn void Atom::chopString()    \also string() */
end_comment
begin_comment
comment|/*! \fn Atom *Atom::next()   Return the next atom in the atom list.   \also type(), string() */
end_comment
begin_comment
comment|/*!   Return the next Atom in the list if it is of Type \a t.   Otherwise return 0.  */
end_comment
begin_function
DECL|function|next
specifier|const
name|Atom
modifier|*
name|Atom
operator|::
name|next
parameter_list|(
name|Type
name|t
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|next_
operator|&&
operator|(
name|next_
operator|->
name|type
argument_list|()
operator|==
name|t
operator|)
operator|)
condition|?
name|next_
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!   Return the next Atom in the list if it is of Type \a t   and its string part is \a s. Otherwise return 0.  */
end_comment
begin_function
DECL|function|next
specifier|const
name|Atom
modifier|*
name|Atom
operator|::
name|next
parameter_list|(
name|Type
name|t
parameter_list|,
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|next_
operator|&&
operator|(
name|next_
operator|->
name|type
argument_list|()
operator|==
name|t
operator|)
operator|&&
operator|(
name|next_
operator|->
name|string
argument_list|()
operator|==
name|s
operator|)
operator|)
condition|?
name|next_
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|/*! \fn const Atom *Atom::next() const   Return the next atom in the atom list.   \also type(), string() */
end_comment
begin_comment
comment|/*! \fn Type Atom::type() const   Return the type of this atom.   \also string(), next() */
end_comment
begin_comment
comment|/*!   Return the type of this atom as a string. Return "Invalid" if   type() returns an impossible value.    This is only useful for debugging.    \also type() */
end_comment
begin_function
DECL|function|typeString
name|QString
name|Atom
operator|::
name|typeString
parameter_list|()
specifier|const
block|{
specifier|static
name|bool
name|deja
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|deja
condition|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|atms
index|[
name|i
index|]
operator|.
name|english
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|atms
index|[
name|i
index|]
operator|.
name|no
operator|!=
name|i
condition|)
name|Location
operator|::
name|internalError
argument_list|(
name|tr
argument_list|(
literal|"atom %1 missing"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
name|deja
operator|=
literal|true
expr_stmt|;
block|}
name|int
name|i
init|=
operator|(
name|int
operator|)
name|type
argument_list|()
decl_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
operator|||
name|i
operator|>
operator|(
name|int
operator|)
name|Last
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"Invalid"
argument_list|)
return|;
return|return
name|QLatin1String
argument_list|(
name|atms
index|[
name|i
index|]
operator|.
name|english
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \fn const QString& Atom::string() const    Returns the string parameter that together with the type   characterizes this atom.    \also type(), next() */
end_comment
begin_comment
comment|/*!   Dumps this Atom to stderr in printer friendly form.  */
end_comment
begin_function
DECL|function|dump
name|void
name|Atom
operator|::
name|dump
parameter_list|()
specifier|const
block|{
name|QString
name|str
init|=
name|string
argument_list|()
decl_stmt|;
name|str
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\\\\"
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"\""
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\\\""
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"\n"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\\n"
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"[^\x20-\x7e]"
argument_list|)
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"?"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|=
name|QLatin1String
argument_list|(
literal|" \""
argument_list|)
operator|+
name|str
operator|+
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    %-15s%s\n"
argument_list|,
name|typeString
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|str
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
