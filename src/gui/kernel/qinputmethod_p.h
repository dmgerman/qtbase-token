begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QINPUTMETHOD_P_H
end_ifndef
begin_define
DECL|macro|QINPUTMETHOD_P_H
define|#
directive|define
name|QINPUTMETHOD_P_H
end_define
begin_include
include|#
directive|include
file|<qinputmethod.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QWeakPointer>
end_include
begin_include
include|#
directive|include
file|<QTransform>
end_include
begin_include
include|#
directive|include
file|<qplatforminputcontext_qpa.h>
end_include
begin_include
include|#
directive|include
file|<qplatformintegration_qpa.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QInputMethodPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QInputMethod
argument_list|)
name|public
operator|:
specifier|inline
name|QInputMethodPrivate
argument_list|()
operator|:
name|testContext
argument_list|(
literal|0
argument_list|)
block|{}
name|QPlatformInputContext
operator|*
name|platformInputContext
argument_list|()
specifier|const
block|{
return|return
name|testContext
operator|?
name|testContext
operator|:
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|inputContext
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|QInputMethodPrivate
operator|*
name|get
argument_list|(
argument|QInputMethod *inputMethod
argument_list|)
block|{
return|return
name|inputMethod
operator|->
name|d_func
argument_list|()
return|;
block|}
name|void
name|q_connectFocusObject
argument_list|()
block|;
name|void
name|q_checkFocusObject
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|QTransform
name|inputItemTransform
block|;
name|QWeakPointer
operator|<
name|QObject
operator|>
name|inputItem
block|;
name|QPlatformInputContext
operator|*
name|testContext
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
