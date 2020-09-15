# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <iomanip>
# include <ctime>
# include <cstring>
# include "GAoptimizer.h"

using namespace std;

int main()

//****************************************************************************80
//
//  Purpose:
//
//    MAIN supervises the genetic algorithm.
//
//  Discussion:
//
//    Each generation involves selecting the best 
//    members, performing crossover & mutation and then 
//    evaluating the resulting population, until the terminating 
//    condition is satisfied   
//
//    This is a simple genetic algorithm implementation where the 
//    evaluation function takes positive values only and the 
//    fitness of an individual is the same as the value of the 
//    objective function.  
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 April 2014
//
//  Author:
//
//    Original version by Dennis Cormier and Sita Raghavan.
//    This C++ version by John Burkardt.
//
//  Reference:
//
//    Zbigniew Michalewicz,
//    Genetic Algorithms + Data Structures = Evolution Programs,
//    Third Edition,
//    Springer, 1996,
//    ISBN: 3-540-60676-9,
//    LC: QA76.618.M53.
//
//  Parameters:
//
//    MAXGENS is the maximum number of generations.
//
//    NVARS is the number of problem variables.
//
//    PMUTATION is the probability of mutation.
//
//    POPSIZE is the population size. 
//
//    PXOVER is the probability of crossover.                          
//
{
    string filename = "input.txt";
    int generation;
    int i;
    int seed;

    timestamp();
    cout << "\n";
    cout << "SIMPLE_GA:\n";
    cout << "  C++ version\n";
    cout << "  A simple example of a genetic algorithm.\n";

    if (NVARS < 2)
    {
        cout << "\n";
        cout << "  The crossover modification will not be available,\n";
        cout << "  since it requires 2 <= NVARS.\n";
    }

    seed = 123456789;

    initialize(filename, seed);

    evaluate();

    keep_the_best();

    for (generation = 0; generation < MAXGENS; generation++)
    {
        selector(seed);
        crossover(seed);
        mutate(seed);
        report(generation);
        evaluate();
        elitist();
    }

    cout << "\n";
    cout << "  Best member after " << MAXGENS << " generations:\n";
    cout << "\n";

    for (i = 0; i < NVARS; i++)
    {
        cout << "  var(" << i << ") = " << population[POPSIZE].gene[i] << "\n";
    }

    cout << "\n";
    cout << "  Best fitness = " << population[POPSIZE].fitness << "\n";
    //
    //  Terminate.
    //
    cout << "\n";
    cout << "SIMPLE_GA:\n";
    cout << "  Normal end of execution.\n";
    cout << "\n";
    timestamp();

    return 0;
}
//****************************************************************************80
