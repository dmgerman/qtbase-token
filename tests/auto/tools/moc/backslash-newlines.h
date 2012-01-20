begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_decl_stmt
DECL|variable|blackslashNewlinesDummy
specifier|const
name|int
name|blackslashNewlinesDummy
init|=
literal|0
DECL|macro|value
define|#
directive|define
name|value
value|0\ 1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|BackslashNewlines
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
name|slots
operator|:
if|#
directive|if
name|value
name|void
name|works
argument_list|()
block|{}
else|#
directive|else
name|void
name|buggy
argument_list|()
block|{}
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_undef
DECL|macro|value
undef|#
directive|undef
name|value
end_undef
end_unit
