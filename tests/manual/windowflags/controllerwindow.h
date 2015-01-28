begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|variable|HintControl
name|class
name|HintControl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|WindowStatesControl
name|class
name|WindowStatesControl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TypeControl
name|class
name|TypeControl
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
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
name|virtual
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|updatePreview
argument_list|()
block|;
name|void
name|updateStateControl
argument_list|()
block|;
name|private
operator|:
name|void
name|createTypeGroupBox
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
name|QWidget
operator|*
name|previewWidget
block|;
name|QGroupBox
operator|*
name|widgetTypeGroupBox
block|;
name|QGroupBox
operator|*
name|additionalOptionsGroupBox
block|;
name|TypeControl
operator|*
name|typeControl
block|;
name|HintControl
operator|*
name|hintsControl
block|;
name|WindowStatesControl
operator|*
name|statesControl
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
