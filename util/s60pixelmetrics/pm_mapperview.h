begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the utility applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PMMAPPERVIEW_H
end_ifndef
begin_define
DECL|macro|PMMAPPERVIEW_H
define|#
directive|define
name|PMMAPPERVIEW_H
end_define
begin_comment
comment|//  INCLUDES
end_comment
begin_include
include|#
directive|include
file|<aknview.h>
end_include
begin_include
include|#
directive|include
file|<EIKLBO.H>
end_include
begin_comment
comment|// CONSTANTS
end_comment
begin_comment
comment|// FORWARD DECLARATIONS
end_comment
begin_decl_stmt
DECL|variable|CAknSingleStyleListBox
name|class
name|CAknSingleStyleListBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|CAknSettingStyleListBox
name|class
name|CAknSettingStyleListBox
decl_stmt|;
end_decl_stmt
begin_comment
comment|// CLASS DECLARATION
end_comment
begin_comment
comment|/** *  CPixelMetricsMapperViewContainer * */
end_comment
begin_decl_stmt
name|class
name|CPixelMetricsMapperViewContainer
DECL|variable|CCoeControl
range|:
name|public
name|CCoeControl
decl_stmt|,
name|public
name|MCoeControlObserver
block|{
name|public
label|:
comment|// Constructors and destructor
comment|/**         * C++ constructor.         */
name|CPixelMetricsMapperViewContainer
argument_list|()
expr_stmt|;
comment|/**         * Symbian 2nd phase constructor.         *         * @param aRect Rectangle.         */
name|void
name|ConstructL
parameter_list|(
specifier|const
name|TRect
modifier|&
name|aRect
parameter_list|)
function_decl|;
comment|/**         * Destructor.         */
operator|~
name|CPixelMetricsMapperViewContainer
argument_list|()
expr_stmt|;
name|public
label|:
comment|// New functions
comment|/**         * Show the given string.         *         * @param aString The string to be shown.         */
name|void
name|ShowL
parameter_list|(
specifier|const
name|TDesC
modifier|&
name|aString
parameter_list|,
name|TBool
modifier|&
name|aLast
parameter_list|,
specifier|const
name|TBool
modifier|&
name|aFileOutput
init|=
name|EFalse
parameter_list|)
function_decl|;
name|void
name|ClearL
parameter_list|()
function_decl|;
name|public
label|:
comment|// Functions from base classes
comment|/**         * From CCoeControl.         */
name|TKeyResponse
name|OfferKeyEventL
parameter_list|(
specifier|const
name|TKeyEvent
modifier|&
name|aKeyEvent
parameter_list|,
name|TEventCode
name|aType
parameter_list|)
function_decl|;
name|void
name|HandleResourceChange
parameter_list|(
name|TInt
name|aType
parameter_list|)
function_decl|;
name|private
label|:
comment|// Functions from base classes
comment|/**         * From CCoeControl.         */
name|void
name|SizeChanged
parameter_list|()
function_decl|;
comment|/**         * From CCoeControl.         */
name|TInt
name|CountComponentControls
argument_list|()
specifier|const
expr_stmt|;
comment|/**         * From CCoeControl.         */
name|CCoeControl
modifier|*
name|ComponentControl
argument_list|(
name|TInt
name|aIndex
argument_list|)
decl|const
decl_stmt|;
comment|/**         * From CCoeControl.         */
name|void
name|Draw
argument_list|(
specifier|const
name|TRect
operator|&
name|aRect
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|// Functions from base classes
comment|/**         * From MCoeControlObserver.         */
name|void
name|HandleControlEventL
parameter_list|(
name|CCoeControl
modifier|*
name|aControl
parameter_list|,
name|TCoeEvent
name|aEventType
parameter_list|)
function_decl|;
name|private
label|:
comment|// Data
comment|// Texts.
name|CDesCArray
modifier|*
name|iTexts
decl_stmt|;
comment|// Count.
name|TInt
name|iCount
decl_stmt|;
comment|// Listbox.
name|CAknSingleStyleListBox
modifier|*
name|iListbox
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/** *  CPixelMetricsMapperView * * *  @since 1.0 */
end_comment
begin_decl_stmt
name|class
name|CPixelMetricsMapperView
range|:
name|public
name|CAknView
block|{
name|public
operator|:
comment|// Constructors and destructor
comment|/**         * Symbian 2nd phase constructor.         */
name|void
name|ConstructL
argument_list|()
block|;
comment|/**         * Destructor.         */
operator|~
name|CPixelMetricsMapperView
argument_list|()
block|;
name|public
operator|:
comment|// Functions from base classes
comment|/**         * From CAknView.         */
name|TUid
name|Id
argument_list|()
specifier|const
block|;
comment|/**         * From CAknView.         */
name|void
name|HandleCommandL
argument_list|(
argument|TInt aCommand
argument_list|)
block|;
comment|/**         * From CAknView.         */
name|void
name|HandleStatusPaneSizeChange
argument_list|()
block|;
comment|/**         * From CAknView.         */
name|void
name|ShowL
argument_list|(
specifier|const
name|TDesC
operator|&
name|aString
argument_list|,
name|TBool
operator|&
name|aLast
argument_list|,
specifier|const
name|TBool
operator|&
name|aFileOutput
operator|=
name|EFalse
argument_list|)
block|;
name|void
name|ClearL
argument_list|()
block|;
name|private
operator|:
comment|// from CAknView
comment|/**         * From CAknView.         */
name|void
name|DoActivateL
argument_list|(
argument|const TVwsViewId& aPrevViewId
argument_list|,
argument|TUid aCustomMessageId
argument_list|,
argument|const TDesC8& aCustomMessage
argument_list|)
block|;
comment|/**         * From CAknView.         */
name|void
name|DoDeactivate
argument_list|()
block|;
name|private
operator|:
comment|// Data
comment|// The view container.
name|CPixelMetricsMapperViewContainer
operator|*
name|iView
block|;      }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PMMAPPERVIEW_H
end_comment
begin_comment
comment|// End of File
end_comment
end_unit
