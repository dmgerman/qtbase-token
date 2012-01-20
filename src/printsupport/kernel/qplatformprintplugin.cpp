begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformprintplugin_qpa.h"
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SETTINGS
argument_list|)
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QPlatformPrinterSupportFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/printsupport"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
DECL|function|QPlatformPrinterSupportPlugin
name|QPlatformPrinterSupportPlugin
operator|::
name|QPlatformPrinterSupportPlugin
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
range|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{ }
DECL|function|~QPlatformPrinterSupportPlugin
name|QPlatformPrinterSupportPlugin
operator|::
name|~
name|QPlatformPrinterSupportPlugin
operator|(
operator|)
block|{ }
DECL|function|get
name|QPlatformPrinterSupport
operator|*
name|QPlatformPrinterSupportPlugin
operator|::
name|get
operator|(
operator|)
block|{
name|QStringList
name|k
operator|=
name|loader
argument_list|()
operator|->
name|keys
argument_list|()
block|;
if|if
condition|(
name|k
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
name|QPlatformPrinterSupportPlugin
operator|*
name|plugin
operator|=
name|qobject_cast
argument_list|<
name|QPlatformPrinterSupportPlugin
operator|*
argument_list|>
argument_list|(
name|loader
argument_list|()
operator|->
name|instance
argument_list|(
name|k
operator|.
name|first
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
operator|!
name|plugin
condition|)
return|return
literal|0
return|;
end_if
begin_return
return|return
name|plugin
operator|->
name|create
argument_list|(
name|k
operator|.
name|first
argument_list|()
argument_list|)
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
