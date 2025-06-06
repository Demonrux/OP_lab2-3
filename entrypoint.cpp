#include "entrypoint.h"
#include "logic.h"

void doOperation(Operation operation, AppContext* context) {
    switch (operation) {
    case Init:
        initializeContext(context);
        break;
    case LoadData: {
        loadDataFromFile(context);
        break;
    }
    case FilterData: {
        filterData(context);
        break;
    }
    case Clear:
        freeResources(context);
        break;
    }
}
