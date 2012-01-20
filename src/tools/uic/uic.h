begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|UIC_H
end_ifndef
begin_define
DECL|macro|UIC_H
define|#
directive|define
name|UIC_H
end_define
begin_include
include|#
directive|include
file|"databaseinfo.h"
end_include
begin_include
include|#
directive|include
file|"customwidgetsinfo.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStack>
end_include
begin_include
include|#
directive|include
file|<QtCore/QXmlStreamReader>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Driver
name|class
name|Driver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomUI
name|class
name|DomUI
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomWidget
name|class
name|DomWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomSpacer
name|class
name|DomSpacer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomLayout
name|class
name|DomLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomLayoutItem
name|class
name|DomLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomItem
name|class
name|DomItem
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|Option
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Uic
block|{
name|public
label|:
name|Uic
argument_list|(
name|Driver
operator|*
name|driver
argument_list|)
expr_stmt|;
operator|~
name|Uic
argument_list|()
expr_stmt|;
name|bool
name|printDependencies
parameter_list|()
function_decl|;
specifier|inline
name|Driver
operator|*
name|driver
argument_list|()
specifier|const
block|{
return|return
name|drv
return|;
block|}
specifier|inline
name|QTextStream
modifier|&
name|output
parameter_list|()
block|{
return|return
name|out
return|;
block|}
specifier|inline
specifier|const
name|Option
operator|&
name|option
argument_list|()
specifier|const
block|{
return|return
name|opt
return|;
block|}
specifier|inline
name|QString
name|pixmapFunction
argument_list|()
specifier|const
block|{
return|return
name|pixFunction
return|;
block|}
specifier|inline
name|void
name|setPixmapFunction
parameter_list|(
specifier|const
name|QString
modifier|&
name|f
parameter_list|)
block|{
name|pixFunction
operator|=
name|f
expr_stmt|;
block|}
specifier|inline
name|bool
name|hasExternalPixmap
argument_list|()
specifier|const
block|{
return|return
name|externalPix
return|;
block|}
specifier|inline
name|void
name|setExternalPixmap
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|externalPix
operator|=
name|b
expr_stmt|;
block|}
specifier|inline
specifier|const
name|DatabaseInfo
operator|*
name|databaseInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|info
return|;
block|}
specifier|inline
specifier|const
name|CustomWidgetsInfo
operator|*
name|customWidgetsInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|cWidgetsInfo
return|;
block|}
name|bool
name|write
parameter_list|(
name|QIODevice
modifier|*
name|in
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|QT_UIC_JAVA_GENERATOR
name|bool
name|jwrite
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_UIC_CPP_GENERATOR
name|bool
name|write
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|)
function_decl|;
endif|#
directive|endif
name|bool
name|isMainWindow
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isToolBar
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isStatusBar
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isButton
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isContainer
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isCustomWidgetContainer
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isMenuBar
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isMenu
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|// copyright header
name|void
name|writeCopyrightHeader
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|)
function_decl|;
name|DomUI
modifier|*
name|parseUiFile
parameter_list|(
name|QXmlStreamReader
modifier|&
name|reader
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|QT_UIC_CPP_GENERATOR
comment|// header protection
name|void
name|writeHeaderProtectionStart
parameter_list|()
function_decl|;
name|void
name|writeHeaderProtectionEnd
parameter_list|()
function_decl|;
endif|#
directive|endif
name|private
label|:
name|Driver
modifier|*
name|drv
decl_stmt|;
name|QTextStream
modifier|&
name|out
decl_stmt|;
name|Option
modifier|&
name|opt
decl_stmt|;
name|DatabaseInfo
name|info
decl_stmt|;
name|CustomWidgetsInfo
name|cWidgetsInfo
decl_stmt|;
name|QString
name|pixFunction
decl_stmt|;
name|bool
name|externalPix
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// UIC_H
end_comment
end_unit
