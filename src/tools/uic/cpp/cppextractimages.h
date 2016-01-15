begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qdir.h>
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
argument|DomUI *node
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|acceptImages
argument_list|(
argument|DomImages *images
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|acceptImage
argument_list|(
argument|DomImage *image
argument_list|)
name|Q_DECL_OVERRIDE
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
