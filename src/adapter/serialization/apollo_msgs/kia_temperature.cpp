#include "adapter/serialization/apollo_msgs/kia_temperature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaTemperature &msg) {
        nlohmann::json obj;
        obj["ambient_celsius"] = (msg.ambient_celsius);
        obj["interior_celsius"] = (msg.interior_celsius);
        obj["battery_celsius"] = (msg.battery_celsius);
        return obj;
    }
    KiaTemperature from_json_KiaTemperature (nlohmann::json obj) {
        KiaTemperature msg;
        if(obj.contains("ambient_celsius"))
        {
            msg.ambient_celsius = (obj["ambient_celsius"].is_string()?(float)atof(obj["ambient_celsius"].get<std::string>().c_str()):obj["ambient_celsius"].get<float>());
        }
        if(obj.contains("interior_celsius"))
        {
            msg.interior_celsius = (obj["interior_celsius"].is_string()?(float)atof(obj["interior_celsius"].get<std::string>().c_str()):obj["interior_celsius"].get<float>());
        }
        if(obj.contains("battery_celsius"))
        {
            msg.battery_celsius = (obj["battery_celsius"].is_string()?(float)atof(obj["battery_celsius"].get<std::string>().c_str()):obj["battery_celsius"].get<float>());
        }
        return msg;
    }
    template <>
    KiaTemperature from_json<KiaTemperature>(nlohmann::json obj){
        return from_json_KiaTemperature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, KiaTemperature &dt)
    {
        dt=from_json_KiaTemperature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const KiaTemperature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaTemperature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
