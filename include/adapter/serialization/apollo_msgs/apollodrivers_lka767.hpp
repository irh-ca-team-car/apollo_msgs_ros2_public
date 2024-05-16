#pragma once
#include "apollo_msgs/msg/apollodrivers_lka767.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLka767 &msg) ;
    ApollodriversLka767 from_json_ApollodriversLka767 (nlohmann::json obj) ;
    template <>
    ApollodriversLka767 from_json<ApollodriversLka767>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLka767 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversLka767 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLka767 & dt);
}
