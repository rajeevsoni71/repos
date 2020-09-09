// Example program
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string timeConversion(const string &s) {
    string time[4];
    string token{};
    stringstream ss{ s };
    int i = 0;
    while (getline(ss,token , ':'))
    {
        time[i] = token;
        i++;
    }

    char ch[sizeof(time[2].c_str())+1] = {};
    strncpy_s(ch, time[2].c_str(),sizeof(time[2].c_str()));
    time[2] = "";
    int k = 0;
    while (ch[k]) {
        if (isalpha(ch[k])) {
            time[3] += ch[k];
        }
        else {
            time[2] += ch[k];
        }
        k++;
    }

   /* for (int j = 0; j < 4; j++)
        cout << time[j] << " ";
    cout << endl;*/

    if (!(time[3]).compare("PM")) {
        //cout << "it is night\n";
        int hh = atoi((time[0]).c_str());
            if (hh != 12)
                hh += 12;
            time[0] = to_string(hh);
    } else if (!(time[3]).compare("AM")) {
        int hh = atoi((time[0]).c_str());
        if (hh == 12) {
            time[0] = "00";
        }
    }
    time[0] += ":" + time[1] + ":" + time[2];
    return time[0];
}
int main()
{
    vector<string> vec{
     "12:05:45AM" ,
     "01:05:45AM" ,
     "02:05:45AM" ,
     "03:05:45AM" ,
     "04:05:45AM" ,
     "05:05:45AM" ,
     "06:05:45AM" ,
     "07:05:45AM" ,
     "08:05:45AM" ,
     "09:05:45AM" ,
     "10:05:45AM" ,
     "11:05:45AM" ,
     "12:05:45PM" ,
     "01:05:45PM" ,
     "02:05:45PM" ,
     "03:05:45PM" ,
     "04:05:45PM" ,
     "05:05:45PM" ,
     "06:05:45PM" ,
     "07:05:45PM" ,
     "08:05:45PM" ,
     "09:05:45PM" ,
     "10:05:45PM" ,
     "11:05:45PM" ,
     "12:05:45PM"
    };
    auto it = vec.begin();
    while(it != vec.end()) {
        cout << timeConversion(*it) << endl;
        it++;
    }
}
