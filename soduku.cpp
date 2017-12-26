#include<iostream>
#include<algorithm>
#include <ctime>
#include<cstdio>
using namespace std;
 int n;
int Initial_State [ 10 ] [ 10 ] ; 
 
bool get_Initial_State( int i , int j  )  //搜索第（ i , j ）位置处可以存储的数字,找到解则返回true，否则返回false
{
    if( i > 9 || j > 9 ) 
        return true;
 
    for( int k = 1 ; k <= 9 ; ++k ) 
    {
        bool can = true;                // can 变量用于记录数字k能否放在 ( i , j ) 处 
        for( int m = 1 ; m < i ; ++m ) 
            if( Initial_State[m][j] == k )  // 检查同一列是否出现过数字k
            {
                can = false ;
                break ;
            }
        if ( can ) 
            for( int n = 1 ; n < j ; ++n ) 
                if( Initial_State[i][n] == k )  // 检查同一行是否出现过数字k
                {
                    can = false ;
                    break; 
                }
        if( can ) 
        {
            int up1 = ( i/3 ) * 3 + 3 ; // (i,j)方格所在的3×3小方格i坐标的上限
            int up2 = ( j/3 ) *3 + 3;   // (i,j)方格所在的3×3小方格在j坐标的上限
 
            if( i % 3 == 0 )    //这是针对特殊情况的处理
                up1 = i ; 
            if( j % 3 == 0 ) 
                up2 = j ;
 
            for( int p = up1-2 ; p <= up1 ; ++p  )  /* 检查在3×3的小方格中是否出现了同一个数字 */
            {
                if( can == false )   /* 跳出外层循环 */
                    break ;
                for( int q = up2-2 ; q <= up2 ; ++q ) 
                    if( Initial_State[p][q] == k ) 
                    {
                        can = false ;
                        break ;
                    }
            }
        }
        if( can ) 
        {
            Initial_State[i][j] = k ; 
            if( j<9 ) 
            {
                if( get_Initial_State( i  , j +1 ) )  
                    return true ;  
            }
            else
            {
                if( i < 9 )  
                {
                    if( get_Initial_State( i + 1 , 1 ) ) 
                        return true ;
                }
                else
                    return true ;  
 
            }
            Initial_State[i][j] = 0 ;   
        }
    }
    return false ;  
}
 
void start() 
{
 int a[2];
 int k;

k=1;
 Initial_State[1][1]=k;
 for(int i=2,j=1;i<=k;i++,j++){
 	Initial_State[1][i]=j;
 }
 for(int i=k+1;i<10;i++){
 	Initial_State[1][i]=i;
 
 }
 int N;
 N=n;
 for(int t=0;t<N;t++){
  random_shuffle(&Initial_State[1][2],&Initial_State[1][9]);
 get_Initial_State(2,1);
 for( int i = 1 ; i <= 9 ; ++ i ) 
    {
        for( int j = 1 ; j <= 9 ; ++j ) 
            cout<< Initial_State [i][j] <<" " ;
        cout<<endl; 
    }
	cout<<endl;}
    getchar() ;  
  
}

int main(int argc,char **argv)
{
if(argv[1][0]!='-'||argv[1][1]!='c'||argv[1][2]!='\0')
	{
		cout<<"input invalid,please input -c ";
	
	 } 
	 for(int i=0;argv[2][i]!='\0';i++)
	 {
	 	if(argv[2][i] < 48 || argv[2][i]>57)
	 	{
	 		cout<<"input invalid,please input number";
	 		break;
		 }
		 n=argv[2][i]-'0'+n*10;
	 }
	 freopen("soduku.txt","w",stdout);
   //for(int t=0;t<3;t++){
    start( ) ;
    /*for( int i = 1 ; i <= 9 ; ++ i ) 
    {
        for( int j = 1 ; j <= 9 ; ++j ) 
            cout<< Initial_State [i][j] <<" " ;
        cout<<endl; 
    }
	cout<<endl;}
    getchar() ; */
     fclose(stdout); 
    return 0 ;
}
