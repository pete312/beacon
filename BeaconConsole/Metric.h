#ifndef METRIC_H
#define METRIC_H

enum MetricType { Int, Dbl, Str };

struct Metric
{
    uint id;
    uint MetricType;
    int intVal;
    double dblVal;
};

struct MetricId
{
    uint id;
    QString name;
};

#endif // METRIC_H
