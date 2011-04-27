begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SYMMAKE_ABLD_H
end_ifndef
begin_define
DECL|macro|SYMMAKE_ABLD_H
define|#
directive|define
name|SYMMAKE_ABLD_H
end_define
begin_include
include|#
directive|include
file|<symmake.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|SymbianAbldMakefileGenerator
range|:
name|public
name|SymbianMakefileGenerator
block|{
name|protected
operator|:
comment|// Inherited from parent
name|virtual
name|void
name|writeBldInfExtensionRulesPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|,
specifier|const
name|QString
operator|&
name|iconTargetFile
argument_list|)
block|;
name|virtual
name|void
name|writeBldInfMkFilePart
argument_list|(
argument|QTextStream& t
argument_list|,
argument|bool addDeploymentExtension
argument_list|)
block|;
name|virtual
name|void
name|writeMkFile
argument_list|(
argument|const QString& wrapperFileName
argument_list|,
argument|bool deploymentOnly
argument_list|)
block|;
name|virtual
name|void
name|writeWrapperMakefile
argument_list|(
argument|QFile& wrapperFile
argument_list|,
argument|bool isPrimaryMakefile
argument_list|)
block|;
name|virtual
name|void
name|appendAbldTempDirs
argument_list|(
argument|QStringList& sysincspaths
argument_list|,
argument|QString includepath
argument_list|)
block|;
name|bool
name|writeDeploymentTargets
argument_list|(
argument|QTextStream&t
argument_list|,
argument|bool isRom
argument_list|)
block|;
name|QString
name|gnuMakefileName
block|;
name|public
operator|:
name|SymbianAbldMakefileGenerator
argument_list|()
block|;
operator|~
name|SymbianAbldMakefileGenerator
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SYMMAKE_ABLD_H
end_comment
end_unit
