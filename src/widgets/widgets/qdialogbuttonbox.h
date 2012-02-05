begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIALOGBUTTONBOX_H
end_ifndef
begin_define
DECL|macro|QDIALOGBUTTONBOX_H
define|#
directive|define
name|QDIALOGBUTTONBOX_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDialogButtonBoxPrivate
name|class
name|QDialogButtonBoxPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDialogButtonBox
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|Q_FLAGS
argument_list|(
argument|StandardButtons
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Orientation orientation READ orientation WRITE setOrientation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|StandardButtons standardButtons READ standardButtons WRITE setStandardButtons
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool centerButtons READ centerButtons WRITE setCenterButtons
argument_list|)
name|public
operator|:
expr|enum
name|ButtonRole
block|{
comment|// keep this in sync with QMessageBox::ButtonRole
name|InvalidRole
operator|=
operator|-
literal|1
block|,
name|AcceptRole
block|,
name|RejectRole
block|,
name|DestructiveRole
block|,
name|ActionRole
block|,
name|HelpRole
block|,
name|YesRole
block|,
name|NoRole
block|,
name|ResetRole
block|,
name|ApplyRole
block|,
name|NRoles
block|}
block|;      enum
name|StandardButton
block|{
comment|// keep this in sync with QMessageBox::StandardButton
name|NoButton
operator|=
literal|0x00000000
block|,
name|Ok
operator|=
literal|0x00000400
block|,
name|Save
operator|=
literal|0x00000800
block|,
name|SaveAll
operator|=
literal|0x00001000
block|,
name|Open
operator|=
literal|0x00002000
block|,
name|Yes
operator|=
literal|0x00004000
block|,
name|YesToAll
operator|=
literal|0x00008000
block|,
name|No
operator|=
literal|0x00010000
block|,
name|NoToAll
operator|=
literal|0x00020000
block|,
name|Abort
operator|=
literal|0x00040000
block|,
name|Retry
operator|=
literal|0x00080000
block|,
name|Ignore
operator|=
literal|0x00100000
block|,
name|Close
operator|=
literal|0x00200000
block|,
name|Cancel
operator|=
literal|0x00400000
block|,
name|Discard
operator|=
literal|0x00800000
block|,
name|Help
operator|=
literal|0x01000000
block|,
name|Apply
operator|=
literal|0x02000000
block|,
name|Reset
operator|=
literal|0x04000000
block|,
name|RestoreDefaults
operator|=
literal|0x08000000
block|,
ifndef|#
directive|ifndef
name|Q_MOC_RUN
name|FirstButton
operator|=
name|Ok
block|,
name|LastButton
operator|=
name|RestoreDefaults
endif|#
directive|endif
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|StandardButtons
argument_list|,
name|StandardButton
argument_list|)
expr|enum
name|ButtonLayout
block|{
name|WinLayout
block|,
name|MacLayout
block|,
name|KdeLayout
block|,
name|GnomeLayout
block|}
block|;
name|QDialogButtonBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QDialogButtonBox
argument_list|(
argument|Qt::Orientation orientation
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|QDialogButtonBox
argument_list|(
argument|StandardButtons buttons
argument_list|,
argument|Qt::Orientation orientation = Qt::Horizontal
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
operator|~
name|QDialogButtonBox
argument_list|()
block|;
name|void
name|setOrientation
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
block|;
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|()
specifier|const
block|;
name|void
name|addButton
argument_list|(
argument|QAbstractButton *button
argument_list|,
argument|ButtonRole role
argument_list|)
block|;
name|QPushButton
operator|*
name|addButton
argument_list|(
argument|const QString&text
argument_list|,
argument|ButtonRole role
argument_list|)
block|;
name|QPushButton
operator|*
name|addButton
argument_list|(
argument|StandardButton button
argument_list|)
block|;
name|void
name|removeButton
argument_list|(
name|QAbstractButton
operator|*
name|button
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|QList
operator|<
name|QAbstractButton
operator|*
operator|>
name|buttons
argument_list|()
specifier|const
block|;
name|ButtonRole
name|buttonRole
argument_list|(
argument|QAbstractButton *button
argument_list|)
specifier|const
block|;
name|void
name|setStandardButtons
argument_list|(
argument|StandardButtons buttons
argument_list|)
block|;
name|StandardButtons
name|standardButtons
argument_list|()
specifier|const
block|;
name|StandardButton
name|standardButton
argument_list|(
argument|QAbstractButton *button
argument_list|)
specifier|const
block|;
name|QPushButton
operator|*
name|button
argument_list|(
argument|StandardButton which
argument_list|)
specifier|const
block|;
name|void
name|setCenterButtons
argument_list|(
argument|bool center
argument_list|)
block|;
name|bool
name|centerButtons
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|clicked
argument_list|(
name|QAbstractButton
operator|*
name|button
argument_list|)
block|;
name|void
name|accepted
argument_list|()
block|;
name|void
name|helpRequested
argument_list|()
block|;
name|void
name|rejected
argument_list|()
block|;
name|protected
operator|:
name|void
name|changeEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QDialogButtonBox
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDialogButtonBox
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_handleButtonClicked()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_handleButtonDestroyed()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDialogButtonBox::StandardButtons
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIALOGBUTTONBOX_H
end_comment
end_unit
