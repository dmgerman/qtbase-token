begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* NOTE: This file is AUTO GENERATED by qtokenautomaton2cpp.xsl. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|q_BasicNamespace_h
end_ifndef
begin_define
DECL|macro|q_BasicNamespace_h
define|#
directive|define
name|q_BasicNamespace_h
end_define
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|BasicNamespace
block|{
name|class
name|Basic
block|{
name|public
label|:
enum|enum
name|Token
block|{
name|NoKeyword
block|,
name|AReallyLongTokenIFreakinMeanItUKnowUKnowKnow
block|,
name|ColonInName
block|,
name|FFFF
block|,
name|FFFG
block|,
name|FFGF
block|,
name|FFGG
block|,
name|FFLM
block|,
name|_
block|,
name|_111
block|,
name|wobbly
block|}
enum|;
specifier|static
specifier|inline
name|Token
name|toToken
parameter_list|(
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|Token
name|toToken
parameter_list|(
specifier|const
name|QStringRef
modifier|&
name|value
parameter_list|)
function_decl|;
specifier|static
name|Token
name|toToken
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
specifier|static
name|QString
name|toString
parameter_list|(
name|Token
name|token
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
specifier|inline
name|Token
name|classifier3
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|Token
name|classifier4
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|Token
name|classifier14
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|Token
name|classifier44
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|)
function_decl|;
block|}
empty_stmt|;
specifier|inline
name|Basic
operator|::
name|Token
name|Basic
operator|::
name|toToken
argument_list|(
argument|const QString&value
argument_list|)
block|{
return|return
name|toToken
argument_list|(
name|value
operator|.
name|constData
argument_list|()
argument_list|,
name|value
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|Basic
operator|::
name|Token
name|Basic
operator|::
name|toToken
argument_list|(
argument|const QStringRef&value
argument_list|)
block|{
return|return
name|toToken
argument_list|(
name|value
operator|.
name|constData
argument_list|()
argument_list|,
name|value
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
