
#include<stdio.h>
#include<stdlib.h>
#include<glut.h>
#include<windows.h>
#define BUFFSIZE 10
char arra[10];
int n,count=0;
void *currentfont;

void shellsort(char*,int);

void myDisplay(void);

GLint a=0,b=0,c=0,d=0,e=0,f=0,g=500,h=600,x=100,i=0;

char po[40]={"A MINI PROJECT ON"};
char game[70]={"GRAPHICAL IMPLEMENTATION OF SHELL SORT"};
char strt[140]={"1.PRESS (a) TO START"};
char exit1[40]={"2.PRESS ESC TO EXIT"};
char subm[20]={"PROJECT BY"};
char guid[30]={"UNDER GUIDANCE OF"};
char name3[50]={"Mr. SHRINATH K.S"};
char name2[20]={"VIKAS MOTLA"};
char reg2[12]={"1ST13CS146"};
char name1[20]={"VISHAL YADAV"};
char reg1[12]={"1ST13CS151"};
char coll[70]={"SAMBHRAM INSTITUTE OF TECHNOLOGY"};
char coll1[50]={"M.S PALYA , BANGALORE"};
char arr1[20]={"ASST. PROFESSOR"};
char bck[80]={"Press 'b' to go back or left mouse button"};
char menu1[10]={"MENU"};
char stre[80]={"Press any key to continue"};
char stro[10]={"or"};
char strm[40]={"right mouse button"};
bool menu=false;
bool strtup_scr=true;
bool bg=false;
bool s_t=false;
bool fg=false;
bool gg=false;
char help[40]={"3.HELP(Press h)"};
char ar[40]={"1.press a to start"};
char br[40]={"2.press ESC to exit"};
char cr[40]={"3.press b or left mouse btn"};
char dr[40]={"press m to go back to menu"};
char sr[100]={"SHELL SORT"};
char hr[40]={"HELP"};
char s1[100]={"SHELL SORT"};
void update(int value)
{
	a+=1000.0; 
	glutPostRedisplay();
	glutTimerFunc(1000,update,0);
}
void text(void *font, const char *string, float x, float y) 
{
	glRasterPos2f(x, y);
	char *p = (char*) string; 
	while (*p != '\0') glutBitmapCharacter(font, *p++); 
}
void mouse(int btn,int state,int x,int y)
{
	if(strtup_scr)
	{
		if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN) 
		{
			strtup_scr=false;
			menu=true;
		}
	}
	if(menu)
	{
		if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN) 
		{
			
			menu=false;
			bg=true;
		}
if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN) 
		{
			
			menu=false;
			strtup_scr=true;
		}
	}
	if(bg)
	{
		if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN) 
		{
			menu=true;
			bg=false;
		}
	}
	if(bg)
	{
      if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN) 
		{
		 
	        menu=false; 
            bg=true;  
			gg=true;
			fg=false;
		}
	}
}
void keyboard(unsigned char key, int x, int y)
{
	if(key==27)	
	{
		exit(0);
	}

	if (strtup_scr)		
	{
		if(key!=27&& key!='A')
		{
		strtup_scr=false;
		menu=true;
		}
	}
	if(menu)
	{
		if(key=='a')	
		{
			menu=false;
			bg=true;
		}
		if(key=='h')
		{
			s_t=true;
			menu=false;
		}
		if(key=='b')
		{
			menu=false;
			strtup_scr=true;
		}
		
       
	}
	if(s_t)
	{
		if(key=='m')
		{
			s_t=false;
			menu=true;
		}
	}

	if(bg)
	{
             if(key=='b')
			 {
				bg=false;
				menu=true;
			 }
			 if(key=='l')
			 {
				 fg=true;
				 gg=false;
			 }
	}
}
void display()
{
                int w;
				glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT );

	if(menu)
	{
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(480.0,600.0);
		for(w=0;w<sizeof(menu1);w++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,menu1[w]);

		glColor3f(0.0,1.0,0.0);
		glRasterPos2f(240.0,430.0);
		for(w=0;w<sizeof(strt);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,strt[w]);

		glColor3f(0.0,1.0,0.0);
		glRasterPos2f(240.0,325.0);
		for(w=0;w<sizeof(exit1);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,exit1[w]);

			glColor3f(0.0,1.0,0.0);
		glRasterPos2f(240.0,220.0);
		for(w=0;w<sizeof(help);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,help[w]);
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(100.0,100.0);
		for(w=0;w<sizeof(bck);w++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,bck[w]);
		
	}
	if(strtup_scr)	
	{
		glClearColor(1.0,0.0,0.0,1.0);
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(390.0,700.0);
		for(w=0;w<sizeof(po);w++)                                      
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,po[w]);
		
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(260.0,650.0);
		for(w=0;w<sizeof(game);w++)                                      
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,game[w]);
		
 		glColor3f(1.0,0.0,1.0);
		glRasterPos2f(450.0,560.0);
		for(w=0;w<sizeof(subm);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,subm[w]);

		glColor3f(1.0,1.0,0.0);
		glRasterPos2f(100.0,420.0);
		for(w=0;w<sizeof(name2);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,name2[w]);
		glColor3f(1.0,1.0,0.0);
		glRasterPos2f(100.0,400.0);
		for(w=0;w<sizeof(reg2);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,reg2[w]);

				glColor3f(1.0,1.0,0.0);
		glRasterPos2f(750.0,420.0);
		for(w=0;w<sizeof(name1);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,name1[w]);
		glColor3f(1.0,1.0,0.0);
		glRasterPos2f(750.0,400.0);
		for(w=0;w<sizeof(reg1);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,reg1[w]);

		glColor3f(1.0,0.0,1.0);
		glRasterPos2f(400.0,300.0);
		for(w=0;w<sizeof(guid);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,guid[w]);

		glColor3f(1.0,1.0,0.0);
		glRasterPos2f(400.0,260.0);
		for(w=0;w<sizeof(arr1);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,arr1[w]);
		
			glColor3f(1.0,1.0,0.0);
		glRasterPos2f(400.0,280.0);
		for(w=0;w<sizeof(name3);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,name3[w]);
		
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(375.0,200.0);
		for(w=0;w<sizeof(coll);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,coll[w]);
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(375.0,175.0);
		for(w=0;w<sizeof(coll1);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,coll1[w]);
		glColor3f(0.0,1.0,0.0);
		glRasterPos2f(375.0,130.0);
		for(w=0;w<sizeof(stre);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,stre[w]);
glColor3f(0.0,1.0,0.0);
		glRasterPos2f(420.0,115.0);
		for(w=0;w<sizeof(stro);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,stro[w]);
glColor3f(0.0,1.0,0.0);
		glRasterPos2f(390,90.0);
		for(w=0;w<sizeof(strm);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,strm[w]);

		



	}
	if(s_t)
	{

			glColor3f(1.0,0.0,0.0);
		glRasterPos2f(500.0,700.0);
		for(w=0;w<sizeof(hr);w++)                                      
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,hr[w]);
		
	glColor3f(1.0,0.0,0.0);
		glRasterPos2f(100.0,650.0);
		for(w=0;w<sizeof(ar);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ar[w]);
		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(100.0,550.0);
		for(w=0;w<sizeof(br);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,br[w]);
		glColor3f(1.0,0.0,0.0);

		glColor3f(1.0,0.0,0.0);
		glRasterPos2f(100.0,350.0);
		for(w=0;w<sizeof(sr);w++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,sr[w]);

			glColor3f(1.0,0.0,0.0);
		glRasterPos2f(100.0,100.0);
		for(w=0;w<sizeof(dr);w++)                                      
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,dr[w]);
	}
	if(bg)
	{	
		glClearColor(1.0,1.0,0.0,1.0);
		
	glClear(GL_COLOR_BUFFER_BIT);

		myDisplay();
		
	}
	glFlush();
	glutSwapBuffers();

}



void setFont(void *font)
{
	currentfont=font;

}

void init(void)
{
	glClearColor(1,1,0,0);
	glColor3f(1,0,0);
	gluOrtho2D(0.0,640.0,0.0,480.0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
}

void myinit()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,799.0);
}

void drawstring(GLfloat x,GLfloat y,char string[])
{
    char c;
	glRasterPos2f(x,y);
	
 
	for(c=0;string[c]!='\0';c++)
	{
		glutBitmapCharacter(currentfont,string[c]);
		
	}
}
void delay()
{
	int i,j;
	count++;
	for(i=0;i<1000;i++)
		for(j=0;j<100000;j++) count++;
}

void draw_tab()//draws the array box
{
	int i,h,k;
	char s[20];
	char *s1=(char*)malloc(BUFFSIZE*sizeof(char));		
	for(i=0;i<n;i++)
	{
		h=350+i*50;//50+i*50
		k=400+i*50;//100+i*50
		glBegin(GL_LINE_LOOP);
			glColor3f(0,0,0);
			glVertex2i(h,350);//50
			glVertex2i(k,350);//50
			glVertex2i(k,450);//100
			glVertex2i(h,450);//100
		glEnd();

		s1=itoa(arra[i],s,10);
		glColor3f(1,0,0);
		drawstring(h+20,400,s1);
		
		glColor3f(1,1,0);
		
	}
	delay();
	
	glFlush();
	glColor3f(1,1,0);
	
}
void draw_tab1()//draws the output array box
{
	int i,h,k;
	char s[20];
	char *s1=(char*)malloc(BUFFSIZE*sizeof(char));	
	count+=2;
	for(i=0;i<n;i++)
	{
		h=50+i*50;
		k=100+i*50;
		glBegin(GL_LINE_LOOP);
			glColor3f(0,0,0);
			glVertex2i(h,50);
			glVertex2i(k,50);
			glVertex2i(k,100);
			glVertex2i(h,100);
		glEnd();

		s1=itoa(arra[i],s,10);
		glColor3f(1,1,0);
		drawstring(h+25,75,s1);
		
		
		
		glColor3f(1,1,0);
		
		
		
	}
	delay();
	
	glFlush();
	glColor3f(1,1,0);

}
void shellsort(char a[], int n)
{
        int i, j, increment, temp;
        for(increment = n/2;increment > 0; increment /= 2)
        {
                for(i = increment; i<n; i++)
                {
                        temp = a[i];
                        for(j = i; j >= increment ;j-=increment)
                        {
                                if(temp < a[j-increment])
                                {
                                        a[j] = a[j-increment];
                                }
                                else
                                {
                                        break;
                                }
                        }
                        a[j] = temp;
                }
        }
}

void myDisplay(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1,0,0);
	drawstring(350,500,"INPUT ARRAY IS\n");
	draw_tab();
	delay();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1,0,0);
	drawstring(350,500,"SORTING THE ARRAY-\n");
	delay();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawstring(350,500,"SORTING THE ARRAY---\n");
	delay();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawstring(350,500,"SORTING THE ARRAY-----\n");
	delay();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawstring(350,500,"SORTING THE ARRAY-------\n");
	delay();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawstring(350,500,"SORTING THE ARRAY---------\n");

    shellsort(arra,n);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawstring(350,500,"SORTED ARRAY IS\n");
	drawstring(50,500,arra);
	draw_tab();
	delay();
delay();
delay();
delay();
delay();
delay();

exit(0);
}



int main(int argc,char* argv[])
{
	int i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arra[i]);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1024.0,640.0);
	glutInitWindowPosition(0.0,0.0);
	glutCreateWindow("SHELL SORT");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	init();
	myinit();
	glutTimerFunc(10,update,0);
	glutMainLoop();
	
	glFlush();
	return 0;
}



