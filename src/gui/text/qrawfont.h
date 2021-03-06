begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRAWFONT_H
end_ifndef
begin_define
DECL|macro|QRAWFONT_H
define|#
directive|define
name|QRAWFONT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qfontdatabase.h>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRawFontPrivate
name|class
name|QRawFontPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRawFont
block|{
name|public
label|:
enum|enum
name|AntialiasingType
block|{
name|PixelAntialiasing
block|,
name|SubPixelAntialiasing
block|}
enum|;
enum|enum
name|LayoutFlag
block|{
name|SeparateAdvances
init|=
literal|0
block|,
name|KernedAdvances
init|=
literal|1
block|,
name|UseDesignMetrics
init|=
literal|2
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|LayoutFlags
argument_list|,
argument|LayoutFlag
argument_list|)
name|QRawFont
argument_list|()
expr_stmt|;
name|QRawFont
argument_list|(
argument|const QString&fileName
argument_list|,
argument|qreal pixelSize
argument_list|,
argument|QFont::HintingPreference hintingPreference = QFont::PreferDefaultHinting
argument_list|)
empty_stmt|;
name|QRawFont
argument_list|(
argument|const QByteArray&fontData
argument_list|,
argument|qreal pixelSize
argument_list|,
argument|QFont::HintingPreference hintingPreference = QFont::PreferDefaultHinting
argument_list|)
empty_stmt|;
name|QRawFont
argument_list|(
specifier|const
name|QRawFont
operator|&
name|other
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QRawFont
modifier|&
name|operator
init|=
operator|(
name|QRawFont
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QRawFont
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QRawFont
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QRawFont
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QRawFont
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
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
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QRawFont
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QRawFont
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|QString
name|familyName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|styleName
argument_list|()
specifier|const
expr_stmt|;
name|QFont
operator|::
name|Style
name|style
argument_list|()
specifier|const
expr_stmt|;
name|int
name|weight
argument_list|()
specifier|const
expr_stmt|;
name|QVector
operator|<
name|quint32
operator|>
name|glyphIndexesForString
argument_list|(
argument|const QString&text
argument_list|)
specifier|const
expr_stmt|;
specifier|inline
name|QVector
operator|<
name|QPointF
operator|>
name|advancesForGlyphIndexes
argument_list|(
argument|const QVector<quint32>&glyphIndexes
argument_list|)
specifier|const
expr_stmt|;
specifier|inline
name|QVector
operator|<
name|QPointF
operator|>
name|advancesForGlyphIndexes
argument_list|(
argument|const QVector<quint32>&glyphIndexes
argument_list|,
argument|LayoutFlags layoutFlags
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|glyphIndexesForChars
argument_list|(
specifier|const
name|QChar
operator|*
name|chars
argument_list|,
name|int
name|numChars
argument_list|,
name|quint32
operator|*
name|glyphIndexes
argument_list|,
name|int
operator|*
name|numGlyphs
argument_list|)
decl|const
decl_stmt|;
name|bool
name|advancesForGlyphIndexes
argument_list|(
specifier|const
name|quint32
operator|*
name|glyphIndexes
argument_list|,
name|QPointF
operator|*
name|advances
argument_list|,
name|int
name|numGlyphs
argument_list|)
decl|const
decl_stmt|;
name|bool
name|advancesForGlyphIndexes
argument_list|(
specifier|const
name|quint32
operator|*
name|glyphIndexes
argument_list|,
name|QPointF
operator|*
name|advances
argument_list|,
name|int
name|numGlyphs
argument_list|,
name|LayoutFlags
name|layoutFlags
argument_list|)
decl|const
decl_stmt|;
name|QImage
name|alphaMapForGlyph
argument_list|(
name|quint32
name|glyphIndex
argument_list|,
name|AntialiasingType
name|antialiasingType
operator|=
name|SubPixelAntialiasing
argument_list|,
specifier|const
name|QTransform
operator|&
name|transform
operator|=
name|QTransform
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QPainterPath
name|pathForGlyph
argument_list|(
name|quint32
name|glyphIndex
argument_list|)
decl|const
decl_stmt|;
name|QRectF
name|boundingRect
argument_list|(
name|quint32
name|glyphIndex
argument_list|)
decl|const
decl_stmt|;
name|void
name|setPixelSize
parameter_list|(
name|qreal
name|pixelSize
parameter_list|)
function_decl|;
name|qreal
name|pixelSize
argument_list|()
specifier|const
expr_stmt|;
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|ascent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|descent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|leading
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|xHeight
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|averageCharWidth
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|maxCharWidth
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|lineThickness
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|underlinePosition
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|unitsPerEm
argument_list|()
specifier|const
expr_stmt|;
name|void
name|loadFromFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|qreal
name|pixelSize
argument_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
argument_list|)
decl_stmt|;
name|void
name|loadFromData
argument_list|(
specifier|const
name|QByteArray
operator|&
name|fontData
argument_list|,
name|qreal
name|pixelSize
argument_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
argument_list|)
decl_stmt|;
name|bool
name|supportsCharacter
argument_list|(
name|uint
name|ucs4
argument_list|)
decl|const
decl_stmt|;
name|bool
name|supportsCharacter
argument_list|(
name|QChar
name|character
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QFontDatabase
operator|::
name|WritingSystem
operator|>
name|supportedWritingSystems
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|fontTable
argument_list|(
specifier|const
name|char
operator|*
name|tagName
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QRawFont
name|fromFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|,
name|QFontDatabase
operator|::
name|WritingSystem
name|writingSystem
operator|=
name|QFontDatabase
operator|::
name|Any
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|class
name|QRawFontPrivate
decl_stmt|;
name|friend
name|class
name|QTextLayout
decl_stmt|;
name|friend
name|class
name|QTextEngine
decl_stmt|;
name|QExplicitlySharedDataPointer
operator|<
name|QRawFontPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QRawFont
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QRawFont::LayoutFlags
argument_list|)
end_macro
begin_expr_stmt
specifier|inline
name|QVector
operator|<
name|QPointF
operator|>
name|QRawFont
operator|::
name|advancesForGlyphIndexes
argument_list|(
argument|const QVector<quint32>&glyphIndexes
argument_list|,
argument|QRawFont::LayoutFlags layoutFlags
argument_list|)
specifier|const
block|{
name|QVector
operator|<
name|QPointF
operator|>
name|advances
argument_list|(
name|glyphIndexes
operator|.
name|size
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|advancesForGlyphIndexes
argument_list|(
name|glyphIndexes
operator|.
name|constData
argument_list|()
argument_list|,
name|advances
operator|.
name|data
argument_list|()
argument_list|,
name|glyphIndexes
operator|.
name|size
argument_list|()
argument_list|,
name|layoutFlags
argument_list|)
condition|)
return|return
name|advances
return|;
end_expr_stmt
begin_return
return|return
name|QVector
operator|<
name|QPointF
operator|>
operator|(
operator|)
return|;
end_return
begin_expr_stmt
unit|}  inline
name|QVector
operator|<
name|QPointF
operator|>
name|QRawFont
operator|::
name|advancesForGlyphIndexes
argument_list|(
argument|const QVector<quint32>&glyphIndexes
argument_list|)
specifier|const
block|{
return|return
name|advancesForGlyphIndexes
argument_list|(
name|glyphIndexes
argument_list|,
name|QRawFont
operator|::
name|SeparateAdvances
argument_list|)
return|;
block|}
end_expr_stmt
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QRAWFONT_H
end_comment
end_unit
