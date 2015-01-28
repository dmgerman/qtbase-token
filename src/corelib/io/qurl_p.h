begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2012 Intel Corporation. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QURL_P_H
end_ifndef
begin_define
DECL|macro|QURL_P_H
define|#
directive|define
name|QURL_P_H
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
comment|// This file is not part of the Qt API. It exists for the convenience of
end_comment
begin_comment
comment|// qurl*.cpp This header file may change from version to version without
end_comment
begin_comment
comment|// notice, or even be removed.
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
file|"qurl.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// in qurlrecode.cpp
specifier|extern
name|Q_AUTOTEST_EXPORT
name|int
name|qt_urlRecode
argument_list|(
name|QString
operator|&
name|appendTo
argument_list|,
specifier|const
name|QChar
operator|*
name|begin
argument_list|,
specifier|const
name|QChar
operator|*
name|end
argument_list|,
name|QUrl
operator|::
name|ComponentFormattingOptions
name|encoding
argument_list|,
specifier|const
name|ushort
operator|*
name|tableModifications
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// in qurlidna.cpp
end_comment
begin_enum
DECL|enum|AceLeadingDot
DECL|enumerator|AllowLeadingDot
DECL|enumerator|ForbidLeadingDot
enum|enum
name|AceLeadingDot
block|{
name|AllowLeadingDot
block|,
name|ForbidLeadingDot
block|}
enum|;
end_enum
begin_enum
DECL|enum|AceOperation
DECL|enumerator|ToAceOnly
DECL|enumerator|NormalizeAce
enum|enum
name|AceOperation
block|{
name|ToAceOnly
block|,
name|NormalizeAce
block|}
enum|;
end_enum
begin_function_decl
specifier|extern
name|QString
name|qt_ACE_do
parameter_list|(
specifier|const
name|QString
modifier|&
name|domain
parameter_list|,
name|AceOperation
name|op
parameter_list|,
name|AceLeadingDot
name|dot
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|void
name|qt_nameprep
parameter_list|(
name|QString
modifier|*
name|source
parameter_list|,
name|int
name|from
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|bool
name|qt_check_std3rules
parameter_list|(
specifier|const
name|QChar
modifier|*
name|uc
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|void
name|qt_punycodeEncoder
parameter_list|(
specifier|const
name|QChar
modifier|*
name|s
parameter_list|,
name|int
name|ucLength
parameter_list|,
name|QString
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|QString
name|qt_punycodeDecoder
parameter_list|(
specifier|const
name|QString
modifier|&
name|pc
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|Q_AUTOTEST_EXPORT
name|QString
name|qt_urlRecodeByteArray
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QURL_P_H
end_comment
end_unit
