#include <iostream>
using namespace std;
int main() {
  int school_hours, home_hours;
  int week_day = 0, max = 8;
  for (int i = 1; i <= 7; i++) {
    cin >> school_hours >> home_hours;
    int current_hours = school_hours + home_hours;
    if (current_hours > max) {
      max = current_hours;
      week_day = i;
    }
  }
  cout << week_day << endl;
  return 0;
}