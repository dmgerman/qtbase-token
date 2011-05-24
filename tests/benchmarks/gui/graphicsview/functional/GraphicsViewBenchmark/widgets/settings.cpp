begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"settings.h"
end_include
begin_constructor
DECL|function|Settings
name|Settings
operator|::
name|Settings
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
member_init_list|,
name|m_scriptName
argument_list|()
member_init_list|,
name|m_outputFileName
argument_list|()
member_init_list|,
name|m_resultFormat
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_size
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
member_init_list|,
name|m_angle
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_listItemCount
argument_list|(
literal|200
argument_list|)
member_init_list|,
name|m_options
argument_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~Settings
name|Settings
operator|::
name|~
name|Settings
parameter_list|()
block|{ }
end_destructor
end_unit
