begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLE_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLE_H
define|#
directive|define
name|QACCESSIBLE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
DECL|variable|QAccessibleInterface
name|class
name|QAccessibleInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleEvent
name|class
name|QAccessibleEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_comment
comment|// We need to inherit QObject to expose the enums to QML.
end_comment
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessible
ifndef|#
directive|ifndef
name|qdoc
range|:
name|public
name|QObject
endif|#
directive|endif
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|Role Event State
argument_list|)
name|public
operator|:
expr|enum
name|Event
block|{
name|SoundPlayed
operator|=
literal|0x0001
block|,
name|Alert
operator|=
literal|0x0002
block|,
name|ForegroundChanged
operator|=
literal|0x0003
block|,
name|MenuStart
operator|=
literal|0x0004
block|,
name|MenuEnd
operator|=
literal|0x0005
block|,
name|PopupMenuStart
operator|=
literal|0x0006
block|,
name|PopupMenuEnd
operator|=
literal|0x0007
block|,
name|ContextHelpStart
operator|=
literal|0x000C
block|,
name|ContextHelpEnd
operator|=
literal|0x000D
block|,
name|DragDropStart
operator|=
literal|0x000E
block|,
name|DragDropEnd
operator|=
literal|0x000F
block|,
name|DialogStart
operator|=
literal|0x0010
block|,
name|DialogEnd
operator|=
literal|0x0011
block|,
name|ScrollingStart
operator|=
literal|0x0012
block|,
name|ScrollingEnd
operator|=
literal|0x0013
block|,
name|MenuCommand
operator|=
literal|0x0018
block|,
comment|// Values from IAccessible2
name|ActionChanged
operator|=
literal|0x0101
block|,
name|ActiveDescendantChanged
operator|=
literal|0x0102
block|,
name|AttributeChanged
operator|=
literal|0x0103
block|,
name|DocumentContentChanged
operator|=
literal|0x0104
block|,
name|DocumentLoadComplete
operator|=
literal|0x0105
block|,
name|DocumentLoadStopped
operator|=
literal|0x0106
block|,
name|DocumentReload
operator|=
literal|0x0107
block|,
name|HyperlinkEndIndexChanged
operator|=
literal|0x0108
block|,
name|HyperlinkNumberOfAnchorsChanged
operator|=
literal|0x0109
block|,
name|HyperlinkSelectedLinkChanged
operator|=
literal|0x010A
block|,
name|HypertextLinkActivated
operator|=
literal|0x010B
block|,
name|HypertextLinkSelected
operator|=
literal|0x010C
block|,
name|HyperlinkStartIndexChanged
operator|=
literal|0x010D
block|,
name|HypertextChanged
operator|=
literal|0x010E
block|,
name|HypertextNLinksChanged
operator|=
literal|0x010F
block|,
name|ObjectAttributeChanged
operator|=
literal|0x0110
block|,
name|PageChanged
operator|=
literal|0x0111
block|,
name|SectionChanged
operator|=
literal|0x0112
block|,
name|TableCaptionChanged
operator|=
literal|0x0113
block|,
name|TableColumnDescriptionChanged
operator|=
literal|0x0114
block|,
name|TableColumnHeaderChanged
operator|=
literal|0x0115
block|,
name|TableModelChanged
operator|=
literal|0x0116
block|,
name|TableRowDescriptionChanged
operator|=
literal|0x0117
block|,
name|TableRowHeaderChanged
operator|=
literal|0x0118
block|,
name|TableSummaryChanged
operator|=
literal|0x0119
block|,
name|TextAttributeChanged
operator|=
literal|0x011A
block|,
name|TextCaretMoved
operator|=
literal|0x011B
block|,
comment|// TextChanged = 0x011C, is deprecated in IA2, use TextUpdated
name|TextColumnChanged
operator|=
literal|0x011D
block|,
name|TextInserted
operator|=
literal|0x011E
block|,
name|TextRemoved
operator|=
literal|0x011F
block|,
name|TextUpdated
operator|=
literal|0x0120
block|,
name|TextSelectionChanged
operator|=
literal|0x0121
block|,
name|VisibleDataChanged
operator|=
literal|0x0122
block|,
name|ObjectCreated
operator|=
literal|0x8000
block|,
name|ObjectDestroyed
operator|=
literal|0x8001
block|,
name|ObjectShow
operator|=
literal|0x8002
block|,
name|ObjectHide
operator|=
literal|0x8003
block|,
name|ObjectReorder
operator|=
literal|0x8004
block|,
name|Focus
operator|=
literal|0x8005
block|,
name|Selection
operator|=
literal|0x8006
block|,
name|SelectionAdd
operator|=
literal|0x8007
block|,
name|SelectionRemove
operator|=
literal|0x8008
block|,
name|SelectionWithin
operator|=
literal|0x8009
block|,
name|StateChanged
operator|=
literal|0x800A
block|,
name|LocationChanged
operator|=
literal|0x800B
block|,
name|NameChanged
operator|=
literal|0x800C
block|,
name|DescriptionChanged
operator|=
literal|0x800D
block|,
name|ValueChanged
operator|=
literal|0x800E
block|,
name|ParentChanged
operator|=
literal|0x800F
block|,
name|HelpChanged
operator|=
literal|0x80A0
block|,
name|DefaultActionChanged
operator|=
literal|0x80B0
block|,
name|AcceleratorChanged
operator|=
literal|0x80C0
block|}
block|;
comment|// 64 bit enums seem hard on some platforms (windows...)
comment|// which makes using a bit field a sensible alternative
block|struct
name|State
block|{
comment|// http://msdn.microsoft.com/en-us/library/ms697270.aspx
name|quint64
name|disabled
operator|:
literal|1
block|;
comment|// used to be Unavailable
name|quint64
name|selected
operator|:
literal|1
block|;
name|quint64
name|focusable
operator|:
literal|1
block|;
name|quint64
name|focused
operator|:
literal|1
block|;
name|quint64
name|pressed
operator|:
literal|1
block|;
name|quint64
name|checkable
operator|:
literal|1
block|;
name|quint64
name|checked
operator|:
literal|1
block|;
name|quint64
name|checkStateMixed
operator|:
literal|1
block|;
comment|// used to be Mixed
name|quint64
name|readOnly
operator|:
literal|1
block|;
name|quint64
name|hotTracked
operator|:
literal|1
block|;
name|quint64
name|defaultButton
operator|:
literal|1
block|;
name|quint64
name|expanded
operator|:
literal|1
block|;
name|quint64
name|collapsed
operator|:
literal|1
block|;
name|quint64
name|busy
operator|:
literal|1
block|;
name|quint64
name|expandable
operator|:
literal|1
block|;
name|quint64
name|marqueed
operator|:
literal|1
block|;
name|quint64
name|animated
operator|:
literal|1
block|;
name|quint64
name|invisible
operator|:
literal|1
block|;
name|quint64
name|offscreen
operator|:
literal|1
block|;
name|quint64
name|sizeable
operator|:
literal|1
block|;
name|quint64
name|movable
operator|:
literal|1
block|;
name|quint64
name|selfVoicing
operator|:
literal|1
block|;
name|quint64
name|selectable
operator|:
literal|1
block|;
name|quint64
name|linked
operator|:
literal|1
block|;
name|quint64
name|traversed
operator|:
literal|1
block|;
name|quint64
name|multiSelectable
operator|:
literal|1
block|;
name|quint64
name|extSelectable
operator|:
literal|1
block|;
name|quint64
name|passwordEdit
operator|:
literal|1
block|;
comment|// used to be Protected
name|quint64
name|hasPopup
operator|:
literal|1
block|;
name|quint64
name|modal
operator|:
literal|1
block|;
comment|// IA2 - we chose to not add some IA2 states for now
comment|// Below the ones that seem helpful
name|quint64
name|active
operator|:
literal|1
block|;
name|quint64
name|invalid
operator|:
literal|1
block|;
comment|// = defunct
name|quint64
name|editable
operator|:
literal|1
block|;
name|quint64
name|multiLine
operator|:
literal|1
block|;
name|quint64
name|selectableText
operator|:
literal|1
block|;
name|quint64
name|supportsAutoCompletion
operator|:
literal|1
block|;
comment|// quint64 horizontal : 1;
comment|// quint64 vertical : 1;
comment|// quint64 invalidEntry : 1;
comment|// quint64 managesDescendants : 1;
comment|// quint64 singleLine : 1; // we have multi line, this is redundant.
comment|// quint64 stale : 1;
comment|// quint64 transient : 1;
comment|// quint64 pinned : 1;
comment|// Apple - see http://mattgemmell.com/2010/12/19/accessibility-for-iphone-and-ipad-apps/
comment|// quint64 playsSound : 1;
comment|// quint64 summaryElement : 1;
comment|// quint64 updatesFrequently : 1;
comment|// quint64 adjustable : 1;
comment|// more and not included here: http://developer.apple.com/library/mac/#documentation/UserExperience/Reference/Accessibility_RoleAttribute_Ref/Attributes.html
comment|// MSAA
comment|// quint64 alertLow : 1;
comment|// quint64 alertMedium : 1;
comment|// quint64 alertHigh : 1;
name|State
argument_list|()
block|{
name|qMemSet
argument_list|(
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|State
argument_list|)
argument_list|)
block|;         }
block|}
block|;          enum
name|Role
block|{
name|NoRole
operator|=
literal|0x00000000
block|,
name|TitleBar
operator|=
literal|0x00000001
block|,
name|MenuBar
operator|=
literal|0x00000002
block|,
name|ScrollBar
operator|=
literal|0x00000003
block|,
name|Grip
operator|=
literal|0x00000004
block|,
name|Sound
operator|=
literal|0x00000005
block|,
name|Cursor
operator|=
literal|0x00000006
block|,
name|Caret
operator|=
literal|0x00000007
block|,
name|AlertMessage
operator|=
literal|0x00000008
block|,
name|Window
operator|=
literal|0x00000009
block|,
name|Client
operator|=
literal|0x0000000A
block|,
name|PopupMenu
operator|=
literal|0x0000000B
block|,
name|MenuItem
operator|=
literal|0x0000000C
block|,
name|ToolTip
operator|=
literal|0x0000000D
block|,
name|Application
operator|=
literal|0x0000000E
block|,
name|Document
operator|=
literal|0x0000000F
block|,
name|Pane
operator|=
literal|0x00000010
block|,
name|Chart
operator|=
literal|0x00000011
block|,
name|Dialog
operator|=
literal|0x00000012
block|,
name|Border
operator|=
literal|0x00000013
block|,
name|Grouping
operator|=
literal|0x00000014
block|,
name|Separator
operator|=
literal|0x00000015
block|,
name|ToolBar
operator|=
literal|0x00000016
block|,
name|StatusBar
operator|=
literal|0x00000017
block|,
name|Table
operator|=
literal|0x00000018
block|,
name|ColumnHeader
operator|=
literal|0x00000019
block|,
name|RowHeader
operator|=
literal|0x0000001A
block|,
name|Column
operator|=
literal|0x0000001B
block|,
name|Row
operator|=
literal|0x0000001C
block|,
name|Cell
operator|=
literal|0x0000001D
block|,
name|Link
operator|=
literal|0x0000001E
block|,
name|HelpBalloon
operator|=
literal|0x0000001F
block|,
name|Assistant
operator|=
literal|0x00000020
block|,
name|List
operator|=
literal|0x00000021
block|,
name|ListItem
operator|=
literal|0x00000022
block|,
name|Tree
operator|=
literal|0x00000023
block|,
name|TreeItem
operator|=
literal|0x00000024
block|,
name|PageTab
operator|=
literal|0x00000025
block|,
name|PropertyPage
operator|=
literal|0x00000026
block|,
name|Indicator
operator|=
literal|0x00000027
block|,
name|Graphic
operator|=
literal|0x00000028
block|,
name|StaticText
operator|=
literal|0x00000029
block|,
name|EditableText
operator|=
literal|0x0000002A
block|,
comment|// Editable, selectable, etc.
name|Button
operator|=
literal|0x0000002B
block|,
ifndef|#
directive|ifndef
name|qdoc
name|PushButton
operator|=
name|Button
block|,
comment|// deprecated
endif|#
directive|endif
name|CheckBox
operator|=
literal|0x0000002C
block|,
name|RadioButton
operator|=
literal|0x0000002D
block|,
name|ComboBox
operator|=
literal|0x0000002E
block|,
comment|// DropList       = 0x0000002F,
name|ProgressBar
operator|=
literal|0x00000030
block|,
name|Dial
operator|=
literal|0x00000031
block|,
name|HotkeyField
operator|=
literal|0x00000032
block|,
name|Slider
operator|=
literal|0x00000033
block|,
name|SpinBox
operator|=
literal|0x00000034
block|,
name|Canvas
operator|=
literal|0x00000035
block|,
name|Animation
operator|=
literal|0x00000036
block|,
name|Equation
operator|=
literal|0x00000037
block|,
name|ButtonDropDown
operator|=
literal|0x00000038
block|,
name|ButtonMenu
operator|=
literal|0x00000039
block|,
name|ButtonDropGrid
operator|=
literal|0x0000003A
block|,
name|Whitespace
operator|=
literal|0x0000003B
block|,
name|PageTabList
operator|=
literal|0x0000003C
block|,
name|Clock
operator|=
literal|0x0000003D
block|,
name|Splitter
operator|=
literal|0x0000003E
block|,
comment|// Additional Qt roles where enum value does not map directly to MSAA:
name|LayeredPane
operator|=
literal|0x0000003F
block|,
name|Terminal
operator|=
literal|0x00000040
block|,
name|UserRole
operator|=
literal|0x0000ffff
block|}
block|;      enum
name|Text
block|{
name|Name
operator|=
literal|0
block|,
name|Description
block|,
name|Value
block|,
name|Help
block|,
name|Accelerator
block|,
name|DebugDescription
block|,
name|UserText
operator|=
literal|0x0000ffff
block|}
block|;      enum
name|RelationFlag
block|{
name|Label
operator|=
literal|0x00020000
block|,
name|Labelled
operator|=
literal|0x00040000
block|,
name|Controller
operator|=
literal|0x00080000
block|,
name|Controlled
operator|=
literal|0x00100000
block|,
name|AllRelations
operator|=
literal|0xffffffff
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|Relation
argument_list|,
name|RelationFlag
argument_list|)
expr|enum
name|InterfaceType
block|{
name|TextInterface
block|,
name|EditableTextInterface
block|,
name|ValueInterface
block|,
name|ActionInterface
block|,
name|ImageInterface
block|,
name|TableInterface
block|,
name|TableCellInterface
block|}
block|;
typedef|typedef
name|QAccessibleInterface
modifier|*
function_decl|(
modifier|*
name|InterfaceFactory
function_decl|)
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|QObject
modifier|*
parameter_list|)
function_decl|;
end_decl_stmt
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|UpdateHandler
function_decl|)
parameter_list|(
specifier|const
name|QAccessibleEvent
modifier|&
name|event
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|RootObjectHandler
function_decl|)
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
specifier|static
name|void
name|installFactory
parameter_list|(
name|InterfaceFactory
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|removeFactory
parameter_list|(
name|InterfaceFactory
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|UpdateHandler
name|installUpdateHandler
parameter_list|(
name|UpdateHandler
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|RootObjectHandler
name|installRootObjectHandler
parameter_list|(
name|RootObjectHandler
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QAccessibleInterface
modifier|*
name|queryAccessibleInterface
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|updateAccessibility
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
name|int
name|child
parameter_list|,
name|Event
name|reason
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|updateAccessibility
parameter_list|(
specifier|const
name|QAccessibleEvent
modifier|&
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isActive
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|setRootObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|cleanup
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
specifier|static
name|UpdateHandler
name|updateHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|RootObjectHandler
name|rootObjectHandler
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*! @internal       This class is purely a collection of enums and static functions,       it is not supposed to be instantiated.     */
end_comment
begin_macro
name|QAccessible
argument_list|()
end_macro
begin_block
block|{}
end_block
begin_expr_stmt
unit|};
name|Q_GUI_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QAccessible
operator|::
name|State
operator|&
name|first
operator|,
specifier|const
name|QAccessible
operator|::
name|State
operator|&
name|second
operator|)
expr_stmt|;
end_expr_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAccessible::Relation
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|QAccessible2Interface
name|class
name|QAccessible2Interface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTextInterface
name|class
name|QAccessibleTextInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleEditableTextInterface
name|class
name|QAccessibleEditableTextInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleValueInterface
name|class
name|QAccessibleValueInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleActionInterface
name|class
name|QAccessibleActionInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleImageInterface
name|class
name|QAccessibleImageInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTableInterface
name|class
name|QAccessibleTableInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTableCellInterface
name|class
name|QAccessibleTableCellInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessibleInterface
argument_list|()
block|{}
comment|// check for valid pointers
name|virtual
name|bool
name|isValid
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QObject
operator|*
name|object
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QWindow
operator|*
name|window
argument_list|()
specifier|const
expr_stmt|;
comment|// relations
name|virtual
name|QVector
operator|<
name|QPair
operator|<
name|QAccessibleInterface
operator|*
operator|,
name|QAccessible
operator|::
name|Relation
operator|>
expr|>
name|relations
argument_list|(
argument|QAccessible::Relation match = QAccessible::AllRelations
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|QAccessibleInterface
operator|*
name|focusChild
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QAccessibleInterface
modifier|*
name|childAt
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// navigation, hierarchy
name|virtual
name|QAccessibleInterface
operator|*
name|parent
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QAccessibleInterface
modifier|*
name|child
argument_list|(
name|int
name|index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|int
name|childCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|int
name|indexOfChild
argument_list|(
specifier|const
name|QAccessibleInterface
operator|*
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// properties and state
name|virtual
name|QString
name|text
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|setText
argument_list|(
name|QAccessible
operator|::
name|Text
name|t
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|QRect
name|rect
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QAccessible
operator|::
name|Role
name|role
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QAccessible
operator|::
name|State
name|state
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QColor
name|foregroundColor
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QColor
name|backgroundColor
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|QAccessibleTextInterface
modifier|*
name|textInterface
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleTextInterface
operator|*
operator|>
operator|(
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|TextInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleEditableTextInterface
modifier|*
name|editableTextInterface
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleEditableTextInterface
operator|*
operator|>
operator|(
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|EditableTextInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleValueInterface
modifier|*
name|valueInterface
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleValueInterface
operator|*
operator|>
operator|(
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|ValueInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleActionInterface
modifier|*
name|actionInterface
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleActionInterface
operator|*
operator|>
operator|(
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|ActionInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleImageInterface
modifier|*
name|imageInterface
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleImageInterface
operator|*
operator|>
operator|(
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|ImageInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleTableInterface
modifier|*
name|tableInterface
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleTableInterface
operator|*
operator|>
operator|(
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|TableInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleTableCellInterface
modifier|*
name|tableCellInterface
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleTableCellInterface
operator|*
operator|>
operator|(
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|TableCellInterface
argument_list|)
operator|)
return|;
block|}
name|virtual
name|void
name|virtual_hook
parameter_list|(
name|int
name|id
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
name|virtual
name|void
modifier|*
name|interface_cast
argument_list|(
name|QAccessible
operator|::
name|InterfaceType
argument_list|)
block|{
return|return
literal|0
return|;
block|}
name|private
label|:
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleEvent
block|{
name|public
label|:
specifier|inline
name|QAccessibleEvent
argument_list|(
argument|QAccessible::Event typ
argument_list|,
argument|QObject *obj
argument_list|,
argument|int chld = -
literal|1
argument_list|)
operator|:
name|m_type
argument_list|(
name|typ
argument_list|)
operator|,
name|m_object
argument_list|(
name|obj
argument_list|)
operator|,
name|m_child
argument_list|(
argument|chld
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|obj
argument_list|)
block|;     }
name|QAccessible
operator|::
name|Event
name|type
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|{
return|return
name|m_object
return|;
block|}
name|int
name|child
argument_list|()
specifier|const
block|{
return|return
name|m_child
return|;
block|}
name|QAccessibleInterface
operator|*
name|accessibleInterface
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QAccessible
operator|::
name|Event
name|m_type
expr_stmt|;
name|QObject
modifier|*
name|m_object
decl_stmt|;
name|int
name|m_child
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|QAccessibleInterface_iid
define|#
directive|define
name|QAccessibleInterface_iid
value|"org.qt-project.Qt.QAccessibleInterface"
end_define
begin_macro
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QAccessibleInterface
argument_list|,
argument|QAccessibleInterface_iid
argument_list|)
end_macro
begin_decl_stmt
name|Q_GUI_EXPORT
specifier|const
name|char
modifier|*
name|qAccessibleRoleString
argument_list|(
name|QAccessible
operator|::
name|Role
name|role
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Q_GUI_EXPORT
specifier|const
name|char
modifier|*
name|qAccessibleEventString
argument_list|(
name|QAccessible
operator|::
name|Event
name|event
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
DECL|variable|operator
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QAccessibleInterface
operator|*
name|iface
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACCESSIBLE_H
end_comment
end_unit
