#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define Capacity 50
#define Max_name 20
#define Max_tele 12
#define Max_sex 6
struct Member
{
	char name[Max_name];
	char telephone[Max_tele];
	char sex[Max_sex];
	int age;
	
};
struct Contact
{
	struct Member data[Capacity];
	int count;
};
void InitContact(struct Contact*);
void New(struct Contact* arr);
void Delete(struct Contact* arr);
void Edit(struct Contact* arr);
void Sort(struct Contact* arr);
void Show(struct Contact* arr);
void Search(struct Contact* arr);
void(*p_f_arr[6])(struct Contact* );