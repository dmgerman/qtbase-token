begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* This file contains character tables that are used when no external tables are passed to PCRE by the application that calls it. The tables are used only for characters whose code values are less than 256.  This is a default version of the tables that assumes ASCII encoding. A program called dftables (which is distributed with PCRE) can be used to build alternative versions of this file. This is necessary if you are running in an EBCDIC environment, or if you want to default to a different encoding, for example ISO-8859-1. When dftables is run, it creates these tables in the current locale. If PCRE is configured with --enable-rebuild-chartables, this happens automatically.  The following #includes are present because without them gcc 4.x may remove the array definition from the final binary if PCRE is built into a static library and dead code stripping is activated. This leads to link errors. Pulling in the header ensures that the array gets flagged as "someone outside this compilation unit might reference this" and so it will always be supplied to the linker. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|PCRE_HAVE_CONFIG_H
end_ifdef
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"pcre_internal.h"
end_include
begin_decl_stmt
specifier|const
name|pcre_uint8
name|PRIV
argument_list|(
name|default_tables
argument_list|)
decl|[]
init|=
block|{
comment|/* This table is a lower casing table. */
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|16
block|,
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|34
block|,
literal|35
block|,
literal|36
block|,
literal|37
block|,
literal|38
block|,
literal|39
block|,
literal|40
block|,
literal|41
block|,
literal|42
block|,
literal|43
block|,
literal|44
block|,
literal|45
block|,
literal|46
block|,
literal|47
block|,
literal|48
block|,
literal|49
block|,
literal|50
block|,
literal|51
block|,
literal|52
block|,
literal|53
block|,
literal|54
block|,
literal|55
block|,
literal|56
block|,
literal|57
block|,
literal|58
block|,
literal|59
block|,
literal|60
block|,
literal|61
block|,
literal|62
block|,
literal|63
block|,
literal|64
block|,
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|101
block|,
literal|102
block|,
literal|103
block|,
literal|104
block|,
literal|105
block|,
literal|106
block|,
literal|107
block|,
literal|108
block|,
literal|109
block|,
literal|110
block|,
literal|111
block|,
literal|112
block|,
literal|113
block|,
literal|114
block|,
literal|115
block|,
literal|116
block|,
literal|117
block|,
literal|118
block|,
literal|119
block|,
literal|120
block|,
literal|121
block|,
literal|122
block|,
literal|91
block|,
literal|92
block|,
literal|93
block|,
literal|94
block|,
literal|95
block|,
literal|96
block|,
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|101
block|,
literal|102
block|,
literal|103
block|,
literal|104
block|,
literal|105
block|,
literal|106
block|,
literal|107
block|,
literal|108
block|,
literal|109
block|,
literal|110
block|,
literal|111
block|,
literal|112
block|,
literal|113
block|,
literal|114
block|,
literal|115
block|,
literal|116
block|,
literal|117
block|,
literal|118
block|,
literal|119
block|,
literal|120
block|,
literal|121
block|,
literal|122
block|,
literal|123
block|,
literal|124
block|,
literal|125
block|,
literal|126
block|,
literal|127
block|,
literal|128
block|,
literal|129
block|,
literal|130
block|,
literal|131
block|,
literal|132
block|,
literal|133
block|,
literal|134
block|,
literal|135
block|,
literal|136
block|,
literal|137
block|,
literal|138
block|,
literal|139
block|,
literal|140
block|,
literal|141
block|,
literal|142
block|,
literal|143
block|,
literal|144
block|,
literal|145
block|,
literal|146
block|,
literal|147
block|,
literal|148
block|,
literal|149
block|,
literal|150
block|,
literal|151
block|,
literal|152
block|,
literal|153
block|,
literal|154
block|,
literal|155
block|,
literal|156
block|,
literal|157
block|,
literal|158
block|,
literal|159
block|,
literal|160
block|,
literal|161
block|,
literal|162
block|,
literal|163
block|,
literal|164
block|,
literal|165
block|,
literal|166
block|,
literal|167
block|,
literal|168
block|,
literal|169
block|,
literal|170
block|,
literal|171
block|,
literal|172
block|,
literal|173
block|,
literal|174
block|,
literal|175
block|,
literal|176
block|,
literal|177
block|,
literal|178
block|,
literal|179
block|,
literal|180
block|,
literal|181
block|,
literal|182
block|,
literal|183
block|,
literal|184
block|,
literal|185
block|,
literal|186
block|,
literal|187
block|,
literal|188
block|,
literal|189
block|,
literal|190
block|,
literal|191
block|,
literal|192
block|,
literal|193
block|,
literal|194
block|,
literal|195
block|,
literal|196
block|,
literal|197
block|,
literal|198
block|,
literal|199
block|,
literal|200
block|,
literal|201
block|,
literal|202
block|,
literal|203
block|,
literal|204
block|,
literal|205
block|,
literal|206
block|,
literal|207
block|,
literal|208
block|,
literal|209
block|,
literal|210
block|,
literal|211
block|,
literal|212
block|,
literal|213
block|,
literal|214
block|,
literal|215
block|,
literal|216
block|,
literal|217
block|,
literal|218
block|,
literal|219
block|,
literal|220
block|,
literal|221
block|,
literal|222
block|,
literal|223
block|,
literal|224
block|,
literal|225
block|,
literal|226
block|,
literal|227
block|,
literal|228
block|,
literal|229
block|,
literal|230
block|,
literal|231
block|,
literal|232
block|,
literal|233
block|,
literal|234
block|,
literal|235
block|,
literal|236
block|,
literal|237
block|,
literal|238
block|,
literal|239
block|,
literal|240
block|,
literal|241
block|,
literal|242
block|,
literal|243
block|,
literal|244
block|,
literal|245
block|,
literal|246
block|,
literal|247
block|,
literal|248
block|,
literal|249
block|,
literal|250
block|,
literal|251
block|,
literal|252
block|,
literal|253
block|,
literal|254
block|,
literal|255
block|,
comment|/* This table is a case flipping table. */
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|16
block|,
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|34
block|,
literal|35
block|,
literal|36
block|,
literal|37
block|,
literal|38
block|,
literal|39
block|,
literal|40
block|,
literal|41
block|,
literal|42
block|,
literal|43
block|,
literal|44
block|,
literal|45
block|,
literal|46
block|,
literal|47
block|,
literal|48
block|,
literal|49
block|,
literal|50
block|,
literal|51
block|,
literal|52
block|,
literal|53
block|,
literal|54
block|,
literal|55
block|,
literal|56
block|,
literal|57
block|,
literal|58
block|,
literal|59
block|,
literal|60
block|,
literal|61
block|,
literal|62
block|,
literal|63
block|,
literal|64
block|,
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|101
block|,
literal|102
block|,
literal|103
block|,
literal|104
block|,
literal|105
block|,
literal|106
block|,
literal|107
block|,
literal|108
block|,
literal|109
block|,
literal|110
block|,
literal|111
block|,
literal|112
block|,
literal|113
block|,
literal|114
block|,
literal|115
block|,
literal|116
block|,
literal|117
block|,
literal|118
block|,
literal|119
block|,
literal|120
block|,
literal|121
block|,
literal|122
block|,
literal|91
block|,
literal|92
block|,
literal|93
block|,
literal|94
block|,
literal|95
block|,
literal|96
block|,
literal|65
block|,
literal|66
block|,
literal|67
block|,
literal|68
block|,
literal|69
block|,
literal|70
block|,
literal|71
block|,
literal|72
block|,
literal|73
block|,
literal|74
block|,
literal|75
block|,
literal|76
block|,
literal|77
block|,
literal|78
block|,
literal|79
block|,
literal|80
block|,
literal|81
block|,
literal|82
block|,
literal|83
block|,
literal|84
block|,
literal|85
block|,
literal|86
block|,
literal|87
block|,
literal|88
block|,
literal|89
block|,
literal|90
block|,
literal|123
block|,
literal|124
block|,
literal|125
block|,
literal|126
block|,
literal|127
block|,
literal|128
block|,
literal|129
block|,
literal|130
block|,
literal|131
block|,
literal|132
block|,
literal|133
block|,
literal|134
block|,
literal|135
block|,
literal|136
block|,
literal|137
block|,
literal|138
block|,
literal|139
block|,
literal|140
block|,
literal|141
block|,
literal|142
block|,
literal|143
block|,
literal|144
block|,
literal|145
block|,
literal|146
block|,
literal|147
block|,
literal|148
block|,
literal|149
block|,
literal|150
block|,
literal|151
block|,
literal|152
block|,
literal|153
block|,
literal|154
block|,
literal|155
block|,
literal|156
block|,
literal|157
block|,
literal|158
block|,
literal|159
block|,
literal|160
block|,
literal|161
block|,
literal|162
block|,
literal|163
block|,
literal|164
block|,
literal|165
block|,
literal|166
block|,
literal|167
block|,
literal|168
block|,
literal|169
block|,
literal|170
block|,
literal|171
block|,
literal|172
block|,
literal|173
block|,
literal|174
block|,
literal|175
block|,
literal|176
block|,
literal|177
block|,
literal|178
block|,
literal|179
block|,
literal|180
block|,
literal|181
block|,
literal|182
block|,
literal|183
block|,
literal|184
block|,
literal|185
block|,
literal|186
block|,
literal|187
block|,
literal|188
block|,
literal|189
block|,
literal|190
block|,
literal|191
block|,
literal|192
block|,
literal|193
block|,
literal|194
block|,
literal|195
block|,
literal|196
block|,
literal|197
block|,
literal|198
block|,
literal|199
block|,
literal|200
block|,
literal|201
block|,
literal|202
block|,
literal|203
block|,
literal|204
block|,
literal|205
block|,
literal|206
block|,
literal|207
block|,
literal|208
block|,
literal|209
block|,
literal|210
block|,
literal|211
block|,
literal|212
block|,
literal|213
block|,
literal|214
block|,
literal|215
block|,
literal|216
block|,
literal|217
block|,
literal|218
block|,
literal|219
block|,
literal|220
block|,
literal|221
block|,
literal|222
block|,
literal|223
block|,
literal|224
block|,
literal|225
block|,
literal|226
block|,
literal|227
block|,
literal|228
block|,
literal|229
block|,
literal|230
block|,
literal|231
block|,
literal|232
block|,
literal|233
block|,
literal|234
block|,
literal|235
block|,
literal|236
block|,
literal|237
block|,
literal|238
block|,
literal|239
block|,
literal|240
block|,
literal|241
block|,
literal|242
block|,
literal|243
block|,
literal|244
block|,
literal|245
block|,
literal|246
block|,
literal|247
block|,
literal|248
block|,
literal|249
block|,
literal|250
block|,
literal|251
block|,
literal|252
block|,
literal|253
block|,
literal|254
block|,
literal|255
block|,
comment|/* This table contains bit maps for various character classes. Each map is 32 bytes long and the bits run from the least significant end of each byte. The classes that have their own maps are: space, xdigit, digit, upper, lower, word, graph, print, punct, and cntrl. Other classes are built from combinations. */
literal|0x00
block|,
literal|0x3e
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
literal|0x03
block|,
literal|0x7e
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x7e
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
literal|0x03
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x07
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x07
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
literal|0x03
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x87
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x07
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x7f
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x7f
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xfe
block|,
literal|0xff
block|,
literal|0x00
block|,
literal|0xfc
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xf8
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x78
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x80
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* This table identifies various classes of character by individual bits:   0x01   white space character   0x02   letter   0x04   decimal digit   0x08   hexadecimal digit   0x10   alphanumeric or '_'   0x80   regular expression metacharacter or binary zero */
literal|0x80
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/*   0-  7 */
literal|0x00
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/*   8- 15 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/*  16- 23 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/*  24- 31 */
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x80
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/*    - '  */
literal|0x80
block|,
literal|0x80
block|,
literal|0x80
block|,
literal|0x80
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x80
block|,
literal|0x00
block|,
comment|/*  ( - /  */
literal|0x1c
block|,
literal|0x1c
block|,
literal|0x1c
block|,
literal|0x1c
block|,
literal|0x1c
block|,
literal|0x1c
block|,
literal|0x1c
block|,
literal|0x1c
block|,
comment|/*  0 - 7  */
literal|0x1c
block|,
literal|0x1c
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x80
block|,
comment|/*  8 - ?  */
literal|0x00
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x12
block|,
comment|/*  @ - G  */
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
comment|/*  H - O  */
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
comment|/*  P - W  */
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x80
block|,
literal|0x80
block|,
literal|0x00
block|,
literal|0x80
block|,
literal|0x10
block|,
comment|/*  X - _  */
literal|0x00
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x1a
block|,
literal|0x12
block|,
comment|/*  ` - g  */
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
comment|/*  h - o  */
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
comment|/*  p - w  */
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x80
block|,
literal|0x80
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/*  x -127 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 128-135 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 136-143 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 144-151 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 152-159 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 160-167 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 168-175 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 176-183 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 184-191 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 192-199 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 200-207 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 208-215 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 216-223 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 224-231 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 232-239 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 240-247 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* 248-255 */
end_comment
begin_comment
comment|/* End of pcre_chartables.c */
end_comment
end_unit
