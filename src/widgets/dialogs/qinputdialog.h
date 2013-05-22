begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QINPUTDIALOG_H
end_ifndef
begin_define
DECL|macro|QINPUTDIALOG_H
define|#
directive|define
name|QINPUTDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qdialog.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qlineedit.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_INPUTDIALOG
DECL|variable|QInputDialogPrivate
name|class
name|QInputDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QInputDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QInputDialog
argument_list|)
comment|//  Q_ENUMS(InputMode InputDialogOption)
name|QDOC_PROPERTY
argument_list|(
argument|InputMode inputMode READ inputMode WRITE setInputMode
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QString labelText READ labelText WRITE setLabelText
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|InputDialogOptions options READ options WRITE setOptions
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QString textValue READ textValue WRITE setTextValue NOTIFY textValueChanged
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int intValue READ intValue WRITE setIntValue NOTIFY intValueChanged
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int doubleValue READ doubleValue WRITE setDoubleValue NOTIFY doubleValueChanged
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QLineEdit::EchoMode textEchoMode READ textEchoMode WRITE setTextEchoMode
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|bool comboBoxEditable READ isComboBoxEditable WRITE setComboBoxEditable
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QStringList comboBoxItems READ comboBoxItems WRITE setComboBoxItems
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int intMinimum READ intMinimum WRITE setIntMinimum
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int intMaximum READ intMaximum WRITE setIntMaximum
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int intStep READ intStep WRITE setIntStep
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|double doubleMinimum READ doubleMinimum WRITE setDoubleMinimum
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|double doubleMaximum READ doubleMaximum WRITE setDoubleMaximum
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int doubleDecimals READ doubleDecimals WRITE setDoubleDecimals
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QString okButtonText READ okButtonText WRITE setOkButtonText
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|QString cancelButtonText READ cancelButtonText WRITE setCancelButtonText
argument_list|)
name|public
operator|:
expr|enum
name|InputDialogOption
block|{
name|NoButtons
operator|=
literal|0x00000001
block|,
name|UseListViewForComboBoxItems
operator|=
literal|0x00000002
block|,
name|UsePlainTextEditForTextInput
operator|=
literal|0x00000004
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
name|InputDialogOptions
argument_list|,
name|InputDialogOption
argument_list|)
expr|enum
name|InputMode
block|{
name|TextInput
block|,
name|IntInput
block|,
name|DoubleInput
block|}
block|;
name|QInputDialog
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
operator|~
name|QInputDialog
argument_list|()
block|;
name|void
name|setInputMode
argument_list|(
argument|InputMode mode
argument_list|)
block|;
name|InputMode
name|inputMode
argument_list|()
specifier|const
block|;
name|void
name|setLabelText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QString
name|labelText
argument_list|()
specifier|const
block|;
name|void
name|setOption
argument_list|(
argument|InputDialogOption option
argument_list|,
argument|bool on = true
argument_list|)
block|;
name|bool
name|testOption
argument_list|(
argument|InputDialogOption option
argument_list|)
specifier|const
block|;
name|void
name|setOptions
argument_list|(
argument|InputDialogOptions options
argument_list|)
block|;
name|InputDialogOptions
name|options
argument_list|()
specifier|const
block|;
name|void
name|setTextValue
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QString
name|textValue
argument_list|()
specifier|const
block|;
name|void
name|setTextEchoMode
argument_list|(
argument|QLineEdit::EchoMode mode
argument_list|)
block|;
name|QLineEdit
operator|::
name|EchoMode
name|textEchoMode
argument_list|()
specifier|const
block|;
name|void
name|setComboBoxEditable
argument_list|(
argument|bool editable
argument_list|)
block|;
name|bool
name|isComboBoxEditable
argument_list|()
specifier|const
block|;
name|void
name|setComboBoxItems
argument_list|(
specifier|const
name|QStringList
operator|&
name|items
argument_list|)
block|;
name|QStringList
name|comboBoxItems
argument_list|()
specifier|const
block|;
name|void
name|setIntValue
argument_list|(
argument|int value
argument_list|)
block|;
name|int
name|intValue
argument_list|()
specifier|const
block|;
name|void
name|setIntMinimum
argument_list|(
argument|int min
argument_list|)
block|;
name|int
name|intMinimum
argument_list|()
specifier|const
block|;
name|void
name|setIntMaximum
argument_list|(
argument|int max
argument_list|)
block|;
name|int
name|intMaximum
argument_list|()
specifier|const
block|;
name|void
name|setIntRange
argument_list|(
argument|int min
argument_list|,
argument|int max
argument_list|)
block|;
name|void
name|setIntStep
argument_list|(
argument|int step
argument_list|)
block|;
name|int
name|intStep
argument_list|()
specifier|const
block|;
name|void
name|setDoubleValue
argument_list|(
argument|double value
argument_list|)
block|;
name|double
name|doubleValue
argument_list|()
specifier|const
block|;
name|void
name|setDoubleMinimum
argument_list|(
argument|double min
argument_list|)
block|;
name|double
name|doubleMinimum
argument_list|()
specifier|const
block|;
name|void
name|setDoubleMaximum
argument_list|(
argument|double max
argument_list|)
block|;
name|double
name|doubleMaximum
argument_list|()
specifier|const
block|;
name|void
name|setDoubleRange
argument_list|(
argument|double min
argument_list|,
argument|double max
argument_list|)
block|;
name|void
name|setDoubleDecimals
argument_list|(
argument|int decimals
argument_list|)
block|;
name|int
name|doubleDecimals
argument_list|()
specifier|const
block|;
name|void
name|setOkButtonText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QString
name|okButtonText
argument_list|()
specifier|const
block|;
name|void
name|setCancelButtonText
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QString
name|cancelButtonText
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
ifndef|#
directive|ifndef
name|Q_QDOC
name|void
name|open
argument_list|()
block|{
name|QDialog
operator|::
name|open
argument_list|()
block|; }
endif|#
directive|endif
else|#
directive|else
name|using
name|QDialog
operator|::
name|open
block|;
endif|#
directive|endif
name|void
name|open
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|QSize
name|minimumSizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
specifier|static
name|QString
name|getText
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|const QString&label
argument_list|,
argument|QLineEdit::EchoMode echo = QLineEdit::Normal
argument_list|,
argument|const QString&text = QString()
argument_list|,
argument|bool *ok =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|,
argument|Qt::InputMethodHints inputMethodHints = Qt::ImhNone
argument_list|)
block|;
specifier|static
name|QString
name|getMultiLineText
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|const QString&label
argument_list|,
argument|const QString&text = QString()
argument_list|,
argument|bool *ok =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|,
argument|Qt::InputMethodHints inputMethodHints = Qt::ImhNone
argument_list|)
block|;
specifier|static
name|QString
name|getItem
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|const QString&label
argument_list|,
argument|const QStringList&items
argument_list|,
argument|int current =
literal|0
argument_list|,
argument|bool editable = true
argument_list|,
argument|bool *ok =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|,
argument|Qt::InputMethodHints inputMethodHints = Qt::ImhNone
argument_list|)
block|;
specifier|static
name|int
name|getInt
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|const QString&label
argument_list|,
argument|int value =
literal|0
argument_list|,
argument|int minValue = -
literal|2147483647
argument_list|,
argument|int maxValue =
literal|2147483647
argument_list|,
argument|int step =
literal|1
argument_list|,
argument|bool *ok =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
specifier|static
name|double
name|getDouble
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|const QString&label
argument_list|,
argument|double value =
literal|0
argument_list|,
argument|double minValue = -
literal|2147483647
argument_list|,
argument|double maxValue =
literal|2147483647
argument_list|,
argument|int decimals =
literal|1
argument_list|,
argument|bool *ok =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|static
specifier|inline
name|int
name|getInteger
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QString&title
argument_list|,
argument|const QString&label
argument_list|,
argument|int value =
literal|0
argument_list|,
argument|int minValue = -
literal|2147483647
argument_list|,
argument|int maxValue =
literal|2147483647
argument_list|,
argument|int step =
literal|1
argument_list|,
argument|bool *ok =
literal|0
argument_list|,
argument|Qt::WindowFlags flags =
literal|0
argument_list|)
block|{
return|return
name|getInt
argument_list|(
name|parent
argument_list|,
name|title
argument_list|,
name|label
argument_list|,
name|value
argument_list|,
name|minValue
argument_list|,
name|maxValue
argument_list|,
name|step
argument_list|,
name|ok
argument_list|,
name|flags
argument_list|)
return|;
block|}
endif|#
directive|endif
name|Q_SIGNALS
operator|:
comment|// ### emit signals!
name|void
name|textValueChanged
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|textValueSelected
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|intValueChanged
argument_list|(
argument|int value
argument_list|)
block|;
name|void
name|intValueSelected
argument_list|(
argument|int value
argument_list|)
block|;
name|void
name|doubleValueChanged
argument_list|(
argument|double value
argument_list|)
block|;
name|void
name|doubleValueSelected
argument_list|(
argument|double value
argument_list|)
block|;
name|public
operator|:
name|void
name|done
argument_list|(
argument|int result
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QInputDialog
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_textChanged(const QString&)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_plainTextEditTextChanged()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_currentRowChanged(const QModelIndex&, const QModelIndex&)
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QInputDialog::InputDialogOptions
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_INPUTDIALOG
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QINPUTDIALOG_H
end_comment
end_unit
