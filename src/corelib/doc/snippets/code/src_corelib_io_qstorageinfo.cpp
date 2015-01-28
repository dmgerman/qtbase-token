begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Ivan Komissarov ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QStorageInfo
name|storage
argument_list|(
name|qApp
operator|->
name|applicationDirPath
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|storage
operator|.
name|isValid
argument_list|()
operator|&&
name|storage
operator|.
name|isReady
argument_list|()
condition|)
block|{
comment|// ...
block|}
end_if
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_foreach
DECL|function|foreach
foreach|foreach
control|(
specifier|const
name|QStorageInfo
modifier|&
name|storage
decl|,
name|QStorageInfo
operator|::
name|mountedVolumes
argument_list|()
control|)
block|{
if|if
condition|(
name|storage
operator|.
name|isValid
argument_list|()
operator|&&
name|storage
operator|.
name|isReady
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|storage
operator|.
name|isReadOnly
argument_list|()
condition|)
block|{
comment|// ...
block|}
block|}
block|}
end_foreach
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|storage
name|QStorageInfo
name|storage
init|=
name|QStorageInfo
operator|::
name|root
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
name|storage
operator|.
name|rootPath
argument_list|()
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|storage
operator|.
name|isReadOnly
argument_list|()
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"isReadOnly:"
operator|<<
name|storage
operator|.
name|isReadOnly
argument_list|()
expr_stmt|;
end_if
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"name:"
operator|<<
name|storage
operator|.
name|name
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"fileSystemType:"
operator|<<
name|storage
operator|.
name|fileSystemType
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"size:"
operator|<<
name|storage
operator|.
name|bytesTotal
argument_list|()
operator|/
literal|1000
operator|/
literal|1000
operator|<<
literal|"MB"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qDebug
argument_list|()
operator|<<
literal|"availableSize:"
operator|<<
name|storage
operator|.
name|bytesAvailable
argument_list|()
operator|/
literal|1000
operator|/
literal|1000
operator|<<
literal|"MB"
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
end_unit
