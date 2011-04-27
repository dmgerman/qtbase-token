begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the utility applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PMMAPPERAPP_H
end_ifndef
begin_define
DECL|macro|PMMAPPERAPP_H
define|#
directive|define
name|PMMAPPERAPP_H
end_define
begin_comment
comment|//  INCLUDES
end_comment
begin_include
include|#
directive|include
file|<eikapp.h>
end_include
begin_include
include|#
directive|include
file|<eikdoc.h>
end_include
begin_include
include|#
directive|include
file|<e32std.h>
end_include
begin_include
include|#
directive|include
file|<aknViewAppUi.h>
end_include
begin_comment
comment|// CONSTANTS
end_comment
begin_decl_stmt
DECL|variable|KUidPMMapperApplication
specifier|const
name|TUid
name|KUidPMMapperApplication
init|=
block|{
literal|0x2002121F
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// FORWARD DECLARATIONS
end_comment
begin_decl_stmt
DECL|variable|CPixelMetricsMapperView
name|class
name|CPixelMetricsMapperView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|MAknsSkinInstance
name|class
name|MAknsSkinInstance
decl_stmt|;
end_decl_stmt
begin_comment
comment|// CLASS DECLARATION
end_comment
begin_comment
comment|/** *  CPixelMetricsMapperDocument */
end_comment
begin_decl_stmt
name|class
name|CPixelMetricsMapperDocument
range|:
name|public
name|CEikDocument
block|{
name|public
operator|:
comment|// Constructors and destructor
comment|/**         * Symbian 2nd phase constructor.         */
name|void
name|ConstructL
argument_list|()
block|;
comment|/**         * Constructor.         */
name|CPixelMetricsMapperDocument
argument_list|(
name|CEikApplication
operator|&
name|aApp
argument_list|)
operator|:
name|CEikDocument
argument_list|(
argument|aApp
argument_list|)
block|{}
comment|/**         * Destructor.         */
operator|~
name|CPixelMetricsMapperDocument
argument_list|()
block|{}
name|public
operator|:
comment|// Functions from base classes
comment|/**         * From CEikDocument.         */
name|CFileStore
operator|*
name|OpenFileL
argument_list|(
argument|TBool
comment|/*aDoOpen*/
argument_list|,
argument|const TDesC&
comment|/*aFilename*/
argument_list|,
argument|RFs&
comment|/*aFs*/
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
name|private
operator|:
comment|// Functions from base classes
comment|/**         * From CEikDocument.         */
name|CEikAppUi
operator|*
name|CreateAppUiL
argument_list|()
block|;     }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/** *  CPixelMetricsMapperAppUi */
end_comment
begin_decl_stmt
name|class
name|CPixelMetricsMapperAppUi
range|:
name|public
name|CAknViewAppUi
block|{
name|public
operator|:
comment|// Constructors and destructor
comment|/**         * Constructor.         */
name|CPixelMetricsMapperAppUi
argument_list|()
block|;
comment|/**         * Symbian 2nd phase constructor.         */
name|void
name|ConstructL
argument_list|()
block|;
comment|/**         * Destructor.         */
operator|~
name|CPixelMetricsMapperAppUi
argument_list|()
block|;
name|private
operator|:
comment|// Functions from base classes
comment|/**         * From CEikAppUi.         */
name|void
name|HandleCommandL
argument_list|(
argument|TInt aCommand
argument_list|)
block|;
comment|/**         * From CEikAppUi.         */
name|virtual
name|TKeyResponse
name|HandleKeyEventL
argument_list|(
argument|const TKeyEvent& aKeyEvent
argument_list|,
argument|TEventCode aType
argument_list|)
block|;
name|private
operator|:
comment|/**         * Shows text given.         */
name|void
name|ShowL
argument_list|(
specifier|const
name|TDesC
operator|&
name|aText
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
name|ShowSingleValueL
argument_list|(
name|TInt
operator|&
name|aPixelMetric
argument_list|,
name|TInt
operator|&
name|aValue
argument_list|,
name|TBool
operator|&
name|aLast
argument_list|)
block|;
name|void
name|ClearL
argument_list|()
block|;
name|void
name|CreateHeaderFileL
argument_list|()
specifier|const
block|;
name|TFileName
name|CreateLayoutNameL
argument_list|(
argument|TFileText& aFileHandle
argument_list|)
specifier|const
block|;
name|private
operator|:
comment|// Data
comment|// Test view.
name|CPixelMetricsMapperView
operator|*
name|iView
block|;
name|CEikDialog
operator|*
name|iDialog
block|;
name|TBool
name|iFileOutputOn
block|;
name|TBool
name|iMode
block|;
name|CFbsBitmap
operator|*
name|icon
block|;
name|CFbsBitmap
operator|*
name|iconMask
block|;      }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/** *  CPixelMetricsMapperApplication */
end_comment
begin_decl_stmt
name|class
name|CPixelMetricsMapperApplication
range|:
name|public
name|CEikApplication
block|{
name|private
operator|:
comment|// Functions from base classes
comment|/**         * From CApaApplication.         */
name|CApaDocument
operator|*
name|CreateDocumentL
argument_list|()
block|;
comment|/**         * From CApaApplication.         */
name|TUid
name|AppDllUid
argument_list|()
specifier|const
block|;     }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// PMMAPPERAPP_H
end_comment
begin_comment
comment|// End of File
end_comment
end_unit
