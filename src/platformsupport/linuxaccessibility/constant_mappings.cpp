begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"constant_mappings_p.h"
end_include
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_comment
comment|// FIXME the assignment of roles is quite arbitrary, at some point go through this list and sort and check that it makes sense
end_comment
begin_comment
comment|//  "calendar" "check menu item"  "color chooser" "column header"    "dateeditor"  "desktop icon"  "desktop frame"
end_comment
begin_comment
comment|//  "directory pane"  "drawing area"  "file chooser" "fontchooser"  "frame"  "glass pane"  "html container"  "icon"
end_comment
begin_comment
comment|//  "internal frame"  "option pane"  "password text" "radio menu item"  "root pane"  "row header"    "scroll pane"
end_comment
begin_comment
comment|//  "tear off menu item"  "terminal" "toggle button" "tree table"  "unknown"  "viewport" "header"  "footer"  "paragraph"
end_comment
begin_comment
comment|//  "ruler"    "autocomplete"  "edit bar" "embedded component"  "entry"    "caption"
end_comment
begin_comment
comment|//  "heading"  "page"  "section"  "redundant object"  "form"  "input method window"  "menu"
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|qSpiRoleMapping
name|QHash
argument_list|<
name|QAccessible
operator|::
name|Role
argument_list|,
name|RoleNames
argument_list|>
name|qSpiRoleMapping
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|spiStatesFromQState
name|quint64
name|spiStatesFromQState
parameter_list|(
name|QAccessible
operator|::
name|State
name|state
parameter_list|)
block|{
name|quint64
name|spiState
init|=
literal|0
decl_stmt|;
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_EDITABLE
argument_list|)
expr_stmt|;
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_ENABLED
argument_list|)
expr_stmt|;
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_SHOWING
argument_list|)
expr_stmt|;
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_VISIBLE
argument_list|)
expr_stmt|;
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_SENSITIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|disabled
condition|)
block|{
name|unsetSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_ENABLED
argument_list|)
expr_stmt|;
name|unsetSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_SHOWING
argument_list|)
expr_stmt|;
name|unsetSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_VISIBLE
argument_list|)
expr_stmt|;
name|unsetSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_SENSITIVE
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|.
name|selected
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_SELECTED
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|focused
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_FOCUSED
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|pressed
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_PRESSED
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|checked
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_CHECKED
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|checkStateMixed
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_INDETERMINATE
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|readOnly
condition|)
name|unsetSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_EDITABLE
argument_list|)
expr_stmt|;
comment|//        if (state.HotTracked)
if|if
condition|(
name|state
operator|.
name|defaultButton
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_IS_DEFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|expanded
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_EXPANDED
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|collapsed
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_COLLAPSED
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|busy
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_BUSY
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|marqueed
operator|||
name|state
operator|.
name|animated
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_ANIMATED
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|invisible
operator|||
name|state
operator|.
name|offscreen
condition|)
block|{
name|unsetSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_SHOWING
argument_list|)
expr_stmt|;
name|unsetSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_VISIBLE
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|.
name|sizeable
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_RESIZABLE
argument_list|)
expr_stmt|;
comment|//        if (state.Movable)
comment|//        if (state.SelfVoicing)
if|if
condition|(
name|state
operator|.
name|focusable
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_FOCUSABLE
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|selectable
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_SELECTABLE
argument_list|)
expr_stmt|;
comment|//        if (state.Linked)
if|if
condition|(
name|state
operator|.
name|traversed
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_VISITED
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|multiSelectable
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_MULTISELECTABLE
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|.
name|extSelectable
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_SELECTABLE
argument_list|)
expr_stmt|;
comment|//        if (state.Protected)
comment|//        if (state.HasPopup)
if|if
condition|(
name|state
operator|.
name|modal
condition|)
name|setSpiStateBit
argument_list|(
operator|&
name|spiState
argument_list|,
name|ATSPI_STATE_MODAL
argument_list|)
expr_stmt|;
comment|// Not implemented in Qt
comment|//    if (state.singleLine)
comment|//        setSpiStateBit(&spiState, ATSPI_STATE_SINGLE_LINE);
return|return
name|spiState
return|;
block|}
end_function
begin_function
DECL|function|spiStateSetFromSpiStates
name|QSpiUIntList
name|spiStateSetFromSpiStates
parameter_list|(
name|quint64
name|states
parameter_list|)
block|{
name|uint
name|low
init|=
name|states
operator|&
literal|0xFFFFFFFF
decl_stmt|;
name|uint
name|high
init|=
operator|(
name|states
operator|>>
literal|32
operator|)
operator|&
literal|0xFFFFFFFF
decl_stmt|;
name|QSpiUIntList
name|stateList
decl_stmt|;
name|stateList
operator|.
name|append
argument_list|(
name|low
argument_list|)
expr_stmt|;
name|stateList
operator|.
name|append
argument_list|(
name|high
argument_list|)
expr_stmt|;
return|return
name|stateList
return|;
block|}
end_function
begin_function
DECL|function|qAccessibleRelationToAtSpiRelation
name|AtspiRelationType
name|qAccessibleRelationToAtSpiRelation
parameter_list|(
name|QAccessible
operator|::
name|Relation
name|relation
parameter_list|)
block|{
switch|switch
condition|(
name|relation
condition|)
block|{
case|case
name|QAccessible
operator|::
name|Label
case|:
return|return
name|ATSPI_RELATION_LABELLED_BY
return|;
case|case
name|QAccessible
operator|::
name|Labelled
case|:
return|return
name|ATSPI_RELATION_LABEL_FOR
return|;
case|case
name|QAccessible
operator|::
name|Controller
case|:
return|return
name|ATSPI_RELATION_CONTROLLED_BY
return|;
case|case
name|QAccessible
operator|::
name|Controlled
case|:
return|return
name|ATSPI_RELATION_CONTROLLER_FOR
return|;
default|default:
name|qWarning
argument_list|()
operator|<<
literal|"Cannot return AT-SPI relation for:"
operator|<<
name|relation
expr_stmt|;
block|}
return|return
name|ATSPI_RELATION_NULL
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
