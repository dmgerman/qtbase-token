begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TST_QVARIANT_COMMON
end_ifndef
begin_define
DECL|macro|TST_QVARIANT_COMMON
define|#
directive|define
name|TST_QVARIANT_COMMON
end_define
begin_include
include|#
directive|include
file|<QString>
end_include
begin_decl_stmt
name|class
name|MessageHandler
block|{
name|public
label|:
name|MessageHandler
argument_list|(
argument|const int typeId
argument_list|,
argument|QtMessageHandler msgHandler = handler
argument_list|)
block|:
name|oldMsgHandler
argument_list|(
argument|qInstallMessageHandler(msgHandler)
argument_list|)
block|{
name|currentId
operator|=
name|typeId
expr_stmt|;
block|}
operator|~
name|MessageHandler
argument_list|()
block|{
name|qInstallMessageHandler
argument_list|(
name|oldMsgHandler
argument_list|)
block|;     }
name|bool
name|testPassed
argument_list|()
specifier|const
block|{
return|return
name|ok
return|;
block|}
name|protected
label|:
specifier|static
name|void
name|handler
parameter_list|(
name|QtMsgType
parameter_list|,
specifier|const
name|QMessageLogContext
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
block|{
comment|// Format itself is not important, but basic data as a type name should be included in the output
name|ok
operator|=
name|msg
operator|.
name|startsWith
argument_list|(
literal|"QVariant("
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|ok
argument_list|,
operator|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Message is not started correctly: '"
argument_list|)
operator|+
name|msg
operator|+
literal|'\''
operator|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|ok
operator|&=
operator|(
name|currentId
operator|==
name|QMetaType
operator|::
name|UnknownType
condition|?
name|msg
operator|.
name|contains
argument_list|(
literal|"Invalid"
argument_list|)
else|:
name|msg
operator|.
name|contains
argument_list|(
name|QMetaType
operator|::
name|typeName
argument_list|(
name|currentId
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|ok
argument_list|,
operator|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Message doesn't contain type name: '"
argument_list|)
operator|+
name|msg
operator|+
literal|'\''
operator|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|currentId
operator|==
name|QMetaType
operator|::
name|Char
operator|||
name|currentId
operator|==
name|QMetaType
operator|::
name|QChar
condition|)
block|{
comment|// Chars insert '\0' into the qdebug stream, it is not possible to find a real string length
return|return;
block|}
if|if
condition|(
name|QMetaType
operator|::
name|typeFlags
argument_list|(
name|currentId
argument_list|)
operator|&
name|QMetaType
operator|::
name|PointerToQObject
condition|)
block|{
name|QByteArray
name|currentName
init|=
name|QMetaType
operator|::
name|typeName
argument_list|(
name|currentId
argument_list|)
decl_stmt|;
name|currentName
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|ok
operator|&=
operator|(
name|msg
operator|.
name|contains
argument_list|(
literal|", "
operator|+
name|currentName
argument_list|)
operator|||
name|msg
operator|.
name|contains
argument_list|(
literal|", 0x0"
argument_list|)
operator|)
expr_stmt|;
block|}
name|ok
operator|&=
name|msg
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|ok
argument_list|,
operator|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Message is not correctly finished: '"
argument_list|)
operator|+
name|msg
operator|+
literal|'\''
operator|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QtMessageHandler
name|oldMsgHandler
decl_stmt|;
specifier|static
name|int
name|currentId
decl_stmt|;
specifier|static
name|bool
name|ok
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|member|ok
name|bool
name|MessageHandler
operator|::
name|ok
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|member|currentId
name|int
name|MessageHandler
operator|::
name|currentId
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|TST_QVARIANT_CANCONVERT_DATATABLE_HEADERS
define|#
directive|define
name|TST_QVARIANT_CANCONVERT_DATATABLE_HEADERS
define|\
value|QTest::addColumn<QVariant>("val"); \     QTest::addColumn<bool>("BitArrayCast"); \     QTest::addColumn<bool>("BitmapCast"); \     QTest::addColumn<bool>("BoolCast"); \     QTest::addColumn<bool>("BrushCast"); \     QTest::addColumn<bool>("ByteArrayCast"); \     QTest::addColumn<bool>("ColorCast"); \     QTest::addColumn<bool>("CursorCast"); \     QTest::addColumn<bool>("DateCast"); \     QTest::addColumn<bool>("DateTimeCast"); \     QTest::addColumn<bool>("DoubleCast"); \     QTest::addColumn<bool>("FontCast"); \     QTest::addColumn<bool>("ImageCast"); \     QTest::addColumn<bool>("IntCast"); \     QTest::addColumn<bool>("InvalidCast"); \     QTest::addColumn<bool>("KeySequenceCast"); \     QTest::addColumn<bool>("ListCast"); \     QTest::addColumn<bool>("LongLongCast"); \     QTest::addColumn<bool>("MapCast"); \     QTest::addColumn<bool>("PaletteCast"); \     QTest::addColumn<bool>("PenCast"); \     QTest::addColumn<bool>("PixmapCast"); \     QTest::addColumn<bool>("PointCast"); \     QTest::addColumn<bool>("RectCast"); \     QTest::addColumn<bool>("RegionCast"); \     QTest::addColumn<bool>("SizeCast"); \     QTest::addColumn<bool>("SizePolicyCast"); \     QTest::addColumn<bool>("StringCast"); \     QTest::addColumn<bool>("StringListCast"); \     QTest::addColumn<bool>("TimeCast"); \     QTest::addColumn<bool>("UIntCast"); \     QTest::addColumn<bool>("ULongLongCast");
end_define
begin_define
DECL|macro|TST_QVARIANT_CANCONVERT_FETCH_DATA
define|#
directive|define
name|TST_QVARIANT_CANCONVERT_FETCH_DATA
define|\
value|QFETCH(QVariant, val); \     QFETCH(bool, BitArrayCast); \     QFETCH(bool, BitmapCast); \     QFETCH(bool, BoolCast); \     QFETCH(bool, BrushCast); \     QFETCH(bool, ByteArrayCast); \     QFETCH(bool, ColorCast); \     QFETCH(bool, CursorCast); \     QFETCH(bool, DateCast); \     QFETCH(bool, DateTimeCast); \     QFETCH(bool, DoubleCast); \     QFETCH(bool, FontCast); \     QFETCH(bool, ImageCast); \     QFETCH(bool, IntCast); \     QFETCH(bool, InvalidCast); \     QFETCH(bool, KeySequenceCast); \     QFETCH(bool, ListCast); \     QFETCH(bool, LongLongCast); \     QFETCH(bool, MapCast); \     QFETCH(bool, PaletteCast); \     QFETCH(bool, PenCast); \     QFETCH(bool, PixmapCast); \     QFETCH(bool, PointCast); \     QFETCH(bool, RectCast); \     QFETCH(bool, RegionCast); \     QFETCH(bool, SizeCast); \     QFETCH(bool, SizePolicyCast); \     QFETCH(bool, StringCast); \     QFETCH(bool, StringListCast); \     QFETCH(bool, TimeCast); \     QFETCH(bool, UIntCast); \     QFETCH(bool, ULongLongCast);
end_define
begin_define
DECL|macro|TST_QVARIANT_CANCONVERT_COMPARE_DATA
define|#
directive|define
name|TST_QVARIANT_CANCONVERT_COMPARE_DATA
define|\
value|QCOMPARE(val.canConvert(QVariant::BitArray), BitArrayCast); \     QCOMPARE(val.canConvert(QVariant::Bitmap), BitmapCast); \     QCOMPARE(val.canConvert(QVariant::Bool), BoolCast); \     QCOMPARE(val.canConvert(QVariant::Brush), BrushCast); \     QCOMPARE(val.canConvert(QVariant::ByteArray), ByteArrayCast); \     QCOMPARE(val.canConvert(QVariant::Color), ColorCast); \     QCOMPARE(val.canConvert(QVariant::Cursor), CursorCast); \     QCOMPARE(val.canConvert(QVariant::Date), DateCast); \     QCOMPARE(val.canConvert(QVariant::DateTime), DateTimeCast); \     QCOMPARE(val.canConvert(QVariant::Double), DoubleCast); \     QCOMPARE(val.canConvert(QVariant::Type(QMetaType::Float)), DoubleCast); \     QCOMPARE(val.canConvert(QVariant::Font), FontCast); \     QCOMPARE(val.canConvert(QVariant::Image), ImageCast); \     QCOMPARE(val.canConvert(QVariant::Int), IntCast); \     QCOMPARE(val.canConvert(QVariant::Invalid), InvalidCast); \     QCOMPARE(val.canConvert(QVariant::KeySequence), KeySequenceCast); \     QCOMPARE(val.canConvert(QVariant::List), ListCast); \     QCOMPARE(val.canConvert(QVariant::LongLong), LongLongCast); \     QCOMPARE(val.canConvert(QVariant::Map), MapCast); \     QCOMPARE(val.canConvert(QVariant::Palette), PaletteCast); \     QCOMPARE(val.canConvert(QVariant::Pen), PenCast); \     QCOMPARE(val.canConvert(QVariant::Pixmap), PixmapCast); \     QCOMPARE(val.canConvert(QVariant::Point), PointCast); \     QCOMPARE(val.canConvert(QVariant::Rect), RectCast); \     QCOMPARE(val.canConvert(QVariant::Region), RegionCast); \     QCOMPARE(val.canConvert(QVariant::Size), SizeCast); \     QCOMPARE(val.canConvert(QVariant::SizePolicy), SizePolicyCast); \     QCOMPARE(val.canConvert(QVariant::String), StringCast); \     QCOMPARE(val.canConvert(QVariant::StringList), StringListCast); \     QCOMPARE(val.canConvert(QVariant::Time), TimeCast); \     QCOMPARE(val.canConvert(QVariant::UInt), UIntCast); \     QCOMPARE(val.canConvert(QVariant::ULongLong), ULongLongCast);
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
