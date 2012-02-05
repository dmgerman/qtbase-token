begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qgenericplugin_qpa.h>
end_include
begin_include
include|#
directive|include
file|"qtslib.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QTsLibPlugin
class|class
name|QTsLibPlugin
super|:
specifier|public
name|QGenericPlugin
block|{
public|public:
name|QTsLibPlugin
parameter_list|()
constructor_decl|;
name|QStringList
name|keys
parameter_list|()
specifier|const
function_decl|;
name|QObject
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QTsLibPlugin
name|QTsLibPlugin
operator|::
name|QTsLibPlugin
parameter_list|()
member_init_list|:
name|QGenericPlugin
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|keys
name|QStringList
name|QTsLibPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"Tslib"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"TslibRaw"
argument_list|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|create
name|QObject
modifier|*
name|QTsLibPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
parameter_list|)
block|{
if|if
condition|(
operator|!
name|key
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"Tslib"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|||
operator|!
name|key
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"TslibRaw"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
condition|)
return|return
operator|new
name|QTsLibMouseHandler
argument_list|(
name|key
argument_list|,
name|specification
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|Q_EXPORT_PLUGIN2
argument_list|(
argument|qtslibplugin
argument_list|,
argument|QTsLibPlugin
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
