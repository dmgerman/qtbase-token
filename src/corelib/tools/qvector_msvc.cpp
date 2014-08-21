begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Intel Corporation ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// ### Qt6: verify if we can remove this, somehow.
end_comment
begin_comment
comment|// First, try to see if the extern template from qvector.h is necessary.
end_comment
begin_comment
comment|// If it still is, check if removing the copy constructors in qarraydata.h
end_comment
begin_comment
comment|// make the calling convention of both sets of begin() and end() functions
end_comment
begin_comment
comment|// match, as it does for the IA-64 C++ ABI.
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QVECTOR_H
end_ifdef
begin_error
error|#
directive|error
literal|"This file must be compiled with no precompiled headers"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// invert the setting of QT_STRICT_ITERATORS, whichever it was
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_STRICT_ITERATORS
end_ifdef
begin_undef
DECL|macro|QT_STRICT_ITERATORS
undef|#
directive|undef
name|QT_STRICT_ITERATORS
end_undef
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_STRICT_ITERATORS
define|#
directive|define
name|QT_STRICT_ITERATORS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// the Q_TEMPLATE_EXTERN at the bottom of qvector.h will do the trick
end_comment
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
end_unit
