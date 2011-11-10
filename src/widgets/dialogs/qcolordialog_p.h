begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLORDIALOG_P_H
end_ifndef
begin_define
DECL|macro|QCOLORDIALOG_P_H
define|#
directive|define
name|QCOLORDIALOG_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"private/qdialog_p.h"
end_include
begin_include
include|#
directive|include
file|"qcolordialog.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COLORDIALOG
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QColorLuminancePicker
name|class
name|QColorLuminancePicker
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColorPicker
name|class
name|QColorPicker
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColorShower
name|class
name|QColorShower
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDialogButtonBox
name|class
name|QDialogButtonBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVBoxLayout
name|class
name|QVBoxLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWellArray
name|class
name|QWellArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QColorDialogPrivate
range|:
name|public
name|QDialogPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QColorDialog
argument_list|)
name|public
operator|:
name|QPlatformColorDialogHelper
operator|*
name|platformColorDialogHelper
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|QPlatformColorDialogHelper
operator|*
operator|>
operator|(
name|platformHelper
argument_list|()
operator|)
return|;
block|}
name|void
name|init
argument_list|(
specifier|const
name|QColor
operator|&
name|initial
argument_list|)
block|;
name|QRgb
name|currentColor
argument_list|()
specifier|const
block|;
name|QColor
name|currentQColor
argument_list|()
specifier|const
block|;
name|void
name|setCurrentColor
argument_list|(
argument|QRgb rgb
argument_list|)
block|;
name|void
name|setCurrentQColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|bool
name|selectColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|int
name|currentAlpha
argument_list|()
specifier|const
block|;
name|void
name|setCurrentAlpha
argument_list|(
argument|int a
argument_list|)
block|;
name|void
name|showAlpha
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|isAlphaVisible
argument_list|()
specifier|const
block|;
name|void
name|retranslateStrings
argument_list|()
block|;
name|void
name|_q_addCustom
argument_list|()
block|;
name|void
name|_q_platformRunNativeAppModalPanel
argument_list|()
block|;
name|void
name|_q_newHsv
argument_list|(
argument|int h
argument_list|,
argument|int s
argument_list|,
argument|int v
argument_list|)
block|;
name|void
name|_q_newColorTypedIn
argument_list|(
argument|QRgb rgb
argument_list|)
block|;
name|void
name|_q_newCustom
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
block|;
name|void
name|_q_newStandard
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
block|;
name|QWellArray
operator|*
name|custom
block|;
name|QWellArray
operator|*
name|standard
block|;
name|QDialogButtonBox
operator|*
name|buttons
block|;
name|QVBoxLayout
operator|*
name|leftLay
block|;
name|QColorPicker
operator|*
name|cp
block|;
name|QColorLuminancePicker
operator|*
name|lp
block|;
name|QColorShower
operator|*
name|cs
block|;
name|QLabel
operator|*
name|lblBasicColors
block|;
name|QLabel
operator|*
name|lblCustomColors
block|;
name|QPushButton
operator|*
name|ok
block|;
name|QPushButton
operator|*
name|cancel
block|;
name|QPushButton
operator|*
name|addCusBt
block|;
name|QColor
name|selectedQColor
block|;
name|int
name|nextCust
block|;
name|bool
name|smallDisplay
block|;
name|QColorDialog
operator|::
name|ColorDialogOptions
name|opts
block|;
name|QPointer
operator|<
name|QObject
operator|>
name|receiverToDisconnectOnClose
block|;
name|QByteArray
name|memberToDisconnectOnClose
block|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|void
name|openCocoaColorPanel
argument_list|(
argument|const QColor&initial
argument_list|,
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|QColorDialog::ColorDialogOptions options
argument_list|)
block|;
name|void
name|closeCocoaColorPanel
argument_list|()
block|;
name|void
name|releaseCocoaColorPanelDelegate
argument_list|()
block|;
name|void
name|setCocoaPanelColor
argument_list|(
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
specifier|inline
name|void
name|done
argument_list|(
argument|int result
argument_list|)
block|{
name|q_func
argument_list|()
operator|->
name|done
argument_list|(
name|result
argument_list|)
block|; }
specifier|inline
name|QColorDialog
operator|*
name|colorDialog
argument_list|()
block|{
return|return
name|q_func
argument_list|()
return|;
block|}
name|void
operator|*
name|delegate
block|;
specifier|static
name|bool
name|sharedColorPanelAvailable
block|;
name|void
name|_q_macRunNativeAppModalPanel
argument_list|()
block|;
name|void
name|mac_nativeDialogModalHelp
argument_list|()
block|;
endif|#
directive|endif
name|private
operator|:
name|virtual
name|void
name|initHelper
argument_list|(
name|QPlatformDialogHelper
operator|*
name|h
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COLORDIALOG
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOLORDIALOG_P_H
end_comment
end_unit
