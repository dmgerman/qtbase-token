begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTODFWRITER_H
end_ifndef
begin_define
DECL|macro|QTEXTODFWRITER_H
define|#
directive|define
name|QTEXTODFWRITER_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|<QtCore/QXmlStreamWriter>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstack.h>
end_include
begin_include
include|#
directive|include
file|"qtextdocument_p.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocumentwriter.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextDocumentPrivate
name|class
name|QTextDocumentPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCursor
name|class
name|QTextCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlock
name|class
name|QTextBlock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXmlStreamWriter
name|class
name|QXmlStreamWriter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextOdfWriterPrivate
name|class
name|QTextOdfWriterPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlockFormat
name|class
name|QTextBlockFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCharFormat
name|class
name|QTextCharFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextListFormat
name|class
name|QTextListFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFrameFormat
name|class
name|QTextFrameFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextTableCellFormat
name|class
name|QTextTableCellFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFrame
name|class
name|QTextFrame
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFragment
name|class
name|QTextFragment
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOutputStrategy
name|class
name|QOutputStrategy
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QTextOdfWriter
block|{
name|public
label|:
name|QTextOdfWriter
argument_list|(
specifier|const
name|QTextDocument
operator|&
name|document
argument_list|,
name|QIODevice
operator|*
name|device
argument_list|)
expr_stmt|;
name|bool
name|writeAll
parameter_list|()
function_decl|;
name|void
name|setCodec
parameter_list|(
name|QTextCodec
modifier|*
name|codec
parameter_list|)
block|{
name|m_codec
operator|=
name|codec
expr_stmt|;
block|}
name|void
name|setCreateArchive
parameter_list|(
name|bool
name|on
parameter_list|)
block|{
name|m_createArchive
operator|=
name|on
expr_stmt|;
block|}
name|bool
name|createArchive
argument_list|()
specifier|const
block|{
return|return
name|m_createArchive
return|;
block|}
name|void
name|writeBlock
parameter_list|(
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
function_decl|;
name|void
name|writeFormats
argument_list|(
name|QXmlStreamWriter
operator|&
name|writer
argument_list|,
name|QSet
operator|<
name|int
operator|>
name|formatIds
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeBlockFormat
argument_list|(
name|QXmlStreamWriter
operator|&
name|writer
argument_list|,
name|QTextBlockFormat
name|format
argument_list|,
name|int
name|formatIndex
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeCharacterFormat
argument_list|(
name|QXmlStreamWriter
operator|&
name|writer
argument_list|,
name|QTextCharFormat
name|format
argument_list|,
name|int
name|formatIndex
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeListFormat
argument_list|(
name|QXmlStreamWriter
operator|&
name|writer
argument_list|,
name|QTextListFormat
name|format
argument_list|,
name|int
name|formatIndex
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeFrameFormat
argument_list|(
name|QXmlStreamWriter
operator|&
name|writer
argument_list|,
name|QTextFrameFormat
name|format
argument_list|,
name|int
name|formatIndex
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeTableCellFormat
argument_list|(
name|QXmlStreamWriter
operator|&
name|writer
argument_list|,
name|QTextTableCellFormat
name|format
argument_list|,
name|int
name|formatIndex
argument_list|)
decl|const
decl_stmt|;
name|void
name|writeFrame
parameter_list|(
name|QXmlStreamWriter
modifier|&
name|writer
parameter_list|,
specifier|const
name|QTextFrame
modifier|*
name|frame
parameter_list|)
function_decl|;
name|void
name|writeInlineCharacter
argument_list|(
name|QXmlStreamWriter
operator|&
name|writer
argument_list|,
specifier|const
name|QTextFragment
operator|&
name|fragment
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QString
name|officeNS
decl_stmt|,
name|textNS
decl_stmt|,
name|styleNS
decl_stmt|,
name|foNS
decl_stmt|,
name|tableNS
decl_stmt|,
name|drawNS
decl_stmt|,
name|xlinkNS
decl_stmt|,
name|svgNS
decl_stmt|;
name|private
label|:
specifier|const
name|QTextDocument
modifier|*
name|m_document
decl_stmt|;
name|QIODevice
modifier|*
name|m_device
decl_stmt|;
name|QOutputStrategy
modifier|*
name|m_strategy
decl_stmt|;
name|QTextCodec
modifier|*
name|m_codec
decl_stmt|;
name|bool
name|m_createArchive
decl_stmt|;
name|QStack
operator|<
name|QTextList
operator|*
operator|>
name|m_listStack
expr_stmt|;
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
comment|// QTEXTODFWRITER_H
end_comment
end_unit
