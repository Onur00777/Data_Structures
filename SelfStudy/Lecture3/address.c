#include <stdio.h>
#include <string.h>
#include "address.h"

void construct_address(
    Addr* const addr,
    char const* const owner,
    int const door,
    char const* const ab,
    char const* const rh
){
    sprintf(addr->owner, "%.*s", 31, owner);
    addr->door = door;
    sprintf(addr->blood[0], "%.*s", 2, ab);
    sprintf(addr->blood[1], "%.*s", 2, rh);
}

void destruct_address(Addr* addr){
    memset(addr, 0, sizeof(Addr));
}