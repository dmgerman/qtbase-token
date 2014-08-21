begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|UNTERMINATED_FUNCTION_MACRO_H
end_ifndef
begin_define
DECL|macro|UNTERMINATED_FUNCTION_MACRO_H
define|#
directive|define
name|UNTERMINATED_FUNCTION_MACRO_H
end_define
begin_decl_stmt
name|class
name|Dummy
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
block|}
DECL|macro|MACRO
define|#
directive|define
name|MACRO
parameter_list|(
name|arg
parameter_list|)
value|do_something(arg)
DECL|function|foo
specifier|static
name|void
name|foo
argument_list|()
block|{
name|MACRO
argument_list|(
argument|foo }
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// UNTERMINATED_FUNCTION_MACRO_H
end_comment
end_unit
