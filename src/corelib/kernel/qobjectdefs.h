begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOBJECTDEFS_H
end_ifndef
begin_define
DECL|macro|QOBJECTDEFS_H
define|#
directive|define
name|QOBJECTDEFS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_MOC_OUTPUT_REVISION
end_ifndef
begin_define
DECL|macro|Q_MOC_OUTPUT_REVISION
define|#
directive|define
name|Q_MOC_OUTPUT_REVISION
value|63
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// The following macros are our "extensions" to C++
end_comment
begin_comment
comment|// They are used, strictly speaking, only by the moc.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_MOC_RUN
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_KEYWORDS
argument_list|)
end_if
begin_define
DECL|macro|QT_NO_EMIT
define|#
directive|define
name|QT_NO_EMIT
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|slots
define|#
directive|define
name|slots
end_define
begin_define
DECL|macro|signals
define|#
directive|define
name|signals
value|protected
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_SLOTS
define|#
directive|define
name|Q_SLOTS
end_define
begin_define
DECL|macro|Q_SIGNALS
define|#
directive|define
name|Q_SIGNALS
value|protected
end_define
begin_define
DECL|macro|Q_PRIVATE_SLOT
define|#
directive|define
name|Q_PRIVATE_SLOT
parameter_list|(
name|d
parameter_list|,
name|signature
parameter_list|)
end_define
begin_define
DECL|macro|Q_EMIT
define|#
directive|define
name|Q_EMIT
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EMIT
end_ifndef
begin_define
DECL|macro|emit
define|#
directive|define
name|emit
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_CLASSINFO
define|#
directive|define
name|Q_CLASSINFO
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
end_define
begin_define
DECL|macro|Q_INTERFACES
define|#
directive|define
name|Q_INTERFACES
parameter_list|(
name|x
parameter_list|)
end_define
begin_define
DECL|macro|Q_PROPERTY
define|#
directive|define
name|Q_PROPERTY
parameter_list|(
name|text
parameter_list|)
end_define
begin_define
DECL|macro|Q_PRIVATE_PROPERTY
define|#
directive|define
name|Q_PRIVATE_PROPERTY
parameter_list|(
name|d
parameter_list|,
name|text
parameter_list|)
end_define
begin_define
DECL|macro|Q_REVISION
define|#
directive|define
name|Q_REVISION
parameter_list|(
name|v
parameter_list|)
end_define
begin_define
DECL|macro|Q_OVERRIDE
define|#
directive|define
name|Q_OVERRIDE
parameter_list|(
name|text
parameter_list|)
end_define
begin_define
DECL|macro|Q_ENUMS
define|#
directive|define
name|Q_ENUMS
parameter_list|(
name|x
parameter_list|)
end_define
begin_define
DECL|macro|Q_FLAGS
define|#
directive|define
name|Q_FLAGS
parameter_list|(
name|x
parameter_list|)
end_define
begin_define
DECL|macro|Q_SCRIPTABLE
define|#
directive|define
name|Q_SCRIPTABLE
end_define
begin_define
DECL|macro|Q_INVOKABLE
define|#
directive|define
name|Q_INVOKABLE
end_define
begin_define
DECL|macro|Q_SIGNAL
define|#
directive|define
name|Q_SIGNAL
end_define
begin_define
DECL|macro|Q_SLOT
define|#
directive|define
name|Q_SLOT
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
end_ifndef
begin_comment
comment|// full set of tr functions
end_comment
begin_comment
comment|// ### Qt 5: merge overloads
end_comment
begin_define
DECL|macro|QT_TR_FUNCTIONS
define|#
directive|define
name|QT_TR_FUNCTIONS
define|\
value|static inline QString tr(const char *s, const char *c = 0) \         { return staticMetaObject.tr(s, c); } \     static inline QString trUtf8(const char *s, const char *c = 0) \         { return staticMetaObject.trUtf8(s, c); } \     static inline QString tr(const char *s, const char *c, int n) \         { return staticMetaObject.tr(s, c, n); } \     static inline QString trUtf8(const char *s, const char *c, int n) \         { return staticMetaObject.trUtf8(s, c, n); }
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|// no QTextCodec, no utf8
end_comment
begin_comment
comment|// ### Qt 5: merge overloads
end_comment
begin_define
DECL|macro|QT_TR_FUNCTIONS
define|#
directive|define
name|QT_TR_FUNCTIONS
define|\
value|static inline QString tr(const char *s, const char *c = 0) \         { return staticMetaObject.tr(s, c); } \     static inline QString tr(const char *s, const char *c, int n) \         { return staticMetaObject.tr(s, c, n); }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|// inherit the ones from QObject
end_comment
begin_define
DECL|macro|QT_TR_FUNCTIONS
define|#
directive|define
name|QT_TR_FUNCTIONS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_QOBJECT_CHECK
argument_list|)
end_if
begin_comment
comment|/* tmake ignore Q_OBJECT */
end_comment
begin_define
DECL|macro|Q_OBJECT_CHECK
define|#
directive|define
name|Q_OBJECT_CHECK
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* This is a compile time check that ensures that any class cast with qobject_cast    actually contains a Q_OBJECT macro. Note: qobject_cast will fail if a QObject    subclass doesn't contain Q_OBJECT.     In qt_check_for_QOBJECT_macro, we call a dummy templated function with two    parameters, the first being "this" and the other the target of the qobject    cast. If the types are not identical, we know that a Q_OBJECT macro is missing.     If you get a compiler error here, make sure that the class you are casting    to contains a Q_OBJECT macro. */
end_comment
begin_comment
comment|/* tmake ignore Q_OBJECT */
end_comment
begin_define
DECL|macro|Q_OBJECT_CHECK
define|#
directive|define
name|Q_OBJECT_CHECK
define|\
value|template<typename T> inline void qt_check_for_QOBJECT_macro(const T&_q_argument) const \     { int i = qYouForgotTheQ_OBJECT_Macro(this,&_q_argument); i = i + 1; }
end_define
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
DECL|function|qYouForgotTheQ_OBJECT_Macro
specifier|inline
name|int
name|qYouForgotTheQ_OBJECT_Macro
argument_list|(
argument|T
argument_list|,
argument|T
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|T1
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
DECL|function|qYouForgotTheQ_OBJECT_Macro
specifier|inline
name|void
name|qYouForgotTheQ_OBJECT_Macro
argument_list|(
argument|T1
argument_list|,
argument|T2
argument_list|)
block|{}
endif|#
directive|endif
comment|// QT_NO_QOBJECT_CHECK
ifdef|#
directive|ifdef
name|Q_NO_DATA_RELOCATION
DECL|macro|Q_OBJECT_GETSTATICMETAOBJECT
define|#
directive|define
name|Q_OBJECT_GETSTATICMETAOBJECT
value|static const QMetaObject&getStaticMetaObject();
else|#
directive|else
DECL|macro|Q_OBJECT_GETSTATICMETAOBJECT
define|#
directive|define
name|Q_OBJECT_GETSTATICMETAOBJECT
endif|#
directive|endif
comment|/* tmake ignore Q_OBJECT */
DECL|macro|Q_OBJECT
define|#
directive|define
name|Q_OBJECT
define|\
value|public: \     Q_OBJECT_CHECK \     static const QMetaObject staticMetaObject; \     Q_OBJECT_GETSTATICMETAOBJECT \     virtual const QMetaObject *metaObject() const; \     virtual void *qt_metacast(const char *); \     QT_TR_FUNCTIONS \     virtual int qt_metacall(QMetaObject::Call, int, void **); \ private: \     Q_DECL_HIDDEN static const QMetaObjectExtraData staticMetaObjectExtraData; \     Q_DECL_HIDDEN static void qt_static_metacall(QObject *, QMetaObject::Call, int, void **);
comment|/* tmake ignore Q_OBJECT */
DECL|macro|Q_OBJECT_FAKE
define|#
directive|define
name|Q_OBJECT_FAKE
value|Q_OBJECT
comment|/* tmake ignore Q_GADGET */
DECL|macro|Q_GADGET
define|#
directive|define
name|Q_GADGET
define|\
value|public: \     static const QMetaObject staticMetaObject; \     Q_OBJECT_GETSTATICMETAOBJECT \ private:
else|#
directive|else
comment|// Q_MOC_RUN
DECL|macro|slots
define|#
directive|define
name|slots
value|slots
DECL|macro|signals
define|#
directive|define
name|signals
value|signals
DECL|macro|Q_SLOTS
define|#
directive|define
name|Q_SLOTS
value|Q_SLOTS
DECL|macro|Q_SIGNALS
define|#
directive|define
name|Q_SIGNALS
value|Q_SIGNALS
DECL|macro|Q_CLASSINFO
define|#
directive|define
name|Q_CLASSINFO
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
value|Q_CLASSINFO(name, value)
DECL|macro|Q_INTERFACES
define|#
directive|define
name|Q_INTERFACES
parameter_list|(
name|x
parameter_list|)
value|Q_INTERFACES(x)
DECL|macro|Q_PROPERTY
define|#
directive|define
name|Q_PROPERTY
parameter_list|(
name|text
parameter_list|)
value|Q_PROPERTY(text)
DECL|macro|Q_PRIVATE_PROPERTY
define|#
directive|define
name|Q_PRIVATE_PROPERTY
parameter_list|(
name|d
parameter_list|,
name|text
parameter_list|)
value|Q_PRIVATE_PROPERTY(d, text)
DECL|macro|Q_REVISION
define|#
directive|define
name|Q_REVISION
parameter_list|(
name|v
parameter_list|)
value|Q_REVISION(v)
DECL|macro|Q_OVERRIDE
define|#
directive|define
name|Q_OVERRIDE
parameter_list|(
name|text
parameter_list|)
value|Q_OVERRIDE(text)
DECL|macro|Q_ENUMS
define|#
directive|define
name|Q_ENUMS
parameter_list|(
name|x
parameter_list|)
value|Q_ENUMS(x)
DECL|macro|Q_FLAGS
define|#
directive|define
name|Q_FLAGS
parameter_list|(
name|x
parameter_list|)
value|Q_FLAGS(x)
comment|/* tmake ignore Q_OBJECT */
DECL|macro|Q_OBJECT
define|#
directive|define
name|Q_OBJECT
value|Q_OBJECT
comment|/* tmake ignore Q_OBJECT */
DECL|macro|Q_OBJECT_FAKE
define|#
directive|define
name|Q_OBJECT_FAKE
value|Q_OBJECT_FAKE
comment|/* tmake ignore Q_GADGET */
DECL|macro|Q_GADGET
define|#
directive|define
name|Q_GADGET
value|Q_GADGET
DECL|macro|Q_SCRIPTABLE
define|#
directive|define
name|Q_SCRIPTABLE
value|Q_SCRIPTABLE
DECL|macro|Q_INVOKABLE
define|#
directive|define
name|Q_INVOKABLE
value|Q_INVOKABLE
DECL|macro|Q_SIGNAL
define|#
directive|define
name|Q_SIGNAL
value|Q_SIGNAL
DECL|macro|Q_SLOT
define|#
directive|define
name|Q_SLOT
value|Q_SLOT
endif|#
directive|endif
comment|//Q_MOC_RUN
comment|// macro for onaming members
ifdef|#
directive|ifdef
name|METHOD
DECL|macro|METHOD
undef|#
directive|undef
name|METHOD
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SLOT
DECL|macro|SLOT
undef|#
directive|undef
name|SLOT
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGNAL
DECL|macro|SIGNAL
undef|#
directive|undef
name|SIGNAL
endif|#
directive|endif
name|Q_CORE_EXPORT
specifier|const
name|char
operator|*
name|qFlagLocation
argument_list|(
specifier|const
name|char
operator|*
name|method
argument_list|)
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|QTOSTRING_HELPER
define|#
directive|define
name|QTOSTRING_HELPER
parameter_list|(
name|s
parameter_list|)
value|#s
end_define
begin_define
DECL|macro|QTOSTRING
define|#
directive|define
name|QTOSTRING
parameter_list|(
name|s
parameter_list|)
value|QTOSTRING_HELPER(s)
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG
end_ifndef
begin_define
DECL|macro|QLOCATION
define|#
directive|define
name|QLOCATION
value|"\0"__FILE__":"QTOSTRING(__LINE__)
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_KEYWORDS
end_ifndef
begin_define
DECL|macro|METHOD
define|#
directive|define
name|METHOD
parameter_list|(
name|a
parameter_list|)
value|qFlagLocation("0"#a QLOCATION)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|SLOT
define|#
directive|define
name|SLOT
parameter_list|(
name|a
parameter_list|)
value|qFlagLocation("1"#a QLOCATION)
end_define
begin_define
DECL|macro|SIGNAL
define|#
directive|define
name|SIGNAL
parameter_list|(
name|a
parameter_list|)
value|qFlagLocation("2"#a QLOCATION)
end_define
begin_else
else|#
directive|else
end_else
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_KEYWORDS
end_ifndef
begin_define
DECL|macro|METHOD
define|#
directive|define
name|METHOD
parameter_list|(
name|a
parameter_list|)
value|"0"#a
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|SLOT
define|#
directive|define
name|SLOT
parameter_list|(
name|a
parameter_list|)
value|"1"#a
end_define
begin_define
DECL|macro|SIGNAL
define|#
directive|define
name|SIGNAL
parameter_list|(
name|a
parameter_list|)
value|"2"#a
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QMETHOD_CODE
define|#
directive|define
name|QMETHOD_CODE
value|0
end_define
begin_comment
DECL|macro|QMETHOD_CODE
comment|// member type codes
end_comment
begin_define
DECL|macro|QSLOT_CODE
define|#
directive|define
name|QSLOT_CODE
value|1
end_define
begin_define
DECL|macro|QSIGNAL_CODE
define|#
directive|define
name|QSIGNAL_CODE
value|2
end_define
begin_define
DECL|macro|Q_ARG
define|#
directive|define
name|Q_ARG
parameter_list|(
name|type
parameter_list|,
name|data
parameter_list|)
value|QArgument<type>(#type, data)
end_define
begin_define
DECL|macro|Q_RETURN_ARG
define|#
directive|define
name|Q_RETURN_ARG
parameter_list|(
name|type
parameter_list|,
name|data
parameter_list|)
value|QReturnArgument<type>(#type, data)
end_define
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMetaMethod
name|class
name|QMetaMethod
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMetaEnum
name|class
name|QMetaEnum
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMetaProperty
name|class
name|QMetaProperty
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMetaClassInfo
name|class
name|QMetaClassInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QGenericArgument
block|{
name|public
label|:
specifier|inline
name|QGenericArgument
argument_list|(
specifier|const
name|char
operator|*
name|aName
operator|=
literal|0
argument_list|,
specifier|const
name|void
operator|*
name|aData
operator|=
literal|0
argument_list|)
operator|:
name|_data
argument_list|(
name|aData
argument_list|)
operator|,
name|_name
argument_list|(
argument|aName
argument_list|)
block|{}
specifier|inline
name|void
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|_data
operator|)
return|;
block|}
specifier|inline
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
name|_name
return|;
block|}
name|private
label|:
specifier|const
name|void
modifier|*
name|_data
decl_stmt|;
specifier|const
name|char
modifier|*
name|_name
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QGenericReturnArgument
range|:
name|public
name|QGenericArgument
block|{
name|public
operator|:
specifier|inline
name|QGenericReturnArgument
argument_list|(
specifier|const
name|char
operator|*
name|aName
operator|=
literal|0
argument_list|,
name|void
operator|*
name|aData
operator|=
literal|0
argument_list|)
operator|:
name|QGenericArgument
argument_list|(
argument|aName
argument_list|,
argument|aData
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QArgument
operator|:
name|public
name|QGenericArgument
block|{
name|public
operator|:
specifier|inline
name|QArgument
argument_list|(
specifier|const
name|char
operator|*
name|aName
argument_list|,
specifier|const
name|T
operator|&
name|aData
argument_list|)
operator|:
name|QGenericArgument
argument_list|(
argument|aName
argument_list|,
argument|static_cast<const void *>(&aData)
argument_list|)
block|{}
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QArgument
operator|<
name|T
operator|&
operator|>
operator|:
name|public
name|QGenericArgument
block|{
name|public
operator|:
specifier|inline
name|QArgument
argument_list|(
specifier|const
name|char
operator|*
name|aName
argument_list|,
name|T
operator|&
name|aData
argument_list|)
operator|:
name|QGenericArgument
argument_list|(
argument|aName
argument_list|,
argument|static_cast<const void *>(&aData)
argument_list|)
block|{}
block|}
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QReturnArgument
operator|:
name|public
name|QGenericReturnArgument
block|{
name|public
operator|:
specifier|inline
name|QReturnArgument
argument_list|(
specifier|const
name|char
operator|*
name|aName
argument_list|,
name|T
operator|&
name|aData
argument_list|)
operator|:
name|QGenericReturnArgument
argument_list|(
argument|aName
argument_list|,
argument|static_cast<void *>(&aData)
argument_list|)
block|{}
block|}
expr_stmt|;
end_expr_stmt
begin_struct
DECL|struct|QMetaObject
struct|struct
name|Q_CORE_EXPORT
name|QMetaObject
block|{
specifier|const
name|char
operator|*
name|className
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QMetaObject
operator|*
name|superClass
argument_list|()
specifier|const
expr_stmt|;
name|QObject
modifier|*
name|cast
argument_list|(
name|QObject
operator|*
name|obj
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QObject
modifier|*
name|cast
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TRANSLATION
comment|// ### Qt 4: Merge overloads
name|QString
name|tr
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
specifier|const
name|char
operator|*
name|c
argument_list|)
decl|const
decl_stmt|;
name|QString
name|trUtf8
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
specifier|const
name|char
operator|*
name|c
argument_list|)
decl|const
decl_stmt|;
name|QString
name|tr
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
specifier|const
name|char
operator|*
name|c
argument_list|,
name|int
name|n
argument_list|)
decl|const
decl_stmt|;
name|QString
name|trUtf8
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
specifier|const
name|char
operator|*
name|c
argument_list|,
name|int
name|n
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
comment|// QT_NO_TRANSLATION
name|int
name|methodOffset
argument_list|()
specifier|const
expr_stmt|;
name|int
name|enumeratorOffset
argument_list|()
specifier|const
expr_stmt|;
name|int
name|propertyOffset
argument_list|()
specifier|const
expr_stmt|;
name|int
name|classInfoOffset
argument_list|()
specifier|const
expr_stmt|;
name|int
name|constructorCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|methodCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|enumeratorCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|propertyCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|classInfoCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|indexOfConstructor
argument_list|(
specifier|const
name|char
operator|*
name|constructor
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexOfMethod
argument_list|(
specifier|const
name|char
operator|*
name|method
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexOfSignal
argument_list|(
specifier|const
name|char
operator|*
name|signal
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexOfSlot
argument_list|(
specifier|const
name|char
operator|*
name|slot
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexOfEnumerator
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexOfProperty
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexOfClassInfo
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
decl|const
decl_stmt|;
name|QMetaMethod
name|constructor
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QMetaMethod
name|method
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QMetaEnum
name|enumerator
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QMetaProperty
name|property
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QMetaClassInfo
name|classInfo
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QMetaProperty
name|userProperty
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|checkConnectArgs
parameter_list|(
specifier|const
name|char
modifier|*
name|signal
parameter_list|,
specifier|const
name|char
modifier|*
name|method
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|normalizedSignature
parameter_list|(
specifier|const
name|char
modifier|*
name|method
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|normalizedType
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
comment|// internal index-based connect
specifier|static
name|bool
name|connect
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
name|int
name|signal_index
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
name|int
name|method_index
parameter_list|,
name|int
name|type
init|=
literal|0
parameter_list|,
name|int
modifier|*
name|types
init|=
literal|0
parameter_list|)
function_decl|;
comment|// internal index-based disconnect
specifier|static
name|bool
name|disconnect
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
name|int
name|signal_index
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
name|int
name|method_index
parameter_list|)
function_decl|;
specifier|static
name|bool
name|disconnectOne
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
name|int
name|signal_index
parameter_list|,
specifier|const
name|QObject
modifier|*
name|receiver
parameter_list|,
name|int
name|method_index
parameter_list|)
function_decl|;
comment|// internal slot-name based connect
specifier|static
name|void
name|connectSlotsByName
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|)
function_decl|;
comment|// internal index-based signal activation
specifier|static
name|void
name|activate
parameter_list|(
name|QObject
modifier|*
name|sender
parameter_list|,
name|int
name|signal_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|//obsolete
specifier|static
name|void
name|activate
parameter_list|(
name|QObject
modifier|*
name|sender
parameter_list|,
name|int
name|from_signal_index
parameter_list|,
name|int
name|to_signal_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|//obsolete
specifier|static
name|void
name|activate
parameter_list|(
name|QObject
modifier|*
name|sender
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
parameter_list|,
name|int
name|local_signal_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
specifier|static
name|void
name|activate
parameter_list|(
name|QObject
modifier|*
name|sender
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
parameter_list|,
name|int
name|from_local_signal_index
parameter_list|,
name|int
name|to_local_signal_index
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|//obsolete
comment|// internal guarded pointers
specifier|static
name|void
name|addGuard
parameter_list|(
name|QObject
modifier|*
modifier|*
name|ptr
parameter_list|)
function_decl|;
specifier|static
name|void
name|removeGuard
parameter_list|(
name|QObject
modifier|*
modifier|*
name|ptr
parameter_list|)
function_decl|;
specifier|static
name|void
name|changeGuard
parameter_list|(
name|QObject
modifier|*
modifier|*
name|ptr
parameter_list|,
name|QObject
modifier|*
name|o
parameter_list|)
function_decl|;
specifier|static
name|bool
name|invokeMethod
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|,
name|Qt
operator|::
name|ConnectionType
argument_list|,
name|QGenericReturnArgument
name|ret
argument_list|,
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
decl_stmt|;
DECL|function|invokeMethod
specifier|static
specifier|inline
name|bool
name|invokeMethod
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|,
name|QGenericReturnArgument
name|ret
parameter_list|,
name|QGenericArgument
name|val0
init|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
parameter_list|,
name|QGenericArgument
name|val1
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val2
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val3
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val4
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val5
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val6
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val7
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val8
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val9
init|=
name|QGenericArgument
argument_list|()
parameter_list|)
block|{
return|return
name|invokeMethod
argument_list|(
name|obj
argument_list|,
name|member
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|ret
argument_list|,
name|val0
argument_list|,
name|val1
argument_list|,
name|val2
argument_list|,
name|val3
argument_list|,
name|val4
argument_list|,
name|val5
argument_list|,
name|val6
argument_list|,
name|val7
argument_list|,
name|val8
argument_list|,
name|val9
argument_list|)
return|;
block|}
DECL|function|invokeMethod
specifier|static
specifier|inline
name|bool
name|invokeMethod
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|,
name|Qt
operator|::
name|ConnectionType
name|type
argument_list|,
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
block|{
return|return
name|invokeMethod
argument_list|(
name|obj
argument_list|,
name|member
argument_list|,
name|type
argument_list|,
name|QGenericReturnArgument
argument_list|()
argument_list|,
name|val0
argument_list|,
name|val1
argument_list|,
name|val2
argument_list|,
name|val3
argument_list|,
name|val4
argument_list|,
name|val5
argument_list|,
name|val6
argument_list|,
name|val7
argument_list|,
name|val8
argument_list|,
name|val9
argument_list|)
return|;
block|}
DECL|function|invokeMethod
specifier|static
specifier|inline
name|bool
name|invokeMethod
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|,
name|QGenericArgument
name|val0
init|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
parameter_list|,
name|QGenericArgument
name|val1
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val2
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val3
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val4
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val5
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val6
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val7
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val8
init|=
name|QGenericArgument
argument_list|()
parameter_list|,
name|QGenericArgument
name|val9
init|=
name|QGenericArgument
argument_list|()
parameter_list|)
block|{
return|return
name|invokeMethod
argument_list|(
name|obj
argument_list|,
name|member
argument_list|,
name|Qt
operator|::
name|AutoConnection
argument_list|,
name|QGenericReturnArgument
argument_list|()
argument_list|,
name|val0
argument_list|,
name|val1
argument_list|,
name|val2
argument_list|,
name|val3
argument_list|,
name|val4
argument_list|,
name|val5
argument_list|,
name|val6
argument_list|,
name|val7
argument_list|,
name|val8
argument_list|,
name|val9
argument_list|)
return|;
block|}
name|QObject
modifier|*
name|newInstance
argument_list|(
name|QGenericArgument
name|val0
operator|=
name|QGenericArgument
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGenericArgument
name|val1
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val2
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val3
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val4
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val5
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val6
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val7
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val8
operator|=
name|QGenericArgument
argument_list|()
argument_list|,
name|QGenericArgument
name|val9
operator|=
name|QGenericArgument
argument_list|()
argument_list|)
decl|const
decl_stmt|;
DECL|enum|Call
enum|enum
name|Call
block|{
DECL|enumerator|InvokeMetaMethod
name|InvokeMetaMethod
block|,
DECL|enumerator|ReadProperty
name|ReadProperty
block|,
DECL|enumerator|WriteProperty
name|WriteProperty
block|,
DECL|enumerator|ResetProperty
name|ResetProperty
block|,
DECL|enumerator|QueryPropertyDesignable
name|QueryPropertyDesignable
block|,
DECL|enumerator|QueryPropertyScriptable
name|QueryPropertyScriptable
block|,
DECL|enumerator|QueryPropertyStored
name|QueryPropertyStored
block|,
DECL|enumerator|QueryPropertyEditable
name|QueryPropertyEditable
block|,
DECL|enumerator|QueryPropertyUser
name|QueryPropertyUser
block|,
DECL|enumerator|CreateInstance
name|CreateInstance
block|,
DECL|enumerator|IndexOfMethod
name|IndexOfMethod
block|}
enum|;
name|int
name|static_metacall
argument_list|(
name|Call
argument_list|,
name|int
argument_list|,
name|void
operator|*
operator|*
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|int
name|metacall
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|Call
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
struct|struct
block|{
comment|// private data
DECL|member|superdata
specifier|const
name|QMetaObject
modifier|*
name|superdata
decl_stmt|;
DECL|member|stringdata
specifier|const
name|char
modifier|*
name|stringdata
decl_stmt|;
DECL|member|data
specifier|const
name|uint
modifier|*
name|data
decl_stmt|;
DECL|member|extradata
specifier|const
name|void
modifier|*
name|extradata
decl_stmt|;
block|}
DECL|member|d
name|d
struct|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|QMetaObjectAccessor
typedef|typedef
specifier|const
name|QMetaObject
modifier|&
function_decl|(
modifier|*
name|QMetaObjectAccessor
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_struct
DECL|struct|QMetaObjectExtraData
struct|struct
name|QMetaObjectExtraData
block|{
ifdef|#
directive|ifdef
name|Q_NO_DATA_RELOCATION
DECL|member|objects
specifier|const
name|QMetaObjectAccessor
modifier|*
name|objects
decl_stmt|;
else|#
directive|else
specifier|const
name|QMetaObject
modifier|*
modifier|*
name|objects
decl_stmt|;
endif|#
directive|endif
DECL|typedef|StaticMetacallFunction
typedef|typedef
name|void
argument_list|(
operator|*
name|StaticMetacallFunction
argument_list|)
argument_list|(
name|QObject
operator|*
argument_list|,
name|QMetaObject
operator|::
name|Call
argument_list|,
name|int
argument_list|,
name|void
operator|*
operator|*
argument_list|)
expr_stmt|;
comment|//from revision 6
comment|//typedef int (*StaticMetaCall)(QMetaObject::Call, int, void **); //used from revison 2 until revison 5
DECL|member|static_metacall
name|StaticMetacallFunction
name|static_metacall
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|function|className
specifier|inline
specifier|const
name|char
operator|*
name|QMetaObject
operator|::
name|className
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|stringdata
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|superClass
specifier|inline
specifier|const
name|QMetaObject
operator|*
name|QMetaObject
operator|::
name|superClass
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|superdata
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOBJECTDEFS_H
end_comment
end_unit
