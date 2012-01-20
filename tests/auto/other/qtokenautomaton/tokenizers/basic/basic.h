begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* NOTE: This file is AUTO GENERATED by qtokenautomaton2cpp.xsl. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|q_Basic_h
end_ifndef
begin_define
DECL|macro|q_Basic_h
define|#
directive|define
name|q_Basic_h
end_define
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
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
name|OneColon
block|,
name|WeHaveDashes
block|,
name|WeHaveDashes2
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
name|classifier9
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
name|classifier15
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
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|toToken
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
end_expr_stmt
begin_expr_stmt
DECL|function|toToken
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
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
