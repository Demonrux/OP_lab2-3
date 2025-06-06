#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include <stdbool.h>

#define LEN_PATH 300
#define MAX_LEN_REGION 50
#define MAX_LEN_ITEM 40
#define MAX_DATA_POINTS 5000
#define REGION_COLUM 1

typedef enum {
    COL_YEAR = 0,
    COL_REGION,
    COL_NPG,
    COL_BIRTH_RATE,
    COL_DEATH_RATE,
    COL_GDW,
    COL_URBANIZATION
} DataColumns;

typedef struct {
    int selectedColumn;
    const char* regionFilter;
    int minYear;
    int maxYear;
} FilterParams;

typedef struct {
    int year;
    double value;
    char region[MAX_LEN_REGION];
} DataPoint;

typedef struct {
    DataPoint* points;
    int count;
    double min;
    double max;
    double median;
} Metrics;

typedef struct {
    DataPoint* dataPoints;
    int rows;
    int cols;
    int invalidRows;
    int dataPointsCount;
    char** headers;
    char*** matrix;
} TableData;

typedef struct {
    TableData tableData;
    Metrics metrics;
    FilterParams filtredParams;
    bool fileLoaded;
    bool dataFiltered;
    char currentFilePath[LEN_PATH];
} AppContext;

#endif // APPCONTEXT_H
