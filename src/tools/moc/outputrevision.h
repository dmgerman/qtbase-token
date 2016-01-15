begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
literal|67
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
