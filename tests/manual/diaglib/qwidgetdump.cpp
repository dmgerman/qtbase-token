begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwidgetdump.h"
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_if
if|#
directive|if
name|QT_VERSION
operator|>
literal|0x050000
end_if
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_namespace
DECL|namespace|QtDiag
namespace|namespace
name|QtDiag
block|{
DECL|function|dumpWidgetRecursion
specifier|static
name|void
name|dumpWidgetRecursion
parameter_list|(
name|QTextStream
modifier|&
name|str
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|,
name|FormatWindowOptions
name|options
parameter_list|,
name|int
name|depth
init|=
literal|0
parameter_list|)
block|{
name|indentStream
argument_list|(
name|str
argument_list|,
literal|2
operator|*
name|depth
argument_list|)
expr_stmt|;
name|formatObject
argument_list|(
name|str
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|str
operator|<<
literal|' '
operator|<<
operator|(
name|w
operator|->
name|isVisible
argument_list|()
condition|?
literal|"[visible] "
else|:
literal|"[hidden] "
operator|)
expr_stmt|;
if|if
condition|(
specifier|const
name|WId
name|nativeWinId
init|=
name|w
operator|->
name|internalWinId
argument_list|()
condition|)
name|str
operator|<<
literal|"[native: "
operator|<<
name|hex
operator|<<
name|showbase
operator|<<
name|nativeWinId
operator|<<
name|dec
operator|<<
name|noshowbase
operator|<<
literal|"] "
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|isWindow
argument_list|()
condition|)
name|str
operator|<<
literal|"[top] "
expr_stmt|;
name|str
operator|<<
operator|(
name|w
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Mapped
argument_list|)
condition|?
literal|"[mapped] "
else|:
literal|"[not mapped] "
operator|)
expr_stmt|;
if|if
condition|(
name|w
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_DontCreateNativeAncestors
argument_list|)
condition|)
name|str
operator|<<
literal|"[NoNativeAncestors] "
expr_stmt|;
if|if
condition|(
specifier|const
name|int
name|states
init|=
name|w
operator|->
name|windowState
argument_list|()
condition|)
name|str
operator|<<
literal|"windowState="
operator|<<
name|hex
operator|<<
name|showbase
operator|<<
name|states
operator|<<
name|dec
operator|<<
name|noshowbase
operator|<<
literal|' '
expr_stmt|;
name|formatRect
argument_list|(
name|str
argument_list|,
name|w
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|options
operator|&
name|DontPrintWindowFlags
operator|)
condition|)
block|{
name|str
operator|<<
literal|' '
expr_stmt|;
name|formatWindowFlags
argument_list|(
name|str
argument_list|,
name|w
operator|->
name|windowFlags
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|str
operator|<<
literal|'\n'
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>
literal|0x050000
if|if
condition|(
specifier|const
name|QWindow
modifier|*
name|win
init|=
name|w
operator|->
name|windowHandle
argument_list|()
condition|)
block|{
name|indentStream
argument_list|(
name|str
argument_list|,
literal|2
operator|*
operator|(
literal|1
operator|+
name|depth
operator|)
argument_list|)
expr_stmt|;
name|formatWindow
argument_list|(
name|str
argument_list|,
name|win
argument_list|,
name|options
argument_list|)
expr_stmt|;
name|str
operator|<<
literal|'\n'
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Qt 5
foreach|foreach
control|(
specifier|const
name|QObject
modifier|*
name|co
decl|,
name|w
operator|->
name|children
argument_list|()
control|)
block|{
if|if
condition|(
name|co
operator|->
name|isWidgetType
argument_list|()
condition|)
name|dumpWidgetRecursion
argument_list|(
name|str
argument_list|,
cast|static_cast
argument_list|<
specifier|const
name|QWidget
operator|*
argument_list|>
argument_list|(
name|co
argument_list|)
argument_list|,
name|options
argument_list|,
name|depth
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|dumpAllWidgets
name|void
name|dumpAllWidgets
parameter_list|(
name|FormatWindowOptions
name|options
parameter_list|)
block|{
name|QString
name|d
decl_stmt|;
name|QTextStream
name|str
argument_list|(
operator|&
name|d
argument_list|)
decl_stmt|;
name|str
operator|<<
literal|"### QWidgets:\n"
expr_stmt|;
foreach|foreach
control|(
name|QWidget
modifier|*
name|tw
decl|,
name|QApplication
operator|::
name|topLevelWidgets
argument_list|()
control|)
name|dumpWidgetRecursion
argument_list|(
name|str
argument_list|,
name|tw
argument_list|,
name|options
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050400
name|qDebug
argument_list|()
operator|.
name|noquote
argument_list|()
operator|<<
name|d
expr_stmt|;
else|#
directive|else
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|qPrintable
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_namespace
begin_comment
comment|// namespace QtDiag
end_comment
end_unit
