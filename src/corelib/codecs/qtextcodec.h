begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTCODEC_H
end_ifndef
begin_define
DECL|macro|QTEXTCODEC_H
define|#
directive|define
name|QTEXTCODEC_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_TEXTCODEC
DECL|variable|QTextCodec
name|class
name|QTextCodec
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDecoder
name|class
name|QTextDecoder
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextEncoder
name|class
name|QTextEncoder
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTextCodec
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QTextCodec
argument_list|)
name|public
label|:
specifier|static
name|QTextCodec
modifier|*
name|codecForName
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|QTextCodec
modifier|*
name|codecForName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|codecForName
argument_list|(
name|QByteArray
argument_list|(
name|name
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|QTextCodec
modifier|*
name|codecForMib
parameter_list|(
name|int
name|mib
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|availableCodecs
argument_list|()
expr_stmt|;
specifier|static
name|QList
operator|<
name|int
operator|>
name|availableMibs
argument_list|()
expr_stmt|;
specifier|static
name|QTextCodec
modifier|*
name|codecForLocale
parameter_list|()
function_decl|;
specifier|static
name|void
name|setCodecForLocale
parameter_list|(
name|QTextCodec
modifier|*
name|c
parameter_list|)
function_decl|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|static
name|QTextCodec
modifier|*
name|codecForTr
parameter_list|()
block|{
return|return
name|codecForMib
argument_list|(
literal|106
argument_list|)
return|;
comment|/* Utf8 */
block|}
endif|#
directive|endif
specifier|static
name|QTextCodec
modifier|*
name|codecForHtml
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
function_decl|;
specifier|static
name|QTextCodec
modifier|*
name|codecForHtml
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|,
name|QTextCodec
modifier|*
name|defaultCodec
parameter_list|)
function_decl|;
specifier|static
name|QTextCodec
modifier|*
name|codecForUtfText
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
function_decl|;
specifier|static
name|QTextCodec
modifier|*
name|codecForUtfText
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|,
name|QTextCodec
modifier|*
name|defaultCodec
parameter_list|)
function_decl|;
name|bool
name|canEncode
argument_list|(
name|QChar
argument_list|)
decl|const
decl_stmt|;
name|bool
name|canEncode
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
decl|const
decl_stmt|;
name|QString
name|toUnicode
argument_list|(
specifier|const
name|QByteArray
operator|&
argument_list|)
decl|const
decl_stmt|;
name|QString
name|toUnicode
argument_list|(
specifier|const
name|char
operator|*
name|chars
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|fromUnicode
argument_list|(
specifier|const
name|QString
operator|&
name|uc
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|ConversionFlag
block|{
name|DefaultConversion
block|,
name|ConvertInvalidToNull
init|=
literal|0x80000000
block|,
name|IgnoreHeader
init|=
literal|0x1
block|,
name|FreeFunction
init|=
literal|0x2
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ConversionFlags
argument_list|,
argument|ConversionFlag
argument_list|)
struct|struct
name|Q_CORE_EXPORT
name|ConverterState
block|{
name|ConverterState
argument_list|(
argument|ConversionFlags f = DefaultConversion
argument_list|)
block|:
name|flags
argument_list|(
name|f
argument_list|)
operator|,
name|remainingChars
argument_list|(
literal|0
argument_list|)
operator|,
name|invalidChars
argument_list|(
literal|0
argument_list|)
operator|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|state_data
index|[
literal|0
index|]
operator|=
name|state_data
index|[
literal|1
index|]
operator|=
name|state_data
index|[
literal|2
index|]
operator|=
literal|0
block|; }
operator|~
name|ConverterState
argument_list|()
expr_stmt|;
name|ConversionFlags
name|flags
decl_stmt|;
name|int
name|remainingChars
decl_stmt|;
name|int
name|invalidChars
decl_stmt|;
name|uint
name|state_data
index|[
literal|3
index|]
decl_stmt|;
name|void
modifier|*
name|d
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|ConverterState
argument_list|)
block|}
struct|;
name|QString
name|toUnicode
argument_list|(
specifier|const
name|char
operator|*
name|in
argument_list|,
name|int
name|length
argument_list|,
name|ConverterState
operator|*
name|state
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|convertToUnicode
argument_list|(
name|in
argument_list|,
name|length
argument_list|,
name|state
argument_list|)
return|;
block|}
name|QByteArray
name|fromUnicode
argument_list|(
specifier|const
name|QChar
operator|*
name|in
argument_list|,
name|int
name|length
argument_list|,
name|ConverterState
operator|*
name|state
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|convertFromUnicode
argument_list|(
name|in
argument_list|,
name|length
argument_list|,
name|state
argument_list|)
return|;
block|}
name|QTextDecoder
modifier|*
name|makeDecoder
argument_list|(
name|ConversionFlags
name|flags
operator|=
name|DefaultConversion
argument_list|)
decl|const
decl_stmt|;
name|QTextEncoder
modifier|*
name|makeEncoder
argument_list|(
name|ConversionFlags
name|flags
operator|=
name|DefaultConversion
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QByteArray
name|name
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QList
operator|<
name|QByteArray
operator|>
name|aliases
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|mibEnum
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|virtual
name|QString
name|convertToUnicode
argument_list|(
specifier|const
name|char
operator|*
name|in
argument_list|,
name|int
name|length
argument_list|,
name|ConverterState
operator|*
name|state
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QByteArray
name|convertFromUnicode
argument_list|(
specifier|const
name|QChar
operator|*
name|in
argument_list|,
name|int
name|length
argument_list|,
name|ConverterState
operator|*
name|state
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|QTextCodec
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QTextCodec
argument_list|()
expr_stmt|;
name|private
label|:
name|friend
struct_decl|struct
name|QCoreGlobalData
struct_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QTextCodec::ConversionFlags
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTextEncoder
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QTextEncoder
argument_list|)
name|public
label|:
name|explicit
name|QTextEncoder
argument_list|(
specifier|const
name|QTextCodec
operator|*
name|codec
argument_list|)
operator|:
name|c
argument_list|(
name|codec
argument_list|)
operator|,
name|state
argument_list|()
block|{}
name|QTextEncoder
argument_list|(
argument|const QTextCodec *codec
argument_list|,
argument|QTextCodec::ConversionFlags flags
argument_list|)
expr_stmt|;
operator|~
name|QTextEncoder
argument_list|()
expr_stmt|;
name|QByteArray
name|fromUnicode
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
name|QByteArray
name|fromUnicode
parameter_list|(
specifier|const
name|QChar
modifier|*
name|uc
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|bool
name|hasFailure
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|QTextCodec
modifier|*
name|c
decl_stmt|;
name|QTextCodec
operator|::
name|ConverterState
name|state
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTextDecoder
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QTextDecoder
argument_list|)
name|public
label|:
name|explicit
name|QTextDecoder
argument_list|(
specifier|const
name|QTextCodec
operator|*
name|codec
argument_list|)
operator|:
name|c
argument_list|(
name|codec
argument_list|)
operator|,
name|state
argument_list|()
block|{}
name|QTextDecoder
argument_list|(
argument|const QTextCodec *codec
argument_list|,
argument|QTextCodec::ConversionFlags flags
argument_list|)
expr_stmt|;
operator|~
name|QTextDecoder
argument_list|()
expr_stmt|;
name|QString
name|toUnicode
parameter_list|(
specifier|const
name|char
modifier|*
name|chars
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|QString
name|toUnicode
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ba
parameter_list|)
function_decl|;
name|void
name|toUnicode
parameter_list|(
name|QString
modifier|*
name|target
parameter_list|,
specifier|const
name|char
modifier|*
name|chars
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|bool
name|hasFailure
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|QTextCodec
modifier|*
name|c
decl_stmt|;
name|QTextCodec
operator|::
name|ConverterState
name|state
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTCODEC
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTCODEC_H
end_comment
end_unit
