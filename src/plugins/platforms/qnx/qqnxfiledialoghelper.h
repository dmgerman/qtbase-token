begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXFILEDIALOGHELPER_H
end_ifndef
begin_define
DECL|macro|QQNXFILEDIALOGHELPER_H
define|#
directive|define
name|QQNXFILEDIALOGHELPER_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxIntegration
name|class
name|QQnxIntegration
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY_TABLET
argument_list|)
end_if
begin_include
include|#
directive|include
file|<bps/dialog.h>
end_include
begin_define
DECL|macro|NativeDialogPtr
define|#
directive|define
name|NativeDialogPtr
value|dialog_instance_t
end_define
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|QQnxFilePicker
name|class
name|QQnxFilePicker
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|NativeDialogPtr
define|#
directive|define
name|NativeDialogPtr
value|QQnxFilePicker *
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QQnxFileDialogHelper
range|:
name|public
name|QPlatformFileDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QQnxFileDialogHelper
argument_list|(
specifier|const
name|QQnxIntegration
operator|*
argument_list|)
block|;
operator|~
name|QQnxFileDialogHelper
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY_TABLET
argument_list|)
name|bool
name|handleEvent
argument_list|(
name|bps_event_t
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|void
name|exec
argument_list|()
block|;
name|bool
name|show
argument_list|(
argument|Qt::WindowFlags flags
argument_list|,
argument|Qt::WindowModality modality
argument_list|,
argument|QWindow *parent
argument_list|)
block|;
name|void
name|hide
argument_list|()
block|;
name|bool
name|defaultNameFilterDisables
argument_list|()
specifier|const
block|;
name|void
name|setDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|directory
argument_list|)
block|;
name|QString
name|directory
argument_list|()
specifier|const
block|;
name|void
name|selectFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|QStringList
name|selectedFiles
argument_list|()
specifier|const
block|;
name|void
name|setFilter
argument_list|()
block|;
name|void
name|selectNameFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|QString
name|selectedNameFilter
argument_list|()
specifier|const
block|;
name|NativeDialogPtr
name|nativeDialog
argument_list|()
specifier|const
block|{
return|return
name|m_dialog
return|;
block|}
name|Q_SIGNALS
operator|:
name|void
name|dialogClosed
argument_list|()
block|;
name|private
operator|:
name|void
name|setNameFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|void
name|setNameFilters
argument_list|(
specifier|const
name|QStringList
operator|&
name|filters
argument_list|)
block|;
specifier|const
name|QQnxIntegration
operator|*
name|m_integration
block|;
name|NativeDialogPtr
name|m_dialog
block|;
name|QFileDialogOptions
operator|::
name|AcceptMode
name|m_acceptMode
block|;
name|QString
name|m_selectedFilter
block|;
name|QPlatformDialogHelper
operator|::
name|DialogCode
name|m_result
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY_TABLET
argument_list|)
name|QStringList
name|m_paths
block|;
endif|#
directive|endif
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
comment|// QQNXFILEDIALOGHELPER_H
end_comment
end_unit
