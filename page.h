/*
 * =====================================================================================
 *       Copyright (c), 2013-2020, Goke.
 *       Filename:  page.h
 *
 *    Description:  
 *         Others:
 *   
 *        Version:  1.0
 *        Date:  2014/8/26 19:34:15
 *       Revision:  none
 *       Compiler:  xxx-gcc
 *
 *         Author:  Sean Hou , houwentaoff@gmail.com
 *   Organization:  Goke
 *        History:   Created by housir
 *
 * =====================================================================================
 */
#ifndef  __PAGE_H__
#define  __PAGE_H__

#define LABEL_OPTION_LEN 32
typedef struct {
	unsigned int value;/* usually increase */
//	char option[LABEL_OPTION_LEN];
    char label[LABEL_OPTION_LEN];
}Label_Option;

typedef struct {
	char* label;/*label name */
    char* name;/*label 'for name', select id*/
    union {
        char *name;
        char *id;
    }bind;
	Label_Option* options;
	int option_num;
	unsigned int value;/* selected value*/
	char* action;
}select_Label;

extern int   view_page();
extern int   enc_page();
extern int   pm_page();
extern int   osd_page();
extern int   sys_page();


#endif//__PAGE_H__

