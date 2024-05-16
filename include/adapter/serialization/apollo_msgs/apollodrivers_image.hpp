#pragma once
#include "apollo_msgs/msg/apollodrivers_image.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apollocommon_header.hpp"
#include "adapter/serialization/apollo_msgs/bytes.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversImage &msg) ;
    ApollodriversImage from_json_ApollodriversImage (nlohmann::json obj) ;
    template <>
    ApollodriversImage from_json<ApollodriversImage>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversImage &dt);
    std::ostream & operator<<(std::ostream & os, const ApollodriversImage & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversImage & dt);
}
