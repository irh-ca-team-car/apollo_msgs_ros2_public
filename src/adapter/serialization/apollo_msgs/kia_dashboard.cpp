#include "adapter/serialization/apollo_msgs/kia_dashboard.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaDashboard &msg) {
        nlohmann::json obj;
        obj["speedmps"] = (msg.speedmps);
        obj["parkingbrake"] = (msg.parkingbrake);
        obj["highbeamsignal"] = (msg.highbeamsignal);
        obj["lowbeamsignal"] = (msg.lowbeamsignal);
        obj["leftturnsignal"] = (msg.leftturnsignal);
        obj["rightturnsignal"] = (msg.rightturnsignal);
        obj["odometerm"] = (msg.odometerm);
        obj["fuelrangem"] = (msg.fuelrangem);
        obj["brake_light"] = (msg.brake_light);
        obj["ks_clock"] = (msg.ks_clock);
        obj["estimated_range"] = (msg.estimated_range);
        obj["extra_range"] = (msg.extra_range);
        return obj;
    }
    KiaDashboard from_json_KiaDashboard (nlohmann::json obj) {
        KiaDashboard msg;
        if(obj.contains("speedmps"))
        {
            msg.speedmps = (obj["speedmps"].is_string()?(float)atof(obj["speedmps"].get<std::string>().c_str()):obj["speedmps"].get<float>());
        }
        if(obj.contains("parkingbrake"))
        {
            msg.parkingbrake = (obj["parkingbrake"].is_string()?(bool)atoi(obj["parkingbrake"].get<std::string>().c_str()):obj["parkingbrake"].get<bool>());
        }
        if(obj.contains("highbeamsignal"))
        {
            msg.highbeamsignal = (obj["highbeamsignal"].is_string()?(bool)atoi(obj["highbeamsignal"].get<std::string>().c_str()):obj["highbeamsignal"].get<bool>());
        }
        if(obj.contains("lowbeamsignal"))
        {
            msg.lowbeamsignal = (obj["lowbeamsignal"].is_string()?(bool)atoi(obj["lowbeamsignal"].get<std::string>().c_str()):obj["lowbeamsignal"].get<bool>());
        }
        if(obj.contains("leftturnsignal"))
        {
            msg.leftturnsignal = (obj["leftturnsignal"].is_string()?(bool)atoi(obj["leftturnsignal"].get<std::string>().c_str()):obj["leftturnsignal"].get<bool>());
        }
        if(obj.contains("rightturnsignal"))
        {
            msg.rightturnsignal = (obj["rightturnsignal"].is_string()?(bool)atoi(obj["rightturnsignal"].get<std::string>().c_str()):obj["rightturnsignal"].get<bool>());
        }
        if(obj.contains("odometerm"))
        {
            msg.odometerm = (obj["odometerm"].is_string()?(float)atof(obj["odometerm"].get<std::string>().c_str()):obj["odometerm"].get<float>());
        }
        if(obj.contains("fuelrangem"))
        {
            msg.fuelrangem = (obj["fuelrangem"].is_string()?(float)atof(obj["fuelrangem"].get<std::string>().c_str()):obj["fuelrangem"].get<float>());
        }
        if(obj.contains("brake_light"))
        {
            msg.brake_light = (obj["brake_light"].is_string()?(bool)atoi(obj["brake_light"].get<std::string>().c_str()):obj["brake_light"].get<bool>());
        }
        if(obj.contains("ks_clock"))
        {
            msg.ks_clock = (obj["ks_clock"].is_string()?(float)atof(obj["ks_clock"].get<std::string>().c_str()):obj["ks_clock"].get<float>());
        }
        if(obj.contains("estimated_range"))
        {
            msg.estimated_range = (obj["estimated_range"].is_string()?(float)atof(obj["estimated_range"].get<std::string>().c_str()):obj["estimated_range"].get<float>());
        }
        if(obj.contains("extra_range"))
        {
            msg.extra_range = (obj["extra_range"].is_string()?(float)atof(obj["extra_range"].get<std::string>().c_str()):obj["extra_range"].get<float>());
        }
        return msg;
    }
    template <>
    KiaDashboard from_json<KiaDashboard>(nlohmann::json obj){
        return from_json_KiaDashboard(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, KiaDashboard &dt)
    {
        dt=from_json_KiaDashboard(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const KiaDashboard & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaDashboard & dt)
    {
        os << to_json(dt);
        return os;
    }
}
