#pragma once
namespace apollo::hdmap{
	enum ErrorCode {
		// common: x
		SUCCESS = 0,
		ERROR = 1,
		ERROR_REQUEST = 2,              // invalid request parameter
		ERROR_SERVICE_NO_RESPONSE = 3,  // cybertron services no response
		ERROR_REPEATED_START = 4,
		ERROR_CHECK_BEFORE_START = 5,
		
		// APP fetch: 10x
		ERROR_GPSBIN_LACK = 101,  // gpsbin in car is lack or not complete.
		ERROR_DISKINFO_ERROR = 102,
		ERROR_DISK_UNMOUNT = 103,
		
		ERROR_SPEED_LACK = 105,
		WARNING_ODOMETER_LACK = 106,
		ERROR_RTKSTATUS_EMPTY = 107,
		
		// map-datachecker: 20x
		ERROR_MAPGRPC_NOT_CONNECT = 201,
		
		// map-datachecher: dynamic_align: 21x
		WARNING_NOT_STRAIGHT =
		212,  // heading too large, need warning straight driving.
		WARNING_PROGRESS_ROLLBACK = 213,  // progress rollback because turn a corner.
		
		// map-datachecher: eight_route: 22x
		ERROR_NOT_EIGHT_ROUTE = 221,  // heading is not an eight route.
		
		// map-datachecher: data_verify: 23x
		ERROR_CHANNEL_VERIFY_TOPIC_LACK = 231,  // some topic lack in channel_verify.
		ERROR_CHANNEL_VERIFY_RATES_ABNORMAL = 232,  // some topic rates abnormal
		ERROR_VERIFY_NO_RECORDERS =
		233,                        // data verify has/find no recorders in disks.
		ERROR_LOOPS_NOT_REACHED = 234,  // loops is not enough 5/6
		ERROR_VERIFY_NO_GNSSPOS = 235,  // cybertron has no gnsspos callback.
		
		// map-datachecker: static_align: 24x
		ERROR_NOT_STATIC = 241,        // car is not static.
		ERROR_GNSS_SIGNAL_FAIL = 242,  // gnss signal is broken | fail
		
		// task handler: 30x
		SUCCESS_TASK_EMPTY =
		301,  // indicate this collect task has no recorders before
		SUCCESS_TASK_STOCK =
		302  // indicate this collect task has collected some recorders already
	};
}