#pragma once
#include "apollo_msgs/msg/kia_safety.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaSafety &msg) ;
    KiaSafety from_json_KiaSafety (nlohmann::json obj) ;
    template <>
    KiaSafety from_json<KiaSafety>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, KiaSafety &dt);
    std::ostream & operator<<(std::ostream & os, const KiaSafety & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaSafety & dt);
}
