begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DRIVER_H
end_ifndef
begin_define
DECL|macro|DRIVER_H
define|#
directive|define
name|DRIVER_H
end_define
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomUI
name|class
name|DomUI
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
DECL|variable|DomActionGroup
name|class
name|DomActionGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomAction
name|class
name|DomAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomButtonGroup
name|class
name|DomButtonGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Driver
block|{
name|public
label|:
name|Driver
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|Driver
argument_list|()
expr_stmt|;
comment|// tools
name|bool
name|printDependencies
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|bool
name|uic
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QTextStream
modifier|*
name|output
init|=
literal|0
parameter_list|)
function_decl|;
name|bool
name|uic
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|DomUI
modifier|*
name|ui
parameter_list|,
name|QTextStream
modifier|*
name|output
init|=
literal|0
parameter_list|)
function_decl|;
comment|// configuration
specifier|inline
name|QTextStream
operator|&
name|output
argument_list|()
specifier|const
block|{
return|return
operator|*
name|m_output
return|;
block|}
specifier|inline
name|Option
modifier|&
name|option
parameter_list|()
block|{
return|return
name|m_option
return|;
block|}
comment|// initialization
name|void
name|reset
parameter_list|()
function_decl|;
comment|// error
specifier|inline
name|QStringList
name|problems
parameter_list|()
block|{
return|return
name|m_problems
return|;
block|}
specifier|inline
name|void
name|addProblem
parameter_list|(
specifier|const
name|QString
modifier|&
name|problem
parameter_list|)
block|{
name|m_problems
operator|.
name|append
argument_list|(
name|problem
argument_list|)
expr_stmt|;
block|}
comment|// utils
specifier|static
name|QString
name|headerFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|QString
name|headerFileName
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QString
name|normalizedName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|QString
name|qtify
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QString
name|unique
parameter_list|(
specifier|const
name|QString
modifier|&
name|instanceName
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|className
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
comment|// symbol table
name|QString
name|findOrInsertWidget
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|)
function_decl|;
name|QString
name|findOrInsertSpacer
parameter_list|(
name|DomSpacer
modifier|*
name|ui_spacer
parameter_list|)
function_decl|;
name|QString
name|findOrInsertLayout
parameter_list|(
name|DomLayout
modifier|*
name|ui_layout
parameter_list|)
function_decl|;
name|QString
name|findOrInsertLayoutItem
parameter_list|(
name|DomLayoutItem
modifier|*
name|ui_layoutItem
parameter_list|)
function_decl|;
name|QString
name|findOrInsertName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QString
name|findOrInsertActionGroup
parameter_list|(
name|DomActionGroup
modifier|*
name|ui_group
parameter_list|)
function_decl|;
name|QString
name|findOrInsertAction
parameter_list|(
name|DomAction
modifier|*
name|ui_action
parameter_list|)
function_decl|;
name|QString
name|findOrInsertButtonGroup
parameter_list|(
specifier|const
name|DomButtonGroup
modifier|*
name|ui_group
parameter_list|)
function_decl|;
comment|// Find a group by its non-uniqified name
specifier|const
name|DomButtonGroup
modifier|*
name|findButtonGroup
argument_list|(
specifier|const
name|QString
operator|&
name|attributeName
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|bool
name|hasName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
block|{
return|return
name|m_nameRepository
operator|.
name|contains
argument_list|(
name|name
argument_list|)
return|;
block|}
name|DomWidget
modifier|*
name|widgetByName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|DomSpacer
modifier|*
name|spacerByName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|DomLayout
modifier|*
name|layoutByName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|DomActionGroup
modifier|*
name|actionGroupByName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|DomAction
modifier|*
name|actionByName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
comment|// pixmap
name|void
name|insertPixmap
parameter_list|(
specifier|const
name|QString
modifier|&
name|pixmap
parameter_list|)
function_decl|;
name|bool
name|containsPixmap
argument_list|(
specifier|const
name|QString
operator|&
name|pixmap
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|Option
name|m_option
decl_stmt|;
name|QTextStream
name|m_stdout
decl_stmt|;
name|QTextStream
modifier|*
name|m_output
decl_stmt|;
name|QStringList
name|m_problems
decl_stmt|;
comment|// symbol tables
name|QHash
operator|<
name|DomWidget
operator|*
operator|,
name|QString
operator|>
name|m_widgets
expr_stmt|;
name|QHash
operator|<
name|DomSpacer
operator|*
operator|,
name|QString
operator|>
name|m_spacers
expr_stmt|;
name|QHash
operator|<
name|DomLayout
operator|*
operator|,
name|QString
operator|>
name|m_layouts
expr_stmt|;
name|QHash
operator|<
name|DomActionGroup
operator|*
operator|,
name|QString
operator|>
name|m_actionGroups
expr_stmt|;
typedef|typedef
name|QHash
operator|<
specifier|const
name|DomButtonGroup
operator|*
operator|,
name|QString
operator|>
name|ButtonGroupNameHash
expr_stmt|;
name|ButtonGroupNameHash
name|m_buttonGroups
decl_stmt|;
name|QHash
operator|<
name|DomAction
operator|*
operator|,
name|QString
operator|>
name|m_actions
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|bool
operator|>
name|m_nameRepository
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|bool
operator|>
name|m_pixmaps
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DRIVER_H
end_comment
end_unit
