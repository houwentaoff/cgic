/*
 * =====================================================================================
 *       Copyright (c), 2013-2020, Goke.
 *       Filename:  page.c
 *
 *    Description:  
 *         Others:
 *   
 *        Version:  1.0
 *        Date:  2014/8/26 18:05:30
 *       Revision:  none
 *       Compiler:  xxx-gcc
 *
 *         Author:  Sean Hou , houwentaoff@gmail.com
 *   Organization:  Goke
 *        History:   Created by housir
 *
 * =====================================================================================
 */
//#include <page.h>
#include "include.h"

#define MAXSTRLEN 128

static int create_select_label(char * text, select_Label* select_label)
{
    char* label_format_title = "<label for=\"%s\">%s</label><select id=\"%s\" %s>\n";
    int num = select_label->option_num;


    char label_string[MAXSTRLEN] = {0};
    sprintf(label_string, label_format_title, \
            select_label->bind.name, select_label->label, select_label->bind.id, select_label->action);
    strncat(text, label_string, strlen(label_string));

    char* option_string_format = "<option value=%d%s>%s</option>\n";
    char option_string[MAXSTRLEN] = {0};
    int i = 0;
    for (i = 0; i < num; i++) 	{
        memset(option_string, 0, sizeof(option_string));
        if (select_label->options[i].value == select_label->value) {
            sprintf(option_string, option_string_format, select_label->options[i].value, \
                    " selected", select_label->options[i].label);
        } else {
            sprintf(option_string, option_string_format, select_label->options[i].value, \
                    " ", select_label->options[i].label);
        }
        strncat(text, option_string, strlen(option_string));
    }
    char* label_format_end = "</select>\n";
    strncat(text, label_format_end, strlen(label_format_end));
 /* :TODO:2014/9/1 17:47:39:Sean:  又上替代*/
#if 0
    fprintf(cgiOut, "<br>\n");
    fprintf(cgiOut, "<label for=\"s0_type\">Type :</label>\n");
    fprintf(cgiOut, "<select id = \"s0_type\">\n");
    fprintf(cgiOut, "<option value=\"0\">OFF\n");
    fprintf(cgiOut, "<option value=\"1\">H264\n");
    fprintf(cgiOut, "<option value=\"2\">MJPEG\n");
    fprintf(cgiOut, "</select>\n");

    char *choicesText[]={"OFF", "H264", "MJPEG"};
    cgiSetFormSelectSingle("s0_type", choicesText, sizeof(choicesText)/sizeof(char *) - 1, -1)
#endif
 /* :TODO:End---  */
        return (0);
}

int   view_page()
{

    return (0);
}

int   enc_page()
{
    char *text=NULL;
    select_Label select_label;

    FUN_IN();     
/*stream 0*/
    text = (char *)malloc(1024);
    for (i=0;i<5;i++)
    {
        select_label = ;
        create_select_label(text, select_label);
    }
    fprintf(cgiOut, "%s", text);

    FUN_OUT();

    return (0);
}
int   pm_page()
{

    return (0);
}
int   osd_page()
{

    return (0);
}
int   sys_page()
{

    return (0);
}

