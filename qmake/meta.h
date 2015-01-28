begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|META_H
end_ifndef
begin_define
DECL|macro|META_H
define|#
directive|define
name|META_H
end_define
begin_include
include|#
directive|include
file|"project.h"
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMakeProject
name|class
name|QMakeProject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMakeMetaInfo
block|{
name|bool
name|readLibtoolFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|f
parameter_list|)
function_decl|;
name|bool
name|readPkgCfgFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|f
parameter_list|)
function_decl|;
name|QMakeProject
modifier|*
name|conf
decl_stmt|;
name|ProValueMap
name|vars
decl_stmt|;
name|QString
name|meta_type
decl_stmt|;
specifier|static
name|QHash
operator|<
name|QString
operator|,
name|ProValueMap
operator|>
name|cache_vars
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|public
label|:
name|QMakeMetaInfo
argument_list|(
name|QMakeProject
operator|*
name|_conf
argument_list|)
expr_stmt|;
name|bool
name|readLib
parameter_list|(
name|QString
name|lib
parameter_list|)
function_decl|;
specifier|static
name|QString
name|findLib
parameter_list|(
name|QString
name|lib
parameter_list|)
function_decl|;
specifier|static
name|bool
name|libExists
parameter_list|(
name|QString
name|lib
parameter_list|)
function_decl|;
name|QString
name|type
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isEmpty
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|v
parameter_list|)
function_decl|;
name|ProStringList
modifier|&
name|values
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|v
parameter_list|)
function_decl|;
name|ProString
name|first
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|v
parameter_list|)
function_decl|;
name|ProValueMap
modifier|&
name|variables
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|isEmpty
specifier|inline
name|bool
name|QMakeMetaInfo
operator|::
name|isEmpty
argument_list|(
argument|const ProKey&v
argument_list|)
block|{
return|return
operator|!
name|vars
operator|.
name|contains
argument_list|(
name|v
argument_list|)
operator|||
name|vars
index|[
name|v
index|]
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|type
specifier|inline
name|QString
name|QMakeMetaInfo
operator|::
name|type
argument_list|()
specifier|const
block|{
return|return
name|meta_type
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|values
specifier|inline
name|ProStringList
operator|&
name|QMakeMetaInfo
operator|::
name|values
argument_list|(
argument|const ProKey&v
argument_list|)
block|{
return|return
name|vars
index|[
name|v
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|first
specifier|inline
name|ProString
name|QMakeMetaInfo
operator|::
name|first
argument_list|(
argument|const ProKey&v
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_SUN
argument_list|)
operator|&&
operator|(
name|__SUNPRO_CC
operator|==
literal|0x500
operator|)
operator|||
name|defined
argument_list|(
name|Q_CC_HP
argument_list|)
comment|// workaround for Sun WorkShop 5.0 bug fixed in Forte 6
if|if
condition|(
name|isEmpty
argument_list|(
name|v
argument_list|)
condition|)
return|return
name|ProString
argument_list|(
literal|""
argument_list|)
return|;
else|else
return|return
name|vars
index|[
name|v
index|]
operator|.
name|first
argument_list|()
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|isEmpty
argument_list|(
name|v
argument_list|)
condition|?
name|ProString
argument_list|(
literal|""
argument_list|)
else|:
name|vars
index|[
name|v
index|]
operator|.
name|first
argument_list|()
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|}  inline
DECL|function|variables
name|ProValueMap
operator|&
name|QMakeMetaInfo
operator|::
name|variables
argument_list|()
block|{
return|return
name|vars
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|libExists
specifier|inline
name|bool
name|QMakeMetaInfo
operator|::
name|libExists
argument_list|(
argument|QString lib
argument_list|)
block|{
return|return
operator|!
name|findLib
argument_list|(
name|lib
argument_list|)
operator|.
name|isNull
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
comment|// META_H
end_comment
end_unit
