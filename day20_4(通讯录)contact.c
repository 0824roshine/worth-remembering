#include"day20_5txl_contact.h"
//有的函数不需要放在头文件里
static int FindByName(struct Contact* arr, const char name[Max_name])
{
	int i = 0;
	for (i = 0; i < arr->count; i++)
	{
		if (0 == strcmp(arr->data[i].name, name))
			return i;
	}
	return  -1;
}
void InitContact(struct Contact* pp)
{
	memset(pp->data,0,sizeof(pp->data));
	pp->count = 0;
}
void New(struct Contact* arr)
{
	if (arr->count == Capacity)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入名字\n");
		scanf("%s", arr->data[arr->count].name);
		printf("请输入电话\n");
		scanf("%s", arr->data[arr->count].telephone);
		printf("请输入性别\n");
		scanf("%s", arr->data[arr->count].sex);
		printf("请输入年龄\n");
		scanf("%d",&(arr->data[arr->count].age)); //一定要给&
		arr->count++;
		printf("新建成功\n");
	}
	
}
void Delete(struct Contact* arr)
{
	char Nam[Max_name];
	printf("你想删谁？\n");
	scanf("%s", Nam);
	int pos = FindByName(arr, Nam);
	if (pos == -1)
		printf("目标不存在\n");
	else
	{
		for (int j = pos; j < (arr->count - 1); j++)
			arr->data[j] = arr->data[j + 1];
	}
	arr->count--;
	printf("已删除\n");
}
void Edit(struct Contact* arr)
{
	char Nam[Max_name];
	printf("你想更改谁的信息？\n");
	scanf("%s", Nam);
	int pos = FindByName(arr, Nam);
	if (pos == -1)
		printf("目标不存在\n");
	else
	{
		printf("请输入名字\n");
		scanf("%s", arr->data[pos].name);
		printf("请输入电话\n");
		scanf("%s", arr->data[pos].telephone);
		printf("请输入性别\n");
		scanf("%s", arr->data[pos].sex);
		printf("请输入年龄\n");
		scanf("%d", &(arr->data[pos].age)); //一定要给&
		printf("修改成功\n");
	}
}
void Sort(struct Contact* arr)
{
	printf("4\n");
}
void Show(struct Contact* arr)
{
	int num = arr->count;
	if (num)
	{
		for (int i = 0; i < num; i++)
		{
			printf("%-20s\t%-12s\t%-6s\t%-3s\n","名字","电话","性别","年龄");
			printf("%-20s\t%-12s\t%-6s\t%-3d\n", 
				arr->data[i].name, 
				arr->data[i].telephone,
				arr->data[i].sex, 
				arr->data[i].age);
		}
	}
	else
	{
		printf("通讯录为空\n");
	}
}
void Search(struct Contact* arr)
{
	char Nam[Max_name];
	printf("你想找谁？\n");
	scanf("%s", Nam);
	int pos = FindByName(arr, Nam);
	if (pos == -1)
		printf("目标不存在\n");
	else
		printf("%-20s\t%-12s\t%-6s\t%-3s\n", "名字", "电话", "性别", "年龄");
		printf("%-20s\t%-12s\t%-6s\t%-3d\n",
			arr->data[pos].name,
			arr->data[pos].telephone,
			arr->data[pos].sex,
			arr->data[pos].age);
}
void(*p_f_arr[6])(struct Contact*) = { New,Delete,Edit,Sort,Show,Search };