begin_unit
begin_comment
comment|/* The table and comments below along with the function xkb_keysym_to_ucs4  * are under the public domain and are derived as described below.  */
end_comment
begin_comment
comment|/* This module converts keysym values into the corresponding ISO 10646  * (UCS, Unicode) values.  *  * The array keysymtab[] contains pairs of X11 keysym values for graphical  * characters and the corresponding Unicode value. The function  * keysym2ucs() maps a keysym onto a Unicode value using a binary search,  * therefore keysymtab[] must remain SORTED by keysym value.  *  * The keysym -> UTF-8 conversion will hopefully one day be provided  * by Xlib via XmbLookupString() and should ideally not have to be  * done in X applications. But we are not there yet.  *  * We allow to represent any UCS character in the range U-00000000 to  * U-00FFFFFF by a keysym value in the range 0x01000000 to 0x01ffffff.  * This admittedly does not cover the entire 31-bit space of UCS, but  * it does cover all of the characters up to U-10FFFF, which can be  * represented by UTF-16, and more, and it is very unlikely that higher  * UCS codes will ever be assigned by ISO. So to get Unicode character  * U+ABCD you can directly use keysym 0x0100abcd.  *  * NOTE: The comments in the table below contain the actual character  * encoded in UTF-8, so for viewing and editing best use an editor in  * UTF-8 mode.  *  * Author: Markus G. Kuhn<http://www.cl.cam.ac.uk/~mgk25/>,  *         University of Cambridge, April 2001  *  * Special thanks to Richard Verhoeven<river@win.tue.nl> for preparing  * an initial draft of the mapping table.  *  * This software is in the public domain. Share and enjoy!  *  */
end_comment
begin_include
include|#
directive|include
file|"xkbcommon/xkbcommon.h"
end_include
begin_include
include|#
directive|include
file|"utils.h"
end_include
begin_comment
comment|/* We don't use the uint32_t types here, to save some space. */
end_comment
begin_struct
DECL|struct|codepair
struct|struct
name|codepair
block|{
DECL|member|keysym
name|uint16_t
name|keysym
decl_stmt|;
DECL|member|ucs
name|uint16_t
name|ucs
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|keysymtab
specifier|static
specifier|const
name|struct
name|codepair
name|keysymtab
index|[]
init|=
block|{
block|{
literal|0x01a1
block|,
literal|0x0104
block|}
block|,
comment|/*                     Aogonek Ä LATIN CAPITAL LETTER A WITH OGONEK */
block|{
literal|0x01a2
block|,
literal|0x02d8
block|}
block|,
comment|/*                       breve Ë BREVE */
block|{
literal|0x01a3
block|,
literal|0x0141
block|}
block|,
comment|/*                     Lstroke Å LATIN CAPITAL LETTER L WITH STROKE */
block|{
literal|0x01a5
block|,
literal|0x013d
block|}
block|,
comment|/*                      Lcaron Ä½ LATIN CAPITAL LETTER L WITH CARON */
block|{
literal|0x01a6
block|,
literal|0x015a
block|}
block|,
comment|/*                      Sacute Å LATIN CAPITAL LETTER S WITH ACUTE */
block|{
literal|0x01a9
block|,
literal|0x0160
block|}
block|,
comment|/*                      Scaron Å  LATIN CAPITAL LETTER S WITH CARON */
block|{
literal|0x01aa
block|,
literal|0x015e
block|}
block|,
comment|/*                    Scedilla Å LATIN CAPITAL LETTER S WITH CEDILLA */
block|{
literal|0x01ab
block|,
literal|0x0164
block|}
block|,
comment|/*                      Tcaron Å¤ LATIN CAPITAL LETTER T WITH CARON */
block|{
literal|0x01ac
block|,
literal|0x0179
block|}
block|,
comment|/*                      Zacute Å¹ LATIN CAPITAL LETTER Z WITH ACUTE */
block|{
literal|0x01ae
block|,
literal|0x017d
block|}
block|,
comment|/*                      Zcaron Å½ LATIN CAPITAL LETTER Z WITH CARON */
block|{
literal|0x01af
block|,
literal|0x017b
block|}
block|,
comment|/*                   Zabovedot Å» LATIN CAPITAL LETTER Z WITH DOT ABOVE */
block|{
literal|0x01b1
block|,
literal|0x0105
block|}
block|,
comment|/*                     aogonek Ä LATIN SMALL LETTER A WITH OGONEK */
block|{
literal|0x01b2
block|,
literal|0x02db
block|}
block|,
comment|/*                      ogonek Ë OGONEK */
block|{
literal|0x01b3
block|,
literal|0x0142
block|}
block|,
comment|/*                     lstroke Å LATIN SMALL LETTER L WITH STROKE */
block|{
literal|0x01b5
block|,
literal|0x013e
block|}
block|,
comment|/*                      lcaron Ä¾ LATIN SMALL LETTER L WITH CARON */
block|{
literal|0x01b6
block|,
literal|0x015b
block|}
block|,
comment|/*                      sacute Å LATIN SMALL LETTER S WITH ACUTE */
block|{
literal|0x01b7
block|,
literal|0x02c7
block|}
block|,
comment|/*                       caron Ë CARON */
block|{
literal|0x01b9
block|,
literal|0x0161
block|}
block|,
comment|/*                      scaron Å¡ LATIN SMALL LETTER S WITH CARON */
block|{
literal|0x01ba
block|,
literal|0x015f
block|}
block|,
comment|/*                    scedilla Å LATIN SMALL LETTER S WITH CEDILLA */
block|{
literal|0x01bb
block|,
literal|0x0165
block|}
block|,
comment|/*                      tcaron Å¥ LATIN SMALL LETTER T WITH CARON */
block|{
literal|0x01bc
block|,
literal|0x017a
block|}
block|,
comment|/*                      zacute Åº LATIN SMALL LETTER Z WITH ACUTE */
block|{
literal|0x01bd
block|,
literal|0x02dd
block|}
block|,
comment|/*                 doubleacute Ë DOUBLE ACUTE ACCENT */
block|{
literal|0x01be
block|,
literal|0x017e
block|}
block|,
comment|/*                      zcaron Å¾ LATIN SMALL LETTER Z WITH CARON */
block|{
literal|0x01bf
block|,
literal|0x017c
block|}
block|,
comment|/*                   zabovedot Å¼ LATIN SMALL LETTER Z WITH DOT ABOVE */
block|{
literal|0x01c0
block|,
literal|0x0154
block|}
block|,
comment|/*                      Racute Å LATIN CAPITAL LETTER R WITH ACUTE */
block|{
literal|0x01c3
block|,
literal|0x0102
block|}
block|,
comment|/*                      Abreve Ä LATIN CAPITAL LETTER A WITH BREVE */
block|{
literal|0x01c5
block|,
literal|0x0139
block|}
block|,
comment|/*                      Lacute Ä¹ LATIN CAPITAL LETTER L WITH ACUTE */
block|{
literal|0x01c6
block|,
literal|0x0106
block|}
block|,
comment|/*                      Cacute Ä LATIN CAPITAL LETTER C WITH ACUTE */
block|{
literal|0x01c8
block|,
literal|0x010c
block|}
block|,
comment|/*                      Ccaron Ä LATIN CAPITAL LETTER C WITH CARON */
block|{
literal|0x01ca
block|,
literal|0x0118
block|}
block|,
comment|/*                     Eogonek Ä LATIN CAPITAL LETTER E WITH OGONEK */
block|{
literal|0x01cc
block|,
literal|0x011a
block|}
block|,
comment|/*                      Ecaron Ä LATIN CAPITAL LETTER E WITH CARON */
block|{
literal|0x01cf
block|,
literal|0x010e
block|}
block|,
comment|/*                      Dcaron Ä LATIN CAPITAL LETTER D WITH CARON */
block|{
literal|0x01d0
block|,
literal|0x0110
block|}
block|,
comment|/*                     Dstroke Ä LATIN CAPITAL LETTER D WITH STROKE */
block|{
literal|0x01d1
block|,
literal|0x0143
block|}
block|,
comment|/*                      Nacute Å LATIN CAPITAL LETTER N WITH ACUTE */
block|{
literal|0x01d2
block|,
literal|0x0147
block|}
block|,
comment|/*                      Ncaron Å LATIN CAPITAL LETTER N WITH CARON */
block|{
literal|0x01d5
block|,
literal|0x0150
block|}
block|,
comment|/*                Odoubleacute Å LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
block|{
literal|0x01d8
block|,
literal|0x0158
block|}
block|,
comment|/*                      Rcaron Å LATIN CAPITAL LETTER R WITH CARON */
block|{
literal|0x01d9
block|,
literal|0x016e
block|}
block|,
comment|/*                       Uring Å® LATIN CAPITAL LETTER U WITH RING ABOVE */
block|{
literal|0x01db
block|,
literal|0x0170
block|}
block|,
comment|/*                Udoubleacute Å° LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
block|{
literal|0x01de
block|,
literal|0x0162
block|}
block|,
comment|/*                    Tcedilla Å¢ LATIN CAPITAL LETTER T WITH CEDILLA */
block|{
literal|0x01e0
block|,
literal|0x0155
block|}
block|,
comment|/*                      racute Å LATIN SMALL LETTER R WITH ACUTE */
block|{
literal|0x01e3
block|,
literal|0x0103
block|}
block|,
comment|/*                      abreve Ä LATIN SMALL LETTER A WITH BREVE */
block|{
literal|0x01e5
block|,
literal|0x013a
block|}
block|,
comment|/*                      lacute Äº LATIN SMALL LETTER L WITH ACUTE */
block|{
literal|0x01e6
block|,
literal|0x0107
block|}
block|,
comment|/*                      cacute Ä LATIN SMALL LETTER C WITH ACUTE */
block|{
literal|0x01e8
block|,
literal|0x010d
block|}
block|,
comment|/*                      ccaron Ä LATIN SMALL LETTER C WITH CARON */
block|{
literal|0x01ea
block|,
literal|0x0119
block|}
block|,
comment|/*                     eogonek Ä LATIN SMALL LETTER E WITH OGONEK */
block|{
literal|0x01ec
block|,
literal|0x011b
block|}
block|,
comment|/*                      ecaron Ä LATIN SMALL LETTER E WITH CARON */
block|{
literal|0x01ef
block|,
literal|0x010f
block|}
block|,
comment|/*                      dcaron Ä LATIN SMALL LETTER D WITH CARON */
block|{
literal|0x01f0
block|,
literal|0x0111
block|}
block|,
comment|/*                     dstroke Ä LATIN SMALL LETTER D WITH STROKE */
block|{
literal|0x01f1
block|,
literal|0x0144
block|}
block|,
comment|/*                      nacute Å LATIN SMALL LETTER N WITH ACUTE */
block|{
literal|0x01f2
block|,
literal|0x0148
block|}
block|,
comment|/*                      ncaron Å LATIN SMALL LETTER N WITH CARON */
block|{
literal|0x01f5
block|,
literal|0x0151
block|}
block|,
comment|/*                odoubleacute Å LATIN SMALL LETTER O WITH DOUBLE ACUTE */
block|{
literal|0x01f8
block|,
literal|0x0159
block|}
block|,
comment|/*                      rcaron Å LATIN SMALL LETTER R WITH CARON */
block|{
literal|0x01f9
block|,
literal|0x016f
block|}
block|,
comment|/*                       uring Å¯ LATIN SMALL LETTER U WITH RING ABOVE */
block|{
literal|0x01fb
block|,
literal|0x0171
block|}
block|,
comment|/*                udoubleacute Å± LATIN SMALL LETTER U WITH DOUBLE ACUTE */
block|{
literal|0x01fe
block|,
literal|0x0163
block|}
block|,
comment|/*                    tcedilla Å£ LATIN SMALL LETTER T WITH CEDILLA */
block|{
literal|0x01ff
block|,
literal|0x02d9
block|}
block|,
comment|/*                    abovedot Ë DOT ABOVE */
block|{
literal|0x02a1
block|,
literal|0x0126
block|}
block|,
comment|/*                     Hstroke Ä¦ LATIN CAPITAL LETTER H WITH STROKE */
block|{
literal|0x02a6
block|,
literal|0x0124
block|}
block|,
comment|/*                 Hcircumflex Ä¤ LATIN CAPITAL LETTER H WITH CIRCUMFLEX */
block|{
literal|0x02a9
block|,
literal|0x0130
block|}
block|,
comment|/*                   Iabovedot Ä° LATIN CAPITAL LETTER I WITH DOT ABOVE */
block|{
literal|0x02ab
block|,
literal|0x011e
block|}
block|,
comment|/*                      Gbreve Ä LATIN CAPITAL LETTER G WITH BREVE */
block|{
literal|0x02ac
block|,
literal|0x0134
block|}
block|,
comment|/*                 Jcircumflex Ä´ LATIN CAPITAL LETTER J WITH CIRCUMFLEX */
block|{
literal|0x02b1
block|,
literal|0x0127
block|}
block|,
comment|/*                     hstroke Ä§ LATIN SMALL LETTER H WITH STROKE */
block|{
literal|0x02b6
block|,
literal|0x0125
block|}
block|,
comment|/*                 hcircumflex Ä¥ LATIN SMALL LETTER H WITH CIRCUMFLEX */
block|{
literal|0x02b9
block|,
literal|0x0131
block|}
block|,
comment|/*                    idotless Ä± LATIN SMALL LETTER DOTLESS I */
block|{
literal|0x02bb
block|,
literal|0x011f
block|}
block|,
comment|/*                      gbreve Ä LATIN SMALL LETTER G WITH BREVE */
block|{
literal|0x02bc
block|,
literal|0x0135
block|}
block|,
comment|/*                 jcircumflex Äµ LATIN SMALL LETTER J WITH CIRCUMFLEX */
block|{
literal|0x02c5
block|,
literal|0x010a
block|}
block|,
comment|/*                   Cabovedot Ä LATIN CAPITAL LETTER C WITH DOT ABOVE */
block|{
literal|0x02c6
block|,
literal|0x0108
block|}
block|,
comment|/*                 Ccircumflex Ä LATIN CAPITAL LETTER C WITH CIRCUMFLEX */
block|{
literal|0x02d5
block|,
literal|0x0120
block|}
block|,
comment|/*                   Gabovedot Ä  LATIN CAPITAL LETTER G WITH DOT ABOVE */
block|{
literal|0x02d8
block|,
literal|0x011c
block|}
block|,
comment|/*                 Gcircumflex Ä LATIN CAPITAL LETTER G WITH CIRCUMFLEX */
block|{
literal|0x02dd
block|,
literal|0x016c
block|}
block|,
comment|/*                      Ubreve Å¬ LATIN CAPITAL LETTER U WITH BREVE */
block|{
literal|0x02de
block|,
literal|0x015c
block|}
block|,
comment|/*                 Scircumflex Å LATIN CAPITAL LETTER S WITH CIRCUMFLEX */
block|{
literal|0x02e5
block|,
literal|0x010b
block|}
block|,
comment|/*                   cabovedot Ä LATIN SMALL LETTER C WITH DOT ABOVE */
block|{
literal|0x02e6
block|,
literal|0x0109
block|}
block|,
comment|/*                 ccircumflex Ä LATIN SMALL LETTER C WITH CIRCUMFLEX */
block|{
literal|0x02f5
block|,
literal|0x0121
block|}
block|,
comment|/*                   gabovedot Ä¡ LATIN SMALL LETTER G WITH DOT ABOVE */
block|{
literal|0x02f8
block|,
literal|0x011d
block|}
block|,
comment|/*                 gcircumflex Ä LATIN SMALL LETTER G WITH CIRCUMFLEX */
block|{
literal|0x02fd
block|,
literal|0x016d
block|}
block|,
comment|/*                      ubreve Å­ LATIN SMALL LETTER U WITH BREVE */
block|{
literal|0x02fe
block|,
literal|0x015d
block|}
block|,
comment|/*                 scircumflex Å LATIN SMALL LETTER S WITH CIRCUMFLEX */
block|{
literal|0x03a2
block|,
literal|0x0138
block|}
block|,
comment|/*                         kra Ä¸ LATIN SMALL LETTER KRA */
block|{
literal|0x03a3
block|,
literal|0x0156
block|}
block|,
comment|/*                    Rcedilla Å LATIN CAPITAL LETTER R WITH CEDILLA */
block|{
literal|0x03a5
block|,
literal|0x0128
block|}
block|,
comment|/*                      Itilde Ä¨ LATIN CAPITAL LETTER I WITH TILDE */
block|{
literal|0x03a6
block|,
literal|0x013b
block|}
block|,
comment|/*                    Lcedilla Ä» LATIN CAPITAL LETTER L WITH CEDILLA */
block|{
literal|0x03aa
block|,
literal|0x0112
block|}
block|,
comment|/*                     Emacron Ä LATIN CAPITAL LETTER E WITH MACRON */
block|{
literal|0x03ab
block|,
literal|0x0122
block|}
block|,
comment|/*                    Gcedilla Ä¢ LATIN CAPITAL LETTER G WITH CEDILLA */
block|{
literal|0x03ac
block|,
literal|0x0166
block|}
block|,
comment|/*                      Tslash Å¦ LATIN CAPITAL LETTER T WITH STROKE */
block|{
literal|0x03b3
block|,
literal|0x0157
block|}
block|,
comment|/*                    rcedilla Å LATIN SMALL LETTER R WITH CEDILLA */
block|{
literal|0x03b5
block|,
literal|0x0129
block|}
block|,
comment|/*                      itilde Ä© LATIN SMALL LETTER I WITH TILDE */
block|{
literal|0x03b6
block|,
literal|0x013c
block|}
block|,
comment|/*                    lcedilla Ä¼ LATIN SMALL LETTER L WITH CEDILLA */
block|{
literal|0x03ba
block|,
literal|0x0113
block|}
block|,
comment|/*                     emacron Ä LATIN SMALL LETTER E WITH MACRON */
block|{
literal|0x03bb
block|,
literal|0x0123
block|}
block|,
comment|/*                    gcedilla Ä£ LATIN SMALL LETTER G WITH CEDILLA */
block|{
literal|0x03bc
block|,
literal|0x0167
block|}
block|,
comment|/*                      tslash Å§ LATIN SMALL LETTER T WITH STROKE */
block|{
literal|0x03bd
block|,
literal|0x014a
block|}
block|,
comment|/*                         ENG Å LATIN CAPITAL LETTER ENG */
block|{
literal|0x03bf
block|,
literal|0x014b
block|}
block|,
comment|/*                         eng Å LATIN SMALL LETTER ENG */
block|{
literal|0x03c0
block|,
literal|0x0100
block|}
block|,
comment|/*                     Amacron Ä LATIN CAPITAL LETTER A WITH MACRON */
block|{
literal|0x03c7
block|,
literal|0x012e
block|}
block|,
comment|/*                     Iogonek Ä® LATIN CAPITAL LETTER I WITH OGONEK */
block|{
literal|0x03cc
block|,
literal|0x0116
block|}
block|,
comment|/*                   Eabovedot Ä LATIN CAPITAL LETTER E WITH DOT ABOVE */
block|{
literal|0x03cf
block|,
literal|0x012a
block|}
block|,
comment|/*                     Imacron Äª LATIN CAPITAL LETTER I WITH MACRON */
block|{
literal|0x03d1
block|,
literal|0x0145
block|}
block|,
comment|/*                    Ncedilla Å LATIN CAPITAL LETTER N WITH CEDILLA */
block|{
literal|0x03d2
block|,
literal|0x014c
block|}
block|,
comment|/*                     Omacron Å LATIN CAPITAL LETTER O WITH MACRON */
block|{
literal|0x03d3
block|,
literal|0x0136
block|}
block|,
comment|/*                    Kcedilla Ä¶ LATIN CAPITAL LETTER K WITH CEDILLA */
block|{
literal|0x03d9
block|,
literal|0x0172
block|}
block|,
comment|/*                     Uogonek Å² LATIN CAPITAL LETTER U WITH OGONEK */
block|{
literal|0x03dd
block|,
literal|0x0168
block|}
block|,
comment|/*                      Utilde Å¨ LATIN CAPITAL LETTER U WITH TILDE */
block|{
literal|0x03de
block|,
literal|0x016a
block|}
block|,
comment|/*                     Umacron Åª LATIN CAPITAL LETTER U WITH MACRON */
block|{
literal|0x03e0
block|,
literal|0x0101
block|}
block|,
comment|/*                     amacron Ä LATIN SMALL LETTER A WITH MACRON */
block|{
literal|0x03e7
block|,
literal|0x012f
block|}
block|,
comment|/*                     iogonek Ä¯ LATIN SMALL LETTER I WITH OGONEK */
block|{
literal|0x03ec
block|,
literal|0x0117
block|}
block|,
comment|/*                   eabovedot Ä LATIN SMALL LETTER E WITH DOT ABOVE */
block|{
literal|0x03ef
block|,
literal|0x012b
block|}
block|,
comment|/*                     imacron Ä« LATIN SMALL LETTER I WITH MACRON */
block|{
literal|0x03f1
block|,
literal|0x0146
block|}
block|,
comment|/*                    ncedilla Å LATIN SMALL LETTER N WITH CEDILLA */
block|{
literal|0x03f2
block|,
literal|0x014d
block|}
block|,
comment|/*                     omacron Å LATIN SMALL LETTER O WITH MACRON */
block|{
literal|0x03f3
block|,
literal|0x0137
block|}
block|,
comment|/*                    kcedilla Ä· LATIN SMALL LETTER K WITH CEDILLA */
block|{
literal|0x03f9
block|,
literal|0x0173
block|}
block|,
comment|/*                     uogonek Å³ LATIN SMALL LETTER U WITH OGONEK */
block|{
literal|0x03fd
block|,
literal|0x0169
block|}
block|,
comment|/*                      utilde Å© LATIN SMALL LETTER U WITH TILDE */
block|{
literal|0x03fe
block|,
literal|0x016b
block|}
block|,
comment|/*                     umacron Å« LATIN SMALL LETTER U WITH MACRON */
block|{
literal|0x047e
block|,
literal|0x203e
block|}
block|,
comment|/*                    overline â¾ OVERLINE */
block|{
literal|0x04a1
block|,
literal|0x3002
block|}
block|,
comment|/*               kana_fullstop ã IDEOGRAPHIC FULL STOP */
block|{
literal|0x04a2
block|,
literal|0x300c
block|}
block|,
comment|/*         kana_openingbracket ã LEFT CORNER BRACKET */
block|{
literal|0x04a3
block|,
literal|0x300d
block|}
block|,
comment|/*         kana_closingbracket ã RIGHT CORNER BRACKET */
block|{
literal|0x04a4
block|,
literal|0x3001
block|}
block|,
comment|/*                  kana_comma ã IDEOGRAPHIC COMMA */
block|{
literal|0x04a5
block|,
literal|0x30fb
block|}
block|,
comment|/*            kana_conjunctive ã» KATAKANA MIDDLE DOT */
block|{
literal|0x04a6
block|,
literal|0x30f2
block|}
block|,
comment|/*                     kana_WO ã² KATAKANA LETTER WO */
block|{
literal|0x04a7
block|,
literal|0x30a1
block|}
block|,
comment|/*                      kana_a ã¡ KATAKANA LETTER SMALL A */
block|{
literal|0x04a8
block|,
literal|0x30a3
block|}
block|,
comment|/*                      kana_i ã£ KATAKANA LETTER SMALL I */
block|{
literal|0x04a9
block|,
literal|0x30a5
block|}
block|,
comment|/*                      kana_u ã¥ KATAKANA LETTER SMALL U */
block|{
literal|0x04aa
block|,
literal|0x30a7
block|}
block|,
comment|/*                      kana_e ã§ KATAKANA LETTER SMALL E */
block|{
literal|0x04ab
block|,
literal|0x30a9
block|}
block|,
comment|/*                      kana_o ã© KATAKANA LETTER SMALL O */
block|{
literal|0x04ac
block|,
literal|0x30e3
block|}
block|,
comment|/*                     kana_ya ã£ KATAKANA LETTER SMALL YA */
block|{
literal|0x04ad
block|,
literal|0x30e5
block|}
block|,
comment|/*                     kana_yu ã¥ KATAKANA LETTER SMALL YU */
block|{
literal|0x04ae
block|,
literal|0x30e7
block|}
block|,
comment|/*                     kana_yo ã§ KATAKANA LETTER SMALL YO */
block|{
literal|0x04af
block|,
literal|0x30c3
block|}
block|,
comment|/*                    kana_tsu ã KATAKANA LETTER SMALL TU */
block|{
literal|0x04b0
block|,
literal|0x30fc
block|}
block|,
comment|/*              prolongedsound ã¼ KATAKANA-HIRAGANA PROLONGED SOUND MARK */
block|{
literal|0x04b1
block|,
literal|0x30a2
block|}
block|,
comment|/*                      kana_A ã¢ KATAKANA LETTER A */
block|{
literal|0x04b2
block|,
literal|0x30a4
block|}
block|,
comment|/*                      kana_I ã¤ KATAKANA LETTER I */
block|{
literal|0x04b3
block|,
literal|0x30a6
block|}
block|,
comment|/*                      kana_U ã¦ KATAKANA LETTER U */
block|{
literal|0x04b4
block|,
literal|0x30a8
block|}
block|,
comment|/*                      kana_E ã¨ KATAKANA LETTER E */
block|{
literal|0x04b5
block|,
literal|0x30aa
block|}
block|,
comment|/*                      kana_O ãª KATAKANA LETTER O */
block|{
literal|0x04b6
block|,
literal|0x30ab
block|}
block|,
comment|/*                     kana_KA ã« KATAKANA LETTER KA */
block|{
literal|0x04b7
block|,
literal|0x30ad
block|}
block|,
comment|/*                     kana_KI ã­ KATAKANA LETTER KI */
block|{
literal|0x04b8
block|,
literal|0x30af
block|}
block|,
comment|/*                     kana_KU ã¯ KATAKANA LETTER KU */
block|{
literal|0x04b9
block|,
literal|0x30b1
block|}
block|,
comment|/*                     kana_KE ã± KATAKANA LETTER KE */
block|{
literal|0x04ba
block|,
literal|0x30b3
block|}
block|,
comment|/*                     kana_KO ã³ KATAKANA LETTER KO */
block|{
literal|0x04bb
block|,
literal|0x30b5
block|}
block|,
comment|/*                     kana_SA ãµ KATAKANA LETTER SA */
block|{
literal|0x04bc
block|,
literal|0x30b7
block|}
block|,
comment|/*                    kana_SHI ã· KATAKANA LETTER SI */
block|{
literal|0x04bd
block|,
literal|0x30b9
block|}
block|,
comment|/*                     kana_SU ã¹ KATAKANA LETTER SU */
block|{
literal|0x04be
block|,
literal|0x30bb
block|}
block|,
comment|/*                     kana_SE ã» KATAKANA LETTER SE */
block|{
literal|0x04bf
block|,
literal|0x30bd
block|}
block|,
comment|/*                     kana_SO ã½ KATAKANA LETTER SO */
block|{
literal|0x04c0
block|,
literal|0x30bf
block|}
block|,
comment|/*                     kana_TA ã¿ KATAKANA LETTER TA */
block|{
literal|0x04c1
block|,
literal|0x30c1
block|}
block|,
comment|/*                    kana_CHI ã KATAKANA LETTER TI */
block|{
literal|0x04c2
block|,
literal|0x30c4
block|}
block|,
comment|/*                    kana_TSU ã KATAKANA LETTER TU */
block|{
literal|0x04c3
block|,
literal|0x30c6
block|}
block|,
comment|/*                     kana_TE ã KATAKANA LETTER TE */
block|{
literal|0x04c4
block|,
literal|0x30c8
block|}
block|,
comment|/*                     kana_TO ã KATAKANA LETTER TO */
block|{
literal|0x04c5
block|,
literal|0x30ca
block|}
block|,
comment|/*                     kana_NA ã KATAKANA LETTER NA */
block|{
literal|0x04c6
block|,
literal|0x30cb
block|}
block|,
comment|/*                     kana_NI ã KATAKANA LETTER NI */
block|{
literal|0x04c7
block|,
literal|0x30cc
block|}
block|,
comment|/*                     kana_NU ã KATAKANA LETTER NU */
block|{
literal|0x04c8
block|,
literal|0x30cd
block|}
block|,
comment|/*                     kana_NE ã KATAKANA LETTER NE */
block|{
literal|0x04c9
block|,
literal|0x30ce
block|}
block|,
comment|/*                     kana_NO ã KATAKANA LETTER NO */
block|{
literal|0x04ca
block|,
literal|0x30cf
block|}
block|,
comment|/*                     kana_HA ã KATAKANA LETTER HA */
block|{
literal|0x04cb
block|,
literal|0x30d2
block|}
block|,
comment|/*                     kana_HI ã KATAKANA LETTER HI */
block|{
literal|0x04cc
block|,
literal|0x30d5
block|}
block|,
comment|/*                     kana_FU ã KATAKANA LETTER HU */
block|{
literal|0x04cd
block|,
literal|0x30d8
block|}
block|,
comment|/*                     kana_HE ã KATAKANA LETTER HE */
block|{
literal|0x04ce
block|,
literal|0x30db
block|}
block|,
comment|/*                     kana_HO ã KATAKANA LETTER HO */
block|{
literal|0x04cf
block|,
literal|0x30de
block|}
block|,
comment|/*                     kana_MA ã KATAKANA LETTER MA */
block|{
literal|0x04d0
block|,
literal|0x30df
block|}
block|,
comment|/*                     kana_MI ã KATAKANA LETTER MI */
block|{
literal|0x04d1
block|,
literal|0x30e0
block|}
block|,
comment|/*                     kana_MU ã  KATAKANA LETTER MU */
block|{
literal|0x04d2
block|,
literal|0x30e1
block|}
block|,
comment|/*                     kana_ME ã¡ KATAKANA LETTER ME */
block|{
literal|0x04d3
block|,
literal|0x30e2
block|}
block|,
comment|/*                     kana_MO ã¢ KATAKANA LETTER MO */
block|{
literal|0x04d4
block|,
literal|0x30e4
block|}
block|,
comment|/*                     kana_YA ã¤ KATAKANA LETTER YA */
block|{
literal|0x04d5
block|,
literal|0x30e6
block|}
block|,
comment|/*                     kana_YU ã¦ KATAKANA LETTER YU */
block|{
literal|0x04d6
block|,
literal|0x30e8
block|}
block|,
comment|/*                     kana_YO ã¨ KATAKANA LETTER YO */
block|{
literal|0x04d7
block|,
literal|0x30e9
block|}
block|,
comment|/*                     kana_RA ã© KATAKANA LETTER RA */
block|{
literal|0x04d8
block|,
literal|0x30ea
block|}
block|,
comment|/*                     kana_RI ãª KATAKANA LETTER RI */
block|{
literal|0x04d9
block|,
literal|0x30eb
block|}
block|,
comment|/*                     kana_RU ã« KATAKANA LETTER RU */
block|{
literal|0x04da
block|,
literal|0x30ec
block|}
block|,
comment|/*                     kana_RE ã¬ KATAKANA LETTER RE */
block|{
literal|0x04db
block|,
literal|0x30ed
block|}
block|,
comment|/*                     kana_RO ã­ KATAKANA LETTER RO */
block|{
literal|0x04dc
block|,
literal|0x30ef
block|}
block|,
comment|/*                     kana_WA ã¯ KATAKANA LETTER WA */
block|{
literal|0x04dd
block|,
literal|0x30f3
block|}
block|,
comment|/*                      kana_N ã³ KATAKANA LETTER N */
block|{
literal|0x04de
block|,
literal|0x309b
block|}
block|,
comment|/*                 voicedsound ã KATAKANA-HIRAGANA VOICED SOUND MARK */
block|{
literal|0x04df
block|,
literal|0x309c
block|}
block|,
comment|/*             semivoicedsound ã KATAKANA-HIRAGANA SEMI-VOICED SOUND MARK */
block|{
literal|0x05ac
block|,
literal|0x060c
block|}
block|,
comment|/*                Arabic_comma Ø ARABIC COMMA */
block|{
literal|0x05bb
block|,
literal|0x061b
block|}
block|,
comment|/*            Arabic_semicolon Ø ARABIC SEMICOLON */
block|{
literal|0x05bf
block|,
literal|0x061f
block|}
block|,
comment|/*        Arabic_question_mark Ø ARABIC QUESTION MARK */
block|{
literal|0x05c1
block|,
literal|0x0621
block|}
block|,
comment|/*                Arabic_hamza Ø¡ ARABIC LETTER HAMZA */
block|{
literal|0x05c2
block|,
literal|0x0622
block|}
block|,
comment|/*          Arabic_maddaonalef Ø¢ ARABIC LETTER ALEF WITH MADDA ABOVE */
block|{
literal|0x05c3
block|,
literal|0x0623
block|}
block|,
comment|/*          Arabic_hamzaonalef Ø£ ARABIC LETTER ALEF WITH HAMZA ABOVE */
block|{
literal|0x05c4
block|,
literal|0x0624
block|}
block|,
comment|/*           Arabic_hamzaonwaw Ø¤ ARABIC LETTER WAW WITH HAMZA ABOVE */
block|{
literal|0x05c5
block|,
literal|0x0625
block|}
block|,
comment|/*       Arabic_hamzaunderalef Ø¥ ARABIC LETTER ALEF WITH HAMZA BELOW */
block|{
literal|0x05c6
block|,
literal|0x0626
block|}
block|,
comment|/*           Arabic_hamzaonyeh Ø¦ ARABIC LETTER YEH WITH HAMZA ABOVE */
block|{
literal|0x05c7
block|,
literal|0x0627
block|}
block|,
comment|/*                 Arabic_alef Ø§ ARABIC LETTER ALEF */
block|{
literal|0x05c8
block|,
literal|0x0628
block|}
block|,
comment|/*                  Arabic_beh Ø¨ ARABIC LETTER BEH */
block|{
literal|0x05c9
block|,
literal|0x0629
block|}
block|,
comment|/*           Arabic_tehmarbuta Ø© ARABIC LETTER TEH MARBUTA */
block|{
literal|0x05ca
block|,
literal|0x062a
block|}
block|,
comment|/*                  Arabic_teh Øª ARABIC LETTER TEH */
block|{
literal|0x05cb
block|,
literal|0x062b
block|}
block|,
comment|/*                 Arabic_theh Ø« ARABIC LETTER THEH */
block|{
literal|0x05cc
block|,
literal|0x062c
block|}
block|,
comment|/*                 Arabic_jeem Ø¬ ARABIC LETTER JEEM */
block|{
literal|0x05cd
block|,
literal|0x062d
block|}
block|,
comment|/*                  Arabic_hah Ø­ ARABIC LETTER HAH */
block|{
literal|0x05ce
block|,
literal|0x062e
block|}
block|,
comment|/*                 Arabic_khah Ø® ARABIC LETTER KHAH */
block|{
literal|0x05cf
block|,
literal|0x062f
block|}
block|,
comment|/*                  Arabic_dal Ø¯ ARABIC LETTER DAL */
block|{
literal|0x05d0
block|,
literal|0x0630
block|}
block|,
comment|/*                 Arabic_thal Ø° ARABIC LETTER THAL */
block|{
literal|0x05d1
block|,
literal|0x0631
block|}
block|,
comment|/*                   Arabic_ra Ø± ARABIC LETTER REH */
block|{
literal|0x05d2
block|,
literal|0x0632
block|}
block|,
comment|/*                 Arabic_zain Ø² ARABIC LETTER ZAIN */
block|{
literal|0x05d3
block|,
literal|0x0633
block|}
block|,
comment|/*                 Arabic_seen Ø³ ARABIC LETTER SEEN */
block|{
literal|0x05d4
block|,
literal|0x0634
block|}
block|,
comment|/*                Arabic_sheen Ø´ ARABIC LETTER SHEEN */
block|{
literal|0x05d5
block|,
literal|0x0635
block|}
block|,
comment|/*                  Arabic_sad Øµ ARABIC LETTER SAD */
block|{
literal|0x05d6
block|,
literal|0x0636
block|}
block|,
comment|/*                  Arabic_dad Ø¶ ARABIC LETTER DAD */
block|{
literal|0x05d7
block|,
literal|0x0637
block|}
block|,
comment|/*                  Arabic_tah Ø· ARABIC LETTER TAH */
block|{
literal|0x05d8
block|,
literal|0x0638
block|}
block|,
comment|/*                  Arabic_zah Ø¸ ARABIC LETTER ZAH */
block|{
literal|0x05d9
block|,
literal|0x0639
block|}
block|,
comment|/*                  Arabic_ain Ø¹ ARABIC LETTER AIN */
block|{
literal|0x05da
block|,
literal|0x063a
block|}
block|,
comment|/*                Arabic_ghain Øº ARABIC LETTER GHAIN */
block|{
literal|0x05e0
block|,
literal|0x0640
block|}
block|,
comment|/*              Arabic_tatweel Ù ARABIC TATWEEL */
block|{
literal|0x05e1
block|,
literal|0x0641
block|}
block|,
comment|/*                  Arabic_feh Ù ARABIC LETTER FEH */
block|{
literal|0x05e2
block|,
literal|0x0642
block|}
block|,
comment|/*                  Arabic_qaf Ù ARABIC LETTER QAF */
block|{
literal|0x05e3
block|,
literal|0x0643
block|}
block|,
comment|/*                  Arabic_kaf Ù ARABIC LETTER KAF */
block|{
literal|0x05e4
block|,
literal|0x0644
block|}
block|,
comment|/*                  Arabic_lam Ù ARABIC LETTER LAM */
block|{
literal|0x05e5
block|,
literal|0x0645
block|}
block|,
comment|/*                 Arabic_meem Ù ARABIC LETTER MEEM */
block|{
literal|0x05e6
block|,
literal|0x0646
block|}
block|,
comment|/*                 Arabic_noon Ù ARABIC LETTER NOON */
block|{
literal|0x05e7
block|,
literal|0x0647
block|}
block|,
comment|/*                   Arabic_ha Ù ARABIC LETTER HEH */
block|{
literal|0x05e8
block|,
literal|0x0648
block|}
block|,
comment|/*                  Arabic_waw Ù ARABIC LETTER WAW */
block|{
literal|0x05e9
block|,
literal|0x0649
block|}
block|,
comment|/*          Arabic_alefmaksura Ù ARABIC LETTER ALEF MAKSURA */
block|{
literal|0x05ea
block|,
literal|0x064a
block|}
block|,
comment|/*                  Arabic_yeh Ù ARABIC LETTER YEH */
block|{
literal|0x05eb
block|,
literal|0x064b
block|}
block|,
comment|/*             Arabic_fathatan Ù ARABIC FATHATAN */
block|{
literal|0x05ec
block|,
literal|0x064c
block|}
block|,
comment|/*             Arabic_dammatan Ù ARABIC DAMMATAN */
block|{
literal|0x05ed
block|,
literal|0x064d
block|}
block|,
comment|/*             Arabic_kasratan Ù ARABIC KASRATAN */
block|{
literal|0x05ee
block|,
literal|0x064e
block|}
block|,
comment|/*                Arabic_fatha Ù ARABIC FATHA */
block|{
literal|0x05ef
block|,
literal|0x064f
block|}
block|,
comment|/*                Arabic_damma Ù ARABIC DAMMA */
block|{
literal|0x05f0
block|,
literal|0x0650
block|}
block|,
comment|/*                Arabic_kasra Ù ARABIC KASRA */
block|{
literal|0x05f1
block|,
literal|0x0651
block|}
block|,
comment|/*               Arabic_shadda Ù ARABIC SHADDA */
block|{
literal|0x05f2
block|,
literal|0x0652
block|}
block|,
comment|/*                Arabic_sukun Ù ARABIC SUKUN */
block|{
literal|0x06a1
block|,
literal|0x0452
block|}
block|,
comment|/*                 Serbian_dje Ñ CYRILLIC SMALL LETTER DJE */
block|{
literal|0x06a2
block|,
literal|0x0453
block|}
block|,
comment|/*               Macedonia_gje Ñ CYRILLIC SMALL LETTER GJE */
block|{
literal|0x06a3
block|,
literal|0x0451
block|}
block|,
comment|/*                 Cyrillic_io Ñ CYRILLIC SMALL LETTER IO */
block|{
literal|0x06a4
block|,
literal|0x0454
block|}
block|,
comment|/*                Ukrainian_ie Ñ CYRILLIC SMALL LETTER UKRAINIAN IE */
block|{
literal|0x06a5
block|,
literal|0x0455
block|}
block|,
comment|/*               Macedonia_dse Ñ CYRILLIC SMALL LETTER DZE */
block|{
literal|0x06a6
block|,
literal|0x0456
block|}
block|,
comment|/*                 Ukrainian_i Ñ CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I */
block|{
literal|0x06a7
block|,
literal|0x0457
block|}
block|,
comment|/*                Ukrainian_yi Ñ CYRILLIC SMALL LETTER YI */
block|{
literal|0x06a8
block|,
literal|0x0458
block|}
block|,
comment|/*                 Cyrillic_je Ñ CYRILLIC SMALL LETTER JE */
block|{
literal|0x06a9
block|,
literal|0x0459
block|}
block|,
comment|/*                Cyrillic_lje Ñ CYRILLIC SMALL LETTER LJE */
block|{
literal|0x06aa
block|,
literal|0x045a
block|}
block|,
comment|/*                Cyrillic_nje Ñ CYRILLIC SMALL LETTER NJE */
block|{
literal|0x06ab
block|,
literal|0x045b
block|}
block|,
comment|/*                Serbian_tshe Ñ CYRILLIC SMALL LETTER TSHE */
block|{
literal|0x06ac
block|,
literal|0x045c
block|}
block|,
comment|/*               Macedonia_kje Ñ CYRILLIC SMALL LETTER KJE */
block|{
literal|0x06ad
block|,
literal|0x0491
block|}
block|,
comment|/*   Ukrainian_ghe_with_upturn Ò CYRILLIC SMALL LETTER GHE WITH UPTURN */
block|{
literal|0x06ae
block|,
literal|0x045e
block|}
block|,
comment|/*         Byelorussian_shortu Ñ CYRILLIC SMALL LETTER SHORT U */
block|{
literal|0x06af
block|,
literal|0x045f
block|}
block|,
comment|/*               Cyrillic_dzhe Ñ CYRILLIC SMALL LETTER DZHE */
block|{
literal|0x06b0
block|,
literal|0x2116
block|}
block|,
comment|/*                  numerosign â NUMERO SIGN */
block|{
literal|0x06b1
block|,
literal|0x0402
block|}
block|,
comment|/*                 Serbian_DJE Ð CYRILLIC CAPITAL LETTER DJE */
block|{
literal|0x06b2
block|,
literal|0x0403
block|}
block|,
comment|/*               Macedonia_GJE Ð CYRILLIC CAPITAL LETTER GJE */
block|{
literal|0x06b3
block|,
literal|0x0401
block|}
block|,
comment|/*                 Cyrillic_IO Ð CYRILLIC CAPITAL LETTER IO */
block|{
literal|0x06b4
block|,
literal|0x0404
block|}
block|,
comment|/*                Ukrainian_IE Ð CYRILLIC CAPITAL LETTER UKRAINIAN IE */
block|{
literal|0x06b5
block|,
literal|0x0405
block|}
block|,
comment|/*               Macedonia_DSE Ð CYRILLIC CAPITAL LETTER DZE */
block|{
literal|0x06b6
block|,
literal|0x0406
block|}
block|,
comment|/*                 Ukrainian_I Ð CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I */
block|{
literal|0x06b7
block|,
literal|0x0407
block|}
block|,
comment|/*                Ukrainian_YI Ð CYRILLIC CAPITAL LETTER YI */
block|{
literal|0x06b8
block|,
literal|0x0408
block|}
block|,
comment|/*                 Cyrillic_JE Ð CYRILLIC CAPITAL LETTER JE */
block|{
literal|0x06b9
block|,
literal|0x0409
block|}
block|,
comment|/*                Cyrillic_LJE Ð CYRILLIC CAPITAL LETTER LJE */
block|{
literal|0x06ba
block|,
literal|0x040a
block|}
block|,
comment|/*                Cyrillic_NJE Ð CYRILLIC CAPITAL LETTER NJE */
block|{
literal|0x06bb
block|,
literal|0x040b
block|}
block|,
comment|/*                Serbian_TSHE Ð CYRILLIC CAPITAL LETTER TSHE */
block|{
literal|0x06bc
block|,
literal|0x040c
block|}
block|,
comment|/*               Macedonia_KJE Ð CYRILLIC CAPITAL LETTER KJE */
block|{
literal|0x06bd
block|,
literal|0x0490
block|}
block|,
comment|/*   Ukrainian_GHE_WITH_UPTURN Ò CYRILLIC CAPITAL LETTER GHE WITH UPTURN */
block|{
literal|0x06be
block|,
literal|0x040e
block|}
block|,
comment|/*         Byelorussian_SHORTU Ð CYRILLIC CAPITAL LETTER SHORT U */
block|{
literal|0x06bf
block|,
literal|0x040f
block|}
block|,
comment|/*               Cyrillic_DZHE Ð CYRILLIC CAPITAL LETTER DZHE */
block|{
literal|0x06c0
block|,
literal|0x044e
block|}
block|,
comment|/*                 Cyrillic_yu Ñ CYRILLIC SMALL LETTER YU */
block|{
literal|0x06c1
block|,
literal|0x0430
block|}
block|,
comment|/*                  Cyrillic_a Ð° CYRILLIC SMALL LETTER A */
block|{
literal|0x06c2
block|,
literal|0x0431
block|}
block|,
comment|/*                 Cyrillic_be Ð± CYRILLIC SMALL LETTER BE */
block|{
literal|0x06c3
block|,
literal|0x0446
block|}
block|,
comment|/*                Cyrillic_tse Ñ CYRILLIC SMALL LETTER TSE */
block|{
literal|0x06c4
block|,
literal|0x0434
block|}
block|,
comment|/*                 Cyrillic_de Ð´ CYRILLIC SMALL LETTER DE */
block|{
literal|0x06c5
block|,
literal|0x0435
block|}
block|,
comment|/*                 Cyrillic_ie Ðµ CYRILLIC SMALL LETTER IE */
block|{
literal|0x06c6
block|,
literal|0x0444
block|}
block|,
comment|/*                 Cyrillic_ef Ñ CYRILLIC SMALL LETTER EF */
block|{
literal|0x06c7
block|,
literal|0x0433
block|}
block|,
comment|/*                Cyrillic_ghe Ð³ CYRILLIC SMALL LETTER GHE */
block|{
literal|0x06c8
block|,
literal|0x0445
block|}
block|,
comment|/*                 Cyrillic_ha Ñ CYRILLIC SMALL LETTER HA */
block|{
literal|0x06c9
block|,
literal|0x0438
block|}
block|,
comment|/*                  Cyrillic_i Ð¸ CYRILLIC SMALL LETTER I */
block|{
literal|0x06ca
block|,
literal|0x0439
block|}
block|,
comment|/*             Cyrillic_shorti Ð¹ CYRILLIC SMALL LETTER SHORT I */
block|{
literal|0x06cb
block|,
literal|0x043a
block|}
block|,
comment|/*                 Cyrillic_ka Ðº CYRILLIC SMALL LETTER KA */
block|{
literal|0x06cc
block|,
literal|0x043b
block|}
block|,
comment|/*                 Cyrillic_el Ð» CYRILLIC SMALL LETTER EL */
block|{
literal|0x06cd
block|,
literal|0x043c
block|}
block|,
comment|/*                 Cyrillic_em Ð¼ CYRILLIC SMALL LETTER EM */
block|{
literal|0x06ce
block|,
literal|0x043d
block|}
block|,
comment|/*                 Cyrillic_en Ð½ CYRILLIC SMALL LETTER EN */
block|{
literal|0x06cf
block|,
literal|0x043e
block|}
block|,
comment|/*                  Cyrillic_o Ð¾ CYRILLIC SMALL LETTER O */
block|{
literal|0x06d0
block|,
literal|0x043f
block|}
block|,
comment|/*                 Cyrillic_pe Ð¿ CYRILLIC SMALL LETTER PE */
block|{
literal|0x06d1
block|,
literal|0x044f
block|}
block|,
comment|/*                 Cyrillic_ya Ñ CYRILLIC SMALL LETTER YA */
block|{
literal|0x06d2
block|,
literal|0x0440
block|}
block|,
comment|/*                 Cyrillic_er Ñ CYRILLIC SMALL LETTER ER */
block|{
literal|0x06d3
block|,
literal|0x0441
block|}
block|,
comment|/*                 Cyrillic_es Ñ CYRILLIC SMALL LETTER ES */
block|{
literal|0x06d4
block|,
literal|0x0442
block|}
block|,
comment|/*                 Cyrillic_te Ñ CYRILLIC SMALL LETTER TE */
block|{
literal|0x06d5
block|,
literal|0x0443
block|}
block|,
comment|/*                  Cyrillic_u Ñ CYRILLIC SMALL LETTER U */
block|{
literal|0x06d6
block|,
literal|0x0436
block|}
block|,
comment|/*                Cyrillic_zhe Ð¶ CYRILLIC SMALL LETTER ZHE */
block|{
literal|0x06d7
block|,
literal|0x0432
block|}
block|,
comment|/*                 Cyrillic_ve Ð² CYRILLIC SMALL LETTER VE */
block|{
literal|0x06d8
block|,
literal|0x044c
block|}
block|,
comment|/*           Cyrillic_softsign Ñ CYRILLIC SMALL LETTER SOFT SIGN */
block|{
literal|0x06d9
block|,
literal|0x044b
block|}
block|,
comment|/*               Cyrillic_yeru Ñ CYRILLIC SMALL LETTER YERU */
block|{
literal|0x06da
block|,
literal|0x0437
block|}
block|,
comment|/*                 Cyrillic_ze Ð· CYRILLIC SMALL LETTER ZE */
block|{
literal|0x06db
block|,
literal|0x0448
block|}
block|,
comment|/*                Cyrillic_sha Ñ CYRILLIC SMALL LETTER SHA */
block|{
literal|0x06dc
block|,
literal|0x044d
block|}
block|,
comment|/*                  Cyrillic_e Ñ CYRILLIC SMALL LETTER E */
block|{
literal|0x06dd
block|,
literal|0x0449
block|}
block|,
comment|/*              Cyrillic_shcha Ñ CYRILLIC SMALL LETTER SHCHA */
block|{
literal|0x06de
block|,
literal|0x0447
block|}
block|,
comment|/*                Cyrillic_che Ñ CYRILLIC SMALL LETTER CHE */
block|{
literal|0x06df
block|,
literal|0x044a
block|}
block|,
comment|/*           Cyrillic_hardsign Ñ CYRILLIC SMALL LETTER HARD SIGN */
block|{
literal|0x06e0
block|,
literal|0x042e
block|}
block|,
comment|/*                 Cyrillic_YU Ð® CYRILLIC CAPITAL LETTER YU */
block|{
literal|0x06e1
block|,
literal|0x0410
block|}
block|,
comment|/*                  Cyrillic_A Ð CYRILLIC CAPITAL LETTER A */
block|{
literal|0x06e2
block|,
literal|0x0411
block|}
block|,
comment|/*                 Cyrillic_BE Ð CYRILLIC CAPITAL LETTER BE */
block|{
literal|0x06e3
block|,
literal|0x0426
block|}
block|,
comment|/*                Cyrillic_TSE Ð¦ CYRILLIC CAPITAL LETTER TSE */
block|{
literal|0x06e4
block|,
literal|0x0414
block|}
block|,
comment|/*                 Cyrillic_DE Ð CYRILLIC CAPITAL LETTER DE */
block|{
literal|0x06e5
block|,
literal|0x0415
block|}
block|,
comment|/*                 Cyrillic_IE Ð CYRILLIC CAPITAL LETTER IE */
block|{
literal|0x06e6
block|,
literal|0x0424
block|}
block|,
comment|/*                 Cyrillic_EF Ð¤ CYRILLIC CAPITAL LETTER EF */
block|{
literal|0x06e7
block|,
literal|0x0413
block|}
block|,
comment|/*                Cyrillic_GHE Ð CYRILLIC CAPITAL LETTER GHE */
block|{
literal|0x06e8
block|,
literal|0x0425
block|}
block|,
comment|/*                 Cyrillic_HA Ð¥ CYRILLIC CAPITAL LETTER HA */
block|{
literal|0x06e9
block|,
literal|0x0418
block|}
block|,
comment|/*                  Cyrillic_I Ð CYRILLIC CAPITAL LETTER I */
block|{
literal|0x06ea
block|,
literal|0x0419
block|}
block|,
comment|/*             Cyrillic_SHORTI Ð CYRILLIC CAPITAL LETTER SHORT I */
block|{
literal|0x06eb
block|,
literal|0x041a
block|}
block|,
comment|/*                 Cyrillic_KA Ð CYRILLIC CAPITAL LETTER KA */
block|{
literal|0x06ec
block|,
literal|0x041b
block|}
block|,
comment|/*                 Cyrillic_EL Ð CYRILLIC CAPITAL LETTER EL */
block|{
literal|0x06ed
block|,
literal|0x041c
block|}
block|,
comment|/*                 Cyrillic_EM Ð CYRILLIC CAPITAL LETTER EM */
block|{
literal|0x06ee
block|,
literal|0x041d
block|}
block|,
comment|/*                 Cyrillic_EN Ð CYRILLIC CAPITAL LETTER EN */
block|{
literal|0x06ef
block|,
literal|0x041e
block|}
block|,
comment|/*                  Cyrillic_O Ð CYRILLIC CAPITAL LETTER O */
block|{
literal|0x06f0
block|,
literal|0x041f
block|}
block|,
comment|/*                 Cyrillic_PE Ð CYRILLIC CAPITAL LETTER PE */
block|{
literal|0x06f1
block|,
literal|0x042f
block|}
block|,
comment|/*                 Cyrillic_YA Ð¯ CYRILLIC CAPITAL LETTER YA */
block|{
literal|0x06f2
block|,
literal|0x0420
block|}
block|,
comment|/*                 Cyrillic_ER Ð  CYRILLIC CAPITAL LETTER ER */
block|{
literal|0x06f3
block|,
literal|0x0421
block|}
block|,
comment|/*                 Cyrillic_ES Ð¡ CYRILLIC CAPITAL LETTER ES */
block|{
literal|0x06f4
block|,
literal|0x0422
block|}
block|,
comment|/*                 Cyrillic_TE Ð¢ CYRILLIC CAPITAL LETTER TE */
block|{
literal|0x06f5
block|,
literal|0x0423
block|}
block|,
comment|/*                  Cyrillic_U Ð£ CYRILLIC CAPITAL LETTER U */
block|{
literal|0x06f6
block|,
literal|0x0416
block|}
block|,
comment|/*                Cyrillic_ZHE Ð CYRILLIC CAPITAL LETTER ZHE */
block|{
literal|0x06f7
block|,
literal|0x0412
block|}
block|,
comment|/*                 Cyrillic_VE Ð CYRILLIC CAPITAL LETTER VE */
block|{
literal|0x06f8
block|,
literal|0x042c
block|}
block|,
comment|/*           Cyrillic_SOFTSIGN Ð¬ CYRILLIC CAPITAL LETTER SOFT SIGN */
block|{
literal|0x06f9
block|,
literal|0x042b
block|}
block|,
comment|/*               Cyrillic_YERU Ð« CYRILLIC CAPITAL LETTER YERU */
block|{
literal|0x06fa
block|,
literal|0x0417
block|}
block|,
comment|/*                 Cyrillic_ZE Ð CYRILLIC CAPITAL LETTER ZE */
block|{
literal|0x06fb
block|,
literal|0x0428
block|}
block|,
comment|/*                Cyrillic_SHA Ð¨ CYRILLIC CAPITAL LETTER SHA */
block|{
literal|0x06fc
block|,
literal|0x042d
block|}
block|,
comment|/*                  Cyrillic_E Ð­ CYRILLIC CAPITAL LETTER E */
block|{
literal|0x06fd
block|,
literal|0x0429
block|}
block|,
comment|/*              Cyrillic_SHCHA Ð© CYRILLIC CAPITAL LETTER SHCHA */
block|{
literal|0x06fe
block|,
literal|0x0427
block|}
block|,
comment|/*                Cyrillic_CHE Ð§ CYRILLIC CAPITAL LETTER CHE */
block|{
literal|0x06ff
block|,
literal|0x042a
block|}
block|,
comment|/*           Cyrillic_HARDSIGN Ðª CYRILLIC CAPITAL LETTER HARD SIGN */
block|{
literal|0x07a1
block|,
literal|0x0386
block|}
block|,
comment|/*           Greek_ALPHAaccent Î GREEK CAPITAL LETTER ALPHA WITH TONOS */
block|{
literal|0x07a2
block|,
literal|0x0388
block|}
block|,
comment|/*         Greek_EPSILONaccent Î GREEK CAPITAL LETTER EPSILON WITH TONOS */
block|{
literal|0x07a3
block|,
literal|0x0389
block|}
block|,
comment|/*             Greek_ETAaccent Î GREEK CAPITAL LETTER ETA WITH TONOS */
block|{
literal|0x07a4
block|,
literal|0x038a
block|}
block|,
comment|/*            Greek_IOTAaccent Î GREEK CAPITAL LETTER IOTA WITH TONOS */
block|{
literal|0x07a5
block|,
literal|0x03aa
block|}
block|,
comment|/*         Greek_IOTAdiaeresis Îª GREEK CAPITAL LETTER IOTA WITH DIALYTIKA */
block|{
literal|0x07a7
block|,
literal|0x038c
block|}
block|,
comment|/*         Greek_OMICRONaccent Î GREEK CAPITAL LETTER OMICRON WITH TONOS */
block|{
literal|0x07a8
block|,
literal|0x038e
block|}
block|,
comment|/*         Greek_UPSILONaccent Î GREEK CAPITAL LETTER UPSILON WITH TONOS */
block|{
literal|0x07a9
block|,
literal|0x03ab
block|}
block|,
comment|/*       Greek_UPSILONdieresis Î« GREEK CAPITAL LETTER UPSILON WITH DIALYTIKA */
block|{
literal|0x07ab
block|,
literal|0x038f
block|}
block|,
comment|/*           Greek_OMEGAaccent Î GREEK CAPITAL LETTER OMEGA WITH TONOS */
block|{
literal|0x07ae
block|,
literal|0x0385
block|}
block|,
comment|/*        Greek_accentdieresis Î GREEK DIALYTIKA TONOS */
block|{
literal|0x07af
block|,
literal|0x2015
block|}
block|,
comment|/*              Greek_horizbar â HORIZONTAL BAR */
block|{
literal|0x07b1
block|,
literal|0x03ac
block|}
block|,
comment|/*           Greek_alphaaccent Î¬ GREEK SMALL LETTER ALPHA WITH TONOS */
block|{
literal|0x07b2
block|,
literal|0x03ad
block|}
block|,
comment|/*         Greek_epsilonaccent Î­ GREEK SMALL LETTER EPSILON WITH TONOS */
block|{
literal|0x07b3
block|,
literal|0x03ae
block|}
block|,
comment|/*             Greek_etaaccent Î® GREEK SMALL LETTER ETA WITH TONOS */
block|{
literal|0x07b4
block|,
literal|0x03af
block|}
block|,
comment|/*            Greek_iotaaccent Î¯ GREEK SMALL LETTER IOTA WITH TONOS */
block|{
literal|0x07b5
block|,
literal|0x03ca
block|}
block|,
comment|/*          Greek_iotadieresis Ï GREEK SMALL LETTER IOTA WITH DIALYTIKA */
block|{
literal|0x07b6
block|,
literal|0x0390
block|}
block|,
comment|/*    Greek_iotaaccentdieresis Î GREEK SMALL LETTER IOTA WITH DIALYTIKA AND TONOS */
block|{
literal|0x07b7
block|,
literal|0x03cc
block|}
block|,
comment|/*         Greek_omicronaccent Ï GREEK SMALL LETTER OMICRON WITH TONOS */
block|{
literal|0x07b8
block|,
literal|0x03cd
block|}
block|,
comment|/*         Greek_upsilonaccent Ï GREEK SMALL LETTER UPSILON WITH TONOS */
block|{
literal|0x07b9
block|,
literal|0x03cb
block|}
block|,
comment|/*       Greek_upsilondieresis Ï GREEK SMALL LETTER UPSILON WITH DIALYTIKA */
block|{
literal|0x07ba
block|,
literal|0x03b0
block|}
block|,
comment|/* Greek_upsilonaccentdieresis Î° GREEK SMALL LETTER UPSILON WITH DIALYTIKA AND TONOS */
block|{
literal|0x07bb
block|,
literal|0x03ce
block|}
block|,
comment|/*           Greek_omegaaccent Ï GREEK SMALL LETTER OMEGA WITH TONOS */
block|{
literal|0x07c1
block|,
literal|0x0391
block|}
block|,
comment|/*                 Greek_ALPHA Î GREEK CAPITAL LETTER ALPHA */
block|{
literal|0x07c2
block|,
literal|0x0392
block|}
block|,
comment|/*                  Greek_BETA Î GREEK CAPITAL LETTER BETA */
block|{
literal|0x07c3
block|,
literal|0x0393
block|}
block|,
comment|/*                 Greek_GAMMA Î GREEK CAPITAL LETTER GAMMA */
block|{
literal|0x07c4
block|,
literal|0x0394
block|}
block|,
comment|/*                 Greek_DELTA Î GREEK CAPITAL LETTER DELTA */
block|{
literal|0x07c5
block|,
literal|0x0395
block|}
block|,
comment|/*               Greek_EPSILON Î GREEK CAPITAL LETTER EPSILON */
block|{
literal|0x07c6
block|,
literal|0x0396
block|}
block|,
comment|/*                  Greek_ZETA Î GREEK CAPITAL LETTER ZETA */
block|{
literal|0x07c7
block|,
literal|0x0397
block|}
block|,
comment|/*                   Greek_ETA Î GREEK CAPITAL LETTER ETA */
block|{
literal|0x07c8
block|,
literal|0x0398
block|}
block|,
comment|/*                 Greek_THETA Î GREEK CAPITAL LETTER THETA */
block|{
literal|0x07c9
block|,
literal|0x0399
block|}
block|,
comment|/*                  Greek_IOTA Î GREEK CAPITAL LETTER IOTA */
block|{
literal|0x07ca
block|,
literal|0x039a
block|}
block|,
comment|/*                 Greek_KAPPA Î GREEK CAPITAL LETTER KAPPA */
block|{
literal|0x07cb
block|,
literal|0x039b
block|}
block|,
comment|/*                Greek_LAMBDA Î GREEK CAPITAL LETTER LAMDA */
block|{
literal|0x07cc
block|,
literal|0x039c
block|}
block|,
comment|/*                    Greek_MU Î GREEK CAPITAL LETTER MU */
block|{
literal|0x07cd
block|,
literal|0x039d
block|}
block|,
comment|/*                    Greek_NU Î GREEK CAPITAL LETTER NU */
block|{
literal|0x07ce
block|,
literal|0x039e
block|}
block|,
comment|/*                    Greek_XI Î GREEK CAPITAL LETTER XI */
block|{
literal|0x07cf
block|,
literal|0x039f
block|}
block|,
comment|/*               Greek_OMICRON Î GREEK CAPITAL LETTER OMICRON */
block|{
literal|0x07d0
block|,
literal|0x03a0
block|}
block|,
comment|/*                    Greek_PI Î  GREEK CAPITAL LETTER PI */
block|{
literal|0x07d1
block|,
literal|0x03a1
block|}
block|,
comment|/*                   Greek_RHO Î¡ GREEK CAPITAL LETTER RHO */
block|{
literal|0x07d2
block|,
literal|0x03a3
block|}
block|,
comment|/*                 Greek_SIGMA Î£ GREEK CAPITAL LETTER SIGMA */
block|{
literal|0x07d4
block|,
literal|0x03a4
block|}
block|,
comment|/*                   Greek_TAU Î¤ GREEK CAPITAL LETTER TAU */
block|{
literal|0x07d5
block|,
literal|0x03a5
block|}
block|,
comment|/*               Greek_UPSILON Î¥ GREEK CAPITAL LETTER UPSILON */
block|{
literal|0x07d6
block|,
literal|0x03a6
block|}
block|,
comment|/*                   Greek_PHI Î¦ GREEK CAPITAL LETTER PHI */
block|{
literal|0x07d7
block|,
literal|0x03a7
block|}
block|,
comment|/*                   Greek_CHI Î§ GREEK CAPITAL LETTER CHI */
block|{
literal|0x07d8
block|,
literal|0x03a8
block|}
block|,
comment|/*                   Greek_PSI Î¨ GREEK CAPITAL LETTER PSI */
block|{
literal|0x07d9
block|,
literal|0x03a9
block|}
block|,
comment|/*                 Greek_OMEGA Î© GREEK CAPITAL LETTER OMEGA */
block|{
literal|0x07e1
block|,
literal|0x03b1
block|}
block|,
comment|/*                 Greek_alpha Î± GREEK SMALL LETTER ALPHA */
block|{
literal|0x07e2
block|,
literal|0x03b2
block|}
block|,
comment|/*                  Greek_beta Î² GREEK SMALL LETTER BETA */
block|{
literal|0x07e3
block|,
literal|0x03b3
block|}
block|,
comment|/*                 Greek_gamma Î³ GREEK SMALL LETTER GAMMA */
block|{
literal|0x07e4
block|,
literal|0x03b4
block|}
block|,
comment|/*                 Greek_delta Î´ GREEK SMALL LETTER DELTA */
block|{
literal|0x07e5
block|,
literal|0x03b5
block|}
block|,
comment|/*               Greek_epsilon Îµ GREEK SMALL LETTER EPSILON */
block|{
literal|0x07e6
block|,
literal|0x03b6
block|}
block|,
comment|/*                  Greek_zeta Î¶ GREEK SMALL LETTER ZETA */
block|{
literal|0x07e7
block|,
literal|0x03b7
block|}
block|,
comment|/*                   Greek_eta Î· GREEK SMALL LETTER ETA */
block|{
literal|0x07e8
block|,
literal|0x03b8
block|}
block|,
comment|/*                 Greek_theta Î¸ GREEK SMALL LETTER THETA */
block|{
literal|0x07e9
block|,
literal|0x03b9
block|}
block|,
comment|/*                  Greek_iota Î¹ GREEK SMALL LETTER IOTA */
block|{
literal|0x07ea
block|,
literal|0x03ba
block|}
block|,
comment|/*                 Greek_kappa Îº GREEK SMALL LETTER KAPPA */
block|{
literal|0x07eb
block|,
literal|0x03bb
block|}
block|,
comment|/*                Greek_lambda Î» GREEK SMALL LETTER LAMDA */
block|{
literal|0x07ec
block|,
literal|0x03bc
block|}
block|,
comment|/*                    Greek_mu Î¼ GREEK SMALL LETTER MU */
block|{
literal|0x07ed
block|,
literal|0x03bd
block|}
block|,
comment|/*                    Greek_nu Î½ GREEK SMALL LETTER NU */
block|{
literal|0x07ee
block|,
literal|0x03be
block|}
block|,
comment|/*                    Greek_xi Î¾ GREEK SMALL LETTER XI */
block|{
literal|0x07ef
block|,
literal|0x03bf
block|}
block|,
comment|/*               Greek_omicron Î¿ GREEK SMALL LETTER OMICRON */
block|{
literal|0x07f0
block|,
literal|0x03c0
block|}
block|,
comment|/*                    Greek_pi Ï GREEK SMALL LETTER PI */
block|{
literal|0x07f1
block|,
literal|0x03c1
block|}
block|,
comment|/*                   Greek_rho Ï GREEK SMALL LETTER RHO */
block|{
literal|0x07f2
block|,
literal|0x03c3
block|}
block|,
comment|/*                 Greek_sigma Ï GREEK SMALL LETTER SIGMA */
block|{
literal|0x07f3
block|,
literal|0x03c2
block|}
block|,
comment|/*       Greek_finalsmallsigma Ï GREEK SMALL LETTER FINAL SIGMA */
block|{
literal|0x07f4
block|,
literal|0x03c4
block|}
block|,
comment|/*                   Greek_tau Ï GREEK SMALL LETTER TAU */
block|{
literal|0x07f5
block|,
literal|0x03c5
block|}
block|,
comment|/*               Greek_upsilon Ï GREEK SMALL LETTER UPSILON */
block|{
literal|0x07f6
block|,
literal|0x03c6
block|}
block|,
comment|/*                   Greek_phi Ï GREEK SMALL LETTER PHI */
block|{
literal|0x07f7
block|,
literal|0x03c7
block|}
block|,
comment|/*                   Greek_chi Ï GREEK SMALL LETTER CHI */
block|{
literal|0x07f8
block|,
literal|0x03c8
block|}
block|,
comment|/*                   Greek_psi Ï GREEK SMALL LETTER PSI */
block|{
literal|0x07f9
block|,
literal|0x03c9
block|}
block|,
comment|/*                 Greek_omega Ï GREEK SMALL LETTER OMEGA */
block|{
literal|0x08a1
block|,
literal|0x23b7
block|}
block|,
comment|/*                 leftradical â· ??? */
block|{
literal|0x08a2
block|,
literal|0x250c
block|}
block|,
comment|/*              topleftradical â BOX DRAWINGS LIGHT DOWN AND RIGHT */
block|{
literal|0x08a3
block|,
literal|0x2500
block|}
block|,
comment|/*              horizconnector â BOX DRAWINGS LIGHT HORIZONTAL */
block|{
literal|0x08a4
block|,
literal|0x2320
block|}
block|,
comment|/*                 topintegral â  TOP HALF INTEGRAL */
block|{
literal|0x08a5
block|,
literal|0x2321
block|}
block|,
comment|/*                 botintegral â¡ BOTTOM HALF INTEGRAL */
block|{
literal|0x08a6
block|,
literal|0x2502
block|}
block|,
comment|/*               vertconnector â BOX DRAWINGS LIGHT VERTICAL */
block|{
literal|0x08a7
block|,
literal|0x23a1
block|}
block|,
comment|/*            topleftsqbracket â¡ ??? */
block|{
literal|0x08a8
block|,
literal|0x23a3
block|}
block|,
comment|/*            botleftsqbracket â£ ??? */
block|{
literal|0x08a9
block|,
literal|0x23a4
block|}
block|,
comment|/*           toprightsqbracket â¤ ??? */
block|{
literal|0x08aa
block|,
literal|0x23a6
block|}
block|,
comment|/*           botrightsqbracket â¦ ??? */
block|{
literal|0x08ab
block|,
literal|0x239b
block|}
block|,
comment|/*               topleftparens â ??? */
block|{
literal|0x08ac
block|,
literal|0x239d
block|}
block|,
comment|/*               botleftparens â ??? */
block|{
literal|0x08ad
block|,
literal|0x239e
block|}
block|,
comment|/*              toprightparens â ??? */
block|{
literal|0x08ae
block|,
literal|0x23a0
block|}
block|,
comment|/*              botrightparens â  ??? */
block|{
literal|0x08af
block|,
literal|0x23a8
block|}
block|,
comment|/*        leftmiddlecurlybrace â¨ ??? */
block|{
literal|0x08b0
block|,
literal|0x23ac
block|}
block|,
comment|/*       rightmiddlecurlybrace â¬ ??? */
comment|/*  0x08b1                        topleftsummation ? ??? */
comment|/*  0x08b2                        botleftsummation ? ??? */
comment|/*  0x08b3               topvertsummationconnector ? ??? */
comment|/*  0x08b4               botvertsummationconnector ? ??? */
comment|/*  0x08b5                       toprightsummation ? ??? */
comment|/*  0x08b6                       botrightsummation ? ??? */
comment|/*  0x08b7                    rightmiddlesummation ? ??? */
block|{
literal|0x08bc
block|,
literal|0x2264
block|}
block|,
comment|/*               lessthanequal â¤ LESS-THAN OR EQUAL TO */
block|{
literal|0x08bd
block|,
literal|0x2260
block|}
block|,
comment|/*                    notequal â  NOT EQUAL TO */
block|{
literal|0x08be
block|,
literal|0x2265
block|}
block|,
comment|/*            greaterthanequal â¥ GREATER-THAN OR EQUAL TO */
block|{
literal|0x08bf
block|,
literal|0x222b
block|}
block|,
comment|/*                    integral â« INTEGRAL */
block|{
literal|0x08c0
block|,
literal|0x2234
block|}
block|,
comment|/*                   therefore â´ THEREFORE */
block|{
literal|0x08c1
block|,
literal|0x221d
block|}
block|,
comment|/*                   variation â PROPORTIONAL TO */
block|{
literal|0x08c2
block|,
literal|0x221e
block|}
block|,
comment|/*                    infinity â INFINITY */
block|{
literal|0x08c5
block|,
literal|0x2207
block|}
block|,
comment|/*                       nabla â NABLA */
block|{
literal|0x08c8
block|,
literal|0x223c
block|}
block|,
comment|/*                 approximate â¼ TILDE OPERATOR */
block|{
literal|0x08c9
block|,
literal|0x2243
block|}
block|,
comment|/*                similarequal â ASYMPTOTICALLY EQUAL TO */
block|{
literal|0x08cd
block|,
literal|0x21d4
block|}
block|,
comment|/*                    ifonlyif â LEFT RIGHT DOUBLE ARROW */
block|{
literal|0x08ce
block|,
literal|0x21d2
block|}
block|,
comment|/*                     implies â RIGHTWARDS DOUBLE ARROW */
block|{
literal|0x08cf
block|,
literal|0x2261
block|}
block|,
comment|/*                   identical â¡ IDENTICAL TO */
block|{
literal|0x08d6
block|,
literal|0x221a
block|}
block|,
comment|/*                     radical â SQUARE ROOT */
block|{
literal|0x08da
block|,
literal|0x2282
block|}
block|,
comment|/*                  includedin â SUBSET OF */
block|{
literal|0x08db
block|,
literal|0x2283
block|}
block|,
comment|/*                    includes â SUPERSET OF */
block|{
literal|0x08dc
block|,
literal|0x2229
block|}
block|,
comment|/*                intersection â© INTERSECTION */
block|{
literal|0x08dd
block|,
literal|0x222a
block|}
block|,
comment|/*                       union âª UNION */
block|{
literal|0x08de
block|,
literal|0x2227
block|}
block|,
comment|/*                  logicaland â§ LOGICAL AND */
block|{
literal|0x08df
block|,
literal|0x2228
block|}
block|,
comment|/*                   logicalor â¨ LOGICAL OR */
block|{
literal|0x08ef
block|,
literal|0x2202
block|}
block|,
comment|/*           partialderivative â PARTIAL DIFFERENTIAL */
block|{
literal|0x08f6
block|,
literal|0x0192
block|}
block|,
comment|/*                    function Æ LATIN SMALL LETTER F WITH HOOK */
block|{
literal|0x08fb
block|,
literal|0x2190
block|}
block|,
comment|/*                   leftarrow â LEFTWARDS ARROW */
block|{
literal|0x08fc
block|,
literal|0x2191
block|}
block|,
comment|/*                     uparrow â UPWARDS ARROW */
block|{
literal|0x08fd
block|,
literal|0x2192
block|}
block|,
comment|/*                  rightarrow â RIGHTWARDS ARROW */
block|{
literal|0x08fe
block|,
literal|0x2193
block|}
block|,
comment|/*                   downarrow â DOWNWARDS ARROW */
comment|/*  0x09df                                     blank ? ??? */
block|{
literal|0x09e0
block|,
literal|0x25c6
block|}
block|,
comment|/*                soliddiamond â BLACK DIAMOND */
block|{
literal|0x09e1
block|,
literal|0x2592
block|}
block|,
comment|/*                checkerboard â MEDIUM SHADE */
block|{
literal|0x09e2
block|,
literal|0x2409
block|}
block|,
comment|/*                          ht â SYMBOL FOR HORIZONTAL TABULATION */
block|{
literal|0x09e3
block|,
literal|0x240c
block|}
block|,
comment|/*                          ff â SYMBOL FOR FORM FEED */
block|{
literal|0x09e4
block|,
literal|0x240d
block|}
block|,
comment|/*                          cr â SYMBOL FOR CARRIAGE RETURN */
block|{
literal|0x09e5
block|,
literal|0x240a
block|}
block|,
comment|/*                          lf â SYMBOL FOR LINE FEED */
block|{
literal|0x09e8
block|,
literal|0x2424
block|}
block|,
comment|/*                          nl â¤ SYMBOL FOR NEWLINE */
block|{
literal|0x09e9
block|,
literal|0x240b
block|}
block|,
comment|/*                          vt â SYMBOL FOR VERTICAL TABULATION */
block|{
literal|0x09ea
block|,
literal|0x2518
block|}
block|,
comment|/*              lowrightcorner â BOX DRAWINGS LIGHT UP AND LEFT */
block|{
literal|0x09eb
block|,
literal|0x2510
block|}
block|,
comment|/*               uprightcorner â BOX DRAWINGS LIGHT DOWN AND LEFT */
block|{
literal|0x09ec
block|,
literal|0x250c
block|}
block|,
comment|/*                upleftcorner â BOX DRAWINGS LIGHT DOWN AND RIGHT */
block|{
literal|0x09ed
block|,
literal|0x2514
block|}
block|,
comment|/*               lowleftcorner â BOX DRAWINGS LIGHT UP AND RIGHT */
block|{
literal|0x09ee
block|,
literal|0x253c
block|}
block|,
comment|/*               crossinglines â¼ BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL */
block|{
literal|0x09ef
block|,
literal|0x23ba
block|}
block|,
comment|/*              horizlinescan1 âº HORIZONTAL SCAN LINE-1 (Unicode 3.2 draft) */
block|{
literal|0x09f0
block|,
literal|0x23bb
block|}
block|,
comment|/*              horizlinescan3 â» HORIZONTAL SCAN LINE-3 (Unicode 3.2 draft) */
block|{
literal|0x09f1
block|,
literal|0x2500
block|}
block|,
comment|/*              horizlinescan5 â BOX DRAWINGS LIGHT HORIZONTAL */
block|{
literal|0x09f2
block|,
literal|0x23bc
block|}
block|,
comment|/*              horizlinescan7 â¼ HORIZONTAL SCAN LINE-7 (Unicode 3.2 draft) */
block|{
literal|0x09f3
block|,
literal|0x23bd
block|}
block|,
comment|/*              horizlinescan9 â½ HORIZONTAL SCAN LINE-9 (Unicode 3.2 draft) */
block|{
literal|0x09f4
block|,
literal|0x251c
block|}
block|,
comment|/*                       leftt â BOX DRAWINGS LIGHT VERTICAL AND RIGHT */
block|{
literal|0x09f5
block|,
literal|0x2524
block|}
block|,
comment|/*                      rightt â¤ BOX DRAWINGS LIGHT VERTICAL AND LEFT */
block|{
literal|0x09f6
block|,
literal|0x2534
block|}
block|,
comment|/*                        bott â´ BOX DRAWINGS LIGHT UP AND HORIZONTAL */
block|{
literal|0x09f7
block|,
literal|0x252c
block|}
block|,
comment|/*                        topt â¬ BOX DRAWINGS LIGHT DOWN AND HORIZONTAL */
block|{
literal|0x09f8
block|,
literal|0x2502
block|}
block|,
comment|/*                     vertbar â BOX DRAWINGS LIGHT VERTICAL */
block|{
literal|0x0aa1
block|,
literal|0x2003
block|}
block|,
comment|/*                     emspace â EM SPACE */
block|{
literal|0x0aa2
block|,
literal|0x2002
block|}
block|,
comment|/*                     enspace â EN SPACE */
block|{
literal|0x0aa3
block|,
literal|0x2004
block|}
block|,
comment|/*                    em3space â THREE-PER-EM SPACE */
block|{
literal|0x0aa4
block|,
literal|0x2005
block|}
block|,
comment|/*                    em4space â FOUR-PER-EM SPACE */
block|{
literal|0x0aa5
block|,
literal|0x2007
block|}
block|,
comment|/*                  digitspace â FIGURE SPACE */
block|{
literal|0x0aa6
block|,
literal|0x2008
block|}
block|,
comment|/*                  punctspace â PUNCTUATION SPACE */
block|{
literal|0x0aa7
block|,
literal|0x2009
block|}
block|,
comment|/*                   thinspace â THIN SPACE */
block|{
literal|0x0aa8
block|,
literal|0x200a
block|}
block|,
comment|/*                   hairspace â HAIR SPACE */
block|{
literal|0x0aa9
block|,
literal|0x2014
block|}
block|,
comment|/*                      emdash â EM DASH */
block|{
literal|0x0aaa
block|,
literal|0x2013
block|}
block|,
comment|/*                      endash â EN DASH */
comment|/*  0x0aac                               signifblank ? ??? */
block|{
literal|0x0aae
block|,
literal|0x2026
block|}
block|,
comment|/*                    ellipsis â¦ HORIZONTAL ELLIPSIS */
block|{
literal|0x0aaf
block|,
literal|0x2025
block|}
block|,
comment|/*             doubbaselinedot â¥ TWO DOT LEADER */
block|{
literal|0x0ab0
block|,
literal|0x2153
block|}
block|,
comment|/*                    onethird â VULGAR FRACTION ONE THIRD */
block|{
literal|0x0ab1
block|,
literal|0x2154
block|}
block|,
comment|/*                   twothirds â VULGAR FRACTION TWO THIRDS */
block|{
literal|0x0ab2
block|,
literal|0x2155
block|}
block|,
comment|/*                    onefifth â VULGAR FRACTION ONE FIFTH */
block|{
literal|0x0ab3
block|,
literal|0x2156
block|}
block|,
comment|/*                   twofifths â VULGAR FRACTION TWO FIFTHS */
block|{
literal|0x0ab4
block|,
literal|0x2157
block|}
block|,
comment|/*                 threefifths â VULGAR FRACTION THREE FIFTHS */
block|{
literal|0x0ab5
block|,
literal|0x2158
block|}
block|,
comment|/*                  fourfifths â VULGAR FRACTION FOUR FIFTHS */
block|{
literal|0x0ab6
block|,
literal|0x2159
block|}
block|,
comment|/*                    onesixth â VULGAR FRACTION ONE SIXTH */
block|{
literal|0x0ab7
block|,
literal|0x215a
block|}
block|,
comment|/*                  fivesixths â VULGAR FRACTION FIVE SIXTHS */
block|{
literal|0x0ab8
block|,
literal|0x2105
block|}
block|,
comment|/*                      careof â CARE OF */
block|{
literal|0x0abb
block|,
literal|0x2012
block|}
block|,
comment|/*                     figdash â FIGURE DASH */
block|{
literal|0x0abc
block|,
literal|0x2329
block|}
block|,
comment|/*            leftanglebracket â© LEFT-POINTING ANGLE BRACKET */
block|{
literal|0x0abd
block|,
literal|0x002e
block|}
block|,
comment|/*                decimalpoint . FULL STOP */
block|{
literal|0x0abe
block|,
literal|0x232a
block|}
block|,
comment|/*           rightanglebracket âª RIGHT-POINTING ANGLE BRACKET */
comment|/*  0x0abf                                  marker ? ??? */
block|{
literal|0x0ac3
block|,
literal|0x215b
block|}
block|,
comment|/*                   oneeighth â VULGAR FRACTION ONE EIGHTH */
block|{
literal|0x0ac4
block|,
literal|0x215c
block|}
block|,
comment|/*                threeeighths â VULGAR FRACTION THREE EIGHTHS */
block|{
literal|0x0ac5
block|,
literal|0x215d
block|}
block|,
comment|/*                 fiveeighths â VULGAR FRACTION FIVE EIGHTHS */
block|{
literal|0x0ac6
block|,
literal|0x215e
block|}
block|,
comment|/*                seveneighths â VULGAR FRACTION SEVEN EIGHTHS */
block|{
literal|0x0ac9
block|,
literal|0x2122
block|}
block|,
comment|/*                   trademark â¢ TRADE MARK SIGN */
block|{
literal|0x0aca
block|,
literal|0x2613
block|}
block|,
comment|/*               signaturemark â SALTIRE */
comment|/*  0x0acb                       trademarkincircle ? ??? */
block|{
literal|0x0acc
block|,
literal|0x25c1
block|}
block|,
comment|/*            leftopentriangle â WHITE LEFT-POINTING TRIANGLE */
block|{
literal|0x0acd
block|,
literal|0x25b7
block|}
block|,
comment|/*           rightopentriangle â· WHITE RIGHT-POINTING TRIANGLE */
block|{
literal|0x0ace
block|,
literal|0x25cb
block|}
block|,
comment|/*                emopencircle â WHITE CIRCLE */
block|{
literal|0x0acf
block|,
literal|0x25af
block|}
block|,
comment|/*             emopenrectangle â¯ WHITE VERTICAL RECTANGLE */
block|{
literal|0x0ad0
block|,
literal|0x2018
block|}
block|,
comment|/*         leftsinglequotemark â LEFT SINGLE QUOTATION MARK */
block|{
literal|0x0ad1
block|,
literal|0x2019
block|}
block|,
comment|/*        rightsinglequotemark â RIGHT SINGLE QUOTATION MARK */
block|{
literal|0x0ad2
block|,
literal|0x201c
block|}
block|,
comment|/*         leftdoublequotemark â LEFT DOUBLE QUOTATION MARK */
block|{
literal|0x0ad3
block|,
literal|0x201d
block|}
block|,
comment|/*        rightdoublequotemark â RIGHT DOUBLE QUOTATION MARK */
block|{
literal|0x0ad4
block|,
literal|0x211e
block|}
block|,
comment|/*                prescription â PRESCRIPTION TAKE */
block|{
literal|0x0ad6
block|,
literal|0x2032
block|}
block|,
comment|/*                     minutes â² PRIME */
block|{
literal|0x0ad7
block|,
literal|0x2033
block|}
block|,
comment|/*                     seconds â³ DOUBLE PRIME */
block|{
literal|0x0ad9
block|,
literal|0x271d
block|}
block|,
comment|/*                  latincross â LATIN CROSS */
comment|/*  0x0ada                                hexagram ? ??? */
block|{
literal|0x0adb
block|,
literal|0x25ac
block|}
block|,
comment|/*            filledrectbullet â¬ BLACK RECTANGLE */
block|{
literal|0x0adc
block|,
literal|0x25c0
block|}
block|,
comment|/*         filledlefttribullet â BLACK LEFT-POINTING TRIANGLE */
block|{
literal|0x0add
block|,
literal|0x25b6
block|}
block|,
comment|/*        filledrighttribullet â¶ BLACK RIGHT-POINTING TRIANGLE */
block|{
literal|0x0ade
block|,
literal|0x25cf
block|}
block|,
comment|/*              emfilledcircle â BLACK CIRCLE */
block|{
literal|0x0adf
block|,
literal|0x25ae
block|}
block|,
comment|/*                emfilledrect â® BLACK VERTICAL RECTANGLE */
block|{
literal|0x0ae0
block|,
literal|0x25e6
block|}
block|,
comment|/*            enopencircbullet â¦ WHITE BULLET */
block|{
literal|0x0ae1
block|,
literal|0x25ab
block|}
block|,
comment|/*          enopensquarebullet â« WHITE SMALL SQUARE */
block|{
literal|0x0ae2
block|,
literal|0x25ad
block|}
block|,
comment|/*              openrectbullet â­ WHITE RECTANGLE */
block|{
literal|0x0ae3
block|,
literal|0x25b3
block|}
block|,
comment|/*             opentribulletup â³ WHITE UP-POINTING TRIANGLE */
block|{
literal|0x0ae4
block|,
literal|0x25bd
block|}
block|,
comment|/*           opentribulletdown â½ WHITE DOWN-POINTING TRIANGLE */
block|{
literal|0x0ae5
block|,
literal|0x2606
block|}
block|,
comment|/*                    openstar â WHITE STAR */
block|{
literal|0x0ae6
block|,
literal|0x2022
block|}
block|,
comment|/*          enfilledcircbullet â¢ BULLET */
block|{
literal|0x0ae7
block|,
literal|0x25aa
block|}
block|,
comment|/*            enfilledsqbullet âª BLACK SMALL SQUARE */
block|{
literal|0x0ae8
block|,
literal|0x25b2
block|}
block|,
comment|/*           filledtribulletup â² BLACK UP-POINTING TRIANGLE */
block|{
literal|0x0ae9
block|,
literal|0x25bc
block|}
block|,
comment|/*         filledtribulletdown â¼ BLACK DOWN-POINTING TRIANGLE */
block|{
literal|0x0aea
block|,
literal|0x261c
block|}
block|,
comment|/*                 leftpointer â WHITE LEFT POINTING INDEX */
block|{
literal|0x0aeb
block|,
literal|0x261e
block|}
block|,
comment|/*                rightpointer â WHITE RIGHT POINTING INDEX */
block|{
literal|0x0aec
block|,
literal|0x2663
block|}
block|,
comment|/*                        club â£ BLACK CLUB SUIT */
block|{
literal|0x0aed
block|,
literal|0x2666
block|}
block|,
comment|/*                     diamond â¦ BLACK DIAMOND SUIT */
block|{
literal|0x0aee
block|,
literal|0x2665
block|}
block|,
comment|/*                       heart â¥ BLACK HEART SUIT */
block|{
literal|0x0af0
block|,
literal|0x2720
block|}
block|,
comment|/*                maltesecross â  MALTESE CROSS */
block|{
literal|0x0af1
block|,
literal|0x2020
block|}
block|,
comment|/*                      dagger â  DAGGER */
block|{
literal|0x0af2
block|,
literal|0x2021
block|}
block|,
comment|/*                doubledagger â¡ DOUBLE DAGGER */
block|{
literal|0x0af3
block|,
literal|0x2713
block|}
block|,
comment|/*                   checkmark â CHECK MARK */
block|{
literal|0x0af4
block|,
literal|0x2717
block|}
block|,
comment|/*                 ballotcross â BALLOT X */
block|{
literal|0x0af5
block|,
literal|0x266f
block|}
block|,
comment|/*                musicalsharp â¯ MUSIC SHARP SIGN */
block|{
literal|0x0af6
block|,
literal|0x266d
block|}
block|,
comment|/*                 musicalflat â­ MUSIC FLAT SIGN */
block|{
literal|0x0af7
block|,
literal|0x2642
block|}
block|,
comment|/*                  malesymbol â MALE SIGN */
block|{
literal|0x0af8
block|,
literal|0x2640
block|}
block|,
comment|/*                femalesymbol â FEMALE SIGN */
block|{
literal|0x0af9
block|,
literal|0x260e
block|}
block|,
comment|/*                   telephone â BLACK TELEPHONE */
block|{
literal|0x0afa
block|,
literal|0x2315
block|}
block|,
comment|/*           telephonerecorder â TELEPHONE RECORDER */
block|{
literal|0x0afb
block|,
literal|0x2117
block|}
block|,
comment|/*         phonographcopyright â SOUND RECORDING COPYRIGHT */
block|{
literal|0x0afc
block|,
literal|0x2038
block|}
block|,
comment|/*                       caret â¸ CARET */
block|{
literal|0x0afd
block|,
literal|0x201a
block|}
block|,
comment|/*          singlelowquotemark â SINGLE LOW-9 QUOTATION MARK */
block|{
literal|0x0afe
block|,
literal|0x201e
block|}
block|,
comment|/*          doublelowquotemark â DOUBLE LOW-9 QUOTATION MARK */
comment|/*  0x0aff                                  cursor ? ??? */
block|{
literal|0x0ba3
block|,
literal|0x003c
block|}
block|,
comment|/*                   leftcaret< LESS-THAN SIGN */
block|{
literal|0x0ba6
block|,
literal|0x003e
block|}
block|,
comment|/*                  rightcaret> GREATER-THAN SIGN */
block|{
literal|0x0ba8
block|,
literal|0x2228
block|}
block|,
comment|/*                   downcaret â¨ LOGICAL OR */
block|{
literal|0x0ba9
block|,
literal|0x2227
block|}
block|,
comment|/*                     upcaret â§ LOGICAL AND */
block|{
literal|0x0bc0
block|,
literal|0x00af
block|}
block|,
comment|/*                     overbar Â¯ MACRON */
block|{
literal|0x0bc2
block|,
literal|0x22a4
block|}
block|,
comment|/*                    downtack â¤ DOWN TACK */
block|{
literal|0x0bc3
block|,
literal|0x2229
block|}
block|,
comment|/*                      upshoe â© INTERSECTION */
block|{
literal|0x0bc4
block|,
literal|0x230a
block|}
block|,
comment|/*                   downstile â LEFT FLOOR */
block|{
literal|0x0bc6
block|,
literal|0x005f
block|}
block|,
comment|/*                    underbar _ LOW LINE */
block|{
literal|0x0bca
block|,
literal|0x2218
block|}
block|,
comment|/*                         jot â RING OPERATOR */
block|{
literal|0x0bcc
block|,
literal|0x2395
block|}
block|,
comment|/*                        quad â APL FUNCTIONAL SYMBOL QUAD (Unicode 3.0) */
block|{
literal|0x0bce
block|,
literal|0x22a5
block|}
block|,
comment|/*                      uptack â¥ UP TACK */
block|{
literal|0x0bcf
block|,
literal|0x25cb
block|}
block|,
comment|/*                      circle â WHITE CIRCLE */
block|{
literal|0x0bd3
block|,
literal|0x2308
block|}
block|,
comment|/*                     upstile â LEFT CEILING */
block|{
literal|0x0bd6
block|,
literal|0x222a
block|}
block|,
comment|/*                    downshoe âª UNION */
block|{
literal|0x0bd8
block|,
literal|0x2283
block|}
block|,
comment|/*                   rightshoe â SUPERSET OF */
block|{
literal|0x0bda
block|,
literal|0x2282
block|}
block|,
comment|/*                    leftshoe â SUBSET OF */
block|{
literal|0x0bdc
block|,
literal|0x22a2
block|}
block|,
comment|/*                    lefttack â¢ RIGHT TACK */
block|{
literal|0x0bfc
block|,
literal|0x22a3
block|}
block|,
comment|/*                   righttack â£ LEFT TACK */
block|{
literal|0x0cdf
block|,
literal|0x2017
block|}
block|,
comment|/*        hebrew_doublelowline â DOUBLE LOW LINE */
block|{
literal|0x0ce0
block|,
literal|0x05d0
block|}
block|,
comment|/*                hebrew_aleph × HEBREW LETTER ALEF */
block|{
literal|0x0ce1
block|,
literal|0x05d1
block|}
block|,
comment|/*                  hebrew_bet × HEBREW LETTER BET */
block|{
literal|0x0ce2
block|,
literal|0x05d2
block|}
block|,
comment|/*                hebrew_gimel × HEBREW LETTER GIMEL */
block|{
literal|0x0ce3
block|,
literal|0x05d3
block|}
block|,
comment|/*                hebrew_dalet × HEBREW LETTER DALET */
block|{
literal|0x0ce4
block|,
literal|0x05d4
block|}
block|,
comment|/*                   hebrew_he × HEBREW LETTER HE */
block|{
literal|0x0ce5
block|,
literal|0x05d5
block|}
block|,
comment|/*                  hebrew_waw × HEBREW LETTER VAV */
block|{
literal|0x0ce6
block|,
literal|0x05d6
block|}
block|,
comment|/*                 hebrew_zain × HEBREW LETTER ZAYIN */
block|{
literal|0x0ce7
block|,
literal|0x05d7
block|}
block|,
comment|/*                 hebrew_chet × HEBREW LETTER HET */
block|{
literal|0x0ce8
block|,
literal|0x05d8
block|}
block|,
comment|/*                  hebrew_tet × HEBREW LETTER TET */
block|{
literal|0x0ce9
block|,
literal|0x05d9
block|}
block|,
comment|/*                  hebrew_yod × HEBREW LETTER YOD */
block|{
literal|0x0cea
block|,
literal|0x05da
block|}
block|,
comment|/*            hebrew_finalkaph × HEBREW LETTER FINAL KAF */
block|{
literal|0x0ceb
block|,
literal|0x05db
block|}
block|,
comment|/*                 hebrew_kaph × HEBREW LETTER KAF */
block|{
literal|0x0cec
block|,
literal|0x05dc
block|}
block|,
comment|/*                hebrew_lamed × HEBREW LETTER LAMED */
block|{
literal|0x0ced
block|,
literal|0x05dd
block|}
block|,
comment|/*             hebrew_finalmem × HEBREW LETTER FINAL MEM */
block|{
literal|0x0cee
block|,
literal|0x05de
block|}
block|,
comment|/*                  hebrew_mem × HEBREW LETTER MEM */
block|{
literal|0x0cef
block|,
literal|0x05df
block|}
block|,
comment|/*             hebrew_finalnun × HEBREW LETTER FINAL NUN */
block|{
literal|0x0cf0
block|,
literal|0x05e0
block|}
block|,
comment|/*                  hebrew_nun ×  HEBREW LETTER NUN */
block|{
literal|0x0cf1
block|,
literal|0x05e1
block|}
block|,
comment|/*               hebrew_samech ×¡ HEBREW LETTER SAMEKH */
block|{
literal|0x0cf2
block|,
literal|0x05e2
block|}
block|,
comment|/*                 hebrew_ayin ×¢ HEBREW LETTER AYIN */
block|{
literal|0x0cf3
block|,
literal|0x05e3
block|}
block|,
comment|/*              hebrew_finalpe ×£ HEBREW LETTER FINAL PE */
block|{
literal|0x0cf4
block|,
literal|0x05e4
block|}
block|,
comment|/*                   hebrew_pe ×¤ HEBREW LETTER PE */
block|{
literal|0x0cf5
block|,
literal|0x05e5
block|}
block|,
comment|/*            hebrew_finalzade ×¥ HEBREW LETTER FINAL TSADI */
block|{
literal|0x0cf6
block|,
literal|0x05e6
block|}
block|,
comment|/*                 hebrew_zade ×¦ HEBREW LETTER TSADI */
block|{
literal|0x0cf7
block|,
literal|0x05e7
block|}
block|,
comment|/*                 hebrew_qoph ×§ HEBREW LETTER QOF */
block|{
literal|0x0cf8
block|,
literal|0x05e8
block|}
block|,
comment|/*                 hebrew_resh ×¨ HEBREW LETTER RESH */
block|{
literal|0x0cf9
block|,
literal|0x05e9
block|}
block|,
comment|/*                 hebrew_shin ×© HEBREW LETTER SHIN */
block|{
literal|0x0cfa
block|,
literal|0x05ea
block|}
block|,
comment|/*                  hebrew_taw ×ª HEBREW LETTER TAV */
block|{
literal|0x0da1
block|,
literal|0x0e01
block|}
block|,
comment|/*                  Thai_kokai à¸ THAI CHARACTER KO KAI */
block|{
literal|0x0da2
block|,
literal|0x0e02
block|}
block|,
comment|/*                Thai_khokhai à¸ THAI CHARACTER KHO KHAI */
block|{
literal|0x0da3
block|,
literal|0x0e03
block|}
block|,
comment|/*               Thai_khokhuat à¸ THAI CHARACTER KHO KHUAT */
block|{
literal|0x0da4
block|,
literal|0x0e04
block|}
block|,
comment|/*               Thai_khokhwai à¸ THAI CHARACTER KHO KHWAI */
block|{
literal|0x0da5
block|,
literal|0x0e05
block|}
block|,
comment|/*                Thai_khokhon à¸ THAI CHARACTER KHO KHON */
block|{
literal|0x0da6
block|,
literal|0x0e06
block|}
block|,
comment|/*             Thai_khorakhang à¸ THAI CHARACTER KHO RAKHANG */
block|{
literal|0x0da7
block|,
literal|0x0e07
block|}
block|,
comment|/*                 Thai_ngongu à¸ THAI CHARACTER NGO NGU */
block|{
literal|0x0da8
block|,
literal|0x0e08
block|}
block|,
comment|/*                Thai_chochan à¸ THAI CHARACTER CHO CHAN */
block|{
literal|0x0da9
block|,
literal|0x0e09
block|}
block|,
comment|/*               Thai_choching à¸ THAI CHARACTER CHO CHING */
block|{
literal|0x0daa
block|,
literal|0x0e0a
block|}
block|,
comment|/*               Thai_chochang à¸ THAI CHARACTER CHO CHANG */
block|{
literal|0x0dab
block|,
literal|0x0e0b
block|}
block|,
comment|/*                   Thai_soso à¸ THAI CHARACTER SO SO */
block|{
literal|0x0dac
block|,
literal|0x0e0c
block|}
block|,
comment|/*                Thai_chochoe à¸ THAI CHARACTER CHO CHOE */
block|{
literal|0x0dad
block|,
literal|0x0e0d
block|}
block|,
comment|/*                 Thai_yoying à¸ THAI CHARACTER YO YING */
block|{
literal|0x0dae
block|,
literal|0x0e0e
block|}
block|,
comment|/*                Thai_dochada à¸ THAI CHARACTER DO CHADA */
block|{
literal|0x0daf
block|,
literal|0x0e0f
block|}
block|,
comment|/*                Thai_topatak à¸ THAI CHARACTER TO PATAK */
block|{
literal|0x0db0
block|,
literal|0x0e10
block|}
block|,
comment|/*                Thai_thothan à¸ THAI CHARACTER THO THAN */
block|{
literal|0x0db1
block|,
literal|0x0e11
block|}
block|,
comment|/*          Thai_thonangmontho à¸ THAI CHARACTER THO NANGMONTHO */
block|{
literal|0x0db2
block|,
literal|0x0e12
block|}
block|,
comment|/*             Thai_thophuthao à¸ THAI CHARACTER THO PHUTHAO */
block|{
literal|0x0db3
block|,
literal|0x0e13
block|}
block|,
comment|/*                  Thai_nonen à¸ THAI CHARACTER NO NEN */
block|{
literal|0x0db4
block|,
literal|0x0e14
block|}
block|,
comment|/*                  Thai_dodek à¸ THAI CHARACTER DO DEK */
block|{
literal|0x0db5
block|,
literal|0x0e15
block|}
block|,
comment|/*                  Thai_totao à¸ THAI CHARACTER TO TAO */
block|{
literal|0x0db6
block|,
literal|0x0e16
block|}
block|,
comment|/*               Thai_thothung à¸ THAI CHARACTER THO THUNG */
block|{
literal|0x0db7
block|,
literal|0x0e17
block|}
block|,
comment|/*              Thai_thothahan à¸ THAI CHARACTER THO THAHAN */
block|{
literal|0x0db8
block|,
literal|0x0e18
block|}
block|,
comment|/*               Thai_thothong à¸ THAI CHARACTER THO THONG */
block|{
literal|0x0db9
block|,
literal|0x0e19
block|}
block|,
comment|/*                   Thai_nonu à¸ THAI CHARACTER NO NU */
block|{
literal|0x0dba
block|,
literal|0x0e1a
block|}
block|,
comment|/*               Thai_bobaimai à¸ THAI CHARACTER BO BAIMAI */
block|{
literal|0x0dbb
block|,
literal|0x0e1b
block|}
block|,
comment|/*                  Thai_popla à¸ THAI CHARACTER PO PLA */
block|{
literal|0x0dbc
block|,
literal|0x0e1c
block|}
block|,
comment|/*               Thai_phophung à¸ THAI CHARACTER PHO PHUNG */
block|{
literal|0x0dbd
block|,
literal|0x0e1d
block|}
block|,
comment|/*                   Thai_fofa à¸ THAI CHARACTER FO FA */
block|{
literal|0x0dbe
block|,
literal|0x0e1e
block|}
block|,
comment|/*                Thai_phophan à¸ THAI CHARACTER PHO PHAN */
block|{
literal|0x0dbf
block|,
literal|0x0e1f
block|}
block|,
comment|/*                  Thai_fofan à¸ THAI CHARACTER FO FAN */
block|{
literal|0x0dc0
block|,
literal|0x0e20
block|}
block|,
comment|/*             Thai_phosamphao à¸  THAI CHARACTER PHO SAMPHAO */
block|{
literal|0x0dc1
block|,
literal|0x0e21
block|}
block|,
comment|/*                   Thai_moma à¸¡ THAI CHARACTER MO MA */
block|{
literal|0x0dc2
block|,
literal|0x0e22
block|}
block|,
comment|/*                  Thai_yoyak à¸¢ THAI CHARACTER YO YAK */
block|{
literal|0x0dc3
block|,
literal|0x0e23
block|}
block|,
comment|/*                  Thai_rorua à¸£ THAI CHARACTER RO RUA */
block|{
literal|0x0dc4
block|,
literal|0x0e24
block|}
block|,
comment|/*                     Thai_ru à¸¤ THAI CHARACTER RU */
block|{
literal|0x0dc5
block|,
literal|0x0e25
block|}
block|,
comment|/*                 Thai_loling à¸¥ THAI CHARACTER LO LING */
block|{
literal|0x0dc6
block|,
literal|0x0e26
block|}
block|,
comment|/*                     Thai_lu à¸¦ THAI CHARACTER LU */
block|{
literal|0x0dc7
block|,
literal|0x0e27
block|}
block|,
comment|/*                 Thai_wowaen à¸§ THAI CHARACTER WO WAEN */
block|{
literal|0x0dc8
block|,
literal|0x0e28
block|}
block|,
comment|/*                 Thai_sosala à¸¨ THAI CHARACTER SO SALA */
block|{
literal|0x0dc9
block|,
literal|0x0e29
block|}
block|,
comment|/*                 Thai_sorusi à¸© THAI CHARACTER SO RUSI */
block|{
literal|0x0dca
block|,
literal|0x0e2a
block|}
block|,
comment|/*                  Thai_sosua à¸ª THAI CHARACTER SO SUA */
block|{
literal|0x0dcb
block|,
literal|0x0e2b
block|}
block|,
comment|/*                  Thai_hohip à¸« THAI CHARACTER HO HIP */
block|{
literal|0x0dcc
block|,
literal|0x0e2c
block|}
block|,
comment|/*                Thai_lochula à¸¬ THAI CHARACTER LO CHULA */
block|{
literal|0x0dcd
block|,
literal|0x0e2d
block|}
block|,
comment|/*                   Thai_oang à¸­ THAI CHARACTER O ANG */
block|{
literal|0x0dce
block|,
literal|0x0e2e
block|}
block|,
comment|/*               Thai_honokhuk à¸® THAI CHARACTER HO NOKHUK */
block|{
literal|0x0dcf
block|,
literal|0x0e2f
block|}
block|,
comment|/*              Thai_paiyannoi à¸¯ THAI CHARACTER PAIYANNOI */
block|{
literal|0x0dd0
block|,
literal|0x0e30
block|}
block|,
comment|/*                  Thai_saraa à¸° THAI CHARACTER SARA A */
block|{
literal|0x0dd1
block|,
literal|0x0e31
block|}
block|,
comment|/*             Thai_maihanakat à¸± THAI CHARACTER MAI HAN-AKAT */
block|{
literal|0x0dd2
block|,
literal|0x0e32
block|}
block|,
comment|/*                 Thai_saraaa à¸² THAI CHARACTER SARA AA */
block|{
literal|0x0dd3
block|,
literal|0x0e33
block|}
block|,
comment|/*                 Thai_saraam à¸³ THAI CHARACTER SARA AM */
block|{
literal|0x0dd4
block|,
literal|0x0e34
block|}
block|,
comment|/*                  Thai_sarai à¸´ THAI CHARACTER SARA I */
block|{
literal|0x0dd5
block|,
literal|0x0e35
block|}
block|,
comment|/*                 Thai_saraii à¸µ THAI CHARACTER SARA II */
block|{
literal|0x0dd6
block|,
literal|0x0e36
block|}
block|,
comment|/*                 Thai_saraue à¸¶ THAI CHARACTER SARA UE */
block|{
literal|0x0dd7
block|,
literal|0x0e37
block|}
block|,
comment|/*                Thai_sarauee à¸· THAI CHARACTER SARA UEE */
block|{
literal|0x0dd8
block|,
literal|0x0e38
block|}
block|,
comment|/*                  Thai_sarau à¸¸ THAI CHARACTER SARA U */
block|{
literal|0x0dd9
block|,
literal|0x0e39
block|}
block|,
comment|/*                 Thai_sarauu à¸¹ THAI CHARACTER SARA UU */
block|{
literal|0x0dda
block|,
literal|0x0e3a
block|}
block|,
comment|/*                Thai_phinthu à¸º THAI CHARACTER PHINTHU */
block|{
literal|0x0dde
block|,
literal|0x0e3e
block|}
block|,
comment|/*      Thai_maihanakat_maitho à¸¾ ??? */
block|{
literal|0x0ddf
block|,
literal|0x0e3f
block|}
block|,
comment|/*                   Thai_baht à¸¿ THAI CURRENCY SYMBOL BAHT */
block|{
literal|0x0de0
block|,
literal|0x0e40
block|}
block|,
comment|/*                  Thai_sarae à¹ THAI CHARACTER SARA E */
block|{
literal|0x0de1
block|,
literal|0x0e41
block|}
block|,
comment|/*                 Thai_saraae à¹ THAI CHARACTER SARA AE */
block|{
literal|0x0de2
block|,
literal|0x0e42
block|}
block|,
comment|/*                  Thai_sarao à¹ THAI CHARACTER SARA O */
block|{
literal|0x0de3
block|,
literal|0x0e43
block|}
block|,
comment|/*          Thai_saraaimaimuan à¹ THAI CHARACTER SARA AI MAIMUAN */
block|{
literal|0x0de4
block|,
literal|0x0e44
block|}
block|,
comment|/*         Thai_saraaimaimalai à¹ THAI CHARACTER SARA AI MAIMALAI */
block|{
literal|0x0de5
block|,
literal|0x0e45
block|}
block|,
comment|/*            Thai_lakkhangyao à¹ THAI CHARACTER LAKKHANGYAO */
block|{
literal|0x0de6
block|,
literal|0x0e46
block|}
block|,
comment|/*               Thai_maiyamok à¹ THAI CHARACTER MAIYAMOK */
block|{
literal|0x0de7
block|,
literal|0x0e47
block|}
block|,
comment|/*              Thai_maitaikhu à¹ THAI CHARACTER MAITAIKHU */
block|{
literal|0x0de8
block|,
literal|0x0e48
block|}
block|,
comment|/*                  Thai_maiek à¹ THAI CHARACTER MAI EK */
block|{
literal|0x0de9
block|,
literal|0x0e49
block|}
block|,
comment|/*                 Thai_maitho à¹ THAI CHARACTER MAI THO */
block|{
literal|0x0dea
block|,
literal|0x0e4a
block|}
block|,
comment|/*                 Thai_maitri à¹ THAI CHARACTER MAI TRI */
block|{
literal|0x0deb
block|,
literal|0x0e4b
block|}
block|,
comment|/*            Thai_maichattawa à¹ THAI CHARACTER MAI CHATTAWA */
block|{
literal|0x0dec
block|,
literal|0x0e4c
block|}
block|,
comment|/*            Thai_thanthakhat à¹ THAI CHARACTER THANTHAKHAT */
block|{
literal|0x0ded
block|,
literal|0x0e4d
block|}
block|,
comment|/*               Thai_nikhahit à¹ THAI CHARACTER NIKHAHIT */
block|{
literal|0x0df0
block|,
literal|0x0e50
block|}
block|,
comment|/*                 Thai_leksun à¹ THAI DIGIT ZERO */
block|{
literal|0x0df1
block|,
literal|0x0e51
block|}
block|,
comment|/*                Thai_leknung à¹ THAI DIGIT ONE */
block|{
literal|0x0df2
block|,
literal|0x0e52
block|}
block|,
comment|/*                Thai_leksong à¹ THAI DIGIT TWO */
block|{
literal|0x0df3
block|,
literal|0x0e53
block|}
block|,
comment|/*                 Thai_leksam à¹ THAI DIGIT THREE */
block|{
literal|0x0df4
block|,
literal|0x0e54
block|}
block|,
comment|/*                  Thai_leksi à¹ THAI DIGIT FOUR */
block|{
literal|0x0df5
block|,
literal|0x0e55
block|}
block|,
comment|/*                  Thai_lekha à¹ THAI DIGIT FIVE */
block|{
literal|0x0df6
block|,
literal|0x0e56
block|}
block|,
comment|/*                 Thai_lekhok à¹ THAI DIGIT SIX */
block|{
literal|0x0df7
block|,
literal|0x0e57
block|}
block|,
comment|/*                Thai_lekchet à¹ THAI DIGIT SEVEN */
block|{
literal|0x0df8
block|,
literal|0x0e58
block|}
block|,
comment|/*                Thai_lekpaet à¹ THAI DIGIT EIGHT */
block|{
literal|0x0df9
block|,
literal|0x0e59
block|}
block|,
comment|/*                 Thai_lekkao à¹ THAI DIGIT NINE */
block|{
literal|0x0ea1
block|,
literal|0x3131
block|}
block|,
comment|/*               Hangul_Kiyeog ã± HANGUL LETTER KIYEOK */
block|{
literal|0x0ea2
block|,
literal|0x3132
block|}
block|,
comment|/*          Hangul_SsangKiyeog ã² HANGUL LETTER SSANGKIYEOK */
block|{
literal|0x0ea3
block|,
literal|0x3133
block|}
block|,
comment|/*           Hangul_KiyeogSios ã³ HANGUL LETTER KIYEOK-SIOS */
block|{
literal|0x0ea4
block|,
literal|0x3134
block|}
block|,
comment|/*                Hangul_Nieun ã´ HANGUL LETTER NIEUN */
block|{
literal|0x0ea5
block|,
literal|0x3135
block|}
block|,
comment|/*           Hangul_NieunJieuj ãµ HANGUL LETTER NIEUN-CIEUC */
block|{
literal|0x0ea6
block|,
literal|0x3136
block|}
block|,
comment|/*           Hangul_NieunHieuh ã¶ HANGUL LETTER NIEUN-HIEUH */
block|{
literal|0x0ea7
block|,
literal|0x3137
block|}
block|,
comment|/*               Hangul_Dikeud ã· HANGUL LETTER TIKEUT */
block|{
literal|0x0ea8
block|,
literal|0x3138
block|}
block|,
comment|/*          Hangul_SsangDikeud ã¸ HANGUL LETTER SSANGTIKEUT */
block|{
literal|0x0ea9
block|,
literal|0x3139
block|}
block|,
comment|/*                Hangul_Rieul ã¹ HANGUL LETTER RIEUL */
block|{
literal|0x0eaa
block|,
literal|0x313a
block|}
block|,
comment|/*          Hangul_RieulKiyeog ãº HANGUL LETTER RIEUL-KIYEOK */
block|{
literal|0x0eab
block|,
literal|0x313b
block|}
block|,
comment|/*           Hangul_RieulMieum ã» HANGUL LETTER RIEUL-MIEUM */
block|{
literal|0x0eac
block|,
literal|0x313c
block|}
block|,
comment|/*           Hangul_RieulPieub ã¼ HANGUL LETTER RIEUL-PIEUP */
block|{
literal|0x0ead
block|,
literal|0x313d
block|}
block|,
comment|/*            Hangul_RieulSios ã½ HANGUL LETTER RIEUL-SIOS */
block|{
literal|0x0eae
block|,
literal|0x313e
block|}
block|,
comment|/*           Hangul_RieulTieut ã¾ HANGUL LETTER RIEUL-THIEUTH */
block|{
literal|0x0eaf
block|,
literal|0x313f
block|}
block|,
comment|/*          Hangul_RieulPhieuf ã¿ HANGUL LETTER RIEUL-PHIEUPH */
block|{
literal|0x0eb0
block|,
literal|0x3140
block|}
block|,
comment|/*           Hangul_RieulHieuh ã HANGUL LETTER RIEUL-HIEUH */
block|{
literal|0x0eb1
block|,
literal|0x3141
block|}
block|,
comment|/*                Hangul_Mieum ã HANGUL LETTER MIEUM */
block|{
literal|0x0eb2
block|,
literal|0x3142
block|}
block|,
comment|/*                Hangul_Pieub ã HANGUL LETTER PIEUP */
block|{
literal|0x0eb3
block|,
literal|0x3143
block|}
block|,
comment|/*           Hangul_SsangPieub ã HANGUL LETTER SSANGPIEUP */
block|{
literal|0x0eb4
block|,
literal|0x3144
block|}
block|,
comment|/*            Hangul_PieubSios ã HANGUL LETTER PIEUP-SIOS */
block|{
literal|0x0eb5
block|,
literal|0x3145
block|}
block|,
comment|/*                 Hangul_Sios ã HANGUL LETTER SIOS */
block|{
literal|0x0eb6
block|,
literal|0x3146
block|}
block|,
comment|/*            Hangul_SsangSios ã HANGUL LETTER SSANGSIOS */
block|{
literal|0x0eb7
block|,
literal|0x3147
block|}
block|,
comment|/*                Hangul_Ieung ã HANGUL LETTER IEUNG */
block|{
literal|0x0eb8
block|,
literal|0x3148
block|}
block|,
comment|/*                Hangul_Jieuj ã HANGUL LETTER CIEUC */
block|{
literal|0x0eb9
block|,
literal|0x3149
block|}
block|,
comment|/*           Hangul_SsangJieuj ã HANGUL LETTER SSANGCIEUC */
block|{
literal|0x0eba
block|,
literal|0x314a
block|}
block|,
comment|/*                Hangul_Cieuc ã HANGUL LETTER CHIEUCH */
block|{
literal|0x0ebb
block|,
literal|0x314b
block|}
block|,
comment|/*               Hangul_Khieuq ã HANGUL LETTER KHIEUKH */
block|{
literal|0x0ebc
block|,
literal|0x314c
block|}
block|,
comment|/*                Hangul_Tieut ã HANGUL LETTER THIEUTH */
block|{
literal|0x0ebd
block|,
literal|0x314d
block|}
block|,
comment|/*               Hangul_Phieuf ã HANGUL LETTER PHIEUPH */
block|{
literal|0x0ebe
block|,
literal|0x314e
block|}
block|,
comment|/*                Hangul_Hieuh ã HANGUL LETTER HIEUH */
block|{
literal|0x0ebf
block|,
literal|0x314f
block|}
block|,
comment|/*                    Hangul_A ã HANGUL LETTER A */
block|{
literal|0x0ec0
block|,
literal|0x3150
block|}
block|,
comment|/*                   Hangul_AE ã HANGUL LETTER AE */
block|{
literal|0x0ec1
block|,
literal|0x3151
block|}
block|,
comment|/*                   Hangul_YA ã HANGUL LETTER YA */
block|{
literal|0x0ec2
block|,
literal|0x3152
block|}
block|,
comment|/*                  Hangul_YAE ã HANGUL LETTER YAE */
block|{
literal|0x0ec3
block|,
literal|0x3153
block|}
block|,
comment|/*                   Hangul_EO ã HANGUL LETTER EO */
block|{
literal|0x0ec4
block|,
literal|0x3154
block|}
block|,
comment|/*                    Hangul_E ã HANGUL LETTER E */
block|{
literal|0x0ec5
block|,
literal|0x3155
block|}
block|,
comment|/*                  Hangul_YEO ã HANGUL LETTER YEO */
block|{
literal|0x0ec6
block|,
literal|0x3156
block|}
block|,
comment|/*                   Hangul_YE ã HANGUL LETTER YE */
block|{
literal|0x0ec7
block|,
literal|0x3157
block|}
block|,
comment|/*                    Hangul_O ã HANGUL LETTER O */
block|{
literal|0x0ec8
block|,
literal|0x3158
block|}
block|,
comment|/*                   Hangul_WA ã HANGUL LETTER WA */
block|{
literal|0x0ec9
block|,
literal|0x3159
block|}
block|,
comment|/*                  Hangul_WAE ã HANGUL LETTER WAE */
block|{
literal|0x0eca
block|,
literal|0x315a
block|}
block|,
comment|/*                   Hangul_OE ã HANGUL LETTER OE */
block|{
literal|0x0ecb
block|,
literal|0x315b
block|}
block|,
comment|/*                   Hangul_YO ã HANGUL LETTER YO */
block|{
literal|0x0ecc
block|,
literal|0x315c
block|}
block|,
comment|/*                    Hangul_U ã HANGUL LETTER U */
block|{
literal|0x0ecd
block|,
literal|0x315d
block|}
block|,
comment|/*                  Hangul_WEO ã HANGUL LETTER WEO */
block|{
literal|0x0ece
block|,
literal|0x315e
block|}
block|,
comment|/*                   Hangul_WE ã HANGUL LETTER WE */
block|{
literal|0x0ecf
block|,
literal|0x315f
block|}
block|,
comment|/*                   Hangul_WI ã HANGUL LETTER WI */
block|{
literal|0x0ed0
block|,
literal|0x3160
block|}
block|,
comment|/*                   Hangul_YU ã  HANGUL LETTER YU */
block|{
literal|0x0ed1
block|,
literal|0x3161
block|}
block|,
comment|/*                   Hangul_EU ã¡ HANGUL LETTER EU */
block|{
literal|0x0ed2
block|,
literal|0x3162
block|}
block|,
comment|/*                   Hangul_YI ã¢ HANGUL LETTER YI */
block|{
literal|0x0ed3
block|,
literal|0x3163
block|}
block|,
comment|/*                    Hangul_I ã£ HANGUL LETTER I */
block|{
literal|0x0ed4
block|,
literal|0x11a8
block|}
block|,
comment|/*             Hangul_J_Kiyeog á¨ HANGUL JONGSEONG KIYEOK */
block|{
literal|0x0ed5
block|,
literal|0x11a9
block|}
block|,
comment|/*        Hangul_J_SsangKiyeog á© HANGUL JONGSEONG SSANGKIYEOK */
block|{
literal|0x0ed6
block|,
literal|0x11aa
block|}
block|,
comment|/*         Hangul_J_KiyeogSios áª HANGUL JONGSEONG KIYEOK-SIOS */
block|{
literal|0x0ed7
block|,
literal|0x11ab
block|}
block|,
comment|/*              Hangul_J_Nieun á« HANGUL JONGSEONG NIEUN */
block|{
literal|0x0ed8
block|,
literal|0x11ac
block|}
block|,
comment|/*         Hangul_J_NieunJieuj á¬ HANGUL JONGSEONG NIEUN-CIEUC */
block|{
literal|0x0ed9
block|,
literal|0x11ad
block|}
block|,
comment|/*         Hangul_J_NieunHieuh á­ HANGUL JONGSEONG NIEUN-HIEUH */
block|{
literal|0x0eda
block|,
literal|0x11ae
block|}
block|,
comment|/*             Hangul_J_Dikeud á® HANGUL JONGSEONG TIKEUT */
block|{
literal|0x0edb
block|,
literal|0x11af
block|}
block|,
comment|/*              Hangul_J_Rieul á¯ HANGUL JONGSEONG RIEUL */
block|{
literal|0x0edc
block|,
literal|0x11b0
block|}
block|,
comment|/*        Hangul_J_RieulKiyeog á° HANGUL JONGSEONG RIEUL-KIYEOK */
block|{
literal|0x0edd
block|,
literal|0x11b1
block|}
block|,
comment|/*         Hangul_J_RieulMieum á± HANGUL JONGSEONG RIEUL-MIEUM */
block|{
literal|0x0ede
block|,
literal|0x11b2
block|}
block|,
comment|/*         Hangul_J_RieulPieub á² HANGUL JONGSEONG RIEUL-PIEUP */
block|{
literal|0x0edf
block|,
literal|0x11b3
block|}
block|,
comment|/*          Hangul_J_RieulSios á³ HANGUL JONGSEONG RIEUL-SIOS */
block|{
literal|0x0ee0
block|,
literal|0x11b4
block|}
block|,
comment|/*         Hangul_J_RieulTieut á´ HANGUL JONGSEONG RIEUL-THIEUTH */
block|{
literal|0x0ee1
block|,
literal|0x11b5
block|}
block|,
comment|/*        Hangul_J_RieulPhieuf áµ HANGUL JONGSEONG RIEUL-PHIEUPH */
block|{
literal|0x0ee2
block|,
literal|0x11b6
block|}
block|,
comment|/*         Hangul_J_RieulHieuh á¶ HANGUL JONGSEONG RIEUL-HIEUH */
block|{
literal|0x0ee3
block|,
literal|0x11b7
block|}
block|,
comment|/*              Hangul_J_Mieum á· HANGUL JONGSEONG MIEUM */
block|{
literal|0x0ee4
block|,
literal|0x11b8
block|}
block|,
comment|/*              Hangul_J_Pieub á¸ HANGUL JONGSEONG PIEUP */
block|{
literal|0x0ee5
block|,
literal|0x11b9
block|}
block|,
comment|/*          Hangul_J_PieubSios á¹ HANGUL JONGSEONG PIEUP-SIOS */
block|{
literal|0x0ee6
block|,
literal|0x11ba
block|}
block|,
comment|/*               Hangul_J_Sios áº HANGUL JONGSEONG SIOS */
block|{
literal|0x0ee7
block|,
literal|0x11bb
block|}
block|,
comment|/*          Hangul_J_SsangSios á» HANGUL JONGSEONG SSANGSIOS */
block|{
literal|0x0ee8
block|,
literal|0x11bc
block|}
block|,
comment|/*              Hangul_J_Ieung á¼ HANGUL JONGSEONG IEUNG */
block|{
literal|0x0ee9
block|,
literal|0x11bd
block|}
block|,
comment|/*              Hangul_J_Jieuj á½ HANGUL JONGSEONG CIEUC */
block|{
literal|0x0eea
block|,
literal|0x11be
block|}
block|,
comment|/*              Hangul_J_Cieuc á¾ HANGUL JONGSEONG CHIEUCH */
block|{
literal|0x0eeb
block|,
literal|0x11bf
block|}
block|,
comment|/*             Hangul_J_Khieuq á¿ HANGUL JONGSEONG KHIEUKH */
block|{
literal|0x0eec
block|,
literal|0x11c0
block|}
block|,
comment|/*              Hangul_J_Tieut á HANGUL JONGSEONG THIEUTH */
block|{
literal|0x0eed
block|,
literal|0x11c1
block|}
block|,
comment|/*             Hangul_J_Phieuf á HANGUL JONGSEONG PHIEUPH */
block|{
literal|0x0eee
block|,
literal|0x11c2
block|}
block|,
comment|/*              Hangul_J_Hieuh á HANGUL JONGSEONG HIEUH */
block|{
literal|0x0eef
block|,
literal|0x316d
block|}
block|,
comment|/*     Hangul_RieulYeorinHieuh ã­ HANGUL LETTER RIEUL-YEORINHIEUH */
block|{
literal|0x0ef0
block|,
literal|0x3171
block|}
block|,
comment|/*    Hangul_SunkyeongeumMieum ã± HANGUL LETTER KAPYEOUNMIEUM */
block|{
literal|0x0ef1
block|,
literal|0x3178
block|}
block|,
comment|/*    Hangul_SunkyeongeumPieub ã¸ HANGUL LETTER KAPYEOUNPIEUP */
block|{
literal|0x0ef2
block|,
literal|0x317f
block|}
block|,
comment|/*              Hangul_PanSios ã¿ HANGUL LETTER PANSIOS */
comment|/*  0x0ef3                  Hangul_KkogjiDalrinIeung ? ??? */
block|{
literal|0x0ef4
block|,
literal|0x3184
block|}
block|,
comment|/*   Hangul_SunkyeongeumPhieuf ã HANGUL LETTER KAPYEOUNPHIEUPH */
block|{
literal|0x0ef5
block|,
literal|0x3186
block|}
block|,
comment|/*          Hangul_YeorinHieuh ã HANGUL LETTER YEORINHIEUH */
block|{
literal|0x0ef6
block|,
literal|0x318d
block|}
block|,
comment|/*                Hangul_AraeA ã HANGUL LETTER ARAEA */
block|{
literal|0x0ef7
block|,
literal|0x318e
block|}
block|,
comment|/*               Hangul_AraeAE ã HANGUL LETTER ARAEAE */
block|{
literal|0x0ef8
block|,
literal|0x11eb
block|}
block|,
comment|/*            Hangul_J_PanSios á« HANGUL JONGSEONG PANSIOS */
block|{
literal|0x0ef9
block|,
literal|0x11f0
block|}
block|,
comment|/*  Hangul_J_KkogjiDalrinIeung á° HANGUL JONGSEONG YESIEUNG */
block|{
literal|0x0efa
block|,
literal|0x11f9
block|}
block|,
comment|/*        Hangul_J_YeorinHieuh á¹ HANGUL JONGSEONG YEORINHIEUH */
block|{
literal|0x0eff
block|,
literal|0x20a9
block|}
block|,
comment|/*                  Korean_Won â© WON SIGN */
block|{
literal|0x13a4
block|,
literal|0x20ac
block|}
block|,
comment|/*                        Euro â¬ EURO SIGN */
block|{
literal|0x13bc
block|,
literal|0x0152
block|}
block|,
comment|/*                          OE Å LATIN CAPITAL LIGATURE OE */
block|{
literal|0x13bd
block|,
literal|0x0153
block|}
block|,
comment|/*                          oe Å LATIN SMALL LIGATURE OE */
block|{
literal|0x13be
block|,
literal|0x0178
block|}
block|,
comment|/*                  Ydiaeresis Å¸ LATIN CAPITAL LETTER Y WITH DIAERESIS */
block|{
literal|0x20a0
block|,
literal|0x20a0
block|}
block|,
comment|/*                     EcuSign â  EURO-CURRENCY SIGN */
block|{
literal|0x20a1
block|,
literal|0x20a1
block|}
block|,
comment|/*                   ColonSign â¡ COLON SIGN */
block|{
literal|0x20a2
block|,
literal|0x20a2
block|}
block|,
comment|/*                CruzeiroSign â¢ CRUZEIRO SIGN */
block|{
literal|0x20a3
block|,
literal|0x20a3
block|}
block|,
comment|/*                  FFrancSign â£ FRENCH FRANC SIGN */
block|{
literal|0x20a4
block|,
literal|0x20a4
block|}
block|,
comment|/*                    LiraSign â¤ LIRA SIGN */
block|{
literal|0x20a5
block|,
literal|0x20a5
block|}
block|,
comment|/*                    MillSign â¥ MILL SIGN */
block|{
literal|0x20a6
block|,
literal|0x20a6
block|}
block|,
comment|/*                   NairaSign â¦ NAIRA SIGN */
block|{
literal|0x20a7
block|,
literal|0x20a7
block|}
block|,
comment|/*                  PesetaSign â§ PESETA SIGN */
block|{
literal|0x20a8
block|,
literal|0x20a8
block|}
block|,
comment|/*                   RupeeSign â¨ RUPEE SIGN */
block|{
literal|0x20a9
block|,
literal|0x20a9
block|}
block|,
comment|/*                     WonSign â© WON SIGN */
block|{
literal|0x20aa
block|,
literal|0x20aa
block|}
block|,
comment|/*               NewSheqelSign âª NEW SHEQEL SIGN */
block|{
literal|0x20ab
block|,
literal|0x20ab
block|}
block|,
comment|/*                    DongSign â« DONG SIGN */
block|{
literal|0x20ac
block|,
literal|0x20ac
block|}
block|,
comment|/*                    EuroSign â¬ EURO SIGN */
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* binary search with range check */
end_comment
begin_function
specifier|static
name|uint32_t
DECL|function|bin_search
name|bin_search
parameter_list|(
specifier|const
name|struct
name|codepair
modifier|*
name|table
parameter_list|,
name|size_t
name|length
parameter_list|,
name|xkb_keysym_t
name|keysym
parameter_list|)
block|{
name|int
name|min
init|=
literal|0
decl_stmt|;
name|int
name|max
init|=
name|length
decl_stmt|;
name|int
name|mid
decl_stmt|;
if|if
condition|(
name|keysym
operator|<
name|table
index|[
literal|0
index|]
operator|.
name|keysym
operator|||
name|keysym
operator|>
name|table
index|[
name|length
index|]
operator|.
name|keysym
condition|)
return|return
literal|0
return|;
comment|/* binary search in table */
while|while
condition|(
name|max
operator|>=
name|min
condition|)
block|{
name|mid
operator|=
operator|(
name|min
operator|+
name|max
operator|)
operator|/
literal|2
expr_stmt|;
if|if
condition|(
name|table
index|[
name|mid
index|]
operator|.
name|keysym
operator|<
name|keysym
condition|)
name|min
operator|=
name|mid
operator|+
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|table
index|[
name|mid
index|]
operator|.
name|keysym
operator|>
name|keysym
condition|)
name|max
operator|=
name|mid
operator|-
literal|1
expr_stmt|;
else|else
comment|/* found it */
return|return
name|table
index|[
name|mid
index|]
operator|.
name|ucs
return|;
block|}
comment|/* no matching Unicode value found in table */
return|return
literal|0
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|uint32_t
DECL|function|xkb_keysym_to_utf32
name|xkb_keysym_to_utf32
parameter_list|(
name|xkb_keysym_t
name|keysym
parameter_list|)
block|{
comment|/* first check for Latin-1 characters (1:1 mapping) */
if|if
condition|(
operator|(
name|keysym
operator|>=
literal|0x0020
operator|&&
name|keysym
operator|<=
literal|0x007e
operator|)
operator|||
operator|(
name|keysym
operator|>=
literal|0x00a0
operator|&&
name|keysym
operator|<=
literal|0x00ff
operator|)
condition|)
return|return
name|keysym
return|;
comment|/* patch encoding botch */
if|if
condition|(
name|keysym
operator|==
name|XKB_KEY_KP_Space
condition|)
return|return
name|XKB_KEY_space
operator|&
literal|0x7f
return|;
comment|/* special keysyms */
if|if
condition|(
operator|(
name|keysym
operator|>=
name|XKB_KEY_BackSpace
operator|&&
name|keysym
operator|<=
name|XKB_KEY_Clear
operator|)
operator|||
operator|(
name|keysym
operator|>=
name|XKB_KEY_KP_Multiply
operator|&&
name|keysym
operator|<=
name|XKB_KEY_KP_9
operator|)
operator|||
name|keysym
operator|==
name|XKB_KEY_Return
operator|||
name|keysym
operator|==
name|XKB_KEY_Escape
operator|||
name|keysym
operator|==
name|XKB_KEY_Delete
operator|||
name|keysym
operator|==
name|XKB_KEY_KP_Tab
operator|||
name|keysym
operator|==
name|XKB_KEY_KP_Enter
operator|||
name|keysym
operator|==
name|XKB_KEY_KP_Equal
condition|)
return|return
name|keysym
operator|&
literal|0x7f
return|;
comment|/* also check for directly encoded 24-bit UCS characters */
if|if
condition|(
operator|(
name|keysym
operator|&
literal|0xff000000
operator|)
operator|==
literal|0x01000000
condition|)
return|return
name|keysym
operator|&
literal|0x00ffffff
return|;
comment|/* search main table */
return|return
name|bin_search
argument_list|(
name|keysymtab
argument_list|,
name|ARRAY_SIZE
argument_list|(
name|keysymtab
argument_list|)
operator|-
literal|1
argument_list|,
name|keysym
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*  * Copyright Â© 2012 Intel Corporation  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Author: Rob Bradford<rob@linux.intel.com>  */
end_comment
begin_function
specifier|static
name|int
DECL|function|utf32_to_utf8
name|utf32_to_utf8
parameter_list|(
name|uint32_t
name|unichar
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
block|{
name|int
name|count
decl_stmt|,
name|shift
decl_stmt|,
name|length
decl_stmt|;
name|uint8_t
name|head
decl_stmt|;
if|if
condition|(
name|unichar
operator|<=
literal|0x007f
condition|)
block|{
name|buffer
index|[
literal|0
index|]
operator|=
name|unichar
expr_stmt|;
name|buffer
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
literal|2
return|;
block|}
elseif|else
if|if
condition|(
name|unichar
operator|<=
literal|0x07FF
condition|)
block|{
name|length
operator|=
literal|2
expr_stmt|;
name|head
operator|=
literal|0xc0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|unichar
operator|<=
literal|0xffff
condition|)
block|{
name|length
operator|=
literal|3
expr_stmt|;
name|head
operator|=
literal|0xe0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|unichar
operator|<=
literal|0x1fffff
condition|)
block|{
name|length
operator|=
literal|4
expr_stmt|;
name|head
operator|=
literal|0xf0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|unichar
operator|<=
literal|0x3ffffff
condition|)
block|{
name|length
operator|=
literal|5
expr_stmt|;
name|head
operator|=
literal|0xf8
expr_stmt|;
block|}
else|else
block|{
name|length
operator|=
literal|6
expr_stmt|;
name|head
operator|=
literal|0xfc
expr_stmt|;
block|}
for|for
control|(
name|count
operator|=
name|length
operator|-
literal|1
operator|,
name|shift
operator|=
literal|0
init|;
name|count
operator|>
literal|0
condition|;
name|count
operator|--
operator|,
name|shift
operator|+=
literal|6
control|)
name|buffer
index|[
name|count
index|]
operator|=
literal|0x80
operator||
operator|(
operator|(
name|unichar
operator|>>
name|shift
operator|)
operator|&
literal|0x3f
operator|)
expr_stmt|;
name|buffer
index|[
literal|0
index|]
operator|=
name|head
operator||
operator|(
operator|(
name|unichar
operator|>>
name|shift
operator|)
operator|&
literal|0x3f
operator|)
expr_stmt|;
name|buffer
index|[
name|length
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|length
operator|+
literal|1
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|int
DECL|function|xkb_keysym_to_utf8
name|xkb_keysym_to_utf8
parameter_list|(
name|xkb_keysym_t
name|keysym
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|uint32_t
name|codepoint
decl_stmt|;
if|if
condition|(
name|size
operator|<
literal|7
condition|)
return|return
operator|-
literal|1
return|;
name|codepoint
operator|=
name|xkb_keysym_to_utf32
argument_list|(
name|keysym
argument_list|)
expr_stmt|;
if|if
condition|(
name|codepoint
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|utf32_to_utf8
argument_list|(
name|codepoint
argument_list|,
name|buffer
argument_list|)
return|;
block|}
end_function
end_unit
