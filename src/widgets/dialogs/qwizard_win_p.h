begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWIZARD_WIN_P_H
end_ifndef
begin_define
DECL|macro|QWIZARD_WIN_P_H
define|#
directive|define
name|QWIZARD_WIN_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WIZARD
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSVISTA
end_ifndef
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|<qabstractbutton.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/private/qwidget_p.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/private/qstylehelper_p.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QVistaBackButton
range|:
name|public
name|QAbstractButton
block|{
name|public
operator|:
name|QVistaBackButton
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
specifier|inline
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|{
return|return
name|sizeHint
argument_list|()
return|;
block|}
name|void
name|enterEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|leaveEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWizard
name|class
name|QWizard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QVistaHelper
range|:
name|public
name|QObject
block|{
name|public
operator|:
name|QVistaHelper
argument_list|(
name|QWizard
operator|*
name|wizard
argument_list|)
block|;
operator|~
name|QVistaHelper
argument_list|()
block|;     enum
name|TitleBarChangeType
block|{
name|NormalTitleBar
block|,
name|ExtendedTitleBar
block|}
block|;
name|void
name|updateCustomMargins
argument_list|(
argument|bool vistaMargins
argument_list|)
block|;
name|bool
name|setDWMTitleBar
argument_list|(
argument|TitleBarChangeType type
argument_list|)
block|;
name|void
name|setTitleBarIconAndCaptionVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|mouseEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|handleWinEvent
argument_list|(
name|MSG
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|QVistaBackButton
operator|*
name|backButton
argument_list|()
specifier|const
block|{
return|return
name|backButton_
return|;
block|}
name|void
name|disconnectBackButton
argument_list|()
block|;
name|void
name|hideBackButton
argument_list|()
block|{
if|if
condition|(
name|backButton_
condition|)
name|backButton_
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
name|QColor
name|basicWindowFrameColor
argument_list|()
block|;     enum
name|VistaState
block|{
name|VistaAero
block|,
name|VistaBasic
block|,
name|Classic
block|,
name|Dirty
block|}
block|;
specifier|static
name|VistaState
name|vistaState
argument_list|()
block|;
specifier|static
name|int
name|titleBarSize
argument_list|()
block|{
return|return
name|frameSize
argument_list|()
operator|+
name|captionSize
argument_list|()
return|;
block|}
specifier|static
name|int
name|topPadding
argument_list|()
block|{
comment|// padding under text
return|return
name|int
argument_list|(
name|QStyleHelper
operator|::
name|dpiScaled
argument_list|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_WINDOWS7
operator|?
literal|4
operator|:
literal|6
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|int
name|topOffset
argument_list|()
block|;
specifier|static
name|HDC
name|backingStoreDC
argument_list|(
specifier|const
name|QWidget
operator|*
name|wizard
argument_list|,
name|QPoint
operator|*
name|offset
argument_list|)
block|;
name|private
operator|:
specifier|static
name|HFONT
name|getCaptionFont
argument_list|(
argument|HANDLE hTheme
argument_list|)
block|;
name|HWND
name|wizardHWND
argument_list|()
specifier|const
block|;
name|bool
name|drawTitleText
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QString&text
argument_list|,
argument|const QRect&rect
argument_list|,
argument|HDC hdc
argument_list|)
block|;
specifier|static
name|bool
name|drawBlackRect
argument_list|(
argument|const QRect&rect
argument_list|,
argument|HDC hdc
argument_list|)
block|;
specifier|static
name|int
name|frameSize
argument_list|()
block|{
return|return
name|GetSystemMetrics
argument_list|(
name|SM_CYSIZEFRAME
argument_list|)
return|;
block|}
specifier|static
name|int
name|captionSize
argument_list|()
block|{
return|return
name|GetSystemMetrics
argument_list|(
name|SM_CYCAPTION
argument_list|)
return|;
block|}
specifier|static
name|int
name|backButtonSize
argument_list|()
block|{
return|return
name|int
argument_list|(
name|QStyleHelper
operator|::
name|dpiScaled
argument_list|(
literal|30
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|int
name|iconSize
argument_list|()
block|{
return|return
literal|16
return|;
block|}
comment|// Standard Aero
specifier|static
name|int
name|glowSize
argument_list|()
block|{
return|return
literal|10
return|;
block|}
name|int
name|leftMargin
argument_list|()
block|{
return|return
name|backButton_
operator|->
name|isVisible
argument_list|()
condition|?
name|backButtonSize
argument_list|()
operator|+
name|iconSpacing
else|:
literal|0
return|;
block|}
name|int
name|titleOffset
argument_list|()
block|;
name|bool
name|resolveSymbols
argument_list|()
block|;
name|void
name|drawTitleBar
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|void
name|setMouseCursor
argument_list|(
argument|QPoint pos
argument_list|)
block|;
name|void
name|collapseTopFrameStrut
argument_list|()
block|;
name|bool
name|winEvent
argument_list|(
name|MSG
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
specifier|static
name|int
name|instanceCount
block|;
specifier|static
name|bool
name|is_vista
block|;
specifier|static
name|VistaState
name|cachedVistaState
block|;
specifier|static
name|bool
name|isCompositionEnabled
argument_list|()
block|;
specifier|static
name|bool
name|isThemeActive
argument_list|()
block|;     enum
name|Changes
block|{
name|resizeTop
block|,
name|movePosition
block|,
name|noChange
block|}
name|change
block|;
name|QPoint
name|pressedPos
block|;
name|bool
name|pressed
block|;
name|QRect
name|rtTop
block|;
name|QRect
name|rtTitle
block|;
name|QWizard
operator|*
name|wizard
block|;
name|QVistaBackButton
operator|*
name|backButton_
block|;
name|int
name|titleBarOffset
block|;
comment|// Extra spacing above the text
name|int
name|iconSpacing
block|;
comment|// Space between button and icon
name|int
name|textSpacing
block|;
comment|// Space between icon and text
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
comment|// QT_NO_STYLE_WINDOWSVISTA
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_WIZARD
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWIZARD_WIN_P_H
end_comment
end_unit
