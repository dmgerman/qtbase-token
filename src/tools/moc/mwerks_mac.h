begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MWERKS_MAC_H
end_ifndef
begin_define
DECL|macro|MWERKS_MAC_H
define|#
directive|define
name|MWERKS_MAC_H
end_define
begin_include
include|#
directive|include
file|<QtGlobal>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|Q_OS_MAC
DECL|macro|macintosh
define|#
directive|define
name|macintosh
comment|/*make moc a plugin*/
DECL|enum|moc_status
name|enum
name|moc_status
block|{
DECL|enumerator|moc_success
name|moc_success
operator|=
literal|1
operator|,
DECL|enumerator|moc_parse_error
name|moc_parse_error
operator|=
literal|2
operator|,
DECL|enumerator|moc_no_qobject
name|moc_no_qobject
operator|=
literal|3
operator|,
DECL|enumerator|moc_not_time
name|moc_not_time
operator|=
literal|4
operator|,
DECL|enumerator|moc_no_source
name|moc_no_source
operator|=
literal|5
operator|,
DECL|enumerator|moc_general_error
name|moc_general_error
operator|=
literal|6
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|// MWERKS_MAC_H
end_comment
end_unit
