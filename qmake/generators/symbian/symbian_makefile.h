begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SYMBIAN_MAKEFILE_H
end_ifndef
begin_define
DECL|macro|SYMBIAN_MAKEFILE_H
define|#
directive|define
name|SYMBIAN_MAKEFILE_H
end_define
begin_include
include|#
directive|include
file|"symbiancommon.h"
end_include
begin_comment
comment|// This allows us to reuse the code for both win32 and unix makefile generators.
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|variable|T
name|class
name|SymbianMakefileTemplate
operator|:
name|public
name|T
operator|,
name|public
name|SymbianCommonGenerator
block|{
name|public
operator|:
name|SymbianMakefileTemplate
argument_list|()
operator|:
name|SymbianCommonGenerator
argument_list|(
argument|this
argument_list|)
block|{}
name|void
name|init
argument_list|()
block|{
name|T
operator|::
name|init
argument_list|()
block|;
name|SymbianCommonGenerator
operator|::
name|init
argument_list|()
block|;     }
name|bool
name|writeMakefile
argument_list|(
argument|QTextStream&t
argument_list|)
block|{
name|QString
name|numberOfIcons
block|;
name|QString
name|iconFile
block|;
name|QMap
operator|<
name|QString
block|,
name|QStringList
operator|>
name|userRssRules
block|;
name|readRssRules
argument_list|(
name|numberOfIcons
argument_list|,
name|iconFile
argument_list|,
name|userRssRules
argument_list|)
block|;
comment|// Generate pkg files if there are any actual files to deploy
name|bool
name|generatePkg
operator|=
name|false
block|;
if|if
condition|(
name|targetType
operator|==
name|TypeExe
condition|)
block|{
name|generatePkg
operator|=
name|true
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QStringList
name|deployments
init|=
name|this
operator|->
name|project
operator|->
name|values
argument_list|(
literal|"DEPLOYMENT"
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|deployments
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
comment|// ### Qt 5: remove .sources, inconsistent with INSTALLS
if|if
condition|(
operator|!
name|this
operator|->
name|project
operator|->
name|values
argument_list|(
name|deployments
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
literal|".sources"
argument_list|)
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|this
operator|->
name|project
operator|->
name|values
argument_list|(
name|deployments
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
literal|".files"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|generatePkg
operator|=
name|true
expr_stmt|;
break|break;
block|}
end_expr_stmt
begin_decl_stmt
unit|}         }
name|SymbianLocalizationList
name|symbianLocalizationList
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|parseTsFiles
argument_list|(
operator|&
name|symbianLocalizationList
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|generatePkg
condition|)
block|{
name|generatePkgFile
argument_list|(
name|iconFile
argument_list|,
name|false
argument_list|,
name|symbianLocalizationList
argument_list|)
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
name|targetType
operator|==
name|TypeExe
condition|)
block|{
if|if
condition|(
operator|!
name|this
operator|->
name|project
operator|->
name|values
argument_list|(
literal|"CONFIG"
argument_list|)
operator|.
name|contains
argument_list|(
literal|"no_icon"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
block|{
name|writeRegRssFile
argument_list|(
name|userRssRules
argument_list|)
expr_stmt|;
name|writeRssFile
argument_list|(
name|numberOfIcons
argument_list|,
name|iconFile
argument_list|)
expr_stmt|;
name|writeLocFile
argument_list|(
name|symbianLocalizationList
argument_list|)
expr_stmt|;
block|}
block|}
end_if
begin_expr_stmt
name|writeCustomDefFile
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|T
operator|::
name|writeMakefile
argument_list|(
name|t
argument_list|)
return|;
end_return
begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SYMBIAN_MAKEFILE_H
end_comment
end_unit
