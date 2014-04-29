begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDEBUG_H
end_ifndef
begin_define
DECL|macro|QDEBUG_H
define|#
directive|define
name|QDEBUG_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qalgorithms.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcontiguouscache.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QDebug
block|{
name|friend
name|class
name|QMessageLogger
decl_stmt|;
name|friend
name|class
name|QDebugStateSaverPrivate
decl_stmt|;
struct|struct
name|Stream
block|{
name|Stream
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
operator|:
name|ts
argument_list|(
name|device
argument_list|)
operator|,
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|type
argument_list|(
name|QtDebugMsg
argument_list|)
operator|,
name|space
argument_list|(
name|true
argument_list|)
operator|,
name|message_output
argument_list|(
argument|false
argument_list|)
block|{}
name|Stream
argument_list|(
name|QString
operator|*
name|string
argument_list|)
operator|:
name|ts
argument_list|(
name|string
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
operator|,
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|type
argument_list|(
name|QtDebugMsg
argument_list|)
operator|,
name|space
argument_list|(
name|true
argument_list|)
operator|,
name|message_output
argument_list|(
argument|false
argument_list|)
block|{}
name|Stream
argument_list|(
argument|QtMsgType t
argument_list|)
operator|:
name|ts
argument_list|(
operator|&
name|buffer
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
operator|,
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|type
argument_list|(
name|t
argument_list|)
operator|,
name|space
argument_list|(
name|true
argument_list|)
operator|,
name|message_output
argument_list|(
argument|true
argument_list|)
block|{}
name|QTextStream
name|ts
expr_stmt|;
name|QString
name|buffer
decl_stmt|;
name|int
name|ref
decl_stmt|;
name|QtMsgType
name|type
decl_stmt|;
name|bool
name|space
decl_stmt|;
name|bool
name|message_output
decl_stmt|;
name|QMessageLogContext
name|context
decl_stmt|;
block|}
modifier|*
name|stream
struct|;
name|public
label|:
specifier|inline
name|QDebug
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
operator|:
name|stream
argument_list|(
argument|new Stream(device)
argument_list|)
block|{}
specifier|inline
name|QDebug
argument_list|(
name|QString
operator|*
name|string
argument_list|)
operator|:
name|stream
argument_list|(
argument|new Stream(string)
argument_list|)
block|{}
specifier|inline
name|QDebug
argument_list|(
argument|QtMsgType t
argument_list|)
operator|:
name|stream
argument_list|(
argument|new Stream(t)
argument_list|)
block|{}
specifier|inline
name|QDebug
argument_list|(
specifier|const
name|QDebug
operator|&
name|o
argument_list|)
operator|:
name|stream
argument_list|(
argument|o.stream
argument_list|)
block|{
operator|++
name|stream
operator|->
name|ref
block|; }
specifier|inline
name|QDebug
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QDebug
operator|&
name|other
operator|)
expr_stmt|;
operator|~
name|QDebug
argument_list|()
expr_stmt|;
specifier|inline
name|void
name|swap
parameter_list|(
name|QDebug
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|stream
argument_list|,
name|other
operator|.
name|stream
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QDebug
modifier|&
name|space
parameter_list|()
block|{
name|stream
operator|->
name|space
operator|=
name|true
expr_stmt|;
name|stream
operator|->
name|ts
operator|<<
literal|' '
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
modifier|&
name|nospace
parameter_list|()
block|{
name|stream
operator|->
name|space
operator|=
name|false
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
modifier|&
name|maybeSpace
parameter_list|()
block|{
if|if
condition|(
name|stream
operator|->
name|space
condition|)
name|stream
operator|->
name|ts
operator|<<
literal|' '
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|autoInsertSpaces
argument_list|()
specifier|const
block|{
return|return
name|stream
operator|->
name|space
return|;
block|}
name|void
name|setAutoInsertSpaces
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|stream
operator|->
name|space
operator|=
name|b
expr_stmt|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QChar
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
literal|'\''
operator|<<
name|t
operator|<<
literal|'\''
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|bool
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
operator|(
name|t
operator|?
literal|"true"
operator|:
literal|"false"
operator|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|char
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|signed
name|short
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|short
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|signed
name|int
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|int
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|signed
name|long
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|unsigned
name|long
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|qint64
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|quint64
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|float
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|double
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|char
operator|*
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
name|t
argument_list|)
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QString
operator|&
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
literal|'\"'
operator|<<
name|t
operator|<<
literal|'\"'
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QStringRef
operator|&
name|t
operator|)
block|{
return|return
name|operator
operator|<<
operator|(
name|t
operator|.
name|toString
argument_list|()
operator|)
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QLatin1String
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
literal|'\"'
operator|<<
name|t
operator|<<
literal|'\"'
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QByteArray
operator|&
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
literal|'\"'
operator|<<
name|t
operator|<<
literal|'\"'
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|void
operator|*
name|t
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|t
block|;
return|return
name|maybeSpace
argument_list|()
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QTextStreamFunction
name|f
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|f
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QTextStreamManipulator
name|m
operator|)
block|{
name|stream
operator|->
name|ts
operator|<<
name|m
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QDebug
argument_list|)
end_macro
begin_decl_stmt
name|class
name|QDebugStateSaverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QDebugStateSaver
block|{
name|public
label|:
name|QDebugStateSaver
argument_list|(
name|QDebug
operator|&
name|dbg
argument_list|)
expr_stmt|;
operator|~
name|QDebugStateSaver
argument_list|()
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDebugStateSaver
argument_list|)
name|QScopedPointer
operator|<
name|QDebugStateSaverPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QNoDebug
block|{
name|public
label|:
specifier|inline
name|QNoDebug
operator|&
name|operator
operator|<<
operator|(
name|QTextStreamFunction
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
operator|&
name|operator
operator|<<
operator|(
name|QTextStreamManipulator
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|space
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|nospace
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|QNoDebug
modifier|&
name|maybeSpace
parameter_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QNoDebug
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
operator|)
block|{
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QDebug
operator|&
name|QDebug
operator|::
name|operator
operator|=
operator|(
specifier|const
name|QDebug
operator|&
name|other
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|other
condition|)
block|{
name|QDebug
name|copy
parameter_list|(
name|other
parameter_list|)
function_decl|;
name|qSwap
argument_list|(
name|stream
argument_list|,
name|copy
operator|.
name|stream
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|FORCE_UREF
argument_list|)
end_if
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QList
operator|<
name|T
operator|>
operator|&
name|list
operator|)
else|#
directive|else
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QList
operator|<
name|T
operator|>
operator|&
name|list
operator|)
endif|#
directive|endif
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|'('
block|;
for|for
control|(
name|typename
name|QList
operator|<
name|T
operator|>
operator|::
name|size_type
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
condition|)
name|debug
operator|<<
literal|", "
expr_stmt|;
name|debug
operator|<<
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|FORCE_UREF
argument_list|)
end_if
begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|&
name|vec
operator|)
else|#
directive|else
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QVector
operator|<
name|T
operator|>
operator|&
name|vec
operator|)
endif|#
directive|endif
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QVector"
block|;
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
block|;
return|return
name|operator
operator|<<
operator|(
name|debug
operator|,
name|vec
operator|.
name|toList
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|FORCE_UREF
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
name|class
name|aKey
operator|,
name|class
name|aT
operator|>
DECL|function|operator
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QMap
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|&
name|map
operator|)
else|#
directive|else
name|template
operator|<
name|class
name|aKey
operator|,
name|class
name|aT
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QMap
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|&
name|map
operator|)
endif|#
directive|endif
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QMap("
block|;
for|for
control|(
name|typename
name|QMap
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|::
name|const_iterator
name|it
operator|=
name|map
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|map
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|debug
operator|<<
literal|'('
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
literal|", "
operator|<<
name|it
operator|.
name|value
argument_list|()
operator|<<
literal|')'
expr_stmt|;
block|}
name|debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|FORCE_UREF
argument_list|)
end_if
begin_expr_stmt
unit|template
DECL|variable|aKey
operator|<
name|class
name|aKey
operator|,
name|class
name|aT
operator|>
DECL|function|operator
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QHash
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|&
name|hash
operator|)
else|#
directive|else
name|template
operator|<
name|class
name|aKey
operator|,
name|class
name|aT
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QHash
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|&
name|hash
operator|)
endif|#
directive|endif
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QHash("
block|;
for|for
control|(
name|typename
name|QHash
operator|<
name|aKey
operator|,
name|aT
operator|>
operator|::
name|const_iterator
name|it
operator|=
name|hash
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|hash
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
name|debug
operator|<<
literal|'('
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
literal|", "
operator|<<
name|it
operator|.
name|value
argument_list|()
operator|<<
literal|')'
expr_stmt|;
name|debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|FORCE_UREF
argument_list|)
end_if
begin_expr_stmt
unit|template
DECL|variable|T1
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
DECL|function|operator
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|pair
operator|)
else|#
directive|else
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QPair
operator|<
name|T1
operator|,
name|T2
operator|>
operator|&
name|pair
operator|)
endif|#
directive|endif
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QPair("
operator|<<
name|pair
operator|.
name|first
operator|<<
literal|','
operator|<<
name|pair
operator|.
name|second
operator|<<
literal|')'
block|;
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
block|;
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|operator
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QSet
operator|<
name|T
operator|>
operator|&
name|set
operator|)
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QSet"
block|;
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
block|;
return|return
name|operator
operator|<<
operator|(
name|debug
operator|,
name|set
operator|.
name|toList
argument_list|()
operator|)
return|;
block|}
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|FORCE_UREF
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|cache
operator|)
else|#
directive|else
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QContiguousCache
operator|<
name|T
operator|>
operator|&
name|cache
operator|)
endif|#
directive|endif
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QContiguousCache("
block|;
for|for
control|(
name|int
name|i
init|=
name|cache
operator|.
name|firstIndex
argument_list|()
init|;
name|i
operator|<=
name|cache
operator|.
name|lastIndex
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|debug
operator|<<
name|cache
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|cache
operator|.
name|lastIndex
argument_list|()
condition|)
name|debug
operator|<<
literal|", "
expr_stmt|;
block|}
name|debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|FORCE_UREF
argument_list|)
end_if
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
DECL|function|operator
specifier|inline
name|QDebug
operator|&
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QFlags
operator|<
name|T
operator|>
operator|&
name|flags
operator|)
else|#
directive|else
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QFlags
operator|<
name|T
operator|>
operator|&
name|flags
operator|)
endif|#
directive|endif
block|{
specifier|const
name|bool
name|oldSetting
operator|=
name|debug
operator|.
name|autoInsertSpaces
argument_list|()
block|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QFlags("
block|;
name|bool
name|needSeparator
operator|=
name|false
block|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|8
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|flags
operator|.
name|testFlag
argument_list|(
name|T
argument_list|(
literal|1
operator|<<
name|i
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|needSeparator
condition|)
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|'|'
expr_stmt|;
else|else
name|needSeparator
operator|=
name|true
expr_stmt|;
name|debug
operator|.
name|nospace
argument_list|()
operator|<<
literal|"0x"
operator|<<
name|QByteArray
operator|::
name|number
argument_list|(
argument|typename QFlags<T>::Int(
literal|1
argument|)<< i
argument_list|,
literal|16
argument_list|)
operator|.
name|constData
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}     debug
operator|<<
literal|')'
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|debug
operator|.
name|setAutoInsertSpaces
argument_list|(
name|oldSetting
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|debug
operator|.
name|maybeSpace
argument_list|()
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QDEBUG_H
end_comment
end_unit
