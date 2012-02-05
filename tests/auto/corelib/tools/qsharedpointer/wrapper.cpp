begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
