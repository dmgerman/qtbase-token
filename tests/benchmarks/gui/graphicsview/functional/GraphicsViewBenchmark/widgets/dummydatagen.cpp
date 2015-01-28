begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_include
include|#
directive|include
file|"dummydatagen.h"
end_include
begin_constructor
DECL|function|DummyDataGenerator
name|DummyDataGenerator
operator|::
name|DummyDataGenerator
parameter_list|()
member_init_list|:
name|m_isMale
argument_list|(
literal|false
argument_list|)
block|{
name|QFile
name|countryCodeFile
argument_list|(
literal|":/contact/areacodes.txt"
argument_list|)
decl_stmt|;
name|countryCodeFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|countryCodeFile
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|m_countryCodes
operator|<<
name|QString
argument_list|(
name|countryCodeFile
operator|.
name|readLine
argument_list|()
argument_list|)
operator|.
name|remove
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|QFile
name|firstNameFFile
argument_list|(
literal|":/contact/firstnamesF.txt"
argument_list|)
decl_stmt|;
name|firstNameFFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|firstNameFFile
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|m_firstNamesF
operator|<<
name|QString
argument_list|(
name|firstNameFFile
operator|.
name|readLine
argument_list|()
argument_list|)
operator|.
name|remove
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|QFile
name|firstNameMFile
argument_list|(
literal|":/contact/firstnamesM.txt"
argument_list|)
decl_stmt|;
name|firstNameMFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|firstNameMFile
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|m_firstNamesM
operator|<<
name|QString
argument_list|(
name|firstNameMFile
operator|.
name|readLine
argument_list|()
argument_list|)
operator|.
name|remove
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|QFile
name|lastNameFile
argument_list|(
literal|":/contact/lastnames.txt"
argument_list|)
decl_stmt|;
name|lastNameFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|lastNameFile
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|m_lastNames
operator|<<
name|QString
argument_list|(
name|lastNameFile
operator|.
name|readLine
argument_list|()
argument_list|)
operator|.
name|remove
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|Reset
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~DummyDataGenerator
name|DummyDataGenerator
operator|::
name|~
name|DummyDataGenerator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|Reset
name|void
name|DummyDataGenerator
operator|::
name|Reset
parameter_list|()
block|{
name|qsrand
argument_list|(
literal|100
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|randomPhoneNumber
name|QString
name|DummyDataGenerator
operator|::
name|randomPhoneNumber
parameter_list|(
name|QString
name|indexNumber
parameter_list|)
block|{
name|int
name|index
init|=
name|qrand
argument_list|()
operator|%
name|m_countryCodes
operator|.
name|count
argument_list|()
decl_stmt|;
name|QString
name|countryCode
init|=
name|m_countryCodes
operator|.
name|at
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|QString
name|areaCode
init|=
name|QString
operator|::
name|number
argument_list|(
name|index
argument_list|)
operator|+
name|QString
argument_list|(
literal|"0"
argument_list|)
operator|.
name|repeated
argument_list|(
literal|2
operator|-
name|QString
operator|::
name|number
argument_list|(
name|index
argument_list|)
operator|.
name|length
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|beginNumber
init|=
name|QString
operator|::
name|number
argument_list|(
literal|555
operator|-
name|index
operator|*
literal|2
argument_list|)
decl_stmt|;
name|QString
name|endNumber
init|=
name|QString
argument_list|(
literal|"0"
argument_list|)
operator|.
name|repeated
argument_list|(
literal|4
operator|-
name|indexNumber
operator|.
name|length
argument_list|()
argument_list|)
operator|+
name|indexNumber
decl_stmt|;
return|return
name|countryCode
operator|+
literal|" "
operator|+
name|areaCode
operator|+
literal|" "
operator|+
name|beginNumber
operator|+
literal|" "
operator|+
name|endNumber
return|;
block|}
end_function
begin_function
DECL|function|randomFirstName
name|QString
name|DummyDataGenerator
operator|::
name|randomFirstName
parameter_list|()
block|{
name|m_isMale
operator|=
operator|!
name|m_isMale
expr_stmt|;
if|if
condition|(
name|m_isMale
condition|)
return|return
name|m_firstNamesM
operator|.
name|at
argument_list|(
name|qrand
argument_list|()
operator|%
name|m_firstNamesM
operator|.
name|count
argument_list|()
argument_list|)
return|;
return|return
name|m_firstNamesF
operator|.
name|at
argument_list|(
name|qrand
argument_list|()
operator|%
name|m_firstNamesF
operator|.
name|count
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|randomLastName
name|QString
name|DummyDataGenerator
operator|::
name|randomLastName
parameter_list|()
block|{
return|return
name|m_lastNames
operator|.
name|at
argument_list|(
name|qrand
argument_list|()
operator|%
name|m_lastNames
operator|.
name|count
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|randomName
name|QString
name|DummyDataGenerator
operator|::
name|randomName
parameter_list|()
block|{
return|return
name|QString
argument_list|(
name|randomFirstName
argument_list|()
operator|+
name|QString
argument_list|(
literal|", "
argument_list|)
operator|+
name|randomLastName
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|randomIconItem
name|QString
name|DummyDataGenerator
operator|::
name|randomIconItem
parameter_list|()
block|{
name|QString
name|avatar
init|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmapPath
argument_list|()
operator|+
literal|"contact_default_icon.svg"
decl_stmt|;
if|if
condition|(
name|qrand
argument_list|()
operator|%
literal|4
condition|)
block|{
name|int
name|randVal
init|=
literal|1
operator|+
name|qrand
argument_list|()
operator|%
literal|25
decl_stmt|;
if|if
condition|(
name|m_isMale
operator|&&
name|randVal
operator|>
literal|15
condition|)
block|{
name|randVal
operator|-=
literal|15
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_isMale
operator|&&
name|randVal
operator|<=
literal|10
condition|)
block|{
name|randVal
operator|+=
literal|10
expr_stmt|;
block|}
name|avatar
operator|=
name|QString
argument_list|(
literal|":/avatars/avatar_%1.png"
argument_list|)
operator|.
name|arg
argument_list|(
name|randVal
argument_list|,
literal|3
argument_list|,
literal|10
argument_list|,
name|QChar
argument_list|(
literal|'0'
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|avatar
return|;
block|}
end_function
begin_function
DECL|function|randomStatusItem
name|QString
name|DummyDataGenerator
operator|::
name|randomStatusItem
parameter_list|()
block|{
switch|switch
condition|(
name|qrand
argument_list|()
operator|%
literal|3
condition|)
block|{
case|case
literal|0
case|:
return|return
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmapPath
argument_list|()
operator|+
literal|"contact_status_online.svg"
return|;
case|case
literal|1
case|:
return|return
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmapPath
argument_list|()
operator|+
literal|"contact_status_offline.svg"
return|;
case|case
literal|2
case|:
return|return
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmapPath
argument_list|()
operator|+
literal|"contact_status_idle.svg"
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
end_unit
