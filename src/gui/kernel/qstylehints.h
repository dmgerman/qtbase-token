begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTYLEHINTS_H
end_ifndef
begin_define
DECL|macro|QSTYLEHINTS_H
define|#
directive|define
name|QSTYLEHINTS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformIntegration
name|class
name|QPlatformIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleHintsPrivate
name|class
name|QStyleHintsPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QStyleHints
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QStyleHints
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int cursorFlashTime READ cursorFlashTime NOTIFY cursorFlashTimeChanged FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal fontSmoothingGamma READ fontSmoothingGamma STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int keyboardAutoRepeatRate READ keyboardAutoRepeatRate STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int keyboardInputInterval READ keyboardInputInterval NOTIFY keyboardInputIntervalChanged FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int mouseDoubleClickInterval READ mouseDoubleClickInterval NOTIFY mouseDoubleClickIntervalChanged FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int mousePressAndHoldInterval READ mousePressAndHoldInterval STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QChar passwordMaskCharacter READ passwordMaskCharacter STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int passwordMaskDelay READ passwordMaskDelay STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool setFocusOnTouchRelease READ setFocusOnTouchRelease STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool showIsFullScreen READ showIsFullScreen STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int startDragDistance READ startDragDistance NOTIFY startDragDistanceChanged FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int startDragTime READ startDragTime NOTIFY startDragTimeChanged FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int startDragVelocity READ startDragVelocity STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool useRtlExtensions READ useRtlExtensions STORED false CONSTANT FINAL
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TabFocusBehavior tabFocusBehavior READ tabFocusBehavior STORED false CONSTANT FINAL
argument_list|)
name|public
operator|:
name|void
name|setMouseDoubleClickInterval
argument_list|(
argument|int mouseDoubleClickInterval
argument_list|)
block|;
name|int
name|mouseDoubleClickInterval
argument_list|()
specifier|const
block|;
name|int
name|mousePressAndHoldInterval
argument_list|()
specifier|const
block|;
name|void
name|setStartDragDistance
argument_list|(
argument|int startDragDistance
argument_list|)
block|;
name|int
name|startDragDistance
argument_list|()
specifier|const
block|;
name|void
name|setStartDragTime
argument_list|(
argument|int startDragTime
argument_list|)
block|;
name|int
name|startDragTime
argument_list|()
specifier|const
block|;
name|int
name|startDragVelocity
argument_list|()
specifier|const
block|;
name|void
name|setKeyboardInputInterval
argument_list|(
argument|int keyboardInputInterval
argument_list|)
block|;
name|int
name|keyboardInputInterval
argument_list|()
specifier|const
block|;
name|int
name|keyboardAutoRepeatRate
argument_list|()
specifier|const
block|;
name|void
name|setCursorFlashTime
argument_list|(
argument|int cursorFlashTime
argument_list|)
block|;
name|int
name|cursorFlashTime
argument_list|()
specifier|const
block|;
name|bool
name|showIsFullScreen
argument_list|()
specifier|const
block|;
name|int
name|passwordMaskDelay
argument_list|()
specifier|const
block|;
name|QChar
name|passwordMaskCharacter
argument_list|()
specifier|const
block|;
name|qreal
name|fontSmoothingGamma
argument_list|()
specifier|const
block|;
name|bool
name|useRtlExtensions
argument_list|()
specifier|const
block|;
name|bool
name|setFocusOnTouchRelease
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|TabFocusBehavior
name|tabFocusBehavior
argument_list|()
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|cursorFlashTimeChanged
argument_list|(
argument|int cursorFlashTime
argument_list|)
block|;
name|void
name|keyboardInputIntervalChanged
argument_list|(
argument|int keyboardInputInterval
argument_list|)
block|;
name|void
name|mouseDoubleClickIntervalChanged
argument_list|(
argument|int mouseDoubleClickInterval
argument_list|)
block|;
name|void
name|startDragDistanceChanged
argument_list|(
argument|int startDragDistance
argument_list|)
block|;
name|void
name|startDragTimeChanged
argument_list|(
argument|int startDragTime
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QGuiApplication
block|;
name|QStyleHints
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
