begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the Qt Designer of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FORMSCRIPTRUNNER_H
end_ifndef
begin_define
DECL|macro|FORMSCRIPTRUNNER_H
define|#
directive|define
name|FORMSCRIPTRUNNER_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"uilib_global.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFlags>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QFORMINTERNAL_NAMESPACE
end_ifdef
begin_decl_stmt
name|namespace
name|QFormInternal
block|{
endif|#
directive|endif
name|class
name|DomWidget
decl_stmt|;
name|class
name|QDESIGNER_UILIB_EXPORT
name|QFormScriptRunner
block|{
name|public
label|:
name|QFormScriptRunner
argument_list|()
expr_stmt|;
operator|~
name|QFormScriptRunner
argument_list|()
expr_stmt|;
typedef|typedef
name|QList
operator|<
name|QWidget
operator|*
operator|>
name|WidgetList
expr_stmt|;
name|bool
name|run
parameter_list|(
specifier|const
name|DomWidget
modifier|*
name|domWidget
parameter_list|,
specifier|const
name|QString
modifier|&
name|customWidgetScript
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|WidgetList
modifier|&
name|children
parameter_list|,
name|QString
modifier|*
name|errorMessage
parameter_list|)
function_decl|;
struct|struct
name|Error
block|{
name|QString
name|objectName
decl_stmt|;
name|QString
name|script
decl_stmt|;
name|QString
name|errorMessage
decl_stmt|;
block|}
struct|;
typedef|typedef
name|QList
operator|<
name|Error
operator|>
name|Errors
expr_stmt|;
name|Errors
name|errors
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clearErrors
parameter_list|()
function_decl|;
enum|enum
name|Option
block|{
name|NoOptions
init|=
literal|0x0
block|,
name|DisableWarnings
init|=
literal|0x1
block|,
name|DisableScripts
init|=
literal|02
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Options
argument_list|,
argument|Option
argument_list|)
name|Options
name|options
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOptions
parameter_list|(
name|Options
name|options
parameter_list|)
function_decl|;
name|private
label|:
name|class
name|QFormScriptRunnerPrivate
decl_stmt|;
name|QFormScriptRunnerPrivate
modifier|*
name|m_impl
decl_stmt|;
name|QFormScriptRunner
argument_list|(
specifier|const
name|QFormScriptRunner
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|QFormScriptRunner
operator|&
operator|)
decl_stmt|;
block|}
empty_stmt|;
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFormScriptRunner::Options
argument_list|)
ifdef|#
directive|ifdef
name|QFORMINTERNAL_NAMESPACE
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// FORMSCRIPTRUNNER_H
end_comment
end_unit
