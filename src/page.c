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
#define SMALLHTML 1024            /*  */

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
        if (select_label->options[i].value == select_label->selected) {
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
    int j,i;
    char *text=NULL;
    char *enc_mode[]      = {"Normal mode", "High Mega-pixel mode", "Low delay mode"};
    char *s0_type[]       = {"OFF", "H.264", "MJPEG"};
    char *s0_enc_fps[]    = {"60", "30", "25", "20", "15", "10", "6", "5", "4", "3", "2", "1"};
    char *s0_dptz[]       = {"Disable", "Enable"};
    char *s0_resolution[] = {"1920 x1080", "1440 x1080", "1280 x1024", "1280 x 960",
        "1280 x 720", " 800 x 600", " 720 x 576", " 720 x 480", " 640 x 480",
        "352 x 288", "352 x 240", "320 x 240", "176 x 144", "176 x 120",
        " 160 x 120",
    };

//    char *((* (labels[]))[]);
//    char *labels[5]={enc_mode,}
    
    /*-----------------------------------------------------------------------------
     *  select
     *-----------------------------------------------------------------------------*/
    select_Label select_label[5] =
    {
        {
            .label      = "Encode Mode :",    
            .bind.id    = "enc_mode",
            .options    = NULL,
            .option_num = 3,
            .selected   = 2,
            .action     = "setEncodeMode(this.options[this.selectedIndex].value)",
        },
        {
            .label      = "Type :",    
            .bind.id    = "s0_type",
            .options    = NULL,
            .option_num = 3,
            .selected   = 2,
            .action     = NULL,
        },
        {
            .label      = "Encode FPS :",    
            .bind.id    = "s0_enc_fps",
            .options    = NULL,
            .option_num = 12,
            .selected   = 2,
            .action     = NULL,
        },        
        {
            .label      = "DPTZ Type :",    
            .bind.id    = "s0_dptz",
            .options    = NULL,
            .option_num = 12,
            .selected   = 2,
            .action     = NULL,
        },
        {
            .label      = "Resolution :",    
            .bind.id    = "s0_resolution",
            .options    = NULL,
            .option_num = 12,
            .selected   = 2,
            .action     = NULL,
        },            
            
    };

    FUN_IN();     
/*init select*/
    for (j = 0;j<5;j++)
    {
        select_label[j].options = (Label_Option *)malloc(select_label[j].option_num * sizeof(Label_Option));
        for (i = 0; i<select_label[j].option_num;i++)
        {
            (select_label[j].options+i)->value = i;
            (select_label[j].options+i)->label = s0_resolution[i];/*mark*/
        }
    }
    /*stream 0*/
    text = (char *)malloc(SMALLHTML);
    if (!text)
    {
        PRINT_ERR("text is null\n");
    }
    for (i=0;i<5;i++)
    {
        create_select_label(text, &select_label[i]);
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

