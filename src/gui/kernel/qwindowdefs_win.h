begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWDEFS_WIN_H
end_ifndef
begin_define
DECL|macro|QWINDOWDEFS_WIN_H
define|#
directive|define
name|QWINDOWDEFS_WIN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|QT_END_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_NOWINSTRICT
argument_list|)
DECL|macro|Q_WINSTRICT
define|#
directive|define
name|Q_WINSTRICT
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WINSTRICT
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STRICT
argument_list|)
DECL|macro|STRICT
define|#
directive|define
name|STRICT
endif|#
directive|endif
DECL|macro|NO_STRICT
undef|#
directive|undef
name|NO_STRICT
DECL|macro|Q_DECLARE_HANDLE
define|#
directive|define
name|Q_DECLARE_HANDLE
parameter_list|(
name|name
parameter_list|)
value|struct name##__; typedef struct name##__ *name
else|#
directive|else
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_STRICT
argument_list|)
define|#
directive|define
name|NO_STRICT
endif|#
directive|endif
undef|#
directive|undef
name|STRICT
define|#
directive|define
name|Q_DECLARE_HANDLE
parameter_list|(
name|name
parameter_list|)
value|typedef HANDLE name
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HINSTANCE
name|Q_DECLARE_HANDLE
parameter_list|(
name|HINSTANCE
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HDC
end_ifndef
begin_expr_stmt
DECL|variable|HDC
name|Q_DECLARE_HANDLE
argument_list|(
name|HDC
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HWND
end_ifndef
begin_expr_stmt
DECL|variable|HWND
name|Q_DECLARE_HANDLE
argument_list|(
name|HWND
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HFONT
end_ifndef
begin_expr_stmt
DECL|variable|HFONT
name|Q_DECLARE_HANDLE
argument_list|(
name|HFONT
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HPEN
end_ifndef
begin_expr_stmt
DECL|variable|HPEN
name|Q_DECLARE_HANDLE
argument_list|(
name|HPEN
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HBRUSH
end_ifndef
begin_expr_stmt
DECL|variable|HBRUSH
name|Q_DECLARE_HANDLE
argument_list|(
name|HBRUSH
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HBITMAP
end_ifndef
begin_expr_stmt
DECL|variable|HBITMAP
name|Q_DECLARE_HANDLE
argument_list|(
name|HBITMAP
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HICON
end_ifndef
begin_expr_stmt
DECL|variable|HICON
name|Q_DECLARE_HANDLE
argument_list|(
name|HICON
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HCURSOR
end_ifndef
begin_typedef
DECL|typedef|HCURSOR
typedef|typedef
name|HICON
name|HCURSOR
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HPALETTE
end_ifndef
begin_expr_stmt
DECL|variable|HPALETTE
name|Q_DECLARE_HANDLE
argument_list|(
name|HPALETTE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HRGN
end_ifndef
begin_expr_stmt
DECL|variable|HRGN
name|Q_DECLARE_HANDLE
argument_list|(
name|HRGN
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HMONITOR
end_ifndef
begin_expr_stmt
DECL|variable|HMONITOR
name|Q_DECLARE_HANDLE
argument_list|(
name|HMONITOR
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|_HRESULT_DEFINED
end_ifndef
begin_typedef
DECL|typedef|HRESULT
typedef|typedef
name|long
name|HRESULT
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|MSG
typedef|typedef
name|struct
name|tagMSG
name|MSG
typedef|;
end_typedef
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_CORE_EXPORT
name|HINSTANCE
name|qWinAppInst
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|HINSTANCE
name|qWinAppPrevInst
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|qWinAppCmdShow
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|HDC
name|qt_win_display_dc
parameter_list|()
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
comment|// QWINDOWDEFS_WIN_H
end_comment
end_unit
