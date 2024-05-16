#pragma once
#include "apollo_msgs/msg/kia_dashboard.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaDashboard &msg) ;
    KiaDashboard from_json_KiaDashboard (nlohmann::json obj) ;
    template <>
    KiaDashboard from_json<KiaDashboard>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, KiaDashboard &dt);
    std::ostream & operator<<(std::ostream & os, const KiaDashboard & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaDashboard & dt);
}
