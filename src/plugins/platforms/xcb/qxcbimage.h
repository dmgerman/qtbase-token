begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBIMAGE_H
end_ifndef
begin_define
DECL|macro|QXCBIMAGE_H
define|#
directive|define
name|QXCBIMAGE_H
end_define
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QPair>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb_image.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
name|QImage
operator|::
name|Format
name|qt_xcb_imageFormatForVisual
argument_list|(
argument|QXcbConnection *connection
argument_list|,
argument|uint8_t depth
argument_list|,
argument|const xcb_visualtype_t *visual
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QPixmap
name|qt_xcb_pixmapFromXPixmap
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|,
name|xcb_pixmap_t
name|pixmap
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|xcb_visualtype_t
modifier|*
name|visual
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|xcb_pixmap_t
name|qt_xcb_XPixmapFromBitmap
parameter_list|(
name|QXcbScreen
modifier|*
name|screen
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
