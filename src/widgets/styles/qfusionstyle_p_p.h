begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUSIONSTYLE_P_P_H
end_ifndef
begin_define
DECL|macro|QFUSIONSTYLE_P_P_H
define|#
directive|define
name|QFUSIONSTYLE_P_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
file|"qcommonstyle.h"
end_include
begin_include
include|#
directive|include
file|"qcommonstyle_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|"private/qguiapplication_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_FUSION
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFusionStylePrivate
range|:
name|public
name|QCommonStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFusionStyle
argument_list|)
name|public
operator|:
name|QFusionStylePrivate
argument_list|()
block|;
comment|// Used for grip handles
name|QColor
name|lightShade
argument_list|()
specifier|const
block|{
return|return
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|90
argument_list|)
return|;
block|}
name|QColor
name|darkShade
argument_list|()
specifier|const
block|{
return|return
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|60
argument_list|)
return|;
block|}
name|QColor
name|topShadow
argument_list|()
specifier|const
block|{
return|return
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|18
argument_list|)
return|;
block|}
name|QColor
name|innerContrastLine
argument_list|()
specifier|const
block|{
return|return
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|30
argument_list|)
return|;
block|}
comment|// On mac we want a standard blue color used when the system palette is used
name|bool
name|isMacSystemPalette
argument_list|(
argument|const QPalette&pal
argument_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|pal
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MACX
argument_list|)
specifier|const
name|QPalette
operator|*
name|themePalette
operator|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|palette
argument_list|()
block|;
if|if
condition|(
name|themePalette
operator|&&
name|themePalette
operator|->
name|color
argument_list|(
name|QPalette
operator|::
name|Normal
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|)
operator|==
name|pal
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Normal
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|)
operator|&&
name|themePalette
operator|->
name|color
argument_list|(
name|QPalette
operator|::
name|Normal
argument_list|,
name|QPalette
operator|::
name|HighlightedText
argument_list|)
operator|==
name|pal
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Normal
argument_list|,
name|QPalette
operator|::
name|HighlightedText
argument_list|)
condition|)
return|return
name|true
return|;
endif|#
directive|endif
return|return
name|false
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QColor
name|highlight
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
decl|const
block|{
if|if
condition|(
name|isMacSystemPalette
argument_list|(
name|pal
argument_list|)
condition|)
return|return
name|QColor
argument_list|(
literal|60
argument_list|,
literal|140
argument_list|,
literal|230
argument_list|)
return|;
return|return
name|pal
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Highlight
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QColor
name|highlightedText
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
decl|const
block|{
if|if
condition|(
name|isMacSystemPalette
argument_list|(
name|pal
argument_list|)
condition|)
return|return
name|Qt
operator|::
name|white
return|;
return|return
name|pal
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|HighlightedText
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QColor
name|outline
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
decl|const
block|{
if|if
condition|(
name|pal
operator|.
name|window
argument_list|()
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|TexturePattern
condition|)
return|return
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|160
argument_list|)
return|;
return|return
name|pal
operator|.
name|background
argument_list|()
operator|.
name|color
argument_list|()
operator|.
name|darker
argument_list|(
literal|140
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QColor
name|highlightedOutline
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
decl|const
block|{
name|QColor
name|highlightedOutline
init|=
name|highlight
argument_list|(
name|pal
argument_list|)
operator|.
name|darker
argument_list|(
literal|125
argument_list|)
decl_stmt|;
if|if
condition|(
name|highlightedOutline
operator|.
name|value
argument_list|()
operator|>
literal|160
condition|)
name|highlightedOutline
operator|.
name|setHsl
argument_list|(
name|highlightedOutline
operator|.
name|hue
argument_list|()
argument_list|,
name|highlightedOutline
operator|.
name|saturation
argument_list|()
argument_list|,
literal|160
argument_list|)
expr_stmt|;
return|return
name|highlightedOutline
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QColor
name|tabFrameColor
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
decl|const
block|{
if|if
condition|(
name|pal
operator|.
name|window
argument_list|()
operator|.
name|style
argument_list|()
operator|==
name|Qt
operator|::
name|TexturePattern
condition|)
return|return
name|QColor
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|,
literal|8
argument_list|)
return|;
return|return
name|buttonColor
argument_list|(
name|pal
argument_list|)
operator|.
name|lighter
argument_list|(
literal|104
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QColor
name|buttonColor
argument_list|(
specifier|const
name|QPalette
operator|&
name|pal
argument_list|)
decl|const
block|{
name|QColor
name|buttonColor
init|=
name|pal
operator|.
name|button
argument_list|()
operator|.
name|color
argument_list|()
decl_stmt|;
name|int
name|val
init|=
name|qGray
argument_list|(
name|buttonColor
operator|.
name|rgb
argument_list|()
argument_list|)
decl_stmt|;
name|buttonColor
operator|=
name|buttonColor
operator|.
name|lighter
argument_list|(
literal|100
operator|+
name|qMax
argument_list|(
literal|1
argument_list|,
operator|(
literal|180
operator|-
name|val
operator|)
operator|/
literal|6
argument_list|)
argument_list|)
expr_stmt|;
name|buttonColor
operator|.
name|setHsv
argument_list|(
name|buttonColor
operator|.
name|hue
argument_list|()
argument_list|,
name|buttonColor
operator|.
name|saturation
argument_list|()
operator|*
literal|0.75
argument_list|,
name|buttonColor
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|buttonColor
return|;
block|}
end_decl_stmt
begin_enum
enum|enum
block|{
name|menuItemHMargin
init|=
literal|3
block|,
comment|// menu item hor text margin
name|menuArrowHMargin
init|=
literal|6
block|,
comment|// menu arrow horizontal margin
name|menuRightBorder
init|=
literal|15
block|,
comment|// right border on menus
name|menuCheckMarkWidth
init|=
literal|12
comment|// checkmarks width on menus
block|}
enum|;
end_enum
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_FUSION
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QFUSIONSTYLE_P_P_H
end_comment
end_unit
