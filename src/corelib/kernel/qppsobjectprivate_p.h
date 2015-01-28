begin_unit
begin_comment
comment|/****************************************************************************  **  ** Copyright (C) 2013 BlackBerry Limited. All rights reserved.  ** Contact: http://www.qt.io/licensing/  **  ** This file is part of the QtCore module of the Qt Toolkit.  **  ** $QT_BEGIN_LICENSE:LGPL21$  ** Commercial License Usage  ** Licensees holding valid commercial Qt licenses may use this file in  ** accordance with the commercial license agreement provided with the  ** Software or, alternatively, in accordance with the terms contained in  ** a written agreement between you and The Qt Company. For licensing terms  ** and conditions see http://www.qt.io/terms-conditions. For further  ** information use the contact form at http://www.qt.io/contact-us.  **  ** GNU Lesser General Public License Usage  ** Alternatively, this file may be used under the terms of the GNU Lesser  ** General Public License version 2.1 or version 3 as published by the Free  ** Software Foundation and appearing in the file LICENSE.LGPLv21 and  ** LICENSE.LGPLv3 included in the packaging of this file. Please review the  ** following information to ensure the GNU Lesser General Public License  ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and  ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.  **  ** As a special exception, The Qt Company gives you certain additional  ** rights. These rights are described in The Qt Company LGPL Exception  ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.  **  ** $QT_END_LICENSE$  **  ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPPSOBJECTPRIVATE_P_H_
end_ifndef
begin_define
DECL|macro|QPPSOBJECTPRIVATE_P_H_
define|#
directive|define
name|QPPSOBJECTPRIVATE_P_H_
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qppsattribute_p.h"
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<sys/pps.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifier
name|class
name|QSocketNotifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPpsObjectPrivate
block|{
name|public
label|:
name|explicit
name|QPpsObjectPrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
specifier|static
name|QPpsAttributeMap
name|decode
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|rawData
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|encode
parameter_list|(
specifier|const
name|QVariantMap
modifier|&
name|ppsData
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
specifier|static
name|QVariantMap
name|variantMapFromPpsAttributeMap
parameter_list|(
specifier|const
name|QPpsAttributeMap
modifier|&
name|data
parameter_list|)
function_decl|;
name|QSocketNotifier
modifier|*
name|notifier
decl_stmt|;
name|QString
name|path
decl_stmt|;
name|mutable
name|int
name|error
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|bool
name|readyReadEnabled
decl_stmt|;
name|private
label|:
specifier|static
name|QPpsAttribute
operator|::
name|Flags
name|readFlags
argument_list|(
name|pps_decoder_t
operator|*
name|decoder
argument_list|)
expr_stmt|;
specifier|static
name|QPpsAttribute
name|decodeString
parameter_list|(
name|pps_decoder_t
modifier|*
name|decoder
parameter_list|)
function_decl|;
specifier|static
name|QPpsAttribute
name|decodeNumber
parameter_list|(
name|pps_decoder_t
modifier|*
name|decoder
parameter_list|)
function_decl|;
specifier|static
name|QPpsAttribute
name|decodeBool
parameter_list|(
name|pps_decoder_t
modifier|*
name|decoder
parameter_list|)
function_decl|;
specifier|static
name|QPpsAttribute
name|decodeData
parameter_list|(
name|pps_decoder_t
modifier|*
name|decoder
parameter_list|)
function_decl|;
specifier|static
name|QPpsAttributeList
name|decodeArray
parameter_list|(
name|pps_decoder_t
modifier|*
name|decoder
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
specifier|static
name|QPpsAttributeMap
name|decodeObject
parameter_list|(
name|pps_decoder_t
modifier|*
name|decoder
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
specifier|static
name|bool
name|decoderPush
parameter_list|(
name|pps_decoder_t
modifier|*
name|decoder
parameter_list|,
specifier|const
name|char
modifier|*
name|name
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|bool
name|decoderPop
parameter_list|(
name|pps_decoder_t
modifier|*
name|decoder
parameter_list|)
function_decl|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|QPpsAttribute
name|decodeNestedData
argument_list|(
name|T
argument_list|(
operator|*
name|decodeFunction
argument_list|)
argument_list|(
name|pps_decoder_t
operator|*
argument_list|,
name|bool
operator|*
argument_list|)
argument_list|,
name|pps_decoder_t
operator|*
name|decoder
argument_list|)
expr_stmt|;
specifier|static
name|void
name|encodeData
parameter_list|(
name|pps_encoder_t
modifier|*
name|encoder
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|data
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
specifier|static
name|void
name|encodeArray
parameter_list|(
name|pps_encoder_t
modifier|*
name|encoder
parameter_list|,
specifier|const
name|QVariantList
modifier|&
name|data
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
specifier|static
name|void
name|encodeObject
parameter_list|(
name|pps_encoder_t
modifier|*
name|encoder
parameter_list|,
specifier|const
name|QVariantMap
modifier|&
name|data
parameter_list|,
name|bool
modifier|*
name|ok
parameter_list|)
function_decl|;
specifier|static
name|QVariant
name|variantFromPpsAttribute
parameter_list|(
specifier|const
name|QPpsAttribute
modifier|&
name|attribute
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|decoderPush
specifier|inline
name|bool
name|QPpsObjectPrivate
operator|::
name|decoderPush
argument_list|(
argument|pps_decoder_t *decoder
argument_list|,
argument|const char *name
argument_list|)
block|{
name|pps_decoder_error_t
name|error
operator|=
name|pps_decoder_push
argument_list|(
name|decoder
argument_list|,
name|name
argument_list|)
block|;
if|if
condition|(
name|error
operator|!=
name|PPS_DECODER_OK
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QPpsObjectPrivate::decodeData: pps_decoder_push failed"
expr_stmt|;
return|return
name|false
return|;
block|}
end_expr_stmt
begin_return
return|return
name|true
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|decoderPop
name|bool
name|QPpsObjectPrivate
operator|::
name|decoderPop
argument_list|(
argument|pps_decoder_t *decoder
argument_list|)
block|{
name|pps_decoder_error_t
name|error
operator|=
name|pps_decoder_pop
argument_list|(
name|decoder
argument_list|)
block|;
if|if
condition|(
name|error
operator|!=
name|PPS_DECODER_OK
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QPpsObjectPrivate::decodeData: pps_decoder_pop failed"
expr_stmt|;
return|return
name|false
return|;
block|}
end_expr_stmt
begin_return
return|return
name|true
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|/* QPPSOBJECTPRIVATE_P_H_ */
end_comment
end_unit
