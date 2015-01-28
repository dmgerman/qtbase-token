begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWHATSTHIS_H
end_ifndef
begin_define
DECL|macro|QWHATSTHIS_H
define|#
directive|define
name|QWHATSTHIS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcursor.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_WHATSTHIS
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QWhatsThis
block|{
name|QWhatsThis
argument_list|()
name|Q_DECL_EQ_DELETE
expr_stmt|;
name|public
label|:
specifier|static
name|void
name|enterWhatsThisMode
parameter_list|()
function_decl|;
specifier|static
name|bool
name|inWhatsThisMode
parameter_list|()
function_decl|;
specifier|static
name|void
name|leaveWhatsThisMode
parameter_list|()
function_decl|;
specifier|static
name|void
name|showText
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
name|QWidget
modifier|*
name|w
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|void
name|hideText
parameter_list|()
function_decl|;
specifier|static
name|QAction
modifier|*
name|createAction
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_WHATSTHIS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWHATSTHIS_H
end_comment
end_unit
