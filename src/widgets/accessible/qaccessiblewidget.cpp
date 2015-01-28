begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qaccessiblewidget.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"qaction.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qgroupbox.h"
end_include
begin_include
include|#
directive|include
file|"qlabel.h"
end_include
begin_include
include|#
directive|include
file|"qtooltip.h"
end_include
begin_include
include|#
directive|include
file|"qwhatsthis.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<QRubberBand>
end_include
begin_include
include|#
directive|include
file|<QFocusFrame>
end_include
begin_include
include|#
directive|include
file|<QMenu>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/private/qwidget_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|childWidgets
specifier|static
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|childWidgets
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|QList
argument_list|<
name|QObject
modifier|*
argument_list|>
name|list
init|=
name|widget
operator|->
name|children
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|widgets
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWidget
modifier|*
name|w
init|=
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|w
operator|&&
operator|!
name|w
operator|->
name|isWindow
argument_list|()
operator|&&
operator|!
name|qobject_cast
argument_list|<
name|QFocusFrame
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_MENU
argument_list|)
operator|&&
operator|!
name|qobject_cast
argument_list|<
name|QMenu
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
endif|#
directive|endif
operator|&&
name|w
operator|->
name|objectName
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"qt_rubberband"
argument_list|)
operator|&&
name|w
operator|->
name|objectName
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"qt_spinbox_lineedit"
argument_list|)
condition|)
name|widgets
operator|.
name|append
argument_list|(
name|w
argument_list|)
expr_stmt|;
block|}
return|return
name|widgets
return|;
block|}
end_function
begin_function
DECL|function|buddyString
specifier|static
name|QString
name|buddyString
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|if
condition|(
operator|!
name|widget
condition|)
return|return
name|QString
argument_list|()
return|;
name|QWidget
modifier|*
name|parent
init|=
name|widget
operator|->
name|parentWidget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|parent
condition|)
return|return
name|QString
argument_list|()
return|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|QObjectList
name|ol
init|=
name|parent
operator|->
name|children
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ol
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QLabel
modifier|*
name|label
init|=
name|qobject_cast
argument_list|<
name|QLabel
operator|*
argument_list|>
argument_list|(
name|ol
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|label
operator|&&
name|label
operator|->
name|buddy
argument_list|()
operator|==
name|widget
condition|)
return|return
name|label
operator|->
name|text
argument_list|()
return|;
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_GROUPBOX
name|QGroupBox
modifier|*
name|groupbox
init|=
name|qobject_cast
argument_list|<
name|QGroupBox
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
name|groupbox
condition|)
return|return
name|groupbox
operator|->
name|title
argument_list|()
return|;
endif|#
directive|endif
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/* This function will return the offset of the '&' in the text that would be    preceding the accelerator character.    If this text does not have an accelerator, -1 will be returned. */
end_comment
begin_function
DECL|function|qt_accAmpIndex
specifier|static
name|int
name|qt_accAmpIndex
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
if|if
condition|(
name|text
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
name|int
name|fa
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|fa
operator|=
name|text
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'&'
argument_list|)
argument_list|,
name|fa
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
operator|++
name|fa
expr_stmt|;
if|if
condition|(
name|fa
operator|<
name|text
operator|.
name|length
argument_list|()
condition|)
block|{
comment|// ignore "&&"
if|if
condition|(
name|text
operator|.
name|at
argument_list|(
name|fa
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'&'
argument_list|)
condition|)
block|{
operator|++
name|fa
expr_stmt|;
continue|continue;
block|}
else|else
block|{
return|return
name|fa
operator|-
literal|1
return|;
break|break;
block|}
block|}
block|}
return|return
operator|-
literal|1
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|text
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qt_accStripAmp
name|QString
name|qt_accStripAmp
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QString
name|newText
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|int
name|ampIndex
init|=
name|qt_accAmpIndex
argument_list|(
name|newText
argument_list|)
decl_stmt|;
if|if
condition|(
name|ampIndex
operator|!=
operator|-
literal|1
condition|)
name|newText
operator|.
name|remove
argument_list|(
name|ampIndex
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|newText
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"&&"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"&"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_accHotKey
name|QString
name|qt_accHotKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|int
name|ampIndex
init|=
name|qt_accAmpIndex
argument_list|(
name|text
argument_list|)
decl_stmt|;
if|if
condition|(
name|ampIndex
operator|!=
operator|-
literal|1
condition|)
return|return
name|QKeySequence
argument_list|(
name|Qt
operator|::
name|ALT
argument_list|)
operator|.
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
operator|+
name|text
operator|.
name|at
argument_list|(
name|ampIndex
operator|+
literal|1
argument_list|)
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// ### inherit QAccessibleObjectPrivate
end_comment
begin_class
DECL|class|QAccessibleWidgetPrivate
class|class
name|QAccessibleWidgetPrivate
block|{
public|public:
DECL|function|QAccessibleWidgetPrivate
name|QAccessibleWidgetPrivate
parameter_list|()
member_init_list|:
name|role
argument_list|(
name|QAccessible
operator|::
name|Client
argument_list|)
block|{}
DECL|member|role
name|QAccessible
operator|::
name|Role
name|role
decl_stmt|;
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|primarySignals
name|QStringList
name|primarySignals
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QAccessibleWidget     \brief The QAccessibleWidget class implements the QAccessibleInterface for QWidgets.      \ingroup accessibility     \inmodule QtWidgets      This class is part of \l {Accessibility for QWidget Applications}.      This class is convenient to use as a base class for custom     implementations of QAccessibleInterfaces that provide information     about widget objects.      The class provides functions to retrieve the parentObject() (the     widget's parent widget), and the associated widget(). Controlling     signals can be added with addControllingSignal(), and setters are     provided for various aspects of the interface implementation, for     example setValue(), setDescription(), setAccelerator(), and     setHelp().      \sa QAccessible, QAccessibleObject */
end_comment
begin_comment
comment|/*!     Creates a QAccessibleWidget object for widget \a w.     \a role and \a name are optional parameters that set the object's     role and name properties. */
end_comment
begin_constructor
DECL|function|QAccessibleWidget
name|QAccessibleWidget
operator|::
name|QAccessibleWidget
parameter_list|(
name|QWidget
modifier|*
name|w
parameter_list|,
name|QAccessible
operator|::
name|Role
name|role
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
member_init_list|:
name|QAccessibleObject
argument_list|(
name|w
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|widget
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|=
operator|new
name|QAccessibleWidgetPrivate
argument_list|()
expr_stmt|;
name|d
operator|->
name|role
operator|=
name|role
expr_stmt|;
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QAccessibleWidget
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|object
argument_list|()
operator|||
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|data
operator|.
name|in_destructor
condition|)
return|return
literal|false
return|;
return|return
name|QAccessibleObject
operator|::
name|isValid
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QAccessibleWidget
operator|::
name|window
parameter_list|()
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|widget
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|widget
argument_list|()
operator|->
name|windowHandle
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Destroys this object. */
end_comment
begin_destructor
DECL|function|~QAccessibleWidget
name|QAccessibleWidget
operator|::
name|~
name|QAccessibleWidget
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the associated widget. */
end_comment
begin_function
DECL|function|widget
name|QWidget
modifier|*
name|QAccessibleWidget
operator|::
name|widget
parameter_list|()
specifier|const
block|{
return|return
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the associated widget's parent object, which is either the     parent widget, or qApp for top-level widgets. */
end_comment
begin_function
DECL|function|parentObject
name|QObject
modifier|*
name|QAccessibleWidget
operator|::
name|parentObject
parameter_list|()
specifier|const
block|{
name|QWidget
modifier|*
name|w
init|=
name|widget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|w
operator|||
name|w
operator|->
name|isWindow
argument_list|()
operator|||
operator|!
name|w
operator|->
name|parentWidget
argument_list|()
condition|)
return|return
name|qApp
return|;
return|return
name|w
operator|->
name|parent
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|rect
name|QRect
name|QAccessibleWidget
operator|::
name|rect
parameter_list|()
specifier|const
block|{
name|QWidget
modifier|*
name|w
init|=
name|widget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|w
operator|->
name|isVisible
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
name|QPoint
name|wpos
init|=
name|w
operator|->
name|mapToGlobal
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|QRect
argument_list|(
name|wpos
operator|.
name|x
argument_list|()
argument_list|,
name|wpos
operator|.
name|y
argument_list|()
argument_list|,
name|w
operator|->
name|width
argument_list|()
argument_list|,
name|w
operator|->
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<private/qobject_p.h>
name|QT_END_INCLUDE_NAMESPACE
DECL|class|QACConnectionObject
name|class
name|QACConnectionObject
operator|:
specifier|public
name|QObject
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QObject
argument_list|)
specifier|public
operator|:
DECL|function|isSender
specifier|inline
name|bool
name|isSender
argument_list|(
argument|const QObject *receiver
argument_list|,
argument|const char *signal
argument_list|)
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|isSender
argument_list|(
name|receiver
argument_list|,
name|signal
argument_list|)
return|;
block|}
DECL|function|receiverList
specifier|inline
name|QObjectList
name|receiverList
argument_list|(
argument|const char *signal
argument_list|)
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|receiverList
argument_list|(
name|signal
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|senderList
specifier|inline
name|QObjectList
name|senderList
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|senderList
argument_list|()
return|;
block|}
end_function
begin_comment
unit|};
comment|/*!     Registers \a signal as a controlling signal.      An object is a Controller to any other object connected to a     controlling signal. */
end_comment
begin_function
DECL|function|addControllingSignal
name|void
name|QAccessibleWidget
operator|::
name|addControllingSignal
parameter_list|(
specifier|const
name|QString
modifier|&
name|signal
parameter_list|)
block|{
name|QByteArray
name|s
init|=
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
name|signal
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|object
argument_list|()
operator|->
name|metaObject
argument_list|()
operator|->
name|indexOfSignal
argument_list|(
name|s
argument_list|)
operator|<
literal|0
condition|)
name|qWarning
argument_list|(
literal|"Signal %s unknown in %s"
argument_list|,
name|s
operator|.
name|constData
argument_list|()
argument_list|,
name|object
argument_list|()
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|primarySignals
operator|<<
name|QLatin1String
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isAncestor
specifier|static
specifier|inline
name|bool
name|isAncestor
parameter_list|(
specifier|const
name|QObject
modifier|*
name|obj
parameter_list|,
specifier|const
name|QObject
modifier|*
name|child
parameter_list|)
block|{
while|while
condition|(
name|child
condition|)
block|{
if|if
condition|(
name|child
operator|==
name|obj
condition|)
return|return
literal|true
return|;
name|child
operator|=
name|child
operator|->
name|parent
argument_list|()
expr_stmt|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
name|QVector
argument_list|<
name|QPair
argument_list|<
name|QAccessibleInterface
modifier|*
argument_list|,
name|QAccessible
operator|::
name|Relation
argument_list|>
argument_list|>
DECL|function|relations
name|QAccessibleWidget
operator|::
name|relations
parameter_list|(
name|QAccessible
operator|::
name|Relation
name|match
comment|/*= QAccessible::AllRelations*/
parameter_list|)
specifier|const
block|{
name|QVector
argument_list|<
name|QPair
argument_list|<
name|QAccessibleInterface
modifier|*
argument_list|,
name|QAccessible
operator|::
name|Relation
argument_list|>
argument_list|>
name|rels
decl_stmt|;
if|if
condition|(
name|match
operator|&
name|QAccessible
operator|::
name|Label
condition|)
block|{
specifier|const
name|QAccessible
operator|::
name|Relation
name|rel
init|=
name|QAccessible
operator|::
name|Label
decl_stmt|;
if|if
condition|(
name|QWidget
modifier|*
name|parent
init|=
name|widget
argument_list|()
operator|->
name|parentWidget
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
comment|// first check for all siblings that are labels to us
comment|// ideally we would go through all objects and check, but that
comment|// will be too expensive
specifier|const
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|kids
init|=
name|childWidgets
argument_list|(
name|parent
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|kids
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QLabel
modifier|*
name|labelSibling
init|=
name|qobject_cast
argument_list|<
name|QLabel
operator|*
argument_list|>
argument_list|(
name|kids
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|labelSibling
operator|->
name|buddy
argument_list|()
operator|==
name|widget
argument_list|()
condition|)
block|{
name|QAccessibleInterface
modifier|*
name|iface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|labelSibling
argument_list|)
decl_stmt|;
name|rels
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|iface
argument_list|,
name|rel
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_GROUPBOX
name|QGroupBox
modifier|*
name|groupbox
init|=
name|qobject_cast
argument_list|<
name|QGroupBox
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
name|groupbox
operator|&&
operator|!
name|groupbox
operator|->
name|title
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QAccessibleInterface
modifier|*
name|iface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|groupbox
argument_list|)
decl_stmt|;
name|rels
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|iface
argument_list|,
name|rel
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
block|}
if|if
condition|(
name|match
operator|&
name|QAccessible
operator|::
name|Controlled
condition|)
block|{
name|QObjectList
name|allReceivers
decl_stmt|;
name|QACConnectionObject
modifier|*
name|connectionObject
init|=
operator|(
name|QACConnectionObject
operator|*
operator|)
name|object
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|sig
init|=
literal|0
init|;
name|sig
operator|<
name|d
operator|->
name|primarySignals
operator|.
name|count
argument_list|()
condition|;
operator|++
name|sig
control|)
block|{
specifier|const
name|QObjectList
name|receivers
init|=
name|connectionObject
operator|->
name|receiverList
argument_list|(
name|d
operator|->
name|primarySignals
operator|.
name|at
argument_list|(
name|sig
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
name|allReceivers
operator|+=
name|receivers
expr_stmt|;
block|}
name|allReceivers
operator|.
name|removeAll
argument_list|(
name|object
argument_list|()
argument_list|)
expr_stmt|;
comment|//### The object might connect to itself internally
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|allReceivers
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QAccessible
operator|::
name|Relation
name|rel
init|=
name|QAccessible
operator|::
name|Controlled
decl_stmt|;
name|QAccessibleInterface
modifier|*
name|iface
init|=
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|allReceivers
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|iface
condition|)
name|rels
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|iface
argument_list|,
name|rel
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|rels
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|parent
name|QAccessibleInterface
modifier|*
name|QAccessibleWidget
operator|::
name|parent
parameter_list|()
specifier|const
block|{
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|parentObject
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|child
name|QAccessibleInterface
modifier|*
name|QAccessibleWidget
operator|::
name|child
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|widget
argument_list|()
argument_list|)
expr_stmt|;
name|QWidgetList
name|childList
init|=
name|childWidgets
argument_list|(
name|widget
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|>=
literal|0
operator|&&
name|index
operator|<
name|childList
operator|.
name|size
argument_list|()
condition|)
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|childList
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|focusChild
name|QAccessibleInterface
modifier|*
name|QAccessibleWidget
operator|::
name|focusChild
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|widget
argument_list|()
operator|->
name|hasFocus
argument_list|()
condition|)
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|object
argument_list|()
argument_list|)
return|;
name|QWidget
modifier|*
name|fw
init|=
name|widget
argument_list|()
operator|->
name|focusWidget
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|fw
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|isAncestor
argument_list|(
name|widget
argument_list|()
argument_list|,
name|fw
argument_list|)
operator|||
name|fw
operator|==
name|widget
argument_list|()
condition|)
return|return
name|QAccessible
operator|::
name|queryAccessibleInterface
argument_list|(
name|fw
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|childCount
name|int
name|QAccessibleWidget
operator|::
name|childCount
parameter_list|()
specifier|const
block|{
name|QWidgetList
name|cl
init|=
name|childWidgets
argument_list|(
name|widget
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|cl
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|indexOfChild
name|int
name|QAccessibleWidget
operator|::
name|indexOfChild
parameter_list|(
specifier|const
name|QAccessibleInterface
modifier|*
name|child
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|child
condition|)
return|return
operator|-
literal|1
return|;
name|QWidgetList
name|cl
init|=
name|childWidgets
argument_list|(
name|widget
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|cl
operator|.
name|indexOf
argument_list|(
name|qobject_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|child
operator|->
name|object
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// from qwidget.cpp
end_comment
begin_function_decl
specifier|extern
name|QString
name|qt_setWindowTitle_helperHelper
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|text
name|QString
name|QAccessibleWidget
operator|::
name|text
parameter_list|(
name|QAccessible
operator|::
name|Text
name|t
parameter_list|)
specifier|const
block|{
name|QString
name|str
decl_stmt|;
switch|switch
condition|(
name|t
condition|)
block|{
case|case
name|QAccessible
operator|::
name|Name
case|:
if|if
condition|(
operator|!
name|d
operator|->
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|str
operator|=
name|d
operator|->
name|name
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|widget
argument_list|()
operator|->
name|accessibleName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|str
operator|=
name|widget
argument_list|()
operator|->
name|accessibleName
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|widget
argument_list|()
operator|->
name|isWindow
argument_list|()
condition|)
block|{
if|if
condition|(
name|widget
argument_list|()
operator|->
name|isMinimized
argument_list|()
condition|)
name|str
operator|=
name|qt_setWindowTitle_helperHelper
argument_list|(
name|widget
argument_list|()
operator|->
name|windowIconText
argument_list|()
argument_list|,
name|widget
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|str
operator|=
name|qt_setWindowTitle_helperHelper
argument_list|(
name|widget
argument_list|()
operator|->
name|windowTitle
argument_list|()
argument_list|,
name|widget
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|str
operator|=
name|qt_accStripAmp
argument_list|(
name|buddyString
argument_list|(
name|widget
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|QAccessible
operator|::
name|Description
case|:
name|str
operator|=
name|widget
argument_list|()
operator|->
name|accessibleDescription
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
if|if
condition|(
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|=
name|widget
argument_list|()
operator|->
name|toolTip
argument_list|()
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|QAccessible
operator|::
name|Help
case|:
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
name|str
operator|=
name|widget
argument_list|()
operator|->
name|whatsThis
argument_list|()
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|QAccessible
operator|::
name|Accelerator
case|:
name|str
operator|=
name|qt_accHotKey
argument_list|(
name|buddyString
argument_list|(
name|widget
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QAccessible
operator|::
name|Value
case|:
break|break;
default|default:
break|break;
block|}
return|return
name|str
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|actionNames
name|QStringList
name|QAccessibleWidget
operator|::
name|actionNames
parameter_list|()
specifier|const
block|{
name|QStringList
name|names
decl_stmt|;
if|if
condition|(
name|widget
argument_list|()
operator|->
name|isEnabled
argument_list|()
condition|)
block|{
if|if
condition|(
name|widget
argument_list|()
operator|->
name|focusPolicy
argument_list|()
operator|!=
name|Qt
operator|::
name|NoFocus
condition|)
name|names
operator|<<
name|setFocusAction
argument_list|()
expr_stmt|;
block|}
return|return
name|names
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|doAction
name|void
name|QAccessibleWidget
operator|::
name|doAction
parameter_list|(
specifier|const
name|QString
modifier|&
name|actionName
parameter_list|)
block|{
if|if
condition|(
operator|!
name|widget
argument_list|()
operator|->
name|isEnabled
argument_list|()
condition|)
return|return;
if|if
condition|(
name|actionName
operator|==
name|setFocusAction
argument_list|()
condition|)
block|{
if|if
condition|(
name|widget
argument_list|()
operator|->
name|isWindow
argument_list|()
condition|)
name|widget
argument_list|()
operator|->
name|activateWindow
argument_list|()
expr_stmt|;
name|widget
argument_list|()
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|keyBindingsForAction
name|QStringList
name|QAccessibleWidget
operator|::
name|keyBindingsForAction
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* actionName */
parameter_list|)
specifier|const
block|{
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|role
name|QAccessible
operator|::
name|Role
name|QAccessibleWidget
operator|::
name|role
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|role
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|state
name|QAccessible
operator|::
name|State
name|QAccessibleWidget
operator|::
name|state
parameter_list|()
specifier|const
block|{
name|QAccessible
operator|::
name|State
name|state
decl_stmt|;
name|QWidget
modifier|*
name|w
init|=
name|widget
argument_list|()
decl_stmt|;
if|if
condition|(
name|w
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_Visible
argument_list|)
operator|==
literal|false
condition|)
name|state
operator|.
name|invisible
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|focusPolicy
argument_list|()
operator|!=
name|Qt
operator|::
name|NoFocus
condition|)
name|state
operator|.
name|focusable
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|hasFocus
argument_list|()
condition|)
name|state
operator|.
name|focused
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|w
operator|->
name|isEnabled
argument_list|()
condition|)
name|state
operator|.
name|disabled
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|isWindow
argument_list|()
condition|)
block|{
if|if
condition|(
name|w
operator|->
name|windowFlags
argument_list|()
operator|&
name|Qt
operator|::
name|WindowSystemMenuHint
condition|)
name|state
operator|.
name|movable
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|minimumSize
argument_list|()
operator|!=
name|w
operator|->
name|maximumSize
argument_list|()
condition|)
name|state
operator|.
name|sizeable
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|isActiveWindow
argument_list|()
condition|)
name|state
operator|.
name|active
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|state
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|foregroundColor
name|QColor
name|QAccessibleWidget
operator|::
name|foregroundColor
parameter_list|()
specifier|const
block|{
return|return
name|widget
argument_list|()
operator|->
name|palette
argument_list|()
operator|.
name|color
argument_list|(
name|widget
argument_list|()
operator|->
name|foregroundRole
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|backgroundColor
name|QColor
name|QAccessibleWidget
operator|::
name|backgroundColor
parameter_list|()
specifier|const
block|{
return|return
name|widget
argument_list|()
operator|->
name|palette
argument_list|()
operator|.
name|color
argument_list|(
name|widget
argument_list|()
operator|->
name|backgroundRole
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|interface_cast
name|void
modifier|*
name|QAccessibleWidget
operator|::
name|interface_cast
parameter_list|(
name|QAccessible
operator|::
name|InterfaceType
name|t
parameter_list|)
block|{
if|if
condition|(
name|t
operator|==
name|QAccessible
operator|::
name|ActionInterface
condition|)
return|return
cast|static_cast
argument_list|<
name|QAccessibleActionInterface
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
return|;
return|return
literal|0
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
comment|//QT_NO_ACCESSIBILITY
end_comment
end_unit
