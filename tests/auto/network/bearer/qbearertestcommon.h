begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
