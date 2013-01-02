begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSFONTDATABASEFT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSFONTDATABASEFT_H
define|#
directive|define
name|QWINDOWSFONTDATABASEFT_H
end_define
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qbasicfontdatabase_p.h>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QWindowsFontDatabaseFT
range|:
name|public
name|QBasicFontDatabase
block|{
name|public
operator|:
name|void
name|populateFontDatabase
argument_list|()
block|;
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
comment|// QWINDOWSFONTDATABASEFT_H
end_comment
end_unit
