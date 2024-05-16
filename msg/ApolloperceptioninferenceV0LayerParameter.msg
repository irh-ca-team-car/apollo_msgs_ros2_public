string name
string type
uint32 numoutput
bool biasterm true
apollo_msgs/ApolloperceptioninferenceFillerParameter weightfiller
apollo_msgs/ApolloperceptioninferenceFillerParameter biasfiller
uint32 pad 0
uint32 kernelsize
uint32 group 1
uint32 stride 1
int32 pool#ApolloperceptioninferencePoolMethod
float32 dropoutratio 0.5
uint32 localsize 5
float32 alpha 1.
float32 beta 0.75
float32 k 1.
string source
float32 scale 1
string meanfile
uint32 batchsize
uint32 cropsize 0
bool mirror false
apollo_msgs/ApolloperceptioninferenceBlobProto[] blobs
float32[] blobslr
float32[] weightdecay
uint32 randskip 0
float32 detfgthreshold 0.5
float32 detbgthreshold 0.5
float32 detfgfraction 0.25
uint32 detcontextpad 0
string detcropmode "warp"
int32 newnum 0
int32 newchannels 0
int32 newheight 0
int32 newwidth 0
bool shuffleimages false
uint32 concatdim 1
apollo_msgs/ApolloperceptioninferenceHDF5OutputParameter hdf5outputparam
