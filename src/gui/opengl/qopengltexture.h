begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLABSTRACTTEXTURE_H
end_ifndef
begin_define
DECL|macro|QOPENGLABSTRACTTEXTURE_H
define|#
directive|define
name|QOPENGLABSTRACTTEXTURE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLTexturePrivate
name|class
name|QOpenGLTexturePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLPixelTransferOptions
name|class
name|QOpenGLPixelTransferOptions
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLTexture
block|{
name|public
label|:
enum|enum
name|Target
block|{
name|Target1D
init|=
literal|0x0DE0
block|,
comment|// GL_TEXTURE_1D
name|Target1DArray
init|=
literal|0x8C18
block|,
comment|// GL_TEXTURE_1D_ARRAY
name|Target2D
init|=
literal|0x0DE1
block|,
comment|// GL_TEXTURE_2D
name|Target2DArray
init|=
literal|0x8C1A
block|,
comment|// GL_TEXTURE_2D_ARRAY
name|Target3D
init|=
literal|0x806F
block|,
comment|// GL_TEXTURE_3D
name|TargetCubeMap
init|=
literal|0x8513
block|,
comment|// GL_TEXTURE_CUBE_MAP
name|TargetCubeMapArray
init|=
literal|0x9009
block|,
comment|// GL_TEXTURE_CUBE_MAP_ARRAY
name|Target2DMultisample
init|=
literal|0x9100
block|,
comment|// GL_TEXTURE_2D_MULTISAMPLE
name|Target2DMultisampleArray
init|=
literal|0x9102
block|,
comment|// GL_TEXTURE_2D_MULTISAMPLE_ARRAY
name|TargetRectangle
init|=
literal|0x84F5
block|,
comment|// GL_TEXTURE_RECTANGLE
name|TargetBuffer
init|=
literal|0x8C2A
comment|// GL_TEXTURE_BUFFER
block|}
enum|;
enum|enum
name|BindingTarget
block|{
name|BindingTarget1D
init|=
literal|0x8068
block|,
comment|// GL_TEXTURE_BINDING_1D
name|BindingTarget1DArray
init|=
literal|0x8C1C
block|,
comment|// GL_TEXTURE_BINDING_1D_ARRAY
name|BindingTarget2D
init|=
literal|0x8069
block|,
comment|// GL_TEXTURE_BINDING_2D
name|BindingTarget2DArray
init|=
literal|0x8C1D
block|,
comment|// GL_TEXTURE_BINDING_2D_ARRAY
name|BindingTarget3D
init|=
literal|0x806A
block|,
comment|// GL_TEXTURE_BINDING_3D
name|BindingTargetCubeMap
init|=
literal|0x8514
block|,
comment|// GL_TEXTURE_BINDING_CUBE_MAP
name|BindingTargetCubeMapArray
init|=
literal|0x900A
block|,
comment|// GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
name|BindingTarget2DMultisample
init|=
literal|0x9104
block|,
comment|// GL_TEXTURE_BINDING_2D_MULTISAMPLE
name|BindingTarget2DMultisampleArray
init|=
literal|0x9105
block|,
comment|// GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
name|BindingTargetRectangle
init|=
literal|0x84F6
block|,
comment|// GL_TEXTURE_BINDING_RECTANGLE
name|BindingTargetBuffer
init|=
literal|0x8C2C
comment|// GL_TEXTURE_BINDING_BUFFER
block|}
enum|;
enum|enum
name|MipMapGeneration
block|{
name|GenerateMipMaps
block|,
name|DontGenerateMipMaps
block|}
enum|;
enum|enum
name|TextureUnitReset
block|{
name|ResetTextureUnit
block|,
name|DontResetTextureUnit
block|}
enum|;
name|explicit
name|QOpenGLTexture
parameter_list|(
name|Target
name|target
parameter_list|)
function_decl|;
name|QOpenGLTexture
argument_list|(
argument|const QImage& image
argument_list|,
argument|MipMapGeneration genMipMaps = GenerateMipMaps
argument_list|)
empty_stmt|;
operator|~
name|QOpenGLTexture
argument_list|()
expr_stmt|;
comment|// Creation and destruction
name|bool
name|create
parameter_list|()
function_decl|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|bool
name|isCreated
argument_list|()
specifier|const
expr_stmt|;
name|GLuint
name|textureId
argument_list|()
specifier|const
expr_stmt|;
comment|// Binding and releasing
name|void
name|bind
parameter_list|()
function_decl|;
name|void
name|bind
parameter_list|(
name|uint
name|unit
parameter_list|,
name|TextureUnitReset
name|reset
init|=
name|DontResetTextureUnit
parameter_list|)
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|(
name|uint
name|unit
parameter_list|,
name|TextureUnitReset
name|reset
init|=
name|DontResetTextureUnit
parameter_list|)
function_decl|;
name|bool
name|isBound
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isBound
parameter_list|(
name|uint
name|unit
parameter_list|)
function_decl|;
specifier|static
name|GLuint
name|boundTextureId
parameter_list|(
name|BindingTarget
name|target
parameter_list|)
function_decl|;
specifier|static
name|GLuint
name|boundTextureId
parameter_list|(
name|uint
name|unit
parameter_list|,
name|BindingTarget
name|target
parameter_list|)
function_decl|;
enum|enum
name|TextureFormat
block|{
name|NoFormat
init|=
literal|0
block|,
comment|// GL_NONE
comment|// Unsigned normalized formats
name|R8_UNorm
init|=
literal|0x8229
block|,
comment|// GL_R8
name|RG8_UNorm
init|=
literal|0x822B
block|,
comment|// GL_RG8
name|RGB8_UNorm
init|=
literal|0x8051
block|,
comment|// GL_RGB8
name|RGBA8_UNorm
init|=
literal|0x8058
block|,
comment|// GL_RGBA8
name|R16_UNorm
init|=
literal|0x822A
block|,
comment|// GL_R16
name|RG16_UNorm
init|=
literal|0x822C
block|,
comment|// GL_RG16
name|RGB16_UNorm
init|=
literal|0x8054
block|,
comment|// GL_RGB16
name|RGBA16_UNorm
init|=
literal|0x805B
block|,
comment|// GL_RGBA16
comment|// Signed normalized formats
name|R8_SNorm
init|=
literal|0x8F94
block|,
comment|// GL_R8_SNORM
name|RG8_SNorm
init|=
literal|0x8F95
block|,
comment|// GL_RG8_SNORM
name|RGB8_SNorm
init|=
literal|0x8F96
block|,
comment|// GL_RGB8_SNORM
name|RGBA8_SNorm
init|=
literal|0x8F97
block|,
comment|// GL_RGBA8_SNORM
name|R16_SNorm
init|=
literal|0x8F98
block|,
comment|// GL_R16_SNORM
name|RG16_SNorm
init|=
literal|0x8F99
block|,
comment|// GL_RG16_SNORM
name|RGB16_SNorm
init|=
literal|0x8F9A
block|,
comment|// GL_RGB16_SNORM
name|RGBA16_SNorm
init|=
literal|0x8F9B
block|,
comment|// GL_RGBA16_SNORM
comment|// Unsigned integer formats
name|R8U
init|=
literal|0x8232
block|,
comment|// GL_R8UI
name|RG8U
init|=
literal|0x8238
block|,
comment|// GL_RG8UI
name|RGB8U
init|=
literal|0x8D7D
block|,
comment|// GL_RGB8UI
name|RGBA8U
init|=
literal|0x8D7C
block|,
comment|// GL_RGBA8UI
name|R16U
init|=
literal|0x8234
block|,
comment|// GL_R16UI
name|RG16U
init|=
literal|0x823A
block|,
comment|// GL_RG16UI
name|RGB16U
init|=
literal|0x8D77
block|,
comment|// GL_RGB16UI
name|RGBA16U
init|=
literal|0x8D76
block|,
comment|// GL_RGBA16UI
name|R32U
init|=
literal|0x8236
block|,
comment|// GL_R32UI
name|RG32U
init|=
literal|0x823C
block|,
comment|// GL_RG32UI
name|RGB32U
init|=
literal|0x8D71
block|,
comment|// GL_RGB32UI
name|RGBA32U
init|=
literal|0x8D70
block|,
comment|// GL_RGBA32UI
comment|// Signed integer formats
name|R8I
init|=
literal|0x8231
block|,
comment|// GL_R8I
name|RG8I
init|=
literal|0x8237
block|,
comment|// GL_RG8I
name|RGB8I
init|=
literal|0x8D8F
block|,
comment|// GL_RGB8I
name|RGBA8I
init|=
literal|0x8D8E
block|,
comment|// GL_RGBA8I
name|R16I
init|=
literal|0x8233
block|,
comment|// GL_R16I
name|RG16I
init|=
literal|0x8239
block|,
comment|// GL_RG16I
name|RGB16I
init|=
literal|0x8D89
block|,
comment|// GL_RGB16I
name|RGBA16I
init|=
literal|0x8D88
block|,
comment|// GL_RGBA16I
name|R32I
init|=
literal|0x8235
block|,
comment|// GL_R32I
name|RG32I
init|=
literal|0x823B
block|,
comment|// GL_RG32I
name|RGB32I
init|=
literal|0x8D83
block|,
comment|// GL_RGB32I
name|RGBA32I
init|=
literal|0x8D82
block|,
comment|// GL_RGBA32I
comment|// Floating point formats
name|R16F
init|=
literal|0x822D
block|,
comment|// GL_R16F
name|RG16F
init|=
literal|0x822F
block|,
comment|// GL_RG16F
name|RGB16F
init|=
literal|0x881B
block|,
comment|// GL_RGB16F
name|RGBA16F
init|=
literal|0x881A
block|,
comment|// GL_RGBA16F
name|R32F
init|=
literal|0x822E
block|,
comment|// GL_R32F
name|RG32F
init|=
literal|0x8230
block|,
comment|// GL_RG32F
name|RGB32F
init|=
literal|0x8815
block|,
comment|// GL_RGB32F
name|RGBA32F
init|=
literal|0x8814
block|,
comment|// GL_RGBA32F
comment|// Packed formats
name|RGB9E5
init|=
literal|0x8C3D
block|,
comment|// GL_RGB9_E5
name|RG11B10F
init|=
literal|0x8C3A
block|,
comment|// GL_R11F_G11F_B10F
name|RG3B2
init|=
literal|0x2A10
block|,
comment|// GL_R3_G3_B2
name|R5G6B5
init|=
literal|0x8D62
block|,
comment|// GL_RGB565
name|RGB5A1
init|=
literal|0x8057
block|,
comment|// GL_RGB5_A1
name|RGBA4
init|=
literal|0x8056
block|,
comment|// GL_RGBA4
name|RGB10A2
init|=
literal|0x906F
block|,
comment|// GL_RGB10_A2UI
comment|// Depth formats
name|D16
init|=
literal|0x81A5
block|,
comment|// GL_DEPTH_COMPONENT16
name|D24
init|=
literal|0x81A6
block|,
comment|// GL_DEPTH_COMPONENT24
name|D24S8
init|=
literal|0x88F0
block|,
comment|// GL_DEPTH24_STENCIL8
name|D32
init|=
literal|0x81A7
block|,
comment|// GL_DEPTH_COMPONENT32
name|D32F
init|=
literal|0x8CAC
block|,
comment|// GL_DEPTH_COMPONENT32F
name|D32FS8X24
init|=
literal|0x8CAD
block|,
comment|// GL_DEPTH32F_STENCIL8
comment|// Compressed formats
name|RGB_DXT1
init|=
literal|0x83F0
block|,
comment|// GL_COMPRESSED_RGB_S3TC_DXT1_EXT
name|RGBA_DXT1
init|=
literal|0x83F1
block|,
comment|// GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
name|RGBA_DXT3
init|=
literal|0x83F2
block|,
comment|// GL_COMPRESSED_RGBA_S3TC_DXT3_EXT
name|RGBA_DXT5
init|=
literal|0x83F3
block|,
comment|// GL_COMPRESSED_RGBA_S3TC_DXT5_EXT
name|R_ATI1N_UNorm
init|=
literal|0x8DBB
block|,
comment|// GL_COMPRESSED_RED_RGTC1
name|R_ATI1N_SNorm
init|=
literal|0x8DBC
block|,
comment|// GL_COMPRESSED_SIGNED_RED_RGTC1
name|RG_ATI2N_UNorm
init|=
literal|0x8DBD
block|,
comment|// GL_COMPRESSED_RG_RGTC2
name|RG_ATI2N_SNorm
init|=
literal|0x8DBE
block|,
comment|// GL_COMPRESSED_SIGNED_RG_RGTC2
name|RGB_BP_UNSIGNED_FLOAT
init|=
literal|0x8E8F
block|,
comment|// GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB
name|RGB_BP_SIGNED_FLOAT
init|=
literal|0x8E8E
block|,
comment|// GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB
name|RGB_BP_UNorm
init|=
literal|0x8E8C
block|,
comment|// GL_COMPRESSED_RGBA_BPTC_UNORM_ARB
comment|// sRGB formats
name|SRGB8
init|=
literal|0x8C41
block|,
comment|// GL_SRGB8
name|SRGB8_Alpha8
init|=
literal|0x8C43
block|,
comment|// GL_SRGB8_ALPHA8
name|SRGB_DXT1
init|=
literal|0x8C4C
block|,
comment|// GL_COMPRESSED_SRGB_S3TC_DXT1_EXT
name|SRGB_Alpha_DXT1
init|=
literal|0x8C4D
block|,
comment|// GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT
name|SRGB_Alpha_DXT3
init|=
literal|0x8C4E
block|,
comment|// GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT
name|SRGB_Alpha_DXT5
init|=
literal|0x8C4F
block|,
comment|// GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT
name|SRGB_BP_UNorm
init|=
literal|0x8E8D
comment|// GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB
block|}
enum|;
comment|// This is not used externally yet but is reserved to allow checking of
comment|// compatibility between texture formats
ifndef|#
directive|ifndef
name|Q_QDOC
enum|enum
name|TextureFormatClass
block|{
name|NoFormatClass
block|,
name|FormatClass_128Bit
block|,
name|FormatClass_96Bit
block|,
name|FormatClass_64Bit
block|,
name|FormatClass_48Bit
block|,
name|FormatClass_32Bit
block|,
name|FormatClass_24Bit
block|,
name|FormatClass_16Bit
block|,
name|FormatClass_8Bit
block|,
name|FormatClass_RGTC1_R
block|,
name|FormatClass_RGTC2_RG
block|,
name|FormatClass_BPTC_Unorm
block|,
name|FormatClass_BPTC_Float
block|,
name|FormatClass_S3TC_DXT1_RGB
block|,
name|FormatClass_S3TC_DXT1_RGBA
block|,
name|FormatClass_S3TC_DXT3_RGBA
block|,
name|FormatClass_S3TC_DXT5_RGBA
block|,
name|FormatClass_Unique
block|}
enum|;
endif|#
directive|endif
comment|// Storage allocation
name|void
name|setFormat
parameter_list|(
name|TextureFormat
name|format
parameter_list|)
function_decl|;
name|TextureFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
init|=
literal|1
parameter_list|,
name|int
name|depth
init|=
literal|1
parameter_list|)
function_decl|;
name|int
name|width
argument_list|()
specifier|const
expr_stmt|;
name|int
name|height
argument_list|()
specifier|const
expr_stmt|;
name|int
name|depth
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMipLevels
parameter_list|(
name|int
name|levels
parameter_list|)
function_decl|;
name|int
name|mipLevels
argument_list|()
specifier|const
expr_stmt|;
name|int
name|maximumMipLevels
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLayers
parameter_list|(
name|int
name|layers
parameter_list|)
function_decl|;
name|int
name|layers
argument_list|()
specifier|const
expr_stmt|;
name|int
name|faces
argument_list|()
specifier|const
expr_stmt|;
name|void
name|allocateStorage
parameter_list|()
function_decl|;
name|bool
name|isStorageAllocated
argument_list|()
specifier|const
expr_stmt|;
name|QOpenGLTexture
modifier|*
name|createTextureView
argument_list|(
name|Target
name|target
argument_list|,
name|TextureFormat
name|viewFormat
argument_list|,
name|int
name|minimumMipmapLevel
argument_list|,
name|int
name|maximumMipmapLevel
argument_list|,
name|int
name|minimumLayer
argument_list|,
name|int
name|maximumLayer
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isTextureView
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|CubeMapFace
block|{
name|CubeMapPositiveX
init|=
literal|0x8515
block|,
comment|// GL_TEXTURE_CUBE_MAP_POSITIVE_X
name|CubeMapNegativeX
init|=
literal|0x8516
block|,
comment|// GL_TEXTURE_CUBE_MAP_NEGATIVE_X
name|CubeMapPositiveY
init|=
literal|0x8517
block|,
comment|// GL_TEXTURE_CUBE_MAP_POSITIVE_Y
name|CubeMapNegativeY
init|=
literal|0x8518
block|,
comment|// GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
name|CubeMapPositiveZ
init|=
literal|0x8519
block|,
comment|// GL_TEXTURE_CUBE_MAP_POSITIVE_Z
name|CubeMapNegativeZ
init|=
literal|0x851A
comment|// GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
block|}
enum|;
enum|enum
name|PixelFormat
block|{
name|NoSourceFormat
init|=
literal|0
block|,
comment|// GL_NONE
name|Red
init|=
literal|0x1903
block|,
comment|// GL_RED
name|RG
init|=
literal|0x8227
block|,
comment|// GL_RG
name|RGB
init|=
literal|0x1907
block|,
comment|// GL_RGB
name|BGR
init|=
literal|0x80E0
block|,
comment|// GL_BGR
name|RGBA
init|=
literal|0x1908
block|,
comment|// GL_RGBA
name|BGRA
init|=
literal|0x80E1
block|,
comment|// GL_BGRA
name|Red_Integer
init|=
literal|0x8D94
block|,
comment|// GL_RED_INTEGER
name|RG_Integer
init|=
literal|0x8228
block|,
comment|// GL_RG_INTEGER
name|RGB_Integer
init|=
literal|0x8D98
block|,
comment|// GL_RGB_INTEGER
name|BGR_Integer
init|=
literal|0x8D9A
block|,
comment|// GL_BGR_INTEGER
name|RGBA_Integer
init|=
literal|0x8D99
block|,
comment|// GL_RGBA_INTEGER
name|BGRA_Integer
init|=
literal|0x8D9B
block|,
comment|// GL_BGRA_INTEGER
name|Depth
init|=
literal|0x1902
block|,
comment|// GL_DEPTH_COMPONENT
name|DepthStencil
init|=
literal|0x84F9
comment|// GL_DEPTH_STENCIL
block|}
enum|;
enum|enum
name|PixelType
block|{
name|NoPixelType
init|=
literal|0
block|,
comment|// GL_NONE
name|Int8
init|=
literal|0x1400
block|,
comment|// GL_BYTE
name|UInt8
init|=
literal|0x1401
block|,
comment|// GL_UNSIGNED_BYTE
name|Int16
init|=
literal|0x1402
block|,
comment|// GL_SHORT
name|UInt16
init|=
literal|0x1403
block|,
comment|// GL_UNSIGNED_SHORT
name|Int32
init|=
literal|0x1404
block|,
comment|// GL_INT
name|UInt32
init|=
literal|0x1405
block|,
comment|// GL_UNSIGNED_INT
name|Float16
init|=
literal|0x140B
block|,
comment|// GL_HALF_FLOAT
name|Float32
init|=
literal|0x1406
block|,
comment|// GL_FLOAT
name|UInt32_RGB9_E5
init|=
literal|0x8C3E
block|,
comment|// GL_UNSIGNED_INT_5_9_9_9_REV
name|UInt32_RG11B10F
init|=
literal|0x8C3B
block|,
comment|// GL_UNSIGNED_INT_10F_11F_11F_REV
name|UInt8_RG3B2
init|=
literal|0x8032
block|,
comment|// GL_UNSIGNED_BYTE_3_3_2
name|UInt8_RG3B2_Rev
init|=
literal|0x8362
block|,
comment|// GL_UNSIGNED_BYTE_2_3_3_REV
name|UInt16_RGB5A1
init|=
literal|0x8034
block|,
comment|// GL_UNSIGNED_SHORT_5_5_5_1
name|UInt16_RGB5A1_Rev
init|=
literal|0x8366
block|,
comment|// GL_UNSIGNED_SHORT_1_5_5_5_REV
name|UInt16_R5G6B5
init|=
literal|0x8363
block|,
comment|// GL_UNSIGNED_SHORT_5_6_5
name|UInt16_R5G6B5_Rev
init|=
literal|0x8364
block|,
comment|// GL_UNSIGNED_SHORT_5_6_5_REV
name|UInt16_RGBA4
init|=
literal|0x8033
block|,
comment|// GL_UNSIGNED_SHORT_4_4_4_4
name|UInt16_RGBA4_Rev
init|=
literal|0x8365
block|,
comment|// GL_UNSIGNED_SHORT_4_4_4_4_REV
name|UInt32_RGB10A2
init|=
literal|0x8036
block|,
comment|// GL_UNSIGNED_INT_10_10_10_2
name|UInt32_RGB10A2_Rev
init|=
literal|0x8368
comment|// GL_UNSIGNED_INT_2_10_10_10_REV
block|}
enum|;
comment|// Pixel transfer
name|void
name|setData
parameter_list|(
name|int
name|mipLevel
parameter_list|,
name|int
name|layer
parameter_list|,
name|CubeMapFace
name|cubeFace
parameter_list|,
name|PixelFormat
name|sourceFormat
parameter_list|,
name|PixelType
name|sourceType
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QOpenGLPixelTransferOptions
modifier|*
specifier|const
name|options
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setData
parameter_list|(
name|int
name|mipLevel
parameter_list|,
name|int
name|layer
parameter_list|,
name|PixelFormat
name|sourceFormat
parameter_list|,
name|PixelType
name|sourceType
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QOpenGLPixelTransferOptions
modifier|*
specifier|const
name|options
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setData
parameter_list|(
name|int
name|mipLevel
parameter_list|,
name|PixelFormat
name|sourceFormat
parameter_list|,
name|PixelType
name|sourceType
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QOpenGLPixelTransferOptions
modifier|*
specifier|const
name|options
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setData
parameter_list|(
name|PixelFormat
name|sourceFormat
parameter_list|,
name|PixelType
name|sourceType
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QOpenGLPixelTransferOptions
modifier|*
specifier|const
name|options
init|=
literal|0
parameter_list|)
function_decl|;
comment|// Compressed data upload
name|void
name|setCompressedData
parameter_list|(
name|int
name|mipLevel
parameter_list|,
name|int
name|layer
parameter_list|,
name|CubeMapFace
name|cubeFace
parameter_list|,
name|int
name|dataSize
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QOpenGLPixelTransferOptions
modifier|*
specifier|const
name|options
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setCompressedData
parameter_list|(
name|int
name|mipLevel
parameter_list|,
name|int
name|layer
parameter_list|,
name|int
name|dataSize
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QOpenGLPixelTransferOptions
modifier|*
specifier|const
name|options
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setCompressedData
parameter_list|(
name|int
name|mipLevel
parameter_list|,
name|int
name|dataSize
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QOpenGLPixelTransferOptions
modifier|*
specifier|const
name|options
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|setCompressedData
parameter_list|(
name|int
name|dataSize
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QOpenGLPixelTransferOptions
modifier|*
specifier|const
name|options
init|=
literal|0
parameter_list|)
function_decl|;
comment|// Helpful overloads for setData
name|void
name|setData
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|MipMapGeneration
name|genMipMaps
init|=
name|GenerateMipMaps
parameter_list|)
function_decl|;
comment|// Features
enum|enum
name|Feature
block|{
name|ImmutableStorage
init|=
literal|0x00000001
block|,
name|ImmutableMultisampleStorage
init|=
literal|0x00000002
block|,
name|TextureRectangle
init|=
literal|0x00000004
block|,
name|TextureArrays
init|=
literal|0x00000008
block|,
name|Texture3D
init|=
literal|0x00000010
block|,
name|TextureMultisample
init|=
literal|0x00000020
block|,
name|TextureBuffer
init|=
literal|0x00000040
block|,
name|TextureCubeMapArrays
init|=
literal|0x00000080
block|,
name|Swizzle
init|=
literal|0x00000100
block|,
name|StencilTexturing
init|=
literal|0x00000200
block|,
name|AnisotropicFiltering
init|=
literal|0x00000400
block|,
name|NPOTTextures
init|=
literal|0x00000800
block|,
name|NPOTTextureRepeat
init|=
literal|0x00001000
block|,
ifndef|#
directive|ifndef
name|Q_QDOC
name|MaxFeatureFlag
init|=
literal|0x00002000
endif|#
directive|endif
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Features
argument_list|,
argument|Feature
argument_list|)
specifier|static
name|bool
name|hasFeature
parameter_list|(
name|Feature
name|feature
parameter_list|)
function_decl|;
comment|// Texture Parameters
name|void
name|setMipBaseLevel
parameter_list|(
name|int
name|baseLevel
parameter_list|)
function_decl|;
name|int
name|mipBaseLevel
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMipMaxLevel
parameter_list|(
name|int
name|maxLevel
parameter_list|)
function_decl|;
name|int
name|mipMaxLevel
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMipLevelRange
parameter_list|(
name|int
name|baseLevel
parameter_list|,
name|int
name|maxLevel
parameter_list|)
function_decl|;
name|QPair
operator|<
name|int
operator|,
name|int
operator|>
name|mipLevelRange
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAutoMipMapGenerationEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|isAutoMipMapGenerationEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|generateMipMaps
parameter_list|()
function_decl|;
name|void
name|generateMipMaps
parameter_list|(
name|int
name|baseLevel
parameter_list|,
name|bool
name|resetBaseLevel
init|=
name|true
parameter_list|)
function_decl|;
enum|enum
name|SwizzleComponent
block|{
name|SwizzleRed
init|=
literal|0x8E42
block|,
comment|// GL_TEXTURE_SWIZZLE_R
name|SwizzleGreen
init|=
literal|0x8E43
block|,
comment|// GL_TEXTURE_SWIZZLE_G
name|SwizzleBlue
init|=
literal|0x8E44
block|,
comment|// GL_TEXTURE_SWIZZLE_B
name|SwizzleAlpha
init|=
literal|0x8E45
comment|// GL_TEXTURE_SWIZZLE_A
block|}
enum|;
enum|enum
name|SwizzleValue
block|{
name|RedValue
init|=
literal|0x1903
block|,
comment|// GL_RED
name|GreenValue
init|=
literal|0x1904
block|,
comment|// GL_GREEN
name|BlueValue
init|=
literal|0x1905
block|,
comment|// GL_BLUE
name|AlphaValue
init|=
literal|0x1906
block|,
comment|// GL_ALPHA
name|ZeroValue
init|=
literal|0
block|,
comment|// GL_ZERO
name|OneValue
init|=
literal|1
comment|// GL_ONE
block|}
enum|;
name|void
name|setSwizzleMask
parameter_list|(
name|SwizzleComponent
name|component
parameter_list|,
name|SwizzleValue
name|value
parameter_list|)
function_decl|;
name|void
name|setSwizzleMask
parameter_list|(
name|SwizzleValue
name|r
parameter_list|,
name|SwizzleValue
name|g
parameter_list|,
name|SwizzleValue
name|b
parameter_list|,
name|SwizzleValue
name|a
parameter_list|)
function_decl|;
name|SwizzleValue
name|swizzleMask
argument_list|(
name|SwizzleComponent
name|component
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|DepthStencilMode
block|{
name|DepthMode
init|=
literal|0x1902
block|,
comment|// GL_DEPTH_COMPONENT
name|StencilMode
init|=
literal|0x1901
comment|// GL_STENCIL_INDEX
block|}
enum|;
name|void
name|setDepthStencilMode
parameter_list|(
name|DepthStencilMode
name|mode
parameter_list|)
function_decl|;
name|DepthStencilMode
name|depthStencilMode
argument_list|()
specifier|const
expr_stmt|;
comment|// Sampling Parameters
enum|enum
name|Filter
block|{
name|Nearest
init|=
literal|0x2600
block|,
comment|// GL_NEAREST
name|Linear
init|=
literal|0x2601
block|,
comment|// GL_LINEAR
name|NearestMipMapNearest
init|=
literal|0x2700
block|,
comment|// GL_NEAREST_MIPMAP_NEAREST
name|NearestMipMapLinear
init|=
literal|0x2702
block|,
comment|// GL_NEAREST_MIPMAP_LINEAR
name|LinearMipMapNearest
init|=
literal|0x2701
block|,
comment|// GL_LINEAR_MIPMAP_NEAREST
name|LinearMipMapLinear
init|=
literal|0x2703
comment|// GL_LINEAR_MIPMAP_LINEAR
block|}
enum|;
name|void
name|setMinificationFilter
parameter_list|(
name|Filter
name|filter
parameter_list|)
function_decl|;
name|Filter
name|minificationFilter
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMagnificationFilter
parameter_list|(
name|Filter
name|filter
parameter_list|)
function_decl|;
name|Filter
name|magnificationFilter
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMinMagFilters
parameter_list|(
name|Filter
name|minificationFilter
parameter_list|,
name|Filter
name|magnificationFilter
parameter_list|)
function_decl|;
name|QPair
operator|<
name|Filter
operator|,
name|Filter
operator|>
name|minMagFilters
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMaximumAnisotropy
parameter_list|(
name|float
name|anisotropy
parameter_list|)
function_decl|;
name|float
name|maximumAnisotropy
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|WrapMode
block|{
name|Repeat
init|=
literal|0x2901
block|,
comment|// GL_REPEAT
name|MirroredRepeat
init|=
literal|0x8370
block|,
comment|// GL_MIRRORED_REPEAT
name|ClampToEdge
init|=
literal|0x812F
block|,
comment|// GL_CLAMP_TO_EDGE
name|ClampToBorder
init|=
literal|0x812D
comment|// GL_CLAMP_TO_BORDER
block|}
enum|;
enum|enum
name|CoordinateDirection
block|{
name|DirectionS
init|=
literal|0x2802
block|,
comment|// GL_TEXTURE_WRAP_S
name|DirectionT
init|=
literal|0x2803
block|,
comment|// GL_TEXTURE_WRAP_T
name|DirectionR
init|=
literal|0x8072
comment|// GL_TEXTURE_WRAP_R
block|}
enum|;
name|void
name|setWrapMode
parameter_list|(
name|WrapMode
name|mode
parameter_list|)
function_decl|;
name|void
name|setWrapMode
parameter_list|(
name|CoordinateDirection
name|direction
parameter_list|,
name|WrapMode
name|mode
parameter_list|)
function_decl|;
name|WrapMode
name|wrapMode
argument_list|(
name|CoordinateDirection
name|direction
argument_list|)
decl|const
decl_stmt|;
name|void
name|setBorderColor
parameter_list|(
name|QColor
name|color
parameter_list|)
function_decl|;
name|void
name|setBorderColor
parameter_list|(
name|float
name|r
parameter_list|,
name|float
name|g
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|a
parameter_list|)
function_decl|;
name|void
name|setBorderColor
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|g
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|a
parameter_list|)
function_decl|;
name|void
name|setBorderColor
parameter_list|(
name|uint
name|r
parameter_list|,
name|uint
name|g
parameter_list|,
name|uint
name|b
parameter_list|,
name|uint
name|a
parameter_list|)
function_decl|;
name|QColor
name|borderColor
argument_list|()
specifier|const
expr_stmt|;
name|void
name|borderColor
argument_list|(
name|float
operator|*
name|border
argument_list|)
decl|const
decl_stmt|;
name|void
name|borderColor
argument_list|(
name|int
operator|*
name|border
argument_list|)
decl|const
decl_stmt|;
name|void
name|borderColor
argument_list|(
name|unsigned
name|int
operator|*
name|border
argument_list|)
decl|const
decl_stmt|;
name|void
name|setMinimumLevelOfDetail
parameter_list|(
name|float
name|value
parameter_list|)
function_decl|;
name|float
name|minimumLevelOfDetail
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMaximumLevelOfDetail
parameter_list|(
name|float
name|value
parameter_list|)
function_decl|;
name|float
name|maximumLevelOfDetail
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLevelOfDetailRange
parameter_list|(
name|float
name|min
parameter_list|,
name|float
name|max
parameter_list|)
function_decl|;
name|QPair
operator|<
name|float
operator|,
name|float
operator|>
name|levelOfDetailRange
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLevelofDetailBias
parameter_list|(
name|float
name|bias
parameter_list|)
function_decl|;
name|float
name|levelofDetailBias
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLTexture
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLTexture
argument_list|)
name|QScopedPointer
operator|<
name|QOpenGLTexturePrivate
operator|>
name|d_ptr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QOpenGLTexture::Features
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGLABSTRACTTEXTURE_H
end_comment
end_unit
