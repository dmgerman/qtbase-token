begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLIBRARY_H
end_ifndef
begin_define
DECL|macro|QLIBRARY_H
define|#
directive|define
name|QLIBRARY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
DECL|variable|QLibraryPrivate
name|class
name|QLibraryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QLibrary
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString fileName READ fileName WRITE setFileName
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|LoadHints loadHints READ loadHints WRITE setLoadHints
argument_list|)
name|public
operator|:
expr|enum
name|LoadHint
block|{
name|ResolveAllSymbolsHint
operator|=
literal|0x01
block|,
name|ExportExternalSymbolsHint
operator|=
literal|0x02
block|,
name|LoadArchiveMemberHint
operator|=
literal|0x04
block|,
name|PreventUnloadHint
operator|=
literal|0x08
block|,
name|DeepBindHint
operator|=
literal|0x10
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|LoadHints
argument_list|,
argument|LoadHint
argument_list|)
name|Q_FLAG
argument_list|(
argument|LoadHint
argument_list|)
name|Q_FLAG
argument_list|(
argument|LoadHints
argument_list|)
name|explicit
name|QLibrary
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QLibrary
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QLibrary
argument_list|(
argument|const QString& fileName
argument_list|,
argument|int verNum
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|explicit
name|QLibrary
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QString
operator|&
name|version
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QLibrary
argument_list|()
block|;
name|QFunctionPointer
name|resolve
argument_list|(
specifier|const
name|char
operator|*
name|symbol
argument_list|)
block|;
specifier|static
name|QFunctionPointer
name|resolve
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|symbol
argument_list|)
block|;
specifier|static
name|QFunctionPointer
name|resolve
argument_list|(
argument|const QString&fileName
argument_list|,
argument|int verNum
argument_list|,
argument|const char *symbol
argument_list|)
block|;
specifier|static
name|QFunctionPointer
name|resolve
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QString
operator|&
name|version
argument_list|,
specifier|const
name|char
operator|*
name|symbol
argument_list|)
block|;
name|bool
name|load
argument_list|()
block|;
name|bool
name|unload
argument_list|()
block|;
name|bool
name|isLoaded
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|isLibrary
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|QString
name|fileName
argument_list|()
specifier|const
block|;
name|void
name|setFileNameAndVersion
argument_list|(
argument|const QString&fileName
argument_list|,
argument|int verNum
argument_list|)
block|;
name|void
name|setFileNameAndVersion
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QString
operator|&
name|version
argument_list|)
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|void
name|setLoadHints
argument_list|(
argument|LoadHints hints
argument_list|)
block|;
name|LoadHints
name|loadHints
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QLibraryPrivate
operator|*
name|d
block|;
name|bool
name|did_load
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QLibrary
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QLibrary::LoadHints
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_LIBRARY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QLIBRARY_H
end_comment
end_unit
