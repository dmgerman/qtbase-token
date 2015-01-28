begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
