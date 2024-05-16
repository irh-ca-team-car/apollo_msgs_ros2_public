#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollotransform_transform.hpp"
#include "adapter/serialization/apollo_msgs/apollotransform_transform.hpp"
namespace apollo::transform{
	typedef apollo_msgs::msg::ApollotransformTransform Transform;
}
#include "apollo_msgs/msg/apollotransform_transform_stamped.hpp"
#include "adapter/serialization/apollo_msgs/apollotransform_transform_stamped.hpp"
namespace apollo::transform{
	typedef apollo_msgs::msg::ApollotransformTransformStamped TransformStamped;
}
#include "apollo_msgs/msg/apollotransform_transform_stampeds.hpp"
#include "adapter/serialization/apollo_msgs/apollotransform_transform_stampeds.hpp"
namespace apollo::transform{
	typedef apollo_msgs::msg::ApollotransformTransformStampeds TransformStampeds;
}