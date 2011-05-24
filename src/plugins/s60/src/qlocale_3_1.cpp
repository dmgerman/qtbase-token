begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<e32std.h>
end_include
begin_include
include|#
directive|include
file|<e32const.h>
end_include
begin_include
include|#
directive|include
file|<e32debug.h>
end_include
begin_expr_stmt
name|_LIT
argument_list|(
name|KYear
argument_list|,
literal|"%Y"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|_LIT
argument_list|(
name|KMonth
argument_list|,
literal|"%M"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|_LIT
argument_list|(
name|KDay
argument_list|,
literal|"%D"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|_LIT
argument_list|(
name|KLocaleIndependent
argument_list|,
literal|"%F"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|dateFormat
specifier|static
name|TBuf
argument_list|<
literal|10
argument_list|>
name|dateFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|timeFormat
specifier|static
name|TBuf
argument_list|<
literal|10
argument_list|>
name|timeFormat
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|initialiseDateFormat
specifier|static
name|void
name|initialiseDateFormat
parameter_list|()
block|{
if|if
condition|(
name|dateFormat
operator|.
name|Length
argument_list|()
condition|)
return|return;
name|TLocale
name|locale
decl_stmt|;
comment|//Separator 1 is used between 1st and 2nd components of the date
comment|//Separator 2 is used between 2nd and 3rd components of the date
comment|//Usually they are the same, but they are allowed to be different
name|TChar
name|s1
init|=
name|locale
operator|.
name|DateSeparator
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|TChar
name|s2
init|=
name|locale
operator|.
name|DateSeparator
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|dateFormat
operator|=
name|KLocaleIndependent
expr_stmt|;
switch|switch
condition|(
name|locale
operator|.
name|DateFormat
argument_list|()
condition|)
block|{
case|case
name|EDateAmerican
case|:
name|dateFormat
operator|.
name|Append
argument_list|(
name|KMonth
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|KDay
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|KYear
argument_list|)
expr_stmt|;
break|break;
case|case
name|EDateEuropean
case|:
name|dateFormat
operator|.
name|Append
argument_list|(
name|KDay
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|KMonth
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|KYear
argument_list|)
expr_stmt|;
break|break;
case|case
name|EDateJapanese
case|:
default|default:
comment|//it's closest to ISO format
name|dateFormat
operator|.
name|Append
argument_list|(
name|KYear
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|KMonth
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|dateFormat
operator|.
name|Append
argument_list|(
name|KDay
argument_list|)
expr_stmt|;
break|break;
block|}
ifdef|#
directive|ifdef
name|_DEBUG
name|RDebug
operator|::
name|Print
argument_list|(
name|_L
argument_list|(
literal|"Date Format \"%S\""
argument_list|)
argument_list|,
operator|&
name|dateFormat
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|initialiseTimeFormat
specifier|static
name|void
name|initialiseTimeFormat
parameter_list|()
block|{
if|if
condition|(
name|timeFormat
operator|.
name|Length
argument_list|()
condition|)
return|return;
name|TLocale
name|locale
decl_stmt|;
comment|//Separator 1 is used between 1st and 2nd components of the time
comment|//Separator 2 is used between 2nd and 3rd components of the time
comment|//Usually they are the same, but they are allowed to be different
name|TChar
name|s1
init|=
name|locale
operator|.
name|TimeSeparator
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|TChar
name|s2
init|=
name|locale
operator|.
name|TimeSeparator
argument_list|(
literal|2
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|locale
operator|.
name|TimeFormat
argument_list|()
condition|)
block|{
case|case
name|ETime12
case|:
name|timeFormat
operator|.
name|Append
argument_list|(
name|_L
argument_list|(
literal|"%I"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|ETime24
case|:
default|default:
name|timeFormat
operator|.
name|Append
argument_list|(
name|_L
argument_list|(
literal|"%H"
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|timeFormat
operator|.
name|Append
argument_list|(
name|s1
argument_list|)
expr_stmt|;
name|timeFormat
operator|.
name|Append
argument_list|(
name|_L
argument_list|(
literal|"%T"
argument_list|)
argument_list|)
expr_stmt|;
name|timeFormat
operator|.
name|Append
argument_list|(
name|s2
argument_list|)
expr_stmt|;
name|timeFormat
operator|.
name|Append
argument_list|(
name|_L
argument_list|(
literal|"%S"
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_DEBUG
name|RDebug
operator|::
name|Print
argument_list|(
name|_L
argument_list|(
literal|"Time Format \"%S\""
argument_list|)
argument_list|,
operator|&
name|timeFormat
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|defaultFormatL
name|EXPORT_C
name|void
name|defaultFormatL
parameter_list|(
name|TTime
modifier|&
name|time
parameter_list|,
name|TDes
modifier|&
name|des
parameter_list|,
specifier|const
name|TDesC
modifier|&
name|fmt
parameter_list|,
specifier|const
name|TLocale
modifier|&
parameter_list|)
block|{
comment|//S60 3.1 does not support format for a specific locale, so use default locale
name|time
operator|.
name|FormatL
argument_list|(
name|des
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//S60 3.1 doesn't support extended locale date&time formats, so use default locale
end_comment
begin_function
DECL|function|defaultGetTimeFormatSpec
name|EXPORT_C
name|TPtrC
name|defaultGetTimeFormatSpec
parameter_list|(
name|TExtendedLocale
modifier|&
parameter_list|)
block|{
name|initialiseTimeFormat
argument_list|()
expr_stmt|;
return|return
name|TPtrC
argument_list|(
name|timeFormat
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|defaultGetLongDateFormatSpec
name|EXPORT_C
name|TPtrC
name|defaultGetLongDateFormatSpec
parameter_list|(
name|TExtendedLocale
modifier|&
parameter_list|)
block|{
name|initialiseDateFormat
argument_list|()
expr_stmt|;
return|return
name|TPtrC
argument_list|(
name|dateFormat
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|defaultGetShortDateFormatSpec
name|EXPORT_C
name|TPtrC
name|defaultGetShortDateFormatSpec
parameter_list|(
name|TExtendedLocale
modifier|&
parameter_list|)
block|{
name|initialiseDateFormat
argument_list|()
expr_stmt|;
return|return
name|TPtrC
argument_list|(
name|dateFormat
argument_list|)
return|;
block|}
end_function
end_unit
