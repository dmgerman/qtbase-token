begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSSTYLE_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSSTYLE_P_H
define|#
directive|define
name|QWINDOWSSTYLE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qwindowsstyle.h"
end_include
begin_include
include|#
directive|include
file|"qcommonstyle_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWS
end_ifndef
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTime
name|class
name|QTime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QProgressBar
name|class
name|QProgressBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsStylePrivate
range|:
name|public
name|QCommonStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QWindowsStyle
argument_list|)
name|public
operator|:
name|QWindowsStylePrivate
argument_list|()
block|;
name|void
name|startProgressAnimation
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QProgressBar
operator|*
name|bar
argument_list|)
block|;
name|void
name|stopProgressAnimation
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QProgressBar
operator|*
name|bar
argument_list|)
block|;
name|bool
name|hasSeenAlt
argument_list|(
argument|const QWidget *widget
argument_list|)
specifier|const
block|;
name|bool
name|altDown
argument_list|()
specifier|const
block|{
return|return
name|alt_down
return|;
block|}
name|bool
name|alt_down
block|;
name|QList
operator|<
specifier|const
name|QWidget
operator|*
operator|>
name|seenAlt
block|;
name|int
name|menuBarTimer
block|;
name|QColor
name|inactiveCaptionText
block|;
name|QColor
name|activeCaptionColor
block|;
name|QColor
name|activeGradientCaptionColor
block|;
name|QColor
name|inactiveCaptionColor
block|;
name|QColor
name|inactiveGradientCaptionColor
block|;      enum
block|{
name|windowsItemFrame
operator|=
literal|2
block|,
comment|// menu item frame width
name|windowsSepHeight
operator|=
literal|9
block|,
comment|// separator item height
name|windowsItemHMargin
operator|=
literal|3
block|,
comment|// menu item hor text margin
name|windowsItemVMargin
operator|=
literal|2
block|,
comment|// menu item ver text margin
name|windowsArrowHMargin
operator|=
literal|6
block|,
comment|// arrow horizontal margin
name|windowsRightBorder
operator|=
literal|15
block|,
comment|// right border on windows
name|windowsCheckMarkWidth
operator|=
literal|12
comment|// checkmarks width on windows
block|}
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_WINDOWS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QWINDOWSSTYLE_P_H
end_comment
end_unit
