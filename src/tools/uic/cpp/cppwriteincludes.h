begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CPPWRITEINCLUDES_H
end_ifndef
begin_define
DECL|macro|CPPWRITEINCLUDES_H
define|#
directive|define
name|CPPWRITEINCLUDES_H
end_define
begin_include
include|#
directive|include
file|"treewalker.h"
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Driver
name|class
name|Driver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Uic
name|class
name|Uic
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|CPP
block|{
name|struct
name|WriteIncludes
range|:
name|public
name|TreeWalker
block|{
name|WriteIncludes
argument_list|(
name|Uic
operator|*
name|uic
argument_list|)
block|;
name|void
name|acceptUI
argument_list|(
name|DomUI
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptWidget
argument_list|(
name|DomWidget
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptLayout
argument_list|(
name|DomLayout
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptSpacer
argument_list|(
name|DomSpacer
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptProperty
argument_list|(
name|DomProperty
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptWidgetScripts
argument_list|(
specifier|const
name|DomScripts
operator|&
argument_list|,
name|DomWidget
operator|*
argument_list|,
specifier|const
name|DomWidgets
operator|&
argument_list|)
block|;
comment|//
comment|// custom widgets
comment|//
name|void
name|acceptCustomWidgets
argument_list|(
name|DomCustomWidgets
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptCustomWidget
argument_list|(
name|DomCustomWidget
operator|*
name|node
argument_list|)
block|;
comment|//
comment|// include hints
comment|//
name|void
name|acceptIncludes
argument_list|(
name|DomIncludes
operator|*
name|node
argument_list|)
block|;
name|void
name|acceptInclude
argument_list|(
name|DomInclude
operator|*
name|node
argument_list|)
block|;
name|bool
name|scriptsActivated
argument_list|()
specifier|const
block|{
return|return
name|m_scriptsActivated
return|;
block|}
name|private
operator|:
name|void
name|add
argument_list|(
argument|const QString&className
argument_list|,
argument|bool determineHeader = true
argument_list|,
argument|const QString&header = QString()
argument_list|,
argument|bool global = false
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|bool
operator|>
name|OrderedSet
expr_stmt|;
name|void
name|insertIncludeForClass
argument_list|(
argument|const QString&className
argument_list|,
argument|QString header = QString()
argument_list|,
argument|bool global = false
argument_list|)
decl_stmt|;
name|void
name|insertInclude
parameter_list|(
specifier|const
name|QString
modifier|&
name|header
parameter_list|,
name|bool
name|global
parameter_list|)
function_decl|;
name|void
name|writeHeaders
parameter_list|(
specifier|const
name|OrderedSet
modifier|&
name|headers
parameter_list|,
name|bool
name|global
parameter_list|)
function_decl|;
name|QString
name|headerForClassName
argument_list|(
specifier|const
name|QString
operator|&
name|className
argument_list|)
decl|const
decl_stmt|;
name|void
name|activateScripts
parameter_list|()
function_decl|;
specifier|const
name|Uic
modifier|*
name|m_uic
decl_stmt|;
name|QTextStream
modifier|&
name|m_output
decl_stmt|;
name|OrderedSet
name|m_localIncludes
decl_stmt|;
name|OrderedSet
name|m_globalIncludes
decl_stmt|;
name|QSet
operator|<
name|QString
operator|>
name|m_includeBaseNames
expr_stmt|;
name|QSet
operator|<
name|QString
operator|>
name|m_knownClasses
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|StringMap
expr_stmt|;
name|StringMap
name|m_classToHeader
decl_stmt|;
name|StringMap
name|m_oldHeaderToNewHeader
decl_stmt|;
name|bool
name|m_scriptsActivated
decl_stmt|;
name|bool
name|m_laidOut
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
unit|}
comment|// namespace CPP
end_comment
begin_endif
unit|QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// CPPWRITEINCLUDES_H
end_comment
end_unit
