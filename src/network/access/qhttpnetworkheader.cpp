begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qhttpnetworkheader_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_HTTP
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QHttpNetworkHeaderPrivate
name|QHttpNetworkHeaderPrivate
operator|::
name|QHttpNetworkHeaderPrivate
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|newUrl
parameter_list|)
member_init_list|:
name|url
argument_list|(
name|newUrl
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QHttpNetworkHeaderPrivate
name|QHttpNetworkHeaderPrivate
operator|::
name|QHttpNetworkHeaderPrivate
parameter_list|(
specifier|const
name|QHttpNetworkHeaderPrivate
modifier|&
name|other
parameter_list|)
member_init_list|:
name|QSharedData
argument_list|(
name|other
argument_list|)
block|{
name|url
operator|=
name|other
operator|.
name|url
expr_stmt|;
name|fields
operator|=
name|other
operator|.
name|fields
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|contentLength
name|qint64
name|QHttpNetworkHeaderPrivate
operator|::
name|contentLength
parameter_list|()
specifier|const
block|{
name|bool
name|ok
init|=
literal|false
decl_stmt|;
comment|// We are not using the headerField() method here because servers might send us multiple content-length
comment|// headers which is crap (see QTBUG-15311). Therefore just take the first content-length header field.
name|QByteArray
name|value
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|fields
operator|.
name|constBegin
argument_list|()
decl_stmt|,
name|end
init|=
name|fields
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
if|if
condition|(
name|qstricmp
argument_list|(
literal|"content-length"
argument_list|,
name|it
operator|->
name|first
argument_list|)
operator|==
literal|0
condition|)
block|{
name|value
operator|=
name|it
operator|->
name|second
expr_stmt|;
break|break;
block|}
name|qint64
name|length
init|=
name|value
operator|.
name|toULongLong
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
return|return
name|length
return|;
return|return
operator|-
literal|1
return|;
comment|// the header field is not set
block|}
end_function
begin_function
DECL|function|setContentLength
name|void
name|QHttpNetworkHeaderPrivate
operator|::
name|setContentLength
parameter_list|(
name|qint64
name|length
parameter_list|)
block|{
name|setHeaderField
argument_list|(
literal|"Content-Length"
argument_list|,
name|QByteArray
operator|::
name|number
argument_list|(
name|length
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|headerField
name|QByteArray
name|QHttpNetworkHeaderPrivate
operator|::
name|headerField
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|defaultValue
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|allValues
init|=
name|headerFieldValues
argument_list|(
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|allValues
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|defaultValue
return|;
name|QByteArray
name|result
decl_stmt|;
name|bool
name|first
init|=
literal|true
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|value
decl|,
name|allValues
control|)
block|{
if|if
condition|(
operator|!
name|first
condition|)
name|result
operator|+=
literal|", "
expr_stmt|;
name|first
operator|=
literal|false
expr_stmt|;
name|result
operator|+=
name|value
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|headerFieldValues
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QHttpNetworkHeaderPrivate
operator|::
name|headerFieldValues
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|)
specifier|const
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|result
decl_stmt|;
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|fields
operator|.
name|constBegin
argument_list|()
decl_stmt|,
name|end
init|=
name|fields
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
if|if
condition|(
name|qstricmp
argument_list|(
name|name
operator|.
name|constData
argument_list|()
argument_list|,
name|it
operator|->
name|first
argument_list|)
operator|==
literal|0
condition|)
name|result
operator|+=
name|it
operator|->
name|second
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|setHeaderField
name|void
name|QHttpNetworkHeaderPrivate
operator|::
name|setHeaderField
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|QList
argument_list|<
name|QPair
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
argument_list|>
operator|::
name|Iterator
name|it
init|=
name|fields
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|fields
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|qstricmp
argument_list|(
name|name
operator|.
name|constData
argument_list|()
argument_list|,
name|it
operator|->
name|first
argument_list|)
operator|==
literal|0
condition|)
name|it
operator|=
name|fields
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
else|else
operator|++
name|it
expr_stmt|;
block|}
name|fields
operator|.
name|append
argument_list|(
name|qMakePair
argument_list|(
name|name
argument_list|,
name|data
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator ==
name|bool
name|QHttpNetworkHeaderPrivate
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QHttpNetworkHeaderPrivate
modifier|&
name|other
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|url
operator|==
name|other
operator|.
name|url
operator|)
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
end_unit
