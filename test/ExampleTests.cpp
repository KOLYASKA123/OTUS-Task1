#include <gtest/gtest.h>
#include "../lib.h"
#include "../build/version.h"

TEST(ExampleTests, DemonstrateGTestMacros) {
    EXPECT_TRUE(version() == PROJECT_VERSION_PATCH);
}