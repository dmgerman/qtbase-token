begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_struct
DECL|struct|T
struct|struct
name|T
block|{
DECL|function|T
name|T
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"static constructor"
argument_list|)
expr_stmt|;
block|}
DECL|function|~T
name|~
name|T
parameter_list|()
block|{
name|qDebug
argument_list|(
literal|"static destructor"
argument_list|)
expr_stmt|;
block|}
block|}
DECL|variable|t
name|t
struct|;
end_struct
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
name|qDebug
argument_list|(
literal|"qDebug"
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"qWarning"
argument_list|)
expr_stmt|;
name|qCritical
argument_list|(
literal|"qCritical"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
