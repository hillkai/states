#include<string>
#include<string.h>
#include<fstream>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct county{
   string name;
   string *city;
   int cities;
   int population;
   float avg_income;
   float avg_house;
};
struct state{
   string name;
   struct county *c;
   int counties;
   int population;
};

bool is_valid_arguments(char *[], int);
state * create_states(int);
void get_state_data(state *, int, ifstream &);
county * create_counties(int);
void get_county_data(county *, int, ifstream &);
void delete_info(state ** , int);
string largest_population_state(state *, int, int &);
string * state_by_name(state *, int);
string * state_by_pop(state *, int, int);
string find_county_with_largest_pop(state *, int, int &);
string * counties_avg_income(state *, int, int &);
float * avg_house(state *, int);
string * counties_by_population(state *, int, int, int);
string * counties_by_name(state * , int, int);
void write_to_file(ofstream &, int, int, char *, float *, string *, string *, string *, string, string *, string, string *);
void print_to_file(int, int, float *, string *, string *, string *, string, string *, string, string *);
void print_or_write(char *, int, int, float *, string *, string *, string *, string, string *, string, string *, ofstream &);
void delete_info(state ** , int);
void get_county_data(county *, int, ifstream &);
county * create_counties(int);
void get_state_data(state *, int, ifstream &);
state * create_states(int);
void delete_arrays(string *, string *, string *, float *, string *, string *);
bool run_again(char **);
