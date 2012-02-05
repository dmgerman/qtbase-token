begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRGB_H
end_ifndef
begin_define
DECL|macro|QRGB_H
define|#
directive|define
name|QRGB_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
end_expr_stmt
begin_typedef
DECL|typedef|QRgb
typedef|typedef
name|unsigned
name|int
name|QRgb
typedef|;
end_typedef
begin_comment
DECL|typedef|QRgb
comment|// RGB triplet
end_comment
begin_decl_stmt
DECL|variable|RGB_MASK
specifier|const
name|QRgb
name|RGB_MASK
init|=
literal|0x00ffffff
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|RGB_MASK
comment|// masks RGB values
end_comment
begin_function
DECL|function|qRed
name|Q_GUI_EXPORT_INLINE
name|int
name|qRed
parameter_list|(
name|QRgb
name|rgb
parameter_list|)
comment|// get red part of RGB
block|{
return|return
operator|(
operator|(
name|rgb
operator|>>
literal|16
operator|)
operator|&
literal|0xff
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qGreen
name|Q_GUI_EXPORT_INLINE
name|int
name|qGreen
parameter_list|(
name|QRgb
name|rgb
parameter_list|)
comment|// get green part of RGB
block|{
return|return
operator|(
operator|(
name|rgb
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qBlue
name|Q_GUI_EXPORT_INLINE
name|int
name|qBlue
parameter_list|(
name|QRgb
name|rgb
parameter_list|)
comment|// get blue part of RGB
block|{
return|return
operator|(
name|rgb
operator|&
literal|0xff
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qAlpha
name|Q_GUI_EXPORT_INLINE
name|int
name|qAlpha
parameter_list|(
name|QRgb
name|rgb
parameter_list|)
comment|// get alpha part of RGBA
block|{
return|return
name|rgb
operator|>>
literal|24
return|;
block|}
end_function
begin_function
DECL|function|qRgb
name|Q_GUI_EXPORT_INLINE
name|QRgb
name|qRgb
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|g
parameter_list|,
name|int
name|b
parameter_list|)
comment|// set RGB value
block|{
return|return
operator|(
literal|0xffu
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|r
operator|&
literal|0xff
operator|)
operator|<<
literal|16
operator|)
operator||
operator|(
operator|(
name|g
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
name|b
operator|&
literal|0xff
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qRgba
name|Q_GUI_EXPORT_INLINE
name|QRgb
name|qRgba
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|g
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|a
parameter_list|)
comment|// set RGBA value
block|{
return|return
operator|(
operator|(
name|a
operator|&
literal|0xff
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|r
operator|&
literal|0xff
operator|)
operator|<<
literal|16
operator|)
operator||
operator|(
operator|(
name|g
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
name|b
operator|&
literal|0xff
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qGray
name|Q_GUI_EXPORT_INLINE
name|int
name|qGray
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|g
parameter_list|,
name|int
name|b
parameter_list|)
comment|// convert R,G,B to gray 0..255
block|{
return|return
operator|(
name|r
operator|*
literal|11
operator|+
name|g
operator|*
literal|16
operator|+
name|b
operator|*
literal|5
operator|)
operator|/
literal|32
return|;
block|}
end_function
begin_function
DECL|function|qGray
name|Q_GUI_EXPORT_INLINE
name|int
name|qGray
parameter_list|(
name|QRgb
name|rgb
parameter_list|)
comment|// convert RGB to gray 0..255
block|{
return|return
name|qGray
argument_list|(
name|qRed
argument_list|(
name|rgb
argument_list|)
argument_list|,
name|qGreen
argument_list|(
name|rgb
argument_list|)
argument_list|,
name|qBlue
argument_list|(
name|rgb
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qIsGray
name|Q_GUI_EXPORT_INLINE
name|bool
name|qIsGray
parameter_list|(
name|QRgb
name|rgb
parameter_list|)
block|{
return|return
name|qRed
argument_list|(
name|rgb
argument_list|)
operator|==
name|qGreen
argument_list|(
name|rgb
argument_list|)
operator|&&
name|qRed
argument_list|(
name|rgb
argument_list|)
operator|==
name|qBlue
argument_list|(
name|rgb
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QRGB_H
end_comment
end_unit
