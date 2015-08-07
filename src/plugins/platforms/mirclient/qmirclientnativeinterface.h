begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIRCLIENTNATIVEINTERFACE_H
end_ifndef
begin_define
DECL|macro|QMIRCLIENTNATIVEINTERFACE_H
define|#
directive|define
name|QMIRCLIENTNATIVEINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_decl_stmt
name|class
name|QMirClientNativeInterface
range|:
name|public
name|QPlatformNativeInterface
block|{
name|public
operator|:
expr|enum
name|ResourceType
block|{
name|EglDisplay
block|,
name|EglContext
block|,
name|NativeOrientation
block|,
name|Display
block|}
block|;
name|QMirClientNativeInterface
argument_list|()
block|;
operator|~
name|QMirClientNativeInterface
argument_list|()
block|;
comment|// QPlatformNativeInterface methods.
name|void
operator|*
name|nativeResourceForContext
argument_list|(
argument|const QByteArray& resourceString
argument_list|,
argument|QOpenGLContext* context
argument_list|)
name|override
block|;
name|void
operator|*
name|nativeResourceForWindow
argument_list|(
argument|const QByteArray& resourceString
argument_list|,
argument|QWindow* window
argument_list|)
name|override
block|;
name|void
operator|*
name|nativeResourceForScreen
argument_list|(
argument|const QByteArray& resourceString
argument_list|,
argument|QScreen* screen
argument_list|)
name|override
block|;
comment|// New methods.
specifier|const
name|QByteArray
operator|&
name|genericEventFilterType
argument_list|()
specifier|const
block|{
return|return
name|mGenericEventFilterType
return|;
block|}
name|private
operator|:
specifier|const
name|QByteArray
name|mGenericEventFilterType
block|;
name|Qt
operator|::
name|ScreenOrientation
operator|*
name|mNativeOrientation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIRCLIENTNATIVEINTERFACE_H
end_comment
end_unit
