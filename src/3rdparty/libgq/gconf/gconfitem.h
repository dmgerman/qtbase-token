begin_unit
begin_comment
comment|/* * This file is part of libgq *  *  * Copyright (C) 2009 Nokia Corporation.  *  * Contact: Marius Vollmer<marius.vollmer@nokia.com>  *  * This library is free software; you can redistribute it and/or  * modify it under the terms of the GNU Lesser General Public License  * version 2.1 as published by the Free Software Foundation.  *  * This library is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  * Lesser General Public License for more details.  *  * You should have received a copy of the GNU Lesser General Public  * License along with this library; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  * 02110-1301 USA  *  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GCONFITEM_H
end_ifndef
begin_define
DECL|macro|GCONFITEM_H
define|#
directive|define
name|GCONFITEM_H
end_define
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_comment
comment|/*!    \brief GConfItem is a simple C++ wrapper for GConf.    Creating a GConfItem instance gives you access to a single GConf   key.  You can get and set its value, and connect to its   valueChanged() signal to be notified about changes.    The value of a GConf key is returned to you as a QVariant, and you   pass in a QVariant when setting the value.  GConfItem converts   between a QVariant and GConf values as needed, and according to the   following rules:    - A QVariant of type QVariant::Invalid denotes an unset GConf key.    - QVariant::Int, QVariant::Double, QVariant::Bool are converted to     and from the obvious equivalents.    - QVariant::String is converted to/from a GConf string and always     uses the UTF-8 encoding.  No other encoding is supported.    - QVariant::StringList is converted to a list of UTF-8 strings.    - QVariant::List (which denotes a QList<QVariant>) is converted     to/from a GConf list.  All elements of such a list must have the     same type, and that type must be one of QVariant::Int,     QVariant::Double, QVariant::Bool, or QVariant::String.  (A list of     strings is returned as a QVariant::StringList, however, when you     get it back.)    - Any other QVariant or GConf value is essentially ignored.    \warning GConfItem is as thread-safe as GConf.  */
end_comment
begin_decl_stmt
name|class
name|GConfItem
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
comment|/*! Initializes a GConfItem to access the GConf key denoted by         \a key.  Key names should follow the normal GConf conventions         like "/myapp/settings/first".          \param key    The name of the key.         \param parent Parent object     */
name|explicit
name|GConfItem
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
comment|/*! Finalizes a GConfItem.      */
name|virtual
operator|~
name|GConfItem
argument_list|()
block|;
comment|/*! Returns the key of this item, as given to the constructor.      */
name|QString
name|key
argument_list|()
specifier|const
block|;
comment|/*! Returns the current value of this item, as a QVariant.      */
name|QVariant
name|value
argument_list|()
specifier|const
block|;
comment|/*! Returns the current value of this item, as a QVariant.  If      *  there is no value for this item, return \a def instead.      */
name|QVariant
name|value
argument_list|(
argument|const QVariant&def
argument_list|)
specifier|const
block|;
comment|/*! Set the value of this item to \a val.  If \a val can not be         represented in GConf or GConf refuses to accept it for other         reasons, the current value is not changed and nothing happens.          When the new value is different from the old value, the         changedValue() signal is emitted on this GConfItem as part         of calling set(), but other GConfItem:s for the same key do         only receive a notification once the main loop runs.          \param val  The new value.     */
name|void
name|set
argument_list|(
specifier|const
name|QVariant
operator|&
name|val
argument_list|)
block|;
comment|/*! Unset this item.  This is equivalent to          \code         item.set(QVariant(QVariant::Invalid));         \endcode      */
name|void
name|unset
argument_list|()
block|;
comment|/*! Return a list of the directories below this item.  The         returned strings are absolute key names like         "/myapp/settings".          A directory is a key that has children.  The same key might         also have a value, but that is confusing and best avoided.     */
name|QList
operator|<
name|QString
operator|>
name|listDirs
argument_list|()
specifier|const
block|;
comment|/*! Return a list of entries below this item.  The returned         strings are absolute key names like "/myapp/settings/first".          A entry is a key that has a value.  The same key might also         have children, but that is confusing and is best avoided.     */
name|QList
operator|<
name|QString
operator|>
name|listEntries
argument_list|()
specifier|const
block|;
name|signals
operator|:
comment|/*! Emitted when the value of this item has changed.      */
name|void
name|valueChanged
argument_list|()
block|;
name|private
operator|:
name|friend
expr|struct
name|GConfItemPrivate
block|;     struct
name|GConfItemPrivate
operator|*
name|priv
block|;
name|void
name|update_value
argument_list|(
argument|bool emit_signal
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// GCONFITEM_H
end_comment
end_unit
