begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGTK2PAINTER_P_H
end_ifndef
begin_define
DECL|macro|QGTK2PAINTER_P_H
define|#
directive|define
name|QGTK2PAINTER_P_H
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
file|<private/qgtkpainter_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QGtk2Painter
range|:
name|public
name|QGtkPainter
block|{
name|public
operator|:
name|QGtk2Painter
argument_list|()
block|;
name|void
name|paintBoxGap
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkPositionType gap_side
argument_list|,
argument|gint x
argument_list|,
argument|gint width
argument_list|,
argument|GtkStyle *style
argument_list|)
block|;
name|void
name|paintBox
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintHline
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|int x1
argument_list|,
argument|int x2
argument_list|,
argument|int y
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintVline
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|int y1
argument_list|,
argument|int y2
argument_list|,
argument|int x
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintExpander
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkExpanderStyle expander_state
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintFocus
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintResizeGrip
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GdkWindowEdge edge
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintArrow
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&arrowrect
argument_list|,
argument|GtkArrowType arrow_type
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|gboolean fill
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintHandle
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkOrientation orientation
argument_list|,
argument|GtkStyle *style
argument_list|)
block|;
name|void
name|paintSlider
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|GtkOrientation orientation
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintShadow
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString&pmKey = QString()
argument_list|)
block|;
name|void
name|paintFlatBox
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar* part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString& = QString()
argument_list|)
block|;
name|void
name|paintExtention
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const gchar *part
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkPositionType gap_pos
argument_list|,
argument|GtkStyle *style
argument_list|)
block|;
name|void
name|paintOption
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString&detail
argument_list|)
block|;
name|void
name|paintCheckbox
argument_list|(
argument|GtkWidget *gtkWidget
argument_list|,
argument|const QRect&rect
argument_list|,
argument|GtkStateType state
argument_list|,
argument|GtkShadowType shadow
argument_list|,
argument|GtkStyle *style
argument_list|,
argument|const QString&detail
argument_list|)
block|;
name|private
operator|:
name|QPixmap
name|renderTheme
argument_list|(
argument|uchar *bdata
argument_list|,
argument|uchar *wdata
argument_list|,
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|GtkWidget
operator|*
name|m_window
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
comment|//!defined(QT_NO_STYLE_QGTK)
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGTK2PAINTER_P_H
end_comment
end_unit
