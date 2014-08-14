begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"androidjnimenu.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformtheme.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformmenubar.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformmenu.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformmenuitem.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformdialoghelpers.h"
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qandroidplatformintegration.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QAndroidPlatformTheme
name|QAndroidPlatformTheme
operator|::
name|QAndroidPlatformTheme
parameter_list|(
name|QAndroidPlatformNativeInterface
modifier|*
name|androidPlatformNativeInterface
parameter_list|)
block|{
name|m_androidPlatformNativeInterface
operator|=
name|androidPlatformNativeInterface
expr_stmt|;
name|QColor
name|background
argument_list|(
literal|229
argument_list|,
literal|229
argument_list|,
literal|229
argument_list|)
decl_stmt|;
name|QColor
name|light
init|=
name|background
operator|.
name|lighter
argument_list|(
literal|150
argument_list|)
decl_stmt|;
name|QColor
name|mid
argument_list|(
name|background
operator|.
name|darker
argument_list|(
literal|130
argument_list|)
argument_list|)
decl_stmt|;
name|QColor
name|midLight
init|=
name|mid
operator|.
name|lighter
argument_list|(
literal|110
argument_list|)
decl_stmt|;
name|QColor
name|base
argument_list|(
literal|249
argument_list|,
literal|249
argument_list|,
literal|249
argument_list|)
decl_stmt|;
name|QColor
name|disabledBase
argument_list|(
name|background
argument_list|)
decl_stmt|;
name|QColor
name|dark
init|=
name|background
operator|.
name|darker
argument_list|(
literal|150
argument_list|)
decl_stmt|;
name|QColor
name|darkDisabled
init|=
name|dark
operator|.
name|darker
argument_list|(
literal|110
argument_list|)
decl_stmt|;
name|QColor
name|text
init|=
name|Qt
operator|::
name|black
decl_stmt|;
name|QColor
name|highlightedText
init|=
name|Qt
operator|::
name|black
decl_stmt|;
name|QColor
name|disabledText
init|=
name|QColor
argument_list|(
literal|190
argument_list|,
literal|190
argument_list|,
literal|190
argument_list|)
decl_stmt|;
name|QColor
name|button
argument_list|(
literal|241
argument_list|,
literal|241
argument_list|,
literal|241
argument_list|)
decl_stmt|;
name|QColor
name|shadow
argument_list|(
literal|201
argument_list|,
literal|201
argument_list|,
literal|201
argument_list|)
decl_stmt|;
name|QColor
name|highlight
argument_list|(
literal|148
argument_list|,
literal|210
argument_list|,
literal|231
argument_list|)
decl_stmt|;
name|QColor
name|disabledShadow
init|=
name|shadow
operator|.
name|lighter
argument_list|(
literal|150
argument_list|)
decl_stmt|;
name|m_defaultPalette
operator|=
name|QPalette
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
name|background
argument_list|,
name|light
argument_list|,
name|dark
argument_list|,
name|mid
argument_list|,
name|text
argument_list|,
name|base
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Midlight
argument_list|,
name|midLight
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Button
argument_list|,
name|button
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Shadow
argument_list|,
name|shadow
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|HighlightedText
argument_list|,
name|highlightedText
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|,
name|disabledText
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|,
name|disabledText
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|disabledText
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Base
argument_list|,
name|disabledBase
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Dark
argument_list|,
name|darkDisabled
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Shadow
argument_list|,
name|disabledShadow
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Active
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|,
name|highlight
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|,
name|highlight
argument_list|)
expr_stmt|;
name|m_defaultPalette
operator|.
name|setBrush
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|,
name|highlight
operator|.
name|lighter
argument_list|(
literal|150
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createPlatformMenuBar
name|QPlatformMenuBar
modifier|*
name|QAndroidPlatformTheme
operator|::
name|createPlatformMenuBar
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QAndroidPlatformMenuBar
return|;
block|}
end_function
begin_function
DECL|function|createPlatformMenu
name|QPlatformMenu
modifier|*
name|QAndroidPlatformTheme
operator|::
name|createPlatformMenu
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QAndroidPlatformMenu
return|;
block|}
end_function
begin_function
DECL|function|createPlatformMenuItem
name|QPlatformMenuItem
modifier|*
name|QAndroidPlatformTheme
operator|::
name|createPlatformMenuItem
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QAndroidPlatformMenuItem
return|;
block|}
end_function
begin_function
DECL|function|showPlatformMenuBar
name|void
name|QAndroidPlatformTheme
operator|::
name|showPlatformMenuBar
parameter_list|()
block|{
name|QtAndroidMenu
operator|::
name|openOptionsMenu
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paletteType
specifier|static
specifier|inline
name|int
name|paletteType
parameter_list|(
name|QPlatformTheme
operator|::
name|Palette
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QPlatformTheme
operator|::
name|ToolButtonPalette
case|:
case|case
name|QPlatformTheme
operator|::
name|ButtonPalette
case|:
return|return
name|QPlatformTheme
operator|::
name|ButtonPalette
return|;
case|case
name|QPlatformTheme
operator|::
name|CheckBoxPalette
case|:
return|return
name|QPlatformTheme
operator|::
name|CheckBoxPalette
return|;
case|case
name|QPlatformTheme
operator|::
name|RadioButtonPalette
case|:
return|return
name|QPlatformTheme
operator|::
name|RadioButtonPalette
return|;
case|case
name|QPlatformTheme
operator|::
name|ComboBoxPalette
case|:
return|return
name|QPlatformTheme
operator|::
name|ComboBoxPalette
return|;
case|case
name|QPlatformTheme
operator|::
name|TextEditPalette
case|:
case|case
name|QPlatformTheme
operator|::
name|TextLineEditPalette
case|:
return|return
name|QPlatformTheme
operator|::
name|TextLineEditPalette
return|;
case|case
name|QPlatformTheme
operator|::
name|ItemViewPalette
case|:
return|return
name|QPlatformTheme
operator|::
name|ItemViewPalette
return|;
default|default:
return|return
name|QPlatformTheme
operator|::
name|SystemPalette
return|;
block|}
block|}
end_function
begin_function
DECL|function|palette
specifier|const
name|QPalette
modifier|*
name|QAndroidPlatformTheme
operator|::
name|palette
parameter_list|(
name|Palette
name|type
parameter_list|)
specifier|const
block|{
name|QHash
argument_list|<
name|int
argument_list|,
name|QPalette
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|m_androidPlatformNativeInterface
operator|->
name|m_palettes
operator|.
name|find
argument_list|(
name|paletteType
argument_list|(
name|type
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|m_androidPlatformNativeInterface
operator|->
name|m_palettes
operator|.
name|end
argument_list|()
condition|)
return|return
operator|&
operator|(
name|it
operator|.
name|value
argument_list|()
operator|)
return|;
return|return
operator|&
name|m_defaultPalette
return|;
block|}
end_function
begin_function
DECL|function|fontType
specifier|static
specifier|inline
name|int
name|fontType
parameter_list|(
name|QPlatformTheme
operator|::
name|Font
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QPlatformTheme
operator|::
name|LabelFont
case|:
return|return
name|QPlatformTheme
operator|::
name|SystemFont
return|;
case|case
name|QPlatformTheme
operator|::
name|ToolButtonFont
case|:
return|return
name|QPlatformTheme
operator|::
name|PushButtonFont
return|;
default|default:
return|return
name|type
return|;
block|}
block|}
end_function
begin_function
DECL|function|font
specifier|const
name|QFont
modifier|*
name|QAndroidPlatformTheme
operator|::
name|font
parameter_list|(
name|Font
name|type
parameter_list|)
specifier|const
block|{
name|QHash
argument_list|<
name|int
argument_list|,
name|QFont
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|m_androidPlatformNativeInterface
operator|->
name|m_fonts
operator|.
name|find
argument_list|(
name|fontType
argument_list|(
name|type
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|m_androidPlatformNativeInterface
operator|->
name|m_fonts
operator|.
name|end
argument_list|()
condition|)
return|return
operator|&
operator|(
name|it
operator|.
name|value
argument_list|()
operator|)
return|;
comment|// default in case the style has not set a font
specifier|static
name|QFont
name|systemFont
argument_list|(
literal|"Roboto"
argument_list|,
literal|14.0
operator|*
literal|100
operator|/
literal|72
argument_list|)
decl_stmt|;
comment|// keep default size the same after changing from 100 dpi to 72 dpi
if|if
condition|(
name|type
operator|==
name|QPlatformTheme
operator|::
name|SystemFont
condition|)
return|return
operator|&
name|systemFont
return|;
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
specifier|static
specifier|const
name|QLatin1String
name|STYLES_PATH
argument_list|(
literal|"/data/data/org.kde.necessitas.ministro/files/dl/style/"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|QLatin1String
name|STYLE_FILE
argument_list|(
literal|"/style.json"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|themeHint
name|QVariant
name|QAndroidPlatformTheme
operator|::
name|themeHint
parameter_list|(
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
name|StyleNames
case|:
if|if
condition|(
name|qgetenv
argument_list|(
literal|"QT_USE_ANDROID_NATIVE_STYLE"
argument_list|)
operator|.
name|toInt
argument_list|()
operator|&&
operator|(
operator|!
name|qgetenv
argument_list|(
literal|"MINISTRO_ANDROID_STYLE_PATH"
argument_list|)
operator|.
name|isEmpty
argument_list|()
operator|||
name|QFileInfo
argument_list|(
name|STYLES_PATH
operator|+
name|QLatin1String
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_ANDROID_THEME_DISPLAY_DPI"
argument_list|)
argument_list|)
operator|+
name|STYLE_FILE
argument_list|)
operator|.
name|exists
argument_list|()
operator|)
condition|)
block|{
return|return
name|QStringList
argument_list|(
literal|"android"
argument_list|)
return|;
block|}
return|return
name|QStringList
argument_list|(
literal|"fusion"
argument_list|)
return|;
case|case
name|MouseDoubleClickDistance
case|:
block|{
name|int
name|minimumDistance
init|=
name|qgetenv
argument_list|(
literal|"QT_ANDROID_MINIMUM_MOUSE_DOUBLE_CLICK_DISTANCE"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|int
name|ret
init|=
name|minimumDistance
decl_stmt|;
name|QAndroidPlatformIntegration
modifier|*
name|platformIntegration
init|=
cast|static_cast
argument_list|<
name|QAndroidPlatformIntegration
operator|*
argument_list|>
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
argument_list|)
decl_stmt|;
name|QAndroidPlatformScreen
modifier|*
name|platformScreen
init|=
name|platformIntegration
operator|->
name|screen
argument_list|()
decl_stmt|;
if|if
condition|(
name|platformScreen
operator|!=
literal|0
condition|)
block|{
name|QScreen
modifier|*
name|screen
init|=
name|platformScreen
operator|->
name|screen
argument_list|()
decl_stmt|;
name|qreal
name|dotsPerInch
init|=
name|screen
operator|->
name|physicalDotsPerInch
argument_list|()
decl_stmt|;
comment|// Allow 15% of an inch between clicks when double clicking
name|int
name|distance
init|=
name|qRound
argument_list|(
name|dotsPerInch
operator|*
literal|0.15
argument_list|)
decl_stmt|;
if|if
condition|(
name|distance
operator|>
name|minimumDistance
condition|)
name|ret
operator|=
name|distance
expr_stmt|;
block|}
if|if
condition|(
name|ret
operator|>
literal|0
condition|)
return|return
name|ret
return|;
comment|// fall through
block|}
default|default:
return|return
name|QPlatformTheme
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
DECL|function|standardButtonText
name|QString
name|QAndroidPlatformTheme
operator|::
name|standardButtonText
parameter_list|(
name|int
name|button
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|button
condition|)
block|{
case|case
name|QPlatformDialogHelper
operator|::
name|Yes
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QAndroidPlatformTheme"
argument_list|,
literal|"Yes"
argument_list|)
return|;
case|case
name|QPlatformDialogHelper
operator|::
name|YesToAll
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QAndroidPlatformTheme"
argument_list|,
literal|"Yes to All"
argument_list|)
return|;
case|case
name|QPlatformDialogHelper
operator|::
name|No
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QAndroidPlatformTheme"
argument_list|,
literal|"No"
argument_list|)
return|;
case|case
name|QPlatformDialogHelper
operator|::
name|NoToAll
case|:
return|return
name|QCoreApplication
operator|::
name|translate
argument_list|(
literal|"QAndroidPlatformTheme"
argument_list|,
literal|"No to All"
argument_list|)
return|;
block|}
return|return
name|QPlatformTheme
operator|::
name|standardButtonText
argument_list|(
name|button
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|usePlatformNativeDialog
name|bool
name|QAndroidPlatformTheme
operator|::
name|usePlatformNativeDialog
parameter_list|(
name|QPlatformTheme
operator|::
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|type
operator|==
name|MessageDialog
condition|)
return|return
name|qgetenv
argument_list|(
literal|"QT_USE_ANDROID_NATIVE_DIALOGS"
argument_list|)
operator|.
name|toInt
argument_list|()
operator|==
literal|1
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createPlatformDialogHelper
name|QPlatformDialogHelper
modifier|*
name|QAndroidPlatformTheme
operator|::
name|createPlatformDialogHelper
parameter_list|(
name|QPlatformTheme
operator|::
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
name|MessageDialog
case|:
return|return
operator|new
name|QtAndroidDialogHelpers
operator|::
name|QAndroidPlatformMessageDialogHelper
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
