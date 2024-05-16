rm msg/*
echo "uint8[] data"> msg/Bytes.msg
python3 create_pb_h.py ~/git/apollo include/ msg/
rm msg/Apollocyber*.msg
rm include/adapter/serialization/apollo_msgs -rd
rm src/adapter/serialization/apollo_msgs -rd
python3 check_message_type.py . msg/
python3 find-loop.py msg/
find msg -type f > msg.list

#cat msg/ApollopredictionFeature.msg
#$sed "17d" msg/ApollopredictionFeature.msg > msg/ApollopredictionFeature.msg.tmp
#mv msg/ApollopredictionFeature.msg.tmp msg/ApollopredictionFeature.msg
python3 create_serialization_adapter.py . msg/
#missing apollo_msgs/ApollopredictionLane lane in ApollopredictionFeature.msg