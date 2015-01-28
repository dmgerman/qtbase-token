begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qtypetraits.h>
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
name|isIntegral
operator|=
name|QtPrivate
operator|::
name|is_integral
operator|<
name|T
operator|>
operator|::
name|value
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
comment|//### Qt6: remove
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
name|isIntegral
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
name|isIntegral
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
name|isIntegral
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
value|template<typename T> class CONTAINER; \ template<typename T> \ class QTypeInfo< CONTAINER<T>> \ { \ public: \     enum { \         isPointer = false, \         isIntegral = false, \         isComplex = true, \         isStatic = false, \         isLarge = (sizeof(CONTAINER<T>)> sizeof(void*)), \         isDummy = false, \         sizeOf = sizeof(CONTAINER<T>) \     }; \ };
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
value|class QTypeInfo<TYPE> \ { \ public: \     enum { \         isComplex = (((FLAGS)& Q_PRIMITIVE_TYPE) == 0), \         isStatic = (((FLAGS)& (Q_MOVABLE_TYPE | Q_PRIMITIVE_TYPE)) == 0), \         isLarge = (sizeof(TYPE)>sizeof(void*)), \         isPointer = false, \         isIntegral = QtPrivate::is_integral< TYPE>::value, \         isDummy = (((FLAGS)& Q_DUMMY_TYPE) != 0), \         sizeOf = sizeof(TYPE) \     }; \     static inline const char *name() { return #TYPE; } \ }
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
DECL|macro|Q_DECLARE_SHARED
define|#
directive|define
name|Q_DECLARE_SHARED
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|Q_DECLARE_TYPEINFO(TYPE, Q_MOVABLE_TYPE); \ inline void swap(TYPE&value1, TYPE&value2) \     Q_DECL_NOEXCEPT_EXPR(noexcept(value1.swap(value2))) \ { value1.swap(value2); }
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
begin_if
if|#
directive|if
name|QT_VERSION
operator|>=
name|QT_VERSION_CHECK
argument_list|(
literal|6
operator|,
literal|0
operator|,
literal|0
argument_list|)
end_if
begin_comment
comment|// We can't do it now because it would break BC on QList<char32_t>
end_comment
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|char16_t
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|char32_t
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|||
name|defined
argument_list|(
name|_NATIVE_WCHAR_T_DEFINED
argument_list|)
end_if
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|wchar_t
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Qt 6
end_comment
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
