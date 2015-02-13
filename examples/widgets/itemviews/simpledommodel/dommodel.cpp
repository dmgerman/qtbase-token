begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"domitem.h"
end_include
begin_include
include|#
directive|include
file|"dommodel.h"
end_include
begin_include
include|#
directive|include
file|<QtXml>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|DomModel
name|DomModel
operator|::
name|DomModel
parameter_list|(
name|QDomDocument
name|document
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractItemModel
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|domDocument
argument_list|(
name|document
argument_list|)
block|{
name|rootItem
operator|=
operator|new
name|DomItem
argument_list|(
name|domDocument
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_destructor
DECL|function|~DomModel
name|DomModel
operator|::
name|~
name|DomModel
parameter_list|()
block|{
operator|delete
name|rootItem
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|columnCount
name|int
name|DomModel
operator|::
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
comment|/*parent*/
parameter_list|)
specifier|const
block|{
return|return
literal|3
return|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|data
name|QVariant
name|DomModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|role
operator|!=
name|Qt
operator|::
name|DisplayRole
condition|)
return|return
name|QVariant
argument_list|()
return|;
name|DomItem
modifier|*
name|item
init|=
cast|static_cast
argument_list|<
name|DomItem
operator|*
argument_list|>
argument_list|(
name|index
operator|.
name|internalPointer
argument_list|()
argument_list|)
decl_stmt|;
name|QDomNode
name|node
init|=
name|item
operator|->
name|node
argument_list|()
decl_stmt|;
comment|//! [3] //! [4]
name|QStringList
name|attributes
decl_stmt|;
name|QDomNamedNodeMap
name|attributeMap
init|=
name|node
operator|.
name|attributes
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|index
operator|.
name|column
argument_list|()
condition|)
block|{
case|case
literal|0
case|:
return|return
name|node
operator|.
name|nodeName
argument_list|()
return|;
case|case
literal|1
case|:
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|attributeMap
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QDomNode
name|attribute
init|=
name|attributeMap
operator|.
name|item
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|attributes
operator|<<
name|attribute
operator|.
name|nodeName
argument_list|()
operator|+
literal|"=\""
operator|+
name|attribute
operator|.
name|nodeValue
argument_list|()
operator|+
literal|"\""
expr_stmt|;
block|}
return|return
name|attributes
operator|.
name|join
argument_list|(
literal|' '
argument_list|)
return|;
case|case
literal|2
case|:
return|return
name|node
operator|.
name|nodeValue
argument_list|()
operator|.
name|split
argument_list|(
literal|"\n"
argument_list|)
operator|.
name|join
argument_list|(
literal|' '
argument_list|)
return|;
default|default:
return|return
name|QVariant
argument_list|()
return|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|flags
name|Qt
operator|::
name|ItemFlags
name|DomModel
operator|::
name|flags
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|QAbstractItemModel
operator|::
name|flags
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|headerData
name|QVariant
name|DomModel
operator|::
name|headerData
parameter_list|(
name|int
name|section
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
operator|&&
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
block|{
switch|switch
condition|(
name|section
condition|)
block|{
case|case
literal|0
case|:
return|return
name|tr
argument_list|(
literal|"Name"
argument_list|)
return|;
case|case
literal|1
case|:
return|return
name|tr
argument_list|(
literal|"Attributes"
argument_list|)
return|;
case|case
literal|2
case|:
return|return
name|tr
argument_list|(
literal|"Value"
argument_list|)
return|;
default|default:
return|return
name|QVariant
argument_list|()
return|;
block|}
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|index
name|QModelIndex
name|DomModel
operator|::
name|index
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|hasIndex
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|parent
argument_list|)
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
name|DomItem
modifier|*
name|parentItem
decl_stmt|;
if|if
condition|(
operator|!
name|parent
operator|.
name|isValid
argument_list|()
condition|)
name|parentItem
operator|=
name|rootItem
expr_stmt|;
else|else
name|parentItem
operator|=
cast|static_cast
argument_list|<
name|DomItem
operator|*
argument_list|>
argument_list|(
name|parent
operator|.
name|internalPointer
argument_list|()
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|DomItem
modifier|*
name|childItem
init|=
name|parentItem
operator|->
name|child
argument_list|(
name|row
argument_list|)
decl_stmt|;
if|if
condition|(
name|childItem
condition|)
return|return
name|createIndex
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|childItem
argument_list|)
return|;
else|else
return|return
name|QModelIndex
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|parent
name|QModelIndex
name|DomModel
operator|::
name|parent
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|child
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|child
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
name|DomItem
modifier|*
name|childItem
init|=
cast|static_cast
argument_list|<
name|DomItem
operator|*
argument_list|>
argument_list|(
name|child
operator|.
name|internalPointer
argument_list|()
argument_list|)
decl_stmt|;
name|DomItem
modifier|*
name|parentItem
init|=
name|childItem
operator|->
name|parent
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|parentItem
operator|||
name|parentItem
operator|==
name|rootItem
condition|)
return|return
name|QModelIndex
argument_list|()
return|;
return|return
name|createIndex
argument_list|(
name|parentItem
operator|->
name|row
argument_list|()
argument_list|,
literal|0
argument_list|,
name|parentItem
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_function
DECL|function|rowCount
name|int
name|DomModel
operator|::
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|parent
operator|.
name|column
argument_list|()
operator|>
literal|0
condition|)
return|return
literal|0
return|;
name|DomItem
modifier|*
name|parentItem
decl_stmt|;
if|if
condition|(
operator|!
name|parent
operator|.
name|isValid
argument_list|()
condition|)
name|parentItem
operator|=
name|rootItem
expr_stmt|;
else|else
name|parentItem
operator|=
cast|static_cast
argument_list|<
name|DomItem
operator|*
argument_list|>
argument_list|(
name|parent
operator|.
name|internalPointer
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|parentItem
operator|->
name|node
argument_list|()
operator|.
name|childNodes
argument_list|()
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
end_unit
