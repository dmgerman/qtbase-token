begin_unit
begin_comment
comment|/*  * This file was generated by qdbusxml2cpp version 0.8  * Command line was: qdbusxml2cpp -N -p qibusinputcontextproxy -c QIBusInputContextProxy interfaces/org.freedesktop.IBus.InputContext.xml  *  * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.  *  * This is an auto-generated file.  * Do not edit! All changes made to it will be lost.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIBUSINPUTCONTEXTPROXY_H_1394889529
end_ifndef
begin_define
DECL|macro|QIBUSINPUTCONTEXTPROXY_H_1394889529
define|#
directive|define
name|QIBUSINPUTCONTEXTPROXY_H_1394889529
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_comment
comment|/*  * Proxy class for interface org.freedesktop.IBus.InputContext  */
end_comment
begin_decl_stmt
name|class
name|QIBusInputContextProxy
range|:
name|public
name|QDBusAbstractInterface
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
specifier|inline
specifier|const
name|char
operator|*
name|staticInterfaceName
argument_list|()
block|{
return|return
literal|"org.freedesktop.IBus.InputContext"
return|;
block|}
name|public
operator|:
name|QIBusInputContextProxy
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QDBusConnection
operator|&
name|connection
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QIBusInputContextProxy
argument_list|()
block|;
name|public
name|Q_SLOTS
operator|:
comment|// METHODS
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|Destroy
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"Destroy"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|Disable
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"Disable"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|Enable
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"Enable"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|FocusIn
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"FocusIn"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|FocusOut
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"FocusOut"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
name|QDBusVariant
operator|>
name|GetEngine
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"GetEngine"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
name|bool
operator|>
name|IsEnabled
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"IsEnabled"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
name|bool
operator|>
name|ProcessKeyEvent
argument_list|(
argument|uint keyval
argument_list|,
argument|uint keycode
argument_list|,
argument|uint state
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|keyval
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|keycode
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|state
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"ProcessKeyEvent"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|PropertyActivate
argument_list|(
argument|const QString&name
argument_list|,
argument|int state
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|name
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|state
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"PropertyActivate"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|Reset
argument_list|()
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"Reset"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|SetCapabilities
argument_list|(
argument|uint caps
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|caps
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"SetCapabilities"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|SetCursorLocation
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|x
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|y
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|w
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|h
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"SetCursorLocation"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|SetEngine
argument_list|(
argument|const QString&name
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|name
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"SetEngine"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
specifier|inline
name|QDBusPendingReply
operator|<
operator|>
name|SetSurroundingText
argument_list|(
argument|const QDBusVariant&text
argument_list|,
argument|uint cursor_pos
argument_list|,
argument|uint anchor_pos
argument_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|argumentList
block|;
name|argumentList
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|text
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|cursor_pos
argument_list|)
operator|<<
name|QVariant
operator|::
name|fromValue
argument_list|(
name|anchor_pos
argument_list|)
block|;
return|return
name|asyncCallWithArgumentList
argument_list|(
name|QLatin1String
argument_list|(
literal|"SetSurroundingText"
argument_list|)
argument_list|,
name|argumentList
argument_list|)
return|;
block|}
name|Q_SIGNALS
operator|:
comment|// SIGNALS
name|void
name|CommitText
argument_list|(
specifier|const
name|QDBusVariant
operator|&
name|text
argument_list|)
block|;
name|void
name|CursorDownLookupTable
argument_list|()
block|;
name|void
name|CursorUpLookupTable
argument_list|()
block|;
name|void
name|DeleteSurroundingText
argument_list|(
argument|int offset
argument_list|,
argument|uint n_chars
argument_list|)
block|;
name|void
name|Disabled
argument_list|()
block|;
name|void
name|Enabled
argument_list|()
block|;
name|void
name|ForwardKeyEvent
argument_list|(
argument|uint keyval
argument_list|,
argument|uint keycode
argument_list|,
argument|uint state
argument_list|)
block|;
name|void
name|HideAuxiliaryText
argument_list|()
block|;
name|void
name|HideLookupTable
argument_list|()
block|;
name|void
name|HidePreeditText
argument_list|()
block|;
name|void
name|PageDownLookupTable
argument_list|()
block|;
name|void
name|PageUpLookupTable
argument_list|()
block|;
name|void
name|RegisterProperties
argument_list|(
specifier|const
name|QDBusVariant
operator|&
name|props
argument_list|)
block|;
name|void
name|RequireSurroundingText
argument_list|()
block|;
name|void
name|ShowAuxiliaryText
argument_list|()
block|;
name|void
name|ShowLookupTable
argument_list|()
block|;
name|void
name|ShowPreeditText
argument_list|()
block|;
name|void
name|UpdateAuxiliaryText
argument_list|(
argument|const QDBusVariant&text
argument_list|,
argument|bool visible
argument_list|)
block|;
name|void
name|UpdateLookupTable
argument_list|(
argument|const QDBusVariant&table
argument_list|,
argument|bool visible
argument_list|)
block|;
name|void
name|UpdatePreeditText
argument_list|(
argument|const QDBusVariant&text
argument_list|,
argument|uint cursor_pos
argument_list|,
argument|bool visible
argument_list|)
block|;
name|void
name|UpdateProperty
argument_list|(
specifier|const
name|QDBusVariant
operator|&
name|prop
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
