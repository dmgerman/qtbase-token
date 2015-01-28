begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpdfwriter.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PDF
end_ifndef
begin_include
include|#
directive|include
file|"qpagedpaintdevice_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|"private/qpdf_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QPdfWriterPrivate
class|class
name|QPdfWriterPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
DECL|function|QPdfWriterPrivate
name|QPdfWriterPrivate
parameter_list|()
member_init_list|:
name|QObjectPrivate
argument_list|()
block|{
name|engine
operator|=
operator|new
name|QPdfEngine
argument_list|()
expr_stmt|;
name|output
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|~QPdfWriterPrivate
name|~
name|QPdfWriterPrivate
parameter_list|()
block|{
operator|delete
name|engine
expr_stmt|;
operator|delete
name|output
expr_stmt|;
block|}
DECL|member|engine
name|QPdfEngine
modifier|*
name|engine
decl_stmt|;
DECL|member|output
name|QFile
modifier|*
name|output
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|QPdfPagedPaintDevicePrivate
class|class
name|QPdfPagedPaintDevicePrivate
super|:
specifier|public
name|QPagedPaintDevicePrivate
block|{
public|public:
DECL|function|QPdfPagedPaintDevicePrivate
name|QPdfPagedPaintDevicePrivate
parameter_list|(
name|QPdfWriterPrivate
modifier|*
name|d
parameter_list|)
member_init_list|:
name|QPagedPaintDevicePrivate
argument_list|()
member_init_list|,
name|pd
argument_list|(
name|d
argument_list|)
block|{}
DECL|function|~QPdfPagedPaintDevicePrivate
specifier|virtual
name|~
name|QPdfPagedPaintDevicePrivate
parameter_list|()
block|{}
name|bool
name|setPageLayout
parameter_list|(
specifier|const
name|QPageLayout
modifier|&
name|newPageLayout
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
comment|// Try to set the paint engine page layout
name|pd
operator|->
name|engine
operator|->
name|setPageLayout
argument_list|(
name|newPageLayout
argument_list|)
expr_stmt|;
comment|// Set QPagedPaintDevice layout to match the current paint engine layout
name|m_pageLayout
operator|=
name|pd
operator|->
name|engine
operator|->
name|pageLayout
argument_list|()
expr_stmt|;
return|return
name|m_pageLayout
operator|.
name|isEquivalentTo
argument_list|(
name|newPageLayout
argument_list|)
return|;
block|}
name|bool
name|setPageSize
parameter_list|(
specifier|const
name|QPageSize
modifier|&
name|pageSize
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
comment|// Try to set the paint engine page size
name|pd
operator|->
name|engine
operator|->
name|setPageSize
argument_list|(
name|pageSize
argument_list|)
expr_stmt|;
comment|// Set QPagedPaintDevice layout to match the current paint engine layout
name|m_pageLayout
operator|=
name|pd
operator|->
name|engine
operator|->
name|pageLayout
argument_list|()
expr_stmt|;
return|return
name|m_pageLayout
operator|.
name|pageSize
argument_list|()
operator|.
name|isEquivalentTo
argument_list|(
name|pageSize
argument_list|)
return|;
block|}
name|bool
name|setPageOrientation
parameter_list|(
name|QPageLayout
operator|::
name|Orientation
name|orientation
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
comment|// Set the print engine value
name|pd
operator|->
name|engine
operator|->
name|setPageOrientation
argument_list|(
name|orientation
argument_list|)
expr_stmt|;
comment|// Set QPagedPaintDevice layout to match the current paint engine layout
name|m_pageLayout
operator|=
name|pd
operator|->
name|engine
operator|->
name|pageLayout
argument_list|()
expr_stmt|;
return|return
name|m_pageLayout
operator|.
name|orientation
argument_list|()
operator|==
name|orientation
return|;
block|}
name|bool
name|setPageMargins
parameter_list|(
specifier|const
name|QMarginsF
modifier|&
name|margins
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
return|return
name|setPageMargins
argument_list|(
name|margins
argument_list|,
name|pageLayout
argument_list|()
operator|.
name|units
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|setPageMargins
parameter_list|(
specifier|const
name|QMarginsF
modifier|&
name|margins
parameter_list|,
name|QPageLayout
operator|::
name|Unit
name|units
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
comment|// Try to set engine margins
name|pd
operator|->
name|engine
operator|->
name|setPageMargins
argument_list|(
name|margins
argument_list|,
name|units
argument_list|)
expr_stmt|;
comment|// Set QPagedPaintDevice layout to match the current paint engine layout
name|m_pageLayout
operator|=
name|pd
operator|->
name|engine
operator|->
name|pageLayout
argument_list|()
expr_stmt|;
return|return
name|m_pageLayout
operator|.
name|margins
argument_list|()
operator|==
name|margins
operator|&&
name|m_pageLayout
operator|.
name|units
argument_list|()
operator|==
name|units
return|;
block|}
name|QPageLayout
name|pageLayout
parameter_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|pd
operator|->
name|engine
operator|->
name|pageLayout
argument_list|()
return|;
block|}
DECL|member|pd
name|QPdfWriterPrivate
modifier|*
name|pd
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*! \class QPdfWriter     \inmodule QtGui      \brief The QPdfWriter class is a class to generate PDFs     that can be used as a paint device.      \ingroup painting      QPdfWriter generates PDF out of a series of drawing commands using QPainter.     The newPage() method can be used to create several pages.   */
end_comment
begin_comment
comment|/*!   Constructs a PDF writer that will write the pdf to \a filename.   */
end_comment
begin_constructor
DECL|function|QPdfWriter
name|QPdfWriter
operator|::
name|QPdfWriter
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QPdfWriterPrivate
argument_list|)
member_init_list|,
name|QPagedPaintDevice
argument_list|(
operator|new
name|QPdfPagedPaintDevicePrivate
argument_list|(
name|d_func
argument_list|()
argument_list|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|setOutputFilename
argument_list|(
name|filename
argument_list|)
expr_stmt|;
comment|// Set QPagedPaintDevice layout to match the current paint engine layout
name|devicePageLayout
argument_list|()
operator|=
name|d
operator|->
name|engine
operator|->
name|pageLayout
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Constructs a PDF writer that will write the pdf to \a device.   */
end_comment
begin_constructor
DECL|function|QPdfWriter
name|QPdfWriter
operator|::
name|QPdfWriter
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QPdfWriterPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|outDevice
operator|=
name|device
expr_stmt|;
comment|// Set QPagedPaintDevice layout to match the current paint engine layout
name|devicePageLayout
argument_list|()
operator|=
name|d
operator|->
name|engine
operator|->
name|pageLayout
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys the pdf writer.   */
end_comment
begin_destructor
DECL|function|~QPdfWriter
name|QPdfWriter
operator|::
name|~
name|QPdfWriter
parameter_list|()
block|{  }
end_destructor
begin_comment
comment|/*!   Returns the title of the document.   */
end_comment
begin_function
DECL|function|title
name|QString
name|QPdfWriter
operator|::
name|title
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|title
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the title of the document being created to \a title.   */
end_comment
begin_function
DECL|function|setTitle
name|void
name|QPdfWriter
operator|::
name|setTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|title
operator|=
name|title
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the creator of the document.   */
end_comment
begin_function
DECL|function|creator
name|QString
name|QPdfWriter
operator|::
name|creator
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|creator
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the creator of the document to \a creator.   */
end_comment
begin_function
DECL|function|setCreator
name|void
name|QPdfWriter
operator|::
name|setCreator
parameter_list|(
specifier|const
name|QString
modifier|&
name|creator
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|->
name|d_func
argument_list|()
operator|->
name|creator
operator|=
name|creator
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp   */
end_comment
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QPdfWriter
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Sets the PDF \a resolution in DPI.      This setting affects the coordinate system as returned by, for     example QPainter::viewport().      \sa resolution() */
end_comment
begin_function
DECL|function|setResolution
name|void
name|QPdfWriter
operator|::
name|setResolution
parameter_list|(
name|int
name|resolution
parameter_list|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
if|if
condition|(
name|resolution
operator|>
literal|0
condition|)
name|d
operator|->
name|engine
operator|->
name|setResolution
argument_list|(
name|resolution
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 5.3      Returns the resolution of the PDF in DPI.      \sa setResolution() */
end_comment
begin_function
DECL|function|resolution
name|int
name|QPdfWriter
operator|::
name|resolution
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|resolution
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Defined in QPagedPaintDevice but non-virtual, add QPdfWriter specific doc here
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_QDOC
end_ifdef
begin_comment
comment|/*!     \fn bool QPdfWriter::setPageLayout(const QPageLayout&newPageLayout)     \since 5.3      Sets the PDF page layout to \a newPageLayout.      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new page layout to a new page.     You should not call any painting methods between a call to setPageLayout()     and newPage() as the wrong paint metrics may be used.      Returns true if the page layout was successfully set to \a newPageLayout.      \sa pageLayout() */
end_comment
begin_comment
comment|/*!     \fn bool QPdfWriter::setPageSize(const QPageSize&pageSize)     \since 5.3      Sets the PDF page size to \a pageSize.      To get the current QPageSize use pageLayout().pageSize().      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new page size to a new page.     You should not call any painting methods between a call to setPageSize()     and newPage() as the wrong paint metrics may be used.      Returns true if the page size was successfully set to \a pageSize.      \sa pageLayout() */
end_comment
begin_comment
comment|/*!     \fn bool QPdfWriter::setPageOrientation(QPageLayout::Orientation orientation)     \since 5.3      Sets the PDF page \a orientation.      The page orientation is used to define the orientation of the     page size when obtaining the page rect.      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new orientation to a new page.     You should not call any painting methods between a call to setPageOrientation()     and newPage() as the wrong paint metrics may be used.      To get the current QPageLayout::Orientation use pageLayout().pageOrientation().      Returns true if the page orientation was successfully set to \a orientation.      \sa pageLayout() */
end_comment
begin_comment
comment|/*!     \fn bool QPdfWriter::setPageMargins(const QMarginsF&margins)     \since 5.3      Set the PDF page \a margins in the current page layout units.      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new margins to a new page.     You should not call any painting methods between a call to setPageMargins()     and newPage() as the wrong paint metrics may be used.      To get the current page margins use pageLayout().pageMargins().      Returns true if the page margins were successfully set to \a margins.      \sa pageLayout() */
end_comment
begin_comment
comment|/*!     \fn bool QPdfWriter::setPageMargins(const QMarginsF&margins, QPageLayout::Unit units)     \since 5.3      Set the PDF page \a margins defined in the given \a units.      You should call this before calling QPainter::begin(), or immediately     before calling newPage() to apply the new margins to a new page.     You should not call any painting methods between a call to setPageMargins()     and newPage() as the wrong paint metrics may be used.      To get the current page margins use pageLayout().pageMargins().      Returns true if the page margins were successfully set to \a margins.      \sa pageLayout() */
end_comment
begin_comment
comment|/*!     \fn QPageLayout QPdfWriter::pageLayout() const     \since 5.3      Returns the current page layout.  Use this method to access the current     QPageSize, QPageLayout::Orientation, QMarginsF, fullRect() and paintRect().      Note that you cannot use the setters on the returned object, you must either     call the individual QPdfWriter methods or use setPageLayout().      \sa setPageLayout(), setPageSize(), setPageOrientation(), setPageMargins() */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \reimp      \obsolete Use setPageSize(QPageSize(id)) instead      \sa setPageSize() */
end_comment
begin_function
DECL|function|setPageSize
name|void
name|QPdfWriter
operator|::
name|setPageSize
parameter_list|(
name|PageSize
name|size
parameter_list|)
block|{
name|setPageSize
argument_list|(
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|PageSizeId
argument_list|(
name|size
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp      \obsolete Use setPageSize(QPageSize(size, QPageSize::Millimeter)) instead      \sa setPageSize() */
end_comment
begin_function
DECL|function|setPageSizeMM
name|void
name|QPdfWriter
operator|::
name|setPageSizeMM
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|size
parameter_list|)
block|{
name|setPageSize
argument_list|(
name|QPageSize
argument_list|(
name|size
argument_list|,
name|QPageSize
operator|::
name|Millimeter
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal      Returns the metric for the given \a id. */
end_comment
begin_function
DECL|function|metric
name|int
name|QPdfWriter
operator|::
name|metric
parameter_list|(
name|PaintDeviceMetric
name|id
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|metric
argument_list|(
name|id
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|newPage
name|bool
name|QPdfWriter
operator|::
name|newPage
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPdfWriter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|->
name|newPage
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp      \obsolete Use setPageMargins(QMarginsF(l, t, r, b), QPageLayout::Millimeter) instead      \sa setPageMargins()   */
end_comment
begin_function
DECL|function|setMargins
name|void
name|QPdfWriter
operator|::
name|setMargins
parameter_list|(
specifier|const
name|Margins
modifier|&
name|m
parameter_list|)
block|{
name|setPageMargins
argument_list|(
name|QMarginsF
argument_list|(
name|m
operator|.
name|left
argument_list|,
name|m
operator|.
name|top
argument_list|,
name|m
operator|.
name|right
argument_list|,
name|m
operator|.
name|bottom
argument_list|)
argument_list|,
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PDF
end_comment
end_unit
