#include "adapter/serialization/apollo_msgs/kia_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaLight &msg) {
        nlohmann::json obj;
        obj["isbrakelampon"] = (msg.isbrakelampon);
        obj["turnlighttype"] = (msg.turnlighttype);
        return obj;
    }
    KiaLight from_json_KiaLight (nlohmann::json obj) {
        KiaLight msg;
        if(obj.contains("isbrakelampon"))
        {
            msg.isbrakelampon = (obj["isbrakelampon"].is_string()?(bool)atoi(obj["isbrakelampon"].get<std::string>().c_str()):obj["isbrakelampon"].get<bool>());
        }
        if(obj.contains("turnlighttype"))
        {
            msg.turnlighttype = (obj["turnlighttype"].is_string()?atoi(obj["turnlighttype"].get<std::string>().c_str()):obj["turnlighttype"].get<int>());
        }
        return msg;
    }
    template <>
    KiaLight from_json<KiaLight>(nlohmann::json obj){
        return from_json_KiaLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, KiaLight &dt)
    {
        dt=from_json_KiaLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const KiaLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
