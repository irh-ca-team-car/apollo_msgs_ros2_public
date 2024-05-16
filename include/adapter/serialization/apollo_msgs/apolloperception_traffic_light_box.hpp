#pragma once
#include "apollo_msgs/msg/apolloperception_traffic_light_box.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionTrafficLightBox &msg) ;
    ApolloperceptionTrafficLightBox from_json_ApolloperceptionTrafficLightBox (nlohmann::json obj) ;
    template <>
    ApolloperceptionTrafficLightBox from_json<ApolloperceptionTrafficLightBox>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionTrafficLightBox &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionTrafficLightBox & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionTrafficLightBox & dt);
}
