begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSWIDGET_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSWIDGET_H
define|#
directive|define
name|QGRAPHICSWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qgraphicslayoutitem.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qgraphicsitem.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpalette.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
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
DECL|variable|QGraphicsLayout
name|class
name|QGraphicsLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneMoveEvent
name|class
name|QGraphicsSceneMoveEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsWidgetPrivate
name|class
name|QGraphicsWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsSceneResizeEvent
name|class
name|QGraphicsSceneResizeEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyle
name|class
name|QStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOption
name|class
name|QStyleOption
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
operator|||
operator|(
name|QT_EDITION
operator|&
name|QT_MODULE_GRAPHICSVIEW
operator|)
operator|!=
name|QT_MODULE_GRAPHICSVIEW
end_if
begin_decl_stmt
DECL|variable|QGraphicsWidgetPrivate
name|class
name|QGraphicsWidgetPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsObject
name|class
name|Q_GUI_EXPORT
name|QGraphicsWidget
range|:
name|public
name|QGraphicsObject
decl_stmt|,
name|public
name|QGraphicsLayoutItem
block|{
name|Q_OBJECT
name|Q_INTERFACES
argument_list|(
name|QGraphicsItem
name|QGraphicsLayoutItem
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QPalette
name|palette
name|READ
name|palette
name|WRITE
name|setPalette
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QFont
name|font
name|READ
name|font
name|WRITE
name|setFont
argument_list|)
name|Q_PROPERTY
argument_list|(
name|Qt
operator|::
name|LayoutDirection
name|layoutDirection
name|READ
name|layoutDirection
name|WRITE
name|setLayoutDirection
name|RESET
name|unsetLayoutDirection
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QSizeF
name|size
name|READ
name|size
name|WRITE
name|resize
name|NOTIFY
name|geometryChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QSizeF
name|minimumSize
name|READ
name|minimumSize
name|WRITE
name|setMinimumSize
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QSizeF
name|preferredSize
name|READ
name|preferredSize
name|WRITE
name|setPreferredSize
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QSizeF
name|maximumSize
name|READ
name|maximumSize
name|WRITE
name|setMaximumSize
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QSizePolicy
name|sizePolicy
name|READ
name|sizePolicy
name|WRITE
name|setSizePolicy
argument_list|)
name|Q_PROPERTY
argument_list|(
name|Qt
operator|::
name|FocusPolicy
name|focusPolicy
name|READ
name|focusPolicy
name|WRITE
name|setFocusPolicy
argument_list|)
name|Q_PROPERTY
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|windowFlags
name|READ
name|windowFlags
name|WRITE
name|setWindowFlags
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QString
name|windowTitle
name|READ
name|windowTitle
name|WRITE
name|setWindowTitle
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QRectF
name|geometry
name|READ
name|geometry
name|WRITE
name|setGeometry
name|NOTIFY
name|geometryChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
name|bool
name|autoFillBackground
name|READ
name|autoFillBackground
name|WRITE
name|setAutoFillBackground
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QGraphicsLayout
operator|*
name|layout
name|READ
name|layout
name|WRITE
name|setLayout
name|NOTIFY
name|layoutChanged
argument_list|)
name|public
range|:
name|QGraphicsWidget
argument_list|(
argument|QGraphicsItem *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags wFlags =
literal|0
argument_list|)
decl_stmt|;
operator|~
name|QGraphicsWidget
argument_list|()
expr_stmt|;
name|QGraphicsLayout
operator|*
name|layout
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLayout
parameter_list|(
name|QGraphicsLayout
modifier|*
name|layout
parameter_list|)
function_decl|;
name|void
name|adjustSize
parameter_list|()
function_decl|;
name|Qt
operator|::
name|LayoutDirection
name|layoutDirection
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLayoutDirection
argument_list|(
name|Qt
operator|::
name|LayoutDirection
name|direction
argument_list|)
decl_stmt|;
name|void
name|unsetLayoutDirection
parameter_list|()
function_decl|;
name|QStyle
operator|*
name|style
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStyle
parameter_list|(
name|QStyle
modifier|*
name|style
parameter_list|)
function_decl|;
name|QFont
name|font
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
function_decl|;
name|QPalette
name|palette
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPalette
parameter_list|(
specifier|const
name|QPalette
modifier|&
name|palette
parameter_list|)
function_decl|;
name|bool
name|autoFillBackground
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAutoFillBackground
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|void
name|resize
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
function_decl|;
specifier|inline
name|void
name|resize
parameter_list|(
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|)
block|{
name|resize
argument_list|(
name|QSizeF
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QSizeF
name|size
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setGeometry
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|,
name|qreal
name|w
parameter_list|,
name|qreal
name|h
parameter_list|)
function_decl|;
specifier|inline
name|QRectF
name|rect
argument_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
name|QPointF
argument_list|()
argument_list|,
name|size
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setContentsMargins
parameter_list|(
name|qreal
name|left
parameter_list|,
name|qreal
name|top
parameter_list|,
name|qreal
name|right
parameter_list|,
name|qreal
name|bottom
parameter_list|)
function_decl|;
name|void
name|getContentsMargins
argument_list|(
name|qreal
operator|*
name|left
argument_list|,
name|qreal
operator|*
name|top
argument_list|,
name|qreal
operator|*
name|right
argument_list|,
name|qreal
operator|*
name|bottom
argument_list|)
decl|const
decl_stmt|;
name|void
name|setWindowFrameMargins
parameter_list|(
name|qreal
name|left
parameter_list|,
name|qreal
name|top
parameter_list|,
name|qreal
name|right
parameter_list|,
name|qreal
name|bottom
parameter_list|)
function_decl|;
name|void
name|getWindowFrameMargins
argument_list|(
name|qreal
operator|*
name|left
argument_list|,
name|qreal
operator|*
name|top
argument_list|,
name|qreal
operator|*
name|right
argument_list|,
name|qreal
operator|*
name|bottom
argument_list|)
decl|const
decl_stmt|;
name|void
name|unsetWindowFrameMargins
parameter_list|()
function_decl|;
name|QRectF
name|windowFrameGeometry
argument_list|()
specifier|const
expr_stmt|;
name|QRectF
name|windowFrameRect
argument_list|()
specifier|const
expr_stmt|;
comment|// Window handling
name|Qt
operator|::
name|WindowFlags
name|windowFlags
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|WindowType
name|windowType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|wFlags
argument_list|)
decl_stmt|;
name|bool
name|isActiveWindow
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
function_decl|;
name|QString
name|windowTitle
argument_list|()
specifier|const
expr_stmt|;
comment|// Focus handling
name|Qt
operator|::
name|FocusPolicy
name|focusPolicy
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|FocusPolicy
name|policy
argument_list|)
decl_stmt|;
specifier|static
name|void
name|setTabOrder
parameter_list|(
name|QGraphicsWidget
modifier|*
name|first
parameter_list|,
name|QGraphicsWidget
modifier|*
name|second
parameter_list|)
function_decl|;
name|QGraphicsWidget
operator|*
name|focusWidget
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|int
name|grabShortcut
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|sequence
argument_list|,
name|Qt
operator|::
name|ShortcutContext
name|context
operator|=
name|Qt
operator|::
name|WindowShortcut
argument_list|)
decl_stmt|;
name|void
name|releaseShortcut
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
name|void
name|setShortcutEnabled
parameter_list|(
name|int
name|id
parameter_list|,
name|bool
name|enabled
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|setShortcutAutoRepeat
parameter_list|(
name|int
name|id
parameter_list|,
name|bool
name|enabled
init|=
name|true
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_ACTION
comment|//actions
name|void
name|addAction
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
function_decl|;
name|void
name|addActions
argument_list|(
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|)
decl_stmt|;
name|void
name|insertAction
parameter_list|(
name|QAction
modifier|*
name|before
parameter_list|,
name|QAction
modifier|*
name|action
parameter_list|)
function_decl|;
name|void
name|insertActions
argument_list|(
name|QAction
operator|*
name|before
argument_list|,
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|)
decl_stmt|;
name|void
name|removeAction
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
function_decl|;
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|void
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WidgetAttribute
name|attribute
argument_list|,
name|bool
name|on
operator|=
name|true
argument_list|)
decl_stmt|;
name|bool
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WidgetAttribute
name|attribute
argument_list|)
decl|const
decl_stmt|;
enum|enum
block|{
name|Type
init|=
literal|11
block|}
enum|;
name|int
name|type
argument_list|()
specifier|const
expr_stmt|;
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
function_decl|;
name|virtual
name|void
name|paintWindowFrame
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
function_decl|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
expr_stmt|;
name|QPainterPath
name|shape
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
literal|0
block|void dumpFocusChain();
endif|#
directive|endif
comment|// ### Qt 5: Disambiguate
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
specifier|const
name|QObjectList
operator|&
name|children
argument_list|()
specifier|const
block|{
return|return
name|QObject
operator|::
name|children
argument_list|()
return|;
block|}
else|#
directive|else
name|using
name|QObject
operator|::
name|children
expr_stmt|;
endif|#
directive|endif
name|Q_SIGNALS
label|:
name|void
name|geometryChanged
parameter_list|()
function_decl|;
name|void
name|layoutChanged
parameter_list|()
function_decl|;
name|public
name|Q_SLOTS
range|:
name|bool
name|close
argument_list|()
decl_stmt|;
name|protected
label|:
name|virtual
name|void
name|initStyleOption
argument_list|(
name|QStyleOption
operator|*
name|option
argument_list|)
decl|const
decl_stmt|;
name|QSizeF
name|sizeHint
argument_list|(
name|Qt
operator|::
name|SizeHint
name|which
argument_list|,
specifier|const
name|QSizeF
operator|&
name|constraint
operator|=
name|QSizeF
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|updateGeometry
parameter_list|()
function_decl|;
comment|// Notification
name|QVariant
name|itemChange
parameter_list|(
name|GraphicsItemChange
name|change
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|virtual
name|QVariant
name|propertyChange
parameter_list|(
specifier|const
name|QString
modifier|&
name|propertyName
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
comment|// Scene events
name|bool
name|sceneEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|bool
name|windowFrameEvent
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
function_decl|;
name|virtual
name|Qt
operator|::
name|WindowFrameSection
name|windowFrameSectionAt
argument_list|(
argument|const QPointF& pos
argument_list|)
specifier|const
expr_stmt|;
comment|// Base event handlers
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
comment|//virtual void actionEvent(QActionEvent *event);
name|virtual
name|void
name|changeEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|event
parameter_list|)
function_decl|;
comment|//void create(WId window = 0, bool initializeWindow = true, bool destroyOldWindow = true);
comment|//void destroy(bool destroyWindow = true, bool destroySubWindows = true);
name|void
name|focusInEvent
parameter_list|(
name|QFocusEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|bool
name|focusNextPrevChild
parameter_list|(
name|bool
name|next
parameter_list|)
function_decl|;
name|void
name|focusOutEvent
parameter_list|(
name|QFocusEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|hideEvent
parameter_list|(
name|QHideEvent
modifier|*
name|event
parameter_list|)
function_decl|;
comment|//virtual bool macEvent(EventHandlerCallRef caller, EventRef event);
comment|//virtual int metric(PaintDeviceMetric m ) const;
name|virtual
name|void
name|moveEvent
parameter_list|(
name|QGraphicsSceneMoveEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|polishEvent
parameter_list|()
function_decl|;
comment|//virtual bool qwsEvent(QWSEvent *event);
comment|//void resetInputContext ();
name|virtual
name|void
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
name|event
parameter_list|)
function_decl|;
comment|//virtual void tabletEvent(QTabletEvent *event);
comment|//virtual bool winEvent(MSG *message, long *result);
comment|//virtual bool x11Event(XEvent *event);
name|virtual
name|void
name|hoverMoveEvent
parameter_list|(
name|QGraphicsSceneHoverEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|hoverLeaveEvent
parameter_list|(
name|QGraphicsSceneHoverEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|grabMouseEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|ungrabMouseEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|grabKeyboardEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|virtual
name|void
name|ungrabKeyboardEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
function_decl|;
name|QGraphicsWidget
argument_list|(
argument|QGraphicsWidgetPrivate&
argument_list|,
argument|QGraphicsItem *parent
argument_list|,
argument|QGraphicsScene *
argument_list|,
argument|Qt::WindowFlags wFlags =
literal|0
argument_list|)
empty_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsWidget
argument_list|)
name|Q_DECLARE_PRIVATE_D
argument_list|(
argument|QGraphicsItem::d_ptr.data()
argument_list|,
argument|QGraphicsWidget
argument_list|)
name|friend
name|class
name|QGraphicsScene
decl_stmt|;
name|friend
name|class
name|QGraphicsScenePrivate
decl_stmt|;
name|friend
name|class
name|QGraphicsView
decl_stmt|;
name|friend
name|class
name|QGraphicsItem
decl_stmt|;
name|friend
name|class
name|QGraphicsItemPrivate
decl_stmt|;
name|friend
name|class
name|QGraphicsLayout
decl_stmt|;
name|friend
name|class
name|QWidget
decl_stmt|;
name|friend
name|class
name|QApplication
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|setGeometry
specifier|inline
name|void
name|QGraphicsWidget
operator|::
name|setGeometry
argument_list|(
argument|qreal ax
argument_list|,
argument|qreal ay
argument_list|,
argument|qreal aw
argument_list|,
argument|qreal ah
argument_list|)
block|{
name|setGeometry
argument_list|(
name|QRectF
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|aw
argument_list|,
name|ah
argument_list|)
argument_list|)
block|; }
endif|#
directive|endif
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
