begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpictureformatplugin.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_PICTURE
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qpicture.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \obsolete      \class QPictureFormatPlugin     \brief The QPictureFormatPlugin class provides an abstract base     for custom picture format plugins.      \ingroup plugins     \inmodule QtGui      The picture format plugin is a simple plugin interface that makes     it easy to create custom picture formats that can be used     transparently by applications.      Writing an picture format plugin is achieved by subclassing this     base class, reimplementing the pure virtual functions     loadPicture(), savePicture(), and installIOHandler(), and     exporting the class with the Q_PLUGIN_METADATA() macro.      The json file containing the metadata should contain one entry     with the list of picture formats supported by the plugin:      \code     { "Keys": [ "mypictureformat" ] }     \endcode      \sa {How to Create Qt Plugins} */
end_comment
begin_comment
comment|/*!     \fn bool QPictureFormatPlugin::installIOHandler(const QString&format)      Installs a QPictureIO picture I/O handler for the picture format \a     format. Returns \c true on success.      \sa keys() */
end_comment
begin_comment
comment|/*!     Constructs an picture format plugin with the given \a parent.     This is invoked automatically by the moc generated code that exports the plugin. */
end_comment
begin_constructor
DECL|function|QPictureFormatPlugin
name|QPictureFormatPlugin
operator|::
name|QPictureFormatPlugin
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
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the picture format plugin.      You never have to call this explicitly. Qt destroys a plugin     automatically when it is no longer used. */
end_comment
begin_destructor
DECL|function|~QPictureFormatPlugin
name|QPictureFormatPlugin
operator|::
name|~
name|QPictureFormatPlugin
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Loads the picture stored in the file called \a fileName, with the     given \a format, into *\a picture. Returns \c true on success;     otherwise returns \c false.      \sa savePicture() */
end_comment
begin_function
DECL|function|loadPicture
name|bool
name|QPictureFormatPlugin
operator|::
name|loadPicture
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
name|QPicture
modifier|*
name|picture
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|format
argument_list|)
name|Q_UNUSED
argument_list|(
argument|fileName
argument_list|)
name|Q_UNUSED
argument_list|(
argument|picture
argument_list|)
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Saves the given \a picture into the file called \a fileName,     using the specified \a format. Returns \c true on success; otherwise     returns \c false.      \sa loadPicture() */
end_comment
begin_function
DECL|function|savePicture
name|bool
name|QPictureFormatPlugin
operator|::
name|savePicture
parameter_list|(
specifier|const
name|QString
modifier|&
name|format
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QPicture
modifier|&
name|picture
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|format
argument_list|)
name|Q_UNUSED
argument_list|(
argument|fileName
argument_list|)
name|Q_UNUSED
argument_list|(
argument|picture
argument_list|)
return|return
literal|false
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY || QT_NO_PICTURE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
