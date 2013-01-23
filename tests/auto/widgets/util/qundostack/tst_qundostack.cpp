begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QAction>
end_include
begin_include
include|#
directive|include
file|<QUndoStack>
end_include
begin_comment
comment|/****************************************************************************** ** Commands */
end_comment
begin_class
DECL|class|InsertCommand
class|class
name|InsertCommand
super|:
specifier|public
name|QUndoCommand
block|{
public|public:
name|InsertCommand
parameter_list|(
name|QString
modifier|*
name|str
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
specifier|virtual
name|void
name|undo
parameter_list|()
function_decl|;
specifier|virtual
name|void
name|redo
parameter_list|()
function_decl|;
private|private:
DECL|member|m_str
name|QString
modifier|*
name|m_str
decl_stmt|;
DECL|member|m_idx
name|int
name|m_idx
decl_stmt|;
DECL|member|m_text
name|QString
name|m_text
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|RemoveCommand
class|class
name|RemoveCommand
super|:
specifier|public
name|QUndoCommand
block|{
public|public:
name|RemoveCommand
parameter_list|(
name|QString
modifier|*
name|str
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
name|len
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
specifier|virtual
name|void
name|undo
parameter_list|()
function_decl|;
specifier|virtual
name|void
name|redo
parameter_list|()
function_decl|;
private|private:
DECL|member|m_str
name|QString
modifier|*
name|m_str
decl_stmt|;
DECL|member|m_idx
name|int
name|m_idx
decl_stmt|;
DECL|member|m_text
name|QString
name|m_text
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|AppendCommand
class|class
name|AppendCommand
super|:
specifier|public
name|QUndoCommand
block|{
public|public:
name|AppendCommand
parameter_list|(
name|QString
modifier|*
name|str
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|bool
name|_fail_merge
init|=
literal|false
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|~
name|AppendCommand
parameter_list|()
destructor_decl|;
specifier|virtual
name|void
name|undo
parameter_list|()
function_decl|;
specifier|virtual
name|void
name|redo
parameter_list|()
function_decl|;
specifier|virtual
name|int
name|id
parameter_list|()
specifier|const
function_decl|;
specifier|virtual
name|bool
name|mergeWith
parameter_list|(
specifier|const
name|QUndoCommand
modifier|*
name|other
parameter_list|)
function_decl|;
DECL|member|merged
name|bool
name|merged
decl_stmt|;
DECL|member|fail_merge
name|bool
name|fail_merge
decl_stmt|;
DECL|member|delete_cnt
specifier|static
name|int
name|delete_cnt
decl_stmt|;
private|private:
DECL|member|m_str
name|QString
modifier|*
name|m_str
decl_stmt|;
DECL|member|m_text
name|QString
name|m_text
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|IdleCommand
class|class
name|IdleCommand
super|:
specifier|public
name|QUndoCommand
block|{
public|public:
name|IdleCommand
parameter_list|(
name|QUndoCommand
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|~
name|IdleCommand
parameter_list|()
destructor_decl|;
specifier|virtual
name|void
name|undo
parameter_list|()
function_decl|;
specifier|virtual
name|void
name|redo
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|InsertCommand
name|InsertCommand
operator|::
name|InsertCommand
parameter_list|(
name|QString
modifier|*
name|str
parameter_list|,
name|int
name|idx
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QUndoCommand
argument_list|(
name|parent
argument_list|)
block|{
name|QVERIFY
argument_list|(
name|str
operator|->
name|length
argument_list|()
operator|>=
name|idx
argument_list|)
expr_stmt|;
name|setText
argument_list|(
literal|"insert"
argument_list|)
expr_stmt|;
name|m_str
operator|=
name|str
expr_stmt|;
name|m_idx
operator|=
name|idx
expr_stmt|;
name|m_text
operator|=
name|text
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|redo
name|void
name|InsertCommand
operator|::
name|redo
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|m_str
operator|->
name|length
argument_list|()
operator|>=
name|m_idx
argument_list|)
expr_stmt|;
name|m_str
operator|->
name|insert
argument_list|(
name|m_idx
argument_list|,
name|m_text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|undo
name|void
name|InsertCommand
operator|::
name|undo
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|m_str
operator|->
name|mid
argument_list|(
name|m_idx
argument_list|,
name|m_text
operator|.
name|length
argument_list|()
argument_list|)
argument_list|,
name|m_text
argument_list|)
expr_stmt|;
name|m_str
operator|->
name|remove
argument_list|(
name|m_idx
argument_list|,
name|m_text
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|RemoveCommand
name|RemoveCommand
operator|::
name|RemoveCommand
parameter_list|(
name|QString
modifier|*
name|str
parameter_list|,
name|int
name|idx
parameter_list|,
name|int
name|len
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QUndoCommand
argument_list|(
name|parent
argument_list|)
block|{
name|QVERIFY
argument_list|(
name|str
operator|->
name|length
argument_list|()
operator|>=
name|idx
operator|+
name|len
argument_list|)
expr_stmt|;
name|setText
argument_list|(
literal|"remove"
argument_list|)
expr_stmt|;
name|m_str
operator|=
name|str
expr_stmt|;
name|m_idx
operator|=
name|idx
expr_stmt|;
name|m_text
operator|=
name|m_str
operator|->
name|mid
argument_list|(
name|m_idx
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|redo
name|void
name|RemoveCommand
operator|::
name|redo
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|m_str
operator|->
name|mid
argument_list|(
name|m_idx
argument_list|,
name|m_text
operator|.
name|length
argument_list|()
argument_list|)
argument_list|,
name|m_text
argument_list|)
expr_stmt|;
name|m_str
operator|->
name|remove
argument_list|(
name|m_idx
argument_list|,
name|m_text
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|undo
name|void
name|RemoveCommand
operator|::
name|undo
parameter_list|()
block|{
name|QVERIFY
argument_list|(
name|m_str
operator|->
name|length
argument_list|()
operator|>=
name|m_idx
argument_list|)
expr_stmt|;
name|m_str
operator|->
name|insert
argument_list|(
name|m_idx
argument_list|,
name|m_text
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|member|delete_cnt
name|int
name|AppendCommand
operator|::
name|delete_cnt
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|AppendCommand
name|AppendCommand
operator|::
name|AppendCommand
parameter_list|(
name|QString
modifier|*
name|str
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|bool
name|_fail_merge
parameter_list|,
name|QUndoCommand
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QUndoCommand
argument_list|(
name|parent
argument_list|)
block|{
name|setText
argument_list|(
literal|"append"
argument_list|)
expr_stmt|;
name|m_str
operator|=
name|str
expr_stmt|;
name|m_text
operator|=
name|text
expr_stmt|;
name|merged
operator|=
literal|false
expr_stmt|;
name|fail_merge
operator|=
name|_fail_merge
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~AppendCommand
name|AppendCommand
operator|::
name|~
name|AppendCommand
parameter_list|()
block|{
operator|++
name|delete_cnt
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|redo
name|void
name|AppendCommand
operator|::
name|redo
parameter_list|()
block|{
name|m_str
operator|->
name|append
argument_list|(
name|m_text
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|undo
name|void
name|AppendCommand
operator|::
name|undo
parameter_list|()
block|{
name|QCOMPARE
argument_list|(
name|m_str
operator|->
name|mid
argument_list|(
name|m_str
operator|->
name|length
argument_list|()
operator|-
name|m_text
operator|.
name|length
argument_list|()
argument_list|)
argument_list|,
name|m_text
argument_list|)
expr_stmt|;
name|m_str
operator|->
name|truncate
argument_list|(
name|m_str
operator|->
name|length
argument_list|()
operator|-
name|m_text
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|id
name|int
name|AppendCommand
operator|::
name|id
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|mergeWith
name|bool
name|AppendCommand
operator|::
name|mergeWith
parameter_list|(
specifier|const
name|QUndoCommand
modifier|*
name|other
parameter_list|)
block|{
if|if
condition|(
name|other
operator|->
name|id
argument_list|()
operator|!=
name|id
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|fail_merge
condition|)
return|return
literal|false
return|;
name|m_text
operator|+=
cast|static_cast
argument_list|<
specifier|const
name|AppendCommand
operator|*
argument_list|>
argument_list|(
name|other
argument_list|)
operator|->
name|m_text
expr_stmt|;
name|merged
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_constructor
DECL|function|IdleCommand
name|IdleCommand
operator|::
name|IdleCommand
parameter_list|(
name|QUndoCommand
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QUndoCommand
argument_list|(
name|parent
argument_list|)
block|{
comment|// "idle-item" goes to QUndoStack::{redo,undo}Text
comment|// "idle-action" goes to all other places (e.g. QUndoView)
name|setText
argument_list|(
literal|"idle-item\nidle-action"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~IdleCommand
name|IdleCommand
operator|::
name|~
name|IdleCommand
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|redo
name|void
name|IdleCommand
operator|::
name|redo
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|undo
name|void
name|IdleCommand
operator|::
name|undo
parameter_list|()
block|{ }
end_function
begin_comment
comment|/****************************************************************************** ** tst_QUndoStack */
end_comment
begin_class
DECL|class|tst_QUndoStack
class|class
name|tst_QUndoStack
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QUndoStack
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|undoRedo
parameter_list|()
function_decl|;
name|void
name|setIndex
parameter_list|()
function_decl|;
name|void
name|setClean
parameter_list|()
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|childCommand
parameter_list|()
function_decl|;
name|void
name|macroBeginEnd
parameter_list|()
function_decl|;
name|void
name|compression
parameter_list|()
function_decl|;
name|void
name|undoLimit
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
name|void
name|commandTextFormat
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|separateUndoText
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QUndoStack
name|tst_QUndoStack
operator|::
name|tst_QUndoStack
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|glue
specifier|static
name|QString
name|glue
parameter_list|(
specifier|const
name|QString
modifier|&
name|s1
parameter_list|,
specifier|const
name|QString
modifier|&
name|s2
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
name|result
operator|.
name|append
argument_list|(
name|s1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|s1
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|s2
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|.
name|append
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|result
operator|.
name|append
argument_list|(
name|s2
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|checkState
specifier|static
name|void
name|checkState
parameter_list|(
name|QSignalSpy
modifier|&
name|redoTextChangedSpy
parameter_list|,
name|QSignalSpy
modifier|&
name|canRedoChangedSpy
parameter_list|,
name|QSignalSpy
modifier|&
name|undoTextChangedSpy
parameter_list|,
name|QAction
modifier|*
specifier|const
name|redoAction
parameter_list|,
name|QAction
modifier|*
specifier|const
name|undoAction
parameter_list|,
name|QSignalSpy
modifier|&
name|canUndoChangedSpy
parameter_list|,
name|QSignalSpy
modifier|&
name|cleanChangedSpy
parameter_list|,
name|QSignalSpy
modifier|&
name|indexChangedSpy
parameter_list|,
name|QUndoStack
modifier|&
name|stack
parameter_list|,
specifier|const
name|bool
name|_clean
parameter_list|,
specifier|const
name|int
name|_count
parameter_list|,
specifier|const
name|int
name|_index
parameter_list|,
specifier|const
name|bool
name|_canUndo
parameter_list|,
specifier|const
name|QString
modifier|&
name|_undoText
parameter_list|,
specifier|const
name|bool
name|_canRedo
parameter_list|,
specifier|const
name|QString
modifier|&
name|_redoText
parameter_list|,
specifier|const
name|bool
name|_cleanChanged
parameter_list|,
specifier|const
name|bool
name|_indexChanged
parameter_list|,
specifier|const
name|bool
name|_undoChanged
parameter_list|,
specifier|const
name|bool
name|_redoChanged
parameter_list|)
block|{
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|count
argument_list|()
argument_list|,
name|_count
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|isClean
argument_list|()
argument_list|,
name|_clean
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|index
argument_list|()
argument_list|,
name|_index
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|canUndo
argument_list|()
argument_list|,
name|_canUndo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|undoText
argument_list|()
argument_list|,
name|QString
argument_list|(
name|_undoText
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|canRedo
argument_list|()
argument_list|,
name|_canRedo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|redoText
argument_list|()
argument_list|,
name|QString
argument_list|(
name|_redoText
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|_indexChanged
condition|)
block|{
name|QCOMPARE
argument_list|(
name|indexChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|indexChangedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|_index
argument_list|)
expr_stmt|;
name|indexChangedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|indexChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|_cleanChanged
condition|)
block|{
name|QCOMPARE
argument_list|(
name|cleanChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cleanChangedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toBool
argument_list|()
argument_list|,
name|_clean
argument_list|)
expr_stmt|;
name|cleanChangedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|cleanChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|_undoChanged
condition|)
block|{
name|QCOMPARE
argument_list|(
name|canUndoChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|canUndoChangedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toBool
argument_list|()
argument_list|,
name|_canUndo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undoAction
operator|->
name|isEnabled
argument_list|()
argument_list|,
name|_canUndo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undoTextChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undoTextChangedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
name|_undoText
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undoAction
operator|->
name|text
argument_list|()
argument_list|,
name|glue
argument_list|(
literal|"foo"
argument_list|,
name|_undoText
argument_list|)
argument_list|)
expr_stmt|;
name|canUndoChangedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|undoTextChangedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|canUndoChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undoTextChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|_redoChanged
condition|)
block|{
name|QCOMPARE
argument_list|(
name|canRedoChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|canRedoChangedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toBool
argument_list|()
argument_list|,
name|_canRedo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redoAction
operator|->
name|isEnabled
argument_list|()
argument_list|,
name|_canRedo
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redoTextChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redoTextChangedSpy
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
name|_redoText
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redoAction
operator|->
name|text
argument_list|()
argument_list|,
name|glue
argument_list|(
literal|"bar"
argument_list|,
name|_redoText
argument_list|)
argument_list|)
expr_stmt|;
name|canRedoChangedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|redoTextChangedSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|canRedoChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redoTextChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|undoRedo
name|void
name|tst_QUndoStack
operator|::
name|undoRedo
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undoAction
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redoAction
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|indexChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|cleanChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canUndoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|undoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canRedoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|redoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|str
decl_stmt|;
comment|// push, undo, redo
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
comment|// nothing to undo
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|2
argument_list|,
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|redo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|redo
argument_list|()
expr_stmt|;
comment|// nothing to redo
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
comment|// nothing to undo
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
comment|// push after undo - check that undone commands get deleted
name|stack
operator|.
name|redo
argument_list|()
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|RemoveCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"heo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count - still 2, last command got deleted
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"remove"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"remove"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"goodbye"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"goodbye"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count - two commands got deleted
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
block|}
end_function
begin_function
DECL|function|setIndex
name|void
name|tst_QUndoStack
operator|::
name|setIndex
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undoAction
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redoAction
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|indexChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|cleanChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canUndoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|undoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canRedoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|redoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|str
decl_stmt|;
name|stack
operator|.
name|setIndex
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|// should do nothing
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// should do nothing
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
operator|-
literal|10
argument_list|)
expr_stmt|;
comment|// should do nothing
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|2
argument_list|,
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|// should set index to 2
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
operator|-
literal|10
argument_list|)
expr_stmt|;
comment|// should set index to 0
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
block|}
end_function
begin_function
DECL|function|setClean
name|void
name|tst_QUndoStack
operator|::
name|setClean
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undoAction
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redoAction
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|indexChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|cleanChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canUndoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|undoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canRedoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|redoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|str
decl_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stack
operator|.
name|setClean
argument_list|()
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"goodbye"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stack
operator|.
name|setClean
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"goodbye"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|" cowboy"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"goodbye cowboy"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
comment|// reaching clean state from above
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"goodbye"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|redo
argument_list|()
expr_stmt|;
comment|// reaching clean state from below
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"goodbye"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"foo"
argument_list|)
argument_list|)
expr_stmt|;
comment|// the clean state gets deleted!
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|cleanIndex
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|tst_QUndoStack
operator|::
name|clear
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undoAction
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
name|this
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redoAction
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
name|this
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|indexChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|cleanChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canUndoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|undoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canRedoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|redoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|str
decl_stmt|;
name|stack
operator|.
name|clear
argument_list|()
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|2
argument_list|,
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|str
operator|.
name|clear
argument_list|()
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|2
argument_list|,
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"he123llo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|0
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
block|}
end_function
begin_function
DECL|function|childCommand
name|void
name|tst_QUndoStack
operator|::
name|childCommand
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undoAction
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redoAction
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|indexChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|cleanChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canUndoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|undoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canRedoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|redoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|str
decl_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|QUndoCommand
modifier|*
name|cmd
init|=
operator|new
name|QUndoCommand
argument_list|()
decl_stmt|;
name|cmd
operator|->
name|setText
argument_list|(
literal|"ding"
argument_list|)
expr_stmt|;
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|5
argument_list|,
literal|"world"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
operator|new
name|RemoveCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hellworld"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"ding"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"ding"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|redo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hellworld"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"ding"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
operator|delete
name|undoAction
expr_stmt|;
operator|delete
name|redoAction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|macroBeginEnd
name|void
name|tst_QUndoStack
operator|::
name|macroBeginEnd
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undoAction
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redoAction
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|indexChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|cleanChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canUndoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|undoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canRedoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|redoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|str
decl_stmt|;
name|stack
operator|.
name|beginMacro
argument_list|(
literal|"ding"
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setClean
argument_list|()
expr_stmt|;
comment|// should do nothing
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
comment|// should do nothing
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|redo
argument_list|()
expr_stmt|;
comment|// should do nothing
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// should do nothing
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|endMacro
argument_list|()
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index - endMacro() increments index
literal|true
argument_list|,
comment|// canUndo
literal|"ding"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"h"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"h"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|1
argument_list|,
literal|"owdy"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"howdy"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|3
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"h"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|beginMacro
argument_list|(
literal|"dong"
argument_list|)
expr_stmt|;
comment|// the "owdy" command gets deleted
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|1
argument_list|,
literal|"ello"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hello"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|RemoveCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hlo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|beginMacro
argument_list|(
literal|"dong2"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"hlo"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|RemoveCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ho"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|endMacro
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ho"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|endMacro
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ho"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|3
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"dong"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"h"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"dong"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|""
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"ding"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ho"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|3
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"dong"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"ding"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"insert"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
operator|delete
name|undoAction
expr_stmt|;
operator|delete
name|redoAction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compression
name|void
name|tst_QUndoStack
operator|::
name|compression
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undoAction
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redoAction
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|indexChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|cleanChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canUndoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|undoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canRedoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|redoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|str
decl_stmt|;
name|AppendCommand
operator|::
name|delete_cnt
operator|=
literal|0
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"ene"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ene"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|" due"
argument_list|)
argument_list|)
expr_stmt|;
comment|// #1
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ene due"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|" rike"
argument_list|)
argument_list|)
expr_stmt|;
comment|// #2 should merge
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ene due rike"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// #2 should be deleted
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setClean
argument_list|()
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|" fake"
argument_list|)
argument_list|)
expr_stmt|;
comment|// #3 should NOT merge, since the stack was clean
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ene due rike fake"
argument_list|)
argument_list|)
expr_stmt|;
comment|// and we want to be able to return to this state
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// #3 should not be deleted
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|3
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ene due rike"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"ene"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"insert"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"ma"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
comment|// #4 clean state gets deleted!
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"enema"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// #1 got deleted
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"trix"
argument_list|)
argument_list|)
expr_stmt|;
comment|// #5 should NOT merge
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"enematrix"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|3
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"enema"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
comment|// and now for command compression inside macros
name|stack
operator|.
name|setClean
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"enema"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|beginMacro
argument_list|(
literal|"ding"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"enema"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// #5 gets deleted
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|AppendCommand
modifier|*
name|merge_cmd
init|=
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"top"
argument_list|)
decl_stmt|;
name|stack
operator|.
name|push
argument_list|(
name|merge_cmd
argument_list|)
expr_stmt|;
comment|// #6
name|QCOMPARE
argument_list|(
name|merge_cmd
operator|->
name|merged
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"enematop"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"eja"
argument_list|)
argument_list|)
expr_stmt|;
comment|// #7 should merge
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"enematopeja"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|merge_cmd
operator|->
name|merged
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// #7 gets deleted
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|merge_cmd
operator|->
name|merged
operator|=
literal|false
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|2
argument_list|,
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
comment|// should not merge
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"en123ematopeja"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|merge_cmd
operator|->
name|merged
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|endMacro
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"en123ematopeja"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|3
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"ding"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"enema"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"ding"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|redo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"en123ematopeja"
argument_list|)
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|3
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"ding"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
operator|delete
name|undoAction
expr_stmt|;
operator|delete
name|redoAction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|undoLimit
name|void
name|tst_QUndoStack
operator|::
name|undoLimit
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undoAction
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redoAction
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|indexChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|indexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|cleanChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|cleanChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canUndoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canUndoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|undoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|undoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|canRedoChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|canRedoChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QSignalSpy
name|redoTextChangedSpy
argument_list|(
operator|&
name|stack
argument_list|,
name|SIGNAL
argument_list|(
name|redoTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|AppendCommand
operator|::
name|delete_cnt
operator|=
literal|0
expr_stmt|;
name|QString
name|str
decl_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|undoLimit
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stack
operator|.
name|setUndoLimit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|undoLimit
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"1"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"1"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"2"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"12"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|setClean
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"12"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"3"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"4"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"1234"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"12"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|true
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"3"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|true
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"4"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"1234"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"5"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"12345"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"1234"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"123"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"4"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"1234"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|1
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"5"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"12345"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"6"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
comment|// should be merged
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"123456"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|beginMacro
argument_list|(
literal|"foo"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"123456"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"7"
argument_list|,
literal|true
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"1234567"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"8"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"12345678"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|3
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|false
argument_list|,
comment|// indexChanged
literal|false
argument_list|,
comment|// undoChanged
literal|false
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|endMacro
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"12345678"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|2
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"foo"
argument_list|,
comment|// undoText
literal|false
argument_list|,
comment|// canRedo
literal|""
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"123456"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|1
argument_list|,
comment|// index
literal|true
argument_list|,
comment|// canUndo
literal|"append"
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"foo"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|str
argument_list|,
name|QString
argument_list|(
literal|"1234"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|AppendCommand
operator|::
name|delete_cnt
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|checkState
argument_list|(
name|redoTextChangedSpy
argument_list|,
name|canRedoChangedSpy
argument_list|,
name|undoTextChangedSpy
argument_list|,
name|redoAction
argument_list|,
name|undoAction
argument_list|,
name|canUndoChangedSpy
argument_list|,
name|cleanChangedSpy
argument_list|,
name|indexChangedSpy
argument_list|,
name|stack
argument_list|,
literal|false
argument_list|,
comment|// clean
literal|2
argument_list|,
comment|// count
literal|0
argument_list|,
comment|// index
literal|false
argument_list|,
comment|// canUndo
literal|""
argument_list|,
comment|// undoText
literal|true
argument_list|,
comment|// canRedo
literal|"append"
argument_list|,
comment|// redoText
literal|false
argument_list|,
comment|// cleanChanged
literal|true
argument_list|,
comment|// indexChanged
literal|true
argument_list|,
comment|// undoChanged
literal|true
argument_list|)
expr_stmt|;
comment|// redoChanged
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROCESS
end_ifndef
begin_function
DECL|function|commandTextFormat
name|void
name|tst_QUndoStack
operator|::
name|commandTextFormat
parameter_list|()
block|{
name|QString
name|binDir
init|=
name|QLibraryInfo
operator|::
name|location
argument_list|(
name|QLibraryInfo
operator|::
name|BinariesPath
argument_list|)
decl_stmt|;
if|if
condition|(
name|QProcess
operator|::
name|execute
argument_list|(
name|binDir
operator|+
literal|"/lrelease -version"
argument_list|)
operator|!=
literal|0
condition|)
name|QSKIP
argument_list|(
literal|"lrelease is missing or broken"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QProcess
operator|::
name|execute
argument_list|(
name|binDir
operator|+
literal|"/lrelease testdata/qundostack.ts"
argument_list|)
argument_list|)
expr_stmt|;
name|QTranslator
name|translator
decl_stmt|;
name|QVERIFY
argument_list|(
name|translator
operator|.
name|load
argument_list|(
literal|"testdata/qundostack.qm"
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|installTranslator
argument_list|(
operator|&
name|translator
argument_list|)
expr_stmt|;
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undo_action
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redo_action
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|undo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Undo-default-text"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Redo-default-text"
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|str
decl_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|AppendCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|"foo"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"undo-prefix append undo-suffix"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Redo-default-text"
argument_list|)
argument_list|)
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
operator|new
name|InsertCommand
argument_list|(
operator|&
name|str
argument_list|,
literal|0
argument_list|,
literal|"bar"
argument_list|)
argument_list|)
expr_stmt|;
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"undo-prefix append undo-suffix"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"redo-prefix insert redo-suffix"
argument_list|)
argument_list|)
expr_stmt|;
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Undo-default-text"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"redo-prefix append redo-suffix"
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|removeTranslator
argument_list|(
operator|&
name|translator
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|separateUndoText
name|void
name|tst_QUndoStack
operator|::
name|separateUndoText
parameter_list|()
block|{
name|QUndoStack
name|stack
decl_stmt|;
name|QAction
modifier|*
name|undo_action
init|=
name|stack
operator|.
name|createUndoAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|redo_action
init|=
name|stack
operator|.
name|createRedoAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QUndoCommand
modifier|*
name|command1
init|=
operator|new
name|IdleCommand
argument_list|()
decl_stmt|;
name|QUndoCommand
modifier|*
name|command2
init|=
operator|new
name|IdleCommand
argument_list|()
decl_stmt|;
name|stack
operator|.
name|push
argument_list|(
name|command1
argument_list|)
expr_stmt|;
name|stack
operator|.
name|push
argument_list|(
name|command2
argument_list|)
expr_stmt|;
name|stack
operator|.
name|undo
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|undo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Undo idle-action"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|redo_action
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Redo idle-action"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|command1
operator|->
name|actionText
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"idle-action"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|command1
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"idle-item"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|stack
operator|.
name|text
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"idle-item"
argument_list|)
argument_list|)
expr_stmt|;
name|command1
operator|->
name|setText
argument_list|(
literal|"idle"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|command1
operator|->
name|actionText
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"idle"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|command1
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"idle"
argument_list|)
argument_list|)
expr_stmt|;
name|command1
operator|->
name|setText
argument_list|(
literal|"idle-item\nidle-action"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|command1
operator|->
name|actionText
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"idle-action"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|command1
operator|->
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"idle-item"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QUndoStack
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qundostack.moc"
end_include
end_unit
