begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPODLIST_P_H
end_ifndef
begin_define
DECL|macro|QPODLIST_P_H
define|#
directive|define
name|QPODLIST_P_H
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
file|<QtCore/qvarlengtharray.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|T
name|template
operator|<
name|typename
name|T
operator|,
name|int
name|Prealloc
operator|>
DECL|variable|T
name|class
name|QPodList
operator|:
name|public
name|QVarLengthArray
operator|<
name|T
operator|,
name|Prealloc
operator|>
block|{
name|using
name|QVarLengthArray
operator|<
name|T
block|,
name|Prealloc
operator|>
operator|::
name|s
block|;
name|using
name|QVarLengthArray
operator|<
name|T
block|,
name|Prealloc
operator|>
operator|::
name|a
block|;
name|using
name|QVarLengthArray
operator|<
name|T
block|,
name|Prealloc
operator|>
operator|::
name|ptr
block|;
name|using
name|QVarLengthArray
operator|<
name|T
block|,
name|Prealloc
operator|>
operator|::
name|realloc
block|;
name|public
operator|:
specifier|inline
name|explicit
name|QPodList
argument_list|(
argument|int size =
literal|0
argument_list|)
operator|:
name|QVarLengthArray
operator|<
name|T
block|,
name|Prealloc
operator|>
operator|(
name|size
operator|)
block|{}
specifier|inline
name|void
name|insert
argument_list|(
argument|int idx
argument_list|,
argument|const T&t
argument_list|)
block|{
specifier|const
name|int
name|sz
operator|=
name|s
operator|++
block|;
if|if
condition|(
name|s
operator|==
name|a
condition|)
name|realloc
argument_list|(
name|s
argument_list|,
name|s
operator|<<
literal|1
argument_list|)
expr_stmt|;
operator|::
name|memmove
argument_list|(
name|ptr
operator|+
name|idx
operator|+
literal|1
argument_list|,
name|ptr
operator|+
name|idx
argument_list|,
operator|(
name|sz
operator|-
name|idx
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;
name|ptr
index|[
name|idx
index|]
operator|=
name|t
block|;     }
specifier|inline
name|void
name|removeAll
argument_list|(
argument|const T&t
argument_list|)
block|{
name|int
name|i
operator|=
literal|0
block|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|s
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
name|ptr
index|[
name|j
index|]
operator|!=
name|t
condition|)
name|ptr
index|[
name|i
operator|++
index|]
operator|=
name|ptr
index|[
name|j
index|]
expr_stmt|;
block|}
name|s
operator|=
name|i
expr_stmt|;
end_expr_stmt
begin_function
unit|}      inline
name|void
name|removeAt
parameter_list|(
name|int
name|idx
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|idx
operator|>=
literal|0
operator|&&
name|idx
operator|<
name|s
argument_list|)
expr_stmt|;
operator|::
name|memmove
argument_list|(
name|ptr
operator|+
name|idx
argument_list|,
name|ptr
operator|+
name|idx
operator|+
literal|1
argument_list|,
operator|(
name|s
operator|-
name|idx
operator|-
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
operator|--
name|s
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|T
name|takeFirst
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|s
operator|>
literal|0
argument_list|)
expr_stmt|;
name|T
name|tmp
init|=
name|ptr
index|[
literal|0
index|]
decl_stmt|;
name|removeAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPODLIST_P_H
end_comment
end_unit
