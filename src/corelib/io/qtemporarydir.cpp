begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtemporarydir.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEMPORARYFILE
end_ifndef
begin_include
include|#
directive|include
file|"qdiriterator.h"
end_include
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_comment
comment|// mkdtemp
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qfilesystemengine_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|//************* QTemporaryDirPrivate
end_comment
begin_class
DECL|class|QTemporaryDirPrivate
class|class
name|QTemporaryDirPrivate
block|{
public|public:
name|QTemporaryDirPrivate
parameter_list|()
constructor_decl|;
name|~
name|QTemporaryDirPrivate
parameter_list|()
destructor_decl|;
name|void
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|)
function_decl|;
DECL|member|path
name|QString
name|path
decl_stmt|;
DECL|member|autoRemove
name|bool
name|autoRemove
decl_stmt|;
DECL|member|success
name|bool
name|success
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QTemporaryDirPrivate
name|QTemporaryDirPrivate
operator|::
name|QTemporaryDirPrivate
parameter_list|()
member_init_list|:
name|autoRemove
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|success
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QTemporaryDirPrivate
name|QTemporaryDirPrivate
operator|::
name|~
name|QTemporaryDirPrivate
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|defaultTemplateName
specifier|static
name|QString
name|defaultTemplateName
parameter_list|()
block|{
name|QString
name|baseName
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_CORE_LIB
argument_list|)
name|baseName
operator|=
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
expr_stmt|;
if|if
condition|(
name|baseName
operator|.
name|isEmpty
argument_list|()
condition|)
endif|#
directive|endif
name|baseName
operator|=
name|QLatin1String
argument_list|(
literal|"qt_temp"
argument_list|)
expr_stmt|;
return|return
name|QDir
operator|::
name|tempPath
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|baseName
operator|+
name|QLatin1String
argument_list|(
literal|"-XXXXXX"
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_if
begin_function
DECL|function|nextRand
specifier|static
name|int
name|nextRand
parameter_list|(
name|int
modifier|&
name|v
parameter_list|)
block|{
name|int
name|r
init|=
name|v
operator|%
literal|62
decl_stmt|;
name|v
operator|/=
literal|62
expr_stmt|;
if|if
condition|(
name|v
operator|<
literal|62
condition|)
name|v
operator|=
name|qrand
argument_list|()
expr_stmt|;
return|return
name|r
return|;
block|}
end_function
begin_function
DECL|function|q_mkdtemp
specifier|static
name|char
modifier|*
name|q_mkdtemp
parameter_list|(
name|char
modifier|*
name|templateName
parameter_list|)
block|{
specifier|static
specifier|const
name|char
name|letters
index|[]
init|=
literal|"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
decl_stmt|;
specifier|const
name|size_t
name|length
init|=
name|strlen
argument_list|(
name|templateName
argument_list|)
decl_stmt|;
name|char
modifier|*
name|XXXXXX
init|=
name|templateName
operator|+
name|length
operator|-
literal|6
decl_stmt|;
if|if
condition|(
operator|(
name|length
operator|<
literal|6u
operator|)
operator|||
name|strncmp
argument_list|(
name|XXXXXX
argument_list|,
literal|"XXXXXX"
argument_list|,
literal|6
argument_list|)
condition|)
return|return
literal|0
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
operator|++
name|i
control|)
block|{
name|int
name|v
init|=
name|qrand
argument_list|()
decl_stmt|;
comment|/* Fill in the random bits.  */
name|XXXXXX
index|[
literal|0
index|]
operator|=
name|letters
index|[
name|nextRand
argument_list|(
name|v
argument_list|)
index|]
expr_stmt|;
name|XXXXXX
index|[
literal|1
index|]
operator|=
name|letters
index|[
name|nextRand
argument_list|(
name|v
argument_list|)
index|]
expr_stmt|;
name|XXXXXX
index|[
literal|2
index|]
operator|=
name|letters
index|[
name|nextRand
argument_list|(
name|v
argument_list|)
index|]
expr_stmt|;
name|XXXXXX
index|[
literal|3
index|]
operator|=
name|letters
index|[
name|nextRand
argument_list|(
name|v
argument_list|)
index|]
expr_stmt|;
name|XXXXXX
index|[
literal|4
index|]
operator|=
name|letters
index|[
name|nextRand
argument_list|(
name|v
argument_list|)
index|]
expr_stmt|;
name|XXXXXX
index|[
literal|5
index|]
operator|=
name|letters
index|[
name|v
operator|%
literal|62
index|]
expr_stmt|;
name|QString
name|templateNameStr
init|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|templateName
argument_list|)
decl_stmt|;
name|QFileSystemEntry
name|fileSystemEntry
argument_list|(
name|templateNameStr
argument_list|)
decl_stmt|;
if|if
condition|(
name|QFileSystemEngine
operator|::
name|createDirectory
argument_list|(
name|fileSystemEntry
argument_list|,
literal|false
argument_list|)
condition|)
block|{
name|QSystemError
name|error
decl_stmt|;
name|QFileSystemEngine
operator|::
name|setPermissions
argument_list|(
name|fileSystemEntry
argument_list|,
name|QFile
operator|::
name|ReadOwner
operator||
name|QFile
operator|::
name|WriteOwner
operator||
name|QFile
operator|::
name|ExeOwner
argument_list|,
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|error
argument_list|()
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|QFileSystemEngine
operator|::
name|removeDirectory
argument_list|(
name|fileSystemEntry
argument_list|,
literal|false
argument_list|)
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"Unable to remove unused directory"
operator|<<
name|templateNameStr
expr_stmt|;
continue|continue;
block|}
return|return
name|templateName
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_comment
comment|// defined(Q_OS_QNX ) || defined(Q_OS_WIN) || defined(Q_OS_ANDROID)
end_comment
begin_function
DECL|function|q_mkdtemp
specifier|static
name|char
modifier|*
name|q_mkdtemp
parameter_list|(
name|char
modifier|*
name|templateName
parameter_list|)
block|{
return|return
name|mkdtemp
argument_list|(
name|templateName
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|create
name|void
name|QTemporaryDirPrivate
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|templateName
parameter_list|)
block|{
name|QByteArray
name|buffer
init|=
name|QFile
operator|::
name|encodeName
argument_list|(
name|templateName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|buffer
operator|.
name|endsWith
argument_list|(
literal|"XXXXXX"
argument_list|)
condition|)
name|buffer
operator|+=
literal|"XXXXXX"
expr_stmt|;
if|if
condition|(
name|q_mkdtemp
argument_list|(
name|buffer
operator|.
name|data
argument_list|()
argument_list|)
condition|)
block|{
comment|// modifies buffer
name|success
operator|=
literal|true
expr_stmt|;
name|path
operator|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|buffer
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//************* QTemporaryDir
end_comment
begin_comment
comment|/*!     \class QTemporaryDir     \inmodule QtCore     \reentrant     \brief The QTemporaryDir class creates a unique directory for temporary use.      \ingroup io       QTemporaryDir is used to create unique temporary dirs safely.     The dir itself is created by the constructor. The name of the     temporary directory is guaranteed to be unique (i.e., you are     guaranteed to not overwrite an existing dir), and the directory will     subsequently be removed upon destruction of the QTemporaryDir     object. The directory name is either auto-generated, or created based     on a template, which is passed to QTemporaryDir's constructor.      Example:      \snippet code/src_corelib_io_qtemporarydir.cpp 0      It is very important to test that the temporary directory could be     created, using isValid(). Do not use \l {QDir::exists()}{exists()}, since a default-constructed     QDir represents the current directory, which exists.      The path to the temporary dir can be found by calling path().      A temporary directory will have some static part of the name and some     part that is calculated to be unique. The default path will be     determined from QCoreApplication::applicationName() (otherwise \c qt_temp) and will     be placed into the temporary path as returned by QDir::tempPath().     If you specify your own path, a relative path will not be placed in the     temporary directory by default, but be relative to the current working directory.     In all cases, a random string will be appended to the path in order to make it unique.      \sa QDir::tempPath(), QDir, QTemporaryFile */
end_comment
begin_comment
comment|/*!     Constructs a QTemporaryDir using as template the application name     returned by QCoreApplication::applicationName() (otherwise \c qt_temp).     The directory is stored in the system's temporary directory, QDir::tempPath().      \sa QDir::tempPath() */
end_comment
begin_constructor
DECL|function|QTemporaryDir
name|QTemporaryDir
operator|::
name|QTemporaryDir
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QTemporaryDirPrivate
argument_list|)
block|{
name|d_ptr
operator|->
name|create
argument_list|(
name|defaultTemplateName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QTemporaryDir with a template of \a templatePath.      If \a templatePath is a relative path, the path will be relative to the     current working directory. You can use QDir::tempPath() to construct \a     templatePath if you want use the system's temporary directory.      If the \a templatePath ends with XXXXXX it will be used as the dynamic portion     of the directory name, otherwise it will be appended.     Unlike QTemporaryFile, XXXXXX in the middle of the template string is not supported.      \sa QDir::tempPath() */
end_comment
begin_constructor
DECL|function|QTemporaryDir
name|QTemporaryDir
operator|::
name|QTemporaryDir
parameter_list|(
specifier|const
name|QString
modifier|&
name|templatePath
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QTemporaryDirPrivate
argument_list|)
block|{
if|if
condition|(
name|templatePath
operator|.
name|isEmpty
argument_list|()
condition|)
name|d_ptr
operator|->
name|create
argument_list|(
name|defaultTemplateName
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|d_ptr
operator|->
name|create
argument_list|(
name|templatePath
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the temporary directory object.     If auto remove mode was set, it will automatically delete the directory     including all its contents.      \sa autoRemove() */
end_comment
begin_destructor
DECL|function|~QTemporaryDir
name|QTemporaryDir
operator|::
name|~
name|QTemporaryDir
parameter_list|()
block|{
if|if
condition|(
name|d_ptr
operator|->
name|autoRemove
condition|)
name|remove
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!    Returns \c true if the QTemporaryDir was created successfully. */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QTemporaryDir
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|success
return|;
block|}
end_function
begin_comment
comment|/*!    Returns the path to the temporary directory.    Empty if the QTemporaryDir could not be created. */
end_comment
begin_function
DECL|function|path
name|QString
name|QTemporaryDir
operator|::
name|path
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|path
return|;
block|}
end_function
begin_comment
comment|/*!    Returns \c true if the QTemporaryDir is in auto remove    mode. Auto-remove mode will automatically delete the directory from    disk upon destruction. This makes it very easy to create your    QTemporaryDir object on the stack, fill it with files, do something with    the files, and finally on function return it will automatically clean up    after itself.     Auto-remove is on by default.     \sa setAutoRemove(), remove() */
end_comment
begin_function
DECL|function|autoRemove
name|bool
name|QTemporaryDir
operator|::
name|autoRemove
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|autoRemove
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the QTemporaryDir into auto-remove mode if \a b is true.      Auto-remove is on by default.      \sa autoRemove(), remove() */
end_comment
begin_function
DECL|function|setAutoRemove
name|void
name|QTemporaryDir
operator|::
name|setAutoRemove
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|d_ptr
operator|->
name|autoRemove
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the temporary directory, including all its contents.      Returns \c true if removing was successful. */
end_comment
begin_function
DECL|function|remove
name|bool
name|QTemporaryDir
operator|::
name|remove
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d_ptr
operator|->
name|success
condition|)
return|return
literal|false
return|;
name|Q_ASSERT
argument_list|(
operator|!
name|path
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|path
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|result
init|=
name|QDir
argument_list|(
name|path
argument_list|()
argument_list|)
operator|.
name|removeRecursively
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QTemporaryDir: Unable to remove"
operator|<<
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|path
argument_list|()
argument_list|)
operator|<<
literal|"most likely due to the presence of read-only files."
expr_stmt|;
block|}
return|return
name|result
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
comment|// QT_NO_TEMPORARYFILE
end_comment
end_unit
