begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLOR_H
end_ifndef
begin_define
DECL|macro|QCOLOR_H
define|#
directive|define
name|QCOLOR_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qrgb.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColormap
name|class
name|QColormap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QColor
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QColor
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QColor
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QColor
block|{
name|public
label|:
enum|enum
name|Spec
block|{
name|Invalid
block|,
name|Rgb
block|,
name|Hsv
block|,
name|Cmyk
block|,
name|Hsl
block|}
enum|;
name|QColor
argument_list|()
expr_stmt|;
name|QColor
argument_list|(
argument|Qt::GlobalColor color
argument_list|)
empty_stmt|;
name|QColor
argument_list|(
argument|int r
argument_list|,
argument|int g
argument_list|,
argument|int b
argument_list|,
argument|int a =
literal|255
argument_list|)
empty_stmt|;
name|QColor
argument_list|(
argument|QRgb rgb
argument_list|)
empty_stmt|;
name|QColor
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
expr_stmt|;
name|QColor
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
name|QColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
expr_stmt|;
name|QColor
argument_list|(
argument|Spec spec
argument_list|)
empty_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setNamedColor
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|colorNames
parameter_list|()
function_decl|;
specifier|inline
name|Spec
name|spec
argument_list|()
specifier|const
block|{
return|return
name|cspec
return|;
block|}
name|int
name|alpha
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAlpha
parameter_list|(
name|int
name|alpha
parameter_list|)
function_decl|;
name|qreal
name|alphaF
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAlphaF
parameter_list|(
name|qreal
name|alpha
parameter_list|)
function_decl|;
name|int
name|red
argument_list|()
specifier|const
expr_stmt|;
name|int
name|green
argument_list|()
specifier|const
expr_stmt|;
name|int
name|blue
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRed
parameter_list|(
name|int
name|red
parameter_list|)
function_decl|;
name|void
name|setGreen
parameter_list|(
name|int
name|green
parameter_list|)
function_decl|;
name|void
name|setBlue
parameter_list|(
name|int
name|blue
parameter_list|)
function_decl|;
name|qreal
name|redF
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|greenF
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|blueF
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRedF
parameter_list|(
name|qreal
name|red
parameter_list|)
function_decl|;
name|void
name|setGreenF
parameter_list|(
name|qreal
name|green
parameter_list|)
function_decl|;
name|void
name|setBlueF
parameter_list|(
name|qreal
name|blue
parameter_list|)
function_decl|;
name|void
name|getRgb
argument_list|(
name|int
operator|*
name|r
argument_list|,
name|int
operator|*
name|g
argument_list|,
name|int
operator|*
name|b
argument_list|,
name|int
operator|*
name|a
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|setRgb
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
init|=
literal|255
parameter_list|)
function_decl|;
name|void
name|getRgbF
argument_list|(
name|qreal
operator|*
name|r
argument_list|,
name|qreal
operator|*
name|g
argument_list|,
name|qreal
operator|*
name|b
argument_list|,
name|qreal
operator|*
name|a
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|setRgbF
parameter_list|(
name|qreal
name|r
parameter_list|,
name|qreal
name|g
parameter_list|,
name|qreal
name|b
parameter_list|,
name|qreal
name|a
init|=
literal|1.0
parameter_list|)
function_decl|;
name|QRgb
name|rgba
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRgba
parameter_list|(
name|QRgb
name|rgba
parameter_list|)
function_decl|;
name|QRgb
name|rgb
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRgb
parameter_list|(
name|QRgb
name|rgb
parameter_list|)
function_decl|;
name|int
name|hue
argument_list|()
specifier|const
expr_stmt|;
comment|// 0<= hue< 360
name|int
name|saturation
argument_list|()
specifier|const
expr_stmt|;
name|int
name|hsvHue
argument_list|()
specifier|const
expr_stmt|;
comment|// 0<= hue< 360
name|int
name|hsvSaturation
argument_list|()
specifier|const
expr_stmt|;
name|int
name|value
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|hueF
argument_list|()
specifier|const
expr_stmt|;
comment|// 0.0<= hueF< 360.0
name|qreal
name|saturationF
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|hsvHueF
argument_list|()
specifier|const
expr_stmt|;
comment|// 0.0<= hueF< 360.0
name|qreal
name|hsvSaturationF
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|valueF
argument_list|()
specifier|const
expr_stmt|;
name|void
name|getHsv
argument_list|(
name|int
operator|*
name|h
argument_list|,
name|int
operator|*
name|s
argument_list|,
name|int
operator|*
name|v
argument_list|,
name|int
operator|*
name|a
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|setHsv
parameter_list|(
name|int
name|h
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|v
parameter_list|,
name|int
name|a
init|=
literal|255
parameter_list|)
function_decl|;
name|void
name|getHsvF
argument_list|(
name|qreal
operator|*
name|h
argument_list|,
name|qreal
operator|*
name|s
argument_list|,
name|qreal
operator|*
name|v
argument_list|,
name|qreal
operator|*
name|a
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|setHsvF
parameter_list|(
name|qreal
name|h
parameter_list|,
name|qreal
name|s
parameter_list|,
name|qreal
name|v
parameter_list|,
name|qreal
name|a
init|=
literal|1.0
parameter_list|)
function_decl|;
name|int
name|cyan
argument_list|()
specifier|const
expr_stmt|;
name|int
name|magenta
argument_list|()
specifier|const
expr_stmt|;
name|int
name|yellow
argument_list|()
specifier|const
expr_stmt|;
name|int
name|black
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|cyanF
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|magentaF
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|yellowF
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|blackF
argument_list|()
specifier|const
expr_stmt|;
name|void
name|getCmyk
parameter_list|(
name|int
modifier|*
name|c
parameter_list|,
name|int
modifier|*
name|m
parameter_list|,
name|int
modifier|*
name|y
parameter_list|,
name|int
modifier|*
name|k
parameter_list|,
name|int
modifier|*
name|a
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setCmyk
parameter_list|(
name|int
name|c
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|k
parameter_list|,
name|int
name|a
init|=
literal|255
parameter_list|)
function_decl|;
name|void
name|getCmykF
parameter_list|(
name|qreal
modifier|*
name|c
parameter_list|,
name|qreal
modifier|*
name|m
parameter_list|,
name|qreal
modifier|*
name|y
parameter_list|,
name|qreal
modifier|*
name|k
parameter_list|,
name|qreal
modifier|*
name|a
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setCmykF
parameter_list|(
name|qreal
name|c
parameter_list|,
name|qreal
name|m
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|k
parameter_list|,
name|qreal
name|a
init|=
literal|1.0
parameter_list|)
function_decl|;
name|int
name|hslHue
argument_list|()
specifier|const
expr_stmt|;
comment|// 0<= hue< 360
name|int
name|hslSaturation
argument_list|()
specifier|const
expr_stmt|;
name|int
name|lightness
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|hslHueF
argument_list|()
specifier|const
expr_stmt|;
comment|// 0.0<= hueF< 360.0
name|qreal
name|hslSaturationF
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|lightnessF
argument_list|()
specifier|const
expr_stmt|;
name|void
name|getHsl
argument_list|(
name|int
operator|*
name|h
argument_list|,
name|int
operator|*
name|s
argument_list|,
name|int
operator|*
name|l
argument_list|,
name|int
operator|*
name|a
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|setHsl
parameter_list|(
name|int
name|h
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|l
parameter_list|,
name|int
name|a
init|=
literal|255
parameter_list|)
function_decl|;
name|void
name|getHslF
argument_list|(
name|qreal
operator|*
name|h
argument_list|,
name|qreal
operator|*
name|s
argument_list|,
name|qreal
operator|*
name|l
argument_list|,
name|qreal
operator|*
name|a
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|void
name|setHslF
parameter_list|(
name|qreal
name|h
parameter_list|,
name|qreal
name|s
parameter_list|,
name|qreal
name|l
parameter_list|,
name|qreal
name|a
init|=
literal|1.0
parameter_list|)
function_decl|;
name|QColor
name|toRgb
argument_list|()
specifier|const
expr_stmt|;
name|QColor
name|toHsv
argument_list|()
specifier|const
expr_stmt|;
name|QColor
name|toCmyk
argument_list|()
specifier|const
expr_stmt|;
name|QColor
name|toHsl
argument_list|()
specifier|const
expr_stmt|;
name|QColor
name|convertTo
argument_list|(
name|Spec
name|colorSpec
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QColor
name|fromRgb
parameter_list|(
name|QRgb
name|rgb
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromRgba
parameter_list|(
name|QRgb
name|rgba
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromRgb
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
init|=
literal|255
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromRgbF
parameter_list|(
name|qreal
name|r
parameter_list|,
name|qreal
name|g
parameter_list|,
name|qreal
name|b
parameter_list|,
name|qreal
name|a
init|=
literal|1.0
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromHsv
parameter_list|(
name|int
name|h
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|v
parameter_list|,
name|int
name|a
init|=
literal|255
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromHsvF
parameter_list|(
name|qreal
name|h
parameter_list|,
name|qreal
name|s
parameter_list|,
name|qreal
name|v
parameter_list|,
name|qreal
name|a
init|=
literal|1.0
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromCmyk
parameter_list|(
name|int
name|c
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|k
parameter_list|,
name|int
name|a
init|=
literal|255
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromCmykF
parameter_list|(
name|qreal
name|c
parameter_list|,
name|qreal
name|m
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|k
parameter_list|,
name|qreal
name|a
init|=
literal|1.0
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromHsl
parameter_list|(
name|int
name|h
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|l
parameter_list|,
name|int
name|a
init|=
literal|255
parameter_list|)
function_decl|;
specifier|static
name|QColor
name|fromHslF
parameter_list|(
name|qreal
name|h
parameter_list|,
name|qreal
name|s
parameter_list|,
name|qreal
name|l
parameter_list|,
name|qreal
name|a
init|=
literal|1.0
parameter_list|)
function_decl|;
name|QColor
name|light
argument_list|(
name|int
name|f
operator|=
literal|150
argument_list|)
decl|const
decl_stmt|;
name|QColor
name|lighter
argument_list|(
name|int
name|f
operator|=
literal|150
argument_list|)
decl|const
decl_stmt|;
name|QColor
name|dark
argument_list|(
name|int
name|f
operator|=
literal|200
argument_list|)
decl|const
decl_stmt|;
name|QColor
name|darker
argument_list|(
name|int
name|f
operator|=
literal|200
argument_list|)
decl|const
decl_stmt|;
name|QColor
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QColor
operator|&
operator|)
decl_stmt|;
name|QColor
modifier|&
name|operator
init|=
operator|(
name|Qt
operator|::
name|GlobalColor
name|color
operator|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QColor
operator|&
name|c
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QColor
operator|&
name|c
operator|)
specifier|const
expr_stmt|;
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|isValidColor
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|invalidate
parameter_list|()
function_decl|;
name|bool
name|setColorFromString
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|Spec
name|cspec
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|ushort
name|alpha
decl_stmt|;
name|ushort
name|red
decl_stmt|;
name|ushort
name|green
decl_stmt|;
name|ushort
name|blue
decl_stmt|;
name|ushort
name|pad
decl_stmt|;
block|}
name|argb
struct|;
struct|struct
block|{
name|ushort
name|alpha
decl_stmt|;
name|ushort
name|hue
decl_stmt|;
name|ushort
name|saturation
decl_stmt|;
name|ushort
name|value
decl_stmt|;
name|ushort
name|pad
decl_stmt|;
block|}
name|ahsv
struct|;
struct|struct
block|{
name|ushort
name|alpha
decl_stmt|;
name|ushort
name|cyan
decl_stmt|;
name|ushort
name|magenta
decl_stmt|;
name|ushort
name|yellow
decl_stmt|;
name|ushort
name|black
decl_stmt|;
block|}
name|acmyk
struct|;
struct|struct
block|{
name|ushort
name|alpha
decl_stmt|;
name|ushort
name|hue
decl_stmt|;
name|ushort
name|saturation
decl_stmt|;
name|ushort
name|lightness
decl_stmt|;
name|ushort
name|pad
decl_stmt|;
block|}
name|ahsl
struct|;
name|ushort
name|array
index|[
literal|5
index|]
decl_stmt|;
block|}
name|ct
union|;
name|friend
name|class
name|QColormap
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QColor
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QColor
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|QColor
specifier|inline
name|QColor
operator|::
name|QColor
argument_list|()
block|{
name|invalidate
argument_list|()
block|; }
DECL|function|QColor
specifier|inline
name|QColor
operator|::
name|QColor
argument_list|(
argument|int r
argument_list|,
argument|int g
argument_list|,
argument|int b
argument_list|,
argument|int a
argument_list|)
block|{
name|setRgb
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|,
name|a
argument_list|)
block|; }
DECL|function|QColor
specifier|inline
name|QColor
operator|::
name|QColor
argument_list|(
argument|const char *aname
argument_list|)
block|{
name|setNamedColor
argument_list|(
name|QLatin1String
argument_list|(
name|aname
argument_list|)
argument_list|)
block|; }
DECL|function|QColor
specifier|inline
name|QColor
operator|::
name|QColor
argument_list|(
argument|const QString& aname
argument_list|)
block|{
name|setNamedColor
argument_list|(
name|aname
argument_list|)
block|; }
DECL|function|QColor
specifier|inline
name|QColor
operator|::
name|QColor
argument_list|(
specifier|const
name|QColor
operator|&
name|acolor
argument_list|)
operator|:
name|cspec
argument_list|(
argument|acolor.cspec
argument_list|)
block|{
name|ct
operator|.
name|argb
operator|=
name|acolor
operator|.
name|ct
operator|.
name|argb
block|; }
DECL|function|isValid
specifier|inline
name|bool
name|QColor
operator|::
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|cspec
operator|!=
name|Invalid
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|lighter
specifier|inline
name|QColor
name|QColor
operator|::
name|lighter
argument_list|(
argument|int f
argument_list|)
specifier|const
block|{
return|return
name|light
argument_list|(
name|f
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|darker
specifier|inline
name|QColor
name|QColor
operator|::
name|darker
argument_list|(
argument|int f
argument_list|)
specifier|const
block|{
return|return
name|dark
argument_list|(
name|f
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOLOR_H
end_comment
end_unit
