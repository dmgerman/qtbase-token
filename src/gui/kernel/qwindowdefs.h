begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWDEFS_H
end_ifndef
begin_define
DECL|macro|QWINDOWDEFS_H
define|#
directive|define
name|QWINDOWDEFS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// Class forward definitions
DECL|variable|QPaintDevice
name|class
name|QPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDialog
name|class
name|QDialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCursor
name|class
name|QCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPolygon
name|class
name|QPolygon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontMetrics
name|class
name|QFontMetrics
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFontInfo
name|class
name|QFontInfo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPen
name|class
name|QPen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBrush
name|class
name|QBrush
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMatrix
name|class
name|QMatrix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBitmap
name|class
name|QBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMovie
name|class
name|QMovie
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPicture
name|class
name|QPicture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimer
name|class
name|QTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTime
name|class
name|QTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QClipboard
name|class
name|QClipboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QApplication
name|class
name|QApplication
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QWidgetList
typedef|typedef
name|QList
operator|<
name|QWidget
operator|*
operator|>
name|QWidgetList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|QWindowList
typedef|typedef
name|QList
operator|<
name|QWindow
operator|*
operator|>
name|QWindowList
expr_stmt|;
end_typedef
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_comment
comment|// Window system dependent definitions
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs_win.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_typedef
DECL|typedef|WId
typedef|typedef
name|QT_PREPEND_NAMESPACE
argument_list|(
argument|quintptr
argument_list|)
name|WId
expr_stmt|;
end_typedef
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|K
DECL|variable|QHash
name|template
operator|<
name|class
name|K
operator|,
name|class
name|V
operator|>
name|class
name|QHash
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|WId
DECL|typedef|QWidgetMapper
typedef|typedef
name|QHash
operator|<
name|WId
operator|,
name|QWidget
operator|*
operator|>
name|QWidgetMapper
expr_stmt|;
end_typedef
begin_expr_stmt
DECL|variable|QSet
name|template
operator|<
name|class
name|V
operator|>
name|class
name|QSet
expr_stmt|;
end_expr_stmt
begin_typedef
DECL|typedef|QWidgetSet
typedef|typedef
name|QSet
operator|<
name|QWidget
operator|*
operator|>
name|QWidgetSet
expr_stmt|;
end_typedef
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NEEDS_QMAIN
argument_list|)
end_if
begin_define
DECL|macro|main
define|#
directive|define
name|main
value|qMain
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Global platform-independent types and functions
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWDEFS_H
end_comment
end_unit
