begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfontenginemultifontconfig_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_ft_p.h>
end_include
begin_include
include|#
directive|include
file|<fontconfig/fontconfig.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qfontengine_ft_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QFontEngineMultiFontConfig
name|QFontEngineMultiFontConfig
operator|::
name|QFontEngineMultiFontConfig
parameter_list|(
name|QFontEngine
modifier|*
name|fe
parameter_list|,
name|int
name|script
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|fallbacks
parameter_list|)
member_init_list|:
name|QFontEngineMultiQPA
argument_list|(
name|fe
argument_list|,
name|script
argument_list|,
name|fallbacks
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|shouldLoadFontEngineForCharacter
name|bool
name|QFontEngineMultiFontConfig
operator|::
name|shouldLoadFontEngineForCharacter
parameter_list|(
name|int
name|at
parameter_list|,
name|uint
name|ucs4
parameter_list|)
specifier|const
block|{
name|QFontEngineFT
modifier|*
name|fontEngine
init|=
cast|static_cast
argument_list|<
name|QFontEngineFT
operator|*
argument_list|>
argument_list|(
name|engines
operator|.
name|at
argument_list|(
name|at
argument_list|)
argument_list|)
decl_stmt|;
name|bool
name|charSetHasChar
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|fontEngine
operator|!=
literal|0
condition|)
block|{
name|FcCharSet
modifier|*
name|charSet
init|=
name|fontEngine
operator|->
name|freetype
operator|->
name|charset
decl_stmt|;
name|charSetHasChar
operator|=
name|FcCharSetHasChar
argument_list|(
name|charSet
argument_list|,
name|ucs4
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|FcPattern
modifier|*
name|requestPattern
init|=
name|FcPatternCreate
argument_list|()
decl_stmt|;
name|FcValue
name|value
decl_stmt|;
name|value
operator|.
name|type
operator|=
name|FcTypeString
expr_stmt|;
name|QByteArray
name|cs
init|=
name|fallbackFamilyAt
argument_list|(
name|at
operator|-
literal|1
argument_list|)
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|value
operator|.
name|u
operator|.
name|s
operator|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|FcChar8
operator|*
argument_list|>
argument_list|(
name|cs
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|FcPatternAdd
argument_list|(
name|requestPattern
argument_list|,
name|FC_FAMILY
argument_list|,
name|value
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|FcResult
name|result
decl_stmt|;
name|FcPattern
modifier|*
name|matchPattern
init|=
name|FcFontMatch
argument_list|(
literal|0
argument_list|,
name|requestPattern
argument_list|,
operator|&
name|result
argument_list|)
decl_stmt|;
if|if
condition|(
name|matchPattern
operator|!=
literal|0
condition|)
block|{
name|FcCharSet
modifier|*
name|charSet
decl_stmt|;
name|FcPatternGetCharSet
argument_list|(
name|matchPattern
argument_list|,
name|FC_CHARSET
argument_list|,
literal|0
argument_list|,
operator|&
name|charSet
argument_list|)
expr_stmt|;
name|charSetHasChar
operator|=
name|FcCharSetHasChar
argument_list|(
name|charSet
argument_list|,
name|ucs4
argument_list|)
expr_stmt|;
name|FcPatternDestroy
argument_list|(
name|matchPattern
argument_list|)
expr_stmt|;
block|}
name|FcPatternDestroy
argument_list|(
name|requestPattern
argument_list|)
expr_stmt|;
block|}
return|return
name|charSetHasChar
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
