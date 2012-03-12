begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the FOO module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSINFO_H
end_ifndef
begin_define
DECL|macro|QSYSINFO_H
define|#
directive|define
name|QSYSINFO_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
comment|/*    System information */
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSysInfo
block|{
name|public
label|:
enum|enum
name|Sizes
block|{
name|WordSize
init|=
operator|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|<<
literal|3
operator|)
block|}
enum|;
if|#
directive|if
name|defined
argument_list|(
name|QT_BUILD_QMAKE
argument_list|)
enum|enum
name|Endian
block|{
name|BigEndian
block|,
name|LittleEndian
block|}
enum|;
comment|/* needed to bootstrap qmake */
specifier|static
specifier|const
name|int
name|ByteOrder
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_BYTE_ORDER
argument_list|)
enum|enum
name|Endian
block|{
name|BigEndian
block|,
name|LittleEndian
ifdef|#
directive|ifdef
name|qdoc
block|,
name|ByteOrder
init|=
operator|<
name|platform
operator|-
name|dependent
operator|>
elif|#
directive|elif
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
block|,
name|ByteOrder
init|=
name|BigEndian
elif|#
directive|elif
name|Q_BYTE_ORDER
operator|==
name|Q_LITTLE_ENDIAN
block|,
name|ByteOrder
init|=
name|LittleEndian
else|#
directive|else
error|#
directive|error
literal|"Undefined byte order"
endif|#
directive|endif
block|}
enum|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_CYGWIN
argument_list|)
enum|enum
name|WinVersion
block|{
name|WV_32s
init|=
literal|0x0001
block|,
name|WV_95
init|=
literal|0x0002
block|,
name|WV_98
init|=
literal|0x0003
block|,
name|WV_Me
init|=
literal|0x0004
block|,
name|WV_DOS_based
init|=
literal|0x000f
block|,
comment|/* codenames */
name|WV_NT
init|=
literal|0x0010
block|,
name|WV_2000
init|=
literal|0x0020
block|,
name|WV_XP
init|=
literal|0x0030
block|,
name|WV_2003
init|=
literal|0x0040
block|,
name|WV_VISTA
init|=
literal|0x0080
block|,
name|WV_WINDOWS7
init|=
literal|0x0090
block|,
name|WV_NT_based
init|=
literal|0x00f0
block|,
comment|/* version numbers */
name|WV_4_0
init|=
name|WV_NT
block|,
name|WV_5_0
init|=
name|WV_2000
block|,
name|WV_5_1
init|=
name|WV_XP
block|,
name|WV_5_2
init|=
name|WV_2003
block|,
name|WV_6_0
init|=
name|WV_VISTA
block|,
name|WV_6_1
init|=
name|WV_WINDOWS7
block|,
name|WV_CE
init|=
literal|0x0100
block|,
name|WV_CENET
init|=
literal|0x0200
block|,
name|WV_CE_5
init|=
literal|0x0300
block|,
name|WV_CE_6
init|=
literal|0x0400
block|,
name|WV_CE_based
init|=
literal|0x0f00
block|}
enum|;
specifier|static
specifier|const
name|WinVersion
name|WindowsVersion
decl_stmt|;
specifier|static
name|WinVersion
name|windowsVersion
parameter_list|()
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_MAC
enum|enum
name|MacVersion
block|{
name|MV_Unknown
init|=
literal|0x0000
block|,
comment|/* version */
name|MV_9
init|=
literal|0x0001
block|,
name|MV_10_0
init|=
literal|0x0002
block|,
name|MV_10_1
init|=
literal|0x0003
block|,
name|MV_10_2
init|=
literal|0x0004
block|,
name|MV_10_3
init|=
literal|0x0005
block|,
name|MV_10_4
init|=
literal|0x0006
block|,
name|MV_10_5
init|=
literal|0x0007
block|,
name|MV_10_6
init|=
literal|0x0008
block|,
name|MV_10_7
init|=
literal|0x0009
block|,
comment|/* codenames */
name|MV_CHEETAH
init|=
name|MV_10_0
block|,
name|MV_PUMA
init|=
name|MV_10_1
block|,
name|MV_JAGUAR
init|=
name|MV_10_2
block|,
name|MV_PANTHER
init|=
name|MV_10_3
block|,
name|MV_TIGER
init|=
name|MV_10_4
block|,
name|MV_LEOPARD
init|=
name|MV_10_5
block|,
name|MV_SNOWLEOPARD
init|=
name|MV_10_6
block|,
name|MV_LION
init|=
name|MV_10_7
block|}
enum|;
specifier|static
specifier|const
name|MacVersion
name|MacintoshVersion
decl_stmt|;
specifier|static
name|MacVersion
name|macVersion
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYSINFO_H
end_comment
end_unit
