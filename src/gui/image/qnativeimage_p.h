begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNATIVEIMAGE_P_H
end_ifndef
begin_define
DECL|macro|QNATIVEIMAGE_P_H
define|#
directive|define
name|QNATIVEIMAGE_P_H
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
file|"qimage.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_WIN
end_ifdef
begin_include
include|#
directive|include
file|"qt_windows.h"
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<private/qt_x11_p.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<private/qt_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QNativeImage
block|{
name|public
label|:
name|QNativeImage
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|QImage::Format format
argument_list|,
argument|bool isTextBuffer = false
argument_list|,
argument|QWidget *widget =
literal|0
argument_list|)
empty_stmt|;
operator|~
name|QNativeImage
argument_list|()
expr_stmt|;
specifier|inline
name|int
name|width
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|int
name|height
argument_list|()
specifier|const
expr_stmt|;
name|QImage
name|image
decl_stmt|;
specifier|static
name|QImage
operator|::
name|Format
name|systemFormat
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_WIN
name|HDC
name|hdc
decl_stmt|;
name|HBITMAP
name|bitmap
decl_stmt|;
name|HBITMAP
name|null_bitmap
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_MITSHM
argument_list|)
name|XImage
modifier|*
name|xshmimg
decl_stmt|;
name|Pixmap
name|xshmpm
decl_stmt|;
name|XShmSegmentInfo
name|xshminfo
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|CGContextRef
name|cg
decl_stmt|;
endif|#
directive|endif
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QNativeImage
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|width
specifier|inline
name|int
name|QNativeImage
operator|::
name|width
argument_list|()
specifier|const
block|{
return|return
name|image
operator|.
name|width
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|height
specifier|inline
name|int
name|QNativeImage
operator|::
name|height
argument_list|()
specifier|const
block|{
return|return
name|image
operator|.
name|height
argument_list|()
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QNATIVEIMAGE_P_H
end_comment
end_unit
