begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLRECORD_H
end_ifndef
begin_define
DECL|macro|QSQLRECORD_H
define|#
directive|define
name|QSQLRECORD_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsql.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSqlField
name|class
name|QSqlField
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSqlRecordPrivate
name|class
name|QSqlRecordPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_SQL_EXPORT
name|QSqlRecord
block|{
name|public
label|:
name|QSqlRecord
argument_list|()
expr_stmt|;
name|QSqlRecord
argument_list|(
specifier|const
name|QSqlRecord
operator|&
name|other
argument_list|)
expr_stmt|;
name|QSqlRecord
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSqlRecord
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QSqlRecord
argument_list|()
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSqlRecord
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSqlRecord
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|other
operator|)
return|;
block|}
name|QVariant
name|value
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QVariant
name|value
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|void
name|setValue
parameter_list|(
name|int
name|i
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|val
parameter_list|)
function_decl|;
name|void
name|setValue
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|val
parameter_list|)
function_decl|;
name|void
name|setNull
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|void
name|setNull
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|bool
name|isNull
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isNull
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexOf
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|QString
name|fieldName
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QSqlField
name|field
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QSqlField
name|field
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isGenerated
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isGenerated
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|void
name|setGenerated
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|bool
name|generated
parameter_list|)
function_decl|;
name|void
name|setGenerated
parameter_list|(
name|int
name|i
parameter_list|,
name|bool
name|generated
parameter_list|)
function_decl|;
name|void
name|append
parameter_list|(
specifier|const
name|QSqlField
modifier|&
name|field
parameter_list|)
function_decl|;
name|void
name|replace
parameter_list|(
name|int
name|pos
parameter_list|,
specifier|const
name|QSqlField
modifier|&
name|field
parameter_list|)
function_decl|;
name|void
name|insert
parameter_list|(
name|int
name|pos
parameter_list|,
specifier|const
name|QSqlField
modifier|&
name|field
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
name|int
name|pos
parameter_list|)
function_decl|;
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|contains
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|clearValues
parameter_list|()
function_decl|;
name|int
name|count
argument_list|()
specifier|const
expr_stmt|;
name|QSqlRecord
name|keyValues
argument_list|(
specifier|const
name|QSqlRecord
operator|&
name|keyFields
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|detach
parameter_list|()
function_decl|;
name|QSqlRecordPrivate
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_SQL_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSqlRecord
operator|&
operator|)
expr_stmt|;
end_expr_stmt
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
comment|// QSQLRECORD_H
end_comment
end_unit
