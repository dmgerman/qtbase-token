begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGTK2DIALOGHELPERS_P_H
end_ifndef
begin_define
DECL|macro|QGTK2DIALOGHELPERS_P_H
define|#
directive|define
name|QGTK2DIALOGHELPERS_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_typedef
DECL|typedef|GtkDialog
typedef|typedef
name|struct
name|_GtkDialog
name|GtkDialog
typedef|;
end_typedef
begin_typedef
DECL|typedef|GtkFileFilter
typedef|typedef
name|struct
name|_GtkFileFilter
name|GtkFileFilter
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGtk2Dialog
name|class
name|QGtk2Dialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGtk2ColorDialogHelper
range|:
name|public
name|QPlatformColorDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|QGtk2ColorDialogHelper
argument_list|()
block|;
operator|~
name|QGtk2ColorDialogHelper
argument_list|()
block|;
name|virtual
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
name|virtual
name|void
name|exec
argument_list|()
block|;
name|virtual
name|void
name|hide
argument_list|()
block|;
name|virtual
name|void
name|setCurrentColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|virtual
name|QColor
name|currentColor
argument_list|()
specifier|const
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|onAccepted
argument_list|()
block|;
name|private
operator|:
specifier|static
name|void
name|onColorChanged
argument_list|(
name|QGtk2ColorDialogHelper
operator|*
name|helper
argument_list|)
block|;
name|void
name|applyOptions
argument_list|()
block|;
name|mutable
name|QScopedPointer
operator|<
name|QGtk2Dialog
operator|>
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGtk2FileDialogHelper
range|:
name|public
name|QPlatformFileDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|QGtk2FileDialogHelper
argument_list|()
block|;
operator|~
name|QGtk2FileDialogHelper
argument_list|()
block|;
name|virtual
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
name|virtual
name|void
name|exec
argument_list|()
block|;
name|virtual
name|void
name|hide
argument_list|()
block|;
name|virtual
name|bool
name|defaultNameFilterDisables
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|directory
argument_list|)
block|;
name|virtual
name|QString
name|directory
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|selectFile
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|)
block|;
name|virtual
name|QStringList
name|selectedFiles
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setFilter
argument_list|()
block|;
name|virtual
name|void
name|selectNameFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|virtual
name|QString
name|selectedNameFilter
argument_list|()
specifier|const
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|onAccepted
argument_list|()
block|;
name|private
operator|:
specifier|static
name|void
name|onSelectionChanged
argument_list|(
name|GtkDialog
operator|*
name|dialog
argument_list|,
name|QGtk2FileDialogHelper
operator|*
name|helper
argument_list|)
block|;
specifier|static
name|void
name|onCurrentFolderChanged
argument_list|(
name|QGtk2FileDialogHelper
operator|*
name|helper
argument_list|)
block|;
name|void
name|applyOptions
argument_list|()
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
name|QString
name|_dir
block|;
name|QStringList
name|_selection
block|;
name|QHash
operator|<
name|QString
block|,
name|GtkFileFilter
operator|*
operator|>
name|_filters
block|;
name|QHash
operator|<
name|GtkFileFilter
operator|*
block|,
name|QString
operator|>
name|_filterNames
block|;
name|mutable
name|QScopedPointer
operator|<
name|QGtk2Dialog
operator|>
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGtk2FontDialogHelper
range|:
name|public
name|QPlatformFontDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|QGtk2FontDialogHelper
argument_list|()
block|;
operator|~
name|QGtk2FontDialogHelper
argument_list|()
block|;
name|virtual
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
name|virtual
name|void
name|exec
argument_list|()
block|;
name|virtual
name|void
name|hide
argument_list|()
block|;
name|virtual
name|void
name|setCurrentFont
argument_list|(
specifier|const
name|QFont
operator|&
name|font
argument_list|)
block|;
name|virtual
name|QFont
name|currentFont
argument_list|()
specifier|const
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|onAccepted
argument_list|()
block|;
name|private
operator|:
name|void
name|applyOptions
argument_list|()
block|;
name|mutable
name|QScopedPointer
operator|<
name|QGtk2Dialog
operator|>
name|d
block|; }
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
comment|// QGTK2DIALOGHELPERS_P_H
end_comment
end_unit
