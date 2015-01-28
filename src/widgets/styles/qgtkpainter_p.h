begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGTKPAINTER_H
end_ifndef
begin_define
DECL|macro|QGTKPAINTER_H
define|#
directive|define
name|QGTKPAINTER_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_GTK
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qgtkglobal_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpainter.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QGtkPainter
block|{
name|public
label|:
name|QGtkPainter
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QGtkPainter
argument_list|()
expr_stmt|;
name|void
name|reset
parameter_list|(
name|QPainter
modifier|*
name|painter
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setAlphaSupport
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|m_alpha
operator|=
name|value
expr_stmt|;
block|}
name|void
name|setClipRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|m_cliprect
operator|=
name|rect
expr_stmt|;
block|}
name|void
name|setFlipHorizontal
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|m_hflipped
operator|=
name|value
expr_stmt|;
block|}
name|void
name|setFlipVertical
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|m_vflipped
operator|=
name|value
expr_stmt|;
block|}
name|void
name|setUsePixmapCache
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|m_usePixmapCache
operator|=
name|value
expr_stmt|;
block|}
name|virtual
name|void
name|paintBoxGap
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkPositionType
name|gap_side
parameter_list|,
name|gint
name|x
parameter_list|,
name|gint
name|width
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintBox
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintHline
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
name|int
name|x1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|y
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintVline
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
name|int
name|y1
parameter_list|,
name|int
name|y2
parameter_list|,
name|int
name|x
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintExpander
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkExpanderStyle
name|expander_state
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintFocus
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintResizeGrip
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GdkWindowEdge
name|edge
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintArrow
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|arrowrect
parameter_list|,
name|GtkArrowType
name|arrow_type
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|gboolean
name|fill
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintHandle
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkOrientation
name|orientation
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintSlider
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
name|GtkOrientation
name|orientation
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintShadow
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
name|pmKey
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintFlatBox
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
init|=
name|QString
argument_list|()
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintExtention
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|gchar
modifier|*
name|part
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkPositionType
name|gap_pos
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintOption
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
name|detail
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|paintCheckbox
parameter_list|(
name|GtkWidget
modifier|*
name|gtkWidget
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
name|GtkStyle
modifier|*
name|style
parameter_list|,
specifier|const
name|QString
modifier|&
name|detail
parameter_list|)
init|=
literal|0
function_decl|;
name|protected
label|:
specifier|static
name|QString
name|uniqueName
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|GtkStateType
name|state
parameter_list|,
name|GtkShadowType
name|shadow
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|GtkWidget
modifier|*
name|widget
init|=
literal|0
parameter_list|)
function_decl|;
name|QPainter
modifier|*
name|m_painter
decl_stmt|;
name|bool
name|m_alpha
decl_stmt|;
name|bool
name|m_hflipped
decl_stmt|;
name|bool
name|m_vflipped
decl_stmt|;
name|bool
name|m_usePixmapCache
decl_stmt|;
name|QRect
name|m_cliprect
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//!defined(QT_NO_STYLE_QGTK)
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGTKPAINTER_H
end_comment
end_unit
