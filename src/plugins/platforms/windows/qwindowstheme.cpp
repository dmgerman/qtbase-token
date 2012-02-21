begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowstheme.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdialoghelpers.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qt_windows.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSysInfo>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPalette>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator <<
specifier|static
specifier|inline
name|QTextStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QTextStream
modifier|&
name|str
parameter_list|,
specifier|const
name|QColor
modifier|&
name|c
parameter_list|)
block|{
name|str
operator|.
name|setIntegerBase
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|str
operator|.
name|setFieldWidth
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|str
operator|.
name|setPadChar
argument_list|(
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|<<
literal|" rgb: #"
operator|<<
name|c
operator|.
name|red
argument_list|()
operator|<<
name|c
operator|.
name|green
argument_list|()
operator|<<
name|c
operator|.
name|blue
argument_list|()
expr_stmt|;
name|str
operator|.
name|setIntegerBase
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|str
operator|.
name|setFieldWidth
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|paletteToString
specifier|static
specifier|inline
name|QString
name|paletteToString
parameter_list|(
specifier|const
name|QPalette
modifier|&
name|palette
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|result
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|"text="
operator|<<
name|palette
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|WindowText
argument_list|)
operator|<<
literal|" background="
operator|<<
name|palette
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|mixColors
specifier|static
specifier|inline
name|QColor
name|mixColors
parameter_list|(
specifier|const
name|QColor
modifier|&
name|c1
parameter_list|,
specifier|const
name|QColor
modifier|&
name|c2
parameter_list|)
block|{
return|return
name|QColor
argument_list|(
operator|(
name|c1
operator|.
name|red
argument_list|()
operator|+
name|c2
operator|.
name|red
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
operator|(
name|c1
operator|.
name|green
argument_list|()
operator|+
name|c2
operator|.
name|green
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
operator|(
name|c1
operator|.
name|blue
argument_list|()
operator|+
name|c2
operator|.
name|blue
argument_list|()
operator|)
operator|/
literal|2
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getSysColor
specifier|static
specifier|inline
name|QColor
name|getSysColor
parameter_list|(
name|int
name|index
parameter_list|)
block|{
return|return
name|qColorToCOLORREF
argument_list|(
name|GetSysColor
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|systemPalette
specifier|static
specifier|inline
name|QPalette
name|systemPalette
parameter_list|()
block|{
name|QPalette
name|result
decl_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|WindowText
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_WINDOWTEXT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Button
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_BTNFACE
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Light
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_BTNHIGHLIGHT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_BTNSHADOW
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Mid
argument_list|,
name|result
operator|.
name|button
argument_list|()
operator|.
name|color
argument_list|()
operator|.
name|darker
argument_list|(
literal|150
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_WINDOWTEXT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|BrightText
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_BTNHIGHLIGHT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_WINDOW
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Window
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_BTNFACE
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_BTNTEXT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Midlight
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_3DLIGHT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Shadow
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_3DDKSHADOW
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Highlight
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_HIGHLIGHT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|HighlightedText
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_HIGHLIGHTTEXT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Link
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|LinkVisited
argument_list|,
name|Qt
operator|::
name|magenta
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Button
argument_list|,
name|result
operator|.
name|button
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Window
argument_list|,
name|result
operator|.
name|background
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Light
argument_list|,
name|result
operator|.
name|light
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Dark
argument_list|,
name|result
operator|.
name|dark
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|.
name|midlight
argument_list|()
operator|==
name|result
operator|.
name|button
argument_list|()
condition|)
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Midlight
argument_list|,
name|result
operator|.
name|button
argument_list|()
operator|.
name|color
argument_list|()
operator|.
name|lighter
argument_list|(
literal|110
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|.
name|background
argument_list|()
operator|!=
name|result
operator|.
name|base
argument_list|()
condition|)
block|{
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|,
name|result
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Window
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|HighlightedText
argument_list|,
name|result
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Inactive
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QColor
name|disabled
init|=
name|mixColors
argument_list|(
name|result
operator|.
name|foreground
argument_list|()
operator|.
name|color
argument_list|()
argument_list|,
name|result
operator|.
name|button
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
decl_stmt|;
name|result
operator|.
name|setColorGroup
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|result
operator|.
name|foreground
argument_list|()
argument_list|,
name|result
operator|.
name|button
argument_list|()
argument_list|,
name|result
operator|.
name|light
argument_list|()
argument_list|,
name|result
operator|.
name|dark
argument_list|()
argument_list|,
name|result
operator|.
name|mid
argument_list|()
argument_list|,
name|result
operator|.
name|text
argument_list|()
argument_list|,
name|result
operator|.
name|brightText
argument_list|()
argument_list|,
name|result
operator|.
name|base
argument_list|()
argument_list|,
name|result
operator|.
name|background
argument_list|()
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|,
name|disabled
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|,
name|disabled
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|disabled
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Highlight
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_HIGHLIGHT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|HighlightedText
argument_list|,
name|getSysColor
argument_list|(
name|COLOR_HIGHLIGHTTEXT
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Base
argument_list|,
name|result
operator|.
name|background
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|toolTipPalette
name|QPalette
name|toolTipPalette
parameter_list|(
specifier|const
name|QPalette
modifier|&
name|systemPalette
parameter_list|)
block|{
name|QPalette
name|result
argument_list|(
name|systemPalette
argument_list|)
decl_stmt|;
specifier|const
name|QColor
name|tipBgColor
argument_list|(
name|getSysColor
argument_list|(
name|COLOR_INFOBK
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QColor
name|tipTextColor
argument_list|(
name|getSysColor
argument_list|(
name|COLOR_INFOTEXT
argument_list|)
argument_list|)
decl_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|Button
argument_list|,
name|tipBgColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|Window
argument_list|,
name|tipBgColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|,
name|tipTextColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|,
name|tipTextColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|tipTextColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|Button
argument_list|,
name|tipBgColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|Window
argument_list|,
name|tipBgColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|,
name|tipTextColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|,
name|tipTextColor
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|All
argument_list|,
name|QPalette
operator|::
name|ButtonText
argument_list|,
name|tipTextColor
argument_list|)
expr_stmt|;
specifier|const
name|QColor
name|disabled
init|=
name|mixColors
argument_list|(
name|result
operator|.
name|foreground
argument_list|()
operator|.
name|color
argument_list|()
argument_list|,
name|result
operator|.
name|button
argument_list|()
operator|.
name|color
argument_list|()
argument_list|)
decl_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|WindowText
argument_list|,
name|disabled
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Text
argument_list|,
name|disabled
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|Base
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|result
operator|.
name|setColor
argument_list|(
name|QPalette
operator|::
name|Disabled
argument_list|,
name|QPalette
operator|::
name|BrightText
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|booleanSystemParametersInfo
specifier|static
specifier|inline
name|bool
name|booleanSystemParametersInfo
parameter_list|(
name|UINT
name|what
parameter_list|,
name|bool
name|defaultValue
parameter_list|)
block|{
name|BOOL
name|result
decl_stmt|;
if|if
condition|(
name|SystemParametersInfo
argument_list|(
name|what
argument_list|,
literal|0
argument_list|,
operator|&
name|result
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|result
condition|?
literal|true
else|:
literal|false
return|;
return|return
name|defaultValue
return|;
block|}
end_function
begin_function
DECL|function|dWordSystemParametersInfo
specifier|static
specifier|inline
name|bool
name|dWordSystemParametersInfo
parameter_list|(
name|UINT
name|what
parameter_list|,
name|DWORD
name|defaultValue
parameter_list|)
block|{
name|DWORD
name|result
decl_stmt|;
if|if
condition|(
name|SystemParametersInfo
argument_list|(
name|what
argument_list|,
literal|0
argument_list|,
operator|&
name|result
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|result
return|;
return|return
name|defaultValue
return|;
block|}
end_function
begin_constructor
DECL|function|QWindowsTheme
name|QWindowsTheme
operator|::
name|QWindowsTheme
parameter_list|()
block|{
name|qFill
argument_list|(
name|m_palettes
argument_list|,
name|m_palettes
operator|+
name|NPalettes
argument_list|,
cast|static_cast
argument_list|<
name|QPalette
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsTheme
name|QWindowsTheme
operator|::
name|~
name|QWindowsTheme
parameter_list|()
block|{
name|clearPalettes
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|clearPalettes
name|void
name|QWindowsTheme
operator|::
name|clearPalettes
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|m_palettes
argument_list|,
name|m_palettes
operator|+
name|NPalettes
argument_list|)
expr_stmt|;
name|qFill
argument_list|(
name|m_palettes
argument_list|,
name|m_palettes
operator|+
name|NPalettes
argument_list|,
cast|static_cast
argument_list|<
name|QPalette
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|instance
name|QWindowsTheme
modifier|*
name|QWindowsTheme
operator|::
name|instance
parameter_list|()
block|{
return|return
cast|static_cast
argument_list|<
name|QWindowsTheme
operator|*
argument_list|>
argument_list|(
name|QWindowsIntegration
operator|::
name|instance
argument_list|()
operator|->
name|platformTheme
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|iconThemeSearchPaths
specifier|static
specifier|inline
name|QStringList
name|iconThemeSearchPaths
parameter_list|()
block|{
specifier|const
name|QFileInfo
name|appDir
argument_list|(
name|QCoreApplication
operator|::
name|applicationDirPath
argument_list|()
operator|+
name|QStringLiteral
argument_list|(
literal|"/icons"
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|appDir
operator|.
name|isDir
argument_list|()
condition|?
name|QStringList
argument_list|(
name|appDir
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
else|:
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|styleNames
specifier|static
specifier|inline
name|QStringList
name|styleNames
parameter_list|()
block|{
name|QStringList
name|result
decl_stmt|;
if|if
condition|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_VISTA
condition|)
name|result
operator|.
name|append
argument_list|(
name|QStringLiteral
argument_list|(
literal|"WindowsVista"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_XP
condition|)
name|result
operator|.
name|append
argument_list|(
name|QStringLiteral
argument_list|(
literal|"WindowsXP"
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|append
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Windows"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|themeHint
name|QVariant
name|QWindowsTheme
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
name|SystemIconThemeName
case|:
break|break;
case|case
name|IconThemeSearchPaths
case|:
return|return
name|QVariant
argument_list|(
name|iconThemeSearchPaths
argument_list|()
argument_list|)
return|;
break|break;
case|case
name|StyleNames
case|:
return|return
name|QVariant
argument_list|(
name|styleNames
argument_list|()
argument_list|)
return|;
case|case
name|TextCursorWidth
case|:
return|return
name|QVariant
argument_list|(
name|int
argument_list|(
name|dWordSystemParametersInfo
argument_list|(
name|SPI_GETCARETWIDTH
argument_list|,
literal|1u
argument_list|)
argument_list|)
argument_list|)
return|;
case|case
name|DropShadow
case|:
return|return
name|QVariant
argument_list|(
name|booleanSystemParametersInfo
argument_list|(
name|SPI_GETDROPSHADOW
argument_list|,
literal|false
argument_list|)
argument_list|)
return|;
case|case
name|MaximumScrollBarDragDistance
case|:
return|return
name|QVariant
argument_list|(
name|qRound
argument_list|(
name|qreal
argument_list|(
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|defaultDPI
argument_list|()
argument_list|)
operator|*
literal|1.375
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|refresh
name|void
name|QWindowsTheme
operator|::
name|refresh
parameter_list|()
block|{
name|clearPalettes
argument_list|()
expr_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|desktopSettingsAware
argument_list|()
condition|)
block|{
name|m_palettes
index|[
name|SystemPalette
index|]
operator|=
operator|new
name|QPalette
argument_list|(
name|systemPalette
argument_list|()
argument_list|)
expr_stmt|;
name|m_palettes
index|[
name|ToolTipPalette
index|]
operator|=
operator|new
name|QPalette
argument_list|(
name|toolTipPalette
argument_list|(
operator|*
name|m_palettes
index|[
name|SystemPalette
index|]
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseTheming
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|'\n'
operator|<<
literal|"  system="
operator|<<
name|paletteToString
argument_list|(
operator|*
name|m_palettes
index|[
name|SystemPalette
index|]
argument_list|)
operator|<<
literal|"  tooltip="
operator|<<
name|paletteToString
argument_list|(
operator|*
name|m_palettes
index|[
name|ToolTipPalette
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|usePlatformNativeDialog
name|bool
name|QWindowsTheme
operator|::
name|usePlatformNativeDialog
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
return|return
name|QWindowsDialogs
operator|::
name|useHelper
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformDialogHelper
name|QPlatformDialogHelper
modifier|*
name|QWindowsTheme
operator|::
name|createPlatformDialogHelper
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
return|return
name|QWindowsDialogs
operator|::
name|createHelper
argument_list|(
name|type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|windowsThemeChanged
name|void
name|QWindowsTheme
operator|::
name|windowsThemeChanged
parameter_list|(
name|QWindow
modifier|*
comment|/* window */
parameter_list|)
block|{
name|refresh
argument_list|()
expr_stmt|;
comment|// QWindowSystemInterface::handleThemeChange(window);
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
