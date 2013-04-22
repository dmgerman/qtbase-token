begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTABLEGENERATOR_H
end_ifndef
begin_define
DECL|macro|QTABLEGENERATOR_H
define|#
directive|define
name|QTABLEGENERATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_define
DECL|macro|QT_KEYSEQUENCE_MAX_LEN
define|#
directive|define
name|QT_KEYSEQUENCE_MAX_LEN
value|6
end_define
begin_struct
DECL|struct|QComposeTableElement
struct|struct
name|QComposeTableElement
block|{
DECL|member|keys
name|uint
name|keys
index|[
name|QT_KEYSEQUENCE_MAX_LEN
index|]
decl_stmt|;
DECL|member|value
name|uint
name|value
decl_stmt|;
DECL|member|comment
name|QString
name|comment
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Compare
block|{
name|public
label|:
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|QComposeTableElement
operator|&
name|lhs
operator|,
specifier|const
name|uint
name|rhs
index|[
name|QT_KEYSEQUENCE_MAX_LEN
index|]
operator|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QT_KEYSEQUENCE_MAX_LEN
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|lhs
operator|.
name|keys
index|[
name|i
index|]
operator|!=
name|rhs
index|[
name|i
index|]
condition|)
return|return
operator|(
name|lhs
operator|.
name|keys
index|[
name|i
index|]
operator|<
name|rhs
index|[
name|i
index|]
operator|)
return|;
block|}
return|return
name|false
return|;
block|}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|QComposeTableElement
operator|&
name|lhs
operator|,
specifier|const
name|QComposeTableElement
operator|&
name|rhs
operator|)
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QT_KEYSEQUENCE_MAX_LEN
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|lhs
operator|.
name|keys
index|[
name|i
index|]
operator|!=
name|rhs
operator|.
name|keys
index|[
name|i
index|]
condition|)
return|return
operator|(
name|lhs
operator|.
name|keys
index|[
name|i
index|]
operator|<
name|rhs
operator|.
name|keys
index|[
name|i
index|]
operator|)
return|;
block|}
return|return
name|false
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|TableGenerator
block|{
name|public
label|:
enum|enum
name|TableState
block|{
name|UnsupportedLocale
block|,
name|EmptyTable
block|,
name|UnknownSystemComposeDir
block|,
name|MissingComposeFile
block|,
name|NoErrors
block|}
enum|;
name|TableGenerator
argument_list|()
expr_stmt|;
operator|~
name|TableGenerator
argument_list|()
expr_stmt|;
name|void
name|parseComposeFile
parameter_list|(
name|QFile
modifier|*
name|composeFile
parameter_list|)
function_decl|;
name|void
name|printComposeTable
argument_list|()
specifier|const
expr_stmt|;
name|void
name|orderComposeTable
parameter_list|()
function_decl|;
name|QList
operator|<
name|QComposeTableElement
operator|>
name|composeTable
argument_list|()
specifier|const
expr_stmt|;
name|TableState
name|tableState
argument_list|()
specifier|const
block|{
return|return
name|m_state
return|;
block|}
name|protected
label|:
name|bool
name|processFile
parameter_list|(
name|QString
name|composeFileName
parameter_list|)
function_decl|;
name|void
name|parseKeySequence
parameter_list|(
name|QString
name|line
parameter_list|)
function_decl|;
name|void
name|parseIncludeInstruction
parameter_list|(
name|QString
name|line
parameter_list|)
function_decl|;
name|void
name|findComposeFile
parameter_list|()
function_decl|;
name|bool
name|findSystemComposeDir
parameter_list|()
function_decl|;
name|QString
name|systemComposeDir
parameter_list|()
function_decl|;
name|ushort
name|keysymToUtf8
parameter_list|(
name|quint32
name|sym
parameter_list|)
function_decl|;
name|quint32
name|stringToKeysym
parameter_list|(
name|QString
name|keysymName
parameter_list|)
function_decl|;
name|void
name|readLocaleMappings
parameter_list|()
function_decl|;
name|void
name|initPossibleLocations
parameter_list|()
function_decl|;
name|bool
name|cleanState
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|m_state
operator|&
name|NoErrors
operator|)
operator|==
name|NoErrors
operator|)
return|;
block|}
name|QString
name|locale
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QList
operator|<
name|QComposeTableElement
operator|>
name|m_composeTable
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|m_localeToTable
expr_stmt|;
name|TableState
name|m_state
decl_stmt|;
name|QString
name|m_systemComposeDir
decl_stmt|;
name|QList
operator|<
name|QString
operator|>
name|m_possibleLocations
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTABLEGENERATOR_H
end_comment
end_unit
