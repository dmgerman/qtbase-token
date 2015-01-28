begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WRAPPER_H
end_ifndef
begin_define
DECL|macro|WRAPPER_H
define|#
directive|define
name|WRAPPER_H
end_define
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSharedPointer
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QSharedPointer
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|Wrapper
block|{
name|public
label|:
name|QSharedPointer
operator|<
name|int
operator|>
name|ptr
expr_stmt|;
name|Wrapper
argument_list|(
specifier|const
name|QSharedPointer
operator|<
name|int
operator|>
operator|&
argument_list|)
expr_stmt|;
operator|~
name|Wrapper
argument_list|()
expr_stmt|;
specifier|static
name|Wrapper
name|create
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// WRAPPER_H
end_comment
end_unit
