begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDASSETSFILEENGINEHANDLER_H
end_ifndef
begin_define
DECL|macro|QANDROIDASSETSFILEENGINEHANDLER_H
define|#
directive|define
name|QANDROIDASSETSFILEENGINEHANDLER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/private/qabstractfileengine_p.h>
end_include
begin_include
include|#
directive|include
file|<QCache>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<android/asset_manager.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct_decl
struct_decl|struct
name|AndroidAssetDir
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|AndroidAssetsFileEngineHandler
range|:
name|public
name|QAbstractFileEngineHandler
block|{
name|public
operator|:
name|AndroidAssetsFileEngineHandler
argument_list|()
block|;
name|virtual
operator|~
name|AndroidAssetsFileEngineHandler
argument_list|()
block|;
name|QAbstractFileEngine
operator|*
name|create
argument_list|(
argument|const QString&fileName
argument_list|)
specifier|const
block|;
name|private
operator|:
name|void
name|prepopulateCache
argument_list|()
specifier|const
block|;
name|AAssetManager
operator|*
name|m_assetManager
block|;
name|mutable
name|QCache
operator|<
name|QByteArray
block|,
name|QSharedPointer
operator|<
name|AndroidAssetDir
operator|>>
name|m_assetsCache
block|;
name|mutable
name|QMutex
name|m_assetsCacheMutext
block|;
name|mutable
name|bool
name|m_hasPrepopulatedCache
block|;
name|mutable
name|bool
name|m_hasTriedPrepopulatingCache
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
comment|// QANDROIDASSETSFILEENGINEHANDLER_H
end_comment
end_unit
