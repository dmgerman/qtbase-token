begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_include
include|#
directive|include
file|"wayland-util.h"
end_include
begin_decl_stmt
DECL|variable|wl_xcomposite_requests
specifier|static
specifier|const
name|struct
name|wl_message
name|wl_xcomposite_requests
index|[]
init|=
block|{
block|{
literal|"create_buffer"
block|,
literal|"nuiio"
block|}
block|, }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|wl_xcomposite_events
specifier|static
specifier|const
name|struct
name|wl_message
name|wl_xcomposite_events
index|[]
init|=
block|{
block|{
literal|"root"
block|,
literal|"su"
block|}
block|, }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|wl_xcomposite_interface
name|WL_EXPORT
specifier|const
expr|struct
name|wl_interface
name|wl_xcomposite_interface
operator|=
block|{
literal|"wl_xcomposite"
block|,
literal|1
block|,
name|ARRAY_LENGTH
argument_list|(
name|wl_xcomposite_requests
argument_list|)
block|,
name|wl_xcomposite_requests
block|,
name|ARRAY_LENGTH
argument_list|(
name|wl_xcomposite_events
argument_list|)
block|,
name|wl_xcomposite_events
block|, }
expr_stmt|;
end_expr_stmt
end_unit
