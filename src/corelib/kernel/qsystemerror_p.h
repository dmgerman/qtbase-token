begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSTEMERROR_P_H
end_ifndef
begin_define
DECL|macro|QSYSTEMERROR_P_H
define|#
directive|define
name|QSYSTEMERROR_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QSystemError
block|{
name|public
label|:
enum|enum
name|ErrorScope
block|{
name|NoError
block|,
name|StandardLibraryError
block|,
name|NativeError
block|}
enum|;
specifier|inline
name|QSystemError
argument_list|(
argument|int error
argument_list|,
argument|ErrorScope scope
argument_list|)
expr_stmt|;
specifier|inline
name|QSystemError
argument_list|()
expr_stmt|;
name|QString
name|toString
parameter_list|()
function_decl|;
specifier|inline
name|ErrorScope
name|scope
parameter_list|()
function_decl|;
specifier|inline
name|int
name|error
parameter_list|()
function_decl|;
comment|//data members
name|int
name|errorCode
decl_stmt|;
name|ErrorScope
name|errorScope
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|QSystemError
name|QSystemError
operator|::
name|QSystemError
argument_list|(
argument|int error
argument_list|,
argument|QSystemError::ErrorScope scope
argument_list|)
operator|:
name|errorCode
argument_list|(
name|error
argument_list|)
operator|,
name|errorScope
argument_list|(
argument|scope
argument_list|)
block|{  }
DECL|function|QSystemError
name|QSystemError
operator|::
name|QSystemError
argument_list|()
operator|:
name|errorCode
argument_list|(
literal|0
argument_list|)
operator|,
name|errorScope
argument_list|(
argument|NoError
argument_list|)
block|{  }
DECL|function|scope
name|QSystemError
operator|::
name|ErrorScope
name|QSystemError
operator|::
name|scope
argument_list|()
block|{
return|return
name|errorScope
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|error
name|int
name|QSystemError
operator|::
name|error
argument_list|()
block|{
return|return
name|errorCode
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYSTEMERROR_P_H
end_comment
end_unit
