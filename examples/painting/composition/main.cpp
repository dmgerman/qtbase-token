begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"composition.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_OPENGL_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|//   Q_INIT_RESOURCE(deform);
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|CompositionWidget
name|compWidget
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QStyle
modifier|*
name|arthurStyle
init|=
operator|new
name|ArthurStyle
argument_list|()
decl_stmt|;
name|compWidget
operator|.
name|setStyle
argument_list|(
name|arthurStyle
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|widgets
init|=
name|compWidget
operator|.
name|findChildren
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QWidget
modifier|*
name|w
decl|,
name|widgets
control|)
name|w
operator|->
name|setStyle
argument_list|(
name|arthurStyle
argument_list|)
expr_stmt|;
name|compWidget
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
