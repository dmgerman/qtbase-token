begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAPSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QPIXMAPSTYLE_P_H
define|#
directive|define
name|QPIXMAPSTYLE_P_H
end_define
begin_include
include|#
directive|include
file|"qpixmapstyle_p.h"
end_include
begin_include
include|#
directive|include
file|"qcommonstyle_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
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
begin_struct
DECL|struct|QPixmapStyleDescriptor
struct|struct
name|QPixmapStyleDescriptor
block|{
DECL|member|fileName
name|QString
name|fileName
decl_stmt|;
DECL|member|size
name|QSize
name|size
decl_stmt|;
DECL|member|margins
name|QMargins
name|margins
decl_stmt|;
DECL|member|tileRules
name|QTileRules
name|tileRules
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QPixmapStylePixmap
struct|struct
name|QPixmapStylePixmap
block|{
DECL|member|pixmap
name|QPixmap
name|pixmap
decl_stmt|;
DECL|member|margins
name|QMargins
name|margins
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QPixmapStylePrivate
range|:
name|public
name|QCommonStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPixmapStyle
argument_list|)
name|public
operator|:
name|QHash
operator|<
name|QPixmapStyle
operator|::
name|ControlDescriptor
block|,
name|QPixmapStyleDescriptor
operator|>
name|descriptors
block|;
name|QHash
operator|<
name|QPixmapStyle
operator|::
name|ControlPixmap
block|,
name|QPixmapStylePixmap
operator|>
name|pixmaps
block|;
specifier|static
name|QPixmap
name|scale
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|const QPixmap&pixmap
argument_list|,
argument|const QPixmapStyleDescriptor&desc
argument_list|)
block|;
name|QPixmap
name|getCachedPixmap
argument_list|(
argument|QPixmapStyle::ControlDescriptor control
argument_list|,
argument|const QPixmapStyleDescriptor&desc
argument_list|,
argument|const QSize&size
argument_list|)
specifier|const
block|;
name|QSize
name|computeSize
argument_list|(
argument|const QPixmapStyleDescriptor&desc
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|)
specifier|const
block|; }
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
comment|// QPIXMAPSTYLE_P_H
end_comment
end_unit
