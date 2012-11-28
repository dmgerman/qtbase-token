begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAACCESIBILITY_H
end_ifndef
begin_define
DECL|macro|QCOCOAACCESIBILITY_H
define|#
directive|define
name|QCOCOAACCESIBILITY_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COCOA_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|<qpa/qplatformaccessibility.h>
end_include
begin_decl_stmt
name|class
name|QCococaAccessibility
range|:
name|public
name|QPlatformAccessibility
block|{
name|public
operator|:
name|QCococaAccessibility
argument_list|()
block|;
operator|~
name|QCococaAccessibility
argument_list|()
block|;
name|void
name|notifyAccessibilityUpdate
argument_list|(
name|QAccessibleEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|setRootObject
argument_list|(
name|QObject
operator|*
name|o
argument_list|)
block|;
name|void
name|initialize
argument_list|()
block|;
name|void
name|cleanup
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QCocoaAccessible
block|{
comment|/*     Qt Cocoa Accessibility Overview      Cocoa accessibility is implemented in the following files:      - qcocoaaccessibility (this file) : QCocoaAccessibility "plugin", conversion and helper functions.     - qnsviewaccessibility            : Root accessibility implementation for QNSView     - qcocoaaccessibilityelement      : Cocoa accessibility protocol wrapper for QAccessibleInterface      The accessibility implementation wraps QAccessibleInterfaces in QCocoaAccessibleElements, which     implements the cocoa accessibility protocol. The root QAccessibleInterface (the one returned     by QWindow::accessibleRoot), is anchored to the QNSView in qnsviewaccessibility.mm.      Cocoa explores the accessibility tree by walking the tree using the parent/child     relationships or hit testing. When this happens we create QCocoaAccessibleElements on     demand. */
name|NSString
modifier|*
name|macRole
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
function_decl|;
name|bool
name|shouldBeIgnrored
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
function_decl|;
name|NSString
modifier|*
name|getTranslatedAction
parameter_list|(
specifier|const
name|QString
modifier|&
name|qtAction
parameter_list|)
function_decl|;
name|NSMutableArray
modifier|*
name|createTranslatedActionsList
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|qtActions
parameter_list|)
function_decl|;
name|QString
name|translateAction
parameter_list|(
name|NSString
modifier|*
name|nsAction
parameter_list|)
function_decl|;
name|bool
name|hasValueAttribute
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
function_decl|;
name|id
name|getValueAttribute
parameter_list|(
name|QAccessibleInterface
modifier|*
name|interface
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COCOA_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
