begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENWFDPORTMODE_H
end_ifndef
begin_define
DECL|macro|QOPENWFDPORTMODE_H
define|#
directive|define
name|QOPENWFDPORTMODE_H
end_define
begin_include
include|#
directive|include
file|<WF/wfd.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSize>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_decl_stmt
DECL|variable|QOpenWFDPort
name|class
name|QOpenWFDPort
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenWFDPortMode
block|{
name|public
label|:
name|QOpenWFDPortMode
argument_list|(
argument|QOpenWFDPort *port
argument_list|,
argument|WFDPortMode portMode
argument_list|)
empty_stmt|;
name|QSize
name|size
argument_list|()
specifier|const
block|{
return|return
name|mSize
return|;
block|}
name|qreal
name|refreshRate
argument_list|()
specifier|const
block|{
return|return
name|mRefresh
return|;
block|}
name|bool
name|flipMirror
argument_list|()
specifier|const
block|{
return|return
name|mFlipMirror
return|;
block|}
name|bool
name|interlaced
argument_list|()
specifier|const
block|{
return|return
name|mInterlaced
return|;
block|}
name|WFDPortMode
name|handle
argument_list|()
specifier|const
block|{
return|return
name|mPortMode
return|;
block|}
name|private
label|:
name|WFDPortMode
name|mPortMode
decl_stmt|;
name|QSize
name|mSize
decl_stmt|;
name|qreal
name|mRefresh
decl_stmt|;
name|bool
name|mFlipMirror
decl_stmt|;
name|bool
name|mInterlaced
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QOpenWFDPortMode
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENWFPORTMODE_H
end_comment
end_unit
