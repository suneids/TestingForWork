#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QtOpenGL>
#include <QtWidgets>
#include <QDebug>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "circle.h"
#include "elipse.h"
#include "helix.h"

class GraphicWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    GraphicWidget(QWidget *parent = nullptr);
    ~GraphicWidget();
    void initializeGL() override;
    void paintGL() override;
    void FillContainer1();
    void ExtractCoordinates(std::vector<Figure*> container);
    QString CoordinateForPI4();
    QString DerivativesForPI4();
    void FillContainer2();
    void SortContainer2();
    float RadiusesSumOfContainer2();


    void RotateY(float y_angle);
    QString GetInfo(QString about);
    const std::vector<Figure*> GetContainer(int container_id) const;
private:
    void PrintAxis();
    float p_rotate_y;
    std::vector<Figure*> container1, container2;
    std::vector<Point> coordinates, axises;
};

bool CompareByR(const Figure* a, const Figure* b);
#endif
