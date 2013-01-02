begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBMIME_H
end_ifndef
begin_define
DECL|macro|QXCBMIME_H
define|#
directive|define
name|QXCBMIME_H
end_define
begin_include
include|#
directive|include
file|<private/qdnd_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QClipboard>
end_include
begin_include
include|#
directive|include
file|"qxcbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qxcbconnection.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|QT_NO_DRAGANDDROP
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_NO_CLIPBOARD
argument_list|)
operator|)
name|class
name|QXcbMime
range|:
name|public
name|QInternalMimeData
block|{
name|Q_OBJECT
name|public
operator|:
name|QXcbMime
argument_list|()
block|;
operator|~
name|QXcbMime
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|xcb_atom_t
operator|>
name|mimeAtomsForFormat
argument_list|(
name|QXcbConnection
operator|*
name|connection
argument_list|,
specifier|const
name|QString
operator|&
name|format
argument_list|)
block|;
specifier|static
name|QString
name|mimeAtomToString
argument_list|(
argument|QXcbConnection *connection
argument_list|,
argument|xcb_atom_t a
argument_list|)
block|;
specifier|static
name|bool
name|mimeDataForAtom
argument_list|(
argument|QXcbConnection *connection
argument_list|,
argument|xcb_atom_t a
argument_list|,
argument|QMimeData *mimeData
argument_list|,
argument|QByteArray *data
argument_list|,
argument|xcb_atom_t *atomFormat
argument_list|,
argument|int *dataFormat
argument_list|)
block|;
specifier|static
name|QVariant
name|mimeConvertToFormat
argument_list|(
argument|QXcbConnection *connection
argument_list|,
argument|xcb_atom_t a
argument_list|,
argument|const QByteArray&data
argument_list|,
argument|const QString&format
argument_list|,
argument|QVariant::Type requestedType
argument_list|,
argument|const QByteArray&encoding
argument_list|)
block|;
specifier|static
name|xcb_atom_t
name|mimeAtomForFormat
argument_list|(
argument|QXcbConnection *connection
argument_list|,
argument|const QString&format
argument_list|,
argument|QVariant::Type requestedType
argument_list|,
argument|const QList<xcb_atom_t>&atoms
argument_list|,
argument|QByteArray *requestedEncoding
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !(defined(QT_NO_DRAGANDDROP)&& defined(QT_NO_CLIPBOARD))
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXCBMIME_H
end_comment
end_unit
