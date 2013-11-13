begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2013 Aleix Pol Gonzalez<aleixpol@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLLATOR_H
end_ifndef
begin_define
DECL|macro|QCOLLATOR_H
define|#
directive|define
name|QCOLLATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCollatorPrivate
name|class
name|QCollatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCollatorSortKeyPrivate
name|class
name|QCollatorSortKeyPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QCollatorSortKey
block|{
name|friend
name|class
name|QCollator
decl_stmt|;
name|public
label|:
name|QCollatorSortKey
argument_list|(
specifier|const
name|QCollatorSortKey
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QCollatorSortKey
argument_list|()
expr_stmt|;
name|QCollatorSortKey
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QCollatorSortKey
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QCollatorSortKey
modifier|&
name|operator
init|=
operator|(
name|QCollatorSortKey
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QCollatorSortKey
operator|&
name|key
operator|)
specifier|const
expr_stmt|;
name|int
name|compare
argument_list|(
specifier|const
name|QCollatorSortKey
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|QCollatorSortKey
argument_list|(
name|QCollatorSortKeyPrivate
operator|*
argument_list|)
expr_stmt|;
name|QSharedDataPointer
operator|<
name|QCollatorSortKeyPrivate
operator|>
name|d
expr_stmt|;
name|private
label|:
name|QCollatorSortKey
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QCollator
block|{
name|public
label|:
name|explicit
name|QCollator
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|locale
init|=
name|QLocale
argument_list|()
parameter_list|)
function_decl|;
name|QCollator
argument_list|(
specifier|const
name|QCollator
operator|&
argument_list|)
expr_stmt|;
operator|~
name|QCollator
argument_list|()
expr_stmt|;
name|QCollator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QCollator
operator|&
operator|)
decl_stmt|;
name|void
name|setLocale
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|locale
parameter_list|)
function_decl|;
name|QLocale
name|locale
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|CaseSensitivity
name|caseSensitivity
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCaseSensitivity
argument_list|(
name|Qt
operator|::
name|CaseSensitivity
name|cs
argument_list|)
decl_stmt|;
name|void
name|setNumericMode
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
name|bool
name|numericMode
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setIgnorePunctuation
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
name|bool
name|ignorePunctuation
argument_list|()
specifier|const
expr_stmt|;
name|int
name|compare
argument_list|(
specifier|const
name|QString
operator|&
name|s1
argument_list|,
specifier|const
name|QString
operator|&
name|s2
argument_list|)
decl|const
decl_stmt|;
name|int
name|compare
argument_list|(
specifier|const
name|QStringRef
operator|&
name|s1
argument_list|,
specifier|const
name|QStringRef
operator|&
name|s2
argument_list|)
decl|const
decl_stmt|;
name|int
name|compare
argument_list|(
specifier|const
name|QChar
operator|*
name|s1
argument_list|,
name|int
name|len1
argument_list|,
specifier|const
name|QChar
operator|*
name|s2
argument_list|,
name|int
name|len2
argument_list|)
decl|const
decl_stmt|;
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|QString
operator|&
name|s1
operator|,
specifier|const
name|QString
operator|&
name|s2
operator|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
operator|<
literal|0
return|;
block|}
name|QCollatorSortKey
name|sortKey
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|QCollatorPrivate
modifier|*
name|d
decl_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
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
begin_comment
comment|// QCOLLATOR_P_H
end_comment
end_unit
