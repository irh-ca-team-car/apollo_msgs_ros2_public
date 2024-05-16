#pragma once
#include "apollo_msgs/msg/kia_power_train.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaPowerTrain &msg) ;
    KiaPowerTrain from_json_KiaPowerTrain (nlohmann::json obj) ;
    template <>
    KiaPowerTrain from_json<KiaPowerTrain>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, KiaPowerTrain &dt);
    std::ostream & operator<<(std::ostream & os, const KiaPowerTrain & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaPowerTrain & dt);
}
