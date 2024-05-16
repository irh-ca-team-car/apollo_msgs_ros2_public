#pragma once
#include "apollo_msgs/msg/kia_temperature.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaTemperature &msg) ;
    KiaTemperature from_json_KiaTemperature (nlohmann::json obj) ;
    template <>
    KiaTemperature from_json<KiaTemperature>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, KiaTemperature &dt);
    std::ostream & operator<<(std::ostream & os, const KiaTemperature & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaTemperature & dt);
}
