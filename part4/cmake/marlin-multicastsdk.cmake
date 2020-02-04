find_package(marlinMulticastSDK QUIET)
if(NOT marlinMulticastSDK_FOUND)
	message("-- marlinMulticastSDK not found. Using internal marlinMulticastSDK.")
	include(FetchContent)
	FetchContent_Declare(marlinMulticastSDK
		GIT_REPOSITORY https://gitlab.com/marlinprotocol/marlin.cpp.git
		GIT_TAG master
	)

	# Check if population has already been performed
	FetchContent_GetProperties(marlinMulticastSDK)
	string(TOLOWER "marlinMulticastSDK" lcName)
	if(NOT ${lcName}_POPULATED)
		# Fetch the content using previously declared details
		FetchContent_Populate(marlinMulticastSDK)

		# Bring the populated content into the build
		add_subdirectory(${${lcName}_SOURCE_DIR} ${${lcName}_BINARY_DIR} EXCLUDE_FROM_ALL)
	endif()
else()
	message("-- marlinMulticastSDK found. Using system marlinMulticastSDK.")
endif()
