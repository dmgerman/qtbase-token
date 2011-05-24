begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QT_NO_KEYWORDS
define|#
directive|define
name|QT_NO_KEYWORDS
end_define
begin_define
DECL|macro|signals
define|#
directive|define
name|signals
value|int
end_define
begin_define
DECL|macro|slots
define|#
directive|define
name|slots
value|int
end_define
begin_define
DECL|macro|emit
define|#
directive|define
name|emit
value|public:;
end_define
begin_define
DECL|macro|foreach
define|#
directive|define
name|foreach
value|public:;
end_define
begin_define
DECL|macro|forever
define|#
directive|define
name|forever
value|public:;
end_define
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/QtNetwork>
end_include
begin_include
include|#
directive|include
file|<QtXml/QtXml>
end_include
begin_include
include|#
directive|include
file|<QtSql/QtSql>
end_include
begin_include
include|#
directive|include
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<QtUiTools/QtUiTools>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtOpenGL/QtOpenGL>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DBUS
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENVG
end_ifndef
begin_include
include|#
directive|include
file|<QtOpenVG/QtOpenVG>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_HeadersClean
class|class
name|tst_HeadersClean
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_HeadersClean
name|tst_HeadersClean
parameter_list|()
block|{}
block|}
class|;
end_class
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_HeadersClean
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_headersclean.moc"
end_include
end_unit
