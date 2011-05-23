begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<qmacstyle_mac.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_decl_stmt
DECL|variable|N
specifier|const
name|int
name|N
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=gui/styles/qmacstyle_mac.h gui/styles/qmacstyle_mac.cpp
end_comment
begin_enum
DECL|enum|Size
DECL|enumerator|Normal
DECL|enumerator|Small
DECL|enumerator|Mini
enum|enum
name|Size
block|{
name|Normal
block|,
name|Small
block|,
name|Mini
block|}
enum|;
end_enum
begin_expr_stmt
DECL|variable|Size
name|Q_DECLARE_METATYPE
argument_list|(
name|Size
argument_list|)
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|CT
define|#
directive|define
name|CT
parameter_list|(
name|E
parameter_list|)
define|\
value|static const ControlType E = QSizePolicy::E;
end_define
begin_typedef
DECL|typedef|ControlType
typedef|typedef
name|QSizePolicy
operator|::
name|ControlType
name|ControlType
typedef|;
end_typedef
begin_macro
name|CT
argument_list|(
argument|DefaultType
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|ButtonBox
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|CheckBox
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|ComboBox
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|Frame
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|GroupBox
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|Label
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|Line
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|LineEdit
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|PushButton
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|RadioButton
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|Slider
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|SpinBox
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|TabWidget
argument_list|)
end_macro
begin_macro
name|CT
argument_list|(
argument|ToolButton
argument_list|)
end_macro
begin_class
DECL|class|tst_QMacStyle
class|class
name|tst_QMacStyle
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QMacStyle
name|tst_QMacStyle
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|Size
argument_list|>
argument_list|(
literal|"Size"
argument_list|)
expr_stmt|;
block|}
private|private
name|slots
private|:
name|void
name|sizeHints_data
parameter_list|()
function_decl|;
name|void
name|sizeHints
parameter_list|()
function_decl|;
name|void
name|layoutMargins_data
parameter_list|()
function_decl|;
name|void
name|layoutMargins
parameter_list|()
function_decl|;
name|void
name|layoutSpacings_data
parameter_list|()
function_decl|;
name|void
name|layoutSpacings
parameter_list|()
function_decl|;
name|void
name|smallMiniNormalExclusivity_data
parameter_list|()
function_decl|;
name|void
name|smallMiniNormalExclusivity
parameter_list|()
function_decl|;
private|private:
specifier|static
name|QSize
name|msh
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
specifier|static
name|QSize
name|sh
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
specifier|static
name|QRect
name|geo
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
DECL|function|pos
specifier|static
name|QPoint
name|pos
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
return|return
name|geo
argument_list|(
name|widget
argument_list|)
operator|.
name|topLeft
argument_list|()
return|;
block|}
DECL|function|size
specifier|static
name|QSize
name|size
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
return|return
name|geo
argument_list|(
name|widget
argument_list|)
operator|.
name|size
argument_list|()
return|;
block|}
specifier|static
name|QSize
name|gap
parameter_list|(
name|QWidget
modifier|*
name|widget1
parameter_list|,
name|QWidget
modifier|*
name|widget2
parameter_list|)
function_decl|;
DECL|function|hgap
specifier|static
name|int
name|hgap
parameter_list|(
name|QWidget
modifier|*
name|widget1
parameter_list|,
name|QWidget
modifier|*
name|widget2
parameter_list|)
block|{
return|return
name|gap
argument_list|(
name|widget1
argument_list|,
name|widget2
argument_list|)
operator|.
name|width
argument_list|()
return|;
block|}
DECL|function|vgap
specifier|static
name|int
name|vgap
parameter_list|(
name|QWidget
modifier|*
name|widget1
parameter_list|,
name|QWidget
modifier|*
name|widget2
parameter_list|)
block|{
return|return
name|gap
argument_list|(
name|widget1
argument_list|,
name|widget2
argument_list|)
operator|.
name|height
argument_list|()
return|;
block|}
specifier|static
name|void
name|setSize
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|Size
name|size
parameter_list|)
function_decl|;
specifier|static
name|int
name|spacing
parameter_list|(
name|ControlType
name|control1
parameter_list|,
name|ControlType
name|control2
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|QStyleOption
modifier|*
name|option
init|=
literal|0
parameter_list|,
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|int
name|hspacing
parameter_list|(
name|ControlType
name|control1
parameter_list|,
name|ControlType
name|control2
parameter_list|,
name|Size
name|size
init|=
name|Normal
parameter_list|)
function_decl|;
specifier|static
name|int
name|vspacing
parameter_list|(
name|ControlType
name|control1
parameter_list|,
name|ControlType
name|control2
parameter_list|,
name|Size
name|size
init|=
name|Normal
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_define
DECL|macro|SIZE
define|#
directive|define
name|SIZE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|((size == Normal) ? (x) : (size == Small) ? (y) : (z))
end_define
begin_function
DECL|function|sizeHints_data
name|void
name|tst_QMacStyle
operator|::
name|sizeHints_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|Size
argument_list|>
argument_list|(
literal|"size"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"normal"
argument_list|)
operator|<<
name|Normal
expr_stmt|;
comment|//    QTest::newRow("small")<< Small;
comment|//    QTest::newRow("mini")<< Mini;
block|}
end_function
begin_function
DECL|function|sizeHints
name|void
name|tst_QMacStyle
operator|::
name|sizeHints
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|Size
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QDialog
name|w
decl_stmt|;
name|setSize
argument_list|(
operator|&
name|w
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QLineEdit
name|lineEdit1
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|lineEdit1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|22
argument_list|,
literal|19
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
comment|// 16 in Builder, 15 in AHIG
name|QProgressBar
name|progress1
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|progress1
operator|.
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"sh"
operator|<<
name|progress1
operator|.
name|sizeHint
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|progress1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|16
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
comment|// Builder
name|progress1
operator|.
name|setOrientation
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|progress1
argument_list|)
operator|.
name|width
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|16
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
comment|// Builder
name|QRadioButton
name|radio1
argument_list|(
literal|"Radio"
argument_list|,
operator|&
name|w
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|radio1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|15
argument_list|,
literal|12
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
comment|// Builder
name|QCheckBox
name|checkBox1
argument_list|(
literal|"Switch"
argument_list|,
operator|&
name|w
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|checkBox1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|14
argument_list|,
literal|12
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
comment|// Builder
name|QComboBox
name|comboBox1
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|comboBox1
operator|.
name|setEditable
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|comboBox1
operator|.
name|addItem
argument_list|(
literal|"Foo"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|comboBox1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|20
argument_list|,
literal|17
argument_list|,
literal|15
argument_list|)
argument_list|)
expr_stmt|;
name|QComboBox
name|comboBox2
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|comboBox2
operator|.
name|setEditable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|comboBox2
operator|.
name|addItem
argument_list|(
literal|"Foo"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|comboBox2
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|20
argument_list|,
literal|17
argument_list|,
literal|15
argument_list|)
argument_list|)
expr_stmt|;
comment|// Combos in toolbars use the actual widget rect to
comment|// avoid faulty clipping:
name|QToolBar
name|tb
decl_stmt|;
name|setSize
argument_list|(
operator|&
name|tb
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QComboBox
name|comboBox3
argument_list|(
operator|&
name|tb
argument_list|)
decl_stmt|;
name|comboBox3
operator|.
name|addItem
argument_list|(
literal|"Foo"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|comboBox3
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|26
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QSlider
name|slider1
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|,
operator|&
name|w
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|slider1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|15
argument_list|,
literal|12
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|slider1
operator|.
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksAbove
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|slider1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|24
argument_list|,
literal|17
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
comment|// Builder
name|slider1
operator|.
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksBelow
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|slider1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|24
argument_list|,
literal|17
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
comment|// Builder
name|slider1
operator|.
name|setTickPosition
argument_list|(
name|QSlider
operator|::
name|TicksBothSides
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sh
argument_list|(
operator|&
name|slider1
argument_list|)
operator|.
name|height
argument_list|()
operator|>
name|SIZE
argument_list|(
literal|15
argument_list|,
literal|12
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
comment|// common sense
name|QPushButton
name|ok1
argument_list|(
literal|"OK"
argument_list|,
operator|&
name|w
argument_list|)
decl_stmt|;
name|QPushButton
name|cancel1
argument_list|(
literal|"Cancel"
argument_list|,
operator|&
name|w
argument_list|)
decl_stmt|;
name|QSize
name|s1
init|=
name|sh
argument_list|(
operator|&
name|ok1
argument_list|)
decl_stmt|;
if|if
condition|(
name|size
operator|==
name|Normal
condition|)
block|{
comment|// AHIG says 68, Builder does 70, and Qt seems to do 69
name|QVERIFY
argument_list|(
name|s1
operator|.
name|width
argument_list|()
operator|>=
literal|68
operator|&&
name|s1
operator|.
name|width
argument_list|()
operator|<=
literal|70
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|s1
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|20
argument_list|,
literal|17
argument_list|,
literal|14
argument_list|)
argument_list|)
expr_stmt|;
comment|// 14 in Builder, 15 in AHIG
comment|// Cancel should be identical to OK, no matter what
name|QCOMPARE
argument_list|(
name|s1
argument_list|,
name|sh
argument_list|(
operator|&
name|cancel1
argument_list|)
argument_list|)
expr_stmt|;
comment|// Play with auto-default and default
name|cancel1
operator|.
name|setAutoDefault
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
argument_list|,
name|sh
argument_list|(
operator|&
name|cancel1
argument_list|)
argument_list|)
expr_stmt|;
name|cancel1
operator|.
name|setAutoDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
argument_list|,
name|sh
argument_list|(
operator|&
name|cancel1
argument_list|)
argument_list|)
expr_stmt|;
name|cancel1
operator|.
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
argument_list|,
name|sh
argument_list|(
operator|&
name|cancel1
argument_list|)
argument_list|)
expr_stmt|;
name|QDialogButtonBox
name|bbox
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|bbox
operator|.
name|setStandardButtons
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
operator||
name|QDialogButtonBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
argument_list|,
name|sh
argument_list|(
name|bbox
operator|.
name|button
argument_list|(
name|QDialogButtonBox
operator|::
name|Ok
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
argument_list|,
name|sh
argument_list|(
name|bbox
operator|.
name|button
argument_list|(
name|QDialogButtonBox
operator|::
name|Cancel
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QMessageBox
name|mbox
argument_list|(
operator|&
name|w
argument_list|)
decl_stmt|;
name|mbox
operator|.
name|setStandardButtons
argument_list|(
name|QMessageBox
operator|::
name|Ok
operator||
name|QMessageBox
operator|::
name|Cancel
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
argument_list|,
name|sh
argument_list|(
name|mbox
operator|.
name|button
argument_list|(
name|QMessageBox
operator|::
name|Ok
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|s1
argument_list|,
name|sh
argument_list|(
name|mbox
operator|.
name|button
argument_list|(
name|QMessageBox
operator|::
name|Cancel
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|/*     QSpinBox spinBox1(&w);     int h1 = sh(&spinBox1).height();     QCOMPARE(h1, SIZE(22, 19, 15));      QDateEdit date1(&w);     QCOMPARE(sh(&date1).height(), h1);      QTimeEdit time1(&w);     QCOMPARE(sh(&time1).height(), h1);      QDateTimeEdit dateTime1(&w);     QCOMPARE(sh(&dateTime1).height(), h1);      ok1.setAttribute(Qt::WA_MacMetalStyle, true);     QSize s2 = sh(&ok1);     if (size == Normal) {         QVERIFY(s2.height()>= 21&& s2.height()<= 32);     } else {         QVERIFY(s2.height()>= 18&& s2.height()<= 24);     }     */
comment|// QMacStyle bug: label doesn't react to Small and Mini
name|QLabel
name|label1
argument_list|(
literal|"Blah"
argument_list|,
operator|&
name|w
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|sh
argument_list|(
operator|&
name|label1
argument_list|)
operator|.
name|height
argument_list|()
argument_list|,
name|SIZE
argument_list|(
literal|17
argument_list|,
literal|14
argument_list|,
literal|11
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|layoutMargins_data
name|void
name|tst_QMacStyle
operator|::
name|layoutMargins_data
parameter_list|()
block|{
name|tst_QMacStyle
operator|::
name|sizeHints_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|layoutMargins
name|void
name|tst_QMacStyle
operator|::
name|layoutMargins
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|Size
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QWidget
name|w
decl_stmt|;
name|setSize
argument_list|(
operator|&
name|w
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|layoutSpacings_data
name|void
name|tst_QMacStyle
operator|::
name|layoutSpacings_data
parameter_list|()
block|{
name|tst_QMacStyle
operator|::
name|sizeHints_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|layoutSpacings
name|void
name|tst_QMacStyle
operator|::
name|layoutSpacings
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|Size
argument_list|,
name|size
argument_list|)
expr_stmt|;
comment|/*         Constraints specified by AHIG.     */
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|ControlType
name|c1
init|=
operator|(
name|i
operator|%
literal|2
operator|==
literal|0
operator|)
condition|?
name|PushButton
else|:
name|ButtonBox
decl_stmt|;
name|ControlType
name|c2
init|=
operator|(
name|i
operator|/
literal|2
operator|==
literal|0
operator|)
condition|?
name|PushButton
else|:
name|ButtonBox
decl_stmt|;
name|QCOMPARE
argument_list|(
name|hspacing
argument_list|(
name|c1
argument_list|,
name|c2
argument_list|,
name|size
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|14
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|vspacing
argument_list|(
name|c1
argument_list|,
name|c2
argument_list|,
name|size
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|14
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|hspacing
argument_list|(
name|Label
argument_list|,
name|RadioButton
argument_list|,
name|size
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|8
argument_list|,
literal|6
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|vspacing
argument_list|(
name|RadioButton
argument_list|,
name|RadioButton
argument_list|,
name|size
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
comment|// Builder, guess, AHIG
name|QCOMPARE
argument_list|(
name|hspacing
argument_list|(
name|Label
argument_list|,
name|CheckBox
argument_list|,
name|size
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|8
argument_list|,
literal|6
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|vspacing
argument_list|(
name|CheckBox
argument_list|,
name|CheckBox
argument_list|,
name|size
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|7
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hspacing
argument_list|(
name|Label
argument_list|,
name|ComboBox
argument_list|,
name|size
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|8
argument_list|,
literal|6
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hspacing
argument_list|(
name|LineEdit
argument_list|,
name|LineEdit
argument_list|,
name|size
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|10
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
comment|/*         Common sense constraints, for when AHIG seems to make no sense (e.g., disagrees         too much with Builder or looks improper).     */
comment|// Comboboxes are a special pain, because AHIG and Builder can't agree,
comment|// and because they can be editable or not, with two totally different looks
name|QVERIFY
argument_list|(
name|vspacing
argument_list|(
name|ComboBox
argument_list|,
name|ComboBox
argument_list|,
name|size
argument_list|)
operator|>=
name|SIZE
argument_list|(
literal|8
argument_list|,
literal|6
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|vspacing
argument_list|(
name|ComboBox
argument_list|,
name|ComboBox
argument_list|,
name|size
argument_list|)
operator|<=
name|SIZE
argument_list|(
literal|12
argument_list|,
literal|10
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
comment|// Make sure button boxes get the respect they deserve, when they occur
comment|// in the bottom or right side of a dialog
name|QCOMPARE
argument_list|(
name|hspacing
argument_list|(
name|ButtonBox
argument_list|,
name|LineEdit
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|20
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|vspacing
argument_list|(
name|ButtonBox
argument_list|,
name|LineEdit
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|20
argument_list|,
literal|7
argument_list|,
literal|7
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hspacing
argument_list|(
name|LineEdit
argument_list|,
name|ButtonBox
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|vspacing
argument_list|(
name|LineEdit
argument_list|,
name|ButtonBox
argument_list|)
argument_list|,
name|SIZE
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// helper functions
end_comment
begin_function
DECL|function|msh
name|QSize
name|tst_QMacStyle
operator|::
name|msh
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|QWidgetItem
name|item
argument_list|(
name|widget
argument_list|)
decl_stmt|;
return|return
name|item
operator|.
name|sizeHint
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|sh
name|QSize
name|tst_QMacStyle
operator|::
name|sh
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|QWidgetItem
name|item
argument_list|(
name|widget
argument_list|)
decl_stmt|;
return|return
name|item
operator|.
name|sizeHint
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|geo
name|QRect
name|tst_QMacStyle
operator|::
name|geo
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|QWidgetItem
name|item
argument_list|(
name|widget
argument_list|)
decl_stmt|;
return|return
name|item
operator|.
name|geometry
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|gap
name|QSize
name|tst_QMacStyle
operator|::
name|gap
parameter_list|(
name|QWidget
modifier|*
name|widget1
parameter_list|,
name|QWidget
modifier|*
name|widget2
parameter_list|)
block|{
name|QPoint
name|d
init|=
name|pos
argument_list|(
name|widget2
argument_list|)
operator|-
name|pos
argument_list|(
name|widget1
argument_list|)
decl_stmt|;
name|QSize
name|s
init|=
name|size
argument_list|(
name|widget1
argument_list|)
decl_stmt|;
return|return
name|s
operator|+
name|QSize
argument_list|(
name|d
operator|.
name|x
argument_list|()
argument_list|,
name|d
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setSize
name|void
name|tst_QMacStyle
operator|::
name|setSize
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
name|Size
name|size
parameter_list|)
block|{
switch|switch
condition|(
name|size
condition|)
block|{
case|case
name|Normal
case|:
name|QMacStyle
operator|::
name|setWidgetSizePolicy
argument_list|(
name|widget
argument_list|,
name|QMacStyle
operator|::
name|SizeDefault
argument_list|)
expr_stmt|;
break|break;
case|case
name|Small
case|:
name|QMacStyle
operator|::
name|setWidgetSizePolicy
argument_list|(
name|widget
argument_list|,
name|QMacStyle
operator|::
name|SizeSmall
argument_list|)
expr_stmt|;
break|break;
case|case
name|Mini
case|:
name|QMacStyle
operator|::
name|setWidgetSizePolicy
argument_list|(
name|widget
argument_list|,
name|QMacStyle
operator|::
name|SizeMini
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|spacing
name|int
name|tst_QMacStyle
operator|::
name|spacing
parameter_list|(
name|ControlType
name|control1
parameter_list|,
name|ControlType
name|control2
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
return|return
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|layoutSpacing
argument_list|(
name|control1
argument_list|,
name|control2
argument_list|,
name|orientation
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|hspacing
name|int
name|tst_QMacStyle
operator|::
name|hspacing
parameter_list|(
name|ControlType
name|control1
parameter_list|,
name|ControlType
name|control2
parameter_list|,
name|Size
name|size
parameter_list|)
block|{
name|QWidget
name|w
decl_stmt|;
name|setSize
argument_list|(
operator|&
name|w
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QStyleOption
name|opt
decl_stmt|;
name|opt
operator|.
name|initFrom
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
return|return
name|spacing
argument_list|(
name|control1
argument_list|,
name|control2
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|,
operator|&
name|opt
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|vspacing
name|int
name|tst_QMacStyle
operator|::
name|vspacing
parameter_list|(
name|ControlType
name|control1
parameter_list|,
name|ControlType
name|control2
parameter_list|,
name|Size
name|size
parameter_list|)
block|{
name|QWidget
name|w
decl_stmt|;
name|setSize
argument_list|(
operator|&
name|w
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|QStyleOption
name|opt
decl_stmt|;
name|opt
operator|.
name|initFrom
argument_list|(
operator|&
name|w
argument_list|)
expr_stmt|;
return|return
name|spacing
argument_list|(
name|control1
argument_list|,
name|control2
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|,
operator|&
name|opt
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|smallMiniNormalExclusivity_data
name|void
name|tst_QMacStyle
operator|::
name|smallMiniNormalExclusivity_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"size3"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expectedHeight1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expectedHeight2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"expectedHeight3"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"normal small mini"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacNormalSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacSmallSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacMiniSize
argument_list|)
operator|<<
literal|32
operator|<<
literal|16
operator|<<
literal|24
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"normal mini small"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacNormalSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacMiniSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacSmallSize
argument_list|)
operator|<<
literal|32
operator|<<
literal|24
operator|<<
literal|16
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"small normal mini"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacSmallSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacNormalSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacMiniSize
argument_list|)
operator|<<
literal|16
operator|<<
literal|32
operator|<<
literal|24
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"small mini normal"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacSmallSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacMiniSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacNormalSize
argument_list|)
operator|<<
literal|16
operator|<<
literal|24
operator|<<
literal|32
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mini small normal"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacMiniSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacSmallSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacNormalSize
argument_list|)
operator|<<
literal|24
operator|<<
literal|16
operator|<<
literal|32
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mini normal small"
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacMiniSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacNormalSize
argument_list|)
operator|<<
name|int
argument_list|(
name|Qt
operator|::
name|WA_MacSmallSize
argument_list|)
operator|<<
literal|24
operator|<<
literal|32
operator|<<
literal|16
expr_stmt|;
block|}
end_function
begin_function
DECL|function|smallMiniNormalExclusivity
name|void
name|tst_QMacStyle
operator|::
name|smallMiniNormalExclusivity
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|size3
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expectedHeight1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expectedHeight2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|expectedHeight3
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|int
name|TotalSizes
init|=
literal|3
decl_stmt|;
name|int
name|attrs
index|[
name|TotalSizes
index|]
init|=
block|{
name|size1
block|,
name|size2
block|,
name|size3
block|}
decl_stmt|;
name|int
name|expected
index|[
name|TotalSizes
index|]
init|=
block|{
name|expectedHeight1
block|,
name|expectedHeight2
block|,
name|expectedHeight3
block|}
decl_stmt|;
name|QPushButton
name|dummyWidget
decl_stmt|;
name|QStyleOptionButton
name|opt
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
name|TotalSizes
condition|;
operator|++
name|i
control|)
block|{
name|dummyWidget
operator|.
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WidgetAttribute
argument_list|(
name|attrs
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|opt
operator|.
name|initFrom
argument_list|(
operator|&
name|dummyWidget
argument_list|)
expr_stmt|;
name|QSize
name|size
init|=
name|dummyWidget
operator|.
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_PushButton
argument_list|,
operator|&
name|opt
argument_list|,
name|QSize
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
operator|&
name|dummyWidget
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|expected
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QMacStyle
argument_list|)
end_macro
begin_else
else|#
directive|else
end_else
begin_macro
name|QTEST_NOOP_MAIN
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"tst_qmacstyle.moc"
end_include
end_unit
