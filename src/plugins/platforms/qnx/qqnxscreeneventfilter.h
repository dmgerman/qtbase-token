begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXSCREENEVENTFILTER_H
end_ifndef
begin_define
DECL|macro|QQNXSCREENEVENTFILTER_H
define|#
directive|define
name|QQNXSCREENEVENTFILTER_H
end_define
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QQnxScreenEventFilter
block|{
name|protected
label|:
operator|~
name|QQnxScreenEventFilter
argument_list|()
block|{}
name|public
operator|:
name|virtual
name|bool
name|handleKeyboardEvent
argument_list|(
argument|int flags
argument_list|,
argument|int sym
argument_list|,
argument|int mod
argument_list|,
argument|int scan
argument_list|,
argument|int cap
argument_list|,
argument|int sequenceId
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
