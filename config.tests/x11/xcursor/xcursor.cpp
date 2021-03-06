begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xcursor/Xcursor.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XCURSOR_LIB_MAJOR
argument_list|)
end_if
begin_define
DECL|macro|XCURSOR_LIB_MAJOR
define|#
directive|define
name|XCURSOR_LIB_MAJOR
value|XCURSOR_MAJOR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XCURSOR_LIB_MINOR
argument_list|)
end_if
begin_define
DECL|macro|XCURSOR_LIB_MINOR
define|#
directive|define
name|XCURSOR_LIB_MINOR
value|XCURSOR_MINOR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|XCURSOR_LIB_MAJOR
operator|==
literal|1
operator|&&
name|XCURSOR_LIB_MINOR
operator|>=
literal|0
end_if
begin_define
DECL|macro|XCURSOR_FOUND
define|#
directive|define
name|XCURSOR_FOUND
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
end_define
begin_error
error|#
directive|error
literal|"Required Xcursor version 1.0 not found."
end_error
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
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
block|{
name|XcursorImage
modifier|*
name|image
decl_stmt|;
name|image
operator|=
literal|0
expr_stmt|;
name|XcursorCursors
modifier|*
name|cursors
decl_stmt|;
name|cursors
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
