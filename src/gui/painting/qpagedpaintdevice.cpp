begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpagedpaintdevice_p.h"
end_include
begin_include
include|#
directive|include
file|<qpagedpaintdevice.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
specifier|static
specifier|const
expr|struct
block|{
DECL|member|width
name|float
name|width
block|;
DECL|member|height
name|float
name|height
block|; }
DECL|variable|pageSizes
name|pageSizes
index|[]
operator|=
block|{
block|{
literal|210
block|,
literal|297
block|}
block|,
comment|// A4
block|{
literal|176
block|,
literal|250
block|}
block|,
comment|// B5
block|{
literal|215.9f
block|,
literal|279.4f
block|}
block|,
comment|// Letter
block|{
literal|215.9f
block|,
literal|355.6f
block|}
block|,
comment|// Legal
block|{
literal|190.5f
block|,
literal|254
block|}
block|,
comment|// Executive
block|{
literal|841
block|,
literal|1189
block|}
block|,
comment|// A0
block|{
literal|594
block|,
literal|841
block|}
block|,
comment|// A1
block|{
literal|420
block|,
literal|594
block|}
block|,
comment|// A2
block|{
literal|297
block|,
literal|420
block|}
block|,
comment|// A3
block|{
literal|148
block|,
literal|210
block|}
block|,
comment|// A5
block|{
literal|105
block|,
literal|148
block|}
block|,
comment|// A6
block|{
literal|74
block|,
literal|105
block|}
block|,
comment|// A7
block|{
literal|52
block|,
literal|74
block|}
block|,
comment|// A8
block|{
literal|37
block|,
literal|52
block|}
block|,
comment|// A8
block|{
literal|1000
block|,
literal|1414
block|}
block|,
comment|// B0
block|{
literal|707
block|,
literal|1000
block|}
block|,
comment|// B1
block|{
literal|31
block|,
literal|44
block|}
block|,
comment|// B10
block|{
literal|500
block|,
literal|707
block|}
block|,
comment|// B2
block|{
literal|353
block|,
literal|500
block|}
block|,
comment|// B3
block|{
literal|250
block|,
literal|353
block|}
block|,
comment|// B4
block|{
literal|125
block|,
literal|176
block|}
block|,
comment|// B6
block|{
literal|88
block|,
literal|125
block|}
block|,
comment|// B7
block|{
literal|62
block|,
literal|88
block|}
block|,
comment|// B8
block|{
literal|33
block|,
literal|62
block|}
block|,
comment|// B9
block|{
literal|163
block|,
literal|229
block|}
block|,
comment|// C5E
block|{
literal|105
block|,
literal|241
block|}
block|,
comment|// US Common
block|{
literal|110
block|,
literal|220
block|}
block|,
comment|// DLE
block|{
literal|210
block|,
literal|330
block|}
block|,
comment|// Folio
block|{
literal|431.8f
block|,
literal|279.4f
block|}
block|,
comment|// Ledger
block|{
literal|279.4f
block|,
literal|431.8f
block|}
comment|// Tabloid
block|}
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*!     \class QPagedPaintDevice      \brief The QPagedPaintDevice class is a represents a paintdevice that supports     multiple pages.      \ingroup painting      Paged paint devices are used to generate output for printing or for formats like PDF.     QPdfWriter and QPrinter inherit from it.   */
end_comment
begin_comment
comment|/*!   Constructs a new paged paint device.   */
end_comment
begin_constructor
DECL|function|QPagedPaintDevice
name|QPagedPaintDevice
operator|::
name|QPagedPaintDevice
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QPagedPaintDevicePrivate
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys the object.   */
end_comment
begin_destructor
DECL|function|~QPagedPaintDevice
name|QPagedPaintDevice
operator|::
name|~
name|QPagedPaintDevice
parameter_list|()
block|{
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!   \enum QPagedPaintDevice::PageSize    This enum type specifies the page size of the paint device.    \value A0 841 x 1189 mm   \value A1 594 x 841 mm   \value A2 420 x 594 mm   \value A3 297 x 420 mm   \value A4 210 x 297 mm, 8.26 x 11.69 inches   \value A5 148 x 210 mm   \value A6 105 x 148 mm   \value A7 74 x 105 mm   \value A8 52 x 74 mm   \value A9 37 x 52 mm   \value B0 1000 x 1414 mm   \value B1 707 x 1000 mm   \value B2 500 x 707 mm   \value B3 353 x 500 mm   \value B4 250 x 353 mm   \value B5 176 x 250 mm, 6.93 x 9.84 inches   \value B6 125 x 176 mm   \value B7 88 x 125 mm   \value B8 62 x 88 mm   \value B9 33 x 62 mm   \value B10 31 x 44 mm   \value C5E 163 x 229 mm   \value Comm10E 105 x 241 mm, U.S. Common 10 Envelope   \value DLE 110 x 220 mm   \value Executive 7.5 x 10 inches, 190.5 x 254 mm   \value Folio 210 x 330 mm   \value Ledger 431.8 x 279.4 mm   \value Legal 8.5 x 14 inches, 215.9 x 355.6 mm   \value Letter 8.5 x 11 inches, 215.9 x 279.4 mm   \value Tabloid 279.4 x 431.8 mm   \value Custom Unknown, or a user defined size.    \omitvalue NPageSize    The page size can also be specified in millimeters using setPageSizeMM(). In this case the   page size enum is set to Custom. */
end_comment
begin_comment
comment|/*!   \fn bool QPagedPaintDevice::newPage()    Starts a new page. */
end_comment
begin_comment
comment|/*!   Sets the size of the a page to \a size.    \sa setPageSizeMM   */
end_comment
begin_function
DECL|function|setPageSize
name|void
name|QPagedPaintDevice
operator|::
name|setPageSize
parameter_list|(
name|PageSize
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|>=
name|Custom
condition|)
return|return;
name|d
operator|->
name|pageSize
operator|=
name|size
expr_stmt|;
name|d
operator|->
name|pageSizeMM
operator|=
name|QSizeF
argument_list|(
name|pageSizes
index|[
name|A4
index|]
operator|.
name|width
argument_list|,
name|pageSizes
index|[
name|A4
index|]
operator|.
name|height
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the currently used page size.   */
end_comment
begin_function
DECL|function|pageSize
name|QPagedPaintDevice
operator|::
name|PageSize
name|QPagedPaintDevice
operator|::
name|pageSize
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|pageSize
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the page size to \a size. \a size is specified in millimeters.   */
end_comment
begin_function
DECL|function|setPageSizeMM
name|void
name|QPagedPaintDevice
operator|::
name|setPageSizeMM
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
block|{
name|d
operator|->
name|pageSize
operator|=
name|Custom
expr_stmt|;
name|d
operator|->
name|pageSizeMM
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the page size in millimeters.   */
end_comment
begin_function
DECL|function|pageSizeMM
name|QSizeF
name|QPagedPaintDevice
operator|::
name|pageSizeMM
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|pageSizeMM
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the margins to be used to \a margins.    Margins are specified in millimeters.    The margins are purely a hint to the drawing method. They don't affect the   coordinate system or clipping.    \sa margins   */
end_comment
begin_function
DECL|function|setMargins
name|void
name|QPagedPaintDevice
operator|::
name|setMargins
parameter_list|(
specifier|const
name|Margins
modifier|&
name|margins
parameter_list|)
block|{
name|d
operator|->
name|margins
operator|=
name|margins
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   returns the current margins of the paint device. The default is 0.    /sa setMargins   */
end_comment
begin_function
DECL|function|margins
name|QPagedPaintDevice
operator|::
name|Margins
name|QPagedPaintDevice
operator|::
name|margins
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|margins
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
