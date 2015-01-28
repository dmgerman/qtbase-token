begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFONTINFO_H
end_ifndef
begin_define
DECL|macro|QFONTINFO_H
define|#
directive|define
name|QFONTINFO_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QFontInfo
block|{
name|public
label|:
name|QFontInfo
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|)
expr_stmt|;
name|QFontInfo
argument_list|(
specifier|const
name|QFontInfo
operator|&
argument_list|)
expr_stmt|;
operator|~
name|QFontInfo
argument_list|()
expr_stmt|;
name|QFontInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFontInfo
operator|&
operator|)
decl_stmt|;
name|void
name|swap
parameter_list|(
name|QFontInfo
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|family
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|styleName
argument_list|()
specifier|const
expr_stmt|;
name|int
name|pixelSize
argument_list|()
specifier|const
expr_stmt|;
name|int
name|pointSize
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|pointSizeF
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|italic
argument_list|()
specifier|const
expr_stmt|;
name|QFont
operator|::
name|Style
name|style
argument_list|()
specifier|const
expr_stmt|;
name|int
name|weight
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|bold
argument_list|()
specifier|const
block|{
return|return
name|weight
argument_list|()
operator|>
name|QFont
operator|::
name|Normal
return|;
block|}
name|bool
name|underline
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|overline
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|strikeOut
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|fixedPitch
argument_list|()
specifier|const
expr_stmt|;
name|QFont
operator|::
name|StyleHint
name|styleHint
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|5
argument_list|)
name|bool
name|rawMode
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|bool
name|exactMatch
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QExplicitlySharedDataPointer
operator|<
name|QFontPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QFontInfo
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFONTINFO_H
end_comment
end_unit
