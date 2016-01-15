begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ERROR_ON_WRONG_NOTIFY_H
end_ifndef
begin_define
DECL|macro|ERROR_ON_WRONG_NOTIFY_H
define|#
directive|define
name|ERROR_ON_WRONG_NOTIFY_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_decl_stmt
name|class
name|ClassWithWrongNOTIFY
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int foo READ foo WRITE setFoo NOTIFY fooChanged
argument_list|)
name|int
name|m_foo
block|;
name|public
operator|:
name|void
name|setFoo
argument_list|(
argument|int i
argument_list|)
block|{
name|m_foo
operator|=
name|i
block|; }
name|int
name|foo
argument_list|()
block|{
return|return
name|m_foo
return|;
block|}
expr|}
block|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ERROR_ON_WRONG_NOTIFY_H
end_comment
end_unit
