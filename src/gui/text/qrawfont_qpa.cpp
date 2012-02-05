begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_RAWFONT
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qrawfont_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qplatformfontdatabase_qpa.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|platformCleanUp
name|void
name|QRawFontPrivate
operator|::
name|platformCleanUp
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|platformLoadFromData
name|void
name|QRawFontPrivate
operator|::
name|platformLoadFromData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|fontData
parameter_list|,
name|qreal
name|pixelSize
parameter_list|,
name|QFont
operator|::
name|HintingPreference
name|hintingPreference
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|fontEngine
operator|==
literal|0
argument_list|)
expr_stmt|;
name|QPlatformFontDatabase
modifier|*
name|pfdb
init|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|fontDatabase
argument_list|()
decl_stmt|;
name|fontEngine
operator|=
name|pfdb
operator|->
name|fontEngine
argument_list|(
name|fontData
argument_list|,
name|pixelSize
argument_list|,
name|hintingPreference
argument_list|)
expr_stmt|;
if|if
condition|(
name|fontEngine
operator|!=
literal|0
condition|)
name|fontEngine
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_RAWFONT
end_comment
end_unit
