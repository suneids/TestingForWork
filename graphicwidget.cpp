#include "graphicwidget.h"
GraphicWidget::GraphicWidget(QWidget *parent)
{
    p_rotate_y = 0;
    axises.push_back(Point(0, 0, 0));
    axises.push_back(Point(50, 0, 0));

    axises.push_back(Point(0, 0, 0));
    axises.push_back(Point(0, 50, 0));

    axises.push_back(Point(0, 0, 0));
    axises.push_back(Point(0, 0, -50));
}

GraphicWidget::~GraphicWidget()
{

}

// Инициализация отрисовщика
void GraphicWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glViewport(700, 700, 700, 700);
}

// Функция отрисовки
void GraphicWidget::paintGL()
{
    glClearColor(0.8, 1.0, 1.0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-50, 50, -50, 50, -50, 50);
    glRotatef(0,30,0,0);
    PrintAxis();
    glColor3f(0,0,0);
    glBegin(GL_POINTS);
    for(unsigned long i = 0; i < coordinates.size(); i++)
        glVertex3f(coordinates[i].x, coordinates[i].y, coordinates[i].z);
    glEnd();

}

// Заполнение первого контейнера
void  GraphicWidget::FillContainer1()
{
    p_rotate_y = 0;
    for(unsigned long long i = 0; i < container1.size(); i++)
        delete container1[i];
    container1.clear();
    container2.clear();
    srand((unsigned)time(0));
    int count = rand()%7+3, next_figure_id;
    float r;
    Point start;
    for(int i = 0; i<count; i++)
    {
        next_figure_id = rand()%3;
        start = {float(rand()%60 - 30),
                       float(rand()%60 - 30),
                       float(rand()%60 - 30)};
        r = rand()%10 + 1;
        if(next_figure_id == 0)
        {
            start.z = 0;
            container1.push_back(new Circle(start, r));
        }
        else if(next_figure_id == 1)
        {
            start.z = 0;
            float r2 = rand()%10 + 1;
            container1.push_back(new Elipse(start, r, r2));
        }
        else if(next_figure_id == 2)
        {
            float step = (rand()%20+10)/10.0;
            container1.push_back(new Helix(start, r, step));
        }
    }
    ExtractCoordinates(container1);
}

// Вычисление координат при t = PI/4
QString GraphicWidget::CoordinateForPI4()
{
    QString result = "Coordinates for PI/4\n";
    for(unsigned long long i = 0; i < container1.size(); i++)
    {
        Point current = container1[i]->C(45);
        QString oName = QString::fromStdString(container1[i]->WhoAmI());
        oName = oName.left(oName.indexOf(','));
        result += oName  + "(" + QString::number(current.x) + ", " + QString::number(current.y) + ", " + QString::number(current.z) + ").\n";
    }
    return result;
}

// Вычисление производных при t = PI/4
QString GraphicWidget::DerivativesForPI4(){
    QString result = "Derivatives for PI/4:\n";
    for(unsigned long long i = 0; i< container1.size(); i++){
        QString oName = QString::fromStdString(container1[i]->WhoAmI());
        result += oName.left(oName.indexOf(',')) + ", ";
        std::vector<float> derivatives = container1[i]->DerivedAtPI4();
        for(unsigned long long i = 0; i < derivatives.size(); i++){
            result += QString::number(derivatives[i]) + ", ";
        }
        result +='\n';
    }
    return result;
}

// Заполнение второго контейнера
void GraphicWidget::FillContainer2(){
    for(unsigned long long i = 0; i < container1.size(); i++)
    {
        QString oName = QString::fromStdString(container1[i]->WhoAmI());
        oName = oName.left(oName.indexOf(','));
        if(oName == "Circle")
            container2.push_back(container1[i]);
    }
    ExtractCoordinates(container2);
}

// Функция сравнения фигур по радиусу для сортировка второго контейнера
bool CompareByR(const Figure* a, const Figure* b)
{
    return a->GetR() < b->GetR();
}

// Сортировка второго контейнера от меньшего радиуса к большему
void GraphicWidget::SortContainer2(){
    std::sort(container2.begin(), container2.end(), CompareByR);
}

float GraphicWidget::RadiusesSumOfContainer2(){
    float result = 0;
    for(unsigned long long i = 0; i < container2.size(); i++)
        result += container2[i]->GetR();
    return result;
}

// Создание сообщения о результате команды
QString GraphicWidget::GetInfo(QString  about)
{
    QString result = "\n";
    if(about == "fc1")
    {
        result += "Container 1 filled with:\n";
        for(unsigned long long i = 0; i < container1.size(); i++)
            result += QString::fromStdString(container1[i]->WhoAmI()) + '\n';
    }
    else if(about == "fc2")
    {
        result += "Container 2 filled with:\n";
        for(unsigned long long i = 0; i < container2.size(); i++)
            result += QString::fromStdString(container2[i]->WhoAmI()) + '\n';
    }
    else if(about == "4PICoords")
    {
        result += CoordinateForPI4();
    }
    else if(about == "4PIDers"){
        result += DerivativesForPI4();
    }
    else if(about == "sort2"){
        result += "Sorted container 2:\n";
        for(unsigned long long i = 0; i < container2.size(); i++)
            result += QString::fromStdString(container2[i]->WhoAmI()) + '\n';
    }
    else if(about == "radSum2"){
        result += "Sum of container 2` radiuses:" + QString::number(RadiusesSumOfContainer2()) + '\n';
    }
    return result;
}

//Запись координат объектов в массив для визуализации
void GraphicWidget::ExtractCoordinates(std::vector<Figure*> container)
{
    coordinates.clear();
    for(unsigned long long i = 0; i < container.size(); i++)
    {
        for(int j = 0; j < 360*container[i]->GetR(); j++)
            coordinates.push_back(container[i]->C(j));
    }
}

// Отрисовка осей
void GraphicWidget::PrintAxis(){
    for(unsigned long long i = 0; i < axises.size(); i+=2)
    {
        Point p1 = axises[i], p2 = axises[i+1];
        glColor3f(i==0, i==2, i==4);
        glBegin(GL_LINES);
        glVertex3f(p1.x, p1.y, p1.z);
        glVertex3f(p2.x, p2.y, p2.z);
        glEnd();
    }
}

// Афинное вычисление для вращения вокруг оси y
void GraphicWidget::RotateY(float y_angle) //
{
    float angle = (y_angle-this->p_rotate_y) * PI / 180;
    this->p_rotate_y = y_angle;
    float x = 0, z = 0;
    for (unsigned long long i = 0; i < coordinates.size(); i++)
    {
        float cosin = cos(angle), sinus = sin(angle);
        x = coordinates[i].x;
        z = coordinates[i].z;
        coordinates[i].x = x * cosin + z * sinus;
        coordinates[i].z = x * -sinus + z * cosin;
    }
    for (unsigned long long i = 0; i < axises.size(); i++)
    {
        float cosin = cos(angle), sinus = sin(angle);
        x = axises[i].x;
        z = axises[i].z;
        axises[i].x = x * cosin + z * sinus;
        axises[i].z = x * -sinus + z * cosin;
    }
}

//Геттер для контейнеров
const std::vector<Figure*> GraphicWidget::GetContainer(int container_id) const
{
    std::vector<Figure*> result;
    if(container_id == 1)
        result = this->container1;
    else
        result = this->container2;
    return result;
}
