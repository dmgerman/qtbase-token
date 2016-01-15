begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TESTSQLDRIVER_H
end_ifndef
begin_define
DECL|macro|TESTSQLDRIVER_H
define|#
directive|define
name|TESTSQLDRIVER_H
end_define
begin_include
include|#
directive|include
file|<QtSql/QSqlResult>
end_include
begin_include
include|#
directive|include
file|<QtSql/QSqlDriver>
end_include
begin_include
include|#
directive|include
file|<QtSql/QSqlRecord>
end_include
begin_include
include|#
directive|include
file|<private/qsqldriver_p.h>
end_include
begin_decl_stmt
name|class
name|TestSqlDriverResult
range|:
name|public
name|QSqlResult
block|{
name|public
operator|:
name|TestSqlDriverResult
argument_list|(
specifier|const
name|QSqlDriver
operator|*
name|driver
argument_list|)
operator|:
name|QSqlResult
argument_list|(
argument|driver
argument_list|)
block|{}
operator|~
name|TestSqlDriverResult
argument_list|()
block|{}
name|bool
name|savePrepare
argument_list|(
argument|const QString& sqlquery
argument_list|)
block|{
return|return
name|QSqlResult
operator|::
name|savePrepare
argument_list|(
name|sqlquery
argument_list|)
return|;
block|}
name|QVector
operator|<
name|QVariant
operator|>
name|boundValues
argument_list|()
specifier|const
block|{
return|return
name|QSqlResult
operator|::
name|boundValues
argument_list|()
return|;
block|}
name|protected
operator|:
name|QVariant
name|data
argument_list|(
argument|int
comment|/* index */
argument_list|)
block|{
return|return
name|QVariant
argument_list|()
return|;
block|}
name|bool
name|isNull
argument_list|(
argument|int
comment|/* index */
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|reset
argument_list|(
argument|const QString&
comment|/* query */
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|fetch
argument_list|(
argument|int
comment|/* index */
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|fetchFirst
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|bool
name|fetchLast
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|int
name|size
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|int
name|numRowsAffected
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|QSqlRecord
name|record
argument_list|()
specifier|const
block|{
return|return
name|QSqlRecord
argument_list|()
return|;
block|}
expr|}
block|;
name|class
name|TestSqlDriver
operator|:
name|public
name|QSqlDriver
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSqlDriver
argument_list|)
name|public
operator|:
name|TestSqlDriver
argument_list|()
block|{}
operator|~
name|TestSqlDriver
argument_list|()
block|{}
name|bool
name|hasFeature
argument_list|(
argument|DriverFeature f
argument_list|)
specifier|const
block|{
switch|switch
condition|(
name|f
condition|)
block|{
case|case
name|QSqlDriver
operator|::
name|PreparedQueries
case|:
case|case
name|QSqlDriver
operator|::
name|NamedPlaceholders
case|:
return|return
name|true
return|;
default|default:
break|break;
block|}
return|return
name|false
return|;
block|}
name|bool
name|open
argument_list|(
argument|const QString&
comment|/* db */
argument_list|,
argument|const QString&
comment|/* user */
argument_list|,
argument|const QString&
comment|/* password */
argument_list|,
argument|const QString&
comment|/* host */
argument_list|,
argument|int
comment|/* port */
argument_list|,
argument|const QString&
comment|/* options */
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|void
name|close
argument_list|()
block|{}
name|QSqlResult
operator|*
name|createResult
argument_list|()
specifier|const
block|{
return|return
name|new
name|TestSqlDriverResult
argument_list|(
name|this
argument_list|)
return|;
block|}
expr|}
block|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TESTSQLDRIVER_H
end_comment
end_unit
