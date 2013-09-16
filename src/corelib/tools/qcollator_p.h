begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2013 Aleix Pol Gonzalez<aleixpol@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLLATOR_P_H
end_ifndef
begin_define
DECL|macro|QCOLLATOR_P_H
define|#
directive|define
name|QCOLLATOR_P_H
end_define
begin_include
include|#
directive|include
file|"qcollator.h"
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_ICU
end_ifdef
begin_include
include|#
directive|include
file|<unicode/ucol.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<CoreServices/CoreServices.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|QT_USE_ICU
end_ifdef
begin_typedef
DECL|typedef|CollatorType
typedef|typedef
name|UCollator
modifier|*
name|CollatorType
typedef|;
end_typedef
begin_typedef
DECL|typedef|CollatorKeyType
typedef|typedef
name|QByteArray
name|CollatorKeyType
typedef|;
end_typedef
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_OSX
argument_list|)
end_elif
begin_typedef
typedef|typedef
name|QVector
operator|<
name|UCCollationValue
operator|>
name|CollatorKeyType
expr_stmt|;
end_typedef
begin_struct
struct|struct
name|CollatorType
block|{
name|CollatorType
argument_list|(
argument|int opt
argument_list|)
block|:
name|collator
argument_list|(
name|NULL
argument_list|)
operator|,
name|options
argument_list|(
argument|opt
argument_list|)
block|{}
name|CollatorRef
name|collator
expr_stmt|;
name|UInt32
name|options
decl_stmt|;
block|}
struct|;
end_struct
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_elif
begin_typedef
typedef|typedef
name|QString
name|CollatorKeyType
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|CollatorType
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_comment
comment|//posix
end_comment
begin_typedef
typedef|typedef
name|QVector
operator|<
name|wchar_t
operator|>
name|CollatorKeyType
expr_stmt|;
end_typedef
begin_typedef
typedef|typedef
name|int
name|CollatorType
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QCollatorPrivate
block|{
name|public
label|:
name|QAtomicInt
name|ref
decl_stmt|;
name|QLocale
name|locale
decl_stmt|;
name|CollatorType
name|collator
decl_stmt|;
name|void
name|clear
parameter_list|()
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|collator
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|QCollatorPrivate
argument_list|()
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|collator
argument_list|(
literal|0
argument_list|)
block|{
name|cleanup
argument_list|()
block|; }
operator|~
name|QCollatorPrivate
argument_list|()
block|{
name|cleanup
argument_list|()
block|; }
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QCollatorPrivate
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QCollatorSortKeyPrivate
range|:
name|public
name|QSharedData
block|{
name|friend
name|class
name|QCollator
block|;
name|public
operator|:
name|QCollatorSortKeyPrivate
argument_list|(
specifier|const
name|CollatorKeyType
operator|&
name|key
argument_list|)
operator|:
name|QSharedData
argument_list|()
block|,
name|m_key
argument_list|(
argument|key
argument_list|)
block|{     }
name|CollatorKeyType
name|m_key
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QCollatorSortKeyPrivate
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOLLATOR_P_H
end_comment
end_unit
