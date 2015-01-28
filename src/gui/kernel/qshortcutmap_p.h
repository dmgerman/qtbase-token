begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSHORTCUTMAP_P_H
end_ifndef
begin_define
DECL|macro|QSHORTCUTMAP_P_H
define|#
directive|define
name|QSHORTCUTMAP_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtGui/qkeysequence.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qscopedpointer.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
comment|// To enable dump output uncomment below
comment|//#define Dump_QShortcutMap
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QShortcutEntry
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QShortcutMapPrivate
name|class
name|QShortcutMapPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QShortcutMap
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QShortcutMap
argument_list|)
name|public
label|:
name|QShortcutMap
argument_list|()
expr_stmt|;
operator|~
name|QShortcutMap
argument_list|()
expr_stmt|;
typedef|typedef
name|bool
argument_list|(
argument|*ContextMatcher
argument_list|)
operator|(
name|QObject
operator|*
name|object
operator|,
name|Qt
operator|::
name|ShortcutContext
name|context
operator|)
expr_stmt|;
name|int
name|addShortcut
argument_list|(
name|QObject
operator|*
name|owner
argument_list|,
specifier|const
name|QKeySequence
operator|&
name|key
argument_list|,
name|Qt
operator|::
name|ShortcutContext
name|context
argument_list|,
name|ContextMatcher
name|matcher
argument_list|)
decl_stmt|;
name|int
name|removeShortcut
parameter_list|(
name|int
name|id
parameter_list|,
name|QObject
modifier|*
name|owner
parameter_list|,
specifier|const
name|QKeySequence
modifier|&
name|key
init|=
name|QKeySequence
argument_list|()
parameter_list|)
function_decl|;
name|int
name|setShortcutEnabled
parameter_list|(
name|bool
name|enable
parameter_list|,
name|int
name|id
parameter_list|,
name|QObject
modifier|*
name|owner
parameter_list|,
specifier|const
name|QKeySequence
modifier|&
name|key
init|=
name|QKeySequence
argument_list|()
parameter_list|)
function_decl|;
name|int
name|setShortcutAutoRepeat
parameter_list|(
name|bool
name|on
parameter_list|,
name|int
name|id
parameter_list|,
name|QObject
modifier|*
name|owner
parameter_list|,
specifier|const
name|QKeySequence
modifier|&
name|key
init|=
name|QKeySequence
argument_list|()
parameter_list|)
function_decl|;
name|bool
name|tryShortcutEvent
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QKeyEvent
modifier|*
name|e
parameter_list|)
function_decl|;
name|bool
name|hasShortcutForKeySequence
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|seq
argument_list|)
decl|const
decl_stmt|;
ifdef|#
directive|ifdef
name|Dump_QShortcutMap
name|void
name|dumpMap
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|private
label|:
name|void
name|resetState
parameter_list|()
function_decl|;
name|QKeySequence
operator|::
name|SequenceMatch
name|nextState
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
expr_stmt|;
name|QKeySequence
operator|::
name|SequenceMatch
name|state
argument_list|()
expr_stmt|;
name|void
name|dispatchEvent
parameter_list|(
name|QKeyEvent
modifier|*
name|e
parameter_list|)
function_decl|;
name|QKeySequence
operator|::
name|SequenceMatch
name|find
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
expr_stmt|;
name|QKeySequence
operator|::
name|SequenceMatch
name|matches
argument_list|(
argument|const QKeySequence&seq1
argument_list|,
argument|const QKeySequence&seq2
argument_list|)
specifier|const
expr_stmt|;
name|QVector
operator|<
specifier|const
name|QShortcutEntry
operator|*
operator|>
name|matches
argument_list|()
specifier|const
expr_stmt|;
name|void
name|createNewSequences
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|,
name|QVector
operator|<
name|QKeySequence
operator|>
operator|&
name|ksl
argument_list|)
decl_stmt|;
name|void
name|clearSequence
argument_list|(
name|QVector
operator|<
name|QKeySequence
operator|>
operator|&
name|ksl
argument_list|)
decl_stmt|;
name|int
name|translateModifiers
argument_list|(
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|)
decl_stmt|;
name|QScopedPointer
operator|<
name|QShortcutMapPrivate
operator|>
name|d_ptr
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
comment|// QT_NO_SHORTCUT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSHORTCUTMAP_P_H
end_comment
end_unit
