begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// moc parsing issue with "unsigned" subphrase
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TASK240368_H
end_ifndef
begin_define
DECL|macro|TASK240368_H
define|#
directive|define
name|TASK240368_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_typedef
DECL|member|_1
DECL|typedef|unsigned1
typedef|typedef
struct|struct
block|{
name|unsigned
name|_1
decl_stmt|;
block|}
name|unsigned1
typedef|;
end_typedef
begin_typedef
DECL|member|qi
DECL|typedef|unsignedQImage
typedef|typedef
struct|struct
block|{
name|unsigned
name|qi
decl_stmt|;
block|}
name|unsignedQImage
typedef|;
end_typedef
begin_decl_stmt
name|class
name|TypenameWithUnsigned
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
name|slots
operator|:
name|void
name|a
argument_list|(
argument|unsigned
argument_list|)
block|{ }
name|void
name|b
argument_list|(
argument|unsigned u
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|u
argument_list|)
block|; }
name|void
name|c
argument_list|(
argument|unsigned*
argument_list|)
block|{ }
name|void
name|d
argument_list|(
argument|unsigned* p
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|p
argument_list|)
block|; }
name|void
name|e
argument_list|(
argument|unsigned&
argument_list|)
block|{ }
name|void
name|f
argument_list|(
argument|unsigned& r
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|r
argument_list|)
block|; }
name|void
name|g
argument_list|(
argument|unsigned1
argument_list|)
block|{ }
name|void
name|h
argument_list|(
argument|unsigned1 u1
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|u1
argument_list|)
block|; }
name|void
name|i
argument_list|(
argument|unsigned
argument_list|,
argument|unsigned1
argument_list|)
block|{ }
name|void
name|j
argument_list|(
argument|unsigned1
argument_list|,
argument|unsigned
argument_list|)
block|{ }
name|void
name|k
argument_list|(
argument|unsignedQImage
argument_list|)
block|{ }
name|void
name|l
argument_list|(
argument|unsignedQImage uqi
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|uqi
argument_list|)
block|; }
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
