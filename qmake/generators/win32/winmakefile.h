begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WINMAKEFILE_H
end_ifndef
begin_define
DECL|macro|WINMAKEFILE_H
define|#
directive|define
name|WINMAKEFILE_H
end_define
begin_include
include|#
directive|include
file|"makefile.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Win32MakefileGenerator
range|:
name|public
name|MakefileGenerator
block|{
name|public
operator|:
name|Win32MakefileGenerator
argument_list|()
block|;
operator|~
name|Win32MakefileGenerator
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|QString
name|defaultInstall
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|virtual
name|void
name|writeCleanParts
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|void
name|writeStandardParts
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|void
name|writeIncPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|void
name|writeLibsPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|void
name|writeObjectsPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|void
name|writeImplicitRulesPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|virtual
name|void
name|writeBuildRulesPart
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|virtual
name|QString
name|escapeFilePath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|;
name|ProString
name|escapeFilePath
argument_list|(
argument|const ProString&path
argument_list|)
specifier|const
block|{
return|return
name|MakefileGenerator
operator|::
name|escapeFilePath
argument_list|(
name|path
argument_list|)
return|;
block|}
name|virtual
name|void
name|writeRcFilePart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|int
name|findHighestVersion
argument_list|(
specifier|const
name|QString
operator|&
name|dir
argument_list|,
specifier|const
name|QString
operator|&
name|stem
argument_list|,
specifier|const
name|QString
operator|&
name|ext
operator|=
name|QLatin1String
argument_list|(
literal|"lib"
argument_list|)
argument_list|)
block|;
name|virtual
name|bool
name|findLibraries
argument_list|()
block|;
name|virtual
name|void
name|processPrlFiles
argument_list|()
block|;
name|void
name|processVars
argument_list|()
block|;
name|void
name|fixTargetExt
argument_list|()
block|;
name|void
name|processRcFileVar
argument_list|()
block|;
name|virtual
name|QString
name|getLibTarget
argument_list|()
block|;
specifier|static
name|QString
name|cQuoted
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|)
block|;
name|virtual
name|QString
name|getManifestFileForRcFile
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|~Win32MakefileGenerator
specifier|inline
name|Win32MakefileGenerator
operator|::
operator|~
name|Win32MakefileGenerator
argument_list|()
block|{ }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// WINMAKEFILE_H
end_comment
end_unit
