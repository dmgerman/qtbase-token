begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTHREADONCE_H
end_ifndef
begin_define
DECL|macro|QTHREADONCE_H
define|#
directive|define
name|QTHREADONCE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_function
name|QT_BEGIN_HEADER
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_THREAD
name|class
name|QOnceControl
decl_stmt|{ public:     QOnceControl(QBasicAtomicInt *
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QOnceControl
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|mustRunCode
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|done
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QBasicAtomicInt
modifier|*
name|gv
decl_stmt|;
end_decl_stmt
begin_union
union|union
block|{
name|qint32
name|extra
decl_stmt|;
name|void
modifier|*
name|d
decl_stmt|;
block|}
union|;
end_union
begin_define
DECL|macro|Q_ONCE_GV_NAME2
unit|};
define|#
directive|define
name|Q_ONCE_GV_NAME2
parameter_list|(
name|prefix
parameter_list|,
name|line
parameter_list|)
value|prefix ## line
end_define
begin_define
DECL|macro|Q_ONCE_GV_NAME
define|#
directive|define
name|Q_ONCE_GV_NAME
parameter_list|(
name|prefix
parameter_list|,
name|line
parameter_list|)
value|Q_ONCE_GV_NAME2(prefix, line)
end_define
begin_define
DECL|macro|Q_ONCE_GV
define|#
directive|define
name|Q_ONCE_GV
value|Q_ONCE_GV_NAME(_q_once_, __LINE__)
end_define
begin_define
DECL|macro|Q_ONCE
define|#
directive|define
name|Q_ONCE
define|\
value|static QBasicAtomicInt Q_ONCE_GV = Q_BASIC_ATOMIC_INITIALIZER(0);   \     if (0){} else                                                       \         for (QOnceControl _control_(&Q_ONCE_GV); _control_.mustRunCode(); _control_.done())
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QSingleton
block|{
comment|// this is a POD-like class
block|struct
name|Destructor
block|{
name|T
operator|*
operator|&
name|pointer
block|;
name|Destructor
argument_list|(
name|T
operator|*
operator|&
name|ptr
argument_list|)
operator|:
name|pointer
argument_list|(
argument|ptr
argument_list|)
block|{}
operator|~
name|Destructor
argument_list|()
block|{
name|delete
name|pointer
block|; }
block|}
block|;
name|public
operator|:
name|T
operator|*
name|_q_value
block|;
name|QBasicAtomicInt
name|_q_guard
block|;
specifier|inline
name|T
operator|*
name|value
argument_list|()
block|{
for|for
control|(
name|QOnceControl
name|control
argument_list|(
operator|&
name|_q_guard
argument_list|)
init|;
name|control
operator|.
name|mustRunCode
argument_list|()
condition|;
name|control
operator|.
name|done
argument_list|()
control|)
block|{
name|_q_value
operator|=
name|new
name|T
argument_list|()
expr_stmt|;
specifier|static
name|Destructor
name|cleanup
parameter_list|(
name|_q_value
parameter_list|)
function_decl|;
block|}
return|return
name|_q_value
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|T
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
return|return
operator|*
name|value
argument_list|()
return|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt
begin_block
unit|)
block|{
return|return
name|value
argument_list|()
return|;
block|}
end_block
begin_function
specifier|inline
name|operator
name|T
modifier|*
parameter_list|()
block|{
return|return
name|value
argument_list|()
return|;
block|}
end_function
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_macro
name|QT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
