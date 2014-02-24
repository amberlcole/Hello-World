#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
    static int line_count = MAX_LINES_PER_PAGE;
    
    if (++line_count > MAX_LINES_PER_PAGE)
    {
        //Needs to start a new page and add a header to the top
        line_count = 0;
        print_page_header( source_name_to_print, date_to_print );
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    {
        // Checking to see if the line is too long, if it is it needs to be 
        //trucated
        save_chp = &line[0];
        save_ch = str( line );
    }
    if (save_chp)
    {
        strncpy( line, line, MAX_PRINT_LINE_LENGTH );
    }
    
    printf("%s", line );
    
    if (save_chp)
    {
        // restores to it's normal length when printed
        strncpy( line, save_chp, save_ch );
    }
    
}
static void print_page_header(char source_name[], char date[])
{
    static int page_number = 0;
    printf( "%s", source_name, date);
    page_number++;
    /* I'm guessing this needs to print a header with the name and date of the
    file. And the page number is to be incremented because this function is only
    called when a new page needs to start.*/
}
