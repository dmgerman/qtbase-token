begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2014 BlackBerry Limited. All rights reserved. ** Copyright (C) 2015 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAPSTYLE_H
end_ifndef
begin_define
DECL|macro|QPIXMAPSTYLE_H
define|#
directive|define
name|QPIXMAPSTYLE_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/QCommonStyle>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QTileRules>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPixmapStylePrivate
name|class
name|QPixmapStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QPixmapStyle
range|:
name|public
name|QCommonStyle
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ControlDescriptor
block|{
name|BG_Background
block|,
name|LE_Enabled
block|,
comment|// QLineEdit
name|LE_Disabled
block|,
name|LE_Focused
block|,
name|PB_Enabled
block|,
comment|// QPushButton
name|PB_Pressed
block|,
name|PB_PressedDisabled
block|,
name|PB_Checked
block|,
name|PB_Disabled
block|,
name|TE_Enabled
block|,
comment|// QTextEdit
name|TE_Disabled
block|,
name|TE_Focused
block|,
name|PB_HBackground
block|,
comment|// Horizontal QProgressBar
name|PB_HContent
block|,
name|PB_HComplete
block|,
name|PB_VBackground
block|,
comment|// Vertical QProgressBar
name|PB_VContent
block|,
name|PB_VComplete
block|,
name|SG_HEnabled
block|,
comment|// Horizontal QSlider groove
name|SG_HDisabled
block|,
name|SG_HActiveEnabled
block|,
name|SG_HActivePressed
block|,
name|SG_HActiveDisabled
block|,
name|SG_VEnabled
block|,
comment|// Vertical QSlider groove
name|SG_VDisabled
block|,
name|SG_VActiveEnabled
block|,
name|SG_VActivePressed
block|,
name|SG_VActiveDisabled
block|,
name|DD_ButtonEnabled
block|,
comment|// QComboBox (DropDown)
name|DD_ButtonDisabled
block|,
name|DD_ButtonPressed
block|,
name|DD_PopupDown
block|,
name|DD_PopupUp
block|,
name|DD_ItemSelected
block|,
name|ID_Selected
block|,
comment|// QStyledItemDelegate
name|SB_Horizontal
block|,
comment|// QScrollBar
name|SB_Vertical
block|}
block|;      enum
name|ControlPixmap
block|{
name|CB_Enabled
block|,
comment|// QCheckBox
name|CB_Checked
block|,
name|CB_Pressed
block|,
name|CB_PressedChecked
block|,
name|CB_Disabled
block|,
name|CB_DisabledChecked
block|,
name|RB_Enabled
block|,
comment|// QRadioButton
name|RB_Checked
block|,
name|RB_Pressed
block|,
name|RB_Disabled
block|,
name|RB_DisabledChecked
block|,
name|SH_HEnabled
block|,
comment|// Horizontal QSlider handle
name|SH_HDisabled
block|,
name|SH_HPressed
block|,
name|SH_VEnabled
block|,
comment|// Vertical QSlider handle
name|SH_VDisabled
block|,
name|SH_VPressed
block|,
name|DD_ArrowEnabled
block|,
comment|// QComboBox (DropDown) arrow
name|DD_ArrowDisabled
block|,
name|DD_ArrowPressed
block|,
name|DD_ArrowOpen
block|,
name|DD_ItemSeparator
block|,
name|ID_Separator
comment|// QStyledItemDelegate separator
block|}
block|;
name|public
operator|:
name|QPixmapStyle
argument_list|()
block|;
operator|~
name|QPixmapStyle
argument_list|()
block|;
name|void
name|polish
argument_list|(
argument|QApplication *application
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|polish
argument_list|(
argument|QPalette&palette
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|polish
argument_list|(
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|unpolish
argument_list|(
argument|QApplication *application
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|unpolish
argument_list|(
argument|QWidget *widget
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawPrimitive
argument_list|(
argument|PrimitiveElement element
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget = Q_NULLPTR
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawControl
argument_list|(
argument|ControlElement element
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget = Q_NULLPTR
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawComplexControl
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget=
literal|0
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|sizeFromContents
argument_list|(
argument|ContentsType type
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget = Q_NULLPTR
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QRect
name|subElementRect
argument_list|(
argument|SubElement element
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget = Q_NULLPTR
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QRect
name|subControlRect
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *option
argument_list|,
argument|SubControl sc
argument_list|,
argument|const QWidget *widget = Q_NULLPTR
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|pixelMetric
argument_list|(
argument|PixelMetric metric
argument_list|,
argument|const QStyleOption *option = Q_NULLPTR
argument_list|,
argument|const QWidget *widget = Q_NULLPTR
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|styleHint
argument_list|(
argument|StyleHint hint
argument_list|,
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widget
argument_list|,
argument|QStyleHintReturn *returnData
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|SubControl
name|hitTestComplexControl
argument_list|(
argument|ComplexControl control
argument_list|,
argument|const QStyleOptionComplex *option
argument_list|,
argument|const QPoint&pos
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|eventFilter
argument_list|(
argument|QObject *watched
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|addDescriptor
argument_list|(
argument|ControlDescriptor control
argument_list|,
argument|const QString&fileName
argument_list|,
argument|QMargins margins = QMargins()
argument_list|,
argument|QTileRules tileRules = QTileRules(Qt::RepeatTile, Qt::RepeatTile)
argument_list|)
block|;
name|void
name|copyDescriptor
argument_list|(
argument|ControlDescriptor source
argument_list|,
argument|ControlDescriptor dest
argument_list|)
block|;
name|void
name|drawCachedPixmap
argument_list|(
argument|ControlDescriptor control
argument_list|,
argument|const QRect&rect
argument_list|,
argument|QPainter *p
argument_list|)
specifier|const
block|;
name|void
name|addPixmap
argument_list|(
argument|ControlPixmap control
argument_list|,
argument|const QString&fileName
argument_list|,
argument|QMargins margins = QMargins()
argument_list|)
block|;
name|void
name|copyPixmap
argument_list|(
argument|ControlPixmap source
argument_list|,
argument|ControlPixmap dest
argument_list|)
block|;
name|protected
operator|:
name|void
name|drawPushButton
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawLineEdit
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawTextEdit
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawCheckBox
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawRadioButton
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawPanelItemViewItem
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawProgressBarBackground
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawProgressBarLabel
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawProgressBarFill
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawSlider
argument_list|(
argument|const QStyleOptionComplex *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawComboBox
argument_list|(
argument|const QStyleOptionComplex *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|void
name|drawScrollBar
argument_list|(
argument|const QStyleOptionComplex *option
argument_list|,
argument|QPainter *painter
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QSize
name|pushButtonSizeFromContents
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QSize
name|lineEditSizeFromContents
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QSize
name|progressBarSizeFromContents
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QSize
name|sliderSizeFromContents
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QSize
name|comboBoxSizeFromContents
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QSize
name|itemViewSizeFromContents
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QRect
name|comboBoxSubControlRect
argument_list|(
argument|const QStyleOptionComplex *option
argument_list|,
argument|QPixmapStyle::SubControl sc
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|QRect
name|scrollBarSubControlRect
argument_list|(
argument|const QStyleOptionComplex *option
argument_list|,
argument|QPixmapStyle::SubControl sc
argument_list|,
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QPixmapStyle
argument_list|(
name|QPixmapStylePrivate
operator|&
name|dd
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPixmapStyle
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPIXMAPSTYLE_H
end_comment
end_unit
