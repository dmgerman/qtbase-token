begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|OLDNORMALIZEOBJECT_H
end_ifndef
begin_define
DECL|macro|OLDNORMALIZEOBJECT_H
define|#
directive|define
name|OLDNORMALIZEOBJECT_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_struct_decl
struct_decl|struct
name|Struct
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|Class
name|class
name|Class
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|Template
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Template
expr_stmt|;
end_expr_stmt
begin_comment
comment|// An object with old moc output that incorrectly normalizes 'T<C> const&' in the function
end_comment
begin_comment
comment|// signatures
end_comment
begin_decl_stmt
name|class
name|OldNormalizeObject
range|:
name|public
name|QObject
block|{
comment|/* tmake ignore Q_OBJECT */
name|Q_OBJECT
name|signals
operator|:
name|void
name|typeRefSignal
argument_list|(
name|Template
operator|<
name|Class
operator|&
operator|>
operator|&
name|ref
argument_list|)
block|;
name|void
name|constTypeRefSignal
argument_list|(
specifier|const
name|Template
operator|<
specifier|const
name|Class
operator|&
operator|>
operator|&
name|ref
argument_list|)
block|;
name|void
name|typeConstRefSignal
argument_list|(
name|Template
operator|<
name|Class
specifier|const
operator|&
operator|>
specifier|const
operator|&
name|ref
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|typeRefSlot
argument_list|(
argument|Template<Class&>&
argument_list|)
block|{}
name|void
name|constTypeRefSlot
argument_list|(
argument|const Template<const Class&>&
argument_list|)
block|{}
name|void
name|typeConstRefSlot
argument_list|(
argument|Template<Class const&> const&
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// OLDNORMALIZEOBJECT_H
end_comment
end_unit
