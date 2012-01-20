begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|tst_QBoxLayout
class|class
name|tst_QBoxLayout
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QBoxLayout
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QBoxLayout
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|insertSpacerItem
parameter_list|()
function_decl|;
name|void
name|sizeHint
parameter_list|()
function_decl|;
name|void
name|sizeConstraints
parameter_list|()
function_decl|;
name|void
name|setGeometry
parameter_list|()
function_decl|;
name|void
name|setStyleShouldChangeSpacing
parameter_list|()
function_decl|;
name|void
name|taskQTBUG_7103_minMaxWidthNotRespected
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|CustomLayoutStyle
class|class
name|CustomLayoutStyle
super|:
specifier|public
name|QWindowsStyle
block|{
name|Q_OBJECT
public|public:
DECL|function|CustomLayoutStyle
name|CustomLayoutStyle
parameter_list|()
member_init_list|:
name|QWindowsStyle
argument_list|()
block|{
name|hspacing
operator|=
literal|5
expr_stmt|;
name|vspacing
operator|=
literal|10
expr_stmt|;
block|}
specifier|virtual
name|int
name|pixelMetric
parameter_list|(
name|PixelMetric
name|metric
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
init|=
literal|0
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
specifier|const
function_decl|;
DECL|member|hspacing
name|int
name|hspacing
decl_stmt|;
DECL|member|vspacing
name|int
name|vspacing
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|pixelMetric
name|int
name|CustomLayoutStyle
operator|::
name|pixelMetric
parameter_list|(
name|PixelMetric
name|metric
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
comment|/*= 0*/
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
comment|/*= 0*/
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|PM_LayoutLeftMargin
case|:
return|return
literal|0
return|;
break|break;
case|case
name|PM_LayoutTopMargin
case|:
return|return
literal|3
return|;
break|break;
case|case
name|PM_LayoutRightMargin
case|:
return|return
literal|6
return|;
break|break;
case|case
name|PM_LayoutBottomMargin
case|:
return|return
literal|9
return|;
break|break;
case|case
name|PM_LayoutHorizontalSpacing
case|:
return|return
name|hspacing
return|;
case|case
name|PM_LayoutVerticalSpacing
case|:
return|return
name|vspacing
return|;
break|break;
default|default:
break|break;
block|}
return|return
name|QWindowsStyle
operator|::
name|pixelMetric
argument_list|(
name|metric
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|tst_QBoxLayout
name|tst_QBoxLayout
operator|::
name|tst_QBoxLayout
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QBoxLayout
name|tst_QBoxLayout
operator|::
name|~
name|tst_QBoxLayout
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QBoxLayout
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QBoxLayout
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|init
name|void
name|tst_QBoxLayout
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QBoxLayout
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|insertSpacerItem
name|void
name|tst_QBoxLayout
operator|::
name|insertSpacerItem
parameter_list|()
block|{
name|QWidget
modifier|*
name|window
init|=
operator|new
name|QWidget
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacer1
init|=
operator|new
name|QSpacerItem
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
decl_stmt|;
name|QSpacerItem
modifier|*
name|spacer2
init|=
operator|new
name|QSpacerItem
argument_list|(
literal|40
argument_list|,
literal|20
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
decl_stmt|;
name|QBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLineEdit
argument_list|(
literal|"Foooooooooooooooooooooooooo"
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addSpacerItem
argument_list|(
name|spacer1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
operator|new
name|QLineEdit
argument_list|(
literal|"Baaaaaaaaaaaaaaaaaaaaaaaaar"
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|insertSpacerItem
argument_list|(
literal|0
argument_list|,
name|spacer2
argument_list|)
expr_stmt|;
name|window
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layout
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
operator|==
name|spacer2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|layout
operator|->
name|itemAt
argument_list|(
literal|2
argument_list|)
operator|==
name|spacer1
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|void
name|tst_QBoxLayout
operator|::
name|sizeHint
parameter_list|()
block|{
name|QWidget
modifier|*
name|window
init|=
operator|new
name|QWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|lay1
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|QHBoxLayout
modifier|*
name|lay2
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
literal|"widget twooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
argument_list|)
decl_stmt|;
name|lay2
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|lay1
operator|->
name|addLayout
argument_list|(
name|lay2
argument_list|)
expr_stmt|;
name|window
operator|->
name|setLayout
argument_list|(
name|lay1
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
name|label
operator|->
name|setText
argument_list|(
literal|"foooooooo baaaaaaar"
argument_list|)
expr_stmt|;
name|QSize
name|sh
init|=
name|lay1
operator|->
name|sizeHint
argument_list|()
decl_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
comment|// Note that this is not strictly required behaviour - actually
comment|// the preferred behaviour would be that sizeHint returns
comment|// the same value regardless of what's lying in the event queue.
comment|// (i.e. we would check for equality here instead)
name|QVERIFY
argument_list|(
name|lay1
operator|->
name|sizeHint
argument_list|()
operator|!=
name|sh
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeConstraints
name|void
name|tst_QBoxLayout
operator|::
name|sizeConstraints
parameter_list|()
block|{
name|QWidget
modifier|*
name|window
init|=
operator|new
name|QWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|lay
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|lay
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
literal|"foooooooooooooooooooooooooooooooooooo"
argument_list|)
argument_list|)
expr_stmt|;
name|lay
operator|->
name|addWidget
argument_list|(
operator|new
name|QLabel
argument_list|(
literal|"baaaaaaaaaaaaaaaaaaaaaaaaaaaaaar"
argument_list|)
argument_list|)
expr_stmt|;
name|lay
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetFixedSize
argument_list|)
expr_stmt|;
name|window
operator|->
name|setLayout
argument_list|(
name|lay
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QSize
name|sh
init|=
name|window
operator|->
name|sizeHint
argument_list|()
decl_stmt|;
name|lay
operator|->
name|takeAt
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|sh
operator|.
name|width
argument_list|()
operator|>=
name|window
operator|->
name|sizeHint
argument_list|()
operator|.
name|width
argument_list|()
operator|&&
name|sh
operator|.
name|height
argument_list|()
operator|>=
name|window
operator|->
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|tst_QBoxLayout
operator|::
name|setGeometry
parameter_list|()
block|{
name|QWidget
name|toplevel
decl_stmt|;
name|QWidget
name|w
argument_list|(
operator|&
name|toplevel
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|lay
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|lay
operator|->
name|setMargin
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|lay
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|lay2
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|QDial
modifier|*
name|dial
init|=
operator|new
name|QDial
decl_stmt|;
name|lay2
operator|->
name|addWidget
argument_list|(
name|dial
argument_list|)
expr_stmt|;
name|lay2
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignTop
argument_list|)
expr_stmt|;
name|lay2
operator|->
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|lay
operator|->
name|addLayout
argument_list|(
name|lay2
argument_list|)
expr_stmt|;
name|w
operator|.
name|setLayout
argument_list|(
name|lay
argument_list|)
expr_stmt|;
name|toplevel
operator|.
name|show
argument_list|()
expr_stmt|;
name|QRect
name|newGeom
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|70
argument_list|,
literal|70
argument_list|)
decl_stmt|;
name|lay2
operator|->
name|setGeometry
argument_list|(
name|newGeom
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
name|newGeom
operator|.
name|contains
argument_list|(
name|dial
operator|->
name|geometry
argument_list|()
argument_list|)
argument_list|,
literal|"dial->geometry() should be smaller and within newGeom"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setStyleShouldChangeSpacing
name|void
name|tst_QBoxLayout
operator|::
name|setStyleShouldChangeSpacing
parameter_list|()
block|{
name|QWidget
modifier|*
name|window
init|=
operator|new
name|QWidget
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hbox
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|pb1
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"The spacing between this"
argument_list|)
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|pb2
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"and this button should depend on the style of the parent widget"
argument_list|)
argument_list|)
decl_stmt|;
empty_stmt|;
name|pb1
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_LayoutUsesWidgetRect
argument_list|)
expr_stmt|;
name|pb2
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_LayoutUsesWidgetRect
argument_list|)
expr_stmt|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|pb1
argument_list|)
expr_stmt|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|pb2
argument_list|)
expr_stmt|;
name|CustomLayoutStyle
modifier|*
name|style1
init|=
operator|new
name|CustomLayoutStyle
decl_stmt|;
name|style1
operator|->
name|hspacing
operator|=
literal|6
expr_stmt|;
name|window
operator|->
name|setStyle
argument_list|(
name|style1
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|int
name|spacing
init|=
name|pb2
operator|->
name|geometry
argument_list|()
operator|.
name|left
argument_list|()
operator|-
name|pb1
operator|->
name|geometry
argument_list|()
operator|.
name|right
argument_list|()
operator|-
literal|1
decl_stmt|;
name|QCOMPARE
argument_list|(
name|spacing
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|CustomLayoutStyle
modifier|*
name|style2
init|=
operator|new
name|CustomLayoutStyle
argument_list|()
decl_stmt|;
name|style2
operator|->
name|hspacing
operator|=
literal|10
expr_stmt|;
name|window
operator|->
name|setStyle
argument_list|(
name|style2
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|spacing
operator|=
name|pb2
operator|->
name|geometry
argument_list|()
operator|.
name|left
argument_list|()
operator|-
name|pb1
operator|->
name|geometry
argument_list|()
operator|.
name|right
argument_list|()
operator|-
literal|1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|spacing
argument_list|,
literal|10
argument_list|)
expr_stmt|;
operator|delete
name|window
expr_stmt|;
operator|delete
name|style1
expr_stmt|;
operator|delete
name|style2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|taskQTBUG_7103_minMaxWidthNotRespected
name|void
name|tst_QBoxLayout
operator|::
name|taskQTBUG_7103_minMaxWidthNotRespected
parameter_list|()
block|{
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
literal|"Qt uses standard C++, but makes extensive use of the C pre-processor to enrich the language. Qt can also be used in several other programming languages via language bindings. It runs on all major platforms, and has extensive internationalization support. Non-GUI features include SQL database access, XML parsing, thread management, network support and a unified cross-platform API for file handling."
argument_list|)
decl_stmt|;
name|label
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|label
operator|->
name|setFixedWidth
argument_list|(
literal|200
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addSpacerItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
argument_list|)
expr_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|widget
operator|.
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWaitForWindowShown
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
name|int
name|height
init|=
name|label
operator|->
name|height
argument_list|()
decl_stmt|;
name|QRect
name|g
init|=
name|widget
operator|.
name|geometry
argument_list|()
decl_stmt|;
name|g
operator|.
name|setWidth
argument_list|(
literal|600
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setGeometry
argument_list|(
name|g
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|label
operator|->
name|height
argument_list|()
argument_list|,
name|height
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QBoxLayout
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qboxlayout.moc"
end_include
end_unit
