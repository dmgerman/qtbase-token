begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Volker Krause<volker.krause@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
literal|1
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
