begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIMPLEX_P_H
end_ifndef
begin_define
DECL|macro|QSIMPLEX_P_H
define|#
directive|define
name|QSIMPLEX_P_H
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
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpair.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QSimplexVariable
struct|struct
name|QSimplexVariable
block|{
DECL|function|QSimplexVariable
name|QSimplexVariable
argument_list|()
operator|:
name|result
argument_list|(
literal|0
argument_list|)
operator|,
name|index
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|result
name|qreal
name|result
expr_stmt|;
DECL|member|index
name|int
name|index
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|/*!   \internal    Representation of a LP constraint like:      (c1 * X1) + (c2 * X2) + ...  =  K                              or<=  K                              or>=  K      Where (ci, Xi) are the pairs in "variables" and K the real "constant". */
end_comment
begin_struct
DECL|struct|QSimplexConstraint
struct|struct
name|QSimplexConstraint
block|{
DECL|function|QSimplexConstraint
name|QSimplexConstraint
argument_list|()
operator|:
name|constant
argument_list|(
literal|0
argument_list|)
operator|,
name|ratio
argument_list|(
name|Equal
argument_list|)
operator|,
name|artificial
argument_list|(
literal|0
argument_list|)
block|{}
expr|enum
DECL|enum|Ratio
name|Ratio
block|{
DECL|enumerator|LessOrEqual
name|LessOrEqual
operator|=
literal|0
block|,
DECL|enumerator|Equal
name|Equal
block|,
DECL|enumerator|MoreOrEqual
name|MoreOrEqual
block|}
expr_stmt|;
DECL|member|QSimplexVariable
DECL|member|variables
name|QHash
operator|<
name|QSimplexVariable
operator|*
operator|,
name|qreal
operator|>
name|variables
expr_stmt|;
DECL|member|constant
name|qreal
name|constant
decl_stmt|;
DECL|member|ratio
name|Ratio
name|ratio
decl_stmt|;
DECL|member|QSimplexVariable
DECL|member|helper
name|QPair
operator|<
name|QSimplexVariable
operator|*
operator|,
name|qreal
operator|>
name|helper
expr_stmt|;
DECL|member|artificial
name|QSimplexVariable
modifier|*
name|artificial
decl_stmt|;
name|void
name|invert
parameter_list|()
function_decl|;
DECL|function|isSatisfied
name|bool
name|isSatisfied
parameter_list|()
block|{
name|qreal
name|leftHandSide
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QHash
operator|<
name|QSimplexVariable
operator|*
operator|,
name|qreal
operator|>
operator|::
name|const_iterator
name|iter
expr_stmt|;
for|for
control|(
name|iter
operator|=
name|variables
operator|.
name|constBegin
argument_list|()
init|;
name|iter
operator|!=
name|variables
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|leftHandSide
operator|+=
name|iter
operator|.
name|value
argument_list|()
operator|*
name|iter
operator|.
name|key
argument_list|()
operator|->
name|result
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|constant
operator|>
literal|0
operator|||
name|qFuzzyCompare
argument_list|(
literal|1
argument_list|,
literal|1
operator|+
name|constant
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|leftHandSide
operator|==
name|constant
operator|)
operator|||
name|qAbs
argument_list|(
name|leftHandSide
operator|-
name|constant
argument_list|)
operator|<
literal|0.0000001
condition|)
return|return
name|true
return|;
switch|switch
condition|(
name|ratio
condition|)
block|{
case|case
name|LessOrEqual
case|:
return|return
name|leftHandSide
operator|<
name|constant
return|;
case|case
name|MoreOrEqual
case|:
return|return
name|leftHandSide
operator|>
name|constant
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
ifdef|#
directive|ifdef
name|QT_DEBUG
DECL|function|toString
name|QString
name|toString
parameter_list|()
block|{
name|QString
name|result
decl_stmt|;
name|result
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"-- QSimplexConstraint %1 --"
argument_list|)
operator|.
name|arg
argument_list|(
name|quintptr
argument_list|(
name|this
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|QHash
operator|<
name|QSimplexVariable
operator|*
operator|,
name|qreal
operator|>
operator|::
name|const_iterator
name|iter
expr_stmt|;
for|for
control|(
name|iter
operator|=
name|variables
operator|.
name|constBegin
argument_list|()
init|;
name|iter
operator|!=
name|variables
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|iter
control|)
block|{
name|result
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"  %1 x %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|iter
operator|.
name|value
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|quintptr
argument_list|(
name|iter
operator|.
name|key
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|16
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|ratio
condition|)
block|{
case|case
name|LessOrEqual
case|:
name|result
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"  (less)<= %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|constant
argument_list|)
expr_stmt|;
break|break;
case|case
name|MoreOrEqual
case|:
name|result
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"  (more)>= %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|constant
argument_list|)
expr_stmt|;
break|break;
default|default:
name|result
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"  (eqal) == %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|constant
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
endif|#
directive|endif
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QSimplex
block|{
name|public
label|:
name|QSimplex
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QSimplex
argument_list|()
expr_stmt|;
name|qreal
name|solveMin
parameter_list|()
function_decl|;
name|qreal
name|solveMax
parameter_list|()
function_decl|;
name|bool
name|setConstraints
argument_list|(
specifier|const
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
name|constraints
argument_list|)
decl_stmt|;
name|void
name|setObjective
parameter_list|(
name|QSimplexConstraint
modifier|*
name|objective
parameter_list|)
function_decl|;
name|void
name|dumpMatrix
parameter_list|()
function_decl|;
name|private
label|:
comment|// Matrix handling
name|qreal
name|valueAt
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|)
function_decl|;
name|void
name|setValueAt
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
name|qreal
name|value
parameter_list|)
function_decl|;
name|void
name|clearRow
parameter_list|(
name|int
name|rowIndex
parameter_list|)
function_decl|;
name|void
name|clearColumns
parameter_list|(
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
name|void
name|combineRows
parameter_list|(
name|int
name|toIndex
parameter_list|,
name|int
name|fromIndex
parameter_list|,
name|qreal
name|factor
parameter_list|)
function_decl|;
comment|// Simplex
name|bool
name|simplifyConstraints
argument_list|(
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
operator|*
name|constraints
argument_list|)
decl_stmt|;
name|int
name|findPivotColumn
parameter_list|()
function_decl|;
name|int
name|pivotRowForColumn
parameter_list|(
name|int
name|column
parameter_list|)
function_decl|;
name|void
name|reducedRowEchelon
parameter_list|()
function_decl|;
name|bool
name|iterate
parameter_list|()
function_decl|;
comment|// Helpers
name|void
name|clearDataStructures
parameter_list|()
function_decl|;
name|void
name|solveMaxHelper
parameter_list|()
function_decl|;
enum|enum
name|solverFactor
block|{
name|Minimum
init|=
operator|-
literal|1
block|,
name|Maximum
init|=
literal|1
block|}
enum|;
name|qreal
name|solver
parameter_list|(
name|solverFactor
name|factor
parameter_list|)
function_decl|;
name|void
name|collectResults
parameter_list|()
function_decl|;
name|QList
operator|<
name|QSimplexConstraint
operator|*
operator|>
name|constraints
expr_stmt|;
name|QList
operator|<
name|QSimplexVariable
operator|*
operator|>
name|variables
expr_stmt|;
name|QSimplexConstraint
modifier|*
name|objective
decl_stmt|;
name|int
name|rows
decl_stmt|;
name|int
name|columns
decl_stmt|;
name|int
name|firstArtificial
decl_stmt|;
name|qreal
modifier|*
name|matrix
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|valueAt
specifier|inline
name|qreal
name|QSimplex
operator|::
name|valueAt
argument_list|(
argument|int rowIndex
argument_list|,
argument|int columnIndex
argument_list|)
block|{
return|return
name|matrix
index|[
name|rowIndex
operator|*
name|columns
operator|+
name|columnIndex
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setValueAt
specifier|inline
name|void
name|QSimplex
operator|::
name|setValueAt
argument_list|(
argument|int rowIndex
argument_list|,
argument|int columnIndex
argument_list|,
argument|qreal value
argument_list|)
block|{
name|matrix
index|[
name|rowIndex
operator|*
name|columns
operator|+
name|columnIndex
index|]
operator|=
name|value
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSIMPLEX_P_H
end_comment
end_unit
