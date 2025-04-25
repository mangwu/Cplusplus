#include <iostream>

// 存储旅途的时间
struct travel_time {
  int hours;
  int mins;
};

const int Mins_per_hr = 60; // 小时分钟的转换系数

travel_time travel_time_sum(travel_time, travel_time);
void show_time(travel_time);
using namespace std;
int main(void) {
  travel_time day1 = {5, 45}; // 5h45
  travel_time day2 = {4, 55};

  cout << "day1: ";
  show_time(day1);
  cout << "day2: ";
  show_time(day2);

  travel_time trip = travel_time_sum(day1, day2);
  cout << "total: ";
  show_time(trip);

  travel_time day3 = {4, 32};
  cout << "day3: ";
  show_time(day3);
  cout << "Three-day total:" << endl;
  show_time(travel_time_sum(trip, day3));
  return 0;
}

travel_time travel_time_sum(travel_time tt1, travel_time tt2) {
  travel_time res;
  res.hours = tt1.hours + tt2.hours + (tt1.mins + tt2.mins) / Mins_per_hr;
  res.mins = (tt1.mins + tt2.mins) % Mins_per_hr;
  return res;
}
void show_time(travel_time tt) {
  cout << tt.hours << " hours," << tt.mins << " mins." << endl;
}
