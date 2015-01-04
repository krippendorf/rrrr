#include "rrrr_types.h"
#include "tdata.h"

/* file-visible struct */
typedef struct tdata_header tdata_header_t;
struct tdata_header {
    /* Contents must read "TTABLEV4" */
    char version_string[8];
    uint64_t calendar_start_time;
    calendar_t dst_active;
    uint32_t n_stop_points;
    uint32_t n_stop_areas;
    uint32_t n_stop_point_attributes;
    uint32_t n_stop_point_coords;
    uint32_t n_stop_area_coords;
    uint32_t n_stop_area_for_stop_point;
    uint32_t n_journey_patterns;
    uint32_t n_journey_pattern_points;
    uint32_t n_journey_pattern_point_attributes;
    uint32_t n_journey_pattern_point_headsigns;
    uint32_t n_stop_times;
    uint32_t n_vjs;
    uint32_t n_journey_patterns_at_stop;
    uint32_t n_transfer_target_stops;
    uint32_t n_transfer_durations;
    uint32_t n_vj_active;
    uint32_t n_journey_pattern_active;
    uint32_t n_platformcodes;
    uint32_t n_stop_point_nameidx;
    uint32_t n_stop_area_nameidx;
    uint32_t n_operator_ids;
    uint32_t n_operator_names;
    uint32_t n_operator_urls;
    uint32_t n_commercial_mode_ids;
    uint32_t n_commercial_mode_names;
    uint32_t n_physical_mode_ids;
    uint32_t n_physical_mode_names;
    /* length of the object in bytes */
    uint32_t n_string_pool;
    uint32_t n_line_codes;
    uint32_t n_line_ids;
    uint32_t n_stop_point_ids;
    uint32_t n_stop_area_ids;
    uint32_t n_vj_ids;
    uint32_t n_line_for_route;
    uint32_t n_operator_for_line;
    uint32_t n_commercial_mode_for_jp;
    uint32_t n_physical_mode_for_line;

    uint32_t loc_stop_points;
    uint32_t loc_stop_point_attributes;
    uint32_t loc_stop_point_coords;
    uint32_t loc_journey_patterns;
    uint32_t loc_journey_pattern_points;
    uint32_t loc_journey_pattern_point_attributes;
    uint32_t loc_journey_pattern_point_headsigns;
    uint32_t loc_stop_times;
    uint32_t loc_vjs;
    uint32_t loc_journey_patterns_at_stop;
    uint32_t loc_transfer_target_stops;
    uint32_t loc_transfer_durations;
    uint32_t loc_vj_active;
    uint32_t loc_journey_pattern_active;
    uint32_t loc_platformcodes;
    uint32_t loc_stop_point_nameidx;
    uint32_t loc_stop_area_nameidx;
    uint32_t loc_line_for_route;
    uint32_t loc_operator_for_line;
    uint32_t loc_operator_ids;
    uint32_t loc_operator_names;
    uint32_t loc_operator_urls;
    uint32_t loc_commercial_mode_ids;
    uint32_t loc_commercial_mode_names;
    uint32_t loc_commercial_mode_for_jp;
    uint32_t loc_physical_mode_ids;
    uint32_t loc_physical_mode_names;
    uint32_t loc_physical_mode_for_line;
    uint32_t loc_string_pool;
    uint32_t loc_line_codes;
    uint32_t loc_line_ids;
    uint32_t loc_stop_point_ids;
    uint32_t loc_stop_area_ids;
    uint32_t loc_vj_ids;
    uint32_t loc_stop_area_coords;
    uint32_t loc_stop_area_for_stop_point;
};

bool tdata_io_v3_load(tdata_t *td, char* filename);
void tdata_io_v3_close(tdata_t *td);
