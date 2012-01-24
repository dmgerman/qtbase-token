begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|OUTPUTREVISION_H
end_ifndef
begin_define
DECL|macro|OUTPUTREVISION_H
define|#
directive|define
name|OUTPUTREVISION_H
end_define
begin_comment
comment|// if the output revision changes, you MUST change it in qobjectdefs.h too
end_comment
begin_enum
DECL|enumerator|mocOutputRevision
enum|enum
block|{
name|mocOutputRevision
init|=
literal|63
block|}
enum|;
end_enum
begin_comment
DECL|enumerator|mocOutputRevision
comment|// moc format output revision
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// OUTPUTREVISION_H
end_comment
end_unit
