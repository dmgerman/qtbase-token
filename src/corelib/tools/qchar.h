begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCHAR_H
end_ifndef
begin_define
DECL|macro|QCHAR_H
define|#
directive|define
name|QCHAR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QLatin1Char
struct|struct
name|QLatin1Char
block|{
DECL|member|public
name|public
label|:
name|Q_DECL_CONSTEXPR
specifier|inline
name|explicit
name|QLatin1Char
argument_list|(
argument|char c
argument_list|)
operator|:
name|ch
argument_list|(
argument|c
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|char
name|toLatin1
argument_list|()
specifier|const
block|{
return|return
name|ch
return|;
block|}
DECL|function|unicode
name|Q_DECL_CONSTEXPR
specifier|inline
name|ushort
name|unicode
argument_list|()
specifier|const
block|{
return|return
name|ushort
argument_list|(
name|uchar
argument_list|(
name|ch
argument_list|)
argument_list|)
return|;
block|}
name|private
label|:
DECL|variable|ch
name|char
name|ch
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QChar
block|{
name|public
label|:
enum|enum
name|SpecialCharacter
block|{
name|Null
init|=
literal|0x0000
block|,
name|Tabulation
init|=
literal|0x0009
block|,
name|LineFeed
init|=
literal|0x000a
block|,
name|CarriageReturn
init|=
literal|0x000d
block|,
name|Space
init|=
literal|0x0020
block|,
name|Nbsp
init|=
literal|0x00a0
block|,
name|SoftHyphen
init|=
literal|0x00ad
block|,
name|ReplacementCharacter
init|=
literal|0xfffd
block|,
name|ObjectReplacementCharacter
init|=
literal|0xfffc
block|,
name|ByteOrderMark
init|=
literal|0xfeff
block|,
name|ByteOrderSwapped
init|=
literal|0xfffe
block|,
name|ParagraphSeparator
init|=
literal|0x2029
block|,
name|LineSeparator
init|=
literal|0x2028
block|,
name|LastValidCodePoint
init|=
literal|0x10ffff
block|}
enum|;
name|Q_DECL_CONSTEXPR
name|QChar
argument_list|()
operator|:
name|ucs
argument_list|(
literal|0
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QChar
argument_list|(
argument|ushort rc
argument_list|)
operator|:
name|ucs
argument_list|(
argument|rc
argument_list|)
block|{}
comment|// implicit
name|Q_DECL_CONSTEXPR
name|QChar
argument_list|(
argument|uchar c
argument_list|,
argument|uchar r
argument_list|)
operator|:
name|ucs
argument_list|(
argument|ushort((r<<
literal|8
argument|) | c)
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QChar
argument_list|(
argument|short rc
argument_list|)
operator|:
name|ucs
argument_list|(
argument|ushort(rc)
argument_list|)
block|{}
comment|// implicit
name|Q_DECL_CONSTEXPR
name|QChar
argument_list|(
argument|uint rc
argument_list|)
operator|:
name|ucs
argument_list|(
argument|ushort(rc&
literal|0xffff
argument|)
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QChar
argument_list|(
argument|int rc
argument_list|)
operator|:
name|ucs
argument_list|(
argument|ushort(rc&
literal|0xffff
argument|)
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QChar
argument_list|(
argument|SpecialCharacter s
argument_list|)
operator|:
name|ucs
argument_list|(
argument|ushort(s)
argument_list|)
block|{}
comment|// implicit
name|Q_DECL_CONSTEXPR
name|QChar
argument_list|(
argument|QLatin1Char ch
argument_list|)
operator|:
name|ucs
argument_list|(
argument|ch.unicode()
argument_list|)
block|{}
comment|// implicit
ifndef|#
directive|ifndef
name|QT_NO_CAST_FROM_ASCII
name|QT_ASCII_CAST_WARN
name|Q_DECL_CONSTEXPR
name|explicit
name|QChar
argument_list|(
argument|char c
argument_list|)
operator|:
name|ucs
argument_list|(
argument|uchar(c)
argument_list|)
block|{ }
name|QT_ASCII_CAST_WARN
name|Q_DECL_CONSTEXPR
name|explicit
name|QChar
argument_list|(
argument|uchar c
argument_list|)
operator|:
name|ucs
argument_list|(
argument|c
argument_list|)
block|{ }
endif|#
directive|endif
comment|// Unicode information
expr|enum
name|Category
block|{
name|Mark_NonSpacing
block|,
comment|//   Mn
name|Mark_SpacingCombining
block|,
comment|//   Mc
name|Mark_Enclosing
block|,
comment|//   Me
name|Number_DecimalDigit
block|,
comment|//   Nd
name|Number_Letter
block|,
comment|//   Nl
name|Number_Other
block|,
comment|//   No
name|Separator_Space
block|,
comment|//   Zs
name|Separator_Line
block|,
comment|//   Zl
name|Separator_Paragraph
block|,
comment|//   Zp
name|Other_Control
block|,
comment|//   Cc
name|Other_Format
block|,
comment|//   Cf
name|Other_Surrogate
block|,
comment|//   Cs
name|Other_PrivateUse
block|,
comment|//   Co
name|Other_NotAssigned
block|,
comment|//   Cn
name|Letter_Uppercase
block|,
comment|//   Lu
name|Letter_Lowercase
block|,
comment|//   Ll
name|Letter_Titlecase
block|,
comment|//   Lt
name|Letter_Modifier
block|,
comment|//   Lm
name|Letter_Other
block|,
comment|//   Lo
name|Punctuation_Connector
block|,
comment|//   Pc
name|Punctuation_Dash
block|,
comment|//   Pd
name|Punctuation_Open
block|,
comment|//   Ps
name|Punctuation_Close
block|,
comment|//   Pe
name|Punctuation_InitialQuote
block|,
comment|//   Pi
name|Punctuation_FinalQuote
block|,
comment|//   Pf
name|Punctuation_Other
block|,
comment|//   Po
name|Symbol_Math
block|,
comment|//   Sm
name|Symbol_Currency
block|,
comment|//   Sc
name|Symbol_Modifier
block|,
comment|//   Sk
name|Symbol_Other
comment|//   So
block|}
expr_stmt|;
enum|enum
name|Script
block|{
name|Script_Unknown
block|,
name|Script_Inherited
block|,
name|Script_Common
block|,
name|Script_Latin
block|,
name|Script_Greek
block|,
name|Script_Cyrillic
block|,
name|Script_Armenian
block|,
name|Script_Hebrew
block|,
name|Script_Arabic
block|,
name|Script_Syriac
block|,
name|Script_Thaana
block|,
name|Script_Devanagari
block|,
name|Script_Bengali
block|,
name|Script_Gurmukhi
block|,
name|Script_Gujarati
block|,
name|Script_Oriya
block|,
name|Script_Tamil
block|,
name|Script_Telugu
block|,
name|Script_Kannada
block|,
name|Script_Malayalam
block|,
name|Script_Sinhala
block|,
name|Script_Thai
block|,
name|Script_Lao
block|,
name|Script_Tibetan
block|,
name|Script_Myanmar
block|,
name|Script_Georgian
block|,
name|Script_Hangul
block|,
name|Script_Ethiopic
block|,
name|Script_Cherokee
block|,
name|Script_CanadianAboriginal
block|,
name|Script_Ogham
block|,
name|Script_Runic
block|,
name|Script_Khmer
block|,
name|Script_Mongolian
block|,
name|Script_Hiragana
block|,
name|Script_Katakana
block|,
name|Script_Bopomofo
block|,
name|Script_Han
block|,
name|Script_Yi
block|,
name|Script_OldItalic
block|,
name|Script_Gothic
block|,
name|Script_Deseret
block|,
name|Script_Tagalog
block|,
name|Script_Hanunoo
block|,
name|Script_Buhid
block|,
name|Script_Tagbanwa
block|,
name|Script_Coptic
block|,
comment|// Unicode 4.0 additions
name|Script_Limbu
block|,
name|Script_TaiLe
block|,
name|Script_LinearB
block|,
name|Script_Ugaritic
block|,
name|Script_Shavian
block|,
name|Script_Osmanya
block|,
name|Script_Cypriot
block|,
name|Script_Braille
block|,
comment|// Unicode 4.1 additions
name|Script_Buginese
block|,
name|Script_NewTaiLue
block|,
name|Script_Glagolitic
block|,
name|Script_Tifinagh
block|,
name|Script_SylotiNagri
block|,
name|Script_OldPersian
block|,
name|Script_Kharoshthi
block|,
comment|// Unicode 5.0 additions
name|Script_Balinese
block|,
name|Script_Cuneiform
block|,
name|Script_Phoenician
block|,
name|Script_PhagsPa
block|,
name|Script_Nko
block|,
comment|// Unicode 5.1 additions
name|Script_Sundanese
block|,
name|Script_Lepcha
block|,
name|Script_OlChiki
block|,
name|Script_Vai
block|,
name|Script_Saurashtra
block|,
name|Script_KayahLi
block|,
name|Script_Rejang
block|,
name|Script_Lycian
block|,
name|Script_Carian
block|,
name|Script_Lydian
block|,
name|Script_Cham
block|,
comment|// Unicode 5.2 additions
name|Script_TaiTham
block|,
name|Script_TaiViet
block|,
name|Script_Avestan
block|,
name|Script_EgyptianHieroglyphs
block|,
name|Script_Samaritan
block|,
name|Script_Lisu
block|,
name|Script_Bamum
block|,
name|Script_Javanese
block|,
name|Script_MeeteiMayek
block|,
name|Script_ImperialAramaic
block|,
name|Script_OldSouthArabian
block|,
name|Script_InscriptionalParthian
block|,
name|Script_InscriptionalPahlavi
block|,
name|Script_OldTurkic
block|,
name|Script_Kaithi
block|,
comment|// Unicode 6.0 additions
name|Script_Batak
block|,
name|Script_Brahmi
block|,
name|Script_Mandaic
block|,
comment|// Unicode 6.1 additions
name|Script_Chakma
block|,
name|Script_MeroiticCursive
block|,
name|Script_MeroiticHieroglyphs
block|,
name|Script_Miao
block|,
name|Script_Sharada
block|,
name|Script_SoraSompeng
block|,
name|Script_Takri
block|,
name|ScriptCount
block|}
enum|;
enum|enum
name|Direction
block|{
name|DirL
block|,
name|DirR
block|,
name|DirEN
block|,
name|DirES
block|,
name|DirET
block|,
name|DirAN
block|,
name|DirCS
block|,
name|DirB
block|,
name|DirS
block|,
name|DirWS
block|,
name|DirON
block|,
name|DirLRE
block|,
name|DirLRO
block|,
name|DirAL
block|,
name|DirRLE
block|,
name|DirRLO
block|,
name|DirPDF
block|,
name|DirNSM
block|,
name|DirBN
block|,
name|DirLRI
block|,
name|DirRLI
block|,
name|DirFSI
block|,
name|DirPDI
block|}
enum|;
enum|enum
name|Decomposition
block|{
name|NoDecomposition
block|,
name|Canonical
block|,
name|Font
block|,
name|NoBreak
block|,
name|Initial
block|,
name|Medial
block|,
name|Final
block|,
name|Isolated
block|,
name|Circle
block|,
name|Super
block|,
name|Sub
block|,
name|Vertical
block|,
name|Wide
block|,
name|Narrow
block|,
name|Small
block|,
name|Square
block|,
name|Compat
block|,
name|Fraction
block|}
enum|;
enum|enum
name|JoiningType
block|{
name|Joining_None
block|,
name|Joining_Causing
block|,
name|Joining_Dual
block|,
name|Joining_Right
block|,
name|Joining_Left
block|,
name|Joining_Transparent
block|}
enum|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|3
argument_list|)
enum|enum
name|Joining
block|{
name|OtherJoining
block|,
name|Dual
block|,
name|Right
block|,
name|Center
block|}
enum|;
endif|#
directive|endif
enum|enum
name|CombiningClass
block|{
name|Combining_BelowLeftAttached
init|=
literal|200
block|,
name|Combining_BelowAttached
init|=
literal|202
block|,
name|Combining_BelowRightAttached
init|=
literal|204
block|,
name|Combining_LeftAttached
init|=
literal|208
block|,
name|Combining_RightAttached
init|=
literal|210
block|,
name|Combining_AboveLeftAttached
init|=
literal|212
block|,
name|Combining_AboveAttached
init|=
literal|214
block|,
name|Combining_AboveRightAttached
init|=
literal|216
block|,
name|Combining_BelowLeft
init|=
literal|218
block|,
name|Combining_Below
init|=
literal|220
block|,
name|Combining_BelowRight
init|=
literal|222
block|,
name|Combining_Left
init|=
literal|224
block|,
name|Combining_Right
init|=
literal|226
block|,
name|Combining_AboveLeft
init|=
literal|228
block|,
name|Combining_Above
init|=
literal|230
block|,
name|Combining_AboveRight
init|=
literal|232
block|,
name|Combining_DoubleBelow
init|=
literal|233
block|,
name|Combining_DoubleAbove
init|=
literal|234
block|,
name|Combining_IotaSubscript
init|=
literal|240
block|}
enum|;
enum|enum
name|UnicodeVersion
block|{
name|Unicode_Unassigned
block|,
name|Unicode_1_1
block|,
name|Unicode_2_0
block|,
name|Unicode_2_1_2
block|,
name|Unicode_3_0
block|,
name|Unicode_3_1
block|,
name|Unicode_3_2
block|,
name|Unicode_4_0
block|,
name|Unicode_4_1
block|,
name|Unicode_5_0
block|,
name|Unicode_5_1
block|,
name|Unicode_5_2
block|,
name|Unicode_6_0
block|,
name|Unicode_6_1
block|,
name|Unicode_6_2
block|,
name|Unicode_6_3
block|}
enum|;
comment|// ****** WHEN ADDING FUNCTIONS, CONSIDER ADDING TO QCharRef TOO
specifier|inline
name|Category
name|category
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|category
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|Direction
name|direction
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|direction
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|JoiningType
name|joiningType
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|joiningType
argument_list|(
name|ucs
argument_list|)
return|;
block|}
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|3
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|Joining
name|joining
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|QChar
operator|::
name|joiningType
argument_list|(
name|ucs
argument_list|)
condition|)
block|{
case|case
name|QChar
operator|::
name|Joining_Causing
case|:
return|return
name|QChar
operator|::
name|Center
return|;
case|case
name|QChar
operator|::
name|Joining_Dual
case|:
return|return
name|QChar
operator|::
name|Dual
return|;
case|case
name|QChar
operator|::
name|Joining_Right
case|:
return|return
name|QChar
operator|::
name|Right
return|;
case|case
name|QChar
operator|::
name|Joining_None
case|:
case|case
name|QChar
operator|::
name|Joining_Left
case|:
case|case
name|QChar
operator|::
name|Joining_Transparent
case|:
default|default:
return|return
name|QChar
operator|::
name|OtherJoining
return|;
block|}
block|}
endif|#
directive|endif
specifier|inline
name|unsigned
name|char
name|combiningClass
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|combiningClass
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|QChar
name|mirroredChar
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|mirroredChar
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|hasMirrored
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|hasMirrored
argument_list|(
name|ucs
argument_list|)
return|;
block|}
name|QString
name|decomposition
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|Decomposition
name|decompositionTag
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|decompositionTag
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|int
name|digitValue
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|digitValue
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|QChar
name|toLower
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|toLower
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|QChar
name|toUpper
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|toUpper
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|QChar
name|toTitleCase
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|toTitleCase
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|QChar
name|toCaseFolded
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|toCaseFolded
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|Script
name|script
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|script
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|UnicodeVersion
name|unicodeVersion
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|unicodeVersion
argument_list|(
name|ucs
argument_list|)
return|;
block|}
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|char
name|toAscii
argument_list|()
specifier|const
block|{
return|return
name|toLatin1
argument_list|()
return|;
block|}
endif|#
directive|endif
specifier|inline
name|char
name|toLatin1
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|ushort
name|unicode
argument_list|()
specifier|const
block|{
return|return
name|ucs
return|;
block|}
specifier|inline
name|ushort
modifier|&
name|unicode
parameter_list|()
block|{
return|return
name|ucs
return|;
block|}
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|static
specifier|inline
name|QChar
name|fromAscii
parameter_list|(
name|char
name|c
parameter_list|)
block|{
return|return
name|fromLatin1
argument_list|(
name|c
argument_list|)
return|;
block|}
endif|#
directive|endif
specifier|static
specifier|inline
name|QChar
name|fromLatin1
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|ucs
operator|==
literal|0
return|;
block|}
specifier|inline
name|bool
name|isPrint
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isPrint
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isSpace
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isSpace
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isMark
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isMark
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isPunct
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isPunct
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isSymbol
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isSymbol
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isLetter
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isLetter
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isNumber
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isNumber
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isLetterOrNumber
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isLetterOrNumber
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isDigit
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isDigit
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isLower
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isLower
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isUpper
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isUpper
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isTitleCase
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isTitleCase
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isNonCharacter
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isNonCharacter
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isHighSurrogate
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isHighSurrogate
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isLowSurrogate
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isLowSurrogate
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|isSurrogate
argument_list|()
specifier|const
block|{
return|return
name|QChar
operator|::
name|isSurrogate
argument_list|(
name|ucs
argument_list|)
return|;
block|}
specifier|inline
name|uchar
name|cell
argument_list|()
specifier|const
block|{
return|return
name|uchar
argument_list|(
name|ucs
operator|&
literal|0xff
argument_list|)
return|;
block|}
specifier|inline
name|uchar
name|row
argument_list|()
specifier|const
block|{
return|return
name|uchar
argument_list|(
operator|(
name|ucs
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
return|;
block|}
specifier|inline
name|void
name|setCell
parameter_list|(
name|uchar
name|cell
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setRow
parameter_list|(
name|uchar
name|row
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|bool
name|isNonCharacter
parameter_list|(
name|uint
name|ucs4
parameter_list|)
block|{
return|return
name|ucs4
operator|>=
literal|0xfdd0
operator|&&
operator|(
name|ucs4
operator|<=
literal|0xfdef
operator|||
operator|(
name|ucs4
operator|&
literal|0xfffe
operator|)
operator|==
literal|0xfffe
operator|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isHighSurrogate
parameter_list|(
name|uint
name|ucs4
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ucs4
operator|&
literal|0xfffffc00
operator|)
operator|==
literal|0xd800
operator|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isLowSurrogate
parameter_list|(
name|uint
name|ucs4
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ucs4
operator|&
literal|0xfffffc00
operator|)
operator|==
literal|0xdc00
operator|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isSurrogate
parameter_list|(
name|uint
name|ucs4
parameter_list|)
block|{
return|return
operator|(
name|ucs4
operator|-
literal|0xd800u
operator|<
literal|2048u
operator|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|requiresSurrogates
parameter_list|(
name|uint
name|ucs4
parameter_list|)
block|{
return|return
operator|(
name|ucs4
operator|>=
literal|0x10000
operator|)
return|;
block|}
specifier|static
specifier|inline
name|uint
name|surrogateToUcs4
parameter_list|(
name|ushort
name|high
parameter_list|,
name|ushort
name|low
parameter_list|)
block|{
return|return
operator|(
name|uint
argument_list|(
name|high
argument_list|)
operator|<<
literal|10
operator|)
operator|+
name|low
operator|-
literal|0x35fdc00
return|;
block|}
specifier|static
specifier|inline
name|uint
name|surrogateToUcs4
parameter_list|(
name|QChar
name|high
parameter_list|,
name|QChar
name|low
parameter_list|)
block|{
return|return
name|surrogateToUcs4
argument_list|(
name|high
operator|.
name|unicode
argument_list|()
argument_list|,
name|low
operator|.
name|unicode
argument_list|()
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|ushort
name|highSurrogate
parameter_list|(
name|uint
name|ucs4
parameter_list|)
block|{
return|return
name|ushort
argument_list|(
operator|(
name|ucs4
operator|>>
literal|10
operator|)
operator|+
literal|0xd7c0
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|ushort
name|lowSurrogate
parameter_list|(
name|uint
name|ucs4
parameter_list|)
block|{
return|return
name|ushort
argument_list|(
name|ucs4
operator|%
literal|0x400
operator|+
literal|0xdc00
argument_list|)
return|;
block|}
specifier|static
name|Category
name|QT_FASTCALL
name|category
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|Direction
name|QT_FASTCALL
name|direction
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|JoiningType
name|QT_FASTCALL
name|joiningType
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|3
argument_list|)
name|QT_DEPRECATED
specifier|static
name|Joining
name|QT_FASTCALL
name|joining
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
endif|#
directive|endif
specifier|static
name|unsigned
name|char
name|QT_FASTCALL
name|combiningClass
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|uint
name|QT_FASTCALL
name|mirroredChar
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|bool
name|QT_FASTCALL
name|hasMirrored
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|QString
name|QT_FASTCALL
name|decomposition
parameter_list|(
name|uint
name|ucs4
parameter_list|)
function_decl|;
specifier|static
name|Decomposition
name|QT_FASTCALL
name|decompositionTag
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|int
name|QT_FASTCALL
name|digitValue
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|uint
name|QT_FASTCALL
name|toLower
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|uint
name|QT_FASTCALL
name|toUpper
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|uint
name|QT_FASTCALL
name|toTitleCase
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|uint
name|QT_FASTCALL
name|toCaseFolded
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|Script
name|QT_FASTCALL
name|script
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|UnicodeVersion
name|QT_FASTCALL
name|unicodeVersion
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|UnicodeVersion
name|QT_FASTCALL
name|currentUnicodeVersion
argument_list|()
name|Q_DECL_CONST_FUNCTION
expr_stmt|;
specifier|static
name|bool
name|QT_FASTCALL
name|isPrint
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isSpace
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|bool
name|QT_FASTCALL
name|isMark
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|bool
name|QT_FASTCALL
name|isPunct
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|bool
name|QT_FASTCALL
name|isSymbol
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isLetter
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isNumber
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isLetterOrNumber
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isDigit
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isLower
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isUpper
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isTitleCase
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
name|private
label|:
specifier|static
name|bool
name|QT_FASTCALL
name|isSpace_helper
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|bool
name|QT_FASTCALL
name|isLetter_helper
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|bool
name|QT_FASTCALL
name|isNumber_helper
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
specifier|static
name|bool
name|QT_FASTCALL
name|isLetterOrNumber_helper
argument_list|(
name|uint
name|ucs4
argument_list|)
name|Q_DECL_CONST_FUNCTION
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_NO_CAST_FROM_ASCII
name|QChar
argument_list|(
argument|char c
argument_list|)
empty_stmt|;
name|QChar
argument_list|(
argument|uchar c
argument_list|)
empty_stmt|;
endif|#
directive|endif
name|ushort
name|ucs
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QChar
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|char
name|QChar
operator|::
name|toLatin1
argument_list|()
specifier|const
block|{
return|return
name|ucs
operator|>
literal|0xff
operator|?
literal|'\0'
operator|:
name|char
argument_list|(
name|ucs
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QChar
name|QChar
operator|::
name|fromLatin1
argument_list|(
argument|char c
argument_list|)
block|{
return|return
name|QChar
argument_list|(
name|ushort
argument_list|(
name|uchar
argument_list|(
name|c
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|void
name|QChar
operator|::
name|setCell
argument_list|(
argument|uchar acell
argument_list|)
block|{
name|ucs
operator|=
name|ushort
argument_list|(
operator|(
name|ucs
operator|&
literal|0xff00
operator|)
operator|+
name|acell
argument_list|)
block|; }
specifier|inline
name|void
name|QChar
operator|::
name|setRow
argument_list|(
argument|uchar arow
argument_list|)
block|{
name|ucs
operator|=
name|ushort
argument_list|(
operator|(
name|ushort
argument_list|(
name|arow
argument_list|)
operator|<<
literal|8
operator|)
operator|+
operator|(
name|ucs
operator|&
literal|0xff
operator|)
argument_list|)
block|; }
specifier|inline
name|bool
name|QChar
operator|::
name|isSpace
argument_list|(
argument|uint ucs4
argument_list|)
block|{
comment|// note that [0x09..0x0d] + 0x85 are exceptional Cc-s and must be handled explicitly
return|return
name|ucs4
operator|==
literal|0x20
operator|||
operator|(
name|ucs4
operator|<=
literal|0x0d
operator|&&
name|ucs4
operator|>=
literal|0x09
operator|)
operator|||
operator|(
name|ucs4
operator|>
literal|127
operator|&&
operator|(
name|ucs4
operator|==
literal|0x85
operator|||
name|ucs4
operator|==
literal|0xa0
operator|||
name|QChar
operator|::
name|isSpace_helper
argument_list|(
name|ucs4
argument_list|)
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QChar
operator|::
name|isLetter
argument_list|(
argument|uint ucs4
argument_list|)
block|{
return|return
operator|(
name|ucs4
operator|>=
literal|'A'
operator|&&
name|ucs4
operator|<=
literal|'z'
operator|&&
operator|(
name|ucs4
operator|>=
literal|'a'
operator|||
name|ucs4
operator|<=
literal|'Z'
operator|)
operator|)
operator|||
operator|(
name|ucs4
operator|>
literal|127
operator|&&
name|QChar
operator|::
name|isLetter_helper
argument_list|(
name|ucs4
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QChar
operator|::
name|isNumber
argument_list|(
argument|uint ucs4
argument_list|)
block|{
return|return
operator|(
name|ucs4
operator|<=
literal|'9'
operator|&&
name|ucs4
operator|>=
literal|'0'
operator|)
operator|||
operator|(
name|ucs4
operator|>
literal|127
operator|&&
name|QChar
operator|::
name|isNumber_helper
argument_list|(
name|ucs4
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QChar
operator|::
name|isLetterOrNumber
argument_list|(
argument|uint ucs4
argument_list|)
block|{
return|return
operator|(
name|ucs4
operator|>=
literal|'A'
operator|&&
name|ucs4
operator|<=
literal|'z'
operator|&&
operator|(
name|ucs4
operator|>=
literal|'a'
operator|||
name|ucs4
operator|<=
literal|'Z'
operator|)
operator|)
operator|||
operator|(
name|ucs4
operator|>=
literal|'0'
operator|&&
name|ucs4
operator|<=
literal|'9'
operator|)
operator|||
operator|(
name|ucs4
operator|>
literal|127
operator|&&
name|QChar
operator|::
name|isLetterOrNumber_helper
argument_list|(
name|ucs4
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QChar
operator|::
name|isDigit
argument_list|(
argument|uint ucs4
argument_list|)
block|{
return|return
operator|(
name|ucs4
operator|<=
literal|'9'
operator|&&
name|ucs4
operator|>=
literal|'0'
operator|)
operator|||
operator|(
name|ucs4
operator|>
literal|127
operator|&&
name|QChar
operator|::
name|category
argument_list|(
name|ucs4
argument_list|)
operator|==
name|Number_DecimalDigit
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QChar
operator|::
name|isLower
argument_list|(
argument|uint ucs4
argument_list|)
block|{
return|return
operator|(
name|ucs4
operator|<=
literal|'z'
operator|&&
name|ucs4
operator|>=
literal|'a'
operator|)
operator|||
operator|(
name|ucs4
operator|>
literal|127
operator|&&
name|QChar
operator|::
name|category
argument_list|(
name|ucs4
argument_list|)
operator|==
name|Letter_Lowercase
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QChar
operator|::
name|isUpper
argument_list|(
argument|uint ucs4
argument_list|)
block|{
return|return
operator|(
name|ucs4
operator|<=
literal|'Z'
operator|&&
name|ucs4
operator|>=
literal|'A'
operator|)
operator|||
operator|(
name|ucs4
operator|>
literal|127
operator|&&
name|QChar
operator|::
name|category
argument_list|(
name|ucs4
argument_list|)
operator|==
name|Letter_Uppercase
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|QChar
operator|::
name|isTitleCase
argument_list|(
argument|uint ucs4
argument_list|)
block|{
return|return
name|ucs4
operator|>
literal|127
operator|&&
name|QChar
operator|::
name|category
argument_list|(
name|ucs4
argument_list|)
operator|==
name|Letter_Titlecase
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|QChar
name|c1
operator|,
name|QChar
name|c2
operator|)
block|{
return|return
name|c1
operator|.
name|unicode
argument_list|()
operator|==
name|c2
operator|.
name|unicode
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|QChar
name|c1
operator|,
name|QChar
name|c2
operator|)
block|{
return|return
name|c1
operator|.
name|unicode
argument_list|()
operator|!=
name|c2
operator|.
name|unicode
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
name|QChar
name|c1
operator|,
name|QChar
name|c2
operator|)
block|{
return|return
name|c1
operator|.
name|unicode
argument_list|()
operator|<=
name|c2
operator|.
name|unicode
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
name|QChar
name|c1
operator|,
name|QChar
name|c2
operator|)
block|{
return|return
name|c1
operator|.
name|unicode
argument_list|()
operator|>=
name|c2
operator|.
name|unicode
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<
operator|(
name|QChar
name|c1
operator|,
name|QChar
name|c2
operator|)
block|{
return|return
name|c1
operator|.
name|unicode
argument_list|()
operator|<
name|c2
operator|.
name|unicode
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
name|QChar
name|c1
operator|,
name|QChar
name|c2
operator|)
block|{
return|return
name|c1
operator|.
name|unicode
argument_list|()
operator|>
name|c2
operator|.
name|unicode
argument_list|()
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
name|QChar
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QChar
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCHAR_H
end_comment
end_unit
