#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


//Functions declarations
void fill_time(char *buffer, int format);
void fill_date(char *buffer);
int input_format();
void clear_screen();


int main() {
    char time_buffer[50],date_buffer[100];
    int format = input_format(); //Get time format

    while(1) {
        //Get current time
        fill_time(time_buffer,format); 
        //Get current date
        fill_date(date_buffer);
        //Clear screen
        clear_screen();

        printf("Current Time: %s\n",time_buffer);
        printf("Date: %s\n",date_buffer);

        //Wait 1 sec and refresh the screen
        sleep(1);
    }
    return 0;
}

//Function of get time format from user
int input_format(){
    int format;
    printf("\nChoose the time format: ");
    printf("\n1. 24 Hour format");
    printf("\n2. 12 Hour format (default)");
    printf("\n Make a choice (1/2):"); 
    scanf("%d", &format);
    
    return format;
}


 // Function of get current date and store in buffer
void fill_date(char *buffer){
    time_t raw_time;
    struct tm *current_time;

    // Get current time
    time(&raw_time);
    // Convert to local time
    current_time = localtime(&raw_time); 
    //Format the date
    strftime(buffer,100,"%A %B %d %Y",current_time);
}

// Function of get current time and store in buffer
void fill_time(char *buffer, int format){
    time_t raw_time;
    struct tm *current_time;

    // Get current time
    time(&raw_time);
    // Convert to local time
    current_time = localtime(&raw_time); 


    if (format == 1) {
        strftime(buffer, 50, "%H:%M:%S", current_time); // 24-hour format
    }
    else {
        strftime(buffer, 50, "%I:%M:%S %p", current_time); // 12-hour format
    }
}


//Function of clear screen 
void clear_screen(){
    #ifdef _WIN32
    system("cls"); // Clear command for Windows
#else
    system("clear"); // Clear command for Linux/Mac
#endif 
}
