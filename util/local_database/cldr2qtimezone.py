begin_unit
comment|'#!/usr/bin/env python'
nl|'\n'
comment|'#############################################################################'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).'
nl|'\n'
comment|'## Contact: http://www.qt-project.org/legal'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## This file is part of the test suite of the Qt Toolkit.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## $QT_BEGIN_LICENSE:LGPL$'
nl|'\n'
comment|'## Commercial License Usage'
nl|'\n'
comment|'## Licensees holding valid commercial Qt licenses may use this file in'
nl|'\n'
comment|'## accordance with the commercial license agreement provided with the'
nl|'\n'
comment|'## Software or, alternatively, in accordance with the terms contained in'
nl|'\n'
comment|'## a written agreement between you and Digia.  For licensing terms and'
nl|'\n'
comment|'## conditions see http://qt.digia.com/licensing.  For further information'
nl|'\n'
comment|'## use the contact form at http://qt.digia.com/contact-us.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## GNU Lesser General Public License Usage'
nl|'\n'
comment|'## Alternatively, this file may be used under the terms of the GNU Lesser'
nl|'\n'
comment|'## General Public License version 2.1 as published by the Free Software'
nl|'\n'
comment|'## Foundation and appearing in the file LICENSE.LGPL included in the'
nl|'\n'
comment|'## packaging of this file.  Please review the following information to'
nl|'\n'
comment|'## ensure the GNU Lesser General Public License version 2.1 requirements'
nl|'\n'
comment|'## will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## In addition, as a special exception, Digia gives you certain additional'
nl|'\n'
comment|'## rights.  These rights are described in the Digia Qt LGPL Exception'
nl|'\n'
comment|'## version 1.1, included in the file LGPL_EXCEPTION.txt in this package.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## GNU General Public License Usage'
nl|'\n'
comment|'## Alternatively, this file may be used under the terms of the GNU'
nl|'\n'
comment|'## General Public License version 3.0 as published by the Free Software'
nl|'\n'
comment|'## Foundation and appearing in the file LICENSE.GPL included in the'
nl|'\n'
comment|'## packaging of this file.  Please review the following information to'
nl|'\n'
comment|'## ensure the GNU General Public License version 3.0 requirements will be'
nl|'\n'
comment|'## met: http://www.gnu.org/copyleft/gpl.html.'
nl|'\n'
comment|'##'
nl|'\n'
comment|'##'
nl|'\n'
comment|'## $QT_END_LICENSE$'
nl|'\n'
comment|'##'
nl|'\n'
comment|'#############################################################################'
nl|'\n'
nl|'\n'
nl|'\n'
comment|'# Script to parse the CLDR supplemental/windowsZones.xml file and encode for use in QTimeZone'
nl|'\n'
comment|'# XML structure is as follows:'
nl|'\n'
comment|'#'
nl|'\n'
comment|'# <supplementalData>'
nl|'\n'
comment|'#     <version number="$Revision: 7825 $"/>'
nl|'\n'
comment|'#     <generation date="$Date: 2012-10-10 14:45:31 -0700 (Wed, 10 Oct 2012) $"/>'
nl|'\n'
comment|'#     <windowsZones>'
nl|'\n'
comment|'#         <mapTimezones otherVersion="7dc0101" typeVersion="2012f">'
nl|'\n'
comment|'#             <!-- (UTC-08:00) Pacific Time (US & Canada) -->'
nl|'\n'
comment|'#             <mapZone other="Pacific Standard Time" territory="001" type="America/Los_Angeles"/>'
nl|'\n'
comment|'#             <mapZone other="Pacific Standard Time" territory="CA"  type="America/Vancouver America/Dawson America/Whitehorse"/>'
nl|'\n'
comment|'#             <mapZone other="Pacific Standard Time" territory="MX"  type="America/Tijuana"/>'
nl|'\n'
comment|'#             <mapZone other="Pacific Standard Time" territory="US"  type="America/Los_Angeles"/>'
nl|'\n'
comment|'#             <mapZone other="Pacific Standard Time" territory="ZZ"  type="PST8PDT"/>'
nl|'\n'
comment|'#       </mapTimezones>'
nl|'\n'
comment|'#     </windowsZones>'
nl|'\n'
comment|'# </supplementalData>'
nl|'\n'
nl|'\n'
name|'import'
name|'os'
newline|'\n'
name|'import'
name|'sys'
newline|'\n'
name|'import'
name|'datetime'
newline|'\n'
name|'import'
name|'tempfile'
newline|'\n'
name|'import'
name|'enumdata'
newline|'\n'
name|'import'
name|'xpathlite'
newline|'\n'
name|'from'
name|'xpathlite'
name|'import'
name|'DraftResolution'
newline|'\n'
name|'import'
name|'re'
newline|'\n'
name|'import'
name|'qlocalexml2cpp'
newline|'\n'
nl|'\n'
DECL|variable|findAlias
name|'findAlias'
op|'='
name|'xpathlite'
op|'.'
name|'findAlias'
newline|'\n'
DECL|variable|findEntry
name|'findEntry'
op|'='
name|'xpathlite'
op|'.'
name|'findEntry'
newline|'\n'
DECL|variable|findEntryInFile
name|'findEntryInFile'
op|'='
name|'xpathlite'
op|'.'
name|'_findEntryInFile'
newline|'\n'
DECL|variable|findTagsInFile
name|'findTagsInFile'
op|'='
name|'xpathlite'
op|'.'
name|'findTagsInFile'
newline|'\n'
DECL|variable|unicode2hex
name|'unicode2hex'
op|'='
name|'qlocalexml2cpp'
op|'.'
name|'unicode2hex'
newline|'\n'
DECL|variable|wrap_list
name|'wrap_list'
op|'='
name|'qlocalexml2cpp'
op|'.'
name|'wrap_list'
newline|'\n'
nl|'\n'
DECL|class|ByteArrayData
name|'class'
name|'ByteArrayData'
op|':'
newline|'\n'
DECL|member|__init__
indent|'    '
name|'def'
name|'__init__'
op|'('
name|'self'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'self'
op|'.'
name|'data'
op|'='
op|'['
op|']'
newline|'\n'
name|'self'
op|'.'
name|'hash'
op|'='
op|'{'
op|'}'
newline|'\n'
DECL|member|append
dedent|''
name|'def'
name|'append'
op|'('
name|'self'
op|','
name|'s'
op|')'
op|':'
newline|'\n'
indent|'        '
name|'s'
op|'='
name|'s'
op|'+'
string|"'\\0'"
newline|'\n'
name|'if'
name|'s'
name|'in'
name|'self'
op|'.'
name|'hash'
op|':'
newline|'\n'
indent|'            '
name|'return'
name|'self'
op|'.'
name|'hash'
op|'['
name|'s'
op|']'
newline|'\n'
nl|'\n'
dedent|''
name|'lst'
op|'='
name|'unicode2hex'
op|'('
name|'s'
op|')'
newline|'\n'
name|'index'
op|'='
name|'len'
op|'('
name|'self'
op|'.'
name|'data'
op|')'
newline|'\n'
name|'if'
name|'index'
op|'>'
number|'65535'
op|':'
newline|'\n'
indent|'            '
name|'print'
string|'"\\n\\n\\n#error Data index is too big!"'
newline|'\n'
name|'sys'
op|'.'
name|'stderr'
op|'.'
name|'write'
op|'('
string|'"\\n\\n\\nERROR: index exceeds the uint16 range! index = %d\\n"'
op|'%'
name|'index'
op|')'
newline|'\n'
name|'sys'
op|'.'
name|'exit'
op|'('
number|'1'
op|')'
newline|'\n'
dedent|''
name|'self'
op|'.'
name|'hash'
op|'['
name|'s'
op|']'
op|'='
name|'index'
newline|'\n'
name|'self'
op|'.'
name|'data'
op|'+='
name|'lst'
newline|'\n'
name|'return'
name|'index'
newline|'\n'
nl|'\n'
comment|'# List of currently known Windows IDs.  If script fails on missing ID plase add it here'
nl|'\n'
comment|'# Not public so may be safely changed.'
nl|'\n'
comment|'# Windows Key : [ Windows Id, Offset Seconds ]'
nl|'\n'
DECL|variable|windowsIdList
dedent|''
dedent|''
name|'windowsIdList'
op|'='
op|'{'
nl|'\n'
number|'1'
op|':'
op|'['
string|"u'Afghanistan Standard Time'"
op|','
number|'16200'
op|']'
op|','
nl|'\n'
number|'2'
op|':'
op|'['
string|"u'Alaskan Standard Time'"
op|','
op|'-'
number|'32400'
op|']'
op|','
nl|'\n'
number|'3'
op|':'
op|'['
string|"u'Arab Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'4'
op|':'
op|'['
string|"u'Arabian Standard Time'"
op|','
number|'14400'
op|']'
op|','
nl|'\n'
number|'5'
op|':'
op|'['
string|"u'Arabic Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'6'
op|':'
op|'['
string|"u'Argentina Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'7'
op|':'
op|'['
string|"u'Atlantic Standard Time'"
op|','
op|'-'
number|'14400'
op|']'
op|','
nl|'\n'
number|'8'
op|':'
op|'['
string|"u'AUS Central Standard Time'"
op|','
number|'34200'
op|']'
op|','
nl|'\n'
number|'9'
op|':'
op|'['
string|"u'AUS Eastern Standard Time'"
op|','
number|'36000'
op|']'
op|','
nl|'\n'
number|'10'
op|':'
op|'['
string|"u'Azerbaijan Standard Time'"
op|','
number|'14400'
op|']'
op|','
nl|'\n'
number|'11'
op|':'
op|'['
string|"u'Azores Standard Time'"
op|','
op|'-'
number|'3600'
op|']'
op|','
nl|'\n'
number|'12'
op|':'
op|'['
string|"u'Bahia Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'13'
op|':'
op|'['
string|"u'Bangladesh Standard Time'"
op|','
number|'21600'
op|']'
op|','
nl|'\n'
number|'14'
op|':'
op|'['
string|"u'Canada Central Standard Time'"
op|','
op|'-'
number|'21600'
op|']'
op|','
nl|'\n'
number|'15'
op|':'
op|'['
string|"u'Cape Verde Standard Time'"
op|','
op|'-'
number|'3600'
op|']'
op|','
nl|'\n'
number|'16'
op|':'
op|'['
string|"u'Caucasus Standard Time'"
op|','
number|'14400'
op|']'
op|','
nl|'\n'
number|'17'
op|':'
op|'['
string|"u'Cen. Australia Standard Time'"
op|','
number|'34200'
op|']'
op|','
nl|'\n'
number|'18'
op|':'
op|'['
string|"u'Central America Standard Time'"
op|','
op|'-'
number|'21600'
op|']'
op|','
nl|'\n'
number|'19'
op|':'
op|'['
string|"u'Central Asia Standard Time'"
op|','
number|'21600'
op|']'
op|','
nl|'\n'
number|'20'
op|':'
op|'['
string|"u'Central Brazilian Standard Time'"
op|','
op|'-'
number|'14400'
op|']'
op|','
nl|'\n'
number|'21'
op|':'
op|'['
string|"u'Central Europe Standard Time'"
op|','
number|'3600'
op|']'
op|','
nl|'\n'
number|'22'
op|':'
op|'['
string|"u'Central European Standard Time'"
op|','
number|'3600'
op|']'
op|','
nl|'\n'
number|'23'
op|':'
op|'['
string|"u'Central Pacific Standard Time'"
op|','
number|'39600'
op|']'
op|','
nl|'\n'
number|'24'
op|':'
op|'['
string|"u'Central Standard Time (Mexico)'"
op|','
op|'-'
number|'21600'
op|']'
op|','
nl|'\n'
number|'25'
op|':'
op|'['
string|"u'Central Standard Time'"
op|','
op|'-'
number|'21600'
op|']'
op|','
nl|'\n'
number|'26'
op|':'
op|'['
string|"u'China Standard Time'"
op|','
number|'28800'
op|']'
op|','
nl|'\n'
number|'27'
op|':'
op|'['
string|"u'Dateline Standard Time'"
op|','
op|'-'
number|'43200'
op|']'
op|','
nl|'\n'
number|'28'
op|':'
op|'['
string|"u'E. Africa Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'29'
op|':'
op|'['
string|"u'E. Australia Standard Time'"
op|','
number|'36000'
op|']'
op|','
nl|'\n'
number|'30'
op|':'
op|'['
string|"u'E. Europe Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'31'
op|':'
op|'['
string|"u'E. South America Standard Time'"
op|','
op|'-'
number|'10800'
op|']'
op|','
nl|'\n'
number|'32'
op|':'
op|'['
string|"u'Eastern Standard Time'"
op|','
op|'-'
number|'18000'
op|']'
op|','
nl|'\n'
number|'33'
op|':'
op|'['
string|"u'Egypt Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'34'
op|':'
op|'['
string|"u'Ekaterinburg Standard Time'"
op|','
number|'21600'
op|']'
op|','
nl|'\n'
number|'35'
op|':'
op|'['
string|"u'Fiji Standard Time'"
op|','
number|'43200'
op|']'
op|','
nl|'\n'
number|'36'
op|':'
op|'['
string|"u'FLE Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'37'
op|':'
op|'['
string|"u'Georgian Standard Time'"
op|','
number|'14400'
op|']'
op|','
nl|'\n'
number|'38'
op|':'
op|'['
string|"u'GMT Standard Time'"
op|','
number|'0'
op|']'
op|','
nl|'\n'
number|'39'
op|':'
op|'['
string|"u'Greenland Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'40'
op|':'
op|'['
string|"u'Greenwich Standard Time'"
op|','
number|'0'
op|']'
op|','
nl|'\n'
number|'41'
op|':'
op|'['
string|"u'GTB Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'42'
op|':'
op|'['
string|"u'Hawaiian Standard Time'"
op|','
op|'-'
number|'36000'
op|']'
op|','
nl|'\n'
number|'43'
op|':'
op|'['
string|"u'India Standard Time'"
op|','
number|'19800'
op|']'
op|','
nl|'\n'
number|'44'
op|':'
op|'['
string|"u'Iran Standard Time'"
op|','
number|'12600'
op|']'
op|','
nl|'\n'
number|'45'
op|':'
op|'['
string|"u'Israel Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'46'
op|':'
op|'['
string|"u'Jordan Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'47'
op|':'
op|'['
string|"u'Kaliningrad Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'48'
op|':'
op|'['
string|"u'Korea Standard Time'"
op|','
number|'32400'
op|']'
op|','
nl|'\n'
number|'49'
op|':'
op|'['
string|"u'Magadan Standard Time'"
op|','
number|'43200'
op|']'
op|','
nl|'\n'
number|'50'
op|':'
op|'['
string|"u'Mauritius Standard Time'"
op|','
number|'14400'
op|']'
op|','
nl|'\n'
number|'51'
op|':'
op|'['
string|"u'Middle East Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'52'
op|':'
op|'['
string|"u'Montevideo Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'53'
op|':'
op|'['
string|"u'Morocco Standard Time'"
op|','
number|'0'
op|']'
op|','
nl|'\n'
number|'54'
op|':'
op|'['
string|"u'Mountain Standard Time (Mexico)'"
op|','
op|'-'
number|'25200'
op|']'
op|','
nl|'\n'
number|'55'
op|':'
op|'['
string|"u'Mountain Standard Time'"
op|','
op|'-'
number|'25200'
op|']'
op|','
nl|'\n'
number|'56'
op|':'
op|'['
string|"u'Myanmar Standard Time'"
op|','
number|'23400'
op|']'
op|','
nl|'\n'
number|'57'
op|':'
op|'['
string|"u'N. Central Asia Standard Time'"
op|','
number|'23400'
op|']'
op|','
nl|'\n'
number|'58'
op|':'
op|'['
string|"u'Namibia Standard Time'"
op|','
number|'3600'
op|']'
op|','
nl|'\n'
number|'59'
op|':'
op|'['
string|"u'Nepal Standard Time'"
op|','
number|'20700'
op|']'
op|','
nl|'\n'
number|'60'
op|':'
op|'['
string|"u'New Zealand Standard Time'"
op|','
number|'43200'
op|']'
op|','
nl|'\n'
number|'61'
op|':'
op|'['
string|"u'Newfoundland Standard Time'"
op|','
op|'-'
number|'12600'
op|']'
op|','
nl|'\n'
number|'62'
op|':'
op|'['
string|"u'North Asia East Standard Time'"
op|','
number|'32400'
op|']'
op|','
nl|'\n'
number|'63'
op|':'
op|'['
string|"u'North Asia Standard Time'"
op|','
number|'28800'
op|']'
op|','
nl|'\n'
number|'64'
op|':'
op|'['
string|"u'Pacific SA Standard Time'"
op|','
op|'-'
number|'14400'
op|']'
op|','
nl|'\n'
number|'65'
op|':'
op|'['
string|"u'Pacific Standard Time (Mexico)'"
op|','
op|'-'
number|'28800'
op|']'
op|','
nl|'\n'
number|'66'
op|':'
op|'['
string|"u'Pacific Standard Time'"
op|','
op|'-'
number|'28800'
op|']'
op|','
nl|'\n'
number|'67'
op|':'
op|'['
string|"u'Pakistan Standard Time'"
op|','
number|'18000'
op|']'
op|','
nl|'\n'
number|'68'
op|':'
op|'['
string|"u'Paraguay Standard Time'"
op|','
op|'-'
number|'14400'
op|']'
op|','
nl|'\n'
number|'69'
op|':'
op|'['
string|"u'Romance Standard Time'"
op|','
number|'3600'
op|']'
op|','
nl|'\n'
number|'70'
op|':'
op|'['
string|"u'Russian Standard Time'"
op|','
number|'14400'
op|']'
op|','
nl|'\n'
number|'71'
op|':'
op|'['
string|"u'SA Eastern Standard Time'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'72'
op|':'
op|'['
string|"u'SA Pacific Standard Time'"
op|','
op|'-'
number|'18000'
op|']'
op|','
nl|'\n'
number|'73'
op|':'
op|'['
string|"u'SA Western Standard Time'"
op|','
op|'-'
number|'14400'
op|']'
op|','
nl|'\n'
number|'74'
op|':'
op|'['
string|"u'Samoa Standard Time'"
op|','
number|'46800'
op|']'
op|','
nl|'\n'
number|'75'
op|':'
op|'['
string|"u'SE Asia Standard Time'"
op|','
number|'23400'
op|']'
op|','
nl|'\n'
number|'76'
op|':'
op|'['
string|"u'Singapore Standard Time'"
op|','
number|'28800'
op|']'
op|','
nl|'\n'
number|'77'
op|':'
op|'['
string|"u'South Africa Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'78'
op|':'
op|'['
string|"u'Sri Lanka Standard Time'"
op|','
number|'19800'
op|']'
op|','
nl|'\n'
number|'79'
op|':'
op|'['
string|"u'Syria Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'80'
op|':'
op|'['
string|"u'Taipei Standard Time'"
op|','
number|'28800'
op|']'
op|','
nl|'\n'
number|'81'
op|':'
op|'['
string|"u'Tasmania Standard Time'"
op|','
number|'36000'
op|']'
op|','
nl|'\n'
number|'82'
op|':'
op|'['
string|"u'Tokyo Standard Time'"
op|','
number|'32400'
op|']'
op|','
nl|'\n'
number|'83'
op|':'
op|'['
string|"u'Tonga Standard Time'"
op|','
number|'46800'
op|']'
op|','
nl|'\n'
number|'84'
op|':'
op|'['
string|"u'Turkey Standard Time'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'85'
op|':'
op|'['
string|"u'Ulaanbaatar Standard Time'"
op|','
number|'28800'
op|']'
op|','
nl|'\n'
number|'86'
op|':'
op|'['
string|"u'US Eastern Standard Time'"
op|','
op|'-'
number|'18000'
op|']'
op|','
nl|'\n'
number|'87'
op|':'
op|'['
string|"u'US Mountain Standard Time'"
op|','
op|'-'
number|'25200'
op|']'
op|','
nl|'\n'
number|'88'
op|':'
op|'['
string|"u'UTC-02'"
op|','
op|'-'
number|'7200'
op|']'
op|','
nl|'\n'
number|'89'
op|':'
op|'['
string|"u'UTC-11'"
op|','
op|'-'
number|'39600'
op|']'
op|','
nl|'\n'
number|'90'
op|':'
op|'['
string|"u'UTC'"
op|','
number|'0'
op|']'
op|','
nl|'\n'
number|'91'
op|':'
op|'['
string|"u'UTC+12'"
op|','
number|'43200'
op|']'
op|','
nl|'\n'
number|'92'
op|':'
op|'['
string|"u'Venezuela Standard Time'"
op|','
op|'-'
number|'16200'
op|']'
op|','
nl|'\n'
number|'93'
op|':'
op|'['
string|"u'Vladivostok Standard Time'"
op|','
number|'39600'
op|']'
op|','
nl|'\n'
number|'94'
op|':'
op|'['
string|"u'W. Australia Standard Time'"
op|','
number|'28800'
op|']'
op|','
nl|'\n'
number|'95'
op|':'
op|'['
string|"u'W. Central Africa Standard Time'"
op|','
number|'3600'
op|']'
op|','
nl|'\n'
number|'96'
op|':'
op|'['
string|"u'W. Europe Standard Time'"
op|','
number|'3600'
op|']'
op|','
nl|'\n'
number|'97'
op|':'
op|'['
string|"u'West Asia Standard Time'"
op|','
number|'18000'
op|']'
op|','
nl|'\n'
number|'98'
op|':'
op|'['
string|"u'West Pacific Standard Time'"
op|','
number|'36000'
op|']'
op|','
nl|'\n'
number|'99'
op|':'
op|'['
string|"u'Yakutsk Standard Time'"
op|','
number|'36000'
op|']'
nl|'\n'
op|'}'
newline|'\n'
nl|'\n'
DECL|function|windowsIdToKey
name|'def'
name|'windowsIdToKey'
op|'('
name|'windowsId'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'for'
name|'windowsKey'
name|'in'
name|'windowsIdList'
op|':'
newline|'\n'
indent|'        '
name|'if'
name|'windowsIdList'
op|'['
name|'windowsKey'
op|']'
op|'['
number|'0'
op|']'
op|'=='
name|'windowsId'
op|':'
newline|'\n'
indent|'            '
name|'return'
name|'windowsKey'
newline|'\n'
dedent|''
dedent|''
name|'return'
number|'0'
newline|'\n'
nl|'\n'
comment|'# List of standard UTC IDs to use.  Not public so may be safely changed.'
nl|'\n'
comment|"# Do not remove ID's as is part of API/behavior guarantee"
nl|'\n'
comment|'# Key : [ UTC Id, Offset Seconds ]'
nl|'\n'
DECL|variable|utcIdList
dedent|''
name|'utcIdList'
op|'='
op|'{'
nl|'\n'
number|'0'
op|':'
op|'['
string|"u'UTC'"
op|','
number|'0'
op|']'
op|','
comment|'# Goes first so is default'
nl|'\n'
number|'1'
op|':'
op|'['
string|"u'UTC-14:00'"
op|','
op|'-'
number|'50400'
op|']'
op|','
nl|'\n'
number|'2'
op|':'
op|'['
string|"u'UTC-13:00'"
op|','
op|'-'
number|'46800'
op|']'
op|','
nl|'\n'
number|'3'
op|':'
op|'['
string|"u'UTC-12:00'"
op|','
op|'-'
number|'43200'
op|']'
op|','
nl|'\n'
number|'4'
op|':'
op|'['
string|"u'UTC-11:00'"
op|','
op|'-'
number|'39600'
op|']'
op|','
nl|'\n'
number|'5'
op|':'
op|'['
string|"u'UTC-10:00'"
op|','
op|'-'
number|'36000'
op|']'
op|','
nl|'\n'
number|'6'
op|':'
op|'['
string|"u'UTC-09:00'"
op|','
op|'-'
number|'32400'
op|']'
op|','
nl|'\n'
number|'7'
op|':'
op|'['
string|"u'UTC-08:00'"
op|','
op|'-'
number|'28800'
op|']'
op|','
nl|'\n'
number|'8'
op|':'
op|'['
string|"u'UTC-07:00'"
op|','
op|'-'
number|'25200'
op|']'
op|','
nl|'\n'
number|'9'
op|':'
op|'['
string|"u'UTC-06:00'"
op|','
op|'-'
number|'21600'
op|']'
op|','
nl|'\n'
number|'10'
op|':'
op|'['
string|"u'UTC-05:00'"
op|','
op|'-'
number|'18000'
op|']'
op|','
nl|'\n'
number|'11'
op|':'
op|'['
string|"u'UTC-04:30'"
op|','
op|'-'
number|'16200'
op|']'
op|','
nl|'\n'
number|'12'
op|':'
op|'['
string|"u'UTC-04:00'"
op|','
op|'-'
number|'14400'
op|']'
op|','
nl|'\n'
number|'13'
op|':'
op|'['
string|"u'UTC-03:30'"
op|','
op|'-'
number|'12600'
op|']'
op|','
nl|'\n'
number|'14'
op|':'
op|'['
string|"u'UTC-03:00'"
op|','
op|'-'
number|'10800'
op|']'
op|','
nl|'\n'
number|'15'
op|':'
op|'['
string|"u'UTC-02:00'"
op|','
op|'-'
number|'7200'
op|']'
op|','
nl|'\n'
number|'16'
op|':'
op|'['
string|"u'UTC-01:00'"
op|','
op|'-'
number|'3600'
op|']'
op|','
nl|'\n'
number|'17'
op|':'
op|'['
string|"u'UTC-00:00'"
op|','
number|'0'
op|']'
op|','
nl|'\n'
number|'18'
op|':'
op|'['
string|"u'UTC+00:00'"
op|','
number|'0'
op|']'
op|','
nl|'\n'
number|'19'
op|':'
op|'['
string|"u'UTC+01:00'"
op|','
number|'3600'
op|']'
op|','
nl|'\n'
number|'20'
op|':'
op|'['
string|"u'UTC+02:00'"
op|','
number|'7200'
op|']'
op|','
nl|'\n'
number|'21'
op|':'
op|'['
string|"u'UTC+03:00'"
op|','
number|'10800'
op|']'
op|','
nl|'\n'
number|'22'
op|':'
op|'['
string|"u'UTC+03:30'"
op|','
number|'12600'
op|']'
op|','
nl|'\n'
number|'23'
op|':'
op|'['
string|"u'UTC+04:00'"
op|','
number|'14400'
op|']'
op|','
nl|'\n'
number|'24'
op|':'
op|'['
string|"u'UTC+04:30'"
op|','
number|'16200'
op|']'
op|','
nl|'\n'
number|'25'
op|':'
op|'['
string|"u'UTC+05:00'"
op|','
number|'18000'
op|']'
op|','
nl|'\n'
number|'26'
op|':'
op|'['
string|"u'UTC+05:30'"
op|','
number|'19800'
op|']'
op|','
nl|'\n'
number|'27'
op|':'
op|'['
string|"u'UTC+05:45'"
op|','
number|'20700'
op|']'
op|','
nl|'\n'
number|'28'
op|':'
op|'['
string|"u'UTC+06:00'"
op|','
number|'21600'
op|']'
op|','
nl|'\n'
number|'29'
op|':'
op|'['
string|"u'UTC+06:30'"
op|','
number|'23400'
op|']'
op|','
nl|'\n'
number|'30'
op|':'
op|'['
string|"u'UTC+07:00'"
op|','
number|'25200'
op|']'
op|','
nl|'\n'
number|'31'
op|':'
op|'['
string|"u'UTC+08:00'"
op|','
number|'28800'
op|']'
op|','
nl|'\n'
number|'32'
op|':'
op|'['
string|"u'UTC+09:00'"
op|','
number|'32400'
op|']'
op|','
nl|'\n'
number|'33'
op|':'
op|'['
string|"u'UTC+09:30'"
op|','
number|'34200'
op|']'
op|','
nl|'\n'
number|'34'
op|':'
op|'['
string|"u'UTC+10:00'"
op|','
number|'36000'
op|']'
op|','
nl|'\n'
number|'35'
op|':'
op|'['
string|"u'UTC+11:00'"
op|','
number|'39600'
op|']'
op|','
nl|'\n'
number|'36'
op|':'
op|'['
string|"u'UTC+12:00'"
op|','
number|'43200'
op|']'
op|','
nl|'\n'
number|'37'
op|':'
op|'['
string|"u'UTC+13:00'"
op|','
number|'46800'
op|']'
op|','
nl|'\n'
number|'38'
op|':'
op|'['
string|"u'UTC+14:00'"
op|','
number|'50400'
op|']'
nl|'\n'
op|'}'
newline|'\n'
nl|'\n'
DECL|function|usage
name|'def'
name|'usage'
op|'('
op|')'
op|':'
newline|'\n'
indent|'    '
name|'print'
string|'"Usage: cldr2qtimezone.py <path to cldr core/common> <path to qtbase>"'
newline|'\n'
name|'sys'
op|'.'
name|'exit'
op|'('
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'if'
name|'len'
op|'('
name|'sys'
op|'.'
name|'argv'
op|')'
op|'!='
number|'3'
op|':'
newline|'\n'
indent|'    '
name|'usage'
op|'('
op|')'
newline|'\n'
nl|'\n'
DECL|variable|cldrPath
dedent|''
name|'cldrPath'
op|'='
name|'sys'
op|'.'
name|'argv'
op|'['
number|'1'
op|']'
newline|'\n'
DECL|variable|qtPath
name|'qtPath'
op|'='
name|'sys'
op|'.'
name|'argv'
op|'['
number|'2'
op|']'
newline|'\n'
nl|'\n'
name|'if'
name|'not'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isdir'
op|'('
name|'cldrPath'
op|')'
name|'or'
name|'not'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isdir'
op|'('
name|'qtPath'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'usage'
op|'('
op|')'
newline|'\n'
nl|'\n'
DECL|variable|windowsZonesPath
dedent|''
name|'windowsZonesPath'
op|'='
name|'cldrPath'
op|'+'
string|'"/supplemental/windowsZones.xml"'
newline|'\n'
DECL|variable|tempFileDir
name|'tempFileDir'
op|'='
name|'qtPath'
op|'+'
string|'"/src/corelib/tools"'
newline|'\n'
DECL|variable|dataFilePath
name|'dataFilePath'
op|'='
name|'qtPath'
op|'+'
string|'"/src/corelib/tools/qtimezoneprivate_data_p.h"'
newline|'\n'
nl|'\n'
name|'if'
name|'not'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isfile'
op|'('
name|'windowsZonesPath'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'usage'
op|'('
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'if'
name|'not'
name|'os'
op|'.'
name|'path'
op|'.'
name|'isfile'
op|'('
name|'dataFilePath'
op|')'
op|':'
newline|'\n'
indent|'    '
name|'usage'
op|'('
op|')'
newline|'\n'
nl|'\n'
comment|"# [[u'version', [(u'number', u'$Revision: 7825 $')]]]"
nl|'\n'
DECL|variable|versionNumber
dedent|''
name|'versionNumber'
op|'='
name|'findTagsInFile'
op|'('
name|'windowsZonesPath'
op|','
string|'"version"'
op|')'
op|'['
number|'0'
op|']'
op|'['
number|'1'
op|']'
op|'['
number|'0'
op|']'
op|'['
number|'1'
op|']'
newline|'\n'
nl|'\n'
comment|"# [[u'generation', [(u'date', u'$Date: 2012-10-10 14:45:31 -0700 (Wed, 10 Oct 2012) $')]]]"
nl|'\n'
DECL|variable|generationDate
name|'generationDate'
op|'='
name|'findTagsInFile'
op|'('
name|'windowsZonesPath'
op|','
string|'"generation"'
op|')'
op|'['
number|'0'
op|']'
op|'['
number|'1'
op|']'
op|'['
number|'0'
op|']'
op|'['
number|'1'
op|']'
newline|'\n'
nl|'\n'
DECL|variable|mapTimezones
name|'mapTimezones'
op|'='
name|'findTagsInFile'
op|'('
name|'windowsZonesPath'
op|','
string|'"windowsZones/mapTimezones"'
op|')'
newline|'\n'
nl|'\n'
DECL|variable|defaultDict
name|'defaultDict'
op|'='
op|'{'
op|'}'
newline|'\n'
DECL|variable|windowsIdDict
name|'windowsIdDict'
op|'='
op|'{'
op|'}'
newline|'\n'
nl|'\n'
name|'if'
name|'mapTimezones'
op|':'
newline|'\n'
indent|'    '
name|'for'
name|'mapZone'
name|'in'
name|'mapTimezones'
op|':'
newline|'\n'
comment|"# [u'mapZone', [(u'territory', u'MH'), (u'other', u'UTC+12'), (u'type', u'Pacific/Majuro Pacific/Kwajalein')]]"
nl|'\n'
indent|'        '
name|'if'
name|'mapZone'
op|'['
number|'0'
op|']'
op|'=='
string|"u'mapZone'"
op|':'
newline|'\n'
indent|'            '
name|'data'
op|'='
op|'{'
op|'}'
newline|'\n'
name|'for'
name|'attribute'
name|'in'
name|'mapZone'
op|'['
number|'1'
op|']'
op|':'
newline|'\n'
indent|'                '
name|'if'
name|'attribute'
op|'['
number|'0'
op|']'
op|'=='
string|"u'other'"
op|':'
newline|'\n'
indent|'                    '
name|'data'
op|'['
string|"'windowsId'"
op|']'
op|'='
name|'attribute'
op|'['
number|'1'
op|']'
newline|'\n'
dedent|''
name|'if'
name|'attribute'
op|'['
number|'0'
op|']'
op|'=='
string|"u'territory'"
op|':'
newline|'\n'
indent|'                    '
name|'data'
op|'['
string|"'countryCode'"
op|']'
op|'='
name|'attribute'
op|'['
number|'1'
op|']'
newline|'\n'
dedent|''
name|'if'
name|'attribute'
op|'['
number|'0'
op|']'
op|'=='
string|"u'type'"
op|':'
newline|'\n'
indent|'                    '
name|'data'
op|'['
string|"'olsenList'"
op|']'
op|'='
name|'attribute'
op|'['
number|'1'
op|']'
newline|'\n'
nl|'\n'
dedent|''
dedent|''
name|'data'
op|'['
string|"'windowsKey'"
op|']'
op|'='
name|'windowsIdToKey'
op|'('
name|'data'
op|'['
string|"'windowsId'"
op|']'
op|')'
newline|'\n'
name|'if'
name|'data'
op|'['
string|"'windowsKey'"
op|']'
op|'<='
number|'0'
op|':'
newline|'\n'
indent|'                '
name|'raise'
name|'xpathlite'
op|'.'
name|'Error'
op|'('
string|'"Unknown Windows ID, please add \\"%s\\""'
op|'%'
name|'data'
op|'['
string|"'windowsId'"
op|']'
op|')'
newline|'\n'
nl|'\n'
dedent|''
name|'countryId'
op|'='
number|'0'
newline|'\n'
name|'if'
name|'data'
op|'['
string|"'countryCode'"
op|']'
op|'=='
string|"u'001'"
op|':'
newline|'\n'
indent|'                '
name|'defaultDict'
op|'['
name|'data'
op|'['
string|"'windowsKey'"
op|']'
op|']'
op|'='
name|'data'
op|'['
string|"'olsenList'"
op|']'
newline|'\n'
dedent|''
name|'else'
op|':'
newline|'\n'
indent|'                '
name|'data'
op|'['
string|"'countryId'"
op|']'
op|'='
name|'enumdata'
op|'.'
name|'countryCodeToId'
op|'('
name|'data'
op|'['
string|"'countryCode'"
op|']'
op|')'
newline|'\n'
name|'if'
name|'data'
op|'['
string|"'countryId'"
op|']'
op|'<'
number|'0'
op|':'
newline|'\n'
indent|'                    '
name|'raise'
name|'xpathlite'
op|'.'
name|'Error'
op|'('
string|'"Unknown Country Code \\"%s\\""'
op|'%'
name|'data'
op|'['
string|"'countryCode'"
op|']'
op|')'
newline|'\n'
dedent|''
name|'data'
op|'['
string|"'country'"
op|']'
op|'='
name|'enumdata'
op|'.'
name|'country_list'
op|'['
name|'data'
op|'['
string|"'countryId'"
op|']'
op|']'
op|'['
number|'0'
op|']'
newline|'\n'
name|'windowsIdDict'
op|'['
name|'data'
op|'['
string|"'windowsKey'"
op|']'
op|','
name|'data'
op|'['
string|"'countryId'"
op|']'
op|']'
op|'='
name|'data'
newline|'\n'
nl|'\n'
dedent|''
dedent|''
dedent|''
dedent|''
name|'print'
string|'"Input file parsed, now writing data"'
newline|'\n'
nl|'\n'
DECL|variable|GENERATED_BLOCK_START
name|'GENERATED_BLOCK_START'
op|'='
string|'"// GENERATED PART STARTS HERE\\n"'
newline|'\n'
DECL|variable|GENERATED_BLOCK_END
name|'GENERATED_BLOCK_END'
op|'='
string|'"// GENERATED PART ENDS HERE\\n"'
newline|'\n'
nl|'\n'
comment|'# Create a temp file to write the new data into'
nl|'\n'
op|'('
name|'newTempFile'
op|','
name|'newTempFilePath'
op|')'
op|'='
name|'tempfile'
op|'.'
name|'mkstemp'
op|'('
string|'"qtimezone_data_p"'
op|','
name|'dir'
op|'='
name|'tempFileDir'
op|')'
newline|'\n'
DECL|variable|newTempFile
name|'newTempFile'
op|'='
name|'os'
op|'.'
name|'fdopen'
op|'('
name|'newTempFile'
op|','
string|'"w"'
op|')'
newline|'\n'
nl|'\n'
comment|'# Open the old file and copy over the first non-generated section to the new file'
nl|'\n'
DECL|variable|oldDataFile
name|'oldDataFile'
op|'='
name|'open'
op|'('
name|'dataFilePath'
op|','
string|'"r"'
op|')'
newline|'\n'
DECL|variable|s
name|'s'
op|'='
name|'oldDataFile'
op|'.'
name|'readline'
op|'('
op|')'
newline|'\n'
name|'while'
name|'s'
name|'and'
name|'s'
op|'!='
name|'GENERATED_BLOCK_START'
op|':'
newline|'\n'
indent|'    '
name|'newTempFile'
op|'.'
name|'write'
op|'('
name|'s'
op|')'
newline|'\n'
DECL|variable|s
name|'s'
op|'='
name|'oldDataFile'
op|'.'
name|'readline'
op|'('
op|')'
newline|'\n'
nl|'\n'
comment|'# Write out generated block start tag and warning'
nl|'\n'
dedent|''
name|'newTempFile'
op|'.'
name|'write'
op|'('
name|'GENERATED_BLOCK_START'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"\\n\\\n/*\\n\\\n    This part of the file was generated on %s from the\\n\\\n    Common Locale Data Repository supplemental/windowsZones.xml file\\n\\\n    %s %s\\n\\\n\\n\\\n    http://www.unicode.org/cldr/\\n\\\n\\n\\\n    Do not change this data, only generate it using cldr2qtimezone.py.\\n\\\n*/\\n\\n"'
op|'%'
op|'('
name|'str'
op|'('
name|'datetime'
op|'.'
name|'date'
op|'.'
name|'today'
op|'('
op|')'
op|')'
op|','
name|'versionNumber'
op|','
name|'generationDate'
op|')'
op|')'
newline|'\n'
nl|'\n'
DECL|variable|windowsIdData
name|'windowsIdData'
op|'='
name|'ByteArrayData'
op|'('
op|')'
newline|'\n'
DECL|variable|olsenIdData
name|'olsenIdData'
op|'='
name|'ByteArrayData'
op|'('
op|')'
newline|'\n'
nl|'\n'
comment|'# Write Windows/Olsen table'
nl|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"// Windows ID Key, Country Enum, Olsen ID Index\\n"'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"static const QZoneData zoneDataTable[] = {\\n"'
op|')'
newline|'\n'
name|'for'
name|'index'
name|'in'
name|'windowsIdDict'
op|':'
newline|'\n'
DECL|variable|data
indent|'    '
name|'data'
op|'='
name|'windowsIdDict'
op|'['
name|'index'
op|']'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"    { %6d,%6d,%6d }, // %s / %s\\n"'
op|'%'
op|'('
name|'data'
op|'['
string|"'windowsKey'"
op|']'
op|','
nl|'\n'
name|'data'
op|'['
string|"'countryId'"
op|']'
op|','
nl|'\n'
name|'olsenIdData'
op|'.'
name|'append'
op|'('
name|'data'
op|'['
string|"'olsenList'"
op|']'
op|')'
op|','
nl|'\n'
name|'data'
op|'['
string|"'windowsId'"
op|']'
op|','
nl|'\n'
name|'data'
op|'['
string|"'country'"
op|']'
op|')'
op|')'
newline|'\n'
dedent|''
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"    {      0,     0,     0 } // Trailing zeroes\\n"'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"};\\n\\n"'
op|')'
newline|'\n'
nl|'\n'
name|'print'
string|'"Done Zone Data"'
newline|'\n'
nl|'\n'
comment|'# Write Windows ID key table'
nl|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"// Windows ID Key, Windows ID Index, Olsen ID Index, UTC Offset\\n"'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"static const QWindowsData windowsDataTable[] = {\\n"'
op|')'
newline|'\n'
name|'for'
name|'windowsKey'
name|'in'
name|'windowsIdList'
op|':'
newline|'\n'
indent|'    '
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"    { %6d,%6d,%6d,%6d }, // %s\\n"'
op|'%'
op|'('
name|'windowsKey'
op|','
nl|'\n'
name|'windowsIdData'
op|'.'
name|'append'
op|'('
name|'windowsIdList'
op|'['
name|'windowsKey'
op|']'
op|'['
number|'0'
op|']'
op|')'
op|','
nl|'\n'
name|'olsenIdData'
op|'.'
name|'append'
op|'('
name|'defaultDict'
op|'['
name|'windowsKey'
op|']'
op|')'
op|','
nl|'\n'
name|'windowsIdList'
op|'['
name|'windowsKey'
op|']'
op|'['
number|'1'
op|']'
op|','
nl|'\n'
name|'windowsIdList'
op|'['
name|'windowsKey'
op|']'
op|'['
number|'0'
op|']'
op|')'
op|')'
newline|'\n'
dedent|''
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"    {      0,     0,     0,     0 } // Trailing zeroes\\n"'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"};\\n\\n"'
op|')'
newline|'\n'
nl|'\n'
name|'print'
string|'"Done Windows Data Table"'
newline|'\n'
nl|'\n'
comment|'# Write UTC ID key table'
nl|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"// Olsen ID Index, UTC Offset\\n"'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"static const QUtcData utcDataTable[] = {\\n"'
op|')'
newline|'\n'
name|'for'
name|'index'
name|'in'
name|'utcIdList'
op|':'
newline|'\n'
DECL|variable|data
indent|'    '
name|'data'
op|'='
name|'utcIdList'
op|'['
name|'index'
op|']'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"    { %6d,%6d }, // %s\\n"'
op|'%'
op|'('
name|'olsenIdData'
op|'.'
name|'append'
op|'('
name|'data'
op|'['
number|'0'
op|']'
op|')'
op|','
nl|'\n'
name|'data'
op|'['
number|'1'
op|']'
op|','
nl|'\n'
name|'data'
op|'['
number|'0'
op|']'
op|')'
op|')'
newline|'\n'
dedent|''
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"    {     0,      0 } // Trailing zeroes\\n"'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"};\\n\\n"'
op|')'
newline|'\n'
nl|'\n'
name|'print'
string|'"Done UTC Data Table"'
newline|'\n'
nl|'\n'
comment|"# Write out Windows ID's data"
nl|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"static const char windowsIdData[] = {\\n"'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
name|'wrap_list'
op|'('
name|'windowsIdData'
op|'.'
name|'data'
op|')'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"\\n};\\n\\n"'
op|')'
newline|'\n'
nl|'\n'
comment|"# Write out Olsen ID's data"
nl|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"static const char olsenIdData[] = {\\n"'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
name|'wrap_list'
op|'('
name|'olsenIdData'
op|'.'
name|'data'
op|')'
op|')'
newline|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
string|'"\\n};\\n"'
op|')'
newline|'\n'
nl|'\n'
name|'print'
string|'"Done ID Data Table"'
newline|'\n'
nl|'\n'
comment|'# Write out the end of generated block tag'
nl|'\n'
name|'newTempFile'
op|'.'
name|'write'
op|'('
name|'GENERATED_BLOCK_END'
op|')'
newline|'\n'
DECL|variable|s
name|'s'
op|'='
name|'oldDataFile'
op|'.'
name|'readline'
op|'('
op|')'
newline|'\n'
nl|'\n'
comment|'# Skip through the old generated data in the old file'
nl|'\n'
name|'while'
name|'s'
name|'and'
name|'s'
op|'!='
name|'GENERATED_BLOCK_END'
op|':'
newline|'\n'
DECL|variable|s
indent|'    '
name|'s'
op|'='
name|'oldDataFile'
op|'.'
name|'readline'
op|'('
op|')'
newline|'\n'
nl|'\n'
comment|'# Now copy the rest of the original file into the new file'
nl|'\n'
DECL|variable|s
dedent|''
name|'s'
op|'='
name|'oldDataFile'
op|'.'
name|'readline'
op|'('
op|')'
newline|'\n'
name|'while'
name|'s'
op|':'
newline|'\n'
indent|'    '
name|'newTempFile'
op|'.'
name|'write'
op|'('
name|'s'
op|')'
newline|'\n'
DECL|variable|s
name|'s'
op|'='
name|'oldDataFile'
op|'.'
name|'readline'
op|'('
op|')'
newline|'\n'
nl|'\n'
comment|'# Now close the old and new file, delete the old file and copy the new file in its place'
nl|'\n'
dedent|''
name|'newTempFile'
op|'.'
name|'close'
op|'('
op|')'
newline|'\n'
name|'oldDataFile'
op|'.'
name|'close'
op|'('
op|')'
newline|'\n'
name|'os'
op|'.'
name|'remove'
op|'('
name|'dataFilePath'
op|')'
newline|'\n'
name|'os'
op|'.'
name|'rename'
op|'('
name|'newTempFilePath'
op|','
name|'dataFilePath'
op|')'
newline|'\n'
nl|'\n'
name|'print'
string|'"Data generation completed, please check the new file at "'
op|'+'
name|'dataFilePath'
newline|'\n'
endmarker|''
end_unit