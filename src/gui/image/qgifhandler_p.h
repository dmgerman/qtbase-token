begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ** WARNING: **      A separate license from Unisys may be required to use the gif **      reader. See http://www.unisys.com/about__unisys/lzw/ **      for information from Unisys ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGIFHANDLER_P_H
end_ifndef
begin_define
DECL|macro|QGIFHANDLER_P_H
define|#
directive|define
name|QGIFHANDLER_P_H
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
file|<QtGui/qimageiohandler.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGIFFormat
name|class
name|QGIFFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGifHandler
range|:
name|public
name|QImageIOHandler
block|{
name|public
operator|:
name|QGifHandler
argument_list|()
block|;
operator|~
name|QGifHandler
argument_list|()
block|;
name|bool
name|canRead
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|read
argument_list|(
argument|QImage *image
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|write
argument_list|(
argument|const QImage&image
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|bool
name|canRead
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
block|;
name|QVariant
name|option
argument_list|(
argument|ImageOption option
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setOption
argument_list|(
argument|ImageOption option
argument_list|,
argument|const QVariant&value
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|supportsOption
argument_list|(
argument|ImageOption option
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|imageCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|loopCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|nextImageDelay
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|currentImageNumber
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|bool
name|imageIsComing
argument_list|()
specifier|const
block|;
name|QGIFFormat
operator|*
name|gifFormat
block|;
name|QString
name|fileName
block|;
name|mutable
name|QByteArray
name|buffer
block|;
name|mutable
name|QImage
name|lastImage
block|;
name|mutable
name|int
name|nextDelay
block|;
name|mutable
name|int
name|loopCnt
block|;
name|int
name|frameNumber
block|;
name|mutable
name|QVector
operator|<
name|QSize
operator|>
name|imageSizes
block|;
name|mutable
name|bool
name|scanIsCached
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
comment|// QGIFHANDLER_P_H
end_comment
end_unit
