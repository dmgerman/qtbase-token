begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_SYMBIAN_EPOCROOT_H
end_ifndef
begin_define
DECL|macro|QT_SYMBIAN_EPOCROOT_H
define|#
directive|define
name|QT_SYMBIAN_EPOCROOT_H
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
file|<QtCore/qstring.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
comment|/**  * Determine the epoc root for the currently active SDK.  *  * The algorithm used is as follows:  * 1. If environment variable EPOCROOT is set and points to an existent  *    directory, this is returned.  * 2. The location of devices.xml is specified by a registry key.  If this  *    file exists, it is parsed.  * 3. If the EPOCDEVICE environment variable is set and a corresponding  *    entry is found in devices.xml, and its epocroot value points to an  *    existent directory, it is returned.  * 4. If a device element marked as default is found in devices.xml and its  *    epocroot value points to an existent directory, this is returned.  * 5. An empty string is returned.  *  * Any return value other than the empty string therefore is guaranteed to  * point to an existent directory.  */
name|QString
name|qt_epocRoot
parameter_list|()
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_SYMBIAN_EPOCROOT_H
end_comment
end_unit
