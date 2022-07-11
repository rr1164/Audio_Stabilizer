#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>
#include "stabilizer.h"
class BackEnd : public QObject
{
    Q_OBJECT

public:
    BackEnd(QObject* parent);
    BackEnd(Stabilizer*& _stabilizer);
    BackEnd() = default;
    int after_slider_value = 0;
    Q_INVOKABLE int getaftervalue();
    ~BackEnd();

signals:
    void valueChanged(int after_value);

public slots:
    void set_division_coefficient(QString division_Coefficient);
    float get_division_coefficient();
    int get_before_slider_value();
    void set_delay_value(QString delay_Value);
    void set_before_slider_value(int slider_value);
    int get_delay_value();
    void set_increased_value(bool increase_low);
    bool get_increased_value();
    void set_decrease_value(bool decrease_high);
    bool get_decreased_value();

private:
    int delay_value = 150;
    float division_coefficient = 2.0;
    int before_slider_value = -1;
    bool increase_low_audio = false;
    bool decrease_high_audio = true;
    int timerId;
    Stabilizer* stabilizer = nullptr;
protected:
    void timerEvent(QTimerEvent* event);
};


#endif // BACKEND_H
