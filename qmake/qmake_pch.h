begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMAKE_PCH_H
end_ifndef
begin_define
DECL|macro|QMAKE_PCH_H
define|#
directive|define
name|QMAKE_PCH_H
end_define
begin_comment
comment|// for rand_s, _CRT_RAND_S must be #defined before #including stdlib.h.
end_comment
begin_comment
comment|// put it at the beginning so some indirect inclusion doesn't break it
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_CRT_RAND_S
end_ifndef
begin_define
DECL|macro|_CRT_RAND_S
define|#
directive|define
name|_CRT_RAND_S
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_define
DECL|macro|_POSIX_
define|#
directive|define
name|_POSIX_
end_define
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_undef
DECL|macro|_POSIX_
undef|#
directive|undef
name|_POSIX_
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_comment
comment|//#include "makefile.h"
end_comment
begin_comment
comment|//#include "meta.h"
end_comment
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_comment
comment|//#include "winmakefile.h"
end_comment
begin_comment
comment|//#include<qtextstream.h>
end_comment
begin_comment
comment|//#include "project.h"
end_comment
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|//#include<qdir.h>
comment|//#include "option.h"
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
