begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Jeremy LainÃ©<jeremy.laine@m4x.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd and its Subsidiary(-ies) nor the **     names of its contributors may be used to endorse or promote products **     derived from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"dnslookup.h"
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QDnsLookup>
end_include
begin_include
include|#
directive|include
file|<QHostAddress>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QCommandLineParser>
end_include
begin_include
include|#
directive|include
file|<QCommandLineOption>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_function
DECL|function|typeFromParameter
specifier|static
name|int
name|typeFromParameter
parameter_list|(
specifier|const
name|QString
modifier|&
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|==
literal|"a"
condition|)
return|return
name|QDnsLookup
operator|::
name|A
return|;
if|if
condition|(
name|type
operator|==
literal|"aaaa"
condition|)
return|return
name|QDnsLookup
operator|::
name|AAAA
return|;
if|if
condition|(
name|type
operator|==
literal|"any"
condition|)
return|return
name|QDnsLookup
operator|::
name|ANY
return|;
if|if
condition|(
name|type
operator|==
literal|"cname"
condition|)
return|return
name|QDnsLookup
operator|::
name|CNAME
return|;
if|if
condition|(
name|type
operator|==
literal|"mx"
condition|)
return|return
name|QDnsLookup
operator|::
name|MX
return|;
if|if
condition|(
name|type
operator|==
literal|"ns"
condition|)
return|return
name|QDnsLookup
operator|::
name|NS
return|;
if|if
condition|(
name|type
operator|==
literal|"ptr"
condition|)
return|return
name|QDnsLookup
operator|::
name|PTR
return|;
if|if
condition|(
name|type
operator|==
literal|"srv"
condition|)
return|return
name|QDnsLookup
operator|::
name|SRV
return|;
if|if
condition|(
name|type
operator|==
literal|"txt"
condition|)
return|return
name|QDnsLookup
operator|::
name|TXT
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_enum
DECL|enum|CommandLineParseResult
enum|enum
name|CommandLineParseResult
block|{
DECL|enumerator|CommandLineOk
name|CommandLineOk
block|,
DECL|enumerator|CommandLineError
name|CommandLineError
block|,
DECL|enumerator|CommandLineVersionRequested
name|CommandLineVersionRequested
block|,
DECL|enumerator|CommandLineHelpRequested
name|CommandLineHelpRequested
block|}
enum|;
end_enum
begin_function
DECL|function|parseCommandLine
name|CommandLineParseResult
name|parseCommandLine
parameter_list|(
name|QCommandLineParser
modifier|&
name|parser
parameter_list|,
name|DnsQuery
modifier|*
name|query
parameter_list|,
name|QString
modifier|*
name|errorMessage
parameter_list|)
block|{
name|parser
operator|.
name|setSingleDashWordOptionMode
argument_list|(
name|QCommandLineParser
operator|::
name|ParseAsLongOptions
argument_list|)
expr_stmt|;
specifier|const
name|QCommandLineOption
name|nameServerOption
argument_list|(
literal|"n"
argument_list|,
literal|"The name server to use."
argument_list|,
literal|"nameserver"
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|nameServerOption
argument_list|)
expr_stmt|;
specifier|const
name|QCommandLineOption
name|typeOption
argument_list|(
literal|"t"
argument_list|,
literal|"The lookup type."
argument_list|,
literal|"type"
argument_list|)
decl_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|typeOption
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"name"
argument_list|,
literal|"The name to look up."
argument_list|)
expr_stmt|;
specifier|const
name|QCommandLineOption
name|helpOption
init|=
name|parser
operator|.
name|addHelpOption
argument_list|()
decl_stmt|;
specifier|const
name|QCommandLineOption
name|versionOption
init|=
name|parser
operator|.
name|addVersionOption
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|parser
operator|.
name|parse
argument_list|(
name|QCoreApplication
operator|::
name|arguments
argument_list|()
argument_list|)
condition|)
block|{
operator|*
name|errorMessage
operator|=
name|parser
operator|.
name|errorText
argument_list|()
expr_stmt|;
return|return
name|CommandLineError
return|;
block|}
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|versionOption
argument_list|)
condition|)
return|return
name|CommandLineVersionRequested
return|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|helpOption
argument_list|)
condition|)
return|return
name|CommandLineHelpRequested
return|;
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|nameServerOption
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|nameserver
init|=
name|parser
operator|.
name|value
argument_list|(
name|nameServerOption
argument_list|)
decl_stmt|;
name|query
operator|->
name|nameServer
operator|=
name|QHostAddress
argument_list|(
name|nameserver
argument_list|)
expr_stmt|;
if|if
condition|(
name|query
operator|->
name|nameServer
operator|.
name|isNull
argument_list|()
operator|||
name|query
operator|->
name|nameServer
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|UnknownNetworkLayerProtocol
condition|)
block|{
operator|*
name|errorMessage
operator|=
literal|"Bad nameserver address: "
operator|+
name|nameserver
expr_stmt|;
return|return
name|CommandLineError
return|;
block|}
block|}
if|if
condition|(
name|parser
operator|.
name|isSet
argument_list|(
name|typeOption
argument_list|)
condition|)
block|{
specifier|const
name|QString
name|typeParameter
init|=
name|parser
operator|.
name|value
argument_list|(
name|typeOption
argument_list|)
decl_stmt|;
specifier|const
name|int
name|type
init|=
name|typeFromParameter
argument_list|(
name|typeParameter
operator|.
name|toLower
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|<
literal|0
condition|)
block|{
operator|*
name|errorMessage
operator|=
literal|"Bad record type: "
operator|+
name|typeParameter
expr_stmt|;
return|return
name|CommandLineError
return|;
block|}
name|query
operator|->
name|type
operator|=
cast|static_cast
argument_list|<
name|QDnsLookup
operator|::
name|Type
argument_list|>
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QStringList
name|positionalArguments
init|=
name|parser
operator|.
name|positionalArguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|positionalArguments
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
operator|*
name|errorMessage
operator|=
literal|"Argument 'name' missing."
expr_stmt|;
return|return
name|CommandLineError
return|;
block|}
if|if
condition|(
name|positionalArguments
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
operator|*
name|errorMessage
operator|=
literal|"Several 'name' arguments specified."
expr_stmt|;
return|return
name|CommandLineError
return|;
block|}
name|query
operator|->
name|name
operator|=
name|positionalArguments
operator|.
name|first
argument_list|()
expr_stmt|;
return|return
name|CommandLineOk
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DnsManager
name|DnsManager
operator|::
name|DnsManager
parameter_list|()
block|{
name|dns
operator|=
operator|new
name|QDnsLookup
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|dns
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showResults
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|execute
name|void
name|DnsManager
operator|::
name|execute
parameter_list|()
block|{
comment|// lookup type
name|dns
operator|->
name|setType
argument_list|(
name|query
operator|.
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|query
operator|.
name|nameServer
operator|.
name|isNull
argument_list|()
condition|)
name|dns
operator|->
name|setNameserver
argument_list|(
name|query
operator|.
name|nameServer
argument_list|)
expr_stmt|;
name|dns
operator|->
name|setName
argument_list|(
name|query
operator|.
name|name
argument_list|)
expr_stmt|;
name|dns
operator|->
name|lookup
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showResults
name|void
name|DnsManager
operator|::
name|showResults
parameter_list|()
block|{
if|if
condition|(
name|dns
operator|->
name|error
argument_list|()
operator|!=
name|QDnsLookup
operator|::
name|NoError
condition|)
name|printf
argument_list|(
literal|"Error: %i (%s)\n"
argument_list|,
name|dns
operator|->
name|error
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|dns
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// CNAME records
foreach|foreach
control|(
specifier|const
name|QDnsDomainNameRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|canonicalNameRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tCNAME\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// A and AAAA records
foreach|foreach
control|(
specifier|const
name|QDnsHostAddressRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|hostAddressRecords
argument_list|()
control|)
block|{
specifier|const
name|char
modifier|*
name|type
init|=
operator|(
name|record
operator|.
name|value
argument_list|()
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|IPv6Protocol
operator|)
condition|?
literal|"AAAA"
else|:
literal|"A"
decl_stmt|;
name|printf
argument_list|(
literal|"%s\t%i\tIN\t%s\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|type
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|value
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// MX records
foreach|foreach
control|(
specifier|const
name|QDnsMailExchangeRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|mailExchangeRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tMX\t%u %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|record
operator|.
name|preference
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|exchange
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// NS records
foreach|foreach
control|(
specifier|const
name|QDnsDomainNameRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|nameServerRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tNS\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// PTR records
foreach|foreach
control|(
specifier|const
name|QDnsDomainNameRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|pointerRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tPTR\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// SRV records
foreach|foreach
control|(
specifier|const
name|QDnsServiceRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|serviceRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tSRV\t%u %u %u %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|record
operator|.
name|priority
argument_list|()
argument_list|,
name|record
operator|.
name|weight
argument_list|()
argument_list|,
name|record
operator|.
name|port
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|target
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// TXT records
foreach|foreach
control|(
specifier|const
name|QDnsTextRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|textRecords
argument_list|()
control|)
block|{
name|QStringList
name|values
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|ba
decl|,
name|record
operator|.
name|values
argument_list|()
control|)
name|values
operator|<<
literal|"\""
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
name|ba
argument_list|)
operator|+
literal|"\""
expr_stmt|;
name|printf
argument_list|(
literal|"%s\t%i\tIN\tTXT\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|values
operator|.
name|join
argument_list|(
literal|' '
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|//! [1]
name|QCoreApplication
operator|::
name|setApplicationVersion
argument_list|(
name|QT_VERSION_STR
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|setApplicationName
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QDnsLookupExample"
argument_list|,
literal|"DNS Lookup Example"
argument_list|)
argument_list|)
expr_stmt|;
name|QCommandLineParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setApplicationDescription
argument_list|(
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QDnsLookupExample"
argument_list|,
literal|"An example demonstrating the class QDnsLookup."
argument_list|)
argument_list|)
expr_stmt|;
name|DnsQuery
name|query
decl_stmt|;
name|QString
name|errorMessage
decl_stmt|;
switch|switch
condition|(
name|parseCommandLine
argument_list|(
name|parser
argument_list|,
operator|&
name|query
argument_list|,
operator|&
name|errorMessage
argument_list|)
condition|)
block|{
case|case
name|CommandLineOk
case|:
break|break;
case|case
name|CommandLineError
case|:
name|fputs
argument_list|(
name|qPrintable
argument_list|(
name|errorMessage
argument_list|)
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|qPrintable
argument_list|(
name|parser
operator|.
name|helpText
argument_list|()
argument_list|)
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
case|case
name|CommandLineVersionRequested
case|:
name|printf
argument_list|(
literal|"%s %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|QCoreApplication
operator|::
name|applicationVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
case|case
name|CommandLineHelpRequested
case|:
name|parser
operator|.
name|showHelp
argument_list|()
expr_stmt|;
name|Q_UNREACHABLE
argument_list|()
expr_stmt|;
block|}
comment|//! [1]
name|DnsManager
name|manager
decl_stmt|;
name|manager
operator|.
name|setQuery
argument_list|(
name|query
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
operator|&
name|manager
argument_list|,
name|SLOT
argument_list|(
name|execute
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
