#pragma once
#include "apollo_msgs/msg/apollodrivers_cluster_list_status600.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversClusterListStatus600 &msg) ;
    ApollodriversClusterListStatus600 from_json_ApollodriversClusterListStatus600 (nlohmann::json obj) ;
    template <>
    ApollodriversClusterListStatus600 from_json<ApollodriversClusterListStatus600>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversClusterListStatus600 &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversClusterListStatus600 & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversClusterListStatus600 & dt);
}