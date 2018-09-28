#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <thread>
#include <mutex>
#include <sstream>
#include <condition_variable>
#include <cstdlib>
using namespace std;

mutex mu;
condition_variable cond;

void printOccurences(string s,int p, int k, int n, int& r, int& counter, int i){
    int own_k = k;
    int pid = i;
    int l = s.length();
    while(own_k != 0)
    {
        if(own_k == k && i == 1){
            unique_lock<mutex> locker(mu);
            string copy_str = s + s;
            cout << "Thread "<<pid<<": "<<copy_str.substr(r, n)<<'\n';
            r = (r + n) % l;
            own_k -= 1;
            counter = (counter + 1)%p;
            locker.unlock();
            cond.notify_all();
        }
        else{
            unique_lock<mutex> locker(mu);
            while(counter != pid-1)
                cond.wait(locker);
            string copy_str = s + s;
            cout << "Thread "<<pid<<": "<<copy_str.substr(r, n)<<'\n';
            r = (r + n) % l;
            own_k -= 1;
            counter = (counter + 1)%p;
            locker.unlock();
            cond.notify_all();
        }
    }
}
int main(int argc, char** argv){
    if(argc != 5){
        cout << "Arg: [string] [p] [k] [n] \n";
        return 0;
    }
    string s = argv[1];
    int p, k, n, counter=0;
    p = atoi(argv[2]);
    k = atoi(argv[3]);
    n = atoi(argv[4]);
    int r = 0;
    vector<thread> v;
    bool inside = false;
    for(int i=0; i<p; i++){
        thread threadobj(&printOccurences, s, p, k, n, ref(r), ref(counter), i+1);
        v.push_back(move(threadobj));
    }
    for(int i=0; i<p; i++){
        if(v[i].joinable())
        {
            v[i].join();
        }
    }
    return 0;
}