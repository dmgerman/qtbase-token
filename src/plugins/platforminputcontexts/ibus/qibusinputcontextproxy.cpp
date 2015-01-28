begin_unit
begin_comment
comment|/*  * This file was generated by qdbusxml2cpp version 0.8  * Command line was: qdbusxml2cpp -N -p qibusinputcontextproxy -c QIBusInputContextProxy interfaces/org.freedesktop.IBus.InputContext.xml  *  * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.  *  * This is an auto-generated file.  * This file may have been hand-edited. Look for HAND-EDIT comments  * before re-generating it.  */
end_comment
begin_include
include|#
directive|include
file|"qibusinputcontextproxy.h"
end_include
begin_comment
comment|/*  * Implementation of interface class QIBusInputContextProxy  */
end_comment
begin_constructor
DECL|function|QIBusInputContextProxy
name|QIBusInputContextProxy
operator|::
name|QIBusInputContextProxy
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractInterface
argument_list|(
name|service
argument_list|,
name|path
argument_list|,
name|staticInterfaceName
argument_list|()
argument_list|,
name|connection
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QIBusInputContextProxy
name|QIBusInputContextProxy
operator|::
name|~
name|QIBusInputContextProxy
parameter_list|()
block|{ }
end_destructor
end_unit
