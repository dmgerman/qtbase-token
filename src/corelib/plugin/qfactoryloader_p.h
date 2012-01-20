begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFACTORYLOADER_P_H
end_ifndef
begin_define
DECL|macro|QFACTORYLOADER_P_H
define|#
directive|define
name|QFACTORYLOADER_P_H
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
file|"QtCore/qobject.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"private/qlibrary_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFactoryLoaderPrivate
name|class
name|QFactoryLoaderPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFactoryLoader
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFactoryLoader
argument_list|)
name|public
operator|:
name|QFactoryLoader
argument_list|(
specifier|const
name|char
operator|*
name|iid
argument_list|,
specifier|const
name|QString
operator|&
name|suffix
operator|=
name|QString
argument_list|()
argument_list|,
name|Qt
operator|::
name|CaseSensitivity
operator|=
name|Qt
operator|::
name|CaseSensitive
argument_list|)
block|;
operator|~
name|QFactoryLoader
argument_list|()
block|;
name|QStringList
name|keys
argument_list|()
specifier|const
block|;
name|QObject
operator|*
name|instance
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|QLibraryPrivate
operator|*
name|library
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|void
name|update
argument_list|()
block|;
specifier|static
name|void
name|refreshAll
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFACTORYLOADER_P_H
end_comment
end_unit
