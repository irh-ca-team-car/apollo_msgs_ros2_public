#pragma once
#include "apollo_msgs/msg/apollocyberproto_single_index.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_single_index.hpp"
#include "apollo_msgs/msg/apollocyberproto_chunk_header_cache.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_chunk_header_cache.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChunkHeaderCache ChunkHeaderCache;
}
#include "apollo_msgs/msg/apollocyberproto_chunk_body_cache.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_chunk_body_cache.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChunkBodyCache ChunkBodyCache;
}
#include "apollo_msgs/msg/apollocyberproto_channel_cache.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_channel_cache.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChannelCache ChannelCache;
}
#include "apollo_msgs/msg/apollocyberproto_single_message.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_single_message.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoSingleMessage SingleMessage;
}
#include "apollo_msgs/msg/apollocyberproto_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_header.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoHeader Header;
}
#include "apollo_msgs/msg/apollocyberproto_channel.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_channel.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChannel Channel;
}
#include "apollo_msgs/msg/apollocyberproto_chunk_header.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_chunk_header.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChunkHeader ChunkHeader;
}
#include "apollo_msgs/msg/apollocyberproto_chunk_body.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_chunk_body.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoChunkBody ChunkBody;
}
#include "apollo_msgs/msg/apollocyberproto_index.hpp"
#include "adapter/serialization/apollo_msgs/apollocyberproto_index.hpp"
namespace apollo::cyber::proto{
	typedef apollo_msgs::msg::ApollocyberprotoIndex Index;
}
namespace apollo::cyber::proto{
	enum SectionType {
		SECTION_HEADER = 0,
		SECTION_CHUNK_HEADER = 1,
		SECTION_CHUNK_BODY = 2,
		SECTION_INDEX = 3,
		SECTION_CHANNEL = 4
	};
}
namespace apollo::cyber::proto{
	enum CompressType {
		COMPRESS_NONE = 0,
		COMPRESS_BZ2 = 1,
		COMPRESS_LZ4 = 2
	};
}