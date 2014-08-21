begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAACCESIBILITYELEMENT_H
end_ifndef
begin_define
DECL|macro|QCOCOAACCESIBILITYELEMENT_H
define|#
directive|define
name|QCOCOAACCESIBILITYELEMENT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|"qt_mac_p.h"
end_include
begin_empty
empty|#import<Cocoa/Cocoa.h>
end_empty
begin_empty
empty|#import<AppKit/NSAccessibility.h>
end_empty
begin_empty
empty|#import<qaccessible.h>
end_empty
begin_function_decl
unit|@
name|class
name|QT_MANGLE_NAMESPACE
parameter_list|(
name|QMacAccessibilityElement
parameter_list|)
function_decl|;
end_function_decl
begin_macro
unit|@
DECL|function|QT_MANGLE_NAMESPACE
name|interface
end_macro
begin_expr_stmt
DECL|function|QT_MANGLE_NAMESPACE
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QMacAccessibilityElement
argument_list|)
operator|:
name|NSObject
block|{
name|NSString
operator|*
name|role
block|;
name|QAccessible
operator|::
name|Id
name|axid
block|; }
operator|-
operator|(
name|id
operator|)
name|initWithId
operator|:
operator|(
name|QAccessible
operator|::
name|Id
operator|)
name|anId
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|+
operator|(
name|QT_MANGLE_NAMESPACE
argument_list|(
name|QMacAccessibilityElement
argument_list|)
operator|*
operator|)
name|elementWithId
operator|:
operator|(
name|QAccessible
operator|::
name|Id
operator|)
name|anId
expr_stmt|;
end_expr_stmt
begin_function_decl
unit|@
name|end
DECL|variable|QT_NAMESPACE_ALIAS_OBJC_CLASS
name|QT_NAMESPACE_ALIAS_OBJC_CLASS
parameter_list|(
name|QMacAccessibilityElement
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
end_unit
