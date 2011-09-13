begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_comment
comment|// Will try to wait for the condition while allowing event processing
end_comment
begin_define
DECL|macro|QTRY_VERIFY
define|#
directive|define
name|QTRY_VERIFY
parameter_list|(
name|__expr
parameter_list|)
define|\
value|do { \         const int __step = 50; \         const int __timeout = 90000; \         if (!(__expr)) { \             QTest::qWait(0); \         } \         for (int __i = 0; __i< __timeout&& !(__expr); __i+=__step) { \             QTest::qWait(__step); \         } \         QVERIFY(__expr); \     } while(0)
end_define
begin_comment
comment|// Will try to wait for the condition while allowing event processing
end_comment
begin_define
DECL|macro|QTRY_COMPARE
define|#
directive|define
name|QTRY_COMPARE
parameter_list|(
name|__expr
parameter_list|,
name|__expected
parameter_list|)
define|\
value|do { \         const int __step = 50; \         const int __timeout = 90000; \         if ((__expr) != (__expected)) { \             QTest::qWait(0); \         } \         for (int __i = 0; __i< __timeout&& ((__expr) != (__expected)); __i+=__step) { \             QTest::qWait(__step); \         } \         QCOMPARE(__expr, __expected); \     } while(0)
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
