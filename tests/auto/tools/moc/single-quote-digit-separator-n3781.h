begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Stephen Kelly<stephen.kelly@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_decl_stmt
name|class
name|KDAB
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
comment|// C++1y allows use of single quote as a digit separator, useful for large
comment|// numbers. http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3781.pdf
comment|// Ensure that moc does not get confused with this.
expr|enum
name|Salaries
block|{
name|Steve
ifdef|#
directive|ifdef
name|Q_MOC_RUN
operator|=
literal|1
literal|'234'
literal|567
endif|#
directive|endif
block|}
block|;
name|Q_ENUMS
argument_list|(
argument|Salaries
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
end_unit
