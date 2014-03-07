begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXFILEPICKER_H
end_ifndef
begin_define
DECL|macro|QQNXFILEPICKER_H
define|#
directive|define
name|QQNXFILEPICKER_H
end_define
begin_include
include|#
directive|include
file|<QAbstractNativeEventFilter>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_struct_decl
struct_decl|struct
name|navigator_invoke_invocation_t
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QObject
name|class
name|QQnxFilePicker
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QAbstractNativeEventFilter
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|QQnxFilePicker
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QQnxFilePicker
argument_list|()
expr_stmt|;
enum|enum
name|Mode
block|{
name|Picker
block|,
name|Saver
block|,
name|PickerMultiple
block|,
name|SaverMultiple
block|}
enum|;
name|bool
name|nativeEventFilter
argument_list|(
specifier|const
name|QByteArray
operator|&
name|eventType
argument_list|,
name|void
operator|*
name|message
argument_list|,
name|long
operator|*
name|result
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setMode
parameter_list|(
name|Mode
name|mode
parameter_list|)
function_decl|;
name|void
name|setDefaultSaveFileNames
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|fileNames
parameter_list|)
function_decl|;
name|void
name|addDefaultSaveFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
name|void
name|setDirectories
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|directories
parameter_list|)
function_decl|;
name|void
name|addDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|directory
parameter_list|)
function_decl|;
name|void
name|setFilters
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|)
function_decl|;
name|void
name|setTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
name|Mode
name|mode
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|defaultSaveFileNames
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|directories
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|filters
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|selectedFiles
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|title
argument_list|()
specifier|const
expr_stmt|;
name|Q_SIGNALS
label|:
name|void
name|closed
parameter_list|()
function_decl|;
name|public
name|Q_SLOTS
range|:
name|void
name|open
argument_list|()
decl_stmt|;
name|void
name|close
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|handleFilePickerResponse
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
name|QString
name|filePickerType
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|modeToString
argument_list|(
name|Mode
name|mode
argument_list|)
decl|const
decl_stmt|;
name|navigator_invoke_invocation_t
modifier|*
name|m_invocationHandle
decl_stmt|;
name|Mode
name|m_mode
decl_stmt|;
name|QStringList
name|m_defaultSaveFileNames
decl_stmt|;
name|QStringList
name|m_directories
decl_stmt|;
name|QStringList
name|m_filters
decl_stmt|;
name|QStringList
name|m_selectedFiles
decl_stmt|;
name|QString
name|m_title
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQNXFILEPICKER_H
end_comment
end_unit
