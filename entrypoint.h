#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "appcontext.h"
typedef enum {
    Init,
    LoadData,
    FilterData,
    Clear
} Operation;

void doOperation(Operation operation, AppContext* context);

#endif // ENTRYPOINT_H
