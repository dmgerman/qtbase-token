begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 Research In Motion ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxfiledialoghelper.h"
end_include
begin_include
include|#
directive|include
file|"qqnxfilepicker.h"
end_include
begin_include
include|#
directive|include
file|"qqnxbpseventfilter.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxintegration.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QEventLoop>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QQNXFILEDIALOGHELPER_DEBUG
end_ifdef
begin_define
DECL|macro|qFileDialogHelperDebug
define|#
directive|define
name|qFileDialogHelperDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qFileDialogHelperDebug
define|#
directive|define
name|qFileDialogHelperDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxFileDialogHelper
name|QQnxFileDialogHelper
operator|::
name|QQnxFileDialogHelper
parameter_list|(
specifier|const
name|QQnxIntegration
modifier|*
name|integration
parameter_list|)
member_init_list|:
name|QPlatformFileDialogHelper
argument_list|()
member_init_list|,
name|m_integration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|m_dialog
argument_list|(
operator|new
name|QQnxFilePicker
argument_list|)
member_init_list|,
name|m_acceptMode
argument_list|(
name|QFileDialogOptions
operator|::
name|AcceptOpen
argument_list|)
member_init_list|,
name|m_selectedFilter
argument_list|()
block|{
name|connect
argument_list|(
name|m_dialog
argument_list|,
operator|&
name|QQnxFilePicker
operator|::
name|closed
argument_list|,
name|this
argument_list|,
operator|&
name|QQnxFileDialogHelper
operator|::
name|emitSignals
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxFileDialogHelper
name|QQnxFileDialogHelper
operator|::
name|~
name|QQnxFileDialogHelper
parameter_list|()
block|{
operator|delete
name|m_dialog
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|exec
name|void
name|QQnxFileDialogHelper
operator|::
name|exec
parameter_list|()
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Clear any previous results
name|m_dialog
operator|->
name|setDirectories
argument_list|(
name|QStringList
argument_list|()
argument_list|)
expr_stmt|;
name|QEventLoop
name|loop
decl_stmt|;
name|connect
argument_list|(
name|m_dialog
argument_list|,
name|SIGNAL
argument_list|(
name|closed
argument_list|()
argument_list|)
argument_list|,
operator|&
name|loop
argument_list|,
name|SLOT
argument_list|(
name|quit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|loop
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|show
name|bool
name|QQnxFileDialogHelper
operator|::
name|show
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|,
name|Qt
operator|::
name|WindowModality
name|modality
parameter_list|,
name|QWindow
modifier|*
name|parent
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|modality
argument_list|)
expr_stmt|;
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
comment|// Create dialog
specifier|const
name|QSharedPointer
argument_list|<
name|QFileDialogOptions
argument_list|>
modifier|&
name|opts
init|=
name|options
argument_list|()
decl_stmt|;
if|if
condition|(
name|opts
operator|->
name|acceptMode
argument_list|()
operator|==
name|QFileDialogOptions
operator|::
name|AcceptOpen
condition|)
block|{
comment|// Select one or many files?
specifier|const
name|QQnxFilePicker
operator|::
name|Mode
name|mode
init|=
operator|(
name|opts
operator|->
name|fileMode
argument_list|()
operator|==
name|QFileDialogOptions
operator|::
name|ExistingFiles
operator|)
condition|?
name|QQnxFilePicker
operator|::
name|PickerMultiple
else|:
name|QQnxFilePicker
operator|::
name|Picker
decl_stmt|;
name|m_dialog
operator|->
name|setMode
argument_list|(
name|mode
argument_list|)
expr_stmt|;
comment|// Set the actual list of extensions
if|if
condition|(
operator|!
name|opts
operator|->
name|nameFilters
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|setNameFilters
argument_list|(
name|opts
operator|->
name|nameFilters
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|setNameFilter
argument_list|(
name|tr
argument_list|(
literal|"All files (*.*)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QQnxFilePicker
operator|::
name|Mode
name|mode
init|=
operator|(
name|opts
operator|->
name|initiallySelectedFiles
argument_list|()
operator|.
name|count
argument_list|()
operator|>=
literal|2
operator|)
condition|?
name|QQnxFilePicker
operator|::
name|SaverMultiple
else|:
name|QQnxFilePicker
operator|::
name|Saver
decl_stmt|;
name|m_dialog
operator|->
name|setMode
argument_list|(
name|mode
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|opts
operator|->
name|initiallySelectedFiles
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QStringList
name|files
decl_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QUrl&url
argument_list|,
argument|opts->initiallySelectedFiles()
argument_list|)
name|files
operator|.
name|append
argument_list|(
name|url
operator|.
name|toLocalFile
argument_list|()
argument_list|)
expr_stmt|;
name|m_dialog
operator|->
name|setDefaultSaveFileNames
argument_list|(
name|files
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Cache the accept mode so we know which functions to use to get the results back
name|m_acceptMode
operator|=
name|opts
operator|->
name|acceptMode
argument_list|()
expr_stmt|;
name|m_dialog
operator|->
name|setTitle
argument_list|(
name|opts
operator|->
name|windowTitle
argument_list|()
argument_list|)
expr_stmt|;
name|m_dialog
operator|->
name|open
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hide
name|void
name|QQnxFileDialogHelper
operator|::
name|hide
parameter_list|()
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|m_dialog
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultNameFilterDisables
name|bool
name|QQnxFileDialogHelper
operator|::
name|defaultNameFilterDisables
parameter_list|()
specifier|const
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setDirectory
name|void
name|QQnxFileDialogHelper
operator|::
name|setDirectory
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|directory
parameter_list|)
block|{
name|m_dialog
operator|->
name|addDirectory
argument_list|(
name|directory
operator|.
name|toLocalFile
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|directory
name|QUrl
name|QQnxFileDialogHelper
operator|::
name|directory
parameter_list|()
specifier|const
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
if|if
condition|(
operator|!
name|m_dialog
operator|->
name|directories
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|m_dialog
operator|->
name|directories
argument_list|()
operator|.
name|first
argument_list|()
argument_list|)
return|;
return|return
name|QUrl
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|selectFile
name|void
name|QQnxFileDialogHelper
operator|::
name|selectFile
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|fileName
parameter_list|)
block|{
name|m_dialog
operator|->
name|addDefaultSaveFileName
argument_list|(
name|fileName
operator|.
name|toLocalFile
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectedFiles
name|QList
argument_list|<
name|QUrl
argument_list|>
name|QQnxFileDialogHelper
operator|::
name|selectedFiles
parameter_list|()
specifier|const
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|QList
argument_list|<
name|QUrl
argument_list|>
name|urls
decl_stmt|;
name|QStringList
name|files
init|=
name|m_dialog
operator|->
name|selectedFiles
argument_list|()
decl_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QString&file
argument_list|,
argument|files
argument_list|)
name|urls
operator|.
name|append
argument_list|(
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|file
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|urls
return|;
block|}
end_function
begin_function
DECL|function|setFilter
name|void
name|QQnxFileDialogHelper
operator|::
name|setFilter
parameter_list|()
block|{
comment|// No native api to support setting a filter from QDir::Filters
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectNameFilter
name|void
name|QQnxFileDialogHelper
operator|::
name|selectNameFilter
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"filter ="
operator|<<
name|filter
expr_stmt|;
name|setNameFilter
argument_list|(
name|filter
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectedNameFilter
name|QString
name|QQnxFileDialogHelper
operator|::
name|selectedNameFilter
parameter_list|()
specifier|const
block|{
comment|// For now there is no way for the user to change the selected filter
comment|// so this just reflects what the developer has set programmatically.
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
return|return
name|m_selectedFilter
return|;
block|}
end_function
begin_function
DECL|function|emitSignals
name|void
name|QQnxFileDialogHelper
operator|::
name|emitSignals
parameter_list|()
block|{
if|if
condition|(
name|m_dialog
operator|->
name|selectedFiles
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|Q_EMIT
name|reject
argument_list|()
decl_stmt|;
else|else
name|Q_EMIT
name|accept
argument_list|()
decl_stmt|;
block|}
end_function
begin_function
DECL|function|setNameFilter
name|void
name|QQnxFileDialogHelper
operator|::
name|setNameFilter
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"filter ="
operator|<<
name|filter
expr_stmt|;
name|setNameFilters
argument_list|(
name|QPlatformFileDialogHelper
operator|::
name|cleanFilterList
argument_list|(
name|filter
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setNameFilters
name|void
name|QQnxFileDialogHelper
operator|::
name|setNameFilters
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|)
block|{
name|qFileDialogHelperDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"filters ="
operator|<<
name|filters
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|filters
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|m_dialog
operator|->
name|setFilters
argument_list|(
name|filters
argument_list|)
expr_stmt|;
name|m_selectedFilter
operator|=
name|filters
operator|.
name|first
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
