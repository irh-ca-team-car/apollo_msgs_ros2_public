#pragma once
namespace apollo::perception::camera::traffic_light::preprocess{
	enum CameraID {
		LONG_FOCUS = 0,    // 25mm
		NARROW_FOCUS = 1,  // 12mm
		SHORT_FOCUS = 2,   // 6mm
		WIDE_FOCUS = 3,    // 2mm
		UNKNOWN = 4,
		CAMERA_ID_COUNT = 5
	};
}