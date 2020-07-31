if (ARCH STREQUAL arm)
    set(SynestiaArch arm)
elseif (ARCH STREQUAL arm64)
    set(SynestiaArch arm64)
else ()
    message(WARNING "unexpected ARCH ${ARCH}, using default value \"arm\"")
    set(SynestiaArch arm)
endif ()

message(STATUS "SynestiaArch is ${SynestiaArch}")
