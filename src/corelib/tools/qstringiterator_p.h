begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Giuseppe D'Angelo<giuseppe.dangelo@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTRINGITERATOR_H
end_ifndef
begin_define
DECL|macro|QSTRINGITERATOR_H
define|#
directive|define
name|QSTRINGITERATOR_H
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
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QStringIterator
block|{
name|QString
operator|::
name|const_iterator
name|i
operator|,
name|pos
operator|,
name|e
expr_stmt|;
name|public
label|:
specifier|inline
name|explicit
name|QStringIterator
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
operator|:
name|i
argument_list|(
name|string
operator|.
name|constBegin
argument_list|()
argument_list|)
operator|,
name|pos
argument_list|(
name|string
operator|.
name|constBegin
argument_list|()
argument_list|)
operator|,
name|e
argument_list|(
argument|string.constEnd()
argument_list|)
block|{     }
specifier|inline
name|explicit
name|QStringIterator
argument_list|(
specifier|const
name|QChar
operator|*
name|begin
argument_list|,
specifier|const
name|QChar
operator|*
name|end
argument_list|)
operator|:
name|i
argument_list|(
name|begin
argument_list|)
operator|,
name|pos
argument_list|(
name|begin
argument_list|)
operator|,
name|e
argument_list|(
argument|end
argument_list|)
block|{     }
specifier|inline
name|QString
operator|::
name|const_iterator
name|position
argument_list|()
specifier|const
block|{
return|return
name|pos
return|;
block|}
specifier|inline
name|void
name|setPosition
argument_list|(
name|QString
operator|::
name|const_iterator
name|position
argument_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|i
operator|<=
name|position
operator|&&
name|position
operator|<=
name|e
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"position out of bounds"
argument_list|)
expr_stmt|;
name|pos
operator|=
name|position
expr_stmt|;
block|}
comment|// forward iteration
specifier|inline
name|bool
name|hasNext
argument_list|()
specifier|const
block|{
return|return
name|pos
operator|<
name|e
return|;
block|}
specifier|inline
name|void
name|advance
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
name|hasNext
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a next item"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|(
name|pos
operator|++
operator|)
operator|->
name|isHighSurrogate
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|pos
operator|!=
name|e
operator|&&
name|pos
operator|->
name|isLowSurrogate
argument_list|()
argument_list|)
condition|)
operator|++
name|pos
expr_stmt|;
block|}
block|}
specifier|inline
name|void
name|advanceUnchecked
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
name|hasNext
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a next item"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|(
name|pos
operator|++
operator|)
operator|->
name|isHighSurrogate
argument_list|()
argument_list|)
condition|)
operator|++
name|pos
expr_stmt|;
block|}
specifier|inline
name|uint
name|peekNextUnchecked
argument_list|()
specifier|const
block|{
name|Q_ASSERT_X
argument_list|(
name|hasNext
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a next item"
argument_list|)
block|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|pos
operator|->
name|isHighSurrogate
argument_list|()
argument_list|)
condition|)
return|return
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
name|pos
index|[
literal|0
index|]
argument_list|,
name|pos
index|[
literal|1
index|]
argument_list|)
return|;
return|return
name|pos
operator|->
name|unicode
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|uint
name|peekNext
argument_list|(
name|uint
name|invalidAs
operator|=
name|QChar
operator|::
name|ReplacementCharacter
argument_list|)
decl|const
block|{
name|Q_ASSERT_X
argument_list|(
name|hasNext
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a next item"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|pos
operator|->
name|isSurrogate
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|pos
operator|->
name|isHighSurrogate
argument_list|()
argument_list|)
condition|)
block|{
specifier|const
name|QChar
modifier|*
name|low
init|=
name|pos
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|low
operator|!=
name|e
operator|&&
name|low
operator|->
name|isLowSurrogate
argument_list|()
argument_list|)
condition|)
return|return
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
operator|*
name|pos
argument_list|,
operator|*
name|low
argument_list|)
return|;
block|}
return|return
name|invalidAs
return|;
block|}
return|return
name|pos
operator|->
name|unicode
argument_list|()
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|uint
name|nextUnchecked
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
name|hasNext
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a next item"
argument_list|)
expr_stmt|;
specifier|const
name|QChar
name|cur
init|=
operator|*
name|pos
operator|++
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|cur
operator|.
name|isHighSurrogate
argument_list|()
argument_list|)
condition|)
return|return
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
name|cur
argument_list|,
operator|*
name|pos
operator|++
argument_list|)
return|;
return|return
name|cur
operator|.
name|unicode
argument_list|()
return|;
block|}
end_function
begin_function
specifier|inline
name|uint
name|next
parameter_list|(
name|uint
name|invalidAs
init|=
name|QChar
operator|::
name|ReplacementCharacter
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|hasNext
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a next item"
argument_list|)
expr_stmt|;
specifier|const
name|QChar
name|uc
init|=
operator|*
name|pos
operator|++
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|uc
operator|.
name|isSurrogate
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|uc
operator|.
name|isHighSurrogate
argument_list|()
operator|&&
name|pos
operator|<
name|e
operator|&&
name|pos
operator|->
name|isLowSurrogate
argument_list|()
argument_list|)
condition|)
return|return
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
name|uc
argument_list|,
operator|*
name|pos
operator|++
argument_list|)
return|;
return|return
name|invalidAs
return|;
block|}
return|return
name|uc
operator|.
name|unicode
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// backwards iteration
end_comment
begin_expr_stmt
specifier|inline
name|bool
name|hasPrevious
argument_list|()
specifier|const
block|{
return|return
name|pos
operator|>
name|i
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|recede
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
name|hasPrevious
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a previous item"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|(
operator|--
name|pos
operator|)
operator|->
name|isLowSurrogate
argument_list|()
argument_list|)
condition|)
block|{
specifier|const
name|QChar
modifier|*
name|high
init|=
name|pos
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|high
operator|!=
name|i
operator|-
literal|1
operator|&&
name|high
operator|->
name|isHighSurrogate
argument_list|()
argument_list|)
condition|)
operator|--
name|pos
expr_stmt|;
block|}
block|}
end_function
begin_function
specifier|inline
name|void
name|recedeUnchecked
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
name|hasPrevious
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a previous item"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|(
operator|--
name|pos
operator|)
operator|->
name|isLowSurrogate
argument_list|()
argument_list|)
condition|)
operator|--
name|pos
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|uint
name|peekPreviousUnchecked
argument_list|()
specifier|const
block|{
name|Q_ASSERT_X
argument_list|(
name|hasPrevious
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a previous item"
argument_list|)
block|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|pos
index|[
operator|-
literal|1
index|]
operator|.
name|isLowSurrogate
argument_list|()
argument_list|)
condition|)
return|return
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
name|pos
index|[
operator|-
literal|2
index|]
argument_list|,
name|pos
index|[
operator|-
literal|1
index|]
argument_list|)
return|;
end_expr_stmt
begin_return
return|return
name|pos
index|[
operator|-
literal|1
index|]
operator|.
name|unicode
argument_list|()
return|;
end_return
begin_decl_stmt
unit|}      inline
name|uint
name|peekPrevious
argument_list|(
name|uint
name|invalidAs
operator|=
name|QChar
operator|::
name|ReplacementCharacter
argument_list|)
decl|const
block|{
name|Q_ASSERT_X
argument_list|(
name|hasPrevious
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a previous item"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|pos
index|[
operator|-
literal|1
index|]
operator|.
name|isSurrogate
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|pos
index|[
operator|-
literal|1
index|]
operator|.
name|isLowSurrogate
argument_list|()
argument_list|)
condition|)
block|{
specifier|const
name|QChar
modifier|*
name|high
init|=
name|pos
operator|-
literal|2
decl_stmt|;
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|high
operator|!=
name|i
operator|-
literal|1
operator|&&
name|high
operator|->
name|isHighSurrogate
argument_list|()
argument_list|)
condition|)
return|return
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
operator|*
name|high
argument_list|,
name|pos
index|[
operator|-
literal|1
index|]
argument_list|)
return|;
block|}
return|return
name|invalidAs
return|;
block|}
return|return
name|pos
index|[
operator|-
literal|1
index|]
operator|.
name|unicode
argument_list|()
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|uint
name|previousUnchecked
parameter_list|()
block|{
name|Q_ASSERT_X
argument_list|(
name|hasPrevious
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a previous item"
argument_list|)
expr_stmt|;
specifier|const
name|QChar
name|cur
init|=
operator|*
operator|--
name|pos
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|cur
operator|.
name|isLowSurrogate
argument_list|()
argument_list|)
condition|)
return|return
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
operator|*
operator|--
name|pos
argument_list|,
name|cur
argument_list|)
return|;
return|return
name|cur
operator|.
name|unicode
argument_list|()
return|;
block|}
end_function
begin_function
specifier|inline
name|uint
name|previous
parameter_list|(
name|uint
name|invalidAs
init|=
name|QChar
operator|::
name|ReplacementCharacter
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|hasPrevious
argument_list|()
argument_list|,
name|Q_FUNC_INFO
argument_list|,
literal|"iterator hasn't a previous item"
argument_list|)
expr_stmt|;
specifier|const
name|QChar
name|uc
init|=
operator|*
operator|--
name|pos
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|uc
operator|.
name|isSurrogate
argument_list|()
argument_list|)
condition|)
block|{
if|if
condition|(
name|Q_LIKELY
argument_list|(
name|uc
operator|.
name|isLowSurrogate
argument_list|()
operator|&&
name|pos
operator|>
name|i
operator|&&
name|pos
index|[
operator|-
literal|1
index|]
operator|.
name|isHighSurrogate
argument_list|()
argument_list|)
condition|)
return|return
name|QChar
operator|::
name|surrogateToUcs4
argument_list|(
operator|*
operator|--
name|pos
argument_list|,
name|uc
argument_list|)
return|;
return|return
name|invalidAs
return|;
block|}
return|return
name|uc
operator|.
name|unicode
argument_list|()
return|;
block|}
end_function
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTRINGITERATOR_H
end_comment
end_unit
