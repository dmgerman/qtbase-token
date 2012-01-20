begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"bencodeparser.h"
end_include
begin_include
include|#
directive|include
file|"metainfo.h"
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_include
include|#
directive|include
file|<QMetaType>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_constructor
DECL|function|MetaInfo
name|MetaInfo
operator|::
name|MetaInfo
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|clear
name|void
name|MetaInfo
operator|::
name|clear
parameter_list|()
block|{
name|errString
operator|=
literal|"Unknown error"
expr_stmt|;
name|content
operator|.
name|clear
argument_list|()
expr_stmt|;
name|infoData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|metaInfoMultiFiles
operator|.
name|clear
argument_list|()
expr_stmt|;
name|metaInfoAnnounce
operator|.
name|clear
argument_list|()
expr_stmt|;
name|metaInfoAnnounceList
operator|.
name|clear
argument_list|()
expr_stmt|;
name|metaInfoCreationDate
operator|=
name|QDateTime
argument_list|()
expr_stmt|;
name|metaInfoComment
operator|.
name|clear
argument_list|()
expr_stmt|;
name|metaInfoCreatedBy
operator|.
name|clear
argument_list|()
expr_stmt|;
name|metaInfoName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|metaInfoPieceLength
operator|=
literal|0
expr_stmt|;
name|metaInfoSha1Sums
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parse
name|bool
name|MetaInfo
operator|::
name|parse
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|content
operator|=
name|data
expr_stmt|;
name|BencodeParser
name|parser
decl_stmt|;
if|if
condition|(
operator|!
name|parser
operator|.
name|parse
argument_list|(
name|content
argument_list|)
condition|)
block|{
name|errString
operator|=
name|parser
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
name|infoData
operator|=
name|parser
operator|.
name|infoSection
argument_list|()
expr_stmt|;
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|dict
init|=
name|parser
operator|.
name|dictionary
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|dict
operator|.
name|contains
argument_list|(
literal|"info"
argument_list|)
condition|)
return|return
literal|false
return|;
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|info
init|=
name|qvariant_cast
argument_list|<
name|Dictionary
argument_list|>
argument_list|(
name|dict
operator|.
name|value
argument_list|(
literal|"info"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|info
operator|.
name|contains
argument_list|(
literal|"files"
argument_list|)
condition|)
block|{
name|metaInfoFileForm
operator|=
name|MultiFileForm
expr_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|files
init|=
name|info
operator|.
name|value
argument_list|(
literal|"files"
argument_list|)
operator|.
name|toList
argument_list|()
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
name|files
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QMap
argument_list|<
name|QByteArray
argument_list|,
name|QVariant
argument_list|>
name|file
init|=
name|qvariant_cast
argument_list|<
name|Dictionary
argument_list|>
argument_list|(
name|files
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|QList
argument_list|<
name|QVariant
argument_list|>
name|pathElements
init|=
name|file
operator|.
name|value
argument_list|(
literal|"path"
argument_list|)
operator|.
name|toList
argument_list|()
decl_stmt|;
name|QByteArray
name|path
decl_stmt|;
foreach|foreach
control|(
name|QVariant
name|p
decl|,
name|pathElements
control|)
block|{
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
name|path
operator|+=
literal|"/"
expr_stmt|;
name|path
operator|+=
name|p
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
block|}
name|MetaInfoMultiFile
name|multiFile
decl_stmt|;
name|multiFile
operator|.
name|length
operator|=
name|file
operator|.
name|value
argument_list|(
literal|"length"
argument_list|)
operator|.
name|toLongLong
argument_list|()
expr_stmt|;
name|multiFile
operator|.
name|path
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|path
argument_list|)
expr_stmt|;
name|multiFile
operator|.
name|md5sum
operator|=
name|file
operator|.
name|value
argument_list|(
literal|"md5sum"
argument_list|)
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
name|metaInfoMultiFiles
operator|<<
name|multiFile
expr_stmt|;
block|}
name|metaInfoName
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|info
operator|.
name|value
argument_list|(
literal|"name"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|metaInfoPieceLength
operator|=
name|info
operator|.
name|value
argument_list|(
literal|"piece length"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|QByteArray
name|pieces
init|=
name|info
operator|.
name|value
argument_list|(
literal|"pieces"
argument_list|)
operator|.
name|toByteArray
argument_list|()
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
name|pieces
operator|.
name|size
argument_list|()
condition|;
name|i
operator|+=
literal|20
control|)
name|metaInfoSha1Sums
operator|<<
name|pieces
operator|.
name|mid
argument_list|(
name|i
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|info
operator|.
name|contains
argument_list|(
literal|"length"
argument_list|)
condition|)
block|{
name|metaInfoFileForm
operator|=
name|SingleFileForm
expr_stmt|;
name|metaInfoSingleFile
operator|.
name|length
operator|=
name|info
operator|.
name|value
argument_list|(
literal|"length"
argument_list|)
operator|.
name|toLongLong
argument_list|()
expr_stmt|;
name|metaInfoSingleFile
operator|.
name|md5sum
operator|=
name|info
operator|.
name|value
argument_list|(
literal|"md5sum"
argument_list|)
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
name|metaInfoSingleFile
operator|.
name|name
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|info
operator|.
name|value
argument_list|(
literal|"name"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|metaInfoSingleFile
operator|.
name|pieceLength
operator|=
name|info
operator|.
name|value
argument_list|(
literal|"piece length"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|QByteArray
name|pieces
init|=
name|info
operator|.
name|value
argument_list|(
literal|"pieces"
argument_list|)
operator|.
name|toByteArray
argument_list|()
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
name|pieces
operator|.
name|size
argument_list|()
condition|;
name|i
operator|+=
literal|20
control|)
name|metaInfoSingleFile
operator|.
name|sha1Sums
operator|<<
name|pieces
operator|.
name|mid
argument_list|(
name|i
argument_list|,
literal|20
argument_list|)
expr_stmt|;
block|}
name|metaInfoAnnounce
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|dict
operator|.
name|value
argument_list|(
literal|"announce"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"announce-list"
argument_list|)
condition|)
block|{
comment|// ### unimplemented
block|}
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"creation date"
argument_list|)
condition|)
name|metaInfoCreationDate
operator|.
name|setTime_t
argument_list|(
name|dict
operator|.
name|value
argument_list|(
literal|"creation date"
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"comment"
argument_list|)
condition|)
name|metaInfoComment
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|dict
operator|.
name|value
argument_list|(
literal|"comment"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|dict
operator|.
name|contains
argument_list|(
literal|"created by"
argument_list|)
condition|)
name|metaInfoCreatedBy
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|dict
operator|.
name|value
argument_list|(
literal|"created by"
argument_list|)
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|infoValue
name|QByteArray
name|MetaInfo
operator|::
name|infoValue
parameter_list|()
specifier|const
block|{
return|return
name|infoData
return|;
block|}
end_function
begin_function
DECL|function|errorString
name|QString
name|MetaInfo
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|errString
return|;
block|}
end_function
begin_function
DECL|function|fileForm
name|MetaInfo
operator|::
name|FileForm
name|MetaInfo
operator|::
name|fileForm
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoFileForm
return|;
block|}
end_function
begin_function
DECL|function|announceUrl
name|QString
name|MetaInfo
operator|::
name|announceUrl
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoAnnounce
return|;
block|}
end_function
begin_function
DECL|function|announceList
name|QStringList
name|MetaInfo
operator|::
name|announceList
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoAnnounceList
return|;
block|}
end_function
begin_function
DECL|function|creationDate
name|QDateTime
name|MetaInfo
operator|::
name|creationDate
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoCreationDate
return|;
block|}
end_function
begin_function
DECL|function|comment
name|QString
name|MetaInfo
operator|::
name|comment
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoComment
return|;
block|}
end_function
begin_function
DECL|function|createdBy
name|QString
name|MetaInfo
operator|::
name|createdBy
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoCreatedBy
return|;
block|}
end_function
begin_function
DECL|function|singleFile
name|MetaInfoSingleFile
name|MetaInfo
operator|::
name|singleFile
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoSingleFile
return|;
block|}
end_function
begin_function
DECL|function|multiFiles
name|QList
argument_list|<
name|MetaInfoMultiFile
argument_list|>
name|MetaInfo
operator|::
name|multiFiles
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoMultiFiles
return|;
block|}
end_function
begin_function
DECL|function|name
name|QString
name|MetaInfo
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoName
return|;
block|}
end_function
begin_function
DECL|function|pieceLength
name|int
name|MetaInfo
operator|::
name|pieceLength
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoPieceLength
return|;
block|}
end_function
begin_function
DECL|function|sha1Sums
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|MetaInfo
operator|::
name|sha1Sums
parameter_list|()
specifier|const
block|{
return|return
name|metaInfoSha1Sums
return|;
block|}
end_function
begin_function
DECL|function|totalSize
name|qint64
name|MetaInfo
operator|::
name|totalSize
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|fileForm
argument_list|()
operator|==
name|SingleFileForm
condition|)
return|return
name|singleFile
argument_list|()
operator|.
name|length
return|;
name|qint64
name|size
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|MetaInfoMultiFile
name|file
decl|,
name|multiFiles
argument_list|()
control|)
name|size
operator|+=
name|file
operator|.
name|length
expr_stmt|;
return|return
name|size
return|;
block|}
end_function
end_unit
