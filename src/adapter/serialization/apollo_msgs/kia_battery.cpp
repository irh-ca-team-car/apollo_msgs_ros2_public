#include "adapter/serialization/apollo_msgs/kia_battery.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaBattery &msg) {
        nlohmann::json obj;
        obj["preheat_timer1_enabled"] = (msg.preheat_timer1_enabled);
        obj["preheat_timer2_enabled"] = (msg.preheat_timer2_enabled);
        return obj;
    }
    KiaBattery from_json_KiaBattery (nlohmann::json obj) {
        KiaBattery msg;
        if(obj.contains("preheat_timer1_enabled"))
        {
            msg.preheat_timer1_enabled = (obj["preheat_timer1_enabled"].is_string()?(float)atof(obj["preheat_timer1_enabled"].get<std::string>().c_str()):obj["preheat_timer1_enabled"].get<float>());
        }
        if(obj.contains("preheat_timer2_enabled"))
        {
            msg.preheat_timer2_enabled = (obj["preheat_timer2_enabled"].is_string()?(float)atof(obj["preheat_timer2_enabled"].get<std::string>().c_str()):obj["preheat_timer2_enabled"].get<float>());
        }
        return msg;
    }
    template <>
    KiaBattery from_json<KiaBattery>(nlohmann::json obj){
        return from_json_KiaBattery(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, KiaBattery &dt)
    {
        dt=from_json_KiaBattery(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const KiaBattery & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaBattery & dt)
    {
        os << to_json(dt);
        return os;
    }
}
