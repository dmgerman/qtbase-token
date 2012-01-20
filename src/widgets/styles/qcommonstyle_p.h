begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOMMONSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QCOMMONSTYLE_P_H
define|#
directive|define
name|QCOMMONSTYLE_P_H
end_define
begin_include
include|#
directive|include
file|"qcommonstyle.h"
end_include
begin_include
include|#
directive|include
file|"qstyle_p.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|//  W A R N I N G
comment|//  -------------
comment|//
comment|// This file is not part of the Qt API.  It exists for the convenience
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
comment|// file may change from version to version without notice, or even be removed.
comment|//
comment|// We mean it.
comment|//
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Private class
end_comment
begin_decl_stmt
name|class
name|QCommonStylePrivate
range|:
name|public
name|QStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QCommonStyle
argument_list|)
name|public
operator|:
specifier|inline
name|QCommonStylePrivate
argument_list|()
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
operator|:
name|cachedOption
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{ }
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
operator|~
name|QCommonStylePrivate
argument_list|()
block|{
name|delete
name|cachedOption
block|;     }
name|void
name|viewItemDrawText
argument_list|(
argument|QPainter *p
argument_list|,
argument|const QStyleOptionViewItemV4 *option
argument_list|,
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|void
name|viewItemLayout
argument_list|(
argument|const QStyleOptionViewItemV4 *opt
argument_list|,
argument|QRect *checkRect
argument_list|,
argument|QRect *pixmapRect
argument_list|,
argument|QRect *textRect
argument_list|,
argument|bool sizehint
argument_list|)
specifier|const
block|;
name|QSize
name|viewItemSize
argument_list|(
argument|const QStyleOptionViewItemV4 *option
argument_list|,
argument|int role
argument_list|)
specifier|const
block|;
name|mutable
name|QRect
name|decorationRect
block|,
name|displayRect
block|,
name|checkRect
block|;
name|mutable
name|QStyleOptionViewItemV4
operator|*
name|cachedOption
block|;
name|bool
name|isViewItemCached
argument_list|(
argument|const QStyleOptionViewItemV4&option
argument_list|)
specifier|const
block|{
return|return
name|cachedOption
operator|&&
operator|(
name|option
operator|.
name|rect
operator|==
name|cachedOption
operator|->
name|rect
operator|&&
name|option
operator|.
name|direction
operator|==
name|cachedOption
operator|->
name|direction
operator|&&
name|option
operator|.
name|state
operator|==
name|cachedOption
operator|->
name|state
operator|&&
name|option
operator|.
name|displayAlignment
operator|==
name|cachedOption
operator|->
name|displayAlignment
operator|&&
name|option
operator|.
name|decorationAlignment
operator|==
name|cachedOption
operator|->
name|decorationAlignment
operator|&&
name|option
operator|.
name|decorationPosition
operator|==
name|cachedOption
operator|->
name|decorationPosition
operator|&&
name|option
operator|.
name|decorationSize
operator|==
name|cachedOption
operator|->
name|decorationSize
operator|&&
name|option
operator|.
name|font
operator|==
name|cachedOption
operator|->
name|font
operator|&&
name|option
operator|.
name|features
operator|==
name|cachedOption
operator|->
name|features
operator|&&
name|option
operator|.
name|widget
operator|==
name|cachedOption
operator|->
name|widget
operator|&&
name|option
operator|.
name|index
operator|==
name|cachedOption
operator|->
name|index
operator|&&
name|option
operator|.
name|icon
operator|.
name|isNull
argument_list|()
operator|==
name|cachedOption
operator|->
name|icon
operator|.
name|isNull
argument_list|()
operator|&&
name|option
operator|.
name|text
operator|==
name|cachedOption
operator|->
name|text
operator|&&
name|option
operator|.
name|viewItemPosition
operator|==
name|cachedOption
operator|->
name|viewItemPosition
operator|)
return|;
block|}
endif|#
directive|endif
name|mutable
name|QIcon
name|tabBarcloseButtonIcon
block|;
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
name|void
name|tabLayout
argument_list|(
argument|const QStyleOptionTabV3 *opt
argument_list|,
argument|const QWidget *widget
argument_list|,
argument|QRect *textRect
argument_list|,
argument|QRect *pixmapRect
argument_list|)
specifier|const
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QCOMMONSTYLE_P_H
end_comment
end_unit
