begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"bridge.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QSpiAccessibleBridgePlugin      \brief QSpiAccessibleBridgePlugin      QSpiAccessibleBridgePlugin */
end_comment
begin_class
DECL|class|QSpiAccessibleBridgePlugin
class|class
name|QSpiAccessibleBridgePlugin
super|:
specifier|public
name|QAccessibleBridgePlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QAccessibleBridgeFactoryInterface"
name|FILE
literal|"linuxaccessibility.json"
argument_list|)
decl_stmt|;
public|public:
name|QSpiAccessibleBridgePlugin
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
DECL|function|~QSpiAccessibleBridgePlugin
specifier|virtual
name|~
name|QSpiAccessibleBridgePlugin
parameter_list|()
block|{}
specifier|virtual
name|QAccessibleBridge
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
specifier|virtual
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/*!   The contructor of the plugin.   */
end_comment
begin_constructor
DECL|function|QSpiAccessibleBridgePlugin
name|QSpiAccessibleBridgePlugin
operator|::
name|QSpiAccessibleBridgePlugin
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAccessibleBridgePlugin
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Creates a new instance of the QAccessibleBridge plugin.   */
end_comment
begin_function
DECL|function|create
name|QAccessibleBridge
modifier|*
name|QSpiAccessibleBridgePlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
if|if
condition|(
name|key
operator|==
literal|"QSPIACCESSIBLEBRIDGE"
condition|)
return|return
operator|new
name|QSpiAccessibleBridge
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!    */
end_comment
begin_function
DECL|function|keys
name|QStringList
name|QSpiAccessibleBridgePlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
literal|"QSPIACCESSIBLEBRIDGE"
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
