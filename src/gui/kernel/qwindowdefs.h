begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtCore/qobjectdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
comment|// Class forward definitions
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
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_decl_stmt
DECL|variable|QColorGroup
name|class
name|QColorGroup
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
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
DECL|variable|QPrinter
name|class
name|QPrinter
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_comment
comment|// Window system dependent definitions
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtGui/qmacdefines_mac.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC32
end_ifdef
begin_typedef
DECL|typedef|WId
typedef|typedef
name|int
name|WId
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
typedef|typedef
name|long
name|WId
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_MAC
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
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
comment|// Q_WS_WIN
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
end_if
begin_typedef
DECL|typedef|Display
typedef|typedef
name|struct
name|_XDisplay
name|Display
typedef|;
end_typedef
begin_typedef
DECL|typedef|XEvent
typedef|typedef
name|union
name|_XEvent
name|XEvent
typedef|;
end_typedef
begin_typedef
DECL|typedef|GC
typedef|typedef
name|struct
name|_XGC
modifier|*
name|GC
typedef|;
end_typedef
begin_typedef
DECL|typedef|Region
typedef|typedef
name|struct
name|_XRegion
modifier|*
name|Region
typedef|;
end_typedef
begin_typedef
DECL|typedef|WId
typedef|typedef
name|unsigned
name|long
name|WId
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_X11
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
end_if
begin_typedef
DECL|typedef|WId
typedef|typedef
name|unsigned
name|long
name|WId
typedef|;
end_typedef
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
expr|struct
name|QWSEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_QWS
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QPA
argument_list|)
end_if
begin_typedef
DECL|typedef|WId
typedef|typedef
name|unsigned
name|long
name|WId
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_WS_QPA
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_decl_stmt
DECL|variable|CCoeControl
name|class
name|CCoeControl
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|WId
typedef|typedef
name|CCoeControl
modifier|*
name|WId
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_SYMBIAN
end_comment
begin_expr_stmt
name|QT_BEGIN_HEADER
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
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
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
