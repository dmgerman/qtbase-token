begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESELECTOR_P_H
end_ifndef
begin_define
DECL|macro|QFILESELECTOR_P_H
define|#
directive|define
name|QFILESELECTOR_P_H
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
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFileSelector>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QFileSelectorSharedData
struct|struct
name|QFileSelectorSharedData
comment|//Not QSharedData because currently is just a global store
block|{
DECL|member|staticSelectors
name|QStringList
name|staticSelectors
decl_stmt|;
DECL|member|preloadedStatics
name|QStringList
name|preloadedStatics
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFileSelectorPrivate
range|:
name|QObjectPrivate
comment|//Exported for use in other modules (like QtGui)
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFileSelector
argument_list|)
name|public
operator|:
specifier|static
name|void
name|updateSelectors
argument_list|()
block|;
specifier|static
name|QStringList
name|platformSelectors
argument_list|()
block|;
specifier|static
name|void
name|addStatics
argument_list|(
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
comment|//For loading GUI statics from other Qt modules
name|QFileSelectorPrivate
argument_list|()
block|;
name|QString
name|select
argument_list|(
argument|const QString&filePath
argument_list|)
specifier|const
block|;
name|QStringList
name|extras
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
end_unit
