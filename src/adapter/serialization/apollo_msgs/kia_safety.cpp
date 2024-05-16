#include "adapter/serialization/apollo_msgs/kia_safety.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const KiaSafety &msg) {
        nlohmann::json obj;
        obj["isdriverbuckled"] = (msg.isdriverbuckled);
        obj["ispassengerbuckled"] = (msg.ispassengerbuckled);
        obj["is_rear_left_passenger_buckled"] = (msg.is_rear_left_passenger_buckled);
        obj["is_rear_middle_passenger_buckled"] = (msg.is_rear_middle_passenger_buckled);
        obj["is_rear_right_passenger_buckled"] = (msg.is_rear_right_passenger_buckled);
        obj["is_rear_right_passenger_buckled"] = (msg.is_rear_right_passenger_buckled);
        obj["is_fuel_door_open"] = (msg.is_fuel_door_open);
        obj["isdrivercardoorclose"] = (msg.isdrivercardoorclose);
        obj["ispassengerdooropen"] = (msg.ispassengerdooropen);
        obj["isrearrightdooropen"] = (msg.isrearrightdooropen);
        obj["isrearleftdooropen"] = (msg.isrearleftdooropen);
        obj["istrunkopen"] = (msg.istrunkopen);
        obj["is_hood_open"] = (msg.is_hood_open);
        obj["traction_control"] = (msg.traction_control);
        return obj;
    }
    KiaSafety from_json_KiaSafety (nlohmann::json obj) {
        KiaSafety msg;
        if(obj.contains("isdriverbuckled"))
        {
            msg.isdriverbuckled = (obj["isdriverbuckled"].is_string()?(bool)atoi(obj["isdriverbuckled"].get<std::string>().c_str()):obj["isdriverbuckled"].get<bool>());
        }
        if(obj.contains("ispassengerbuckled"))
        {
            msg.ispassengerbuckled = (obj["ispassengerbuckled"].is_string()?(bool)atoi(obj["ispassengerbuckled"].get<std::string>().c_str()):obj["ispassengerbuckled"].get<bool>());
        }
        if(obj.contains("is_rear_left_passenger_buckled"))
        {
            msg.is_rear_left_passenger_buckled = (obj["is_rear_left_passenger_buckled"].is_string()?(bool)atoi(obj["is_rear_left_passenger_buckled"].get<std::string>().c_str()):obj["is_rear_left_passenger_buckled"].get<bool>());
        }
        if(obj.contains("is_rear_middle_passenger_buckled"))
        {
            msg.is_rear_middle_passenger_buckled = (obj["is_rear_middle_passenger_buckled"].is_string()?(bool)atoi(obj["is_rear_middle_passenger_buckled"].get<std::string>().c_str()):obj["is_rear_middle_passenger_buckled"].get<bool>());
        }
        if(obj.contains("is_rear_right_passenger_buckled"))
        {
            msg.is_rear_right_passenger_buckled = (obj["is_rear_right_passenger_buckled"].is_string()?(bool)atoi(obj["is_rear_right_passenger_buckled"].get<std::string>().c_str()):obj["is_rear_right_passenger_buckled"].get<bool>());
        }
        if(obj.contains("is_fuel_door_open"))
        {
            msg.is_fuel_door_open = (obj["is_fuel_door_open"].is_string()?(bool)atoi(obj["is_fuel_door_open"].get<std::string>().c_str()):obj["is_fuel_door_open"].get<bool>());
        }
        if(obj.contains("isdrivercardoorclose"))
        {
            msg.isdrivercardoorclose = (obj["isdrivercardoorclose"].is_string()?(bool)atoi(obj["isdrivercardoorclose"].get<std::string>().c_str()):obj["isdrivercardoorclose"].get<bool>());
        }
        if(obj.contains("ispassengerdooropen"))
        {
            msg.ispassengerdooropen = (obj["ispassengerdooropen"].is_string()?(bool)atoi(obj["ispassengerdooropen"].get<std::string>().c_str()):obj["ispassengerdooropen"].get<bool>());
        }
        if(obj.contains("isrearrightdooropen"))
        {
            msg.isrearrightdooropen = (obj["isrearrightdooropen"].is_string()?(bool)atoi(obj["isrearrightdooropen"].get<std::string>().c_str()):obj["isrearrightdooropen"].get<bool>());
        }
        if(obj.contains("isrearleftdooropen"))
        {
            msg.isrearleftdooropen = (obj["isrearleftdooropen"].is_string()?(bool)atoi(obj["isrearleftdooropen"].get<std::string>().c_str()):obj["isrearleftdooropen"].get<bool>());
        }
        if(obj.contains("istrunkopen"))
        {
            msg.istrunkopen = (obj["istrunkopen"].is_string()?(bool)atoi(obj["istrunkopen"].get<std::string>().c_str()):obj["istrunkopen"].get<bool>());
        }
        if(obj.contains("is_hood_open"))
        {
            msg.is_hood_open = (obj["is_hood_open"].is_string()?(bool)atoi(obj["is_hood_open"].get<std::string>().c_str()):obj["is_hood_open"].get<bool>());
        }
        if(obj.contains("traction_control"))
        {
            msg.traction_control = (obj["traction_control"].is_string()?(bool)atoi(obj["traction_control"].get<std::string>().c_str()):obj["traction_control"].get<bool>());
        }
        return msg;
    }
    template <>
    KiaSafety from_json<KiaSafety>(nlohmann::json obj){
        return from_json_KiaSafety(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, KiaSafety &dt)
    {
        dt=from_json_KiaSafety(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const KiaSafety & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const KiaSafety & dt)
    {
        os << to_json(dt);
        return os;
    }
}
