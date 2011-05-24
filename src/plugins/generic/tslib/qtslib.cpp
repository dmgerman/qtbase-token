begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtslib.h"
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QPoint>
end_include
begin_include
include|#
directive|include
file|<QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<Qt>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<tslib.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QTsLibMouseHandler
name|QTsLibMouseHandler
operator|::
name|QTsLibMouseHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|)
member_init_list|:
name|m_notify
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_x
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_y
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_pressed
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_rawMode
argument_list|(
literal|false
argument_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"QTsLibMouseHandler"
operator|<<
name|key
operator|<<
name|specification
expr_stmt|;
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"TSLib Mouse Handler"
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|device
init|=
literal|"/dev/input/event1"
decl_stmt|;
if|if
condition|(
name|specification
operator|.
name|startsWith
argument_list|(
literal|"/dev/"
argument_list|)
condition|)
name|device
operator|=
name|specification
operator|.
name|toLocal8Bit
argument_list|()
expr_stmt|;
name|m_dev
operator|=
name|ts_open
argument_list|(
name|device
operator|.
name|constData
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|ts_config
argument_list|(
name|m_dev
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"Error configuring\n"
argument_list|)
expr_stmt|;
block|}
name|m_rawMode
operator|=
operator|!
name|key
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"TslibRaw"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
expr_stmt|;
name|int
name|fd
init|=
name|ts_fd
argument_list|(
name|m_dev
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|>=
literal|0
condition|)
block|{
name|m_notify
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_notify
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readMouseData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Cannot open mouse input device '%s': %s"
argument_list|,
name|device
operator|.
name|constData
argument_list|()
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QTsLibMouseHandler
name|QTsLibMouseHandler
operator|::
name|~
name|QTsLibMouseHandler
parameter_list|()
block|{
if|if
condition|(
name|m_dev
condition|)
name|ts_close
argument_list|(
name|m_dev
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|get_sample
specifier|static
name|bool
name|get_sample
parameter_list|(
name|struct
name|tsdev
modifier|*
name|dev
parameter_list|,
name|struct
name|ts_sample
modifier|*
name|sample
parameter_list|,
name|bool
name|rawMode
parameter_list|)
block|{
if|if
condition|(
name|rawMode
condition|)
block|{
return|return
operator|(
name|ts_read_raw
argument_list|(
name|dev
argument_list|,
name|sample
argument_list|,
literal|1
argument_list|)
operator|==
literal|1
operator|)
return|;
block|}
else|else
block|{
name|int
name|ret
init|=
name|ts_read
argument_list|(
name|dev
argument_list|,
name|sample
argument_list|,
literal|1
argument_list|)
decl_stmt|;
return|return
operator|(
name|ret
operator|==
literal|1
operator|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|readMouseData
name|void
name|QTsLibMouseHandler
operator|::
name|readMouseData
parameter_list|()
block|{
name|ts_sample
name|sample
decl_stmt|;
while|while
condition|(
name|get_sample
argument_list|(
name|m_dev
argument_list|,
operator|&
name|sample
argument_list|,
name|m_rawMode
argument_list|)
condition|)
block|{
name|bool
name|pressed
init|=
name|sample
operator|.
name|pressure
decl_stmt|;
name|int
name|x
init|=
name|sample
operator|.
name|x
decl_stmt|;
name|int
name|y
init|=
name|sample
operator|.
name|y
decl_stmt|;
if|if
condition|(
operator|!
name|m_rawMode
condition|)
block|{
comment|//filtering: ignore movements of 2 pixels or less
name|int
name|dx
init|=
name|x
operator|-
name|m_x
decl_stmt|;
name|int
name|dy
init|=
name|y
operator|-
name|m_y
decl_stmt|;
if|if
condition|(
name|dx
operator|*
name|dx
operator|<=
literal|4
operator|&&
name|dy
operator|*
name|dy
operator|<=
literal|4
operator|&&
name|pressed
operator|==
name|m_pressed
condition|)
continue|continue;
block|}
else|else
block|{
comment|// work around missing coordinates on mouse release in raw mode
if|if
condition|(
name|sample
operator|.
name|pressure
operator|==
literal|0
operator|&&
name|sample
operator|.
name|x
operator|==
literal|0
operator|&&
name|sample
operator|.
name|y
operator|==
literal|0
condition|)
block|{
name|x
operator|=
name|m_x
expr_stmt|;
name|y
operator|=
name|m_y
expr_stmt|;
block|}
block|}
name|QPoint
name|pos
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
decl_stmt|;
comment|//printf("handleMouseEvent %d %d %d %ld\n", m_x, m_y, pressed, sample.tv.tv_usec);
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
literal|0
argument_list|,
name|pos
argument_list|,
name|pos
argument_list|,
name|pressed
condition|?
name|Qt
operator|::
name|LeftButton
else|:
name|Qt
operator|::
name|NoButton
argument_list|)
expr_stmt|;
name|m_x
operator|=
name|x
expr_stmt|;
name|m_y
operator|=
name|y
expr_stmt|;
name|m_pressed
operator|=
name|pressed
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
