begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WIZARDPANEL_H
end_ifndef
begin_define
DECL|macro|WIZARDPANEL_H
define|#
directive|define
name|WIZARDPANEL_H
end_define
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_decl_stmt
DECL|variable|WizardStyleControl
name|class
name|WizardStyleControl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|WizardOptionsControl
name|class
name|WizardOptionsControl
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
name|WizardPanel
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|WizardPanel
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|showModal
argument_list|()
block|;
name|void
name|showNonModal
argument_list|()
block|;
name|void
name|showEmbedded
argument_list|()
block|;
name|private
operator|:
name|void
name|applyParameters
argument_list|(
argument|QWizard *wizard
argument_list|)
specifier|const
block|;
name|WizardStyleControl
operator|*
name|m_styleControl
block|;
name|WizardOptionsControl
operator|*
name|m_optionsControl
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// WIZARDPANEL_H
end_comment
end_unit
