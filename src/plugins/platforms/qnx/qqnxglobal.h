begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2014 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXGLOBAL_H
end_ifndef
begin_define
DECL|macro|QQNXGLOBAL_H
define|#
directive|define
name|QQNXGLOBAL_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|void
name|qScreenCheckError
parameter_list|(
name|int
name|rc
parameter_list|,
specifier|const
name|char
modifier|*
name|funcInfo
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
name|bool
name|critical
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|Q_SCREEN_CHECKERROR
define|#
directive|define
name|Q_SCREEN_CHECKERROR
parameter_list|(
name|x
parameter_list|,
name|message
parameter_list|)
define|\
value|qScreenCheckError(x, Q_FUNC_INFO, message, false)
end_define
begin_define
DECL|macro|Q_SCREEN_CRITICALERROR
define|#
directive|define
name|Q_SCREEN_CRITICALERROR
parameter_list|(
name|x
parameter_list|,
name|message
parameter_list|)
define|\
value|qScreenCheckError(x, Q_FUNC_INFO, message, true)
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQNXGLOBAL_H
end_comment
end_unit