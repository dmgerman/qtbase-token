begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qgtk3theme.h"
end_include
begin_include
include|#
directive|include
file|"qgtk3dialoghelpers.h"
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_undef
DECL|macro|signals
undef|#
directive|undef
name|signals
end_undef
begin_include
include|#
directive|include
file|<gtk/gtk.h>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|name
specifier|const
name|char
modifier|*
name|QGtk3Theme
operator|::
name|name
init|=
literal|"gtk3"
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|gtkSetting
specifier|static
name|QString
name|gtkSetting
parameter_list|(
specifier|const
name|gchar
modifier|*
name|propertyName
parameter_list|)
block|{
name|GtkSettings
modifier|*
name|settings
init|=
name|gtk_settings_get_default
argument_list|()
decl_stmt|;
name|gchararray
name|value
decl_stmt|;
name|g_object_get
argument_list|(
name|settings
argument_list|,
name|propertyName
argument_list|,
operator|&
name|value
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|QString
name|str
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|value
argument_list|)
decl_stmt|;
name|g_free
argument_list|(
name|value
argument_list|)
expr_stmt|;
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|gtkMessageHandler
name|void
name|gtkMessageHandler
parameter_list|(
specifier|const
name|gchar
modifier|*
name|log_domain
parameter_list|,
name|GLogLevelFlags
name|log_level
parameter_list|,
specifier|const
name|gchar
modifier|*
name|message
parameter_list|,
name|gpointer
name|unused_data
parameter_list|)
block|{
comment|/* Silence false-positive Gtk warnings (we are using Xlib to set      * the WM_TRANSIENT_FOR hint).      */
if|if
condition|(
name|g_strcmp0
argument_list|(
name|message
argument_list|,
literal|"GtkDialog mapped without a transient parent. "
literal|"This is discouraged."
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* For other messages, call the default handler. */
name|g_log_default_handler
argument_list|(
name|log_domain
argument_list|,
name|log_level
argument_list|,
name|message
argument_list|,
name|unused_data
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|QGtk3Theme
name|QGtk3Theme
operator|::
name|QGtk3Theme
parameter_list|()
block|{
comment|// gtk_init will reset the Xlib error handler, and that causes
comment|// Qt applications to quit on X errors. Therefore, we need to manually restore it.
name|int
function_decl|(
modifier|*
name|oldErrorHandler
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|XErrorEvent
modifier|*
parameter_list|)
init|=
name|XSetErrorHandler
argument_list|(
name|NULL
argument_list|)
function_decl|;
name|gtk_init
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|XSetErrorHandler
argument_list|(
name|oldErrorHandler
argument_list|)
expr_stmt|;
comment|/* Initialize some types here so that Gtk+ does not crash when reading      * the treemodel for GtkFontChooser.      */
name|g_type_ensure
argument_list|(
name|PANGO_TYPE_FONT_FAMILY
argument_list|)
expr_stmt|;
name|g_type_ensure
argument_list|(
name|PANGO_TYPE_FONT_FACE
argument_list|)
expr_stmt|;
comment|/* Use our custom log handler. */
name|g_log_set_handler
argument_list|(
literal|"Gtk"
argument_list|,
name|G_LOG_LEVEL_MESSAGE
argument_list|,
name|gtkMessageHandler
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|themeHint
name|QVariant
name|QGtk3Theme
operator|::
name|themeHint
parameter_list|(
name|QPlatformTheme
operator|::
name|ThemeHint
name|hint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|QPlatformTheme
operator|::
name|SystemIconThemeName
case|:
return|return
name|QVariant
argument_list|(
name|gtkSetting
argument_list|(
literal|"gtk-icon-theme-name"
argument_list|)
argument_list|)
return|;
case|case
name|QPlatformTheme
operator|::
name|SystemIconFallbackThemeName
case|:
return|return
name|QVariant
argument_list|(
name|gtkSetting
argument_list|(
literal|"gtk-fallback-icon-theme"
argument_list|)
argument_list|)
return|;
default|default:
return|return
name|QGnomeTheme
operator|::
name|themeHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|gtkFontName
name|QString
name|QGtk3Theme
operator|::
name|gtkFontName
parameter_list|()
specifier|const
block|{
name|QString
name|cfgFontName
init|=
name|gtkSetting
argument_list|(
literal|"gtk-font-name"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|cfgFontName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|cfgFontName
return|;
return|return
name|QGnomeTheme
operator|::
name|gtkFontName
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|usePlatformNativeDialog
name|bool
name|QGtk3Theme
operator|::
name|usePlatformNativeDialog
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|ColorDialog
case|:
return|return
literal|true
return|;
case|case
name|FileDialog
case|:
return|return
literal|true
return|;
case|case
name|FontDialog
case|:
return|return
literal|true
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformDialogHelper
name|QPlatformDialogHelper
modifier|*
name|QGtk3Theme
operator|::
name|createPlatformDialogHelper
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|ColorDialog
case|:
return|return
operator|new
name|QGtk3ColorDialogHelper
return|;
case|case
name|FileDialog
case|:
return|return
operator|new
name|QGtk3FileDialogHelper
return|;
case|case
name|FontDialog
case|:
return|return
operator|new
name|QGtk3FontDialogHelper
return|;
default|default:
return|return
literal|0
return|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
