#include <stdio.h>
//Class Activity. Pedro Alejandro Uicab Diaz

//Date of birth structure
typedef struct date_of_birth{
  int day;
  int month;
  int year;
}birth_s;

//Patients structure
typedef struct patient{
  char first_name[10];
  char last_name[15];
  char gender[10];
  float height;
  float weight;
  birth_s date;
}patient_s;

// Function prototype to request the date
birth_s create_date();
// Function prototype to request data
patient_s create_profile();
// Function prototype to print data
void print_profile(patient_s profile);
// Age function prototype
void calculate_age(patient_s age);
// MHR and HRR function prototype
void calculate_heart(int x);
// IMB function prototype
float calculate_ibm(patient_s ibm);


int main(void){
  //Creation of variable
  patient_s HealthProfile;

  //Creation of HealthProfile data
  HealthProfile=create_profile();

  //Data printing
  print_profile(HealthProfile);

  //Age and MHR, THRR Calculations
  calculate_age(HealthProfile);

  //Returns of IBM
  printf("Your current IBM is: %.2f\n",calculate_ibm(HealthProfile));
  printf("\n\t****************\n");
  printf("BMI values\nUnderweight: Less than 18.5\nNormal: Between 18.5 and 24.9\nOverweight: Between 25 and 29.9\nObese: 30 or greater\n");
  printf("\t****************\n");


  return 0;
}

// Function to request the date
birth_s create_date(){

  birth_s new_date; // New variable

  printf("\n\nType your date of birth\n");
  // Asking for day
  printf("Day:"); fflush(stdin);
  scanf("%d",&new_date.day);
  // Asking for month
  printf("Month:"); fflush(stdin);
  scanf("%d",&new_date.month);
  // Asking for year
  printf("Year:"); fflush(stdin);
  scanf("%d",&new_date.year);

  return new_date;
}

// Function  to request data
patient_s create_profile(){

  patient_s new_profile; // New variable
  printf("Fill Up, Please");
  // Asking for name
  printf("\n\nFirst name:"); fflush(stdin);
  gets(new_profile.first_name);
  // Asking for last name
  printf("Last name:"); fflush(stdin);
  gets(new_profile.last_name);
  // Asking for gender
  printf("Gender:"); fflush(stdin);
  gets(new_profile.gender);
  // Asking for date
  new_profile.date=create_date();
   // Asking for height
  printf("\n\nHeight:"); fflush(stdin);
  scanf("%f",&new_profile.height);
  // Asking for Weight
  printf("Weight:"); fflush(stdin);
  scanf("%f",&new_profile.weight);

  return new_profile;
}

// Function to print data
void print_profile(patient_s profile){
  printf("\n\t****************");
  printf("\n\tYour HealthProfile");
  printf("\n\t****************\n");

  printf("First name: %s\nLast name: %s\nGender: %s\n",profile.first_name,profile.last_name,profile.gender);

  printf("Date of birth: %d /%d /%d\n",profile.date.day,profile.date.month,profile.date.year);

  printf("Height: %.2f\nWeight: %.2f\n",profile.height,profile.weight);
}

// Age function
void calculate_age(patient_s age){

  int c_age=2020-age.date.year;
  calculate_heart(c_age);

}

// MHR and HRR function
void calculate_heart(int x){

  int mhr= 220 - x;
  int low= (mhr * .50);
  int upper= (mhr * .85);
  printf("Your current age is: %d\n",x);
  printf("Your Maximmus Heart Rate is: %d\n",mhr);
  printf("Your Target-Heart-Rate would be between %d - %d beats per minute.\n",low,upper);

}

//IMB function
float calculate_ibm(patient_s ibm){

  float IBM_mark=((ibm.weight)/(ibm.height * ibm.height));

  return IBM_mark;
}
