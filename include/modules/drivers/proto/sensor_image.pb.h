#pragma once
#include "modules/common/proto/header.pb.h"
#include "apollo_msgs/msg/apollodrivers_image.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_image.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversImage Image;
}
#include "apollo_msgs/msg/apollodrivers_compressed_image.hpp"
#include "adapter/serialization/apollo_msgs/apollodrivers_compressed_image.hpp"
namespace apollo::drivers{
	typedef apollo_msgs::msg::ApollodriversCompressedImage CompressedImage;
}
namespace apollo::drivers{
	enum PixelFormat {
		RGB8 = 1001,
		RGBA8 = 1002,
		RGB16 = 1003,
		RGBA16 = 1004,
		BGR8 = 1005,
		BGRA8 = 1006,
		BGR16 = 1007,
		BGRA16 = 1008,
		MONO8 = 1009,
		MONO16 = 1010,
		
		// OpenCV CvMat types
		TYPE_8UC1 = 2001,
		TYPE_8UC2 = 2002,
		TYPE_8UC3 = 2003,
		TYPE_8UC4 = 2004,
		TYPE_8SC1 = 2005,
		TYPE_8SC2 = 2006,
		TYPE_8SC3 = 2007,
		TYPE_8SC4 = 2008,
		TYPE_16UC1 = 2009,
		TYPE_16UC2 = 2010,
		TYPE_16UC3 = 2011,
		TYPE_16UC4 = 2012,
		TYPE_16SC1 = 2013,
		TYPE_16SC2 = 2014,
		TYPE_16SC3 = 2015,
		TYPE_16SC4 = 2016,
		TYPE_32SC1 = 2017,
		TYPE_32SC2 = 2018,
		TYPE_32SC3 = 2019,
		TYPE_32SC4 = 2020,
		TYPE_32FC1 = 2021,
		TYPE_32FC2 = 2022,
		TYPE_32FC3 = 2023,
		TYPE_32FC4 = 2024,
		TYPE_64FC1 = 2025,
		TYPE_64FC2 = 2026,
		TYPE_64FC3 = 2027,
		TYPE_64FC4 = 2028,
		
		// Bayer encodings
		BAYER_RGGB8 = 3001,
		BAYER_BGGR8 = 3002,
		BAYER_GBRG8 = 3003,
		BAYER_GRBG8 = 3004,
		BAYER_RGGB16 = 3005,
		BAYER_BGGR16 = 3006,
		BAYER_GBRG16 = 3007,
		BAYER_GRBG16 = 3008,
		
		// Miscellaneous
		// This is the UYVY version of YUV422 codec http://www.fourcc.org/yuv.php#UYVY
		// with an 8-bit depth
		YUV422 = 4001
	};
}