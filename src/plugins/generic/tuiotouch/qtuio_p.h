begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Robin Burchell<robin.burchell@viroteck.net> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTUIO_P_H
end_ifndef
begin_define
DECL|macro|QTUIO_P_H
define|#
directive|define
name|QTUIO_P_H
end_define
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qt_readOscString
specifier|inline
name|bool
name|qt_readOscString
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|source
parameter_list|,
name|QByteArray
modifier|&
name|dest
parameter_list|,
name|quint32
modifier|&
name|pos
parameter_list|)
block|{
name|int
name|end
init|=
name|source
operator|.
name|indexOf
argument_list|(
literal|'\0'
argument_list|,
name|pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|end
operator|<
literal|0
condition|)
block|{
name|pos
operator|=
name|source
operator|.
name|size
argument_list|()
expr_stmt|;
name|dest
operator|=
name|QByteArray
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
name|dest
operator|=
name|source
operator|.
name|mid
argument_list|(
name|pos
argument_list|,
name|end
operator|-
name|pos
argument_list|)
expr_stmt|;
comment|// Skip additional NULL bytes at the end of the string to make sure the
comment|// total number of bits a multiple of 32 bits ("OSC-string" in the
comment|// specification).
name|end
operator|+=
literal|4
operator|-
operator|(
operator|(
name|end
operator|-
name|pos
operator|)
operator|%
literal|4
operator|)
expr_stmt|;
name|pos
operator|=
name|end
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
