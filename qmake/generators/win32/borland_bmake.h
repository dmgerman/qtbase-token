begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BORLAND_BMAKE_H
end_ifndef
begin_define
DECL|macro|BORLAND_BMAKE_H
define|#
directive|define
name|BORLAND_BMAKE_H
end_define
begin_include
include|#
directive|include
file|"winmakefile.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|BorlandMakefileGenerator
range|:
name|public
name|Win32MakefileGenerator
block|{
name|bool
name|init_flag
block|;
name|void
name|writeBorlandParts
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|void
name|writeBuildRulesPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeCleanParts
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|bool
name|writeMakefile
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|void
name|init
argument_list|()
block|;
name|public
operator|:
name|BorlandMakefileGenerator
argument_list|()
block|;
operator|~
name|BorlandMakefileGenerator
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|~BorlandMakefileGenerator
specifier|inline
name|BorlandMakefileGenerator
operator|::
operator|~
name|BorlandMakefileGenerator
argument_list|()
block|{ }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// BORLAND_BMAKE_H
end_comment
end_unit
