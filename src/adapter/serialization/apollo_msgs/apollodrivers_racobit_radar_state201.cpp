#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_radar_state201.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitRadarState201 &msg) {
        nlohmann::json obj;
        obj["maxdistance"] = (msg.maxdistance);
        obj["radarpower"] = (msg.radarpower);
        obj["outputtype"] = (msg.outputtype);
        obj["rcsthreshold"] = (msg.rcsthreshold);
        obj["sendquality"] = (msg.sendquality);
        obj["sendextinfo"] = (msg.sendextinfo);
        return obj;
    }
    ApollodriversRacobitRadarState201 from_json_ApollodriversRacobitRadarState201 (nlohmann::json obj) {
        ApollodriversRacobitRadarState201 msg;
        if(obj.contains("maxdistance"))
        {
            msg.maxdistance = (obj["maxdistance"].is_string()?atoi(obj["maxdistance"].get<std::string>().c_str()):obj["maxdistance"].get<uint32_t>());
        }
        if(obj.contains("radarpower"))
        {
            msg.radarpower = (obj["radarpower"].is_string()?atoi(obj["radarpower"].get<std::string>().c_str()):obj["radarpower"].get<uint32_t>());
        }
        if(obj.contains("outputtype"))
        {
            msg.outputtype = (obj["outputtype"].is_string()?atoi(obj["outputtype"].get<std::string>().c_str()):obj["outputtype"].get<int>());
        }
        if(obj.contains("rcsthreshold"))
        {
            msg.rcsthreshold = (obj["rcsthreshold"].is_string()?atoi(obj["rcsthreshold"].get<std::string>().c_str()):obj["rcsthreshold"].get<int>());
        }
        if(obj.contains("sendquality"))
        {
            msg.sendquality = (obj["sendquality"].is_string()?(bool)atoi(obj["sendquality"].get<std::string>().c_str()):obj["sendquality"].get<bool>());
        }
        if(obj.contains("sendextinfo"))
        {
            msg.sendextinfo = (obj["sendextinfo"].is_string()?(bool)atoi(obj["sendextinfo"].get<std::string>().c_str()):obj["sendextinfo"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriversRacobitRadarState201 from_json<ApollodriversRacobitRadarState201>(nlohmann::json obj){
        return from_json_ApollodriversRacobitRadarState201(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitRadarState201 &dt)
    {
        dt=from_json_ApollodriversRacobitRadarState201(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitRadarState201 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitRadarState201 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
