#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> swap(vector<int> &arr, int i, int j)
{
    vector<int> arr2 = arr;
    int temp = arr2[i];
    arr2[i] = arr2[j];
    arr2[j] = temp;
    return arr2;
}

#include "SportsLayout.h"

SportsLayout::SportsLayout(string inputfilename)
{

    readInInputFile(inputfilename);
    mapping = vector<int>(l);
}

bool SportsLayout::check_output_format()
{

    vector<bool> visited(l, false);
    for (int i = 0; i < z; i++)
    {
        if ((mapping[i] >= 1 && mapping[i] <= l))
        {
            if (!visited[mapping[i] - 1])
                visited[mapping[i] - 1] = true;
            else
            {
                cout << "Repeated locations, check format\n";
                return false;
            }
        }
        else
        {
            cout << "Invalid location, check format\n";
            return false;
        }
    }

    return true;
}

// void SportsLayout::readOutputFile(string output_filename)
// {
//         fstream ipfile;
//         ipfile.open(output_filename, ios::in);
//         if (!ipfile) {
//             cout << "No such file\n";
//             exit( 0 );
//         }
//         else {

//             vector<int> ip;

//             while (1) {
//                 int t;
//                 ipfile >> t;
//                 ip.push_back(t);
//                 if (ipfile.eof())
//                     break;

//             }

//         if(ip.size()!=z)
//         {
//             cout<<"number of values not equal to number of zones, check output format\n";
//             exit(0);
//         }
//         for(int i=0;i<z;i++)
//         mapping[i]=ip[i];
//     ipfile.close();

//     if(!check_output_format())
//         exit(0);
//     cout<<"Read output file, format OK"<<endl;

//         }

// }

long long SportsLayout::cost_fn(vector<int> &mapp)
{

    long long cost = 0;

    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < z; j++)
        {
            cost += (long long)N[i][j] * (long long)T[mapp[i] - 1][mapp[j] - 1];
        }
    }

    return cost;
}

void SportsLayout::readInInputFile(string inputfilename)
{
    fstream ipfile;
    ipfile.open(inputfilename, ios::in);
    if (!ipfile)
    {
        cout << "No such file\n";
        exit(0);
    }
    else
    {

        ipfile >> time;
        ipfile >> z;
        ipfile >> l;

        if (z > l)
        {
            cout << "Number of zones more than locations, check format of input file\n";
            exit(0);
        }

        int **tempT;
        int **tempN;

        tempT = new int *[l];
        for (int i = 0; i < l; ++i)
            tempT[i] = new int[l];

        tempN = new int *[z];
        for (int i = 0; i < z; ++i)
            tempN[i] = new int[z];

        for (int i = 0; i < z; i++)
        {
            for (int j = 0; j < z; j++)
                ipfile >> tempN[i][j];
        }

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++)
                ipfile >> tempT[i][j];
        }

        ipfile.close();

        T = tempT;
        N = tempN;
    }
}

void SportsLayout::write_to_file(string outputfilename, vector<int> &arr)
{

    // Open the file for writing
    ofstream outputFile(outputfilename);

    // Check if the file is opened successfully
    if (!outputFile.is_open())
    {
        cerr << "Failed to open the file for writing." << std::endl;
        exit(0);
    }

    for (int i = 0; i < z; i++)
        outputFile << arr[i] << " ";

    // Close the file
    outputFile.close();

    //cout << "Allocation written to the file successfully." << endl;
}

void SportsLayout::random_fn()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, l);

    int arraySize = z;
    std::vector<int> randomNumbers;
    for (int i = 0; i < arraySize; i++)
    {
        int randomNumber = dist(gen);
        bool isUnique = true;

        for (int j = 0; j < i; j++)
        {
            if (randomNumber == randomNumbers[j])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique)
        {
            randomNumbers.push_back(randomNumber);
        }
        else
        {
            i--; // Retry for the same index
        }
    }
    for (int i = 0; i < z; i++)
    {
        mapping[i] = randomNumbers[i];
    }
}

vector<neighbour> SportsLayout::create_neighbourhood()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(1, l);
    vector<neighbour> my_neighbours;
    int n = z;
    int m = l;
    int diff = m - n;
    int count = std::min(n, diff);
    if (diff == 0)
    {
        count = 1;
    }
    vector<int> temp = mapping;
    //print_vector(temp);
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < count)
        {
            int rand_num = distribution(mt);
            if (rand_num == temp[i]) continue;
            //cout<<rand_num<<endl;

            if (std::find(temp.begin(), temp.end(), rand_num) == temp.end())
            {
                std::vector<int> t2 = temp;
                t2[i] = rand_num;
                long long t_cost = cost_fn(t2);
                neighbour nb; nb.arr = t2; nb.cost = t_cost;
                //print_vector(nb.arr);
                //cout<<t_cost<<endl;
                my_neighbours.push_back(nb);
                j++;
            }
            else
            {
                int pos = std::distance(temp.begin(), std::find(temp.begin(), temp.end(), rand_num));
                vector<int> t2 = temp;
                t2 = swap(t2, i, pos);
                long long t_cost = cost_fn(t2);
                neighbour nb; nb.arr = t2; nb.cost = t_cost;
                //print_vector(nb.arr);
                //cout<<t_cost<<endl;
                my_neighbours.push_back(nb);
                j++;
            }
        }
        i++;
    }
    return my_neighbours;
}

vector<int> SportsLayout::hill_climbing_helper()
{
    vector<int> temp = mapping;
    long long curr_cost = cost_fn(temp);
    vector<neighbour> nbs = create_neighbourhood();
    int n = nbs.size();
    int counter = 0;
    neighbour best_nb;
    best_nb.cost = 1000000000;
    while (counter < n)
    {
        neighbour nb = nbs[counter];
        long long t_cost = nb.cost;
        if (t_cost < best_nb.cost)
        {
            best_nb.arr = nb.arr;
            best_nb.cost = nb.cost;
        }
        counter++;
    }
    if (best_nb.cost >= curr_cost)
    {
        return temp;
    }
    else
    {
        mapping = best_nb.arr;
        return hill_climbing_helper();
    }
}

vector<int> SportsLayout::hill_climbing()
{
    vector<int> new_mapping;
    random_fn(); 
    vector<int> ans = hill_climbing_helper();
    new_mapping = ans;
    return new_mapping;
}

void SportsLayout::print_vector(vector<int> &arr)
{
    for (int i = 0; i<z; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}