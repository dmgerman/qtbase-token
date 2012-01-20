begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qstylepainter.h"
end_include
begin_include
include|#
directive|include
file|"qrubberband.h"
end_include
begin_include
include|#
directive|include
file|"qtimer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
end_ifndef
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<private/qt_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qt_cocoa_helpers_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qwidget_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|//### a rubberband window type would be a more elegant solution
end_comment
begin_define
DECL|macro|RUBBERBAND_WINDOW_TYPE
define|#
directive|define
name|RUBBERBAND_WINDOW_TYPE
value|Qt::ToolTip
end_define
begin_class
DECL|class|QRubberBandPrivate
class|class
name|QRubberBandPrivate
super|:
specifier|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QRubberBand
parameter_list|)
specifier|public
private|:
DECL|member|rect
name|QRect
name|rect
decl_stmt|;
DECL|member|shape
name|QRubberBand
operator|::
name|Shape
name|shape
decl_stmt|;
DECL|member|clipping
name|QRegion
name|clipping
decl_stmt|;
name|void
name|updateMask
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/*!     Initialize \a option with the values from this QRubberBand. This method     is useful for subclasses when they need a QStyleOptionRubberBand, but don't want     to fill in all the information themselves.      \sa QStyleOption::initFrom() */
end_comment
begin_function
DECL|function|initStyleOption
name|void
name|QRubberBand
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOptionRubberBand
modifier|*
name|option
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|option
condition|)
return|return;
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|option
operator|->
name|shape
operator|=
name|d_func
argument_list|()
operator|->
name|shape
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_WS_MAC
name|option
operator|->
name|opaque
operator|=
literal|true
expr_stmt|;
else|#
directive|else
name|option
operator|->
name|opaque
operator|=
name|windowFlags
argument_list|()
operator|&
name|RUBBERBAND_WINDOW_TYPE
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     \class QRubberBand     \brief The QRubberBand class provides a rectangle or line that can     indicate a selection or a boundary.      \inmodule QtWidgets      A rubber band is often used to show a new bounding area (as in a     QSplitter or a QDockWidget that is undocking). Historically this has     been implemented using a QPainter and XOR, but this approach     doesn't always work properly since rendering can happen in the     window below the rubber band, but before the rubber band has been     "erased".      You can create a QRubberBand whenever you need to render a rubber band     around a given area (or to represent a single line), then call     setGeometry(), move() or resize() to position and size it. A common     pattern is to do this in conjunction with mouse events. For example:      \snippet doc/src/snippets/code/src_gui_widgets_qrubberband.cpp 0      If you pass a parent to QRubberBand's constructor, the rubber band will     display only inside its parent, but stays on top of other child widgets.     If no parent is passed, QRubberBand will act as a top-level widget.      Call show() to make the rubber band visible; also when the     rubber band is not a top-level. Hiding or destroying     the widget will make the rubber band disappear. The rubber band     can be a \l Rectangle or a \l Line (vertical or horizontal),     depending on the shape() it was given when constructed. */
end_comment
begin_comment
comment|// ### DOC: How about some nice convenience constructors?
end_comment
begin_comment
comment|//QRubberBand::QRubberBand(QRubberBand::Type t, const QRect&rect, QWidget *p)
end_comment
begin_comment
comment|//QRubberBand::QRubberBand(QRubberBand::Type t, int x, int y, int w, int h, QWidget *p)
end_comment
begin_comment
comment|/*!     Constructs a rubber band of shape \a s, with parent \a p.      By default a rectangular rubber band (\a s is \c Rectangle) will     use a mask, so that a small border of the rectangle is all     that is visible. Some styles (e.g., native Mac OS X) will     change this and call QWidget::setWindowOpacity() to make a     semi-transparent filled selection rectangle. */
end_comment
begin_constructor
DECL|function|QRubberBand
name|QRubberBand
operator|::
name|QRubberBand
parameter_list|(
name|Shape
name|s
parameter_list|,
name|QWidget
modifier|*
name|p
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QRubberBandPrivate
argument_list|,
name|p
argument_list|,
operator|(
name|p
operator|&&
name|p
operator|->
name|windowType
argument_list|()
operator|!=
name|Qt
operator|::
name|Desktop
operator|)
condition|?
name|Qt
operator|::
name|Widget
else|:
name|RUBBERBAND_WINDOW_TYPE
argument_list|)
block|{
name|Q_D
argument_list|(
name|QRubberBand
argument_list|)
expr_stmt|;
name|d
operator|->
name|shape
operator|=
name|s
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_TransparentForMouseEvents
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_WS_WIN
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_NoSystemBackground
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|//Q_WS_WIN
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ExplicitShowHide
argument_list|)
expr_stmt|;
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
if|if
condition|(
name|isWindow
argument_list|()
condition|)
block|{
name|createWinId
argument_list|()
expr_stmt|;
specifier|extern
name|OSWindowRef
name|qt_mac_window_for
argument_list|(
specifier|const
name|QWidget
operator|*
argument_list|)
decl_stmt|;
comment|//qwidget_mac.cpp
name|macWindowSetHasShadow
argument_list|(
name|qt_mac_window_for
argument_list|(
name|this
argument_list|)
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_constructor
begin_comment
comment|/*!     Destructor. */
end_comment
begin_destructor
DECL|function|~QRubberBand
name|QRubberBand
operator|::
name|~
name|QRubberBand
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \enum QRubberBand::Shape      This enum specifies what shape a QRubberBand should have. This is     a drawing hint that is passed down to the style system, and can be     interpreted by each QStyle.      \value Line A QRubberBand can represent a vertical or horizontal                 line. Geometry is still given in rect() and the line                 will fill the given geometry on most styles.      \value Rectangle A QRubberBand can represent a rectangle. Some                      styles will interpret this as a filled (often                      semi-transparent) rectangle, or a rectangular                      outline. */
end_comment
begin_comment
comment|/*!   Returns the shape of this rubber band. The shape can only be set   upon construction. */
end_comment
begin_function
DECL|function|shape
name|QRubberBand
operator|::
name|Shape
name|QRubberBand
operator|::
name|shape
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QRubberBand
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|shape
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|updateMask
name|void
name|QRubberBandPrivate
operator|::
name|updateMask
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QRubberBand
argument_list|)
expr_stmt|;
name|QStyleHintReturnMask
name|mask
decl_stmt|;
name|QStyleOptionRubberBand
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_RubberBand_Mask
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|,
operator|&
name|mask
argument_list|)
condition|)
block|{
name|q
operator|->
name|setMask
argument_list|(
name|mask
operator|.
name|region
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|q
operator|->
name|clearMask
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QRubberBand
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QStylePainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOptionRubberBand
name|option
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|option
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_RubberBand
argument_list|,
name|option
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|changeEvent
name|void
name|QRubberBand
operator|::
name|changeEvent
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|QWidget
operator|::
name|changeEvent
argument_list|(
name|e
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|ParentChange
case|:
if|if
condition|(
name|parent
argument_list|()
condition|)
block|{
name|setWindowFlags
argument_list|(
name|windowFlags
argument_list|()
operator|&
operator|~
name|RUBBERBAND_WINDOW_TYPE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setWindowFlags
argument_list|(
name|windowFlags
argument_list|()
operator||
name|RUBBERBAND_WINDOW_TYPE
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|ZOrderChange
condition|)
name|raise
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|showEvent
name|void
name|QRubberBand
operator|::
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
name|e
parameter_list|)
block|{
name|raise
argument_list|()
expr_stmt|;
name|e
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|QRubberBand
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QRubberBand
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateMask
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|moveEvent
name|void
name|QRubberBand
operator|::
name|moveEvent
parameter_list|(
name|QMoveEvent
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QRubberBand
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateMask
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QRubberBand::move(const QPoint&p);      \overload      Moves the rubberband to point \a p.      \sa resize() */
end_comment
begin_comment
comment|/*!     \fn void QRubberBand::move(int x, int y);      Moves the rubberband to point (\a x, \a y).      \sa resize() */
end_comment
begin_comment
comment|/*!     \fn void QRubberBand::resize(const QSize&size);      \overload      Resizes the rubberband so that its new size is \a size.      \sa move() */
end_comment
begin_comment
comment|/*!     \fn void QRubberBand::resize(int width, int height);      Resizes the rubberband so that its width is \a width, and its     height is \a height.      \sa move() */
end_comment
begin_comment
comment|/*!     \fn void QRubberBand::setGeometry(const QRect&rect)      Sets the geometry of the rubber band to \a rect, specified in the coordinate system     of its parent widget.      \sa QWidget::geometry */
end_comment
begin_function
DECL|function|setGeometry
name|void
name|QRubberBand
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|geom
parameter_list|)
block|{
name|QWidget
operator|::
name|setGeometry
argument_list|(
name|geom
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QRubberBand::setGeometry(int x, int y, int width, int height)     \overload      Sets the geometry of the rubberband to the rectangle whose top-left corner lies at     the point (\a x, \a y), and with dimensions specified by \a width and \a height.     The geometry is specified in the parent widget's coordinate system. */
end_comment
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QRubberBand
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_RUBBERBAND
end_comment
end_unit
