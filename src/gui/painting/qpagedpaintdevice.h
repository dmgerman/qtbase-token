begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|QPAGEDPAINTDEVICE_H
end_ifndef
begin_define
DECL|macro|QPAGEDPAINTDEVICE_H
define|#
directive|define
name|QPAGEDPAINTDEVICE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QPagedPaintDevicePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPagedPaintDevice
range|:
name|public
name|QPaintDevice
block|{
name|public
operator|:
name|QPagedPaintDevice
argument_list|()
block|;
operator|~
name|QPagedPaintDevice
argument_list|()
block|;
name|virtual
name|bool
name|newPage
argument_list|()
operator|=
literal|0
block|;      enum
name|PageSize
block|{
name|A4
block|,
name|B5
block|,
name|Letter
block|,
name|Legal
block|,
name|Executive
block|,
name|A0
block|,
name|A1
block|,
name|A2
block|,
name|A3
block|,
name|A5
block|,
name|A6
block|,
name|A7
block|,
name|A8
block|,
name|A9
block|,
name|B0
block|,
name|B1
block|,
name|B10
block|,
name|B2
block|,
name|B3
block|,
name|B4
block|,
name|B6
block|,
name|B7
block|,
name|B8
block|,
name|B9
block|,
name|C5E
block|,
name|Comm10E
block|,
name|DLE
block|,
name|Folio
block|,
name|Ledger
block|,
name|Tabloid
block|,
name|Custom
block|,
name|NPageSize
operator|=
name|Custom
block|}
block|;
name|virtual
name|void
name|setPageSize
argument_list|(
argument|PageSize size
argument_list|)
block|;
name|PageSize
name|pageSize
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setPageSizeMM
argument_list|(
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
block|;
name|QSizeF
name|pageSizeMM
argument_list|()
specifier|const
block|;      struct
name|Margins
block|{
name|qreal
name|left
block|;
name|qreal
name|right
block|;
name|qreal
name|top
block|;
name|qreal
name|bottom
block|;     }
block|;
name|virtual
name|void
name|setMargins
argument_list|(
specifier|const
name|Margins
operator|&
name|margins
argument_list|)
block|;
name|Margins
name|margins
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|friend
name|class
name|QPagedPaintDevicePrivate
block|;
name|QPagedPaintDevicePrivate
operator|*
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
