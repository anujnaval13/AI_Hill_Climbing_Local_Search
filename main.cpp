#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>

#include "SportsLayout.h"

using namespace std;

int main(int argc, char** argv )
{

     // Parse the input.
    if ( argc < 3 )
    {   
        cout<<"Missing arguments\n";
        cout<<"Correct format : \n";
        cout << "./main <input_filename> <output_filename>";
        exit ( 0 );
    }
    string inputfilename ( argv[1] );
    string outputfilename ( argv[2] );
    
    std::chrono::high_resolution_clock::time_point start_time = std::chrono::high_resolution_clock::now();
    SportsLayout *s  = new SportsLayout( inputfilename );
    vector<int> best_map;
    long long best_cost = 1000000000;
    float minutes = s->time;
    std::chrono::high_resolution_clock::time_point end_time = start_time + std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(std::chrono::seconds(static_cast<long long>(minutes*60)));
    while (std::chrono::high_resolution_clock::now() < end_time)
    {
        vector<int> new_map = s->hill_climbing();
        long long new_cost = s->cost_fn(new_map);
        if (new_cost < best_cost)
        {
            best_cost = new_cost;
            best_map = new_map;
            s->print_vector(best_map);
            cout<< "cost:"<<best_cost<<endl;
        }
    }
    s->write_to_file(outputfilename, best_map);

    s->print_vector(best_map);
    cout<< "cost:"<<best_cost<<endl;


    return 0;

}