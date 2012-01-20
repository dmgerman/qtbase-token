begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtGui/QPlatformFontDatabase>
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
name|virtual
name|void
name|populateFontDatabase
argument_list|()
block|;
name|virtual
name|QFontEngine
operator|*
name|fontEngine
argument_list|(
argument|const QFontDef&fontDef
argument_list|,
argument|QUnicodeTables::Script script
argument_list|,
argument|void *handle
argument_list|)
block|;
name|virtual
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
block|;
name|virtual
name|QStringList
name|fallbacksForFamily
argument_list|(
argument|const QString family
argument_list|,
argument|const QFont::Style&style
argument_list|,
argument|const QFont::StyleHint&styleHint
argument_list|,
argument|const QUnicodeTables::Script&script
argument_list|)
specifier|const
block|;
name|virtual
name|QStringList
name|addApplicationFont
argument_list|(
specifier|const
name|QByteArray
operator|&
name|fontData
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|virtual
name|void
name|releaseHandle
argument_list|(
name|void
operator|*
name|handle
argument_list|)
block|;
name|virtual
name|QString
name|fontDir
argument_list|()
specifier|const
block|;
name|virtual
name|QFont
name|defaultFont
argument_list|()
specifier|const
block|;
name|virtual
name|QHash
operator|<
name|QByteArray
block|,
name|QFont
operator|>
name|defaultFonts
argument_list|()
specifier|const
block|;
specifier|static
name|QFontEngine
operator|*
name|createEngine
argument_list|(
argument|int script
argument_list|,
argument|const QFontDef&request
argument_list|,
argument|HDC fontHdc
argument_list|,
argument|int dpi
argument_list|,
argument|bool rawMode
argument_list|,
argument|const QStringList&family_list
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
name|QSharedPointer
operator|<
name|QWindowsFontEngineData
operator|>
name|m_fontEngineData
block|;
name|QSet
operator|<
name|QString
operator|>
name|m_families
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
