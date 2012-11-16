begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstylefactory.h"
end_include
begin_include
include|#
directive|include
file|"qstyleplugin.h"
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsstyle.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_FUSION
end_ifndef
begin_include
include|#
directive|include
file|"qfusionstyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_GTK
end_ifndef
begin_include
include|#
directive|include
file|"qgtkstyle_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSXP
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsxpstyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSVISTA
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsvistastyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSCE
end_ifndef
begin_include
include|#
directive|include
file|"qwindowscestyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSMOBILE
end_ifndef
begin_include
include|#
directive|include
file|"qwindowsmobilestyle.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_MAC
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qmacstyle_mac.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QStyleFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/styles"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
comment|/*!     \class QStyleFactory     \brief The QStyleFactory class creates QStyle objects.      \ingroup appearance     \inmodule QtWidgets      The QStyle class is an abstract base class that encapsulates the     look and feel of a GUI. QStyleFactory creates a QStyle object     using the create() function and a key identifying the style. The     styles are either built-in or dynamically loaded from a style     plugin (see QStylePlugin).      The valid keys can be retrieved using the keys()     function. Typically they include "windows" and "fusion".     Depending on the platform, "windowsxp", "windowsvista", "gtk"     and "macintosh" may be available.     Note that keys are case insensitive.      \sa QStyle */
comment|/*!     Creates and returns a QStyle object that matches the given \a key, or     returns 0 if no matching style is found.      Both built-in styles and styles from style plugins are queried for a     matching style.      \note The keys used are case insensitive.      \sa keys() */
DECL|function|create
name|QStyle
modifier|*
name|QStyleFactory
operator|::
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
argument_list|{
name|QStyle
operator|*
name|ret
operator|=
literal|0
argument_list|;
name|QString
name|style
operator|=
name|key
operator|.
name|toLower
argument_list|()
argument_list|;
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWS
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windows"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSCE
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windowsce"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsCEStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSMOBILE
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windowsmobile"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsMobileStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSXP
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windowsxp"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsXPStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSVISTA
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"windowsvista"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QWindowsVistaStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_FUSION
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"fusion"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QFusionStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_GTK
argument_list|if
operator|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"gtk"
argument_list|)
operator|||
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"gtk+"
argument_list|)
operator|)
name|ret
operator|=
operator|new
name|QGtkStyle
argument_list|;     else
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_STYLE_MAC
argument_list|if
operator|(
name|style
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"macintosh"
argument_list|)
argument_list|)
operator|)
block|{
name|ret
operator|=
operator|new
name|QMacStyle
block|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
if|if
condition|(
name|style
operator|==
name|QLatin1String
argument_list|(
literal|"macintosh"
argument_list|)
condition|)
name|style
operator|+=
name|QLatin1String
argument_list|(
literal|" (aqua)"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
else|else
endif|#
directive|endif
block|{ }
comment|// Keep these here - they make the #ifdefery above work
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
if|if
condition|(
operator|!
name|ret
condition|)
name|ret
operator|=
name|qLoadPlugin
argument_list|<
name|QStyle
argument_list|,
name|QStylePlugin
argument_list|>
argument_list|(
name|loader
argument_list|()
argument_list|,
name|style
argument_list|)
expr_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|if
condition|(
name|ret
condition|)
name|ret
operator|->
name|setObjectName
argument_list|(
name|style
argument_list|)
expr_stmt|;
end_if
begin_return
return|return
name|ret
return|;
end_return
begin_comment
unit|}
comment|/*!     Returns the list of valid keys, i.e. the keys this factory can     create styles for.      \sa create() */
end_comment
begin_macro
unit|QStringList
DECL|function|keys
name|QStyleFactory
end_macro
begin_expr_stmt
DECL|function|keys
operator|::
name|keys
operator|(
operator|)
block|{
name|QStringList
name|list
block|;
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
typedef|typedef
name|QMultiMap
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
name|PluginKeyMap
typedef|;
specifier|const
name|PluginKeyMap
name|keyMap
operator|=
name|loader
argument_list|()
operator|->
name|keyMap
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|PluginKeyMap
operator|::
name|const_iterator
name|cend
init|=
name|keyMap
operator|.
name|constEnd
argument_list|()
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|PluginKeyMap
operator|::
name|const_iterator
name|it
init|=
name|keyMap
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
name|list
operator|.
name|append
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
end_for
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWS
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"Windows"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Windows"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSCE
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WindowsCE"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"WindowsCE"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSMOBILE
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WindowsMobile"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"WindowsMobile"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSXP
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WindowsXP"
argument_list|)
argument_list|)
operator|&&
operator|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_XP
operator|&&
operator|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|&
name|QSysInfo
operator|::
name|WV_NT_based
operator|)
operator|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"WindowsXP"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSVISTA
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"WindowsVista"
argument_list|)
argument_list|)
operator|&&
operator|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|>=
name|QSysInfo
operator|::
name|WV_VISTA
operator|&&
operator|(
name|QSysInfo
operator|::
name|WindowsVersion
operator|&
name|QSysInfo
operator|::
name|WV_NT_based
operator|)
operator|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"WindowsVista"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_GTK
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"GTK+"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"GTK+"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_FUSION
end_ifndef
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"Fusion"
argument_list|)
argument_list|)
condition|)
name|list
operator|<<
name|QLatin1String
argument_list|(
literal|"Fusion"
argument_list|)
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_MAC
end_ifndef
begin_decl_stmt
name|QString
name|mstyle
init|=
name|QLatin1String
argument_list|(
literal|"Macintosh"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_WS_MAC
end_ifdef
begin_expr_stmt
name|mstyle
operator|+=
name|QLatin1String
argument_list|(
literal|" (aqua)"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|if
condition|(
operator|!
name|list
operator|.
name|contains
argument_list|(
name|mstyle
argument_list|)
condition|)
name|list
operator|<<
name|mstyle
expr_stmt|;
end_if
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
name|list
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
