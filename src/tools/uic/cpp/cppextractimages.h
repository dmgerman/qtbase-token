begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CPPEXTRACTIMAGES_H
end_ifndef
begin_define
DECL|macro|CPPEXTRACTIMAGES_H
define|#
directive|define
name|CPPEXTRACTIMAGES_H
end_define
begin_include
include|#
directive|include
file|"treewalker.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Driver
name|class
name|Driver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Uic
name|class
name|Uic
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|Option
struct_decl|;
end_struct_decl
begin_decl_stmt
name|namespace
name|CPP
block|{
name|class
name|ExtractImages
range|:
name|public
name|TreeWalker
block|{
name|public
operator|:
name|ExtractImages
argument_list|(
specifier|const
name|Option
operator|&
name|opt
argument_list|)
block|;
name|void
name|acceptUI
argument_list|(
name|DomUI
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptImages
argument_list|(
name|DomImages
operator|*
name|images
argument_list|)
block|;
name|void
name|acceptImage
argument_list|(
name|DomImage
operator|*
name|image
argument_list|)
block|;
name|private
operator|:
name|QTextStream
operator|*
name|m_output
block|;
specifier|const
name|Option
operator|&
name|m_option
block|;
name|QDir
name|m_imagesDir
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace CPP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CPPEXTRACTIMAGES_H
end_comment
end_unit
