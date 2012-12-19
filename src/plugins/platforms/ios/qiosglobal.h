begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIOSGLOBAL_H
end_ifndef
begin_define
DECL|macro|QIOSGLOBAL_H
define|#
directive|define
name|QIOSGLOBAL_H
end_define
begin_empty
empty|#import<UIKit/UIKit.h>
end_empty
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_decl_stmt
unit|@
DECL|variable|QIOSViewController
name|class
name|QIOSViewController
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|bool
name|isQtApplication
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|QIOSViewController
modifier|*
name|rootViewController
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|CGRect
name|toCGRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QRect
name|fromCGRect
parameter_list|(
specifier|const
name|CGRect
modifier|&
name|rect
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Qt
operator|::
name|ScreenOrientation
name|toQtScreenOrientation
argument_list|(
argument|UIDeviceOrientation uiDeviceOrientation
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|UIDeviceOrientation
name|fromQtScreenOrientation
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|qtOrientation
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QRect
name|fromPortraitToPrimary
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
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
comment|// QIOSGLOBAL_H
end_comment
end_unit
