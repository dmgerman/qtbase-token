begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PROPERTY_H
end_ifndef
begin_define
DECL|macro|PROPERTY_H
define|#
directive|define
name|PROPERTY_H
end_define
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSettings
name|class
name|QSettings
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMakeProperty
block|{
name|QSettings
modifier|*
name|settings
decl_stmt|;
name|void
name|initSettings
parameter_list|()
function_decl|;
name|QString
name|keyBase
argument_list|(
name|bool
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
name|QString
name|value
parameter_list|(
name|QString
parameter_list|,
name|bool
name|just_check
parameter_list|)
function_decl|;
name|public
label|:
name|QMakeProperty
argument_list|()
expr_stmt|;
operator|~
name|QMakeProperty
argument_list|()
expr_stmt|;
name|bool
name|hasValue
parameter_list|(
name|QString
parameter_list|)
function_decl|;
name|QString
name|value
parameter_list|(
name|QString
name|v
parameter_list|)
block|{
return|return
name|value
argument_list|(
name|v
argument_list|,
name|false
argument_list|)
return|;
block|}
name|void
name|setValue
parameter_list|(
name|QString
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|bool
name|exec
parameter_list|()
function_decl|;
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
comment|// PROPERTY_H
end_comment
end_unit
