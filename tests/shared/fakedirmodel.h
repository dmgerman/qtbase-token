begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FAKEDIRMODEL_H
end_ifndef
begin_define
DECL|macro|FAKEDIRMODEL_H
define|#
directive|define
name|FAKEDIRMODEL_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QStandardItemModel>
end_include
begin_include
include|#
directive|include
file|<QtGui/QStandardItem>
end_include
begin_include
include|#
directive|include
file|<QtGui/QIcon>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_typedef
DECL|typedef|StandardItemList
typedef|typedef
name|QList
operator|<
name|QStandardItem
operator|*
operator|>
name|StandardItemList
expr_stmt|;
end_typedef
begin_decl_stmt
DECL|function|coloredIcon
specifier|static
specifier|inline
name|QIcon
name|coloredIcon
argument_list|(
name|Qt
operator|::
name|GlobalColor
name|color
argument_list|)
block|{
name|QImage
name|image
argument_list|(
literal|22
argument_list|,
literal|22
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
name|image
operator|.
name|fill
argument_list|(
name|color
argument_list|)
expr_stmt|;
return|return
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|image
argument_list|)
return|;
block|}
end_decl_stmt
begin_function
DECL|function|addFileEntry
specifier|static
name|void
name|addFileEntry
parameter_list|(
specifier|const
name|StandardItemList
modifier|&
name|directory
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|size
parameter_list|)
block|{
specifier|static
specifier|const
name|QIcon
name|fileIcon
init|=
name|coloredIcon
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
decl_stmt|;
name|directory
operator|.
name|front
argument_list|()
operator|->
name|appendRow
argument_list|(
argument|StandardItemList()<< new QStandardItem(fileIcon, name)<< new QStandardItem(size)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createDirEntry
specifier|static
name|StandardItemList
name|createDirEntry
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
specifier|static
specifier|const
name|QIcon
name|dirIcon
init|=
name|coloredIcon
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
decl_stmt|;
name|StandardItemList
name|result
decl_stmt|;
name|result
operator|<<
name|new
name|QStandardItem
argument_list|(
name|dirIcon
argument_list|,
name|name
argument_list|)
operator|<<
name|new
name|QStandardItem
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|addDirEntry
specifier|static
specifier|inline
name|StandardItemList
name|addDirEntry
parameter_list|(
specifier|const
name|StandardItemList
modifier|&
name|directory
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
specifier|const
name|StandardItemList
name|entry
init|=
name|createDirEntry
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|directory
operator|.
name|front
argument_list|()
operator|->
name|appendRow
argument_list|(
name|entry
argument_list|)
expr_stmt|;
return|return
name|entry
return|;
block|}
end_function
begin_function
DECL|function|populateFakeDirModel
specifier|static
name|QStandardItem
modifier|*
name|populateFakeDirModel
parameter_list|(
name|QStandardItemModel
modifier|*
name|model
parameter_list|)
block|{
enum|enum
name|Columns
block|{
name|NameColumn
block|,
name|SizeColumn
block|,
name|ColumnCount
block|}
enum|;
name|model
operator|->
name|setColumnCount
argument_list|(
name|ColumnCount
argument_list|)
expr_stmt|;
name|model
operator|->
name|setHorizontalHeaderLabels
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"Name"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"Size"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|root
init|=
name|createDirEntry
argument_list|(
name|QStringLiteral
argument_list|(
literal|"/"
argument_list|)
argument_list|)
decl_stmt|;
name|model
operator|->
name|appendRow
argument_list|(
name|root
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|binDir
init|=
name|addDirEntry
argument_list|(
name|root
argument_list|,
name|QStringLiteral
argument_list|(
literal|"bin"
argument_list|)
argument_list|)
decl_stmt|;
name|addFileEntry
argument_list|(
name|binDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"ls"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"100 KB"
argument_list|)
argument_list|)
expr_stmt|;
name|addFileEntry
argument_list|(
name|binDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"bash"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"200 KB"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|devDir
init|=
name|addDirEntry
argument_list|(
name|root
argument_list|,
name|QStringLiteral
argument_list|(
literal|"dev"
argument_list|)
argument_list|)
decl_stmt|;
name|addFileEntry
argument_list|(
name|devDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"tty1"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"0 B"
argument_list|)
argument_list|)
expr_stmt|;
name|addDirEntry
argument_list|(
name|devDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"proc"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|etcDir
init|=
name|addDirEntry
argument_list|(
name|root
argument_list|,
name|QStringLiteral
argument_list|(
literal|"etc"
argument_list|)
argument_list|)
decl_stmt|;
name|addFileEntry
argument_list|(
name|etcDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"foo1.config"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"1 KB"
argument_list|)
argument_list|)
expr_stmt|;
name|addFileEntry
argument_list|(
name|etcDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"foo2.conf"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"654 B"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|homeDir
init|=
name|addDirEntry
argument_list|(
name|root
argument_list|,
name|QStringLiteral
argument_list|(
literal|"home"
argument_list|)
argument_list|)
decl_stmt|;
name|addFileEntry
argument_list|(
name|homeDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"file1"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"1 KB"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|documentsDir
init|=
name|addDirEntry
argument_list|(
name|homeDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Documents"
argument_list|)
argument_list|)
decl_stmt|;
name|addFileEntry
argument_list|(
name|documentsDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"txt1.odt"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"2 MB"
argument_list|)
argument_list|)
expr_stmt|;
name|addFileEntry
argument_list|(
name|documentsDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"sheet1.xls"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"32 KB"
argument_list|)
argument_list|)
expr_stmt|;
name|addFileEntry
argument_list|(
name|documentsDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"foo.doc"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"214 KB"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|downloadsDir
init|=
name|addDirEntry
argument_list|(
name|homeDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Downloads"
argument_list|)
argument_list|)
decl_stmt|;
name|addFileEntry
argument_list|(
name|downloadsDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"package1.zip"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"34 MB"
argument_list|)
argument_list|)
expr_stmt|;
name|addFileEntry
argument_list|(
name|downloadsDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"package2.zip"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"623 KB"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|picturesDir
init|=
name|addDirEntry
argument_list|(
name|homeDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Pictures"
argument_list|)
argument_list|)
decl_stmt|;
name|addFileEntry
argument_list|(
name|picturesDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"img0001.jpg"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"4 MB"
argument_list|)
argument_list|)
expr_stmt|;
name|addFileEntry
argument_list|(
name|picturesDir
argument_list|,
name|QStringLiteral
argument_list|(
literal|"img0002.png"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"10 MB"
argument_list|)
argument_list|)
expr_stmt|;
comment|// qcolumnview::moveCursor() requires an empty directory followed by another one.
name|addDirEntry
argument_list|(
name|root
argument_list|,
name|QStringLiteral
argument_list|(
literal|"lost+found"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|StandardItemList
name|tmpDir
init|=
name|addDirEntry
argument_list|(
name|root
argument_list|,
name|QStringLiteral
argument_list|(
literal|"tmp"
argument_list|)
argument_list|)
decl_stmt|;
name|addFileEntry
argument_list|(
name|tmpDir
argument_list|,
literal|"asdujhsdjys"
argument_list|,
literal|"435 B"
argument_list|)
expr_stmt|;
name|addFileEntry
argument_list|(
name|tmpDir
argument_list|,
literal|"krtbldfhd"
argument_list|,
literal|"5557 B"
argument_list|)
expr_stmt|;
return|return
name|homeDir
operator|.
name|front
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// FAKEDIRMODEL_H
end_comment
end_unit
