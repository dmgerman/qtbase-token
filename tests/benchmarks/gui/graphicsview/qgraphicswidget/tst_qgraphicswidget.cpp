begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QGraphicsWidget>
end_include
begin_class
DECL|class|tst_QGraphicsWidget
class|class
name|tst_QGraphicsWidget
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QGraphicsWidget
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QGraphicsWidget
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|move
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QGraphicsWidget
name|tst_QGraphicsWidget
operator|::
name|tst_QGraphicsWidget
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QGraphicsWidget
name|tst_QGraphicsWidget
operator|::
name|~
name|tst_QGraphicsWidget
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QGraphicsWidget
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QGraphicsWidget
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|move
name|void
name|tst_QGraphicsWidget
operator|::
name|move
parameter_list|()
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsWidget
modifier|*
name|widget
init|=
operator|new
name|QGraphicsWidget
argument_list|()
decl_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|QBENCHMARK
block|{
name|widget
operator|->
name|setPos
argument_list|(
name|qrand
argument_list|()
argument_list|,
name|qrand
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsWidget
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicswidget.moc"
end_include
end_unit
