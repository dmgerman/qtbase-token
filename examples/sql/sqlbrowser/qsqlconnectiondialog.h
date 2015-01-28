begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLCONNECTIONDIALOG_H
end_ifndef
begin_define
DECL|macro|QSQLCONNECTIONDIALOG_H
define|#
directive|define
name|QSQLCONNECTIONDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QDialog>
end_include
begin_include
include|#
directive|include
file|<QMessageBox>
end_include
begin_include
include|#
directive|include
file|"ui_qsqlconnectiondialog.h"
end_include
begin_decl_stmt
name|class
name|QSqlConnectionDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|QSqlConnectionDialog
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSqlConnectionDialog
argument_list|()
block|;
name|QString
name|driverName
argument_list|()
specifier|const
block|;
name|QString
name|databaseName
argument_list|()
specifier|const
block|;
name|QString
name|userName
argument_list|()
specifier|const
block|;
name|QString
name|password
argument_list|()
specifier|const
block|;
name|QString
name|hostName
argument_list|()
specifier|const
block|;
name|int
name|port
argument_list|()
specifier|const
block|;
name|bool
name|useInMemoryDatabase
argument_list|()
specifier|const
block|;
name|private
name|slots
operator|:
name|void
name|on_okButton_clicked
argument_list|()
block|;
name|void
name|on_cancelButton_clicked
argument_list|()
block|{
name|reject
argument_list|()
block|; }
name|void
name|on_dbCheckBox_clicked
argument_list|()
block|{
name|ui
operator|.
name|connGroupBox
operator|->
name|setEnabled
argument_list|(
operator|!
name|ui
operator|.
name|dbCheckBox
operator|->
name|isChecked
argument_list|()
argument_list|)
block|; }
name|private
operator|:
name|Ui
operator|::
name|QSqlConnectionDialogUi
name|ui
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
