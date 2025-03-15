#include <gtest/gtest.h>
#include "version.h"
#include "lib.h"

TEST(ExampleTests, DemonstrateGTestMacros) {
    EXPECT_TRUE(version() == PROJECT_VERSION_PATCH);
}