#include "adapter/serialization/apollo_msgs/kia_power_train.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaPowerTrain &msg) {
        nlohmann::json obj;
        obj["engine_rpm"] = (msg.engine_rpm);
        obj["speed_mps"] = (msg.speed_mps);
        obj["steering_mode"] = (msg.steering_mode);
        obj["available_charge_power_kw"] = (msg.available_charge_power_kw);
        obj["soc"] = (msg.soc);
        obj["battery_voltage"] = (msg.battery_voltage);
        obj["battery_watt"] = (msg.battery_watt);
        obj["battery_current"] = (msg.battery_current);
        obj["battery_capacity"] = (msg.battery_capacity);
        obj["battery_soc_wh"] = (msg.battery_soc_wh);
        obj["battery_soc_wh"] = (msg.battery_soc_wh);
        return obj;
    }
    KiaPowerTrain from_json_KiaPowerTrain (nlohmann::json obj) {
        KiaPowerTrain msg;
        if(obj.contains("engine_rpm"))
        {
            msg.engine_rpm = (obj["engine_rpm"].is_string()?(float)atof(obj["engine_rpm"].get<std::string>().c_str()):obj["engine_rpm"].get<float>());
        }
        if(obj.contains("speed_mps"))
        {
            msg.speed_mps = (obj["speed_mps"].is_string()?(float)atof(obj["speed_mps"].get<std::string>().c_str()):obj["speed_mps"].get<float>());
        }
        if(obj.contains("steering_mode"))
        {
            msg.steering_mode = (obj["steering_mode"].is_string()?atoi(obj["steering_mode"].get<std::string>().c_str()):obj["steering_mode"].get<int>());
        }
        if(obj.contains("available_charge_power_kw"))
        {
            msg.available_charge_power_kw = (obj["available_charge_power_kw"].is_string()?(float)atof(obj["available_charge_power_kw"].get<std::string>().c_str()):obj["available_charge_power_kw"].get<float>());
        }
        if(obj.contains("soc"))
        {
            msg.soc = (obj["soc"].is_string()?(float)atof(obj["soc"].get<std::string>().c_str()):obj["soc"].get<float>());
        }
        if(obj.contains("battery_voltage"))
        {
            msg.battery_voltage = (obj["battery_voltage"].is_string()?(float)atof(obj["battery_voltage"].get<std::string>().c_str()):obj["battery_voltage"].get<float>());
        }
        if(obj.contains("battery_watt"))
        {
            msg.battery_watt = (obj["battery_watt"].is_string()?(float)atof(obj["battery_watt"].get<std::string>().c_str()):obj["battery_watt"].get<float>());
        }
        if(obj.contains("battery_current"))
        {
            msg.battery_current = (obj["battery_current"].is_string()?(float)atof(obj["battery_current"].get<std::string>().c_str()):obj["battery_current"].get<float>());
        }
        if(obj.contains("battery_capacity"))
        {
            msg.battery_capacity = (obj["battery_capacity"].is_string()?(float)atof(obj["battery_capacity"].get<std::string>().c_str()):obj["battery_capacity"].get<float>());
        }
        if(obj.contains("battery_soc_wh"))
        {
            msg.battery_soc_wh = (obj["battery_soc_wh"].is_string()?(float)atof(obj["battery_soc_wh"].get<std::string>().c_str()):obj["battery_soc_wh"].get<float>());
        }
        return msg;
    }
    template <>
    KiaPowerTrain from_json<KiaPowerTrain>(nlohmann::json obj){
        return from_json_KiaPowerTrain(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, KiaPowerTrain &dt)
    {
        dt=from_json_KiaPowerTrain(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const KiaPowerTrain & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaPowerTrain & dt)
    {
        os << to_json(dt);
        return os;
    }
}
