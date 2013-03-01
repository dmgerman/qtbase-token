begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QICON_P_H
end_ifndef
begin_define
DECL|macro|QICON_P_H
define|#
directive|define
name|QICON_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qiconengine.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ICON
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QIconPrivate
block|{
name|public
label|:
name|QIconPrivate
argument_list|()
expr_stmt|;
operator|~
name|QIconPrivate
argument_list|()
block|{
name|delete
name|engine
block|;     }
name|qreal
name|pixmapDevicePixelRatio
argument_list|(
argument|qreal displayDevicePixelRatio
argument_list|,
argument|const QSize&requestedSize
argument_list|,
argument|const QSize&actualSize
argument_list|)
expr_stmt|;
name|QIconEngine
modifier|*
name|engine
decl_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|int
name|serialNum
decl_stmt|;
name|int
name|detach_no
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QPixmapIconEngineEntry
struct|struct
name|QPixmapIconEngineEntry
block|{
DECL|function|QPixmapIconEngineEntry
name|QPixmapIconEngineEntry
argument_list|()
operator|:
name|mode
argument_list|(
name|QIcon
operator|::
name|Normal
argument_list|)
operator|,
name|state
argument_list|(
argument|QIcon::Off
argument_list|)
block|{}
DECL|function|QPixmapIconEngineEntry
name|QPixmapIconEngineEntry
argument_list|(
argument|const QPixmap&pm
argument_list|,
argument|QIcon::Mode m = QIcon::Normal
argument_list|,
argument|QIcon::State s = QIcon::Off
argument_list|)
operator|:
name|pixmap
argument_list|(
name|pm
argument_list|)
operator|,
name|size
argument_list|(
name|pm
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|mode
argument_list|(
name|m
argument_list|)
operator|,
name|state
argument_list|(
argument|s
argument_list|)
block|{}
DECL|function|QPixmapIconEngineEntry
name|QPixmapIconEngineEntry
argument_list|(
argument|const QString&file
argument_list|,
argument|const QSize&sz = QSize()
argument_list|,
argument|QIcon::Mode m = QIcon::Normal
argument_list|,
argument|QIcon::State s = QIcon::Off
argument_list|)
operator|:
name|fileName
argument_list|(
name|file
argument_list|)
operator|,
name|size
argument_list|(
name|sz
argument_list|)
operator|,
name|mode
argument_list|(
name|m
argument_list|)
operator|,
name|state
argument_list|(
argument|s
argument_list|)
block|{}
DECL|member|pixmap
name|QPixmap
name|pixmap
expr_stmt|;
DECL|member|fileName
name|QString
name|fileName
decl_stmt|;
DECL|member|size
name|QSize
name|size
decl_stmt|;
DECL|member|mode
name|QIcon
operator|::
name|Mode
name|mode
expr_stmt|;
DECL|member|state
name|QIcon
operator|::
name|State
name|state
expr_stmt|;
DECL|function|isNull
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
operator|(
name|fileName
operator|.
name|isEmpty
argument_list|()
operator|&&
name|pixmap
operator|.
name|isNull
argument_list|()
operator|)
return|;
block|}
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QPixmapIconEngine
range|:
name|public
name|QIconEngine
block|{
name|public
operator|:
name|QPixmapIconEngine
argument_list|()
block|;
name|QPixmapIconEngine
argument_list|(
specifier|const
name|QPixmapIconEngine
operator|&
argument_list|)
block|;
operator|~
name|QPixmapIconEngine
argument_list|()
block|;
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|,
argument|QIcon::Mode mode
argument_list|,
argument|QIcon::State state
argument_list|)
block|;
name|QPixmap
name|pixmap
argument_list|(
argument|const QSize&size
argument_list|,
argument|QIcon::Mode mode
argument_list|,
argument|QIcon::State state
argument_list|)
block|;
name|QPixmapIconEngineEntry
operator|*
name|bestMatch
argument_list|(
argument|const QSize&size
argument_list|,
argument|QIcon::Mode mode
argument_list|,
argument|QIcon::State state
argument_list|,
argument|bool sizeOnly
argument_list|)
block|;
name|QSize
name|actualSize
argument_list|(
argument|const QSize&size
argument_list|,
argument|QIcon::Mode mode
argument_list|,
argument|QIcon::State state
argument_list|)
block|;
name|void
name|addPixmap
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|QIcon::Mode mode
argument_list|,
argument|QIcon::State state
argument_list|)
block|;
name|void
name|addFile
argument_list|(
argument|const QString&fileName
argument_list|,
argument|const QSize&size
argument_list|,
argument|QIcon::Mode mode
argument_list|,
argument|QIcon::State state
argument_list|)
block|;
name|QString
name|key
argument_list|()
specifier|const
block|;
name|QIconEngine
operator|*
name|clone
argument_list|()
specifier|const
block|;
name|bool
name|read
argument_list|(
name|QDataStream
operator|&
name|in
argument_list|)
block|;
name|bool
name|write
argument_list|(
argument|QDataStream&out
argument_list|)
specifier|const
block|;
name|void
name|virtual_hook
argument_list|(
argument|int id
argument_list|,
argument|void *data
argument_list|)
block|;
name|private
operator|:
name|QPixmapIconEngineEntry
operator|*
name|tryMatch
argument_list|(
argument|const QSize&size
argument_list|,
argument|QIcon::Mode mode
argument_list|,
argument|QIcon::State state
argument_list|)
block|;
name|QVector
operator|<
name|QPixmapIconEngineEntry
operator|>
name|pixmaps
block|;
name|friend
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
expr|,
specifier|const
name|QIcon
operator|&
name|icon
operator|)
block|;
name|friend
name|class
name|QIconThemeEngine
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
comment|//QT_NO_ICON
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QICON_P_H
end_comment
end_unit
