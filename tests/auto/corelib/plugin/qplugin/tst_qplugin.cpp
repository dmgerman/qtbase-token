begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QPluginLoader>
end_include
begin_class
DECL|class|tst_QPlugin
class|class
name|tst_QPlugin
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|dir
name|QDir
name|dir
decl_stmt|;
public|public:
name|tst_QPlugin
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|loadDebugPlugin
parameter_list|()
function_decl|;
name|void
name|loadReleasePlugin
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QPlugin
name|tst_QPlugin
operator|::
name|tst_QPlugin
parameter_list|()
member_init_list|:
name|dir
argument_list|(
literal|"plugins"
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|loadDebugPlugin
name|void
name|tst_QPlugin
operator|::
name|loadDebugPlugin
parameter_list|()
block|{
foreach|foreach
control|(
name|QString
name|fileName
decl|,
name|dir
operator|.
name|entryList
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"*debug*"
argument_list|,
name|QDir
operator|::
name|Files
argument_list|)
control|)
block|{
if|if
condition|(
operator|!
name|QLibrary
operator|::
name|isLibrary
argument_list|(
name|fileName
argument_list|)
condition|)
continue|continue;
name|QPluginLoader
name|loader
argument_list|(
name|dir
operator|.
name|filePath
argument_list|(
name|fileName
argument_list|)
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
comment|// we can always load a plugin on unix
name|QVERIFY
argument_list|(
name|loader
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|object
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|!=
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// loading a plugin is dependent on which lib we are running against
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
comment|// release build, we cannot load debug plugins
name|QVERIFY
argument_list|(
operator|!
name|loader
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// debug build, we can load debug plugins
name|QVERIFY
argument_list|(
name|loader
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|object
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|!=
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|loadReleasePlugin
name|void
name|tst_QPlugin
operator|::
name|loadReleasePlugin
parameter_list|()
block|{
foreach|foreach
control|(
name|QString
name|fileName
decl|,
name|dir
operator|.
name|entryList
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"*release*"
argument_list|,
name|QDir
operator|::
name|Files
argument_list|)
control|)
block|{
if|if
condition|(
operator|!
name|QLibrary
operator|::
name|isLibrary
argument_list|(
name|fileName
argument_list|)
condition|)
continue|continue;
name|QPluginLoader
name|loader
argument_list|(
name|dir
operator|.
name|filePath
argument_list|(
name|fileName
argument_list|)
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
comment|// we can always load a plugin on unix
name|QVERIFY
argument_list|(
name|loader
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|object
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|!=
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// loading a plugin is dependent on which lib we are running against
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
comment|// release build, we can load debug plugins
name|QVERIFY
argument_list|(
name|loader
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
name|QObject
modifier|*
name|object
init|=
name|loader
operator|.
name|instance
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|object
operator|!=
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// debug build, we cannot load debug plugins
name|QVERIFY
argument_list|(
operator|!
name|loader
operator|.
name|load
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPlugin
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qplugin.moc"
end_include
end_unit
