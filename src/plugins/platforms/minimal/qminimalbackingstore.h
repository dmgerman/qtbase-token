begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBACKINGSTORE_MINIMAL_H
end_ifndef
begin_define
DECL|macro|QBACKINGSTORE_MINIMAL_H
define|#
directive|define
name|QBACKINGSTORE_MINIMAL_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformbackingstore.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QMinimalBackingStore
range|:
name|public
name|QPlatformBackingStore
block|{
name|public
operator|:
name|QMinimalBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QMinimalBackingStore
argument_list|()
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|flush
argument_list|(
argument|QWindow *window
argument_list|,
argument|const QRegion&region
argument_list|,
argument|const QPoint&offset
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resize
argument_list|(
argument|const QSize&size
argument_list|,
argument|const QRegion&staticContents
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QImage
name|mImage
block|;
specifier|const
name|bool
name|mDebug
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
end_unit
