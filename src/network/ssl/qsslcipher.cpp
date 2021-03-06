begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QSslCipher     \brief The QSslCipher class represents an SSL cryptographic cipher.     \since 4.3      \reentrant     \ingroup network     \ingroup ssl     \ingroup shared     \inmodule QtNetwork      QSslCipher stores information about one cryptographic cipher. It     is most commonly used with QSslSocket, either for configuring     which ciphers the socket can use, or for displaying the socket's     ciphers to the user.      \sa QSslSocket, QSslKey */
end_comment
begin_include
include|#
directive|include
file|"qsslcipher.h"
end_include
begin_include
include|#
directive|include
file|"qsslcipher_p.h"
end_include
begin_include
include|#
directive|include
file|"qsslsocket.h"
end_include
begin_include
include|#
directive|include
file|"qsslconfiguration.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     Constructs an empty QSslCipher object. */
end_comment
begin_constructor
DECL|function|QSslCipher
name|QSslCipher
operator|::
name|QSslCipher
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslCipherPrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \since 5.3      Constructs a QSslCipher object for the cipher determined by \a     name. The constructor accepts only supported ciphers (i.e., the     \a name must identify a cipher in the list of ciphers returned by     QSslSocket::supportedCiphers()).      You can call isNull() after construction to check if \a name     correctly identified a supported cipher. */
end_comment
begin_constructor
DECL|function|QSslCipher
name|QSslCipher
operator|::
name|QSslCipher
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslCipherPrivate
argument_list|)
block|{
specifier|const
specifier|auto
name|ciphers
init|=
name|QSslConfiguration
operator|::
name|supportedCiphers
argument_list|()
decl_stmt|;
for|for
control|(
specifier|const
name|QSslCipher
modifier|&
name|cipher
range|:
name|ciphers
control|)
block|{
if|if
condition|(
name|cipher
operator|.
name|name
argument_list|()
operator|==
name|name
condition|)
block|{
operator|*
name|this
operator|=
name|cipher
expr_stmt|;
return|return;
block|}
block|}
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QSslCipher object for the cipher determined by \a     name and \a protocol. The constructor accepts only supported     ciphers (i.e., the \a name and \a protocol must identify a cipher     in the list of ciphers returned by     QSslSocket::supportedCiphers()).      You can call isNull() after construction to check if \a name and     \a protocol correctly identified a supported cipher. */
end_comment
begin_constructor
DECL|function|QSslCipher
name|QSslCipher
operator|::
name|QSslCipher
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QSsl
operator|::
name|SslProtocol
name|protocol
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslCipherPrivate
argument_list|)
block|{
specifier|const
specifier|auto
name|ciphers
init|=
name|QSslConfiguration
operator|::
name|supportedCiphers
argument_list|()
decl_stmt|;
for|for
control|(
specifier|const
name|QSslCipher
modifier|&
name|cipher
range|:
name|ciphers
control|)
block|{
if|if
condition|(
name|cipher
operator|.
name|name
argument_list|()
operator|==
name|name
operator|&&
name|cipher
operator|.
name|protocol
argument_list|()
operator|==
name|protocol
condition|)
block|{
operator|*
name|this
operator|=
name|cipher
expr_stmt|;
return|return;
block|}
block|}
block|}
end_constructor
begin_comment
comment|/*!     Constructs an identical copy of the \a other cipher. */
end_comment
begin_constructor
DECL|function|QSslCipher
name|QSslCipher
operator|::
name|QSslCipher
parameter_list|(
specifier|const
name|QSslCipher
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
operator|new
name|QSslCipherPrivate
argument_list|)
block|{
operator|*
name|d
operator|.
name|data
argument_list|()
operator|=
operator|*
name|other
operator|.
name|d
operator|.
name|data
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QSslCipher object. */
end_comment
begin_destructor
DECL|function|~QSslCipher
name|QSslCipher
operator|::
name|~
name|QSslCipher
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Copies the contents of \a other into this cipher, making the two     ciphers identical. */
end_comment
begin_function
DECL|function|operator =
name|QSslCipher
modifier|&
name|QSslCipher
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QSslCipher
modifier|&
name|other
parameter_list|)
block|{
operator|*
name|d
operator|.
name|data
argument_list|()
operator|=
operator|*
name|other
operator|.
name|d
operator|.
name|data
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QSslCipher::swap(QSslCipher&other)     \since 5.0      Swaps this cipher instance with \a other. This function is very     fast and never fails. */
end_comment
begin_comment
comment|/*!     Returns \c true if this cipher is the same as \a other; otherwise,     false is returned. */
end_comment
begin_function
DECL|function|operator ==
name|bool
name|QSslCipher
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QSslCipher
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
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
name|protocol
operator|==
name|other
operator|.
name|d
operator|->
name|protocol
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QSslCipher::operator!=(const QSslCipher&other) const      Returns \c true if this cipher is not the same as \a other;     otherwise, false is returned. */
end_comment
begin_comment
comment|/*!     Returns \c true if this is a null cipher; otherwise returns \c false. */
end_comment
begin_function
DECL|function|isNull
name|bool
name|QSslCipher
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|isNull
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the name of the cipher, or an empty QString if this is a null     cipher.      \sa isNull() */
end_comment
begin_function
DECL|function|name
name|QString
name|QSslCipher
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|name
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of bits supported by the cipher.      \sa usedBits() */
end_comment
begin_function
DECL|function|supportedBits
name|int
name|QSslCipher
operator|::
name|supportedBits
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|supportedBits
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of bits used by the cipher.      \sa supportedBits() */
end_comment
begin_function
DECL|function|usedBits
name|int
name|QSslCipher
operator|::
name|usedBits
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|bits
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the cipher's key exchange method as a QString. */
end_comment
begin_function
DECL|function|keyExchangeMethod
name|QString
name|QSslCipher
operator|::
name|keyExchangeMethod
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|keyExchangeMethod
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the cipher's authentication method as a QString. */
end_comment
begin_function
DECL|function|authenticationMethod
name|QString
name|QSslCipher
operator|::
name|authenticationMethod
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|authenticationMethod
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the cipher's encryption method as a QString. */
end_comment
begin_function
DECL|function|encryptionMethod
name|QString
name|QSslCipher
operator|::
name|encryptionMethod
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|encryptionMethod
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the cipher's protocol as a QString.      \sa protocol() */
end_comment
begin_function
DECL|function|protocolString
name|QString
name|QSslCipher
operator|::
name|protocolString
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|protocolString
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the cipher's protocol type, or \l QSsl::UnknownProtocol if     QSslCipher is unable to determine the protocol (protocolString() may     contain more information).      \sa protocolString() */
end_comment
begin_function
DECL|function|protocol
name|QSsl
operator|::
name|SslProtocol
name|QSslCipher
operator|::
name|protocol
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|protocol
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
specifier|const
name|QSslCipher
modifier|&
name|cipher
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|debug
argument_list|)
decl_stmt|;
name|debug
operator|.
name|resetFormat
argument_list|()
operator|.
name|nospace
argument_list|()
operator|.
name|noquote
argument_list|()
expr_stmt|;
name|debug
operator|<<
literal|"QSslCipher(name="
operator|<<
name|cipher
operator|.
name|name
argument_list|()
operator|<<
literal|", bits="
operator|<<
name|cipher
operator|.
name|usedBits
argument_list|()
operator|<<
literal|", proto="
operator|<<
name|cipher
operator|.
name|protocolString
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|debug
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
