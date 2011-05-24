begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qmap.h>
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
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|vars
expr_stmt|;
name|QString
name|meta_type
decl_stmt|;
specifier|static
name|QMap
operator|<
name|QString
operator|,
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
expr|>
name|cache_vars
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|public
label|:
name|QMakeMetaInfo
argument_list|()
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
name|QString
modifier|&
name|v
parameter_list|)
function_decl|;
name|QStringList
modifier|&
name|values
parameter_list|(
specifier|const
name|QString
modifier|&
name|v
parameter_list|)
function_decl|;
name|QString
name|first
parameter_list|(
specifier|const
name|QString
modifier|&
name|v
parameter_list|)
function_decl|;
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
operator|&
name|variables
argument_list|()
expr_stmt|;
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
argument|const QString&v
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
name|QStringList
operator|&
name|QMakeMetaInfo
operator|::
name|values
argument_list|(
argument|const QString&v
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
name|QString
name|QMakeMetaInfo
operator|::
name|first
argument_list|(
argument|const QString&v
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
name|QString
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
name|QString
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
DECL|variable|QString
DECL|function|variables
name|QMap
operator|<
name|QString
operator|,
name|QStringList
operator|>
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
