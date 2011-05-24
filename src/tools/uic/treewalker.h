begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TREEWALKER_H
end_ifndef
begin_define
DECL|macro|TREEWALKER_H
define|#
directive|define
name|TREEWALKER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|DomUI
name|class
name|DomUI
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomLayoutDefault
name|class
name|DomLayoutDefault
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomLayoutFunction
name|class
name|DomLayoutFunction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomTabStops
name|class
name|DomTabStops
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomLayout
name|class
name|DomLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomLayoutItem
name|class
name|DomLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomWidget
name|class
name|DomWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomSpacer
name|class
name|DomSpacer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomColor
name|class
name|DomColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomColorGroup
name|class
name|DomColorGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomPalette
name|class
name|DomPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomFont
name|class
name|DomFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomPoint
name|class
name|DomPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomRect
name|class
name|DomRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomSizePolicy
name|class
name|DomSizePolicy
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomSize
name|class
name|DomSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomDate
name|class
name|DomDate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomTime
name|class
name|DomTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomDateTime
name|class
name|DomDateTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomProperty
name|class
name|DomProperty
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomCustomWidgets
name|class
name|DomCustomWidgets
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomCustomWidget
name|class
name|DomCustomWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomAction
name|class
name|DomAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomActionGroup
name|class
name|DomActionGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomActionRef
name|class
name|DomActionRef
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomImages
name|class
name|DomImages
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomImage
name|class
name|DomImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomItem
name|class
name|DomItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomIncludes
name|class
name|DomIncludes
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomInclude
name|class
name|DomInclude
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomString
name|class
name|DomString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomResourcePixmap
name|class
name|DomResourcePixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomResources
name|class
name|DomResources
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomResource
name|class
name|DomResource
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomConnections
name|class
name|DomConnections
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomConnection
name|class
name|DomConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomConnectionHints
name|class
name|DomConnectionHints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomConnectionHint
name|class
name|DomConnectionHint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomScript
name|class
name|DomScript
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomButtonGroups
name|class
name|DomButtonGroups
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomButtonGroup
name|class
name|DomButtonGroup
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|TreeWalker
struct|struct
name|TreeWalker
block|{
DECL|function|~TreeWalker
specifier|inline
name|virtual
operator|~
name|TreeWalker
argument_list|()
block|{}
name|virtual
name|void
name|acceptUI
argument_list|(
name|DomUI
operator|*
name|ui
argument_list|)
expr_stmt|;
name|virtual
name|void
name|acceptLayoutDefault
parameter_list|(
name|DomLayoutDefault
modifier|*
name|layoutDefault
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptLayoutFunction
parameter_list|(
name|DomLayoutFunction
modifier|*
name|layoutFunction
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptTabStops
parameter_list|(
name|DomTabStops
modifier|*
name|tabStops
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptCustomWidgets
parameter_list|(
name|DomCustomWidgets
modifier|*
name|customWidgets
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptCustomWidget
parameter_list|(
name|DomCustomWidget
modifier|*
name|customWidget
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptLayout
parameter_list|(
name|DomLayout
modifier|*
name|layout
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptLayoutItem
parameter_list|(
name|DomLayoutItem
modifier|*
name|layoutItem
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptWidget
parameter_list|(
name|DomWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptSpacer
parameter_list|(
name|DomSpacer
modifier|*
name|spacer
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptColor
parameter_list|(
name|DomColor
modifier|*
name|color
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptColorGroup
parameter_list|(
name|DomColorGroup
modifier|*
name|colorGroup
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptPalette
parameter_list|(
name|DomPalette
modifier|*
name|palette
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptFont
parameter_list|(
name|DomFont
modifier|*
name|font
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptPoint
parameter_list|(
name|DomPoint
modifier|*
name|point
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptRect
parameter_list|(
name|DomRect
modifier|*
name|rect
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptSizePolicy
parameter_list|(
name|DomSizePolicy
modifier|*
name|sizePolicy
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptSize
parameter_list|(
name|DomSize
modifier|*
name|size
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptDate
parameter_list|(
name|DomDate
modifier|*
name|date
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptTime
parameter_list|(
name|DomTime
modifier|*
name|time
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptDateTime
parameter_list|(
name|DomDateTime
modifier|*
name|dateTime
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptProperty
parameter_list|(
name|DomProperty
modifier|*
name|property
parameter_list|)
function_decl|;
DECL|typedef|DomScripts
typedef|typedef
name|QList
operator|<
name|DomScript
operator|*
operator|>
name|DomScripts
expr_stmt|;
DECL|typedef|DomWidgets
typedef|typedef
name|QList
operator|<
name|DomWidget
operator|*
operator|>
name|DomWidgets
expr_stmt|;
name|virtual
name|void
name|acceptWidgetScripts
parameter_list|(
specifier|const
name|DomScripts
modifier|&
parameter_list|,
name|DomWidget
modifier|*
name|node
parameter_list|,
specifier|const
name|DomWidgets
modifier|&
name|childWidgets
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptImages
parameter_list|(
name|DomImages
modifier|*
name|images
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptImage
parameter_list|(
name|DomImage
modifier|*
name|image
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptIncludes
parameter_list|(
name|DomIncludes
modifier|*
name|includes
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptInclude
parameter_list|(
name|DomInclude
modifier|*
name|incl
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptAction
parameter_list|(
name|DomAction
modifier|*
name|action
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptActionGroup
parameter_list|(
name|DomActionGroup
modifier|*
name|actionGroup
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptActionRef
parameter_list|(
name|DomActionRef
modifier|*
name|actionRef
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptConnections
parameter_list|(
name|DomConnections
modifier|*
name|connections
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptConnection
parameter_list|(
name|DomConnection
modifier|*
name|connection
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptConnectionHints
parameter_list|(
name|DomConnectionHints
modifier|*
name|connectionHints
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptConnectionHint
parameter_list|(
name|DomConnectionHint
modifier|*
name|connectionHint
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptButtonGroups
parameter_list|(
specifier|const
name|DomButtonGroups
modifier|*
name|buttonGroups
parameter_list|)
function_decl|;
name|virtual
name|void
name|acceptButtonGroup
parameter_list|(
specifier|const
name|DomButtonGroup
modifier|*
name|buttonGroup
parameter_list|)
function_decl|;
block|}
struct|;
end_struct
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TREEWALKER_H
end_comment
end_unit
