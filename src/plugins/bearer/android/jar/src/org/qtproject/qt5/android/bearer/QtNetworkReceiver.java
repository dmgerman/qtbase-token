begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_package
DECL|package|org.qtproject.qt5.android.bearer
package|package
name|org
operator|.
name|qtproject
operator|.
name|qt5
operator|.
name|android
operator|.
name|bearer
package|;
end_package
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|BroadcastReceiver
import|;
end_import
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|Context
import|;
end_import
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|Intent
import|;
end_import
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|IntentFilter
import|;
end_import
begin_import
import|import
name|android
operator|.
name|util
operator|.
name|Log
import|;
end_import
begin_import
import|import
name|android
operator|.
name|app
operator|.
name|Activity
import|;
end_import
begin_import
import|import
name|android
operator|.
name|net
operator|.
name|ConnectivityManager
import|;
end_import
begin_class
DECL|class|QtNetworkReceiver
specifier|public
class|class
name|QtNetworkReceiver
block|{
DECL|field|LOG_TAG
specifier|private
specifier|static
specifier|final
name|String
name|LOG_TAG
init|=
literal|"QtNetworkReceiver"
decl_stmt|;
DECL|method|activeNetworkInfoChanged
specifier|private
specifier|static
specifier|native
name|void
name|activeNetworkInfoChanged
parameter_list|()
function_decl|;
DECL|field|m_broadcastReceiver
specifier|private
specifier|static
name|BroadcastReceiverPrivate
name|m_broadcastReceiver
init|=
literal|null
decl_stmt|;
DECL|field|m_lock
specifier|private
specifier|static
specifier|final
name|Object
name|m_lock
init|=
operator|new
name|Object
argument_list|()
decl_stmt|;
DECL|class|BroadcastReceiverPrivate
specifier|private
specifier|static
class|class
name|BroadcastReceiverPrivate
extends|extends
name|BroadcastReceiver
block|{
annotation|@
name|Override
DECL|method|onReceive
specifier|public
name|void
name|onReceive
parameter_list|(
name|Context
name|context
parameter_list|,
name|Intent
name|intent
parameter_list|)
block|{
name|activeNetworkInfoChanged
argument_list|()
expr_stmt|;
block|}
block|}
DECL|method|QtNetworkReceiver
specifier|private
name|QtNetworkReceiver
parameter_list|()
block|{}
DECL|method|registerReceiver
specifier|public
specifier|static
name|void
name|registerReceiver
parameter_list|(
specifier|final
name|Activity
name|activity
parameter_list|)
block|{
synchronized|synchronized
init|(
name|m_lock
init|)
block|{
if|if
condition|(
name|m_broadcastReceiver
operator|==
literal|null
condition|)
block|{
name|m_broadcastReceiver
operator|=
operator|new
name|BroadcastReceiverPrivate
argument_list|()
expr_stmt|;
name|IntentFilter
name|intentFilter
init|=
operator|new
name|IntentFilter
argument_list|(
name|ConnectivityManager
operator|.
name|CONNECTIVITY_ACTION
argument_list|)
decl_stmt|;
name|activity
operator|.
name|registerReceiver
argument_list|(
name|m_broadcastReceiver
argument_list|,
name|intentFilter
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|method|unregisterReceiver
specifier|public
specifier|static
name|void
name|unregisterReceiver
parameter_list|(
specifier|final
name|Activity
name|activity
parameter_list|)
block|{
synchronized|synchronized
init|(
name|m_lock
init|)
block|{
if|if
condition|(
name|m_broadcastReceiver
operator|==
literal|null
condition|)
return|return;
name|activity
operator|.
name|unregisterReceiver
argument_list|(
name|m_broadcastReceiver
argument_list|)
expr_stmt|;
block|}
block|}
DECL|method|getConnectivityManager
specifier|public
specifier|static
name|ConnectivityManager
name|getConnectivityManager
parameter_list|(
specifier|final
name|Activity
name|activity
parameter_list|)
block|{
return|return
operator|(
name|ConnectivityManager
operator|)
name|activity
operator|.
name|getApplicationContext
argument_list|()
operator|.
name|getSystemService
argument_list|(
name|Context
operator|.
name|CONNECTIVITY_SERVICE
argument_list|)
return|;
block|}
block|}
end_class
end_unit
