#pragma once
#include "apollo_msgs/msg/apollolocalization_msf_sensor_msg_status.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_msf_sensor_msg_status.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationMsfSensorMsgStatus MsfSensorMsgStatus;
}
#include "apollo_msgs/msg/apollolocalization_msf_status.hpp"
#include "adapter/serialization/apollo_msgs/apollolocalization_msf_status.hpp"
namespace apollo::localization{
	typedef apollo_msgs::msg::ApollolocalizationMsfStatus MsfStatus;
}
namespace apollo::localization{
	enum LocalLidarStatus {
		MSF_LOCAL_LIDAR_NORMAL = 0,       // Localization result satisfy threshold
		MSF_LOCAL_LIDAR_MAP_MISSING = 1,  // Can't find localization map (config.xml)
		MSF_LOCAL_LIDAR_EXTRINSICS_MISSING = 2,  // Missing extrinsic parameters
		MSF_LOCAL_LIDAR_MAP_LOADING_FAILED = 3,  // Fail to load localization map
		MSF_LOCAL_LIDAR_NO_OUTPUT =
		4,  // No output (comparing to timestamp of imu msg)
		MSF_LOCAL_LIDAR_OUT_OF_MAP =
		5,  // Coverage of online pointcloud and map is lower than threshold
		MSF_LOCAL_LIDAR_NOT_GOOD = 6,  // Localization result do not meet threshold
		MSF_LOCAL_LIDAR_UNDEFINED_STATUS = 7  // others
	};
}
namespace apollo::localization{
	enum LocalLidarQuality {
		MSF_LOCAL_LIDAR_VERY_GOOD = 0,
		MSF_LOCAL_LIDAR_GOOD = 1,
		MSF_LOCAL_LIDAR_NOT_BAD = 2,
		MSF_LOCAL_LIDAR_BAD = 3
	};
}
namespace apollo::localization{
	enum LocalLidarConsistency {
		MSF_LOCAL_LIDAR_CONSISTENCY_00 =
		0,  // The difference is less than threshold 1
		MSF_LOCAL_LIDAR_CONSISTENCY_01 =
		1,  // The difference is bigger than threshold 1 but less than threshold 2
		MSF_LOCAL_LIDAR_CONSISTENCY_02 =
		2,  // The difference is bigger than threshold 2
		MSF_LOCAL_LIDAR_CONSISTENCY_03 = 3  // others
	};
}
namespace apollo::localization{
	enum GnssConsistency {
		MSF_GNSS_CONSISTENCY_00 = 0,  // The difference is less than threshold 1
		MSF_GNSS_CONSISTENCY_01 =
		1,  // The difference is bigger than threshold 1 but less than threshold 2
		MSF_GNSS_CONSISTENCY_02 = 2,  // The difference is bigger than threshold 2
		MSF_GNSS_CONSISTENCY_03 = 3  // others
	};
}
namespace apollo::localization{
	enum GnssPositionType {
		NONE = 0,         // No solution
		FIXEDPOS = 1,     // Position has been fixed by the FIX POSITION command or by
		// position averaging
		FIXEDHEIGHT = 2,  // Position has been fixed by the FIX HEIGHT, or FIX AUTO,
		// command or by position averaging
		FLOATCONV = 4,    // Solution from floating point carrier phase anbiguities
		WIDELANE = 5,     // Solution from wide-lane ambiguities
		NARROWLANE = 6,   // Solution from narrow-lane ambiguities
		DOPPLER_VELOCITY = 8,  // Velocity computed using instantaneous Doppler
		SINGLE = 16,           // Single point position
		PSRDIFF = 17,          // Pseudorange differential solution
		WAAS = 18,             // Solution calculated using corrections from an SBAS
		PROPOGATED = 19,  // Propagated by a Kalman filter without new observations
		OMNISTAR = 20,    // OmniSTAR VBS position
		L1_FLOAT = 32,    // Floating L1 albiguity solution
		IONOFREE_FLOAT = 33,  // Floating ionospheric free ambiguity solution
		NARROW_FLOAT = 34,    // Floating narrow-lane anbiguity solution
		L1_INT = 48,          // Integer L1 ambiguity solution
		WIDE_INT = 49,        // Integer wide-lane ambiguity solution
		NARROW_INT = 50,      // Integer narrow-lane ambiguity solution
		RTK_DIRECT_INS = 51,  // RTK status where RTK filter is directly initialized
		// from the INS filter
		INS_SBAS = 52,        // INS calculated position corrected for the antenna
		INS_PSRSP =
		53,  // INS pseudorange single point solution - no DGPS corrections
		INS_PSRDIFF = 54,         // INS pseudorange differential solution
		INS_RTKFLOAT = 55,        // INS RTK float point ambiguities solution
		INS_RTKFIXED = 56,        // INS RTK fixed ambiguities solution
		INS_OMNISTAR = 57,        // INS OmniSTAR VBS solution
		INS_OMNISTAR_HP = 58,     // INS OmniSTAR high precision solution
		INS_OMNISTAR_XP = 59,     // INS OmniSTAR extra precision solution
		OMNISTAR_HP = 64,         // OmniSTAR high precision
		OMNISTAR_XP = 65,         // OmniSTAR extra precision
		PPP_CONVERGING = 68,      // Precise Point Position(PPP) solution converging
		PPP = 69,                 // Precise Point Position(PPP)solution
		INS_PPP_Converging = 73,  // INS NovAtel CORRECT Precise Point Position(PPP)
		// solution converging
		INS_PPP = 74,   // INS NovAtel CORRECT Precise Point Position(PPP) solution
		MSG_LOSS = 91  // Gnss position message loss
	};
}
namespace apollo::localization{
	enum ImuMsgDelayStatus {
		IMU_DELAY_NORMAL = 0,
		IMU_DELAY_1 = 1,
		IMU_DELAY_2 = 2,
		IMU_DELAY_3 = 3,
		IMU_DELAY_ABNORMAL = 4
	};
}
namespace apollo::localization{
	enum ImuMsgMissingStatus {
		IMU_MISSING_NORMAL = 0,
		IMU_MISSING_1 = 1,
		IMU_MISSING_2 = 2,
		IMU_MISSING_3 = 3,
		IMU_MISSING_4 = 4,
		IMU_MISSING_5 = 5,
		IMU_MISSING_ABNORMAL = 6
	};
}
namespace apollo::localization{
	enum ImuMsgDataStatus {
		IMU_DATA_NORMAL = 0,
		IMU_DATA_ABNORMAL = 1,
		IMU_DATA_OTHER = 2
	};
}
namespace apollo::localization{
	enum MsfRunningStatus {
		MSF_SOL_LIDAR_GNSS = 0,
		MSF_SOL_X_GNSS = 1,
		MSF_SOL_LIDAR_X = 2,
		MSF_SOL_LIDAR_XX = 3,
		MSF_SOL_LIDAR_XXX = 4,
		MSF_SOL_X_X = 5,
		MSF_SOL_X_XX = 6,
		MSF_SOL_X_XXX = 7,
		MSF_SSOL_LIDAR_GNSS = 8,
		MSF_SSOL_X_GNSS = 9,
		MSF_SSOL_LIDAR_X = 10,
		MSF_SSOL_LIDAR_XX = 11,
		MSF_SSOL_LIDAR_XXX = 12,
		MSF_SSOL_X_X = 13,
		MSF_SSOL_X_XX = 14,
		MSF_SSOL_X_XXX = 15,
		MSF_NOSOL_LIDAR_GNSS = 16,
		MSF_NOSOL_X_GNSS = 17,
		MSF_NOSOL_LIDAR_X = 18,
		MSF_NOSOL_LIDAR_XX = 19,
		MSF_NOSOL_LIDAR_XXX = 20,
		MSF_NOSOL_X_X = 21,
		MSF_NOSOL_X_XX = 22,
		MSF_NOSOL_X_XXX = 23,
		MSF_RUNNING_INIT = 24
	};
}