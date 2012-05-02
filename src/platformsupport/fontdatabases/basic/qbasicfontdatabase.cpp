begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbasicfontdatabase_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformScreen>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLibraryInfo>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUuid>
end_include
begin_undef
DECL|macro|QT_NO_FREETYPE
undef|#
directive|undef
name|QT_NO_FREETYPE
end_undef
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_ft_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_p.h>
end_include
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TABLES_H
end_include
begin_include
include|#
directive|include
include|FT_ERRORS_H
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|SimplifiedChineseCsbBit
define|#
directive|define
name|SimplifiedChineseCsbBit
value|18
DECL|macro|TraditionalChineseCsbBit
define|#
directive|define
name|TraditionalChineseCsbBit
value|20
DECL|macro|JapaneseCsbBit
define|#
directive|define
name|JapaneseCsbBit
value|17
DECL|macro|KoreanCsbBit
define|#
directive|define
name|KoreanCsbBit
value|21
DECL|variable|requiredUnicodeBits
specifier|static
name|int
name|requiredUnicodeBits
index|[
name|QFontDatabase
operator|::
name|WritingSystemsCount
index|]
index|[
literal|2
index|]
init|=
block|{
comment|// Any,
block|{
literal|127
block|,
literal|127
block|}
block|,
comment|// Latin,
block|{
literal|0
block|,
literal|127
block|}
block|,
comment|// Greek,
block|{
literal|7
block|,
literal|127
block|}
block|,
comment|// Cyrillic,
block|{
literal|9
block|,
literal|127
block|}
block|,
comment|// Armenian,
block|{
literal|10
block|,
literal|127
block|}
block|,
comment|// Hebrew,
block|{
literal|11
block|,
literal|127
block|}
block|,
comment|// Arabic,
block|{
literal|13
block|,
literal|127
block|}
block|,
comment|// Syriac,
block|{
literal|71
block|,
literal|127
block|}
block|,
comment|//Thaana,
block|{
literal|72
block|,
literal|127
block|}
block|,
comment|//Devanagari,
block|{
literal|15
block|,
literal|127
block|}
block|,
comment|//Bengali,
block|{
literal|16
block|,
literal|127
block|}
block|,
comment|//Gurmukhi,
block|{
literal|17
block|,
literal|127
block|}
block|,
comment|//Gujarati,
block|{
literal|18
block|,
literal|127
block|}
block|,
comment|//Oriya,
block|{
literal|19
block|,
literal|127
block|}
block|,
comment|//Tamil,
block|{
literal|20
block|,
literal|127
block|}
block|,
comment|//Telugu,
block|{
literal|21
block|,
literal|127
block|}
block|,
comment|//Kannada,
block|{
literal|22
block|,
literal|127
block|}
block|,
comment|//Malayalam,
block|{
literal|23
block|,
literal|127
block|}
block|,
comment|//Sinhala,
block|{
literal|73
block|,
literal|127
block|}
block|,
comment|//Thai,
block|{
literal|24
block|,
literal|127
block|}
block|,
comment|//Lao,
block|{
literal|25
block|,
literal|127
block|}
block|,
comment|//Tibetan,
block|{
literal|70
block|,
literal|127
block|}
block|,
comment|//Myanmar,
block|{
literal|74
block|,
literal|127
block|}
block|,
comment|// Georgian,
block|{
literal|26
block|,
literal|127
block|}
block|,
comment|// Khmer,
block|{
literal|80
block|,
literal|127
block|}
block|,
comment|// SimplifiedChinese,
block|{
literal|126
block|,
literal|127
block|}
block|,
comment|// TraditionalChinese,
block|{
literal|126
block|,
literal|127
block|}
block|,
comment|// Japanese,
block|{
literal|126
block|,
literal|127
block|}
block|,
comment|// Korean,
block|{
literal|56
block|,
literal|127
block|}
block|,
comment|// Vietnamese,
block|{
literal|0
block|,
literal|127
block|}
block|,
comment|// same as latin1
comment|// Other,
block|{
literal|126
block|,
literal|127
block|}
block|,
comment|// Ogham,
block|{
literal|78
block|,
literal|127
block|}
block|,
comment|// Runic,
block|{
literal|79
block|,
literal|127
block|}
block|,
comment|// Nko,
block|{
literal|14
block|,
literal|127
block|}
block|, }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|determineWritingSystemsFromTrueTypeBits
name|QSupportedWritingSystems
name|QBasicFontDatabase
operator|::
name|determineWritingSystemsFromTrueTypeBits
parameter_list|(
name|quint32
name|unicodeRange
index|[
literal|4
index|]
parameter_list|,
name|quint32
name|codePageRange
index|[
literal|2
index|]
parameter_list|)
block|{
name|QSupportedWritingSystems
name|writingSystems
decl_stmt|;
name|bool
name|hasScript
init|=
literal|false
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|QFontDatabase
operator|::
name|WritingSystemsCount
condition|;
name|i
operator|++
control|)
block|{
name|int
name|bit
init|=
name|requiredUnicodeBits
index|[
name|i
index|]
index|[
literal|0
index|]
decl_stmt|;
name|int
name|index
init|=
name|bit
operator|/
literal|32
decl_stmt|;
name|int
name|flag
init|=
literal|1
operator|<<
operator|(
name|bit
operator|&
literal|31
operator|)
decl_stmt|;
if|if
condition|(
name|bit
operator|!=
literal|126
operator|&&
name|unicodeRange
index|[
name|index
index|]
operator|&
name|flag
condition|)
block|{
name|bit
operator|=
name|requiredUnicodeBits
index|[
name|i
index|]
index|[
literal|1
index|]
expr_stmt|;
name|index
operator|=
name|bit
operator|/
literal|32
expr_stmt|;
name|flag
operator|=
literal|1
operator|<<
operator|(
name|bit
operator|&
literal|31
operator|)
expr_stmt|;
if|if
condition|(
name|bit
operator|==
literal|127
operator|||
name|unicodeRange
index|[
name|index
index|]
operator|&
name|flag
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|WritingSystem
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|// qDebug("font %s: index=%d, flag=%8x supports script %d", familyName.latin1(), index, flag, i);
block|}
block|}
block|}
if|if
condition|(
name|codePageRange
index|[
literal|0
index|]
operator|&
operator|(
literal|1
operator|<<
name|SimplifiedChineseCsbBit
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|SimplifiedChinese
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|//qDebug("font %s supports Simplified Chinese", familyName.latin1());
block|}
if|if
condition|(
name|codePageRange
index|[
literal|0
index|]
operator|&
operator|(
literal|1
operator|<<
name|TraditionalChineseCsbBit
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|TraditionalChinese
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|//qDebug("font %s supports Traditional Chinese", familyName.latin1());
block|}
if|if
condition|(
name|codePageRange
index|[
literal|0
index|]
operator|&
operator|(
literal|1
operator|<<
name|JapaneseCsbBit
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Japanese
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|//qDebug("font %s supports Japanese", familyName.latin1());
block|}
if|if
condition|(
name|codePageRange
index|[
literal|0
index|]
operator|&
operator|(
literal|1
operator|<<
name|KoreanCsbBit
operator|)
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Korean
argument_list|)
expr_stmt|;
name|hasScript
operator|=
literal|true
expr_stmt|;
comment|//qDebug("font %s supports Korean", familyName.latin1());
block|}
if|if
condition|(
operator|!
name|hasScript
condition|)
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Symbol
argument_list|)
expr_stmt|;
return|return
name|writingSystems
return|;
block|}
end_function
begin_function
DECL|function|scriptRequiresOpenType
specifier|static
specifier|inline
name|bool
name|scriptRequiresOpenType
parameter_list|(
name|int
name|script
parameter_list|)
block|{
return|return
operator|(
operator|(
name|script
operator|>=
name|QUnicodeTables
operator|::
name|Syriac
operator|&&
name|script
operator|<=
name|QUnicodeTables
operator|::
name|Sinhala
operator|)
operator|||
name|script
operator|==
name|QUnicodeTables
operator|::
name|Khmer
operator|||
name|script
operator|==
name|QUnicodeTables
operator|::
name|Nko
operator|)
return|;
block|}
end_function
begin_function
DECL|function|populateFontDatabase
name|void
name|QBasicFontDatabase
operator|::
name|populateFontDatabase
parameter_list|()
block|{
name|QString
name|fontpath
init|=
name|fontDir
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|fontpath
argument_list|)
condition|)
block|{
name|qFatal
argument_list|(
literal|"QFontDatabase: Cannot find font directory %s - is Qt installed correctly?"
argument_list|,
name|qPrintable
argument_list|(
name|fontpath
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QDir
name|dir
argument_list|(
name|fontpath
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setNameFilters
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"*.ttf"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"*.ttc"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"*.pfa"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"*.pfb"
argument_list|)
argument_list|)
expr_stmt|;
name|dir
operator|.
name|refresh
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|int
argument_list|(
name|dir
operator|.
name|count
argument_list|()
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QByteArray
name|file
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|dir
operator|.
name|absoluteFilePath
argument_list|(
name|dir
index|[
name|i
index|]
argument_list|)
argument_list|)
decl_stmt|;
comment|//        qDebug()<< "looking at"<< file;
name|addTTFile
argument_list|(
name|QByteArray
argument_list|()
argument_list|,
name|file
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QBasicFontDatabase
operator|::
name|fontEngine
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|,
name|QUnicodeTables
operator|::
name|Script
name|script
parameter_list|,
name|void
modifier|*
name|usrPtr
parameter_list|)
block|{
name|QFontEngineFT
modifier|*
name|engine
decl_stmt|;
name|FontFile
modifier|*
name|fontfile
init|=
cast|static_cast
argument_list|<
name|FontFile
operator|*
argument_list|>
argument_list|(
name|usrPtr
argument_list|)
decl_stmt|;
name|QFontEngine
operator|::
name|FaceId
name|fid
decl_stmt|;
name|fid
operator|.
name|filename
operator|=
name|fontfile
operator|->
name|fileName
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
name|fid
operator|.
name|index
operator|=
name|fontfile
operator|->
name|indexValue
expr_stmt|;
name|engine
operator|=
operator|new
name|QFontEngineFT
argument_list|(
name|fontDef
argument_list|)
expr_stmt|;
name|bool
name|antialias
init|=
operator|!
operator|(
name|fontDef
operator|.
name|styleStrategy
operator|&
name|QFont
operator|::
name|NoAntialias
operator|)
decl_stmt|;
name|QFontEngineFT
operator|::
name|GlyphFormat
name|format
init|=
name|antialias
condition|?
name|QFontEngineFT
operator|::
name|Format_A8
else|:
name|QFontEngineFT
operator|::
name|Format_Mono
decl_stmt|;
if|if
condition|(
operator|!
name|engine
operator|->
name|init
argument_list|(
name|fid
argument_list|,
name|antialias
argument_list|,
name|format
argument_list|)
condition|)
block|{
operator|delete
name|engine
expr_stmt|;
name|engine
operator|=
literal|0
expr_stmt|;
return|return
name|engine
return|;
block|}
if|if
condition|(
name|engine
operator|->
name|invalid
argument_list|()
condition|)
block|{
operator|delete
name|engine
expr_stmt|;
name|engine
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|scriptRequiresOpenType
argument_list|(
name|script
argument_list|)
condition|)
block|{
name|HB_Face
name|hbFace
init|=
name|engine
operator|->
name|initializedHarfbuzzFace
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|hbFace
operator|||
operator|!
name|hbFace
operator|->
name|supported_scripts
index|[
name|script
index|]
condition|)
block|{
operator|delete
name|engine
expr_stmt|;
name|engine
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
name|engine
return|;
block|}
end_function
begin_namespace
namespace|namespace
block|{
DECL|class|QFontEngineFTRawData
class|class
name|QFontEngineFTRawData
super|:
specifier|public
name|QFontEngineFT
block|{
public|public:
DECL|function|QFontEngineFTRawData
name|QFontEngineFTRawData
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|fontDef
parameter_list|)
member_init_list|:
name|QFontEngineFT
argument_list|(
name|fontDef
argument_list|)
block|{         }
DECL|function|updateFamilyNameAndStyle
name|void
name|updateFamilyNameAndStyle
parameter_list|()
block|{
name|fontDef
operator|.
name|family
operator|=
name|QString
operator|::
name|fromAscii
argument_list|(
name|freetype
operator|->
name|face
operator|->
name|family_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|freetype
operator|->
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_ITALIC
condition|)
name|fontDef
operator|.
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
if|if
condition|(
name|freetype
operator|->
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_BOLD
condition|)
name|fontDef
operator|.
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
block|}
DECL|function|initFromData
name|bool
name|initFromData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|)
block|{
name|FaceId
name|faceId
decl_stmt|;
name|faceId
operator|.
name|filename
operator|=
literal|""
expr_stmt|;
name|faceId
operator|.
name|index
operator|=
literal|0
expr_stmt|;
name|faceId
operator|.
name|uuid
operator|=
name|QUuid
operator|::
name|createUuid
argument_list|()
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
return|return
name|init
argument_list|(
name|faceId
argument_list|,
literal|true
argument_list|,
name|Format_None
argument_list|,
name|fontData
argument_list|)
return|;
block|}
block|}
class|;
block|}
end_namespace
begin_function
DECL|function|fontEngine
name|QFontEngine
modifier|*
name|QBasicFontDatabase
operator|::
name|fontEngine
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
name|qreal
name|pixelSize
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
block|{
name|QFontDef
name|fontDef
decl_stmt|;
name|fontDef
operator|.
name|pixelSize
operator|=
name|pixelSize
expr_stmt|;
name|QFontEngineFTRawData
modifier|*
name|fe
init|=
operator|new
name|QFontEngineFTRawData
argument_list|(
name|fontDef
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fe
operator|->
name|initFromData
argument_list|(
name|fontData
argument_list|)
condition|)
block|{
operator|delete
name|fe
expr_stmt|;
return|return
literal|0
return|;
block|}
name|fe
operator|->
name|updateFamilyNameAndStyle
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|hintingPreference
condition|)
block|{
case|case
name|QFont
operator|::
name|PreferNoHinting
case|:
name|fe
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintNone
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|PreferFullHinting
case|:
name|fe
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintFull
argument_list|)
expr_stmt|;
break|break;
case|case
name|QFont
operator|::
name|PreferVerticalHinting
case|:
name|fe
operator|->
name|setDefaultHintStyle
argument_list|(
name|QFontEngineFT
operator|::
name|HintLight
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|// Leave it as it is
break|break;
block|}
return|return
name|fe
return|;
block|}
end_function
begin_function
DECL|function|fallbacksForFamily
name|QStringList
name|QBasicFontDatabase
operator|::
name|fallbacksForFamily
parameter_list|(
specifier|const
name|QString
name|family
parameter_list|,
specifier|const
name|QFont
operator|::
name|Style
modifier|&
name|style
parameter_list|,
specifier|const
name|QFont
operator|::
name|StyleHint
modifier|&
name|styleHint
parameter_list|,
specifier|const
name|QUnicodeTables
operator|::
name|Script
modifier|&
name|script
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|family
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|style
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|script
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|styleHint
argument_list|)
expr_stmt|;
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|addApplicationFont
name|QStringList
name|QBasicFontDatabase
operator|::
name|addApplicationFont
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
return|return
name|addTTFile
argument_list|(
name|fontData
argument_list|,
name|fileName
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|releaseHandle
name|void
name|QBasicFontDatabase
operator|::
name|releaseHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|FontFile
modifier|*
name|file
init|=
cast|static_cast
argument_list|<
name|FontFile
operator|*
argument_list|>
argument_list|(
name|handle
argument_list|)
decl_stmt|;
operator|delete
name|file
expr_stmt|;
block|}
end_function
begin_function_decl
specifier|extern
name|FT_Library
name|qt_getFreetype
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|addTTFile
name|QStringList
name|QBasicFontDatabase
operator|::
name|addTTFile
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|file
parameter_list|)
block|{
name|FT_Library
name|library
init|=
name|qt_getFreetype
argument_list|()
decl_stmt|;
name|int
name|index
init|=
literal|0
decl_stmt|;
name|int
name|numFaces
init|=
literal|0
decl_stmt|;
name|QStringList
name|families
decl_stmt|;
do|do
block|{
name|FT_Face
name|face
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
if|if
condition|(
operator|!
name|fontData
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|error
operator|=
name|FT_New_Memory_Face
argument_list|(
name|library
argument_list|,
operator|(
specifier|const
name|FT_Byte
operator|*
operator|)
name|fontData
operator|.
name|constData
argument_list|()
argument_list|,
name|fontData
operator|.
name|size
argument_list|()
argument_list|,
name|index
argument_list|,
operator|&
name|face
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|error
operator|=
name|FT_New_Face
argument_list|(
name|library
argument_list|,
name|file
operator|.
name|constData
argument_list|()
argument_list|,
name|index
argument_list|,
operator|&
name|face
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|error
operator|!=
name|FT_Err_Ok
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"FT_New_Face failed with index"
operator|<<
name|index
operator|<<
literal|":"
operator|<<
name|hex
operator|<<
name|error
expr_stmt|;
break|break;
block|}
name|numFaces
operator|=
name|face
operator|->
name|num_faces
expr_stmt|;
name|QFont
operator|::
name|Weight
name|weight
init|=
name|QFont
operator|::
name|Normal
decl_stmt|;
name|QFont
operator|::
name|Style
name|style
init|=
name|QFont
operator|::
name|StyleNormal
decl_stmt|;
if|if
condition|(
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_ITALIC
condition|)
name|style
operator|=
name|QFont
operator|::
name|StyleItalic
expr_stmt|;
if|if
condition|(
name|face
operator|->
name|style_flags
operator|&
name|FT_STYLE_FLAG_BOLD
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
name|bool
name|fixedPitch
init|=
operator|(
name|face
operator|->
name|face_flags
operator|&
name|FT_FACE_FLAG_FIXED_WIDTH
operator|)
decl_stmt|;
name|QSupportedWritingSystems
name|writingSystems
decl_stmt|;
comment|// detect symbol fonts
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|face
operator|->
name|num_charmaps
condition|;
operator|++
name|i
control|)
block|{
name|FT_CharMap
name|cm
init|=
name|face
operator|->
name|charmaps
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|cm
operator|->
name|encoding
operator|==
name|FT_ENCODING_ADOBE_CUSTOM
operator|||
name|cm
operator|->
name|encoding
operator|==
name|FT_ENCODING_MS_SYMBOL
condition|)
block|{
name|writingSystems
operator|.
name|setSupported
argument_list|(
name|QFontDatabase
operator|::
name|Symbol
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|TT_OS2
modifier|*
name|os2
init|=
operator|(
name|TT_OS2
operator|*
operator|)
name|FT_Get_Sfnt_Table
argument_list|(
name|face
argument_list|,
name|ft_sfnt_os2
argument_list|)
decl_stmt|;
if|if
condition|(
name|os2
condition|)
block|{
name|quint32
name|unicodeRange
index|[
literal|4
index|]
init|=
block|{
name|quint32
argument_list|(
name|os2
operator|->
name|ulUnicodeRange1
argument_list|)
block|,
name|quint32
argument_list|(
name|os2
operator|->
name|ulUnicodeRange2
argument_list|)
block|,
name|quint32
argument_list|(
name|os2
operator|->
name|ulUnicodeRange3
argument_list|)
block|,
name|quint32
argument_list|(
argument|os2->ulUnicodeRange4
argument_list|)
block|}
decl_stmt|;
name|quint32
name|codePageRange
index|[
literal|2
index|]
init|=
block|{
name|quint32
argument_list|(
name|os2
operator|->
name|ulCodePageRange1
argument_list|)
block|,
name|quint32
argument_list|(
argument|os2->ulCodePageRange2
argument_list|)
block|}
decl_stmt|;
name|writingSystems
operator|=
name|determineWritingSystemsFromTrueTypeBits
argument_list|(
name|unicodeRange
argument_list|,
name|codePageRange
argument_list|)
expr_stmt|;
if|if
condition|(
name|os2
operator|->
name|usWeightClass
operator|==
literal|0
condition|)
empty_stmt|;
elseif|else
if|if
condition|(
name|os2
operator|->
name|usWeightClass
operator|<
literal|350
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Light
expr_stmt|;
elseif|else
if|if
condition|(
name|os2
operator|->
name|usWeightClass
operator|<
literal|450
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Normal
expr_stmt|;
elseif|else
if|if
condition|(
name|os2
operator|->
name|usWeightClass
operator|<
literal|650
condition|)
name|weight
operator|=
name|QFont
operator|::
name|DemiBold
expr_stmt|;
elseif|else
if|if
condition|(
name|os2
operator|->
name|usWeightClass
operator|<
literal|750
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
elseif|else
if|if
condition|(
name|os2
operator|->
name|usWeightClass
operator|<
literal|1000
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Black
expr_stmt|;
if|if
condition|(
name|os2
operator|->
name|panose
index|[
literal|2
index|]
operator|>=
literal|2
condition|)
block|{
name|int
name|w
init|=
name|os2
operator|->
name|panose
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|w
operator|<=
literal|3
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Light
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|5
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Normal
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|7
condition|)
name|weight
operator|=
name|QFont
operator|::
name|DemiBold
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|8
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Bold
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|<=
literal|10
condition|)
name|weight
operator|=
name|QFont
operator|::
name|Black
expr_stmt|;
block|}
block|}
name|QString
name|family
init|=
name|QString
operator|::
name|fromAscii
argument_list|(
name|face
operator|->
name|family_name
argument_list|)
decl_stmt|;
name|FontFile
modifier|*
name|fontFile
init|=
operator|new
name|FontFile
decl_stmt|;
name|fontFile
operator|->
name|fileName
operator|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|fontFile
operator|->
name|indexValue
operator|=
name|index
expr_stmt|;
name|QFont
operator|::
name|Stretch
name|stretch
init|=
name|QFont
operator|::
name|Unstretched
decl_stmt|;
name|registerFont
argument_list|(
name|family
argument_list|,
name|QString
argument_list|()
argument_list|,
name|weight
argument_list|,
name|style
argument_list|,
name|stretch
argument_list|,
literal|true
argument_list|,
literal|true
argument_list|,
literal|0
argument_list|,
name|fixedPitch
argument_list|,
name|writingSystems
argument_list|,
name|fontFile
argument_list|)
expr_stmt|;
name|families
operator|.
name|append
argument_list|(
name|family
argument_list|)
expr_stmt|;
name|FT_Done_Face
argument_list|(
name|face
argument_list|)
expr_stmt|;
operator|++
name|index
expr_stmt|;
block|}
do|while
condition|(
name|index
operator|<
name|numFaces
condition|)
do|;
return|return
name|families
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
