begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEFFECTS_P_H
end_ifndef
begin_define
DECL|macro|QEFFECTS_P_H
define|#
directive|define
name|QEFFECTS_P_H
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
comment|// of qeffects.cpp, qcombobox.cpp, qpopupmenu.cpp and qtooltip.cpp.
end_comment
begin_comment
comment|// This header file may change from version to version without notice,
end_comment
begin_comment
comment|// or even be removed.
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
file|"QtCore/qnamespace.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_EFFECTS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QEffects
struct|struct
name|QEffects
block|{
DECL|enum|Direction
enum|enum
name|Direction
block|{
DECL|enumerator|LeftScroll
name|LeftScroll
init|=
literal|0x0001
block|,
DECL|enumerator|RightScroll
name|RightScroll
init|=
literal|0x0002
block|,
DECL|enumerator|UpScroll
name|UpScroll
init|=
literal|0x0004
block|,
DECL|enumerator|DownScroll
name|DownScroll
init|=
literal|0x0008
block|}
enum|;
DECL|typedef|DirFlags
typedef|typedef
name|uint
name|DirFlags
typedef|;
block|}
struct|;
end_struct
begin_decl_stmt
specifier|extern
name|void
name|Q_GUI_EXPORT
name|qScrollEffect
argument_list|(
name|QWidget
operator|*
argument_list|,
name|QEffects
operator|::
name|DirFlags
name|dir
operator|=
name|QEffects
operator|::
name|DownScroll
argument_list|,
name|int
name|time
operator|=
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|extern
name|void
name|Q_GUI_EXPORT
name|qFadeEffect
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
name|int
name|time
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_EFFECTS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QEFFECTS_P_H
end_comment
end_unit
