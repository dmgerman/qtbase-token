begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTYLE_H
end_ifndef
begin_define
DECL|macro|QSTYLE_H
define|#
directive|define
name|QSTYLE_H
end_define
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
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpalette.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qsizepolicy.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTab
name|class
name|QTab
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontMetrics
name|class
name|QFontMetrics
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleHintReturn
name|class
name|QStyleHintReturn
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOption
name|class
name|QStyleOption
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionComplex
name|class
name|QStyleOptionComplex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStylePrivate
name|class
name|QStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QStyle
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QStyle
argument_list|)
name|protected
operator|:
name|QStyle
argument_list|(
name|QStylePrivate
operator|&
name|dd
argument_list|)
block|;
name|public
operator|:
name|QStyle
argument_list|()
block|;
name|virtual
operator|~
name|QStyle
argument_list|()
block|;
name|virtual
name|void
name|polish
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|virtual
name|void
name|unpolish
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|virtual
name|void
name|polish
argument_list|(
name|QApplication
operator|*
argument_list|)
block|;
name|virtual
name|void
name|unpolish
argument_list|(
name|QApplication
operator|*
argument_list|)
block|;
name|virtual
name|void
name|polish
argument_list|(
name|QPalette
operator|&
argument_list|)
block|;
name|virtual
name|QRect
name|itemTextRect
argument_list|(
argument|const QFontMetrics&fm
argument_list|,
argument|const QRect&r
argument_list|,
argument|int flags
argument_list|,
argument|bool enabled
argument_list|,
argument|const QString&text
argument_list|)
specifier|const
block|;
name|virtual
name|QRect
name|itemPixmapRect
argument_list|(
argument|const QRect&r
argument_list|,
argument|int flags
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|drawItemText
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|,
argument|int flags
argument_list|,
argument|const QPalette&pal
argument_list|,
argument|bool enabled
argument_list|,
argument|const QString&text
argument_list|,
argument|QPalette::ColorRole textRole = QPalette::NoRole
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|drawItemPixmap
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|,
argument|int alignment
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
specifier|const
block|;
name|virtual
name|QPalette
name|standardPalette
argument_list|()
specifier|const
block|;      enum
name|StateFlag
block|{
name|State_None
operator|=
literal|0x00000000
block|,
name|State_Enabled
operator|=
literal|0x00000001
block|,
name|State_Raised
operator|=
literal|0x00000002
block|,
name|State_Sunken
operator|=
literal|0x00000004
block|,
name|State_Off
operator|=
literal|0x00000008
block|,
name|State_NoChange
operator|=
literal|0x00000010
block|,
name|State_On
operator|=
literal|0x00000020
block|,
name|State_DownArrow
operator|=
literal|0x00000040
block|,
name|State_Horizontal
operator|=
literal|0x00000080
block|,
name|State_HasFocus
operator|=
literal|0x00000100
block|,
name|State_Top
operator|=
literal|0x00000200
block|,
name|State_Bottom
operator|=
literal|0x00000400
block|,
name|State_FocusAtBorder
operator|=
literal|0x00000800
block|,
name|State_AutoRaise
operator|=
literal|0x00001000
block|,
name|State_MouseOver
operator|=
literal|0x00002000
block|,
name|State_UpArrow
operator|=
literal|0x00004000
block|,
name|State_Selected
operator|=
literal|0x00008000
block|,
name|State_Active
operator|=
literal|0x00010000
block|,
name|State_Window
operator|=
literal|0x00020000
block|,
name|State_Open
operator|=
literal|0x00040000
block|,
name|State_Children
operator|=
literal|0x00080000
block|,
name|State_Item
operator|=
literal|0x00100000
block|,
name|State_Sibling
operator|=
literal|0x00200000
block|,
name|State_Editing
operator|=
literal|0x00400000
block|,
name|State_KeyboardFocusChange
operator|=
literal|0x00800000
block|,
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|State_HasEditFocus
operator|=
literal|0x01000000
block|,
endif|#
directive|endif
name|State_ReadOnly
operator|=
literal|0x02000000
block|,
name|State_Small
operator|=
literal|0x04000000
block|,
name|State_Mini
operator|=
literal|0x08000000
block|}
block|;
name|Q_ENUM
argument_list|(
argument|StateFlag
argument_list|)
name|Q_DECLARE_FLAGS
argument_list|(
name|State
argument_list|,
name|StateFlag
argument_list|)
expr|enum
name|PrimitiveElement
block|{
name|PE_Frame
block|,
name|PE_FrameDefaultButton
block|,
name|PE_FrameDockWidget
block|,
name|PE_FrameFocusRect
block|,
name|PE_FrameGroupBox
block|,
name|PE_FrameLineEdit
block|,
name|PE_FrameMenu
block|,
name|PE_FrameStatusBar
block|,
comment|// obsolete
name|PE_FrameStatusBarItem
operator|=
name|PE_FrameStatusBar
block|,
name|PE_FrameTabWidget
block|,
name|PE_FrameWindow
block|,
name|PE_FrameButtonBevel
block|,
name|PE_FrameButtonTool
block|,
name|PE_FrameTabBarBase
block|,
name|PE_PanelButtonCommand
block|,
name|PE_PanelButtonBevel
block|,
name|PE_PanelButtonTool
block|,
name|PE_PanelMenuBar
block|,
name|PE_PanelToolBar
block|,
name|PE_PanelLineEdit
block|,
name|PE_IndicatorArrowDown
block|,
name|PE_IndicatorArrowLeft
block|,
name|PE_IndicatorArrowRight
block|,
name|PE_IndicatorArrowUp
block|,
name|PE_IndicatorBranch
block|,
name|PE_IndicatorButtonDropDown
block|,
name|PE_IndicatorViewItemCheck
block|,
name|PE_IndicatorItemViewItemCheck
operator|=
name|PE_IndicatorViewItemCheck
block|,
name|PE_IndicatorCheckBox
block|,
name|PE_IndicatorDockWidgetResizeHandle
block|,
name|PE_IndicatorHeaderArrow
block|,
name|PE_IndicatorMenuCheckMark
block|,
name|PE_IndicatorProgressChunk
block|,
name|PE_IndicatorRadioButton
block|,
name|PE_IndicatorSpinDown
block|,
name|PE_IndicatorSpinMinus
block|,
name|PE_IndicatorSpinPlus
block|,
name|PE_IndicatorSpinUp
block|,
name|PE_IndicatorToolBarHandle
block|,
name|PE_IndicatorToolBarSeparator
block|,
name|PE_PanelTipLabel
block|,
name|PE_IndicatorTabTear
block|,
name|PE_PanelScrollAreaCorner
block|,
name|PE_Widget
block|,
name|PE_IndicatorColumnViewArrow
block|,
name|PE_IndicatorItemViewItemDrop
block|,
name|PE_PanelItemViewItem
block|,
name|PE_PanelItemViewRow
block|,
comment|// ### Qt 6: remove
name|PE_PanelStatusBar
block|,
name|PE_IndicatorTabClose
block|,
name|PE_PanelMenu
block|,
comment|// do not add any values below/greater this
name|PE_CustomBase
operator|=
literal|0xf000000
block|}
block|;
name|Q_ENUM
argument_list|(
argument|PrimitiveElement
argument_list|)
name|virtual
name|void
name|drawPrimitive
argument_list|(
argument|PrimitiveElement pe
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;     enum
name|ControlElement
block|{
name|CE_PushButton
block|,
name|CE_PushButtonBevel
block|,
name|CE_PushButtonLabel
block|,
name|CE_CheckBox
block|,
name|CE_CheckBoxLabel
block|,
name|CE_RadioButton
block|,
name|CE_RadioButtonLabel
block|,
name|CE_TabBarTab
block|,
name|CE_TabBarTabShape
block|,
name|CE_TabBarTabLabel
block|,
name|CE_ProgressBar
block|,
name|CE_ProgressBarGroove
block|,
name|CE_ProgressBarContents
block|,
name|CE_ProgressBarLabel
block|,
name|CE_MenuItem
block|,
name|CE_MenuScroller
block|,
name|CE_MenuVMargin
block|,
name|CE_MenuHMargin
block|,
name|CE_MenuTearoff
block|,
name|CE_MenuEmptyArea
block|,
name|CE_MenuBarItem
block|,
name|CE_MenuBarEmptyArea
block|,
name|CE_ToolButtonLabel
block|,
name|CE_Header
block|,
name|CE_HeaderSection
block|,
name|CE_HeaderLabel
block|,
name|CE_ToolBoxTab
block|,
name|CE_SizeGrip
block|,
name|CE_Splitter
block|,
name|CE_RubberBand
block|,
name|CE_DockWidgetTitle
block|,
name|CE_ScrollBarAddLine
block|,
name|CE_ScrollBarSubLine
block|,
name|CE_ScrollBarAddPage
block|,
name|CE_ScrollBarSubPage
block|,
name|CE_ScrollBarSlider
block|,
name|CE_ScrollBarFirst
block|,
name|CE_ScrollBarLast
block|,
name|CE_FocusFrame
block|,
name|CE_ComboBoxLabel
block|,
name|CE_ToolBar
block|,
name|CE_ToolBoxTabShape
block|,
name|CE_ToolBoxTabLabel
block|,
name|CE_HeaderEmptyArea
block|,
name|CE_ColumnViewGrip
block|,
name|CE_ItemViewItem
block|,
name|CE_ShapedFrame
block|,
comment|// do not add any values below/greater than this
name|CE_CustomBase
operator|=
literal|0xf0000000
block|}
block|;
name|Q_ENUM
argument_list|(
argument|ControlElement
argument_list|)
name|virtual
name|void
name|drawControl
argument_list|(
argument|ControlElement element
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;      enum
name|SubElement
block|{
name|SE_PushButtonContents
block|,
name|SE_PushButtonFocusRect
block|,
name|SE_CheckBoxIndicator
block|,
name|SE_CheckBoxContents
block|,
name|SE_CheckBoxFocusRect
block|,
name|SE_CheckBoxClickRect
block|,
name|SE_RadioButtonIndicator
block|,
name|SE_RadioButtonContents
block|,
name|SE_RadioButtonFocusRect
block|,
name|SE_RadioButtonClickRect
block|,
name|SE_ComboBoxFocusRect
block|,
name|SE_SliderFocusRect
block|,
name|SE_ProgressBarGroove
block|,
name|SE_ProgressBarContents
block|,
name|SE_ProgressBarLabel
block|,
name|SE_ToolBoxTabContents
block|,
name|SE_HeaderLabel
block|,
name|SE_HeaderArrow
block|,
name|SE_TabWidgetTabBar
block|,
name|SE_TabWidgetTabPane
block|,
name|SE_TabWidgetTabContents
block|,
name|SE_TabWidgetLeftCorner
block|,
name|SE_TabWidgetRightCorner
block|,
name|SE_ViewItemCheckIndicator
block|,
name|SE_ItemViewItemCheckIndicator
operator|=
name|SE_ViewItemCheckIndicator
block|,
name|SE_TabBarTearIndicator
block|,
name|SE_TreeViewDisclosureItem
block|,
name|SE_LineEditContents
block|,
name|SE_FrameContents
block|,
name|SE_DockWidgetCloseButton
block|,
name|SE_DockWidgetFloatButton
block|,
name|SE_DockWidgetTitleBarText
block|,
name|SE_DockWidgetIcon
block|,
name|SE_CheckBoxLayoutItem
block|,
name|SE_ComboBoxLayoutItem
block|,
name|SE_DateTimeEditLayoutItem
block|,
name|SE_DialogButtonBoxLayoutItem
block|,
comment|// ### Qt 6: remove
name|SE_LabelLayoutItem
block|,
name|SE_ProgressBarLayoutItem
block|,
name|SE_PushButtonLayoutItem
block|,
name|SE_RadioButtonLayoutItem
block|,
name|SE_SliderLayoutItem
block|,
name|SE_SpinBoxLayoutItem
block|,
name|SE_ToolButtonLayoutItem
block|,
name|SE_FrameLayoutItem
block|,
name|SE_GroupBoxLayoutItem
block|,
name|SE_TabWidgetLayoutItem
block|,
name|SE_ItemViewItemDecoration
block|,
name|SE_ItemViewItemText
block|,
name|SE_ItemViewItemFocusRect
block|,
name|SE_TabBarTabLeftButton
block|,
name|SE_TabBarTabRightButton
block|,
name|SE_TabBarTabText
block|,
name|SE_ShapedFrameContents
block|,
name|SE_ToolBarHandle
block|,
comment|// do not add any values below/greater than this
name|SE_CustomBase
operator|=
literal|0xf0000000
block|}
block|;
name|Q_ENUM
argument_list|(
argument|SubElement
argument_list|)
name|virtual
name|QRect
name|subElementRect
argument_list|(
argument|SubElement subElement
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;       enum
name|ComplexControl
block|{
name|CC_SpinBox
block|,
name|CC_ComboBox
block|,
name|CC_ScrollBar
block|,
name|CC_Slider
block|,
name|CC_ToolButton
block|,
name|CC_TitleBar
block|,
name|CC_Dial
block|,
name|CC_GroupBox
block|,
name|CC_MdiControls
block|,
comment|// do not add any values below/greater than this
name|CC_CustomBase
operator|=
literal|0xf0000000
block|}
block|;
name|Q_ENUM
argument_list|(
name|ComplexControl
argument_list|)
expr|enum
name|SubControl
block|{
name|SC_None
operator|=
literal|0x00000000
block|,
name|SC_ScrollBarAddLine
operator|=
literal|0x00000001
block|,
name|SC_ScrollBarSubLine
operator|=
literal|0x00000002
block|,
name|SC_ScrollBarAddPage
operator|=
literal|0x00000004
block|,
name|SC_ScrollBarSubPage
operator|=
literal|0x00000008
block|,
name|SC_ScrollBarFirst
operator|=
literal|0x00000010
block|,
name|SC_ScrollBarLast
operator|=
literal|0x00000020
block|,
name|SC_ScrollBarSlider
operator|=
literal|0x00000040
block|,
name|SC_ScrollBarGroove
operator|=
literal|0x00000080
block|,
name|SC_SpinBoxUp
operator|=
literal|0x00000001
block|,
name|SC_SpinBoxDown
operator|=
literal|0x00000002
block|,
name|SC_SpinBoxFrame
operator|=
literal|0x00000004
block|,
name|SC_SpinBoxEditField
operator|=
literal|0x00000008
block|,
name|SC_ComboBoxFrame
operator|=
literal|0x00000001
block|,
name|SC_ComboBoxEditField
operator|=
literal|0x00000002
block|,
name|SC_ComboBoxArrow
operator|=
literal|0x00000004
block|,
name|SC_ComboBoxListBoxPopup
operator|=
literal|0x00000008
block|,
name|SC_SliderGroove
operator|=
literal|0x00000001
block|,
name|SC_SliderHandle
operator|=
literal|0x00000002
block|,
name|SC_SliderTickmarks
operator|=
literal|0x00000004
block|,
name|SC_ToolButton
operator|=
literal|0x00000001
block|,
name|SC_ToolButtonMenu
operator|=
literal|0x00000002
block|,
name|SC_TitleBarSysMenu
operator|=
literal|0x00000001
block|,
name|SC_TitleBarMinButton
operator|=
literal|0x00000002
block|,
name|SC_TitleBarMaxButton
operator|=
literal|0x00000004
block|,
name|SC_TitleBarCloseButton
operator|=
literal|0x00000008
block|,
name|SC_TitleBarNormalButton
operator|=
literal|0x00000010
block|,
name|SC_TitleBarShadeButton
operator|=
literal|0x00000020
block|,
name|SC_TitleBarUnshadeButton
operator|=
literal|0x00000040
block|,
name|SC_TitleBarContextHelpButton
operator|=
literal|0x00000080
block|,
name|SC_TitleBarLabel
operator|=
literal|0x00000100
block|,
name|SC_DialGroove
operator|=
literal|0x00000001
block|,
name|SC_DialHandle
operator|=
literal|0x00000002
block|,
name|SC_DialTickmarks
operator|=
literal|0x00000004
block|,
name|SC_GroupBoxCheckBox
operator|=
literal|0x00000001
block|,
name|SC_GroupBoxLabel
operator|=
literal|0x00000002
block|,
name|SC_GroupBoxContents
operator|=
literal|0x00000004
block|,
name|SC_GroupBoxFrame
operator|=
literal|0x00000008
block|,
name|SC_MdiMinButton
operator|=
literal|0x00000001
block|,
name|SC_MdiNormalButton
operator|=
literal|0x00000002
block|,
name|SC_MdiCloseButton
operator|=
literal|0x00000004
block|,
name|SC_CustomBase
operator|=
literal|0xf0000000
block|,
name|SC_All
operator|=
literal|0xffffffff
block|}
block|;
name|Q_ENUM
argument_list|(
argument|SubControl
argument_list|)
name|Q_DECLARE_FLAGS
argument_list|(
argument|SubControls
argument_list|,
argument|SubControl
argument_list|)
name|virtual
name|void
name|drawComplexControl
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|SubControl
name|hitTestComplexControl
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|const QPoint&pt
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QRect
name|subControlRect
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|SubControl sc
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;      enum
name|PixelMetric
block|{
name|PM_ButtonMargin
block|,
name|PM_ButtonDefaultIndicator
block|,
name|PM_MenuButtonIndicator
block|,
name|PM_ButtonShiftHorizontal
block|,
name|PM_ButtonShiftVertical
block|,
name|PM_DefaultFrameWidth
block|,
name|PM_SpinBoxFrameWidth
block|,
name|PM_ComboBoxFrameWidth
block|,
name|PM_MaximumDragDistance
block|,
name|PM_ScrollBarExtent
block|,
name|PM_ScrollBarSliderMin
block|,
name|PM_SliderThickness
block|,
comment|// total slider thickness
name|PM_SliderControlThickness
block|,
comment|// thickness of the business part
name|PM_SliderLength
block|,
comment|// total length of slider
name|PM_SliderTickmarkOffset
block|,
comment|//
name|PM_SliderSpaceAvailable
block|,
comment|// available space for slider to move
name|PM_DockWidgetSeparatorExtent
block|,
name|PM_DockWidgetHandleExtent
block|,
name|PM_DockWidgetFrameWidth
block|,
name|PM_TabBarTabOverlap
block|,
name|PM_TabBarTabHSpace
block|,
name|PM_TabBarTabVSpace
block|,
name|PM_TabBarBaseHeight
block|,
name|PM_TabBarBaseOverlap
block|,
name|PM_ProgressBarChunkWidth
block|,
name|PM_SplitterWidth
block|,
name|PM_TitleBarHeight
block|,
name|PM_MenuScrollerHeight
block|,
name|PM_MenuHMargin
block|,
name|PM_MenuVMargin
block|,
name|PM_MenuPanelWidth
block|,
name|PM_MenuTearoffHeight
block|,
name|PM_MenuDesktopFrameWidth
block|,
name|PM_MenuBarPanelWidth
block|,
name|PM_MenuBarItemSpacing
block|,
name|PM_MenuBarVMargin
block|,
name|PM_MenuBarHMargin
block|,
name|PM_IndicatorWidth
block|,
name|PM_IndicatorHeight
block|,
name|PM_ExclusiveIndicatorWidth
block|,
name|PM_ExclusiveIndicatorHeight
block|,
name|PM_DialogButtonsSeparator
block|,
name|PM_DialogButtonsButtonWidth
block|,
name|PM_DialogButtonsButtonHeight
block|,
name|PM_MdiSubWindowFrameWidth
block|,
name|PM_MDIFrameWidth
operator|=
name|PM_MdiSubWindowFrameWidth
block|,
comment|//obsolete
name|PM_MdiSubWindowMinimizedWidth
block|,
name|PM_MDIMinimizedWidth
operator|=
name|PM_MdiSubWindowMinimizedWidth
block|,
comment|//obsolete
name|PM_HeaderMargin
block|,
name|PM_HeaderMarkSize
block|,
name|PM_HeaderGripMargin
block|,
name|PM_TabBarTabShiftHorizontal
block|,
name|PM_TabBarTabShiftVertical
block|,
name|PM_TabBarScrollButtonWidth
block|,
name|PM_ToolBarFrameWidth
block|,
name|PM_ToolBarHandleExtent
block|,
name|PM_ToolBarItemSpacing
block|,
name|PM_ToolBarItemMargin
block|,
name|PM_ToolBarSeparatorExtent
block|,
name|PM_ToolBarExtensionExtent
block|,
name|PM_SpinBoxSliderHeight
block|,
name|PM_DefaultTopLevelMargin
block|,
name|PM_DefaultChildMargin
block|,
name|PM_DefaultLayoutSpacing
block|,
name|PM_ToolBarIconSize
block|,
name|PM_ListViewIconSize
block|,
name|PM_IconViewIconSize
block|,
name|PM_SmallIconSize
block|,
name|PM_LargeIconSize
block|,
name|PM_FocusFrameVMargin
block|,
name|PM_FocusFrameHMargin
block|,
name|PM_ToolTipLabelFrameWidth
block|,
name|PM_CheckBoxLabelSpacing
block|,
name|PM_TabBarIconSize
block|,
name|PM_SizeGripSize
block|,
name|PM_DockWidgetTitleMargin
block|,
name|PM_MessageBoxIconSize
block|,
name|PM_ButtonIconSize
block|,
name|PM_DockWidgetTitleBarButtonMargin
block|,
name|PM_RadioButtonLabelSpacing
block|,
name|PM_LayoutLeftMargin
block|,
name|PM_LayoutTopMargin
block|,
name|PM_LayoutRightMargin
block|,
name|PM_LayoutBottomMargin
block|,
name|PM_LayoutHorizontalSpacing
block|,
name|PM_LayoutVerticalSpacing
block|,
name|PM_TabBar_ScrollButtonOverlap
block|,
name|PM_TextCursorWidth
block|,
name|PM_TabCloseIndicatorWidth
block|,
name|PM_TabCloseIndicatorHeight
block|,
name|PM_ScrollView_ScrollBarSpacing
block|,
name|PM_ScrollView_ScrollBarOverlap
block|,
name|PM_SubMenuOverlap
block|,
name|PM_TreeViewIndentation
block|,
name|PM_HeaderDefaultSectionSizeHorizontal
block|,
name|PM_HeaderDefaultSectionSizeVertical
block|,
comment|// do not add any values below/greater than this
name|PM_CustomBase
operator|=
literal|0xf0000000
block|}
block|;
name|Q_ENUM
argument_list|(
argument|PixelMetric
argument_list|)
name|virtual
name|int
name|pixelMetric
argument_list|(
argument|PixelMetric metric
argument_list|,
argument|const QStyleOption *option =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;      enum
name|ContentsType
block|{
name|CT_PushButton
block|,
name|CT_CheckBox
block|,
name|CT_RadioButton
block|,
name|CT_ToolButton
block|,
name|CT_ComboBox
block|,
name|CT_Splitter
block|,
name|CT_ProgressBar
block|,
name|CT_MenuItem
block|,
name|CT_MenuBarItem
block|,
name|CT_MenuBar
block|,
name|CT_Menu
block|,
name|CT_TabBarTab
block|,
name|CT_Slider
block|,
name|CT_ScrollBar
block|,
name|CT_LineEdit
block|,
name|CT_SpinBox
block|,
name|CT_SizeGrip
block|,
name|CT_TabWidget
block|,
name|CT_DialogButtons
block|,
name|CT_HeaderSection
block|,
name|CT_GroupBox
block|,
name|CT_MdiControls
block|,
name|CT_ItemViewItem
block|,
comment|// do not add any values below/greater than this
name|CT_CustomBase
operator|=
literal|0xf0000000
block|}
block|;
name|Q_ENUM
argument_list|(
argument|ContentsType
argument_list|)
name|virtual
name|QSize
name|sizeFromContents
argument_list|(
argument|ContentsType ct
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;      enum
name|RequestSoftwareInputPanel
block|{
name|RSIP_OnMouseClickAndAlreadyFocused
block|,
name|RSIP_OnMouseClick
block|}
block|;
name|Q_ENUM
argument_list|(
name|RequestSoftwareInputPanel
argument_list|)
expr|enum
name|StyleHint
block|{
name|SH_EtchDisabledText
block|,
name|SH_DitherDisabledText
block|,
name|SH_ScrollBar_MiddleClickAbsolutePosition
block|,
name|SH_ScrollBar_ScrollWhenPointerLeavesControl
block|,
name|SH_TabBar_SelectMouseType
block|,
name|SH_TabBar_Alignment
block|,
name|SH_Header_ArrowAlignment
block|,
name|SH_Slider_SnapToValue
block|,
name|SH_Slider_SloppyKeyEvents
block|,
name|SH_ProgressDialog_CenterCancelButton
block|,
name|SH_ProgressDialog_TextLabelAlignment
block|,
name|SH_PrintDialog_RightAlignButtons
block|,
name|SH_MainWindow_SpaceBelowMenuBar
block|,
name|SH_FontDialog_SelectAssociatedText
block|,
name|SH_Menu_AllowActiveAndDisabled
block|,
name|SH_Menu_SpaceActivatesItem
block|,
name|SH_Menu_SubMenuPopupDelay
block|,
name|SH_ScrollView_FrameOnlyAroundContents
block|,
name|SH_MenuBar_AltKeyNavigation
block|,
name|SH_ComboBox_ListMouseTracking
block|,
name|SH_Menu_MouseTracking
block|,
name|SH_MenuBar_MouseTracking
block|,
name|SH_ItemView_ChangeHighlightOnFocus
block|,
name|SH_Widget_ShareActivation
block|,
name|SH_Workspace_FillSpaceOnMaximize
block|,
name|SH_ComboBox_Popup
block|,
name|SH_TitleBar_NoBorder
block|,
name|SH_Slider_StopMouseOverSlider
block|,
name|SH_ScrollBar_StopMouseOverSlider
operator|=
name|SH_Slider_StopMouseOverSlider
block|,
comment|// obsolete
name|SH_BlinkCursorWhenTextSelected
block|,
name|SH_RichText_FullWidthSelection
block|,
name|SH_Menu_Scrollable
block|,
name|SH_GroupBox_TextLabelVerticalAlignment
block|,
name|SH_GroupBox_TextLabelColor
block|,
name|SH_Menu_SloppySubMenus
block|,
name|SH_Table_GridLineColor
block|,
name|SH_LineEdit_PasswordCharacter
block|,
name|SH_DialogButtons_DefaultButton
block|,
name|SH_ToolBox_SelectedPageTitleBold
block|,
name|SH_TabBar_PreferNoArrows
block|,
name|SH_ScrollBar_LeftClickAbsolutePosition
block|,
name|SH_ListViewExpand_SelectMouseType
block|,
name|SH_UnderlineShortcut
block|,
name|SH_SpinBox_AnimateButton
block|,
name|SH_SpinBox_KeyPressAutoRepeatRate
block|,
name|SH_SpinBox_ClickAutoRepeatRate
block|,
name|SH_Menu_FillScreenWithScroll
block|,
name|SH_ToolTipLabel_Opacity
block|,
name|SH_DrawMenuBarSeparator
block|,
name|SH_TitleBar_ModifyNotification
block|,
name|SH_Button_FocusPolicy
block|,
name|SH_MessageBox_UseBorderForButtonSpacing
block|,
name|SH_TitleBar_AutoRaise
block|,
name|SH_ToolButton_PopupDelay
block|,
name|SH_FocusFrame_Mask
block|,
name|SH_RubberBand_Mask
block|,
name|SH_WindowFrame_Mask
block|,
name|SH_SpinControls_DisableOnBounds
block|,
name|SH_Dial_BackgroundRole
block|,
name|SH_ComboBox_LayoutDirection
block|,
name|SH_ItemView_EllipsisLocation
block|,
name|SH_ItemView_ShowDecorationSelected
block|,
name|SH_ItemView_ActivateItemOnSingleClick
block|,
name|SH_ScrollBar_ContextMenu
block|,
name|SH_ScrollBar_RollBetweenButtons
block|,
name|SH_Slider_AbsoluteSetButtons
block|,
name|SH_Slider_PageSetButtons
block|,
name|SH_Menu_KeyboardSearch
block|,
name|SH_TabBar_ElideMode
block|,
name|SH_DialogButtonLayout
block|,
name|SH_ComboBox_PopupFrameStyle
block|,
name|SH_MessageBox_TextInteractionFlags
block|,
name|SH_DialogButtonBox_ButtonsHaveIcons
block|,
name|SH_SpellCheckUnderlineStyle
block|,
name|SH_MessageBox_CenterButtons
block|,
name|SH_Menu_SelectionWrap
block|,
name|SH_ItemView_MovementWithoutUpdatingSelection
block|,
name|SH_ToolTip_Mask
block|,
name|SH_FocusFrame_AboveWidget
block|,
name|SH_TextControl_FocusIndicatorTextCharFormat
block|,
name|SH_WizardStyle
block|,
name|SH_ItemView_ArrowKeysNavigateIntoChildren
block|,
name|SH_Menu_Mask
block|,
name|SH_Menu_FlashTriggeredItem
block|,
name|SH_Menu_FadeOutOnHide
block|,
name|SH_SpinBox_ClickAutoRepeatThreshold
block|,
name|SH_ItemView_PaintAlternatingRowColorsForEmptyArea
block|,
name|SH_FormLayoutWrapPolicy
block|,
name|SH_TabWidget_DefaultTabPosition
block|,
name|SH_ToolBar_Movable
block|,
name|SH_FormLayoutFieldGrowthPolicy
block|,
name|SH_FormLayoutFormAlignment
block|,
name|SH_FormLayoutLabelAlignment
block|,
name|SH_ItemView_DrawDelegateFrame
block|,
name|SH_TabBar_CloseButtonPosition
block|,
name|SH_DockWidget_ButtonsHaveFrame
block|,
name|SH_ToolButtonStyle
block|,
name|SH_RequestSoftwareInputPanel
block|,
name|SH_ScrollBar_Transient
block|,
name|SH_Menu_SupportsSections
block|,
name|SH_ToolTip_WakeUpDelay
block|,
name|SH_ToolTip_FallAsleepDelay
block|,
name|SH_Widget_Animate
block|,
name|SH_Splitter_OpaqueResize
block|,
comment|// Whether we should use a native popup.
comment|// Only supported for non-editable combo boxes on Mac OS X so far.
name|SH_ComboBox_UseNativePopup
block|,
name|SH_LineEdit_PasswordMaskDelay
block|,
name|SH_TabBar_ChangeCurrentDelay
block|,
name|SH_Menu_SubMenuUniDirection
block|,
name|SH_Menu_SubMenuUniDirectionFailCount
block|,
name|SH_Menu_SubMenuSloppySelectOtherActions
block|,
name|SH_Menu_SubMenuSloppyCloseTimeout
block|,
name|SH_Menu_SubMenuResetWhenReenteringParent
block|,
name|SH_Menu_SubMenuDontStartSloppyOnLeave
block|,
comment|// Add new style hint values here
name|SH_CustomBase
operator|=
literal|0xf0000000
block|}
block|;
name|Q_ENUM
argument_list|(
argument|StyleHint
argument_list|)
name|virtual
name|int
name|styleHint
argument_list|(
argument|StyleHint stylehint
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|,
argument|QStyleHintReturn* returnData =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;      enum
name|StandardPixmap
block|{
name|SP_TitleBarMenuButton
block|,
name|SP_TitleBarMinButton
block|,
name|SP_TitleBarMaxButton
block|,
name|SP_TitleBarCloseButton
block|,
name|SP_TitleBarNormalButton
block|,
name|SP_TitleBarShadeButton
block|,
name|SP_TitleBarUnshadeButton
block|,
name|SP_TitleBarContextHelpButton
block|,
name|SP_DockWidgetCloseButton
block|,
name|SP_MessageBoxInformation
block|,
name|SP_MessageBoxWarning
block|,
name|SP_MessageBoxCritical
block|,
name|SP_MessageBoxQuestion
block|,
name|SP_DesktopIcon
block|,
name|SP_TrashIcon
block|,
name|SP_ComputerIcon
block|,
name|SP_DriveFDIcon
block|,
name|SP_DriveHDIcon
block|,
name|SP_DriveCDIcon
block|,
name|SP_DriveDVDIcon
block|,
name|SP_DriveNetIcon
block|,
name|SP_DirOpenIcon
block|,
name|SP_DirClosedIcon
block|,
name|SP_DirLinkIcon
block|,
name|SP_DirLinkOpenIcon
block|,
name|SP_FileIcon
block|,
name|SP_FileLinkIcon
block|,
name|SP_ToolBarHorizontalExtensionButton
block|,
name|SP_ToolBarVerticalExtensionButton
block|,
name|SP_FileDialogStart
block|,
name|SP_FileDialogEnd
block|,
name|SP_FileDialogToParent
block|,
name|SP_FileDialogNewFolder
block|,
name|SP_FileDialogDetailedView
block|,
name|SP_FileDialogInfoView
block|,
name|SP_FileDialogContentsView
block|,
name|SP_FileDialogListView
block|,
name|SP_FileDialogBack
block|,
name|SP_DirIcon
block|,
name|SP_DialogOkButton
block|,
name|SP_DialogCancelButton
block|,
name|SP_DialogHelpButton
block|,
name|SP_DialogOpenButton
block|,
name|SP_DialogSaveButton
block|,
name|SP_DialogCloseButton
block|,
name|SP_DialogApplyButton
block|,
name|SP_DialogResetButton
block|,
name|SP_DialogDiscardButton
block|,
name|SP_DialogYesButton
block|,
name|SP_DialogNoButton
block|,
name|SP_ArrowUp
block|,
name|SP_ArrowDown
block|,
name|SP_ArrowLeft
block|,
name|SP_ArrowRight
block|,
name|SP_ArrowBack
block|,
name|SP_ArrowForward
block|,
name|SP_DirHomeIcon
block|,
name|SP_CommandLink
block|,
name|SP_VistaShield
block|,
name|SP_BrowserReload
block|,
name|SP_BrowserStop
block|,
name|SP_MediaPlay
block|,
name|SP_MediaStop
block|,
name|SP_MediaPause
block|,
name|SP_MediaSkipForward
block|,
name|SP_MediaSkipBackward
block|,
name|SP_MediaSeekForward
block|,
name|SP_MediaSeekBackward
block|,
name|SP_MediaVolume
block|,
name|SP_MediaVolumeMuted
block|,
name|SP_LineEditClearButton
block|,
comment|// do not add any values below/greater than this
name|SP_CustomBase
operator|=
literal|0xf0000000
block|}
block|;
name|Q_ENUM
argument_list|(
argument|StandardPixmap
argument_list|)
name|virtual
name|QPixmap
name|standardPixmap
argument_list|(
argument|StandardPixmap standardPixmap
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QIcon
name|standardIcon
argument_list|(
argument|StandardPixmap standardIcon
argument_list|,
argument|const QStyleOption *option =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QPixmap
name|generatedIconPixmap
argument_list|(
argument|QIcon::Mode iconMode
argument_list|,
argument|const QPixmap&pixmap
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
operator|=
literal|0
block|;
specifier|static
name|QRect
name|visualRect
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|,
argument|const QRect&boundingRect
argument_list|,
argument|const QRect&logicalRect
argument_list|)
block|;
specifier|static
name|QPoint
name|visualPos
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|,
argument|const QRect&boundingRect
argument_list|,
argument|const QPoint&logicalPos
argument_list|)
block|;
specifier|static
name|int
name|sliderPositionFromValue
argument_list|(
argument|int min
argument_list|,
argument|int max
argument_list|,
argument|int val
argument_list|,
argument|int space
argument_list|,
argument|bool upsideDown = false
argument_list|)
block|;
specifier|static
name|int
name|sliderValueFromPosition
argument_list|(
argument|int min
argument_list|,
argument|int max
argument_list|,
argument|int pos
argument_list|,
argument|int space
argument_list|,
argument|bool upsideDown = false
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|Alignment
name|visualAlignment
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|,
argument|Qt::Alignment alignment
argument_list|)
block|;
specifier|static
name|QRect
name|alignedRect
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|,
argument|Qt::Alignment alignment
argument_list|,
argument|const QSize&size
argument_list|,
argument|const QRect&rectangle
argument_list|)
block|;
name|virtual
name|int
name|layoutSpacing
argument_list|(
argument|QSizePolicy::ControlType control1
argument_list|,
argument|QSizePolicy::ControlType control2
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|const QStyleOption *option =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|int
name|combinedLayoutSpacing
argument_list|(
argument|QSizePolicy::ControlTypes controls1
argument_list|,
argument|QSizePolicy::ControlTypes controls2
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|QStyleOption *option =
literal|0
argument_list|,
argument|QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
specifier|const
name|QStyle
operator|*
name|proxy
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QStyle
argument_list|)
name|friend
name|class
name|QWidget
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|friend
name|class
name|QApplication
block|;
name|friend
name|class
name|QProxyStyle
block|;
name|friend
name|class
name|QProxyStylePrivate
block|;
name|void
name|setProxy
argument_list|(
name|QStyle
operator|*
name|style
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QStyle::State
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QStyle::SubControls
argument_list|)
end_macro
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
end_if
begin_expr_stmt
name|Q_WIDGETS_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
name|QStyle
operator|::
name|State
name|state
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTYLE_H
end_comment
end_unit
