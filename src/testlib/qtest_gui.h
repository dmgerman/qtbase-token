begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEST_GUI_H
end_ifndef
begin_define
DECL|macro|QTEST_GUI_H
define|#
directive|define
name|QTEST_GUI_H
end_define
begin_comment
comment|// enable GUI features
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_GUI_LIB
end_ifndef
begin_define
DECL|macro|QT_GUI_LIB
define|#
directive|define
name|QT_GUI_LIB
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
literal|0
end_if
begin_pragma
pragma|#
directive|pragma
name|qt_class
name|(
name|QtTestGui
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/qtestassert.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestevent.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestmouse.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtesttouch.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestkeyboard.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_WIDGETS_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtGui/qicon.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// inform syncqt
end_comment
begin_pragma
pragma|#
directive|pragma
name|qt_no_master_include
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QTest
block|{
comment|/*!     \internal  */
name|template
operator|<
operator|>
specifier|inline
name|char
operator|*
name|toString
argument_list|(
argument|const QColor&color
argument_list|)
block|{
return|return
name|qstrdup
argument_list|(
name|color
operator|.
name|name
argument_list|()
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|qCompare
parameter_list|(
name|QIcon
specifier|const
modifier|&
name|t1
parameter_list|,
name|QIcon
specifier|const
modifier|&
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|QTEST_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|QIcon
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|qCompare
argument_list|(
operator|*
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|const
operator|*
operator|>
operator|(
operator|&
name|t1
operator|)
argument_list|,
operator|*
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|const
operator|*
operator|>
operator|(
operator|&
name|t2
operator|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|qCompare
parameter_list|(
name|QImage
specifier|const
modifier|&
name|t1
parameter_list|,
name|QImage
specifier|const
modifier|&
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|char
name|msg
index|[
literal|1024
index|]
decl_stmt|;
name|msg
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
specifier|const
name|bool
name|t1Null
init|=
name|t1
operator|.
name|isNull
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|t2Null
init|=
name|t2
operator|.
name|isNull
argument_list|()
decl_stmt|;
if|if
condition|(
name|t1Null
operator|!=
name|t2Null
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
literal|1024
argument_list|,
literal|"Compared QImages differ.\n"
literal|"   Actual   (%s).isNull(): %d\n"
literal|"   Expected (%s).isNull(): %d"
argument_list|,
name|actual
argument_list|,
name|t1Null
argument_list|,
name|expected
argument_list|,
name|t2Null
argument_list|)
expr_stmt|;
return|return
name|compare_helper
argument_list|(
name|false
argument_list|,
name|msg
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
if|if
condition|(
name|t1Null
operator|&&
name|t2Null
condition|)
return|return
name|compare_helper
argument_list|(
name|true
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
if|if
condition|(
name|t1
operator|.
name|width
argument_list|()
operator|!=
name|t2
operator|.
name|width
argument_list|()
operator|||
name|t1
operator|.
name|height
argument_list|()
operator|!=
name|t2
operator|.
name|height
argument_list|()
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
literal|1024
argument_list|,
literal|"Compared QImages differ in size.\n"
literal|"   Actual   (%s): %dx%d\n"
literal|"   Expected (%s): %dx%d"
argument_list|,
name|actual
argument_list|,
name|t1
operator|.
name|width
argument_list|()
argument_list|,
name|t1
operator|.
name|height
argument_list|()
argument_list|,
name|expected
argument_list|,
name|t2
operator|.
name|width
argument_list|()
argument_list|,
name|t2
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|compare_helper
argument_list|(
name|false
argument_list|,
name|msg
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
if|if
condition|(
name|t1
operator|.
name|format
argument_list|()
operator|!=
name|t2
operator|.
name|format
argument_list|()
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
literal|1024
argument_list|,
literal|"Compared QImages differ in format.\n"
literal|"   Actual   (%s): %d\n"
literal|"   Expected (%s): %d"
argument_list|,
name|actual
argument_list|,
name|t1
operator|.
name|format
argument_list|()
argument_list|,
name|expected
argument_list|,
name|t2
operator|.
name|format
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|compare_helper
argument_list|(
name|false
argument_list|,
name|msg
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
return|return
name|compare_helper
argument_list|(
name|t1
operator|==
name|t2
argument_list|,
literal|"Compared values are not the same"
argument_list|,
name|toString
argument_list|(
name|t1
argument_list|)
argument_list|,
name|toString
argument_list|(
name|t2
argument_list|)
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|qCompare
parameter_list|(
name|QPixmap
specifier|const
modifier|&
name|t1
parameter_list|,
name|QPixmap
specifier|const
modifier|&
name|t2
parameter_list|,
specifier|const
name|char
modifier|*
name|actual
parameter_list|,
specifier|const
name|char
modifier|*
name|expected
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|char
name|msg
index|[
literal|1024
index|]
decl_stmt|;
name|msg
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
specifier|const
name|bool
name|t1Null
init|=
name|t1
operator|.
name|isNull
argument_list|()
decl_stmt|;
specifier|const
name|bool
name|t2Null
init|=
name|t2
operator|.
name|isNull
argument_list|()
decl_stmt|;
if|if
condition|(
name|t1Null
operator|!=
name|t2Null
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
literal|1024
argument_list|,
literal|"Compared QPixmaps differ.\n"
literal|"   Actual   (%s).isNull(): %d\n"
literal|"   Expected (%s).isNull(): %d"
argument_list|,
name|actual
argument_list|,
name|t1Null
argument_list|,
name|expected
argument_list|,
name|t2Null
argument_list|)
expr_stmt|;
return|return
name|compare_helper
argument_list|(
name|false
argument_list|,
name|msg
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
if|if
condition|(
name|t1Null
operator|&&
name|t2Null
condition|)
return|return
name|compare_helper
argument_list|(
name|true
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
if|if
condition|(
name|t1
operator|.
name|width
argument_list|()
operator|!=
name|t2
operator|.
name|width
argument_list|()
operator|||
name|t1
operator|.
name|height
argument_list|()
operator|!=
name|t2
operator|.
name|height
argument_list|()
condition|)
block|{
name|qsnprintf
argument_list|(
name|msg
argument_list|,
literal|1024
argument_list|,
literal|"Compared QPixmaps differ in size.\n"
literal|"   Actual   (%s): %dx%d\n"
literal|"   Expected (%s): %dx%d"
argument_list|,
name|actual
argument_list|,
name|t1
operator|.
name|width
argument_list|()
argument_list|,
name|t1
operator|.
name|height
argument_list|()
argument_list|,
name|expected
argument_list|,
name|t2
operator|.
name|width
argument_list|()
argument_list|,
name|t2
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|compare_helper
argument_list|(
name|false
argument_list|,
name|msg
argument_list|,
name|Q_NULLPTR
argument_list|,
name|Q_NULLPTR
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
return|return
name|qCompare
argument_list|(
name|t1
operator|.
name|toImage
argument_list|()
argument_list|,
name|t2
operator|.
name|toImage
argument_list|()
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
return|;
block|}
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
