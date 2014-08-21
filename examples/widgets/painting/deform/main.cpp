begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"pathdeform.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
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
name|Q_INIT_RESOURCE
argument_list|(
name|deform
argument_list|)
expr_stmt|;
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|bool
name|smallScreen
init|=
name|QApplication
operator|::
name|arguments
argument_list|()
operator|.
name|contains
argument_list|(
literal|"-small-screen"
argument_list|)
decl_stmt|;
name|PathDeformWidget
name|deformWidget
argument_list|(
literal|0
argument_list|,
name|smallScreen
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
name|deformWidget
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
name|deformWidget
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
if|if
condition|(
name|smallScreen
condition|)
name|deformWidget
operator|.
name|showFullScreen
argument_list|()
expr_stmt|;
else|else
name|deformWidget
operator|.
name|show
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|QApplication
operator|::
name|setNavigationMode
argument_list|(
name|Qt
operator|::
name|NavigationModeCursorAuto
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
