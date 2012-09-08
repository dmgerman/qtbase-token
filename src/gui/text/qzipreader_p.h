begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QZIPREADER_H
end_ifndef
begin_define
DECL|macro|QZIPREADER_H
define|#
directive|define
name|QZIPREADER_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTODFWRITER
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QZipReader class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QZipReaderPrivate
name|class
name|QZipReaderPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QZipReader
block|{
name|public
label|:
name|explicit
name|QZipReader
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|QIODevice
operator|::
name|OpenMode
name|mode
operator|=
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|explicit
name|QZipReader
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
operator|~
name|QZipReader
argument_list|()
expr_stmt|;
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isReadable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|exists
argument_list|()
specifier|const
decl_stmt|;
struct|struct
name|Q_GUI_EXPORT
name|FileInfo
block|{
name|FileInfo
argument_list|()
expr_stmt|;
name|FileInfo
argument_list|(
specifier|const
name|FileInfo
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|FileInfo
argument_list|()
expr_stmt|;
name|FileInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|FileInfo
operator|&
name|other
operator|)
decl_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|filePath
decl_stmt|;
name|uint
name|isDir
range|:
literal|1
decl_stmt|;
name|uint
name|isFile
range|:
literal|1
decl_stmt|;
name|uint
name|isSymLink
range|:
literal|1
decl_stmt|;
name|QFile
operator|::
name|Permissions
name|permissions
expr_stmt|;
name|uint
name|crc
decl_stmt|;
name|qint64
name|size
decl_stmt|;
name|QDateTime
name|lastModified
decl_stmt|;
name|void
modifier|*
name|d
decl_stmt|;
block|}
struct|;
name|QList
operator|<
name|FileInfo
operator|>
name|fileInfoList
argument_list|()
specifier|const
expr_stmt|;
name|int
name|count
argument_list|()
specifier|const
expr_stmt|;
name|FileInfo
name|entryInfoAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|fileData
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
name|bool
name|extractAll
argument_list|(
specifier|const
name|QString
operator|&
name|destinationDir
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|Status
block|{
name|NoError
block|,
name|FileReadError
block|,
name|FileOpenError
block|,
name|FilePermissionsError
block|,
name|FileError
block|}
enum|;
name|Status
name|status
argument_list|()
specifier|const
expr_stmt|;
name|void
name|close
parameter_list|()
function_decl|;
name|private
label|:
name|QZipReaderPrivate
modifier|*
name|d
decl_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QZipReader
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTODFWRITER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QZIPREADER_H
end_comment
end_unit
