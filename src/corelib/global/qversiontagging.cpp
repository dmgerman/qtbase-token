begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Intel Corporation. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_STATIC
argument_list|)
end_if
begin_define
DECL|macro|SYM
define|#
directive|define
name|SYM
value|QT_MANGLE_NAMESPACE(qt_version_tag)
end_define
begin_define
DECL|macro|SSYM
define|#
directive|define
name|SSYM
value|QT_STRINGIFY(SYM)
end_define
begin_asm
asm|asm(
comment|// ASM macro that makes one ELF versioned symbol qt_version_tag{sep}Qt_{major}.{minor}
comment|// that is an alias to qt_version_tag_{major}_{minor}.
comment|// The {sep} parameter must be @ for all old versions and @@ for the current version.
asm|".macro      make_one_tag    major minor sep\n" ".globl      " SSYM "_\\major\\()_\\minor\n"
comment|// make the symbol global
asm|SSYM "_\\major\\()_\\minor:\n"
comment|// declare it
asm|"    .symver " SSYM "_\\major\\()_\\minor, " SSYM "\\sep\\()Qt_\\major\\().\\minor\n" ".endm\n"  ".altmacro\n" ".bss\n" ".set qt_version_major, " QT_STRINGIFY(QT_VERSION) ">> 16\n"
comment|// set qt_version_major
asm|".set qt_version_minor, 0\n"
comment|// set qt_version_minor to 0 (it will grow to the current)
asm|".rept (" QT_STRINGIFY(QT_VERSION) ">> 8)& 0xff\n"
comment|// repeat minor version times (0 to N-1)
asm|"    make_one_tag    %qt_version_major, %qt_version_minor, @\n" "    .set qt_version_minor, (qt_version_minor + 1)\n" ".endr\n" "    make_one_tag    %qt_version_major, %qt_version_minor, @@\n"
comment|// call the macro for the current version
asm|"    .space  1\n"
comment|// variable is 1 byte, value 0
asm|);
end_asm
begin_endif
endif|#
directive|endif
end_endif
end_unit
