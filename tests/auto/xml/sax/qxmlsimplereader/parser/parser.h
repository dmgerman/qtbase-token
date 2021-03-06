begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PARSER_H
end_ifndef
begin_define
DECL|macro|PARSER_H
define|#
directive|define
name|PARSER_H
end_define
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qxml.h>
end_include
begin_decl_stmt
DECL|variable|ContentHandler
name|class
name|ContentHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Parser
range|:
name|public
name|QXmlSimpleReader
block|{
name|public
operator|:
name|Parser
argument_list|()
block|;
operator|~
name|Parser
argument_list|()
block|;
name|bool
name|parseFile
argument_list|(
name|QFile
operator|*
name|file
argument_list|)
block|;
name|QString
name|result
argument_list|()
specifier|const
block|;
name|QString
name|errorMsg
argument_list|()
specifier|const
block|;
name|private
operator|:
name|ContentHandler
operator|*
name|handler
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
