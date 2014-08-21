begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QPixmapCache>
end_include
begin_class
DECL|class|tst_QPixmapCache
class|class
name|tst_QPixmapCache
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QPixmapCache
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QPixmapCache
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|insert_data
parameter_list|()
function_decl|;
name|void
name|insert
parameter_list|()
function_decl|;
name|void
name|find_data
parameter_list|()
function_decl|;
name|void
name|find
parameter_list|()
function_decl|;
name|void
name|styleUseCaseComplexKey
parameter_list|()
function_decl|;
name|void
name|styleUseCaseComplexKey_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QPixmapCache
name|tst_QPixmapCache
operator|::
name|tst_QPixmapCache
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QPixmapCache
name|tst_QPixmapCache
operator|::
name|~
name|tst_QPixmapCache
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QPixmapCache
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QPixmapCache
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|insert_data
name|void
name|tst_QPixmapCache
operator|::
name|insert_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"cacheType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QPixmapCache"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QPixmapCache (int API)"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|keys
name|QList
argument_list|<
name|QPixmapCache
operator|::
name|Key
argument_list|>
name|keys
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|insert
name|void
name|tst_QPixmapCache
operator|::
name|insert
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|cacheType
argument_list|)
expr_stmt|;
name|QPixmap
name|p
decl_stmt|;
if|if
condition|(
name|cacheType
condition|)
block|{
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10000
condition|;
name|i
operator|++
control|)
block|{
name|QString
name|tmp
decl_stmt|;
name|tmp
operator|.
name|sprintf
argument_list|(
literal|"my-key-%d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|tmp
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10000
condition|;
name|i
operator|++
control|)
name|keys
operator|.
name|append
argument_list|(
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|find_data
name|void
name|tst_QPixmapCache
operator|::
name|find_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"cacheType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QPixmapCache"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QPixmapCache (int API)"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|find
name|void
name|tst_QPixmapCache
operator|::
name|find
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|cacheType
argument_list|)
expr_stmt|;
name|QPixmap
name|p
decl_stmt|;
if|if
condition|(
name|cacheType
condition|)
block|{
name|QBENCHMARK
block|{
name|QString
name|tmp
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10000
condition|;
name|i
operator|++
control|)
block|{
name|tmp
operator|.
name|sprintf
argument_list|(
literal|"my-key-%d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|find
argument_list|(
name|tmp
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10000
condition|;
name|i
operator|++
control|)
name|QPixmapCache
operator|::
name|find
argument_list|(
name|keys
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
operator|&
name|p
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|styleUseCaseComplexKey_data
name|void
name|tst_QPixmapCache
operator|::
name|styleUseCaseComplexKey_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"cacheType"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QPixmapCache"
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"QPixmapCache (int API)"
argument_list|)
operator|<<
literal|false
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|styleStruct
struct|struct
name|styleStruct
block|{
DECL|member|key
name|QString
name|key
decl_stmt|;
DECL|member|state
name|uint
name|state
decl_stmt|;
DECL|member|direction
name|uint
name|direction
decl_stmt|;
DECL|member|complex
name|uint
name|complex
decl_stmt|;
DECL|member|palette
name|uint
name|palette
decl_stmt|;
DECL|member|width
name|int
name|width
decl_stmt|;
DECL|member|height
name|int
name|height
decl_stmt|;
DECL|function|operator ==
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|styleStruct
modifier|&
name|str
parameter_list|)
specifier|const
block|{
return|return
name|str
operator|.
name|state
operator|==
name|state
operator|&&
name|str
operator|.
name|direction
operator|==
name|direction
operator|&&
name|str
operator|.
name|complex
operator|==
name|complex
operator|&&
name|str
operator|.
name|palette
operator|==
name|palette
operator|&&
name|str
operator|.
name|width
operator|==
name|width
operator|&&
name|str
operator|.
name|height
operator|==
name|height
operator|&&
name|str
operator|.
name|key
operator|==
name|key
return|;
block|}
block|}
struct|;
end_struct
begin_function
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
specifier|const
name|styleStruct
modifier|&
name|myStruct
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|myStruct
operator|.
name|state
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|styleUseCaseComplexKey
name|void
name|tst_QPixmapCache
operator|::
name|styleUseCaseComplexKey
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|cacheType
argument_list|)
expr_stmt|;
name|QPixmap
name|p
decl_stmt|;
if|if
condition|(
name|cacheType
condition|)
block|{
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10000
condition|;
name|i
operator|++
control|)
block|{
name|QString
name|tmp
decl_stmt|;
name|tmp
operator|.
name|sprintf
argument_list|(
literal|"%s-%d-%d-%d-%d-%d-%d"
argument_list|,
name|QString
argument_list|(
literal|"my-progressbar-%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
literal|5
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|358
argument_list|,
literal|100
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|tmp
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10000
condition|;
name|i
operator|++
control|)
block|{
name|QString
name|tmp
decl_stmt|;
name|tmp
operator|.
name|sprintf
argument_list|(
literal|"%s-%d-%d-%d-%d-%d-%d"
argument_list|,
name|QString
argument_list|(
literal|"my-progressbar-%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
literal|5
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|358
argument_list|,
literal|100
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|QPixmapCache
operator|::
name|find
argument_list|(
name|tmp
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|QHash
argument_list|<
name|styleStruct
argument_list|,
name|QPixmapCache
operator|::
name|Key
argument_list|>
name|hash
decl_stmt|;
name|QBENCHMARK
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10000
condition|;
name|i
operator|++
control|)
block|{
name|styleStruct
name|myStruct
decl_stmt|;
name|myStruct
operator|.
name|key
operator|=
name|QString
argument_list|(
literal|"my-progressbar-%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|myStruct
operator|.
name|key
operator|=
literal|5
expr_stmt|;
name|myStruct
operator|.
name|key
operator|=
literal|4
expr_stmt|;
name|myStruct
operator|.
name|key
operator|=
literal|3
expr_stmt|;
name|myStruct
operator|.
name|palette
operator|=
literal|358
expr_stmt|;
name|myStruct
operator|.
name|width
operator|=
literal|100
expr_stmt|;
name|myStruct
operator|.
name|key
operator|=
literal|200
expr_stmt|;
name|QPixmapCache
operator|::
name|Key
name|key
init|=
name|QPixmapCache
operator|::
name|insert
argument_list|(
name|p
argument_list|)
decl_stmt|;
name|hash
operator|.
name|insert
argument_list|(
name|myStruct
argument_list|,
name|key
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|10000
condition|;
name|i
operator|++
control|)
block|{
name|styleStruct
name|myStruct
decl_stmt|;
name|myStruct
operator|.
name|key
operator|=
name|QString
argument_list|(
literal|"my-progressbar-%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|myStruct
operator|.
name|key
operator|=
literal|5
expr_stmt|;
name|myStruct
operator|.
name|key
operator|=
literal|4
expr_stmt|;
name|myStruct
operator|.
name|key
operator|=
literal|3
expr_stmt|;
name|myStruct
operator|.
name|palette
operator|=
literal|358
expr_stmt|;
name|myStruct
operator|.
name|width
operator|=
literal|100
expr_stmt|;
name|myStruct
operator|.
name|key
operator|=
literal|200
expr_stmt|;
name|QPixmapCache
operator|::
name|Key
name|key
init|=
name|hash
operator|.
name|value
argument_list|(
name|myStruct
argument_list|)
decl_stmt|;
name|QPixmapCache
operator|::
name|find
argument_list|(
name|key
argument_list|,
operator|&
name|p
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPixmapCache
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpixmapcache.moc"
end_include
end_unit
