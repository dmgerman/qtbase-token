begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TST_QGRAPHICSVIEW_H
end_ifndef
begin_define
DECL|macro|TST_QGRAPHICSVIEW_H
define|#
directive|define
name|TST_QGRAPHICSVIEW_H
end_define
begin_comment
comment|// This file contains structs used in tst_qgraphicsview::scrollBarRanges.
end_comment
begin_comment
comment|// Whenever these mention scrollbars or spacing it is about the number of
end_comment
begin_comment
comment|// scrollbars or spacings to use as these are style dependent so that the real
end_comment
begin_comment
comment|// value to add/remove has to be obtained in test run using the actual style.
end_comment
begin_struct
DECL|struct|ExpectedValueDescription
struct|struct
name|ExpectedValueDescription
block|{
DECL|function|ExpectedValueDescription
name|ExpectedValueDescription
argument_list|(
argument|int v =
literal|0
argument_list|,
argument|int sbeta =
literal|0
argument_list|,
argument|int sta =
literal|0
argument_list|)
block|:
name|value
argument_list|(
name|v
argument_list|)
operator|,
name|scrollBarExtentsToAdd
argument_list|(
name|sbeta
argument_list|)
operator|,
name|spacingsToAdd
argument_list|(
argument|sta
argument_list|)
block|{     }
DECL|member|value
name|int
name|value
expr_stmt|;
comment|// Describes how often the scrollbar widht/height has to be added to or
comment|// removed from the value.
DECL|member|scrollBarExtentsToAdd
name|int
name|scrollBarExtentsToAdd
decl_stmt|;
comment|// Describes how often the scrollbar spacing has to be added to or removed
comment|// from the value if the used style has SH_ScrollView_FrameOnlyAroundContents
comment|// set
DECL|member|spacingsToAdd
name|int
name|spacingsToAdd
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|// Describes how often the scroll bar width/height has to be added to/removed
end_comment
begin_comment
comment|// from the according side of the sceneRect.
end_comment
begin_struct
DECL|struct|ScrollBarCount
struct|struct
name|ScrollBarCount
block|{
DECL|function|ScrollBarCount
name|ScrollBarCount
argument_list|(
argument|int l =
literal|0
argument_list|,
argument|int t =
literal|0
argument_list|,
argument|int r =
literal|0
argument_list|,
argument|int b =
literal|0
argument_list|)
block|:
name|left
argument_list|(
name|l
argument_list|)
operator|,
name|top
argument_list|(
name|t
argument_list|)
operator|,
name|right
argument_list|(
name|r
argument_list|)
operator|,
name|bottom
argument_list|(
argument|b
argument_list|)
block|{     }
DECL|member|left
name|int
name|left
expr_stmt|;
DECL|member|top
name|int
name|top
decl_stmt|;
DECL|member|right
name|int
name|right
decl_stmt|;
DECL|member|bottom
name|int
name|bottom
decl_stmt|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TST_QGRAPHICSVIEW_H
end_comment
end_unit
