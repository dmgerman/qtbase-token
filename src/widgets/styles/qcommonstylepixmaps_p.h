begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_IMAGEFORMAT_XPM
end_comment
end_unit
