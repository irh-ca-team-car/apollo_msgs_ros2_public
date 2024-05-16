#include "adapter/serialization/std_msgs/header.hpp"
namespace apollo_msgs::msg
{
    nlohmann::json to_json(std_msgs::msg::Header msg)
    {
        nlohmann::json obj;

        obj["frame_id"] = (msg.frame_id);
        obj["nanosec"] = msg.stamp.nanosec;
        obj["sec"] = msg.stamp.sec;

        return obj;
    };
    std_msgs::msg::Header from_json_Header(nlohmann::json obj)
    {
        std_msgs::msg::Header msg;
        msg.frame_id = (obj["frame_id"].get<std::string>());
        msg.stamp.nanosec = (obj["nanosec"].get<uint32_t>());
        msg.stamp.sec = (obj["sec"].get<int32_t>());

        return msg;
    };
}
