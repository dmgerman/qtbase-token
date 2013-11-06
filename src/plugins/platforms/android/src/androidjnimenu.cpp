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
file|"androidjnimain.h"
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
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_include
include|#
directive|include
file|<QQueue>
end_include
begin_include
include|#
directive|include
file|<QWindow>
end_include
begin_using
using|using
namespace|namespace
name|QtAndroid
namespace|;
end_using
begin_namespace
DECL|namespace|QtAndroidMenu
namespace|namespace
name|QtAndroidMenu
block|{
DECL|member|pendingContextMenus
specifier|static
name|QQueue
argument_list|<
name|QAndroidPlatformMenu
modifier|*
argument_list|>
name|pendingContextMenus
decl_stmt|;
DECL|member|visibleMenu
specifier|static
name|QAndroidPlatformMenu
modifier|*
name|visibleMenu
init|=
literal|0
decl_stmt|;
specifier|static
name|QMutex
name|visibleMenuMutex
parameter_list|(
name|QMutex
operator|::
name|Recursive
parameter_list|)
function_decl|;
DECL|member|menuBars
specifier|static
name|QSet
argument_list|<
name|QAndroidPlatformMenuBar
modifier|*
argument_list|>
name|menuBars
decl_stmt|;
DECL|member|visibleMenuBar
specifier|static
name|QAndroidPlatformMenuBar
modifier|*
name|visibleMenuBar
init|=
literal|0
decl_stmt|;
DECL|member|activeTopLevelWindow
specifier|static
name|QWindow
modifier|*
name|activeTopLevelWindow
init|=
literal|0
decl_stmt|;
specifier|static
name|QMutex
name|menuBarMutex
parameter_list|(
name|QMutex
operator|::
name|Recursive
parameter_list|)
function_decl|;
DECL|member|openContextMenuMethodID
specifier|static
name|jmethodID
name|openContextMenuMethodID
init|=
literal|0
decl_stmt|;
DECL|member|closeContextMenuMethodID
specifier|static
name|jmethodID
name|closeContextMenuMethodID
init|=
literal|0
decl_stmt|;
DECL|member|resetOptionsMenuMethodID
specifier|static
name|jmethodID
name|resetOptionsMenuMethodID
init|=
literal|0
decl_stmt|;
DECL|member|clearMenuMethodID
specifier|static
name|jmethodID
name|clearMenuMethodID
init|=
literal|0
decl_stmt|;
DECL|member|addMenuItemMethodID
specifier|static
name|jmethodID
name|addMenuItemMethodID
init|=
literal|0
decl_stmt|;
DECL|member|menuNoneValue
specifier|static
name|int
name|menuNoneValue
init|=
literal|0
decl_stmt|;
DECL|member|setHeaderTitleContextMenuMethodID
specifier|static
name|jmethodID
name|setHeaderTitleContextMenuMethodID
init|=
literal|0
decl_stmt|;
DECL|member|setCheckableMenuItemMethodID
specifier|static
name|jmethodID
name|setCheckableMenuItemMethodID
init|=
literal|0
decl_stmt|;
DECL|member|setCheckedMenuItemMethodID
specifier|static
name|jmethodID
name|setCheckedMenuItemMethodID
init|=
literal|0
decl_stmt|;
DECL|member|setEnabledMenuItemMethodID
specifier|static
name|jmethodID
name|setEnabledMenuItemMethodID
init|=
literal|0
decl_stmt|;
DECL|member|setIconMenuItemMethodID
specifier|static
name|jmethodID
name|setIconMenuItemMethodID
init|=
literal|0
decl_stmt|;
DECL|member|setVisibleMenuItemMethodID
specifier|static
name|jmethodID
name|setVisibleMenuItemMethodID
init|=
literal|0
decl_stmt|;
DECL|function|resetMenuBar
name|void
name|resetMenuBar
parameter_list|()
block|{
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
name|env
operator|.
name|jniEnv
condition|)
name|env
operator|.
name|jniEnv
operator|->
name|CallStaticVoidMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|resetOptionsMenuMethodID
argument_list|)
expr_stmt|;
block|}
DECL|function|showContextMenu
name|void
name|showContextMenu
parameter_list|(
name|QAndroidPlatformMenu
modifier|*
name|menu
parameter_list|,
name|JNIEnv
modifier|*
name|env
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|visibleMenuMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|visibleMenu
condition|)
block|{
name|pendingContextMenus
operator|.
name|enqueue
argument_list|(
name|menu
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|visibleMenu
operator|=
name|menu
expr_stmt|;
name|menu
operator|->
name|aboutToShow
argument_list|()
expr_stmt|;
if|if
condition|(
name|env
condition|)
block|{
name|env
operator|->
name|CallStaticVoidMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|openContextMenuMethodID
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|AttachedJNIEnv
name|aenv
decl_stmt|;
if|if
condition|(
name|aenv
operator|.
name|jniEnv
condition|)
name|aenv
operator|.
name|jniEnv
operator|->
name|CallStaticVoidMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|openContextMenuMethodID
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|function|hideContextMenu
name|void
name|hideContextMenu
parameter_list|(
name|QAndroidPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|visibleMenuMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|visibleMenu
operator|==
name|menu
condition|)
block|{
name|AttachedJNIEnv
name|env
decl_stmt|;
if|if
condition|(
name|env
operator|.
name|jniEnv
condition|)
name|env
operator|.
name|jniEnv
operator|->
name|CallStaticVoidMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
name|openContextMenuMethodID
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|pendingContextMenus
operator|.
name|removeOne
argument_list|(
name|menu
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|syncMenu
name|void
name|syncMenu
parameter_list|(
name|QAndroidPlatformMenu
modifier|*
comment|/*menu*/
parameter_list|)
block|{
comment|//        QMutexLocker lock(&visibleMenuMutex);
comment|//        if (visibleMenu == menu)
comment|//        {
comment|//            hideContextMenu(menu);
comment|//            showContextMenu(menu);
comment|//        }
block|}
DECL|function|androidPlatformMenuDestroyed
name|void
name|androidPlatformMenuDestroyed
parameter_list|(
name|QAndroidPlatformMenu
modifier|*
name|menu
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|visibleMenuMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|visibleMenu
operator|==
name|menu
condition|)
name|visibleMenu
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|setMenuBar
name|void
name|setMenuBar
parameter_list|(
name|QAndroidPlatformMenuBar
modifier|*
name|menuBar
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
name|activeTopLevelWindow
operator|==
name|window
operator|&&
name|visibleMenuBar
operator|!=
name|menuBar
condition|)
block|{
name|visibleMenuBar
operator|=
name|menuBar
expr_stmt|;
name|resetMenuBar
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|setActiveTopLevelWindow
name|void
name|setActiveTopLevelWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|window
operator|->
name|flags
argument_list|()
decl_stmt|;
name|bool
name|isNonRegularWindow
init|=
name|flags
operator|&
operator|(
name|Qt
operator|::
name|Desktop
operator||
name|Qt
operator|::
name|Popup
operator||
name|Qt
operator|::
name|Dialog
operator||
name|Qt
operator|::
name|Sheet
operator|)
operator|&
operator|~
name|Qt
operator|::
name|Window
decl_stmt|;
if|if
condition|(
name|isNonRegularWindow
condition|)
return|return;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|menuBarMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|activeTopLevelWindow
operator|==
name|window
condition|)
return|return;
name|visibleMenuBar
operator|=
literal|0
expr_stmt|;
name|activeTopLevelWindow
operator|=
name|window
expr_stmt|;
foreach|foreach
control|(
name|QAndroidPlatformMenuBar
modifier|*
name|menuBar
decl|,
name|menuBars
control|)
block|{
if|if
condition|(
name|menuBar
operator|->
name|parentWindow
argument_list|()
operator|==
name|window
condition|)
block|{
name|visibleMenuBar
operator|=
name|menuBar
expr_stmt|;
break|break;
block|}
block|}
name|resetMenuBar
argument_list|()
expr_stmt|;
block|}
DECL|function|addMenuBar
name|void
name|addMenuBar
parameter_list|(
name|QAndroidPlatformMenuBar
modifier|*
name|menuBar
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|menuBarMutex
argument_list|)
decl_stmt|;
name|menuBars
operator|.
name|insert
argument_list|(
name|menuBar
argument_list|)
expr_stmt|;
block|}
DECL|function|removeMenuBar
name|void
name|removeMenuBar
parameter_list|(
name|QAndroidPlatformMenuBar
modifier|*
name|menuBar
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|menuBarMutex
argument_list|)
decl_stmt|;
name|menuBars
operator|.
name|remove
argument_list|(
name|menuBar
argument_list|)
expr_stmt|;
if|if
condition|(
name|visibleMenuBar
operator|==
name|menuBar
condition|)
block|{
name|visibleMenuBar
operator|=
literal|0
expr_stmt|;
name|resetMenuBar
argument_list|()
expr_stmt|;
block|}
block|}
DECL|function|removeAmpersandEscapes
specifier|static
name|QString
name|removeAmpersandEscapes
parameter_list|(
name|QString
name|s
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|s
operator|.
name|size
argument_list|()
condition|)
block|{
operator|++
name|i
expr_stmt|;
if|if
condition|(
name|s
operator|.
name|at
argument_list|(
name|i
operator|-
literal|1
argument_list|)
operator|!=
name|QLatin1Char
argument_list|(
literal|'&'
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|i
operator|<
name|s
operator|.
name|size
argument_list|()
operator|&&
name|s
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'&'
argument_list|)
condition|)
operator|++
name|i
expr_stmt|;
name|s
operator|.
name|remove
argument_list|(
name|i
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|s
operator|.
name|trimmed
argument_list|()
return|;
block|}
DECL|function|fillMenuItem
specifier|static
name|void
name|fillMenuItem
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
name|menuItem
parameter_list|,
name|bool
name|checkable
parameter_list|,
name|bool
name|checked
parameter_list|,
name|bool
name|enabled
parameter_list|,
name|bool
name|visible
parameter_list|,
specifier|const
name|QIcon
modifier|&
name|icon
init|=
name|QIcon
argument_list|()
parameter_list|)
block|{
name|env
operator|->
name|CallObjectMethod
argument_list|(
name|menuItem
argument_list|,
name|setCheckableMenuItemMethodID
argument_list|,
name|checkable
argument_list|)
expr_stmt|;
name|env
operator|->
name|CallObjectMethod
argument_list|(
name|menuItem
argument_list|,
name|setCheckedMenuItemMethodID
argument_list|,
name|checked
argument_list|)
expr_stmt|;
name|env
operator|->
name|CallObjectMethod
argument_list|(
name|menuItem
argument_list|,
name|setEnabledMenuItemMethodID
argument_list|,
name|enabled
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|icon
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// isNull() only checks the d pointer, not the actual image data.
name|int
name|sz
init|=
name|qMax
argument_list|(
literal|36
argument_list|,
name|qgetenv
argument_list|(
literal|"QT_ANDROID_APP_ICON_SIZE"
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|QImage
name|img
init|=
name|icon
operator|.
name|pixmap
argument_list|(
name|QSize
argument_list|(
name|sz
argument_list|,
name|sz
argument_list|)
argument_list|,
name|enabled
condition|?
name|QIcon
operator|::
name|Normal
else|:
name|QIcon
operator|::
name|Disabled
argument_list|,
name|QIcon
operator|::
name|On
argument_list|)
operator|.
name|toImage
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|img
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// Make sure we have a valid image.
name|env
operator|->
name|CallObjectMethod
argument_list|(
name|menuItem
argument_list|,
name|setIconMenuItemMethodID
argument_list|,
name|createBitmapDrawable
argument_list|(
name|createBitmap
argument_list|(
name|img
argument_list|,
name|env
argument_list|)
argument_list|,
name|env
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|env
operator|->
name|CallObjectMethod
argument_list|(
name|menuItem
argument_list|,
name|setVisibleMenuItemMethodID
argument_list|,
name|visible
argument_list|)
expr_stmt|;
block|}
DECL|function|addAllMenuItemsToMenu
specifier|static
name|int
name|addAllMenuItemsToMenu
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
name|menu
parameter_list|,
name|QAndroidPlatformMenu
modifier|*
name|platformMenu
parameter_list|)
block|{
name|int
name|order
init|=
literal|0
decl_stmt|;
name|QMutexLocker
name|lock
argument_list|(
name|platformMenu
operator|->
name|menuItemsMutex
argument_list|()
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QAndroidPlatformMenuItem
modifier|*
name|item
decl|,
name|platformMenu
operator|->
name|menuItems
argument_list|()
control|)
block|{
if|if
condition|(
name|item
operator|->
name|isSeparator
argument_list|()
condition|)
continue|continue;
name|QString
name|itemText
init|=
name|removeAmpersandEscapes
argument_list|(
name|item
operator|->
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|jstring
name|jtext
init|=
name|env
operator|->
name|NewString
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|jchar
operator|*
argument_list|>
argument_list|(
name|itemText
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|itemText
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|jobject
name|menuItem
init|=
name|env
operator|->
name|CallObjectMethod
argument_list|(
name|menu
argument_list|,
name|addMenuItemMethodID
argument_list|,
name|menuNoneValue
argument_list|,
name|int
argument_list|(
name|item
operator|->
name|tag
argument_list|()
argument_list|)
argument_list|,
name|order
operator|++
argument_list|,
name|jtext
argument_list|)
decl_stmt|;
name|env
operator|->
name|DeleteLocalRef
argument_list|(
name|jtext
argument_list|)
expr_stmt|;
name|fillMenuItem
argument_list|(
name|env
argument_list|,
name|menuItem
argument_list|,
name|item
operator|->
name|isCheckable
argument_list|()
argument_list|,
name|item
operator|->
name|isChecked
argument_list|()
argument_list|,
name|item
operator|->
name|isEnabled
argument_list|()
argument_list|,
name|item
operator|->
name|isVisible
argument_list|()
argument_list|,
name|item
operator|->
name|icon
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|order
return|;
block|}
DECL|function|onPrepareOptionsMenu
specifier|static
name|jboolean
name|onPrepareOptionsMenu
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jobject
name|menu
parameter_list|)
block|{
name|env
operator|->
name|CallVoidMethod
argument_list|(
name|menu
argument_list|,
name|clearMenuMethodID
argument_list|)
expr_stmt|;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|menuBarMutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|visibleMenuBar
condition|)
return|return
name|JNI_FALSE
return|;
specifier|const
name|QAndroidPlatformMenuBar
operator|::
name|PlatformMenusType
modifier|&
name|menus
init|=
name|visibleMenuBar
operator|->
name|menus
argument_list|()
decl_stmt|;
name|int
name|order
init|=
literal|0
decl_stmt|;
name|QMutexLocker
name|lockMenuBarMutex
argument_list|(
name|visibleMenuBar
operator|->
name|menusListMutex
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|menus
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
block|{
comment|// Expand the menu
name|order
operator|=
name|addAllMenuItemsToMenu
argument_list|(
name|env
argument_list|,
name|menu
argument_list|,
cast|static_cast
argument_list|<
name|QAndroidPlatformMenu
operator|*
argument_list|>
argument_list|(
name|menus
operator|.
name|front
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
foreach|foreach
control|(
name|QAndroidPlatformMenu
modifier|*
name|item
decl|,
name|menus
control|)
block|{
name|QString
name|itemText
init|=
name|removeAmpersandEscapes
argument_list|(
name|item
operator|->
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|jstring
name|jtext
init|=
name|env
operator|->
name|NewString
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|jchar
operator|*
argument_list|>
argument_list|(
name|itemText
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|itemText
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|jobject
name|menuItem
init|=
name|env
operator|->
name|CallObjectMethod
argument_list|(
name|menu
argument_list|,
name|addMenuItemMethodID
argument_list|,
name|menuNoneValue
argument_list|,
name|int
argument_list|(
name|item
operator|->
name|tag
argument_list|()
argument_list|)
argument_list|,
name|order
operator|++
argument_list|,
name|jtext
argument_list|)
decl_stmt|;
name|env
operator|->
name|DeleteLocalRef
argument_list|(
name|jtext
argument_list|)
expr_stmt|;
name|fillMenuItem
argument_list|(
name|env
argument_list|,
name|menuItem
argument_list|,
literal|false
argument_list|,
literal|false
argument_list|,
name|item
operator|->
name|isEnabled
argument_list|()
argument_list|,
name|item
operator|->
name|isVisible
argument_list|()
argument_list|,
name|item
operator|->
name|icon
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|order
condition|?
name|JNI_TRUE
else|:
name|JNI_FALSE
return|;
block|}
DECL|function|onOptionsItemSelected
specifier|static
name|jboolean
name|onOptionsItemSelected
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
name|menuId
parameter_list|,
name|jboolean
name|checked
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|menuBarMutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|visibleMenuBar
condition|)
return|return
name|JNI_FALSE
return|;
specifier|const
name|QAndroidPlatformMenuBar
operator|::
name|PlatformMenusType
modifier|&
name|menus
init|=
name|visibleMenuBar
operator|->
name|menus
argument_list|()
decl_stmt|;
if|if
condition|(
name|menus
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
block|{
comment|// Expanded menu
name|QAndroidPlatformMenuItem
modifier|*
name|item
init|=
cast|static_cast
argument_list|<
name|QAndroidPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|menus
operator|.
name|front
argument_list|()
operator|->
name|menuItemForTag
argument_list|(
name|menuId
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
if|if
condition|(
name|item
operator|->
name|menu
argument_list|()
condition|)
block|{
name|showContextMenu
argument_list|(
name|item
operator|->
name|menu
argument_list|()
argument_list|,
name|env
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|item
operator|->
name|isCheckable
argument_list|()
condition|)
name|item
operator|->
name|setChecked
argument_list|(
name|checked
argument_list|)
expr_stmt|;
name|item
operator|->
name|activated
argument_list|()
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|QAndroidPlatformMenu
modifier|*
name|menu
init|=
cast|static_cast
argument_list|<
name|QAndroidPlatformMenu
operator|*
argument_list|>
argument_list|(
name|visibleMenuBar
operator|->
name|menuForTag
argument_list|(
name|menuId
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|menu
condition|)
name|showContextMenu
argument_list|(
name|menu
argument_list|,
name|env
argument_list|)
expr_stmt|;
block|}
return|return
name|JNI_TRUE
return|;
block|}
DECL|function|onOptionsMenuClosed
specifier|static
name|void
name|onOptionsMenuClosed
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jobject
comment|/*menu*/
parameter_list|)
block|{     }
DECL|function|onCreateContextMenu
specifier|static
name|void
name|onCreateContextMenu
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jobject
name|menu
parameter_list|)
block|{
name|env
operator|->
name|CallVoidMethod
argument_list|(
name|menu
argument_list|,
name|clearMenuMethodID
argument_list|)
expr_stmt|;
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|visibleMenuMutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|visibleMenu
condition|)
return|return;
name|QString
name|menuText
init|=
name|removeAmpersandEscapes
argument_list|(
name|visibleMenu
operator|->
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|jstring
name|jtext
init|=
name|env
operator|->
name|NewString
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|jchar
operator|*
argument_list|>
argument_list|(
name|menuText
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|menuText
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|env
operator|->
name|CallObjectMethod
argument_list|(
name|menu
argument_list|,
name|setHeaderTitleContextMenuMethodID
argument_list|,
name|jtext
argument_list|)
expr_stmt|;
name|env
operator|->
name|DeleteLocalRef
argument_list|(
name|jtext
argument_list|)
expr_stmt|;
name|addAllMenuItemsToMenu
argument_list|(
name|env
argument_list|,
name|menu
argument_list|,
name|visibleMenu
argument_list|)
expr_stmt|;
block|}
DECL|function|onContextItemSelected
specifier|static
name|jboolean
name|onContextItemSelected
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jint
name|menuId
parameter_list|,
name|jboolean
name|checked
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|visibleMenuMutex
argument_list|)
decl_stmt|;
name|QAndroidPlatformMenuItem
modifier|*
name|item
init|=
cast|static_cast
argument_list|<
name|QAndroidPlatformMenuItem
operator|*
argument_list|>
argument_list|(
name|visibleMenu
operator|->
name|menuItemForTag
argument_list|(
name|menuId
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
if|if
condition|(
name|item
operator|->
name|menu
argument_list|()
condition|)
block|{
name|showContextMenu
argument_list|(
name|item
operator|->
name|menu
argument_list|()
argument_list|,
name|env
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|item
operator|->
name|isCheckable
argument_list|()
condition|)
name|item
operator|->
name|setChecked
argument_list|(
name|checked
argument_list|)
expr_stmt|;
name|item
operator|->
name|activated
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|JNI_TRUE
return|;
block|}
DECL|function|onContextMenuClosed
specifier|static
name|void
name|onContextMenuClosed
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jobject
comment|/*menu*/
parameter_list|)
block|{
name|QMutexLocker
name|lock
argument_list|(
operator|&
name|visibleMenuMutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|visibleMenu
condition|)
return|return;
name|visibleMenu
operator|->
name|aboutToHide
argument_list|()
expr_stmt|;
name|visibleMenu
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|pendingContextMenus
operator|.
name|empty
argument_list|()
condition|)
name|showContextMenu
argument_list|(
name|pendingContextMenus
operator|.
name|dequeue
argument_list|()
argument_list|,
name|env
argument_list|)
expr_stmt|;
block|}
DECL|member|methods
specifier|static
name|JNINativeMethod
name|methods
index|[]
init|=
block|{
block|{
literal|"onPrepareOptionsMenu"
block|,
literal|"(Landroid/view/Menu;)Z"
block|,
operator|(
name|void
operator|*
operator|)
name|onPrepareOptionsMenu
block|}
block|,
block|{
literal|"onOptionsItemSelected"
block|,
literal|"(IZ)Z"
block|,
operator|(
name|void
operator|*
operator|)
name|onOptionsItemSelected
block|}
block|,
block|{
literal|"onOptionsMenuClosed"
block|,
literal|"(Landroid/view/Menu;)V"
block|,
operator|(
name|void
operator|*
operator|)
name|onOptionsMenuClosed
block|}
block|,
block|{
literal|"onCreateContextMenu"
block|,
literal|"(Landroid/view/ContextMenu;)V"
block|,
operator|(
name|void
operator|*
operator|)
name|onCreateContextMenu
block|}
block|,
block|{
literal|"onContextItemSelected"
block|,
literal|"(IZ)Z"
block|,
operator|(
name|void
operator|*
operator|)
name|onContextItemSelected
block|}
block|,
block|{
literal|"onContextMenuClosed"
block|,
literal|"(Landroid/view/Menu;)V"
block|,
operator|(
name|void
operator|*
operator|)
name|onContextMenuClosed
block|}
block|,     }
decl_stmt|;
DECL|macro|FIND_AND_CHECK_CLASS
define|#
directive|define
name|FIND_AND_CHECK_CLASS
parameter_list|(
name|CLASS_NAME
parameter_list|)
define|\
value|clazz = env->FindClass(CLASS_NAME); \     if (!clazz) { \         __android_log_print(ANDROID_LOG_FATAL, qtTagText(), classErrorMsgFmt(), CLASS_NAME); \         return false; \     }
DECL|macro|GET_AND_CHECK_METHOD
define|#
directive|define
name|GET_AND_CHECK_METHOD
parameter_list|(
name|VAR
parameter_list|,
name|CLASS
parameter_list|,
name|METHOD_NAME
parameter_list|,
name|METHOD_SIGNATURE
parameter_list|)
define|\
value|VAR = env->GetMethodID(CLASS, METHOD_NAME, METHOD_SIGNATURE); \     if (!VAR) { \         __android_log_print(ANDROID_LOG_FATAL, qtTagText(), methodErrorMsgFmt(), METHOD_NAME, METHOD_SIGNATURE); \         return false; \     }
DECL|macro|GET_AND_CHECK_STATIC_METHOD
define|#
directive|define
name|GET_AND_CHECK_STATIC_METHOD
parameter_list|(
name|VAR
parameter_list|,
name|CLASS
parameter_list|,
name|METHOD_NAME
parameter_list|,
name|METHOD_SIGNATURE
parameter_list|)
define|\
value|VAR = env->GetStaticMethodID(CLASS, METHOD_NAME, METHOD_SIGNATURE); \     if (!VAR) { \         __android_log_print(ANDROID_LOG_FATAL, qtTagText(), methodErrorMsgFmt(), METHOD_NAME, METHOD_SIGNATURE); \         return false; \     }
DECL|macro|GET_AND_CHECK_STATIC_FIELD
define|#
directive|define
name|GET_AND_CHECK_STATIC_FIELD
parameter_list|(
name|VAR
parameter_list|,
name|CLASS
parameter_list|,
name|FIELD_NAME
parameter_list|,
name|FIELD_SIGNATURE
parameter_list|)
define|\
value|VAR = env->GetStaticFieldID(CLASS, FIELD_NAME, FIELD_SIGNATURE); \     if (!VAR) { \         __android_log_print(ANDROID_LOG_FATAL, qtTagText(), methodErrorMsgFmt(), FIELD_NAME, FIELD_SIGNATURE); \         return false; \     }
DECL|function|registerNatives
name|bool
name|registerNatives
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|)
block|{
name|jclass
name|appClass
init|=
name|applicationClass
argument_list|()
decl_stmt|;
if|if
condition|(
name|env
operator|->
name|RegisterNatives
argument_list|(
name|appClass
argument_list|,
name|methods
argument_list|,
sizeof|sizeof
argument_list|(
name|methods
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|methods
index|[
literal|0
index|]
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
name|__android_log_print
argument_list|(
name|ANDROID_LOG_FATAL
argument_list|,
literal|"Qt"
argument_list|,
literal|"RegisterNatives failed"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|GET_AND_CHECK_STATIC_METHOD
argument_list|(
name|openContextMenuMethodID
argument_list|,
name|appClass
argument_list|,
literal|"openContextMenu"
argument_list|,
literal|"()V"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_STATIC_METHOD
argument_list|(
name|closeContextMenuMethodID
argument_list|,
name|appClass
argument_list|,
literal|"closeContextMenu"
argument_list|,
literal|"()V"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_STATIC_METHOD
argument_list|(
name|resetOptionsMenuMethodID
argument_list|,
name|appClass
argument_list|,
literal|"resetOptionsMenu"
argument_list|,
literal|"()V"
argument_list|)
expr_stmt|;
name|jclass
name|clazz
decl_stmt|;
name|FIND_AND_CHECK_CLASS
argument_list|(
literal|"android/view/Menu"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_METHOD
argument_list|(
name|clearMenuMethodID
argument_list|,
name|clazz
argument_list|,
literal|"clear"
argument_list|,
literal|"()V"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_METHOD
argument_list|(
name|addMenuItemMethodID
argument_list|,
name|clazz
argument_list|,
literal|"add"
argument_list|,
literal|"(IIILjava/lang/CharSequence;)Landroid/view/MenuItem;"
argument_list|)
expr_stmt|;
name|jfieldID
name|menuNoneFiledId
decl_stmt|;
name|GET_AND_CHECK_STATIC_FIELD
argument_list|(
name|menuNoneFiledId
argument_list|,
name|clazz
argument_list|,
literal|"NONE"
argument_list|,
literal|"I"
argument_list|)
expr_stmt|;
name|menuNoneValue
operator|=
name|env
operator|->
name|GetStaticIntField
argument_list|(
name|clazz
argument_list|,
name|menuNoneFiledId
argument_list|)
expr_stmt|;
name|FIND_AND_CHECK_CLASS
argument_list|(
literal|"android/view/ContextMenu"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_METHOD
argument_list|(
name|setHeaderTitleContextMenuMethodID
argument_list|,
name|clazz
argument_list|,
literal|"setHeaderTitle"
argument_list|,
literal|"(Ljava/lang/CharSequence;)Landroid/view/ContextMenu;"
argument_list|)
expr_stmt|;
name|FIND_AND_CHECK_CLASS
argument_list|(
literal|"android/view/MenuItem"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_METHOD
argument_list|(
name|setCheckableMenuItemMethodID
argument_list|,
name|clazz
argument_list|,
literal|"setCheckable"
argument_list|,
literal|"(Z)Landroid/view/MenuItem;"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_METHOD
argument_list|(
name|setCheckedMenuItemMethodID
argument_list|,
name|clazz
argument_list|,
literal|"setChecked"
argument_list|,
literal|"(Z)Landroid/view/MenuItem;"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_METHOD
argument_list|(
name|setEnabledMenuItemMethodID
argument_list|,
name|clazz
argument_list|,
literal|"setEnabled"
argument_list|,
literal|"(Z)Landroid/view/MenuItem;"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_METHOD
argument_list|(
name|setIconMenuItemMethodID
argument_list|,
name|clazz
argument_list|,
literal|"setIcon"
argument_list|,
literal|"(Landroid/graphics/drawable/Drawable;)Landroid/view/MenuItem;"
argument_list|)
expr_stmt|;
name|GET_AND_CHECK_METHOD
argument_list|(
name|setVisibleMenuItemMethodID
argument_list|,
name|clazz
argument_list|,
literal|"setVisible"
argument_list|,
literal|"(Z)Landroid/view/MenuItem;"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
end_namespace
end_unit
