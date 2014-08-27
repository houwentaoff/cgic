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

static int showStream()
{
	fprintf(cgiOut, "<br>\n");
	fprintf(cgiOut, "<label for=\"s0_type\">Type :</label>\n");
	fprintf(cgiOut, "<select id = \"s0_type\">\n");
	fprintf(cgiOut, "<option value=\"0\">OFF\n");
	fprintf(cgiOut, "<option value=\"1\">H264\n");
	fprintf(cgiOut, "<option value=\"2\">MJPEG\n");
	fprintf(cgiOut, "</select>\n");

    return (0);
}

int   view_page()
{

    return (0);
}

int   enc_page()
{
    FUN_IN();     

    showStream();

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

