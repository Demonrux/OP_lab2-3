#include "logic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static int compareDataPoints(const void* a, const void* b) {
    double valueA = ((const DataPoint*)a)->value;
    double valueB = ((const DataPoint*)b)->value;
    return (valueA > valueB) - (valueA < valueB);
}

void initializeContext(AppContext* context) {
    memset(context, 0, sizeof(AppContext));
    context->tableData.headers = NULL;
    context->tableData.matrix = NULL;
    context->tableData.dataPoints = NULL;
    context->tableData.cols = 0;
    context->tableData.rows = 0;
}

bool loadDataFromFile(AppContext* context) {
    FILE* file = fopen(context->currentFilePath, "r");
    if (!file) return false;

    freeResources(context);

    char line[4096];
    int row = 0;

    if (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        int colCount = 0;

        while (token) {
            colCount++;
            token = strtok(NULL, ",");
        }

        context->tableData.cols = colCount;
        rewind(file);

        context->tableData.headers = (char**)malloc(colCount * sizeof(char*));
        fgets(line, sizeof(line), file);

        token = strtok(line, ",");
        for (int i = 0; i < colCount && token; i++) {
            context->tableData.headers[i] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    context->tableData.matrix = (char***)malloc(MAX_DATA_POINTS * sizeof(char**));
    context->tableData.dataPoints = (DataPoint*)malloc(MAX_DATA_POINTS * sizeof(DataPoint));

    while (fgets(line, sizeof(line), file) && row < MAX_DATA_POINTS) {
        line[strcspn(line, "\n")] = '\0';
        context->tableData.matrix[row] = (char**)malloc(context->tableData.cols * sizeof(char*));

        char* token = strtok(line, ",");
        int col = 0;
        DataPoint dp = {0};

        while (token && col < context->tableData.cols) {
            context->tableData.matrix[row][col] = strdup(token);

            switch (col) {
            case COL_YEAR:
                dp.year = atoi(token);
                break;
            case COL_REGION:
                strncpy(dp.region, token, MAX_LEN_REGION - 1);
                break;
            }

            token = strtok(NULL, ",");
            col++;
        }

        if (col == context->tableData.cols) {
            context->tableData.dataPoints[row] = dp;
            row++;
        } else {
            context->tableData.invalidRows++;
        }
    }

    context->tableData.rows = row;
    context->tableData.dataPointsCount = row;
    fclose(file);
    context->fileLoaded = true;
    return true;
}

void filterData(AppContext* context) {
    if (!context->fileLoaded || context->filtredParams.selectedColumn >= context->tableData.cols) return;

    if (context->metrics.points) {
        free(context->metrics.points);
    }

    int count = 0;
    for (int i = 0; i < context->tableData.dataPointsCount; i++) {
        DataPoint* dp = &context->tableData.dataPoints[i];
        if (dp->year >= context->filtredParams.minYear && dp->year <= context->filtredParams.maxYear) {
            if (!context->filtredParams.regionFilter || strcmp(dp->region, context->filtredParams.regionFilter) == 0) {
                count++;
            }
        }
    }

    context->metrics.points = (DataPoint*)malloc(count * sizeof(DataPoint));
    if (!context->metrics.points) return;

    int idx = 0;
    for (int i = 0; i < context->tableData.dataPointsCount; i++) {
        DataPoint* src = &context->tableData.dataPoints[i];
        if (src->year >= context->filtredParams.minYear && src->year <= context->filtredParams.maxYear) {
            if (!context->filtredParams.regionFilter || strcmp(src->region, context->filtredParams.regionFilter) == 0) {
                DataPoint* dest = &context->metrics.points[idx++];
                *dest = *src;

                switch (context->filtredParams.selectedColumn) {
                case COL_NPG:
                    dest->value = atof(context->tableData.matrix[i][COL_NPG]);
                    break;
                case COL_BIRTH_RATE:
                    dest->value = atof(context->tableData.matrix[i][COL_BIRTH_RATE]);
                    break;
                case COL_DEATH_RATE:
                    dest->value = atof(context->tableData.matrix[i][COL_DEATH_RATE]);
                    break;
                case COL_GDW:
                    dest->value = atof(context->tableData.matrix[i][COL_GDW]);
                    break;
                case COL_URBANIZATION:
                    dest->value = atof(context->tableData.matrix[i][COL_URBANIZATION]);
                    break;
                }
            }
        }
    }

    context->metrics.count = count;
    context->dataFiltered = true;

    if (count > 0) {
        qsort(context->metrics.points, count, sizeof(DataPoint), compareDataPoints);

        context->metrics.min = context->metrics.points[0].value;
        context->metrics.max = context->metrics.points[0].value;

        for (int i = 0; i < count; i++) {
            double val = context->metrics.points[i].value;
            if (val < context->metrics.min) context->metrics.min = val;
            if (val > context->metrics.max) context->metrics.max = val;
        }

        if (count % 2 == 1) {
            context->metrics.median = context->metrics.points[count/2].value;
        } else {
            context->metrics.median = (context->metrics.points[count/2 - 1].value +
                                       context->metrics.points[count/2].value) / 2.0;
        }
    }
}

void freeResources(AppContext* context) {
    if (!context) return;

    if (context->tableData.headers) {
        for (int i = 0; i < context->tableData.cols; i++) {
            if (context->tableData.headers[i]) {
                free(context->tableData.headers[i]);
            }
        }
        free(context->tableData.headers);
        context->tableData.headers = NULL;
    }

    if (context->tableData.matrix) {
        for (int i = 0; i < context->tableData.rows; i++) {
            if (context->tableData.matrix[i]) {
                for (int j = 0; j < context->tableData.cols; j++) {
                    if (context->tableData.matrix[i][j])
                        free(context->tableData.matrix[i][j]);
                }
                free(context->tableData.matrix[i]);
            }
        }
        free(context->tableData.matrix);
        context->tableData.matrix = NULL;
    }

    if (context->tableData.dataPoints) {
        free(context->tableData.dataPoints);
        context->tableData.dataPoints = NULL;
    }

    if (context->metrics.points) {
        free(context->metrics.points);
        context->metrics.points = NULL;
    }

    context->tableData.rows = 0;
    context->tableData.cols = 0;
    context->tableData.dataPointsCount = 0;
    context->tableData.invalidRows = 0;
    context->metrics.count = 0;
    context->fileLoaded = false;
    context->dataFiltered = false;
    context->currentFilePath[0] = '\0';
}
