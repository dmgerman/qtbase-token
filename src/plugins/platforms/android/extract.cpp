begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3-COMM$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|<android/log.h>
end_include
begin_include
include|#
directive|include
file|<extract.h>
end_include
begin_include
include|#
directive|include
file|<alloca.h>
end_include
begin_define
DECL|macro|LOG_TAG
define|#
directive|define
name|LOG_TAG
value|"extractSyleInfo"
end_define
begin_define
DECL|macro|LOGE
define|#
directive|define
name|LOGE
parameter_list|(
modifier|...
parameter_list|)
value|__android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
end_define
begin_extern
DECL|function|Java_org_qtproject_qt5_android_ExtractStyle_extractNativeChunkInfo
extern|extern
literal|"C"
name|JNIEXPORT
name|jintArray
name|JNICALL
name|Java_org_qtproject_qt5_android_ExtractStyle_extractNativeChunkInfo
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
parameter_list|,
name|Res_png_9patch
modifier|*
name|chunk
parameter_list|)
block|{
name|Res_png_9patch
operator|::
name|deserialize
argument_list|(
name|chunk
argument_list|)
expr_stmt|;
comment|//printChunkInformation(chunk);
name|jintArray
name|result
decl_stmt|;
name|size_t
name|size
init|=
literal|3
operator|+
name|chunk
operator|->
name|numXDivs
operator|+
name|chunk
operator|->
name|numYDivs
operator|+
name|chunk
operator|->
name|numColors
decl_stmt|;
name|result
operator|=
name|env
operator|->
name|NewIntArray
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
return|return
literal|0
return|;
name|jint
modifier|*
name|data
init|=
operator|(
name|jint
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|jint
argument_list|)
operator|*
name|size
argument_list|)
decl_stmt|;
name|size_t
name|pos
init|=
literal|0
decl_stmt|;
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|numXDivs
expr_stmt|;
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|numYDivs
expr_stmt|;
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|numColors
expr_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|chunk
operator|->
name|numXDivs
condition|;
name|x
operator|++
control|)
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|xDivs
index|[
name|x
index|]
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|chunk
operator|->
name|numYDivs
condition|;
name|y
operator|++
control|)
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|yDivs
index|[
name|y
index|]
expr_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|chunk
operator|->
name|numColors
condition|;
name|c
operator|++
control|)
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|colors
index|[
name|c
index|]
expr_stmt|;
name|env
operator|->
name|SetIntArrayRegion
argument_list|(
name|result
argument_list|,
literal|0
argument_list|,
name|size
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|data
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_extern
begin_extern
DECL|function|Java_org_qtproject_qt5_android_ExtractStyle_extractChunkInfo
extern|extern
literal|"C"
name|JNIEXPORT
name|jintArray
name|JNICALL
name|Java_org_qtproject_qt5_android_ExtractStyle_extractChunkInfo
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
name|obj
parameter_list|,
name|jbyteArray
name|chunkObj
parameter_list|)
block|{
name|size_t
name|chunkSize
init|=
name|env
operator|->
name|GetArrayLength
argument_list|(
name|chunkObj
argument_list|)
decl_stmt|;
name|void
modifier|*
name|storage
init|=
name|alloca
argument_list|(
name|chunkSize
argument_list|)
decl_stmt|;
name|env
operator|->
name|GetByteArrayRegion
argument_list|(
name|chunkObj
argument_list|,
literal|0
argument_list|,
name|chunkSize
argument_list|,
cast|reinterpret_cast
argument_list|<
name|jbyte
operator|*
argument_list|>
argument_list|(
name|storage
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|env
operator|->
name|ExceptionCheck
argument_list|()
condition|)
return|return
name|Java_org_qtproject_qt5_android_ExtractStyle_extractNativeChunkInfo
argument_list|(
name|env
argument_list|,
name|obj
argument_list|,
cast|static_cast
argument_list|<
name|Res_png_9patch
operator|*
argument_list|>
argument_list|(
name|storage
argument_list|)
argument_list|)
return|;
else|else
name|env
operator|->
name|ExceptionClear
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_extern
begin_comment
comment|// The following part was shamelessly stolen from ResourceTypes.cpp from Android's sources
end_comment
begin_comment
comment|/*  * Copyright (C) 2005 The Android Open Source Project  *  * Licensed under the Apache License, Version 2.0 (the "License");  * you may not use this file except in compliance with the License.  * You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment
begin_function
DECL|function|deserializeInternal
specifier|static
name|void
name|deserializeInternal
parameter_list|(
specifier|const
name|void
modifier|*
name|inData
parameter_list|,
name|Res_png_9patch
modifier|*
name|outData
parameter_list|)
block|{
name|char
modifier|*
name|patch
init|=
operator|(
name|char
operator|*
operator|)
name|inData
decl_stmt|;
if|if
condition|(
name|inData
operator|!=
name|outData
condition|)
block|{
name|memmove
argument_list|(
operator|&
name|outData
operator|->
name|wasDeserialized
argument_list|,
name|patch
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// copy  wasDeserialized, numXDivs, numYDivs, numColors
name|memmove
argument_list|(
operator|&
name|outData
operator|->
name|paddingLeft
argument_list|,
name|patch
operator|+
literal|12
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// copy  wasDeserialized, numXDivs, numYDivs, numColors
block|}
name|outData
operator|->
name|wasDeserialized
operator|=
literal|true
expr_stmt|;
name|char
modifier|*
name|data
init|=
operator|(
name|char
operator|*
operator|)
name|outData
decl_stmt|;
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|Res_png_9patch
argument_list|)
expr_stmt|;
name|outData
operator|->
name|xDivs
operator|=
operator|(
name|int32_t
operator|*
operator|)
name|data
expr_stmt|;
name|data
operator|+=
name|outData
operator|->
name|numXDivs
operator|*
sizeof|sizeof
argument_list|(
name|int32_t
argument_list|)
expr_stmt|;
name|outData
operator|->
name|yDivs
operator|=
operator|(
name|int32_t
operator|*
operator|)
name|data
expr_stmt|;
name|data
operator|+=
name|outData
operator|->
name|numYDivs
operator|*
sizeof|sizeof
argument_list|(
name|int32_t
argument_list|)
expr_stmt|;
name|outData
operator|->
name|colors
operator|=
operator|(
name|uint32_t
operator|*
operator|)
name|data
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deserialize
name|Res_png_9patch
modifier|*
name|Res_png_9patch
operator|::
name|deserialize
parameter_list|(
specifier|const
name|void
modifier|*
name|inData
parameter_list|)
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|int32_t
argument_list|)
condition|)
block|{
name|LOGE
argument_list|(
literal|"Cannot deserialize on non 32-bit system\n"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|deserializeInternal
argument_list|(
name|inData
argument_list|,
operator|(
name|Res_png_9patch
operator|*
operator|)
name|inData
argument_list|)
expr_stmt|;
return|return
operator|(
name|Res_png_9patch
operator|*
operator|)
name|inData
return|;
block|}
end_function
begin_extern
DECL|function|Java_org_qtproject_qt5_android_ExtractStyle_extractNativeChunkInfo20
extern|extern
literal|"C"
name|JNIEXPORT
name|jintArray
name|JNICALL
name|Java_org_qtproject_qt5_android_ExtractStyle_extractNativeChunkInfo20
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
parameter_list|,
name|long
name|addr
parameter_list|)
block|{
name|Res_png_9patch20
modifier|*
name|chunk
init|=
cast|reinterpret_cast
argument_list|<
name|Res_png_9patch20
operator|*
argument_list|>
argument_list|(
name|addr
argument_list|)
decl_stmt|;
name|Res_png_9patch20
operator|::
name|deserialize
argument_list|(
name|chunk
argument_list|)
expr_stmt|;
comment|//printChunkInformation(chunk);
name|jintArray
name|result
decl_stmt|;
name|size_t
name|size
init|=
literal|3
operator|+
name|chunk
operator|->
name|numXDivs
operator|+
name|chunk
operator|->
name|numYDivs
operator|+
name|chunk
operator|->
name|numColors
decl_stmt|;
name|result
operator|=
name|env
operator|->
name|NewIntArray
argument_list|(
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
return|return
literal|0
return|;
name|jint
modifier|*
name|data
init|=
operator|(
name|jint
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|jint
argument_list|)
operator|*
name|size
argument_list|)
decl_stmt|;
name|size_t
name|pos
init|=
literal|0
decl_stmt|;
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|numXDivs
expr_stmt|;
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|numYDivs
expr_stmt|;
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|chunk
operator|->
name|numColors
expr_stmt|;
name|int32_t
modifier|*
name|xDivs
init|=
name|chunk
operator|->
name|getXDivs
argument_list|()
decl_stmt|;
name|int32_t
modifier|*
name|yDivs
init|=
name|chunk
operator|->
name|getYDivs
argument_list|()
decl_stmt|;
name|uint32_t
modifier|*
name|colors
init|=
name|chunk
operator|->
name|getColors
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|chunk
operator|->
name|numXDivs
condition|;
name|x
operator|++
control|)
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|xDivs
index|[
name|x
index|]
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|chunk
operator|->
name|numYDivs
condition|;
name|y
operator|++
control|)
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|yDivs
index|[
name|y
index|]
expr_stmt|;
for|for
control|(
name|int
name|c
init|=
literal|0
init|;
name|c
operator|<
name|chunk
operator|->
name|numColors
condition|;
name|c
operator|++
control|)
name|data
index|[
name|pos
operator|++
index|]
operator|=
name|colors
index|[
name|c
index|]
expr_stmt|;
name|env
operator|->
name|SetIntArrayRegion
argument_list|(
name|result
argument_list|,
literal|0
argument_list|,
name|size
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|data
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_extern
begin_extern
DECL|function|Java_org_qtproject_qt5_android_ExtractStyle_extractChunkInfo20
extern|extern
literal|"C"
name|JNIEXPORT
name|jintArray
name|JNICALL
name|Java_org_qtproject_qt5_android_ExtractStyle_extractChunkInfo20
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
name|obj
parameter_list|,
name|jbyteArray
name|chunkObj
parameter_list|)
block|{
name|size_t
name|chunkSize
init|=
name|env
operator|->
name|GetArrayLength
argument_list|(
name|chunkObj
argument_list|)
decl_stmt|;
name|void
modifier|*
name|storage
init|=
name|alloca
argument_list|(
name|chunkSize
argument_list|)
decl_stmt|;
name|env
operator|->
name|GetByteArrayRegion
argument_list|(
name|chunkObj
argument_list|,
literal|0
argument_list|,
name|chunkSize
argument_list|,
cast|reinterpret_cast
argument_list|<
name|jbyte
operator|*
argument_list|>
argument_list|(
name|storage
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|env
operator|->
name|ExceptionCheck
argument_list|()
condition|)
return|return
name|Java_org_qtproject_qt5_android_ExtractStyle_extractNativeChunkInfo20
argument_list|(
name|env
argument_list|,
name|obj
argument_list|,
name|long
argument_list|(
name|storage
argument_list|)
argument_list|)
return|;
else|else
name|env
operator|->
name|ExceptionClear
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_extern
begin_function
DECL|function|fill9patchOffsets
specifier|static
specifier|inline
name|void
name|fill9patchOffsets
parameter_list|(
name|Res_png_9patch20
modifier|*
name|patch
parameter_list|)
block|{
name|patch
operator|->
name|xDivsOffset
operator|=
sizeof|sizeof
argument_list|(
name|Res_png_9patch20
argument_list|)
expr_stmt|;
name|patch
operator|->
name|yDivsOffset
operator|=
name|patch
operator|->
name|xDivsOffset
operator|+
operator|(
name|patch
operator|->
name|numXDivs
operator|*
sizeof|sizeof
argument_list|(
name|int32_t
argument_list|)
operator|)
expr_stmt|;
name|patch
operator|->
name|colorsOffset
operator|=
name|patch
operator|->
name|yDivsOffset
operator|+
operator|(
name|patch
operator|->
name|numYDivs
operator|*
sizeof|sizeof
argument_list|(
name|int32_t
argument_list|)
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deserialize
name|Res_png_9patch20
modifier|*
name|Res_png_9patch20
operator|::
name|deserialize
parameter_list|(
name|void
modifier|*
name|inData
parameter_list|)
block|{
name|Res_png_9patch20
modifier|*
name|patch
init|=
cast|reinterpret_cast
argument_list|<
name|Res_png_9patch20
operator|*
argument_list|>
argument_list|(
name|inData
argument_list|)
decl_stmt|;
name|patch
operator|->
name|wasDeserialized
operator|=
literal|true
expr_stmt|;
name|fill9patchOffsets
argument_list|(
name|patch
argument_list|)
expr_stmt|;
return|return
name|patch
return|;
block|}
end_function
end_unit
