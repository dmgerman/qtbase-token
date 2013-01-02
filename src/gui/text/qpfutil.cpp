begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
