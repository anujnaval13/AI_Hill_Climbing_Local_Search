
#ifndef SPORTSLAYOUT_H
#define	SPORTSLAYOUT_H

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct neighbour
{
    vector<int> arr;
    long long cost;
};

class SportsLayout{

    private:
    int z,l;
    int** T;
    int **N;

    public:

    vector<int> mapping;
    float time;
    SportsLayout(string inputfilename);

    bool check_output_format();

    // void readOutputFile(string output_filename);
    
    long long cost_fn(vector<int> &mapp);

    void write_to_file(string outputfilename, vector<int> &arr);

    void readInInputFile(string inputfilename);

    void random_fn();

    vector<neighbour> create_neighbourhood();

    vector<int> hill_climbing_helper();

    vector<int> hill_climbing();

    void print_vector(vector<int> &arr);

};


#endif