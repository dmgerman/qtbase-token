begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLABEL_P_H
end_ifndef
begin_define
DECL|macro|QLABEL_P_H
define|#
directive|define
name|QLABEL_P_H
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
file|"qlabel.h"
end_include
begin_include
include|#
directive|include
file|"private/qtextdocumentlayout_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtextcontrol_p.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocumentfragment.h"
end_include
begin_include
include|#
directive|include
file|"qframe_p.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocument.h"
end_include
begin_include
include|#
directive|include
file|"qmovie.h"
end_include
begin_include
include|#
directive|include
file|"qimage.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qpicture.h"
end_include
begin_include
include|#
directive|include
file|"qmenu.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QLabelPrivate
range|:
name|public
name|QFramePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QLabel
argument_list|)
name|public
operator|:
name|QLabelPrivate
argument_list|()
block|{}
name|void
name|init
argument_list|()
block|;
name|void
name|clearContents
argument_list|()
block|;
name|void
name|updateLabel
argument_list|()
block|;
name|QSize
name|sizeForWidth
argument_list|(
argument|int w
argument_list|)
specifier|const
block|;
name|mutable
name|QSize
name|sh
block|;
name|mutable
name|QSize
name|msh
block|;
name|mutable
name|bool
name|valid_hints
block|;
name|mutable
name|QSizePolicy
name|sizePolicy
block|;
name|int
name|margin
block|;
name|QString
name|text
block|;
name|QPixmap
operator|*
name|pixmap
block|;
name|QPixmap
operator|*
name|scaledpixmap
block|;
name|QImage
operator|*
name|cachedimage
block|;
ifndef|#
directive|ifndef
name|QT_NO_PICTURE
name|QPicture
operator|*
name|picture
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_MOVIE
name|QPointer
operator|<
name|QMovie
operator|>
name|movie
block|;
name|void
name|_q_movieUpdated
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
block|;
name|void
name|_q_movieResized
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|void
name|updateShortcut
argument_list|()
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|QPointer
operator|<
name|QWidget
operator|>
name|buddy
block|;
name|int
name|shortcutId
block|;
endif|#
directive|endif
name|ushort
name|align
block|;
name|short
name|indent
block|;
name|uint
name|scaledcontents
operator|:
literal|1
block|;
name|mutable
name|uint
name|textLayoutDirty
operator|:
literal|1
block|;
name|mutable
name|uint
name|textDirty
operator|:
literal|1
block|;
name|mutable
name|uint
name|isRichText
operator|:
literal|1
block|;
name|mutable
name|uint
name|isTextLabel
operator|:
literal|1
block|;
name|mutable
name|uint
name|hasShortcut
operator|:
literal|1
block|;
name|Qt
operator|::
name|TextFormat
name|textformat
block|;
name|mutable
name|QTextControl
operator|*
name|control
block|;
name|mutable
name|QTextCursor
name|shortcutCursor
block|;
name|Qt
operator|::
name|TextInteractionFlags
name|textInteractionFlags
block|;
specifier|inline
name|bool
name|needTextControl
argument_list|()
specifier|const
block|{
return|return
name|isTextLabel
operator|&&
operator|(
name|isRichText
operator|||
operator|(
operator|!
name|isRichText
operator|&&
operator|(
name|textInteractionFlags
operator|&
operator|(
name|Qt
operator|::
name|TextSelectableByMouse
operator||
name|Qt
operator|::
name|TextSelectableByKeyboard
operator|)
operator|)
operator|)
operator|)
return|;
block|}
name|void
name|ensureTextPopulated
argument_list|()
specifier|const
block|;
name|void
name|ensureTextLayouted
argument_list|()
specifier|const
block|;
name|void
name|ensureTextControl
argument_list|()
specifier|const
block|;
name|void
name|sendControlEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|_q_linkHovered
argument_list|(
specifier|const
name|QString
operator|&
name|link
argument_list|)
block|;
name|QRectF
name|layoutRect
argument_list|()
specifier|const
block|;
name|QRect
name|documentRect
argument_list|()
specifier|const
block|;
name|QPoint
name|layoutPoint
argument_list|(
argument|const QPoint& p
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|LayoutDirection
name|textDirection
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
name|QMenu
operator|*
name|createStandardContextMenu
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
endif|#
directive|endif
name|bool
name|openExternalLinks
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|uint
name|validCursor
operator|:
literal|1
block|;
name|uint
name|onAnchor
operator|:
literal|1
block|;
name|QCursor
name|cursor
block|;
endif|#
directive|endif
name|friend
name|class
name|QMessageBoxPrivate
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
comment|// QLABEL_P_H
end_comment
end_unit
