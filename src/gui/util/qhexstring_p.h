begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpolygon.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringbuilder.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QHEXSTRING_P_H
end_ifndef
begin_define
DECL|macro|QHEXSTRING_P_H
define|#
directive|define
name|QHEXSTRING_P_H
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
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|// internal helper. Converts an integer value to an unique string token
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|HexString
name|HexString
block|{
DECL|function|HexString
specifier|inline
name|HexString
argument_list|(
argument|const T t
argument_list|)
operator|:
name|val
argument_list|(
argument|t
argument_list|)
block|{}
DECL|function|write
specifier|inline
name|void
name|write
argument_list|(
argument|QChar *&dest
argument_list|)
specifier|const
block|{
specifier|const
name|ushort
name|hexChars
index|[]
operator|=
block|{
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'9'
block|,
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|}
block|;
specifier|const
name|char
operator|*
name|c
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|char
operator|*
operator|>
operator|(
operator|&
name|val
operator|)
block|;
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
operator|*
name|dest
operator|++
operator|=
name|hexChars
index|[
operator|*
name|c
operator|&
literal|0xf
index|]
expr_stmt|;
operator|*
name|dest
operator|++
operator|=
name|hexChars
index|[
operator|(
operator|*
name|c
operator|&
literal|0xf0
operator|)
operator|>>
literal|4
index|]
expr_stmt|;
operator|++
name|c
expr_stmt|;
block|}
block|}
DECL|member|val
specifier|const
name|T
name|val
expr_stmt|;
end_expr_stmt
begin_comment
unit|};
comment|// specialization to enable fast concatenating of our string tokens to a string
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
DECL|struct|T
name|QConcatenable
operator|<
name|HexString
operator|<
name|T
operator|>
expr|>
block|{
DECL|typedef|type
typedef|typedef
name|HexString
operator|<
name|T
operator|>
name|type
expr_stmt|;
block|enum
DECL|enumerator|ExactSize
block|{
name|ExactSize
operator|=
name|true
block|}
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|int
name|size
argument_list|(
specifier|const
name|HexString
operator|<
name|T
operator|>
operator|&
argument_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|2
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|inline
name|void
name|appendTo
argument_list|(
specifier|const
name|HexString
operator|<
name|T
operator|>
operator|&
name|str
argument_list|,
name|QChar
operator|*
operator|&
name|out
argument_list|)
block|{
name|str
operator|.
name|write
argument_list|(
name|out
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_typedef
DECL|typedef|ConvertTo
typedef|typedef
name|QString
name|ConvertTo
typedef|;
end_typedef
begin_macro
DECL|typedef|ConvertTo
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QHEXSTRING_P_H
end_comment
end_unit
