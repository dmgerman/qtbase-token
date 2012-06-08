begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnetworkcookiejar.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkcookiejar_p.h"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qnetworkcookie.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qurl.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatetime.h"
end_include
begin_include
include|#
directive|include
file|"private/qtldurl_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QNetworkCookieJar     \since 4.4     \inmodule QtNetwork      \brief The QNetworkCookieJar class implements a simple jar of QNetworkCookie objects      Cookies are small bits of information that stateless protocols     like HTTP use to maintain some persistent information across     requests.      A cookie is set by a remote server when it replies to a request     and it expects the same cookie to be sent back when further     requests are sent.      The cookie jar is the object that holds all cookies set in     previous requests. Web browsers save their cookie jars to disk in     order to conserve permanent cookies across invocations of the     application.      QNetworkCookieJar does not implement permanent storage: it only     keeps the cookies in memory. Once the QNetworkCookieJar object is     deleted, all cookies it held will be discarded as well. If you     want to save the cookies, you should derive from this class and     implement the saving to disk to your own storage format.      This class implements only the basic security recommended by the     cookie specifications and does not implement any cookie acceptance     policy (it accepts all cookies set by any requests). In order to     override those rules, you should reimplement the     cookiesForUrl() and setCookiesFromUrl() virtual     functions. They are called by QNetworkReply and     QNetworkAccessManager when they detect new cookies and when they     require cookies.      \sa QNetworkCookie, QNetworkAccessManager, QNetworkReply,     QNetworkRequest, QNetworkAccessManager::setCookieJar() */
end_comment
begin_comment
comment|/*!     Creates a QNetworkCookieJar object and sets the parent object to     be \a parent.      The cookie jar is initialized to empty. */
end_comment
begin_constructor
DECL|function|QNetworkCookieJar
name|QNetworkCookieJar
operator|::
name|QNetworkCookieJar
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QNetworkCookieJarPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys this cookie jar object and discards all cookies stored in     it. Cookies are not saved to disk in the QNetworkCookieJar default     implementation.      If you need to save the cookies to disk, you have to derive from     QNetworkCookieJar and save the cookies to disk yourself. */
end_comment
begin_destructor
DECL|function|~QNetworkCookieJar
name|QNetworkCookieJar
operator|::
name|~
name|QNetworkCookieJar
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns all cookies stored in this cookie jar. This function is     suitable for derived classes to save cookies to disk, as well as     to implement cookie expiration and other policies.      \sa setAllCookies(), cookiesForUrl() */
end_comment
begin_function
DECL|function|allCookies
name|QList
argument_list|<
name|QNetworkCookie
argument_list|>
name|QNetworkCookieJar
operator|::
name|allCookies
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|allCookies
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the internal list of cookies held by this cookie jar to be \a     cookieList. This function is suitable for derived classes to     implement loading cookies from permanent storage, or their own     cookie acceptance policies by reimplementing     setCookiesFromUrl().      \sa allCookies(), setCookiesFromUrl() */
end_comment
begin_function
DECL|function|setAllCookies
name|void
name|QNetworkCookieJar
operator|::
name|setAllCookies
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QNetworkCookie
argument_list|>
modifier|&
name|cookieList
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkCookieJar
argument_list|)
expr_stmt|;
name|d
operator|->
name|allCookies
operator|=
name|cookieList
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isParentPath
specifier|static
specifier|inline
name|bool
name|isParentPath
parameter_list|(
name|QString
name|path
parameter_list|,
name|QString
name|reference
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|startsWith
argument_list|(
name|reference
argument_list|)
condition|)
block|{
comment|//The cookie-path and the request-path are identical.
if|if
condition|(
name|path
operator|.
name|length
argument_list|()
operator|==
name|reference
operator|.
name|length
argument_list|()
condition|)
return|return
literal|true
return|;
comment|//The cookie-path is a prefix of the request-path, and the last
comment|//character of the cookie-path is %x2F ("/").
if|if
condition|(
name|reference
operator|.
name|endsWith
argument_list|(
literal|'/'
argument_list|)
condition|)
return|return
literal|true
return|;
comment|//The cookie-path is a prefix of the request-path, and the first
comment|//character of the request-path that is not included in the cookie-
comment|//path is a %x2F ("/") character.
if|if
condition|(
name|path
operator|.
name|at
argument_list|(
name|reference
operator|.
name|length
argument_list|()
argument_list|)
operator|==
literal|'/'
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|isParentDomain
specifier|static
specifier|inline
name|bool
name|isParentDomain
parameter_list|(
name|QString
name|domain
parameter_list|,
name|QString
name|reference
parameter_list|)
block|{
if|if
condition|(
operator|!
name|reference
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
condition|)
return|return
name|domain
operator|==
name|reference
return|;
return|return
name|domain
operator|.
name|endsWith
argument_list|(
name|reference
argument_list|)
operator|||
name|domain
operator|==
name|reference
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Adds the cookies in the list \a cookieList to this cookie     jar. Before being inserted cookies are normalized.      Returns true if one or more cookies are set for \a url,     otherwise false.      If a cookie already exists in the cookie jar, it will be     overridden by those in \a cookieList.      The default QNetworkCookieJar class implements only a very basic     security policy (it makes sure that the cookies' domain and path     match the reply's). To enhance the security policy with your own     algorithms, override setCookiesFromUrl().      Also, QNetworkCookieJar does not have a maximum cookie jar     size. Reimplement this function to discard older cookies to create     room for new ones.      \sa cookiesForUrl(), QNetworkAccessManager::setCookieJar(), QNetworkCookie::normalize() */
end_comment
begin_function
DECL|function|setCookiesFromUrl
name|bool
name|QNetworkCookieJar
operator|::
name|setCookiesFromUrl
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QNetworkCookie
argument_list|>
modifier|&
name|cookieList
parameter_list|,
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|bool
name|added
init|=
literal|false
decl_stmt|;
foreach|foreach
control|(
name|QNetworkCookie
name|cookie
decl|,
name|cookieList
control|)
block|{
name|cookie
operator|.
name|normalize
argument_list|(
name|url
argument_list|)
expr_stmt|;
if|if
condition|(
name|validateCookie
argument_list|(
name|cookie
argument_list|,
name|url
argument_list|)
operator|&&
name|insertCookie
argument_list|(
name|cookie
argument_list|)
condition|)
name|added
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|added
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the cookies to be added to when a request is sent to     \a url. This function is called by the default     QNetworkAccessManager::createRequest(), which adds the     cookies returned by this function to the request being sent.      If more than one cookie with the same name is found, but with     differing paths, the one with longer path is returned before the     one with shorter path. In other words, this function returns     cookies sorted decreasingly by path length.      The default QNetworkCookieJar class implements only a very basic     security policy (it makes sure that the cookies' domain and path     match the reply's). To enhance the security policy with your own     algorithms, override cookiesForUrl().      \sa setCookiesFromUrl(), QNetworkAccessManager::setCookieJar() */
end_comment
begin_function
DECL|function|cookiesForUrl
name|QList
argument_list|<
name|QNetworkCookie
argument_list|>
name|QNetworkCookieJar
operator|::
name|cookiesForUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
specifier|const
block|{
comment|//     \b Warning! This is only a dumb implementation!
comment|//     It does NOT follow all of the recommendations from
comment|//     http://wp.netscape.com/newsref/std/cookie_spec.html
comment|//     It does not implement a very good cross-domain verification yet.
name|Q_D
argument_list|(
specifier|const
name|QNetworkCookieJar
argument_list|)
expr_stmt|;
name|QDateTime
name|now
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QNetworkCookie
argument_list|>
name|result
decl_stmt|;
name|bool
name|isEncrypted
init|=
name|url
operator|.
name|scheme
argument_list|()
operator|.
name|toLower
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"https"
argument_list|)
decl_stmt|;
comment|// scan our cookies for something that matches
name|QList
argument_list|<
name|QNetworkCookie
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|d
operator|->
name|allCookies
operator|.
name|constBegin
argument_list|()
decl_stmt|,
name|end
init|=
name|d
operator|->
name|allCookies
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|!
name|isParentDomain
argument_list|(
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|it
operator|->
name|domain
argument_list|()
argument_list|)
condition|)
continue|continue;
if|if
condition|(
operator|!
name|isParentPath
argument_list|(
name|url
operator|.
name|path
argument_list|()
argument_list|,
name|it
operator|->
name|path
argument_list|()
argument_list|)
condition|)
continue|continue;
if|if
condition|(
operator|!
operator|(
operator|*
name|it
operator|)
operator|.
name|isSessionCookie
argument_list|()
operator|&&
operator|(
operator|*
name|it
operator|)
operator|.
name|expirationDate
argument_list|()
operator|<
name|now
condition|)
continue|continue;
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|.
name|isSecure
argument_list|()
operator|&&
operator|!
name|isEncrypted
condition|)
continue|continue;
comment|// insert this cookie into result, sorted by path
name|QList
argument_list|<
name|QNetworkCookie
argument_list|>
operator|::
name|Iterator
name|insertIt
init|=
name|result
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|insertIt
operator|!=
name|result
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|insertIt
operator|->
name|path
argument_list|()
operator|.
name|length
argument_list|()
operator|<
name|it
operator|->
name|path
argument_list|()
operator|.
name|length
argument_list|()
condition|)
block|{
comment|// insert here
name|insertIt
operator|=
name|result
operator|.
name|insert
argument_list|(
name|insertIt
argument_list|,
operator|*
name|it
argument_list|)
expr_stmt|;
break|break;
block|}
else|else
block|{
operator|++
name|insertIt
expr_stmt|;
block|}
block|}
comment|// this is the shortest path yet, just append
if|if
condition|(
name|insertIt
operator|==
name|result
operator|.
name|end
argument_list|()
condition|)
name|result
operator|+=
operator|*
name|it
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.0     Adds \a cookie to this cookie jar.      Returns true if \a cookie was added, false otherwise.      If a cookie with the same identifier already exists in the     cookie jar, it will be overridden. */
end_comment
begin_function
DECL|function|insertCookie
name|bool
name|QNetworkCookieJar
operator|::
name|insertCookie
parameter_list|(
specifier|const
name|QNetworkCookie
modifier|&
name|cookie
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkCookieJar
argument_list|)
expr_stmt|;
name|QDateTime
name|now
init|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
decl_stmt|;
name|bool
name|isDeletion
init|=
operator|!
name|cookie
operator|.
name|isSessionCookie
argument_list|()
operator|&&
name|cookie
operator|.
name|expirationDate
argument_list|()
operator|<
name|now
decl_stmt|;
name|deleteCookie
argument_list|(
name|cookie
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isDeletion
condition|)
block|{
name|d
operator|->
name|allCookies
operator|+=
name|cookie
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.0     If a cookie with the same identifier as \a cookie exists in this cookie jar     it will be updated. This function uses insertCookie().      Returns true if \a cookie was updated, false if no cookie in the jar matches     the identifier of \a cookie.      \sa QNetworkCookie::hasSameIdentifier() */
end_comment
begin_function
DECL|function|updateCookie
name|bool
name|QNetworkCookieJar
operator|::
name|updateCookie
parameter_list|(
specifier|const
name|QNetworkCookie
modifier|&
name|cookie
parameter_list|)
block|{
if|if
condition|(
name|deleteCookie
argument_list|(
name|cookie
argument_list|)
condition|)
return|return
name|insertCookie
argument_list|(
name|cookie
argument_list|)
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.0     Deletes from cookie jar the cookie found to have the same identifier as \a cookie.      Returns true if a cookie was deleted, false otherwise.      \sa QNetworkCookie::hasSameIdentifier() */
end_comment
begin_function
DECL|function|deleteCookie
name|bool
name|QNetworkCookieJar
operator|::
name|deleteCookie
parameter_list|(
specifier|const
name|QNetworkCookie
modifier|&
name|cookie
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QNetworkCookieJar
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QNetworkCookie
argument_list|>
operator|::
name|Iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|d
operator|->
name|allCookies
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|d
operator|->
name|allCookies
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
if|if
condition|(
name|it
operator|->
name|hasSameIdentifier
argument_list|(
name|cookie
argument_list|)
condition|)
block|{
name|d
operator|->
name|allCookies
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.0     Returns true if the domain and path of \a cookie are valid, false otherwise.     The \a url parameter is used to determine if the domain specified in the cookie     is allowed. */
end_comment
begin_function
DECL|function|validateCookie
name|bool
name|QNetworkCookieJar
operator|::
name|validateCookie
parameter_list|(
specifier|const
name|QNetworkCookie
modifier|&
name|cookie
parameter_list|,
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
specifier|const
block|{
name|QString
name|domain
init|=
name|cookie
operator|.
name|domain
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|isParentDomain
argument_list|(
name|domain
argument_list|,
name|url
operator|.
name|host
argument_list|()
argument_list|)
operator|||
name|isParentDomain
argument_list|(
name|url
operator|.
name|host
argument_list|()
argument_list|,
name|domain
argument_list|)
operator|)
condition|)
return|return
literal|false
return|;
comment|// not accepted
comment|// the check for effective TLDs makes the "embedded dot" rule from RFC 2109 section 4.3.2
comment|// redundant; the "leading dot" rule has been relaxed anyway, see QNetworkCookie::normalize()
comment|// we remove the leading dot for this check if it's present
if|if
condition|(
name|qIsEffectiveTLD
argument_list|(
name|domain
operator|.
name|startsWith
argument_list|(
literal|'.'
argument_list|)
condition|?
name|domain
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
else|:
name|domain
argument_list|)
condition|)
return|return
literal|false
return|;
comment|// not accepted
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
