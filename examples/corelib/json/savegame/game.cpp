begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"game.h"
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QJsonArray>
end_include
begin_include
include|#
directive|include
file|<QJsonDocument>
end_include
begin_constructor
DECL|function|Game
name|Game
operator|::
name|Game
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|player
specifier|const
name|Character
modifier|&
name|Game
operator|::
name|player
parameter_list|()
specifier|const
block|{
return|return
name|mPlayer
return|;
block|}
end_function
begin_function
DECL|function|levels
specifier|const
name|QList
argument_list|<
name|Level
argument_list|>
modifier|&
name|Game
operator|::
name|levels
parameter_list|()
specifier|const
block|{
return|return
name|mLevels
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|newGame
name|void
name|Game
operator|::
name|newGame
parameter_list|()
block|{
name|mPlayer
operator|=
name|Character
argument_list|()
expr_stmt|;
name|mPlayer
operator|.
name|setName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Hero"
argument_list|)
argument_list|)
expr_stmt|;
name|mPlayer
operator|.
name|setClassType
argument_list|(
name|Character
operator|::
name|Archer
argument_list|)
expr_stmt|;
name|mPlayer
operator|.
name|setLevel
argument_list|(
literal|15
argument_list|)
expr_stmt|;
name|mLevels
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Level
name|village
decl_stmt|;
name|QList
argument_list|<
name|Character
argument_list|>
name|villageNpcs
decl_stmt|;
name|villageNpcs
operator|.
name|append
argument_list|(
name|Character
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Barry the Blacksmith"
argument_list|)
argument_list|,
literal|10
argument_list|,
name|Character
operator|::
name|Warrior
argument_list|)
argument_list|)
expr_stmt|;
name|villageNpcs
operator|.
name|append
argument_list|(
name|Character
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Terry the Trader"
argument_list|)
argument_list|,
literal|10
argument_list|,
name|Character
operator|::
name|Warrior
argument_list|)
argument_list|)
expr_stmt|;
name|village
operator|.
name|setNpcs
argument_list|(
name|villageNpcs
argument_list|)
expr_stmt|;
name|mLevels
operator|.
name|append
argument_list|(
name|village
argument_list|)
expr_stmt|;
name|Level
name|dungeon
decl_stmt|;
name|QList
argument_list|<
name|Character
argument_list|>
name|dungeonNpcs
decl_stmt|;
name|dungeonNpcs
operator|.
name|append
argument_list|(
name|Character
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Eric the Evil"
argument_list|)
argument_list|,
literal|20
argument_list|,
name|Character
operator|::
name|Mage
argument_list|)
argument_list|)
expr_stmt|;
name|dungeonNpcs
operator|.
name|append
argument_list|(
name|Character
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Eric's Sidekick #1"
argument_list|)
argument_list|,
literal|5
argument_list|,
name|Character
operator|::
name|Warrior
argument_list|)
argument_list|)
expr_stmt|;
name|dungeonNpcs
operator|.
name|append
argument_list|(
name|Character
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Eric's Sidekick #2"
argument_list|)
argument_list|,
literal|5
argument_list|,
name|Character
operator|::
name|Warrior
argument_list|)
argument_list|)
expr_stmt|;
name|dungeon
operator|.
name|setNpcs
argument_list|(
name|dungeonNpcs
argument_list|)
expr_stmt|;
name|mLevels
operator|.
name|append
argument_list|(
name|dungeon
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|loadGame
name|bool
name|Game
operator|::
name|loadGame
parameter_list|(
name|Game
operator|::
name|SaveFormat
name|saveFormat
parameter_list|)
block|{
name|QFile
name|loadFile
argument_list|(
name|saveFormat
operator|==
name|Json
condition|?
name|QStringLiteral
argument_list|(
literal|"save.json"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"save.dat"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|loadFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Couldn't open save file."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QByteArray
name|saveData
init|=
name|loadFile
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QJsonDocument
name|loadDoc
argument_list|(
name|saveFormat
operator|==
name|Json
condition|?
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|saveData
argument_list|)
else|:
name|QJsonDocument
operator|::
name|fromBinaryData
argument_list|(
name|saveData
argument_list|)
argument_list|)
decl_stmt|;
name|read
argument_list|(
name|loadDoc
operator|.
name|object
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|saveGame
name|bool
name|Game
operator|::
name|saveGame
parameter_list|(
name|Game
operator|::
name|SaveFormat
name|saveFormat
parameter_list|)
specifier|const
block|{
name|QFile
name|saveFile
argument_list|(
name|saveFormat
operator|==
name|Json
condition|?
name|QStringLiteral
argument_list|(
literal|"save.json"
argument_list|)
else|:
name|QStringLiteral
argument_list|(
literal|"save.dat"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|saveFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Couldn't open save file."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|QJsonObject
name|gameObject
decl_stmt|;
name|write
argument_list|(
name|gameObject
argument_list|)
expr_stmt|;
name|QJsonDocument
name|saveDoc
argument_list|(
name|gameObject
argument_list|)
decl_stmt|;
name|saveFile
operator|.
name|write
argument_list|(
name|saveFormat
operator|==
name|Json
condition|?
name|saveDoc
operator|.
name|toJson
argument_list|()
else|:
name|saveDoc
operator|.
name|toBinaryData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|read
name|void
name|Game
operator|::
name|read
parameter_list|(
specifier|const
name|QJsonObject
modifier|&
name|json
parameter_list|)
block|{
name|mPlayer
operator|.
name|read
argument_list|(
name|json
index|[
literal|"player"
index|]
operator|.
name|toObject
argument_list|()
argument_list|)
expr_stmt|;
name|mLevels
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QJsonArray
name|levelArray
init|=
name|json
index|[
literal|"levels"
index|]
operator|.
name|toArray
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|levelIndex
init|=
literal|0
init|;
name|levelIndex
operator|<
name|levelArray
operator|.
name|size
argument_list|()
condition|;
operator|++
name|levelIndex
control|)
block|{
name|QJsonObject
name|levelObject
init|=
name|levelArray
index|[
name|levelIndex
index|]
operator|.
name|toObject
argument_list|()
decl_stmt|;
name|Level
name|level
decl_stmt|;
name|level
operator|.
name|read
argument_list|(
name|levelObject
argument_list|)
expr_stmt|;
name|mLevels
operator|.
name|append
argument_list|(
name|level
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|write
name|void
name|Game
operator|::
name|write
parameter_list|(
name|QJsonObject
modifier|&
name|json
parameter_list|)
specifier|const
block|{
name|QJsonObject
name|playerObject
decl_stmt|;
name|mPlayer
operator|.
name|write
argument_list|(
name|playerObject
argument_list|)
expr_stmt|;
name|json
index|[
literal|"player"
index|]
operator|=
name|playerObject
expr_stmt|;
name|QJsonArray
name|levelArray
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|Level
name|level
decl|,
name|mLevels
control|)
block|{
name|QJsonObject
name|levelObject
decl_stmt|;
name|level
operator|.
name|write
argument_list|(
name|levelObject
argument_list|)
expr_stmt|;
name|levelArray
operator|.
name|append
argument_list|(
name|levelObject
argument_list|)
expr_stmt|;
block|}
name|json
index|[
literal|"levels"
index|]
operator|=
name|levelArray
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
end_unit
