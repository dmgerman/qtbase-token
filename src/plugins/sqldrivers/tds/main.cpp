begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|Q_UUIDIMPL
define|#
directive|define
name|Q_UUIDIMPL
end_define
begin_include
include|#
directive|include
file|<qsqldriverplugin.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN32
end_ifdef
begin_comment
comment|// We assume that MS SQL Server is used. Set Q_USE_SYBASE to force Sybase.
end_comment
begin_comment
comment|// Conflicting declarations of LPCBYTE in sqlfront.h and winscard.h
end_comment
begin_define
DECL|macro|_WINSCARD_H_
define|#
directive|define
name|_WINSCARD_H_
end_define
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"../../../sql/drivers/tds/qsql_tds_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTDSDriverPlugin
class|class
name|QTDSDriverPlugin
super|:
specifier|public
name|QSqlDriverPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QSqlDriverFactoryInterface"
name|FILE
literal|"tds.json"
argument_list|)
decl|public
range|:
name|QTDSDriverPlugin
argument_list|()
decl_stmt|;
name|QSqlDriver
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QTDSDriverPlugin
name|QTDSDriverPlugin
operator|::
name|QTDSDriverPlugin
parameter_list|()
member_init_list|:
name|QSqlDriverPlugin
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|create
name|QSqlDriver
modifier|*
name|QTDSDriverPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QTDS"
argument_list|)
operator|||
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QTDS7"
argument_list|)
condition|)
block|{
name|QTDSDriver
modifier|*
name|driver
init|=
operator|new
name|QTDSDriver
argument_list|()
decl_stmt|;
return|return
name|driver
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
