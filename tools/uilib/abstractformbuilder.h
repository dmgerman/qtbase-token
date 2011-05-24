begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the Qt Designer of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ABSTRACTFORMBUILDER_H
end_ifndef
begin_define
DECL|macro|ABSTRACTFORMBUILDER_H
define|#
directive|define
name|ABSTRACTFORMBUILDER_H
end_define
begin_include
include|#
directive|include
file|"uilib_global.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSizePolicy>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPalette>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
literal|0
comment|// pragma for syncqt, don't remove.
pragma|#
directive|pragma
name|qt_class
name|(
name|QAbstractFormBuilder
name|)
endif|#
directive|endif
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QButtonGroup
name|class
name|QButtonGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QActionGroup
name|class
name|QActionGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLayout
name|class
name|QLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLayoutItem
name|class
name|QLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QListWidget
name|class
name|QListWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpacerItem
name|class
name|QSpacerItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidget
name|class
name|QTreeWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTableWidget
name|class
name|QTableWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractButton
name|class
name|QAbstractButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractItemView
name|class
name|QAbstractItemView
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QFORMINTERNAL_NAMESPACE
end_ifdef
begin_decl_stmt
name|namespace
name|QFormInternal
block|{
endif|#
directive|endif
name|class
name|DomAction
decl_stmt|;
name|class
name|DomActionGroup
decl_stmt|;
name|class
name|DomButtonGroup
decl_stmt|;
name|class
name|DomButtonGroups
decl_stmt|;
name|class
name|DomActionRef
decl_stmt|;
name|class
name|DomBrush
decl_stmt|;
name|class
name|DomColorGroup
decl_stmt|;
name|class
name|DomConnections
decl_stmt|;
name|class
name|DomCustomWidgets
decl_stmt|;
name|class
name|DomLayout
decl_stmt|;
name|class
name|DomLayoutItem
decl_stmt|;
name|class
name|DomProperty
decl_stmt|;
name|class
name|DomResources
decl_stmt|;
name|class
name|DomSpacer
decl_stmt|;
name|class
name|DomString
decl_stmt|;
name|class
name|DomTabStops
decl_stmt|;
name|class
name|DomUI
decl_stmt|;
name|class
name|DomWidget
decl_stmt|;
name|class
name|DomResourcePixmap
decl_stmt|;
name|class
name|QResourceBuilder
decl_stmt|;
name|class
name|QTextBuilder
decl_stmt|;
name|class
name|QFormBuilderExtra
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_FORMBUILDER_NO_SCRIPT
name|class
name|QFormScriptRunner
decl_stmt|;
endif|#
directive|endif
name|class
name|QDESIGNER_UILIB_EXPORT
name|QAbstractFormBuilder
block|{
name|public
label|:
name|QAbstractFormBuilder
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QAbstractFormBuilder
argument_list|()
expr_stmt|;
name|QDir
name|workingDirectory
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWorkingDirectory
parameter_list|(
specifier|const
name|QDir
modifier|&
name|directory
parameter_list|)
function_decl|;
name|virtual
name|QWidget
modifier|*
name|load
parameter_list|(
name|QIODevice
modifier|*
name|dev
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
init|=
literal|0
parameter_list|)
function_decl|;
name|virtual
name|void
name|save
parameter_list|(
name|QIODevice
modifier|*
name|dev
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
name|void
name|setScriptingEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isScriptingEnabled
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
comment|//
comment|// load
comment|//
name|virtual
name|void
name|loadExtraInfo
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|virtual
name|QWidget
modifier|*
name|create
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|virtual
name|QWidget
modifier|*
name|create
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|virtual
name|QLayout
modifier|*
name|create
parameter_list|(
name|DomLayout
modifier|*
name|ui_layout
parameter_list|,
name|QLayout
modifier|*
name|layout
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|virtual
name|QLayoutItem
modifier|*
name|create
parameter_list|(
name|DomLayoutItem
modifier|*
name|ui_layoutItem
parameter_list|,
name|QLayout
modifier|*
name|layout
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|virtual
name|QAction
modifier|*
name|create
parameter_list|(
name|DomAction
modifier|*
name|ui_action
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
function_decl|;
name|virtual
name|QActionGroup
modifier|*
name|create
parameter_list|(
name|DomActionGroup
modifier|*
name|ui_action_group
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
function_decl|;
name|virtual
name|void
name|addMenuAction
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
function_decl|;
name|virtual
name|void
name|applyProperties
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
specifier|const
name|QList
operator|<
name|DomProperty
operator|*
operator|>
operator|&
name|properties
argument_list|)
decl_stmt|;
name|bool
name|applyPropertyInternally
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
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
name|virtual
name|void
name|applyTabStops
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|DomTabStops
modifier|*
name|tabStops
parameter_list|)
function_decl|;
name|virtual
name|QWidget
modifier|*
name|createWidget
parameter_list|(
specifier|const
name|QString
modifier|&
name|widgetName
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|virtual
name|QLayout
modifier|*
name|createLayout
parameter_list|(
specifier|const
name|QString
modifier|&
name|layoutName
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|virtual
name|QAction
modifier|*
name|createAction
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|virtual
name|QActionGroup
modifier|*
name|createActionGroup
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|virtual
name|void
name|createCustomWidgets
parameter_list|(
name|DomCustomWidgets
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|createConnections
parameter_list|(
name|DomConnections
modifier|*
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|createResources
parameter_list|(
name|DomResources
modifier|*
parameter_list|)
block|{}
name|virtual
name|bool
name|addItem
parameter_list|(
name|DomLayoutItem
modifier|*
name|ui_item
parameter_list|,
name|QLayoutItem
modifier|*
name|item
parameter_list|,
name|QLayout
modifier|*
name|layout
parameter_list|)
function_decl|;
name|virtual
name|bool
name|addItem
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
comment|//
comment|// save
comment|//
name|virtual
name|void
name|saveExtraInfo
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|virtual
name|void
name|saveDom
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
name|virtual
name|DomActionRef
modifier|*
name|createActionRefDom
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
function_decl|;
name|virtual
name|DomWidget
modifier|*
name|createDom
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|,
name|bool
name|recursive
init|=
name|true
parameter_list|)
function_decl|;
name|virtual
name|DomLayout
modifier|*
name|createDom
parameter_list|(
name|QLayout
modifier|*
name|layout
parameter_list|,
name|DomLayout
modifier|*
name|ui_layout
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|virtual
name|DomLayoutItem
modifier|*
name|createDom
parameter_list|(
name|QLayoutItem
modifier|*
name|item
parameter_list|,
name|DomLayout
modifier|*
name|ui_parentLayout
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|virtual
name|DomSpacer
modifier|*
name|createDom
parameter_list|(
name|QSpacerItem
modifier|*
name|spacer
parameter_list|,
name|DomLayout
modifier|*
name|ui_parentLayout
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|virtual
name|DomAction
modifier|*
name|createDom
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
function_decl|;
name|virtual
name|DomActionGroup
modifier|*
name|createDom
parameter_list|(
name|QActionGroup
modifier|*
name|actionGroup
parameter_list|)
function_decl|;
name|DomButtonGroup
modifier|*
name|createDom
parameter_list|(
name|QButtonGroup
modifier|*
name|buttonGroup
parameter_list|)
function_decl|;
name|virtual
name|DomConnections
modifier|*
name|saveConnections
parameter_list|()
function_decl|;
name|virtual
name|DomCustomWidgets
modifier|*
name|saveCustomWidgets
parameter_list|()
function_decl|;
name|virtual
name|DomTabStops
modifier|*
name|saveTabStops
parameter_list|()
function_decl|;
name|virtual
name|DomResources
modifier|*
name|saveResources
parameter_list|()
function_decl|;
name|DomButtonGroups
modifier|*
name|saveButtonGroups
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|mainContainer
parameter_list|)
function_decl|;
name|virtual
name|QList
operator|<
name|DomProperty
operator|*
operator|>
name|computeProperties
argument_list|(
name|QObject
operator|*
name|obj
argument_list|)
expr_stmt|;
name|virtual
name|bool
name|checkProperty
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
specifier|const
name|QString
operator|&
name|prop
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|DomProperty
modifier|*
name|createProperty
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|,
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
name|virtual
name|void
name|layoutInfo
parameter_list|(
name|DomLayout
modifier|*
name|layout
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|,
name|int
modifier|*
name|margin
parameter_list|,
name|int
modifier|*
name|spacing
parameter_list|)
function_decl|;
name|void
name|loadListWidgetExtraInfo
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QListWidget
modifier|*
name|listWidget
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|void
name|loadTreeWidgetExtraInfo
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QTreeWidget
modifier|*
name|treeWidget
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|void
name|loadTableWidgetExtraInfo
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QTableWidget
modifier|*
name|tableWidget
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|void
name|loadComboBoxExtraInfo
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QComboBox
modifier|*
name|comboBox
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|void
name|loadButtonExtraInfo
parameter_list|(
specifier|const
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QAbstractButton
modifier|*
name|button
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|void
name|loadItemViewExtraInfo
parameter_list|(
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|QAbstractItemView
modifier|*
name|itemView
parameter_list|,
name|QWidget
modifier|*
name|parentWidget
parameter_list|)
function_decl|;
name|void
name|saveListWidgetExtraInfo
parameter_list|(
name|QListWidget
modifier|*
name|widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|void
name|saveTreeWidgetExtraInfo
parameter_list|(
name|QTreeWidget
modifier|*
name|treeWidget
parameter_list|,
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|void
name|saveTableWidgetExtraInfo
parameter_list|(
name|QTableWidget
modifier|*
name|tablWidget
parameter_list|,
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|void
name|saveComboBoxExtraInfo
parameter_list|(
name|QComboBox
modifier|*
name|widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|void
name|saveButtonExtraInfo
parameter_list|(
specifier|const
name|QAbstractButton
modifier|*
name|widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|void
name|saveItemViewExtraInfo
parameter_list|(
specifier|const
name|QAbstractItemView
modifier|*
name|itemView
parameter_list|,
name|DomWidget
modifier|*
name|ui_widget
parameter_list|,
name|DomWidget
modifier|*
name|ui_parentWidget
parameter_list|)
function_decl|;
name|void
name|setResourceBuilder
parameter_list|(
name|QResourceBuilder
modifier|*
name|builder
parameter_list|)
function_decl|;
name|QResourceBuilder
operator|*
name|resourceBuilder
argument_list|()
specifier|const
expr_stmt|;
name|DomProperty
modifier|*
name|saveResource
argument_list|(
specifier|const
name|QVariant
operator|&
name|v
argument_list|)
decl|const
decl_stmt|;
name|void
name|setTextBuilder
parameter_list|(
name|QTextBuilder
modifier|*
name|builder
parameter_list|)
function_decl|;
name|QTextBuilder
operator|*
name|textBuilder
argument_list|()
specifier|const
expr_stmt|;
name|DomProperty
modifier|*
name|saveText
argument_list|(
specifier|const
name|QString
operator|&
name|attributeName
argument_list|,
specifier|const
name|QVariant
operator|&
name|v
argument_list|)
decl|const
decl_stmt|;
comment|//
comment|// utils
comment|//
name|QVariant
name|toVariant
parameter_list|(
specifier|const
name|QMetaObject
modifier|*
name|meta
parameter_list|,
name|DomProperty
modifier|*
name|property
parameter_list|)
function_decl|;
specifier|static
name|QString
name|toString
parameter_list|(
specifier|const
name|DomString
modifier|*
name|str
parameter_list|)
function_decl|;
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|DomProperty
operator|*
operator|>
name|DomPropertyHash
expr_stmt|;
specifier|static
name|DomPropertyHash
name|propertyMap
argument_list|(
specifier|const
name|QList
operator|<
name|DomProperty
operator|*
operator|>
operator|&
name|properties
argument_list|)
decl_stmt|;
name|void
name|setupColorGroup
argument_list|(
name|QPalette
operator|&
name|palette
argument_list|,
name|QPalette
operator|::
name|ColorGroup
name|colorGroup
argument_list|,
name|DomColorGroup
operator|*
name|group
argument_list|)
decl_stmt|;
name|DomColorGroup
modifier|*
name|saveColorGroup
parameter_list|(
specifier|const
name|QPalette
modifier|&
name|palette
parameter_list|)
function_decl|;
name|QBrush
name|setupBrush
parameter_list|(
name|DomBrush
modifier|*
name|brush
parameter_list|)
function_decl|;
name|DomBrush
modifier|*
name|saveBrush
parameter_list|(
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
name|void
name|reset
parameter_list|()
function_decl|;
name|void
name|initialize
parameter_list|(
specifier|const
name|DomUI
modifier|*
name|ui
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_FORMBUILDER_NO_SCRIPT
name|QFormScriptRunner
operator|*
name|formScriptRunner
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|//
comment|//  utils
comment|//
specifier|static
name|QMetaEnum
name|toolBarAreaMetaEnum
parameter_list|()
function_decl|;
comment|//
comment|//  Icon/pixmap stuff
comment|//
comment|// A Pair of icon path/qrc path.
typedef|typedef
name|QPair
operator|<
name|QString
operator|,
name|QString
operator|>
name|IconPaths
expr_stmt|;
name|IconPaths
name|iconPaths
argument_list|(
specifier|const
name|QIcon
operator|&
argument_list|)
decl|const
decl_stmt|;
name|IconPaths
name|pixmapPaths
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
decl|const
decl_stmt|;
name|void
name|setIconProperty
argument_list|(
name|DomProperty
operator|&
argument_list|,
specifier|const
name|IconPaths
operator|&
argument_list|)
decl|const
decl_stmt|;
name|void
name|setPixmapProperty
argument_list|(
name|DomProperty
operator|&
argument_list|,
specifier|const
name|IconPaths
operator|&
argument_list|)
decl|const
decl_stmt|;
name|DomProperty
modifier|*
name|iconToDomProperty
argument_list|(
specifier|const
name|QIcon
operator|&
argument_list|)
decl|const
decl_stmt|;
specifier|static
specifier|const
name|DomResourcePixmap
modifier|*
name|domPixmap
parameter_list|(
specifier|const
name|DomProperty
modifier|*
name|p
parameter_list|)
function_decl|;
name|QIcon
name|domPropertyToIcon
parameter_list|(
specifier|const
name|DomResourcePixmap
modifier|*
parameter_list|)
function_decl|;
name|QIcon
name|domPropertyToIcon
parameter_list|(
specifier|const
name|DomProperty
modifier|*
name|p
parameter_list|)
function_decl|;
name|QPixmap
name|domPropertyToPixmap
parameter_list|(
specifier|const
name|DomResourcePixmap
modifier|*
name|p
parameter_list|)
function_decl|;
name|QPixmap
name|domPropertyToPixmap
parameter_list|(
specifier|const
name|DomProperty
modifier|*
name|p
parameter_list|)
function_decl|;
name|private
label|:
comment|//
comment|//  utils
comment|//
specifier|static
name|Qt
operator|::
name|ToolBarArea
name|toolbarAreaFromDOMAttributes
argument_list|(
specifier|const
name|DomPropertyHash
operator|&
name|attributeMap
argument_list|)
expr_stmt|;
name|QAbstractFormBuilder
argument_list|(
specifier|const
name|QAbstractFormBuilder
operator|&
name|other
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|QAbstractFormBuilder
operator|&
name|other
operator|)
decl_stmt|;
name|friend
name|QDESIGNER_UILIB_EXPORT
name|DomProperty
modifier|*
name|variantToDomProperty
parameter_list|(
name|QAbstractFormBuilder
modifier|*
name|abstractFormBuilder
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|meta
parameter_list|,
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
name|friend
name|QDESIGNER_UILIB_EXPORT
name|QVariant
name|domPropertyToVariant
parameter_list|(
name|QAbstractFormBuilder
modifier|*
name|abstractFormBuilder
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|meta
parameter_list|,
specifier|const
name|DomProperty
modifier|*
name|property
parameter_list|)
function_decl|;
name|protected
label|:
name|QScopedPointer
operator|<
name|QFormBuilderExtra
operator|>
name|d
expr_stmt|;
block|}
empty_stmt|;
ifdef|#
directive|ifdef
name|QFORMINTERNAL_NAMESPACE
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ABSTRACTFORMBUILDER_H
end_comment
end_unit
