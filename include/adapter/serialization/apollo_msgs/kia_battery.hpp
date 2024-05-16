#pragma once
#include "apollo_msgs/msg/kia_battery.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaBattery &msg) ;
    KiaBattery from_json_KiaBattery (nlohmann::json obj) ;
    template <>
    KiaBattery from_json<KiaBattery>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, KiaBattery &dt);
    std::ostream & operator<<(std::ostream & os, const KiaBattery & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaBattery & dt);
}
