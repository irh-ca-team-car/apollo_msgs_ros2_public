#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_layer_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_param_spec.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_proto.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_state_rule.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_transformation_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_accuracy_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotated_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_arg_max_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_batch_norm_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_b_box_reg_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_bias_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_concat_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_contrastive_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_convolution_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_crop_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_evaluate_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_output_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_output_ssd_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dfmbpsroi_align_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dropout_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dummy_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_eltwise_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_elu_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_embed_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_exp_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_flatten_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_output_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hinge_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_image_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_infogain_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_inner_product_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_input_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_log_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_lrn_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_memory_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_multi_box_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_output_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_proposal_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_target_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_anchors_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_dump_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_padding_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reorg_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_mvn_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_normalize_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_parameter_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_permute_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_pooling_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_power_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_p_re_lu_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_prior_box_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_python_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_recurrent_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reduction_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_re_lu_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reshape_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_roi_pooling_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_scale_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sigmoid_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_softmax_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_spp_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_slice_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_tan_h_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_threshold_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_tile_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_video_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_window_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLayerParameter &msg) ;
    ApolloperceptioninferenceLayerParameter from_json_ApolloperceptioninferenceLayerParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceLayerParameter from_json<ApolloperceptioninferenceLayerParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLayerParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLayerParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLayerParameter & dt);
}
