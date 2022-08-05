#pragma once

#include "GyverFilters.h"

struct RemoteFilter
{
	GKalman remote_channel_1;
	GKalman remote_channel_2;
	GKalman remote_channel_3;
	GKalman remote_channel_4;
	GKalman remote_channel_5;
	GKalman remote_channel_6;

	RemoteFilter()
	: remote_channel_1(40, 0.5)
	, remote_channel_2(40, 0.5)
	, remote_channel_3(40, 0.5)
	, remote_channel_4(40, 0.5)
	, remote_channel_5(40, 0.5)
	, remote_channel_6(40, 0.5)
	{
	}
};
