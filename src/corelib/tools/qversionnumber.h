begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2014 Keith Gardner<kreios4004@gmail.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVERSIONNUMBER_H
end_ifndef
begin_define
DECL|macro|QVERSIONNUMBER_H
define|#
directive|define
name|QVERSIONNUMBER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
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
file|<QtCore/qmetatype.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtypeinfo.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVersionNumber
name|class
name|QVersionNumber
decl_stmt|;
end_decl_stmt
begin_function_decl
name|Q_CORE_EXPORT
name|uint
name|qHash
parameter_list|(
specifier|const
name|QVersionNumber
modifier|&
name|key
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QVersionNumber
operator|&
name|version
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QVersionNumber
operator|&
name|version
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QVersionNumber
block|{
name|public
label|:
specifier|inline
name|QVersionNumber
argument_list|()
name|Q_DECL_NOTHROW
operator|:
name|m_segments
argument_list|()
block|{}
comment|// compiler-generated copy/move ctor/assignment operators are ok
specifier|inline
name|explicit
name|QVersionNumber
argument_list|(
argument|const QVector<int>&seg
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|m_segments
argument_list|(
argument|seg
argument_list|)
block|{}
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|explicit
name|QVersionNumber
argument_list|(
argument|QVector<int>&&seg
argument_list|)
name|Q_DECL_NOTHROW
operator|:
name|m_segments
argument_list|(
argument|qMove(seg)
argument_list|)
block|{}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
specifier|inline
name|QVersionNumber
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|int
operator|>
name|args
argument_list|)
operator|:
name|m_segments
argument_list|(
argument|args
argument_list|)
block|{}
endif|#
directive|endif
specifier|inline
name|explicit
name|QVersionNumber
argument_list|(
argument|int maj
argument_list|)
block|{
name|m_segments
operator|.
name|reserve
argument_list|(
literal|1
argument_list|)
block|;
name|m_segments
operator|<<
name|maj
block|; }
specifier|inline
name|explicit
name|QVersionNumber
argument_list|(
argument|int maj
argument_list|,
argument|int min
argument_list|)
block|{
name|m_segments
operator|.
name|reserve
argument_list|(
literal|2
argument_list|)
block|;
name|m_segments
operator|<<
name|maj
operator|<<
name|min
block|; }
specifier|inline
name|explicit
name|QVersionNumber
argument_list|(
argument|int maj
argument_list|,
argument|int min
argument_list|,
argument|int mic
argument_list|)
block|{
name|m_segments
operator|.
name|reserve
argument_list|(
literal|3
argument_list|)
block|;
name|m_segments
operator|<<
name|maj
operator|<<
name|min
operator|<<
name|mic
block|; }
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|m_segments
operator|.
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|isNormalized
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|isNull
argument_list|()
operator|||
name|m_segments
operator|.
name|last
argument_list|()
operator|!=
literal|0
return|;
block|}
specifier|inline
name|int
name|majorVersion
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|segmentAt
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|inline
name|int
name|minorVersion
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|segmentAt
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|inline
name|int
name|microVersion
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|segmentAt
argument_list|(
literal|2
argument_list|)
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_COMPILER_REF_QUALIFIERS
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
comment|// required due to https://gcc.gnu.org/bugzilla/show_bug.cgi?id=61941
pragma|#
directive|pragma
name|push_macro
name|(
literal|"Q_REQUIRED_RESULT"
name|)
DECL|macro|Q_REQUIRED_RESULT
undef|#
directive|undef
name|Q_REQUIRED_RESULT
DECL|macro|Q_REQUIRED_RESULT
define|#
directive|define
name|Q_REQUIRED_RESULT
DECL|macro|Q_REQUIRED_RESULT_pushed
define|#
directive|define
name|Q_REQUIRED_RESULT_pushed
endif|#
directive|endif
specifier|inline
name|QVersionNumber
name|normalized
argument_list|()
specifier|const
operator|&
name|Q_REQUIRED_RESULT
block|{
name|QVector
operator|<
name|int
operator|>
name|segs
argument_list|(
name|m_segments
argument_list|)
block|;
return|return
name|normalizedImpl
argument_list|(
name|segs
argument_list|)
return|;
block|}
specifier|inline
name|QVersionNumber
name|normalized
argument_list|()
operator|&&
name|Q_REQUIRED_RESULT
block|{
return|return
name|normalizedImpl
argument_list|(
name|m_segments
argument_list|)
return|;
block|}
specifier|inline
name|QVector
operator|<
name|int
operator|>
name|segments
argument_list|()
specifier|const
operator|&
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|m_segments
return|;
block|}
specifier|inline
name|QVector
operator|<
name|int
operator|>
name|segments
argument_list|()
operator|&&
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|qMove
argument_list|(
name|m_segments
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|Q_REQUIRED_RESULT_pushed
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"Q_REQUIRED_RESULT"
name|)
endif|#
directive|endif
else|#
directive|else
specifier|inline
name|QVersionNumber
name|normalized
argument_list|()
specifier|const
name|Q_REQUIRED_RESULT
block|{
name|QVector
operator|<
name|int
operator|>
name|segs
argument_list|(
name|m_segments
argument_list|)
block|;
return|return
name|normalizedImpl
argument_list|(
name|segs
argument_list|)
return|;
block|}
specifier|inline
name|QVector
operator|<
name|int
operator|>
name|segments
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|m_segments
return|;
block|}
endif|#
directive|endif
specifier|inline
name|int
name|segmentAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
operator|(
name|m_segments
operator|.
name|size
argument_list|()
operator|>
name|index
operator|)
condition|?
name|m_segments
operator|.
name|at
argument_list|(
name|index
argument_list|)
else|:
literal|0
return|;
block|}
specifier|inline
name|int
name|segmentCount
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
block|{
return|return
name|m_segments
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|isPrefixOf
argument_list|(
specifier|const
name|QVersionNumber
operator|&
name|other
argument_list|)
decl|const
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
decl_stmt|;
specifier|static
name|int
name|compare
argument_list|(
specifier|const
name|QVersionNumber
operator|&
name|v1
argument_list|,
specifier|const
name|QVersionNumber
operator|&
name|v2
argument_list|)
name|Q_DECL_NOTHROW
name|Q_REQUIRED_RESULT
decl_stmt|;
specifier|static
name|Q_DECL_PURE_FUNCTION
name|QVersionNumber
name|commonPrefix
argument_list|(
specifier|const
name|QVersionNumber
operator|&
name|v1
argument_list|,
specifier|const
name|QVersionNumber
operator|&
name|v2
argument_list|)
name|Q_REQUIRED_RESULT
decl_stmt|;
name|QString
name|toString
argument_list|()
specifier|const
name|Q_REQUIRED_RESULT
expr_stmt|;
specifier|static
name|Q_DECL_PURE_FUNCTION
name|QVersionNumber
name|fromString
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|,
name|int
operator|*
name|suffixIndex
operator|=
literal|0
argument_list|)
name|Q_REQUIRED_RESULT
decl_stmt|;
name|private
label|:
specifier|static
name|QVersionNumber
name|normalizedImpl
argument_list|(
name|QVector
operator|<
name|int
operator|>
operator|&
name|segs
argument_list|)
name|Q_REQUIRED_RESULT
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QVersionNumber
operator|&
name|version
operator|)
expr_stmt|;
endif|#
directive|endif
name|friend
name|Q_CORE_EXPORT
name|uint
name|qHash
parameter_list|(
specifier|const
name|QVersionNumber
modifier|&
name|key
parameter_list|,
name|uint
name|seed
parameter_list|)
function_decl|;
name|QVector
operator|<
name|int
operator|>
name|m_segments
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QVersionNumber
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QVersionNumber
operator|&
name|version
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|Q_REQUIRED_RESULT
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QVersionNumber
operator|&
name|lhs
operator|,
specifier|const
name|QVersionNumber
operator|&
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QVersionNumber
operator|::
name|compare
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
operator|>
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_REQUIRED_RESULT
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QVersionNumber
operator|&
name|lhs
operator|,
specifier|const
name|QVersionNumber
operator|&
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QVersionNumber
operator|::
name|compare
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
operator|>=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_REQUIRED_RESULT
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QVersionNumber
operator|&
name|lhs
operator|,
specifier|const
name|QVersionNumber
operator|&
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QVersionNumber
operator|::
name|compare
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
operator|<
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_REQUIRED_RESULT
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QVersionNumber
operator|&
name|lhs
operator|,
specifier|const
name|QVersionNumber
operator|&
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QVersionNumber
operator|::
name|compare
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
operator|<=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_REQUIRED_RESULT
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVersionNumber
operator|&
name|lhs
operator|,
specifier|const
name|QVersionNumber
operator|&
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QVersionNumber
operator|::
name|compare
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_REQUIRED_RESULT
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QVersionNumber
operator|&
name|lhs
operator|,
specifier|const
name|QVersionNumber
operator|&
name|rhs
operator|)
name|Q_DECL_NOTHROW
block|{
return|return
name|QVersionNumber
operator|::
name|compare
argument_list|(
name|lhs
argument_list|,
name|rhs
argument_list|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QVersionNumber
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QVERSIONNUMBER_H
end_comment
end_unit
