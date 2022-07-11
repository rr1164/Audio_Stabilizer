#include "backend.h"
BackEnd::BackEnd(QObject* parent) :
    QObject(parent)
{
    timerId = startTimer(delay_value);
}
BackEnd::BackEnd(Stabilizer*& _stabilizer) {
    timerId = startTimer(delay_value);
    stabilizer = _stabilizer;
    before_slider_value = stabilizer->get_original_volume();
    after_slider_value = stabilizer->get_original_volume();
}
void BackEnd::set_division_coefficient(QString division_Coefficient) {
    bool ok;
    auto x{ division_Coefficient.toFloat(&ok) };
    assert(ok);
    double tmp_coefficient = static_cast<double>(x);
    division_coefficient = tmp_coefficient;
    assert(ok);
}
void BackEnd::set_increased_value(bool increase_low) {
    increase_low_audio = increase_low;
}
void BackEnd::set_decrease_value(bool decrease_high) {
    decrease_high_audio = decrease_high;
}
void BackEnd::set_before_slider_value(int slider_value) {
    before_slider_value = slider_value;
}
void BackEnd::set_delay_value(QString delay_Value) {
    bool ok;
    delay_value = delay_Value.toInt(&ok);
    assert(ok);
    killTimer(timerId);
    timerId = startTimer(delay_value);
}
int BackEnd::get_delay_value() {
    return delay_value;
}
int BackEnd::getaftervalue() {
    return after_slider_value;
}
int BackEnd::get_before_slider_value() {
    return before_slider_value;
}
float BackEnd::get_division_coefficient() {
    return division_coefficient;
}
bool BackEnd::get_increased_value() {
    return increase_low_audio;
}
bool BackEnd::get_decreased_value() {
    return decrease_high_audio;
}
void BackEnd::timerEvent(QTimerEvent* event)
{
    float flt_before = static_cast<float> (before_slider_value) / static_cast < float> (100);
    float current_vol = 
        stabilizer->stabilize_audio(increase_low_audio, decrease_high_audio, division_coefficient, flt_before);
    after_slider_value = round(current_vol * 100);
    valueChanged(after_slider_value);
}
BackEnd::~BackEnd() {
    killTimer(timerId);
}
