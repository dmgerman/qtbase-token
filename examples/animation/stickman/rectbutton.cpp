begin_unit
begin_include
include|#
directive|include
file|"rectbutton.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_constructor
DECL|function|RectButton
name|RectButton
operator|::
name|RectButton
parameter_list|(
name|QString
name|buttonText
parameter_list|)
member_init_list|:
name|m_ButtonText
argument_list|(
name|buttonText
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~RectButton
name|RectButton
operator|::
name|~
name|RectButton
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|mousePressEvent
name|void
name|RectButton
operator|::
name|mousePressEvent
parameter_list|(
name|QGraphicsSceneMouseEvent
modifier|*
name|event
parameter_list|)
block|{
emit|emit
name|clicked
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|QRectF
name|RectButton
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|90.0
argument_list|,
literal|40.0
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paint
name|void
name|RectButton
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|painter
operator|->
name|setBrush
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundedRect
argument_list|(
name|boundingRect
argument_list|()
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
literal|20
argument_list|,
literal|25
argument_list|,
name|m_ButtonText
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
