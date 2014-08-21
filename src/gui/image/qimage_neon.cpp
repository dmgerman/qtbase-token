begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<private/qimage_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qsimd_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_NEON__
end_ifdef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qt_convert_rgb888_to_rgb32_neon
name|Q_GUI_EXPORT
name|void
name|QT_FASTCALL
name|qt_convert_rgb888_to_rgb32_neon
parameter_list|(
name|quint32
modifier|*
name|dst
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|len
parameter_list|)
block|{
if|if
condition|(
operator|!
name|len
condition|)
return|return;
specifier|const
name|quint32
modifier|*
specifier|const
name|end
init|=
name|dst
operator|+
name|len
decl_stmt|;
comment|// align dst on 64 bits
specifier|const
name|int
name|offsetToAlignOn8Bytes
init|=
operator|(
cast|reinterpret_cast
argument_list|<
name|quintptr
argument_list|>
argument_list|(
name|dst
argument_list|)
operator|>>
literal|2
operator|)
operator|&
literal|0x1
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|offsetToAlignOn8Bytes
condition|;
operator|++
name|i
control|)
block|{
operator|*
name|dst
operator|++
operator|=
name|qRgb
argument_list|(
name|src
index|[
literal|0
index|]
argument_list|,
name|src
index|[
literal|1
index|]
argument_list|,
name|src
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|src
operator|+=
literal|3
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|len
operator|-
name|offsetToAlignOn8Bytes
operator|)
operator|>=
literal|8
condition|)
block|{
specifier|const
name|quint32
modifier|*
specifier|const
name|simdEnd
init|=
name|end
operator|-
literal|7
decl_stmt|;
specifier|register
name|uint8x8_t
name|fullVector
name|asm
argument_list|(
literal|"d3"
argument_list|)
init|=
name|vdup_n_u8
argument_list|(
literal|0xff
argument_list|)
decl_stmt|;
do|do
block|{
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
asm|asm
specifier|volatile
asm|(                 "vld3.8     { d4, d5, d6 }, [%[SRC]] !\n\t"                 "vst4.8     { d3, d4, d5, d6 }, [%[DST],:64] !\n\t"                 : [DST]"+r" (dst), [SRC]"+r" (src)                 : "w"(fullVector)                 : "memory", "d4", "d5", "d6"             );
else|#
directive|else
asm|asm
specifier|volatile
asm|(                 "vld3.8     { d0, d1, d2 }, [%[SRC]] !\n\t"                 "vswp d0, d2\n\t"                 "vst4.8     { d0, d1, d2, d3 }, [%[DST],:64] !\n\t"                 : [DST]"+r" (dst), [SRC]"+r" (src)                 : "w"(fullVector)                 : "memory", "d0", "d1", "d2"             );
endif|#
directive|endif
block|}
do|while
condition|(
name|dst
operator|<
name|simdEnd
condition|)
do|;
block|}
while|while
condition|(
name|dst
operator|!=
name|end
condition|)
block|{
operator|*
name|dst
operator|++
operator|=
name|qRgb
argument_list|(
name|src
index|[
literal|0
index|]
argument_list|,
name|src
index|[
literal|1
index|]
argument_list|,
name|src
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|src
operator|+=
literal|3
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|convert_RGB888_to_RGB32_neon
name|void
name|convert_RGB888_to_RGB32_neon
parameter_list|(
name|QImageData
modifier|*
name|dest
parameter_list|,
specifier|const
name|QImageData
modifier|*
name|src
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|src
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_RGB888
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|dest
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_RGB32
operator|||
name|dest
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_ARGB32
operator|||
name|dest
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|src
operator|->
name|width
operator|==
name|dest
operator|->
name|width
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|src
operator|->
name|height
operator|==
name|dest
operator|->
name|height
argument_list|)
expr_stmt|;
specifier|const
name|uchar
modifier|*
name|src_data
init|=
operator|(
name|uchar
operator|*
operator|)
name|src
operator|->
name|data
decl_stmt|;
name|quint32
modifier|*
name|dest_data
init|=
operator|(
name|quint32
operator|*
operator|)
name|dest
operator|->
name|data
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|src
operator|->
name|height
condition|;
operator|++
name|i
control|)
block|{
name|qt_convert_rgb888_to_rgb32_neon
argument_list|(
name|dest_data
argument_list|,
name|src_data
argument_list|,
name|src
operator|->
name|width
argument_list|)
expr_stmt|;
name|src_data
operator|+=
name|src
operator|->
name|bytes_per_line
expr_stmt|;
name|dest_data
operator|=
operator|(
name|quint32
operator|*
operator|)
operator|(
operator|(
name|uchar
operator|*
operator|)
name|dest_data
operator|+
name|dest
operator|->
name|bytes_per_line
operator|)
expr_stmt|;
block|}
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
comment|// __ARM_NEON__
end_comment
end_unit
