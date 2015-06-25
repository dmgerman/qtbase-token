begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Laszlo Papp<lpapp@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOMMANDLINEOPTION_H
end_ifndef
begin_define
DECL|macro|QCOMMANDLINEOPTION_H
define|#
directive|define
name|QCOMMANDLINEOPTION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCommandLineOptionPrivate
name|class
name|QCommandLineOptionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QCommandLineOption
block|{
name|public
label|:
name|explicit
name|QCommandLineOption
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|explicit
name|QCommandLineOption
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|names
parameter_list|)
function_decl|;
comment|/*implicit*/
name|QCommandLineOption
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|,
specifier|const
name|QString
operator|&
name|description
argument_list|,
specifier|const
name|QString
operator|&
name|valueName
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|defaultValue
operator|=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
comment|/*implicit*/
name|QCommandLineOption
argument_list|(
specifier|const
name|QStringList
operator|&
name|names
argument_list|,
specifier|const
name|QString
operator|&
name|description
argument_list|,
specifier|const
name|QString
operator|&
name|valueName
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|defaultValue
operator|=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QCommandLineOption
argument_list|(
specifier|const
name|QCommandLineOption
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QCommandLineOption
argument_list|()
expr_stmt|;
name|QCommandLineOption
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QCommandLineOption
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QCommandLineOption
modifier|&
name|operator
init|=
operator|(
name|QCommandLineOption
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QCommandLineOption
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QStringList
name|names
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setValueName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|QString
name|valueName
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDescription
parameter_list|(
specifier|const
name|QString
modifier|&
name|description
parameter_list|)
function_decl|;
name|QString
name|description
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDefaultValue
parameter_list|(
specifier|const
name|QString
modifier|&
name|defaultValue
parameter_list|)
function_decl|;
name|void
name|setDefaultValues
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|defaultValues
parameter_list|)
function_decl|;
name|QStringList
name|defaultValues
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setHidden
parameter_list|(
name|bool
name|hidden
parameter_list|)
function_decl|;
name|bool
name|isHidden
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QCommandLineOptionPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QCommandLineOption
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOMMANDLINEOPTION_H
end_comment
end_unit
