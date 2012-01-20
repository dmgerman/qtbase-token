begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<tiffio.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIFF_VERSION
argument_list|)
operator|&&
name|defined
argument_list|(
name|TIFF_VERSION_CLASSIC
argument_list|)
end_if
begin_comment
comment|// libtiff 4.0 splits it into TIFF_VERSION_CLASSIC and TIFF_VERSION_BIG
end_comment
begin_define
DECL|macro|TIFF_VERSION
define|#
directive|define
name|TIFF_VERSION
value|TIFF_VERSION_CLASSIC
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TIFF_VERSION
argument_list|)
end_if
begin_error
error|#
directive|error
literal|"Required libtiff not found"
end_error
begin_elif
elif|#
directive|elif
name|TIFF_VERSION
operator|<
literal|42
end_elif
begin_error
error|#
directive|error
literal|"unsupported tiff version"
end_error
begin_endif
endif|#
directive|endif
end_endif
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
name|tdata_t
name|buffer
init|=
name|_TIFFmalloc
argument_list|(
literal|128
argument_list|)
decl_stmt|;
name|_TIFFfree
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
comment|// some libtiff implementations where TIFF_VERSION>= 42 do not
comment|// have TIFFReadRGBAImageOriented(), so let's check for it
name|TIFFReadRGBAImageOriented
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
