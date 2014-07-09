begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEDIALOG_P_H
end_ifndef
begin_define
DECL|macro|QFILEDIALOG_P_H
define|#
directive|define
name|QFILEDIALOG_P_H
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
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILEDIALOG
end_ifndef
begin_include
include|#
directive|include
file|"qfiledialog.h"
end_include
begin_include
include|#
directive|include
file|"private/qdialog_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qfilesystemmodel_p.h"
end_include
begin_include
include|#
directive|include
file|<qlistview.h>
end_include
begin_include
include|#
directive|include
file|<qtreeview.h>
end_include
begin_include
include|#
directive|include
file|<qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbutton.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<qstackedwidget.h>
end_include
begin_include
include|#
directive|include
file|<qdialogbuttonbox.h>
end_include
begin_include
include|#
directive|include
file|<qabstractproxymodel.h>
end_include
begin_include
include|#
directive|include
file|<qcompleter.h>
end_include
begin_include
include|#
directive|include
file|<qpointer.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qsidebar_p.h"
end_include
begin_include
include|#
directive|include
file|"qfscompleter_p.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFileDialogListView
name|class
name|QFileDialogListView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileDialogTreeView
name|class
name|QFileDialogTreeView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileDialogLineEdit
name|class
name|QFileDialogLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGridLayout
name|class
name|QGridLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCompleter
name|class
name|QCompleter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHBoxLayout
name|class
name|QHBoxLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Ui_QFileDialog
name|class
name|Ui_QFileDialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDialogHelper
name|class
name|QPlatformDialogHelper
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QFileDialogArgs
struct|struct
name|QFileDialogArgs
block|{
DECL|function|QFileDialogArgs
name|QFileDialogArgs
argument_list|()
operator|:
name|parent
argument_list|(
literal|0
argument_list|)
operator|,
name|mode
argument_list|(
argument|QFileDialog::AnyFile
argument_list|)
block|{}
DECL|member|parent
name|QWidget
operator|*
name|parent
expr_stmt|;
DECL|member|caption
name|QString
name|caption
decl_stmt|;
DECL|member|directory
name|QString
name|directory
decl_stmt|;
DECL|member|selection
name|QString
name|selection
decl_stmt|;
DECL|member|filter
name|QString
name|filter
decl_stmt|;
DECL|member|mode
name|QFileDialog
operator|::
name|FileMode
name|mode
expr_stmt|;
DECL|member|options
name|QFileDialog
operator|::
name|Options
name|options
expr_stmt|;
block|}
struct|;
end_struct
begin_define
DECL|macro|UrlRole
define|#
directive|define
name|UrlRole
value|(Qt::UserRole + 1)
end_define
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QFileDialogPrivate
range|:
name|public
name|QDialogPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFileDialog
argument_list|)
name|public
operator|:
name|QFileDialogPrivate
argument_list|()
block|;
name|QPlatformFileDialogHelper
operator|*
name|platformFileDialogHelper
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|QPlatformFileDialogHelper
operator|*
operator|>
operator|(
name|platformHelper
argument_list|()
operator|)
return|;
block|}
name|void
name|createToolButtons
argument_list|()
block|;
name|void
name|createMenuActions
argument_list|()
block|;
name|void
name|createWidgets
argument_list|()
block|;
name|void
name|init
argument_list|(
specifier|const
name|QString
operator|&
name|directory
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|nameFilter
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|caption
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|bool
name|itemViewKeyboardEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|QString
name|getEnvironmentVariable
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
block|;
specifier|static
name|QString
name|workingDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
specifier|static
name|QString
name|initialSelection
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|QStringList
name|typedFiles
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QUrl
operator|>
name|userSelectedFiles
argument_list|()
specifier|const
block|;
name|QStringList
name|addDefaultSuffixToFiles
argument_list|(
argument|const QStringList filesToFix
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QUrl
operator|>
name|addDefaultSuffixToUrls
argument_list|(
argument|const QList<QUrl>&urlsToFix
argument_list|)
specifier|const
block|;
name|bool
name|removeDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|setLabelTextControl
argument_list|(
argument|QFileDialog::DialogLabel label
argument_list|,
argument|const QString&text
argument_list|)
block|;
specifier|inline
name|void
name|updateLookInLabel
argument_list|()
block|;
specifier|inline
name|void
name|updateFileNameLabel
argument_list|()
block|;
specifier|inline
name|void
name|updateFileTypeLabel
argument_list|()
block|;
name|void
name|updateOkButtonText
argument_list|(
argument|bool saveAsOnFolder = false
argument_list|)
block|;
name|void
name|updateCancelButtonText
argument_list|()
block|;
specifier|inline
name|QModelIndex
name|mapToSource
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|QModelIndex
name|mapFromSource
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|QModelIndex
name|rootIndex
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|setRootIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|QModelIndex
name|select
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|QString
name|rootPath
argument_list|()
specifier|const
block|;
name|QLineEdit
operator|*
name|lineEdit
argument_list|()
specifier|const
block|;
specifier|static
name|int
name|maxNameLength
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|QString
name|basename
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|{
name|int
name|separator
operator|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|path
argument_list|)
operator|.
name|lastIndexOf
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|separator
operator|!=
operator|-
literal|1
condition|)
return|return
name|path
operator|.
name|mid
argument_list|(
name|separator
operator|+
literal|1
argument_list|)
return|;
return|return
name|path
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|QDir
operator|::
name|Filters
name|filterForMode
argument_list|(
argument|QDir::Filters filters
argument_list|)
specifier|const
block|{
specifier|const
name|QFileDialog
operator|::
name|FileMode
name|fileMode
operator|=
name|q_func
argument_list|()
operator|->
name|fileMode
argument_list|()
block|;
if|if
condition|(
name|fileMode
operator|==
name|QFileDialog
operator|::
name|DirectoryOnly
condition|)
block|{
name|filters
operator||=
name|QDir
operator|::
name|Drives
operator||
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|Dirs
expr_stmt|;
name|filters
operator|&=
operator|~
name|QDir
operator|::
name|Files
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|filters
operator||=
name|QDir
operator|::
name|Drives
operator||
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Dirs
expr_stmt|;
block|}
end_else
begin_return
return|return
name|filters
return|;
end_return
begin_expr_stmt
unit|}      QAbstractItemView
operator|*
name|currentView
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|QString
name|toInternal
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|QString
name|n
argument_list|(
name|path
argument_list|)
decl_stmt|;
name|n
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|,
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
if|if
condition|(
operator|(
name|n
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|)
operator|&&
operator|(
name|n
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"//"
argument_list|)
argument_list|)
operator|)
condition|)
name|n
operator|=
name|n
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|n
return|;
else|#
directive|else
comment|// the compile should optimize away this
return|return
name|path
return|;
endif|#
directive|endif
block|}
end_function
begin_function_decl
name|void
name|setLastVisitedDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|dir
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|retranslateWindowTitle
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|retranslateStrings
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|emitFilesSelected
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_goHome
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_pathChanged
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_navigateBackward
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_navigateForward
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_navigateToParent
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_createDirectory
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showListView
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showDetailsView
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showContextMenu
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|position
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_renameCurrent
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_deleteCurrent
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showHidden
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showHeader
parameter_list|(
name|QAction
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_updateOkButton
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_currentChanged
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_enterDirectory
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_emitUrlSelected
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|_q_emitUrlsSelected
argument_list|(
specifier|const
name|QList
operator|<
name|QUrl
operator|>
operator|&
name|files
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|_q_nativeCurrentChanged
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|file
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_nativeEnterDirectory
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|directory
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_goToDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_useNameFilter
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_selectionChanged
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_goToUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_autoCompleteFileName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_rowsInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_fileRenamed
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
name|oldName
parameter_list|,
specifier|const
name|QString
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// layout
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROXYMODEL
end_ifndef
begin_decl_stmt
name|QAbstractProxyModel
modifier|*
name|proxyModel
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// data
end_comment
begin_decl_stmt
name|QStringList
name|watching
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFileSystemModel
modifier|*
name|model
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FSCOMPLETER
end_ifndef
begin_decl_stmt
name|QFSCompleter
modifier|*
name|completer
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_FSCOMPLETER
end_comment
begin_decl_stmt
name|QString
name|setWindowTitle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|currentHistory
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|currentHistoryLocation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|renameAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|deleteAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|showHiddenAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|newFolderAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|useDefaultCaption
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|defaultFileTypes
decl_stmt|;
end_decl_stmt
begin_comment
comment|// setVisible_sys returns true if it ends up showing a native
end_comment
begin_comment
comment|// dialog. Returning false means that a non-native dialog must be
end_comment
begin_comment
comment|// used instead.
end_comment
begin_expr_stmt
name|bool
name|canBeNativeDialog
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|usingWidgets
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDirectory_sys
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|directory
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QUrl
name|directory_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|selectFile_sys
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|filename
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QList
operator|<
name|QUrl
operator|>
name|selectedFiles_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFilter_sys
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|selectNameFilter_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|selectedNameFilter_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|//////////////////////////////////////////////
end_comment
begin_expr_stmt
name|QScopedPointer
operator|<
name|Ui_QFileDialog
operator|>
name|qFileDialogUi
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|acceptLabel
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QObject
operator|>
name|receiverToDisconnectOnClose
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QByteArray
name|memberToDisconnectOnClose
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|signalToDisconnectOnClose
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QSharedPointer
operator|<
name|QFileDialogOptions
operator|>
name|options
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QFileDialogPrivate
argument_list|()
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
name|virtual
name|void
name|initHelper
parameter_list|(
name|QPlatformDialogHelper
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|helperPrepareShow
parameter_list|(
name|QPlatformDialogHelper
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|void
name|helperDone
argument_list|(
name|QDialog
operator|::
name|DialogCode
argument_list|,
name|QPlatformDialogHelper
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QFileDialogPrivate
argument_list|)
end_macro
begin_decl_stmt
unit|};
name|class
name|QFileDialogLineEdit
range|:
name|public
name|QLineEdit
block|{
name|public
operator|:
name|QFileDialogLineEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QLineEdit
argument_list|(
name|parent
argument_list|)
block|,
name|d_ptr
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|setFileDialogPrivate
argument_list|(
argument|QFileDialogPrivate *d_pointer
argument_list|)
block|{
name|d_ptr
operator|=
name|d_pointer
block|; }
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|bool
name|hideOnEsc
block|;
name|private
operator|:
name|QFileDialogPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFileDialogComboBox
range|:
name|public
name|QComboBox
block|{
name|public
operator|:
name|QFileDialogComboBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QComboBox
argument_list|(
name|parent
argument_list|)
block|,
name|urlModel
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|setFileDialogPrivate
argument_list|(
name|QFileDialogPrivate
operator|*
name|d_pointer
argument_list|)
block|;
name|void
name|showPopup
argument_list|()
block|;
name|void
name|setHistory
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|)
block|;
name|QStringList
name|history
argument_list|()
specifier|const
block|{
return|return
name|m_history
return|;
block|}
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|QUrlModel
operator|*
name|urlModel
block|;
name|QFileDialogPrivate
operator|*
name|d_ptr
block|;
name|QStringList
name|m_history
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFileDialogListView
range|:
name|public
name|QListView
block|{
name|public
operator|:
name|QFileDialogListView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|setFileDialogPrivate
argument_list|(
name|QFileDialogPrivate
operator|*
name|d_pointer
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|QFileDialogPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFileDialogTreeView
range|:
name|public
name|QTreeView
block|{
name|public
operator|:
name|QFileDialogTreeView
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|void
name|setFileDialogPrivate
argument_list|(
name|QFileDialogPrivate
operator|*
name|d_pointer
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|QFileDialogPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|mapToSource
specifier|inline
name|QModelIndex
name|QFileDialogPrivate
operator|::
name|mapToSource
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_NO_PROXYMODEL
return|return
name|index
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|proxyModel
condition|?
name|proxyModel
operator|->
name|mapToSource
argument_list|(
name|index
argument_list|)
else|:
name|index
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|} inline
DECL|function|mapFromSource
name|QModelIndex
name|QFileDialogPrivate
operator|::
name|mapFromSource
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_NO_PROXYMODEL
return|return
name|index
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|proxyModel
condition|?
name|proxyModel
operator|->
name|mapFromSource
argument_list|(
name|index
argument_list|)
else|:
name|index
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|}  inline
DECL|function|rootPath
name|QString
name|QFileDialogPrivate
operator|::
name|rootPath
argument_list|()
specifier|const
block|{
return|return
operator|(
name|model
operator|?
name|model
operator|->
name|rootPath
argument_list|()
operator|:
name|QStringLiteral
argument_list|(
literal|"/"
argument_list|)
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setDirectory_sys
specifier|inline
name|void
name|QFileDialogPrivate
operator|::
name|setDirectory_sys
argument_list|(
argument|const QUrl&directory
argument_list|)
block|{
name|QPlatformFileDialogHelper
operator|*
name|helper
operator|=
name|platformFileDialogHelper
argument_list|()
block|;
if|if
condition|(
operator|!
name|helper
condition|)
return|return;
end_expr_stmt
begin_if
if|if
condition|(
name|helper
operator|->
name|isSupportedUrl
argument_list|(
name|directory
argument_list|)
condition|)
name|helper
operator|->
name|setDirectory
argument_list|(
name|directory
argument_list|)
expr_stmt|;
end_if
begin_expr_stmt
unit|}  inline
DECL|function|directory_sys
name|QUrl
name|QFileDialogPrivate
operator|::
name|directory_sys
argument_list|()
specifier|const
block|{
if|if
condition|(
name|QPlatformFileDialogHelper
modifier|*
name|helper
init|=
name|platformFileDialogHelper
argument_list|()
condition|)
return|return
name|helper
operator|->
name|directory
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|QUrl
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|selectFile_sys
name|void
name|QFileDialogPrivate
operator|::
name|selectFile_sys
argument_list|(
argument|const QUrl&filename
argument_list|)
block|{
name|QPlatformFileDialogHelper
operator|*
name|helper
operator|=
name|platformFileDialogHelper
argument_list|()
block|;
if|if
condition|(
operator|!
name|helper
condition|)
return|return;
end_expr_stmt
begin_if
if|if
condition|(
name|helper
operator|->
name|isSupportedUrl
argument_list|(
name|filename
argument_list|)
condition|)
name|helper
operator|->
name|selectFile
argument_list|(
name|filename
argument_list|)
expr_stmt|;
end_if
begin_expr_stmt
unit|}  inline
DECL|function|selectedFiles_sys
name|QList
operator|<
name|QUrl
operator|>
name|QFileDialogPrivate
operator|::
name|selectedFiles_sys
argument_list|()
specifier|const
block|{
if|if
condition|(
name|QPlatformFileDialogHelper
modifier|*
name|helper
init|=
name|platformFileDialogHelper
argument_list|()
condition|)
return|return
name|helper
operator|->
name|selectedFiles
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|QList
operator|<
name|QUrl
operator|>
operator|(
operator|)
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|setFilter_sys
name|void
name|QFileDialogPrivate
operator|::
name|setFilter_sys
argument_list|()
block|{
if|if
condition|(
name|QPlatformFileDialogHelper
modifier|*
name|helper
init|=
name|platformFileDialogHelper
argument_list|()
condition|)
name|helper
operator|->
name|setFilter
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|selectNameFilter_sys
specifier|inline
name|void
name|QFileDialogPrivate
operator|::
name|selectNameFilter_sys
argument_list|(
argument|const QString&filter
argument_list|)
block|{
if|if
condition|(
name|QPlatformFileDialogHelper
modifier|*
name|helper
init|=
name|platformFileDialogHelper
argument_list|()
condition|)
name|helper
operator|->
name|selectNameFilter
argument_list|(
name|filter
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|selectedNameFilter_sys
specifier|inline
name|QString
name|QFileDialogPrivate
operator|::
name|selectedNameFilter_sys
argument_list|()
specifier|const
block|{
if|if
condition|(
name|QPlatformFileDialogHelper
modifier|*
name|helper
init|=
name|platformFileDialogHelper
argument_list|()
condition|)
return|return
name|helper
operator|->
name|selectedNameFilter
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|QString
argument_list|()
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FILEDIALOG
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEDIALOG_P_H
end_comment
end_unit
