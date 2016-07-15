begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTCONFIGDATABASE_H
end_ifndef
begin_define
DECL|macro|QFONTCONFIGDATABASE_H
define|#
directive|define
name|QFONTCONFIGDATABASE_H
end_define
begin_include
include|#
directive|include
file|<QPlatformFontDatabase>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qbasicfontdatabase_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFontconfigDatabase
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
name|QString
name|resolveFontFamilyAlias
argument_list|(
argument|const QString&family
argument_list|)
specifier|const
block|;
name|QFont
name|defaultFont
argument_list|()
specifier|const
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
comment|// QFONTCONFIGDATABASE_H
end_comment
end_unit
