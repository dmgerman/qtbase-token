begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Olivier Goffart<ogoffart@woboq.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_class
DECL|class|tst_QMetaEnum
class|class
name|tst_QMetaEnum
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|enum|SuperEnum
DECL|enumerator|SuperValue1
DECL|enumerator|SuperValue2
enum|enum
name|SuperEnum
block|{
name|SuperValue1
init|=
literal|1
block|,
name|SuperValue2
init|=
literal|2
block|}
enum|;
name|Q_ENUM
parameter_list|(
name|SuperEnum
parameter_list|)
specifier|private
name|slots
public|:
name|void
name|fromType
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|fromType
name|void
name|tst_QMetaEnum
operator|::
name|fromType
parameter_list|()
block|{
name|QMetaEnum
name|meta
init|=
name|QMetaEnum
operator|::
name|fromType
argument_list|<
name|SuperEnum
argument_list|>
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|meta
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|meta
operator|.
name|name
argument_list|()
argument_list|,
literal|"SuperEnum"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|meta
operator|.
name|enclosingMetaObject
argument_list|()
argument_list|,
operator|&
name|staticMetaObject
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|meta
operator|.
name|keyCount
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMetaEnum
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmetaenum.moc"
end_include
end_unit
