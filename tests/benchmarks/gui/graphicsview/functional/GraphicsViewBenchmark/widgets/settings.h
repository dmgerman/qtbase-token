begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SETTINGS_H
end_ifndef
begin_define
DECL|macro|SETTINGS_H
define|#
directive|define
name|SETTINGS_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QSize>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QFlags>
end_include
begin_decl_stmt
name|class
name|Settings
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|Option
block|{
name|NoOptions
operator|=
literal|0x1
block|,
name|UseListItemCache
operator|=
literal|0x2
block|,
name|UseOpenGL
operator|=
literal|0x4
block|,
name|OutputFps
operator|=
literal|0x8
block|,
name|NoResourceUsage
operator|=
literal|0x10
block|,
name|ManualTest
operator|=
literal|0x20
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Options
argument_list|,
argument|Option
argument_list|)
name|Settings
argument_list|()
block|;
operator|~
name|Settings
argument_list|()
block|;
specifier|const
name|QString
operator|&
name|scriptName
argument_list|()
specifier|const
block|{
return|return
name|m_scriptName
return|;
block|}
name|void
name|setScriptName
argument_list|(
argument|const QString& scriptName
argument_list|)
block|{
name|m_scriptName
operator|=
name|scriptName
block|; }
specifier|const
name|QString
operator|&
name|outputFileName
argument_list|()
specifier|const
block|{
return|return
name|m_outputFileName
return|;
block|}
name|void
name|setOutputFileName
argument_list|(
argument|const QString& outputFileName
argument_list|)
block|{
name|m_outputFileName
operator|=
name|outputFileName
block|; }
name|int
name|resultFormat
argument_list|()
specifier|const
block|{
return|return
name|m_resultFormat
return|;
block|}
name|void
name|setResultFormat
argument_list|(
argument|int resultFormat
argument_list|)
block|{
name|m_resultFormat
operator|=
name|resultFormat
block|; }
specifier|const
name|QSize
operator|&
name|size
argument_list|()
specifier|const
block|{
return|return
name|m_size
return|;
block|}
name|void
name|setSize
argument_list|(
argument|const QSize& size
argument_list|)
block|{
name|m_size
operator|=
name|size
block|; }
name|int
name|angle
argument_list|()
specifier|const
block|{
return|return
name|m_angle
return|;
block|}
name|void
name|setAngle
argument_list|(
argument|int angle
argument_list|)
block|{
name|m_angle
operator|=
name|angle
block|; }
specifier|const
name|Options
operator|&
name|options
argument_list|()
specifier|const
block|{
return|return
name|m_options
return|;
block|}
name|void
name|setOptions
argument_list|(
argument|Options options
argument_list|)
block|{
name|m_options
operator|=
name|options
block|; }
name|int
name|listItemCount
argument_list|()
block|{
return|return
name|m_listItemCount
return|;
block|}
name|void
name|setListItemCount
argument_list|(
argument|int items
argument_list|)
block|{
name|m_listItemCount
operator|=
name|items
block|; }
name|private
operator|:
name|QString
name|m_scriptName
block|;
name|QString
name|m_outputFileName
block|;
name|int
name|m_resultFormat
block|;
name|QSize
name|m_size
block|;
name|int
name|m_angle
block|;
name|int
name|m_listItemCount
block|;
name|Options
name|m_options
block|;     }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|Settings::Options
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
