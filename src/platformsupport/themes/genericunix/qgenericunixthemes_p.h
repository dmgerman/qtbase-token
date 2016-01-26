begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGENERICUNIXTHEMES_H
end_ifndef
begin_define
DECL|macro|QGENERICUNIXTHEMES_H
define|#
directive|define
name|QGENERICUNIXTHEMES_H
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
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtGui/QFont>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|ResourceHelper
block|{
name|public
label|:
name|ResourceHelper
argument_list|()
expr_stmt|;
operator|~
name|ResourceHelper
argument_list|()
block|{
name|clear
argument_list|()
block|; }
name|void
name|clear
argument_list|()
expr_stmt|;
name|QPalette
modifier|*
name|palettes
index|[
name|QPlatformTheme
operator|::
name|NPalettes
index|]
decl_stmt|;
name|QFont
modifier|*
name|fonts
index|[
name|QPlatformTheme
operator|::
name|NFonts
index|]
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QGenericUnixThemePrivate
name|class
name|QGenericUnixThemePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGenericUnixTheme
range|:
name|public
name|QPlatformTheme
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGenericUnixTheme
argument_list|)
name|public
operator|:
name|QGenericUnixTheme
argument_list|()
block|;
specifier|static
name|QPlatformTheme
operator|*
name|createUnixTheme
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
specifier|static
name|QStringList
name|themeNames
argument_list|()
block|;
specifier|const
name|QFont
operator|*
name|font
argument_list|(
argument|Font type
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|themeHint
argument_list|(
argument|ThemeHint hint
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|QStringList
name|xdgIconThemePaths
argument_list|()
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DBUS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SYSTEMTRAYICON
argument_list|)
name|QPlatformSystemTrayIcon
operator|*
name|createPlatformSystemTrayIcon
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
specifier|static
specifier|const
name|char
operator|*
name|name
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
end_ifndef
begin_decl_stmt
DECL|variable|QKdeThemePrivate
name|class
name|QKdeThemePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QKdeTheme
range|:
name|public
name|QPlatformTheme
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QKdeTheme
argument_list|)
name|public
operator|:
name|QKdeTheme
argument_list|(
argument|const QStringList& kdeDirs
argument_list|,
argument|int kdeVersion
argument_list|)
block|;
specifier|static
name|QPlatformTheme
operator|*
name|createKdeTheme
argument_list|()
block|;
name|QVariant
name|themeHint
argument_list|(
argument|ThemeHint hint
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QPalette
operator|*
name|palette
argument_list|(
argument|Palette type = SystemPalette
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QFont
operator|*
name|font
argument_list|(
argument|Font type
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DBUS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SYSTEMTRAYICON
argument_list|)
name|QPlatformSystemTrayIcon
operator|*
name|createPlatformSystemTrayIcon
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
specifier|static
specifier|const
name|char
operator|*
name|name
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SETTINGS
end_comment
begin_decl_stmt
DECL|variable|QGnomeThemePrivate
name|class
name|QGnomeThemePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGnomeTheme
range|:
name|public
name|QPlatformTheme
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGnomeTheme
argument_list|)
name|public
operator|:
name|QGnomeTheme
argument_list|()
block|;
name|QVariant
name|themeHint
argument_list|(
argument|ThemeHint hint
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QFont
operator|*
name|font
argument_list|(
argument|Font type
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|standardButtonText
argument_list|(
argument|int button
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|gtkFontName
argument_list|()
specifier|const
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DBUS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SYSTEMTRAYICON
argument_list|)
name|QPlatformSystemTrayIcon
operator|*
name|createPlatformSystemTrayIcon
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
specifier|static
specifier|const
name|char
operator|*
name|name
block|; }
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QPlatformTheme
modifier|*
name|qt_createUnixTheme
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
comment|// QGENERICUNIXTHEMES_H
end_comment
end_unit
