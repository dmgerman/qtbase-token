begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|"qblendfunctions_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|SourceOnlyAlpha
struct|struct
name|SourceOnlyAlpha
block|{
DECL|function|alpha
specifier|inline
name|uchar
name|alpha
parameter_list|(
name|uchar
name|src
parameter_list|)
specifier|const
block|{
return|return
name|src
return|;
block|}
DECL|function|bytemul
specifier|inline
name|quint16
name|bytemul
parameter_list|(
name|quint16
name|spix
parameter_list|)
specifier|const
block|{
return|return
name|spix
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|SourceAndConstAlpha
struct|struct
name|SourceAndConstAlpha
block|{
DECL|function|SourceAndConstAlpha
name|SourceAndConstAlpha
parameter_list|(
name|int
name|a
parameter_list|)
member_init_list|:
name|m_alpha256
argument_list|(
name|a
argument_list|)
block|{
name|m_alpha255
operator|=
operator|(
name|m_alpha256
operator|*
literal|255
operator|)
operator|>>
literal|8
expr_stmt|;
block|}
empty_stmt|;
DECL|function|alpha
specifier|inline
name|uchar
name|alpha
parameter_list|(
name|uchar
name|src
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|src
operator|*
name|m_alpha256
operator|)
operator|>>
literal|8
return|;
block|}
DECL|function|bytemul
specifier|inline
name|quint16
name|bytemul
parameter_list|(
name|quint16
name|x
parameter_list|)
specifier|const
block|{
name|uint
name|t
init|=
operator|(
operator|(
operator|(
name|x
operator|&
literal|0x07e0
operator|)
operator|*
name|m_alpha255
operator|)
operator|>>
literal|8
operator|)
operator|&
literal|0x07e0
decl_stmt|;
name|t
operator||=
operator|(
operator|(
operator|(
name|x
operator|&
literal|0xf81f
operator|)
operator|*
operator|(
name|m_alpha255
operator|>>
literal|2
operator|)
operator|)
operator|>>
literal|6
operator|)
operator|&
literal|0xf81f
expr_stmt|;
return|return
name|t
return|;
block|}
DECL|member|m_alpha255
name|int
name|m_alpha255
decl_stmt|;
DECL|member|m_alpha256
name|int
name|m_alpha256
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|/************************************************************************                        RGB16 (565) format target format  ************************************************************************/
end_comment
begin_struct
DECL|struct|Blend_RGB16_on_RGB16_NoAlpha
struct|struct
name|Blend_RGB16_on_RGB16_NoAlpha
block|{
DECL|function|write
specifier|inline
name|void
name|write
parameter_list|(
name|quint16
modifier|*
name|dst
parameter_list|,
name|quint16
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|src
expr_stmt|;
block|}
DECL|function|flush
specifier|inline
name|void
name|flush
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
block|}
struct|;
end_struct
begin_struct
DECL|struct|Blend_RGB16_on_RGB16_ConstAlpha
struct|struct
name|Blend_RGB16_on_RGB16_ConstAlpha
block|{
DECL|function|Blend_RGB16_on_RGB16_ConstAlpha
specifier|inline
name|Blend_RGB16_on_RGB16_ConstAlpha
parameter_list|(
name|quint32
name|alpha
parameter_list|)
block|{
name|m_alpha
operator|=
operator|(
name|alpha
operator|*
literal|255
operator|)
operator|>>
literal|8
expr_stmt|;
name|m_ialpha
operator|=
literal|255
operator|-
name|m_alpha
expr_stmt|;
block|}
DECL|function|write
specifier|inline
name|void
name|write
parameter_list|(
name|quint16
modifier|*
name|dst
parameter_list|,
name|quint16
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|BYTE_MUL_RGB16
argument_list|(
name|src
argument_list|,
name|m_alpha
argument_list|)
operator|+
name|BYTE_MUL_RGB16
argument_list|(
operator|*
name|dst
argument_list|,
name|m_ialpha
argument_list|)
expr_stmt|;
block|}
DECL|function|flush
specifier|inline
name|void
name|flush
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
DECL|member|m_alpha
name|quint32
name|m_alpha
decl_stmt|;
DECL|member|m_ialpha
name|quint32
name|m_ialpha
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|Blend_ARGB32_on_RGB16_SourceAlpha
struct|struct
name|Blend_ARGB32_on_RGB16_SourceAlpha
block|{
DECL|function|write
specifier|inline
name|void
name|write
parameter_list|(
name|quint16
modifier|*
name|dst
parameter_list|,
name|quint32
name|src
parameter_list|)
block|{
specifier|const
name|quint8
name|alpha
init|=
name|qAlpha
argument_list|(
name|src
argument_list|)
decl_stmt|;
if|if
condition|(
name|alpha
condition|)
block|{
name|quint16
name|s
init|=
name|qConvertRgb32To16
argument_list|(
name|src
argument_list|)
decl_stmt|;
if|if
condition|(
name|alpha
operator|<
literal|255
condition|)
name|s
operator|+=
name|BYTE_MUL_RGB16
argument_list|(
operator|*
name|dst
argument_list|,
literal|255
operator|-
name|alpha
argument_list|)
expr_stmt|;
operator|*
name|dst
operator|=
name|s
expr_stmt|;
block|}
block|}
DECL|function|flush
specifier|inline
name|void
name|flush
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
block|}
struct|;
end_struct
begin_struct
DECL|struct|Blend_ARGB32_on_RGB16_SourceAndConstAlpha
struct|struct
name|Blend_ARGB32_on_RGB16_SourceAndConstAlpha
block|{
DECL|function|Blend_ARGB32_on_RGB16_SourceAndConstAlpha
specifier|inline
name|Blend_ARGB32_on_RGB16_SourceAndConstAlpha
parameter_list|(
name|quint32
name|alpha
parameter_list|)
block|{
name|m_alpha
operator|=
operator|(
name|alpha
operator|*
literal|255
operator|)
operator|>>
literal|8
expr_stmt|;
block|}
DECL|function|write
specifier|inline
name|void
name|write
parameter_list|(
name|quint16
modifier|*
name|dst
parameter_list|,
name|quint32
name|src
parameter_list|)
block|{
name|src
operator|=
name|BYTE_MUL
argument_list|(
name|src
argument_list|,
name|m_alpha
argument_list|)
expr_stmt|;
specifier|const
name|quint8
name|alpha
init|=
name|qAlpha
argument_list|(
name|src
argument_list|)
decl_stmt|;
if|if
condition|(
name|alpha
condition|)
block|{
name|quint16
name|s
init|=
name|qConvertRgb32To16
argument_list|(
name|src
argument_list|)
decl_stmt|;
if|if
condition|(
name|alpha
operator|<
literal|255
condition|)
name|s
operator|+=
name|BYTE_MUL_RGB16
argument_list|(
operator|*
name|dst
argument_list|,
literal|255
operator|-
name|alpha
argument_list|)
expr_stmt|;
operator|*
name|dst
operator|=
name|s
expr_stmt|;
block|}
block|}
DECL|function|flush
specifier|inline
name|void
name|flush
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
DECL|member|m_alpha
name|quint32
name|m_alpha
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|qt_scale_image_rgb16_on_rgb16
name|void
name|qt_scale_image_rgb16_on_rgb16
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sourceRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|clip
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG_DRAW
name|printf
argument_list|(
literal|"qt_scale_rgb16_on_rgb16: dst=(%p, %d), src=(%p, %d), target=(%d, %d), [%d x %d], src=(%d, %d) [%d x %d] alpha=%d\n"
argument_list|,
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
operator|.
name|x
argument_list|()
argument_list|,
name|targetRect
operator|.
name|y
argument_list|()
argument_list|,
name|targetRect
operator|.
name|width
argument_list|()
argument_list|,
name|targetRect
operator|.
name|height
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|x
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|y
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|width
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|height
argument_list|()
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
name|Blend_RGB16_on_RGB16_NoAlpha
name|noAlpha
decl_stmt|;
name|qt_scale_image_16bit
argument_list|<
name|quint16
argument_list|>
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|noAlpha
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Blend_RGB16_on_RGB16_ConstAlpha
name|constAlpha
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
name|qt_scale_image_16bit
argument_list|<
name|quint16
argument_list|>
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|constAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_scale_image_argb32_on_rgb16
name|void
name|qt_scale_image_argb32_on_rgb16
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sourceRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|clip
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG_DRAW
name|printf
argument_list|(
literal|"qt_scale_argb32_on_rgb16: dst=(%p, %d), src=(%p, %d), target=(%d, %d), [%d x %d], src=(%d, %d) [%d x %d] alpha=%d\n"
argument_list|,
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
operator|.
name|x
argument_list|()
argument_list|,
name|targetRect
operator|.
name|y
argument_list|()
argument_list|,
name|targetRect
operator|.
name|width
argument_list|()
argument_list|,
name|targetRect
operator|.
name|height
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|x
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|y
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|width
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|height
argument_list|()
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
name|Blend_ARGB32_on_RGB16_SourceAlpha
name|noAlpha
decl_stmt|;
name|qt_scale_image_16bit
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|noAlpha
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Blend_ARGB32_on_RGB16_SourceAndConstAlpha
name|constAlpha
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
name|qt_scale_image_16bit
argument_list|<
name|quint32
argument_list|>
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|constAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_blend_rgb16_on_rgb16
name|void
name|qt_blend_rgb16_on_rgb16
parameter_list|(
name|uchar
modifier|*
name|dst
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG_DRAW
name|printf
argument_list|(
literal|"qt_blend_rgb16_on_rgb16: dst=(%p, %d), src=(%p, %d), dim=(%d, %d) alpha=%d\n"
argument_list|,
name|dst
argument_list|,
name|dbpl
argument_list|,
name|src
argument_list|,
name|sbpl
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
if|if
condition|(
name|w
operator|<=
literal|64
condition|)
block|{
while|while
condition|(
name|h
operator|--
condition|)
block|{
name|QT_MEMCPY_USHORT
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|dst
operator|+=
name|dbpl
expr_stmt|;
name|src
operator|+=
name|sbpl
expr_stmt|;
block|}
block|}
else|else
block|{
name|int
name|length
init|=
name|w
operator|<<
literal|1
decl_stmt|;
while|while
condition|(
name|h
operator|--
condition|)
block|{
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|dst
operator|+=
name|dbpl
expr_stmt|;
name|src
operator|+=
name|sbpl
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
name|const_alpha
operator|!=
literal|0
condition|)
block|{
name|quint16
modifier|*
name|d
init|=
operator|(
name|quint16
operator|*
operator|)
name|dst
decl_stmt|;
specifier|const
name|quint16
modifier|*
name|s
init|=
operator|(
specifier|const
name|quint16
operator|*
operator|)
name|src
decl_stmt|;
name|quint8
name|a
init|=
operator|(
literal|255
operator|*
name|const_alpha
operator|)
operator|>>
literal|8
decl_stmt|;
name|quint8
name|ia
init|=
literal|255
operator|-
name|a
decl_stmt|;
while|while
condition|(
name|h
operator|--
condition|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
name|d
index|[
name|x
index|]
operator|=
name|BYTE_MUL_RGB16
argument_list|(
name|s
index|[
name|x
index|]
argument_list|,
name|a
argument_list|)
operator|+
name|BYTE_MUL_RGB16
argument_list|(
name|d
index|[
name|x
index|]
argument_list|,
name|ia
argument_list|)
expr_stmt|;
block|}
name|d
operator|=
operator|(
name|quint16
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|d
operator|)
operator|+
name|dbpl
operator|)
expr_stmt|;
name|s
operator|=
operator|(
specifier|const
name|quint16
operator|*
operator|)
operator|(
operator|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|s
operator|)
operator|+
name|sbpl
operator|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|qt_blend_argb32_on_rgb16_const_alpha
name|void
name|qt_blend_argb32_on_rgb16_const_alpha
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
name|quint16
modifier|*
name|dst
init|=
operator|(
name|quint16
operator|*
operator|)
name|destPixels
decl_stmt|;
specifier|const
name|quint32
modifier|*
name|src
init|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
name|srcPixels
decl_stmt|;
name|const_alpha
operator|=
operator|(
name|const_alpha
operator|*
literal|255
operator|)
operator|>>
literal|8
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|w
condition|;
operator|++
name|i
control|)
block|{
name|uint
name|s
init|=
name|src
index|[
name|i
index|]
decl_stmt|;
name|s
operator|=
name|BYTE_MUL
argument_list|(
name|s
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
name|int
name|alpha
init|=
name|qAlpha
argument_list|(
name|s
argument_list|)
decl_stmt|;
name|s
operator|=
name|qConvertRgb32To16
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|s
operator|+=
name|BYTE_MUL_RGB16
argument_list|(
name|dst
index|[
name|i
index|]
argument_list|,
literal|255
operator|-
name|alpha
argument_list|)
expr_stmt|;
name|dst
index|[
name|i
index|]
operator|=
name|s
expr_stmt|;
block|}
name|dst
operator|=
operator|(
name|quint16
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|dst
operator|)
operator|+
name|dbpl
operator|)
expr_stmt|;
name|src
operator|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|src
operator|)
operator|+
name|sbpl
operator|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_blend_argb32_on_rgb16
specifier|static
name|void
name|qt_blend_argb32_on_rgb16
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
if|if
condition|(
name|const_alpha
operator|!=
literal|256
condition|)
block|{
name|qt_blend_argb32_on_rgb16_const_alpha
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
return|return;
block|}
name|quint16
modifier|*
name|dst
init|=
operator|(
name|quint16
operator|*
operator|)
name|destPixels
decl_stmt|;
name|quint32
modifier|*
name|src
init|=
operator|(
name|quint32
operator|*
operator|)
name|srcPixels
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
name|quint32
name|spix
init|=
name|src
index|[
name|x
index|]
decl_stmt|;
name|quint32
name|alpha
init|=
name|spix
operator|>>
literal|24
decl_stmt|;
if|if
condition|(
name|alpha
operator|==
literal|255
condition|)
block|{
name|dst
index|[
name|x
index|]
operator|=
name|qConvertRgb32To16
argument_list|(
name|spix
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|alpha
operator|!=
literal|0
condition|)
block|{
name|quint32
name|dpix
init|=
name|dst
index|[
name|x
index|]
decl_stmt|;
name|quint32
name|sia
init|=
literal|255
operator|-
name|alpha
decl_stmt|;
name|quint32
name|sr
init|=
operator|(
name|spix
operator|>>
literal|8
operator|)
operator|&
literal|0xf800
decl_stmt|;
name|quint32
name|sg
init|=
operator|(
name|spix
operator|>>
literal|5
operator|)
operator|&
literal|0x07e0
decl_stmt|;
name|quint32
name|sb
init|=
operator|(
name|spix
operator|>>
literal|3
operator|)
operator|&
literal|0x001f
decl_stmt|;
name|quint32
name|dr
init|=
operator|(
name|dpix
operator|&
literal|0x0000f800
operator|)
decl_stmt|;
name|quint32
name|dg
init|=
operator|(
name|dpix
operator|&
literal|0x000007e0
operator|)
decl_stmt|;
name|quint32
name|db
init|=
operator|(
name|dpix
operator|&
literal|0x0000001f
operator|)
decl_stmt|;
name|quint32
name|siar
init|=
name|dr
operator|*
name|sia
decl_stmt|;
name|quint32
name|siag
init|=
name|dg
operator|*
name|sia
decl_stmt|;
name|quint32
name|siab
init|=
name|db
operator|*
name|sia
decl_stmt|;
name|quint32
name|rr
init|=
name|sr
operator|+
operator|(
operator|(
name|siar
operator|+
operator|(
name|siar
operator|>>
literal|8
operator|)
operator|+
operator|(
literal|0x80
operator|<<
literal|8
operator|)
operator|)
operator|>>
literal|8
operator|)
decl_stmt|;
name|quint32
name|rg
init|=
name|sg
operator|+
operator|(
operator|(
name|siag
operator|+
operator|(
name|siag
operator|>>
literal|8
operator|)
operator|+
operator|(
literal|0x80
operator|<<
literal|3
operator|)
operator|)
operator|>>
literal|8
operator|)
decl_stmt|;
name|quint32
name|rb
init|=
name|sb
operator|+
operator|(
operator|(
name|siab
operator|+
operator|(
name|siab
operator|>>
literal|8
operator|)
operator|+
operator|(
literal|0x80
operator|>>
literal|3
operator|)
operator|)
operator|>>
literal|8
operator|)
decl_stmt|;
name|dst
index|[
name|x
index|]
operator|=
operator|(
name|rr
operator|&
literal|0xf800
operator|)
operator||
operator|(
name|rg
operator|&
literal|0x07e0
operator|)
operator||
operator|(
name|rb
operator|)
expr_stmt|;
block|}
block|}
name|dst
operator|=
operator|(
name|quint16
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|dst
operator|)
operator|+
name|dbpl
operator|)
expr_stmt|;
name|src
operator|=
operator|(
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|src
operator|)
operator|+
name|sbpl
operator|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_blend_rgb32_on_rgb16
specifier|static
name|void
name|qt_blend_rgb32_on_rgb16
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG_DRAW
name|printf
argument_list|(
literal|"qt_blend_rgb32_on_rgb16: dst=(%p, %d), src=(%p, %d), dim=(%d, %d) alpha=%d\n"
argument_list|,
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|const_alpha
operator|!=
literal|256
condition|)
block|{
name|qt_blend_argb32_on_rgb16
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|quint32
modifier|*
name|src
init|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
name|srcPixels
decl_stmt|;
name|int
name|srcExtraStride
init|=
operator|(
name|sbpl
operator|>>
literal|2
operator|)
operator|-
name|w
decl_stmt|;
name|int
name|dstJPL
init|=
name|dbpl
operator|/
literal|2
decl_stmt|;
name|quint16
modifier|*
name|dst
init|=
operator|(
name|quint16
operator|*
operator|)
name|destPixels
decl_stmt|;
name|quint16
modifier|*
name|dstEnd
init|=
name|dst
operator|+
name|dstJPL
operator|*
name|h
decl_stmt|;
name|int
name|dstExtraStride
init|=
name|dstJPL
operator|-
name|w
decl_stmt|;
while|while
condition|(
name|dst
operator|<
name|dstEnd
condition|)
block|{
specifier|const
name|quint32
modifier|*
name|srcEnd
init|=
name|src
operator|+
name|w
decl_stmt|;
while|while
condition|(
name|src
operator|<
name|srcEnd
condition|)
block|{
operator|*
name|dst
operator|=
name|qConvertRgb32To16
argument_list|(
operator|*
name|src
argument_list|)
expr_stmt|;
operator|++
name|dst
expr_stmt|;
operator|++
name|src
expr_stmt|;
block|}
name|dst
operator|+=
name|dstExtraStride
expr_stmt|;
name|src
operator|+=
name|srcExtraStride
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/************************************************************************                        RGB32 (-888) format target format  ************************************************************************/
end_comment
begin_function
DECL|function|qt_blend_argb32_on_argb32
specifier|static
name|void
name|qt_blend_argb32_on_argb32
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG_DRAW
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"qt_blend_argb32_on_argb32: dst=(%p, %d), src=(%p, %d), dim=(%d, %d) alpha=%d\n"
argument_list|,
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
specifier|const
name|uint
modifier|*
name|src
init|=
operator|(
specifier|const
name|uint
operator|*
operator|)
name|srcPixels
decl_stmt|;
name|uint
modifier|*
name|dst
init|=
operator|(
name|uint
operator|*
operator|)
name|destPixels
decl_stmt|;
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
name|uint
name|s
init|=
name|src
index|[
name|x
index|]
decl_stmt|;
if|if
condition|(
name|s
operator|>=
literal|0xff000000
condition|)
name|dst
index|[
name|x
index|]
operator|=
name|s
expr_stmt|;
elseif|else
if|if
condition|(
name|s
operator|!=
literal|0
condition|)
name|dst
index|[
name|x
index|]
operator|=
name|s
operator|+
name|BYTE_MUL
argument_list|(
name|dst
index|[
name|x
index|]
argument_list|,
name|qAlpha
argument_list|(
operator|~
name|s
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|dst
operator|=
operator|(
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|dst
operator|)
operator|+
name|dbpl
operator|)
expr_stmt|;
name|src
operator|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|src
operator|)
operator|+
name|sbpl
operator|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|const_alpha
operator|!=
literal|0
condition|)
block|{
name|const_alpha
operator|=
operator|(
name|const_alpha
operator|*
literal|255
operator|)
operator|>>
literal|8
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|w
condition|;
operator|++
name|x
control|)
block|{
name|uint
name|s
init|=
name|BYTE_MUL
argument_list|(
name|src
index|[
name|x
index|]
argument_list|,
name|const_alpha
argument_list|)
decl_stmt|;
name|dst
index|[
name|x
index|]
operator|=
name|s
operator|+
name|BYTE_MUL
argument_list|(
name|dst
index|[
name|x
index|]
argument_list|,
name|qAlpha
argument_list|(
operator|~
name|s
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|dst
operator|=
operator|(
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|dst
operator|)
operator|+
name|dbpl
operator|)
expr_stmt|;
name|src
operator|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|src
operator|)
operator|+
name|sbpl
operator|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|qt_blend_rgb32_on_rgb32
name|void
name|qt_blend_rgb32_on_rgb32
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG_DRAW
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"qt_blend_rgb32_on_rgb32: dst=(%p, %d), src=(%p, %d), dim=(%d, %d) alpha=%d\n"
argument_list|,
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|const_alpha
operator|!=
literal|256
condition|)
block|{
name|qt_blend_argb32_on_argb32
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|uint
modifier|*
name|src
init|=
operator|(
specifier|const
name|uint
operator|*
operator|)
name|srcPixels
decl_stmt|;
name|uint
modifier|*
name|dst
init|=
operator|(
name|uint
operator|*
operator|)
name|destPixels
decl_stmt|;
name|int
name|len
init|=
name|w
operator|*
literal|4
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|dst
operator|=
operator|(
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
name|uchar
operator|*
operator|)
name|dst
operator|)
operator|+
name|dbpl
operator|)
expr_stmt|;
name|src
operator|=
operator|(
specifier|const
name|quint32
operator|*
operator|)
operator|(
operator|(
operator|(
specifier|const
name|uchar
operator|*
operator|)
name|src
operator|)
operator|+
name|sbpl
operator|)
expr_stmt|;
block|}
block|}
end_function
begin_struct
DECL|struct|Blend_RGB32_on_RGB32_NoAlpha
struct|struct
name|Blend_RGB32_on_RGB32_NoAlpha
block|{
DECL|function|write
specifier|inline
name|void
name|write
parameter_list|(
name|quint32
modifier|*
name|dst
parameter_list|,
name|quint32
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|src
expr_stmt|;
block|}
DECL|function|flush
specifier|inline
name|void
name|flush
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
block|}
struct|;
end_struct
begin_struct
DECL|struct|Blend_RGB32_on_RGB32_ConstAlpha
struct|struct
name|Blend_RGB32_on_RGB32_ConstAlpha
block|{
DECL|function|Blend_RGB32_on_RGB32_ConstAlpha
specifier|inline
name|Blend_RGB32_on_RGB32_ConstAlpha
parameter_list|(
name|quint32
name|alpha
parameter_list|)
block|{
name|m_alpha
operator|=
operator|(
name|alpha
operator|*
literal|255
operator|)
operator|>>
literal|8
expr_stmt|;
name|m_ialpha
operator|=
literal|255
operator|-
name|m_alpha
expr_stmt|;
block|}
DECL|function|write
specifier|inline
name|void
name|write
parameter_list|(
name|quint32
modifier|*
name|dst
parameter_list|,
name|quint32
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|BYTE_MUL
argument_list|(
name|src
argument_list|,
name|m_alpha
argument_list|)
operator|+
name|BYTE_MUL
argument_list|(
operator|*
name|dst
argument_list|,
name|m_ialpha
argument_list|)
expr_stmt|;
block|}
DECL|function|flush
specifier|inline
name|void
name|flush
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
DECL|member|m_alpha
name|quint32
name|m_alpha
decl_stmt|;
DECL|member|m_ialpha
name|quint32
name|m_ialpha
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|Blend_ARGB32_on_ARGB32_SourceAlpha
struct|struct
name|Blend_ARGB32_on_ARGB32_SourceAlpha
block|{
DECL|function|write
specifier|inline
name|void
name|write
parameter_list|(
name|quint32
modifier|*
name|dst
parameter_list|,
name|quint32
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|src
operator|+
name|BYTE_MUL
argument_list|(
operator|*
name|dst
argument_list|,
name|qAlpha
argument_list|(
operator|~
name|src
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|flush
specifier|inline
name|void
name|flush
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
block|}
struct|;
end_struct
begin_struct
DECL|struct|Blend_ARGB32_on_ARGB32_SourceAndConstAlpha
struct|struct
name|Blend_ARGB32_on_ARGB32_SourceAndConstAlpha
block|{
DECL|function|Blend_ARGB32_on_ARGB32_SourceAndConstAlpha
specifier|inline
name|Blend_ARGB32_on_ARGB32_SourceAndConstAlpha
parameter_list|(
name|quint32
name|alpha
parameter_list|)
block|{
name|m_alpha
operator|=
operator|(
name|alpha
operator|*
literal|255
operator|)
operator|>>
literal|8
expr_stmt|;
name|m_ialpha
operator|=
literal|255
operator|-
name|m_alpha
expr_stmt|;
block|}
DECL|function|write
specifier|inline
name|void
name|write
parameter_list|(
name|quint32
modifier|*
name|dst
parameter_list|,
name|quint32
name|src
parameter_list|)
block|{
name|src
operator|=
name|BYTE_MUL
argument_list|(
name|src
argument_list|,
name|m_alpha
argument_list|)
expr_stmt|;
operator|*
name|dst
operator|=
name|src
operator|+
name|BYTE_MUL
argument_list|(
operator|*
name|dst
argument_list|,
name|qAlpha
argument_list|(
operator|~
name|src
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|flush
specifier|inline
name|void
name|flush
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
DECL|member|m_alpha
name|quint32
name|m_alpha
decl_stmt|;
DECL|member|m_ialpha
name|quint32
name|m_ialpha
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|qt_scale_image_rgb32_on_rgb32
name|void
name|qt_scale_image_rgb32_on_rgb32
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sourceRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|clip
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG_DRAW
name|printf
argument_list|(
literal|"qt_scale_rgb32_on_rgb32: dst=(%p, %d), src=(%p, %d), target=(%d, %d), [%d x %d], src=(%d, %d) [%d x %d] alpha=%d\n"
argument_list|,
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
operator|.
name|x
argument_list|()
argument_list|,
name|targetRect
operator|.
name|y
argument_list|()
argument_list|,
name|targetRect
operator|.
name|width
argument_list|()
argument_list|,
name|targetRect
operator|.
name|height
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|x
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|y
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|width
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|height
argument_list|()
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
name|Blend_RGB32_on_RGB32_NoAlpha
name|noAlpha
decl_stmt|;
name|qt_scale_image_32bit
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|noAlpha
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Blend_RGB32_on_RGB32_ConstAlpha
name|constAlpha
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
name|qt_scale_image_32bit
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|constAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_scale_image_argb32_on_argb32
name|void
name|qt_scale_image_argb32_on_argb32
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sourceRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|clip
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_DEBUG_DRAW
name|printf
argument_list|(
literal|"qt_scale_argb32_on_argb32: dst=(%p, %d), src=(%p, %d), target=(%d, %d), [%d x %d], src=(%d, %d) [%d x %d] alpha=%d\n"
argument_list|,
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
operator|.
name|x
argument_list|()
argument_list|,
name|targetRect
operator|.
name|y
argument_list|()
argument_list|,
name|targetRect
operator|.
name|width
argument_list|()
argument_list|,
name|targetRect
operator|.
name|height
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|x
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|y
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|width
argument_list|()
argument_list|,
name|sourceRect
operator|.
name|height
argument_list|()
argument_list|,
name|const_alpha
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
name|Blend_ARGB32_on_ARGB32_SourceAlpha
name|sourceAlpha
decl_stmt|;
name|qt_scale_image_32bit
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|sourceAlpha
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Blend_ARGB32_on_ARGB32_SourceAndConstAlpha
name|constAlpha
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
name|qt_scale_image_32bit
argument_list|(
name|destPixels
argument_list|,
name|dbpl
argument_list|,
name|srcPixels
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|constAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_transform_image_rgb16_on_rgb16
name|void
name|qt_transform_image_rgb16_on_rgb16
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sourceRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|clip
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|targetRectTransform
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
name|Blend_RGB16_on_RGB16_NoAlpha
name|noAlpha
decl_stmt|;
name|qt_transform_image
argument_list|(
cast|reinterpret_cast
argument_list|<
name|quint16
operator|*
argument_list|>
argument_list|(
name|destPixels
argument_list|)
argument_list|,
name|dbpl
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint16
operator|*
argument_list|>
argument_list|(
name|srcPixels
argument_list|)
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|targetRectTransform
argument_list|,
name|noAlpha
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Blend_RGB16_on_RGB16_ConstAlpha
name|constAlpha
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
name|qt_transform_image
argument_list|(
cast|reinterpret_cast
argument_list|<
name|quint16
operator|*
argument_list|>
argument_list|(
name|destPixels
argument_list|)
argument_list|,
name|dbpl
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint16
operator|*
argument_list|>
argument_list|(
name|srcPixels
argument_list|)
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|targetRectTransform
argument_list|,
name|constAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_transform_image_argb32_on_rgb16
name|void
name|qt_transform_image_argb32_on_rgb16
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sourceRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|clip
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|targetRectTransform
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
name|Blend_ARGB32_on_RGB16_SourceAlpha
name|noAlpha
decl_stmt|;
name|qt_transform_image
argument_list|(
cast|reinterpret_cast
argument_list|<
name|quint16
operator|*
argument_list|>
argument_list|(
name|destPixels
argument_list|)
argument_list|,
name|dbpl
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint32
operator|*
argument_list|>
argument_list|(
name|srcPixels
argument_list|)
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|targetRectTransform
argument_list|,
name|noAlpha
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Blend_ARGB32_on_RGB16_SourceAndConstAlpha
name|constAlpha
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
name|qt_transform_image
argument_list|(
cast|reinterpret_cast
argument_list|<
name|quint16
operator|*
argument_list|>
argument_list|(
name|destPixels
argument_list|)
argument_list|,
name|dbpl
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint32
operator|*
argument_list|>
argument_list|(
name|srcPixels
argument_list|)
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|targetRectTransform
argument_list|,
name|constAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_transform_image_rgb32_on_rgb32
name|void
name|qt_transform_image_rgb32_on_rgb32
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sourceRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|clip
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|targetRectTransform
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
name|Blend_RGB32_on_RGB32_NoAlpha
name|noAlpha
decl_stmt|;
name|qt_transform_image
argument_list|(
cast|reinterpret_cast
argument_list|<
name|quint32
operator|*
argument_list|>
argument_list|(
name|destPixels
argument_list|)
argument_list|,
name|dbpl
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint32
operator|*
argument_list|>
argument_list|(
name|srcPixels
argument_list|)
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|targetRectTransform
argument_list|,
name|noAlpha
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Blend_RGB32_on_RGB32_ConstAlpha
name|constAlpha
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
name|qt_transform_image
argument_list|(
cast|reinterpret_cast
argument_list|<
name|quint32
operator|*
argument_list|>
argument_list|(
name|destPixels
argument_list|)
argument_list|,
name|dbpl
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint32
operator|*
argument_list|>
argument_list|(
name|srcPixels
argument_list|)
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|targetRectTransform
argument_list|,
name|constAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_transform_image_argb32_on_argb32
name|void
name|qt_transform_image_argb32_on_argb32
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|targetRect
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|sourceRect
parameter_list|,
specifier|const
name|QRect
modifier|&
name|clip
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|targetRectTransform
parameter_list|,
name|int
name|const_alpha
parameter_list|)
block|{
if|if
condition|(
name|const_alpha
operator|==
literal|256
condition|)
block|{
name|Blend_ARGB32_on_ARGB32_SourceAlpha
name|sourceAlpha
decl_stmt|;
name|qt_transform_image
argument_list|(
cast|reinterpret_cast
argument_list|<
name|quint32
operator|*
argument_list|>
argument_list|(
name|destPixels
argument_list|)
argument_list|,
name|dbpl
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint32
operator|*
argument_list|>
argument_list|(
name|srcPixels
argument_list|)
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|targetRectTransform
argument_list|,
name|sourceAlpha
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Blend_ARGB32_on_ARGB32_SourceAndConstAlpha
name|constAlpha
argument_list|(
name|const_alpha
argument_list|)
decl_stmt|;
name|qt_transform_image
argument_list|(
cast|reinterpret_cast
argument_list|<
name|quint32
operator|*
argument_list|>
argument_list|(
name|destPixels
argument_list|)
argument_list|,
name|dbpl
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|quint32
operator|*
argument_list|>
argument_list|(
name|srcPixels
argument_list|)
argument_list|,
name|sbpl
argument_list|,
name|targetRect
argument_list|,
name|sourceRect
argument_list|,
name|clip
argument_list|,
name|targetRectTransform
argument_list|,
name|constAlpha
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|qScaleFunctions
name|SrcOverScaleFunc
name|qScaleFunctions
index|[
name|QImage
operator|::
name|NImageFormats
index|]
index|[
name|QImage
operator|::
name|NImageFormats
index|]
init|=
block|{
block|{
comment|// Format_Invalid
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_Mono
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_MonoLSB
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_Indexed8
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB32
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
name|qt_scale_image_rgb32_on_rgb32
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_scale_image_argb32_on_argb32
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB32
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB32_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
name|qt_scale_image_rgb32_on_rgb32
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_scale_image_argb32_on_argb32
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB16
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_scale_image_argb32_on_rgb16
block|,
comment|// Format_ARGB32_Premultiplied,
name|qt_scale_image_rgb16_on_rgb16
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB8565_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB666
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB6666_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB555
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB8555_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB444
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB4444_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGBX8888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
name|qt_scale_image_rgb32_on_rgb32
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
name|qt_scale_image_argb32_on_argb32
block|,
comment|// Format_RGBA8888_Premultiplied,
else|#
directive|else
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
endif|#
directive|endif
block|}
block|,
block|{
comment|// Format_RGBA8888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGBA8888_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
name|qt_scale_image_rgb32_on_rgb32
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
name|qt_scale_image_argb32_on_argb32
block|,
comment|// Format_RGBA8888_Premultiplied,
else|#
directive|else
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
endif|#
directive|endif
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qBlendFunctions
name|SrcOverBlendFunc
name|qBlendFunctions
index|[
name|QImage
operator|::
name|NImageFormats
index|]
index|[
name|QImage
operator|::
name|NImageFormats
index|]
init|=
block|{
block|{
comment|// Format_Invalid
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_Mono
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_MonoLSB
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_Indexed8
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB32
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
name|qt_blend_rgb32_on_rgb32
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_blend_argb32_on_argb32
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB32
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB32_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
name|qt_blend_rgb32_on_rgb32
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_blend_argb32_on_argb32
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB16
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
name|qt_blend_rgb32_on_rgb16
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_blend_argb32_on_rgb16
block|,
comment|// Format_ARGB32_Premultiplied,
name|qt_blend_rgb16_on_rgb16
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB8565_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB666
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB6666_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB555
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB8555_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB444
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB4444_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGBX8888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
name|qt_blend_rgb32_on_rgb32
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
name|qt_blend_argb32_on_argb32
block|,
comment|// Format_RGBA8888_Premultiplied,
else|#
directive|else
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
endif|#
directive|endif
block|}
block|,
block|{
comment|// Format_RGBA8888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGBA8888_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
name|qt_blend_rgb32_on_rgb32
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
name|qt_blend_argb32_on_argb32
block|,
comment|// Format_RGBA8888_Premultiplied,
else|#
directive|else
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
endif|#
directive|endif
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qTransformFunctions
name|SrcOverTransformFunc
name|qTransformFunctions
index|[
name|QImage
operator|::
name|NImageFormats
index|]
index|[
name|QImage
operator|::
name|NImageFormats
index|]
init|=
block|{
block|{
comment|// Format_Invalid
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_Mono
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_MonoLSB
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_Indexed8
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB32
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
name|qt_transform_image_rgb32_on_rgb32
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_transform_image_argb32_on_argb32
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB32
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB32_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
name|qt_transform_image_rgb32_on_rgb32
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_transform_image_argb32_on_argb32
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB16
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
name|qt_transform_image_argb32_on_rgb16
block|,
comment|// Format_ARGB32_Premultiplied,
name|qt_transform_image_rgb16_on_rgb16
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB8565_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB666
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB6666_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB555
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB8555_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGB444
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_ARGB4444_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGBX8888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
name|qt_transform_image_rgb32_on_rgb32
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
name|qt_transform_image_argb32_on_argb32
block|,
comment|// Format_RGBA8888_Premultiplied,
else|#
directive|else
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
endif|#
directive|endif
block|}
block|,
block|{
comment|// Format_RGBA8888
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
block|}
block|,
block|{
comment|// Format_RGBA8888_Premultiplied
literal|0
block|,
comment|// Format_Invalid,
literal|0
block|,
comment|// Format_Mono,
literal|0
block|,
comment|// Format_MonoLSB,
literal|0
block|,
comment|// Format_Indexed8,
literal|0
block|,
comment|// Format_RGB32,
literal|0
block|,
comment|// Format_ARGB32,
literal|0
block|,
comment|// Format_ARGB32_Premultiplied,
literal|0
block|,
comment|// Format_RGB16,
literal|0
block|,
comment|// Format_ARGB8565_Premultiplied,
literal|0
block|,
comment|// Format_RGB666,
literal|0
block|,
comment|// Format_ARGB6666_Premultiplied,
literal|0
block|,
comment|// Format_RGB555,
literal|0
block|,
comment|// Format_ARGB8555_Premultiplied,
literal|0
block|,
comment|// Format_RGB888,
literal|0
block|,
comment|// Format_RGB444,
literal|0
block|,
comment|// Format_ARGB4444_Premultiplied,
if|#
directive|if
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
name|qt_transform_image_rgb32_on_rgb32
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
name|qt_transform_image_argb32_on_argb32
block|,
comment|// Format_RGBA8888_Premultiplied,
else|#
directive|else
literal|0
block|,
comment|// Format_RGBX8888,
literal|0
block|,
comment|// Format_RGBA8888,
literal|0
comment|// Format_RGBA8888_Premultiplied,
endif|#
directive|endif
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
