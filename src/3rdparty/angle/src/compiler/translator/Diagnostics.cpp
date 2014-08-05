begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2013 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/translator/Diagnostics.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/compilerdebug.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InfoSink.h"
end_include
begin_include
include|#
directive|include
file|"compiler/preprocessor/SourceLocation.h"
end_include
begin_constructor
DECL|function|TDiagnostics
name|TDiagnostics
operator|::
name|TDiagnostics
parameter_list|(
name|TInfoSink
modifier|&
name|infoSink
parameter_list|)
member_init_list|:
name|mInfoSink
argument_list|(
name|infoSink
argument_list|)
member_init_list|,
name|mNumErrors
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mNumWarnings
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~TDiagnostics
name|TDiagnostics
operator|::
name|~
name|TDiagnostics
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|writeInfo
name|void
name|TDiagnostics
operator|::
name|writeInfo
parameter_list|(
name|Severity
name|severity
parameter_list|,
specifier|const
name|pp
operator|::
name|SourceLocation
modifier|&
name|loc
parameter_list|,
specifier|const
name|std
operator|::
name|string
modifier|&
name|reason
parameter_list|,
specifier|const
name|std
operator|::
name|string
modifier|&
name|token
parameter_list|,
specifier|const
name|std
operator|::
name|string
modifier|&
name|extra
parameter_list|)
block|{
name|TPrefixType
name|prefix
init|=
name|EPrefixNone
decl_stmt|;
switch|switch
condition|(
name|severity
condition|)
block|{
case|case
name|PP_ERROR
case|:
operator|++
name|mNumErrors
expr_stmt|;
name|prefix
operator|=
name|EPrefixError
expr_stmt|;
break|break;
case|case
name|PP_WARNING
case|:
operator|++
name|mNumWarnings
expr_stmt|;
name|prefix
operator|=
name|EPrefixWarning
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
break|break;
block|}
name|TInfoSinkBase
modifier|&
name|sink
init|=
name|mInfoSink
operator|.
name|info
decl_stmt|;
comment|/* VC++ format: file(linenum) : error #: 'token' : extrainfo */
name|sink
operator|.
name|prefix
argument_list|(
name|prefix
argument_list|)
expr_stmt|;
name|sink
operator|.
name|location
argument_list|(
name|loc
operator|.
name|file
argument_list|,
name|loc
operator|.
name|line
argument_list|)
expr_stmt|;
name|sink
operator|<<
literal|"'"
operator|<<
name|token
operator|<<
literal|"' : "
operator|<<
name|reason
operator|<<
literal|" "
operator|<<
name|extra
operator|<<
literal|"\n"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeDebug
name|void
name|TDiagnostics
operator|::
name|writeDebug
parameter_list|(
specifier|const
name|std
operator|::
name|string
modifier|&
name|str
parameter_list|)
block|{
name|mInfoSink
operator|.
name|debug
operator|<<
name|str
expr_stmt|;
block|}
end_function
begin_function
DECL|function|print
name|void
name|TDiagnostics
operator|::
name|print
parameter_list|(
name|ID
name|id
parameter_list|,
specifier|const
name|pp
operator|::
name|SourceLocation
modifier|&
name|loc
parameter_list|,
specifier|const
name|std
operator|::
name|string
modifier|&
name|text
parameter_list|)
block|{
name|writeInfo
argument_list|(
name|severity
argument_list|(
name|id
argument_list|)
argument_list|,
name|loc
argument_list|,
name|message
argument_list|(
name|id
argument_list|)
argument_list|,
name|text
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
