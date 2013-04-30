begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   location.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LOCATION_H
end_ifndef
begin_define
DECL|macro|LOCATION_H
define|#
directive|define
name|LOCATION_H
end_define
begin_include
include|#
directive|include
file|<qstack.h>
end_include
begin_include
include|#
directive|include
file|"tr.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Config
name|class
name|Config
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegExp
name|class
name|QRegExp
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Location
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::Location
argument_list|)
name|public
label|:
name|Location
argument_list|()
expr_stmt|;
name|Location
argument_list|(
specifier|const
name|QString
operator|&
name|filePath
argument_list|)
expr_stmt|;
name|Location
argument_list|(
specifier|const
name|Location
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|Location
argument_list|()
block|{
name|delete
name|stk
block|; }
name|Location
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Location
operator|&
name|other
operator|)
expr_stmt|;
name|void
name|start
parameter_list|()
function_decl|;
name|void
name|advance
parameter_list|(
name|QChar
name|ch
parameter_list|)
function_decl|;
name|void
name|advanceLines
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|stkTop
operator|->
name|lineNo
operator|+=
name|n
expr_stmt|;
name|stkTop
operator|->
name|columnNo
operator|=
literal|1
expr_stmt|;
block|}
name|void
name|push
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
function_decl|;
name|void
name|pop
parameter_list|()
function_decl|;
name|void
name|setEtc
parameter_list|(
name|bool
name|etc
parameter_list|)
block|{
name|etcetera
operator|=
name|etc
expr_stmt|;
block|}
name|void
name|setLineNo
parameter_list|(
name|int
name|no
parameter_list|)
block|{
name|stkTop
operator|->
name|lineNo
operator|=
name|no
expr_stmt|;
block|}
name|void
name|setColumnNo
parameter_list|(
name|int
name|no
parameter_list|)
block|{
name|stkTop
operator|->
name|columnNo
operator|=
name|no
expr_stmt|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|stkDepth
operator|==
literal|0
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|stkDepth
return|;
block|}
specifier|const
name|QString
operator|&
name|filePath
argument_list|()
specifier|const
block|{
return|return
name|stkTop
operator|->
name|filePath
return|;
block|}
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
name|int
name|lineNo
argument_list|()
specifier|const
block|{
return|return
name|stkTop
operator|->
name|lineNo
return|;
block|}
name|int
name|columnNo
argument_list|()
specifier|const
block|{
return|return
name|stkTop
operator|->
name|columnNo
return|;
block|}
name|bool
name|etc
argument_list|()
specifier|const
block|{
return|return
name|etcetera
return|;
block|}
name|void
name|warning
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|,
specifier|const
name|QString
operator|&
name|details
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|error
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|,
specifier|const
name|QString
operator|&
name|details
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|fatal
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|,
specifier|const
name|QString
operator|&
name|details
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QT_STATIC_CONST
name|Location
name|null
decl_stmt|;
specifier|static
name|void
name|initialize
parameter_list|(
specifier|const
name|Config
modifier|&
name|config
parameter_list|)
function_decl|;
specifier|static
name|void
name|terminate
parameter_list|()
function_decl|;
specifier|static
name|void
name|information
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
function_decl|;
specifier|static
name|void
name|internalError
parameter_list|(
specifier|const
name|QString
modifier|&
name|hint
parameter_list|)
function_decl|;
specifier|static
name|void
name|logToStdErr
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
function_decl|;
specifier|static
name|void
name|startLoggingProgress
parameter_list|()
block|{
name|logProgress_
operator|=
name|true
expr_stmt|;
block|}
specifier|static
name|void
name|stopLoggingProgress
parameter_list|()
block|{
name|logProgress_
operator|=
name|false
expr_stmt|;
block|}
specifier|static
name|QString
name|canonicalRelativePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|private
label|:
enum|enum
name|MessageType
block|{
name|Warning
block|,
name|Error
block|}
enum|;
struct|struct
name|StackEntry
block|{
name|QString
name|filePath
decl_stmt|;
name|int
name|lineNo
decl_stmt|;
name|int
name|columnNo
decl_stmt|;
block|}
struct|;
name|void
name|emitMessage
argument_list|(
name|MessageType
name|type
argument_list|,
specifier|const
name|QString
operator|&
name|message
argument_list|,
specifier|const
name|QString
operator|&
name|details
argument_list|)
decl|const
decl_stmt|;
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|top
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|StackEntry
name|stkBottom
decl_stmt|;
name|QStack
operator|<
name|StackEntry
operator|>
operator|*
name|stk
expr_stmt|;
name|StackEntry
modifier|*
name|stkTop
decl_stmt|;
name|int
name|stkDepth
decl_stmt|;
name|bool
name|etcetera
decl_stmt|;
specifier|static
name|int
name|tabSize
decl_stmt|;
specifier|static
name|QString
name|programName
decl_stmt|;
specifier|static
name|QRegExp
modifier|*
name|spuriousRegExp
decl_stmt|;
specifier|static
name|bool
name|logProgress_
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
end_unit
