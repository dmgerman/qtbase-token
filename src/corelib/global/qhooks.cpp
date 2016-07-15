begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Volker Krause<volker.krause@kdab.com> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhooks_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// Only add to the end, and bump version if you do.
DECL|variable|qtHookData
name|quintptr
name|Q_CORE_EXPORT
name|qtHookData
index|[]
init|=
block|{
literal|3
block|,
comment|// hook data version
name|QHooks
operator|::
name|LastHookIndex
block|,
comment|// size of qtHookData
name|QT_VERSION
block|,
comment|// AddQObject, void(*)(QObject*), called for every constructed QObject
comment|// Note: this is called from the QObject constructor, ie. the sub-class
comment|// constructors haven't run yet.
literal|0
block|,
comment|// RemoveQObject, void(*)(QObject*), called for every destructed QObject
comment|// Note: this is called from the QObject destructor, ie. the object
comment|// you get as an argument is already largely invalid.
literal|0
block|,
comment|// Startup, void(*)(), called once QCoreApplication is operational
literal|0
block|,
comment|// TypeInformationVersion, an integral value, bumped whenever private
comment|// object sizes or member offsets that are used in Qt Creator's
comment|// data structure "pretty printing" change.
comment|//
comment|// The required sizes and offsets are tested in tests/auto/other/toolsupport.
comment|// When this fails and the change was intentional, adjust the test and
comment|// adjust this value here.
literal|3
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_STATIC_ASSERT
argument_list|(
name|QHooks
operator|::
name|LastHookIndex
operator|==
sizeof|sizeof
argument_list|(
name|qtHookData
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|qtHookData
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
