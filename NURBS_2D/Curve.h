#pragma once

#include <vector>
#include <QPoint>

struct CurvePoint
{
    QPoint point;        // Координаты точки кривой
    QPoint firstDeriv;   // Координаты 1-ой производной
    QPoint secondDeriv;  // Координаты 2-ой производной
    double parameter;    // Элемент реальной части узлового вектора
    int span;   // Номер интервала, к которому относится CurvePoint
};

class Curve
{
public:
    Curve(const std::vector<QPoint> &controlPoints, const std::vector<double> &weights, int degree, int numRealRangePoints) noexcept;

private:
    std::vector<QPoint> _controlPoints;    // Точки определяющего многоугольника
    std::vector<CurvePoint> _pointsNURBS;  // Точки кривой
    std::vector<double> _nodalVector;      // Узловой вектор
    std::vector<double> _weights;          // Весовые коэффициенты точек определяющего многоугольника
    int _realRangeStart, _realRangeEnd;    // Начало/конец реального диапазона узлового вектора
    int _numRealRangeKnots;  // Кол-во узлов (длина) реальной части узлового вектора
    int _numRealRangePoints; // Кол-во точек (разбиений) в реальной части узлового вектора
    int _numVertices;   // Кол-во вершин в определяющем многоугольнике
    int _numKnots;      // Кол-во узлов (длина) в узловом векторе
    int _degree;        // Степень полинома
};