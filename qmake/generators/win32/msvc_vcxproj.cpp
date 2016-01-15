begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"msvc_vcxproj.h"
end_include
begin_include
include|#
directive|include
file|"msbuild_objectmodel.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|VcxprojGenerator
name|VcxprojGenerator
operator|::
name|VcxprojGenerator
parameter_list|()
member_init_list|:
name|VcprojGenerator
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|createProjectWriter
name|VCProjectWriter
modifier|*
name|VcxprojGenerator
operator|::
name|createProjectWriter
parameter_list|()
block|{
return|return
operator|new
name|VCXProjectWriter
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
