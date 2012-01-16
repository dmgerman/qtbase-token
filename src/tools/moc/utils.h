begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|UTILS_H
end_ifndef
begin_define
DECL|macro|UTILS_H
define|#
directive|define
name|UTILS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|is_whitespace
specifier|inline
name|bool
name|is_whitespace
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
name|s
operator|==
literal|' '
operator|||
name|s
operator|==
literal|'\t'
operator|||
name|s
operator|==
literal|'\n'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_space
specifier|inline
name|bool
name|is_space
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
name|s
operator|==
literal|' '
operator|||
name|s
operator|==
literal|'\t'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_ident_start
specifier|inline
name|bool
name|is_ident_start
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
operator|(
name|s
operator|>=
literal|'a'
operator|&&
name|s
operator|<=
literal|'z'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'A'
operator|&&
name|s
operator|<=
literal|'Z'
operator|)
operator|||
name|s
operator|==
literal|'_'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_ident_char
specifier|inline
name|bool
name|is_ident_char
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
operator|(
name|s
operator|>=
literal|'a'
operator|&&
name|s
operator|<=
literal|'z'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'A'
operator|&&
name|s
operator|<=
literal|'Z'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'0'
operator|&&
name|s
operator|<=
literal|'9'
operator|)
operator|||
name|s
operator|==
literal|'_'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_digit_char
specifier|inline
name|bool
name|is_digit_char
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
name|s
operator|>=
literal|'0'
operator|&&
name|s
operator|<=
literal|'9'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_octal_char
specifier|inline
name|bool
name|is_octal_char
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
name|s
operator|>=
literal|'0'
operator|&&
name|s
operator|<=
literal|'7'
operator|)
return|;
block|}
end_function
begin_function
DECL|function|is_hex_char
specifier|inline
name|bool
name|is_hex_char
parameter_list|(
name|char
name|s
parameter_list|)
block|{
return|return
operator|(
operator|(
name|s
operator|>=
literal|'a'
operator|&&
name|s
operator|<=
literal|'f'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'A'
operator|&&
name|s
operator|<=
literal|'F'
operator|)
operator|||
operator|(
name|s
operator|>=
literal|'0'
operator|&&
name|s
operator|<=
literal|'9'
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|skipQuote
specifier|inline
specifier|const
name|char
modifier|*
name|skipQuote
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|)
block|{
while|while
condition|(
operator|*
name|data
operator|&&
operator|(
operator|*
name|data
operator|!=
literal|'\"'
operator|)
condition|)
block|{
if|if
condition|(
operator|*
name|data
operator|==
literal|'\\'
condition|)
block|{
operator|++
name|data
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|data
condition|)
break|break;
block|}
operator|++
name|data
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|data
condition|)
comment|//Skip last quote
operator|++
name|data
expr_stmt|;
return|return
name|data
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// UTILS_H
end_comment
end_unit
