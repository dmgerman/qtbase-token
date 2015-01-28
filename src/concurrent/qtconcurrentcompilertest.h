begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTCONCURRENT_COMPILERTEST_H
end_ifndef
begin_define
DECL|macro|QTCONCURRENT_COMPILERTEST_H
define|#
directive|define
name|QTCONCURRENT_COMPILERTEST_H
end_define
begin_include
include|#
directive|include
file|<QtConcurrent/qtconcurrent_global.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CONCURRENT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtPrivate
block|{
name|template
operator|<
name|class
name|T
operator|>
name|class
name|HasResultType
block|{
typedef|typedef
name|char
name|Yes
typedef|;
typedef|typedef
name|void
modifier|*
name|No
typedef|;
name|template
operator|<
name|typename
name|U
operator|>
specifier|static
name|Yes
name|test
argument_list|(
argument|int
argument_list|,
argument|const typename U::result_type * =
literal|0
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|U
operator|>
specifier|static
name|No
name|test
argument_list|(
name|double
argument_list|)
expr_stmt|;
name|public
label|:
enum|enum
block|{
name|Value
init|=
operator|(
sizeof|sizeof
argument_list|(
name|test
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
operator|)
block|}
enum|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CONCURRENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
