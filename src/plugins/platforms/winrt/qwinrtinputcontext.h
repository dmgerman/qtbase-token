begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINRTINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINRTINPUTCONTEXT_H
define|#
directive|define
name|QWINRTINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRectF>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
end_ifndef
begin_include
include|#
directive|include
file|<UIAutomationCore.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|namespace
name|ABI
block|{
name|namespace
name|Windows
block|{
name|namespace
name|UI
block|{
name|namespace
name|Core
block|{
struct_decl|struct
name|ICoreWindow
struct_decl|;
block|}
name|namespace
name|ViewManagement
block|{
struct_decl|struct
name|IInputPane
struct_decl|;
struct_decl|struct
name|IInputPaneVisibilityEventArgs
struct_decl|;
block|}
block|}
block|}
block|}
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformInputContext
name|class
name|QWinRTInputContext
range|:
name|public
name|QPlatformInputContext
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
decl_stmt|,
name|public
name|Microsoft
decl|::
name|WRL
decl|::
name|RuntimeClass
decl|<
DECL|member|WinRtClassicComMix
name|Microsoft
decl|::
name|WRL
decl|::
name|RuntimeClassFlags
decl|<
name|Microsoft
decl|::
name|WRL
decl|::
name|WinRtClassicComMix
decl|>
decl_stmt|,
DECL|variable|IRawElementProviderSimple
DECL|variable|ITextProvider
name|IRawElementProviderSimple
decl_stmt|,
name|ITextProvider
decl_stmt|,
name|IValueProvider
decl|>
endif|#
directive|endif
comment|// !Q_OS_WINPHONE
block|{
name|public
label|:
name|explicit
name|QWinRTInputContext
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
name|window
argument_list|)
decl_stmt|;
name|QRectF
name|keyboardRect
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isInputPanelVisible
argument_list|()
specifier|const
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINPHONE
name|void
name|showInputPanel
parameter_list|()
function_decl|;
name|void
name|hideInputPanel
parameter_list|()
function_decl|;
else|#
directive|else
comment|// Q_OS_WINPHONE
comment|// IRawElementProviderSimple
name|HRESULT
name|__stdcall
name|get_ProviderOptions
parameter_list|(
name|ProviderOptions
modifier|*
name|retVal
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|GetPatternProvider
parameter_list|(
name|PATTERNID
parameter_list|,
name|IUnknown
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|GetPropertyValue
parameter_list|(
name|PROPERTYID
name|idProp
parameter_list|,
name|VARIANT
modifier|*
name|retVal
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|get_HostRawElementProvider
parameter_list|(
name|IRawElementProviderSimple
modifier|*
modifier|*
name|retVal
parameter_list|)
function_decl|;
comment|// ITextProvider
name|HRESULT
name|__stdcall
name|GetSelection
parameter_list|(
name|SAFEARRAY
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|GetVisibleRanges
parameter_list|(
name|SAFEARRAY
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|RangeFromChild
parameter_list|(
name|IRawElementProviderSimple
modifier|*
parameter_list|,
name|ITextRangeProvider
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|RangeFromPoint
parameter_list|(
name|UiaPoint
parameter_list|,
name|ITextRangeProvider
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|get_DocumentRange
parameter_list|(
name|ITextRangeProvider
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|get_SupportedTextSelection
parameter_list|(
name|SupportedTextSelection
modifier|*
parameter_list|)
function_decl|;
comment|// IValueProvider
name|HRESULT
name|__stdcall
name|SetValue
parameter_list|(
name|LPCWSTR
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|get_Value
parameter_list|(
name|BSTR
modifier|*
parameter_list|)
function_decl|;
name|HRESULT
name|__stdcall
name|get_IsReadOnly
parameter_list|(
name|BOOL
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// !Q_OS_WINPHONE
name|private
label|:
name|HRESULT
name|onShowing
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPane
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPaneVisibilityEventArgs
operator|*
argument_list|)
decl_stmt|;
name|HRESULT
name|onHiding
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPane
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPaneVisibilityEventArgs
operator|*
argument_list|)
decl_stmt|;
name|void
name|setKeyboardRect
parameter_list|(
specifier|const
name|QRectF
name|rect
parameter_list|)
function_decl|;
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
name|m_window
expr_stmt|;
name|QRectF
name|m_keyboardRect
decl_stmt|;
name|bool
name|m_isInputPanelVisible
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINRTINPUTCONTEXT_H
end_comment
end_unit
