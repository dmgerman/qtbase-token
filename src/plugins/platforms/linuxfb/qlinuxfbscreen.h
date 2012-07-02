begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLINUXFBSCREEN_H
end_ifndef
begin_define
DECL|macro|QLINUXFBSCREEN_H
define|#
directive|define
name|QLINUXFBSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbscreen_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QLinuxFbScreen
range|:
name|public
name|QFbScreen
block|{
name|Q_OBJECT
name|public
operator|:
name|QLinuxFbScreen
argument_list|(
argument|uchar * d
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|int lstep
argument_list|,
argument|QImage::Format screenFormat
argument_list|)
block|;
name|void
name|setGeometry
argument_list|(
argument|QRect rect
argument_list|)
block|;
name|void
name|setFormat
argument_list|(
argument|QImage::Format format
argument_list|)
block|;
name|public
name|slots
operator|:
name|QRegion
name|doRedraw
argument_list|()
block|;
name|private
operator|:
name|QImage
operator|*
name|mFbScreenImage
block|;
name|uchar
operator|*
name|data
block|;
name|int
name|bytesPerLine
block|;
name|QPainter
operator|*
name|compositePainter
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
comment|// QLINUXFBSCREEN_H
end_comment
end_unit
