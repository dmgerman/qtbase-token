begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindow
name|class
name|QWindow
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
argument|QWindow *window =
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
