begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusextratypes.h"
end_include
begin_include
include|#
directive|include
file|"qdbusutil_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|doCheck
name|void
name|QDBusObjectPath
operator|::
name|doCheck
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidObjectPath
argument_list|(
name|m_path
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QDBusObjectPath: invalid path \"%s\""
argument_list|,
name|qPrintable
argument_list|(
name|m_path
argument_list|)
argument_list|)
expr_stmt|;
name|m_path
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|doCheck
name|void
name|QDBusSignature
operator|::
name|doCheck
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QDBusUtil
operator|::
name|isValidSignature
argument_list|(
name|m_signature
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QDBusSignature: invalid signature \"%s\""
argument_list|,
name|qPrintable
argument_list|(
name|m_signature
argument_list|)
argument_list|)
expr_stmt|;
name|m_signature
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \class QDBusVariant     \inmodule QtDBus     \since 4.2      \brief The QDBusVariant class enables the programmer to identify     the variant type provided by the D-Bus typesystem.      A D-Bus function that takes an integer, a D-Bus variant and a string as parameters     can be called with the following argument list (see QDBusMessage::setArguments()):      \snippet qdbusextratypes/qdbusextratypes.cpp 0      When a D-Bus function returns a D-Bus variant, it can be retrieved as follows:      \snippet qdbusextratypes/qdbusextratypes.cpp 1      The QVariant within a QDBusVariant is required to distinguish between a normal     D-Bus value and a value within a D-Bus variant.      \sa {The Qt D-Bus Type System} */
end_comment
begin_comment
comment|/*!     \fn QDBusVariant::QDBusVariant()      Constructs a new D-Bus variant. */
end_comment
begin_comment
comment|/*!     \fn QDBusVariant::QDBusVariant(const QVariant&variant)      Constructs a new D-Bus variant from the given Qt \a variant.      \sa setVariant() */
end_comment
begin_comment
comment|/*!     \fn QVariant QDBusVariant::variant() const      Returns this D-Bus variant as a QVariant object.      \sa setVariant() */
end_comment
begin_comment
comment|/*!     \fn void QDBusVariant::setVariant(const QVariant&variant)      Assigns the value of the given Qt \a variant to this D-Bus variant.      \sa variant() */
end_comment
begin_comment
comment|/*!     \class QDBusObjectPath     \inmodule QtDBus     \since 4.2      \brief The QDBusObjectPath class enables the programmer to     identify the OBJECT_PATH type provided by the D-Bus typesystem.      \sa {The Qt D-Bus Type System} */
end_comment
begin_comment
comment|/*!     \fn QDBusObjectPath::QDBusObjectPath()      Constructs a new object path. */
end_comment
begin_comment
comment|/*!     \fn QDBusObjectPath::QDBusObjectPath(const char *path)      Constructs a new object path from the given \a path.      \sa setPath() */
end_comment
begin_comment
comment|/*!     \fn QDBusObjectPath::QDBusObjectPath(QLatin1String path)      Constructs a new object path from the given \a path. */
end_comment
begin_comment
comment|/*!     \fn QDBusObjectPath::QDBusObjectPath(const QString&path)      Constructs a new object path from the given \a path. */
end_comment
begin_comment
comment|/*!     \fn QString QDBusObjectPath::path() const      Returns this object path.      \sa setPath() */
end_comment
begin_comment
comment|/*!     \fn void QDBusObjectPath::setPath(const QString&path)      Assigns the value of the given \a path to this object path.      \sa path() */
end_comment
begin_comment
comment|/*!     \class QDBusSignature     \inmodule QtDBus     \since 4.2      \brief The QDBusSignature class enables the programmer to     identify the SIGNATURE type provided by the D-Bus typesystem.      \sa {The Qt D-Bus Type System} */
end_comment
begin_comment
comment|/*!     \fn QDBusSignature::QDBusSignature()      Constructs a new signature.      \sa setSignature() */
end_comment
begin_comment
comment|/*!     \fn QDBusSignature::QDBusSignature(const char *signature)      Constructs a new signature from the given \a signature. */
end_comment
begin_comment
comment|/*!     \fn QDBusSignature::QDBusSignature(QLatin1String signature)      Constructs a new signature from the given \a signature. */
end_comment
begin_comment
comment|/*!     \fn QDBusSignature::QDBusSignature(const QString&signature)      Constructs a new signature from the given \a signature. */
end_comment
begin_comment
comment|/*!     \fn QString QDBusSignature::signature() const      Returns this signature.      \sa setSignature() */
end_comment
begin_comment
comment|/*!     \fn void QDBusSignature::setSignature(const QString&signature)      Assigns the value of the given \a signature to this signature.     \sa signature() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
end_unit
