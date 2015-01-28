begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Robin Burchell<robin.burchell@viroteck.net> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTUIOCURSOR_P_H
end_ifndef
begin_define
DECL|macro|QTUIOCURSOR_P_H
define|#
directive|define
name|QTUIOCURSOR_P_H
end_define
begin_include
include|#
directive|include
file|<Qt>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QTuioCursor
block|{
name|public
label|:
name|QTuioCursor
argument_list|(
argument|int id = -
literal|1
argument_list|)
block|:
name|m_id
argument_list|(
name|id
argument_list|)
operator|,
name|m_x
argument_list|(
literal|0
argument_list|)
operator|,
name|m_y
argument_list|(
literal|0
argument_list|)
operator|,
name|m_vx
argument_list|(
literal|0
argument_list|)
operator|,
name|m_vy
argument_list|(
literal|0
argument_list|)
operator|,
name|m_acceleration
argument_list|(
literal|0
argument_list|)
operator|,
name|m_state
argument_list|(
argument|Qt::TouchPointPressed
argument_list|)
block|{     }
name|int
name|id
argument_list|()
specifier|const
block|{
return|return
name|m_id
return|;
block|}
name|void
name|setX
parameter_list|(
name|float
name|x
parameter_list|)
block|{
if|if
condition|(
name|state
argument_list|()
operator|==
name|Qt
operator|::
name|TouchPointStationary
operator|&&
operator|!
name|qFuzzyCompare
argument_list|(
name|m_x
operator|+
literal|2.0
argument_list|,
name|x
operator|+
literal|2.0
argument_list|)
condition|)
block|{
comment|// +2 because 1 is a valid value, and qFuzzyCompare can't cope with 0.0
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointMoved
argument_list|)
expr_stmt|;
block|}
name|m_x
operator|=
name|x
expr_stmt|;
block|}
name|float
name|x
argument_list|()
specifier|const
block|{
return|return
name|m_x
return|;
block|}
name|void
name|setY
parameter_list|(
name|float
name|y
parameter_list|)
block|{
if|if
condition|(
name|state
argument_list|()
operator|==
name|Qt
operator|::
name|TouchPointStationary
operator|&&
operator|!
name|qFuzzyCompare
argument_list|(
name|m_y
operator|+
literal|2.0
argument_list|,
name|y
operator|+
literal|2.0
argument_list|)
condition|)
block|{
comment|// +2 because 1 is a valid value, and qFuzzyCompare can't cope with 0.0
name|setState
argument_list|(
name|Qt
operator|::
name|TouchPointMoved
argument_list|)
expr_stmt|;
block|}
name|m_y
operator|=
name|y
expr_stmt|;
block|}
name|float
name|y
argument_list|()
specifier|const
block|{
return|return
name|m_y
return|;
block|}
name|void
name|setVX
parameter_list|(
name|float
name|vx
parameter_list|)
block|{
name|m_vx
operator|=
name|vx
expr_stmt|;
block|}
name|float
name|vx
argument_list|()
specifier|const
block|{
return|return
name|m_vx
return|;
block|}
name|void
name|setVY
parameter_list|(
name|float
name|vy
parameter_list|)
block|{
name|m_vy
operator|=
name|vy
expr_stmt|;
block|}
name|float
name|vy
argument_list|()
specifier|const
block|{
return|return
name|m_vy
return|;
block|}
name|void
name|setAcceleration
parameter_list|(
name|float
name|acceleration
parameter_list|)
block|{
name|m_acceleration
operator|=
name|acceleration
expr_stmt|;
block|}
name|float
name|acceleration
argument_list|()
specifier|const
block|{
return|return
name|m_acceleration
return|;
block|}
name|void
name|setState
argument_list|(
specifier|const
name|Qt
operator|::
name|TouchPointState
operator|&
name|state
argument_list|)
block|{
name|m_state
operator|=
name|state
expr_stmt|;
block|}
name|Qt
operator|::
name|TouchPointState
name|state
argument_list|()
specifier|const
block|{
return|return
name|m_state
return|;
block|}
name|private
label|:
name|int
name|m_id
decl_stmt|;
name|float
name|m_x
decl_stmt|;
name|float
name|m_y
decl_stmt|;
name|float
name|m_vx
decl_stmt|;
name|float
name|m_vy
decl_stmt|;
name|float
name|m_acceleration
decl_stmt|;
name|Qt
operator|::
name|TouchPointState
name|m_state
expr_stmt|;
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
comment|// QTUIOCURSOR_P_H
end_comment
end_unit
