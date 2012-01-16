begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"borland_bmake.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|BorlandMakefileGenerator
name|BorlandMakefileGenerator
operator|::
name|BorlandMakefileGenerator
parameter_list|()
member_init_list|:
name|Win32MakefileGenerator
argument_list|()
member_init_list|,
name|init_flag
argument_list|(
literal|false
argument_list|)
block|{  }
end_constructor
begin_function
name|bool
DECL|function|writeMakefile
name|BorlandMakefileGenerator
operator|::
name|writeMakefile
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
name|writeHeader
argument_list|(
name|t
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_FAILED_REQUIREMENTS"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QStringList
modifier|&
name|qut
init|=
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_EXTRA_TARGETS"
argument_list|)
decl_stmt|;
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|qut
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|qut
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
name|t
operator|<<
operator|*
name|it
operator|<<
literal|" "
expr_stmt|;
name|t
operator|<<
literal|"all first clean:"
operator|<<
literal|"\n\t"
operator|<<
literal|"@echo \"Some of the required modules ("
operator|<<
name|var
argument_list|(
literal|"QMAKE_FAILED_REQUIREMENTS"
argument_list|)
operator|<<
literal|") are not available.\""
operator|<<
literal|"\n\t"
operator|<<
literal|"@echo \"Skipped.\""
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
return|return
literal|true
return|;
block|}
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"app"
operator|||
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"lib"
operator|||
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"aux"
condition|)
block|{
name|writeBorlandParts
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
name|MakefileGenerator
operator|::
name|writeMakefile
argument_list|(
name|t
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"subdirs"
condition|)
block|{
name|writeSubDirs
argument_list|(
name|t
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
name|void
DECL|function|writeBorlandParts
name|BorlandMakefileGenerator
operator|::
name|writeBorlandParts
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
name|t
operator|<<
literal|"!if !$d(BCB)"
operator|<<
name|endl
expr_stmt|;
name|t
operator|<<
literal|"BCB = $(MAKEDIR)\\.."
operator|<<
name|endl
expr_stmt|;
name|t
operator|<<
literal|"!endif"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
name|writeStandardParts
argument_list|(
name|t
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
DECL|function|init
name|BorlandMakefileGenerator
operator|::
name|init
parameter_list|()
block|{
if|if
condition|(
name|init_flag
condition|)
return|return;
name|init_flag
operator|=
literal|true
expr_stmt|;
comment|/* this should probably not be here, but I'm using it to wrap the .t files */
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"app"
condition|)
block|{
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_APP_FLAG"
argument_list|)
operator|.
name|append
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"lib"
condition|)
block|{
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LIB_FLAG"
argument_list|)
operator|.
name|append
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"subdirs"
condition|)
block|{
name|MakefileGenerator
operator|::
name|init
argument_list|()
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_COPY_FILE"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_COPY_FILE"
argument_list|)
operator|.
name|append
argument_list|(
literal|"$(COPY)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_COPY_DIR"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_COPY_DIR"
argument_list|)
operator|.
name|append
argument_list|(
literal|"xcopy /s /q /y /i"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_INSTALL_FILE"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_INSTALL_FILE"
argument_list|)
operator|.
name|append
argument_list|(
literal|"$(COPY_FILE)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_INSTALL_PROGRAM"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_INSTALL_PROGRAM"
argument_list|)
operator|.
name|append
argument_list|(
literal|"$(COPY_FILE)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_INSTALL_DIR"
argument_list|)
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_INSTALL_DIR"
argument_list|)
operator|.
name|append
argument_list|(
literal|"$(COPY_DIR)"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|values
argument_list|(
literal|"MAKEFILE"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
name|project
operator|->
name|values
argument_list|(
literal|"MAKEFILE"
argument_list|)
operator|.
name|append
argument_list|(
literal|"Makefile"
argument_list|)
expr_stmt|;
return|return;
block|}
name|processVars
argument_list|()
expr_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_LIBS"
argument_list|)
operator|+=
name|project
operator|->
name|values
argument_list|(
literal|"LIBS"
argument_list|)
expr_stmt|;
name|MakefileGenerator
operator|::
name|init
argument_list|()
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"dll"
argument_list|)
operator|||
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_APP_FLAG"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// bcc does not generate a .tds file for static libs
name|QString
name|tdsPostfix
decl_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|values
argument_list|(
literal|"VERSION"
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
name|tdsPostfix
operator|=
name|project
operator|->
name|first
argument_list|(
literal|"TARGET_VERSION_EXT"
argument_list|)
expr_stmt|;
name|tdsPostfix
operator|+=
literal|".tds"
expr_stmt|;
name|project
operator|->
name|values
argument_list|(
literal|"QMAKE_CLEAN"
argument_list|)
operator|.
name|append
argument_list|(
name|project
operator|->
name|first
argument_list|(
literal|"DESTDIR"
argument_list|)
operator|+
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|+
name|tdsPostfix
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|writeBuildRulesPart
name|void
name|BorlandMakefileGenerator
operator|::
name|writeBuildRulesPart
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
if|if
condition|(
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"aux"
condition|)
block|{
name|t
operator|<<
literal|"first:"
operator|<<
name|endl
expr_stmt|;
return|return;
block|}
name|t
operator|<<
literal|"first: all"
operator|<<
name|endl
expr_stmt|;
name|t
operator|<<
literal|"all: "
operator|<<
name|fileFixify
argument_list|(
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
argument_list|)
operator|<<
literal|" "
operator|<<
name|varGlue
argument_list|(
literal|"ALL_DEPS"
argument_list|,
literal|" "
argument_list|,
literal|" "
argument_list|,
literal|" "
argument_list|)
operator|<<
literal|" $(DESTDIR_TARGET)"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
name|t
operator|<<
literal|"$(DESTDIR_TARGET): "
operator|<<
name|var
argument_list|(
literal|"PRE_TARGETDEPS"
argument_list|)
operator|<<
literal|" $(OBJECTS) "
operator|<<
name|var
argument_list|(
literal|"POST_TARGETDEPS"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_PRE_LINK"
argument_list|)
condition|)
name|t
operator|<<
literal|"\n\t"
operator|<<
name|var
argument_list|(
literal|"QMAKE_PRE_LINK"
argument_list|)
expr_stmt|;
if|if
condition|(
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"staticlib"
argument_list|)
condition|)
block|{
name|t
operator|<<
literal|"\n\t-$(DEL_FILE) $(DESTDIR_TARGET)"
operator|<<
literal|"\n\t"
operator|<<
literal|"$(LIB) $(DESTDIR_TARGET) @&&|"
operator|<<
literal|" \n+"
operator|<<
name|project
operator|->
name|values
argument_list|(
literal|"OBJECTS"
argument_list|)
operator|.
name|join
argument_list|(
literal|" \\\n+"
argument_list|)
operator|<<
literal|" \\\n+"
operator|<<
name|project
operator|->
name|values
argument_list|(
literal|"OBJMOC"
argument_list|)
operator|.
name|join
argument_list|(
literal|" \\\n+"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|t
operator|<<
literal|"\n\t"
operator|<<
literal|"$(LINK) @&&|"
operator|<<
literal|"\n\t"
operator|<<
literal|"$(LFLAGS) $(OBJECTS) $(OBJMOC),$(DESTDIR_TARGET),,$(LIBS),$(DEF_FILE),$(RES_FILE)"
expr_stmt|;
block|}
name|t
operator|<<
name|endl
operator|<<
literal|"|"
expr_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_POST_LINK"
argument_list|)
condition|)
name|t
operator|<<
literal|"\n\t"
operator|<<
name|var
argument_list|(
literal|"QMAKE_POST_LINK"
argument_list|)
expr_stmt|;
name|t
operator|<<
name|endl
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeCleanParts
name|void
name|BorlandMakefileGenerator
operator|::
name|writeCleanParts
parameter_list|(
name|QTextStream
modifier|&
name|t
parameter_list|)
block|{
name|t
operator|<<
literal|"clean: "
operator|<<
name|varGlue
argument_list|(
literal|"OBJECTS"
argument_list|,
literal|"\n\t-$(DEL_FILE) "
argument_list|,
literal|"\n\t-$(DEL_FILE) "
argument_list|,
literal|""
argument_list|)
operator|<<
name|varGlue
argument_list|(
literal|"QMAKE_CLEAN"
argument_list|,
literal|"\n\t-$(DEL_FILE) "
argument_list|,
literal|"\n\t-$(DEL_FILE) "
argument_list|,
literal|"\n"
argument_list|)
operator|<<
name|varGlue
argument_list|(
literal|"CLEAN_FILES"
argument_list|,
literal|"\n\t-$(DEL_FILE) "
argument_list|,
literal|"\n\t-$(DEL_FILE) "
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
literal|"IMAGES"
argument_list|)
condition|)
name|t
operator|<<
name|varGlue
argument_list|(
literal|"QMAKE_IMAGE_COLLECTION"
argument_list|,
literal|"\n\t-$(DEL_FILE) "
argument_list|,
literal|"\n\t-$(DEL_FILE) "
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|t
operator|<<
name|endl
expr_stmt|;
name|t
operator|<<
literal|"distclean: clean"
operator|<<
literal|"\n\t-$(DEL_FILE) $(DESTDIR_TARGET)"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
