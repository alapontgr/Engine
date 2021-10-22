////////////////////////////////////////////////////////////////////////////////
//
//	Author: Sergio Alapont Granero (seralgrainf@gmail.com)
//	Date: 	2019/02/24
//	File: 	GfGraphicResourcesShared_Platform.inl
//
//	Copyright (c) 2018 (See README.md)
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __GFGRAPHICRESOURCESSHARED_PLATFORM_INL__
#define __GFGRAPHICRESOURCESSHARED_PLATFORM_INL__
////////////////////////////////////////////////////////////////////////////////

static const VkFormat g_pTextureFormatConverter[] =
{
	VK_FORMAT_UNDEFINED,
	// 2-comp, 8b
	VK_FORMAT_R4G4_UNORM_PACK8,
	// 4-comp, 16b
	VK_FORMAT_R4G4B4A4_UNORM_PACK16,
	VK_FORMAT_B4G4R4A4_UNORM_PACK16,
	// 3-comp, 16b
	VK_FORMAT_R5G6B5_UNORM_PACK16,
	VK_FORMAT_B5G6R5_UNORM_PACK16,
	// 4-comp, 16b
	VK_FORMAT_R5G5B5A1_UNORM_PACK16,
	VK_FORMAT_B5G5R5A1_UNORM_PACK16,
	VK_FORMAT_A1R5G5B5_UNORM_PACK16,
	// 8b
	VK_FORMAT_R8_UNORM,
	VK_FORMAT_R8_SNORM,
	VK_FORMAT_R8_USCALED,
	VK_FORMAT_R8_SSCALED,
	VK_FORMAT_R8_UINT,
	VK_FORMAT_R8_SINT,
	VK_FORMAT_R8_SRGB,
	// 2-comp, 16b
	VK_FORMAT_R8G8_UNORM,
	VK_FORMAT_R8G8_SNORM,
	VK_FORMAT_R8G8_USCALED,
	VK_FORMAT_R8G8_SSCALED,
	VK_FORMAT_R8G8_UINT,
	VK_FORMAT_R8G8_SINT,
	VK_FORMAT_R8G8_SRGB,
	// 3-comp, 24b
	VK_FORMAT_R8G8B8_UNORM,
	VK_FORMAT_R8G8B8_SNORM,
	VK_FORMAT_R8G8B8_USCALED,
	VK_FORMAT_R8G8B8_SSCALED,
	VK_FORMAT_R8G8B8_UINT,
	VK_FORMAT_R8G8B8_SINT,
	VK_FORMAT_R8G8B8_SRGB,
	VK_FORMAT_B8G8R8_UNORM,
	VK_FORMAT_B8G8R8_SNORM,
	VK_FORMAT_B8G8R8_USCALED,
	VK_FORMAT_B8G8R8_SSCALED,
	VK_FORMAT_B8G8R8_UINT,
	VK_FORMAT_B8G8R8_SINT,
	VK_FORMAT_B8G8R8_SRGB,
	// 4-comp, 32b
	VK_FORMAT_R8G8B8A8_UNORM,
	VK_FORMAT_R8G8B8A8_SNORM,
	VK_FORMAT_R8G8B8A8_USCALED,
	VK_FORMAT_R8G8B8A8_SSCALED,
	VK_FORMAT_R8G8B8A8_UINT,
	VK_FORMAT_R8G8B8A8_SINT,
	VK_FORMAT_R8G8B8A8_SRGB,
	VK_FORMAT_B8G8R8A8_UNORM,
	VK_FORMAT_B8G8R8A8_SNORM,
	VK_FORMAT_B8G8R8A8_USCALED,
	VK_FORMAT_B8G8R8A8_SSCALED,
	VK_FORMAT_B8G8R8A8_UINT,
	VK_FORMAT_B8G8R8A8_SINT,
	VK_FORMAT_B8G8R8A8_SRGB,
	VK_FORMAT_A8B8G8R8_UNORM_PACK32,
	VK_FORMAT_A8B8G8R8_SNORM_PACK32,
	VK_FORMAT_A8B8G8R8_USCALED_PACK32,
	VK_FORMAT_A8B8G8R8_SSCALED_PACK32,
	VK_FORMAT_A8B8G8R8_UINT_PACK32,
	VK_FORMAT_A8B8G8R8_SINT_PACK32,
	VK_FORMAT_A8B8G8R8_SRGB_PACK32,
	// 4-comp, 32b (Special packing)
	VK_FORMAT_A2R10G10B10_UNORM_PACK32,
	VK_FORMAT_A2R10G10B10_SNORM_PACK32,
	VK_FORMAT_A2R10G10B10_USCALED_PACK32,
	VK_FORMAT_A2R10G10B10_SSCALED_PACK32,
	VK_FORMAT_A2R10G10B10_UINT_PACK32,
	VK_FORMAT_A2R10G10B10_SINT_PACK32,
	VK_FORMAT_A2B10G10R10_UNORM_PACK32,
	VK_FORMAT_A2B10G10R10_SNORM_PACK32,
	VK_FORMAT_A2B10G10R10_USCALED_PACK32,
	VK_FORMAT_A2B10G10R10_SSCALED_PACK32,
	VK_FORMAT_A2B10G10R10_UINT_PACK32,
	VK_FORMAT_A2B10G10R10_SINT_PACK32,
	// 1-comp, 16b
	VK_FORMAT_R16_UNORM,
	VK_FORMAT_R16_SNORM,
	VK_FORMAT_R16_USCALED,
	VK_FORMAT_R16_SSCALED,
	VK_FORMAT_R16_UINT,
	VK_FORMAT_R16_SINT,
	VK_FORMAT_R16_SFLOAT,
	// 2-comp, 32b
	VK_FORMAT_R16G16_UNORM,
	VK_FORMAT_R16G16_SNORM,
	VK_FORMAT_R16G16_USCALED,
	VK_FORMAT_R16G16_SSCALED,
	VK_FORMAT_R16G16_UINT,
	VK_FORMAT_R16G16_SINT,
	VK_FORMAT_R16G16_SFLOAT,
	// 3-comp, 48b
	VK_FORMAT_R16G16B16_UNORM,
	VK_FORMAT_R16G16B16_SNORM,
	VK_FORMAT_R16G16B16_USCALED,
	VK_FORMAT_R16G16B16_SSCALED,
	VK_FORMAT_R16G16B16_UINT,
	VK_FORMAT_R16G16B16_SINT,
	VK_FORMAT_R16G16B16_SFLOAT,
	// 4-comp, 64b
	VK_FORMAT_R16G16B16A16_UNORM,
	VK_FORMAT_R16G16B16A16_SNORM,
	VK_FORMAT_R16G16B16A16_USCALED,
	VK_FORMAT_R16G16B16A16_SSCALED,
	VK_FORMAT_R16G16B16A16_UINT,
	VK_FORMAT_R16G16B16A16_SINT,
	VK_FORMAT_R16G16B16A16_SFLOAT,
	// 1-comp, 32b
	VK_FORMAT_R32_UINT,
	VK_FORMAT_R32_SINT,
	VK_FORMAT_R32_SFLOAT,
	// 2-comp, 64b
	VK_FORMAT_R32G32_UINT,
	VK_FORMAT_R32G32_SINT,
	VK_FORMAT_R32G32_SFLOAT,
	// 3-comp, 86b
	VK_FORMAT_R32G32B32_UINT,
	VK_FORMAT_R32G32B32_SINT,
	VK_FORMAT_R32G32B32_SFLOAT,
	// 4-comp, 128b
	VK_FORMAT_R32G32B32A32_UINT,
	VK_FORMAT_R32G32B32A32_SINT,
	VK_FORMAT_R32G32B32A32_SFLOAT,
	// 1-comp, 64b
	VK_FORMAT_R64_UINT,
	VK_FORMAT_R64_SINT,
	VK_FORMAT_R64_SFLOAT,
	// 2-comp, 128b
	VK_FORMAT_R64G64_UINT,
	VK_FORMAT_R64G64_SINT,
	VK_FORMAT_R64G64_SFLOAT,
	// 3-comp, 192b
	VK_FORMAT_R64G64B64_UINT,
	VK_FORMAT_R64G64B64_SINT,
	VK_FORMAT_R64G64B64_SFLOAT,
	// 4-comp, 256b
	VK_FORMAT_R64G64B64A64_UINT,
	VK_FORMAT_R64G64B64A64_SINT,
	VK_FORMAT_R64G64B64A64_SFLOAT,

	// (special packing)
	VK_FORMAT_B10G11R11_UFLOAT_PACK32,
	VK_FORMAT_E5B9G9R9_UFLOAT_PACK32,

	// Depth formats
	VK_FORMAT_D16_UNORM,
	VK_FORMAT_X8_D24_UNORM_PACK32,
	VK_FORMAT_D32_SFLOAT,

	// Stencil formats
	VK_FORMAT_S8_UINT,

	// Depth-Stencil formats
	VK_FORMAT_D16_UNORM_S8_UINT	,
	VK_FORMAT_D24_UNORM_S8_UINT	,
	VK_FORMAT_D32_SFLOAT_S8_UINT,

	// Block compression formats
	VK_FORMAT_BC1_RGB_UNORM_BLOCK,
	VK_FORMAT_BC1_RGB_SRGB_BLOCK,
	VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
	VK_FORMAT_BC1_RGBA_SRGB_BLOCK,
	VK_FORMAT_BC2_UNORM_BLOCK,
	VK_FORMAT_BC2_SRGB_BLOCK,
	VK_FORMAT_BC3_UNORM_BLOCK,
	VK_FORMAT_BC3_SRGB_BLOCK,
	VK_FORMAT_BC4_UNORM_BLOCK,
	VK_FORMAT_BC4_SNORM_BLOCK,
	VK_FORMAT_BC5_UNORM_BLOCK,
	VK_FORMAT_BC5_SNORM_BLOCK,
	VK_FORMAT_BC6H_UFLOAT_BLOCK,
	VK_FORMAT_BC6H_SFLOAT_BLOCK,
	VK_FORMAT_BC7_UNORM_BLOCK,
	VK_FORMAT_BC7_SRGB_BLOCK,
};

////////////////////////////////////////////////////////////////////////////////

static const VkImageUsageFlagBits g_pImageUsageBitsConverter[] =
{
	VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
	VK_IMAGE_USAGE_TRANSFER_DST_BIT,
	VK_IMAGE_USAGE_SAMPLED_BIT,
	VK_IMAGE_USAGE_STORAGE_BIT,
	VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
	VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
	VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT,
	VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT,
};

////////////////////////////////////////////////////////////////////////////////

static const VkImageViewType g_pViewTypeConverter[] =
{
	VK_IMAGE_VIEW_TYPE_1D,
	VK_IMAGE_VIEW_TYPE_2D,
	VK_IMAGE_VIEW_TYPE_3D,
	VK_IMAGE_VIEW_TYPE_CUBE,
	VK_IMAGE_VIEW_TYPE_1D_ARRAY,
	VK_IMAGE_VIEW_TYPE_2D_ARRAY,
	VK_IMAGE_VIEW_TYPE_CUBE_ARRAY
};

////////////////////////////////////////////////////////////////////////////////

static const VkFilter g_pTexFilterConverter[] =
{
	VK_FILTER_NEAREST,
	VK_FILTER_LINEAR,
	VK_FILTER_CUBIC_IMG,
};

////////////////////////////////////////////////////////////////////////////////

static const VkSamplerMipmapMode g_pSamplerMipMapModeConverter[] =
{
	VK_SAMPLER_MIPMAP_MODE_NEAREST,
	VK_SAMPLER_MIPMAP_MODE_LINEAR,
};

////////////////////////////////////////////////////////////////////////////////

static const VkSamplerAddressMode g_pTexAddressModeConverter[] =
{
	VK_SAMPLER_ADDRESS_MODE_REPEAT,
	VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT,
	VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
	VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER,
	VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE,
};

////////////////////////////////////////////////////////////////////////////////

static GF_FORCEINLINE VkFormat ConvertTextureFormat(GfTextureFormat::Type eTextureFormat)
{
	return g_pTextureFormatConverter[eTextureFormat];
}

static GF_FORCEINLINE GfTextureFormat::Type ConvertTextureFormatToVkFormat(VkFormat eTextureFormat)
{
	for (u32 i=0;i<GfTextureFormat::COUNT; ++i)
	{
		if (g_pTextureFormatConverter[i] == eTextureFormat) 
		{
			return (GfTextureFormat::Type)i;
		}
	}
	return GfTextureFormat::Undefined;
}


////////////////////////////////////////////////////////////////////////////////

static GF_FORCEINLINE VkImageUsageFlags ConvertTextureUsageShift(ETextureUsageShift::Type eShift)
{
	return g_pImageUsageBitsConverter[eShift];
}

////////////////////////////////////////////////////////////////////////////////

static GF_FORCEINLINE VkImageViewType ConvertViewType(ETextureViewType::Type eViewType)
{
	return g_pViewTypeConverter[eViewType];
}

////////////////////////////////////////////////////////////////////////////////

static GF_FORCEINLINE VkFilter ConvertTexFilter(ETexFilter::Type eTexFilter)
{
	return g_pTexFilterConverter[eTexFilter];
}

////////////////////////////////////////////////////////////////////////////////

static GF_FORCEINLINE VkSamplerMipmapMode ConvertTexMipMapMode(ESamplerMipMapMode::Type eMipMapMode)
{
	return g_pSamplerMipMapModeConverter[eMipMapMode];
}

////////////////////////////////////////////////////////////////////////////////

static GF_FORCEINLINE VkSamplerAddressMode ConvertTexAddressMode(ETexAddressMode::Type eTexAddressMode)
{
	return g_pTexAddressModeConverter[eTexAddressMode];
}

////////////////////////////////////////////////////////////////////////////////
#endif // __GFGRAPHICRESOURCESSHARED_PLATFORM_H__