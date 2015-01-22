//
const int row[8] = {23,25,27,29,31,33,35,37};
const int col[8] = {39,41,43,45,47,49,51,53};
//
int v   = 3; 
int dms = 400; 

bool A[8][80] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,0,0,0,1,1,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,0,0,0,0,
0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,
0,0,1,0,1,0,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0,0,1,1,1,1,0,
0,1,1,1,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,
0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

void setup() {

for (int i=0; i<8; i++)
{
pinMode(row[i],OUTPUT);
pinMode(col[i],OUTPUT);
}
for (int i=0; i<8; i++)
{
digitalWrite(row[i],HIGH); 
}
}

void loop()
{
paint(A, v);
scroll(A);
}

void paint(boolean screen[8][80], int v) 
{  
int i, j;
for (int c=0; c <v; c ++) 
{
for (i=0; i<8; i++)
for (j=0; j<8; j++)
{
if (screen[i][j]==1)            
{
digitalWrite(row[i], LOW); 
digitalWrite(col[j], HIGH); 
delayMicroseconds(dms); 
digitalWrite(row[i], HIGH); 
digitalWrite(col[j], LOW); 
}
else 
{
digitalWrite(row[i], HIGH); 
digitalWrite(col[j], LOW); 
delayMicroseconds(dms); 
digitalWrite(row[i], HIGH); 
digitalWrite(col[j], LOW);
} 
} 
}
}

void scroll(boolean screen[8][80]) 
{
boolean buf[8][1]; 
for (int i=0; i<8; i++)
{
buf[i][0]=screen[i][0]; 
}
for (int i=0; i<8; i++)
for (int j=0; j<80; j++)
{
screen[i][j]=screen[i][j+1]; 
}
for (int i=0; i<8; i++)
{
screen[i][80-1]=buf[i][0]; 
}
}