#pragma once

class Counter {
private:
  int _value = 0;
  // If maxValue == -1, there is no up limit for counter
  // (except data type size)
  int _maxValue = -1;

public:
  Counter(int maxValue_=-1, int value_=0)
  : _value(value_), _maxValue(maxValue_)
  {}

  int getValue() { return _value; }
  void setValue(int newValue) {
    if (_maxValue != -1) {
      _value = max(0, min(newValue, _maxValue));
    }
  }

  int getMaxValue() { return _maxValue; }
  void setMaxValue(int newValue) {
    if (_maxValue < -1 || _maxValue == 0) {
      Serial.print("Try to assign next value to Counter::_maxValue: ");
      Serial.println(newValue);
      Serial.println("Counter::_maxValue cant <= 0, except -1!");
    }
    _maxValue = newValue;
    setValue(_value);
  }

  void increase() { setValue(_value + 1); }
  void decrease() { setValue(_value - 1); }

  void add(int value) { setValue(_value + value); }
  void substract(int value) { setValue(_value - value); }
};
