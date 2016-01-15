begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|spurious
define|#
directive|define
name|spurious
define|\
value|/ #include "needed.cpp"
end_define
begin_comment
comment|// if not ignored, symbol needed() won't be available ...
end_comment
begin_comment
comment|// Check we're not confused by string juxtaposition:
end_comment
begin_decl_stmt
DECL|variable|text
specifier|static
specifier|const
name|char
name|text
index|[]
init|=
literal|"lorem "
literal|"ipsum /*"
decl_stmt|;
end_decl_stmt
begin_include
include|#
directive|include
file|<moc_object1.cpp>
end_include
begin_comment
comment|/**/
end_comment
begin_include
include|#
directive|include
file|"\ moc_object2.cpp\ "
end_include
begin_comment
comment|/**/
end_comment
begin_comment
comment|/**/
end_comment
begin_include
include|#
directive|include
file|<moc_\ o\ b\ j\ e\ c\ t\ 3\ .cpp>
end_include
begin_comment
comment|/*'"*/
end_comment
begin_include
include|#
directive|include
file|<moc_object4.cpp>
end_include
begin_comment
comment|/*"' */
end_comment
begin_include
include|#
directive|include
file|<moc_object5.cpp>
end_include
begin_comment
comment|/* #include "missing.cpp" */
end_comment
begin_comment
comment|// a backslash newline does make the next line part of this comment \
end_comment
begin_comment
comment|/* so this text is in last line's C++-style comment, not a C-comment ! #include<moc_object6.cpp> #if 0 #pragma "ignore me" '&' L"me" #line 4321 "main.cpp" more /* preprocessing */
end_comment
begin_function_decl
name|tokens
endif|#
directive|endif
specifier|static
name|void
name|function1
parameter_list|()
function_decl|;
end_function_decl
begin_include
include|#
directive|include
comment|/* every comment gets replaced (in phase 3) by a single space */
file|<moc_object7.cpp>
end_include
begin_function_decl
specifier|static
name|void
name|function2
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|/**/
end_comment
begin_include
include|#
directive|include
include|\
file|<moc_object8.cpp>
end_include
begin_function_decl
specifier|static
name|void
name|function3
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<moc_object9.cpp>
end_include
begin_comment
comment|/* backslash-newline elimination happens in phase 2 *\ / # /* and that's valid here, too. *\ / include/* and, of course, here *\ /<moc_objecta.cpp>// while we're here, ... \ #include "needed.cpp"  int main () {     extern int needed(void);     return needed(); }  /*   Deliberately end file in a #include, with nothing after it but the mandatory   (unescaped) newline at the end of every source file. */
end_comment
begin_include
include|#
directive|include
file|"moc_objectf.cpp"
end_include
end_unit
