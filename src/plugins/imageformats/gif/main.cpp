begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qimageiohandler.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMATPLUGIN
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_IMAGEFORMAT_GIF
end_ifdef
begin_undef
DECL|macro|QT_NO_IMAGEFORMAT_GIF
undef|#
directive|undef
name|QT_NO_IMAGEFORMAT_GIF
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qgifhandler_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QGifPlugin
class|class
name|QGifPlugin
super|:
specifier|public
name|QImageIOPlugin
block|{
public|public:
name|QGifPlugin
parameter_list|()
constructor_decl|;
name|~
name|QGifPlugin
parameter_list|()
destructor_decl|;
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
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
block|}
class|;
end_class
begin_constructor
DECL|function|QGifPlugin
name|QGifPlugin
operator|::
name|QGifPlugin
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QGifPlugin
name|QGifPlugin
operator|::
name|~
name|QGifPlugin
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|keys
name|QStringList
name|QGifPlugin
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
literal|"gif"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|capabilities
name|QImageIOPlugin
operator|::
name|Capabilities
name|QGifPlugin
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
literal|"gif"
operator|||
operator|(
name|device
operator|&&
name|device
operator|->
name|isReadable
argument_list|()
operator|&&
name|QGifHandler
operator|::
name|canRead
argument_list|(
name|device
argument_list|)
operator|)
condition|)
return|return
name|Capabilities
argument_list|(
name|CanRead
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|create
name|QImageIOHandler
modifier|*
name|QGifPlugin
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
name|handler
init|=
operator|new
name|QGifHandler
decl_stmt|;
name|handler
operator|->
name|setDevice
argument_list|(
name|device
argument_list|)
expr_stmt|;
name|handler
operator|->
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
return|return
name|handler
return|;
block|}
end_function
begin_macro
name|Q_EXPORT_STATIC_PLUGIN
argument_list|(
argument|QGifPlugin
argument_list|)
end_macro
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|qgif
argument_list|,
argument|QGifPlugin
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_IMAGEFORMATPLUGIN
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
