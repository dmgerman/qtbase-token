begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSFONTDATABASE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSFONTDATABASE_H
define|#
directive|define
name|QWINDOWSFONTDATABASE_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformfontdatabase.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DIRECTWRITE
argument_list|)
end_if
begin_struct_decl
struct_decl|struct
name|IDWriteFactory
struct_decl|;
end_struct_decl
begin_struct_decl
struct_decl|struct
name|IDWriteGdiInterop
struct_decl|;
end_struct_decl
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QWindowsFontEngineData
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsFontEngineData
argument_list|)
name|public
label|:
name|QWindowsFontEngineData
argument_list|()
expr_stmt|;
operator|~
name|QWindowsFontEngineData
argument_list|()
expr_stmt|;
name|uint
name|pow_gamma
index|[
literal|256
index|]
decl_stmt|;
name|bool
name|clearTypeEnabled
decl_stmt|;
name|qreal
name|fontSmoothingGamma
decl_stmt|;
name|HDC
name|hdc
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DIRECTWRITE
argument_list|)
name|IDWriteFactory
modifier|*
name|directWriteFactory
decl_stmt|;
name|IDWriteGdiInterop
modifier|*
name|directWriteGdiInterop
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QWindowsFontDatabase
range|:
name|public
name|QPlatformFontDatabase
block|{
name|public
operator|:
name|QWindowsFontDatabase
argument_list|()
block|;
operator|~
name|QWindowsFontDatabase
argument_list|()
block|;
name|void
name|populateFontDatabase
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QFontEngineMulti
operator|*
name|fontEngineMulti
argument_list|(
argument|QFontEngine *fontEngine
argument_list|,
argument|QChar::Script script
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFontEngine
operator|*
name|fontEngine
argument_list|(
argument|const QFontDef&fontDef
argument_list|,
argument|void *handle
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFontEngine
operator|*
name|fontEngine
argument_list|(
argument|const QByteArray&fontData
argument_list|,
argument|qreal pixelSize
argument_list|,
argument|QFont::HintingPreference hintingPreference
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|fallbacksForFamily
argument_list|(
argument|const QString&family
argument_list|,
argument|QFont::Style style
argument_list|,
argument|QFont::StyleHint styleHint
argument_list|,
argument|QChar::Script script
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|addApplicationFont
argument_list|(
argument|const QByteArray&fontData
argument_list|,
argument|const QString&fileName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|releaseHandle
argument_list|(
argument|void *handle
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QString
name|fontDir
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFont
name|defaultFont
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|systemDefaultFont
argument_list|()
return|;
block|}
name|bool
name|fontsAlwaysScalable
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|derefUniqueFont
argument_list|(
specifier|const
name|QString
operator|&
name|uniqueFont
argument_list|)
block|;
name|void
name|refUniqueFont
argument_list|(
specifier|const
name|QString
operator|&
name|uniqueFont
argument_list|)
block|;
specifier|static
name|QFont
name|systemDefaultFont
argument_list|()
block|;
specifier|static
name|QFontEngine
operator|*
name|createEngine
argument_list|(
argument|const QFontDef&request
argument_list|,
argument|HDC fontHdc
argument_list|,
argument|int dpi
argument_list|,
argument|bool rawMode
argument_list|,
argument|const QSharedPointer<QWindowsFontEngineData>&data
argument_list|)
block|;
specifier|static
name|HFONT
name|systemFont
argument_list|()
block|;
specifier|static
name|QFont
name|LOGFONT_to_QFont
argument_list|(
argument|const LOGFONT& lf
argument_list|,
argument|int verticalDPI =
literal|0
argument_list|)
block|;
specifier|static
name|qreal
name|fontSmoothingGamma
argument_list|()
block|;
specifier|static
name|LOGFONT
name|fontDefToLOGFONT
argument_list|(
specifier|const
name|QFontDef
operator|&
name|fontDef
argument_list|)
block|;
specifier|static
name|QStringList
name|extraTryFontsForFamily
argument_list|(
specifier|const
name|QString
operator|&
name|family
argument_list|)
block|;
specifier|static
name|QString
name|familyForStyleHint
argument_list|(
argument|QFont::StyleHint styleHint
argument_list|)
block|;
name|private
operator|:
name|void
name|populate
argument_list|(
specifier|const
name|QString
operator|&
name|family
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|removeApplicationFonts
argument_list|()
block|;
name|QSet
operator|<
name|QString
operator|>
name|m_families
block|;      struct
name|WinApplicationFont
block|{
name|HANDLE
name|handle
block|;
name|QString
name|fileName
block|;     }
block|;
name|QList
operator|<
name|WinApplicationFont
operator|>
name|m_applicationFonts
block|;      struct
name|UniqueFontData
block|{
name|HANDLE
name|handle
block|;
name|QAtomicInt
name|refCount
block|;     }
block|;
name|QMap
operator|<
name|QString
block|,
name|UniqueFontData
operator|>
name|m_uniqueFontData
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSFONTDATABASE_H
end_comment
end_unit
