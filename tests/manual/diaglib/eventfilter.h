begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_EVENTFILTER_
end_ifndef
begin_define
DECL|macro|_EVENTFILTER_
define|#
directive|define
name|_EVENTFILTER_
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_decl_stmt
name|namespace
name|QtDiag
block|{
comment|// Event filter that can for example be installed on QApplication
comment|// to log relevant events.
name|class
name|EventFilter
range|:
name|public
name|QObject
block|{
name|public
operator|:
expr|enum
name|EventCategory
block|{
name|MouseEvents
operator|=
literal|0x00001
block|,
name|MouseMoveEvents
operator|=
literal|0x00002
block|,
name|TouchEvents
operator|=
literal|0x00004
block|,
name|TabletEvents
operator|=
literal|0x00008
block|,
name|DragAndDropEvents
operator|=
literal|0x00010
block|,
name|KeyEvents
operator|=
literal|0x00020
block|,
name|FocusEvents
operator|=
literal|0x00040
block|,
name|GeometryEvents
operator|=
literal|0x00080
block|,
name|PaintEvents
operator|=
literal|0x00100
block|,
name|StateChangeEvents
operator|=
literal|0x00200
block|,
name|InputMethodEvents
operator|=
literal|0x00400
block|,
name|TimerEvents
operator|=
literal|0x00800
block|,
name|ObjectEvents
operator|=
literal|0x01000
block|,
name|AllEvents
operator|=
literal|0xFFFFF
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|EventCategories
argument_list|,
name|EventCategory
argument_list|)
expr|enum
name|ObjectType
block|{
name|QWindowType
operator|=
literal|0x1
block|,
name|QWidgetType
operator|=
literal|0x2
block|,
name|OtherType
operator|=
literal|0x4
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ObjectTypes
argument_list|,
argument|ObjectType
argument_list|)
name|explicit
name|EventFilter
argument_list|(
argument|EventCategories eventCategories
argument_list|,
argument|QObject *p =
literal|0
argument_list|)
block|;
name|explicit
name|EventFilter
argument_list|(
name|QObject
operator|*
name|p
operator|=
literal|0
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|ObjectTypes
name|objectTypes
argument_list|()
specifier|const
block|{
return|return
name|m_objectTypes
return|;
block|}
name|void
name|setObjectTypes
argument_list|(
argument|ObjectTypes objectTypes
argument_list|)
block|{
name|m_objectTypes
operator|=
name|objectTypes
block|; }
name|private
operator|:
name|void
name|init
argument_list|(
argument|EventCategories eventCategories
argument_list|)
block|;
name|QList
operator|<
name|QEvent
operator|::
name|Type
operator|>
name|m_eventTypes
block|;
name|ObjectTypes
name|m_objectTypes
block|; }
decl_stmt|;
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|EventFilter::EventCategories
argument_list|)
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|EventFilter::ObjectTypes
argument_list|)
block|}
end_decl_stmt
begin_comment
comment|// namespace QtDiag
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
