/* Copyright 2013-2015 Bliksem Labs B.V.
 * See the LICENSE file at the top-level directory of this distribution and at
 * https://github.com/bliksemlabs/rrrr/
 */

#ifndef _PLAN_H
#define _PLAN_H

#include "rrrr_types.h"
#include "tdata.h"
#include "bitset.h"

#include <stdlib.h>

#define MAX_LEGS RRRR_DEFAULT_MAX_ROUNDS * 20 + 1

/* A leg represents one ride or walking transfer. */
typedef struct leg leg_t;
struct leg {
    /* vj index */
    jp_vjoffset_t vj;

    /* journey_pattern index */
    jpidx_t journey_pattern;

    /* from stop_point index */
    spidx_t sp_from;

    /* to stop_point index */
    spidx_t sp_to;

    /* start time */
    rtime_t  t0;

    /* end time */
    rtime_t  t1;

    #ifdef RRRR_FEATURE_REALTIME_EXPANDED
    /* Serviceday of the vehicle_journey */
    calendar_t  cal_day;
    #endif

    #ifdef RRRR_FEATURE_REALTIME
    /* start journey_pattern_point index */
    uint16_t jpp0;

    /* end journey_pattern_point index */
    uint16_t jpp1;

    /* start delay */
    int16_t d0;

    /* end delay */
    int16_t d1;
    #endif
};

/* An itinerary is a chain of legs leading from one place to another. */
typedef struct itinerary itinerary_t;
struct itinerary {
    leg_t legs[MAX_LEGS];
    uint8_t n_rides;
    uint8_t n_legs;
};

/* A plan is several pareto-optimal itineraries connecting the same two stops. */
typedef struct plan plan_t;
struct plan {
    itinerary_t itineraries[RRRR_DEFAULT_PLAN_ITIN];
    router_request_t req;
    uint8_t n_itineraries;
};

bool itinerary_init (itinerary_t *itin);

bool plan_init (plan_t *plan);

void plan_sort (plan_t *plan);

bool plan_get_operators (plan_t *plan, tdata_t *td, bitset_t *bs);

#endif /* _PLAN_H */
