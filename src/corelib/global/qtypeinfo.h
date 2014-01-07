begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QTYPEINFO_H
end_ifndef
begin_define
DECL|macro|QTYPEINFO_H
define|#
directive|define
name|QTYPEINFO_H
end_define
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|/*    QTypeInfo     - type trait functionality */
comment|/*   The catch-all template. */
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QTypeInfo
block|{
name|public
operator|:
expr|enum
block|{
name|isPointer
operator|=
name|false
block|,
name|isComplex
operator|=
name|true
block|,
name|isStatic
operator|=
name|true
block|,
name|isLarge
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|)
block|,
name|isDummy
operator|=
name|false
block|,
name|sizeOf
operator|=
expr|sizeof
operator|(
name|T
operator|)
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|QTypeInfo
operator|<
name|void
operator|>
block|{
name|public
operator|:
expr|enum
block|{
name|isPointer
operator|=
name|false
block|,
name|isComplex
operator|=
name|false
block|,
name|isStatic
operator|=
name|false
block|,
name|isLarge
operator|=
name|false
block|,
name|isDummy
operator|=
name|false
block|,
name|sizeOf
operator|=
literal|0
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QTypeInfo
operator|<
name|T
operator|*
operator|>
block|{
name|public
operator|:
expr|enum
block|{
name|isPointer
operator|=
name|true
block|,
name|isComplex
operator|=
name|false
block|,
name|isStatic
operator|=
name|false
block|,
name|isLarge
operator|=
name|false
block|,
name|isDummy
operator|=
name|false
block|,
name|sizeOf
operator|=
expr|sizeof
operator|(
name|T
operator|*
operator|)
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!     \class QTypeInfoMerger     \inmodule QtCore     \internal      \brief QTypeInfoMerger merges the QTypeInfo flags of T1, T2... and presents them     as a QTypeInfo<T> would do.      Let's assume that we have a simple set of structs:      \snippet code/src_corelib_global_qglobal.cpp 50      To create a proper QTypeInfo specialization for A struct, we have to check     all sub-components; B, C and D, then take the lowest common denominator and call     Q_DECLARE_TYPEINFO with the resulting flags. An easier and less fragile approach is to     use QTypeInfoMerger, which does that automatically. So struct A would have     the following QTypeInfo definition:      \snippet code/src_corelib_global_qglobal.cpp 51 */
end_comment
begin_expr_stmt
DECL|variable|T
DECL|variable|T1
DECL|variable|T2
DECL|variable|T3
DECL|variable|T4
name|template
operator|<
name|class
name|T
operator|,
name|class
name|T1
operator|,
name|class
name|T2
operator|=
name|T1
operator|,
name|class
name|T3
operator|=
name|T1
operator|,
name|class
name|T4
operator|=
name|T1
operator|>
name|class
name|QTypeInfoMerger
block|{
name|public
operator|:
expr|enum
block|{
name|isComplex
operator|=
name|QTypeInfo
operator|<
name|T1
operator|>
operator|::
name|isComplex
operator|||
name|QTypeInfo
operator|<
name|T2
operator|>
operator|::
name|isComplex
operator|||
name|QTypeInfo
operator|<
name|T3
operator|>
operator|::
name|isComplex
operator|||
name|QTypeInfo
operator|<
name|T4
operator|>
operator|::
name|isComplex
block|,
name|isStatic
operator|=
name|QTypeInfo
operator|<
name|T1
operator|>
operator|::
name|isStatic
operator|||
name|QTypeInfo
operator|<
name|T2
operator|>
operator|::
name|isStatic
operator|||
name|QTypeInfo
operator|<
name|T3
operator|>
operator|::
name|isStatic
operator|||
name|QTypeInfo
operator|<
name|T4
operator|>
operator|::
name|isStatic
block|,
name|isLarge
operator|=
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
block|,
name|isPointer
operator|=
name|false
block|,
name|isDummy
operator|=
name|false
block|,
name|sizeOf
operator|=
expr|sizeof
operator|(
name|T
operator|)
block|}
block|; }
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|Q_DECLARE_MOVABLE_CONTAINER
define|#
directive|define
name|Q_DECLARE_MOVABLE_CONTAINER
parameter_list|(
name|CONTAINER
parameter_list|)
define|\
value|template<typename T> class CONTAINER; \ template<typename T> \ class QTypeInfo< CONTAINER<T>> \ { \ public: \     enum { \         isPointer = false, \         isComplex = true, \         isStatic = false, \         isLarge = (sizeof(CONTAINER<T>)> sizeof(void*)), \         isDummy = false, \         sizeOf = sizeof(CONTAINER<T>) \     }; \ };
end_define
begin_macro
DECL|function|Q_DECLARE_MOVABLE_CONTAINER
name|Q_DECLARE_MOVABLE_CONTAINER
argument_list|(
argument|QList
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_MOVABLE_CONTAINER
argument_list|(
argument|QVector
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_MOVABLE_CONTAINER
argument_list|(
argument|QQueue
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_MOVABLE_CONTAINER
argument_list|(
argument|QStack
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_MOVABLE_CONTAINER
argument_list|(
argument|QLinkedList
argument_list|)
end_macro
begin_expr_stmt
name|Q_DECLARE_MOVABLE_CONTAINER
argument_list|(
name|QSet
argument_list|)
DECL|macro|Q_DECLARE_MOVABLE_CONTAINER
undef|#
directive|undef
name|Q_DECLARE_MOVABLE_CONTAINER
comment|/*    Specialize a specific type with:       Q_DECLARE_TYPEINFO(type, flags);     where 'type' is the name of the type to specialize and 'flags' is    logically-OR'ed combination of the flags below. */
expr|enum
block|{
comment|/* TYPEINFO flags */
name|Q_COMPLEX_TYPE
operator|=
literal|0
block|,
name|Q_PRIMITIVE_TYPE
operator|=
literal|0x1
block|,
name|Q_STATIC_TYPE
operator|=
literal|0
block|,
name|Q_MOVABLE_TYPE
operator|=
literal|0x2
block|,
name|Q_DUMMY_TYPE
operator|=
literal|0x4
block|}
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|Q_DECLARE_TYPEINFO_BODY
define|#
directive|define
name|Q_DECLARE_TYPEINFO_BODY
parameter_list|(
name|TYPE
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|class QTypeInfo<TYPE> \ { \ public: \     enum { \         isComplex = (((FLAGS)& Q_PRIMITIVE_TYPE) == 0), \         isStatic = (((FLAGS)& (Q_MOVABLE_TYPE | Q_PRIMITIVE_TYPE)) == 0), \         isLarge = (sizeof(TYPE)>sizeof(void*)), \         isPointer = false, \         isDummy = (((FLAGS)& Q_DUMMY_TYPE) != 0), \         sizeOf = sizeof(TYPE) \     }; \     static inline const char *name() { return #TYPE; } \ }
end_define
begin_define
DECL|macro|Q_DECLARE_TYPEINFO
define|#
directive|define
name|Q_DECLARE_TYPEINFO
parameter_list|(
name|TYPE
parameter_list|,
name|FLAGS
parameter_list|)
define|\
value|template<> \ Q_DECLARE_TYPEINFO_BODY(TYPE, FLAGS)
end_define
begin_comment
comment|/* Specialize QTypeInfo for QFlags<T> */
end_comment
begin_expr_stmt
DECL|variable|QFlags
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QFlags
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Q_DECLARE_TYPEINFO_BODY
argument_list|(
name|QFlags
operator|<
name|T
operator|>
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*    Specialize a shared type with:       Q_DECLARE_SHARED(type)     where 'type' is the name of the type to specialize.  NOTE: shared    types must define a member-swap, and be defined in the same    namespace as Qt for this to work. */
end_comment
begin_define
DECL|macro|Q_DECLARE_SHARED_STL
define|#
directive|define
name|Q_DECLARE_SHARED_STL
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|QT_END_NAMESPACE \ namespace std { \     template<> inline void swap< QT_PREPEND_NAMESPACE(TYPE)>(QT_PREPEND_NAMESPACE(TYPE)&value1, QT_PREPEND_NAMESPACE(TYPE)&value2) \     { value1.swap(value2); } \ } \ QT_BEGIN_NAMESPACE
end_define
begin_define
DECL|macro|Q_DECLARE_SHARED
define|#
directive|define
name|Q_DECLARE_SHARED
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|Q_DECLARE_TYPEINFO(TYPE, Q_MOVABLE_TYPE); \ template<> inline void qSwap<TYPE>(TYPE&value1, TYPE&value2) \ { value1.swap(value2); } \ Q_DECLARE_SHARED_STL(TYPE)
end_define
begin_comment
comment|/*    QTypeInfo primitive specializations */
end_comment
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|bool
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|char
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|Q_DECLARE_TYPEINFO
argument_list|(
argument|signed char
argument_list|,
argument|Q_PRIMITIVE_TYPE
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|uchar
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|short
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|ushort
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|int
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|uint
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|long
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|ulong
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|qint64
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|quint64
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|float
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|double
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_DARWIN
end_ifndef
begin_macro
name|Q_DECLARE_TYPEINFO
argument_list|(
argument|long double
argument_list|,
argument|Q_PRIMITIVE_TYPE
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTYPEINFO_H
end_comment
end_unit
