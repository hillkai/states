#include "./state_facts.h"
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main(int argc, char *argv[]){
   bool valid;
   int num_of_states;
   int where_state;
   int where_file;
   state *s;
   bool work = true;
   char file_name[256];
   int largest_pop_state = 0;
   int num_of_counties = 0;
   int largest_pop_county = 0;
   string *state_by_name_arr;
   string largest_pop_state_name;
   string *state_by_pop_arr;
   string largest_pop_county_str;
   string *counties_avg_income_arr;
   float *avg_house_arr;
   string *counties_by_pop_arr;
   string *counties_by_name_arr;
   char file_name_write[256];
   char **argv_make;
   bool again;

   argv_make = new char *[5];
   for(int i=0; i<5; i++){
      argv_make[i] = new char[256];
   }
   for(int i=0; i<5; i++){
     for(int j=0; j<256; j++){
       argv_make[i][j] = '\0';
     }
   }     
   
   for(int i=0; i<5; i++){
      for(int j=0; j<strlen(argv[i]); j++){
         argv_make[i][j] = argv[i][j];
      }
   }
     
    do{
      largest_pop_state = 0;
      num_of_counties = 0;
      largest_pop_county = 0;
      memset((void *)file_name, 0, 256);
      memset((void *)file_name_write, 0, 256);
      valid = is_valid_arguments(argv_make, argc);
      if(valid){
	 for(int i=0; i<5; i++){
	    if (((argv_make[i][0]) == '-' && (argv_make[i][1] == 's')) || ((argv_make[i][0] == '-') && (argv_make[i][1] == 'S'))){
	       where_state = i+1; 
	    }
	 }
	 if(where_state == 2){
	    where_file = 4;
	 }
	 else if(where_state == 4){
	    where_file = 2;
	 }
	 num_of_states = atoi(argv_make[where_state]);
      }
      else{
	 exit(0);
      }
      strcpy(file_name, argv_make[where_file]);
      std::ifstream read;
      std::ofstream write;
      work = true;
      while(work == true){
	 read.open(file_name);
	 if(read.fail()){
	    read.close();
	    read.clear();
	    cout << "The file failed to open! Please enter a good file name!" << endl;
	    cin.getline(file_name, 256);
	    work = true;
	 }
	 else{
	    work = false;
	 }
      }  
   s=create_states(num_of_states);
   get_state_data(s, num_of_states, read);
   state_by_name_arr = state_by_name(s, num_of_states);
   largest_pop_state_name = largest_population_state(s, num_of_states, largest_pop_state);
   state_by_pop_arr = state_by_pop(s, num_of_states, largest_pop_state);
   largest_pop_county_str = find_county_with_largest_pop(s, num_of_states, largest_pop_county);
   counties_avg_income_arr = counties_avg_income(s, num_of_states, num_of_counties);
   avg_house_arr = avg_house(s, num_of_states);
   counties_by_pop_arr = counties_by_population(s, num_of_states, num_of_counties, largest_pop_county);
   counties_by_name_arr = counties_by_name(s, num_of_states, num_of_counties);
   print_or_write(file_name_write, num_of_states, num_of_counties, avg_house_arr, counties_by_pop_arr, counties_by_name_arr, state_by_name_arr, largest_pop_state_name, 
	 state_by_pop_arr, largest_pop_county_str, counties_avg_income_arr, write);
   delete_arrays(state_by_name_arr, state_by_pop_arr, counties_avg_income_arr, avg_house_arr, counties_by_pop_arr, counties_by_name_arr);
   delete_info(&s, num_of_states);
   again = run_again(argv_make);
   }while(again == true);
   return 0;
}
