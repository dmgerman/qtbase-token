begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  qgrayraster_p.h, derived from ftgrays.h                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType smooth renderer declaration                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, ../../3rdparty/freetype/docs/FTL.TXT.  By continuing to use,  */
end_comment
begin_comment
comment|/*  modify, or distribute this file you indicate that you have read        */
end_comment
begin_comment
comment|/*  the license and understand and accept it fully.                        */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTGRAYS_H__
end_ifndef
begin_define
DECL|macro|__FTGRAYS_H__
define|#
directive|define
name|__FTGRAYS_H__
end_define
begin_comment
comment|/* //  W A R N I N G //  ------------- // // This file is not part of the Qt API.  It exists purely as an // implementation detail.  This header file may change from version to // version without notice, or even be removed. // // We mean it. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<private/qrasterdefs_p.h>
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* To make ftgrays.h independent from configuration files we check       */
comment|/* whether QT_FT_EXPORT_VAR has been defined already.                    */
comment|/*                                                                       */
comment|/* On some systems and compilers (Win32 mostly), an extra keyword is     */
comment|/* necessary to compile the library as a DLL.                            */
comment|/*                                                                       */
ifndef|#
directive|ifndef
name|QT_FT_EXPORT_VAR
DECL|macro|QT_FT_EXPORT_VAR
define|#
directive|define
name|QT_FT_EXPORT_VAR
parameter_list|(
name|x
parameter_list|)
value|extern  x
endif|#
directive|endif
comment|/* Minimum buffer size for raster object, that accounts    for TWorker and TCell sizes.*/
DECL|macro|MINIMUM_POOL_SIZE
define|#
directive|define
name|MINIMUM_POOL_SIZE
value|8192
name|QT_FT_EXPORT_VAR
argument_list|(
argument|const QT_FT_Raster_Funcs
argument_list|)
name|qt_ft_grays_raster
expr_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTGRAYS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
