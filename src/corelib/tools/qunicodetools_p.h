begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QUNICODETOOLS_P_H
end_ifndef
begin_define
DECL|macro|QUNICODETOOLS_P_H
define|#
directive|define
name|QUNICODETOOLS_P_H
end_define
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
comment|// of other Qt classes.  This header file may change from version to
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
begin_include
include|#
directive|include
file|<QtCore/qchar.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QCharAttributes
struct|struct
name|Q_PACKED
name|QCharAttributes
block|{
DECL|member|graphemeBoundary
name|uchar
name|graphemeBoundary
range|:
literal|1
decl_stmt|;
DECL|member|wordBreak
name|uchar
name|wordBreak
range|:
literal|1
decl_stmt|;
DECL|member|sentenceBoundary
name|uchar
name|sentenceBoundary
range|:
literal|1
decl_stmt|;
DECL|member|lineBreak
name|uchar
name|lineBreak
range|:
literal|1
decl_stmt|;
DECL|member|whiteSpace
name|uchar
name|whiteSpace
range|:
literal|1
decl_stmt|;
DECL|member|wordStart
name|uchar
name|wordStart
range|:
literal|1
decl_stmt|;
DECL|member|wordEnd
name|uchar
name|wordEnd
range|:
literal|1
decl_stmt|;
DECL|member|mandatoryBreak
name|uchar
name|mandatoryBreak
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QCharAttributes
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|namespace
name|QUnicodeTools
block|{
comment|// ### temporary
struct|struct
name|ScriptItem
block|{
name|int
name|position
decl_stmt|;
name|int
name|script
decl_stmt|;
block|}
struct|;
enum|enum
name|CharAttributeOption
block|{
name|GraphemeBreaks
init|=
literal|0x01
block|,
name|WordBreaks
init|=
literal|0x02
block|,
name|SentenceBreaks
init|=
literal|0x04
block|,
name|LineBreaks
init|=
literal|0x08
block|,
name|WhiteSpaces
init|=
literal|0x10
block|,
name|DefaultOptionsCompat
init|=
name|GraphemeBreaks
operator||
name|LineBreaks
operator||
name|WhiteSpaces
block|,
comment|// ### remove
name|DontClearAttributes
init|=
literal|0x1000
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|CharAttributeOptions
argument_list|,
argument|CharAttributeOption
argument_list|)
comment|// attributes buffer has to have a length of string length + 1
name|Q_CORE_EXPORT
name|void
name|initCharAttributes
parameter_list|(
specifier|const
name|ushort
modifier|*
name|string
parameter_list|,
name|int
name|length
parameter_list|,
specifier|const
name|ScriptItem
modifier|*
name|items
parameter_list|,
name|int
name|numItems
parameter_list|,
name|QCharAttributes
modifier|*
name|attributes
parameter_list|,
name|CharAttributeOptions
name|options
init|=
name|DefaultOptionsCompat
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_comment
comment|// namespace QUnicodeTools
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QUNICODETOOLS_P_H
end_comment
end_unit
