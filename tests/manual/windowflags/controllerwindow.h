begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONTROLLERWINDOW_H
end_ifndef
begin_define
DECL|macro|CONTROLLERWINDOW_H
define|#
directive|define
name|CONTROLLERWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|"previewwindow.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGroupBox
name|class
name|QGroupBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRadioButton
name|class
name|QRadioButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMainWindow
name|class
name|QMainWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|//! [0]
name|class
name|ControllerWindow
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|ControllerWindow
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|updatePreview
argument_list|()
block|;
name|private
operator|:
name|void
name|createTypeGroupBox
argument_list|()
block|;
name|void
name|createHintsGroupBox
argument_list|()
block|;
name|QCheckBox
operator|*
name|createCheckBox
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QRadioButton
operator|*
name|createRadioButton
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QMainWindow
operator|*
name|parentWindow
block|;
name|PreviewWindow
operator|*
name|previewWindow
block|;
name|PreviewDialog
operator|*
name|previewDialog
block|;
name|QGroupBox
operator|*
name|widgetTypeGroupBox
block|;
name|QGroupBox
operator|*
name|additionalOptionsGroupBox
block|;
name|QGroupBox
operator|*
name|typeGroupBox
block|;
name|QGroupBox
operator|*
name|hintsGroupBox
block|;
name|QPushButton
operator|*
name|quitButton
block|;
name|QRadioButton
operator|*
name|previewWidgetButton
block|;
name|QRadioButton
operator|*
name|previewDialogButton
block|;
name|QCheckBox
operator|*
name|modalWindowCheckBox
block|;
name|QCheckBox
operator|*
name|fixedSizeWindowCheckBox
block|;
name|QRadioButton
operator|*
name|windowRadioButton
block|;
name|QRadioButton
operator|*
name|dialogRadioButton
block|;
name|QRadioButton
operator|*
name|sheetRadioButton
block|;
name|QRadioButton
operator|*
name|drawerRadioButton
block|;
name|QRadioButton
operator|*
name|popupRadioButton
block|;
name|QRadioButton
operator|*
name|toolRadioButton
block|;
name|QRadioButton
operator|*
name|toolTipRadioButton
block|;
name|QRadioButton
operator|*
name|splashScreenRadioButton
block|;
name|QCheckBox
operator|*
name|msWindowsFixedSizeDialogCheckBox
block|;
name|QCheckBox
operator|*
name|x11BypassWindowManagerCheckBox
block|;
name|QCheckBox
operator|*
name|framelessWindowCheckBox
block|;
name|QCheckBox
operator|*
name|windowTitleCheckBox
block|;
name|QCheckBox
operator|*
name|windowSystemMenuCheckBox
block|;
name|QCheckBox
operator|*
name|windowMinimizeButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowMaximizeButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowCloseButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowContextHelpButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowShadeButtonCheckBox
block|;
name|QCheckBox
operator|*
name|windowStaysOnTopCheckBox
block|;
name|QCheckBox
operator|*
name|windowStaysOnBottomCheckBox
block|;
name|QCheckBox
operator|*
name|customizeWindowHintCheckBox
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
