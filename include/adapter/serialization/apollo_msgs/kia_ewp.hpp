#pragma once
#include "apollo_msgs/msg/kia_ewp.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaEWP &msg) ;
    KiaEWP from_json_KiaEWP (nlohmann::json obj) ;
    template <>
    KiaEWP from_json<KiaEWP>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, KiaEWP &dt);
    std::ostream & operator<<(std::ostream & os, const KiaEWP & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaEWP & dt);
}
