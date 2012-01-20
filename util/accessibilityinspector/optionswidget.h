begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).  ** All rights reserved.  ** Contact: http://www.qt-project.org/  **  ** This file is part of the tools applications of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL$  ** GNU Lesser General Public License Usage  ** This file may be used under the terms of the GNU Lesser General Public  ** License version 2.1 as published by the Free Software Foundation and  ** appearing in the file LICENSE.LGPL included in the packaging of this  ** file. Please review the following information to ensure the GNU Lesser  ** General Public License version 2.1 requirements will be met:  ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.  **  ** In addition, as a special exception, Nokia gives you certain additional  ** rights. These rights are described in the Nokia Qt LGPL Exception  ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.  **  ** GNU General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU General  ** Public License version 3.0 as published by the Free Software Foundation  ** and appearing in the file LICENSE.GPL included in the packaging of this  ** file. Please review the following information to ensure the GNU General  ** Public License version 3.0 requirements will be met:  ** http://www.gnu.org/copyleft/gpl.html.  **  ** Other Usage  ** Alternatively, this file may be used in accordance with the terms and  ** conditions contained in a signed written agreement between you and Nokia.  **  **  **  **  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|OPTIONSWIDGET_H
end_ifndef
begin_define
DECL|macro|OPTIONSWIDGET_H
define|#
directive|define
name|OPTIONSWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_decl_stmt
name|class
name|OptionsWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|OptionsWidget
argument_list|()
operator|:
name|QWidget
argument_list|()
block|{
name|QVBoxLayout
operator|*
name|m_layout
operator|=
name|new
name|QVBoxLayout
block|;
name|m_refresh
operator|=
name|new
name|QPushButton
argument_list|(
name|this
argument_list|)
block|;
name|m_refresh
operator|->
name|setText
argument_list|(
name|QLatin1String
argument_list|(
literal|"Refresh"
argument_list|)
argument_list|)
block|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|m_refresh
argument_list|)
block|;
name|connect
argument_list|(
name|m_refresh
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|refreshClicked
argument_list|()
argument_list|)
argument_list|)
block|;
name|m_hideInvisibleItems
operator|=
name|new
name|QCheckBox
argument_list|(
name|this
argument_list|)
block|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|m_hideInvisibleItems
argument_list|)
block|;
name|m_hideInvisibleItems
operator|->
name|setText
argument_list|(
literal|"Hide Invisible Items"
argument_list|)
block|;
name|m_hideInvisibleItems
operator|->
name|setChecked
argument_list|(
name|true
argument_list|)
block|;
name|connect
argument_list|(
name|m_hideInvisibleItems
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|optionsChanged
argument_list|()
argument_list|)
argument_list|)
block|;
name|m_hideOffscreenItems
operator|=
name|new
name|QCheckBox
argument_list|(
name|this
argument_list|)
block|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|m_hideOffscreenItems
argument_list|)
block|;
name|m_hideOffscreenItems
operator|->
name|setText
argument_list|(
literal|"Hide Offscreen Items"
argument_list|)
block|;
name|m_hideOffscreenItems
operator|->
name|setChecked
argument_list|(
name|true
argument_list|)
block|;
name|connect
argument_list|(
name|m_hideOffscreenItems
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|optionsChanged
argument_list|()
argument_list|)
argument_list|)
block|;
name|m_hidePaneItems
operator|=
name|new
name|QCheckBox
argument_list|(
name|this
argument_list|)
block|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|m_hidePaneItems
argument_list|)
block|;
name|m_hidePaneItems
operator|->
name|setText
argument_list|(
literal|"Hide Items with the Pane role"
argument_list|)
block|;
name|m_hidePaneItems
operator|->
name|setChecked
argument_list|(
name|true
argument_list|)
block|;
name|connect
argument_list|(
name|m_hidePaneItems
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|optionsChanged
argument_list|()
argument_list|)
argument_list|)
block|;
name|m_enableTextToSpeach
operator|=
name|new
name|QCheckBox
argument_list|(
name|this
argument_list|)
block|;
name|m_layout
operator|->
name|addWidget
argument_list|(
name|m_enableTextToSpeach
argument_list|)
block|;
name|m_enableTextToSpeach
operator|->
name|setText
argument_list|(
literal|"Enable Text To Speech"
argument_list|)
block|;
name|m_enableTextToSpeach
operator|->
name|setChecked
argument_list|(
name|false
argument_list|)
block|;
name|connect
argument_list|(
name|m_enableTextToSpeach
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|optionsChanged
argument_list|()
argument_list|)
argument_list|)
block|;
name|m_scale
operator|=
name|new
name|QSlider
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
block|;
comment|//        m_layout->addWidget(m_scale);
name|m_scale
operator|->
name|setRange
argument_list|(
literal|5
argument_list|,
literal|30
argument_list|)
block|;
name|m_scale
operator|->
name|setValue
argument_list|(
literal|1
argument_list|)
block|;
name|connect
argument_list|(
name|m_scale
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|scaleChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
block|;
name|this
operator|->
name|setLayout
argument_list|(
name|m_layout
argument_list|)
block|;     }
name|bool
name|hideInvisibleItems
argument_list|()
block|{
return|return
name|m_hideInvisibleItems
operator|->
name|isChecked
argument_list|()
return|;
block|}
name|bool
name|hideOffscreenItems
argument_list|()
block|{
return|return
name|m_hideOffscreenItems
operator|->
name|isChecked
argument_list|()
return|;
block|}
name|bool
name|hidePaneItems
argument_list|()
block|{
return|return
name|m_hidePaneItems
operator|->
name|isChecked
argument_list|()
return|;
block|}
name|bool
name|enableTextToSpeach
argument_list|()
block|{
return|return
name|m_enableTextToSpeach
operator|->
name|isChecked
argument_list|()
return|;
block|}
name|signals
operator|:
name|void
name|optionsChanged
argument_list|()
block|;
name|void
name|refreshClicked
argument_list|()
block|;
name|void
name|scaleChanged
argument_list|(
name|int
argument_list|)
block|;
name|private
operator|:
name|QVBoxLayout
operator|*
name|m_layout
block|;
name|QPushButton
operator|*
name|m_refresh
block|;
name|QCheckBox
operator|*
name|m_hideInvisibleItems
block|;
name|QCheckBox
operator|*
name|m_hideOffscreenItems
block|;
name|QCheckBox
operator|*
name|m_hidePaneItems
block|;
name|QCheckBox
operator|*
name|m_enableTextToSpeach
block|;
name|QSlider
operator|*
name|m_scale
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// OPTIONSWIDGET_H
end_comment
end_unit
