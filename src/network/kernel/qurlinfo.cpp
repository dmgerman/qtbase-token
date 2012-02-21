begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qurlinfo.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_URLINFO
end_ifndef
begin_include
include|#
directive|include
file|"qurl.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QUrlInfoPrivate
class|class
name|QUrlInfoPrivate
block|{
public|public:
DECL|function|QUrlInfoPrivate
name|QUrlInfoPrivate
parameter_list|()
member_init_list|:
name|permissions
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|size
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|isDir
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|isFile
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|isSymLink
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|isWritable
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|isReadable
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|isExecutable
argument_list|(
literal|false
argument_list|)
block|{}
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|permissions
name|int
name|permissions
decl_stmt|;
DECL|member|owner
name|QString
name|owner
decl_stmt|;
DECL|member|group
name|QString
name|group
decl_stmt|;
DECL|member|size
name|qint64
name|size
decl_stmt|;
DECL|member|lastModified
name|QDateTime
name|lastModified
decl_stmt|;
DECL|member|lastRead
name|QDateTime
name|lastRead
decl_stmt|;
DECL|member|isDir
name|bool
name|isDir
decl_stmt|;
DECL|member|isFile
name|bool
name|isFile
decl_stmt|;
DECL|member|isSymLink
name|bool
name|isSymLink
decl_stmt|;
DECL|member|isWritable
name|bool
name|isWritable
decl_stmt|;
DECL|member|isReadable
name|bool
name|isReadable
decl_stmt|;
DECL|member|isExecutable
name|bool
name|isExecutable
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QUrlInfo     \brief The QUrlInfo class stores information about URLs.      \ingroup io     \ingroup network     \inmodule QtNetwork      The information about a URL that can be retrieved includes name(),     permissions(), owner(), group(), size(), lastModified(),     lastRead(), isDir(), isFile(), isSymLink(), isWritable(),     isReadable() and isExecutable().      You can create your own QUrlInfo objects passing in all the     relevant information in the constructor, and you can modify a     QUrlInfo; for each getter mentioned above there is an equivalent     setter. Note that setting values does not affect the underlying     resource that the QUrlInfo provides information about; for example     if you call setWritable(true) on a read-only resource the only     thing changed is the QUrlInfo object, not the resource.      \sa QUrl, {FTP Example} */
end_comment
begin_comment
comment|/*!     \enum QUrlInfo::PermissionSpec      This enum is used by the permissions() function to report the     permissions of a file.      \value ReadOwner The file is readable by the owner of the file.     \value WriteOwner The file is writable by the owner of the file.     \value ExeOwner The file is executable by the owner of the file.     \value ReadGroup The file is readable by the group.     \value WriteGroup The file is writable by the group.     \value ExeGroup The file is executable by the group.     \value ReadOther The file is readable by anyone.     \value WriteOther The file is writable by anyone.     \value ExeOther The file is executable by anyone. */
end_comment
begin_comment
comment|/*!     Constructs an invalid QUrlInfo object with default values.      \sa isValid() */
end_comment
begin_constructor
DECL|function|QUrlInfo
name|QUrlInfo
operator|::
name|QUrlInfo
parameter_list|()
block|{
name|d
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Copy constructor, copies \a ui to this URL info object. */
end_comment
begin_constructor
DECL|function|QUrlInfo
name|QUrlInfo
operator|::
name|QUrlInfo
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|ui
parameter_list|)
block|{
if|if
condition|(
name|ui
operator|.
name|d
condition|)
block|{
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
operator|*
name|d
operator|=
operator|*
name|ui
operator|.
name|d
expr_stmt|;
block|}
else|else
block|{
name|d
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QUrlInfo object by specifying all the URL's     information.      The information that is passed is the \a name, file \a     permissions, \a owner and \a group and the file's \a size. Also     passed is the \a lastModified date/time and the \a lastRead     date/time. Flags are also passed, specifically, \a isDir, \a     isFile, \a isSymLink, \a isWritable, \a isReadable and \a     isExecutable. */
end_comment
begin_constructor
DECL|function|QUrlInfo
name|QUrlInfo
operator|::
name|QUrlInfo
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|int
name|permissions
parameter_list|,
specifier|const
name|QString
modifier|&
name|owner
parameter_list|,
specifier|const
name|QString
modifier|&
name|group
parameter_list|,
name|qint64
name|size
parameter_list|,
specifier|const
name|QDateTime
modifier|&
name|lastModified
parameter_list|,
specifier|const
name|QDateTime
modifier|&
name|lastRead
parameter_list|,
name|bool
name|isDir
parameter_list|,
name|bool
name|isFile
parameter_list|,
name|bool
name|isSymLink
parameter_list|,
name|bool
name|isWritable
parameter_list|,
name|bool
name|isReadable
parameter_list|,
name|bool
name|isExecutable
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|d
operator|->
name|permissions
operator|=
name|permissions
expr_stmt|;
name|d
operator|->
name|owner
operator|=
name|owner
expr_stmt|;
name|d
operator|->
name|group
operator|=
name|group
expr_stmt|;
name|d
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|d
operator|->
name|lastModified
operator|=
name|lastModified
expr_stmt|;
name|d
operator|->
name|lastRead
operator|=
name|lastRead
expr_stmt|;
name|d
operator|->
name|isDir
operator|=
name|isDir
expr_stmt|;
name|d
operator|->
name|isFile
operator|=
name|isFile
expr_stmt|;
name|d
operator|->
name|isSymLink
operator|=
name|isSymLink
expr_stmt|;
name|d
operator|->
name|isWritable
operator|=
name|isWritable
expr_stmt|;
name|d
operator|->
name|isReadable
operator|=
name|isReadable
expr_stmt|;
name|d
operator|->
name|isExecutable
operator|=
name|isExecutable
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QUrlInfo object by specifying all the URL's     information.      The information that is passed is the \a url, file \a     permissions, \a owner and \a group and the file's \a size. Also     passed is the \a lastModified date/time and the \a lastRead     date/time. Flags are also passed, specifically, \a isDir, \a     isFile, \a isSymLink, \a isWritable, \a isReadable and \a     isExecutable. */
end_comment
begin_constructor
DECL|function|QUrlInfo
name|QUrlInfo
operator|::
name|QUrlInfo
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|,
name|int
name|permissions
parameter_list|,
specifier|const
name|QString
modifier|&
name|owner
parameter_list|,
specifier|const
name|QString
modifier|&
name|group
parameter_list|,
name|qint64
name|size
parameter_list|,
specifier|const
name|QDateTime
modifier|&
name|lastModified
parameter_list|,
specifier|const
name|QDateTime
modifier|&
name|lastRead
parameter_list|,
name|bool
name|isDir
parameter_list|,
name|bool
name|isFile
parameter_list|,
name|bool
name|isSymLink
parameter_list|,
name|bool
name|isWritable
parameter_list|,
name|bool
name|isReadable
parameter_list|,
name|bool
name|isExecutable
parameter_list|)
block|{
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|name
operator|=
name|QFileInfo
argument_list|(
name|url
operator|.
name|path
argument_list|()
argument_list|)
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|d
operator|->
name|permissions
operator|=
name|permissions
expr_stmt|;
name|d
operator|->
name|owner
operator|=
name|owner
expr_stmt|;
name|d
operator|->
name|group
operator|=
name|group
expr_stmt|;
name|d
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|d
operator|->
name|lastModified
operator|=
name|lastModified
expr_stmt|;
name|d
operator|->
name|lastRead
operator|=
name|lastRead
expr_stmt|;
name|d
operator|->
name|isDir
operator|=
name|isDir
expr_stmt|;
name|d
operator|->
name|isFile
operator|=
name|isFile
expr_stmt|;
name|d
operator|->
name|isSymLink
operator|=
name|isSymLink
expr_stmt|;
name|d
operator|->
name|isWritable
operator|=
name|isWritable
expr_stmt|;
name|d
operator|->
name|isReadable
operator|=
name|isReadable
expr_stmt|;
name|d
operator|->
name|isExecutable
operator|=
name|isExecutable
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Sets the name of the URL to \a name. The name is the full text,     for example, "http://qt.nokia.com/doc/qurlinfo.html".      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setName
name|void
name|QUrlInfo
operator|::
name|setName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|name
operator|=
name|name
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     If \a b is true then the URL is set to be a directory; if \a b is     false then the URL is set not to be a directory (which normally     means it is a file). (Note that a URL can refer to both a file and     a directory even though most file systems do not support this.)      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setDir
name|void
name|QUrlInfo
operator|::
name|setDir
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|isDir
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     If \a b is true then the URL is set to be a file; if \b is false     then the URL is set not to be a file (which normally means it is a     directory). (Note that a URL can refer to both a file and a     directory even though most file systems do not support this.)      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setFile
name|void
name|QUrlInfo
operator|::
name|setFile
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|isFile
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Specifies that the URL refers to a symbolic link if \a b is true     and that it does not if \a b is false.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setSymLink
name|void
name|QUrlInfo
operator|::
name|setSymLink
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|isSymLink
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Specifies that the URL is writable if \a b is true and not     writable if \a b is false.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setWritable
name|void
name|QUrlInfo
operator|::
name|setWritable
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|isWritable
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Specifies that the URL is readable if \a b is true and not     readable if \a b is false.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setReadable
name|void
name|QUrlInfo
operator|::
name|setReadable
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|isReadable
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Specifies that the owner of the URL is called \a s.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setOwner
name|void
name|QUrlInfo
operator|::
name|setOwner
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|owner
operator|=
name|s
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Specifies that the owning group of the URL is called \a s.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setGroup
name|void
name|QUrlInfo
operator|::
name|setGroup
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|group
operator|=
name|s
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Specifies the \a size of the URL.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setSize
name|void
name|QUrlInfo
operator|::
name|setSize
parameter_list|(
name|qint64
name|size
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|size
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Specifies that the URL has access permissions \a p.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setPermissions
name|void
name|QUrlInfo
operator|::
name|setPermissions
parameter_list|(
name|int
name|p
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|permissions
operator|=
name|p
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Specifies that the object the URL refers to was last modified at     \a dt.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setLastModified
name|void
name|QUrlInfo
operator|::
name|setLastModified
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|dt
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|lastModified
operator|=
name|dt
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4      Specifies that the object the URL refers to was last read at     \a dt.      If you call this function for an invalid URL info, this function     turns it into a valid one.      \sa isValid() */
end_comment
begin_function
DECL|function|setLastRead
name|void
name|QUrlInfo
operator|::
name|setLastRead
parameter_list|(
specifier|const
name|QDateTime
modifier|&
name|dt
parameter_list|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
name|d
operator|->
name|lastRead
operator|=
name|dt
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Destroys the URL info object. */
end_comment
begin_destructor
DECL|function|~QUrlInfo
name|QUrlInfo
operator|::
name|~
name|QUrlInfo
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Assigns the values of \a ui to this QUrlInfo object. */
end_comment
begin_function
DECL|function|operator =
name|QUrlInfo
modifier|&
name|QUrlInfo
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|ui
parameter_list|)
block|{
if|if
condition|(
name|ui
operator|.
name|d
condition|)
block|{
if|if
condition|(
operator|!
name|d
condition|)
name|d
operator|=
operator|new
name|QUrlInfoPrivate
expr_stmt|;
operator|*
name|d
operator|=
operator|*
name|ui
operator|.
name|d
expr_stmt|;
block|}
else|else
block|{
operator|delete
name|d
expr_stmt|;
name|d
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the file name of the URL.      \sa isValid() */
end_comment
begin_function
DECL|function|name
name|QString
name|QUrlInfo
operator|::
name|name
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the permissions of the URL. You can use the \c PermissionSpec flags     to test for certain permissions.      \sa isValid() */
end_comment
begin_function
DECL|function|permissions
name|int
name|QUrlInfo
operator|::
name|permissions
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|0
return|;
return|return
name|d
operator|->
name|permissions
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the owner of the URL.      \sa isValid() */
end_comment
begin_function
DECL|function|owner
name|QString
name|QUrlInfo
operator|::
name|owner
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|d
operator|->
name|owner
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the group of the URL.      \sa isValid() */
end_comment
begin_function
DECL|function|group
name|QString
name|QUrlInfo
operator|::
name|group
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QString
argument_list|()
return|;
return|return
name|d
operator|->
name|group
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the size of the URL.      \sa isValid() */
end_comment
begin_function
DECL|function|size
name|qint64
name|QUrlInfo
operator|::
name|size
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|0
return|;
return|return
name|d
operator|->
name|size
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the last modification date of the URL.      \sa isValid() */
end_comment
begin_function
DECL|function|lastModified
name|QDateTime
name|QUrlInfo
operator|::
name|lastModified
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QDateTime
argument_list|()
return|;
return|return
name|d
operator|->
name|lastModified
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the date when the URL was last read.      \sa isValid() */
end_comment
begin_function
DECL|function|lastRead
name|QDateTime
name|QUrlInfo
operator|::
name|lastRead
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QDateTime
argument_list|()
return|;
return|return
name|d
operator|->
name|lastRead
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the URL is a directory; otherwise returns false.      \sa isValid() */
end_comment
begin_function
DECL|function|isDir
name|bool
name|QUrlInfo
operator|::
name|isDir
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|isDir
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the URL is a file; otherwise returns false.      \sa isValid() */
end_comment
begin_function
DECL|function|isFile
name|bool
name|QUrlInfo
operator|::
name|isFile
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|isFile
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the URL is a symbolic link; otherwise returns false.      \sa isValid() */
end_comment
begin_function
DECL|function|isSymLink
name|bool
name|QUrlInfo
operator|::
name|isSymLink
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|isSymLink
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the URL is writable; otherwise returns false.      \sa isValid() */
end_comment
begin_function
DECL|function|isWritable
name|bool
name|QUrlInfo
operator|::
name|isWritable
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|isWritable
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the URL is readable; otherwise returns false.      \sa isValid() */
end_comment
begin_function
DECL|function|isReadable
name|bool
name|QUrlInfo
operator|::
name|isReadable
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|isReadable
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the URL is executable; otherwise returns false.      \sa isValid() */
end_comment
begin_function
DECL|function|isExecutable
name|bool
name|QUrlInfo
operator|::
name|isExecutable
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
return|return
name|d
operator|->
name|isExecutable
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if \a i1 is greater than \a i2; otherwise returns     false. The objects are compared by the value, which is specified     by \a sortBy. This must be one of QDir::Name, QDir::Time or     QDir::Size. */
end_comment
begin_function
DECL|function|greaterThan
name|bool
name|QUrlInfo
operator|::
name|greaterThan
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|i1
parameter_list|,
specifier|const
name|QUrlInfo
modifier|&
name|i2
parameter_list|,
name|int
name|sortBy
parameter_list|)
block|{
switch|switch
condition|(
name|sortBy
condition|)
block|{
case|case
name|QDir
operator|::
name|Name
case|:
return|return
name|i1
operator|.
name|name
argument_list|()
operator|>
name|i2
operator|.
name|name
argument_list|()
return|;
case|case
name|QDir
operator|::
name|Time
case|:
return|return
name|i1
operator|.
name|lastModified
argument_list|()
operator|>
name|i2
operator|.
name|lastModified
argument_list|()
return|;
case|case
name|QDir
operator|::
name|Size
case|:
return|return
name|i1
operator|.
name|size
argument_list|()
operator|>
name|i2
operator|.
name|size
argument_list|()
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns true if \a i1 is less than \a i2; otherwise returns false.     The objects are compared by the value, which is specified by \a     sortBy. This must be one of QDir::Name, QDir::Time or QDir::Size. */
end_comment
begin_function
DECL|function|lessThan
name|bool
name|QUrlInfo
operator|::
name|lessThan
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|i1
parameter_list|,
specifier|const
name|QUrlInfo
modifier|&
name|i2
parameter_list|,
name|int
name|sortBy
parameter_list|)
block|{
return|return
operator|!
name|greaterThan
argument_list|(
name|i1
argument_list|,
name|i2
argument_list|,
name|sortBy
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if \a i1 equals to \a i2; otherwise returns false.     The objects are compared by the value, which is specified by \a     sortBy. This must be one of QDir::Name, QDir::Time or QDir::Size. */
end_comment
begin_function
DECL|function|equal
name|bool
name|QUrlInfo
operator|::
name|equal
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|i1
parameter_list|,
specifier|const
name|QUrlInfo
modifier|&
name|i2
parameter_list|,
name|int
name|sortBy
parameter_list|)
block|{
switch|switch
condition|(
name|sortBy
condition|)
block|{
case|case
name|QDir
operator|::
name|Name
case|:
return|return
name|i1
operator|.
name|name
argument_list|()
operator|==
name|i2
operator|.
name|name
argument_list|()
return|;
case|case
name|QDir
operator|::
name|Time
case|:
return|return
name|i1
operator|.
name|lastModified
argument_list|()
operator|==
name|i2
operator|.
name|lastModified
argument_list|()
return|;
case|case
name|QDir
operator|::
name|Size
case|:
return|return
name|i1
operator|.
name|size
argument_list|()
operator|==
name|i2
operator|.
name|size
argument_list|()
return|;
default|default:
return|return
literal|false
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns true if this QUrlInfo is equal to \a other; otherwise     returns false.      \sa lessThan(), equal() */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QUrlInfo
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QUrlInfo
modifier|&
name|other
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|other
operator|.
name|d
operator|==
literal|0
return|;
if|if
condition|(
operator|!
name|other
operator|.
name|d
condition|)
return|return
literal|false
return|;
return|return
operator|(
name|d
operator|->
name|name
operator|==
name|other
operator|.
name|d
operator|->
name|name
operator|&&
name|d
operator|->
name|permissions
operator|==
name|other
operator|.
name|d
operator|->
name|permissions
operator|&&
name|d
operator|->
name|owner
operator|==
name|other
operator|.
name|d
operator|->
name|owner
operator|&&
name|d
operator|->
name|group
operator|==
name|other
operator|.
name|d
operator|->
name|group
operator|&&
name|d
operator|->
name|size
operator|==
name|other
operator|.
name|d
operator|->
name|size
operator|&&
name|d
operator|->
name|lastModified
operator|==
name|other
operator|.
name|d
operator|->
name|lastModified
operator|&&
name|d
operator|->
name|lastRead
operator|==
name|other
operator|.
name|d
operator|->
name|lastRead
operator|&&
name|d
operator|->
name|isDir
operator|==
name|other
operator|.
name|d
operator|->
name|isDir
operator|&&
name|d
operator|->
name|isFile
operator|==
name|other
operator|.
name|d
operator|->
name|isFile
operator|&&
name|d
operator|->
name|isSymLink
operator|==
name|other
operator|.
name|d
operator|->
name|isSymLink
operator|&&
name|d
operator|->
name|isWritable
operator|==
name|other
operator|.
name|d
operator|->
name|isWritable
operator|&&
name|d
operator|->
name|isReadable
operator|==
name|other
operator|.
name|d
operator|->
name|isReadable
operator|&&
name|d
operator|->
name|isExecutable
operator|==
name|other
operator|.
name|d
operator|->
name|isExecutable
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QUrlInfo::operator!=(const QUrlInfo&other) const     \since 4.2      Returns true if this QUrlInfo is not equal to \a other; otherwise     returns false.      \sa lessThan(), equal() */
end_comment
begin_comment
comment|/*!     Returns true if the URL info is valid; otherwise returns false.     Valid means that the QUrlInfo contains real information.      You should always check if the URL info is valid before relying on     the values. */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QUrlInfo
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|!=
literal|0
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
comment|// QT_NO_URLINFO
end_comment
end_unit
