/*****************
 * Program:run_states.cpp
 * Author: Kaitlin Hill
 * Date: 4/16/17
 * Description: Organize state information and print or write info to a file.
 * Input: Number of states, file name, amount they want the states to be above, want to write to file or print and if they want to run again.
 * Output: State info
 * ****************/
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "./state_facts.h"
using namespace std;

/*****************************
 * Function: largest_population_state 
 * Description: finds the largest population
 * Parameters: s, num_of_states, lar_pop
 * Pre-conditions: Parmeters must have values
 * Post-conditions: lar_pop_string will have a string
 * Return: lar_pop
 * ******************************/
string largest_population_state(state *s, int num_of_states, int &lar_pop){
   int pop = 0;
   string lar_pop_string;
   for(int i = 0; i<2; i++){
      if (s[i].population > pop){
	 pop = s[i].population;
         lar_pop_string = s[i].name;
	 lar_pop = s[i].population;

      }
   }
   return lar_pop_string;
}

/*****************************
 * Function: state_by_name 
 * Description: orders states by name
 * Parameters: s, num_of_state
 * Pre-conditions: num_of_states must be num of states
 * Post-conditions: state_by_name will have something
 * Return: state_by_name
 * ******************************/
string * state_by_name(state *s, int num_of_states){
   string *state_by_name = new string[num_of_states];
   int j =0;
   for (char u_letter=65; u_letter < 91; u_letter++){
      for (int i = 0; i < num_of_states; i++){
         if (s[i].name.at(0) == u_letter){
            state_by_name[j] = s[i].name;
	    j++;
         }
      }
   }
 return state_by_name;  
}
/*****************************
 * Function: state_by_pop 
 * Description: orders state by pop
 * Parameters: s, num_of_state
 * Pre-conditions: incoming variables must have values
 * Post-conditions: state_pop has value
 * Return: state_pop
 * ******************************/
string * state_by_pop(state *s, int num_of_state, int lar_pop){
   int num_of_state_2 = num_of_state-1;
   string *state_pop = new string[num_of_state];

   for(int i=0; i<=lar_pop; i++){
      for(int j=0; j<num_of_state; j++){
         if(s[j].population == i){
	    state_pop[num_of_state_2] = s[j].name;
	    num_of_state_2--;
	 }
      }
   }
   return state_pop;
}
/*****************************
 * Function: find_county_with_largest_pop 
 * Description: finds county with largest pop
 * Parameters: s, num_of_states, county_lar_pop
 * Pre-conditions: incoming variables must have values
 * Post-conditions: return variable has value
 * Return: county_lar_pop
 * ******************************/
string find_county_with_largest_pop(state *s, int num_of_states, int &county_lar_pop){
   string county_lar_pop_str;
   for(int i=0; i<num_of_states; i++){
      for(int j=0; j<s[i].counties; j++){
         if(s[i].c[j].population > county_lar_pop){
	    county_lar_pop_str = s[i].c[j].name;
	    county_lar_pop = s[i].c[j].population;
	 }
      }
   }
   return county_lar_pop_str;
}
/*****************************
 * Function: counties_avg_income 
 * Description: finds the income above a user defined amount
 * Parameters:s, num_of_states, num_of_counties
 * Pre-conditions: incoming variables must have value
 * Post-conditions: outgoing variable has values
 * Return: income_arr
 * ******************************/
string * counties_avg_income(state *s, int num_of_states, int &num_of_counties){
   float income;
   int g=0;
   for(int i=0; i<num_of_states; i++){
      num_of_counties += s[i].counties;
   }
   string *income_arr = new string [num_of_counties];

   cout << "What specific income would you like to use?" << endl;
   cin >> income;
   for(int i=0; i<num_of_states; i++){
      for(int j=0; j<s[i].counties; j++){
         if(s[i].c[j].avg_income > income){
	    income_arr[g] = s[i].c[j].name;
	    g++;
	 }
      }
   }
   return income_arr;
}
/*****************************
 * Function: avg_house 
 * Description: finds the avg house cost
 * Parameters: s, num_of_states
 * Pre-conditions: incoming variables must have value
 * Post-conditions: outgoing variable has value
 * Return: avg_house
 * ******************************/
float * avg_house(state *s, int num_of_states){
   float *avg_house = new float [num_of_states];
   for(int i=0; i<num_of_states; i++){
      avg_house[i] = 0;
   }
   for(int i=0; i<num_of_states; i++){
      for(int j=0; j<s[i].counties; j++){
         avg_house[i] += s[i].c[j].avg_house;
      }
      avg_house[i] = avg_house[i]/s[i].counties;
   }
   return avg_house;
}
/*****************************
 * Function: counties_by_population
 * Description: orders counties by their population
 * Parameters: s, num_of_states, num_of_counties, lar_pop_c
 * Pre-conditions: incoming variables must have value
 * Post-conditions: outgoing variable has value
 * Return:counties_by_pop
 * ******************************/
string * counties_by_population(state *s, int num_of_states, int num_of_counties, int lar_pop_c){
   int temp_num_of_counties = num_of_counties;
   string *counties_by_pop = new string[num_of_counties];
   for(int i=(num_of_states-1); i>=0; i--){
      for(int k =0; k<=lar_pop_c; k++){
	 for(int j=0; j<s[i].counties; j++){
	    if(s[i].c[j].population == k){
	       counties_by_pop[temp_num_of_counties-1] = s[i].c[j].name;
	       temp_num_of_counties--;
	    }
	 }
      }
   }
   return counties_by_pop;
}
/*****************************
 * Function: counties_by_name
 * Description: lists counties by name
 * Parameters: s, num_of_states, num_of_counties
 * Pre-conditions: incoming variables must have value
 * Post-conditions: outgoing variable has value
 * Return: counties_by_name
 * ******************************/
string * counties_by_name(state * s, int num_of_states, int num_of_counties){
   string *counties_by_name = new string[num_of_counties];
   int f = 0;
   for(int i=0; i<num_of_states; i++){
      for(int k=65; k<91; k++){
         for(int j=0; j<s[i].counties; j++){
	    if(s[i].c[j].name.at(0) == k){
	       counties_by_name[f] = s[i].c[j].name;
	       f++;
	    }
	 }
      }
   }
   return counties_by_name;
}

/*****************************
 * Function: write_to_file 
 * Description: writes info to file
 * Parameters: variables that we returned and variables that help us iterate through the arrays
 * Pre-conditions: incoming variables must have value
 * Post-conditions: None
 * Return: none
 * ******************************/
void write_to_file(ofstream &write, int num_of_states, int num_of_counties, char *file_name, float *avg_house_arr, string *counties_by_pop_arr,string *counties_by_name_arr, 
      string *state_by_name_arr, string largest_pop_state_name, string *state_by_pop_arr, string largest_pop_county_str, string *counties_avg_income_arr){
   write.open(file_name);
   write << "States by name:" << endl;
   for(int i=0; i<num_of_states; i++){
      write << state_by_name_arr[i] << ' ';
   }
   write << endl;
   write << "States by population:" << endl;
   for(int i=0; i<num_of_states; i++){
      write << state_by_pop_arr[i] << ' ';
   }
   write << endl;
   write << "State with largest population:" << endl;
   write << largest_pop_state_name << endl;
   write << "Counties by name by state:" << endl;
   for(int j=0; j<num_of_counties; j++){
      write << counties_by_name_arr[j] << ' ';
   }
   write << endl;
   write << "Counties by population by state:" << endl;
   for(int j=0; j<num_of_counties; j++){
      write << counties_by_pop_arr[j] << ' ';
   }
   write << endl;
   write << "County with largest population:" << endl;
   write << largest_pop_county_str<< endl;
   write << "Counties with income above specified amount:" << endl;
   for(int j=0; j<num_of_counties; j++){
      write << counties_avg_income_arr[j] << ' ';
   }
   write << endl;
   write << "Average household cost of counties per state:" << endl;
   for(int j=0; j<num_of_states; j++){
      write << avg_house_arr[j] << ' ';
   }
   write << endl;
   write.close();
}
/*****************************
 * Function: print_to_file 
 * Description: prints info to a file
 * Parameters: variables that we returned and variables that help us iterate through the arrays
 * Pre-conditions: incoming variables must have value
 * Post-conditions: file has been written to
 * Return: none
 * ******************************/
void print_to_file(int num_of_states, int num_of_counties, float *avg_house_arr, string *counties_by_pop_arr,string *counties_by_name_arr, string *state_by_name_arr,
   string largest_pop_state_name, string *state_by_pop_arr, string largest_pop_county_str, string *counties_avg_income_arr){
   cout << "States by name:" << endl;
   for(int i=0; i<num_of_states; i++){
      cout << state_by_name_arr[i] << ' ';
   }
   cout << endl;
   cout << "States by population:" << endl;
   for(int i=0; i<num_of_states; i++){
      cout << state_by_pop_arr[i] << ' ';
   }
   cout << endl;
   cout << "State with largest population:" << endl;
   cout << largest_pop_state_name << endl;
   cout << "Counties by name by state:" << endl;
   for(int j=0; j<num_of_counties; j++){
      cout << counties_by_name_arr[j] << ' ';
   }
   cout << endl;
   cout << "Counties by population by state:" << endl;
   for(int j=0; j<num_of_counties; j++){
      cout << counties_by_pop_arr[j] << ' ';
   }
   cout << endl;
   cout << "County with largest population:" << endl;
   cout << largest_pop_county_str<< endl;
   cout << "Counties with income above specified amount:" << endl;
   for(int j=0; j<num_of_counties; j++){
      cout << counties_avg_income_arr[j] << ' ';
   }
   cout << endl;
   cout << "Average household cost of counties per state:" << endl;
   for(int j=0; j<num_of_states; j++){
      cout << avg_house_arr[j] << ' ';
   }
   cout << endl;
}
/*****************************
 * Function: print_or_write
 * Description: allows user to pick between printing and writing info to file
 * Parameters: variables that we returned and variables that hel us iterate through the arrays
 * Pre-conditions: none
 * Post-conditions: none
 * Return: none
 * ******************************/
void print_or_write(char *file_name, int num_of_states, int num_of_counties, float *avg_house_arr, string *counties_by_pop_arr,string *counties_by_name_arr, string *state_by_name_arr,
   string largest_pop_state_name, string *state_by_pop_arr, string largest_pop_county_str, string *counties_avg_income_arr, ofstream &write){
   char p_or_w;
   cout<< "Press p to print the information or any other key to write the material to a file" << endl;
   cin >> p_or_w;
   cin.ignore();
   if(p_or_w == 'p' || p_or_w == 'P'){
      print_to_file(num_of_states, num_of_counties, avg_house_arr, counties_by_pop_arr, counties_by_name_arr, state_by_name_arr, largest_pop_state_name, state_by_pop_arr,
	    largest_pop_county_str, counties_avg_income_arr);
   }
   else{
      cout << "What file would you like to write to?" << endl;
      cin.getline(file_name, 256);
      write_to_file(write, num_of_states, num_of_counties, file_name, avg_house_arr, counties_by_pop_arr, counties_by_name_arr, state_by_name_arr, largest_pop_state_name, 
	    state_by_pop_arr, largest_pop_county_str, counties_avg_income_arr);
   }
}
   
/*****************************
 * Function: delete_info 
 * Description: deletes the dyamic memory
 * Parameters: s, num_of_states
 * Pre-conditions: incoming variables must have value
 * Post-conditions: the dynamic arrays will no longer exist
 * Return: none
 * ******************************/
void delete_info(state ** s, int num_of_states){
   for (int i = 0; i < num_of_states; i++){
	  for(int j=0; j<(*s)[i].counties; j++){
	     delete [] (*s)[i].c[j].city;
	     (*s)[i].c[j].city = NULL;
	  }
	  delete [] (*s)[i].c;
	  (*s)[i].c = NULL;
       }
       delete [] *s;
       *s = NULL;
}
/*****************************
 * Function: get_county_data 
 * Description: reads in county data
 * Parameters: c, num_of_counties, read
 * Pre-conditions: incoming variables must have value
 * Post-conditions: c will have info
 * Return: one
 * ******************************/
void get_county_data(county *c, int num_of_counties, ifstream &read){
   for(int j=0; j<num_of_counties; j++){
      read >> c[j].name;
      read >> c[j].population;
      read >> c[j].avg_income;
      read >> c[j].avg_house;
      read >> c[j].cities;
      c[j].city = new string[c[j].cities];
      for (int k=0; k<c[j].cities; k++){
	 read >> c[j].city[k];
      }	    
   }
}
/*****************************
 * Function: create_counties 
 * Description: creates the array of counties
 * Parameters: counties
 * Pre-conditions: incoming variable must have value
 * Post-conditions: c will be created
 * Return: c
 * ******************************/
county * create_counties(int counties){
   county *c;
   c = new county[counties];
   return c;
}
/*****************************
 * Function: get_state_data 
 * Description: gets state data
 * Parameters: s, num_of_states, read
 * Pre-conditions: incoming variables must have data
 * Post-conditions: state will hold info
 * Return: none
 * ******************************/
void get_state_data(state *s, int num_of_states, ifstream &read){
   county *c;
   for(int i=0; i<num_of_states; i++){
      read >> s[i].name;
      read >> s[i].population;
      read >> s[i].counties;
      s[i].c = create_counties(s[i].counties);
      get_county_data(s[i].c, s[i].counties, read);
   }
   read.close();
}
/*****************************
 * Function: create_state
 * Description: create state
 * Parameters: num_of_state
 * Pre-conditions: incoming variables must have value
 * Post-conditions: s has value
 * Return: s
 * ******************************/
state * create_states(int num_of_states){
   state *s = new state[num_of_states];
   return s;
}
/*****************************
 * Function: is_valid_arguments 
 * Description: checks for good input
 * Parameters: argv, argc
 * Pre-conditions: incoming variables must have value
 * Post-conditions: outgoing variable will have value
 * Return: true or false value
 * ******************************/     
bool is_valid_arguments(char *argv[], int argc){
   int options = 0;
   bool bad = false;
   int where_s;
   int where_f;

   if(argc != 5){
      cout<< "You are missing an argument"<< endl;
      return false;
      }
   for(int i=0; i<5; i++){
      if (((argv[i][0]) == '-' && (argv[i][1] == 's')) || ((argv[i][0] == '-') && (argv[i][1] == 'S'))){
         options++;
	 where_s = i;
      }
   }
   for(int i=0; i<5; i++){
      if (((argv[i][0] == '-') && (argv[i][1] == 'f')) || ((argv[i][0] == '-') && (argv[i][1] == 'F'))){
         options++;
	 where_f = i;
      }
   }
   if(options != 2){
      cout<< "You did not put in the right options." << endl;
      return false;
   }
   char num_of_states[strlen(argv[where_s+1])];
   strcpy(num_of_states, argv[where_s+1]);
   bool checker = false;
   do{
      for(int i=0; i<strlen(num_of_states); i++){
         if((num_of_states[i] < '0' || num_of_states[i] > '9') || (num_of_states[0] == '0')){
            cout << "Not a good number of states. "<< "Enter a positive integer greater than one" << endl;
	    cin.getline(num_of_states, 256);
	    bad = true; 
	    checker = true;
         } 
      }
      if(checker == false){
         bad = false;
      }
    checker = false;
   }while(bad == true);
   strcpy(argv[where_s+1], num_of_states);
   return true;
}
/*****************************
 * Function: delete_arrays
 * Description: deletes dynamic memory
 * Parameters: state_by_name_arr, state_by_pop_arr, counties_avg_income_arr, avg_house_arr, counities_by_pop_arr
 * Pre-conditions: incoming variables must have value
 * Post-conditions: dyanamic memory is cleared
 * Return: none
 * ******************************/
void delete_arrays(string *state_by_name_arr, string *state_by_pop_arr, string *counties_avg_income_arr, float *avg_house_arr, string *counties_by_pop_arr, 
      string *counties_by_name_arr){
  delete [] state_by_name_arr;
  state_by_name_arr = NULL;
  delete [] state_by_pop_arr;
  state_by_pop_arr = NULL;
  delete [] counties_avg_income_arr;
  counties_avg_income_arr = NULL;
  delete [] avg_house_arr;
  avg_house_arr = NULL;
  delete [] counties_by_pop_arr;
  counties_by_pop_arr = NULL;
  delete [] counties_by_name_arr;
  counties_by_name_arr = NULL;
}
/*****************************
 * Function: run_again
 * Description: asks user if they want to go again
 * Parameters: argv
 * Pre-conditions: incoming variable must have value
 * Post-conditions: dynamic memory will be cleared or argv will have new values
 * Return: true of false
 * ******************************/
bool run_again(char **argv){
   char again_char;
   bool again;
   cout << "Press t to run again and any other key to quit:" << endl;
   cin >> again_char;
   cin.ignore();
   if((again_char == 't') || (again_char == 'T')){
      again = true;
      cout << "How many states would you like?" << endl;
      cin >> argv[2];
      cin.ignore();
      cout << "What file do you want to read from?" << endl;
      cin >> argv[4];
      cin.ignore();
      char a[6] = "a.out";
      strcpy(argv[0], a);
      char s[3] = "-s";
      strcpy(argv[1], s);
      char f[3] = "-f";
      strcpy(argv[3], f);
   }
   else{
      again = false;
      for(int i=0; i<5; i++){
         delete [] argv[i];
	 argv[i] = NULL;
      }
      delete [] argv;
      argv = NULL;
   }
   return again;
}
