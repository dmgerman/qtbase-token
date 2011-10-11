begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"v8test.h"
end_include
begin_using
using|using
namespace|namespace
name|v8
namespace|;
end_using
begin_define
DECL|macro|BEGINTEST
define|#
directive|define
name|BEGINTEST
parameter_list|()
value|bool _testPassed = true;
end_define
begin_define
DECL|macro|ENDTEST
define|#
directive|define
name|ENDTEST
parameter_list|()
value|return _testPassed;
end_define
begin_define
DECL|macro|VERIFY
define|#
directive|define
name|VERIFY
parameter_list|(
name|expr
parameter_list|)
value|{ \     if (!(expr)) { \         fprintf(stderr, "FAIL: %s:%d %s\n", __FILE__, __LINE__, # expr); \         _testPassed = false; \         goto cleanup; \     }  \ }
end_define
begin_struct
DECL|struct|MyStringResource
struct|struct
name|MyStringResource
super|:
specifier|public
name|String
operator|::
name|ExternalAsciiStringResource
block|{
DECL|member|wasDestroyed
specifier|static
name|bool
name|wasDestroyed
decl_stmt|;
DECL|function|~MyStringResource
specifier|virtual
name|~
name|MyStringResource
parameter_list|()
block|{
name|wasDestroyed
operator|=
literal|true
expr_stmt|;
block|}
DECL|function|data
specifier|virtual
specifier|const
name|char
modifier|*
name|data
parameter_list|()
specifier|const
block|{
return|return
literal|"v8test"
return|;
block|}
DECL|function|length
specifier|virtual
name|size_t
name|length
parameter_list|()
specifier|const
block|{
return|return
literal|6
return|;
block|}
block|}
struct|;
end_struct
begin_decl_stmt
DECL|member|wasDestroyed
name|bool
name|MyStringResource
operator|::
name|wasDestroyed
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|MyResource
struct|struct
name|MyResource
super|:
specifier|public
name|Object
operator|::
name|ExternalResource
block|{
DECL|member|wasDestroyed
specifier|static
name|bool
name|wasDestroyed
decl_stmt|;
DECL|function|~MyResource
specifier|virtual
name|~
name|MyResource
parameter_list|()
block|{
name|wasDestroyed
operator|=
literal|true
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_decl_stmt
DECL|member|wasDestroyed
name|bool
name|MyResource
operator|::
name|wasDestroyed
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|v8test_externalteardown
name|bool
name|v8test_externalteardown
parameter_list|()
block|{
name|BEGINTEST
argument_list|()
expr_stmt|;
name|Isolate
modifier|*
name|isolate
init|=
name|v8
operator|::
name|Isolate
operator|::
name|New
argument_list|()
decl_stmt|;
name|isolate
operator|->
name|Enter
argument_list|()
expr_stmt|;
block|{
name|HandleScope
name|handle_scope
decl_stmt|;
name|Persistent
argument_list|<
name|Context
argument_list|>
name|context
init|=
name|Context
operator|::
name|New
argument_list|()
decl_stmt|;
name|Context
operator|::
name|Scope
name|context_scope
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|Local
argument_list|<
name|String
argument_list|>
name|str
init|=
name|String
operator|::
name|NewExternal
argument_list|(
operator|new
name|MyStringResource
argument_list|)
decl_stmt|;
name|Local
argument_list|<
name|FunctionTemplate
argument_list|>
name|ft
init|=
name|FunctionTemplate
operator|::
name|New
argument_list|()
decl_stmt|;
name|ft
operator|->
name|InstanceTemplate
argument_list|()
operator|->
name|SetHasExternalResource
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|Local
argument_list|<
name|Object
argument_list|>
name|obj
init|=
name|ft
operator|->
name|GetFunction
argument_list|()
operator|->
name|NewInstance
argument_list|()
decl_stmt|;
name|obj
operator|->
name|SetExternalResource
argument_list|(
operator|new
name|MyResource
argument_list|)
expr_stmt|;
name|context
operator|.
name|Dispose
argument_list|()
expr_stmt|;
block|}
comment|// while (!v8::V8::IdleNotification()) ;
name|isolate
operator|->
name|Exit
argument_list|()
expr_stmt|;
name|isolate
operator|->
name|Dispose
argument_list|()
expr_stmt|;
comment|// ExternalString resources aren't guaranteed to be freed by v8 at this
comment|// point. Uncommenting the IdleNotification() line above helps.
comment|//    VERIFY(MyStringResource::wasDestroyed);
name|VERIFY
argument_list|(
name|MyResource
operator|::
name|wasDestroyed
argument_list|)
expr_stmt|;
name|cleanup
label|:
name|ENDTEST
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|v8test_eval
name|bool
name|v8test_eval
parameter_list|()
block|{
name|BEGINTEST
argument_list|()
expr_stmt|;
name|HandleScope
name|handle_scope
decl_stmt|;
name|Persistent
argument_list|<
name|Context
argument_list|>
name|context
init|=
name|Context
operator|::
name|New
argument_list|()
decl_stmt|;
name|Context
operator|::
name|Scope
name|context_scope
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|Local
argument_list|<
name|Object
argument_list|>
name|qmlglobal
init|=
name|Object
operator|::
name|New
argument_list|()
decl_stmt|;
name|qmlglobal
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"a"
argument_list|)
argument_list|,
name|Integer
operator|::
name|New
argument_list|(
literal|1922
argument_list|)
argument_list|)
expr_stmt|;
name|Local
argument_list|<
name|Script
argument_list|>
name|script
init|=
name|Script
operator|::
name|Compile
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"eval(\"a\")"
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|Handle
argument_list|<
name|String
argument_list|>
argument_list|()
argument_list|,
name|Script
operator|::
name|QmlMode
argument_list|)
decl_stmt|;
name|TryCatch
name|tc
decl_stmt|;
name|Local
argument_list|<
name|Value
argument_list|>
name|result
init|=
name|script
operator|->
name|Run
argument_list|(
name|qmlglobal
argument_list|)
decl_stmt|;
name|VERIFY
argument_list|(
operator|!
name|tc
operator|.
name|HasCaught
argument_list|()
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|result
operator|->
name|Int32Value
argument_list|()
operator|==
literal|1922
argument_list|)
expr_stmt|;
name|cleanup
label|:
name|context
operator|.
name|Dispose
argument_list|()
expr_stmt|;
name|ENDTEST
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|v8test_globalcall
name|bool
name|v8test_globalcall
parameter_list|()
block|{
name|BEGINTEST
argument_list|()
expr_stmt|;
name|HandleScope
name|handle_scope
decl_stmt|;
name|Persistent
argument_list|<
name|Context
argument_list|>
name|context
init|=
name|Context
operator|::
name|New
argument_list|()
decl_stmt|;
name|Context
operator|::
name|Scope
name|context_scope
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|Local
argument_list|<
name|Object
argument_list|>
name|qmlglobal
init|=
name|Object
operator|::
name|New
argument_list|()
decl_stmt|;
DECL|macro|SOURCE
define|#
directive|define
name|SOURCE
value|"function func1() { return 1; }\n" \                "function func2() { var sum = 0; for (var ii = 0; ii< 10000000; ++ii) { sum += func1(); } return sum; }\n" \                "func2();"
name|Local
argument_list|<
name|Script
argument_list|>
name|script
init|=
name|Script
operator|::
name|Compile
argument_list|(
name|String
operator|::
name|New
argument_list|(
name|SOURCE
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|Handle
argument_list|<
name|String
argument_list|>
argument_list|()
argument_list|,
name|Script
operator|::
name|QmlMode
argument_list|)
decl_stmt|;
name|Local
argument_list|<
name|Value
argument_list|>
name|result
init|=
name|script
operator|->
name|Run
argument_list|(
name|qmlglobal
argument_list|)
decl_stmt|;
name|VERIFY
argument_list|(
operator|!
name|result
operator|.
name|IsEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|result
operator|->
name|IsInt32
argument_list|()
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|result
operator|->
name|Int32Value
argument_list|()
operator|==
literal|10000000
argument_list|)
expr_stmt|;
DECL|macro|SOURCE
undef|#
directive|undef
name|SOURCE
name|cleanup
label|:
name|context
operator|.
name|Dispose
argument_list|()
expr_stmt|;
name|ENDTEST
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|v8test_evalwithinwith
name|bool
name|v8test_evalwithinwith
parameter_list|()
block|{
name|BEGINTEST
argument_list|()
expr_stmt|;
name|HandleScope
name|handle_scope
decl_stmt|;
name|Persistent
argument_list|<
name|Context
argument_list|>
name|context
init|=
name|Context
operator|::
name|New
argument_list|()
decl_stmt|;
name|Context
operator|::
name|Scope
name|context_scope
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|Local
argument_list|<
name|Object
argument_list|>
name|qmlglobal
init|=
name|Object
operator|::
name|New
argument_list|()
decl_stmt|;
name|qmlglobal
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"a"
argument_list|)
argument_list|,
name|Integer
operator|::
name|New
argument_list|(
literal|1922
argument_list|)
argument_list|)
expr_stmt|;
comment|// There was a bug that the "eval" lookup would incorrectly resolve
comment|// to the QML global object
name|qmlglobal
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"eval"
argument_list|)
argument_list|,
name|Integer
operator|::
name|New
argument_list|(
literal|1922
argument_list|)
argument_list|)
expr_stmt|;
DECL|macro|SOURCE
define|#
directive|define
name|SOURCE
define|\
value|"(function() { " \     "    var b = { c: 10 }; " \     "    with (b) { " \     "        return eval(\"a\"); " \     "    } " \     "})"
name|Local
argument_list|<
name|Script
argument_list|>
name|script
init|=
name|Script
operator|::
name|Compile
argument_list|(
name|String
operator|::
name|New
argument_list|(
name|SOURCE
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|Handle
argument_list|<
name|String
argument_list|>
argument_list|()
argument_list|,
name|Script
operator|::
name|QmlMode
argument_list|)
decl_stmt|;
DECL|macro|SOURCE
undef|#
directive|undef
name|SOURCE
name|TryCatch
name|tc
decl_stmt|;
name|Local
argument_list|<
name|Value
argument_list|>
name|result
init|=
name|script
operator|->
name|Run
argument_list|(
name|qmlglobal
argument_list|)
decl_stmt|;
name|VERIFY
argument_list|(
operator|!
name|tc
operator|.
name|HasCaught
argument_list|()
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|result
operator|->
name|IsFunction
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|Local
argument_list|<
name|Value
argument_list|>
name|fresult
init|=
name|Handle
argument_list|<
name|Function
argument_list|>
operator|::
name|Cast
argument_list|(
name|result
argument_list|)
operator|->
name|Call
argument_list|(
name|context
operator|->
name|Global
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|VERIFY
argument_list|(
operator|!
name|tc
operator|.
name|HasCaught
argument_list|()
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|fresult
operator|->
name|Int32Value
argument_list|()
operator|==
literal|1922
argument_list|)
expr_stmt|;
block|}
name|cleanup
label|:
name|context
operator|.
name|Dispose
argument_list|()
expr_stmt|;
name|ENDTEST
argument_list|()
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|userObjectComparisonCalled
specifier|static
name|int
name|userObjectComparisonCalled
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|userObjectComparisonReturn
specifier|static
name|bool
name|userObjectComparisonReturn
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|expectedLhs
specifier|static
name|Local
argument_list|<
name|Object
argument_list|>
name|expectedLhs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|expectedRhs
specifier|static
name|Local
argument_list|<
name|Object
argument_list|>
name|expectedRhs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|expectedObjectsCompared
specifier|static
name|bool
name|expectedObjectsCompared
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|SET_EXPECTED
define|#
directive|define
name|SET_EXPECTED
parameter_list|(
name|lhs
parameter_list|,
name|rhs
parameter_list|)
value|{ \     expectedObjectsCompared = false; \     expectedLhs = lhs; \     expectedRhs = rhs; \ }
end_define
begin_function
DECL|function|UserObjectComparison
specifier|static
name|bool
name|UserObjectComparison
parameter_list|(
name|Local
argument_list|<
name|Object
argument_list|>
name|lhs
parameter_list|,
name|Local
argument_list|<
name|Object
argument_list|>
name|rhs
parameter_list|)
block|{
name|userObjectComparisonCalled
operator|++
expr_stmt|;
name|expectedObjectsCompared
operator|=
operator|(
name|lhs
operator|==
name|expectedLhs
operator|&&
name|rhs
operator|==
name|expectedRhs
operator|)
expr_stmt|;
return|return
name|userObjectComparisonReturn
return|;
block|}
end_function
begin_function
DECL|function|runscript
specifier|inline
name|bool
name|runscript
parameter_list|(
specifier|const
name|char
modifier|*
name|source
parameter_list|)
block|{
name|Local
argument_list|<
name|Script
argument_list|>
name|script
init|=
name|Script
operator|::
name|Compile
argument_list|(
name|String
operator|::
name|New
argument_list|(
name|source
argument_list|)
argument_list|)
decl_stmt|;
name|Local
argument_list|<
name|Value
argument_list|>
name|result
init|=
name|script
operator|->
name|Run
argument_list|()
decl_stmt|;
return|return
name|result
operator|->
name|BooleanValue
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|v8test_userobjectcompare
name|bool
name|v8test_userobjectcompare
parameter_list|()
block|{
name|BEGINTEST
argument_list|()
expr_stmt|;
name|HandleScope
name|handle_scope
decl_stmt|;
name|Persistent
argument_list|<
name|Context
argument_list|>
name|context
init|=
name|Context
operator|::
name|New
argument_list|()
decl_stmt|;
name|Context
operator|::
name|Scope
name|context_scope
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|V8
operator|::
name|SetUserObjectComparisonCallbackFunction
argument_list|(
name|UserObjectComparison
argument_list|)
expr_stmt|;
name|Local
argument_list|<
name|ObjectTemplate
argument_list|>
name|ot
init|=
name|ObjectTemplate
operator|::
name|New
argument_list|()
decl_stmt|;
name|ot
operator|->
name|MarkAsUseUserObjectComparison
argument_list|()
expr_stmt|;
name|Local
argument_list|<
name|Object
argument_list|>
name|uoc1
init|=
name|ot
operator|->
name|NewInstance
argument_list|()
decl_stmt|;
name|Local
argument_list|<
name|Object
argument_list|>
name|uoc2
init|=
name|ot
operator|->
name|NewInstance
argument_list|()
decl_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"uoc1a"
argument_list|)
argument_list|,
name|uoc1
argument_list|)
expr_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"uoc1b"
argument_list|)
argument_list|,
name|uoc1
argument_list|)
expr_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"uoc2"
argument_list|)
argument_list|,
name|uoc2
argument_list|)
expr_stmt|;
name|Local
argument_list|<
name|Object
argument_list|>
name|obj1
init|=
name|Object
operator|::
name|New
argument_list|()
decl_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"obj1a"
argument_list|)
argument_list|,
name|obj1
argument_list|)
expr_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"obj1b"
argument_list|)
argument_list|,
name|obj1
argument_list|)
expr_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"obj2"
argument_list|)
argument_list|,
name|Object
operator|::
name|New
argument_list|()
argument_list|)
expr_stmt|;
name|Local
argument_list|<
name|String
argument_list|>
name|string1
init|=
name|String
operator|::
name|New
argument_list|(
literal|"Hello World"
argument_list|)
decl_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"string1a"
argument_list|)
argument_list|,
name|string1
argument_list|)
expr_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"string1b"
argument_list|)
argument_list|,
name|string1
argument_list|)
expr_stmt|;
name|context
operator|->
name|Global
argument_list|()
operator|->
name|Set
argument_list|(
name|String
operator|::
name|New
argument_list|(
literal|"string2"
argument_list|)
argument_list|,
name|v8
operator|::
name|String
operator|::
name|New
argument_list|(
literal|"Goodbye World"
argument_list|)
argument_list|)
expr_stmt|;
comment|// XXX Opportunity for optimization - don't invoke user callback if objects are
comment|// equal.
if|#
directive|if
literal|0
block|userObjectComparisonCalled = 0; userObjectComparisonReturn = false;     VERIFY(true == runscript("uoc1a == uoc1b"));     VERIFY(userObjectComparisonCalled == 0);
endif|#
directive|endif
comment|// Comparing two uoc objects invokes uoc
name|userObjectComparisonCalled
operator|=
literal|0
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|false
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc1a == uoc2"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|1
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc2 == uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|2
argument_list|)
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|true
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc1a == uoc2"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|3
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc2 == uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|4
argument_list|)
expr_stmt|;
comment|// != on two uoc object invokes uoc
name|userObjectComparisonCalled
operator|=
literal|0
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|false
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc1a != uoc2"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|1
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc2 != uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|2
argument_list|)
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|true
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc1a != uoc2"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|3
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc2 != uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|4
argument_list|)
expr_stmt|;
comment|// Comparison against a non-object doesn't invoke uoc
name|userObjectComparisonCalled
operator|=
literal|0
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|false
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc1a == string1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|0
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"string1a == uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|0
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"2 == uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|0
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc1a != string1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|0
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"string1a != uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|0
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"2 != uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// Comparison against a non-uoc-object still invokes uoc
name|userObjectComparisonCalled
operator|=
literal|0
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|false
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc1a == obj1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|1
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"obj1a == uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|2
argument_list|)
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|true
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc1a == obj1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|3
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"obj1a == uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|4
argument_list|)
expr_stmt|;
comment|// != comparison against a non-uoc-object still invokes uoc
name|userObjectComparisonCalled
operator|=
literal|0
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|false
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc1a != obj1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|1
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"obj1a != uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|2
argument_list|)
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|true
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc1a != obj1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|3
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"obj1a != uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|4
argument_list|)
expr_stmt|;
comment|// Comparing two non-uoc objects does not invoke uoc
name|userObjectComparisonCalled
operator|=
literal|0
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|false
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"obj1a == obj1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"obj1a == obj1b"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"obj1a == obj2"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"obj1a == string1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"string1a == string1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"string1a == string1b"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"string1a == string2"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
name|userObjectComparisonCalled
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// Correct lhs and rhs passed to uoc
name|userObjectComparisonCalled
operator|=
literal|0
expr_stmt|;
name|userObjectComparisonReturn
operator|=
literal|false
expr_stmt|;
name|SET_EXPECTED
argument_list|(
name|uoc1
argument_list|,
name|uoc2
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc1a == uoc2"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|expectedObjectsCompared
argument_list|)
expr_stmt|;
name|SET_EXPECTED
argument_list|(
name|uoc2
argument_list|,
name|uoc1
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc2 == uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|expectedObjectsCompared
argument_list|)
expr_stmt|;
name|SET_EXPECTED
argument_list|(
name|uoc1
argument_list|,
name|uoc2
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc1a != uoc2"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|expectedObjectsCompared
argument_list|)
expr_stmt|;
name|SET_EXPECTED
argument_list|(
name|uoc2
argument_list|,
name|uoc1
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|runscript
argument_list|(
literal|"uoc2 != uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|expectedObjectsCompared
argument_list|)
expr_stmt|;
name|SET_EXPECTED
argument_list|(
name|uoc1
argument_list|,
name|obj1
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"uoc1a == obj1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|expectedObjectsCompared
argument_list|)
expr_stmt|;
name|SET_EXPECTED
argument_list|(
name|obj1
argument_list|,
name|uoc1
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|false
operator|==
name|runscript
argument_list|(
literal|"obj1a == uoc1a"
argument_list|)
argument_list|)
expr_stmt|;
name|VERIFY
argument_list|(
literal|true
operator|==
name|expectedObjectsCompared
argument_list|)
expr_stmt|;
name|cleanup
label|:
name|V8
operator|::
name|SetUserObjectComparisonCallbackFunction
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|context
operator|.
name|Dispose
argument_list|()
expr_stmt|;
name|ENDTEST
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
