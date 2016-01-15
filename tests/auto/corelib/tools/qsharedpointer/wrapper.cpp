begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_SHAREDPOINTER_TRACK_POINTERS
end_ifdef
begin_undef
DECL|macro|QT_SHAREDPOINTER_TRACK_POINTERS
undef|#
directive|undef
name|QT_SHAREDPOINTER_TRACK_POINTERS
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|"wrapper.h"
end_include
begin_constructor
DECL|function|Wrapper
name|Wrapper
operator|::
name|Wrapper
parameter_list|(
specifier|const
name|QSharedPointer
argument_list|<
name|int
argument_list|>
modifier|&
name|value
parameter_list|)
member_init_list|:
name|ptr
argument_list|(
name|value
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~Wrapper
name|Wrapper
operator|::
name|~
name|Wrapper
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|create
name|Wrapper
name|Wrapper
operator|::
name|create
parameter_list|()
block|{
return|return
name|Wrapper
argument_list|(
name|QSharedPointer
argument_list|<
name|int
argument_list|>
argument_list|(
operator|new
name|int
argument_list|(
operator|-
literal|47
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
end_unit
