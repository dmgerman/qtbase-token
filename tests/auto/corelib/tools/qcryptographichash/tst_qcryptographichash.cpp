begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_class
DECL|class|tst_QCryptographicHash
class|class
name|tst_QCryptographicHash
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|repeated_result_data
parameter_list|()
function_decl|;
name|void
name|repeated_result
parameter_list|()
function_decl|;
name|void
name|intermediary_result_data
parameter_list|()
function_decl|;
name|void
name|intermediary_result
parameter_list|()
function_decl|;
name|void
name|sha1
parameter_list|()
function_decl|;
name|void
name|sha3
parameter_list|()
function_decl|;
name|void
name|files_data
parameter_list|()
function_decl|;
name|void
name|files
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|repeated_result_data
name|void
name|tst_QCryptographicHash
operator|::
name|repeated_result_data
parameter_list|()
block|{
name|intermediary_result_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|repeated_result
name|void
name|tst_QCryptographicHash
operator|::
name|repeated_result
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|algo
argument_list|)
expr_stmt|;
name|QCryptographicHash
operator|::
name|Algorithm
name|_algo
init|=
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|(
name|algo
argument_list|)
decl_stmt|;
name|QCryptographicHash
name|hash
argument_list|(
name|_algo
argument_list|)
decl_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|first
argument_list|)
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|first
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|hash_first
argument_list|)
expr_stmt|;
name|QByteArray
name|result
init|=
name|hash
operator|.
name|result
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|hash_first
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|hash
operator|.
name|result
argument_list|()
argument_list|)
expr_stmt|;
name|hash
operator|.
name|reset
argument_list|()
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|first
argument_list|)
expr_stmt|;
name|result
operator|=
name|hash
operator|.
name|result
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|hash_first
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|hash
operator|.
name|result
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|intermediary_result_data
name|void
name|tst_QCryptographicHash
operator|::
name|intermediary_result_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"algo"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"first"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"second"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"hash_first"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"hash_firstsecond"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"md4"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Md4
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"A448017AAF21D8525FC10AE87AA6729D"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"03E5E436DAFAF3B9B3589DB83C417C6B"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"md5"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Md5
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"900150983CD24FB0D6963F7D28E17F72"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"440AC85892CA43AD26D44C7AD9D47D3E"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha1"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"A9993E364706816ABA3E25717850C26C9CD0D89D"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"F8C1D87006FBF7E5CC4B026C3138BC046883DC71"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha224"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha224
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"23097D223405D8228642A477BDA255B32AADBCE4BDA0B3F7E36C9DA7"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"7C9C91FC479626AA1A525301084DEB96716131D146A2DB61B533F4C9"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha256"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha256
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"BA7816BF8F01CFEA414140DE5DAE2223B00361A396177A9CB410FF61F20015AD"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"BBB59DA3AF939F7AF5F360F2CEB80A496E3BAE1CD87DDE426DB0AE40677E1C2C"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha384"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha384
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"CB00753F45A35E8BB5A03D699AC65007272C32AB0EDED1631A8B605A43FF5BED8086072BA1E7CC2358BAECA134C825A7"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"CAF33A735C9535CE7F5D24FB5B3A4834F0E9316664AD15A9E8221679D4A3B4FB7E962404BA0C10C1D43AB49D03A08B8D"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha512"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha512
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"DDAF35A193617ABACC417349AE20413112E6FA4E89A97EA20A9EEEE64B55D39A2192992A274FC1A836BA3C23A3FEEBBD454D4423643CE80E2A9AC94FA54CA49F"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"F3C41E7B63EE869596FC28BAD64120612C520F65928AB4D126C72C6998B551B8FF1CEDDFED4373E6717554DC89D1EEE6F0AB22FD3675E561ABA9AE26A3EEC53B"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha3_224"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha3_224
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"C30411768506EBE1C2871B1EE2E87D38DF342317300A9B97A95EC6A8"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"048330E7C7C8B4A41AB713B3A6F958D77B8CF3EE969930F1584DD550"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha3_256"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha3_256
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"4E03657AEA45A94FC7D47BA826C8D667C0D1E6E33A64A036EC44F58FA12D6C45"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"9F0ADAD0A59B05D2E04A1373342B10B9EB16C57C164C8A3BFCBF46DCCEE39A21"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha3_384"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha3_384
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"F7DF1165F033337BE098E7D288AD6A2F74409D7A60B49C36642218DE161B1F99F8C681E4AFAF31A34DB29FB763E3C28E"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"D733B87D392D270889D3DA23AE113F349E25574B445F319CDE4CD3F877C753E9E3C65980421339B3A131457FF393939F"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"sha3_512"
argument_list|)
operator|<<
name|int
argument_list|(
name|QCryptographicHash
operator|::
name|Sha3_512
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"18587DC2EA106B9A1563E32B3312421CA164C7F1F07BC922A9C83D77CEA3A1E5D0C69910739025372DC14AC9642629379540C17E2A65B19D77AA511A9D00BB96"
argument_list|)
operator|<<
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"A7C392D2A42155761CA76BDDDE1C47D55486B007EDF465397BFB9DFA74D11C8F0D7C86CD29415283F1B5E7F655CEC25B869C9E9C33A8986F0B38542FB12BFB93"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|intermediary_result
name|void
name|tst_QCryptographicHash
operator|::
name|intermediary_result
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|algo
argument_list|)
expr_stmt|;
name|QCryptographicHash
operator|::
name|Algorithm
name|_algo
init|=
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|(
name|algo
argument_list|)
decl_stmt|;
name|QCryptographicHash
name|hash
argument_list|(
name|_algo
argument_list|)
decl_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|first
argument_list|)
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|first
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|hash_first
argument_list|)
expr_stmt|;
name|QByteArray
name|result
init|=
name|hash
operator|.
name|result
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|hash_first
argument_list|)
expr_stmt|;
comment|// don't reset
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|second
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|hash_firstsecond
argument_list|)
expr_stmt|;
name|hash
operator|.
name|addData
argument_list|(
name|second
argument_list|)
expr_stmt|;
name|result
operator|=
name|hash
operator|.
name|result
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
argument_list|,
name|hash_firstsecond
argument_list|)
expr_stmt|;
name|hash
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sha1
name|void
name|tst_QCryptographicHash
operator|::
name|sha1
parameter_list|()
block|{
comment|//  SHA1("abc") =
comment|//      A9993E36 4706816A BA3E2571 7850C26C 9CD0D89D
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"abc"
argument_list|,
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
operator|.
name|toHex
argument_list|()
operator|.
name|toUpper
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"A9993E364706816ABA3E25717850C26C9CD0D89D"
argument_list|)
argument_list|)
expr_stmt|;
comment|//  SHA1("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq") =
comment|//      84983E44 1C3BD26E BAAE4AA1 F95129E5 E54670F1
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"
argument_list|,
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
operator|.
name|toHex
argument_list|()
operator|.
name|toUpper
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"84983E441C3BD26EBAAE4AA1F95129E5E54670F1"
argument_list|)
argument_list|)
expr_stmt|;
comment|//  SHA1(A million repetitions of "a") =
comment|//      34AA973C D4C4DAA4 F61EEB2B DBAD2731 6534016F
name|QByteArray
name|as
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|1000000
condition|;
operator|++
name|i
control|)
name|as
operator|+=
literal|'a'
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
name|as
argument_list|,
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
operator|.
name|toHex
argument_list|()
operator|.
name|toUpper
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"34AA973CD4C4DAA4F61EEB2BDBAD27316534016F"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sha3
name|void
name|tst_QCryptographicHash
operator|::
name|sha3
parameter_list|()
block|{
comment|// SHA3-224("The quick brown fox jumps over the lazy dog")
comment|// 10aee6b30c47350576ac2873fa89fd190cdc488442f3ef654cf23fe
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"The quick brown fox jumps over the lazy dog"
argument_list|,
name|QCryptographicHash
operator|::
name|Sha3_224
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"310aee6b30c47350576ac2873fa89fd190cdc488442f3ef654cf23fe"
argument_list|)
argument_list|)
expr_stmt|;
comment|// SHA3-224("The quick brown fox jumps over the lazy dog.")
comment|// c59d4eaeac728671c635ff645014e2afa935bebffdb5fbd207ffdeab
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"The quick brown fox jumps over the lazy dog."
argument_list|,
name|QCryptographicHash
operator|::
name|Sha3_224
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"c59d4eaeac728671c635ff645014e2afa935bebffdb5fbd207ffdeab"
argument_list|)
argument_list|)
expr_stmt|;
comment|// SHA3-256("The quick brown fox jumps over the lazy dog")
comment|// 4d741b6f1eb29cb2a9b9911c82f56fa8d73b04959d3d9d222895df6c0b28aa15
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"The quick brown fox jumps over the lazy dog"
argument_list|,
name|QCryptographicHash
operator|::
name|Sha3_256
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"4d741b6f1eb29cb2a9b9911c82f56fa8d73b04959d3d9d222895df6c0b28aa15"
argument_list|)
argument_list|)
expr_stmt|;
comment|// SHA3-256("The quick brown fox jumps over the lazy dog.")
comment|// 578951e24efd62a3d63a86f7cd19aaa53c898fe287d2552133220370240b572d
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"The quick brown fox jumps over the lazy dog."
argument_list|,
name|QCryptographicHash
operator|::
name|Sha3_256
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"578951e24efd62a3d63a86f7cd19aaa53c898fe287d2552133220370240b572d"
argument_list|)
argument_list|)
expr_stmt|;
comment|// SHA3-384("The quick brown fox jumps over the lazy dog")
comment|// 283990fa9d5fb731d786c5bbee94ea4db4910f18c62c03d173fc0a5e494422e8a0b3da7574dae7fa0baf005e504063b3
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"The quick brown fox jumps over the lazy dog"
argument_list|,
name|QCryptographicHash
operator|::
name|Sha3_384
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"283990fa9d5fb731d786c5bbee94ea4db4910f18c62c03d173fc0a5e494422e8a0b3da7574dae7fa0baf005e504063b3"
argument_list|)
argument_list|)
expr_stmt|;
comment|// SHA3-384("The quick brown fox jumps over the lazy dog.")
comment|// 9ad8e17325408eddb6edee6147f13856ad819bb7532668b605a24a2d958f88bd5c169e56dc4b2f89ffd325f6006d820b
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"The quick brown fox jumps over the lazy dog."
argument_list|,
name|QCryptographicHash
operator|::
name|Sha3_384
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"9ad8e17325408eddb6edee6147f13856ad819bb7532668b605a24a2d958f88bd5c169e56dc4b2f89ffd325f6006d820b"
argument_list|)
argument_list|)
expr_stmt|;
comment|// SHA3-512("The quick brown fox jumps over the lazy dog")
comment|// d135bb84d0439dbac432247ee573a23ea7d3c9deb2a968eb31d47c4fb45f1ef4422d6c531b5b9bd6f449ebcc449ea94d0a8f05f62130fda612da53c79659f609
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"The quick brown fox jumps over the lazy dog"
argument_list|,
name|QCryptographicHash
operator|::
name|Sha3_512
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"d135bb84d0439dbac432247ee573a23ea7d3c9deb2a968eb31d47c4fb45f1ef4422d6c531b5b9bd6f449ebcc449ea94d0a8f05f62130fda612da53c79659f609"
argument_list|)
argument_list|)
expr_stmt|;
comment|// SHA3-512("The quick brown fox jumps over the lazy dog.")
comment|// ab7192d2b11f51c7dd744e7b3441febf397ca07bf812cceae122ca4ded6387889064f8db9230f173f6d1ab6e24b6e50f065b039f799f5592360a6558eb52d760
name|QCOMPARE
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
literal|"The quick brown fox jumps over the lazy dog."
argument_list|,
name|QCryptographicHash
operator|::
name|Sha3_512
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
literal|"ab7192d2b11f51c7dd744e7b3441febf397ca07bf812cceae122ca4ded6387889064f8db9230f173f6d1ab6e24b6e50f065b039f799f5592360a6558eb52d760"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|Algorithm
name|Q_DECLARE_METATYPE
argument_list|(
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|files_data
name|void
name|tst_QCryptographicHash
operator|::
name|files_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"filename"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|>
argument_list|(
literal|"algorithm"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"md5sum"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"data/2c1517dad3678f03917f15849b052fd5.md5"
argument_list|)
operator|<<
name|QCryptographicHash
operator|::
name|Md5
operator|<<
name|QByteArray
argument_list|(
literal|"2c1517dad3678f03917f15849b052fd5"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"data/d41d8cd98f00b204e9800998ecf8427e.md5"
argument_list|)
operator|<<
name|QCryptographicHash
operator|::
name|Md5
operator|<<
name|QByteArray
argument_list|(
literal|"d41d8cd98f00b204e9800998ecf8427e"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|files
name|void
name|tst_QCryptographicHash
operator|::
name|files
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QCryptographicHash
operator|::
name|Algorithm
argument_list|,
name|algorithm
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|md5sum
argument_list|)
expr_stmt|;
block|{
name|QString
name|testData
init|=
name|QFINDTESTDATA
argument_list|(
name|filename
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
operator|!
name|testData
operator|.
name|isEmpty
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"Cannot find test data: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|filename
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QFile
name|f
argument_list|(
name|testData
argument_list|)
decl_stmt|;
name|QCryptographicHash
name|hash
argument_list|(
name|algorithm
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|hash
operator|.
name|addData
argument_list|(
operator|&
name|f
argument_list|)
argument_list|)
expr_stmt|;
comment|// file is not open for reading;
if|if
condition|(
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|QVERIFY
argument_list|(
name|hash
operator|.
name|addData
argument_list|(
operator|&
name|f
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hash
operator|.
name|result
argument_list|()
operator|.
name|toHex
argument_list|()
argument_list|,
name|md5sum
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QFAIL
argument_list|(
literal|"Failed to open file for testing. should not happen"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QCryptographicHash
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qcryptographichash.moc"
end_include
end_unit
