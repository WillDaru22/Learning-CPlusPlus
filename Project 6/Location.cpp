// I wrote the to_string and IsReservable functions inline in the .h file, so this one is just empty.
#include "Location.h"

float Location::operator-(const Position that) {
    return posit.operator-(that);
}