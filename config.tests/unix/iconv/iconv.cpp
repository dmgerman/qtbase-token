begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if
begin_error
error|#
directive|error
literal|"iconv not supported on IRIX"
end_error
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<iconv.h>
end_include
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
name|iconv_t
name|x
init|=
name|iconv_open
argument_list|(
literal|""
argument_list|,
literal|""
argument_list|)
decl_stmt|;
name|char
modifier|*
name|inp
decl_stmt|;
name|char
modifier|*
name|outp
decl_stmt|;
name|size_t
name|inbytes
decl_stmt|,
name|outbytes
decl_stmt|;
name|iconv
argument_list|(
name|x
argument_list|,
operator|&
name|inp
argument_list|,
operator|&
name|inbytes
argument_list|,
operator|&
name|outp
argument_list|,
operator|&
name|outbytes
argument_list|)
expr_stmt|;
name|iconv_close
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
end_unit
