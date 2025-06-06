#ifndef LOGIC_H
#define LOGIC_H

#include "appcontext.h"

void initializeContext(AppContext* context);
bool loadDataFromFile(AppContext* context);
void filterData(AppContext* context);
void freeResources(AppContext* context);

#endif // LOGIC_H
