begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVALIDATOR_H
end_ifndef
begin_define
DECL|macro|QVALIDATOR_H
define|#
directive|define
name|QVALIDATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qregexp.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_VALIDATOR
name|class
name|QValidatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QValidator
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QValidator
argument_list|()
block|;      enum
name|State
block|{
name|Invalid
block|,
name|Intermediate
block|,
name|Acceptable
if|#
directive|if
name|defined
argument_list|(
name|QT3_SUPPORT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_MOC_RUN
argument_list|)
block|,
name|Valid
operator|=
name|Intermediate
endif|#
directive|endif
block|}
block|;
name|void
name|setLocale
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
block|;
name|QLocale
name|locale
argument_list|()
specifier|const
block|;
name|virtual
name|State
name|validate
argument_list|(
argument|QString&
argument_list|,
argument|int&
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|fixup
argument_list|(
argument|QString&
argument_list|)
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
name|QT3_SUPPORT_CONSTRUCTOR
name|QValidator
argument_list|(
name|QObject
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
endif|#
directive|endif
name|protected
operator|:
name|QValidator
argument_list|(
name|QObjectPrivate
operator|&
name|d
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|QValidator
argument_list|(
name|QValidatorPrivate
operator|&
name|d
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QValidator
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QValidator
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QIntValidator
range|:
name|public
name|QValidator
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int bottom READ bottom WRITE setBottom
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int top READ top WRITE setTop
argument_list|)
name|public
operator|:
name|explicit
name|QIntValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QIntValidator
argument_list|(
argument|int bottom
argument_list|,
argument|int top
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|QIntValidator
argument_list|()
block|;
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&
argument_list|,
argument|int&
argument_list|)
specifier|const
block|;
name|void
name|fixup
argument_list|(
argument|QString&input
argument_list|)
specifier|const
block|;
name|void
name|setBottom
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setTop
argument_list|(
name|int
argument_list|)
block|;
name|virtual
name|void
name|setRange
argument_list|(
argument|int bottom
argument_list|,
argument|int top
argument_list|)
block|;
name|int
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|b
return|;
block|}
name|int
name|top
argument_list|()
specifier|const
block|{
return|return
name|t
return|;
block|}
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
name|QT3_SUPPORT_CONSTRUCTOR
name|QIntValidator
argument_list|(
name|QObject
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QIntValidator
argument_list|(
argument|int bottom
argument_list|,
argument|int top
argument_list|,
argument|QObject * parent
argument_list|,
argument|const char *name
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QIntValidator
argument_list|)
name|int
name|b
block|;
name|int
name|t
block|; }
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_decl_stmt
DECL|variable|QDoubleValidatorPrivate
name|class
name|QDoubleValidatorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDoubleValidator
range|:
name|public
name|QValidator
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|double bottom READ bottom WRITE setBottom
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|double top READ top WRITE setTop
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int decimals READ decimals WRITE setDecimals
argument_list|)
name|Q_ENUMS
argument_list|(
argument|Notation
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Notation notation READ notation WRITE setNotation
argument_list|)
name|public
operator|:
name|explicit
name|QDoubleValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QDoubleValidator
argument_list|(
argument|double bottom
argument_list|,
argument|double top
argument_list|,
argument|int decimals
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|QDoubleValidator
argument_list|()
block|;      enum
name|Notation
block|{
name|StandardNotation
block|,
name|ScientificNotation
block|}
block|;
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&
argument_list|,
argument|int&
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setRange
argument_list|(
argument|double bottom
argument_list|,
argument|double top
argument_list|,
argument|int decimals =
literal|0
argument_list|)
block|;
name|void
name|setBottom
argument_list|(
name|double
argument_list|)
block|;
name|void
name|setTop
argument_list|(
name|double
argument_list|)
block|;
name|void
name|setDecimals
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setNotation
argument_list|(
name|Notation
argument_list|)
block|;
name|double
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|b
return|;
block|}
name|double
name|top
argument_list|()
specifier|const
block|{
return|return
name|t
return|;
block|}
name|int
name|decimals
argument_list|()
specifier|const
block|{
return|return
name|dec
return|;
block|}
name|Notation
name|notation
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
name|QT3_SUPPORT_CONSTRUCTOR
name|QDoubleValidator
argument_list|(
name|QObject
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QDoubleValidator
argument_list|(
argument|double bottom
argument_list|,
argument|double top
argument_list|,
argument|int decimals
argument_list|,
argument|QObject * parent
argument_list|,
argument|const char *name
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDoubleValidator
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QDoubleValidator
argument_list|)
name|double
name|b
block|;
name|double
name|t
block|;
name|int
name|dec
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QRegExpValidator
range|:
name|public
name|QValidator
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QRegExp regExp READ regExp WRITE setRegExp
argument_list|)
name|public
operator|:
name|explicit
name|QRegExpValidator
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QRegExpValidator
argument_list|(
specifier|const
name|QRegExp
operator|&
name|rx
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QRegExpValidator
argument_list|()
block|;
name|virtual
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString& input
argument_list|,
argument|int& pos
argument_list|)
specifier|const
block|;
name|void
name|setRegExp
argument_list|(
specifier|const
name|QRegExp
operator|&
name|rx
argument_list|)
block|;
specifier|const
name|QRegExp
operator|&
name|regExp
argument_list|()
specifier|const
block|{
return|return
name|r
return|;
block|}
comment|// ### make inline for 5.0
ifdef|#
directive|ifdef
name|QT3_SUPPORT
name|public
operator|:
name|QT3_SUPPORT_CONSTRUCTOR
name|QRegExpValidator
argument_list|(
name|QObject
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|QT3_SUPPORT_CONSTRUCTOR
name|QRegExpValidator
argument_list|(
specifier|const
name|QRegExp
operator|&
name|rx
argument_list|,
name|QObject
operator|*
name|parent
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QRegExpValidator
argument_list|)
name|QRegExp
name|r
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_REGEXP
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_VALIDATOR
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QVALIDATOR_H
end_comment
end_unit
