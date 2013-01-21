/* router.h */
#include <stdbool.h>
#include "transitdata.h"

typedef struct router router_t;
struct router {
    transit_data_t *tdata;
    // scratch space for solving
    // making this opaque requires more dynamic allocation
    int *arrivals;
//int (*back_trip)[tdata->nstops];
//int (*back_stop)[tdata->nstops];
};

typedef struct router_request router_request_t;
struct router_request {
    int from;
    int to;
    long time;
    double walk_speed;
    bool arrive_by; 
};

void router_setup(router_t*, transit_data_t*);

bool router_request_from_qstring(router_request_t*);

void router_request_dump(router_request_t*);

void router_teardown(router_t*);
