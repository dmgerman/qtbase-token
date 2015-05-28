begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSNATIVEINTERFACE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSNATIVEINTERFACE_H
define|#
directive|define
name|QWINDOWSNATIVEINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qfont.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformnativeinterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QWindowsNativeInterface     \brief Provides access to native handles.      Currently implemented keys     \list     \li handle (HWND)     \li getDC (DC)     \li releaseDC Releases the previously acquired DC and returns 0.     \endlist      \internal     \ingroup qt-lighthouse-win */
name|class
name|QWindowsNativeInterface
range|:
name|public
name|QPlatformNativeInterface
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool asyncExpose READ asyncExpose WRITE setAsyncExpose
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QVariant gpu READ gpu STORED false
argument_list|)
name|public
operator|:
name|void
operator|*
name|nativeResourceForIntegration
argument_list|(
argument|const QByteArray&resource
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|void
operator|*
name|nativeResourceForContext
argument_list|(
argument|const QByteArray&resource
argument_list|,
argument|QOpenGLContext *context
argument_list|)
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|void
operator|*
name|nativeResourceForWindow
argument_list|(
argument|const QByteArray&resource
argument_list|,
argument|QWindow *window
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|Q_INVOKABLE
name|void
operator|*
name|createMessageWindow
argument_list|(
argument|const QString&classNameTemplate
argument_list|,
argument|const QString&windowName
argument_list|,
argument|void *eventProc
argument_list|)
specifier|const
block|;
name|Q_INVOKABLE
name|QString
name|registerWindowClass
argument_list|(
argument|const QString&classNameIn
argument_list|,
argument|void *eventProc
argument_list|)
specifier|const
block|;
name|Q_INVOKABLE
name|void
name|beep
argument_list|()
block|;
name|Q_INVOKABLE
name|void
name|registerWindowsMime
argument_list|(
name|void
operator|*
name|mimeIn
argument_list|)
block|;
name|Q_INVOKABLE
name|void
name|unregisterWindowsMime
argument_list|(
name|void
operator|*
name|mime
argument_list|)
block|;
name|Q_INVOKABLE
name|int
name|registerMimeType
argument_list|(
specifier|const
name|QString
operator|&
name|mimeType
argument_list|)
block|;
name|Q_INVOKABLE
name|QFont
name|logFontToQFont
argument_list|(
argument|const void *logFont
argument_list|,
argument|int verticalDpi
argument_list|)
block|;
name|bool
name|asyncExpose
argument_list|()
specifier|const
block|;
name|void
name|setAsyncExpose
argument_list|(
argument|bool value
argument_list|)
block|;
name|QVariant
name|gpu
argument_list|()
specifier|const
block|;
name|QVariantMap
name|windowProperties
argument_list|(
argument|QPlatformWindow *window
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|windowProperty
argument_list|(
argument|QPlatformWindow *window
argument_list|,
argument|const QString&name
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|windowProperty
argument_list|(
argument|QPlatformWindow *window
argument_list|,
argument|const QString&name
argument_list|,
argument|const QVariant&defaultValue
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setWindowProperty
argument_list|(
argument|QPlatformWindow *window
argument_list|,
argument|const QString&name
argument_list|,
argument|const QVariant&value
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QFunctionPointer
name|platformFunction
argument_list|(
argument|const QByteArray&function
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
comment|// QWINDOWSNATIVEINTERFACE_H
end_comment
end_unit
