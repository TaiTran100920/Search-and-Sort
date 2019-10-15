#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
ofstream myfile2;
bool KT(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
		if (a[i] > a[i+1]) 
			return false;
	return true;
}
void output(int a[], int n)
{
	for (int i = 0;i < n; i++)
	{
		cout << a[i] <<" ";
		myfile2 << a[i] <<" ";
	}
}

int TKTuanTu(int a[],int n,int x)
{
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( a[i] == x )
            return i+1;
    }
    return -1;
}

int TKTuanTuCaiTien(int a[],int n,int x)
{
    int i = 0;
    a[n] = x;
    while (a[i]!=x)
        i++;
    if (i<n) return i+1;
    return -1;
}

int TKNhiPhan(int a[],int first,int last,int x)
{
	if (KT(a,last) == true)
	{
		if (last >= first)
	    {
	        int mid = ( last + first)/2;
	        if (a[mid] == x) return mid+1;
	        if (a[mid] > x) return TKNhiPhan (a,first,mid-1,x);
	        else return TKNhiPhan(a,mid+1,last,x);
	    }
	    return -1;
	}
}

void SXChon(int a[],int n)
{
    for (int i = 0;i < n-1;i++)
    {
        int Cs_min = i;
        for (int j = i+1;j < n;j++)
        {
            if (a[Cs_min] > a[j] )
                Cs_min = j;
            swap(a[Cs_min],a[i]);
        }
    }
}

void SXChen(int a[],int n)
{
    int pos,i,x;
    for (int i = 0;i < n;i++)
    {
        x=a[i];
        pos=i-1;
        while (pos >= 0 && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

void SXDoiCho(int a[], int n)
{
    for (int i = 0 ; i < n-1 ; i++)
        for (int j = i + 1 ; j < n ; j++)
            if (a[j] < a[i]) swap(a[i],a[j]);
}

void SXNoiBot(int a[],int n)
{
    for (int i = 0;i< n-1;i++)
        for (int j = n - 1;j > i;j--)
            if (a[j]<a[j-1]) swap(a[j],a[j-1]);
}

void Tron(int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;
    int Left[n1], Right[n2];
    for (i = 0 ; i < n1 ; i++)
        Left[i] = a[left + i];
    for (j = 0 ; j < n2 ; j++)
        Right[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            a[k] = Left[i];
            i++;
        }
        else
        {
            a[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = Left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = Right[j];
        j++;
        k++;
    }
} 

void SXTron(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        SXTron(a, left, mid);
        SXTron(a, mid + 1, right);
        Tron(a, left, mid, right);
    }
}

void SXNhanh(int a[], int left, int right)
{ 
	int i,j,x;
	x = a[(left + right)/2]; 
	i = left;
	j = right;
	do {
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if(i <= j)
		{	 
			swap(a[i],a[j]);
			i++ ; 
			j--; 
		}
	} while(i <= j);
	if(left < j) SXNhanh(a,left,j);
	if(i < right) SXNhanh(a,i,right);
}

int main()
{
    int n,x;
    int a[1000];
    ofstream myfile;
    myfile.open("INPUT.txt");
    myfile2.open("OUTPUT.txt");
    cout << "Moi ban nhap so can tim: ";
    cin >> x;
    cout << "Moi ban nhap n: ";
    cin >> n;
    myfile << n << endl;
    for ( int i = 0 ; i < n; i++ )
    {    
		cout << "Moi ban nhap phan tu thu " <<i+1<<": ";
        cin >> a[i];
        myfile << a[i] << " ";
    }
    myfile.close();
	int choose;
	do 
	{
		system("cls");
		cout << "\t\t\tMENU" << endl;
		cout << "\t\tTRAN LE TAN TAI - D18PM01\n";
		cout << "------------------------------------\n";
		cout << "1. Tim kiem tuan tu\n";
		cout << "2. Tim kiem tuan tu cai tien\n";
		cout << "3. Tim kiem nhi phan\n";
		cout << "4. Sap xep chon\n";
        cout << "5. Sap xep chen\n";
        cout << "6. Sap xep doi cho\n";
        cout << "7. Sap xep noi bot\n";
        cout << "8. Sap xep tron\n";
        cout << "9. Sap xep nhanh bang phan hoach\n";
		cout << "0. Thoat\n";
		cout << "Ban chon: ";
		cin >> choose;
		cout << endl;
	    switch(choose)
	    {
	        case 1:
	        	cout << "Tim kiem tuan tu: ";
	        	myfile2 << "Tim kiem tuan tu: ";
	        	if ( TKTuanTu(a,n,x) == -1) 
	        	{
	        		cout << "Khong tim thay so ban can tim !!!" << endl;
	        		myfile2 << "Khong tim thay so ban can tim !!!" << endl;
				}
	        	else
	        	{
	        		cout << "So " << x <<" ban can tim nam o vi tri thu " << TKTuanTu(a,n,x) << endl;
	        		myfile2 << "So " << x <<" ban can tim nam o vi tri thu " << TKTuanTu(a,n,x) << endl;
				}
	        	system("pause");
	            break;
	        case 2:
	        	cout << "Tim kiem tuan tu cai tien: ";
	        	myfile2 << "Tim kiem tuan tu cai tien: ";
	        	if ( TKTuanTuCaiTien(a,n,x) == -1) 
	        	{
	        		cout << "Khong tim thay so ban can tim !!!" << endl;
	        		myfile2 << "Khong tim thay so ban can tim !!!" << endl;
				}
	        	else
	        	{
	        		cout << "So "<< x <<" ban can tim nam o vi tri thu " << TKTuanTuCaiTien(a,n,x)<<endl;
	        		myfile2 << "So "<< x <<" ban can tim nam o vi tri thu " << TKTuanTuCaiTien(a,n,x)<<endl;
				}	
	        	system("pause");
	            break;
	        case 3:
	        	cout << "Tim kiem nhi phan: ";
	        	myfile2 << "Tim kiem nhi phan: ";
	        	if (KT(a,n) == false) 
	        	{
	        		cout << "Day chua duoc sap xep\n";
	        		myfile2 << "Day chua duoc sap xep\n";
				}
	        	else
	        	{
		        	if ( TKNhiPhan(a,0,n-1,x) == -1) 
		        	{
		        		cout << "Khong tim thay so ban can tim !!!" << endl;
		        		myfile2 << "Khong tim thay so ban can tim !!!" << endl;
					}
		        	else
		        	{
		        		cout << "So "<< x <<" ban can tim nam o vi tri thu " << TKNhiPhan(a,0,n-1,x) << endl;
		        		myfile2 << "So "<< x <<" ban can tim nam o vi tri thu " << TKNhiPhan(a,0,n-1,x) << endl;
					}	
				}
	        	system("pause");
	            break;	

	        case 4:
	        	cout << "Sap xep chon: ";
	        	myfile2 << "Sap xep chon: ";
	            SXChon(a,n);
	            output(a,n);
	            cout << endl;
	            myfile2 << endl;
	            system("pause");
	            break;
	        case 5:
	        	cout << "Sap xep chen: ";
	        	myfile2 << "Sap xep chen: ";
	            SXChen(a,n);
	            output(a,n);
	            cout << endl;
	            myfile2 << endl;
	            system("pause");
	            break;
	        case 6:
	        	cout << "Sap xep doi cho truc tiep: ";
	        	myfile2 << "Sap xep doi cho truc tiep: ";
	            SXDoiCho(a,n);
	            output(a,n);
	            cout << endl;
	            myfile2 << endl;
	            system("pause");
	            break;
	        case 7:
	        	cout << "Sap xep noi bot: ";
	        	myfile2 << "Sap xep noi bot: ";
	            SXNoiBot(a,n);
	            output(a,n);
	            cout << endl;
	            myfile2 << endl;
	            system("pause");
	            break;
	        case 8:
	        	cout << "Sap xep tron: ";
	        	myfile2 << "Sap xep tron: ";
	            SXTron(a,0,n-1);
	            output(a,n);
	            cout << endl;
	            myfile2 << endl;
	            system("pause");
	            break;
	        case 9:
	        	cout << "Sap xep nhanh: ";
	        	myfile2 << "Sap xep nhanh: ";
	            SXNhanh(a,0,n-1);
	            output(a,n);
	            cout << endl;
	            myfile2 << endl;
	            system("pause");
	            break;
	    }
	} while (choose != 0);
	myfile2.close();
}
