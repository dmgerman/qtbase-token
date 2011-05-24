begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|XMLDATA_H
end_ifndef
begin_define
DECL|macro|XMLDATA_H
define|#
directive|define
name|XMLDATA_H
end_define
begin_include
include|#
directive|include
file|<QtXml>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_enum
DECL|enum|GeneratorFlag
enum|enum
name|GeneratorFlag
block|{
DECL|enumerator|Normal
name|Normal
init|=
literal|0x1
operator|<<
literal|0
block|,
DECL|enumerator|Default
name|Default
init|=
literal|0x1
operator|<<
literal|1
block|,
DECL|enumerator|Foreign
name|Foreign
init|=
literal|0x1
operator|<<
literal|2
block|,
DECL|enumerator|Reference
name|Reference
init|=
literal|0x1
operator|<<
literal|3
block|}
enum|;
end_enum
begin_expr_stmt
name|Q_DECLARE_FLAGS
argument_list|(
name|GeneratorFlags
argument_list|,
name|GeneratorFlag
argument_list|)
expr_stmt|;
end_expr_stmt
begin_struct
DECL|struct|XMLData
struct|struct
name|XMLData
block|{
DECL|function|XMLData
name|XMLData
argument_list|()
operator|:
name|date
argument_list|(
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
argument_list|)
operator|,
name|timeToRender
argument_list|(
literal|0
argument_list|)
operator|,
name|iterations
argument_list|(
literal|0
argument_list|)
operator|,
name|maxElapsed
argument_list|(
literal|0
argument_list|)
operator|,
name|minElapsed
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|XMLData
name|XMLData
argument_list|(
argument|const QDateTime&dt
argument_list|,
argument|int ttr
argument_list|,
argument|int itrs =
literal|1
argument_list|)
operator|:
name|date
argument_list|(
name|dt
argument_list|)
operator|,
name|timeToRender
argument_list|(
name|ttr
argument_list|)
operator|,
name|iterations
argument_list|(
name|itrs
argument_list|)
operator|,
name|maxElapsed
argument_list|(
literal|0
argument_list|)
operator|,
name|minElapsed
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|XMLData
name|XMLData
argument_list|(
argument|const QString&dt
argument_list|,
argument|int ttr
argument_list|,
argument|int itrs =
literal|1
argument_list|)
operator|:
name|timeToRender
argument_list|(
name|ttr
argument_list|)
operator|,
name|iterations
argument_list|(
name|itrs
argument_list|)
operator|,
name|maxElapsed
argument_list|(
literal|0
argument_list|)
operator|,
name|minElapsed
argument_list|(
literal|0
argument_list|)
block|{
name|date
operator|=
name|QDateTime
operator|::
name|fromString
argument_list|(
name|dt
argument_list|)
block|;     }
DECL|member|date
name|QDateTime
name|date
expr_stmt|;
DECL|member|timeToRender
name|int
name|timeToRender
decl_stmt|;
DECL|member|iterations
name|int
name|iterations
decl_stmt|;
DECL|member|details
name|QString
name|details
decl_stmt|;
DECL|member|maxElapsed
name|int
name|maxElapsed
decl_stmt|;
DECL|member|minElapsed
name|int
name|minElapsed
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|XMLFile
struct|struct
name|XMLFile
block|{
DECL|function|XMLFile
name|XMLFile
argument_list|()
block|{}
DECL|function|XMLFile
name|XMLFile
argument_list|(
specifier|const
name|QString
operator|&
name|testcase
argument_list|)
operator|:
name|name
argument_list|(
argument|testcase
argument_list|)
block|{}
DECL|function|XMLFile
name|XMLFile
argument_list|(
specifier|const
name|QString
operator|&
name|testcase
argument_list|,
specifier|const
name|QString
operator|&
name|img
argument_list|)
operator|:
name|name
argument_list|(
name|testcase
argument_list|)
operator|,
name|output
argument_list|(
argument|img
argument_list|)
block|{}
DECL|member|name
name|QString
name|name
expr_stmt|;
DECL|member|output
name|QString
name|output
decl_stmt|;
DECL|member|data
name|QList
operator|<
name|XMLData
operator|>
name|data
expr_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|XMLSuite
struct|struct
name|XMLSuite
block|{
DECL|function|XMLSuite
name|XMLSuite
argument_list|()
block|{}
DECL|function|XMLSuite
name|XMLSuite
argument_list|(
specifier|const
name|QString
operator|&
name|n
argument_list|)
operator|:
name|name
argument_list|(
argument|n
argument_list|)
block|{}
DECL|member|name
name|QString
name|name
expr_stmt|;
DECL|member|QString
DECL|member|files
name|QMap
operator|<
name|QString
operator|,
name|XMLFile
operator|*
operator|>
name|files
expr_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|XMLEngine
struct|struct
name|XMLEngine
block|{
DECL|function|XMLEngine
name|XMLEngine
argument_list|()
operator|:
name|defaultEngine
argument_list|(
name|false
argument_list|)
operator|,
name|foreignEngine
argument_list|(
name|false
argument_list|)
operator|,
name|referenceEngine
argument_list|(
argument|false
argument_list|)
block|{}
DECL|function|XMLEngine
name|XMLEngine
argument_list|(
argument|const QString&engine
argument_list|,
argument|bool def
argument_list|)
operator|:
name|name
argument_list|(
name|engine
argument_list|)
operator|,
name|defaultEngine
argument_list|(
name|def
argument_list|)
operator|,
name|foreignEngine
argument_list|(
name|false
argument_list|)
operator|,
name|referenceEngine
argument_list|(
argument|false
argument_list|)
block|{}
DECL|member|name
name|QString
name|name
expr_stmt|;
DECL|member|defaultEngine
name|bool
name|defaultEngine
decl_stmt|;
DECL|member|foreignEngine
name|bool
name|foreignEngine
decl_stmt|;
DECL|member|referenceEngine
name|bool
name|referenceEngine
decl_stmt|;
DECL|member|QString
DECL|member|suites
name|QMap
operator|<
name|QString
operator|,
name|XMLSuite
operator|*
operator|>
name|suites
expr_stmt|;
DECL|member|generationDate
name|QDateTime
name|generationDate
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|XMLReader
range|:
name|public
name|QXmlDefaultHandler
block|{
name|public
operator|:
name|XMLEngine
operator|*
name|xmlEngine
argument_list|()
specifier|const
block|{
return|return
name|engine
return|;
block|}
name|bool
name|startElement
argument_list|(
specifier|const
name|QString
operator|&
name|namespaceURI
argument_list|,
specifier|const
name|QString
operator|&
name|localName
argument_list|,
specifier|const
name|QString
operator|&
name|qName
argument_list|,
specifier|const
name|QXmlAttributes
operator|&
name|attributes
argument_list|)
block|;
name|bool
name|endElement
argument_list|(
specifier|const
name|QString
operator|&
name|namespaceURI
argument_list|,
specifier|const
name|QString
operator|&
name|localName
argument_list|,
specifier|const
name|QString
operator|&
name|qName
argument_list|)
block|;
name|bool
name|fatalError
argument_list|(
specifier|const
name|QXmlParseException
operator|&
name|exception
argument_list|)
block|;
name|private
operator|:
name|XMLEngine
operator|*
name|engine
block|;
name|XMLSuite
operator|*
name|suite
block|;
name|XMLFile
operator|*
name|file
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
