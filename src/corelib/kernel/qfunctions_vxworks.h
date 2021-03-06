begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUNCTIONS_VXWORKS_H
end_ifndef
begin_define
DECL|macro|QFUNCTIONS_VXWORKS_H
define|#
directive|define
name|QFUNCTIONS_VXWORKS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_VXWORKS
end_ifdef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_include
include|#
directive|include
file|<dirent.h>
end_include
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<strings.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WRS_KERNEL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/times.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<sys/wait.h>
end_include
begin_include
include|#
directive|include
file|<netinet/in.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IPV6IFNAME
end_ifndef
begin_include
include|#
directive|include
file|<net/if.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// VxWorks has public header mbuf.h which defines following variables for DKM.
end_comment
begin_comment
comment|// Let's undef those to because they overlap with Qt variable names-
end_comment
begin_comment
comment|// File mbuf.h is included in headers<netinet/in.h><net/if.h>, so make sure
end_comment
begin_comment
comment|// that those are included before undef's.
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|mbuf
argument_list|)
end_if
begin_undef
DECL|macro|mbuf
undef|#
directive|undef
name|mbuf
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_data
argument_list|)
end_if
begin_undef
DECL|macro|m_data
undef|#
directive|undef
name|m_data
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_type
argument_list|)
end_if
begin_undef
DECL|macro|m_type
undef|#
directive|undef
name|m_type
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_next
argument_list|)
end_if
begin_undef
DECL|macro|m_next
undef|#
directive|undef
name|m_next
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_len
argument_list|)
end_if
begin_undef
DECL|macro|m_len
undef|#
directive|undef
name|m_len
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_flags
argument_list|)
end_if
begin_undef
DECL|macro|m_flags
undef|#
directive|undef
name|m_flags
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_hdr
argument_list|)
end_if
begin_undef
DECL|macro|m_hdr
undef|#
directive|undef
name|m_hdr
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_ext
argument_list|)
end_if
begin_undef
DECL|macro|m_ext
undef|#
directive|undef
name|m_ext
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_act
argument_list|)
end_if
begin_undef
DECL|macro|m_act
undef|#
directive|undef
name|m_act
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_nextpkt
argument_list|)
end_if
begin_undef
DECL|macro|m_nextpkt
undef|#
directive|undef
name|m_nextpkt
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|m_pkthdr
argument_list|)
end_if
begin_undef
DECL|macro|m_pkthdr
undef|#
directive|undef
name|m_pkthdr
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_BUILD_CORE_LIB
endif|#
directive|endif
name|QT_END_NAMESPACE
ifndef|#
directive|ifndef
name|RTLD_LOCAL
DECL|macro|RTLD_LOCAL
define|#
directive|define
name|RTLD_LOCAL
value|0
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NSIG
DECL|macro|NSIG
define|#
directive|define
name|NSIG
value|_NSIGS
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
specifier|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// isascii is missing (sometimes!!)
ifndef|#
directive|ifndef
name|isascii
DECL|function|isascii
specifier|inline
name|int
name|isascii
argument_list|(
argument|int c
argument_list|)
block|{
return|return
operator|(
name|c
operator|&
literal|0x7f
operator|)
return|;
block|}
endif|#
directive|endif
comment|// no lfind() - used by the TIF image format
name|void
operator|*
name|lfind
argument_list|(
argument|const void* key
argument_list|,
argument|const void* base
argument_list|,
argument|size_t* elements
argument_list|,
argument|size_t size
argument_list|,
argument|int (*compare)(const void*, const void*)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// no rand_r(), but rand()
end_comment
begin_comment
comment|// NOTE: this implementation is wrong for multi threaded applications,
end_comment
begin_comment
comment|// but there is no way to get it right on VxWorks (in kernel mode)
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WRS_KERNEL
argument_list|)
end_if
begin_function_decl
name|int
name|rand_r
parameter_list|(
name|unsigned
name|int
modifier|*
comment|/*seedp*/
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// no usleep() support
end_comment
begin_function_decl
name|int
name|usleep
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_if
if|#
directive|if
name|defined
argument_list|(
name|VXWORKS_DKM
argument_list|)
operator|||
name|defined
argument_list|(
name|VXWORKS_RTP
argument_list|)
end_if
begin_function_decl
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_else
else|#
directive|else
end_else
begin_comment
comment|// gettimeofday() is declared, but is missing from the library.
end_comment
begin_comment
comment|// It IS however defined in the Curtis-Wright X11 libraries, so
end_comment
begin_comment
comment|// we have to make the symbol 'weak'
end_comment
begin_function_decl
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|void
comment|/*struct timezone*/
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(weak
end_function_decl
begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// getpagesize() not available
end_comment
begin_function_decl
name|int
name|getpagesize
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// symlinks are not supported (lstat is now just a call to stat - see qplatformdefs.h)
end_comment
begin_function_decl
name|int
name|symlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|ssize_t
name|readlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// there's no truncate(), but ftruncate() support...
end_comment
begin_function_decl
name|int
name|truncate
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|off_t
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// VxWorks doesn't know about passwd& friends.
end_comment
begin_comment
comment|// in order to avoid patching the unix fs path everywhere
end_comment
begin_comment
comment|// we introduce some dummy functions that simulate a single
end_comment
begin_comment
comment|// 'root' user on the system.
end_comment
begin_function_decl
name|uid_t
name|getuid
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|gid_t
name|getgid
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|uid_t
name|geteuid
parameter_list|()
function_decl|;
end_function_decl
begin_struct
DECL|struct|passwd
struct|struct
name|passwd
block|{
DECL|member|pw_name
name|char
modifier|*
name|pw_name
decl_stmt|;
comment|/* user name */
DECL|member|pw_passwd
name|char
modifier|*
name|pw_passwd
decl_stmt|;
comment|/* user password */
DECL|member|pw_uid
name|uid_t
name|pw_uid
decl_stmt|;
comment|/* user ID */
DECL|member|pw_gid
name|gid_t
name|pw_gid
decl_stmt|;
comment|/* group ID */
DECL|member|pw_gecos
name|char
modifier|*
name|pw_gecos
decl_stmt|;
comment|/* real name */
DECL|member|pw_dir
name|char
modifier|*
name|pw_dir
decl_stmt|;
comment|/* home directory */
DECL|member|pw_shell
name|char
modifier|*
name|pw_shell
decl_stmt|;
comment|/* shell program */
block|}
struct|;
end_struct
begin_struct
DECL|struct|group
struct|struct
name|group
block|{
DECL|member|gr_name
name|char
modifier|*
name|gr_name
decl_stmt|;
comment|/* group name */
DECL|member|gr_passwd
name|char
modifier|*
name|gr_passwd
decl_stmt|;
comment|/* group password */
DECL|member|gr_gid
name|gid_t
name|gr_gid
decl_stmt|;
comment|/* group ID */
DECL|member|gr_mem
name|char
modifier|*
modifier|*
name|gr_mem
decl_stmt|;
comment|/* group members */
block|}
struct|;
end_struct
begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|(
name|gid_t
name|gid
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_comment
unit|}
comment|// extern "C"
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_VXWORKS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFUNCTIONS_VXWORKS_H
end_comment
end_unit
