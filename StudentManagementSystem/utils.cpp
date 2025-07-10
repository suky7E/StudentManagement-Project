#include "utils.h"
#include <algorithm>

using namespace std;

string toLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}
