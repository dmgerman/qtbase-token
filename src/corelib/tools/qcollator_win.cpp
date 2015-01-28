begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Aleix Pol Gonzalez<aleixpol@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcollator_p.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<qsysinfo.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
comment|//NOTE: SORT_DIGITSASNUMBERS is available since win7
ifndef|#
directive|ifndef
name|SORT_DIGITSASNUMBERS
DECL|macro|SORT_DIGITSASNUMBERS
define|#
directive|define
name|SORT_DIGITSASNUMBERS
value|8
endif|#
directive|endif
comment|// implemented in qlocale_win.cpp
specifier|extern
name|LCID
name|qt_inIsoNametoLCID
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|init
name|void
name|QCollatorPrivate
operator|::
name|init
parameter_list|()
block|{
name|collator
operator|=
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|USE_COMPARESTRINGEX
name|localeID
operator|=
name|qt_inIsoNametoLCID
argument_list|(
name|locale
operator|.
name|bcp47Name
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|localeName
operator|=
name|locale
operator|.
name|bcp47Name
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|caseSensitivity
operator|==
name|Qt
operator|::
name|CaseInsensitive
condition|)
name|collator
operator||=
name|NORM_IGNORECASE
expr_stmt|;
if|if
condition|(
name|numericMode
condition|)
block|{
if|if
condition|(
name|QSysInfo
operator|::
name|windowsVersion
argument_list|()
operator|>=
name|QSysInfo
operator|::
name|WV_WINDOWS7
condition|)
name|collator
operator||=
name|SORT_DIGITSASNUMBERS
expr_stmt|;
else|else
name|qWarning
argument_list|()
operator|<<
literal|"Numeric sorting unsupported on Windows versions older than Windows 7."
expr_stmt|;
block|}
if|if
condition|(
name|ignorePunctuation
condition|)
name|collator
operator||=
name|NORM_IGNORESYMBOLS
expr_stmt|;
name|dirty
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QCollatorPrivate
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QChar
modifier|*
name|s1
parameter_list|,
name|int
name|len1
parameter_list|,
specifier|const
name|QChar
modifier|*
name|s2
parameter_list|,
name|int
name|len2
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|dirty
condition|)
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
comment|//* from Windows documentation *
comment|// Returns one of the following values if successful. To maintain the C runtime convention of
comment|// comparing strings, the value 2 can be subtracted from a nonzero return value. Then, the
comment|// meaning of<0, ==0, and>0 is consistent with the C runtime.
ifndef|#
directive|ifndef
name|USE_COMPARESTRINGEX
return|return
name|CompareString
argument_list|(
name|d
operator|->
name|localeID
argument_list|,
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|s1
argument_list|)
argument_list|,
name|len1
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|s2
argument_list|)
argument_list|,
name|len2
argument_list|)
operator|-
literal|2
return|;
else|#
directive|else
return|return
name|CompareStringEx
argument_list|(
name|LPCWSTR
argument_list|(
name|d
operator|->
name|localeName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPCWSTR
argument_list|>
argument_list|(
name|s1
argument_list|)
argument_list|,
name|len1
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPCWSTR
argument_list|>
argument_list|(
name|s2
argument_list|)
argument_list|,
name|len2
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|-
literal|2
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QString
modifier|&
name|str1
parameter_list|,
specifier|const
name|QString
modifier|&
name|str2
parameter_list|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|str1
operator|.
name|constData
argument_list|()
argument_list|,
name|str1
operator|.
name|size
argument_list|()
argument_list|,
name|str2
operator|.
name|constData
argument_list|()
argument_list|,
name|str2
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollator
operator|::
name|compare
parameter_list|(
specifier|const
name|QStringRef
modifier|&
name|s1
parameter_list|,
specifier|const
name|QStringRef
modifier|&
name|s2
parameter_list|)
specifier|const
block|{
return|return
name|compare
argument_list|(
name|s1
operator|.
name|constData
argument_list|()
argument_list|,
name|s1
operator|.
name|size
argument_list|()
argument_list|,
name|s2
operator|.
name|constData
argument_list|()
argument_list|,
name|s2
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sortKey
name|QCollatorSortKey
name|QCollator
operator|::
name|sortKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|dirty
condition|)
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|USE_COMPARESTRINGEX
name|int
name|size
init|=
name|LCMapStringW
argument_list|(
name|d
operator|->
name|localeID
argument_list|,
name|LCMAP_SORTKEY
operator||
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|string
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
else|#
directive|else
name|int
name|size
init|=
name|LCMapStringEx
argument_list|(
name|LPCWSTR
argument_list|(
name|d
operator|->
name|localeName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|LCMAP_SORTKEY
operator||
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPCWSTR
argument_list|>
argument_list|(
name|string
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|QString
name|ret
argument_list|(
name|size
argument_list|,
name|Qt
operator|::
name|Uninitialized
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|USE_COMPARESTRINGEX
name|int
name|finalSize
init|=
name|LCMapStringW
argument_list|(
name|d
operator|->
name|localeID
argument_list|,
name|LCMAP_SORTKEY
operator||
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|string
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|ret
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|ret
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
else|#
directive|else
name|int
name|finalSize
init|=
name|LCMapStringEx
argument_list|(
name|LPCWSTR
argument_list|(
name|d
operator|->
name|localeName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|LCMAP_SORTKEY
operator||
name|d
operator|->
name|collator
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPCWSTR
argument_list|>
argument_list|(
name|string
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|string
operator|.
name|size
argument_list|()
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPWSTR
argument_list|>
argument_list|(
name|ret
operator|.
name|data
argument_list|()
argument_list|)
argument_list|,
name|ret
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|finalSize
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"there were problems when generating the ::sortKey by LCMapStringW with error:"
operator|<<
name|GetLastError
argument_list|()
expr_stmt|;
block|}
return|return
name|QCollatorSortKey
argument_list|(
operator|new
name|QCollatorSortKeyPrivate
argument_list|(
name|ret
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|QCollatorSortKey
operator|::
name|compare
parameter_list|(
specifier|const
name|QCollatorSortKey
modifier|&
name|otherKey
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|m_key
operator|.
name|compare
argument_list|(
name|otherKey
operator|.
name|d
operator|->
name|m_key
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
