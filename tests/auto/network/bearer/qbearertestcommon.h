begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBEARERTESTCOMMON_H
end_ifndef
begin_define
DECL|macro|QBEARERTESTCOMMON_H
define|#
directive|define
name|QBEARERTESTCOMMON_H
end_define
begin_include
include|#
directive|include
file|<QtTest/qtestcase.h>
end_include
begin_enum
DECL|enumerator|TestTimeOut
enum|enum
block|{
name|TestTimeOut
init|=
literal|90000
block|}
enum|;
end_enum
begin_comment
comment|// Wait for __expr to happen, while still allowing events to be processed.
end_comment
begin_define
DECL|macro|QTRY_NOOP
define|#
directive|define
name|QTRY_NOOP
parameter_list|(
name|__expr
parameter_list|)
define|\
value|do { \         const int __step = 50; \         const int __timeout = 15000; \         if (!(__expr)) { \             QTest::qWait(0); \         } \         for (int __i = 0; __i< __timeout&& !(__expr); __i+=__step) { \             QTest::qWait(__step); \         } \     } while(0)
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
