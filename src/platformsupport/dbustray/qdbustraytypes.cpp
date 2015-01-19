begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 Marco Martin<notmart@gmail.com> ** Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_include
include|#
directive|include
file|"qdbustraytypes_p.h"
end_include
begin_include
include|#
directive|include
file|<QDBusConnection>
end_include
begin_include
include|#
directive|include
file|<QDBusMetaType>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtEndian>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|"qdbusplatformmenu_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|IconSizeLimit
specifier|static
specifier|const
name|int
name|IconSizeLimit
init|=
literal|32
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|IconNormalSmallSize
specifier|static
specifier|const
name|int
name|IconNormalSmallSize
init|=
literal|22
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|iconToQXdgDBusImageVector
name|QXdgDBusImageVector
name|iconToQXdgDBusImageVector
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|QXdgDBusImageVector
name|ret
decl_stmt|;
name|QList
argument_list|<
name|QSize
argument_list|>
name|sizes
init|=
name|icon
operator|.
name|availableSizes
argument_list|()
decl_stmt|;
comment|// Omit any size larger than 32 px, to save D-Bus bandwidth;
comment|// and ensure that 22px or smaller exists, because it's a common size.
name|bool
name|hasSmallIcon
init|=
literal|false
decl_stmt|;
name|QList
argument_list|<
name|QSize
argument_list|>
name|toRemove
decl_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QSize&size
argument_list|,
argument|sizes
argument_list|)
block|{
name|int
name|maxSize
init|=
name|qMax
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|maxSize
operator|<=
name|IconNormalSmallSize
condition|)
name|hasSmallIcon
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|maxSize
operator|>
name|IconSizeLimit
condition|)
name|toRemove
operator|<<
name|size
expr_stmt|;
block|}
name|Q_FOREACH
argument_list|(
argument|const QSize&size
argument_list|,
argument|toRemove
argument_list|)
name|sizes
operator|.
name|removeOne
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hasSmallIcon
condition|)
name|sizes
operator|.
name|append
argument_list|(
name|QSize
argument_list|(
name|IconNormalSmallSize
argument_list|,
name|IconNormalSmallSize
argument_list|)
argument_list|)
expr_stmt|;
foreach|foreach
control|(
name|QSize
name|size
decl|,
name|sizes
control|)
block|{
comment|// Protocol specifies ARGB32 format in network byte order
name|QImage
name|im
init|=
name|icon
operator|.
name|pixmap
argument_list|(
name|size
argument_list|)
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
comment|// letterbox if necessary to make it square
if|if
condition|(
name|im
operator|.
name|height
argument_list|()
operator|!=
name|im
operator|.
name|width
argument_list|()
condition|)
block|{
name|int
name|maxSize
init|=
name|qMax
argument_list|(
name|im
operator|.
name|width
argument_list|()
argument_list|,
name|im
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QImage
name|padded
argument_list|(
name|maxSize
argument_list|,
name|maxSize
argument_list|,
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
name|padded
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|padded
argument_list|)
decl_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
operator|(
name|maxSize
operator|-
name|im
operator|.
name|width
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
operator|(
name|maxSize
operator|-
name|im
operator|.
name|height
argument_list|()
operator|)
operator|/
literal|2
argument_list|,
name|im
argument_list|)
expr_stmt|;
name|im
operator|=
name|padded
expr_stmt|;
block|}
name|QXdgDBusImageStruct
name|kim
decl_stmt|;
name|kim
operator|.
name|width
operator|=
name|im
operator|.
name|width
argument_list|()
expr_stmt|;
name|kim
operator|.
name|height
operator|=
name|im
operator|.
name|height
argument_list|()
expr_stmt|;
name|kim
operator|.
name|data
operator|=
name|QByteArray
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|im
operator|.
name|constBits
argument_list|()
argument_list|)
argument_list|,
name|im
operator|.
name|byteCount
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|QSysInfo
operator|::
name|ByteOrder
operator|==
name|QSysInfo
operator|::
name|LittleEndian
condition|)
block|{
for|for
control|(
name|char
modifier|*
name|ptr
init|=
name|kim
operator|.
name|data
operator|.
name|begin
argument_list|()
init|;
name|ptr
operator|<
name|kim
operator|.
name|data
operator|.
name|end
argument_list|()
condition|;
name|ptr
operator|+=
literal|4
control|)
name|qToUnaligned
argument_list|(
name|qToBigEndian
argument_list|<
name|quint32
argument_list|>
argument_list|(
operator|*
name|ptr
argument_list|)
argument_list|,
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|ptr
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|ret
operator|<<
name|kim
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_comment
comment|// Marshall the ImageStruct data into a D-Bus argument
end_comment
begin_function
DECL|function|operator <<
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QXdgDBusImageStruct
modifier|&
name|icon
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|icon
operator|.
name|width
expr_stmt|;
name|argument
operator|<<
name|icon
operator|.
name|height
expr_stmt|;
name|argument
operator|<<
name|icon
operator|.
name|data
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|// Retrieve the ImageStruct data from the D-Bus argument
end_comment
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QXdgDBusImageStruct
modifier|&
name|icon
parameter_list|)
block|{
name|qint32
name|width
decl_stmt|;
name|qint32
name|height
decl_stmt|;
name|QByteArray
name|data
decl_stmt|;
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|width
expr_stmt|;
name|argument
operator|>>
name|height
expr_stmt|;
name|argument
operator|>>
name|data
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
name|icon
operator|.
name|width
operator|=
name|width
expr_stmt|;
name|icon
operator|.
name|height
operator|=
name|height
expr_stmt|;
name|icon
operator|.
name|data
operator|=
name|data
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|// Marshall the ImageVector data into a D-Bus argument
end_comment
begin_function
DECL|function|operator <<
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QXdgDBusImageVector
modifier|&
name|iconVector
parameter_list|)
block|{
name|argument
operator|.
name|beginArray
argument_list|(
name|qMetaTypeId
argument_list|<
name|QXdgDBusImageStruct
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iconVector
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|argument
operator|<<
name|iconVector
index|[
name|i
index|]
expr_stmt|;
block|}
name|argument
operator|.
name|endArray
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|// Retrieve the ImageVector data from the D-Bus argument
end_comment
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QXdgDBusImageVector
modifier|&
name|iconVector
parameter_list|)
block|{
name|argument
operator|.
name|beginArray
argument_list|()
expr_stmt|;
name|iconVector
operator|.
name|clear
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|argument
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QXdgDBusImageStruct
name|element
decl_stmt|;
name|argument
operator|>>
name|element
expr_stmt|;
name|iconVector
operator|.
name|append
argument_list|(
name|element
argument_list|)
expr_stmt|;
block|}
name|argument
operator|.
name|endArray
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|// Marshall the ToolTipStruct data into a D-Bus argument
end_comment
begin_function
DECL|function|operator <<
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|QXdgDBusToolTipStruct
modifier|&
name|toolTip
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|toolTip
operator|.
name|icon
expr_stmt|;
name|argument
operator|<<
name|toolTip
operator|.
name|image
expr_stmt|;
name|argument
operator|<<
name|toolTip
operator|.
name|title
expr_stmt|;
name|argument
operator|<<
name|toolTip
operator|.
name|subTitle
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|// Retrieve the ToolTipStruct data from the D-Bus argument
end_comment
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|QXdgDBusToolTipStruct
modifier|&
name|toolTip
parameter_list|)
block|{
name|QString
name|icon
decl_stmt|;
name|QXdgDBusImageVector
name|image
decl_stmt|;
name|QString
name|title
decl_stmt|;
name|QString
name|subTitle
decl_stmt|;
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|icon
expr_stmt|;
name|argument
operator|>>
name|image
expr_stmt|;
name|argument
operator|>>
name|title
expr_stmt|;
name|argument
operator|>>
name|subTitle
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
name|toolTip
operator|.
name|icon
operator|=
name|icon
expr_stmt|;
name|toolTip
operator|.
name|image
operator|=
name|image
expr_stmt|;
name|toolTip
operator|.
name|title
operator|=
name|title
expr_stmt|;
name|toolTip
operator|.
name|subTitle
operator|=
name|subTitle
expr_stmt|;
return|return
name|argument
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
comment|// QT_NO_SYSTEMTRAYICON
end_comment
end_unit
