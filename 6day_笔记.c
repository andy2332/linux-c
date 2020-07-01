
6day_笔记
	1，结构体
	2，内存映象
	3，内存管理
	4，存储类型
========================================================

一，结构体

1，概念
	结构体是不同类型数据的集合，该类型在C语言中没有具体的定义，
	当使用时，需要自己定义具体的结构体类型，所以，也称为自定义类型。
	把结构体不同的类型的数据称为结构体的成员。
	也就是说结构体是不同类型成员的集合。
	
2，结构体类型的定义 -------- //目的:定义结构体变量
	语法格式： 
		struct <结构体标签>{
			成员类型  成员名;
			成员类型  成员名;
			......		....
			成员类型  成员名;
		};
	例如： 
	struct person{
		int age;
		char name[20];
		float height;
	};
	
3，结构体类型的变量 ----//目的：保存结构体数据
	
	1》常规方式
		struct person{
			int age;
			char name[20];
			float height;
		};
		struct person p;   //p就是一个结构体变量

	2》与类型同时定义方式
		struct person{
			int age;
			char name[20];
			float height;
		} p;             //p就是一个结构体变量

	3》直接定义方式
		struct {
			int age;
			char name[20];
			float height;
		} p;             //p就是一个结构体变量

4，结构体变量的初始化
	1》完全初始化
		struct person p = {18,"小明",1.87};    //给结构体中每一个成员都赋值
	
	2》部分初始化
		struct person p = {18,"小明"};    //给结构体中前若干成员都赋值
	
	3》指定成员初始化
		struct person p = {.name="小明",1.78, .age=18};    //给结构体中每一个成员都赋值

5，结构体变量的使用 
	1》赋值
		//注意： 不能整体赋值，例如：
		struct peroson p; 
		p = {18,"小明",1.87};   //错误
		
		//相同类型的结构体变量之间可以相互赋值，例如 ： 
		struct person p = {18,"小明",1.87}; 
		struct person p1;
		
		p1 = p;   //同类型变量可以赋值
		
		//通常结构体变量的赋值，是给每个成员分别赋值，例如： 
		struct peroson p; 
		p.age = 18;
		p.name = "小明";   //错误
		strcpy(p.name,"小明");  //正确
		p.float = 1.87;
		
	2》取值
		//取值时，也只能分别使用结构体中每一个成员
		struct person{
			int age;
			char name[20];
			float height;
		};

		int main(void)
		{
			struct person p;
			p.age = 18;
			//p.name = "小明";   //错误
			strcpy(p.name,"小明");  //正确
			p.height = 1.87;

			printf("%s %d %.2f\n",p.name,p.age,p.height);
			return 0;
		}
6，结构体(类型)数组-----//保存多个结构体的信息
	例如： 
		struct person{
			int age;
			char name[20];
			float height;
		};

		int main(void)
		{
			int n;

			printf("请输入人数:");
			scanf("%d",&n);

			struct person p[n];		//p为结构体数组
			int i;

			for(i = 0; i < n; i++){
				printf("请输入一个人的信息:");
				scanf("%s%d%f",p[i].name,&p[i].age,&p[i].height);
			}
			for(i = 0; i < n; i++)
				printf("name = %s,age = %d, height =  %.2f\n",p[i].name,p[i].age,p[i].height);

			/*
			p.age = 18;
			//p.name = "小明";   //错误
			strcpy(p.name,"小明");  //正确
			p.height = 1.87;
			*/
			return 0;
		}


7，结构体(类型)指针 ------ //保存结构体变量的地址
	
	例如： 
		struct person{
			int age;
			char name[20];
			float height;
		};

		int main(void)
		{
			struct person p;
			struct person *ps;   //ps为野指针,必须要赋值，才具有实际意义，才能被使用

			ps = &p;

			p.age = 18;
			//p.name = "小明";   //错误
			strcpy(p.name,"小明");  //正确
			p.height = 1.87;

			printf("%s %d %.2f\n",p.name,p.age,p.height);
			printf("%s %d %.2f\n",(*ps).name,(*ps).age,(*ps).height);
			printf("%s %d %.2f\n",ps->name,ps->age,ps->height);
			return 0;
		}	

8，结构体(变量)传参
	
	1》值传递
		例如： 
			struct person{
				int age;
				char name[20];
				float height;
			};

			void print_struct(struct person p)
			{
				printf("%s %d %.2f\n",p.name,p.age,p.height);
			}

			int main(void)
			{
				struct person p;
				struct person *ps;   //ps为野指针,必须要赋值，才具有实际意义，才能被使用

				ps = &p;

				p.age = 18;
				//p.name = "小明";   //错误
				strcpy(p.name,"小明");  //正确
				p.height = 1.87;

				print_struct(p);   //将结构体变量的值传给函数:print_struct
				
				return 0;
			}
	
	
	2》地址传递
		struct person{
			int age;
			char name[20];
			float height;
		};

		void print_struct(struct person p)
		{
			printf("%s %d %.2f\n",p.name,p.age,p.height);
		}

		void set_struct(struct person *ps)
		{
			ps->age = 19;
			strcpy(ps->name,"小红");
			ps->height = 1.76;
		}

		int main(void)
		{
			struct person p;
			struct person *ps;   //ps为野指针,必须要赋值，才具有实际意义，才能被使用

			ps = &p;

			set_struct(&p);  //将结构体变量p的地址传给函数:set_struct
			
			print_struct(p);
			
			return 0;
		}
		
二，内存映象
	
	//当运行程序时，计算机会给当前的程序映射一块4GB大小的(虚拟)内存空间
	//在分析程序的运行过程时，可以借助该内存映射图来分析，方便对问题的分析和解决。
		
	内存映象图，参考：3_内存映象.tif
	
三，内存管理 ----- //堆空间的管理：申请，释放

	思考： 为什么在程序中要使用堆空间？

	1，栈空间和堆空间的对比
		
		1》栈空间
			1) 由系统申请释放
			2) 在内存中占有时间不好控制
			3) 空间相对较小，只能保存一些小数据，临时数据
			4) 存取速度较快
			5) 有名空间，可以通过名称访问
			
		2》堆空间
			1) 由工程师申请释放
			2) 在内存中占有时间好控制
			3) 空间相对较大,可以保存规模较大的数据
			4) 存取速度较慢
			5) 无名空间，只能通过指针访问
			
	2，如何使用堆空间
		1》申请堆空间
			#include <stdlib.h>
		    void *malloc(size_t size);
			//参数 ------ 要申请的空间的长度
			//返回值 ------- 成功：申请的空间的起始地址，失败：NULL
		    例如 ： 
				struct person{
					int age;
					char name[20];
					float height;
				};

				int main(void)
				{
					/*
					struct person p;
					p.age = 18;
					//p.name = "小明";   //错误
					strcpy(p.name,"小明");  //正确
					p.height = 1.87;

					printf("%s %d %.2f\n",p.name,p.age,p.height);
					*/

					struct person * p;

					p = (struct person*)malloc(sizeof(struct person));
					if(p == NULL){
						perror("malloc");   //打印上面函数调用失败的原因
						exit(1);  //结束当前正在执行的程序
					}

					p->age = 19;
					strcpy(p->name,"小张");
					p->height = 1.79;

					printf("%s %d %.2f\n",p->name,p->age,p->height);
					/*
					int *p,i;

					p = (int*)malloc(5*sizeof(int));
					if(p == NULL){
						perror("malloc");   //打印上面函数调用失败的原因
						exit(1);  //结束当前正在执行的程序
					}
					for(i = 0; i < 5; i++)
						scanf("%d",p+i);

					for(i = 0; i < 5; i++)
						printf("p[%d] = %d\n",i,p[i]);
					*/

					return 0;
				}
			//总结：malloc 
			 1) 申请的空间是一块连续的空间
			 2) 申请的空间没有被初始化
			 3) malloc返回的地址需要强制类型转换

		2》释放堆空间
			void free(void *ptr);
			//参数 ----malloc调用成功时返回的地址
			例如： 
				int main(void)
				{
					char *p;
					p = (char*)malloc(100);
					if(p == NULL){
						perror("malloc");   //打印上面函数调用失败的原因
						exit(1);  //结束当前正在执行的程序
					}

					strcpy(p,"hello world");
					printf("%s\n",p);

					//p++;	
					free(NULL);   //错误的
					free(p);
					p = NULL;
				   // strcpy(p,"farsight");
					//printf("%s\n",p);

				   // while(1);
					return 0;
				}

			//注意：
				1)不能释放申请的空间中的一部分
				2)不能使用free之后的空间
				3)不能给free传:NULL
	
四，存储类型	

1，概念： 
	在定义变量或者数组时，除了需要说明变量或数组的数据类型之外，还需要说明变量或数组的存储类型，
	
	数据类型 -----说明变量或数组：在内存中的长度和存储方式
	例如： 
		int a;    //数据类型int :说明变量a在长度为4，同时a在内存中的存储方式:二进制补码
	以上数据类型int只能说明数据的长度和存储方式，但是不能确定数据在什么地方分配空间，空间什么时候释放以及数据在程序中的使用范围。
	像在哪分配空间，什么时候释放空间以及在程序中的使用范围，只能通过变量或数组的存储类型来加以说明
	
2，存储类型的分类
	1》自动存储
	2》寄存器存储
	3》全局非static静态存储
	4》全局static静态存储
	5》局部static静态存储
	6》外部存储

3，如何定义不同存储类型的数据----以整型变量为例
	
	//代码块：用{}括起来的一块代码,例如： 
	
	void fun(void)
	{
		代码块
	}
	
	while(1){
		代码块
	}
	
	if(表达式){
		代码块
	}	
	

	1》自动存储					------	 代码块中定义，定义的格式：int a;
	2》寄存器存储				------	 代码块中定义，定义的格式：register int a;
	3》全局非static静态存储		------	 所有的函数外定义，定义的格式：int a;
	4》全局static静态存储		------	 所有的函数外定义，定义的格式：static int a;
	5》局部static静态存储		------	 代码块中定义，定义的格式：static int a;
	6》外部存储					------ 	 在另外一个文件中定义的变量，在当前文件中使用之前，需要声明外部存储:extern int a;

4，不同存储类型变量的特点
							  在内存中的位置    占用内存的时间段(生存期)  在程序中使用范围(作用域) ---- 链接类型
	1》自动存储					栈				  定义 ----->代码块结束		代码块内部					空
	2》寄存器存储				寄存器/栈		  定义 ----->代码块结束		代码块内部					空
	3》全局非static静态存储		.data/.bss		  定义 ----->程序结束		多个文件中使用				外部链接
	4》全局static静态存储		.data/.bss		  定义 ----->程序结束		单文件中使用				内部链接
	5》局部static静态存储		.data/.bss		  定义 ----->程序结束		代码块内部					空
	6》外部存储					.data/.bss		  定义 ----->程序结束		多个文件中使用				外部链接




