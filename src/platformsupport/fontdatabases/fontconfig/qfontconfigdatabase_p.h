begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtPlatformSupport/private/qbasicunixfontdatabase_p.h>
end_include
begin_decl_stmt
name|class
name|QFontconfigDatabase
range|:
name|public
name|QBasicUnixFontDatabase
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
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTCONFIGDATABASE_H
end_comment
end_unit
