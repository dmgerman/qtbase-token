begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_decl_stmt
DECL|variable|tagTypes
specifier|static
specifier|const
name|QFontEngineQPF
operator|::
name|TagType
name|tagTypes
index|[
name|QFontEngineQPF
operator|::
name|NumTags
index|]
init|=
block|{
name|QFontEngineQPF
operator|::
name|StringType
block|,
comment|// FontName
name|QFontEngineQPF
operator|::
name|StringType
block|,
comment|// FileName
name|QFontEngineQPF
operator|::
name|UInt32Type
block|,
comment|// FileIndex
name|QFontEngineQPF
operator|::
name|UInt32Type
block|,
comment|// FontRevision
name|QFontEngineQPF
operator|::
name|StringType
block|,
comment|// FreeText
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// Ascent
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// Descent
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// Leading
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// XHeight
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// AverageCharWidth
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// MaxCharWidth
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// LineThickness
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// MinLeftBearing
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// MinRightBearing
name|QFontEngineQPF
operator|::
name|FixedType
block|,
comment|// UnderlinePosition
name|QFontEngineQPF
operator|::
name|UInt8Type
block|,
comment|// GlyphFormat
name|QFontEngineQPF
operator|::
name|UInt8Type
block|,
comment|// PixelSize
name|QFontEngineQPF
operator|::
name|UInt8Type
block|,
comment|// Weight
name|QFontEngineQPF
operator|::
name|UInt8Type
block|,
comment|// Style
name|QFontEngineQPF
operator|::
name|StringType
block|,
comment|// EndOfHeader
name|QFontEngineQPF
operator|::
name|BitFieldType
comment|// WritingSystems
block|}
decl_stmt|;
end_decl_stmt
end_unit
