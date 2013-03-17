begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_XPM
end_ifndef
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
DECL|variable|check_list_controller_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|check_list_controller_xpm
index|[]
init|=
block|{
literal|"16 16 4 1"
block|,
literal|"        c None"
block|,
literal|".        c #000000000000"
block|,
literal|"X        c #FFFFFFFF0000"
block|,
literal|"o        c #C71BC30BC71B"
block|,
literal|"                "
block|,
literal|"                "
block|,
literal|" ..........     "
block|,
literal|" .XXXXXXXX.     "
block|,
literal|" .XXXXXXXX.oo   "
block|,
literal|" .XXXXXXXX.oo   "
block|,
literal|" .XXXXXXXX.oo   "
block|,
literal|" .XXXXXXXX.oo   "
block|,
literal|" .XXXXXXXX.oo   "
block|,
literal|" .XXXXXXXX.oo   "
block|,
literal|" .XXXXXXXX.oo   "
block|,
literal|" ..........oo   "
block|,
literal|"   oooooooooo   "
block|,
literal|"   oooooooooo   "
block|,
literal|"                "
block|,
literal|"                "
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|tb_extension_arrow_v_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|tb_extension_arrow_v_xpm
index|[]
init|=
block|{
literal|"5 8 3 1"
block|,
literal|"            c None"
block|,
literal|".            c #000000"
block|,
literal|"+            c none"
block|,
literal|".+++."
block|,
literal|"..+.."
block|,
literal|"+...+"
block|,
literal|"++.++"
block|,
literal|".+++."
block|,
literal|"..+.."
block|,
literal|"+...+"
block|,
literal|"++.++"
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|tb_extension_arrow_h_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|tb_extension_arrow_h_xpm
index|[]
init|=
block|{
literal|"8 5 3 1"
block|,
literal|"            c None"
block|,
literal|".            c #000000"
block|,
literal|"+            c none"
block|,
literal|"..++..++"
block|,
literal|"+..++..+"
block|,
literal|"++..++.."
block|,
literal|"+..++..+"
block|,
literal|"..++..++"
block|, }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|filedialog_start_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|filedialog_start_xpm
index|[]
init|=
block|{
literal|"16 15 8 1"
block|,
literal|"a c #cec6bd"
block|,
literal|"# c #000000"
block|,
literal|"e c #ffff00"
block|,
literal|"b c #999999"
block|,
literal|"f c #cccccc"
block|,
literal|"d c #dcdcdc"
block|,
literal|"c c #ffffff"
block|,
literal|". c None"
block|,
literal|".....######aaaaa"
block|,
literal|"...bb#cccc##aaaa"
block|,
literal|"..bcc#cccc#d#aaa"
block|,
literal|".bcef#cccc#dd#aa"
block|,
literal|".bcfe#cccc#####a"
block|,
literal|".bcef#ccccccccc#"
block|,
literal|"bbbbbbbbbbbbccc#"
block|,
literal|"bccccccccccbbcc#"
block|,
literal|"bcefefefefee#bc#"
block|,
literal|".bcefefefefef#c#"
block|,
literal|".bcfefefefefe#c#"
block|,
literal|"..bcfefefefeeb##"
block|,
literal|"..bbbbbbbbbbbbb#"
block|,
literal|"...#############"
block|,
literal|"................"
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|filedialog_end_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|filedialog_end_xpm
index|[]
init|=
block|{
literal|"16 15 9 1"
block|,
literal|"d c #a0a0a0"
block|,
literal|"c c #c3c3c3"
block|,
literal|"# c #cec6bd"
block|,
literal|". c #000000"
block|,
literal|"f c #ffff00"
block|,
literal|"e c #999999"
block|,
literal|"g c #cccccc"
block|,
literal|"b c #ffffff"
block|,
literal|"a c None"
block|,
literal|"......####aaaaaa"
block|,
literal|".bbbb..###aaaaaa"
block|,
literal|".bbbb.c.##aaaaaa"
block|,
literal|".bbbb....ddeeeea"
block|,
literal|".bbbbbbb.bbbbbe."
block|,
literal|".bbbbbbb.bcfgfe."
block|,
literal|"eeeeeeeeeeeeefe."
block|,
literal|"ebbbbbbbbbbeege."
block|,
literal|"ebfgfgfgfgff.ee."
block|,
literal|"aebfgfgfgfgfg.e."
block|,
literal|"aebgfgfgfgfgf.e."
block|,
literal|"aaebgfgfgfgffe.."
block|,
literal|"aaeeeeeeeeeeeee."
block|,
literal|"aaa............."
block|,
literal|"aaaaaaaaaaaaaaaa"
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* XPM */
end_comment
begin_decl_stmt
DECL|variable|qt_menu_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qt_menu_xpm
index|[]
init|=
block|{
literal|"16 16 72 1"
block|,
literal|"  c None"
block|,
literal|". c #65AF36"
block|,
literal|"+ c #66B036"
block|,
literal|"@ c #77B94C"
block|,
literal|"# c #A7D28C"
block|,
literal|"$ c #BADBA4"
block|,
literal|"% c #A4D088"
block|,
literal|"& c #72B646"
block|,
literal|"* c #9ACB7A"
block|,
literal|"= c #7FBD56"
block|,
literal|"- c #85C05F"
block|,
literal|"; c #F4F9F0"
block|,
literal|"> c #FFFFFF"
block|,
literal|", c #E5F1DC"
block|,
literal|"' c #ECF5E7"
block|,
literal|") c #7ABA50"
block|,
literal|"! c #83BF5C"
block|,
literal|"~ c #AED595"
block|,
literal|"{ c #D7EACA"
block|,
literal|"] c #A9D28D"
block|,
literal|"^ c #BCDDA8"
block|,
literal|"/ c #C4E0B1"
block|,
literal|"( c #81BE59"
block|,
literal|"_ c #D0E7C2"
block|,
literal|": c #D4E9C6"
block|,
literal|"< c #6FB542"
block|,
literal|"[ c #6EB440"
block|,
literal|"} c #88C162"
block|,
literal|"| c #98CA78"
block|,
literal|"1 c #F4F9F1"
block|,
literal|"2 c #8FC56C"
block|,
literal|"3 c #F1F8EC"
block|,
literal|"4 c #E8F3E1"
block|,
literal|"5 c #D4E9C7"
block|,
literal|"6 c #74B748"
block|,
literal|"7 c #80BE59"
block|,
literal|"8 c #73B747"
block|,
literal|"9 c #6DB43F"
block|,
literal|"0 c #CBE4BA"
block|,
literal|"a c #80BD58"
block|,
literal|"b c #6DB33F"
block|,
literal|"c c #FEFFFE"
block|,
literal|"d c #68B138"
block|,
literal|"e c #F9FCF7"
block|,
literal|"f c #91C66F"
block|,
literal|"g c #E8F3E0"
block|,
literal|"h c #DCEDD0"
block|,
literal|"i c #91C66E"
block|,
literal|"j c #A3CF86"
block|,
literal|"k c #C9E3B8"
block|,
literal|"l c #B0D697"
block|,
literal|"m c #E3F0DA"
block|,
literal|"n c #95C873"
block|,
literal|"o c #E6F2DE"
block|,
literal|"p c #9ECD80"
block|,
literal|"q c #BEDEAA"
block|,
literal|"r c #C7E2B6"
block|,
literal|"s c #79BA4F"
block|,
literal|"t c #6EB441"
block|,
literal|"u c #BCDCA7"
block|,
literal|"v c #FAFCF8"
block|,
literal|"w c #F6FAF3"
block|,
literal|"x c #84BF5D"
block|,
literal|"y c #EDF6E7"
block|,
literal|"z c #FAFDF9"
block|,
literal|"A c #88C263"
block|,
literal|"B c #98CA77"
block|,
literal|"C c #CDE5BE"
block|,
literal|"D c #67B037"
block|,
literal|"E c #D9EBCD"
block|,
literal|"F c #6AB23C"
block|,
literal|"G c #77B94D"
block|,
literal|" .++++++++++++++"
block|,
literal|".+++++++++++++++"
block|,
literal|"+++@#$%&+++*=+++"
block|,
literal|"++-;>,>')+!>~+++"
block|,
literal|"++{>]+^>/(_>:~<+"
block|,
literal|"+[>>}+|>123>456+"
block|,
literal|"+7>>8+->>90>~+++"
block|,
literal|"+a>>b+a>c[0>~+++"
block|,
literal|"+de>=+f>g+0>~+++"
block|,
literal|"++h>i+j>k+0>~+++"
block|,
literal|"++l>mno>p+q>rst+"
block|,
literal|"++duv>wl++xy>zA+"
block|,
literal|"++++B>Cb++++&D++"
block|,
literal|"+++++0zE++++++++"
block|,
literal|"++++++FG+++++++."
block|,
literal|"++++++++++++++. "
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_close_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qt_close_xpm
index|[]
init|=
block|{
literal|"10 10 2 1"
block|,
literal|"# c #000000"
block|,
literal|". c None"
block|,
literal|".........."
block|,
literal|".##....##."
block|,
literal|"..##..##.."
block|,
literal|"...####..."
block|,
literal|"....##...."
block|,
literal|"...####..."
block|,
literal|"..##..##.."
block|,
literal|".##....##."
block|,
literal|".........."
block|,
literal|".........."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_maximize_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qt_maximize_xpm
index|[]
init|=
block|{
literal|"10 10 2 1"
block|,
literal|"# c #000000"
block|,
literal|". c None"
block|,
literal|"#########."
block|,
literal|"#########."
block|,
literal|"#.......#."
block|,
literal|"#.......#."
block|,
literal|"#.......#."
block|,
literal|"#.......#."
block|,
literal|"#.......#."
block|,
literal|"#.......#."
block|,
literal|"#########."
block|,
literal|".........."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_minimize_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qt_minimize_xpm
index|[]
init|=
block|{
literal|"10 10 2 1"
block|,
literal|"# c #000000"
block|,
literal|". c None"
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".#######.."
block|,
literal|".#######.."
block|,
literal|".........."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_normalizeup_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qt_normalizeup_xpm
index|[]
init|=
block|{
literal|"10 10 2 1"
block|,
literal|"# c #000000"
block|,
literal|". c None"
block|,
literal|"...######."
block|,
literal|"...######."
block|,
literal|"...#....#."
block|,
literal|".######.#."
block|,
literal|".######.#."
block|,
literal|".#....###."
block|,
literal|".#....#..."
block|,
literal|".#....#..."
block|,
literal|".######..."
block|,
literal|".........."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_help_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qt_help_xpm
index|[]
init|=
block|{
literal|"10 10 2 1"
block|,
literal|". c None"
block|,
literal|"# c #000000"
block|,
literal|".........."
block|,
literal|"..######.."
block|,
literal|".##....##."
block|,
literal|"......##.."
block|,
literal|".....##..."
block|,
literal|"....##...."
block|,
literal|"....##...."
block|,
literal|".........."
block|,
literal|"....##...."
block|,
literal|".........."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_shade_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qt_shade_xpm
index|[]
init|=
block|{
literal|"10 10 2 1"
block|,
literal|"# c #000000"
block|,
literal|". c None"
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|"....#....."
block|,
literal|"...###...."
block|,
literal|"..#####..."
block|,
literal|".#######.."
block|,
literal|".........."
block|,
literal|".........."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_unshade_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|qt_unshade_xpm
index|[]
init|=
block|{
literal|"10 10 2 1"
block|,
literal|"# c #000000"
block|,
literal|". c None"
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".#######.."
block|,
literal|"..#####..."
block|,
literal|"...###...."
block|,
literal|"....#....."
block|,
literal|".........."
block|,
literal|".........."
block|,
literal|".........."
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|dock_widget_close_xpm
specifier|static
specifier|const
name|char
modifier|*
name|dock_widget_close_xpm
index|[]
init|=
block|{
literal|"8 8 2 1"
block|,
literal|"# c #000000"
block|,
literal|". c None"
block|,
literal|"........"
block|,
literal|".##..##."
block|,
literal|"..####.."
block|,
literal|"...##..."
block|,
literal|"..####.."
block|,
literal|".##..##."
block|,
literal|"........"
block|,
literal|"........"
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* XPM */
end_comment
begin_decl_stmt
DECL|variable|information_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|information_xpm
index|[]
init|=
block|{
literal|"32 32 5 1"
block|,
literal|". c None"
block|,
literal|"c c #000000"
block|,
literal|"* c #999999"
block|,
literal|"a c #ffffff"
block|,
literal|"b c #0000ff"
block|,
literal|"...........********............."
block|,
literal|"........***aaaaaaaa***.........."
block|,
literal|"......**aaaaaaaaaaaaaa**........"
block|,
literal|".....*aaaaaaaaaaaaaaaaaa*......."
block|,
literal|"....*aaaaaaaabbbbaaaaaaaac......"
block|,
literal|"...*aaaaaaaabbbbbbaaaaaaaac....."
block|,
literal|"..*aaaaaaaaabbbbbbaaaaaaaaac...."
block|,
literal|".*aaaaaaaaaaabbbbaaaaaaaaaaac..."
block|,
literal|".*aaaaaaaaaaaaaaaaaaaaaaaaaac*.."
block|,
literal|"*aaaaaaaaaaaaaaaaaaaaaaaaaaaac*."
block|,
literal|"*aaaaaaaaaabbbbbbbaaaaaaaaaaac*."
block|,
literal|"*aaaaaaaaaaaabbbbbaaaaaaaaaaac**"
block|,
literal|"*aaaaaaaaaaaabbbbbaaaaaaaaaaac**"
block|,
literal|"*aaaaaaaaaaaabbbbbaaaaaaaaaaac**"
block|,
literal|"*aaaaaaaaaaaabbbbbaaaaaaaaaaac**"
block|,
literal|"*aaaaaaaaaaaabbbbbaaaaaaaaaaac**"
block|,
literal|".*aaaaaaaaaaabbbbbaaaaaaaaaac***"
block|,
literal|".*aaaaaaaaaaabbbbbaaaaaaaaaac***"
block|,
literal|"..*aaaaaaaaaabbbbbaaaaaaaaac***."
block|,
literal|"...caaaaaaabbbbbbbbbaaaaaac****."
block|,
literal|"....caaaaaaaaaaaaaaaaaaaac****.."
block|,
literal|".....caaaaaaaaaaaaaaaaaac****..."
block|,
literal|"......ccaaaaaaaaaaaaaacc****...."
block|,
literal|".......*cccaaaaaaaaccc*****....."
block|,
literal|"........***cccaaaac*******......"
block|,
literal|"..........****caaac*****........"
block|,
literal|".............*caaac**..........."
block|,
literal|"...............caac**..........."
block|,
literal|"................cac**..........."
block|,
literal|".................cc**..........."
block|,
literal|"..................***..........."
block|,
literal|"...................**..........."
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* XPM */
end_comment
begin_decl_stmt
DECL|variable|warning_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|warning_xpm
index|[]
init|=
block|{
literal|"32 32 4 1"
block|,
literal|". c None"
block|,
literal|"a c #ffff00"
block|,
literal|"* c #000000"
block|,
literal|"b c #999999"
block|,
literal|".............***................"
block|,
literal|"............*aaa*..............."
block|,
literal|"...........*aaaaa*b............."
block|,
literal|"...........*aaaaa*bb............"
block|,
literal|"..........*aaaaaaa*bb..........."
block|,
literal|"..........*aaaaaaa*bb..........."
block|,
literal|".........*aaaaaaaaa*bb.........."
block|,
literal|".........*aaaaaaaaa*bb.........."
block|,
literal|"........*aaaaaaaaaaa*bb........."
block|,
literal|"........*aaaa***aaaa*bb........."
block|,
literal|".......*aaaa*****aaaa*bb........"
block|,
literal|".......*aaaa*****aaaa*bb........"
block|,
literal|"......*aaaaa*****aaaaa*bb......."
block|,
literal|"......*aaaaa*****aaaaa*bb......."
block|,
literal|".....*aaaaaa*****aaaaaa*bb......"
block|,
literal|".....*aaaaaa*****aaaaaa*bb......"
block|,
literal|"....*aaaaaaaa***aaaaaaaa*bb....."
block|,
literal|"....*aaaaaaaa***aaaaaaaa*bb....."
block|,
literal|"...*aaaaaaaaa***aaaaaaaaa*bb...."
block|,
literal|"...*aaaaaaaaaa*aaaaaaaaaa*bb...."
block|,
literal|"..*aaaaaaaaaaa*aaaaaaaaaaa*bb..."
block|,
literal|"..*aaaaaaaaaaaaaaaaaaaaaaa*bb..."
block|,
literal|".*aaaaaaaaaaaa**aaaaaaaaaaa*bb.."
block|,
literal|".*aaaaaaaaaaa****aaaaaaaaaa*bb.."
block|,
literal|"*aaaaaaaaaaaa****aaaaaaaaaaa*bb."
block|,
literal|"*aaaaaaaaaaaaa**aaaaaaaaaaaa*bb."
block|,
literal|"*aaaaaaaaaaaaaaaaaaaaaaaaaaa*bbb"
block|,
literal|"*aaaaaaaaaaaaaaaaaaaaaaaaaaa*bbb"
block|,
literal|".*aaaaaaaaaaaaaaaaaaaaaaaaa*bbbb"
block|,
literal|"..*************************bbbbb"
block|,
literal|"....bbbbbbbbbbbbbbbbbbbbbbbbbbb."
block|,
literal|".....bbbbbbbbbbbbbbbbbbbbbbbbb.."
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* XPM */
end_comment
begin_decl_stmt
DECL|variable|critical_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|critical_xpm
index|[]
init|=
block|{
literal|"32 32 4 1"
block|,
literal|". c None"
block|,
literal|"a c #999999"
block|,
literal|"* c #ff0000"
block|,
literal|"b c #ffffff"
block|,
literal|"...........********............."
block|,
literal|".........************..........."
block|,
literal|".......****************........."
block|,
literal|"......******************........"
block|,
literal|".....********************a......"
block|,
literal|"....**********************a....."
block|,
literal|"...************************a...."
block|,
literal|"..*******b**********b*******a..."
block|,
literal|"..******bbb********bbb******a..."
block|,
literal|".******bbbbb******bbbbb******a.."
block|,
literal|".*******bbbbb****bbbbb*******a.."
block|,
literal|"*********bbbbb**bbbbb*********a."
block|,
literal|"**********bbbbbbbbbb**********a."
block|,
literal|"***********bbbbbbbb***********aa"
block|,
literal|"************bbbbbb************aa"
block|,
literal|"************bbbbbb************aa"
block|,
literal|"***********bbbbbbbb***********aa"
block|,
literal|"**********bbbbbbbbbb**********aa"
block|,
literal|"*********bbbbb**bbbbb*********aa"
block|,
literal|".*******bbbbb****bbbbb*******aa."
block|,
literal|".******bbbbb******bbbbb******aa."
block|,
literal|"..******bbb********bbb******aaa."
block|,
literal|"..*******b**********b*******aa.."
block|,
literal|"...************************aaa.."
block|,
literal|"....**********************aaa..."
block|,
literal|"....a********************aaa...."
block|,
literal|".....a******************aaa....."
block|,
literal|"......a****************aaa......"
block|,
literal|".......aa************aaaa......."
block|,
literal|".........aa********aaaaa........"
block|,
literal|"...........aaaaaaaaaaa.........."
block|,
literal|".............aaaaaaa............"
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* XPM */
end_comment
begin_decl_stmt
DECL|variable|question_xpm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|question_xpm
index|[]
init|=
block|{
literal|"32 32 5 1"
block|,
literal|". c None"
block|,
literal|"c c #000000"
block|,
literal|"* c #999999"
block|,
literal|"a c #ffffff"
block|,
literal|"b c #0000ff"
block|,
literal|"...........********............."
block|,
literal|"........***aaaaaaaa***.........."
block|,
literal|"......**aaaaaaaaaaaaaa**........"
block|,
literal|".....*aaaaaaaaaaaaaaaaaa*......."
block|,
literal|"....*aaaaaaaaaaaaaaaaaaaac......"
block|,
literal|"...*aaaaaaaabbbbbbaaaaaaaac....."
block|,
literal|"..*aaaaaaaabaaabbbbaaaaaaaac...."
block|,
literal|".*aaaaaaaabbaaaabbbbaaaaaaaac..."
block|,
literal|".*aaaaaaaabbbbaabbbbaaaaaaaac*.."
block|,
literal|"*aaaaaaaaabbbbaabbbbaaaaaaaaac*."
block|,
literal|"*aaaaaaaaaabbaabbbbaaaaaaaaaac*."
block|,
literal|"*aaaaaaaaaaaaabbbbaaaaaaaaaaac**"
block|,
literal|"*aaaaaaaaaaaaabbbaaaaaaaaaaaac**"
block|,
literal|"*aaaaaaaaaaaaabbaaaaaaaaaaaaac**"
block|,
literal|"*aaaaaaaaaaaaabbaaaaaaaaaaaaac**"
block|,
literal|"*aaaaaaaaaaaaaaaaaaaaaaaaaaaac**"
block|,
literal|".*aaaaaaaaaaaabbaaaaaaaaaaaac***"
block|,
literal|".*aaaaaaaaaaabbbbaaaaaaaaaaac***"
block|,
literal|"..*aaaaaaaaaabbbbaaaaaaaaaac***."
block|,
literal|"...caaaaaaaaaabbaaaaaaaaaac****."
block|,
literal|"....caaaaaaaaaaaaaaaaaaaac****.."
block|,
literal|".....caaaaaaaaaaaaaaaaaac****..."
block|,
literal|"......ccaaaaaaaaaaaaaacc****...."
block|,
literal|".......*cccaaaaaaaaccc*****....."
block|,
literal|"........***cccaaaac*******......"
block|,
literal|"..........****caaac*****........"
block|,
literal|".............*caaac**..........."
block|,
literal|"...............caac**..........."
block|,
literal|"................cac**..........."
block|,
literal|".................cc**..........."
block|,
literal|"..................***..........."
block|,
literal|"...................**..........."
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_IMAGEFORMAT_XPM
end_comment
end_unit
