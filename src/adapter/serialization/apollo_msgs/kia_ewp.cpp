#include "adapter/serialization/apollo_msgs/kia_ewp.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaEWP &msg) {
        nlohmann::json obj;
        obj["ewp_speed"] = (msg.ewp_speed);
        return obj;
    }
    KiaEWP from_json_KiaEWP (nlohmann::json obj) {
        KiaEWP msg;
        if(obj.contains("ewp_speed"))
        {
            msg.ewp_speed = (obj["ewp_speed"].is_string()?(float)atof(obj["ewp_speed"].get<std::string>().c_str()):obj["ewp_speed"].get<float>());
        }
        return msg;
    }
    template <>
    KiaEWP from_json<KiaEWP>(nlohmann::json obj){
        return from_json_KiaEWP(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, KiaEWP &dt)
    {
        dt=from_json_KiaEWP(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const KiaEWP & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaEWP & dt)
    {
        os << to_json(dt);
        return os;
    }
}
