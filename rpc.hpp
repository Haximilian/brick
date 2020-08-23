#pragma once

#include <stdint.h>

enum rpc : uint32_t
{
    start_transaction = 0,
    write_value = 1,
    read_value = 2,
    commit_transaction = 3
};