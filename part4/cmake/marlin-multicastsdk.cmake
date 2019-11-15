find_package(MarlinMulticastSDK QUIET)
if(NOT MarlinMulticastSDK_FOUND)
	message("-- MarlinMulticastSDK not found. Using internal MarlinMulticastSDK.")
	include(FetchContent)
	FetchContent_Declare(MarlinMulticastSDK
		GIT_REPOSITORY https://gitlab.com/marlinprotocol/multicastsdk.cpp.git
		GIT_TAG master
	)
	FetchContent_MakeAvailable(MarlinMulticastSDK)

	add_library(Marlin::multicastsdk ALIAS multicastsdk)
else()
	message("-- MarlinMulticastSDK found. Using system MarlinMulticastSDK.")
endif()
