begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Intel Corporation ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<sys/eventfd.h>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|eventfd_t
name|value
decl_stmt|;
name|int
name|fd
init|=
name|eventfd
argument_list|(
literal|0
argument_list|,
name|EFD_CLOEXEC
argument_list|)
decl_stmt|;
name|eventfd_read
argument_list|(
name|fd
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
name|eventfd_write
argument_list|(
name|fd
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
