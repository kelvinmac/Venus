
set(VULKAN_INC # include directories
        "vulkanUtility.h"
        "vulkanDevice.h"
        )

set(VULKAN_SRC # source directories
        "vulkanUtility.cpp"
        "vulkanDevice.cpp"
        )

set(VULKAN_PLUGIN_SRC
        ${VULKAN_INC}
        ${VULKAN_SRC}
        )