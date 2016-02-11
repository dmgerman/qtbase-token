begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKEYSEQUENCE_P_H
end_ifndef
begin_define
DECL|macro|QKEYSEQUENCE_P_H
define|#
directive|define
name|QKEYSEQUENCE_P_H
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
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
file|"qkeysequence.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
end_ifndef
begin_struct
DECL|struct|QKeyBinding
struct|struct
name|QKeyBinding
block|{
DECL|member|standardKey
name|QKeySequence
operator|::
name|StandardKey
name|standardKey
expr_stmt|;
DECL|member|priority
name|uchar
name|priority
decl_stmt|;
DECL|member|shortcut
name|uint
name|shortcut
decl_stmt|;
DECL|member|platform
name|uint
name|platform
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QKeySequencePrivate
block|{
name|public
label|:
enum|enum
block|{
name|MaxKeyCount
init|=
literal|4
block|}
enum|;
comment|// also used in QKeySequenceEdit
specifier|inline
name|QKeySequencePrivate
argument_list|()
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
block|{
name|std
operator|::
name|fill_n
argument_list|(
name|key
argument_list|,
name|uint
argument_list|(
name|MaxKeyCount
argument_list|)
argument_list|,
literal|0
argument_list|)
block|;     }
specifier|inline
name|QKeySequencePrivate
argument_list|(
specifier|const
name|QKeySequencePrivate
operator|&
name|copy
argument_list|)
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
block|{
name|std
operator|::
name|copy
argument_list|(
name|copy
operator|.
name|key
argument_list|,
name|copy
operator|.
name|key
operator|+
name|MaxKeyCount
argument_list|,
name|key
argument_list|)
block|;     }
name|QAtomicInt
name|ref
expr_stmt|;
name|int
name|key
index|[
name|MaxKeyCount
index|]
decl_stmt|;
specifier|static
name|QString
name|encodeString
argument_list|(
name|int
name|key
argument_list|,
name|QKeySequence
operator|::
name|SequenceFormat
name|format
argument_list|)
decl_stmt|;
comment|// used in dbusmenu
name|Q_GUI_EXPORT
specifier|static
name|QString
name|keyName
argument_list|(
name|int
name|key
argument_list|,
name|QKeySequence
operator|::
name|SequenceFormat
name|format
argument_list|)
decl_stmt|;
specifier|static
name|int
name|decodeString
argument_list|(
specifier|const
name|QString
operator|&
name|keyStr
argument_list|,
name|QKeySequence
operator|::
name|SequenceFormat
name|format
argument_list|)
decl_stmt|;
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
comment|// QT_NO_SHORTCUT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QKEYSEQUENCE_P_H
end_comment
end_unit
