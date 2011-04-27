begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTESTLITEMIME_H
end_ifndef
begin_define
DECL|macro|QTESTLITEMIME_H
define|#
directive|define
name|QTESTLITEMIME_H
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
file|"qxlibintegration.h"
end_include
begin_include
include|#
directive|include
file|"qxlibclipboard.h"
end_include
begin_decl_stmt
name|class
name|QXlibMime
range|:
name|public
name|QInternalMimeData
block|{
name|Q_OBJECT
name|public
operator|:
name|QXlibMime
argument_list|()
block|;
operator|~
name|QXlibMime
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|Atom
operator|>
name|mimeAtomsForFormat
argument_list|(
name|Display
operator|*
name|display
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
argument|Display *display
argument_list|,
argument|Atom a
argument_list|)
block|;
specifier|static
name|bool
name|mimeDataForAtom
argument_list|(
argument|Display *display
argument_list|,
argument|Atom a
argument_list|,
argument|QMimeData *mimeData
argument_list|,
argument|QByteArray *data
argument_list|,
argument|Atom *atomFormat
argument_list|,
argument|int *dataFormat
argument_list|)
block|;
specifier|static
name|QStringList
name|mimeFormatsForAtom
argument_list|(
argument|Display *display
argument_list|,
argument|Atom a
argument_list|)
block|;
specifier|static
name|Atom
name|mimeStringToAtom
argument_list|(
name|Display
operator|*
name|display
argument_list|,
specifier|const
name|QString
operator|&
name|mimeType
argument_list|)
block|;
specifier|static
name|QVariant
name|mimeConvertToFormat
argument_list|(
argument|Display *display
argument_list|,
argument|Atom a
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
name|Atom
name|mimeAtomForFormat
argument_list|(
argument|Display *display
argument_list|,
argument|const QString&format
argument_list|,
argument|QVariant::Type requestedType
argument_list|,
argument|const QList<Atom>&atoms
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
comment|// QTESTLITEMIME_H
end_comment
end_unit
