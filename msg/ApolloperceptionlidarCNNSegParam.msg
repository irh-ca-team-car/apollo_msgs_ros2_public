string modeltype "CaffeNet"
apollo_msgs/ApolloperceptionlidarNetworkParam networkparam
apollo_msgs/ApolloperceptionlidarFeatureParam featureparam
bool doclassification true
bool doheading true
uint32 gpuid 0
string grounddetector
string roifilter "HdmapROIFilter"
bool removegroundpoints false
float32 objectnessthresh 0.5
float32 confidencethresh 0.1
float32 heightthresh 0.5
uint32 minptsnum 3
float32 confidencerange 60
