begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qlibraryinfo.h>
end_include
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|"stdio.h"
end_include
begin_include
include|#
directive|include
file|"stdlib.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
include|#
directive|include
file|"qconfig_eval.cpp"
DECL|variable|boilerplate_supported_but_time_limited
specifier|static
specifier|const
name|char
name|boilerplate_supported_but_time_limited
index|[]
init|=
literal|"\nQt %1 Evaluation License\n"
literal|"Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).\n"
literal|"This trial version may only be used for evaluation purposes\n"
literal|"and will shut down after 120 minutes.\n"
literal|"Registered to:\n"
literal|"   Licensee: %2\n\n"
literal|"The evaluation expires in %4 days\n\n"
literal|"Contact http://qt.digia.com/contact-us for pricing and purchasing information.\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|boilerplate_supported
specifier|static
specifier|const
name|char
name|boilerplate_supported
index|[]
init|=
literal|"\nQt %1 Evaluation License\n"
literal|"Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).\n"
literal|"This trial version may only be used for evaluation purposes\n"
literal|"Registered to:\n"
literal|"   Licensee: %2\n\n"
literal|"The evaluation expires in %4 days\n\n"
literal|"Contact http://qt.digia.com/contact-us for pricing and purchasing information.\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|boilerplate_expired
specifier|static
specifier|const
name|char
name|boilerplate_expired
index|[]
init|=
literal|"This software is using the trial version of the Qt GUI toolkit.\n"
literal|"The trial period has expired. If you need more time to\n"
literal|"evaluate Qt, or if you have any questions about Qt, contact us\n"
literal|"at: http://qt.digia.com/contact-us.\n\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|will_shutdown_1min
specifier|static
specifier|const
name|char
name|will_shutdown_1min
index|[]
init|=
literal|"\nThe evaluation of Qt will SHUT DOWN in 1 minute.\n"
literal|"Contact http://qt.digia.com/contact-us for pricing and purchasing information.\n"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|will_shutdown_now
specifier|static
specifier|const
name|char
name|will_shutdown_now
index|[]
init|=
literal|"\nThe evaluation of Qt has now reached its automatic\n"
literal|"timeout and will shut down.\n"
literal|"Contact http://qt.digia.com/contact-us for pricing and purchasing information.\n"
decl_stmt|;
end_decl_stmt
begin_enum
DECL|enum|EvaluationStatus
enum|enum
name|EvaluationStatus
block|{
DECL|enumerator|EvaluationNotSupported
name|EvaluationNotSupported
init|=
literal|0
block|,
DECL|enumerator|EvaluationSupportedButTimeLimited
name|EvaluationSupportedButTimeLimited
block|,
DECL|enumerator|EvaluationSupported
name|EvaluationSupported
block|}
enum|;
end_enum
begin_function
DECL|function|qt_eval_is_supported
specifier|static
name|EvaluationStatus
name|qt_eval_is_supported
parameter_list|()
block|{
specifier|const
specifier|volatile
name|char
modifier|*
specifier|const
name|license_key
init|=
name|qt_eval_key_data
operator|+
literal|12
decl_stmt|;
comment|// fast fail
if|if
condition|(
operator|!
name|qt_eval_key_data
index|[
literal|0
index|]
operator|||
operator|!
operator|*
name|license_key
condition|)
return|return
name|EvaluationNotSupported
return|;
comment|// is this an unsupported evaluation?
specifier|const
specifier|volatile
name|char
modifier|*
name|typecode
init|=
name|license_key
decl_stmt|;
name|int
name|field
init|=
literal|2
decl_stmt|;
for|for
control|(
init|;
name|field
operator|&&
operator|*
name|typecode
condition|;
operator|++
name|typecode
control|)
if|if
condition|(
operator|*
name|typecode
operator|==
literal|'-'
condition|)
operator|--
name|field
expr_stmt|;
if|if
condition|(
operator|!
name|field
operator|&&
name|typecode
index|[
literal|1
index|]
operator|==
literal|'4'
operator|&&
name|typecode
index|[
literal|2
index|]
operator|==
literal|'M'
condition|)
block|{
if|if
condition|(
name|typecode
index|[
literal|0
index|]
operator|==
literal|'Q'
condition|)
return|return
name|EvaluationSupportedButTimeLimited
return|;
elseif|else
if|if
condition|(
name|typecode
index|[
literal|0
index|]
operator|==
literal|'R'
operator|||
name|typecode
index|[
literal|0
index|]
operator|==
literal|'Z'
condition|)
return|return
name|EvaluationSupported
return|;
block|}
return|return
name|EvaluationNotSupported
return|;
block|}
end_function
begin_function
DECL|function|qt_eval_days_left
specifier|static
name|int
name|qt_eval_days_left
parameter_list|()
block|{
name|QDate
name|today
init|=
name|QDate
operator|::
name|currentDate
argument_list|()
decl_stmt|;
name|QDate
name|build
init|=
name|QLibraryInfo
operator|::
name|buildDate
argument_list|()
decl_stmt|;
return|return
name|qMax
argument_list|<
name|qint64
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|,
name|today
operator|.
name|daysTo
argument_list|(
name|build
argument_list|)
operator|+
literal|30
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_eval_is_expired
specifier|static
name|bool
name|qt_eval_is_expired
parameter_list|()
block|{
return|return
name|qt_eval_days_left
argument_list|()
operator|<
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_eval_string
specifier|static
name|QString
name|qt_eval_string
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|msg
decl_stmt|;
switch|switch
condition|(
name|qt_eval_is_supported
argument_list|()
condition|)
block|{
case|case
name|EvaluationSupportedButTimeLimited
case|:
name|msg
operator|=
name|boilerplate_supported_but_time_limited
expr_stmt|;
break|break;
case|case
name|EvaluationSupported
case|:
name|msg
operator|=
name|boilerplate_supported
expr_stmt|;
break|break;
default|default:
return|return
name|QString
argument_list|()
return|;
name|msg
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
name|msg
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
name|QT_VERSION_STR
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QLibraryInfo
operator|::
name|licensee
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|qt_eval_days_left
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_define
DECL|macro|WARN_TIMEOUT
define|#
directive|define
name|WARN_TIMEOUT
value|60 * 1000 * 119
end_define
begin_define
DECL|macro|KILL_DELAY
define|#
directive|define
name|KILL_DELAY
value|60 * 1000 * 1
end_define
begin_class
DECL|class|QCoreFuriCuri
class|class
name|QCoreFuriCuri
super|:
specifier|public
name|QObject
block|{
public|public:
DECL|member|warn
name|int
name|warn
decl_stmt|;
DECL|member|kill
name|int
name|kill
decl_stmt|;
DECL|function|QCoreFuriCuri
name|QCoreFuriCuri
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
member_init_list|,
name|warn
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|kill
argument_list|(
operator|-
literal|1
argument_list|)
block|{
if|if
condition|(
name|qt_eval_is_supported
argument_list|()
operator|==
name|EvaluationSupportedButTimeLimited
condition|)
block|{
name|warn
operator|=
name|startTimer
argument_list|(
name|WARN_TIMEOUT
argument_list|)
expr_stmt|;
name|kill
operator|=
literal|0
expr_stmt|;
block|}
block|}
DECL|function|timerEvent
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|warn
condition|)
block|{
name|killTimer
argument_list|(
name|warn
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|will_shutdown_1min
argument_list|)
expr_stmt|;
name|kill
operator|=
name|startTimer
argument_list|(
name|KILL_DELAY
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|kill
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|will_shutdown_now
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_BOOTSTRAPPED
argument_list|)
end_if
begin_function
DECL|function|qt_core_eval_init
name|void
name|qt_core_eval_init
parameter_list|(
name|QCoreApplicationPrivate
operator|::
name|Type
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|!=
name|QCoreApplicationPrivate
operator|::
name|Tty
condition|)
return|return;
if|if
condition|(
operator|!
name|qt_eval_is_supported
argument_list|()
condition|)
return|return;
if|if
condition|(
name|qt_eval_is_expired
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|boilerplate_expired
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|qt_eval_string
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
operator|new
name|QCoreFuriCuri
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUILD_WIDGETS_LIB
end_ifdef
begin_decl_stmt
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<qdialog.h>
include|#
directive|include
file|<qlabel.h>
include|#
directive|include
file|<qlayout.h>
include|#
directive|include
file|<qmessagebox.h>
include|#
directive|include
file|<qpushbutton.h>
include|#
directive|include
file|<qtimer.h>
include|#
directive|include
file|<qapplication.h>
name|QT_END_INCLUDE_NAMESPACE
DECL|variable|qtlogo_eval_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qtlogo_eval_xpm
index|[]
init|=
block|{
comment|/* columns rows colors chars-per-pixel */
literal|"46 55 174 2"
block|,
literal|"   c #002E02"
block|,
literal|".  c #00370D"
block|,
literal|"X  c #003A0E"
block|,
literal|"o  c #003710"
block|,
literal|"O  c #013C13"
block|,
literal|"+  c #043E1A"
block|,
literal|"@  c #084F0A"
block|,
literal|"#  c #0B520C"
block|,
literal|"$  c #054413"
block|,
literal|"%  c #0C4C17"
block|,
literal|"&  c #07421D"
block|,
literal|"*  c #09451D"
block|,
literal|"=  c #0D491E"
block|,
literal|"-  c #125515"
block|,
literal|";  c #13541A"
block|,
literal|":  c #17591B"
block|,
literal|">  c #1B5C1D"
block|,
literal|",  c #1F611F"
block|,
literal|"<  c #20621E"
block|,
literal|"1  c #337B1E"
block|,
literal|"2  c #0B4521"
block|,
literal|"3  c #0F4923"
block|,
literal|"4  c #114B24"
block|,
literal|"5  c #154D2A"
block|,
literal|"6  c #175323"
block|,
literal|"7  c #1C5924"
block|,
literal|"8  c #1C532F"
block|,
literal|"9  c #1E5432"
block|,
literal|"0  c #245936"
block|,
literal|"q  c #265938"
block|,
literal|"w  c #295C3B"
block|,
literal|"e  c #246324"
block|,
literal|"r  c #266823"
block|,
literal|"t  c #2A6C24"
block|,
literal|"y  c #276628"
block|,
literal|"u  c #2D7026"
block|,
literal|"i  c #327427"
block|,
literal|"p  c #367927"
block|,
literal|"a  c #37782A"
block|,
literal|"s  c #397C2A"
block|,
literal|"d  c #2E613E"
block|,
literal|"f  c #336C37"
block|,
literal|"g  c #2F6040"
block|,
literal|"h  c #356545"
block|,
literal|"j  c #3C6B4E"
block|,
literal|"k  c #3F6C51"
block|,
literal|"l  c #406E4F"
block|,
literal|"z  c #406D52"
block|,
literal|"x  c #477457"
block|,
literal|"c  c #497557"
block|,
literal|"v  c #4B7857"
block|,
literal|"b  c #517B5E"
block|,
literal|"n  c #3C8423"
block|,
literal|"m  c #3E812C"
block|,
literal|"M  c #53A61D"
block|,
literal|"N  c #41862C"
block|,
literal|"B  c #458A2D"
block|,
literal|"V  c #498F2D"
block|,
literal|"C  c #479324"
block|,
literal|"Z  c #489226"
block|,
literal|"A  c #4D952C"
block|,
literal|"S  c #478B30"
block|,
literal|"D  c #488C30"
block|,
literal|"F  c #4D9232"
block|,
literal|"G  c #509632"
block|,
literal|"H  c #549A33"
block|,
literal|"J  c #589F35"
block|,
literal|"K  c #56A526"
block|,
literal|"L  c #57A821"
block|,
literal|"P  c #5BAA27"
block|,
literal|"I  c #57A32A"
block|,
literal|"U  c #5CA72E"
block|,
literal|"Y  c #5DAB2A"
block|,
literal|"T  c #5CA336"
block|,
literal|"R  c #60AD2E"
block|,
literal|"E  c #63B12D"
block|,
literal|"W  c #65AF35"
block|,
literal|"Q  c #62A53F"
block|,
literal|"!  c #65AE39"
block|,
literal|"~  c #66B036"
block|,
literal|"^  c #6AB437"
block|,
literal|"/  c #67B138"
block|,
literal|"(  c #6AB339"
block|,
literal|")  c #6DB838"
block|,
literal|"_  c #70BA3C"
block|,
literal|"`  c #4D8545"
block|,
literal|"'  c #4E8942"
block|,
literal|"]  c #548851"
block|,
literal|"[  c #6FAF4A"
block|,
literal|"{  c #6DB243"
block|,
literal|"}  c #71B546"
block|,
literal|"|  c #70B840"
block|,
literal|" . c #73B648"
block|,
literal|".. c #79BA4E"
block|,
literal|"X. c #7CBB53"
block|,
literal|"o. c #598266"
block|,
literal|"O. c #62886D"
block|,
literal|"+. c #6A8F75"
block|,
literal|"@. c #6B9173"
block|,
literal|"#. c #70937A"
block|,
literal|"$. c #799F79"
block|,
literal|"%. c #7BAF66"
block|,
literal|"&. c #81BD5B"
block|,
literal|"*. c #85BF60"
block|,
literal|"=. c #85AC7F"
block|,
literal|"-. c #8DBA7B"
block|,
literal|";. c #87C061"
block|,
literal|":. c #8AC364"
block|,
literal|">. c #8DC46A"
block|,
literal|",. c #90C56E"
block|,
literal|"<. c #93C771"
block|,
literal|"1. c #96CA73"
block|,
literal|"2. c #9ACB7C"
block|,
literal|"3. c #9FD07D"
block|,
literal|"4. c #779981"
block|,
literal|"5. c #7F9F89"
block|,
literal|"6. c #809F88"
block|,
literal|"7. c #82A18B"
block|,
literal|"8. c #86A192"
block|,
literal|"9. c #8DA994"
block|,
literal|"0. c #8FA998"
block|,
literal|"q. c #94AF9B"
block|,
literal|"w. c #97B991"
block|,
literal|"e. c #97B19E"
block|,
literal|"r. c #9DB6A3"
block|,
literal|"t. c #A3BCA7"
block|,
literal|"y. c #A6BCAB"
block|,
literal|"u. c #A9BEB1"
block|,
literal|"i. c #9ECD81"
block|,
literal|"p. c #A2CF85"
block|,
literal|"a. c #A5D284"
block|,
literal|"s. c #A6D189"
block|,
literal|"d. c #A9D28E"
block|,
literal|"f. c #ABD491"
block|,
literal|"g. c #B1D797"
block|,
literal|"h. c #B1D699"
block|,
literal|"j. c #B5D89E"
block|,
literal|"k. c #ADC5AC"
block|,
literal|"l. c #B1CAAE"
block|,
literal|"z. c #B9DAA3"
block|,
literal|"x. c #BDDDA8"
block|,
literal|"c. c #ADC1B4"
block|,
literal|"v. c #B2C6B6"
block|,
literal|"b. c #B5C6BC"
block|,
literal|"n. c #B6C9BA"
block|,
literal|"m. c #BCD1BA"
block|,
literal|"M. c #C6E1B4"
block|,
literal|"N. c #CDE5BD"
block|,
literal|"B. c #C2D2C6"
block|,
literal|"V. c #CADEC2"
block|,
literal|"C. c #C6D3CC"
block|,
literal|"Z. c #C8D7CB"
block|,
literal|"A. c #CEDAD2"
block|,
literal|"S. c #D2DDD4"
block|,
literal|"D. c #D3E9C6"
block|,
literal|"F. c #D7EBC9"
block|,
literal|"G. c #D9EBCD"
block|,
literal|"H. c #DEEED4"
block|,
literal|"J. c #D6E0D9"
block|,
literal|"K. c #DAE4DC"
block|,
literal|"L. c #E0EFD7"
block|,
literal|"P. c #E5F2DD"
block|,
literal|"I. c #DFE8E0"
block|,
literal|"U. c #E4EBE5"
block|,
literal|"Y. c #E9EFEA"
block|,
literal|"T. c #EDF4EB"
block|,
literal|"R. c #F0FAE6"
block|,
literal|"E. c #F1F8EC"
block|,
literal|"W. c #EDF0F0"
block|,
literal|"Q. c #F4F7F3"
block|,
literal|"!. c #F6F9F4"
block|,
literal|"~. c #F8FAF7"
block|,
literal|"^. c #FEFEFE"
block|,
literal|"/. c None"
block|,
comment|/* pixels */
literal|"/././././.c h ' Q / W _&.p././././././././././././././././././././././././././././././././."
block|,
literal|"/././.4 O % Z ~ ~ W ~ W R U R R ( X.>.p././././././././././././././././././././././././././."
block|,
literal|"/./.. * = J _ ~ ~ ~ ~ ~ / / / / W W U P P U W  .;.2././././././././././././././././././././."
block|,
literal|"/.= =& a ) W ~ ~ ~ ~ ~ / W / ~ ~ ~ ^ ( ( ^ ~ R R U P Y ~  .;.2././././././././././././././."
block|,
literal|"O.O = = T ^ W ~ ~ ~ ~ ~ ~ W W / W ~ ~ ~ ~ ~ ~ ~ ( ( ( ( ~ W Y Y Y Y W {&.1././././././././."
block|,
literal|"0 = * 7 ~ ~ ~ ~ ~ ~ ~ ~ ~ / / W ~ ~ ~ ~ ~ ~ ~ ~ W W W ~ ~ ~ ~ ( ( ( W W R U P U W { X.1.f./."
block|,
literal|"= =& e ^ W ~ ~ ~ ~ ~ ~ ~ ~ / / ~ ~ ~ ~ ~ ~ ~ ~ W ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ^ ( ( / ~ W R U U Y "
block|,
literal|"= =& e ^ W ~ ~ ~ ~ ~ ~ ~ ~ W W ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W ( W ~ ~ ~ ^ ^ ( "
block|,
literal|"= = * e ^ W ~ ~ ~ ~ ~ ~ / W / W ! ( / ~ W ^ ( ( ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W ~ W W ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ ! ~ ~ ~ ~ ~ ~ W W ^ _ ~ K Y W W R P Y W ( ~ ~ ~ ~ ~ ~ ~ W / ~ ~ ~ ^ W ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W ~ ~ ~ ~ ~ ~ W ) W 1 ` w.V.L.H.D.z.,.~ Y ^ ~ ~ ~ ~ ~ W ~ ~ ~ ( ~ W W ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W ~ ~ ~ ~ ~ W ) V = 8.~.^.^.^.^.^.^.^.U.<.Y ~ ~ ~ ~ ~ W W ! ~ Y W ^ W ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W ~ ~ ~ ~ W ^ B O u.^.~.^.^.^.^.~.~.^.^.^.h.Y ^ ~ ~ ^ F $ k.R.G.1.Y / ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ ~ ~ ~ / W ( J X 7.^.~.^.^.^.^.^.^.^.^.^.^.^.s.Y / W ) a 2 U.^.^.d.U ( ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W / ~ ~ ~ ^> w ~.^.^.^.^.^.F.%.v c.^.^.^.^.~.X.W ~ ^> h ^.^.^.d.P ( ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W ~ ~ W ^ H o e.^.^.^.^.^.G.Y E n . y.^.^.^.^.M.Y ( ! $ @.^.~.^.f.U ( / ~ ~ W ~ ~ "
block|,
literal|"= =& e ^ W ~ W ! ) t 4 U.^.^.^.^.^.>.U ( _ , 9 ~.^.^.^.~...^ A   y.^.~.^.s.M W Y ~ ~ ~ ~ ~ "
block|,
literal|"= 3& e ^ W ~ ( ^ ( $ c ^.^.^.^.^.E.) ~ ~ ^ S o n.^.^.^.^.=.- l.v.Y.^.^.^.M.:.:.X.~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ ! W W ( J X 7.^.^.^.^.^.F.Y ( W ^ T X 6.^.^.~.^.c.. J.^.^.^.^.^.^.^.^.P.~ ~ ~ ~ ~ "
block|,
literal|"= =& r ^ W / W ) B o v.^.~.^.^.^.M.U / ~ ~ ! $ o.^.^.^.^.K.* S.^.^.^.^.^.^.^.^.P.~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ ! ~ W ) a + S.^.^.^.^.^.z.P ( W ~ ( % z ^.^.^.^.~.f t.U.^.^.^.^.~.^.^.P.~ ~ ~ ~ ~ "
block|,
literal|"* =& e ^ W ~ W ) t 3 Y.^.^.^.^.^.f.P ( ~ ~ ^ ; h ^.^.^.^.^.:.@ j ^.^.^.^.h.{ X.&.~ ~ ~ ~ ~ "
block|,
literal|"3 =& e ^ W ~ ~ ^ e 8 Q.^.^.^.^.^.s.P ~ ~ W ^> 0 ~.^.^.^.^.1.# z ^.^.^.^.d.L W R ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W ~ ~ ^> q ~.^.^.^.^.^.p.U ^ ~ W ) e 9 ~.^.^.^.^.3.# k ^.^.^.^.f.Y ( / ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W / W ^> w ~.^.^.^.^.^.i.Y / ~ W ^ e 8 Q.^.^.^.^.a.# z ^.^.^.^.f.Y / ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W / W ^> w ^.^.^.^.^.^.2.Y / ~ ~ ) e 8 Q.^.^.^.^.s.# z ^.^.^.^.d.P ( ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W W W ^> q ^.^.^.^.^.^.p.Y / ~ ~ ^ e 9 Q.^.^.^.^.a.@ z ^.^.^.^.f.U / ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W / W ) 7 9 Q.^.^.^.^.^.a.P / ~ W ) , 9 Q.^.^.^.^.3.# z ^.^.~.^.f.P ^ ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W / W ) r 5 T.^.^.^.^.^.d.Y / ~ W )> q ~.^.^.^.^.1.# k ^.^.^.^.f.Y ( ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ / / W ) i 2 I.^.^.^.^.^.h.P ( ~ W (> g ^.^.^.^.^.:.# z ^.^.^.^.f.P / ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ( W / W ) m O Z.^.^.^.^.^.x.P / ~ ~ ( ; j ^.^.^.^.~.&.- k ^.^.~.^.f.P / ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ( W / W ) F o y.^.~.^.^.^.N.U ( ~ ~ W $ b ^.^.^.^.R._ - k ^.^.^.^.f.Y ( ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W ~ ~ ^ J X 4.^.^.^.^.^.L.~ ~ W ^ T X #.^.^.^.^.F.~ ; j ^.^.^.^.f.U ( ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ ~ ~ ~ / ^ % l ^.^.^.^.^.!. .R ^ ^ G . r.^.~.^.^.j.E : j ^.^.^.^.f.P ) ( ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W ~ ~ W ) u = U.^.^.^.^.^.1.Y ! ) a& K.^.^.^.^.;.~ : j ^.^.~.^.z.M I I / ~ ~ W ~ "
block|,
literal|"= =& e ( W ~ ~ W ( G . q.^.^.^.^.^.D.U ^ ! X o.^.^.^.^.P.~ ^> g ^.^.^.^.E.-.$.m.X.W ~ ~ ~ "
block|,
literal|"= =& e ^ / ~ ~ ^ ! (> w ~.^.^.^.^.^.h.T> j T.^.^.~.^.a.Y _ i 3 U.^.^.^.^.^.^.^.X.R ~ ~ ~ "
block|,
literal|"= =& e ^ / ~ ~ W W ^ H . 9.^.~.^.^.^.^.K.C.~.^.^.^.^.H.W W ^ T . q.^.~.^.^.^.^.^.X.R ~ ~ ~ "
block|,
literal|"= = + e ^ W / ~ W W W ) m + B.^.~.^.^.^.^.^.^.^.^.^.E.X.Y ( W ^ B 6 y.^.^.^.E.D.2.( ~ ~ ~ ~ "
block|,
literal|"= = * e ^ ! / ! W ^ W W ) a 4 b.^.^.^.^.^.^.^.^.^.P...Y ( ! W ! ^ W Z [ *.X.{ Y U ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ( W ~ ~ W / W / W ) A< +.A.~.^.^.^.^.!.p.W R ~ ~ ~ ~ ~ W / ) E U W W / ^ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ W ~ ~ / W / / / W ( _ Z X 6.^.^.^.^.E.W ~ ^ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ / ~ ~ ~ ~ ~ ~ ~ ~ "
block|,
literal|"= =& e ^ ~ ~ ~ W W / W ~ ~ ~ ~ ) ; h ^.^.^.^.^.d.M U ~ / ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W "
block|,
literal|"= =& e ^ W ~ ~ ^ W W / ~ ~ ~ W ) p + S.^.^.^.^.~.M.f. .W ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  ."
block|,
literal|"= =& e ^ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W ( T O +.^.~.^.^.^.^.^.&.Y ( ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W ( Y 2."
block|,
literal|"= =& e ( W ~ ~ ~ ~ ~ ~ ~ ~ ~ / W ) N + b.^.^.^.^.^.^.&.R ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W /."
block|,
literal|"= =& e ^ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W ^ N 7 r.W.^.^.^.!.X.W ~ ~ W ~ W ~ ~ ~ ~ ~ ~ / ( ( K p./."
block|,
literal|"= =& e ( W ~ ~ W ~ ~ ~ ~ ~ ~ ~ ~ ~ W ( W C Q&.:.X.| ~ ~ ~ ~ W ~ / ~ ( / ( ~ W E U P 1././."
block|,
literal|"= = + e ^ / / / ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W / ) ^ R Y W W ~ ~ ( / ( / W R Y Y U R ( X.,././././."
block|,
literal|"= = * e ( / ~ / ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ W W W ! ( ( ( W W E U P Y W ( X.,.d./././././././././."
block|,
literal|"= = * e ( W ~ ~ ~ ~ W ! ~ W ~ W ~ ( ( / ^ W W U Y P W ( X.,.d./././././././././././././././."
block|,
literal|"8 $ * e ( W ~ ~ ~ ! ( ( ( / ( W R Y Y Y R ( X.>.d./././././././././././././././././././././."
block|,
literal|"/.d . y ^ / / / ( W Y Y P P W ( X.>.d./././././././././././././././././././././././././././."
block|,
literal|"/./.h : ^ R R R W ( X.<.f./././././././././././././././././././././././././././././././././."
block|,
literal|"/././.] _ *.3./././././././././././././././././././././././././././././././././././././././."
block|}
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|EvalMessageBox
class|class
name|EvalMessageBox
super|:
specifier|public
name|QDialog
block|{
public|public:
DECL|function|EvalMessageBox
name|EvalMessageBox
parameter_list|(
name|bool
name|expired
parameter_list|)
block|{
name|setWindowTitle
argument_list|(
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
argument_list|)
expr_stmt|;
name|QString
name|str
init|=
name|expired
condition|?
name|QLatin1String
argument_list|(
name|boilerplate_expired
argument_list|)
else|:
name|qt_eval_string
argument_list|()
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|trimmed
argument_list|()
expr_stmt|;
name|QFrame
modifier|*
name|border
init|=
operator|new
name|QFrame
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QLabel
modifier|*
name|pixmap_label
init|=
operator|new
name|QLabel
argument_list|(
name|border
argument_list|)
decl_stmt|;
name|pixmap_label
operator|->
name|setPixmap
argument_list|(
name|QPixmap
argument_list|(
name|qtlogo_eval_xpm
argument_list|)
argument_list|)
expr_stmt|;
name|pixmap_label
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|text_label
init|=
operator|new
name|QLabel
argument_list|(
name|str
argument_list|,
name|border
argument_list|)
decl_stmt|;
name|QHBoxLayout
modifier|*
name|pm_and_text_layout
init|=
operator|new
name|QHBoxLayout
argument_list|()
decl_stmt|;
name|pm_and_text_layout
operator|->
name|addWidget
argument_list|(
name|pixmap_label
argument_list|)
expr_stmt|;
name|pm_and_text_layout
operator|->
name|addWidget
argument_list|(
name|text_label
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|master_layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|border
argument_list|)
decl_stmt|;
name|master_layout
operator|->
name|addLayout
argument_list|(
name|pm_and_text_layout
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|border_layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|border_layout
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|border_layout
operator|->
name|addWidget
argument_list|(
name|border
argument_list|)
expr_stmt|;
if|if
condition|(
name|expired
condition|)
block|{
name|QPushButton
modifier|*
name|cmd
init|=
operator|new
name|QPushButton
argument_list|(
name|QLatin1String
argument_list|(
literal|"OK"
argument_list|)
argument_list|,
name|border
argument_list|)
decl_stmt|;
name|cmd
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
name|cmd
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|button_layout
init|=
operator|new
name|QHBoxLayout
argument_list|()
decl_stmt|;
name|master_layout
operator|->
name|addLayout
argument_list|(
name|button_layout
argument_list|)
expr_stmt|;
name|button_layout
operator|->
name|addWidget
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cmd
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|border
operator|->
name|setFrameShape
argument_list|(
name|QFrame
operator|::
name|WinPanel
argument_list|)
expr_stmt|;
name|border
operator|->
name|setFrameShadow
argument_list|(
name|QFrame
operator|::
name|Raised
argument_list|)
expr_stmt|;
name|setParent
argument_list|(
name|parentWidget
argument_list|()
argument_list|,
name|Qt
operator|::
name|FramelessWindowHint
operator||
name|Qt
operator|::
name|WindowStaysOnTopHint
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|7000
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_DeleteOnClose
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_QuitOnClose
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
name|setFixedSize
argument_list|(
name|sizeHint
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|QGuiFuriCuri
class|class
name|QGuiFuriCuri
super|:
specifier|public
name|QCoreFuriCuri
block|{
public|public:
DECL|function|timerEvent
name|void
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|warn
condition|)
block|{
name|killTimer
argument_list|(
name|warn
argument_list|)
expr_stmt|;
name|QMessageBox
operator|::
name|information
argument_list|(
literal|0
argument_list|,
name|QLatin1String
argument_list|(
literal|"Automatic Timeout"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|will_shutdown_1min
argument_list|)
argument_list|)
expr_stmt|;
name|kill
operator|=
name|startTimer
argument_list|(
name|KILL_DELAY
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|e
operator|->
name|timerId
argument_list|()
operator|==
name|kill
condition|)
block|{
name|killTimer
argument_list|(
name|kill
argument_list|)
expr_stmt|;
name|QMessageBox
operator|::
name|information
argument_list|(
literal|0
argument_list|,
name|QLatin1String
argument_list|(
literal|"Automatic Timeout"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
name|will_shutdown_now
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
block|}
class|;
end_class
begin_function
DECL|function|qt_gui_eval_init
name|void
name|qt_gui_eval_init
parameter_list|(
name|QCoreApplicationPrivate
operator|::
name|Type
name|type
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qt_eval_is_supported
argument_list|()
condition|)
return|return;
if|if
condition|(
name|qt_eval_is_expired
argument_list|()
condition|)
block|{
name|EvalMessageBox
name|box
argument_list|(
literal|true
argument_list|)
decl_stmt|;
name|box
operator|.
name|exec
argument_list|()
expr_stmt|;
operator|::
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|EvalMessageBox
modifier|*
name|box
init|=
operator|new
name|EvalMessageBox
argument_list|(
literal|false
argument_list|)
decl_stmt|;
name|box
operator|->
name|show
argument_list|()
expr_stmt|;
name|Q_UNUSED
argument_list|(
operator|new
name|QGuiFuriCuri
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|qt_eval_title_prefix
specifier|static
name|QString
name|qt_eval_title_prefix
parameter_list|()
block|{
return|return
name|QLatin1String
argument_list|(
literal|"[Qt Evaluation] "
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_eval_adapt_window_title
name|QString
name|qt_eval_adapt_window_title
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
if|if
condition|(
operator|!
name|qt_eval_is_supported
argument_list|()
condition|)
return|return
name|title
return|;
return|return
name|qt_eval_title_prefix
argument_list|()
operator|+
name|title
return|;
block|}
end_function
begin_function
DECL|function|qt_eval_init_widget
name|void
name|qt_eval_init_widget
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
if|if
condition|(
operator|!
name|qt_eval_is_supported
argument_list|()
condition|)
return|return;
if|if
condition|(
name|w
operator|->
name|isTopLevel
argument_list|()
operator|&&
name|w
operator|->
name|windowTitle
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|w
operator|->
name|windowType
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
condition|)
block|{
name|w
operator|->
name|setWindowTitle
argument_list|(
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
