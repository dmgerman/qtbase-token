begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qabstractitemdelegate.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
end_ifndef
begin_include
include|#
directive|include
file|<qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<qabstractitemview.h>
end_include
begin_include
include|#
directive|include
file|<qfontmetrics.h>
end_include
begin_include
include|#
directive|include
file|<qwhatsthis.h>
end_include
begin_include
include|#
directive|include
file|<qtooltip.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qtextedit.h>
end_include
begin_include
include|#
directive|include
file|<qplaintextedit.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qtextengine_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstractitemdelegate_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdrag.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdnd_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QAbstractItemDelegate      \brief The QAbstractItemDelegate class is used to display and edit     data items from a model.      \ingroup model-view     \inmodule QtWidgets      A QAbstractItemDelegate provides the interface and common functionality     for delegates in the model/view architecture. Delegates display     individual items in views, and handle the editing of model data.      The QAbstractItemDelegate class is one of the \l{Model/View Classes}     and is part of Qt's \l{Model/View Programming}{model/view framework}.      To render an item in a custom way, you must implement paint() and     sizeHint(). The QItemDelegate class provides default implementations for     these functions; if you do not need custom rendering, subclass that     class instead.      We give an example of drawing a progress bar in items; in our case     for a package management program.      \image widgetdelegate.png      We create the \c WidgetDelegate class, which inherits from     QStyledItemDelegate. We do the drawing in the paint() function:      \snippet widgetdelegate.cpp 0      Notice that we use a QStyleOptionProgressBar and initialize its     members. We can then use the current QStyle to draw it.      To provide custom editing, there are two approaches that can be     used. The first approach is to create an editor widget and display     it directly on top of the item. To do this you must reimplement     createEditor() to provide an editor widget, setEditorData() to populate     the editor with the data from the model, and setModelData() so that the     delegate can update the model with data from the editor.      The second approach is to handle user events directly by reimplementing     editorEvent().      \sa {model-view-programming}{Model/View Programming}, QItemDelegate,         {Pixelator Example}, QStyledItemDelegate, QStyle */
end_comment
begin_comment
comment|/*!     \enum QAbstractItemDelegate::EndEditHint      This enum describes the different hints that the delegate can give to the     model and view components to make editing data in a model a comfortable     experience for the user.      \value NoHint           There is no recommended action to be performed.      These hints let the delegate influence the behavior of the view:      \value EditNextItem     The view should use the delegate to open an                             editor on the next item in the view.     \value EditPreviousItem The view should use the delegate to open an                             editor on the previous item in the view.      Note that custom views may interpret the concepts of next and previous     differently.      The following hints are most useful when models are used that cache     data, such as those that manipulate data locally in order to increase     performance or conserve network bandwidth.      \value SubmitModelCache If the model caches data, it should write out                             cached data to the underlying data store.     \value RevertModelCache If the model caches data, it should discard                             cached data and replace it with data from the                             underlying data store.      Although models and views should respond to these hints in appropriate     ways, custom components may ignore any or all of them if they are not     relevant. */
end_comment
begin_comment
comment|/*!   \fn void QAbstractItemDelegate::commitData(QWidget *editor)    This signal must be emitted when the \a editor widget has completed   editing the data, and wants to write it back into the model. */
end_comment
begin_comment
comment|/*!     \fn void QAbstractItemDelegate::closeEditor(QWidget *editor, QAbstractItemDelegate::EndEditHint hint)      This signal is emitted when the user has finished editing an item using     the specified \a editor.      The \a hint provides a way for the delegate to influence how the model and     view behave after editing is completed. It indicates to these components     what action should be performed next to provide a comfortable editing     experience for the user. For example, if \c EditNextItem is specified,     the view should use a delegate to open an editor on the next item in the     model.      \sa EndEditHint */
end_comment
begin_comment
comment|/*!     \fn void QAbstractItemDelegate::sizeHintChanged(const QModelIndex&index)     \since 4.4      This signal must be emitted when the sizeHint() of \a index changed.      Views automatically connect to this signal and relayout items as necessary. */
end_comment
begin_comment
comment|/*!     Creates a new abstract item delegate with the given \a parent. */
end_comment
begin_constructor
DECL|function|QAbstractItemDelegate
name|QAbstractItemDelegate
operator|::
name|QAbstractItemDelegate
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QAbstractItemDelegatePrivate
argument_list|,
name|parent
argument_list|)
block|{  }
end_constructor
begin_comment
comment|/*!     \internal      Creates a new abstract item delegate with the given \a parent. */
end_comment
begin_constructor
DECL|function|QAbstractItemDelegate
name|QAbstractItemDelegate
operator|::
name|QAbstractItemDelegate
parameter_list|(
name|QObjectPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{  }
end_constructor
begin_comment
comment|/*!     Destroys the abstract item delegate. */
end_comment
begin_destructor
DECL|function|~QAbstractItemDelegate
name|QAbstractItemDelegate
operator|::
name|~
name|QAbstractItemDelegate
parameter_list|()
block|{  }
end_destructor
begin_comment
comment|/*!     \fn void QAbstractItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem&option, const QModelIndex&index) const = 0;      This pure abstract function must be reimplemented if you want to     provide custom rendering. Use the \a painter and style \a option to     render the item specified by the item \a index.      If you reimplement this you must also reimplement sizeHint(). */
end_comment
begin_comment
comment|/*!     \fn QSize QAbstractItemDelegate::sizeHint(const QStyleOptionViewItem&option, const QModelIndex&index) const = 0      This pure abstract function must be reimplemented if you want to     provide custom rendering. The options are specified by \a option     and the model item by \a index.      If you reimplement this you must also reimplement paint(). */
end_comment
begin_comment
comment|/*!     Returns the editor to be used for editing the data item with the     given \a index. Note that the index contains information about the     model being used. The editor's parent widget is specified by \a parent,     and the item options by \a option.      The base implementation returns 0. If you want custom editing you     will need to reimplement this function.      The returned editor widget should have Qt::StrongFocus;     otherwise, \l{QMouseEvent}s received by the widget will propagate     to the view. The view's background will shine through unless the     editor paints its own background (e.g., with     \l{QWidget::}{setAutoFillBackground()}).      \sa destroyEditor(), setModelData(), setEditorData() */
end_comment
begin_function
DECL|function|createEditor
name|QWidget
modifier|*
name|QAbstractItemDelegate
operator|::
name|createEditor
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Called when the \a editor is no longer needed for editing the data item     with the given \a index and should be destroyed. The default behavior is a     call to deleteLater on the editor. It is possible e.g. to avoid this delete by     reimplementing this function.      \since 5.0     \sa createEditor() */
end_comment
begin_function
DECL|function|destroyEditor
name|void
name|QAbstractItemDelegate
operator|::
name|destroyEditor
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|editor
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the contents of the given \a editor to the data for the item     at the given \a index. Note that the index contains information     about the model being used.      The base implementation does nothing. If you want custom editing     you will need to reimplement this function.      \sa setModelData() */
end_comment
begin_function
DECL|function|setEditorData
name|void
name|QAbstractItemDelegate
operator|::
name|setEditorData
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
comment|// do nothing
block|}
end_function
begin_comment
comment|/*!     Sets the data for the item at the given \a index in the \a model     to the contents of the given \a editor.      The base implementation does nothing. If you want custom editing     you will need to reimplement this function.      \sa setEditorData() */
end_comment
begin_function
DECL|function|setModelData
name|void
name|QAbstractItemDelegate
operator|::
name|setModelData
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
name|QAbstractItemModel
modifier|*
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
comment|// do nothing
block|}
end_function
begin_comment
comment|/*!     Updates the geometry of the \a editor for the item with the given     \a index, according to the rectangle specified in the \a option.     If the item has an internal layout, the editor will be laid out     accordingly. Note that the index contains information about the     model being used.      The base implementation does nothing. If you want custom editing     you must reimplement this function. */
end_comment
begin_function
DECL|function|updateEditorGeometry
name|void
name|QAbstractItemDelegate
operator|::
name|updateEditorGeometry
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
comment|// do nothing
block|}
end_function
begin_comment
comment|/*!     When editing of an item starts, this function is called with the     \a event that triggered the editing, the \a model, the \a index of     the item, and the \a option used for rendering the item.      Mouse events are sent to editorEvent() even if they don't start     editing of the item. This can, for instance, be useful if you wish     to open a context menu when the right mouse button is pressed on     an item.      The base implementation returns \c false (indicating that it has not     handled the event). */
end_comment
begin_function
DECL|function|editorEvent
name|bool
name|QAbstractItemDelegate
operator|::
name|editorEvent
parameter_list|(
name|QEvent
modifier|*
parameter_list|,
name|QAbstractItemModel
modifier|*
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
block|{
comment|// do nothing
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \obsolete      Use QFontMetrics::elidedText() instead.      \oldcode         QFontMetrics fm = ...         QString str = QAbstractItemDelegate::elidedText(fm, width, mode, text);     \newcode         QFontMetrics fm = ...         QString str = fm.elidedText(text, mode, width);     \endcode */
end_comment
begin_function
DECL|function|elidedText
name|QString
name|QAbstractItemDelegate
operator|::
name|elidedText
parameter_list|(
specifier|const
name|QFontMetrics
modifier|&
name|fontMetrics
parameter_list|,
name|int
name|width
parameter_list|,
name|Qt
operator|::
name|TextElideMode
name|mode
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
return|return
name|fontMetrics
operator|.
name|elidedText
argument_list|(
name|text
argument_list|,
name|mode
argument_list|,
name|width
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.3     Whenever a help event occurs, this function is called with the \a event     \a view \a option and the \a index that corresponds to the item where the     event occurs.      Returns \c true if the delegate can handle the event; otherwise returns \c false.     A return value of true indicates that the data obtained using the index had     the required role.      For QEvent::ToolTip and QEvent::WhatsThis events that were handled successfully,     the relevant popup may be shown depending on the user's system configuration.      \sa QHelpEvent */
end_comment
begin_function
DECL|function|helpEvent
name|bool
name|QAbstractItemDelegate
operator|::
name|helpEvent
parameter_list|(
name|QHelpEvent
modifier|*
name|event
parameter_list|,
name|QAbstractItemView
modifier|*
name|view
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|option
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|event
operator|||
operator|!
name|view
condition|)
return|return
literal|false
return|;
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
case|case
name|QEvent
operator|::
name|ToolTip
case|:
block|{
name|QHelpEvent
modifier|*
name|he
init|=
cast|static_cast
argument_list|<
name|QHelpEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QVariant
name|tooltip
init|=
name|index
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|ToolTipRole
argument_list|)
decl_stmt|;
if|if
condition|(
name|tooltip
operator|.
name|canConvert
argument_list|<
name|QString
argument_list|>
argument_list|()
condition|)
block|{
name|QToolTip
operator|::
name|showText
argument_list|(
name|he
operator|->
name|globalPos
argument_list|()
argument_list|,
name|tooltip
operator|.
name|toString
argument_list|()
argument_list|,
name|view
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
case|case
name|QEvent
operator|::
name|QueryWhatsThis
case|:
block|{
if|if
condition|(
name|index
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|WhatsThisRole
argument_list|)
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|true
return|;
break|break;
block|}
case|case
name|QEvent
operator|::
name|WhatsThis
case|:
block|{
name|QHelpEvent
modifier|*
name|he
init|=
cast|static_cast
argument_list|<
name|QHelpEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QVariant
name|whatsthis
init|=
name|index
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|WhatsThisRole
argument_list|)
decl_stmt|;
if|if
condition|(
name|whatsthis
operator|.
name|canConvert
argument_list|<
name|QString
argument_list|>
argument_list|()
condition|)
block|{
name|QWhatsThis
operator|::
name|showText
argument_list|(
name|he
operator|->
name|globalPos
argument_list|()
argument_list|,
name|whatsthis
operator|.
name|toString
argument_list|()
argument_list|,
name|view
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
break|break ;
block|}
endif|#
directive|endif
default|default:
break|break;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \internal      This virtual method is reserved and will be used in Qt 5.1. */
end_comment
begin_function
DECL|function|paintingRoles
name|QVector
argument_list|<
name|int
argument_list|>
name|QAbstractItemDelegate
operator|::
name|paintingRoles
parameter_list|()
specifier|const
block|{
return|return
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QAbstractItemDelegatePrivate
name|QAbstractItemDelegatePrivate
operator|::
name|QAbstractItemDelegatePrivate
parameter_list|()
member_init_list|:
name|QObjectPrivate
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|editorHandlesKeyEvent
specifier|static
name|bool
name|editorHandlesKeyEvent
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
specifier|const
name|QKeyEvent
modifier|*
name|event
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
comment|// do not filter enter / return / tab / backtab for QTextEdit or QPlainTextEdit
if|if
condition|(
name|qobject_cast
argument_list|<
name|QTextEdit
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
operator|||
name|qobject_cast
argument_list|<
name|QPlainTextEdit
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|event
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Tab
case|:
case|case
name|Qt
operator|::
name|Key_Backtab
case|:
case|case
name|Qt
operator|::
name|Key_Enter
case|:
case|case
name|Qt
operator|::
name|Key_Return
case|:
return|return
literal|true
return|;
default|default:
break|break;
block|}
block|}
endif|#
directive|endif
comment|// QT_NO_TEXTEDIT
name|Q_UNUSED
argument_list|(
name|editor
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|editorEventFilter
name|bool
name|QAbstractItemDelegatePrivate
operator|::
name|editorEventFilter
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QAbstractItemDelegate
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|editor
init|=
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|object
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|editor
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|KeyPress
condition|)
block|{
name|QKeyEvent
modifier|*
name|keyEvent
init|=
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|editorHandlesKeyEvent
argument_list|(
name|editor
argument_list|,
name|keyEvent
argument_list|)
condition|)
return|return
literal|false
return|;
switch|switch
condition|(
name|keyEvent
operator|->
name|key
argument_list|()
condition|)
block|{
case|case
name|Qt
operator|::
name|Key_Tab
case|:
if|if
condition|(
name|tryFixup
argument_list|(
name|editor
argument_list|)
condition|)
block|{
emit|emit
name|q
operator|->
name|commitData
argument_list|(
name|editor
argument_list|)
emit|;
emit|emit
name|q
operator|->
name|closeEditor
argument_list|(
name|editor
argument_list|,
name|QAbstractItemDelegate
operator|::
name|EditNextItem
argument_list|)
emit|;
block|}
return|return
literal|true
return|;
case|case
name|Qt
operator|::
name|Key_Backtab
case|:
if|if
condition|(
name|tryFixup
argument_list|(
name|editor
argument_list|)
condition|)
block|{
emit|emit
name|q
operator|->
name|commitData
argument_list|(
name|editor
argument_list|)
emit|;
emit|emit
name|q
operator|->
name|closeEditor
argument_list|(
name|editor
argument_list|,
name|QAbstractItemDelegate
operator|::
name|EditPreviousItem
argument_list|)
emit|;
block|}
return|return
literal|true
return|;
case|case
name|Qt
operator|::
name|Key_Enter
case|:
case|case
name|Qt
operator|::
name|Key_Return
case|:
comment|// We want the editor to be able to process the key press
comment|// before committing the data (e.g. so it can do
comment|// validation/fixup of the input).
if|if
condition|(
operator|!
name|tryFixup
argument_list|(
name|editor
argument_list|)
condition|)
return|return
literal|true
return|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|q
argument_list|,
literal|"_q_commitDataAndCloseEditor"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|QWidget
operator|*
argument_list|,
name|editor
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
case|case
name|Qt
operator|::
name|Key_Escape
case|:
comment|// don't commit data
emit|emit
name|q
operator|->
name|closeEditor
argument_list|(
name|editor
argument_list|,
name|QAbstractItemDelegate
operator|::
name|RevertModelCache
argument_list|)
emit|;
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|FocusOut
operator|||
operator|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Hide
operator|&&
name|editor
operator|->
name|isWindow
argument_list|()
operator|)
condition|)
block|{
comment|//the Hide event will take care of he editors that are in fact complete dialogs
if|if
condition|(
operator|!
name|editor
operator|->
name|isActiveWindow
argument_list|()
operator|||
operator|(
name|QApplication
operator|::
name|focusWidget
argument_list|()
operator|!=
name|editor
operator|)
condition|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|QApplication
operator|::
name|focusWidget
argument_list|()
decl_stmt|;
while|while
condition|(
name|w
condition|)
block|{
comment|// don't worry about focus changes internally in the editor
if|if
condition|(
name|w
operator|==
name|editor
condition|)
return|return
literal|false
return|;
name|w
operator|=
name|w
operator|->
name|parentWidget
argument_list|()
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
comment|// The window may lose focus during an drag operation.
comment|// i.e when dragging involves the taskbar on Windows.
name|QPlatformDrag
modifier|*
name|platformDrag
init|=
name|QGuiApplicationPrivate
operator|::
name|instance
argument_list|()
operator|->
name|platformIntegration
argument_list|()
operator|->
name|drag
argument_list|()
decl_stmt|;
if|if
condition|(
name|platformDrag
operator|&&
name|platformDrag
operator|->
name|currentDrag
argument_list|()
condition|)
block|{
return|return
literal|false
return|;
block|}
endif|#
directive|endif
if|if
condition|(
name|tryFixup
argument_list|(
name|editor
argument_list|)
condition|)
emit|emit
name|q
operator|->
name|commitData
argument_list|(
name|editor
argument_list|)
emit|;
emit|emit
name|q
operator|->
name|closeEditor
argument_list|(
name|editor
argument_list|,
name|QAbstractItemDelegate
operator|::
name|NoHint
argument_list|)
emit|;
block|}
block|}
elseif|else
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|ShortcutOverride
condition|)
block|{
if|if
condition|(
cast|static_cast
argument_list|<
name|QKeyEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
operator|->
name|key
argument_list|()
operator|==
name|Qt
operator|::
name|Key_Escape
condition|)
block|{
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|tryFixup
name|bool
name|QAbstractItemDelegatePrivate
operator|::
name|tryFixup
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
if|if
condition|(
name|QLineEdit
modifier|*
name|e
init|=
name|qobject_cast
argument_list|<
name|QLineEdit
operator|*
argument_list|>
argument_list|(
name|editor
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|e
operator|->
name|hasAcceptableInput
argument_list|()
condition|)
block|{
if|if
condition|(
specifier|const
name|QValidator
modifier|*
name|validator
init|=
name|e
operator|->
name|validator
argument_list|()
condition|)
block|{
name|QString
name|text
init|=
name|e
operator|->
name|text
argument_list|()
decl_stmt|;
name|validator
operator|->
name|fixup
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|e
operator|->
name|setText
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
return|return
name|e
operator|->
name|hasAcceptableInput
argument_list|()
return|;
block|}
block|}
endif|#
directive|endif
comment|// QT_NO_LINEEDIT
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|_q_commitDataAndCloseEditor
name|void
name|QAbstractItemDelegatePrivate
operator|::
name|_q_commitDataAndCloseEditor
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QAbstractItemDelegate
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|commitData
argument_list|(
name|editor
argument_list|)
emit|;
emit|emit
name|q
operator|->
name|closeEditor
argument_list|(
name|editor
argument_list|,
name|QAbstractItemDelegate
operator|::
name|SubmitModelCache
argument_list|)
emit|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qabstractitemdelegate.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ITEMVIEWS
end_comment
end_unit
