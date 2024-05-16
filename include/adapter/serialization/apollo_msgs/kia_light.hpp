#pragma once
#include "apollo_msgs/msg/kia_light.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaLight &msg) ;
    KiaLight from_json_KiaLight (nlohmann::json obj) ;
    template <>
    KiaLight from_json<KiaLight>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, KiaLight &dt);
    std::ostream & operator<<(std::ostream & os, const KiaLight & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaLight & dt);
}
