#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollodreamview_options_axis.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_options_axis.hpp"
namespace apollo::dreamview::Options{
	typedef apollo_msgs::msg::ApollodreamviewOptionsAxis Axis;
}
#include "apollo_msgs/msg/apollodreamview_options.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_options.hpp"
#include "apollo_msgs/msg/apollodreamview_line.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_line.hpp"
#include "apollo_msgs/msg/apollodreamview_polygon.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_polygon.hpp"
#include "apollo_msgs/msg/apollodreamview_car.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_car.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewCar Car;
}
#include "apollo_msgs/msg/apollodreamview_chart.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_chart.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewChart Chart;
}