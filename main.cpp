#include "chartsqt.h"

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

QChart* BarChartExample()
{
    // Assign names to the set of bars used
    QBarSet *set0 = new QBarSet("Konior");
    QBarSet *set1 = new QBarSet("Grzegorzek");
    QBarSet *set2 = new QBarSet("Kosinski");
    QBarSet *set3 = new QBarSet("Kuczynski");
    QBarSet *set4 = new QBarSet("Wisniewski");

    // Assign values for each bar
    *set0 << 283 << 341 << 313 << 338 << 346 << 335;
    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
    *set3 << 248 << 244 << 265 << 281 << 278 << 313;
    *set4 << 323 << 287 << 299 << 315 << 306 << 313;

    // Add all sets of data to the chart as a whole
    // QBarSeries *series = new QBarSeries();
    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    // Pointer to the bar chart
    QChart* chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("Batting Avg by Year");

    // Define starting animation
//    chart->setAnimationOptions(QChart::NoAnimation);
//    chart->setAnimationOptions(QChart::GridAxisAnimations);
//    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    //chart->setAxisX(axis, series);  //for bar chart
    chart->setAxisY(axis, series);  //for stacked bar chart

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    // Apply palette changes to the application
    qApp->setPalette(pal);

    return chart;
}

QChart* LineChartExample()
{
    // Define points
    QLineSeries *series = new QLineSeries();
    series->append(0, 16);
    series->append(1, 25);
    series->append(2, 24);
    series->append(3, 19);
    series->append(4, 33);
    series->append(5, 25);
    series->append(6, 34);

    // Create chart, add data, hide legend and add axis
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Customize the title font
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Barry Bonds HRs as Pirate");

    // Change the line color and weight
    QPen pen(QRgb(0x000000));
    pen.setWidth(5);
    series->setPen(pen);

    chart->setAnimationOptions(QChart::AllAnimations);

    // Change the x-axis categories
    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("1986", 0);
    axisX->append("1987", 1);
    axisX->append("1988", 2);
    axisX->append("1989", 3);
    axisX->append("1990", 4);
    axisX->append("1991", 5);
    axisX->append("1992", 6);
    chart->setAxisX(axisX, series);

    return chart;
}

QChart* PieChartExample()
{
    //Define slices and percengage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("Vegetables", 0.40);
    series->append("Beans", 0.20);
    series->append("Fruits", 0.15);
    series->append("Seeds/Nuts", 0.10);
    series->append("Whole Grains", 0.15);

    // Add label to 1st slice
    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();

    // Add label, explode and define brush for 2nd slice
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    // Add labels to rest of slices
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();
    QPieSlice *slice3 = series->slices().at(3);
    slice3->setLabelVisible();
    QPieSlice *slice4 = series->slices().at(4);
    slice4->setLabelVisible();

    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Whad Wojtek likes");
    chart->legend()->hide();

    return chart;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the main app window
    QMainWindow window;

    // Create the chart widget
    QChart *chart = new QChart();
    chart = LineChartExample();
    chart = PieChartExample();
    chart = BarChartExample();

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set the main window widget
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();

    return a.exec();
}
