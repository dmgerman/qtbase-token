begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPAINTDEVICEWINDOW_P_H
end_ifndef
begin_define
DECL|macro|QPAINTDEVICEWINDOW_P_H
define|#
directive|define
name|QPAINTDEVICEWINDOW_P_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QPaintDeviceWindow>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qwindow_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPaintEvent>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QPaintDeviceWindowPrivate
range|:
name|public
name|QWindowPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPaintDeviceWindow
argument_list|)
name|public
operator|:
name|QPaintDeviceWindowPrivate
argument_list|()
operator|:
name|paintEventSent
argument_list|(
argument|false
argument_list|)
block|{ }
name|virtual
name|void
name|beginPaint
argument_list|(
argument|const QRegion&region
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
block|;     }
name|virtual
name|void
name|endPaint
argument_list|()
block|{     }
name|virtual
name|void
name|flush
argument_list|(
argument|const QRegion&region
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
block|;     }
name|bool
name|paint
argument_list|(
argument|const QRegion&region
argument_list|)
block|{
name|Q_Q
argument_list|(
name|QPaintDeviceWindow
argument_list|)
block|;
name|QRegion
name|toPaint
operator|=
name|region
operator|&
name|dirtyRegion
block|;
if|if
condition|(
name|toPaint
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|false
return|;
comment|// Clear the region now. The overridden functions may call update().
name|dirtyRegion
operator|-=
name|toPaint
block|;
name|beginPaint
argument_list|(
name|toPaint
argument_list|)
block|;
name|QPaintEvent
name|paintEvent
argument_list|(
name|toPaint
argument_list|)
block|;
name|q
operator|->
name|paintEvent
argument_list|(
operator|&
name|paintEvent
argument_list|)
block|;
name|endPaint
argument_list|()
block|;
return|return
name|true
return|;
block|}
end_decl_stmt
begin_function
name|void
name|triggerUpdate
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QPaintDeviceWindow
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|paintEventSent
condition|)
block|{
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
argument|q
argument_list|,
argument|new QEvent(QEvent::UpdateRequest)
argument_list|)
expr_stmt|;
name|paintEventSent
operator|=
name|true
expr_stmt|;
block|}
block|}
end_function
begin_function
name|void
name|doFlush
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|QRegion
name|toFlush
init|=
name|region
decl_stmt|;
if|if
condition|(
name|paint
argument_list|(
name|toFlush
argument_list|)
condition|)
name|flush
argument_list|(
name|toFlush
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|handleUpdateEvent
parameter_list|()
block|{
if|if
condition|(
name|dirtyRegion
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|doFlush
argument_list|(
name|dirtyRegion
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|markWindowAsDirty
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QPaintDeviceWindow
argument_list|)
expr_stmt|;
name|dirtyRegion
operator|+=
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|q
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QRegion
name|dirtyRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|paintEventSent
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QPAINTDEVICEWINDOW_P_H
end_comment
end_unit
