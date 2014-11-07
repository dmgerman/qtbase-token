begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUNCTIONS_WINRT_H
end_ifndef
begin_define
DECL|macro|QFUNCTIONS_WINRT_H
define|#
directive|define
name|QFUNCTIONS_WINRT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QtCore/QAbstractEventDispatcher>
end_include
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_comment
comment|// Convenience macros for handling HRESULT values
end_comment
begin_define
DECL|macro|RETURN_IF_FAILED
define|#
directive|define
name|RETURN_IF_FAILED
parameter_list|(
name|msg
parameter_list|,
name|ret
parameter_list|)
define|\
value|if (FAILED(hr)) { \         qErrnoWarning(hr, msg); \         ret; \     }
end_define
begin_define
DECL|macro|RETURN_HR_IF_FAILED
define|#
directive|define
name|RETURN_HR_IF_FAILED
parameter_list|(
name|msg
parameter_list|)
value|RETURN_IF_FAILED(msg, return hr)
end_define
begin_define
DECL|macro|RETURN_OK_IF_FAILED
define|#
directive|define
name|RETURN_OK_IF_FAILED
parameter_list|(
name|msg
parameter_list|)
value|RETURN_IF_FAILED(msg, return S_OK)
end_define
begin_define
DECL|macro|RETURN_FALSE_IF_FAILED
define|#
directive|define
name|RETURN_FALSE_IF_FAILED
parameter_list|(
name|msg
parameter_list|)
value|RETURN_IF_FAILED(msg, return false)
end_define
begin_define
DECL|macro|RETURN_VOID_IF_FAILED
define|#
directive|define
name|RETURN_VOID_IF_FAILED
parameter_list|(
name|msg
parameter_list|)
value|RETURN_IF_FAILED(msg, return)
end_define
begin_define
DECL|macro|Q_ASSERT_SUCCEEDED
define|#
directive|define
name|Q_ASSERT_SUCCEEDED
parameter_list|(
name|hr
parameter_list|)
define|\
value|Q_ASSERT_X(SUCCEEDED(hr), Q_FUNC_INFO, qPrintable(qt_error_string(hr)));
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINRT
end_ifdef
begin_function_decl
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_BUILD_CORE_LIB
endif|#
directive|endif
name|QT_END_NAMESPACE
comment|// Environment ------------------------------------------------------
name|errno_t
name|qt_winrt_getenv_s
parameter_list|(
name|size_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|errno_t
name|qt_winrt__putenv_s
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_winrt_tzset
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_winrt__tzset
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// As Windows Runtime lacks some standard functions used in Qt, these got
end_comment
begin_comment
comment|// reimplemented. Other projects do this as well. Inline functions are used
end_comment
begin_comment
comment|// that there is a central place to disable functions for newer versions if
end_comment
begin_comment
comment|// they get available. There are no defines used anymore, because this
end_comment
begin_comment
comment|// will break member functions of classes which are called like these
end_comment
begin_comment
comment|// functions.
end_comment
begin_comment
comment|// The other declarations available in this file are being used per
end_comment
begin_comment
comment|// define inside qplatformdefs.h of the corresponding WinRT mkspec.
end_comment
begin_define
DECL|macro|generate_inline_return_func0
define|#
directive|define
name|generate_inline_return_func0
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|)
define|\
value|inline returntype funcname() \         { \             return qt_winrt_##funcname(); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func1
define|#
directive|define
name|generate_inline_return_func1
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|)
define|\
value|inline returntype funcname(param1 p1) \         { \             return qt_winrt_##funcname(p1); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func2
define|#
directive|define
name|generate_inline_return_func2
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2) \         { \             return qt_winrt_##funcname(p1,  p2); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func3
define|#
directive|define
name|generate_inline_return_func3
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3) \         { \             return qt_winrt_##funcname(p1,  p2, p3); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func4
define|#
directive|define
name|generate_inline_return_func4
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|,
name|param4
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3, param4 p4) \         { \             return qt_winrt_##funcname(p1,  p2, p3, p4); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func5
define|#
directive|define
name|generate_inline_return_func5
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|,
name|param4
parameter_list|,
name|param5
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3, param4 p4, param5 p5) \         { \             return qt_winrt_##funcname(p1,  p2, p3, p4, p5); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func6
define|#
directive|define
name|generate_inline_return_func6
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|,
name|param4
parameter_list|,
name|param5
parameter_list|,
name|param6
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3, param4 p4, param5 p5, param6 p6) \         { \             return qt_winrt_##funcname(p1,  p2, p3, p4, p5, p6); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func7
define|#
directive|define
name|generate_inline_return_func7
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|,
name|param4
parameter_list|,
name|param5
parameter_list|,
name|param6
parameter_list|,
name|param7
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3, param4 p4, param5 p5, param6 p6, param7 p7) \         { \             return qt_winrt_##funcname(p1,  p2, p3, p4, p5, p6, p7); \         }
end_define
begin_typedef
DECL|typedef|StartAdressExFunc
typedef|typedef
name|unsigned
function_decl|(
name|__stdcall
modifier|*
name|StartAdressExFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|StartAdressFunc
typedef|typedef
name|void
function_decl|(
modifier|*
name|StartAdressFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CompareFunc
typedef|typedef
name|int
function_decl|(
name|__cdecl
modifier|*
name|CompareFunc
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_macro
name|generate_inline_return_func4
argument_list|(
argument|getenv_s
argument_list|,
argument|errno_t
argument_list|,
argument|size_t *
argument_list|,
argument|char *
argument_list|,
argument|size_t
argument_list|,
argument|const char *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|_putenv_s
argument_list|,
argument|errno_t
argument_list|,
argument|const char *
argument_list|,
argument|const char *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func0
argument_list|(
argument|tzset
argument_list|,
argument|void
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func0
argument_list|(
argument|_tzset
argument_list|,
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|namespace
name|Microsoft
block|{
name|namespace
name|WRL
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ComPtr
expr_stmt|;
block|}
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|QWinRTFunctions
block|{
comment|// Synchronization methods
enum|enum
name|AwaitStyle
block|{
name|YieldThread
init|=
literal|0
block|,
name|ProcessThreadEvents
init|=
literal|1
block|,
name|ProcessMainThreadEvents
init|=
literal|2
block|}
enum|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|HRESULT
name|_await_impl
argument_list|(
argument|const Microsoft::WRL::ComPtr<T>&asyncOp
argument_list|,
argument|AwaitStyle awaitStyle
argument_list|)
block|{
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
operator|<
name|IAsyncInfo
operator|>
name|asyncInfo
block|;
name|HRESULT
name|hr
operator|=
name|asyncOp
operator|.
name|As
argument_list|(
operator|&
name|asyncInfo
argument_list|)
block|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|hr
return|;
name|AsyncStatus
name|status
expr_stmt|;
switch|switch
condition|(
name|awaitStyle
condition|)
block|{
case|case
name|ProcessMainThreadEvents
case|:
while|while
condition|(
name|SUCCEEDED
argument_list|(
name|hr
operator|=
name|asyncInfo
operator|->
name|get_Status
argument_list|(
operator|&
name|status
argument_list|)
argument_list|)
operator|&&
name|status
operator|==
name|Started
condition|)
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
break|break;
case|case
name|ProcessThreadEvents
case|:
if|if
condition|(
name|QAbstractEventDispatcher
modifier|*
name|dispatcher
init|=
name|QThread
operator|::
name|currentThread
argument_list|()
operator|->
name|eventDispatcher
argument_list|()
condition|)
block|{
while|while
condition|(
name|SUCCEEDED
argument_list|(
name|hr
operator|=
name|asyncInfo
operator|->
name|get_Status
argument_list|(
operator|&
name|status
argument_list|)
argument_list|)
operator|&&
name|status
operator|==
name|Started
condition|)
name|dispatcher
operator|->
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|)
expr_stmt|;
break|break;
block|}
comment|// fall through
default|default:
case|case
name|YieldThread
case|:
while|while
condition|(
name|SUCCEEDED
argument_list|(
name|hr
operator|=
name|asyncInfo
operator|->
name|get_Status
argument_list|(
operator|&
name|status
argument_list|)
argument_list|)
operator|&&
name|status
operator|==
name|Started
condition|)
name|QThread
operator|::
name|yieldCurrentThread
argument_list|()
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
operator|||
name|status
operator|!=
name|Completed
condition|)
block|{
name|HRESULT
name|ec
decl_stmt|;
name|hr
operator|=
name|asyncInfo
operator|->
name|get_ErrorCode
argument_list|(
operator|&
name|ec
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|hr
return|;
return|return
name|ec
return|;
block|}
return|return
name|hr
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|HRESULT
name|await
argument_list|(
argument|const Microsoft::WRL::ComPtr<T>&asyncOp
argument_list|,
argument|AwaitStyle awaitStyle = YieldThread
argument_list|)
block|{
name|HRESULT
name|hr
operator|=
name|_await_impl
argument_list|(
name|asyncOp
argument_list|,
name|awaitStyle
argument_list|)
block|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|hr
return|;
end_expr_stmt
begin_return
return|return
name|asyncOp
operator|->
name|GetResults
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
specifier|static
specifier|inline
name|HRESULT
name|await
argument_list|(
argument|const Microsoft::WRL::ComPtr<T>&asyncOp
argument_list|,
argument|U *results
argument_list|,
argument|AwaitStyle awaitStyle = YieldThread
argument_list|)
block|{
name|HRESULT
name|hr
operator|=
name|_await_impl
argument_list|(
name|asyncOp
argument_list|,
name|awaitStyle
argument_list|)
block|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|hr
return|;
end_expr_stmt
begin_return
return|return
name|asyncOp
operator|->
name|GetResults
argument_list|(
name|results
argument_list|)
return|;
end_return
begin_comment
unit|}  }
comment|// QWinRTFunctions
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINRT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFUNCTIONS_WINRT_H
end_comment
end_unit
