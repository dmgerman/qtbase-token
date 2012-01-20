begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qimageiohandler.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMATPLUGIN
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_IMAGEFORMAT_TIFF
end_ifdef
begin_undef
DECL|macro|QT_NO_IMAGEFORMAT_TIFF
undef|#
directive|undef
name|QT_NO_IMAGEFORMAT_TIFF
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qtiffhandler_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTiffPlugin
class|class
name|QTiffPlugin
super|:
specifier|public
name|QImageIOPlugin
block|{
public|public:
name|Capabilities
name|capabilities
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
specifier|const
function_decl|;
name|QImageIOHandler
modifier|*
name|create
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|format
init|=
name|QByteArray
argument_list|()
parameter_list|)
specifier|const
function_decl|;
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|capabilities
name|QImageIOPlugin
operator|::
name|Capabilities
name|QTiffPlugin
operator|::
name|capabilities
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|format
operator|==
literal|"tiff"
operator|||
name|format
operator|==
literal|"tif"
condition|)
return|return
name|Capabilities
argument_list|(
name|CanRead
operator||
name|CanWrite
argument_list|)
return|;
if|if
condition|(
operator|!
name|format
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|device
operator|->
name|isOpen
argument_list|()
condition|)
return|return
literal|0
return|;
name|Capabilities
name|cap
decl_stmt|;
if|if
condition|(
name|device
operator|->
name|isReadable
argument_list|()
operator|&&
name|QTiffHandler
operator|::
name|canRead
argument_list|(
name|device
argument_list|)
condition|)
name|cap
operator||=
name|CanRead
expr_stmt|;
if|if
condition|(
name|device
operator|->
name|isWritable
argument_list|()
condition|)
name|cap
operator||=
name|CanWrite
expr_stmt|;
return|return
name|cap
return|;
block|}
end_function
begin_function
DECL|function|create
name|QImageIOHandler
modifier|*
name|QTiffPlugin
operator|::
name|create
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
specifier|const
block|{
name|QImageIOHandler
modifier|*
name|tiffHandler
init|=
operator|new
name|QTiffHandler
argument_list|()
decl_stmt|;
name|tiffHandler
operator|->
name|setDevice
argument_list|(
name|device
argument_list|)
expr_stmt|;
name|tiffHandler
operator|->
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
return|return
name|tiffHandler
return|;
block|}
end_function
begin_function
DECL|function|keys
name|QStringList
name|QTiffPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"tiff"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"tif"
argument_list|)
return|;
block|}
end_function
begin_macro
name|Q_EXPORT_STATIC_PLUGIN
argument_list|(
argument|QTiffPlugin
argument_list|)
end_macro
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|qtiff
argument_list|,
argument|QTiffPlugin
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* QT_NO_IMAGEFORMATPLUGIN */
end_comment
end_unit
