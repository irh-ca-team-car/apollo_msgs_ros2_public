#pragma once
#include "apollo_msgs/msg/apolloplanning_internal_lattice_st_pixel.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalLatticeStPixel &msg) ;
    ApolloplanningInternalLatticeStPixel from_json_ApolloplanningInternalLatticeStPixel (nlohmann::json obj) ;
    template <>
    ApolloplanningInternalLatticeStPixel from_json<ApolloplanningInternalLatticeStPixel>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalLatticeStPixel &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalLatticeStPixel & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalLatticeStPixel & dt);
}
