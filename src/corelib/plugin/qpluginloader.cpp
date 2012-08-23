begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qplugin.h"
end_include
begin_include
include|#
directive|include
file|"qpluginloader.h"
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|"qlibrary_p.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QPluginLoader     \inmodule QtCore     \reentrant     \brief The QPluginLoader class loads a plugin at run-time.       \ingroup plugins      QPluginLoader provides access to a \l{How to Create Qt     Plugins}{Qt plugin}. A Qt plugin is stored in a shared library (a     DLL) and offers these benefits over shared libraries accessed     using QLibrary:      \list     \li QPluginLoader checks that a plugin is linked against the same        version of Qt as the application.     \li QPluginLoader provides direct access to a root component object        (instance()), instead of forcing you to resolve a C function manually.     \endlist      An instance of a QPluginLoader object operates on a single shared     library file, which we call a plugin. It provides access to the     functionality in the plugin in a platform-independent way. To     specify which plugin to load, either pass a file name in     the constructor or set it with setFileName().      The most important functions are load() to dynamically load the     plugin file, isLoaded() to check whether loading was successful,     and instance() to access the root component in the plugin. The     instance() function implicitly tries to load the plugin if it has     not been loaded yet. Multiple instances of QPluginLoader can be     used to access the same physical plugin.      Once loaded, plugins remain in memory until all instances of     QPluginLoader has been unloaded, or until the application     terminates. You can attempt to unload a plugin using unload(),     but if other instances of QPluginLoader are using the same     library, the call will fail, and unloading will only happen when     every instance has called unload(). Right before the unloading     happen, the root component will also be deleted.      See \l{How to Create Qt Plugins} for more information about     how to make your application extensible through plugins.      Note that the QPluginLoader cannot be used if your application is     statically linked against Qt. In this case, you will also have to     link to plugins statically. You can use QLibrary if you need to     load dynamic libraries in a statically linked application.      \sa QLibrary, {Plug& Paint Example} */
end_comment
begin_comment
comment|/*!     Constructs a plugin loader with the given \a parent. */
end_comment
begin_constructor
DECL|function|QPluginLoader
name|QPluginLoader
operator|::
name|QPluginLoader
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|did_load
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a plugin loader with the given \a parent that will     load the plugin specified by \a fileName.      To be loadable, the file's suffix must be a valid suffix for a     loadable library in accordance with the platform, e.g. \c .so on     Unix, - \c .dylib on Mac OS X, and \c .dll on Windows. The suffix     can be verified with QLibrary::isLibrary().      \sa setFileName() */
end_comment
begin_constructor
DECL|function|QPluginLoader
name|QPluginLoader
operator|::
name|QPluginLoader
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|did_load
argument_list|(
literal|false
argument_list|)
block|{
name|setFileName
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QPluginLoader object.      Unless unload() was called explicitly, the plugin stays in memory     until the application terminates.      \sa isLoaded(), unload() */
end_comment
begin_destructor
DECL|function|~QPluginLoader
name|QPluginLoader
operator|::
name|~
name|QPluginLoader
parameter_list|()
block|{
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|release
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns the root component object of the plugin. The plugin is     loaded if necessary. The function returns 0 if the plugin could     not be loaded or if the root component object could not be     instantiated.      If the root component object was destroyed, calling this function     creates a new instance.      The root component, returned by this function, is not deleted when     the QPluginLoader is destroyed. If you want to ensure that the root     component is deleted, you should call unload() as soon you don't     need to access the core component anymore.  When the library is     finally unloaded, the root component will automatically be deleted.      The component object is a QObject. Use qobject_cast() to access     interfaces you are interested in.      \sa load() */
end_comment
begin_function
DECL|function|instance
name|QObject
modifier|*
name|QPluginLoader
operator|::
name|instance
parameter_list|()
block|{
if|if
condition|(
operator|!
name|isLoaded
argument_list|()
operator|&&
operator|!
name|load
argument_list|()
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|d
operator|->
name|inst
operator|&&
name|d
operator|->
name|instance
condition|)
name|d
operator|->
name|inst
operator|=
name|d
operator|->
name|instance
argument_list|()
expr_stmt|;
return|return
name|d
operator|->
name|inst
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the meta data for this plugin. The meta data is data specified     in a json format using the Q_PLUGIN_METADATA() macro when compiling     the plugin.      The meta data can be queried in a fast and inexpensive way without     actually loading the plugin. This makes it possible to e.g. store     capabilities of the plugin in there, and make the decision whether to     load the plugin dependent on this meta data.  */
end_comment
begin_function
DECL|function|metaData
name|QJsonObject
name|QPluginLoader
operator|::
name|metaData
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QJsonObject
argument_list|()
return|;
return|return
name|d
operator|->
name|metaData
return|;
block|}
end_function
begin_comment
comment|/*!     Loads the plugin and returns true if the plugin was loaded     successfully; otherwise returns false. Since instance() always     calls this function before resolving any symbols it is not     necessary to call it explicitly. In some situations you might want     the plugin loaded in advance, in which case you would use this     function.      \sa unload() */
end_comment
begin_function
DECL|function|load
name|bool
name|QPluginLoader
operator|::
name|load
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|||
name|d
operator|->
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|did_load
condition|)
return|return
name|d
operator|->
name|pHnd
operator|&&
name|d
operator|->
name|instance
return|;
if|if
condition|(
operator|!
name|d
operator|->
name|isPlugin
argument_list|()
condition|)
return|return
literal|false
return|;
name|did_load
operator|=
literal|true
expr_stmt|;
return|return
name|d
operator|->
name|loadPlugin
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Unloads the plugin and returns true if the plugin could be     unloaded; otherwise returns false.      This happens automatically on application termination, so you     shouldn't normally need to call this function.      If other instances of QPluginLoader are using the same plugin, the     call will fail, and unloading will only happen when every instance     has called unload().      Don't try to delete the root component. Instead rely on     that unload() will automatically delete it when needed.      \sa instance(), load() */
end_comment
begin_function
DECL|function|unload
name|bool
name|QPluginLoader
operator|::
name|unload
parameter_list|()
block|{
if|if
condition|(
name|did_load
condition|)
block|{
name|did_load
operator|=
literal|false
expr_stmt|;
return|return
name|d
operator|->
name|unload
argument_list|()
return|;
block|}
if|if
condition|(
name|d
condition|)
comment|// Ouch
name|d
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"The plugin was not loaded."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the plugin is loaded; otherwise returns false.      \sa load()  */
end_comment
begin_function
DECL|function|isLoaded
name|bool
name|QPluginLoader
operator|::
name|isLoaded
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|&&
name|d
operator|->
name|pHnd
operator|&&
name|d
operator|->
name|instance
return|;
block|}
end_function
begin_comment
comment|/*!     \property QPluginLoader::fileName     \brief the file name of the plugin      To be loadable, the file's suffix must be a valid suffix for a     loadable library in accordance with the platform, e.g. \c .so on     Unix, \c .dylib on Mac OS X, and \c .dll on Windows. The suffix     can be verified with QLibrary::isLibrary().      If the file name does not exist, it will not be set. This property     will then contain an empty string.      By default, this property contains an empty string.      \sa load() */
end_comment
begin_function
DECL|function|setFileName
name|void
name|QPluginLoader
operator|::
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_SHARED
argument_list|)
name|QLibrary
operator|::
name|LoadHints
name|lh
decl_stmt|;
if|if
condition|(
name|d
condition|)
block|{
name|lh
operator|=
name|d
operator|->
name|loadHints
expr_stmt|;
name|d
operator|->
name|release
argument_list|()
expr_stmt|;
name|d
operator|=
literal|0
expr_stmt|;
name|did_load
operator|=
literal|false
expr_stmt|;
block|}
name|QString
name|fn
init|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
decl_stmt|;
name|d
operator|=
name|QLibraryPrivate
operator|::
name|findOrCreate
argument_list|(
name|fn
argument_list|)
expr_stmt|;
name|d
operator|->
name|loadHints
operator|=
name|lh
expr_stmt|;
if|if
condition|(
name|fn
operator|.
name|isEmpty
argument_list|()
condition|)
name|d
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"The shared library was not found."
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|qt_debug_component
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Cannot load %s into a statically linked Qt library."
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|QFile
operator|::
name|encodeName
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|Q_UNUSED
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|fileName
name|QString
name|QPluginLoader
operator|::
name|fileName
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
condition|)
return|return
name|d
operator|->
name|fileName
return|;
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.2      Returns a text string with the description of the last error that occurred. */
end_comment
begin_function
DECL|function|errorString
name|QString
name|QPluginLoader
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
operator|(
operator|!
name|d
operator|||
name|d
operator|->
name|errorString
operator|.
name|isEmpty
argument_list|()
operator|)
condition|?
name|tr
argument_list|(
literal|"Unknown error"
argument_list|)
else|:
name|d
operator|->
name|errorString
return|;
block|}
end_function
begin_typedef
DECL|typedef|StaticPluginList
typedef|typedef
name|QVector
argument_list|<
name|QStaticPlugin
argument_list|>
name|StaticPluginList
typedef|;
end_typedef
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|StaticPluginList
argument_list|,
argument|staticPluginList
argument_list|)
end_macro
begin_comment
comment|/*! \since 4.4      \property QPluginLoader::loadHints     \brief Give the load() function some hints on how it should behave.      You can give hints on how the symbols in the plugin are     resolved. By default, none of the hints are set.      See the documentation of QLibrary::loadHints for a complete     description of how this property works.      \sa QLibrary::loadHints */
end_comment
begin_function
DECL|function|setLoadHints
name|void
name|QPluginLoader
operator|::
name|setLoadHints
parameter_list|(
name|QLibrary
operator|::
name|LoadHints
name|loadHints
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|d
operator|=
name|QLibraryPrivate
operator|::
name|findOrCreate
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
comment|// ugly, but we need a d-ptr
name|d
operator|->
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|loadHints
operator|=
name|loadHints
expr_stmt|;
block|}
end_function
begin_function
DECL|function|loadHints
name|QLibrary
operator|::
name|LoadHints
name|QPluginLoader
operator|::
name|loadHints
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
block|{
name|QPluginLoader
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QPluginLoader
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|d
operator|=
name|QLibraryPrivate
operator|::
name|findOrCreate
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
comment|// ugly, but we need a d-ptr
name|that
operator|->
name|d
operator|->
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
return|return
name|d
operator|->
name|loadHints
return|;
block|}
end_function
begin_comment
comment|/*!     \relates QPluginLoader     \since 5.0      Registers the given \a plugin with the plugin loader. */
end_comment
begin_function
DECL|function|qRegisterStaticPluginFunction
name|void
name|Q_CORE_EXPORT
name|qRegisterStaticPluginFunction
parameter_list|(
name|QStaticPlugin
name|plugin
parameter_list|)
block|{
name|staticPluginList
argument_list|()
operator|->
name|append
argument_list|(
name|plugin
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of static plugin instances (root components) held     by the plugin loader. */
end_comment
begin_function
DECL|function|staticInstances
name|QObjectList
name|QPluginLoader
operator|::
name|staticInstances
parameter_list|()
block|{
name|QObjectList
name|instances
decl_stmt|;
specifier|const
name|StaticPluginList
modifier|*
name|plugins
init|=
name|staticPluginList
argument_list|()
decl_stmt|;
if|if
condition|(
name|plugins
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|plugins
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|instances
operator|+=
name|plugins
operator|->
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|instance
argument_list|()
expr_stmt|;
block|}
return|return
name|instances
return|;
block|}
end_function
begin_function
DECL|function|staticPlugins
name|QVector
argument_list|<
name|QStaticPlugin
argument_list|>
name|QLibraryPrivate
operator|::
name|staticPlugins
parameter_list|()
block|{
name|StaticPluginList
modifier|*
name|plugins
init|=
name|staticPluginList
argument_list|()
decl_stmt|;
if|if
condition|(
name|plugins
condition|)
return|return
operator|*
name|plugins
return|;
return|return
name|QVector
argument_list|<
name|QStaticPlugin
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
end_unit
