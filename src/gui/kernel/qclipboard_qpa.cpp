begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qclipboard.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_include
include|#
directive|include
file|"qmimedata.h"
end_include
begin_include
include|#
directive|include
file|"private/qguiapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformclipboard_qpa.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
name|QT_USE_NAMESPACE
DECL|function|clear
name|void
name|QClipboard
operator|::
name|clear
parameter_list|(
name|Mode
name|mode
parameter_list|)
block|{
name|setMimeData
argument_list|(
literal|0
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QClipboard
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QObject
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|mimeData
specifier|const
name|QMimeData
modifier|*
name|QClipboard
operator|::
name|mimeData
parameter_list|(
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
name|QPlatformClipboard
modifier|*
name|clipboard
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|clipboard
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|clipboard
operator|->
name|supportsMode
argument_list|(
name|mode
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
name|clipboard
operator|->
name|mimeData
argument_list|(
name|mode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|QClipboard
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|src
parameter_list|,
name|Mode
name|mode
parameter_list|)
block|{
name|QPlatformClipboard
modifier|*
name|clipboard
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|clipboard
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|clipboard
operator|->
name|supportsMode
argument_list|(
name|mode
argument_list|)
condition|)
return|return;
name|clipboard
operator|->
name|setMimeData
argument_list|(
name|src
argument_list|,
name|mode
argument_list|)
expr_stmt|;
name|emitChanged
argument_list|(
name|mode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsMode
name|bool
name|QClipboard
operator|::
name|supportsMode
parameter_list|(
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
name|QPlatformClipboard
modifier|*
name|clipboard
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|clipboard
argument_list|()
decl_stmt|;
return|return
name|clipboard
operator|->
name|supportsMode
argument_list|(
name|mode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|ownsMode
name|bool
name|QClipboard
operator|::
name|ownsMode
parameter_list|(
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
name|QPlatformClipboard
modifier|*
name|clipboard
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|clipboard
argument_list|()
decl_stmt|;
return|return
name|clipboard
operator|->
name|ownsMode
argument_list|(
name|mode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|connectNotify
name|void
name|QClipboard
operator|::
name|connectNotify
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|ownerDestroyed
name|void
name|QClipboard
operator|::
name|ownerDestroyed
parameter_list|()
block|{ }
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CLIPBOARD
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
