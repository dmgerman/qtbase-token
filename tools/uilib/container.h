begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the Qt Designer of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONTAINER_H
end_ifndef
begin_define
DECL|macro|CONTAINER_H
define|#
directive|define
name|CONTAINER_H
end_define
begin_include
include|#
directive|include
file|<QtDesigner/extension.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDesignerContainerExtension
block|{
name|public
label|:
name|virtual
operator|~
name|QDesignerContainerExtension
argument_list|()
block|{}
name|virtual
name|int
name|count
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QWidget
modifier|*
name|widget
argument_list|(
name|int
name|index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|int
name|currentIndex
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setCurrentIndex
parameter_list|(
name|int
name|index
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|addWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|insertWidget
parameter_list|(
name|int
name|index
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|remove
parameter_list|(
name|int
name|index
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|canAddWidget
argument_list|()
specifier|const
comment|// ### Qt6 remove body, provided in Qt5 for source compatibility to Qt4.
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|canRemove
argument_list|(
name|int
name|index
argument_list|)
decl|const
comment|// ### Qt6 remove body, provided in Qt5 for source compatibility to Qt4.
block|{
name|Q_UNUSED
argument_list|(
name|index
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_EXTENSION_INTERFACE
argument_list|(
argument|QDesignerContainerExtension
argument_list|,
literal|"com.trolltech.Qt.Designer.Container"
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CONTAINER_H
end_comment
end_unit
