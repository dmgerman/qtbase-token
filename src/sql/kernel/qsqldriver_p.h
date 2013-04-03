begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLDRIVER_P_H
end_ifndef
begin_define
DECL|macro|QSQLDRIVER_P_H
define|#
directive|define
name|QSQLDRIVER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API. It exists for the convenience
end_comment
begin_comment
comment|// of the QtSQL module. This header file may change from version to version
end_comment
begin_comment
comment|// without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"qsqldriver.h"
end_include
begin_include
include|#
directive|include
file|"qsqlerror.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSqlDriverPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
expr|enum
name|DBMSType
block|{
name|UnknownDB
block|,
name|MSSqlServer
block|,
name|MySqlServer
block|,
name|PostgreSQL
block|,
name|Oracle
block|,
name|Sybase
block|,
name|SQLite
block|,
name|Interbase
block|,
name|DB2
block|}
block|;
name|QSqlDriverPrivate
argument_list|()
operator|:
name|QObjectPrivate
argument_list|()
block|,
name|isOpen
argument_list|(
name|false
argument_list|)
block|,
name|isOpenError
argument_list|(
name|false
argument_list|)
block|,
name|precisionPolicy
argument_list|(
name|QSql
operator|::
name|LowPrecisionDouble
argument_list|)
block|,
name|dbmsType
argument_list|(
argument|UnknownDB
argument_list|)
block|{ }
comment|// @CHECK: this member is never used. It was named q, which expanded to q_func().
name|QSqlDriver
operator|*
name|q_func
argument_list|()
block|;
name|uint
name|isOpen
block|;
name|uint
name|isOpenError
block|;
name|QSqlError
name|error
block|;
name|QSql
operator|::
name|NumericalPrecisionPolicy
name|precisionPolicy
block|;
name|DBMSType
name|dbmsType
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
comment|// QSQLDRIVER_P_H
end_comment
end_unit
