begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXBMHANDLER_P_H
end_ifndef
begin_define
DECL|macro|QXBMHANDLER_P_H
define|#
directive|define
name|QXBMHANDLER_P_H
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
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"QtGui/qimageiohandler.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_XBM
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QXbmHandler
range|:
name|public
name|QImageIOHandler
block|{
name|public
operator|:
name|QXbmHandler
argument_list|()
block|;
name|bool
name|canRead
argument_list|()
specifier|const
block|;
name|bool
name|read
argument_list|(
name|QImage
operator|*
name|image
argument_list|)
block|;
name|bool
name|write
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
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
block|;
name|void
name|setOption
argument_list|(
argument|ImageOption option
argument_list|,
argument|const QVariant&value
argument_list|)
block|;
name|bool
name|supportsOption
argument_list|(
argument|ImageOption option
argument_list|)
specifier|const
block|;
name|private
operator|:
name|bool
name|readHeader
argument_list|()
block|;     enum
name|State
block|{
name|Ready
block|,
name|ReadHeader
block|,
name|Error
block|}
block|;
name|State
name|state
block|;
name|int
name|width
block|;
name|int
name|height
block|;
name|QString
name|fileName
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
comment|// QT_NO_IMAGEFORMAT_XBM
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXBMHANDLER_P_H
end_comment
end_unit
