begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCREEN_H
end_ifndef
begin_define
DECL|macro|QSCREEN_H
define|#
directive|define
name|QSCREEN_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSize>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSizeF>
end_include
begin_include
include|#
directive|include
file|<QtGui/QTransform>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformScreen
name|class
name|QPlatformScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScreenPrivate
name|class
name|QScreenPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QScreen
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QScreen
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString name READ name CONSTANT
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int depth READ depth CONSTANT
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSize size READ size NOTIFY sizeChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRect geometry READ geometry NOTIFY geometryChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSizeF physicalSize READ physicalSize CONSTANT
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal physicalDotsPerInchX READ physicalDotsPerInchX NOTIFY physicalDotsPerInchXChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal physicalDotsPerInchY READ physicalDotsPerInchY NOTIFY physicalDotsPerInchYChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal physicalDotsPerInch READ physicalDotsPerInch NOTIFY physicalDotsPerInchChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal logicalDotsPerInchX READ logicalDotsPerInchX NOTIFY logicalDotsPerInchXChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal logicalDotsPerInchY READ logicalDotsPerInchY NOTIFY logicalDotsPerInchYChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal logicalDotsPerInch READ logicalDotsPerInch NOTIFY logicalDotsPerInchChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QSize availableSize READ availableSize NOTIFY availableSizeChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QRect availableGeometry READ availableGeometry NOTIFY availableGeometryChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::ScreenOrientation primaryOrientation READ orientation NOTIFY primaryOrientationChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::ScreenOrientation orientation READ orientation NOTIFY orientationChanged
argument_list|)
name|public
operator|:
name|QPlatformScreen
operator|*
name|handle
argument_list|()
specifier|const
block|;
name|QString
name|name
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|;
name|qreal
name|physicalDotsPerInchX
argument_list|()
specifier|const
block|;
name|qreal
name|physicalDotsPerInchY
argument_list|()
specifier|const
block|;
name|qreal
name|physicalDotsPerInch
argument_list|()
specifier|const
block|;
name|qreal
name|logicalDotsPerInchX
argument_list|()
specifier|const
block|;
name|qreal
name|logicalDotsPerInchY
argument_list|()
specifier|const
block|;
name|qreal
name|logicalDotsPerInch
argument_list|()
specifier|const
block|;
name|QSize
name|availableSize
argument_list|()
specifier|const
block|;
name|QRect
name|availableGeometry
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QScreen
operator|*
operator|>
name|virtualSiblings
argument_list|()
specifier|const
block|;
name|QSize
name|virtualSize
argument_list|()
specifier|const
block|;
name|QRect
name|virtualGeometry
argument_list|()
specifier|const
block|;
name|QSize
name|availableVirtualSize
argument_list|()
specifier|const
block|;
name|QRect
name|availableVirtualGeometry
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ScreenOrientation
name|primaryOrientation
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
block|;
name|int
name|angleBetween
argument_list|(
argument|Qt::ScreenOrientation a
argument_list|,
argument|Qt::ScreenOrientation b
argument_list|)
block|;
name|QTransform
name|transformBetween
argument_list|(
argument|Qt::ScreenOrientation a
argument_list|,
argument|Qt::ScreenOrientation b
argument_list|,
argument|const QRect&target
argument_list|)
block|;
name|QRect
name|mapBetween
argument_list|(
argument|Qt::ScreenOrientation a
argument_list|,
argument|Qt::ScreenOrientation b
argument_list|,
argument|const QRect&rect
argument_list|)
block|;
name|bool
name|isPortrait
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|bool
name|isLandscape
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|sizeChanged
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|void
name|geometryChanged
argument_list|(
specifier|const
name|QRect
operator|&
name|geometry
argument_list|)
block|;
name|void
name|physicalDotsPerInchXChanged
argument_list|(
argument|qreal dpi
argument_list|)
block|;
name|void
name|physicalDotsPerInchYChanged
argument_list|(
argument|qreal dpi
argument_list|)
block|;
name|void
name|physicalDotsPerInchChanged
argument_list|(
argument|qreal dpi
argument_list|)
block|;
name|void
name|logicalDotsPerInchXChanged
argument_list|(
argument|qreal dpi
argument_list|)
block|;
name|void
name|logicalDotsPerInchYChanged
argument_list|(
argument|qreal dpi
argument_list|)
block|;
name|void
name|logicalDotsPerInchChanged
argument_list|(
argument|qreal dpi
argument_list|)
block|;
name|void
name|availableSizeChanged
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|void
name|availableGeometryChanged
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|primaryOrientationChanged
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|void
name|orientationChanged
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|private
operator|:
name|QScreen
argument_list|(
name|QPlatformScreen
operator|*
name|screen
argument_list|)
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QScreen
argument_list|)
name|friend
name|class
name|QGuiApplicationPrivate
block|;
name|friend
name|class
name|QPlatformIntegration
block|;
name|friend
name|class
name|QPlatformScreen
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCREEN_H
end_comment
end_unit
