begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_using
using|using
namespace|namespace
name|std
namespace|;
end_using
begin_class
DECL|class|Widget
class|class
name|Widget
super|:
specifier|public
name|QWidget
block|{
public|public:
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|Widget
name|Widget
operator|::
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
comment|//! [0]
name|QStringList
name|fonts
decl_stmt|;
name|fonts
operator|<<
literal|"Arial"
operator|<<
literal|"Helvetica"
operator|<<
literal|"Times"
operator|<<
literal|"Courier"
expr_stmt|;
comment|//! [0]
comment|//! [1]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|fonts
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|cout
operator|<<
name|fonts
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
operator|<<
name|endl
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QStringListIterator
name|javaStyleIterator
argument_list|(
name|fonts
argument_list|)
decl_stmt|;
while|while
condition|(
name|javaStyleIterator
operator|.
name|hasNext
argument_list|()
condition|)
name|cout
operator|<<
name|javaStyleIterator
operator|.
name|next
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
operator|<<
name|endl
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QStringList
operator|::
name|const_iterator
name|constIterator
decl_stmt|;
for|for
control|(
name|constIterator
operator|=
name|fonts
operator|.
name|constBegin
argument_list|()
init|;
name|constIterator
operator|!=
name|fonts
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|constIterator
control|)
name|cout
operator|<<
operator|(
operator|*
name|constIterator
operator|)
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
operator|<<
name|endl
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|QString
name|str
init|=
name|fonts
operator|.
name|join
argument_list|(
literal|", "
argument_list|)
decl_stmt|;
comment|// str == "Arial, Helvetica, Times, Courier"
comment|//! [4]
comment|//! [5] //! [6]
name|QStringList
name|list
decl_stmt|;
comment|//! [5]
name|list
operator|=
name|str
operator|.
name|split
argument_list|(
literal|","
argument_list|)
expr_stmt|;
comment|// list: ["Arial", "Helvetica", "Times", "Courier"]
comment|//! [6]
comment|//! [7]
name|QStringList
name|monospacedFonts
init|=
name|fonts
operator|.
name|filter
argument_list|(
name|QRegExp
argument_list|(
literal|"Courier|Fixed"
argument_list|)
argument_list|)
decl_stmt|;
comment|//! [7]
comment|//! [8]
name|QStringList
name|files
decl_stmt|;
name|files
operator|<<
literal|"$QTDIR/src/moc/moc.y"
operator|<<
literal|"$QTDIR/src/moc/moc.l"
operator|<<
literal|"$QTDIR/include/qconfig.h"
expr_stmt|;
name|files
operator|.
name|replaceInStrings
argument_list|(
literal|"$QTDIR"
argument_list|,
literal|"/usr/lib/qt"
argument_list|)
expr_stmt|;
comment|// files: [ "/usr/lib/qt/src/moc/moc.y", ...]
comment|//! [8]
name|QString
name|str1
decl_stmt|,
name|str2
decl_stmt|,
name|str3
decl_stmt|;
comment|//! [9]
name|QStringList
name|longerList
init|=
operator|(
name|QStringList
argument_list|()
operator|<<
name|str1
operator|<<
name|str2
operator|<<
name|str3
operator|)
decl_stmt|;
comment|//! [9]
name|list
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//! [10]
name|list
operator|<<
literal|"Bill Murray"
operator|<<
literal|"John Doe"
operator|<<
literal|"Bill Clinton"
expr_stmt|;
comment|//! [11]
name|QStringList
name|result
decl_stmt|;
comment|//! [11]
name|result
operator|=
name|list
operator|.
name|filter
argument_list|(
literal|"Bill"
argument_list|)
expr_stmt|;
comment|// result: ["Bill Murray", "Bill Clinton"]
comment|//! [10]
name|result
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//! [12]
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|str
decl|,
name|list
control|)
block|{
if|if
condition|(
name|str
operator|.
name|contains
argument_list|(
literal|"Bill"
argument_list|)
condition|)
name|result
operator|+=
name|str
expr_stmt|;
block|}
comment|//! [12]
name|list
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//! [13]
name|list
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"gamma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|list
operator|.
name|replaceInStrings
argument_list|(
literal|"a"
argument_list|,
literal|"o"
argument_list|)
expr_stmt|;
comment|// list == ["olpho", "beto", "gommo", "epsilon"]
comment|//! [13]
name|list
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//! [14]
name|list
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"gamma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|list
operator|.
name|replaceInStrings
argument_list|(
name|QRegExp
argument_list|(
literal|"^a"
argument_list|)
argument_list|,
literal|"o"
argument_list|)
expr_stmt|;
comment|// list == ["olpha", "beta", "gamma", "epsilon"]
comment|//! [14]
name|list
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//! [15]
name|list
operator|<<
literal|"Bill Clinton"
operator|<<
literal|"Murray, Bill"
expr_stmt|;
name|list
operator|.
name|replaceInStrings
argument_list|(
name|QRegExp
argument_list|(
literal|"^(.*), (.*)$"
argument_list|)
argument_list|,
literal|"\\2 \\1"
argument_list|)
expr_stmt|;
comment|// list == ["Bill Clinton", "Bill Murray"]
comment|//! [15]
name|list
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//! [16]
name|list
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"gamma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|list
operator|.
name|replaceInStrings
argument_list|(
name|QRegularExpression
argument_list|(
literal|"^a"
argument_list|)
argument_list|,
literal|"o"
argument_list|)
expr_stmt|;
comment|// list == ["olpha", "beta", "gamma", "epsilon"]
comment|//! [16]
name|list
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|//! [17]
name|list
operator|<<
literal|"Bill Clinton"
operator|<<
literal|"Murray, Bill"
expr_stmt|;
name|list
operator|.
name|replaceInStrings
argument_list|(
name|QRegularExpression
argument_list|(
literal|"^(.*), (.*)$"
argument_list|)
argument_list|,
literal|"\\2 \\1"
argument_list|)
expr_stmt|;
comment|// list == ["Bill Clinton", "Bill Murray"]
comment|//! [17]
block|}
end_constructor
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
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|Widget
name|widget
decl_stmt|;
name|widget
operator|.
name|show
argument_list|()
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
