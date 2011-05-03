begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qsessionmanager.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QSessionManagerPrivate
class|class
name|QSessionManagerPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
name|QSessionManagerPrivate
parameter_list|(
name|QSessionManager
modifier|*
name|m
parameter_list|,
specifier|const
name|QString
modifier|&
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
constructor_decl|;
DECL|member|restartCommand
name|QStringList
name|restartCommand
decl_stmt|;
DECL|member|discardCommand
name|QStringList
name|discardCommand
decl_stmt|;
DECL|member|sessionId
specifier|const
name|QString
name|sessionId
decl_stmt|;
DECL|member|sessionKey
specifier|const
name|QString
name|sessionKey
decl_stmt|;
DECL|member|restartHint
name|QSessionManager
operator|::
name|RestartHint
name|restartHint
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QSessionManagerPrivate
name|QSessionManagerPrivate
operator|::
name|QSessionManagerPrivate
parameter_list|(
name|QSessionManager
modifier|*
parameter_list|,
specifier|const
name|QString
modifier|&
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
member_init_list|:
name|QObjectPrivate
argument_list|()
member_init_list|,
name|sessionId
argument_list|(
name|id
argument_list|)
member_init_list|,
name|sessionKey
argument_list|(
name|key
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QSessionManager
name|QSessionManager
operator|::
name|QSessionManager
parameter_list|(
name|QApplication
modifier|*
name|app
parameter_list|,
name|QString
modifier|&
name|id
parameter_list|,
name|QString
modifier|&
name|key
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|(
operator|new
name|QSessionManagerPrivate
argument_list|(
name|this
argument_list|,
name|id
argument_list|,
name|key
argument_list|)
operator|)
argument_list|,
name|app
argument_list|)
block|{
name|Q_D
argument_list|(
name|QSessionManager
argument_list|)
expr_stmt|;
name|d
operator|->
name|restartHint
operator|=
name|RestartIfRunning
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSessionManager
name|QSessionManager
operator|::
name|~
name|QSessionManager
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|sessionId
name|QString
name|QSessionManager
operator|::
name|sessionId
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSessionManager
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sessionId
return|;
block|}
end_function
begin_function
DECL|function|sessionKey
name|QString
name|QSessionManager
operator|::
name|sessionKey
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSessionManager
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sessionKey
return|;
block|}
end_function
begin_function
DECL|function|allowsInteraction
name|bool
name|QSessionManager
operator|::
name|allowsInteraction
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|allowsErrorInteraction
name|bool
name|QSessionManager
operator|::
name|allowsErrorInteraction
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|QSessionManager
operator|::
name|release
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cancel
name|void
name|QSessionManager
operator|::
name|cancel
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|setRestartHint
name|void
name|QSessionManager
operator|::
name|setRestartHint
parameter_list|(
name|QSessionManager
operator|::
name|RestartHint
name|hint
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSessionManager
argument_list|)
expr_stmt|;
name|d
operator|->
name|restartHint
operator|=
name|hint
expr_stmt|;
block|}
end_function
begin_function
DECL|function|restartHint
name|QSessionManager
operator|::
name|RestartHint
name|QSessionManager
operator|::
name|restartHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSessionManager
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|restartHint
return|;
block|}
end_function
begin_function
DECL|function|setRestartCommand
name|void
name|QSessionManager
operator|::
name|setRestartCommand
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|command
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSessionManager
argument_list|)
expr_stmt|;
name|d
operator|->
name|restartCommand
operator|=
name|command
expr_stmt|;
block|}
end_function
begin_function
DECL|function|restartCommand
name|QStringList
name|QSessionManager
operator|::
name|restartCommand
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSessionManager
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|restartCommand
return|;
block|}
end_function
begin_function
DECL|function|setDiscardCommand
name|void
name|QSessionManager
operator|::
name|setDiscardCommand
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|command
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSessionManager
argument_list|)
expr_stmt|;
name|d
operator|->
name|discardCommand
operator|=
name|command
expr_stmt|;
block|}
end_function
begin_function
DECL|function|discardCommand
name|QStringList
name|QSessionManager
operator|::
name|discardCommand
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSessionManager
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|discardCommand
return|;
block|}
end_function
begin_function
DECL|function|setManagerProperty
name|void
name|QSessionManager
operator|::
name|setManagerProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setManagerProperty
name|void
name|QSessionManager
operator|::
name|setManagerProperty
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|value
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isPhase2
name|bool
name|QSessionManager
operator|::
name|isPhase2
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|requestPhase2
name|void
name|QSessionManager
operator|::
name|requestPhase2
parameter_list|()
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SESSIONMANAGER
end_comment
end_unit
