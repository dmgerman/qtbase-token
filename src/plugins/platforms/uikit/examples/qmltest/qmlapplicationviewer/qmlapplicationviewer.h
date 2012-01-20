begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// checksum 0x5a59 version 0x3000a
end_comment
begin_comment
comment|/*   This file was generated by the Qt Quick Application wizard of Qt Creator.   QmlApplicationViewer is a convenience class containing mobile device specific   code such as screen orientation handling. Also QML paths and debugging are   handled here.   It is recommended not to modify this file, since newer versions of Qt Creator   may offer an updated version of it. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMLAPPLICATIONVIEWER_H
end_ifndef
begin_define
DECL|macro|QMLAPPLICATIONVIEWER_H
define|#
directive|define
name|QMLAPPLICATIONVIEWER_H
end_define
begin_include
include|#
directive|include
file|<QtDeclarative/QDeclarativeView>
end_include
begin_decl_stmt
name|class
name|QmlApplicationViewer
range|:
name|public
name|QDeclarativeView
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ScreenOrientation
block|{
name|ScreenOrientationLockPortrait
block|,
name|ScreenOrientationLockLandscape
block|,
name|ScreenOrientationAuto
block|}
block|;
name|explicit
name|QmlApplicationViewer
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QmlApplicationViewer
argument_list|()
block|;
name|void
name|setMainQmlFile
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|void
name|addImportPath
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|setOrientation
argument_list|(
argument|ScreenOrientation orientation
argument_list|)
block|;
name|void
name|showExpanded
argument_list|()
block|;
name|private
operator|:
name|class
name|QmlApplicationViewerPrivate
operator|*
name|m_d
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMLAPPLICATIONVIEWER_H
end_comment
end_unit
