begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2013 BlackBerry Limited. All rights reserved.  ** Contact: http://www.qt.io/licensing/  **  ** This file is part of the QtCore module of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL21$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and The Qt Company. For licensing terms  ** and conditions see http://www.qt.io/terms-conditions. For further  ** information use the contact form at http://www.qt.io/contact-us.  **  ** GNU Lesser General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU Lesser  ** General Public License version 2.1 or version 3 as published by the Free  ** Software Foundation and appearing in the file LICENSE.LGPLv21 and  ** LICENSE.LGPLv3 included in the packaging of this file. Please review the  ** following information to ensure the GNU Lesser General Public License  ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and  ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.  **  ** As a special exception, The Qt Company gives you certain additional  ** rights. These rights are described in The Qt Company LGPL Exception  ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPPSATTRIBUTEPRIVATE_P_H
end_ifndef
begin_define
DECL|macro|QPPSATTRIBUTEPRIVATE_P_H
define|#
directive|define
name|QPPSATTRIBUTEPRIVATE_P_H
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
file|"qppsattribute_p.h"
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QSharedData>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QPpsAttributePrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QPpsAttributePrivate
argument_list|()
block|;
specifier|static
name|QPpsAttribute
name|createPpsAttribute
argument_list|(
argument|double value
argument_list|,
argument|QPpsAttribute::Flags flags
argument_list|)
block|;
specifier|static
name|QPpsAttribute
name|createPpsAttribute
argument_list|(
argument|long long value
argument_list|,
argument|QPpsAttribute::Flags flags
argument_list|)
block|;
specifier|static
name|QPpsAttribute
name|createPpsAttribute
argument_list|(
argument|int value
argument_list|,
argument|QPpsAttribute::Flags flags
argument_list|)
block|;
specifier|static
name|QPpsAttribute
name|createPpsAttribute
argument_list|(
argument|bool value
argument_list|,
argument|QPpsAttribute::Flags flags
argument_list|)
block|;
specifier|static
name|QPpsAttribute
name|createPpsAttribute
argument_list|(
argument|const QString&value
argument_list|,
argument|QPpsAttribute::Flags flags
argument_list|)
block|;
specifier|static
name|QPpsAttribute
name|createPpsAttribute
argument_list|(
argument|const QPpsAttributeList&value
argument_list|,
argument|QPpsAttribute::Flags flags
argument_list|)
block|;
specifier|static
name|QPpsAttribute
name|createPpsAttribute
argument_list|(
argument|const QPpsAttributeMap&value
argument_list|,
argument|QPpsAttribute::Flags flags
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QPpsAttribute
block|;
name|QVariant
name|data
block|;
name|QPpsAttribute
operator|::
name|Type
name|type
block|;
name|QPpsAttribute
operator|::
name|Flags
name|flags
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
comment|// QPPSATTRIBUTEPRIVATE_P_H
end_comment
end_unit
