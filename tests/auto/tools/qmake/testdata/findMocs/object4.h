begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_comment
comment|/*/<-- Inside a comment  class Object4 : public QObject {     Q_OBJECT };  Comment ends there --> /*/
end_comment
begin_comment
comment|// Now we poison moc, just to make sure this doesn't get moc'ed :)
end_comment
begin_decl_stmt
name|class
name|NonMocObject4
comment|/*  : QObject */
block|{
comment|/* qmake ignore Q_OBJECT */
name|Q_OBJECT
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
end_unit
