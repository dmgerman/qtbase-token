begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the Qt Designer of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"textbuilder_p.h"
end_include
begin_include
include|#
directive|include
file|"ui4_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|QFORMINTERNAL_NAMESPACE
end_ifdef
begin_namespace
DECL|namespace|QFormInternal
namespace|namespace
name|QFormInternal
block|{
endif|#
directive|endif
DECL|function|QTextBuilder
name|QTextBuilder
operator|::
name|QTextBuilder
parameter_list|()
block|{  }
DECL|function|~QTextBuilder
name|QTextBuilder
operator|::
name|~
name|QTextBuilder
parameter_list|()
block|{  }
DECL|function|loadText
name|QVariant
name|QTextBuilder
operator|::
name|loadText
parameter_list|(
specifier|const
name|DomProperty
modifier|*
name|property
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|property
operator|->
name|kind
argument_list|()
operator|==
name|DomProperty
operator|::
name|String
condition|)
return|return
name|property
operator|->
name|elementString
argument_list|()
operator|->
name|text
argument_list|()
return|;
return|return
name|QVariant
argument_list|()
return|;
block|}
DECL|function|toNativeValue
name|QVariant
name|QTextBuilder
operator|::
name|toNativeValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
specifier|const
block|{
return|return
name|value
return|;
block|}
DECL|function|saveText
name|DomProperty
modifier|*
name|QTextBuilder
operator|::
name|saveText
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
argument|value
argument_list|)
return|return
literal|0
return|;
block|}
ifdef|#
directive|ifdef
name|QFORMINTERNAL_NAMESPACE
block|}
end_namespace
begin_comment
comment|// namespace QFormInternal
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
