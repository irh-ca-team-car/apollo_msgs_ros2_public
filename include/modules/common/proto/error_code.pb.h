#pragma once
#include "apollo_msgs/msg/apollocommon_status_pb.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_status_pb.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonStatusPb StatusPb;
}
namespace apollo::common{
	enum ErrorCode {
		// No error, returns on success.
		OK = 0,
		
		// Control module error codes start from here.
		CONTROL_ERROR = 1000,
		CONTROL_INIT_ERROR = 1001,
		CONTROL_COMPUTE_ERROR = 1002,
		CONTROL_ESTOP_ERROR = 1003,
		PERFECT_CONTROL_ERROR = 1004,
		
		// Canbus module error codes start from here.
		CANBUS_ERROR = 2000,
		CAN_CLIENT_ERROR_BASE = 2100,
		CAN_CLIENT_ERROR_OPEN_DEVICE_FAILED = 2101,
		CAN_CLIENT_ERROR_FRAME_NUM = 2102,
		CAN_CLIENT_ERROR_SEND_FAILED = 2103,
		CAN_CLIENT_ERROR_RECV_FAILED = 2104,
		
		// Localization module error codes start from here.
		LOCALIZATION_ERROR = 3000,
		LOCALIZATION_ERROR_MSG = 3100,
		LOCALIZATION_ERROR_LIDAR = 3200,
		LOCALIZATION_ERROR_INTEG = 3300,
		LOCALIZATION_ERROR_GNSS = 3400,
		
		// Perception module error codes start from here.
		PERCEPTION_ERROR = 4000,
		PERCEPTION_ERROR_TF = 4001,
		PERCEPTION_ERROR_PROCESS = 4002,
		PERCEPTION_FATAL = 4003,
		PERCEPTION_ERROR_NONE = 4004,
		PERCEPTION_ERROR_UNKNOWN = 4005,
		
		// Prediction module error codes start from here.
		PREDICTION_ERROR = 5000,
		
		// Planning module error codes start from here
		PLANNING_ERROR = 6000,
		PLANNING_ERROR_NOT_READY = 6001,
		
		// HDMap module error codes start from here
		HDMAP_DATA_ERROR = 7000,
		
		// Routing module error codes
		ROUTING_ERROR = 8000,
		ROUTING_ERROR_REQUEST = 8001,
		ROUTING_ERROR_RESPONSE = 8002,
		ROUTING_ERROR_NOT_READY = 8003,
		
		// Indicates an input has been exhausted.
		END_OF_INPUT = 9000,
		
		// HTTP request error codes.
		HTTP_LOGIC_ERROR = 10000,
		HTTP_RUNTIME_ERROR = 10001,
		
		// Relative Map error codes.
		RELATIVE_MAP_ERROR = 11000,  // general relative map error code
		RELATIVE_MAP_NOT_READY = 11001,
		
		// Driver error codes.
		DRIVER_ERROR_GNSS = 12000,
		DRIVER_ERROR_VELODYNE = 13000,
		
		// Storytelling error codes.
		STORYTELLING_ERROR = 14000
	};
}