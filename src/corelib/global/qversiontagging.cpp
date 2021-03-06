begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_define
DECL|macro|SYM
define|#
directive|define
name|SYM
value|QT_MANGLE_NAMESPACE(qt_version_tag)
end_define
begin_comment
comment|//#define SSYM QT_STRINGIFY(SYM)
end_comment
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
name|Q_OF_ELF
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_if
begin_define
DECL|macro|make_versioned_symbol2
define|#
directive|define
name|make_versioned_symbol2
parameter_list|(
name|sym
parameter_list|,
name|m
parameter_list|,
name|n
parameter_list|,
name|separator
parameter_list|)
define|\
value|Q_CORE_EXPORT extern const char sym ## _ ## m ## _ ## n = 0; \     asm(".symver " QT_STRINGIFY(sym) "_" QT_STRINGIFY(m) "_" QT_STRINGIFY(n) ", " \         QT_STRINGIFY(sym) separator "Qt_" QT_STRINGIFY(m) "." QT_STRINGIFY(n))
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|make_versioned_symbol2
define|#
directive|define
name|make_versioned_symbol2
parameter_list|(
name|sym
parameter_list|,
name|m
parameter_list|,
name|n
parameter_list|,
name|separator
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|make_versioned_symbol
define|#
directive|define
name|make_versioned_symbol
parameter_list|(
name|sym
parameter_list|,
name|m
parameter_list|,
name|n
parameter_list|,
name|separator
parameter_list|)
value|make_versioned_symbol2(sym, m, n, separator)
end_define
begin_extern
extern|extern
literal|"C"
block|{
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|0
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|0
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|1
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|1
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|2
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|2
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|3
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|3
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|4
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|4
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|5
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|5
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|6
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|6
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|7
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|7
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|8
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|8
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|9
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
literal|9
argument_list|,
literal|"@"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|QT_VERSION_MINOR
operator|>
literal|10
error|#
directive|error
literal|"Please update this file with more Qt versions."
endif|#
directive|endif
comment|// the default version:
name|make_versioned_symbol
argument_list|(
name|SYM
argument_list|,
name|QT_VERSION_MAJOR
argument_list|,
name|QT_VERSION_MINOR
argument_list|,
literal|"@@"
argument_list|)
expr_stmt|;
block|}
end_extern
end_unit
