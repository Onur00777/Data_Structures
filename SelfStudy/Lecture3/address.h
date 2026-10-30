#ifndef ADDRESS_H
#define ADDRESS_H

typedef struct AddressStruct {
    char owner[32];
    int door;
    char blood[2][3];
} Addr;

void construct_address(
    Addr* const addr,
    char const* const owner,
    int const door,
    char const* const ab,
    char const* const rh
);

void destruct_address(Addr* addr);
#endif