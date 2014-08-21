begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ROUNDEDBOX_H
end_ifndef
begin_define
DECL|macro|ROUNDEDBOX_H
define|#
directive|define
name|ROUNDEDBOX_H
end_define
begin_comment
comment|//#include<GL/glew.h>
end_comment
begin_include
include|#
directive|include
file|"glextensions.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL>
end_include
begin_include
include|#
directive|include
file|"gltrianglemesh.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector3d.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector2d.h>
end_include
begin_include
include|#
directive|include
file|"glbuffers.h"
end_include
begin_struct
DECL|struct|P3T2N3Vertex
struct|struct
name|P3T2N3Vertex
block|{
DECL|member|position
name|QVector3D
name|position
decl_stmt|;
DECL|member|texCoord
name|QVector2D
name|texCoord
decl_stmt|;
DECL|member|normal
name|QVector3D
name|normal
decl_stmt|;
DECL|member|description
specifier|static
name|VertexDescription
name|description
index|[]
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|P3T2N3Vertex
name|class
name|GLRoundedBox
range|:
name|public
name|GLTriangleMesh
operator|<
name|P3T2N3Vertex
decl_stmt|,
name|unsigned
name|short
decl|>
block|{
name|public
label|:
comment|// 0< r< 0.5, 0<= n<= 125
name|explicit
name|GLRoundedBox
parameter_list|(
name|float
name|r
init|=
literal|0.25f
parameter_list|,
name|float
name|scale
init|=
literal|1.0f
parameter_list|,
name|int
name|n
init|=
literal|10
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
