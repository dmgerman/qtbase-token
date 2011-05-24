begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************** ** ** Definition of QInputContextFactory class ** ** Copyright (C) 2003-2004 immodule for Qt Project.  All rights reserved. ** ** This file is written to contribute to Nokia Corporation and/or its subsidiary(-ies) under their own ** license. You may use this file under your Qt license. Following ** description is copied from their original file headers. Contact ** immodule-qt@freedesktop.org if any conditions of this licensing are ** not clear to you. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QINPUTCONTEXTFACTORY_H
end_ifndef
begin_define
DECL|macro|QINPUTCONTEXTFACTORY_H
define|#
directive|define
name|QINPUTCONTEXTFACTORY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_IM
name|class
name|QInputContext
decl_stmt|;
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QInputContextFactory
decl_stmt|{ public:     static QStringList keys(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_function_decl
specifier|static
name|QInputContext
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// should be a toplevel widget
end_comment
begin_function_decl
specifier|static
name|QStringList
name|languages
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|displayName
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|description
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_IM
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QINPUTCONTEXTFACTORY_H
end_comment
end_unit
