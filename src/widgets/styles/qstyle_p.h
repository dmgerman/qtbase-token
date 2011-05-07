begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QSTYLE_P_H
define|#
directive|define
name|QSTYLE_P_H
end_define
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyle.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|//  W A R N I N G
comment|//  -------------
comment|//
comment|// This file is not part of the Qt API.  It exists for the convenience
comment|// of qstyle_*.cpp.  This header file may change from version to version
comment|// without notice, or even be removed.
comment|//
comment|// We mean it.
comment|//
comment|// Private class
DECL|variable|QStyle
name|class
name|QStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QStylePrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QStyle
argument_list|)
name|public
operator|:
specifier|inline
name|QStylePrivate
argument_list|()
operator|:
name|layoutSpacingIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|proxyStyle
argument_list|(
literal|0
argument_list|)
block|{}
name|mutable
name|int
name|layoutSpacingIndex
block|;
name|QStyle
operator|*
name|proxyStyle
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|BEGIN_STYLE_PIXMAPCACHE
define|#
directive|define
name|BEGIN_STYLE_PIXMAPCACHE
parameter_list|(
name|a
parameter_list|)
define|\
value|QRect rect = option->rect; \     QPixmap internalPixmapCache; \     QImage imageCache; \     QPainter *p = painter; \     QString unique = QStyleHelper::uniqueName((a), option, option->rect.size()); \     int txType = painter->deviceTransform().type() | painter->worldTransform().type(); \     bool doPixmapCache = txType<= QTransform::TxTranslate; \     if (doPixmapCache&& QPixmapCache::find(unique, internalPixmapCache)) { \         painter->drawPixmap(option->rect.topLeft(), internalPixmapCache); \     } else { \         if (doPixmapCache) { \             rect.setRect(0, 0, option->rect.width(), option->rect.height()); \             imageCache = QImage(option->rect.size(), QImage::Format_ARGB32_Premultiplied); \             imageCache.fill(0); \             p = new QPainter(&imageCache); \         }
end_define
begin_define
DECL|macro|END_STYLE_PIXMAPCACHE
define|#
directive|define
name|END_STYLE_PIXMAPCACHE
define|\
value|if (doPixmapCache) { \             p->end(); \             delete p; \             internalPixmapCache = QPixmap::fromImage(imageCache); \             painter->drawPixmap(option->rect.topLeft(), internalPixmapCache); \             QPixmapCache::insert(unique, internalPixmapCache); \         } \     }
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QSTYLE_P_H
end_comment
end_unit
