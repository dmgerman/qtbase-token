begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   cppcodemarker.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CPPCODEMARKER_H
end_ifndef
begin_define
DECL|macro|CPPCODEMARKER_H
define|#
directive|define
name|CPPCODEMARKER_H
end_define
begin_include
include|#
directive|include
file|"codemarker.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|CppCodeMarker
range|:
name|public
name|CodeMarker
block|{
name|Q_DECLARE_TR_FUNCTIONS
argument_list|(
argument|QDoc::CppCodeMarker
argument_list|)
name|public
operator|:
name|CppCodeMarker
argument_list|()
block|;
operator|~
name|CppCodeMarker
argument_list|()
block|;
name|virtual
name|bool
name|recognizeCode
argument_list|(
argument|const QString& code
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|recognizeExtension
argument_list|(
argument|const QString& ext
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|recognizeLanguage
argument_list|(
argument|const QString& lang
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|Atom
operator|::
name|AtomType
name|atomType
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|markedUpCode
argument_list|(
argument|const QString& code
argument_list|,
argument|const Node *relative
argument_list|,
argument|const Location&location
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|markedUpSynopsis
argument_list|(
argument|const Node *node
argument_list|,
argument|const Node *relative
argument_list|,
argument|SynopsisStyle style
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|markedUpQmlItem
argument_list|(
argument|const Node *node
argument_list|,
argument|bool summary
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|markedUpName
argument_list|(
argument|const Node *node
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|markedUpFullName
argument_list|(
argument|const Node *node
argument_list|,
argument|const Node *relative
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|markedUpEnumValue
argument_list|(
argument|const QString&enumValue
argument_list|,
argument|const Node *relative
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|markedUpIncludes
argument_list|(
argument|const QStringList& includes
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|functionBeginRegExp
argument_list|(
argument|const QString& funcName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|functionEndRegExp
argument_list|(
argument|const QString& funcName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QList
operator|<
name|Section
operator|>
name|sections
argument_list|(
argument|const InnerNode *innerNode
argument_list|,
argument|SynopsisStyle style
argument_list|,
argument|Status status
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QList
operator|<
name|Section
operator|>
name|qmlSections
argument_list|(
argument|QmlTypeNode* qmlTypeNode
argument_list|,
argument|SynopsisStyle style
argument_list|,
argument|Status status = Okay
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QString
name|addMarkUp
argument_list|(
specifier|const
name|QString
operator|&
name|protectedCode
argument_list|,
specifier|const
name|Node
operator|*
name|relative
argument_list|,
specifier|const
name|Location
operator|&
name|location
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
