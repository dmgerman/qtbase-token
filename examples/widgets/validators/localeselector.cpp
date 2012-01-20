begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"localeselector.h"
end_include
begin_include
include|#
directive|include
file|<QLocale>
end_include
begin_struct
DECL|struct|SupportedLocale
struct|struct
name|SupportedLocale
block|{
DECL|member|lang
DECL|member|country
name|int
name|lang
decl_stmt|,
name|country
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|SUPPORTED_LOCALES
specifier|const
name|SupportedLocale
name|SUPPORTED_LOCALES
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|0
block|}
block|,
comment|// C/AnyCountry
block|{
literal|3
block|,
literal|69
block|}
block|,
comment|// Afan/Ethiopia
block|{
literal|3
block|,
literal|111
block|}
block|,
comment|// Afan/Kenya
block|{
literal|4
block|,
literal|59
block|}
block|,
comment|// Afar/Djibouti
block|{
literal|4
block|,
literal|67
block|}
block|,
comment|// Afar/Eritrea
block|{
literal|4
block|,
literal|69
block|}
block|,
comment|// Afar/Ethiopia
block|{
literal|5
block|,
literal|195
block|}
block|,
comment|// Afrikaans/SouthAfrica
block|{
literal|5
block|,
literal|148
block|}
block|,
comment|// Afrikaans/Namibia
block|{
literal|6
block|,
literal|2
block|}
block|,
comment|// Albanian/Albania
block|{
literal|7
block|,
literal|69
block|}
block|,
comment|// Amharic/Ethiopia
block|{
literal|8
block|,
literal|186
block|}
block|,
comment|// Arabic/SaudiArabia
block|{
literal|8
block|,
literal|3
block|}
block|,
comment|// Arabic/Algeria
block|{
literal|8
block|,
literal|17
block|}
block|,
comment|// Arabic/Bahrain
block|{
literal|8
block|,
literal|64
block|}
block|,
comment|// Arabic/Egypt
block|{
literal|8
block|,
literal|103
block|}
block|,
comment|// Arabic/Iraq
block|{
literal|8
block|,
literal|109
block|}
block|,
comment|// Arabic/Jordan
block|{
literal|8
block|,
literal|115
block|}
block|,
comment|// Arabic/Kuwait
block|{
literal|8
block|,
literal|119
block|}
block|,
comment|// Arabic/Lebanon
block|{
literal|8
block|,
literal|122
block|}
block|,
comment|// Arabic/LibyanArabJamahiriya
block|{
literal|8
block|,
literal|145
block|}
block|,
comment|// Arabic/Morocco
block|{
literal|8
block|,
literal|162
block|}
block|,
comment|// Arabic/Oman
block|{
literal|8
block|,
literal|175
block|}
block|,
comment|// Arabic/Qatar
block|{
literal|8
block|,
literal|201
block|}
block|,
comment|// Arabic/Sudan
block|{
literal|8
block|,
literal|207
block|}
block|,
comment|// Arabic/SyrianArabRepublic
block|{
literal|8
block|,
literal|216
block|}
block|,
comment|// Arabic/Tunisia
block|{
literal|8
block|,
literal|223
block|}
block|,
comment|// Arabic/UnitedArabEmirates
block|{
literal|8
block|,
literal|237
block|}
block|,
comment|// Arabic/Yemen
block|{
literal|9
block|,
literal|11
block|}
block|,
comment|// Armenian/Armenia
block|{
literal|10
block|,
literal|100
block|}
block|,
comment|// Assamese/India
block|{
literal|12
block|,
literal|15
block|}
block|,
comment|// Azerbaijani/Azerbaijan
block|{
literal|14
block|,
literal|197
block|}
block|,
comment|// Basque/Spain
block|{
literal|15
block|,
literal|18
block|}
block|,
comment|// Bengali/Bangladesh
block|{
literal|15
block|,
literal|100
block|}
block|,
comment|// Bengali/India
block|{
literal|16
block|,
literal|25
block|}
block|,
comment|// Bhutani/Bhutan
block|{
literal|20
block|,
literal|33
block|}
block|,
comment|// Bulgarian/Bulgaria
block|{
literal|22
block|,
literal|20
block|}
block|,
comment|// Byelorussian/Belarus
block|{
literal|23
block|,
literal|36
block|}
block|,
comment|// Cambodian/Cambodia
block|{
literal|24
block|,
literal|197
block|}
block|,
comment|// Catalan/Spain
block|{
literal|25
block|,
literal|44
block|}
block|,
comment|// Chinese/China
block|{
literal|25
block|,
literal|97
block|}
block|,
comment|// Chinese/HongKong
block|{
literal|25
block|,
literal|126
block|}
block|,
comment|// Chinese/Macau
block|{
literal|25
block|,
literal|190
block|}
block|,
comment|// Chinese/Singapore
block|{
literal|25
block|,
literal|208
block|}
block|,
comment|// Chinese/Taiwan
block|{
literal|27
block|,
literal|54
block|}
block|,
comment|// Croatian/Croatia
block|{
literal|28
block|,
literal|57
block|}
block|,
comment|// Czech/CzechRepublic
block|{
literal|29
block|,
literal|58
block|}
block|,
comment|// Danish/Denmark
block|{
literal|30
block|,
literal|151
block|}
block|,
comment|// Dutch/Netherlands
block|{
literal|30
block|,
literal|21
block|}
block|,
comment|// Dutch/Belgium
block|{
literal|31
block|,
literal|225
block|}
block|,
comment|// English/UnitedStates
block|{
literal|31
block|,
literal|4
block|}
block|,
comment|// English/AmericanSamoa
block|{
literal|31
block|,
literal|13
block|}
block|,
comment|// English/Australia
block|{
literal|31
block|,
literal|21
block|}
block|,
comment|// English/Belgium
block|{
literal|31
block|,
literal|22
block|}
block|,
comment|// English/Belize
block|{
literal|31
block|,
literal|28
block|}
block|,
comment|// English/Botswana
block|{
literal|31
block|,
literal|38
block|}
block|,
comment|// English/Canada
block|{
literal|31
block|,
literal|89
block|}
block|,
comment|// English/Guam
block|{
literal|31
block|,
literal|97
block|}
block|,
comment|// English/HongKong
block|{
literal|31
block|,
literal|100
block|}
block|,
comment|// English/India
block|{
literal|31
block|,
literal|104
block|}
block|,
comment|// English/Ireland
block|{
literal|31
block|,
literal|107
block|}
block|,
comment|// English/Jamaica
block|{
literal|31
block|,
literal|133
block|}
block|,
comment|// English/Malta
block|{
literal|31
block|,
literal|134
block|}
block|,
comment|// English/MarshallIslands
block|{
literal|31
block|,
literal|148
block|}
block|,
comment|// English/Namibia
block|{
literal|31
block|,
literal|154
block|}
block|,
comment|// English/NewZealand
block|{
literal|31
block|,
literal|160
block|}
block|,
comment|// English/NorthernMarianaIslands
block|{
literal|31
block|,
literal|163
block|}
block|,
comment|// English/Pakistan
block|{
literal|31
block|,
literal|170
block|}
block|,
comment|// English/Philippines
block|{
literal|31
block|,
literal|190
block|}
block|,
comment|// English/Singapore
block|{
literal|31
block|,
literal|195
block|}
block|,
comment|// English/SouthAfrica
block|{
literal|31
block|,
literal|215
block|}
block|,
comment|// English/TrinidadAndTobago
block|{
literal|31
block|,
literal|224
block|}
block|,
comment|// English/UnitedKingdom
block|{
literal|31
block|,
literal|226
block|}
block|,
comment|// English/UnitedStatesMinorOutlyingIslands
block|{
literal|31
block|,
literal|234
block|}
block|,
comment|// English/USVirginIslands
block|{
literal|31
block|,
literal|240
block|}
block|,
comment|// English/Zimbabwe
block|{
literal|33
block|,
literal|68
block|}
block|,
comment|// Estonian/Estonia
block|{
literal|34
block|,
literal|71
block|}
block|,
comment|// Faroese/FaroeIslands
block|{
literal|36
block|,
literal|73
block|}
block|,
comment|// Finnish/Finland
block|{
literal|37
block|,
literal|74
block|}
block|,
comment|// French/France
block|{
literal|37
block|,
literal|21
block|}
block|,
comment|// French/Belgium
block|{
literal|37
block|,
literal|38
block|}
block|,
comment|// French/Canada
block|{
literal|37
block|,
literal|125
block|}
block|,
comment|// French/Luxembourg
block|{
literal|37
block|,
literal|142
block|}
block|,
comment|// French/Monaco
block|{
literal|37
block|,
literal|206
block|}
block|,
comment|// French/Switzerland
block|{
literal|40
block|,
literal|197
block|}
block|,
comment|// Galician/Spain
block|{
literal|41
block|,
literal|81
block|}
block|,
comment|// Georgian/Georgia
block|{
literal|42
block|,
literal|82
block|}
block|,
comment|// German/Germany
block|{
literal|42
block|,
literal|14
block|}
block|,
comment|// German/Austria
block|{
literal|42
block|,
literal|21
block|}
block|,
comment|// German/Belgium
block|{
literal|42
block|,
literal|123
block|}
block|,
comment|// German/Liechtenstein
block|{
literal|42
block|,
literal|125
block|}
block|,
comment|// German/Luxembourg
block|{
literal|42
block|,
literal|206
block|}
block|,
comment|// German/Switzerland
block|{
literal|43
block|,
literal|85
block|}
block|,
comment|// Greek/Greece
block|{
literal|43
block|,
literal|56
block|}
block|,
comment|// Greek/Cyprus
block|{
literal|44
block|,
literal|86
block|}
block|,
comment|// Greenlandic/Greenland
block|{
literal|46
block|,
literal|100
block|}
block|,
comment|// Gujarati/India
block|{
literal|47
block|,
literal|83
block|}
block|,
comment|// Hausa/Ghana
block|{
literal|47
block|,
literal|156
block|}
block|,
comment|// Hausa/Niger
block|{
literal|47
block|,
literal|157
block|}
block|,
comment|// Hausa/Nigeria
block|{
literal|48
block|,
literal|105
block|}
block|,
comment|// Hebrew/Israel
block|{
literal|49
block|,
literal|100
block|}
block|,
comment|// Hindi/India
block|{
literal|50
block|,
literal|98
block|}
block|,
comment|// Hungarian/Hungary
block|{
literal|51
block|,
literal|99
block|}
block|,
comment|// Icelandic/Iceland
block|{
literal|52
block|,
literal|101
block|}
block|,
comment|// Indonesian/Indonesia
block|{
literal|57
block|,
literal|104
block|}
block|,
comment|// Irish/Ireland
block|{
literal|58
block|,
literal|106
block|}
block|,
comment|// Italian/Italy
block|{
literal|58
block|,
literal|206
block|}
block|,
comment|// Italian/Switzerland
block|{
literal|59
block|,
literal|108
block|}
block|,
comment|// Japanese/Japan
block|{
literal|61
block|,
literal|100
block|}
block|,
comment|// Kannada/India
block|{
literal|63
block|,
literal|110
block|}
block|,
comment|// Kazakh/Kazakhstan
block|{
literal|64
block|,
literal|179
block|}
block|,
comment|// Kinyarwanda/Rwanda
block|{
literal|65
block|,
literal|116
block|}
block|,
comment|// Kirghiz/Kyrgyzstan
block|{
literal|66
block|,
literal|114
block|}
block|,
comment|// Korean/RepublicOfKorea
block|{
literal|67
block|,
literal|102
block|}
block|,
comment|// Kurdish/Iran
block|{
literal|67
block|,
literal|103
block|}
block|,
comment|// Kurdish/Iraq
block|{
literal|67
block|,
literal|207
block|}
block|,
comment|// Kurdish/SyrianArabRepublic
block|{
literal|67
block|,
literal|217
block|}
block|,
comment|// Kurdish/Turkey
block|{
literal|69
block|,
literal|117
block|}
block|,
comment|// Laothian/Lao
block|{
literal|71
block|,
literal|118
block|}
block|,
comment|// Latvian/Latvia
block|{
literal|72
block|,
literal|49
block|}
block|,
comment|// Lingala/DemocraticRepublicOfCongo
block|{
literal|72
block|,
literal|50
block|}
block|,
comment|// Lingala/PeoplesRepublicOfCongo
block|{
literal|73
block|,
literal|124
block|}
block|,
comment|// Lithuanian/Lithuania
block|{
literal|74
block|,
literal|127
block|}
block|,
comment|// Macedonian/Macedonia
block|{
literal|76
block|,
literal|130
block|}
block|,
comment|// Malay/Malaysia
block|{
literal|76
block|,
literal|32
block|}
block|,
comment|// Malay/BruneiDarussalam
block|{
literal|77
block|,
literal|100
block|}
block|,
comment|// Malayalam/India
block|{
literal|78
block|,
literal|133
block|}
block|,
comment|// Maltese/Malta
block|{
literal|80
block|,
literal|100
block|}
block|,
comment|// Marathi/India
block|{
literal|82
block|,
literal|143
block|}
block|,
comment|// Mongolian/Mongolia
block|{
literal|84
block|,
literal|150
block|}
block|,
comment|// Nepali/Nepal
block|{
literal|85
block|,
literal|161
block|}
block|,
comment|// Norwegian/Norway
block|{
literal|87
block|,
literal|100
block|}
block|,
comment|// Oriya/India
block|{
literal|88
block|,
literal|1
block|}
block|,
comment|// Pashto/Afghanistan
block|{
literal|89
block|,
literal|102
block|}
block|,
comment|// Persian/Iran
block|{
literal|89
block|,
literal|1
block|}
block|,
comment|// Persian/Afghanistan
block|{
literal|90
block|,
literal|172
block|}
block|,
comment|// Polish/Poland
block|{
literal|91
block|,
literal|173
block|}
block|,
comment|// Portuguese/Portugal
block|{
literal|91
block|,
literal|30
block|}
block|,
comment|// Portuguese/Brazil
block|{
literal|92
block|,
literal|100
block|}
block|,
comment|// Punjabi/India
block|{
literal|92
block|,
literal|163
block|}
block|,
comment|// Punjabi/Pakistan
block|{
literal|95
block|,
literal|177
block|}
block|,
comment|// Romanian/Romania
block|{
literal|96
block|,
literal|178
block|}
block|,
comment|// Russian/RussianFederation
block|{
literal|96
block|,
literal|222
block|}
block|,
comment|// Russian/Ukraine
block|{
literal|99
block|,
literal|100
block|}
block|,
comment|// Sanskrit/India
block|{
literal|100
block|,
literal|241
block|}
block|,
comment|// Serbian/SerbiaAndMontenegro
block|{
literal|100
block|,
literal|27
block|}
block|,
comment|// Serbian/BosniaAndHerzegowina
block|{
literal|100
block|,
literal|238
block|}
block|,
comment|// Serbian/Yugoslavia
block|{
literal|101
block|,
literal|241
block|}
block|,
comment|// SerboCroatian/SerbiaAndMontenegro
block|{
literal|101
block|,
literal|27
block|}
block|,
comment|// SerboCroatian/BosniaAndHerzegowina
block|{
literal|101
block|,
literal|238
block|}
block|,
comment|// SerboCroatian/Yugoslavia
block|{
literal|102
block|,
literal|195
block|}
block|,
comment|// Sesotho/SouthAfrica
block|{
literal|103
block|,
literal|195
block|}
block|,
comment|// Setswana/SouthAfrica
block|{
literal|107
block|,
literal|195
block|}
block|,
comment|// Siswati/SouthAfrica
block|{
literal|108
block|,
literal|191
block|}
block|,
comment|// Slovak/Slovakia
block|{
literal|109
block|,
literal|192
block|}
block|,
comment|// Slovenian/Slovenia
block|{
literal|110
block|,
literal|194
block|}
block|,
comment|// Somali/Somalia
block|{
literal|110
block|,
literal|59
block|}
block|,
comment|// Somali/Djibouti
block|{
literal|110
block|,
literal|69
block|}
block|,
comment|// Somali/Ethiopia
block|{
literal|110
block|,
literal|111
block|}
block|,
comment|// Somali/Kenya
block|{
literal|111
block|,
literal|197
block|}
block|,
comment|// Spanish/Spain
block|{
literal|111
block|,
literal|10
block|}
block|,
comment|// Spanish/Argentina
block|{
literal|111
block|,
literal|26
block|}
block|,
comment|// Spanish/Bolivia
block|{
literal|111
block|,
literal|43
block|}
block|,
comment|// Spanish/Chile
block|{
literal|111
block|,
literal|47
block|}
block|,
comment|// Spanish/Colombia
block|{
literal|111
block|,
literal|52
block|}
block|,
comment|// Spanish/CostaRica
block|{
literal|111
block|,
literal|61
block|}
block|,
comment|// Spanish/DominicanRepublic
block|{
literal|111
block|,
literal|63
block|}
block|,
comment|// Spanish/Ecuador
block|{
literal|111
block|,
literal|65
block|}
block|,
comment|// Spanish/ElSalvador
block|{
literal|111
block|,
literal|90
block|}
block|,
comment|// Spanish/Guatemala
block|{
literal|111
block|,
literal|96
block|}
block|,
comment|// Spanish/Honduras
block|{
literal|111
block|,
literal|139
block|}
block|,
comment|// Spanish/Mexico
block|{
literal|111
block|,
literal|155
block|}
block|,
comment|// Spanish/Nicaragua
block|{
literal|111
block|,
literal|166
block|}
block|,
comment|// Spanish/Panama
block|{
literal|111
block|,
literal|168
block|}
block|,
comment|// Spanish/Paraguay
block|{
literal|111
block|,
literal|169
block|}
block|,
comment|// Spanish/Peru
block|{
literal|111
block|,
literal|174
block|}
block|,
comment|// Spanish/PuertoRico
block|{
literal|111
block|,
literal|225
block|}
block|,
comment|// Spanish/UnitedStates
block|{
literal|111
block|,
literal|227
block|}
block|,
comment|// Spanish/Uruguay
block|{
literal|111
block|,
literal|231
block|}
block|,
comment|// Spanish/Venezuela
block|{
literal|113
block|,
literal|111
block|}
block|,
comment|// Swahili/Kenya
block|{
literal|113
block|,
literal|210
block|}
block|,
comment|// Swahili/Tanzania
block|{
literal|114
block|,
literal|205
block|}
block|,
comment|// Swedish/Sweden
block|{
literal|114
block|,
literal|73
block|}
block|,
comment|// Swedish/Finland
block|{
literal|116
block|,
literal|209
block|}
block|,
comment|// Tajik/Tajikistan
block|{
literal|117
block|,
literal|100
block|}
block|,
comment|// Tamil/India
block|{
literal|118
block|,
literal|178
block|}
block|,
comment|// Tatar/RussianFederation
block|{
literal|119
block|,
literal|100
block|}
block|,
comment|// Telugu/India
block|{
literal|120
block|,
literal|211
block|}
block|,
comment|// Thai/Thailand
block|{
literal|122
block|,
literal|67
block|}
block|,
comment|// Tigrinya/Eritrea
block|{
literal|122
block|,
literal|69
block|}
block|,
comment|// Tigrinya/Ethiopia
block|{
literal|124
block|,
literal|195
block|}
block|,
comment|// Tsonga/SouthAfrica
block|{
literal|125
block|,
literal|217
block|}
block|,
comment|// Turkish/Turkey
block|{
literal|129
block|,
literal|222
block|}
block|,
comment|// Ukrainian/Ukraine
block|{
literal|130
block|,
literal|100
block|}
block|,
comment|// Urdu/India
block|{
literal|130
block|,
literal|163
block|}
block|,
comment|// Urdu/Pakistan
block|{
literal|131
block|,
literal|228
block|}
block|,
comment|// Uzbek/Uzbekistan
block|{
literal|131
block|,
literal|1
block|}
block|,
comment|// Uzbek/Afghanistan
block|{
literal|132
block|,
literal|232
block|}
block|,
comment|// Vietnamese/VietNam
block|{
literal|134
block|,
literal|224
block|}
block|,
comment|// Welsh/UnitedKingdom
block|{
literal|136
block|,
literal|195
block|}
block|,
comment|// Xhosa/SouthAfrica
block|{
literal|138
block|,
literal|157
block|}
block|,
comment|// Yoruba/Nigeria
block|{
literal|140
block|,
literal|195
block|}
block|,
comment|// Zulu/SouthAfrica
block|{
literal|141
block|,
literal|161
block|}
block|,
comment|// Nynorsk/Norway
block|{
literal|142
block|,
literal|27
block|}
block|,
comment|// Bosnian/BosniaAndHerzegowina
block|{
literal|143
block|,
literal|131
block|}
block|,
comment|// Divehi/Maldives
block|{
literal|144
block|,
literal|224
block|}
block|,
comment|// Manx/UnitedKingdom
block|{
literal|145
block|,
literal|224
block|}
block|,
comment|// Cornish/UnitedKingdom
block|{
literal|146
block|,
literal|83
block|}
block|,
comment|// Akan/Ghana
block|{
literal|147
block|,
literal|100
block|}
block|,
comment|// Konkani/India
block|{
literal|148
block|,
literal|83
block|}
block|,
comment|// Ga/Ghana
block|{
literal|149
block|,
literal|157
block|}
block|,
comment|// Igbo/Nigeria
block|{
literal|150
block|,
literal|111
block|}
block|,
comment|// Kamba/Kenya
block|{
literal|151
block|,
literal|207
block|}
block|,
comment|// Syriac/SyrianArabRepublic
block|{
literal|152
block|,
literal|67
block|}
block|,
comment|// Blin/Eritrea
block|{
literal|153
block|,
literal|67
block|}
block|,
comment|// Geez/Eritrea
block|{
literal|153
block|,
literal|69
block|}
block|,
comment|// Geez/Ethiopia
block|{
literal|154
block|,
literal|157
block|}
block|,
comment|// Koro/Nigeria
block|{
literal|155
block|,
literal|69
block|}
block|,
comment|// Sidamo/Ethiopia
block|{
literal|156
block|,
literal|157
block|}
block|,
comment|// Atsam/Nigeria
block|{
literal|157
block|,
literal|67
block|}
block|,
comment|// Tigre/Eritrea
block|{
literal|158
block|,
literal|157
block|}
block|,
comment|// Jju/Nigeria
block|{
literal|159
block|,
literal|106
block|}
block|,
comment|// Friulian/Italy
block|{
literal|160
block|,
literal|195
block|}
block|,
comment|// Venda/SouthAfrica
block|{
literal|161
block|,
literal|83
block|}
block|,
comment|// Ewe/Ghana
block|{
literal|161
block|,
literal|212
block|}
block|,
comment|// Ewe/Togo
block|{
literal|163
block|,
literal|225
block|}
block|,
comment|// Hawaiian/UnitedStates
block|{
literal|164
block|,
literal|157
block|}
block|,
comment|// Tyap/Nigeria
block|{
literal|165
block|,
literal|129
block|}
comment|// Chewa/Malawi
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|SUPPORTED_LOCALES_COUNT
specifier|const
name|int
name|SUPPORTED_LOCALES_COUNT
init|=
sizeof|sizeof
argument_list|(
name|SUPPORTED_LOCALES
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|SupportedLocale
argument_list|)
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|IntPair
typedef|typedef
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|IntPair
typedef|;
end_typedef
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|SupportedLocale
argument_list|)
end_macro
begin_constructor
DECL|function|LocaleSelector
name|LocaleSelector
operator|::
name|LocaleSelector
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QComboBox
argument_list|(
name|parent
argument_list|)
block|{
name|int
name|curIndex
init|=
operator|-
literal|1
decl_stmt|;
name|QLocale
name|curLocale
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|SUPPORTED_LOCALES_COUNT
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|SupportedLocale
modifier|&
name|l
init|=
name|SUPPORTED_LOCALES
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|l
operator|.
name|lang
operator|==
name|curLocale
operator|.
name|language
argument_list|()
operator|&&
name|l
operator|.
name|country
operator|==
name|curLocale
operator|.
name|country
argument_list|()
condition|)
name|curIndex
operator|=
name|i
expr_stmt|;
name|QString
name|text
init|=
name|QLocale
operator|::
name|languageToString
argument_list|(
name|QLocale
operator|::
name|Language
argument_list|(
name|l
operator|.
name|lang
argument_list|)
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|QLocale
operator|::
name|countryToString
argument_list|(
name|QLocale
operator|::
name|Country
argument_list|(
name|l
operator|.
name|country
argument_list|)
argument_list|)
decl_stmt|;
name|addItem
argument_list|(
name|text
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|l
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|setCurrentIndex
argument_list|(
name|curIndex
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|emitLocaleSelected
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|emitLocaleSelected
name|void
name|LocaleSelector
operator|::
name|emitLocaleSelected
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|QVariant
name|v
init|=
name|itemData
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|v
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|SupportedLocale
name|l
init|=
name|qvariant_cast
argument_list|<
name|SupportedLocale
argument_list|>
argument_list|(
name|v
argument_list|)
decl_stmt|;
emit|emit
name|localeSelected
argument_list|(
name|QLocale
argument_list|(
name|QLocale
operator|::
name|Language
argument_list|(
name|l
operator|.
name|lang
argument_list|)
argument_list|,
name|QLocale
operator|::
name|Country
argument_list|(
name|l
operator|.
name|country
argument_list|)
argument_list|)
argument_list|)
emit|;
block|}
end_function
end_unit
